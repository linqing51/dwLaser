#include "delay.h"
/*****************************************************************************/
extern uint16_t data hWdelayTickCount;
/*****************************************************************************/
void delayUs(uint8_t us) reentrant{//΢����ʱ
	while(us){
#if CONFIG_SPLC_USING_WDT == 1
		feedWatchDog();
#endif
        us --;
	}
}
void delayMs(uint8_t ms) reentrant{//������ʱ
	while(ms--){
		delayUs(100);
	}
}

void delayHwMs(uint16_t delay){//������ʱӲ�� ���10000mS
    uint16_t tick = hWdelayTickCount;
    while(1){
        if((uint16_t)(hWdelayTickCount - tick) > delay){
            break;
		}
    }
}

