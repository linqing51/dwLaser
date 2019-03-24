#include "MainApp.h"
#include "vGus.h"
//#include "sPlcTest.h"
/*****************************************************************************/
//T0->PCA
//T1->UART0/UART1
//T2->MODBUS
//T3->SPLC
//T4->LASER
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



bit debugLed0, debugLed1, debugLed2, debugLed3;

void main(void){ 
	initDevice();
	sPlcInit();//初始化软逻辑
	while(1){
		debugLed0 = ~debugLed0;
		sPlcProcessStart();
		if(LD(SPCOIL_START_UP)){//执行一次的代码
			RES(R_VGUS_UPLOAD_DONE);
			RES(R_VGUS_UPLOAD_DOING);
			RES(R_VGUS_POWERON_DONE);
			RES(R_VGUS_POWERON_DOING);
		}
		vGusWaitPowerOn();//等待vGus上电
		
//		if(LD(R_VGUS_POWERON_DONE)){//vGus就绪
//			vGusInit();
//		}
//		if(LD(R_VGUS_INIT_DONE)){
//			vGusUpload();//vGus数据上传
//		}
#if CONFIG_SPLC_FUNTEST == 1
#endif
		sPlcProcessEnd();
	}
}


