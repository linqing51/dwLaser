#include "softPlc.h"
/*****************************************************************************/
softPlc_t softPlc;

static void Timer0_Init(void);
/*****************************************************************************/
void SoftPlc_Init(void)
{
	memset(softPlc.X_Input0, 0x0, (CONFIG_PLC_X_NUM / 16 + 1));
	memset(softPlc.X_Input1, 0x0, (CONFIG_PLC_X_NUM / 16 + 1));
	memset(softPlc.M_Coil, 0x0, (CONFIG_PLC_M_NUM / 16 + 1));
	memset(softPlc.X_Coil, 0x0, (CONFIG_PLC_X_NUM / 16 + 1));
	memset(softPlc.Y_Coil, 0x0, (CONFIG_PLC_Y_NUM / 16 + 1));
	memset(softPlc.D_Reg, 0x0, (CONFIG_PLC_D_NUM));
	softPlc.TimerCounter_10mS = 0;//软件计时器分频 10mS
	softPlc.TimerCounter_100mS = 0;//软件计时器分频 100mS
	memset(softPlc.Timer_1mS, 0x0, (CONFIG_PLC_TIMER_1MS_NUM));
	memset(softPlc.Timer_10mS, 0x0, (CONFIG_PLC_TIMER_10MS_NUM));
	memset(softPlc.Timer_100mS, 0x0, (CONFIG_PLC_TIMER_100MS_NUM));
	Timer0_Init();
}
static void Timer0_Init(void)
{//硬件sTimer计时器初始化
	softPlc.TimerCounter_10mS = 0;
	softPlc.TimerCounter_100mS = 0;
	TH0 = 0;// Init Timer0 High register
	TL0 = 255;// Init Timer0 Low register
	TMOD &= 0xFC;
	TMOD |= 0x01;// Timer0 in 16-bit mode
	ET0 = 1;// Timer1 interrupt enabled
	TR0 = 1;// Timer1 ON
}
void Timer0_ISR(void) interrupt INTERRUPT_TIMER0
{//硬件sTimer计时器中断 1mS
	uint8_t i;
	for(i = 0;i < CONFIG_PLC_TIMER_1MS_NUM;i ++)
	{
		if(softPlc.Timer_1mS[i] < SHRT_MAX)
		{
			softPlc.Timer_1mS[i] ++;
		}
	}
	if(softPlc.TimerCounter_10mS < 10)
	{
		for(i = 0;i < CONFIG_PLC_TIMER_10MS_NUM;i ++)
		{
			if(softPlc.Timer_10mS[i] < SHRT_MAX)
			{
				softPlc.Timer_10mS[i] ++;
			}
		}
		softPlc.TimerCounter_10mS = 0;
	}
	if(softPlc.TimerCounter_100mS < 100)
	{
		for(i = 0;i < CONFIG_PLC_TIMER_100MS_NUM;i ++)
		{
			
			if(softPlc.Timer_100mS[i] < SHRT_MAX)
			{
				softPlc.Timer_100mS[i] ++;
			}
		}
		softPlc.TimerCounter_100mS = 0;
	}
	TH0 = (uint8_t)((CONFIG_TIME0_1MS >> 8) & 0xff);
	TL0 = (uint8_t)(CONFIG_TIME0_1MS & 0xff);
	TF0 = 0;
}

void set_Coil(uint16_t addr, uint16_t *coil)
{//置位线圈
	uint16_t dat, mask;
	dat = coil[(addr / 16)];
	mask = addr % 16;
	dat |= (1 << mask);
}
void reset_Coil(uint16_t addr, uint16_t *coil)
{//复位线圈
	uint16_t dat, mask;
	dat = coil[(addr / 16)];
	mask = addr % 16;
	dat &= ~(1 << mask);
}
void flip_Coil(uint16_t addr, uint16_t *coil)
{//翻转线圈
	uint16_t dat, mask;
	dat = coil[addr / 16];
	mask = addr % 16;
	if((dat >> mask) & 0x01)
	{
		dat &= ~(1 << mask);
	}
	else
	{
		dat |= (1 << mask);
	}
}

void inputFilter(softPlc_t *plc)
{//对P0-P3进行数字滤波滤波
	uint8_t i, j;
	uint8_t s1, s2;
	plc->X_Input0[0] = 0x0000;
	plc->X_Input0[1] = 0x0000;
	plc->X_Input0[0] = (P0 | (P1 << 8));
	plc->X_Input0[1] = (P2 | (P3 << 8));
	
	plc->X_Input1[0] = plc->X_Input0[0];
	plc->X_Input1[1] = plc->X_Input0[1];
	for(i = 0;i < CONFIG_PLC_X_NUM;i ++)
	{//遍历所有X寄存器
		for(j = 0; j < 16;j ++)
		{
			s1 = (plc->X_Input0[i] >> j) & 0x01;
			s2 = (plc->X_Input1[i] >> j) & 0x01;
			if(s1 == s2)
			{
				plc->X_Coil[i] &= ~(1 << j);
			}
		}
	}
}
void outputRefush(softPlc_t *plc)
{//输出端口刷新
	uint8_t outbit;
	outbit = (plc->Y_Coil[0] >> (8 + 3)) & 0x01;
	if(outbit)
		P1 |= 1 << 3;
	else
		P1 &= ~(1 << 3);
}