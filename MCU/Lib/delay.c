#include "delay.h"
/*****************************************************************************/
#if CONFIG_USING_HW_DELAY == 1
void hwDelayUs(uint8_t us) reentrant
{//计时范围20-1000uS
	uint16_t counter;
	uint8_t SFRPAGE_save = SFRPAGE;
	SFRPAGE = ACTIVE_PAGE;	
	if(us >= 1000)
		us = 1000;
	counter = (uint16_t)(65536 - (uint16_t)(CONFIG_SYSCLK / 12 / 1000000 * us));//计时1ms
	TH0 = (uint8_t)((counter >> 8) & 0xff);
	TL0 = (uint8_t)(counter & 0xff);
	TF0 = 0;
	TR0 = 1;
	while(!TF0);                                               
	TR0 = 0;
	SFRPAGE = SFRPAGE_save;
}

void hwDelayMs(uint8_t ms) reentrant
{//计时范围1-32765mS
	uint16_t counter;
	uint8_t SFRPAGE_save = SFRPAGE;
	SFRPAGE = ACTIVE_PAGE;
	counter = (uint16_t)(65536 - (uint16_t)(CONFIG_SYSCLK/ 12 / 1000));//计时1ms
	while(ms)
	{
		TH0 = counter >> 8;
		TL0 = counter & 0xff;
		TF0 = 0;
		TR0 = 1;
		while(!TF0);                     
		ms--;                           
	}
	TR0 = 0;
	SFRPAGE = SFRPAGE_save;
}
#else
void hwDelayUs(uint8_t us) reentrant
{//微秒延时
	while(us)
	{
        us --;
	}
}
void hwDelayMs(uint8_t ms) reentrant
{//毫秒延时
	while(ms--)
	{
		hwDelayUs(100);
	}
}
#endif