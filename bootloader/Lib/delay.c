#include "delay.h"
/*****************************************************************************/
void delayUs(uint8_t us) reentrant{//Œ¢√Î—” ±
	while(us){
		NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
        NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
		NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();	
		us --;	
	}
}
void delayMs(uint8_t ms) reentrant{//∫¡√Î—” ±
	while(ms--){
		delayUs(1000);
	}
}


