#include "MainApp.h"
#include "hmiLib.h"
//#include "sPlcTest.h"
/*****************************************************************************/
#define T10MS_HMI_UPDATA					0//HMI刷新定时器
#define R_HMI_UPDATA_REQ					(R_START * 16 + 0)//HMI立即刷新标志
#define EM_HMI_CMD_QUEUE					(EM_START + 0)//HMI指令队列数量
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
	//NVRAM0[EM_VGUS_WAVE_SEL] = 999;
	queue_reset();//清空指令接收缓冲区
	delayMs(100);//延时等待串口屏初始化完毕,必须等待
	while(1){
		debugLed0 = ~debugLed0;
		sPlcProcessStart();
		if(LD(SPCOIL_START_UP)){//等待vGus就绪
			//FlashRestoreControl(FLASH_DATA_VERSION, FLASH_DATA_ADDR);//尝试从FLASH中恢复设置
			RES(R_HMI_UPDATA_REQ);
			NVRAM0[EM_HMI_CMD_QUEUE] = 0;
		}
		NVRAM0[EM_HMI_CMD_QUEUE] = queue_find_cmd(hmiCmdBuffer, CMD_MAX_SIZE);//从缓冲区中获取一条指令         
		if(NVRAM0[EM_HMI_CMD_QUEUE] > 0){ //接收到指令 ，及判断是否为开机提示                                                                           
			ProcessMessage((PCTRL_MSG)hmiCmdBuffer, NVRAM0[EM_HMI_CMD_QUEUE]);//指令处理  
		}                                                                           
		T10MS(T10MS_HMI_UPDATA, true, 2);//HMI刷新周期
		if(LD(T_10MS_START * 16 + T10MS_HMI_UPDATA) || LD(R_HMI_UPDATA_REQ)){
			RES(R_HMI_UPDATA_REQ);
			T10MS(T10MS_HMI_UPDATA, false, 1);//停止计时器
			UpdateUI();	
		}
		
#if CONFIG_SPLC_FUNTEST == 1
#endif
		sPlcProcessEnd();
	}
}


