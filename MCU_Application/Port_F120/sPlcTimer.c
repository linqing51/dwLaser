#include "sPlcTimer.h"
/*****************************************************************************/
bit debugTimer, OverTimer;
static uint8_t Timer0_L, Timer0_H;
void initSplcTimer(void){//硬件sTimer计时器初始化
	uint16_t temp;
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
	SFRPAGE = TIMER01_PAGE;// Set SFR page
	TimerCounter_1mS = 0;
	TimerCounter_10mS = 0;
	temp = 65536 - (CONFIG_SYSCLK / 48 / CONFIG_SOFTPLC_TICK);	
	Timer0_H = (temp >> 8) & 0xFF;
	Timer0_L = temp & 0xFF;
	TH0 = Timer0_H;
	TL0 = Timer0_L;
	CKCON = 0;
	CKCON |= 0x02;//System clock divided by 48
	TMOD &= 0xF0;//Clear T0
	TMOD |= (1 << 0);//16-bit counter/timer
	TR0 = 1; 
	ET0 = 1;// Timer0 interrupt enabled
	SFRPAGE = SFRPAGE_SAVE;// Restore SFR page
}
void sPlcTimerIsr(void) interrupt INTERRUPT_TIMER0{//硬件sTimer计时器中断 1mS
	uint16_t i;
	//debugTimer = ~debugTimer;
	TF0 = false;
	TH0 = Timer0_H;
	TL0 = Timer0_L;
	TR0 = true;
	if(TD_1MS_SP < CHAR_MAX){
		TD_1MS_SP ++;
	}	
	for(i = TD_1MS_START;i <= TD_1MS_END;i ++){//1mS计时
		if(LD(T_1MS_ENA_START * 16 + (i - TD_1MS_START))){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		else{
			NVRAM0[i] = 0;
		}
	}
	if(TimerCounter_1mS >= 10){//10mS计算
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
		TimerCounter_1mS = 0;
#if CONFIG_SPLC_USING_PCA == 1
		NVRAM0[SPREG_BEEM_COUNTER] += 1;
#endif
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
	TimerCounter_1mS ++;
	//SFRPAGE = LEGACY_PAGE;
}
