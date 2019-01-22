#include "MainApp.h"
/*****************************************************************************/
//C8051F020 仿真计时器功能定义
//TIMER0 ->SPLC_FRAME
//TIMER1 ->
//TIMER2 ->UART0 Buadrate
//TIMER3 ->Modbus RTU TIMER
//TIMER4 ->UART1 Buadrate
//C8051F580 计时器功能定义
//TIMER0 ->SPLC_FRAME
//TIMER1 ->UART1 Baud Rate Generator
//TIMER2 ->SPLC_LASER
//TIMER3 ->MODBUS RTU TIMER
//TIMER4 ->EXT TIMER OUT
//TIMER5 ->BEEM
/*****************************************************************************/
//sbit LED_MCU = P2^3;//处理器指示LED
//sbit LED_LASER0 = P1^7;//激光发射指示LED0 980nM
//sbit LED_LASER1 = P1^6;//激光发射指示LED1 1470nM
//bit  TP0, TP1, TP2, TP3;
/*****************************************************************************/
#define ENUM_MODE_CW					0//连续模式
#define ENUM_MODE_SP					1//单脉冲模式
#define ENUM_MODE_MP					2//多脉冲模式
#define ENUM_MODE_GP					3//群脉冲模式
#define ENUM_MODE_CC					4//校正模式
/*****************************************************************************/
/*****************************************************************************/
#define STEPNUM_FAULT					-1//故障
#define STEPNUM_INIT					0//初始化
#define STEPNUM_STANDBY					1//待机
#define STEPNUM_INTO_READY				2//进入准备
#define STEPNUM_READY					3//准备
#define STEPNUM_LASERON					4//激光开始

/*****************************************************************************/
void main(void){
	initDevice();
	sPlcInit();//初始化软逻辑
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
	ENABLE_INTERRUPT;
	while(1){
		sPlcProcessStart();
		if(LD(SPCOIL_START_UP)){//执行一次的代码
		}
		sPlcProcessEnd();
	}
}

