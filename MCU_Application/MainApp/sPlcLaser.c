#include "sPlcLaser.h"
/*****************************************************************************/
#define MCP47X6_LASER_CHANNEL_CH1				0
#define MCP47X6_LASER_CHANNEL_CH2				1
#define LASER_MODE_CW							0//连续模式
#define LASER_MODE_SP							1//单脉冲模式
#define LASER_MODE_MP							2//多脉冲模式
#define LASER_MODE_GP							3//群脉冲模式
#define LASER_STEPNUM_INIT						0
#define LASER_STEPNUM_STANDBY					1
#define LASER_STEPNUM_INTO_READY				2
#define LASER_STEPNUM_READY						3
#define LASER_STEPNUM_LASERON					100
#define LASER_STEPNUM_FAULT						255
/*****************************************************************************/
#define LASER_CH1_MODPIN_ON		(P4 |= (uint8_t)(1 << 6))
#define LASER_CH1_MODPIN_OFF	(P4 &= ~(uint8_t)(1 << 6))

#define LASER_CH2_MODPIN_ON		(P4 |= (uint8_t)(1 << 1))
#define LASER_CH2_MODPIN_OFF	(P4 &= ~(uint8_t)(1 << 1))
#define SPLC_100MS_INTOREADY_BEEM				1
/*****************************************************************************/
static void STLAR(void);
static void EDLAR(void);
////上位机使能MCU软复位
//#if CONFIG_USING_RESET == 1
//		if(my.mcuReset)
//		{
//			RSTSRC |= (1 << 1);//Forces a Power-On Reset. /RST is driven low.
//		}
//#endif
//		//数字滤波扫描输入IO

//		p->flagConnectErr = 0;//每次扫描错误标志清零
//		//心跳->PLC
//		if(my.heartFlag)
//		{
//			my.heatFlag = 0;
//		}
//		else
//		{
//			my.heatFlag = 1;
//		}
//		
//		//获取过热状态
//		my.overTempFault = (my.overTempDiode && !my.overTempDiodeIgnore) ||
//							  (my.overTempAmplifier && !my.overTempAmplifierIgnore) ||
//	                          (my.overTempEnvironment && !my.overTempEnvironmentIgnore) ||
//							  (my.overTempMcu && !my.overTempMcuIgnore);
//	    my.overTempFault = my.overTempFault && !my.overTempIgnore;
//		//获取安全状态
//		my.safeFault = (my.safeInterlock && !my.safeInterlockIgnore) ||
//					(my.safeFiberDetect0 && my.safeFiberDetect0Ignore) ||
//					(my.safeFiberDetect1 && my.safeFiberDetect1Ignore) ||
//					(my.safeOpenCase && my.safeOpenCaseIgnore);
//		my.safeFault = my.safeFault && !my.safeFaultIgnore;
//		//模拟输入扫描

void sPlcLaserStep(void){
//STEP_LOOP_START:
		if(NVRAM0[EM_STEP_NUM] == LASER_STEPNUM_INIT){//初始化
			NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_STANDBY;//Goto next step
			goto STEP_LOOP_END;
		}
		if(NVRAM0[EM_STEP_NUM] == LASER_STEPNUM_STANDBY){//第一步 待机状态->蜂鸣器提示
			if(LD(R_FLAG_SAFE_FAULT) || LD(R_FLAG_TEMP_FAULT)){
				NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_FAULT;
				goto STEP_LOOP_END;
			}
			if(LD(R_FLAG_READY)){//检测准备状态
				SET(R_FLAG_BEEM);
				NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_INTO_READY;//进入准备状态
				goto STEP_LOOP_END;
			}
			goto STEP_LOOP_END;
		}
		if(NVRAM0[EM_STEP_NUM] == LASER_STEPNUM_INTO_READY){//第二步 等待1秒后进入
			T100MS(SPLC_100MS_INTOREADY_BEEM, true, 10);//启动1秒延时器	
			if(LD(T_100MS_START * 16 + SPLC_100MS_INTOREADY_BEEM)){//计时达到进入READY步骤
				SET(R_FLAG_BEEM);
				NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_READY;
				T100MS(SPLC_100MS_INTOREADY_BEEM, false, 10);//停止延时器
				goto STEP_LOOP_END;
			}
			goto STEP_LOOP_END;
		}
		if(NVRAM0[EM_STEP_NUM] == LASER_STEPNUM_READY){//第三步 准备状态 等待脚踏信号发射激光
			if(LD(R_FLAG_SAFE_FAULT) || LD(R_FLAG_TEMP_FAULT)){
				NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_FAULT;
				goto STEP_LOOP_END;
			}
			if(LDP(R_FLAG_FOOTSWITCH)){//检测footSwitch上升沿
				NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_LASERON;
				RES(R_FLAG_LASER_EMITOVER);//发射完成标志清零
				SET(R_FLAG_LASER_EMITING);//发射中标志置位
				//将激光功率值转换为电流值
				STLAR();//开始发射激光
				goto STEP_LOOP_END;
			}
			goto STEP_LOOP_END;
		}
		if(NVRAM0[EM_STEP_NUM] == LASER_STEPNUM_LASERON){
			if(LD(R_FLAG_SAFE_FAULT) || LD(R_FLAG_TEMP_FAULT)){
				NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_FAULT;
				goto STEP_LOOP_END;
			}
			if(LDB(R_FLAG_FOOTSWITCH)){//检测到脚踏复位
				EDLAR();//关闭激光
				SET(R_FLAG_LASER_EMITOVER);//发射完成标志清零
				RES(R_FLAG_LASER_EMITING);//发射中标志置位
				NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_FAULT;//返回READY步骤
				goto STEP_LOOP_END;
			}
			goto STEP_LOOP_END;
		}
		if(NVRAM0[EM_STEP_NUM] == LASER_STEPNUM_FAULT){//错误状态
			if(LDB(R_FLAG_SAFE_FAULT) && LDB(R_FLAG_TEMP_FAULT)){//错误已消除
				if(LD(R_LASER_ERROR_CLEAR)){//错误消除返回待机状态
					RES(R_LASER_ERROR_CLEAR);
					NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_STANDBY;
				}
				goto STEP_LOOP_END;
			}
			goto STEP_LOOP_END;
		}
STEP_LOOP_END:
		{}
}
		
//		if( my.triggerCW || !my.triggerSP || !my.triggerMP || !my.triggerGP || !my.triggerCC)
//		{//连续模式
//			if(!my.laserOnFlag)
//			{	
//				switch(my.selectChannel)
//				{
//					case ENUM_CHANNEL_BOTH:
//					{
//						DAC0 = laserCurrent[0];
//						DAC1 = laserCurrent[1];
//						break;
//					}
//					case ENUM_CHANNEL1:
//					{
//						DAC0 = laserCurrent[0];	
//						break;
//					}
//					case ENUM_CHANNEL2:
//					{
//						DAC1 = laserCurrent[1];
//						break;
//					}
//					default:break;
//				}
//				my.laserOnFlag = 1;
//			}
//			
//		}
//		if( my.triggerCW || !my.triggerSP || !my.triggerMP || !my.triggerGP || !my.triggerCC)
//		{//单脉冲模式
//			if(!my.laserOnFlag)
//			{
//				if(selectChannel == ENUM_CHANNEL_BOTH)
//				{
//					DAC0 = laserCurrent[0];
//					DAC1 = laserCurrent[1];
//				}
//				if(selectChannel == ENUM_CHANNEL1)
//				{
//					DAC0 = laserCurrent[0];
//				}
//				if(selectChannel = ENUM_CHANNEL2)
//				{
//					DAC1 = laserCurrent[1];
//				}
//				sTimerCtrl(STIMER_ON, STIMER_1MS_SP_LASER_ON, my.posWidth);
//				if(sTimer[STIMER_1MS_LASER_ON].status)
//				{
//					DAC0 = 0x0;
//					DAC1 = 0x0;
//					my.laserOnFlag = 0;
//					my.triggerSP = 0;
//					sTimerCtrl(STIMER_OFF, STIMER_1MS_SP_LASER_ON, my.posWidth);
//				}
//			}
//			
//		}
//		if( !my.triggerCW || !my.triggerSP || my.triggerMP || !my.triggerGP || !my.triggerCC)
//		{//多脉冲模式
//			if(my.laserOnFlag)
//			{//正脉宽计时
//				if(selectChannel == ENUM_CHANNEL_BOTH)
//				{
//					DAC0 = laserCurrent[0];
//					DAC1 = laserCurrent[1];
//				}
//				if(selectChannel == ENUM_CHANNEL1)
//				{
//					
//				}
//				if(selectChannel = ENUM_CHANNEL2)
//				{
//				}
//				sTimerCtrl(STIMER_ON, STIMER_1MS_LASER_ON, my.posWidth);
//				if(sTimer[STIMER_1MS_LASER_ON].status)
//				{
//					//关闭激光
//					//关闭计时器
//					my.laserOnFlag = 0;
//					sTimerCtrl(STIMER_OFF, STIMER_1MS_LASER_ON, my.posWidth);
//				}	
//			}
//			else if(!my.laserOnFlag)
//			{//负脉宽计时
//				sTimerCtrl(STIMER_ON, STIMER_1MS_LASER_OFF, my.negWidth);
//				if(sTimer[STIMER_1MS_LASER_OFF].status)
//				{
//					my.laserOnFlag = 1;
//					sTimerCtrl(STIMER_OFF, STIMER_1MS_LASER_ON, my.posWidth);
//				}
//			}
//		}
//		if( !my.triggerCW || !my.triggerSP || !my.triggerMP || !my.triggerGP || my.triggerCC)
//		{//校正模式
//			
//		}
//		
//		//Debug LED闪烁
//		if(LED_MCU)
//		{
//			if(sTimer[STIMER_1000MS_LED_ON].status)//等待时间A
//			{
//				LED_MCU = 0;
//				sTimerCtrl(STIMER_OFF, STIMER_1000MS_LED_ON, 1);
//			}
//			else
//				sTimerCtrl(STIMER_ON, STIMER_1000MS_LED_ON, 1);
//		}
//		if(!LED_MCU)
//		{
//			if(sTimer[STIMER_1000MS_LED_OFF].status)//等待时间B
//			{
//				LED_MCU = 1;
//				sTimerCtrl(STIMER_OFF, STIMER_1000MS_LED_OFF, 1);
//			}
//			else
//				sTimerCtrl(STIMER_ON, STIMER_1000MS_LED_OFF, 1);
//		}




static void STLAR(void){//开始发射脉冲
	uint8_t SFRPAGE_save;
	NVRAM0[EM_LASER_TMATE] = NVRAM0[EM_LASER_POSWIDTH];//设置匹配值
	NVRAM0[EM_LASER_TOVERFLOW] = ADD(NVRAM0[EM_LASER_POSWIDTH], NVRAM0[EM_LASER_POSWIDTH]);//设置溢出值
	NVRAM0[EM_LASER_TCOUNTER] = 0X00;	
	NVRAM0[EM_LASER_PMATE] = 0x00;//脉冲个数匹配值
	NVRAM0[EM_LASER_SMATE] = 0x0;//脉个数溢出值
	NVRAM0[EM_LASER_PCOUNTER] = 0X0;
	NVRAM0[EM_LASER_SCOUNTER] = 0X0;
#ifdef C8051F580
		SFRPAGE_save = SFRPAGE;
		SFRPAGE = ACTIVE_PAGE;
		TMR3CN &= ~(uint8_t)(1 << 7);//T3中断标志清零
		EIE1 |= (1 << 6);//T3 ET3中断使能
		TMR3L = 0xFF;
		TMR3H = 0xFF;
		TMR3CN |= (1 << 2);//TR3 使能TIMER3计时器
		SFRPAGE = SFRPAGE_save;
#endif
#ifdef C8051F020
		TMR3CN &= ~(uint8_t)(1 << 7);//TF3 溢出标志清零
		EIE2 |= (1 << 0);//T3 ET3中断使能
		TMR3L = 0xFF;
		TMR3H = 0xFF;
		TMR3CN |= (1 << 2);//TR3 使能TIMER3计时器
#endif
	SET(R_FLAG_LASER_EMITING);//发射标志置位
	RES(R_FLAG_LASER_EMITOVER);
}
static void EDLAR(void){//停止发射脉冲
#ifdef C8051F020
	TMR3CN &= ~(uint8_t)(1 << 2);//Stop Timer 3
	TMR3CN &= ~(uint8_t)(1 << 7);//Clear Timer 3 High Byte Overflow Flag.
	EIE1 &= ~(uint8_t)(1 << 6);//关闭Timer3中断
#endif
#ifdef C8051F580
	uint8_t SFRPAGE_save;
	SFRPAGE_save = SFRPAGE;
	SFRPAGE = ACTIVE_PAGE;
	TMR3CN &= ~(uint8_t)(1 << 2);//Stop Timer 3
	TMR3CN &= ~(uint8_t)(1 << 7);//Clear Timer 3 High Byte Overflow Flag.
	EIE1 &= ~(uint8_t)(1 << 6);//关闭Timer3中断
	SFRPAGE = SFRPAGE_save;
#endif
	//关闭DAC输出
	NVRAM0[SPREG_DAC_0] = 0;
	NVRAM0[SPREG_DAC_1] = 1;
	UPDAC(MCP47X6_LASER_CHANNEL_CH1);
	UPDAC(MCP47X6_LASER_CHANNEL_CH2);
	RES(R_FLAG_LASER_EMITING);//发射标志置位
}
void initTimer3(void){//TIMER3初始化
	
}
void timer3Isr(void) interrupt INTERRUPT_TIMER3{//TIMER3 中断 激光发射
	uint8_t SFRPAGE_save;
#ifdef C8051F580	
	SFRPAGE_save = SFRPAGE;
	SFRPAGE = ACTIVE_PAGE;
	TMR3CN &= ~(uint8_t)(1 << 7);//Clear Timer 3 High Byte Overflow Flag
	SFRPAGE = SFRPAGE_save;
#endif
#ifdef C8051F020
#endif
	switch(NVRAM0[EM_LASER_MODE]){
		case LASER_MODE_CW:{//CW连续模式
			if(LD(R_LASER_SELECT_CH1)){
				mcp47x6Write(MCP47X6_LASER_CHANNEL_CH1, NVRAM0[EM_LASER_CURRENT_CH1]);
			}
			else{
				mcp47x6Write(MCP47X6_LASER_CHANNEL_CH1, 0);
			}
			if(LD(R_LASER_SELECT_CH2)){
				mcp47x6Write(MCP47X6_LASER_CHANNEL_CH2, NVRAM0[EM_LASER_CURRENT_CH2]);
			}
			else{
				mcp47x6Write(MCP47X6_LASER_CHANNEL_CH2, 0);
			}
			break;
		}
		case LASER_MODE_SP:{//SP单脉冲模式
			break;
		}
		case LASER_MODE_MP:{//MP多脉冲模式	
			if(NVRAM0[EM_LASER_TCOUNTER] ==  NVRAM0[EM_LASER_TMATE]){//计时器匹配
				LASER_CH1_MODPIN_OFF;LASER_CH2_MODPIN_OFF;//翻转输出		
			}
			if(NVRAM0[EM_LASER_TCOUNTER] == NVRAM0[EM_LASER_TOVERFLOW]){//计时器溢出
				NVRAM0[EM_LASER_TCOUNTER] = 0;//清零
			}
			if(NVRAM0[EM_LASER_TCOUNTER] == 0){//翻转
				LASER_CH1_MODPIN_ON;LASER_CH2_MODPIN_ON;//翻转输出
			}
			NVRAM0[EM_LASER_TCOUNTER] ++;
			break;
		}
		case LASER_MODE_GP:{//GP可编程脉冲模式
			if(NVRAM0[EM_LASER_PCOUNTER] < NVRAM0[EM_START + EM_LASER_PMATE]){
				if(NVRAM0[EM_LASER_TCOUNTER] == 0){
					if(NVRAM0[EM_LASER_PCOUNTER] < NVRAM0[EM_LASER_PCOUNTER]){
						LASER_CH1_MODPIN_ON;LASER_CH2_MODPIN_ON;//翻转输出						
					}
				}
				if(NVRAM0[EM_LASER_TCOUNTER] == NVRAM0[EM_LASER_TMATE]){//计时器匹配
					LASER_CH1_MODPIN_OFF;LASER_CH2_MODPIN_OFF;//翻转输出	
				}
				if(NVRAM0[EM_LASER_TCOUNTER] == (NVRAM0[EM_LASER_TOVERFLOW] - 1)){//计时器溢出
					NVRAM0[EM_LASER_TCOUNTER] = 0xFFFF;//清零
					NVRAM0[EM_LASER_PCOUNTER] ++;//清零	
				}
				NVRAM0[EM_LASER_TCOUNTER] ++;
			}
			if((NVRAM0[EM_LASER_PCOUNTER] == NVRAM0[EM_LASER_PMATE]) && (NVRAM0[EM_LASER_TCOUNTER] == 0)){//脉冲个数发现匹配
				LASER_CH1_MODPIN_OFF;LASER_CH2_MODPIN_OFF;//翻转输出
				NVRAM0[EM_LASER_PCOUNTER] = 0xFFFF;
				NVRAM0[EM_LASER_SCOUNTER] = 0x0000;
			}
			if(NVRAM0[EM_LASER_PCOUNTER] == 0xFFFF){		
				if( NVRAM0[EM_LASER_SCOUNTER] == NVRAM0[EM_LASER_SMATE]){
					NVRAM0[EM_LASER_PCOUNTER] = 0;
				}
				NVRAM0[EM_LASER_SCOUNTER] ++;
			}
			break;
		}
		default:break;
	}
}
