#include "delay.h"
/*****************************************************************************/
void delayUs(uint32_t us)
{//Œ¢√Î—” ±
	while(us--)
	{
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
	}
}
void delayMs(uint32_t ms)
{//∫¡√Î—” ±
	while(ms--)
	{
		delayUs(1000);
	}
}


