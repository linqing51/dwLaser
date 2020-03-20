#include "delay.h"
/*****************************************************************************/

/*****************************************************************************/
void delayUs(uint8_t us) reentrant
{//΢����ʱ
	while(us)
	{
#if CONFIG_SPLC_USING_WDT == 1
		feedWatchDog();
#endif
        us --;
	}
}
void delayMs(uint8_t ms) reentrant
{//������ʱ
	while(ms--)
	{
		delayUs(100);
	}
}


