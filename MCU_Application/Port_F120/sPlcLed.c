#include "sPlcLed.h"
/*****************************************************************************/
bit LedRun, LedError, LedEprom, LedAdc, LedDac, LedIO, LedUart0, LedUart1;
void setLedRun(uint8_t st){//SETLED RUN P7_0
	LedRun = st;
	if(st)
		P6 |= (1 << 0);
	else
		P6 &= ~(1 << 0);
}
uint8_t getLedRun(void){//GET LED RUN P7_0
	return LedRun;
}
void setLedEprom(uint8_t st){//SET LED EPROM P7_1
	LedEprom = st;
	if(st)
		P6 |= (1 << 1);
	else
		P6 &= ~(1 << 1);
}
uint8_t getLedEprom(void){//GET LED EPROM P7_1
	return LedEprom;
}
void setLedDac(uint8_t st){
	LedDac = st;
}
uint8_t getLedDac(void){
	return LedDac;
}
void setLedError(uint8_t idata st){
	LedError = st;
	if(st)
		P6 |= (1 << 2);
	else
		P6 &= (1 << 2);
}
uint8_t getLedError(void){
	return LedError;
}
void setLedAdc(uint8_t st){
	LedAdc = st;
}
uint8_t getLedAdc(void){
	return LedAdc;
}