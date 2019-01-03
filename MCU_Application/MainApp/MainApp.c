#include "MainApp.h"
/*****************************************************************************/
//C8051F020 ��ʱ�����ܶ���
//TIMER0 ->SPLC_FRAME
//TIMER1 ->Modbus RTU
//TIMER2 ->UART0 Buadrate
//TIMER3 ->SPLC_LASER
//TIMER4 ->UART1 Buadrate
/*****************************************************************************/
//sbit LED_MCU = P2^3;//������ָʾLED
//sbit LED_LASER0 = P1^7;//���ⷢ��ָʾLED0 980nM
//sbit LED_LASER1 = P1^6;//���ⷢ��ָʾLED1 1470nM
//bit  TP0, TP1, TP2, TP3;
/*****************************************************************************/
#define ENUM_CHANNEL1					4321
#define ENUM_CHANNEL2					8765
#define ENUM_CHANNEL_BOTH				9431
#define ENUM_MODE_CW					0//����ģʽ
#define ENUM_MODE_SP					1//������ģʽ
#define ENUM_MODE_MP					2//������ģʽ
#define ENUM_MODE_GP					3//Ⱥ����ģʽ
#define ENUM_MODE_CC					4//У��ģʽ
/*****************************************************************************/
#define INPUT_FOOTSWITCH_NC				0
#define INPUT_FOOTSWITCH_NO				1
#define INPUT_INTERLOCK					2
#define INPUT_OPENCASE					3
#define INPUT_FIBERDETECT0				4
#define INPUT_FIBERDETECT1				5

#define STIMER_1MS_INPUT_FILTER			0//�����˲���ʱ��			
#define STIMER_1MS_SP_LASER_ON			1//������ON��ʱ��
#define STIMER_1MS_MP_LASER_ON			2//������ON��ʱ��
#define STIMER_1MS_MP_LASER_OFF			3//������OFF��ʱ��
#define STIMER_1MS_GP_LASER_ON			4//�ɱ�����ON��ʱ��
#define STIMER_IMS_GP_LASER_OFF			5//�ɱ�����OFF��ʱ��
#define STIMER_1MS_GP_SPACE				6//�ɱ���������ʱ��

#define STIMER_1000MS_PID				61//PID�¶����ڼ�ʱ��
#define STIMER_100MS_OFF_BEEM			44//���伤����ʱ������OFF��ʱ��
#define STIMER_100MS_ON_BEEM			45//���伤����ʱ������ON��ʱ��
#define STIMER_100MS_INTOREADY_BEEM		46//INTO READY���������ʱ��

#define STIMER_1000MS_LED_ON			62//LED��˸ON��ʱ��
#define STIMER_1000MS_LED_OFF			63//LED��˸OFF��ʱ��
/*****************************************************************************/

#define STEPNUM_FAULT					-1//����
#define STEPNUM_INIT					0//��ʼ��
#define STEPNUM_STANDBY					1//����
#define STEPNUM_INTO_READY				2//����׼��
#define STEPNUM_READY					3//׼��
#define STEPNUM_LASERON					4//���⿪ʼ



//#define DM_LASER_CURRENT_0			0//����������0
//#define DM_LASER_CURRENT_1			1//����������1
//#define DM_PHOTODIODE_0				2//����������0
//#define DM_PHOTODIODE_1				3//����������1
//#define DM_LASER_MODE				4//���ⷢ��ģʽ
//#define DM_LASER_POSWIDTH			5//��������������
//#define DM_LASER_NEGWIDTH			6//��������������
//#define DM_LASER_GROUP_NUM			7//����Ⱥ�������
//#define DM_LASER_GROUP_SPACE		8//����Ⱥ������
//#define DM_LASER_SELECT_CHANNEL		9//����ͨ��ѡ��

//#define MCP4768_DAC1		1
//#define MCP4768_DAC2		2
//#define MCP4768_DAC3		3
//#define MCP4768_DAC4		4

/*****************************************************************************/
sbit loopFlag = P0^4;
sbit epromBusyFlag = P0^5;
void main(void){
#ifdef C8051F020
	initDeviceF020();
#endif
	sPlcInit();//��ʼ�����߼�
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
	NVRAM0[0] = 0xA5;
	NVRAM0[1] = 0x5A;
	ENABLE_INTERRUPT;
	while(1){
		loopFlag = ~loopFlag;
		sPlcProcessStart();
		//SPLC�������˴�
////		SET(10);
////		RESET(10);
////		SET(10);
////		RESET(10);
////		SET(10);
////		RESET(10);
////		SET(10);
////		RESET(10);
////		FLIP(10);
////		FLIP(10);
////		FLIP(10);
////		FLIP(10);
////		//��ȡIO
////		//ִ�г���
////		//���IO
////		T100MS(0, 1, 2);
////		if(LD(TD_100MS_START * 16 + 0));
////		{
////			SET(0);	
////		}
		sPlcProcessEnd();
	}
}

