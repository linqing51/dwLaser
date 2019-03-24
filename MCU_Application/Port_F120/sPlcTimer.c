#include "sPlcTimer.h"
/*****************************************************************************/
bit debugTimer;
void initSplcTimer(void){//硬件sTimer计时器初始化
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
	SFRPAGE = TMR2_PAGE;// Set SFR page
	TimerCounter_1mS = 0;
	TimerCounter_10mS = 0;
	TimerCounter_100mS = 0;
	temp =(uint16_t)(65536 - CONFIG_SYSCLK / 12 /1000 / CONFIG_SOFTPLC_HWTIME
	TMR2CF = 0x0;//SYSCLK/2;Timer output disable;Timer count up
	RCAP2 = temp;// Reload value to be used in Timer2
	TMR2 = RCAP2;// Init the Timer2 register
	TMR2CN = 0x0;
	TMR2CN |= (1 << 2);Enable Timer2 in auto-reload mode
	ET2 = 1;// Timer2 interrupt enabled
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
}
static void sPlcTimerIsr(void) interrupt INTERRUPT_TIMER2{//硬件sTimer计时器中断 1mS
	idata uint16_t i;
	idata uint32_t tmp;
	enterSplcIsr();
	debugTimer = ~debugTimer;
	TF2 = 0;// Reset Interrupt
	//TR2 = 0;//关闭T2
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
	//TR2 = 1;//打开T2
	exitSplcIsr();
	
}
