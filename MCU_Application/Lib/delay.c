#include "delay.h"
/*****************************************************************************/

/*****************************************************************************/
void delayUs(uint8_t data us) reentrant
{//微秒延时
	while(us)
	{
        us --;
	}
}
void delayMs(uint8_t data ms) reentrant
{//毫秒延时
	while(ms--)
	{
		delayUs(100);
	}
}
void hwDelayInit(uint8_t data reload_h, uint8_t data reload_l)
{
	TMOD &= 0x0F;
	TMOD |= 0x10;
	ET1 = 0;
	TH1 = reload_h;
	TL1 = reload_l;
	TF1 = 0;
	TR1 = 1;
}
void hwDelay(uint8_t control, uint8_t reload_h, uint8_t reload_l)
{//control = 0 等待计时器完成 
	//control 1 等待计时器重新开始后完成
	if(TR1 == 1)
	{
		while(TF1 == 0);
	}
	TR1 = 0;
	if(control == 1)
	{
		TH1 = reload_h;
		TL1 = reload_l;
		TF1 = 0;
		TR1 = 1;
	}
}
