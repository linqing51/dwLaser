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
