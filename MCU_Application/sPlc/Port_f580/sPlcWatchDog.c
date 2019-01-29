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
void checkWatchDog(void){//检查看门狗状态
#if CONFIG_SPLC_USING_WDT == 1
	if ((RSTSRC & 0x02) == 0x00){
		if(RSTSRC == 0x08){//检测WDT看门狗 看门狗复位后锁定
			SET(SPCOIL_WATCHDOG);
			setLedError(DEBUG_LED_ON);
			setLedRun(DEBUG_LED_ON);
			setLedDac(DEBUG_LED_OFF);
			setLedEprom(DEBUG_LED_OFF);
			delayMs(100);
		}
	}
#endif
}