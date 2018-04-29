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
{//软PLC线程
	yydata = yydata;
	while(1)
	{
		 OSTimeDly(100);
	}
}
void main(void)
{
	Init_Device();//初始化MCU
	InitOsTimer();//UCOS 计时器T0 初始化
	//SoftPlc_Init();
	//setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//设置从机地址
	//InitModbusHardware(CONFIG_UART0_BAUDRATE);//初始化MODBUS从机串口
	OSTaskCreate(softPlcTask, (void *)0, (void *)&softPlcTaskStk[0], 5);/* 建立任务0 */
	OSStart();                        /* 开始多任务调度 */
	/**********************************************************************/
	while(1)
	{
	}		
}


