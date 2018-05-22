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
#define ENUM_CHANNEL1					4321
#define ENUM_CHANNEL2					8765
#define ENUM_CHANNEL_BOTH				9431
#define ENUM_MODE_CW					7631//连续模式
#define ENUM_MODE_SP					8934//单脉冲模式
#define ENUM_MODE_MP						2453//多脉冲模式
#define ENUM_MODE_GP						3876//群脉冲模式
#define ENUM_MODE_CC						14563//校正模式
/*****************************************************************************/
laser_t laser;

/*****************************************************************************/
void main(void)
{
	int8_t temp;
	pidFuzzy_t pidFuzzy;
	Init_Device();//初始化MCU
	//hwI2cInit();//初始化硬件I2C
	sTimerInit();//初始化软逻辑
	//SMB_Init();
	//pidFuzzyInit(&pidFuzzy);//初始化模糊PID
	setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//设置从机地址
	InitModbusHardware(CONFIG_UART0_BAUDRATE);//初始化MODBUS从机串口
	/**********************************************************************/
	EA = 1;
	
	while(1)
	{//开始循环扫描周期
		//每10mS扫描输入IO
		if(sTimer[0].status)
		{
		
		}
		//获取过热状态
		laser.overTempFault = (laser.overTempDiode && !laser.overTempDiodeIgnore) ||
							  (laser.overTempAmplifier && !laser.overTempAmplifierIgnore) ||
	                          (laser.overTempEnvironment && !laser.overTempEnvironmentIgnore) ||
							  (laser.overTempMcu && !laser.overTempMcuIgnore);
	    laser.overTempFault = laser.overTempFault && !laser.overTempIgnore;
		//获取安全状态
		laser.safeFault = (laser.safeInterlock && !laser.safeInterlockIgnore) ||
					(laser.safeFiberDetect0 && laser.safeFiberDetect0Ignore) ||
					(laser.safeFiberDetect1 && laser.safeFiberDetect1Ignore) ||
					(laser.safeOpenCase && laser.safeOpenCaseIgnore);
		laser.safeFault = laser.safeFault && !laser.safeFaultIgnore;
		//模拟输入扫描
		//检测故障

//		//确定发射模式
//		if(!softPlc.M[MADR_OVERTMP] &&//检测无过热
//		   !softPlc.M[MADR_SAFTFAULT] &&//无安全故障 
//		    softPlc.M[R_MADR_FOOTSWITCH] &&//脚踏触发
//		    softPlc.M[MADR_READY])//准备状态
//		{
//			switch(softPlc.R[RADR_LASER_MODE])
//			{
//				case ENUM_MODE_CW:
//				{//开始连续模式
//					
//					break;
//				}
//				case ENUM_MODE_SP:
//				{//开始单脉冲模式
//					break;
//				}
//				case ENUM_MODE_MP:
//				{//开始多脉冲模式
//					break;
//				}
//				case ENUM_MODE_GP:
//				{//开始可编程模式
//					break;
//				}
//				case ENUM_MODE_CC:
//				{//开始校正模式
//					break;
//				}
//				default:break;
//			}
//			
//		}
		
		
		if(LED_MCU)
		{
			if(sTimer[0].status)//等待时间A
			{
				LED_MCU = 0;
				sTimerCtrl(0, 0, 10);//T0 STOP
			}
			else
				sTimerCtrl(1, 0, 10);//T0 STOP
		}
		if(!LED_MCU)
		{
			if(sTimer[0].status)//等待时间B
			{
				LED_MCU = 1;
				sTimerCtrl(0, 1, 20);//T0 STOP
			}
			else
				sTimerCtrl(1, 1, 20);//T0 STOP
		}
		//PID指令
		//if(getCoil(&softPlc.M, 100))
		//{//执行PID 温控指令
			//执行PID
//		if(softPlc.T_10ms[2].output)//等待A时间
//		{
//			//pidFuzzyRealize(&pidFuzzy, 25.0, 30.0);
//			stopTimer(&softPlc.T_10ms[2]);//停止计时器
//		}
//		else
//		{
//			startTimer(&softPlc.T_10ms[2], 100);//开始计数器	
//		}
//		
//		if(softPlc.T_100ms[4].output)
//		{
//			stopTimer(&softPlc.T_100ms[4]);
//		}
//		else
//		{
//			startTimer(&softPlc.T_100ms[4],1);
//		}
//		
//		if(softPlc.T_1000ms[4].output)
//		{
//			stopTimer(&softPlc.T_1000ms[4]);
//		}
//		else
//		{
//			startTimer(&softPlc.T_1000ms[4],1);
//		}
		modbusPoll();//执行MODBUS POLL
		
		//setOutput();//更新输出IO
		
		//看门狗喂狗
		
	}		
}



