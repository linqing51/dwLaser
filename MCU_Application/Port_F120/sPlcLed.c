#include "sPlcLed.h"
/*****************************************************************************/
bit LedRun, LedError, LedEprom, LedAdc, LedIO, LedUart0, LedUart1;//内部调试指示灯
bit LedPower, LedEmit, LedAlarm;//外部LED指示灯
bit LedFlash, LedEprom, LedDac;//内部LED指示灯
void setLedPower(uint8_t st){
	if(st){
		LedPower = true;
	}
	else{
		LedPower = false;
	}
}
void setLedEmit(uint8_t st){
	if(st){
		LedEmit = true;
	}
	else{
		LedEmit = false;
	}
}
void setLedAlarm(uint8_t st){
	if(st){
		LedAlarm = true;
	}
	else{
		LedAlarm = false;
	}
}
void setLedRun(uint8_t st){//SETLED RUN P7_0
	if(st){
		LedRun = true;
		P6 |= (1 << 0);
	}
	else{
		LedRun = false;
		P6 &= ~(1 << 0);
	}
}
uint8_t getLedRun(void){//GET LED RUN P7_0
	return LedRun;
}
void setLedEprom(uint8_t st){//SET LED EPROM P7_1
	if(st){
		LedEprom = true;
		P6 |= (1 << 1);
	}
	else{
		LedRun = false;
		P6 &= ~(1 << 1);
	}
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