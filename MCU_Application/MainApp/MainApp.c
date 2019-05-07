#include "MainApp.h"
/*****************************************************************************/
void hwTest(void){
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
	disableSplcIsr();
	SFRPAGE   = DAC0_PAGE;
	DAC0 = 0xFFF;
	SFRPAGE   = DAC1_PAGE;
	DAC1 = 0xFFF;
	SFRPAGE = CONFIG_PAGE;
	P2 |= (1 << 6);
	P2 |= (1 << 7);
	SFRPAGE_SAVE = SFRPAGE;
}


void main(void){ 
	initDevice();
	sPlcInit();
	hwTest();
	while(1);
#if CONFIG_DEBUG == 1
	printf("sPLC->main:Debug Port->UART1\n");
	printf("sPLC->main:sPlcInit Done\n");
#endif
	Cache_ISR_Entry((unsigned int)sPlcTimerIsr, INTERRUPT_TIMER0);
#if CONFIG_SPLC_USING_LASER_TIMER == 1
	//Cache_ISR_Entry((unsigned int)laserTimerIsr, INTERRUPT_TIMER4);
#endif
	//Cache_ISR_Entry((unsigned int)Uart0Isr, INTERRUPT_UART0);
	while(1){
		sPlcProcessStart();
		if(LD(SPCOIL_START_UP)){//
#if CONFIG_USING_BACKGROUND_APP == 1 
			backgroundAppInit();
#endif
#if CONFIG_USING_DCHMI_APP == 1			
			dcHmiLoopInit();
#endif			
		}
#if CONFIG_USING_BACKGROUND_APP == 1 
			backgroundApp();
#endif		
#if CONFIG_USING_DCHMI_APP == 1
			dcHmiLoop();
#endif
#if CONFIG_SPLC_FUNTEST == 1
#endif
		sPlcProcessEnd();
	}
}


