#include "sPlcMcu.h"
/*****************************************************************************/
static uint8_t sPlcInterrupt;
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
void mucReboot(void) reentrant {//复位
	RSTSRC |= 1 << 4;//强制复位
}
void enterSplcIsr(void) reentrant{//SPLC 进入中断
	sPlcInterrupt = EA;
	EA = false;
}
void exitSplcIsr(void) reentrant{//SPLC 退出中断
	EA = sPlcInterrupt;
}
void disableSplcIsr(void) reentrant{//SPLC关闭全局中断
	EA = 0;
}
void enableSplcIsr(void) reentrant{//SPLC打开全局中断
	EA = 1;
}