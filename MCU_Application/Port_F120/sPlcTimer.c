#include "sPlcTimer.h"
/*****************************************************************************/
bit debugTimer, OverTimer;
static uint8_t Timer0_L, Timer0_H;
void initSplcTimer(void){//硬件sTimer计时器初始化
	xdata uint16_t temp;
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
	SFRPAGE = TIMER01_PAGE;// Set SFR page
	TimerCounter_1mS = 0;
	TimerCounter_10mS = 0;
	TimerCounter_100mS = 0;
	temp = 65536 - (CONFIG_SYSCLK / 48 / CONFIG_SOFTPLC_TICK);	
	Timer0_H = (temp >> 8) & 0xFF;
	Timer0_L = temp & 0xFF;
	TH0 = Timer0_H;
	TL0 = Timer0_L;
	
	TMOD &= 0xF0;//Clear T0
	TMOD |= (1 << 0);//16-bit counter/timer
	TR0 = 1; 
	ET0 = 1;// Timer0 interrupt enabled
	SFRPAGE = SFRPAGE_SAVE;// Restore SFR page
}
static void sPlcTimerIsr(void) interrupt INTERRUPT_TIMER0{//硬件sTimer计时器中断 1mS
	idata uint16_t i;
	idata uint32_t tmp;
	enterSplcIsr();
	debugTimer = ~debugTimer;
	TF0 = false;
	TH0 = Timer0_H;
	TL0 = Timer0_L;
	TR0 = true;
	if(LD(SPCOIL_PS1MS)){//ON
		RES(SPCOIL_PS1MS);
	}
	else{//OFF
		SET(SPCOIL_PS1MS);
	}
	for(i = TD_1MS_START;i <= TD_1MS_END;i ++){//1mS计时
		if(NVRAM0[i] < SHRT_MAX){
			NVRAM0[i] ++;
		}
	}
	if(TimerCounter_1mS >= 10){//10mS计算
		if(LD(SPCOIL_PS10MS)){//ON
			RES(SPCOIL_PS10MS);
		}
		else{//OFF
			SET(SPCOIL_PS10MS);
		}
		for(i = TD_10MS_START;i <= TD_10MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_10mS ++;
		TimerCounter_1mS = 0;
	}
	if(TimerCounter_10mS >= 10){//100ms计算
		if(LD(SPCOIL_PS100MS)){//ON
			RES(SPCOIL_PS100MS);
		}
		else{//OFF
			SET(SPCOIL_PS100MS);
		}
		for(i = TD_100MS_START;i < TD_100MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_100mS ++;
		TimerCounter_10mS = 0;
#if CONFIG_SPLC_USING_LED == 1
		setLedRun(LD(SPCOIL_PS100MS));
#endif
	}
	if(TimerCounter_100mS >= 10){//1000mS计算
		if(LD(SPCOIL_PS1000MS)){//ON
			RES(SPCOIL_PS1000MS);
		}
		else{
			SET(SPCOIL_PS1000MS);
		}
		tmp = 0;
		tmp = NVRAM0[SPREG_RUNTIME_L] + (uint32_t)(NVRAM0[SPREG_RUNTIME_H]) * 65536L;
		tmp += 1;
		NVRAM0[SPREG_RUNTIME_H] = (tmp >> 16) & 0xFFFF;
		NVRAM0[SPREG_RUNTIME_L] = tmp & 0xFFFF;
		TimerCounter_100mS = 0;
	}
#if CONFIG_SPLC_USING_ADC == 1
	chipAdcProcess();//ADC扫描
#endif
	TimerCounter_1mS ++;
	exitSplcIsr();
	
}
