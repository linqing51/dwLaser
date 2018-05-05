#include "MainApp.h"
/*****************************************************************************/
//TIMER0 ->Laser Pulse
//TIMER1 ->UART0/1 Buadrate
//TIMER2 ->Modbus Slave TIMER
//TIMER3 ->HW I2C
//TIMER4 ->SoftPLC HWTIMER
/*****************************************************************************/

/*****************************************************************************/
void main(void)
{
	uint8_t st;
	Init_Device();//初始化MCU
	SoftPlc_Init(&softPlc);
	//setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//设置从机地址
	//InitModbusHardware(CONFIG_UART0_BAUDRATE);//初始化MODBUS从机串口
	/**********************************************************************/
	EA = 1;
	st = 0;
	while(1)
	{
		startTimer(&softPlc.T_1000ms[4], 10);
		if(softPlc.T_1000ms[4].output)
		{
			st = 1;
		}
	}		
}


