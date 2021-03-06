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
void sPlcLaser(void){
	if(LD(SPCOIL_PSST)){//上电初始化STEPNUM
		NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_INIT;
	}
	if((NVRAM0[EM_DRIVER_TEMPERATURE] > NVRAM0[DM_DRIVE_PROTECT_HTEMP]) && LDF(R_FLAG_DRIVER_TEMP_FAULT_IGNORE)){
		SET(R_FLAG_DRIVER_HTEMP_FAULT);
	}
	else{
		RES(R_FLAG_DRIVER_HTEMP_FAULT);
	}
	if((NVRAM0[EM_DRIVER_TEMPERATURE] < NVRAM0[DM_DRIVE_PROTECT_LTEMP]) && LDF(R_FLAG_DRIVER_TEMP_FAULT_IGNORE)){
		SET(R_FLAG_DRIVER_LTEMP_FAULT);
	}
	else{
		RES(R_FLAG_DRIVER_LTEMP_FAULT);
	}
	if((NVRAM0[EM_MCHIP_TEMPERATURE] > NVRAM0[DM_MCHIP_PROTECT_HTEMP]) && LDF(R_FLAG_MCHIP_TEMP_FAULT_IGNORE)){
		SET(R_FLAG_MCHIP_HTEMP_FAULT);
	}
	else{
		RES(R_FLAG_MCHIP_HTEMP_FAULT);
	}
	if((NVRAM0[EM_MCHIP_TEMPERATURE] < NVRAM0[DM_MCHIP_PROTECT_LTEMP]) && LDF(R_FLAG_MCHIP_TEMP_FAULT_IGNORE)){
		SET(R_FLAG_MCHIP_HTEMP_FAULT);
	}
	else{
		RES(R_FLAG_MCHIP_HTEMP_FAULT);
	}
	if((NVRAM0[EM_LASER_TEMPERATURE] > NVRAM0[DM_LASER_PROTECT_HTEMP]) && LDF(R_FLAG_LASER_TEMP_FAULT_IGNORE)){
		SET(R_FLAG_LASER_HTEMP_FAULT);
	}
	else{
		RES(R_FLAG_LASER_HTEMP_FAULT);
	}
	if((NVRAM0[EM_LASER_TEMPERATURE] < NVRAM0[DM_LASER_PROTCET_LTEMP]) && LDF(R_FLAG_LASER_TEMP_FAULT_IGNORE)){
		SET(R_FLAG_LASER_LTEMP_FAULT);
	}
	else{
		RES(R_FLAG_LASER_LTEMP_FAULT);
	}
		
	if(LD(R_FLAG_DRIVER_LTEMP_FAULT) || 
	   LD(R_FLAG_DRIVER_HTEMP_FAULT) || 
	   LD(R_FLAG_MCHIP_LTEMP_FAULT) ||
	   LD(R_FLAG_MCHIP_HTEMP_FAULT) || 
	   LD(R_FLAG_LASER_LTEMP_FAULT) ||
	   LD(R_FLAG_LASER_HTEMP_FAULT)){
		SET(R_FLAG_TEMP_FAULT);
	}
	else{
		RES(R_FLAG_TEMP_FAULT);
	}
	if(LDF(X_MECH_FIBER_DETECT)){
		SET(R_FLAG_FIBER_MECH_DETECT);
	}
	else{
		RES(R_FLAG_FIBER_MECH_DETECT);
	}
	if(LD(R_FLAG_FIBER_MECH_DETECT) && LDF(R_FLAG_FIBER_MECH_DETECT)){
		SET(R_FLAG_SAFE_FAULT);
	}
	else{
		RES(R_FLAG_SAFE_FAULT);
	}

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
void initTimer2(void){//TIMER3初始化
	
}
void timer2Isr(void) interrupt INTERRUPT_TIMER2{//TIMER3 中断 激光发射
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
