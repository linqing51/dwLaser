#include "MainApp.h"
/*****************************************************************************/
void main(void){ 
	initDevice();
	sPlcInit();
	Cache_ISR_Entry((unsigned int)sPlcTimerIsr, INTERRUPT_TIMER3);
#if CONFIG_SPLC_USING_LASER_TIMER == 1
	Cache_ISR_Entry((unsigned int)laserTimerIsr, INTERRUPT_TIMER4);
#endif
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

