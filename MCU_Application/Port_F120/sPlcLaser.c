#include "sPlcLaser.h"
/*****************************************************************************/
sbit LASER_CH0_MODPIN = P2^7;
sbit LASER_CH1_MODPIN = P2^6;
volatile int8_t data LaserTimer_Mode;
volatile int8_t data LaserTimer_Select;
volatile int16_t data LaserTimer_TCounter;
volatile int16_t data LaserTimer_TMate;
volatile int16_t data LaserTimer_TOvertime;
volatile int16_t data LaserTimer_PCounter;
volatile int16_t data LaserTimer_PMate;
volatile int16_t data LaserTimer_POvertime;
volatile int16_t data LaserTimer_ReleaseTime;
volatile int16_t data LaserTimer_ReleaseCounter;
volatile int16_t data LaserTimer_BeemSwitchCounter;
volatile int16_t data LaserTimer_BeemSwtichLength;
/*****************************************************************************/
static void initTimer4(void);
static void laserStop(void);
static void laserStart(void);
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
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_ALL;
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
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_ALL;
		NVRAM0[SPREG_LASER_TMATE] = 30;//激光脉冲正脉宽 10mS
		STLAR();
	}
	if(st == 6){//CH0 MP模式测试
		LaserTimer_Mode = LASER_MODE_MP;
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
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_ALL;
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
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_ALL;
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
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_ALL;
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
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_ALL;
		STLAR();
	}
}

#endif
void STLAR(void){//开始发射脉冲
#if CONFIG_SPLC_USING_LASER_TIMER == 1	
	uint8_t SFRPAGE_save;		
	if(LD(MR_BEEM_TONE) || (LaserTimer_Mode == LASER_MODE_SIGNAL)){
		BeemMode = BEEM_MODE_1;	
	}
	else{
		BeemMode = BEEM_MODE_2;
	}
	BeemFreq = BEEM_FREQ_0;
	BeemDuty = getBeemDuty(NVRAM0[DM_BEEM_VOLUME]);
	BeemCounter = 0;
	BeemEnable = true;
	SET(SPCOIL_LASER_EMITING);//发射标志置位
	RES(SPCOIL_LASER_EMITOVER);
	LaserTimer_TCounter = 0X0;
	LaserTimer_PCounter = 0X0;
	LaserTimer_ReleaseCounter = 0x0;
	LaserTimer_BeemSwitchCounter = 0x0;	
	SFRPAGE_save = SFRPAGE;
	SFRPAGE = TMR4_PAGE;
	TMR4CN &= ~(uint8_t)(1 << 7);//TF4 溢出标志清零
	EIE2 |= (1 << 2);//T4 ET3中断使能
	TMR4L = 0xFF;
	TMR4H = 0xFF;
	TMR4CN |= (1 << 2);//TR4 使能TIMER4计时器
	SFRPAGE = SFRPAGE_save;
#endif
}
void EDLAR(void) reentrant {//停止发射脉冲
#if CONFIG_SPLC_USING_LASER_TIMER == 1 	
	uint8_t SFRPAGE_save;
	SFRPAGE = TMR4_PAGE;	
	TMR4CN &= ~(uint8_t)(1 << 2);//Stop Timer 4
	EIE2 &= ~(uint8_t)(1 << 2);//关闭Timer4中断
	TMR4CN &= ~(uint8_t)(1 << 7);//Clear Timer 4 High Byte Overflow Flag.
	SFRPAGE = SFRPAGE_save;
	laserStop();//关闭DAC输出
	LaserTimer_TCounter = 0X0;
	LaserTimer_PCounter = 0X0;
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
	RCAP4 = temp;// Reload value to be used in Timer4
	TMR4 = RCAP4;// Init the Timer4 register
	TMR4CN = 0;//16Bit AutoReload
	RES(SPCOIL_LASER_DRIVER_INIT_FAIL);
	SFRPAGE = SFRPAGE_SAVE; 
	//EIP2 = 0x04;
	LaserTimer_Mode = 0;
	LaserTimer_Select = 0;
	LaserTimer_TCounter = 0;
	LaserTimer_TMate = 0;
	LaserTimer_TOvertime = 0;
	LaserTimer_PCounter = 0;
	LaserTimer_PMate = 0;
	LaserTimer_POvertime = 0;
	LaserTimer_ReleaseTime = 0;
	LaserTimer_ReleaseCounter = 0;
	LaserTimer_BeemSwitchCounter = 0;
	LaserTimer_BeemSwtichLength = 0;
#endif
}
static void laserStart(void){//按通道选择打开激光
	setLedEmit(true);
	switch(LaserTimer_Select){
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
		case LASER_SELECT_ALL:{
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
	uint8_t data SFRPAGE_save = SFRPAGE;
	TMR4CN &= 0x7F;//Clear Timer 4 High Byte Overflow Flag
	switch(LaserTimer_Mode){
		case LASER_MODE_CW:{//CW连续模式
			if(LaserTimer_TCounter == 0){
				laserStart();
				setLedEmit(true);
				LaserTimer_TCounter ++;
			}
			if(LaserTimer_ReleaseTime < 1000){
				LaserTimer_ReleaseTime ++;//发射时间累计
			}
			else{
				LaserTimer_ReleaseTime = 0;
				ADDS1(EM_RELEASE_TOTAL_TIME);
			}
			break;
		}
		case LASER_MODE_SIGNAL:{
			if(LaserTimer_TCounter == 0){
				laserStart();
				setLedEmit(true);
				LaserTimer_TCounter ++;
				LaserTimer_BeemSwitchCounter = 0;
				LaserTimer_BeemSwtichLength = 0;
			}
			else{
				LaserTimer_BeemSwitchCounter += 1;
				if(LaserTimer_ReleaseTime < 1000){
					LaserTimer_ReleaseTime ++;//发射时间累计
				}
				else{
					LaserTimer_ReleaseTime = 0;
					ADDS1(EM_RELEASE_TOTAL_TIME);
				}
				if((LaserTimer_BeemSwitchCounter * NVRAM0[EM_TOTAL_POWER] / 10000) >= NVRAM0[EM_LASER_SIGNAL_ENERGY_INTERVAL]){
					SFRPAGE = TIMER01_PAGE;
					if(TH0 != BEEM_FREQ_1){
						TH0 = BEEM_FREQ_1;
						TL0 = TH0;
					}
					SFRPAGE = SFRPAGE_save;
					LaserTimer_BeemSwtichLength ++;
				}
				if(LaserTimer_BeemSwtichLength >= CONFIG_BEEM_ENERGY_INTERVAL_TIME){
					SFRPAGE = TIMER01_PAGE;
					TH0 = BEEM_FREQ_0;
					TL0 = TH0;
					SFRPAGE = SFRPAGE_save;
					LaserTimer_BeemSwitchCounter = 0;
					LaserTimer_BeemSwtichLength = 0;
				}
			}
			break;
		}
		case LASER_MODE_DERMA:{//与MP模式相同
		}
		case LASER_MODE_MP:{//MP多脉冲模式	
			if(LaserTimer_TCounter == 0){//翻转
				laserStart();		
			}
			if(LaserTimer_TCounter >= LaserTimer_TMate){//计时器匹配
				laserStop();
			}
			if(LaserTimer_TCounter < LaserTimer_TMate){//激光发射中
				if(LaserTimer_ReleaseTime < 1000){
					LaserTimer_ReleaseTime ++;//发射时间累计
				}
				else{
					LaserTimer_ReleaseTime = 0;
					ADDS1(EM_RELEASE_TOTAL_TIME);
				}
			}
			if(LaserTimer_TCounter >= LaserTimer_TOvertime){//计时器溢出
				LaserTimer_TCounter = -1;//清零
			}
			LaserTimer_TCounter ++;
			break;
		}
		case LASER_MODE_GP:{//GP可编程脉冲模式
			if(LaserTimer_TCounter < LaserTimer_PMate){//脉冲串输出
				if(LaserTimer_TCounter == 0){//翻转	
					laserStart();
				}
				if(LaserTimer_TCounter < LaserTimer_PMate){//激光发射中
					if(LaserTimer_ReleaseTime < 1000){
						LaserTimer_ReleaseTime ++;//发射时间累计
					}
					else{
						LaserTimer_ReleaseTime = 0;
						ADDS1(EM_RELEASE_TOTAL_TIME);
					}
				}
				if(LaserTimer_TCounter == LaserTimer_PMate){//计时器匹配
					laserStop();
					if(LaserTimer_ReleaseTime < 1000){
						LaserTimer_ReleaseTime ++;//发射时间累计
					}
					else{
						LaserTimer_ReleaseTime = 0;
						ADDS1(EM_RELEASE_TOTAL_TIME);
					}
				}
				if(LaserTimer_TCounter >= LaserTimer_TOvertime){//计时器溢出
					LaserTimer_TCounter = -1;//清零
					LaserTimer_PCounter ++;
				}
				LaserTimer_TCounter ++;
			}
			if(LaserTimer_PCounter >= LaserTimer_PMate){//多脉冲间隔		
				if(LaserTimer_PCounter >= (LaserTimer_POvertime + LaserTimer_PMate)){//脉冲个数发现匹配
					LaserTimer_PCounter = -1;
					LaserTimer_TCounter = 0;
				}
				LaserTimer_PCounter ++;
			}
			break;
		}
		case LASER_MODE_SP:{//单脉冲模式
			if(LaserTimer_TCounter == 0){//翻转
				laserStart();
			}
			if(LaserTimer_TCounter >= LaserTimer_TMate){//计时器匹配
				laserStop();//关闭DAC输出	
				TMR4CN &= ~(uint8_t)(1 << 2);//Stop Timer 4
				EIE2 &= ~(uint8_t)(1 << 2);//关闭Timer4中断
				TMR4CN &= ~(uint8_t)(1 << 7);//Clear Timer 4 High Byte Overflow Flag.
				RES(SPCOIL_LASER_EMITING);//发射标志置位
			}
			if(LaserTimer_ReleaseTime < 1000){
				LaserTimer_ReleaseTime ++;//发射时间累计
			}
			else{
				LaserTimer_ReleaseTime = 0;
				ADDS1(EM_RELEASE_TOTAL_TIME);
			}
			LaserTimer_TCounter ++;
			break;
		}
		default:break;
	}
}