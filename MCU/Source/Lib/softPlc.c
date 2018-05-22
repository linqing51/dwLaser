#include "softPlc.h"
/*****************************************************************************/
//SI_SEG_PDATA uint16_t InputFilterCounter;//�����˲�����
//SI_SEG_PDATA uint16_t InputFilter[(CONFIG_PLC_X_NUM / 16 + 1)];//���˲�����
//SI_SEG_PDATA uint16_t InputCurrent[(CONFIG_PLC_X_NUM / 16 + 1)];//��ǰ����
//SI_SEG_PDATA uint16_t InputLast[(CONFIG_PLC_X_NUM / 16 + 1)];//�ϴ�����
SI_SEG_DATA uint8_t Tcounter_1ms =0;
SI_SEG_DATA uint8_t Tcounter_10ms = 0;
SI_SEG_DATA uint8_t Tcounter_100ms = 0;
SI_SEG_DATA uint8_t Tcounter_1000ms = 0;
softPlc_t softPlc;
static void plcHwTimer_Init(void);
/*****************************************************************************/
void SoftPlc_Init(softPlc_t *pt)
{
	//��ʼ��
	
	//����Ĵ���
	memset(pt->X, 0x0, (CONFIG_PLC_X_NUM / 16 + 1));
	memset(pt->X1, 0x0, (CONFIG_PLC_X_NUM / 16 + 1));
	//����Ĵ���
	memset(pt->Y, 0x0, (CONFIG_PLC_Y_NUM / 16 + 1));
	memset(pt->Y1, 0x0, (CONFIG_PLC_Y_NUM / 16 + 1));
	//λ�Ĵ���
	memset(pt->M, 0x0, (CONFIG_PLC_M_NUM / 16 + 1));
	memset(pt->M1, 0x0, (CONFIG_PLC_M_NUM / 16 + 1));
	//��ʱ��
	memset(pt->T, 0x0, (CONFIG_PLC_T_NUM / 16 + 1));
	memset(pt->T1, 0x0, (CONFIG_PLC_T_NUM / 16 + 1));
	memset(pt->T_EN, 0x0, (CONFIG_PLC_T_NUM /16 + 1));
	memset(pt->T_MATE, 0x0, CONFIG_PLC_T_NUM);
	memset(pt->T_VALUE, 0x0, CONFIG_PLC_T_NUM);
	//������
	memset(pt->C, 0x0, (CONFIG_PLC_C_NUM / 16 + 1));
	memset(pt->C_VALUE, 0x0, (CONFIG_PLC_C_NUM));
	//���ݼĴ���
	memset(pt->D, 0x0, CONFIG_PLC_D_NUM);
	
	//��EEPROM�лָ��Ĵ���
	plcHwTimer_Init();
}
static void plcHwTimer_Init(void)
{//Ӳ��sTimer��ʱ����ʼ��
	RCAP4H = 0xFF & (CONFIG_SOFTPLC_HWTIME >> 8);// Init Timer4 High register
	RCAP4L = CONFIG_SOFTPLC_HWTIME & 0xFF;// Init Timer4 Low register
	T4CON = 0x0;	
	EIE2 |= (1 << 2);//ET4: Enable Timer 4 Interrupt
	T4CON |= (1 << 2);//TR4: Timer 4 Run Control.
}
void plcHwTimer_ISR(void) interrupt INTERRUPT_TIMER4
{//Ӳ��sTimer��ʱ���ж� 1mS
	SI_SEG_DATA uint8_t i;
	softPlc_t *pt = &softPlc;
	T4CON &= ~(1 << 7);//TF4: Timer 4 output Flag Clear	
	for(i = 0;i < CONFIG_PLC_T_10MS_NUM;i ++)
	{//10mS����������
		if(pt->T_EN[(i / 16)] >> (i % 16))
		{
			if(pt->T_VALUE[i] >= pt->T_MATE[i])
				pt->T[(i / 16)] |= (1 << (i % 16));//��λ
			else
				pt->T[(i / 16)] &= ~(1 << (i % 16));//��λ
			if(pt->T_VALUE[i] < SHRT_MAX)
				pt->T_VALUE[i] ++;
		}
	}
	Tcounter_10ms ++;
	
	if(Tcounter_10ms >= 10)
	{//100mS
		for(i = CONFIG_PLC_T_10MS_NUM;i < CONFIG_PLC_T_100MS_NUM;i ++)
		{//10mS����������
			if(pt->T_EN[(i / 16)] >> (i % 16))
			{
				if(pt->T_VALUE[i] >= pt->T_MATE[i])
					pt->T[(i / 16)] |= (1 << (i % 16));//��λ
				else
					pt->T[(i / 16)] &= ~(1 << (i % 16));//��λ
				if(pt->T_VALUE[i] < SHRT_MAX)
					pt->T_VALUE[i] ++;
			}
		}
		Tcounter_10ms = 0;
		Tcounter_100ms ++;
	}
	
	if(Tcounter_100ms >= 10)
	{//1000mS 
		for(i = CONFIG_PLC_T_100MS_NUM;i < CONFIG_PLC_T_1000MS_NUM;i ++)
		{//10mS����������
			if(pt->T_EN[(i / 16)] >> (i % 16))
			{
				if(pt->T_VALUE[i] >= pt->T_MATE[i])
					pt->T[(i / 16)] |= (1 << (i % 16));//��λ
				else
					pt->T[(i / 16)] &= ~(1 << (i % 16));//��λ
				if(pt->T_VALUE[i] < SHRT_MAX)
					pt->T_VALUE[i] ++;
			}
		}
		Tcounter_100ms = 0;
		Tcounter_1000ms ++;
	}
	
//	//�����˲�
//	InputCurrent[0] = 0x0;
//	*((uint8_t*)(InputCurrent)) = P7;
//	*((uint8_t*)(InputCurrent + 1)) = P6;
//	if(InputFilterCounter >= CONFIG_INPUT_FILTER_TIME)
//	{//�ﵽ�˲�ʱ�䳣��
//		for(i = 0;i < (CONFIG_PLC_X_NUM / 16 + 1);i ++)
//		{
//			for(j = 0;j < 16;j ++)
//			{
//				temp0 = (InputCurrent[i] >> j) & 0x01;
//				temp1 = (InputLast[i] >> j) & 0x01;
//				if(temp0 == temp1)
//				{
//					InputFilter[i] &= ~((uint16_t)(1 << j));
//					InputFilter[i] |= (uint16_t)(temp0 << j);
//				}
//			}
//			InputLast[i] = InputCurrent[i];
//		}
//		InputFilterCounter = 0;
//	}
//	else
//		InputFilterCounter ++;
}
void getInput(softPlc_t *pt)
{//ɨ�����ڶ�ȡ���˲������״̬
	*((uint8_t*)(pt->X)) = P6;
	*((uint8_t*)(pt->X + 1)) = P7;
}


void setOutput(void)
{//����˿�ˢ��
	softPlc_t *pt = &softPlc;
	P6 = pt->Y[0] & 0x00FF;
	//P1^6 = (pt->Y[0] >> 8) & 0x01;
	//P1^7 = (pt->Y[0] >> 9) & 0x01;
}



int8_t TB(int8_t en, int16_t num, int16_t value)
{//һ���ʱ�� en:��ʱ��ʹ�� num:��ʱ������ value:��ʱ���趨ֵ ����ֵ:TUP ���ֵ
	int8_t res = 0;
	if(en)
	{//ʹ�ܼ�ʱ��
		if(!(softPlc.T_EN[num / 16] >> (num % 16)))
		{
			softPlc.T_MATE[num] = value;//�趨��ʱֵ
			softPlc.T_VALUE[num] = 0;//��λ��ʱֵ
			softPlc.T_EN[(num /16)] |= (1 << (num % 16));
			softPlc.T[num] = 0;
		}
		else
		{
			if(softPlc.T_VALUE >= softPlc.T_MATE)
				res = 1;
			else
				res = 0;
		}
	}
	else
	{
		softPlc.T_EN[(num / 16)] &= ~(1 << (num % 16));
		softPlc.T[(num / 16)] &= ~(1 << (num % 16));
		res = 0;
	}
	return res;
}

int8_t LD(uint8_t reg, uint16_t num)
{//
	switch(reg)
	{
		case SOFTPLC_X:
			return softPlc.X[(num / 16)] >> (num % 16);
		case SOFTPLC_Y:
			return softPlc.Y[(num / 16)] >> (num % 16);
		case SOFTPLC_M:
			return softPlc.M[(num / 16)] >> (num % 16);
		case SOFTPLC_T:
			return softPlc.T[(num / 16)] >> (num % 16);
		case SOFTPLC_C:
			return softPlc.C[(num / 16)] >> (num % 16);
		default:
			return 0;
	}
}

void OUT(uint8_t reg, uint16_t num, int8_t ena)
{//���������͵���Ȧȥ reg=�Ĵ������� num=�Ĵ������ ena=�Ĵ���ʹ��
	switch(reg)
	{
		case SOFTPLC_Y:
		{
			if(ena)
				softPlc.Y[(num / 16)] |= (1 << (num % 16));
			else
				softPlc.Y[(num / 16)] &= ~(1 << (num % 16));
			break;
		}
		case SOFTPLC_M:
		{
			if(ena)
				softPlc.M[(num / 16)] |= (1 << (num % 16));
			else
				softPlc.M[(num / 16)] &= ~(1 << (num % 16));
			break;
		}
		default:break;
	}
}
//int8_t TU(uint8_t *opt)
//{//��΢��
//	int8_t res = 0;
//	int8_t reg;
//	uint16_t num;
//	reg = *opt;
//	num = atoi(opt + 1);
//	switch(reg)
//	{
//		case "X":
//		{
//			if(num > CONFIG_PLC_X_NUM)
//				num = CONFIG_PLC_X_NUM;
//			if(softPlc.X[num] == 1) && softPlc.X1[num] == 0)
//				res = 1;
//			else
//				res = 0;
//			break;
//		}
//		case "Y":
//		{
//			if(num > CONFIG_PLC_Y_NUM)
//				num = CONFIG_PLC_Y_NUM;
//			if(softPlc.Y[num] == 1) && softPlc.Y1[num] == 0)
//				res = 1;
//			else
//				res = 0;
//			break;
//		}
//		case 'M':
//		{
//			if(num > CONFIG_PLC_M_NUM)
//				num = CONFIG_PLC_M_NUM;
//			if(softPlc.M[num] == 1 && softPlc.M1[num] == 0)
//				res = 1;
//			else 
//				res = 0;
//			break;
//		}
//		case 'N'
//		{
//			if(num > CONFIG_PLC_M_NUM)
//				num = CONFIG_PLC_M_NUM;
//			if(softPlc.M[num] == 1 && softPlc.M1[num] == 0)
//				res = 1;
//			else 
//				res = 0;
//			break;
//			break;
//		}
//		default:break;
//	}
//}
int8_t TD(uint8_t name, uint16_t num)
{//��΢��
	return 0;
}	