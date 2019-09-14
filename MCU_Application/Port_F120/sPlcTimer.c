#include "sPlcTimer.h"
/*****************************************************************************/
void initSplcTimer(void){//硬件sTimer计时器初始化
	uint16_t temp;
	uint8_t SFRPAGE_SAVE;
	SFRPAGE = TMR4_PAGE;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 12 / CONFIG_SOFTPLC_TICK));
	TMR4CF = 0x00;
	RCAP4 = temp;// Reload value to be used in Timer4
	TMR4 = RCAP4;// Init the Timer4 register
	TMR4CN &= ~(uint8_t)(1 << 7);//TF4 溢出标志清零
	EIE2 |= (1 << 2);//T4 ET4中断使能
	TMR4L = 0xFF;
	TMR4H = 0xFF;
	TMR4CN |= (1 << 2);//TR3 使能TIMER3计时器
	SFRPAGE = SFRPAGE_SAVE;
	TimerCounter_5mS = 0;
	TimerCounter_10mS = 0;
	TimerCounter_100mS = 0;
}
void sPlcTimerIsr(void) interrupt INTERRUPT_TIMER4{//硬件sTimer计时器中断 10mS
	data uint16_t i;
	data uint8_t SFRPAGE_save;	
	SFRPAGE_save = SFRPAGE;
	SFRPAGE = TMR4_PAGE;
	TMR4CN &= 0x7F;//Clear Timer 4 High Byte Overflow Flag
	SFRPAGE = SFRPAGE_save;
	if(TimerCounter_5mS >= 2){//10mS计算
		for(i = TD_10MS_START;i <= TD_10MS_END;i ++){
			if(LD(T_10MS_ENA_START * 16 + (i - TD_10MS_START))){
				if(NVRAM0[i] < SHRT_MAX){
					NVRAM0[i] ++;
				}
			}
			else{
				NVRAM0[i] = 0;
			}
		}
		if(TD_10MS_SP < CHAR_MAX){
			TD_10MS_SP ++;
		}
		TimerCounter_10mS ++;
		TimerCounter_5mS = 0;
	}
	if(TimerCounter_10mS >= 10){//100ms计算
		for(i = TD_100MS_START;i < TD_100MS_END;i ++){
			if(LD(T_100MS_ENA_START * 16 + (i - TD_100MS_START))){
				if(NVRAM0[i] < SHRT_MAX){
					NVRAM0[i] ++;
				}
			}
			else{
				NVRAM0[i] = 0;
			}
		}
		if(TD_100MS_SP < CHAR_MAX){
			TD_100MS_SP ++;
		}
		TimerCounter_100mS ++;
		TimerCounter_10mS = 0;
	}
	if(TimerCounter_100mS >= 10){//100ms计算
		if(TD_1000MS_SP < CHAR_MAX){
			TD_1000MS_SP ++;
		}
		TimerCounter_100mS = 0;
	}
#if CONFIG_SPLC_USING_ADC == 1
	chipAdcProcess();//ADC扫描
#endif
	TimerCounter_5mS ++;
	feedWatchDog();
}


