#include "delay.h"
/*****************************************************************************/
static uint32_t Timer_100us, Timer_1ms, Timer_10ms, Timer_100ms;
static uint8_t sTL1, sTH1;
/*****************************************************************************/

void hwDelayInit(void)
{//TICK计时器初始化
	uint16_t temp;
	Timer_1ms = 0;
	Timer_10ms = 0;
	Timer_100ms = 0;
	TMOD &= 0x0F;
	TMOD |= (1 << 4);//Mode 1:16-bit counter/timer
	CKCON &= 0xF7;//T1 clock / 12
	temp = CONFIG_SYSCLK * 100 / 12;
	TL1 = temp & 0xFF;
	TH1 = (temp >> 8) & 0xFF;
	ET1 = 1;
	TR1 = 1;
}

#if CONFIG_USING_HW_DELAY == 1
void hwDelayISR(void) interrupt INTERRUPT_TIMER1
{
	//TickCounter ++;
}
void hwDelayUs(uint16_t us) reentrant
{//计时范围

}

void hwDelayMs(uint16_t ms) reentrant
{//计时范围1-32765mS
//	uint16_t counter;
//	uint8_t SFRPAGE_save = SFRPAGE;
//	SFRPAGE = ACTIVE_PAGE;
//	counter = (uint16_t)(65536 - (uint16_t)(CONFIG_SYSCLK/ 12 / 1000));//计时1ms
//	while(ms)
//	{
//		TH0 = counter >> 8;
//		TL0 = counter & 0xff;
//		TF0 = 0;
//		TR0 = 1;
//		while(!TF0);                     
//		ms--;                           
//	}
//	TR0 = 0;
//	SFRPAGE = SFRPAGE_save;
}
#else
void swDelayUs(uint8_t us) reentrant
{//微秒延时
	while(us)
	{
        us --;
	}
}
void swDelayMs(uint8_t ms) reentrant
{//毫秒延时
	while(ms--)
	{
		hwDelayUs(100);
	}
}
#endif