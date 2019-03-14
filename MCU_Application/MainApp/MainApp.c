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

#define DM_VGUS_PINCODE						0//密码值
#define DM_VGUS_NEWPINCODE					1//新密码值
#define DM_VGUS_BRIGHTNESS					2//屏幕亮度值
#define DM_VGUS_VOLUME						3//蜂鸣器音量
#define DM_VGUS_TONE						4//蜂鸣器声音模式


#define EM_VGUS_WAVE_SEL					0//波长选择->100
#define EM_VGUS_MODE_SEL					1//模式选择->101
#define EM_VGUS_POWER_980					2//功率->102
#define EM_VGUS_POWER_1470					3//功率->103
#define EM_VGUS_PP_POS						4//正脉宽->104
#define EM_VGUS_PP_NEG						5//负脉宽->105
#define EM_VGUS_PP_SPACE					6//群脉冲间隔->106
#define EM_VGUS_PP_GROUP					7//群脉冲个数->107
#define EM_VGUS_DISP_NAME					10//9+32//方案名称->110-159

#define EM_VGUS_DISP_ENERGY					40//32bit ->110
#define EM_VGUS_DISP_TIME					42//32bit ->112
#define EM_VGUS_DISP_WARNING				50//32Byte ->300

#define DM_SCHEME_0							0
#define DM_SCHEME_1							40
#define DM_SCHEME_2							80
#define DM_SCHEME_3							120
#define DM_SCHEME_4							160
#define DM_SCHEME_5							200
#define DM_SCHEME_6							240
#define DM_SCHEME_7							280
#define DM_SCHEME_8							320
#define DM_SCHEME_9							360//40
#define DM_SCHEME_10						360//40
#define DM_SCHEME_11						360//40
#define DM_SCHEME_12						360//40
#define DM_SCHEME_13						360//40
#define DM_SCHEME_14						360//40
#define DM_SCHEME_15						360//40

#define R_VGUS_READY
#define R_VGUS_SAVE
#define R_VGUS_DISP_RESET
bit debugLed0, debugLed1, debugLed2, debugLed3;
void main(void){
	initDevice();
	sPlcInit();//初始化软逻辑
	URECV(UART1, (6 + 1));
	vGusRegRead(0, 1);
	
	while(1){
		
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


