#include "MainApp.h"
/*****************************************************************************/
//TIMER0 ->uCos Tick
//TIMER1 ->UART0/1 Buadrate
//TIMER2 ->Modbus Slave TIMER
//TIMER3 ->HW I2C
//TIMER4 ->Laser Pulse
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

void main(void)
{
	Init_Device();//初始化MCU
	//SoftPlc_Init();
	//setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//设置从机地址
	//InitModbusHardware(CONFIG_UART0_BAUDRATE);//初始化MODBUS从机串口
	/**********************************************************************/
	while(1)
	{
	}		
}


