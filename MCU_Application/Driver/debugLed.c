#include "debugLed.h"
/*****************************************************************************/
void setLedRun(uint8_t st){//P6_0
	if(st){
		P6 &= 0xFE;
	}
	else{
		P6 |= 0x01;
	}
}
void setLedError(uint8_t st){//P5_7
	if(st){
		P5 &= ~(1 << 7);	
	}
	else{
		P5 |= (1 << 7);
	}
}
void setLedEprom(uint8_t st){//P5_6
	if(st){
		P5 &= 0xBF;
	}
	else{
		P5 |= 0x40;
	}
}
