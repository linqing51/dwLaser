#include "MainApp.h"
/*****************************************************************************/
//TIMER0 ->Laser Pulse
//TIMER1 ->UART0/1 Buadrate
//TIMER2 ->Modbus Slave TIMER
//TIMER3 ->HW I2C
//TIMER4 ->SoftPLC HWTIMER
/*****************************************************************************/
sbit LED_MCU = P2^3;//处理器指示LED
sbit LED_LASER0 = P1^7;//激光发射指示LED0 980nM
sbit LED_LASER1 = P1^6;//激光发射指示LED1 1470nM
/*****************************************************************************/
void main(void)
{
	pidFuzzy_t pidFuzzy;
	Init_Device();//初始化MCU
	//hwI2cInit();//初始化硬件I2C
	SoftPlc_Init(&softPlc);//初始化软逻辑
	SMB_Init();
	//pidFuzzyInit(&pidFuzzy);//初始化模糊PID
	setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//设置从机地址
	InitModbusHardware(CONFIG_UART0_BAUDRATE);//初始化MODBUS从机串口
	/**********************************************************************/
	EA = 1;
	while(1)
	{//开始循环扫描周期
		getInput();
		if(LED_MCU)
		{
			if(softPlc.T_10ms[0].output)//等待时间A
			{
				LED_MCU = 0;
				stopTimer(&softPlc.T_10ms[0]);
			}
			else
				startTimer(&softPlc.T_10ms[0], 50);
		}
		if(!LED_MCU)
		{
			if(softPlc.T_10ms[1].output)//等待时间B
			{
				LED_MCU = 1;
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
			//pidFuzzyRealize(&pidFuzzy, 25.0, 30.0);
			stopTimer(&softPlc.T_10ms[2]);//停止计时器
		}
		else
		{
			startTimer(&softPlc.T_10ms[2], 100);//开始计数器	
		}
		
		if(softPlc.T_100ms[4].output)
		{
			stopTimer(&softPlc.T_100ms[4]);
		}
		else
		{
			startTimer(&softPlc.T_100ms[4],1);
		}
		
		if(softPlc.T_1000ms[4].output)
		{
			stopTimer(&softPlc.T_1000ms[4]);
		}
		else
		{
			startTimer(&softPlc.T_1000ms[4],1);
		}
		modbusPoll();//执行MODBUS POLL
		
		setOutput();//更新输出IO
		
		//看门狗喂狗
		
	}		
}



