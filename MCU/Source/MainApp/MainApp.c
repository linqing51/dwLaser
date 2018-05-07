#include "MainApp.h"
/*****************************************************************************/
//TIMER0 ->Laser Pulse
//TIMER1 ->UART0/1 Buadrate
//TIMER2 ->Modbus Slave TIMER
//TIMER3 ->HW I2C
//TIMER4 ->SoftPLC HWTIMER
/*****************************************************************************/
sbit LED3 = P1^7;
sbit LED4 = P1^6;
/*****************************************************************************/
void main(void)
{
	uint8_t st;
	pidFuzzy_t pidFuzzy;
	Init_Device();//初始化MCU
	
	SoftPlc_Init(&softPlc);
	pidFuzzyInit(&pidFuzzy);
	setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//设置从机地址
	InitModbusHardware(CONFIG_UART0_BAUDRATE);//初始化MODBUS从机串口
	/**********************************************************************/
	EA = 1;
	LED3 = 0;
	LED3 = 1;
	LED4 = 0;
	LED4 = 1;
	//setCoil(&softPlc.M, 1000);//M1000
	while(1)
	{//开始循环扫描周期
		if(LED3)
		{
			if(softPlc.T_10ms[0].output)//等待时间A
			{
				LED3 = 0;
				stopTimer(&softPlc.T_10ms[0]);
			}
			else
				startTimer(&softPlc.T_10ms[0], 50);
		}
		if(!LED3)
		{
			if(softPlc.T_10ms[1].output)//等待时间B
			{
				LED3 = 1;
				stopTimer(&softPlc.T_10ms[1]);
			}
			else
				startTimer(&softPlc.T_10ms[1], 20);
				
		}
		//PID指令
		//if(getCoil(&softPlc.M, 100))
		//{//执行PID 温控指令
			//执行PID
		if(softPlc.T_10ms[2].output)//等待A时间
		{
			pidFuzzyRealize(&pidFuzzy, 25.0, 30.0);
			stopTimer(&softPlc.T_10ms[2]);//停止计时器
		}
		else
		{
			startTimer(&softPlc.T_10ms[2], 100);//开始计数器	
		}
		//}
		modbusPoll();//执行MODBUS POLL
		
		setOutput(&softPlc);//更新输出IO
		
		//看门狗喂狗
		
	}		
}



