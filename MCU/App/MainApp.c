#include "MainApp.h"
/*****************************************************************************/
//TIMER0 ->uCos Tick
//TIMER1 ->UART0/1 Buadrate
//TIMER2 ->Modbus Slave TIMER
//TIMER3 ->HW I2C
//TIMER4 ->Laser Pulse
/*****************************************************************************/
OS_STK softPlcTaskStk[CONFIG_TASK_STACK_SIZE];
/*****************************************************************************/
void softPlcTask(void *yydata);
/*****************************************************************************/
/*****************************************************************************/
void softPlcTask(void *yydata)
{//��PLC�߳�
	yydata = yydata;
	while(1)
	{
		 OSTimeDly(100);
	}
}
void main(void)
{
	Init_Device();//��ʼ��MCU
	InitOsTimer();//UCOS ��ʱ��T0 ��ʼ��
	//SoftPlc_Init();
	//setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//���ôӻ���ַ
	//InitModbusHardware(CONFIG_UART0_BAUDRATE);//��ʼ��MODBUS�ӻ�����
	OSTaskCreate(softPlcTask, (void *)0, (void *)&softPlcTaskStk[0], 5);/* ��������0 */
	OSStart();                        /* ��ʼ��������� */
	/**********************************************************************/
	while(1)
	{
	}		
}


