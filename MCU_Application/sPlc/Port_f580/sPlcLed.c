#include "sPlcLed.h"
/*****************************************************************************/
void setLedRun(uint8_t idata st){//SETLED RUN P7_0
	if(st){
		P7 |= (uint8_t)(1 << 0);
	}
	else{
		P7 &= ~(uint8_t)(1 << 0);
	}
}
uint8_t getLedRun(void){//GET LED RUN P7_0
	return (uint8_t)((P7 >> 0) & 0x01);
}
void setLedEprom(uint8_t idata st){//SET LED EPROM P7_1
	if(st){
		P7 |= (uint8_t)(1 << 1);
	}
	else{
		P7 &= ~(uint8_t)(1 << 1);
	}
}
uint8_t getLedEprom(void){//GET LED EPROM P7_1
	return (uint8_t)((P7 >> 1) & 0x01);
}
void setLedDac(uint8_t idata st){//SET LED DAC P7_2
	if(st){
		P7 |= (uint8_t)(1 << 2);
	}
	else{
		P7 &= ~(uint8_t)(1 << 2);
	}
}
uint8_t getLedDac(void){//GET LED DAC P7_2
	return (uint8_t)((P7 >> 2) & 0x01);
}
void setLedError(uint8_t idata st){//SET LED ERROR P7_3
	if(st){
		P7 |= (uint8_t)(1 << 3);
	}
	else{
		P7 &= ~(uint8_t)(1 << 3);
	}
}
uint8_t getLedError(void){//GET LED ERROR
	return (uint8_t)((P7 >> 3) & 0x01);
}