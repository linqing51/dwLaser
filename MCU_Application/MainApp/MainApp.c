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
	uint8_t tmp;
#ifdef C8051F020
	initDeviceF020();
#endif
#ifdef C8051F580
	initDeviceF580();
	inPca9554Init();
	epromTest();
	tmp = inPca9554Read();
	tmp &= 0x0;
	tmp = inPca9554Read();
	tmp &= 0x0;
	tmp = inPca9554Read();
	tmp &= 0x0;
	tmp = inPca9554Read();
	tmp &= 0x0;
	tmp = inPca9554Read();
	tmp &= 0x0;
	tmp = inPca9554Read();
	tmp &= 0x0;
	tmp = inPca9554Read();
	tmp &= 0x0;
	//while(1);
#endif
#if CONFIG_USING_WDT == 1
	if ((RSTSRC & 0x02) == 0x00)
	{
		if (RSTSRC == 0x08)
		{//检测WDT看门狗 看门狗复位后锁定
			while(1);
		}
	}
#endif
	sPlcInit();//初始化软逻辑
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
	NVRAM0[SPREG_CHECKCODE] = CONFIG_CHECK_CODE;
	ENABLE_INTERRUPT;
	while(1){
		sPlcProcessStart();
		NVRAM0[EM_MCU_CHECKCODE] = CONFIG_CHECK_CODE;//写入板卡校验码
		if(LD(R_MCU_RESET)){
			REBOOT();
		}
		sPlcLaser();
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

