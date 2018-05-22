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
//非保持位数据
#define MADR_START_CW							10//启动CW
#define MADR_START_SP							11//启动SP
#define MADR_START_MP							12//启动MP
#define MADR_START_GP							13//启动GP 可编程脉冲
#define MADR_START_CC							14//启动CC 校正模式


#define MADR_LASER_OVERTEMP					1//激光器过热
#define MADR_LASER_OVERTEMP_IGNORE			2//激光器过热忽略
#define MADR_ENVI_OVERTEMP					3//环境过热
#define MADR_ENVI_OVERTEMP_IGNORE				4//环境过热忽略
#define MADR_DRIVE_OVERTEMP					5//驱动器过热
#define MADR_DRIVE_OVERTEMP_IGNORE			6//驱动器过热忽略
#define MADR_MCU_OVERTEMP						7//单片机过热
#define MADR_MCU_OVERTEMP_IGNORE				8//单片机过热忽略

#define MADR_INTERLOCK						9//安全连锁
#define MADR_INTERLOCK_IGNORE					10//安全连锁忽略
#define MADR_FIBER_DETECT0					11//光纤探测1
#define MADR_FIBER_DETECT0_IGNORE				12//光纤探测1忽略
#define MADR_FIBER_DETECT1					13//光纤探测2
#define MADR_FIBER_DETECT1_IGNORE				14//光纤探测2忽略
#define MADR_OPEN_CASE						15//开机检测
#define MADR_OPEN_CASE_IGNORE					16//开机检测忽略
#define MADR_OVERTEMP							17//温度过热故障
#define MADR_OVERTEMP_IGNORE					18//温度过热故障忽略
#define MADR_SAFTFAULT						19//安全检查失败
#define MADR_SAFTFAULT_IGNORE					20//安全检查失败忽略

#define MADR_READY							21//待机准备状态

#define MADR_FOOTSWITCH						22//脚踏
//非保持16位数据
#define DADR_LASER_CURRENT0					1//通道0激光电流值 mA
#define DADR_LASER_CURRENT1					2//通道1激光电流值 mA
#define DADR_LASER_MODE						3//激光发射模式
#define DADR_LASER_POSWIDTH					4//激光发射正脉宽 mS
#define DADR_LASER_NEGWIDTH					5//激光发射负脉宽 mS
#define DADR_LASER_GROUPNUM					6//激光发射脉冲数
#define DADR_LASER_GROUPSPACE					7//激光发射脉冲间隔时间 mS
#define DADR_LASER_CHANNEL					8//激光通道选择
#define DADR_PWNOUT0							9//PWM模拟输出0
#define DADR_PWMOUT1							10//PWM模拟输出1
#define DADR_PWMOUT2						11//PWM模拟输出2
#define DADR_PWMOUT3						12//PWM模拟输出3
#define DADR_NTCTEMP0						13//NTC温度读值0
#define DADR_NTCTEMP1						14//NTC温度读值1
#define DADR_NTCTEMP2						15//NTC温度读值2
#define DADR_NTCTEMP3						16//NTC温度读值3
#define DADR_MCUTEMP						17//单片机温度读值

#define SP_TADR_INPUTFILTER					0//输入滤波计时器
/*****************************************************************************/
void main(void)
{
	int8_t temp;
	pidFuzzy_t pidFuzzy;
	Init_Device();//初始化MCU
	//hwI2cInit();//初始化硬件I2C
	SoftPlc_Init(&softPlc);//初始化软逻辑
	//SMB_Init();
	//pidFuzzyInit(&pidFuzzy);//初始化模糊PID
	setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//设置从机地址
	InitModbusHardware(CONFIG_UART0_BAUDRATE);//初始化MODBUS从机串口
	/**********************************************************************/
	EA = 1;
	while(1)
	{//开始循环扫描周期
		if(LD(SOFTPLC_T, SP_TADR_INPUTFILTER))
		{
			getInput(&softPlc);//输入IO扫描
		}
		temp = (LD(SOFTPLC_M, MADR_LASER_OVERTEMP) && LD(SOFTPLC_M, MADR_LASER_OVERTEMP_IGNORE)) ||
		       (LD(SOFTPLC_M, MADR_ENVI_OVERTEMP) && LD(SOFTPLC_M, MADR_ENVI_OVERTEMP_IGNORE)) ||
			   (LD(SOFTPLC_M, MADR_DRIVE_OVERTEMP) && LD(SOFTPLC_M, MADR_ENVI_OVERTEMP_IGNORE)) ||
		       (LD(SOFTPLC_M, MADR_MCU_OVERTEMP) && LD(SOFTPLC_M, MADR_MCU_OVERTEMP_IGNORE));
		OUT(SOFTPLC_M, MADR_OVERTEMP, temp);
		//模拟输入扫描
		//检测故障
//		softPlc.M[MADR_OVERTEMP] = 
//								
//								
//								(softPlc.M[MADR_MCU_OVERTEMP] && softPlc.M[MADR_MCU_OVERTEMP_IGNORE]);
//		softPlc.M[MADR_OVERTEMP] &= !softPlc.M[MADR_OVERTEMP_IGNORE]; 
//		//安全检查
//		softPlc.M[MADR_SAFTFAULT] = (softPlc.M[MADR_INTERLOCK] && softPlc.M[MADR_INTERLOCK_IGNORE]) ||
//									(softPlc.M[MADR_FIBER_DETECT1] && softPlc.M[MADR_FIBER_DETECT1_IGNORE]) ||
//									(softPlc.M[MADR_FIBER_DETECT2] && softPlc.M[MADR_FIBER_DETECT2_IGNORE]) ||
//									(softPlc.M[MADR_OPEN_CASE] && softPlc.M[MADR_OPEN_CASE_IGNORE]);
//		softPlc.M[MADR_SAFTFAULT] &= !softPlc.M[MADR_SAFTFAULT_IGNORE];
//		
//		if(softPlc.M[MADR_OVERTEMP] || softPlc.M[MADR_SAFTFAULT])
//		{//检测到过热或安全故障进入待机状态
//			softPlc.M[MADR_READY] = false;//进入待机状态
//			//关闭激光
//		}
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
			if(LD(SOFTPLC_T, 0))//等待时间A
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
		
		setOutput();//更新输出IO
		
		//看门狗喂狗
		
	}		
}



