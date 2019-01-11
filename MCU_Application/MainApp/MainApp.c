#include "MainApp.h"
/*****************************************************************************/
//C8051F020 �����ʱ�����ܶ���
//TIMER0 ->SPLC_FRAME
//TIMER1 ->
//TIMER2 ->UART0 Buadrate
//TIMER3 ->Modbus RTU TIMER
//TIMER4 ->UART1 Buadrate
//C8051F580 ��ʱ�����ܶ���
//TIMER0 ->SPLC_FRAME
//TIMER1 ->UART1 Baud Rate Generator
//TIMER2 ->SPLC_LASER
//TIMER3 ->MODBUS RTU TIMER
//TIMER4 ->EXT TIMER OUT
//TIMER5 ->BEEM
/*****************************************************************************/
//sbit LED_MCU = P2^3;//������ָʾLED
//sbit LED_LASER0 = P1^7;//���ⷢ��ָʾLED0 980nM
//sbit LED_LASER1 = P1^6;//���ⷢ��ָʾLED1 1470nM
//bit  TP0, TP1, TP2, TP3;
/*****************************************************************************/
#define ENUM_MODE_CW					0//����ģʽ
#define ENUM_MODE_SP					1//������ģʽ
#define ENUM_MODE_MP					2//������ģʽ
#define ENUM_MODE_GP					3//Ⱥ����ģʽ
#define ENUM_MODE_CC					4//У��ģʽ
/*****************************************************************************/
/*****************************************************************************/
#define STEPNUM_FAULT					-1//����
#define STEPNUM_INIT					0//��ʼ��
#define STEPNUM_STANDBY					1//����
#define STEPNUM_INTO_READY				2//����׼��
#define STEPNUM_READY					3//׼��
#define STEPNUM_LASERON					4//���⿪ʼ

/*****************************************************************************/
void main(void){
	uint8_t tmp;
#ifdef C8051F020
	initDeviceF020();
#endif
#ifdef C8051F580
	initDeviceF580();
	inPca9554Init();
	epromTest();
	tmp = inPca9554Read();
	tmp &= 0x0;
	tmp = inPca9554Read();
	tmp &= 0x0;
	tmp = inPca9554Read();
	tmp &= 0x0;
	tmp = inPca9554Read();
	tmp &= 0x0;
	tmp = inPca9554Read();
	tmp &= 0x0;
	tmp = inPca9554Read();
	tmp &= 0x0;
	tmp = inPca9554Read();
	tmp &= 0x0;
	//while(1);
#endif
#if CONFIG_USING_WDT == 1
	if ((RSTSRC & 0x02) == 0x00)
	{
		if (RSTSRC == 0x08)
		{//���WDT���Ź� ���Ź���λ������
			while(1);
		}
	}
#endif
	sPlcInit();//��ʼ�����߼�
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
	NVRAM0[SPREG_CHECKCODE] = CONFIG_CHECK_CODE;
	ENABLE_INTERRUPT;
	while(1){
		sPlcProcessStart();
		NVRAM0[EM_MCU_CHECKCODE] = CONFIG_CHECK_CODE;//д��忨У����
		if(LD(R_MCU_RESET)){
			REBOOT();
		}
		sPlcLaser();
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

