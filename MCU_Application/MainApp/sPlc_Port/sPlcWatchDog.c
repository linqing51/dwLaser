#include "sPlcWatchDog.h"
/*****************************************************************************/
void initWatchDog(void){//看门狗初始化
	WDTCN = 0x07;//47mS
}
void enableWatchDog(void){//使能看门狗
	WDTCN = 0xA5;
}
void disableWatchDog(void){//关闭看门狗(未锁定)
	uint8_t flagEA;
	flagEA = EA;
	EA = 0;
	WDTCN = 0xDE;
    WDTCN = 0xAD;
	EA = flagEA;
}
void feedWatchDog(void) reentrant{//喂狗
	WDTCN = 0xA5;
}
