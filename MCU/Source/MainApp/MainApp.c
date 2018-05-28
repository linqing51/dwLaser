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
bit  COOL_OUT;
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

#define INPUT_FOOTSWITCH_NC				0
#define INPUT_FOOTSWITCH_NO				1
#define INPUT_INTERLOCK					2
#define INPUT_OPENCASE					3
#define INPUT_FIBERDETECT0				4
#define INPUT_FIBERDETECT1				5




/*****************************************************************************/
void main(void)
{
	int8_t temp;
	int16_t tecOnTime, tecOffTime;//制冷开关时间
	pidFuzzy_t pidFuzzy;
	Init_Device();//初始化MCU
	//hwI2cInit();//初始化硬件I2C
	sTimerInit();//初始化软逻辑
	//SMB_Init();
	pidFuzzyInit(&pidFuzzy, 2, 0.5, 0.1);
	setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//设置从机地址
	InitModbusHardware(CONFIG_UART0_BAUDRATE);//初始化MODBUS从机串口
	/**********************************************************************/
	EA = 1;
	
	while(1)
	{//开始循环扫描周期
		//每10mS扫描输入IO
		if(sTimer[(CONFIG_STIMER_1MS_NUM - 1)].status)
		{
			if(((( P6 >> INPUT_FOOTSWITCH_NC) & 0x01) == 1) &&
			  ((( P6 >> INPUT_FOOTSWITCH_NO) & 0x01) == 0))
				laser.footSwitch = 1;
			else
				laser.footSwitch = 0;
			laser.safeInterlock = (P6 >> INPUT_INTERLOCK) & 0x01;
			laser.safeFiberDetect0 = (P6 >> INPUT_FIBERDETECT0) & 0x01;
			laser.safeFiberDetect1 = (P6 >> INPUT_FIBERDETECT1) & 0x01;
			sTimerCtrl(STIMER_OFF, (CONFIG_STIMER_1MS_NUM - 1), CONFIG_INPUT_FILTER_TIME);//T0 STOP
		}
		else
			sTimerCtrl(STIMER_ON, (CONFIG_STIMER_1MS_NUM - 1), CONFIG_INPUT_FILTER_TIME);//T0 STOP
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
		
		//Debug LED闪烁
		if(LED_MCU)
		{
			if(sTimer[(CONFIG_STIMER_1000MS_NUM - 1)].status)//等待时间A
			{
				LED_MCU = 0;
				sTimerCtrl(STIMER_OFF, (CONFIG_STIMER_1000MS_NUM - 1), 1);//T0 STOP
			}
			else
				sTimerCtrl(STIMER_ON, (CONFIG_STIMER_1000MS_NUM - 1), 1);//T0 STOP
		}
		if(!LED_MCU)
		{
			if(sTimer[(CONFIG_STIMER_1000MS_NUM - 2)].status)//等待时间B
			{
				LED_MCU = 1;
				sTimerCtrl(STIMER_OFF, (CONFIG_STIMER_1000MS_NUM - 2), 1);//T0 STOP
			}
			else
				sTimerCtrl(STIMER_ON, (CONFIG_STIMER_1000MS_NUM - 2), 1);//T0 STOP
		}
		//PID 温控指令
		if(sTimer[(CONFIG_STIMER_100MS_NUM - 3)].status)//等待A时间
		{
			laser.pidOut += pidFuzzyRealize(&pidFuzzy, 25.0, 26.0);
			if(laser.pidOut > 1)
				laser.pidOut = 1;
			if(laser.pidOut < 0)
				laser.pidOut = 0;
			//laser.onTimerPid = (int16_t)(laser.pidOut * CONFIG_PIDOUT_PWM);
			//laser.offTimerPid = CONFIG_TECOUT_MAX_CYCLE - laser.onTimerPid; 
			sTimerCtrl(STIMER_OFF, (CONFIG_STIMER_100MS_NUM - 3), 10);
		}
		else
			sTimerCtrl(STIMER_ON, (CONFIG_STIMER_100MS_NUM - 3), 10);
		//PID结果输出

		if(sTimer[1].value >= CONFIG_TECOUT_CYCLE || sTimer[1].enable == 0)
		{
			COOL_OUT = 1;
			//tecOnTime = (int16_t)(laser.pidOut * CONFIG_TECOUT_CYCLE);
			tecOnTime = (int16_t)(0.25 * CONFIG_TECOUT_CYCLE);
			sTimerCtrl(STIMER_OFF, 1, tecOnTime);
			sTimerCtrl(STIMER_ON, 1, tecOnTime);
		}
		if(sTimer[1].value >= tecOnTime)
		{
			COOL_OUT = 0;
		}
		modbusPoll();//执行MODBUS POLL
		
		//setOutput();//更新输出IO
		
		//看门狗喂狗
		
	}		
}



