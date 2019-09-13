#include "MainApp.h"
/*****************************************************************************/
extern void Uart0Isr(void);
void main(void){ 
	initDevice();
	feedWatchDog();
	SET(Y_FAN1);
	sPlcInit();
	Cache_ISR_Entry((unsigned int)Uart0Isr, INTERRUPT_UART0);
	Cache_ISR_Entry((unsigned int)laserTimerIsr, INTERRUPT_TIMER3);
	Cache_ISR_Entry((unsigned int)sPlcTimerIsr, INTERRUPT_TIMER4);
	while(1){
		sPlcProcessStart();
		if(LD(SPCOIL_START_UP)){//
#if CONFIG_USING_DCHMI_APP == 1			
			dcHmiLoopInit();
#endif			
		}
#if CONFIG_USING_DCHMI_APP == 1
			dcHmiLoop();
#endif
#if CONFIG_SPLC_FUNTEST == 1
#endif
		sPlcProcessEnd();
	}
}

