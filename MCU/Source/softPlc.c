#include "softPlc.h"
/*****************************************************************************/
softPlc_t softPlc;

static void Timer4_Init(void);
/*****************************************************************************/
void SoftPlc_Init(softPlc_t *pt)
{
	int16_t i;
	memset(softPlc.X_Input0, 0x0, (CONFIG_PLC_X_NUM / 16 + 1));
	memset(softPlc.X_Input1, 0x0, (CONFIG_PLC_X_NUM / 16 + 1));
	memset(softPlc.M_Coil, 0x0, (CONFIG_PLC_M_NUM / 16 + 1));
	memset(softPlc.X_Coil, 0x0, (CONFIG_PLC_X_NUM / 16 + 1));
	memset(softPlc.Y_Coil, 0x0, (CONFIG_PLC_Y_NUM / 16 + 1));
	memset(softPlc.D_Reg, 0x0, (CONFIG_PLC_D_NUM));
	
	pt->counter_1ms = 0;
	pt->counter_10ms = 0;
	pt->counter_100ms = 0;
	
	for(i = 0; i<= CONFIG_PLC_TIMER_1MS_NUM; i++)
	{
		pt->T_1ms[i].value = 0;
		pt->T_1ms[i].mate = 0;
		pt->T_1ms[i].enable = 0;
		pt->T_1ms[i].output = 0;
	}

	for(i = 0; i<= CONFIG_PLC_TIMER_10MS_NUM; i++)
	{
		pt->T_10ms[i].value = 0;
		pt->T_10ms[i].mate = 0;
		pt->T_10ms[i].enable = 0;
		pt->T_10ms[i].output = 0;
	}
	
	for(i = 0; i<= CONFIG_PLC_TIMER_100MS_NUM; i++)
	{
		pt->T_100ms[i].value = 0;
		pt->T_100ms[i].mate = 0;
		pt->T_100ms[i].enable = 0;
		pt->T_100ms[i].output = 0;
	}
	
	for(i = 0; i<= CONFIG_PLC_TIMER_1000MS_NUM; i++)
	{
		pt->T_1000ms[i].value = 0;
		pt->T_1000ms[i].mate = 0;
		pt->T_1000ms[i].enable = 0;
		pt->T_1000ms[i].output = 0;
	}
	Timer4_Init();
}
static void Timer4_Init(void)
{//硬件sTimer计时器初始化
	CKCON &= ~(1 << 6);//Timer 4 uses the system clock divided by 12
	RCAP4H = 0xFF & (CONFIG_SOFTPLC_HWTIME >> 8);// Init Timer4 High register
	RCAP4L = (CONFIG_SOFTPLC_HWTIME & 0xFF);// Init Timer4 Low register
	T4CON = 0x0;	
	EIE2 |= (1 << 2);//ET4: Enable Timer 4 Interrupt
	T4CON |= (1 << 2);//TR4: Timer 4 Run Control.
}
void Timer4_ISR(void) interrupt INTERRUPT_TIMER4
{//硬件sTimer计时器中断 1mS
	uint8_t i;
	T4CON &= ~(1 << 7);//TF4: Timer 4 output Flag Clear
	
	for(i = 0;i < CONFIG_PLC_TIMER_1MS_NUM;i ++)
	{//1mS计数器增加
		if(softPlc.T_1ms[i].enable)
		{
			if(softPlc.T_1ms[i].value >= softPlc.T_1ms[i].mate)
				softPlc.T_1ms[i].output = 1;
			else
				softPlc.T_1ms[i].output = 0;
			if(softPlc.T_1ms[i].value < SHRT_MAX)
				softPlc.T_1ms[i].value ++;
			else
				softPlc.T_1ms[1].output = 0;
		}
	}
	
	if(softPlc.counter_1ms >= 10)
	{//10mS T
		for(i = 0;i < CONFIG_PLC_TIMER_10MS_NUM;i ++)
		{//10mS计数器增加
			if(softPlc.T_10ms[i].enable)
			{
				if(softPlc.T_10ms[i].value >= softPlc.T_10ms[i].mate)
					softPlc.T_10ms[i].output = 1;
				else
					softPlc.T_10ms[i].output = 0;
				if(softPlc.T_10ms[i].value < SHRT_MAX)
					softPlc.T_10ms[i].value ++;
				else
					softPlc.T_10ms[1].output = 0;
			}
		}
		softPlc.counter_1ms = 0;
	}
	
	if(softPlc.counter_10ms >= 100)
	{//100mS T
		for(i = 0;i < CONFIG_PLC_TIMER_100MS_NUM;i ++)
		{//100mS计数器增加
			if(softPlc.T_100ms[i].enable)
			{
				if(softPlc.T_100ms[i].value >= softPlc.T_100ms[i].mate)
					softPlc.T_100ms[i].output = 1;
				else
					softPlc.T_100ms[i].output = 0;
				
				if(softPlc.T_100ms[i].value < SHRT_MAX)
					softPlc.T_100ms[i].value ++;
				else
					softPlc.T_100ms[1].output = 0;
			}
		}
		softPlc.counter_10ms = 0;
	}
	
	if(softPlc.counter_100ms >= 1000)
	{//1000mS T
		for(i = 0;i < CONFIG_PLC_TIMER_1000MS_NUM;i ++)
		{//1000mS计数器增加
			if(softPlc.T_1000ms[i].enable)
			{
				if(softPlc.T_1000ms[i].value >= softPlc.T_1000ms[i].mate)
					softPlc.T_1000ms[i].output = 1;
				else
					softPlc.T_1000ms[i].output = 0;
				
				if(softPlc.T_1000ms[i].value < SHRT_MAX)
					softPlc.T_1000ms[i].value ++;
				else
					softPlc.T_1000ms[1].output = 0;
			}
		}
		softPlc.counter_100ms = 0;
	}
	
	softPlc.counter_1ms ++;
	softPlc.counter_10ms ++;
	softPlc.counter_100ms ++;
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


void startTimer(softPlcTimer_t *pt, int16_t value)
{//启动计时器
	if(pt->enable == 0x0)
	{
		pt->mate = value;//设定初值
		pt->value = 0;//复位计时值
		pt->enable = 1;
		pt->output = 0;
	}
}

void stopTimer(softPlcTimer_t *pt)
{//停止计时器
	if(pt->enable != 0x0)
	{
		pt->enable = 0;
		pt->output = 0;
	}
}