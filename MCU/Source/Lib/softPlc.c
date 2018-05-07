#include "softPlc.h"
/*****************************************************************************/
SI_SEG_DATA uint8_t inputFilterCounter;//输入滤波常熟
SI_SEG_DATA uint16_t inputFilter[CONFIG_PLC_X_NUM / 16 + 2];//已滤波输入
SI_SEG_DATA uint16_t inputCurrent[CONFIG_PLC_X_NUM / 16 + 2];//当前输入
SI_SEG_DATA uint16_t inputLast[CONFIG_PLC_X_NUM / 16 + 2];//上次输入
softPlc_t softPlc;
static void plcHwTimer_Init(void);
/*****************************************************************************/
void SoftPlc_Init(softPlc_t *pt)
{
	int16_t i;
	//初始化
	memset(inputFilter, 0x0, (CONFIG_PLC_X_NUM / 16 + 1));
	memset(inputCurrent, 0x0, (CONFIG_PLC_X_NUM / 16 + 1));
	memset(inputLast, 0x0, (CONFIG_PLC_X_NUM / 16 + 1));
	inputFilterCounter = 3;//3mS
	memset(softPlc.X, 0x0, (CONFIG_PLC_X_NUM / 16 + 1));
	memset(softPlc.Y, 0x0, (CONFIG_PLC_Y_NUM / 16 + 1));
	memset(softPlc.M, 0x0, (CONFIG_PLC_M_NUM / 16 + 1));
	memset(softPlc.N, 0x0, (CONFIG_PLC_N_NUM / 16 + 1));
	memset(softPlc.T_1ms, 0x0, (CONFIG_PLC_T_1MS_NUM / 16 + 1));
	memset(softPlc.T_10ms, 0x0, (CONFIG_PLC_T_10MS_NUM / 16 + 1));
	memset(softPlc.T_100ms, 0x0, (CONFIG_PLC_T_100MS_NUM / 16 + 1));
	memset(softPlc.T_1000ms, 0x0, (CONFIG_PLC_T_1000MS_NUM / 16 + 1));
	memset(softPlc.D, 0x0, CONFIG_PLC_D_NUM);
	memset(softPlc.R, 0x0, CONFIG_PLC_R_NUM);
	
	pt->counter_1ms = 0;
	pt->counter_10ms = 0;
	pt->counter_100ms = 0;
	
	for(i = 0; i<= CONFIG_PLC_T_1MS_NUM; i++)
	{
		pt->T_1ms[i].value = 0;
		pt->T_1ms[i].mate = 0;
		pt->T_1ms[i].enable = 0;
		pt->T_1ms[i].output = 0;
	}

	for(i = 0; i<= CONFIG_PLC_T_10MS_NUM; i++)
	{
		pt->T_10ms[i].value = 0;
		pt->T_10ms[i].mate = 0;
		pt->T_10ms[i].enable = 0;
		pt->T_10ms[i].output = 0;
	}
	
	for(i = 0; i<= CONFIG_PLC_T_100MS_NUM; i++)
	{
		pt->T_100ms[i].value = 0;
		pt->T_100ms[i].mate = 0;
		pt->T_100ms[i].enable = 0;
		pt->T_100ms[i].output = 0;
	}
	
	for(i = 0; i<= CONFIG_PLC_T_1000MS_NUM; i++)
	{
		pt->T_1000ms[i].value = 0;
		pt->T_1000ms[i].mate = 0;
		pt->T_1000ms[i].enable = 0;
		pt->T_1000ms[i].output = 0;
	}
	
	//从EEPROM中恢复D寄存器
	plcHwTimer_Init();
}
static void plcHwTimer_Init(void)
{//硬件sTimer计时器初始化
	CKCON &= ~(1 << 6);//Timer 4 uses the system clock divided by 12
	RCAP4H = 0xFF & (CONFIG_SOFTPLC_HWTIME >> 8);// Init Timer4 High register
	RCAP4L = (CONFIG_SOFTPLC_HWTIME & 0xFF);// Init Timer4 Low register
	T4CON = 0x0;	
	EIE2 |= (1 << 2);//ET4: Enable Timer 4 Interrupt
	T4CON |= (1 << 2);//TR4: Timer 4 Run Control.
}
void plcHwTimer_ISR(void) interrupt INTERRUPT_TIMER4
{//硬件sTimer计时器中断 1mS
	SI_SEG_DATA uint8_t i, j, temp0, temp1;

	T4CON &= ~(1 << 7);//TF4: Timer 4 output Flag Clear	
	for(i = 0;i < CONFIG_PLC_T_1MS_NUM;i ++)
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
		for(i = 0;i < CONFIG_PLC_T_10MS_NUM;i ++)
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
		for(i = 0;i < CONFIG_PLC_T_100MS_NUM;i ++)
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
		for(i = 0;i < CONFIG_PLC_T_1000MS_NUM;i ++)
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
	
	//输入滤波
	inputCurrent[0] = 0x0;
	inputCurrent[0] += P7;
	inputCurrent[0] += (P6 * 256);
	if(inputFilterCounter >= CONFIG_INPUT_FILTER_TIME)
	{//达到滤波时间常数
		for(i = 0;i < (CONFIG_PLC_X_NUM / 16 + 1);i ++)
		{
			for(j = 0;j < 16;j ++)
			{
				temp0 = (inputCurrent[i] >> j) & 0x01;
				temp1 = (inputLast[i] >> j) & 0x01;
				if(temp0 == temp1)
				{
					inputFilter[i] &= ~((uint16_t)(1 << j));
					inputFilter[i] |= (uint16_t)(temp0 << j);
				}
			}
			inputLast[i] = inputCurrent[i];
		}
		inputFilterCounter = 0;
	}
	else
		inputFilterCounter ++;
}
void getInput(softPlc_t *pt)
{//扫描周期读取已滤波输入口状态
	SI_SEG_DATA uint8_t i;
	EIE2 &= ~(1 << 2);//ET4: Disable Timer 4 Interrupt//关闭PLC硬件计时器中断
	for(i = 0;i <= CONFIG_PLC_X_NUM;i ++)
	{
		pt->X[i] = inputFilter[i];
	}
	EIE2 |= (1 << 2);//ET4: Enable Timer 4 Interrupt//打开PLC硬件计时器中断
}


void setOutput(softPlc_t *pt)
{//输出端口刷新
	P6 = pt->Y[0] & 0x00FF;
	//P1^6 = (pt->Y[0] >> 8) & 0x01;
	//P1^7 = (pt->Y[0] >> 9) & 0x01;
}
uint8_t getCoil(uint16_t *coil, uint16_t addr)
{//获取线圈状态
	return (uint8_t)((*(coil + (addr / 16)) >> (addr % 16)) & 0x01);
}
void setCoil(uint16_t *coil, uint16_t addr)
{//置位线圈
	SI_SEG_DATA uint16_t dat, mask;
	dat = coil[(addr / 16)];
	mask = addr % 16;
	dat |= (1 << mask);
}
void resetCoil(uint16_t *coil, uint16_t addr)
{//复位线圈
	SI_SEG_DATA uint16_t dat, mask;
	dat = coil[(addr / 16)];
	mask = addr % 16;
	dat &= ~(1 << mask);
}
void flipCoil(uint16_t *coil, uint16_t addr)
{//翻转线圈
	SI_SEG_DATA uint16_t dat, mask;
	dat = coil[addr / 16];
	mask = addr % 16;
	if((dat >> mask) & 0x01)
		dat &= ~(1 << mask);
	else
		dat |= (1 << mask);
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