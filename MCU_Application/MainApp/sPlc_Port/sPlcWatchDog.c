#include "sPlcWatchDog.h"
/*****************************************************************************/
void lockWatchDog(void){//使能看门狗
	WDTCN = 0xA5;//喂狗
	WDTCN = 0xFF;
    WDTCN = 0x07;//锁定看门狗
}
void feedWatchDog(void) reentrant{//喂狗
	WDTCN = 0xA5;
}
void disableWatchDog(void){//关闭看门狗(未锁定)
	WDTCN = 0xDE;
    WDTCN = 0xAD;
}
 void feedExtWtd(void){//外部看门狗喂狗
	if(P5 &  0x10){
		P5 &= ~(uint8_t)(1 << 4);
	}
	else{
		P5 |= (uint8_t)(1 << 4);
	}
}