#include "sTimer.h"
/*****************************************************************************/
SI_SEG_DATA uint8_t Tcounter_1ms =0;
SI_SEG_DATA uint8_t Tcounter_10ms = 0;
SI_SEG_DATA uint8_t Tcounter_100ms = 0;
SI_SEG_DATA uint8_t Tcounter_1000ms = 0;
sTimer_t sTimer[CONFIG_STIMER_NUM];
/*****************************************************************************/
void sTimerInit(void)
{
	//��ʱ��
	uint16_t i;
	sTimer_t *st = &sTimer;
	for(i = 0;i < CONFIG_STIMER_NUM;i ++)
	{
		sTimer[i].enable = 0x0;
		sTimer[i].status = 0x0;
		sTimer[i].value = 0x0;
		sTimer[i].mate = 0x0;
	}
	Tcounter_1ms =0;
	Tcounter_10ms = 0;
	Tcounter_100ms = 0;
	Tcounter_1000ms = 0;
	//Ӳ��sTimer��ʱ����ʼ��
	RCAP4H = 0xFF & (CONFIG_SOFTPLC_HWTIME >> 8);// Init Timer4 High register
	RCAP4L = CONFIG_SOFTPLC_HWTIME & 0xFF;// Init Timer4 Low register
	T4CON = 0x0;	
	EIE2 |= (1 << 2);//ET4: Enable Timer 4 Interrupt
	T4CON |= (1 << 2);//TR4: Timer 4 Run Control.
}

void sTimerISR(void) interrupt INTERRUPT_TIMER4
{//Ӳ��sTimer��ʱ���ж� 1mS
	SI_SEG_DATA uint8_t i;
	sTimer_t *st = &sTimer;
	T4CON &= ~(1 << 7);//TF4: Timer 4 output Flag Clear	
<<<<<<< HEAD
	for(i = CONFIG_PLC_T_1MS_START;i < CONFIG_PLC_T_1MS_END;i ++)
=======
	for(i = 0;i < CONFIG_STIMER_1MS_NUM;i ++)
>>>>>>> f2e27d8502aafb19eb14774ec23e774246145beb
	{//10mS����������
		if(sTimer[i].enable)
		{
			if(sTimer[i].value >= sTimer[i].mate)
				sTimer[i].status = 1;//��λ
			else
				sTimer[i].status = 0;//��λ
			if(sTimer[i].value < SHRT_MAX)
				sTimer[i].value ++;
		}
	}
	Tcounter_1ms ++;
	
	if(Tcounter_1ms >= 10)
	{//100mS
<<<<<<< HEAD
		for(i = CONFIG_PLC_T_10MS_START;i < CONFIG_PLC_T_10MS_END;i ++)
=======
		for(i = CONFIG_STIMER_1MS_NUM;i < CONFIG_STIMER_10MS_NUM;i ++)
>>>>>>> f2e27d8502aafb19eb14774ec23e774246145beb
		{//10mS����������
			if(sTimer[i].enable)
			{
				if(sTimer[i].value >= sTimer[i].mate)
					sTimer[i].status = 1;//��λ
				else
					sTimer[i].status = 0;//��λ
				if(sTimer[i].value < SHRT_MAX)
					sTimer[i].value ++;
			}
		}
		Tcounter_1ms = 0;
		Tcounter_10ms ++;
	}
	
	if(Tcounter_10ms >= 10)
	{//1000mS 
<<<<<<< HEAD
		for(i = CONFIG_PLC_T_100MS_START;i < CONFIG_PLC_T_100MS_END;i ++)
=======
		for(i = CONFIG_STIMER_10MS_NUM;i < CONFIG_STIMER_100MS_NUM;i ++)
>>>>>>> f2e27d8502aafb19eb14774ec23e774246145beb
		{//10mS����������
			if(sTimer[i].enable)
			{
				if(sTimer[i].value >= sTimer[i].mate)
					sTimer[i].status = 1;//��λ
				else
					sTimer[i].status = 0;//��λ
				if(sTimer[i].value < SHRT_MAX)
					sTimer[i].value ++;
			}
		}
		Tcounter_10ms = 0;
		Tcounter_100ms ++;
	}
	
	if(Tcounter_100ms >= 100)
	{//1000mS 
<<<<<<< HEAD
		for(i = CONFIG_PLC_T_1000MS_START;i < CONFIG_PLC_T_1000MS_END;i ++)
=======
		for(i = CONFIG_STIMER_100MS_NUM;i < CONFIG_STIMER_1000MS_NUM;i ++)
>>>>>>> f2e27d8502aafb19eb14774ec23e774246145beb
		{//10mS����������
			if(sTimer[i].enable)
			{
				if(sTimer[i].value >= sTimer[i].mate)
					sTimer[i].status = 1;//��λ
				else
					sTimer[i].status = 0;//��λ
				if(sTimer[i].value < SHRT_MAX)
					sTimer[i].value ++;
			}
		}
		Tcounter_100ms = 0;
	}
}

int8_t sTimerCtrl(int8_t enable, uint16_t num, uint16_t value)
{//���ʱ������  enable:��ʱ��ʹ�� num:��ʱ������ value:��ʱ���趨ֵ ����ֵ:���
	int8_t res = 0;
	if(enable)
	{//ʹ�ܼ�ʱ��
		if(!(sTimer[num].enable))
		{
			sTimer[num].mate = value;//�趨��ʱֵ
			sTimer[num].value = 0;//��λ��ʱֵ
			sTimer[num].enable = 1;
			sTimer[num].status = 0;
		}
		else
		{
			if(sTimer[num].value >= sTimer[num].mate)
				res = 1;
			else
				res = 0;
		}
	}
	else
	{
		sTimer[num].enable = 0;
		sTimer[num].status = 0;
		res = 0;
	}
	return res;
}
