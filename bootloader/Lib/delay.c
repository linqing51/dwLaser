#include "delay.h"
/*****************************************************************************/
void delayUs(uint8_t us) reentrant{//΢����ʱ
	while(us){
		NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
        NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
		NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();	
		us --;	
	}
}
void delayMs(uint8_t ms) reentrant{//������ʱ
	while(ms--){
		delayUs(1000);
	}
}


