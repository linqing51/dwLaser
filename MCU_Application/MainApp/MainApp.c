#include "MainApp.h"
#include "vGus.h"
//#include "sPlcTest.h"
/*****************************************************************************/
////C8051F020 仿真计时器功能定义
////TIMER0 ->SPLC_FRAME
////TIMER1 ->
////TIMER2 ->UART0 Buadrate
//<<<<<<< HEAD
////TIMER3 ->Modbus RTU TIMER
//=======
////TIMER3 ->NO FUNCTION
//>>>>>>> MCFCL_25MP
////TIMER4 ->UART1 Buadrate
////C8051F580 计时器功能定义
////TIMER0 ->SPLC_FRAME
////TIMER1 ->UART1 Baud Rate Generator
////TIMER2 ->SPLC_LASER
////TIMER3 ->MODBUS RTU TIMER
////TIMER4 ->EXT TIMER OUT
////TIMER5 ->BEEM
///*****************************************************************************/
//#define DM_TOTAL_TIME_L					(DM_START + 0)
//#define DM_TOTAL_TIME_H					(DM_START + 1)
/*****************************************************************************/
//<<<<<<< HEAD
//#define ENUM_MODE_CW					0//连续模式
//#define ENUM_MODE_SP					1//单脉冲模式
//#define ENUM_MODE_MP					2//多脉冲模式
//#define ENUM_MODE_GP					3//群脉冲模式
//#define ENUM_MODE_CC					4//校正模式
///*****************************************************************************/
///*****************************************************************************/
//#define STEPNUM_FAULT					-1//故障
//#define STEPNUM_INIT					0//初始化
//#define STEPNUM_STANDBY					1//待机
//#define STEPNUM_INTO_READY				2//进入准备
//#define STEPNUM_READY					3//准备
//#define STEPNUM_LASERON					4//激光开始


#define R_VGUS_READY
#define R_VGUS_SAVE
#define R_VGUS_DISP_RESET
bit debugLed0, debugLed1, debugLed2, debugLed3;
void main(void){
	initDevice();
	sPlcInit();//初始化软逻辑
//	URECV(UART1, (6 + 1));
	//vGusRegRead(1, 2);
	//vGusUpload();
	while(1){
		//RES(R_VGUS_LOOP_DONE);
		vGusUpload();
		debugLed0 = ~debugLed0;
		sPlcProcessStart();
		//debugLed0 = false;
	
		//debugLed1 = true;
		if(LD(SPCOIL_START_UP)){//执行一次的代码
		
		}
		//debugLed1 = false;

#if CONFIG_SPLC_FUNTEST == 1
		//sPlcTest();
#endif
		
		//debugLed2 = true;
		sPlcProcessEnd();
		//debugLed2 = false;
	}
}


