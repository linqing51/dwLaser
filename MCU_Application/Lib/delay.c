#include "delay.h"
/*****************************************************************************/
void delayUs(uint8_t us) reentrant
{//΢����ʱ
	while(us){
        us --;
	}
}

