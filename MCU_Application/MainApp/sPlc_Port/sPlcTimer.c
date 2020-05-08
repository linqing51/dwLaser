#include "sPlcTimer.h"
/*****************************************************************************/
uint8_t adcProcessCounter;
void timer0Init(void){//硬件sTimer计时器初始化 100mS
	uint16_t temp;
	DelayCounter = 0;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 12 / 1000 * CONFIG_SOFTPLC_HWTIME));
	Timer0_L = temp & 0xFF;
	Timer0_H = (temp >> 8) & 0xFF;
	TH0 = Timer0_H;// Init T0 High register
	TL0 = Timer0_L;// Init T0 Low register
	CKCON &= ~(1 << 3);//SYSCLK / 12	
	TMOD &= 0xF0;
	TMOD |= (1 << 0);// T0 in 16-bit mode
	ET0 = 1;// T0 interrupt enabled
	TR0 = 1;// T0 ON
}
static void timer0Isr(void) interrupt INTERRUPT_TIMER0{//硬件sTimer计时器中断 100mS
	uint16_t i;
	TF0 = 0;
	TR0 = 0;
	TH0 = Timer0_H;
	TL0 = Timer0_L;
	TR0 = 1;
	if(DelayCounter < 0xFF){
		DelayCounter ++;
		if(DelayCounter >= CONFIG_SPLC_DAC_DELAY_INIT_TIME){
			SET(SPCOIL_DELAY_DAC_INIT);
		}
	}
	if(LD(SPCOIL_PS10MS)){//ON
		RES(SPCOIL_PS10MS);
	}
	else{
		SET(SPCOIL_PS10MS);
	}
	for(i = TD_10MS_START;i < TD_10MS_END;i ++){
		if(NVRAM0[i] < SHRT_MAX){
			NVRAM0[i] ++;
		}
	}
	feedExtWtd();//外部看门狗喂狗
	if(adcProcessCounter < 255){
		adcProcessCounter ++;
	}
}
