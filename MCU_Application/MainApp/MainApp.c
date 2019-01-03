#include "MainApp.h"
/*****************************************************************************/
//C8051F020 计时器功能定义
//TIMER0 ->SPLC_FRAME
//TIMER1 ->Modbus RTU
//TIMER2 ->UART0 Buadrate
//TIMER3 ->SPLC_LASER
//TIMER4 ->UART1 Buadrate
/*****************************************************************************/
//sbit LED_MCU = P2^3;//处理器指示LED
//sbit LED_LASER0 = P1^7;//激光发射指示LED0 980nM
//sbit LED_LASER1 = P1^6;//激光发射指示LED1 1470nM
//bit  TP0, TP1, TP2, TP3;
/*****************************************************************************/
#define ENUM_CHANNEL1					4321
#define ENUM_CHANNEL2					8765
#define ENUM_CHANNEL_BOTH				9431
#define ENUM_MODE_CW					0//连续模式
#define ENUM_MODE_SP					1//单脉冲模式
#define ENUM_MODE_MP					2//多脉冲模式
#define ENUM_MODE_GP					3//群脉冲模式
#define ENUM_MODE_CC					4//校正模式
/*****************************************************************************/
#define INPUT_FOOTSWITCH_NC				0
#define INPUT_FOOTSWITCH_NO				1
#define INPUT_INTERLOCK					2
#define INPUT_OPENCASE					3
#define INPUT_FIBERDETECT0				4
#define INPUT_FIBERDETECT1				5

#define STIMER_1MS_INPUT_FILTER			0//输入滤波计时器			
#define STIMER_1MS_SP_LASER_ON			1//单脉冲ON计时器
#define STIMER_1MS_MP_LASER_ON			2//多脉冲ON计时器
#define STIMER_1MS_MP_LASER_OFF			3//多脉冲OFF计时器
#define STIMER_1MS_GP_LASER_ON			4//可变脉冲ON计时器
#define STIMER_IMS_GP_LASER_OFF			5//可变脉冲OFF计时器
#define STIMER_1MS_GP_SPACE				6//可变脉冲间隔计时器

#define STIMER_1000MS_PID				61//PID温度周期计时器
#define STIMER_100MS_OFF_BEEM			44//发射激光器时蜂鸣器OFF计时器
#define STIMER_100MS_ON_BEEM			45//发射激光器时蜂鸣器ON计时器
#define STIMER_100MS_INTOREADY_BEEM		46//INTO READY后蜂鸣器计时器

#define STIMER_1000MS_LED_ON			62//LED闪烁ON计时器
#define STIMER_1000MS_LED_OFF			63//LED闪烁OFF计时器
/*****************************************************************************/

#define STEPNUM_FAULT					-1//故障
#define STEPNUM_INIT					0//初始化
#define STEPNUM_STANDBY					1//待机
#define STEPNUM_INTO_READY				2//进入准备
#define STEPNUM_READY					3//准备
#define STEPNUM_LASERON					4//激光开始



//#define DM_LASER_CURRENT_0			0//激光器电流0
//#define DM_LASER_CURRENT_1			1//激光器电流1
//#define DM_PHOTODIODE_0				2//激光器反馈0
//#define DM_PHOTODIODE_1				3//激光器反馈1
//#define DM_LASER_MODE				4//激光发射模式
//#define DM_LASER_POSWIDTH			5//激光脉冲正脉宽
//#define DM_LASER_NEGWIDTH			6//激光脉冲正脉宽
//#define DM_LASER_GROUP_NUM			7//激光群脉冲个数
//#define DM_LASER_GROUP_SPACE		8//激光群脉冲间隔
//#define DM_LASER_SELECT_CHANNEL		9//激光通道选择

//#define MCP4768_DAC1		1
//#define MCP4768_DAC2		2
//#define MCP4768_DAC3		3
//#define MCP4768_DAC4		4

/*****************************************************************************/
sbit loopFlag = P0^4;
sbit epromBusyFlag = P0^5;
void main(void){
#ifdef C8051F020
	initDeviceF020();
#endif
	sPlcInit();//初始化软逻辑
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
	NVRAM0[0] = 0xA5;
	NVRAM0[1] = 0x5A;
	ENABLE_INTERRUPT;
	while(1){
		loopFlag = ~loopFlag;
		sPlcProcessStart();
		//SPLC代码插入此处
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
////		//读取IO
////		//执行程序
////		//输出IO
////		T100MS(0, 1, 2);
////		if(LD(TD_100MS_START * 16 + 0));
////		{
////			SET(0);	
////		}
		sPlcProcessEnd();
	}
}

