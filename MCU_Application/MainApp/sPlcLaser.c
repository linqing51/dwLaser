#include "sPlcLaser.h"
/*****************************************************************************/
#define MCP47X6_LASER_CHANNEL_CH1				0
#define MCP47X6_LASER_CHANNEL_CH2				1
#define LASER_CHANNEL_BOTH				9431
#define LASER_MODE_CW					0//连续模式
#define LASER_MODE_SP					1//单脉冲模式
#define LASER_MODE_MP					2//多脉冲模式
#define LASER_MODE_GP					3//群脉冲模式
#define LASER_MODE_CC					4//校正模式




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
//		STEP_LOOP_START:
//		if(my.stepNum == STEPNUM_INIT)
//		{//初始化
//			my.stepNum = STEPNUM_STANDBY;//Goto next step
//			goto STEP_LOOP_END;
//		}
//		if(my.stepNum == STEPNUM_STANDBY)
//		{//第一步 待机状态->蜂鸣器提示
//			if(my.safeFault ||
//               my.overTempFault)
//			{
//				my.stepNum = STEPNUM_FAULT;
//			}
//			else if(my.readyFlag)
//			{
//				my.beemOn = true;
//				my.stepNum = STEPNUM_INTO_READY;
//			}
//			else
//			{
//				my.stepNum = STEPNUM_STANDBY;
//			}
//			goto STEP_LOOP_END;
//		}
//		if(my.stepNum == STEPNUM_INTO_READY)
//		{//第二步 等待1秒后进入
//			if(my.readyFlag)
//			{
//				my.beemOn = true;
//				sTimerCtrl(STIMER_ON, STIMER_100MS_INTOREADY_BEEM, 10);
//				if(sTimer[STIMER_100MS_INTOREADY_BEEM].status)
//				{//计时达到进入READY步骤
//					sTimerCtrl(STIMER_OFF, STIMER_100MS_INTOREADY_BEEM, 10);
//					my.beemOn = false;
//					my.stepNum = STEPNUM_READY;
//				}
//			}
//			goto STEP_LOOP_END;
//		}
//		if(my.stepNum == STEPNUM_READY)
//		{//第三步 准备状态 等待脚踏信号发射激光
//			if(my.safeFault ||
//               my.overTempFault)
//			{
//				my.stepNum = STEPNUM_FAULT;
//			}
//			else if((my.footSwitch && 0x01) &&
//				    !(my.footSwitch && 0x02))//检测footSwitch上升沿
//			{//发射激光步骤
//				//打开激光
//				my.stepNum = STEPNUM_LASERON;
//				my.laserEmitOver = 0x0;//发射完成标志清零
//				switch(my.laserMode)
//				{
//					case ENUM_MODE_CW:
//					{
//						my.laserEmiting |=  1 << ENUM_MODE_CW;
//						break;
//					}
//					case ENUM_MODE_SP:
//					{
//						my.laserEmiting |=  1 << ENUM_MODE_SP;
//						break;
//					}
//					case ENUM_MODE_MP:
//					{
//						my.laserEmiting |=  1 << ENUM_MODE_MP;
//						break;
//					}
//					case ENUM_MODE_GP:
//					{
//						my.laserEmiting |=  1 << ENUM_MODE_GP;
//						break;
//					}
//					case ENUM_MODE_CC:
//					{
//						my.laserEmiting |=  1 << ENUM_MODE_CC;
//						break;
//					}
//					default:break;
//				}
//			}
//			goto STEP_LOOP_END;
//		}
//		if(my.stepNum == STEPNUM_LASERON)
//		{
//			if(my.safeFault || my.overTempFault)
//			{//故障:
//				my.stepNum = STEPNUM_FAULT;
//			}
//			else if(!(my.footSwitch & 0x01))//脚踏复位
//			{
//				//关闭激光
//				my.stepNum = STEPNUM_READY;//返回READY步骤
//			}
//			else
//			{
//				if( my.laserEmiting == ENUM_MODE_CW)
//				{//连续模式
//					switch(my.selectChannel)
//					{
//						case ENUM_CHANNEL_BOTH:
//						{
//							upDateDac0(laserCurrent[0]);
//							upDateDac1(laserCurrent[1]);
//							break;
//						}
//						case ENUM_CHANNEL1:
//						{
//							upDateDac0(laserCurrent[0]);
//							break;
//						}
//						case ENUM_CHANNEL2:
//						{
//							upDateDac1(laserCurrent[1]);
//							break;
//						}
//						default:break;
//					}
//				}
//				if( my.laserEmiting == ENUM_MODE_SP )
//				{//单脉冲模式
//					if(selectChannel == ENUM_CHANNEL_BOTH)
//					{
//						upDateDac0(laserCurrent[0]);
//						upDateDac1(laserCurrent[1]);
//					}
//					if(selectChannel == ENUM_CHANNEL1)
//					{
//						upDateDac0(laserCurrent[0]);
//					}
//					if(selectChannel = ENUM_CHANNEL2)
//					{
//						upDateDac1(laserCurrent[1]);
//					}
//					sTimerCtrl(STIMER_ON, STIMER_1MS_SP_LASER_ON, my.posWidth);
//					if(sTimer[STIMER_1MS_LASER_ON].status)
//					{
//						upDateDac0(0x0);
//						upDateDac1(0x0);
//						my.laserEmiting &=  ~(1<< ENUM_MODE_CW);//发射完成清空正在发射标志位
//						my.laserEmitOver |= 1 << ENUM_MODE_CW;//发射完成标志位置位
//						sTimerCtrl(STIMER_OFF, STIMER_1MS_SP_LASER_ON, my.posWidth);
//					}
//				}	
//				if( my.laserEmiting == ENUM_MODE_MP )
//				{//多脉冲模式
//					if(!sTimer[STIMER_1MS_LASER_ON].enable)
//					{//正脉宽计时
//					if(selectChannel == ENUM_CHANNEL_BOTH)
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
//			}
//			goto STEP_LOOP_END;
//		}
//		if(my.stepNum == STEPNUM_FAULT)
//		{//错误状态
//			//关闭激光
//			if(!my.safeFault &&
//               !my.overTempFault)
//			{//错误消除
//				if(my.clearError)
//				{//错误消除返回待机状态
//					my.clearError = 0;
//					my.stepNum = STEPNUM_STANDBY;
//				}
//			}
//			else
//			{
//				my.stepNum = STEPNUM_FAULT;
//			}
//			goto STEP_LOOP_END;
//		}
//		STEP_LOOP_END:
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




void startLaser(void){//开始发射脉冲
#ifdef C8051F580	
	uint8_t SFRPAGE_save;
#endif
	if(NVRAM0[EM_START + EM_LASER_MODE] == LASER_MODE_CW ){
		NVRAM0[SPREG_START + SPREG_DAC_0] = NVRAM0[EM_START + EM_LASER_CURRENT_CH1];
		NVRAM0[SPREG_START + SPREG_DAC_1] = NVRAM0[EM_START + EM_LASER_CURRENT_CH2];
		UPDAC(0);UPDAC(1);//立即更新DAC
	}
	else if((NVRAM0[EM_START + EM_LASER_MODE] == LASER_MODE_SP) | 
			(NVRAM0[EM_START + EM_LASER_MODE] == LASER_MODE_MP) |
			(NVRAM0[EM_START + EM_LASER_MODE] == LASER_MODE_GP)){
		NVRAM0[EM_START + EM_LASER_TMATE] = NVRAM0[EM_LASER_POSWIDTH];//设置匹配值
		NVRAM0[EM_START + EM_LASER_TOVERFLOW] = ADD(NVRAM0[EM_LASER_POSWIDTH], NVRAM0[EM_LASER_POSWIDTH]);//设置溢出值
		NVRAM0[EM_START + EM_LASER_TCOUNTER] = 0X00;	
		NVRAM0[EM_START + EM_LASER_PMATE] = 0x00;//脉冲个数匹配值
		NVRAM0[EM_START + EM_LASER_SMATE] = 0x0;//脉个数溢出值
		NVRAM0[EM_START + EM_LASER_PCOUNTER] = 0X0;
		NVRAM0[EM_START + EM_LASER_SCOUNTER] = 0X0;
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
	}
	else if(NVRAM0[EM_START + EM_LASER_MODE] == LASER_MODE_CC)
	{//校正模式
		NVRAM0[EM_START + EM_LASER_TMATE] = NVRAM0[EM_LASER_POSWIDTH];//设置匹配值
		NVRAM0[EM_START + EM_LASER_TOVERFLOW] = ADD(NVRAM0[EM_LASER_POSWIDTH], NVRAM0[EM_LASER_POSWIDTH]);//设置溢出值
		NVRAM0[EM_START + EM_LASER_TCOUNTER] = 0X00;	
		NVRAM0[EM_START + EM_LASER_PMATE] = NVRAM0[EM_START + EM_LASER_GROUP_NUM];//脉冲个数匹配值
		NVRAM0[EM_START + EM_LASER_SMATE] = NVRAM0[EM_START + EM_LASER_GROUP_SPACE];//脉个数溢出值
		NVRAM0[EM_START + EM_LASER_PCOUNTER] = 0X0;
		NVRAM0[EM_START + EM_LASER_SCOUNTER] = 0X0;	
#ifdef C8051F580
		SFRPAGE_save = SFRPAGE;
		SFRPAGE = ACTIVE_PAGE;
		TMR3CN &= ~(uint8_t)(1 << 7);//TF3 溢出标志清零
		EIE2 |= (1 << 0);//T3 ET3中断使能
		TMR3L = 0xFF;
		TMR3L = 0xFF;
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
	}
	SET(R_START * 16+ R_FLAG_LASER_EMITING);//发射标志置位
}
static void stopLaser(void){//停止发射脉冲
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
	NVRAM0[SPREG_START + SPREG_DAC_0] = 0;
	NVRAM0[SPREG_START + SPREG_DAC_1] = 1;
	UPDAC(MCP47X6_LASER_CHANNEL_CH1);
	UPDAC(MCP47X6_LASER_CHANNEL_CH2);
	RESET(R_START * 16+ R_FLAG_LASER_EMITING);//发射标志置位
}
static void setLaserModCh1(uint8_t st){//CH1调制控制
	if(st){
		P4 |= (uint8_t)(1 << 6);
	}
	else{
		P4 &= ~(uint8_t)(1 << 6);
	}
}
static void setLaserModCh2(uint8_t st){//CH2调制控制
	if(st){
		P4 |= (uint8_t)(1 << 1);
	}
	else{
		P4 &= ~(uint8_t)(1 << 1);
	}
}
static void setLaserModBoth(uint8_t st){////CH1+CH2调制控制
	if(st){
		P4 |= (uint8_t)(1 << 6);
		P4 |= (uint8_t)(1 << 1);
	}
	else{
		P4 &= ~(uint8_t)(1 << 6);
		P4 &= ~(uint8_t)(1 << 1);
	}
}
static void setLaserCurrent(void){//设置DAC输出
	if(LD(R_START * 16 + R_LASER_SELECT_CH1)){
		mcp47x6Write(MCP47X6_LASER_CHANNEL_CH1, NVRAM0[EM_START + EM_LASER_CURRENT_CH1]);
	}
	else{
		mcp47x6Write(MCP47X6_LASER_CHANNEL_CH1, 0);
	}
	if(LD(R_START * 16 + R_LASER_SELECT_CH2)){
		mcp47x6Write(MCP47X6_LASER_CHANNEL_CH2, NVRAM0[EM_START + EM_LASER_CURRENT_CH2]);
	}
	else{
		mcp47x6Write(MCP47X6_LASER_CHANNEL_CH2, 0);
	}
}

void initTimer3(void){//TIMER3初始化
	
}
void timer3Isr(void) interrupt INTERRUPT_TIMER3{//TIMER3 中断 激光发射
#ifdef C8051F580
	uint8_t SFRPAGE_save;
	SFRPAGE_save = SFRPAGE;
	TMR3CN &= ~(uint8_t)(1 << 7);//Clear Timer 3 High Byte Overflow Flag
	SFRPAGE = SFRPAGE_save;
#endif
#ifdef C8051F020
#endif
	switch(NVRAM0[EM_START + EM_LASER_MODE){
		case LASER_MODE_CW:{//CW连续模式
			SetLaserCurrent();
			break;
		}
		case LASER_MODE_SP:{//SP单脉冲模式
			break;
		}
		case LASER_MODE_MP:{//MP多脉冲模式	
			if(p->softTimer.tCounter == p->softTimer.tMate){//计时器匹配
				setLaserModBoth(LASER_OFF);//翻转输出
			}
			if(p->softTimer.tCounter == p->softTimer.tOverflow){//计时器溢出
				p->softTimer.tCounter = 0;//清零
			}
			if(p->softTimer.tCounter == 0){//翻转
				setLaserModBoth(LASER_ON);//翻转输出
			}
			p->softTimer.tCounter ++;
			break;
		}
		case LASER_MODE_GP:{//GP可编程脉冲模式
			if(p->softTimer.pCounter < p->softTimer.pMate){
				if(p->softTimer.tCounter == 0){
					if(p->softTimer.pCounter < p->softTimer.pMate){
						setLaserModBoth(LASER_ON);//翻转输出						
					}
				}
				if(p->softTimer.tCounter == p->softTimer.tMate){//计时器匹配
					setLaserModBoth(LASER_OFF);//翻转输出
				}
				if(p->softTimer.tCounter == (p->softTimer.tOverflow - 1)){//计时器溢出
					p->softTimer.tCounter = 0xFFFF;//清零
					p->softTimer.pCounter ++;//清零	
				}
				p->softTimer.tCounter ++;
			}
			if(p->softTimer.pCounter == p->softTimer.pMate && p->softTimer.tCounter == 0){//脉冲个数发现匹配
				LaserMod_PIN = LASER_OFF;
				p->softTimer.pCounter = 0xFFFF;
				p->softTimer.sCounter = 0x0;
			}
			if(p->softTimer.pCounter == 0xFFFF){		
				if(p->softTimer.sCounter == p->softTimer.sMate){
					p->softTimer.pCounter = 0;	
				}
				p->softTimer.sCounter ++;
			}
			break;
		}
		default:break;
	}
}
