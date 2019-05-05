#include "MainApp.h"
/*****************************************************************************/
bit debugLed0, debugLed1, debugLed2, debugLed3;
void main(void){ 
	initDevice();
	sPlcInit();
#if CONFIG_DEBUG == 1
	printf("sPLC->main:Debug Port->UART1\n");
	printf("sPLC->main:sPlcInit Done\n");
#endif
	Cache_ISR_Entry((unsigned int)sPlcTimerIsr, INTERRUPT_TIMER0);
#if CONFIG_SPLC_USING_LASER_TIMER == 1
	Cache_ISR_Entry((unsigned int)laserTimerIsr, INTERRUPT_TIMER4);
#endif
	//Cache_ISR_Entry((unsigned int)Uart0Isr, INTERRUPT_UART0);
	while(1){
		debugLed0 = ~debugLed0;
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


