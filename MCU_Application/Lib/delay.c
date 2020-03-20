#include "delay.h"
/*****************************************************************************/

/*****************************************************************************/
void delayUs(uint8_t us) reentrant
{//Œ¢√Î—” ±
	while(us)
	{
#if CONFIG_SPLC_USING_WDT == 1
		feedWatchDog();
#endif
        us --;
	}
}

