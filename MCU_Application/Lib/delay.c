#include "delay.h"
/*****************************************************************************/
void delayUs(uint16_t us) reentrant{//Œ¢√Î—” ±
	while(us){
#if CONFIG_SPLC_USING_WDT == 1
		NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
        NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
		NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
		feedWatchDog();
#else
		NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
		NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
		NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
		NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
		NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();	
#endif
		us --;	
	}
}
void delayMs(uint16_t ms) reentrant{//∫¡√Î—” ±
	while(ms--){
		delayUs(1000);
		feedWatchDog();
	}
}


