#include "sPlcLaser.h"
/*****************************************************************************/
sbit LASER_CH0_MODPIN = P2^7;
sbit LASER_CH1_MODPIN = P2^6;
int32_t LaserReleaseTime;//激光发射时间
int32_t BeemChangeEnergy;//蜂鸣器频率改变能量
/*****************************************************************************/
static void initTimer4(void);
/*****************************************************************************/
#if CONFIG_SPLC_USING_LASER_TIMER_TEST == 1
void testBenchLaserTimer(uint8_t st){//LASER激光发射测试
	EDLAR();
	if(st == 0){//CH0 CW模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_CW;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH0;
		STLAR();
	}
	if(st == 1){//CH1 CW模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_CW;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH1;
		STLAR();
	}
	if(st == 2){//CH0+CH1 CW模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_CW;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		STLAR();
	}
	if(st == 3){//CH0 SP模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH0;
		NVRAM0[SPREG_LASER_TMATE] = 50;//激光脉冲正脉宽 10mS
		STLAR();
	}
	if(st == 4){//CH1 SP模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH1;
		NVRAM0[SPREG_LASER_TMATE] = 25;//激光脉冲正脉宽 10mS
		STLAR();
	}
	if(st == 5){//CH0+CH1 SP模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		NVRAM0[SPREG_LASER_TMATE] = 30;//激光脉冲正脉宽 10mS
		STLAR();
	}
	if(st == 6){//CH0 MP模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_MP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH0;
		NVRAM0[SPREG_LASER_TMATE] = 30;//激光脉冲正脉宽 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 90;//激光脉冲周期 25mS
		STLAR();
	}
	if(st == 7){//CH1 MP模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_MP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH1;
		NVRAM0[SPREG_LASER_TMATE] = 74;//激光脉冲正脉宽 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 96;//激光脉冲周期 25mS
		STLAR();
	}
	if(st == 8){//CH0+CH1 MP模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_MP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		NVRAM0[SPREG_LASER_TMATE] = 53;//激光脉冲正脉宽 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 130;//激光脉冲周期 25mS
		STLAR();
	}
	if(st == 9){//CH0 GP模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_GP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH0;
		NVRAM0[SPREG_LASER_TMATE] = 10;//激光脉冲正脉宽 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 15;//激光脉冲周期 25mS
		NVRAM0[SPREG_LASER_PMATE] = 10;//10个脉冲
		NVRAM0[SPREG_LASER_POVERTIME] = 33;//间隔33mS
		STLAR();
	}
	if(st == 10){//CH1 GP模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_GP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH1;
		NVRAM0[SPREG_LASER_TMATE] = 19;//激光脉冲正脉宽 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 86;//激光脉冲周期 25mS
		NVRAM0[SPREG_LASER_PMATE] = 12;//10个脉冲
		NVRAM0[SPREG_LASER_POVERTIME] = 43;//间隔33mS
		STLAR();
	}
	if(st == 11){//CH0+CH1 GP模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_GP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		NVRAM0[SPREG_LASER_TMATE] = 5;//激光脉冲正脉宽 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 24;//激光脉冲周期 25mS
		NVRAM0[SPREG_LASER_PMATE] = 6;//10个脉冲
		NVRAM0[SPREG_LASER_POVERTIME] = 60;//间隔33mS
		STLAR();
	}	
	if(st == 12){//CH0 DERMA模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_DERMA;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH0;
		NVRAM0[SPREG_LASER_TMATE] = 10;//激光脉冲正脉宽 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 15;//激光脉冲周期 25mS
		STLAR();
	}
	if(st == 13){//CH1 DERMA模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_DERMA;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH1;
		NVRAM0[SPREG_LASER_TMATE] = 19;//激光脉冲正脉宽 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 86;//激光脉冲周期 25mS
		STLAR();
	}
	if(st == 14){//CH0+CH1 DERMA模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_DERMA;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		NVRAM0[SPREG_LASER_TMATE] = 5;//激光脉冲正脉宽 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 24;//激光脉冲周期 25mS
		STLAR();
	}	
	if(st == 15){//CH0 SIGNAL模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SIGNAL;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH0;
		NVRAM0[SPREG_LASER_TMATE] = 10;//激光脉冲正脉宽 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 15;//激光脉冲周期 25mS
		STLAR();
	}
	if(st == 16){//CH1 SIGNAL模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SIGNAL;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH1;
		STLAR();
	}
	if(st == 17){//CH0+CH1 SIGNAL模式测试
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SIGNAL;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		STLAR();
	}
}

#endif
void STLAR(void){//开始发射脉冲
#if CONFIG_SPLC_USING_LASER_TIMER == 1	
	uint8_t SFRPAGE_save;
	if((NVRAM0[DM_BEEM_MODE] == BEEM_MODE_SYNC) || (NVRAM0[EM_LASER_PULSE_MODE] == LASER_MODE_SIGNAL)){
		NVRAM0[SPREG_BEEM_MODE] = BEEM_MODE_1;	
	}
	else{
		NVRAM0[SPREG_BEEM_MODE] = BEEM_MODE_2;
	}
	NVRAM0[SPREG_BEEM_FREQ] = BEEM_FREQ_0;
	NVRAM0[SPREG_BEEM_VOLUME] = NVRAM0[DM_BEEM_VOLUME];
	SET(SPCOIL_BEEM_ENABLE);
	SET(SPCOIL_LASER_EMITING);//发射标志置位
	RES(SPCOIL_LASER_EMITOVER);
	NVRAM0[SPREG_LASER_PCOUNTER] = 0X0;
	NVRAM0[SPREG_LASER_TCOUNTER] = 0X00;	
	SFRPAGE_save = SFRPAGE;
	SFRPAGE = TMR4_PAGE;
	TMR4CN &= ~(uint8_t)(1 << 7);//TF4 溢出标志清零
	EIE2 |= (1 << 2);//T4 ET3中断使能
	TMR4L = 0xFF;
	TMR4H = 0xFF;
	TMR4CN |= (1 << 2);//TR3 使能TIMER3计时器
	SFRPAGE = SFRPAGE_save;
#endif
}
void EDLAR(void){//停止发射脉冲
#if CONFIG_SPLC_USING_LASER_TIMER == 1 	
	uint8_t SFRPAGE_save;
	SFRPAGE = TMR4_PAGE;
	TMR4CN &= ~(uint8_t)(1 << 2);//Stop Timer 4
	TMR4CN &= ~(uint8_t)(1 << 7);//Clear Timer 4 High Byte Overflow Flag.
	EIE2 &= ~(uint8_t)(1 << 2);//关闭Timer4中断
	SFRPAGE = SFRPAGE_save;
	//关闭DAC输出
#if CONFIG_SPLC_USING_DAC == 1
	CLDAC();
#endif
	RES(SPCOIL_LASER_EMITING);//发射标志置位
#endif
}
void sPlcLaserInit(void){//激光脉冲功能初始化
#if CONFIG_SPLC_USING_LASER_TIMER ==1
	uint16_t temp;
	uint8_t SFRPAGE_SAVE;
	LASER_CH0_MODPIN = 0;
	LASER_CH1_MODPIN = 0;
	SFRPAGE = TMR4_PAGE;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 12 / CONFIG_LASER_TIMER_TICK));
	TMR4CF = 0;//	
	RCAP4 = temp;// Reload value to be used in Timer3
	TMR4 = RCAP4;// Init the Timer3 register
	TMR4CN = 0;//16Bit AutoReload
	RES(SPCOIL_LASER_DRIVER_INIT_FAIL);
	SFRPAGE = SFRPAGE_SAVE; 
#endif
}
static void laserStart(void){//按通道选择打开激光
	switch(NVRAM0[SPREG_LASER_SELECT]){
		case LASER_SELECT_CH0:{//0激光通道
#if CONFIG_SPLC_USING_DAC == 1
			UPDAC0();//DAC立即输出计时器值
#endif
			LASER_CH0_MODPIN = true; 
			LASER_CH1_MODPIN = false;
			break;
		}
		case LASER_SELECT_CH1:{ 
#if CONFIG_SPLC_USING_DAC == 1
			UPDAC1();//DAC立即输出计时器值
#endif
			LASER_CH0_MODPIN = false;
			LASER_CH1_MODPIN = true;
			break;
		}
		case LASER_SELECT_BOTH:{
#if CONFIG_SPLC_USING_DAC == 1
			UPDAC0();//DAC立即输出计时器值
			UPDAC1();//DAC立即输出计时器值
#endif
			LASER_CH0_MODPIN = true; 
			LASER_CH1_MODPIN = true; 
			break;
		}
	}
}
static void laserStop(void){//按通道选择关闭激光
#if CONFIG_SPLC_USING_DAC == 1
	CLDAC();//DAC立即输出计时器值
#endif
	LASER_CH0_MODPIN = false;
	LASER_CH1_MODPIN = false;//翻转输出	
	setLedEmit(false);	
}
void laserTimerIsr(void) interrupt INTERRUPT_TIMER4{//TIMER4 中断 激光发射	
	TMR4CN &= ~(uint8_t)(1 << 7);//Clear Timer 4 High Byte Overflow Flag
	switch(NVRAM0[SPREG_LASER_MODE]){
		case LASER_MODE_CW:{//CW连续模式
			if(NVRAM0[SPREG_LASER_TCOUNTER] == 0){
				laserStart();	
				NVRAM0[SPREG_LASER_TCOUNTER] ++;
			}
			else{
				if(LaserReleaseTime < 1000){
					LaserReleaseTime ++;//发射时间累计
				}
				else{
					LaserReleaseTime = 0;
					ADDS1(EM_RELEASE_TOTAL_TIME);
				}
			}
			break;
		}
		case LASER_MODE_SIGNAL:{
			if(NVRAM0[SPREG_LASER_TCOUNTER] == 0){
				laserStart();
				NVRAM0[SPREG_LASER_TCOUNTER] ++;
				BeemChangeEnergy = 0;
			}
			else{
				BeemChangeEnergy += 1;
				if(LaserReleaseTime < 1000){
					LaserReleaseTime ++;//发射时间累计
				}
				else{
					LaserReleaseTime = 0;
					ADDS1(EM_RELEASE_TOTAL_TIME);
				}
				if(BeemChangeEnergy >= NVRAM0[EM_LASER_SIGNAL_TIME_INTERVAL]){
					BeemChangeEnergy = 0;
					if(NVRAM0[SPREG_BEEM_FREQ] == BEEM_FREQ_0){
						NVRAM0[SPREG_BEEM_FREQ] = BEEM_FREQ_1;
					}
					else{
						NVRAM0[SPREG_BEEM_FREQ] = BEEM_FREQ_0;
					}
				}
			}		
			NVRAM0[SPREG_LASER_TCOUNTER] ++;
			break;
		}
		case LASER_MODE_DERMA:{//与MP模式相同
		}
		case LASER_MODE_MP:{//MP多脉冲模式	
			if(NVRAM0[SPREG_LASER_TCOUNTER] == 0){//翻转
				laserStart();
			}
			if((NVRAM0[SPREG_LASER_TCOUNTER] > 0) && (NVRAM0[SPREG_LASER_TCOUNTER] < NVRAM0[SPREG_LASER_TMATE])){//激光发射中
				if(LaserReleaseTime < 1000){
					LaserReleaseTime ++;//发射时间累计
				}
				else{
					LaserReleaseTime = 0;
					ADDS1(EM_RELEASE_TOTAL_TIME);
				}
			}
			if(NVRAM0[SPREG_LASER_TCOUNTER] == NVRAM0[SPREG_LASER_TMATE]){//计时器匹配
				laserStop();
				if(LaserReleaseTime < 1000){
					LaserReleaseTime ++;//发射时间累计
				}
				else{
					LaserReleaseTime = 0;
					ADDS1(EM_RELEASE_TOTAL_TIME);
				}
				
			}
			if(NVRAM0[SPREG_LASER_TCOUNTER] >= NVRAM0[SPREG_LASER_TOVERTIME]){//计时器溢出
				NVRAM0[SPREG_LASER_TCOUNTER] = -1;//清零
			}
			NVRAM0[SPREG_LASER_TCOUNTER] ++;
			break;
		}
		case LASER_MODE_GP:{//GP可编程脉冲模式
			if(NVRAM0[SPREG_LASER_PCOUNTER] < NVRAM0[SPREG_LASER_PMATE]){//脉冲串输出
				if(NVRAM0[SPREG_LASER_TCOUNTER] == 0){//翻转	
					laserStart();
				}
				if((NVRAM0[SPREG_LASER_TCOUNTER] > 0) && (NVRAM0[SPREG_LASER_TCOUNTER] < NVRAM0[SPREG_LASER_PMATE])){//激光发射中
					if(LaserReleaseTime < 1000){
						LaserReleaseTime ++;//发射时间累计
					}
					else{
						LaserReleaseTime = 0;
						ADDS1(EM_RELEASE_TOTAL_TIME);
					}
				}
				if(NVRAM0[SPREG_LASER_TCOUNTER] == NVRAM0[SPREG_LASER_TMATE]){//计时器匹配
					laserStop();
					if(LaserReleaseTime < 1000){
						LaserReleaseTime ++;//发射时间累计
					}
					else{
						LaserReleaseTime = 0;
						ADDS1(EM_RELEASE_TOTAL_TIME);
					}
				}
				if(NVRAM0[SPREG_LASER_TCOUNTER] >= NVRAM0[SPREG_LASER_TOVERTIME]){//计时器溢出
					NVRAM0[SPREG_LASER_TCOUNTER] = -1;//清零
					NVRAM0[SPREG_LASER_PCOUNTER] ++;
				}
				NVRAM0[SPREG_LASER_TCOUNTER] ++;
			}
			if(NVRAM0[SPREG_LASER_PCOUNTER] >= NVRAM0[SPREG_LASER_PMATE]){//多脉冲间隔		
				if(NVRAM0[SPREG_LASER_PCOUNTER] >= (NVRAM0[SPREG_LASER_POVERTIME] + NVRAM0[SPREG_LASER_PMATE])){//脉冲个数发现匹配
					NVRAM0[SPREG_LASER_PCOUNTER] = -1;
					NVRAM0[SPREG_LASER_TCOUNTER] = 0;
				}
				NVRAM0[SPREG_LASER_PCOUNTER] ++;
			}
			break;
		}
		case LASER_MODE_SP:{//单脉冲模式
			if(NVRAM0[SPREG_LASER_TCOUNTER] == 0){//翻转	
				laserStart();
			}
			if((NVRAM0[SPREG_LASER_TCOUNTER] > 0) && (NVRAM0[SPREG_LASER_TCOUNTER] < NVRAM0[SPREG_LASER_TMATE])){
				if(LaserReleaseTime < 1000){
					LaserReleaseTime ++;//发射时间累计
				}
				else{
					LaserReleaseTime = 0;
					ADDS1(EM_RELEASE_TOTAL_TIME);
				}
			}
			if(NVRAM0[SPREG_LASER_TCOUNTER] >= NVRAM0[SPREG_LASER_TMATE]){//计时器匹配
				laserStop();
				if(LaserReleaseTime < 1000){
					LaserReleaseTime ++;//发射时间累计
				}
				else{
					LaserReleaseTime = 0;
					ADDS1(EM_RELEASE_TOTAL_TIME);
				}
				EDLAR();
			}
			NVRAM0[SPREG_LASER_TCOUNTER] ++;
			break;
		}
		default:break;
	}
}