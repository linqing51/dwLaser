#include "MainApp.h"
/*****************************************************************************/
sbit LaserMod_PIN						= P0^6;
/*****************************************************************************/
myDevice_t myDevice;
/*****************************************************************************/
#define ENUM_CHANNEL1					4321
#define ENUM_CHANNEL2					8765
#define ENUM_CHANNEL_BOTH				9431
#define ENUM_MODE_CW					7631//����ģʽ
#define ENUM_MODE_SP					8934//������ģʽ
#define ENUM_MODE_MP					2453//������ģʽ
#define ENUM_MODE_GP					3876//Ⱥ����ģʽ
#define ENUM_MODE_CC					14563//У��ģʽ
#define LASER_OFF						1
#define LASER_ON						0
#define LED_OFF							1
#define LED_ON							0
//code char *LOOPTEST 					= "Hello World Power BOARD!";//���Իػ�
//����R�Ĵ�����ַ
code char *R_LASER_POSWIDTH				= "R03002";//�����������趨
code char *R_LASER_NEGWIDTH 			= "R03003";//���⸺�����趨
code char *R_LASER_GROUP_SPACE			= "R03004";//Ⱥ������
code char *R_LASER_GROUP_NUM 			= "R03005";//Ⱥ�������
code char *R_LASER_MODE					= "R03006";//����ģʽ
code char *R_LASER_SELECT				= "R03007";//ͨ��ѡ��
code char *R_SETCUR_CH1		 			= "R03198";//����ͨ��1�����趨
code char *R_SETCUR_CH2 				= "R03199";//����ͨ��2�����趨
code char *W_VERSION					= "R03200";//�忨�̼��汾
code char *W_IPID_OUT					= "R03201";//IPID���ֵ	
code char *W_LASER_T					= "R03202";//�������¶�	NTC0
code char *W_RADIATOR_T	 				= "R03203";//ɢ�����¶�	NTC1
code char *W_ENVI_T						= "R03204";//�忨�¶�	TMCU
code char *W_PHOTODIODE_CH1				= "R03205";//PD1����ֵ	mV
code char *W_PHOTODIODE_CH2				= "R03206";//PD2����ֵ  mV
//����D�Ĵ�����ַ
code char *R_IPID_KP					= "D00002";//IPID ����KP ��������
code char *R_IPID_TI					= "D00003";//IPID ����TI����ʱ��
code char *R_IPID_TD					= "D00004";//IPID ����TD΢��ʱ��
code char *R_IPID_TS					= "D00005";//IPID ����TS��������
code char *R_IPID_REFT					= "D00005";//IPID ����Ŀ���¶�
code char *R_FAN_V						= "D00006";//����ת���趨 0-4095
code char *R_AIM_VOLTAGE				= "D00007";//ָʾ��������
code char *R_BEEM_VOLUME				= "D00008";//����������
//����M�Ĵ�����ַ
code char *W_FLAG_MCUHEART				= "M0001";//������PLC����
code char *R_MCU_RESET					= "M0003";//PLC��λMCU
code char *R_BEEM_ENABLE				= "M0004";//������ʹ��
code char *W_FIBER_SENSOR_CH1			= "M0005";//������ͨ��0���˱���
code char *W_FIBER_SENSOR_CH2			= "M0006";//������ͨ��1���˱���
code char *W_COOL_ENABLE				= "M0029";//�������MCU
code char *R_FLAG_LASER_START 			= "M0034";//���⿪ʼ�����־
code char *W_FLAG_LASER_INDICATE		= "M0035";//���ⷢ����ϱ�־
code char *R_LASER_READY				= "M0050";//׼��״̬
/*****************************************************************************/
void startLaser(myDevice_t *p);
void stopLaser(myDevice_t *p);
void SetLaserCurrent(myDevice_t *p) reentrant;
void Timer1_Init(void);
void Timer2_Init(void);
/*****************************************************************************/

static void Timer2_Init(void)
{//TIMER2 ��ʼ��
	int8_t SFRPAGE_save = SFRPAGE;	
	uint16_t temp;
	SFRPAGE = ACTIVE_PAGE;
	TMR2CN = 0x0;
	temp = (uint16_t)(0xFFFF - (CONFIG_TIMER2_OVERFLOW_US * (CONFIG_SYSCLK / 1000000L)));
	TMR2RLH = (uint8_t)((temp >> 8) & 0xff);
	TMR2RLL = (uint8_t)(temp & 0xff);
	TF2H = 0;//Timer 2 High Byte Overflow Flag.
	TF2L = 0;//Timer 2 Low Byte Overflow Flag.	
	ET2 = 0;
	TR2 = 0;//ʹ��TIMER2��ʱ��
	SFRPAGE = SFRPAGE_save;
}

void Timer2_ISR(void) interrupt INTERRUPT_TIMER2
{//TIMER2 �ж� ���ⷢ��
	data myDevice_t *p = &myDevice;
	data int8_t SFRPAGE_save = SFRPAGE;
	SFRPAGE = ACTIVE_PAGE;
	TF2H = 0;
	SFRPAGE = SFRPAGE_save;
	switch(p->LaserMode)
	{
		case ENUM_MODE_CC:
		{//CCģʽ
			SetLaserCurrent(p);
			break;
		}
		case ENUM_MODE_SP:
		{//SPģʽ
			break;
		}
		case ENUM_MODE_MP:
		{//MPģʽ	
			if(p->softTimer.tCounter == p->softTimer.tMate)
			{//��ʱ��ƥ��
				LaserMod_PIN = LASER_OFF;//��ת���
			}
			if(p->softTimer.tCounter == p->softTimer.tOverflow)
			{//��ʱ�����
				p->softTimer.tCounter = 0;//����
			}
			if(p->softTimer.tCounter == 0)
			{//��ת
				LaserMod_PIN = LASER_ON;//��ת���
			}
			p->softTimer.tCounter ++;
			break;
		}
		case ENUM_MODE_GP:
		{//GPģʽ
			if(p->softTimer.pCounter < p->softTimer.pMate)
			{
				if(p->softTimer.tCounter == 0)
				{
					if(p->softTimer.pCounter < p->softTimer.pMate)
					{
						LaserMod_PIN = LASER_ON;//��ת���						
					}
				}
				if(p->softTimer.tCounter == p->softTimer.tMate)
				{//��ʱ��ƥ��
					LaserMod_PIN = LASER_OFF;//��ת���
				}
				if(p->softTimer.tCounter == (p->softTimer.tOverflow - 1))
				{//��ʱ�����
					p->softTimer.tCounter = 0xFFFF;//����
					p->softTimer.pCounter ++;//����	
				}
				p->softTimer.tCounter ++;
			}
			if(p->softTimer.pCounter == p->softTimer.pMate && p->softTimer.tCounter == 0)
			{//�����������ƥ��
				LaserMod_PIN = LASER_OFF;
				p->softTimer.pCounter = 0xFFFF;
				p->softTimer.sCounter = 0x0;
			}
			if(p->softTimer.pCounter == 0xFFFF)
			{		
				if(p->softTimer.sCounter == p->softTimer.sMate)
				{
					p->softTimer.pCounter = 0;	
				}
				p->softTimer.sCounter ++;
			}
			break;
		}
		default:break;
	}
}

void initLaserPulse(void)
{//��ʼ��LaserPulse
}

void setLaserCurrent(myDevice_t *p) reentrant
{//�趨����������ֵ
	if(p->SelectChannel == ENUM_CHANNEL1)
	{
		//ad5621_write(AD5621_LASER_CH1, p->LaserCurrent[0]);
	}
	else if(myDevice.SelectChannel == ENUM_CHANNEL2)
	{
		//ad5621_write(AD5621_LASER_CH2, p->LaserCurrent[1]);
	}
	else if(p->SelectChannel == ENUM_CHANNEL_BOTH)
	{
		//ad5621_write(AD5621_LASER_CH1, p->LaserCurrent[0]);
		//ad5621_write(AD5621_LASER_CH2, p->LaserCurrent[1]);
	}
} 

void startLaser(myDevice_t *p)
{//��ʼ��������	
	data int8_t SFRPAGE_save = SFRPAGE;
	if(p->LaserMode == ENUM_MODE_CW)
	{
		SetLaserCurrent(p);
		LaserMod_PIN = LASER_ON;
	}
	else if((p->LaserMode == ENUM_MODE_SP) | 
			(p->LaserMode == ENUM_MODE_MP) |
			(p->LaserMode == ENUM_MODE_GP))
	{
		p->softTimer.tMate = p->PosWidth;//����ƥ��ֵ
		p->softTimer.tOverflow = p->NegWidth + p->PosWidth;//�������ֵ
		p->softTimer.tCounter = 0x0;	
		p->softTimer.pMate = 0x0;//�������ƥ��ֵ
		p->softTimer.sMate = 0x0;//���������ֵ
		p->softTimer.pCounter = 0x0;
		p->softTimer.sCounter = 0x0;
		SFRPAGE = ACTIVE_PAGE;	
		TF2H = 0;//Timer 2 High Byte Overflow Flag.
		ET2 = 1;
		SetLaserCurrent(p);
		TMR2L = 0xFF;
		TMR2H = 0xFF;
		TR2 = 1;//ʹ��TIMER2��ʱ��
		SFRPAGE = SFRPAGE_save;
	}
	else if(p->LaserMode == ENUM_MODE_CC)
	{//У��ģʽ
		p->softTimer.tMate = p->PosWidth;//����ƥ��ֵ
		p->softTimer.tOverflow = p->NegWidth + p->PosWidth;//�������ֵ
		p->softTimer.tCounter = 0x0;	
		p->softTimer.pMate = p->GroupNum;//�������ƥ��ֵ
		p->softTimer.sMate = p->GroupSpace;//���������ֵ
		p->softTimer.pCounter = 0x0;
		p->softTimer.sCounter = 0x0;
		SFRPAGE = ACTIVE_PAGE;	
		TF2H = 0;//Timer 2 High Byte Overflow Flag.
		ET2 = 1;
		TMR2L = 0xFF;
		TMR2H = 0xFF;
		TR2 = 1;//ʹ��TIMER2��ʱ��
		SFRPAGE = SFRPAGE_save;
	}
	p->FlagIndicate = 1;
}
void stopLaser(myDevice_t *p)
{//ֹͣ��������
	TR2 = 0;
	ET2 = 0;
	TF2H = 0;
	LaserMod_PIN = LASER_OFF;
	ad5621_write(AD5621_LASER_CH1, 0);
	ad5621_write(AD5621_LASER_CH2, 0);
	p->FlagIndicate = 0;	
}

