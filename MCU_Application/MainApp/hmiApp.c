#include "hmiApp.h"
/*****************************************************************************/
#define WORKSTEP_IDLE								0//初始状态
#define WORKSTEP_STANDBY							1//等待状态	
#define WORKSTEP_READY_LOAD_PARA					2//载入参数
#define WORKSTEP_READY_LOAD_DONE					3//载入参数完毕
#define WORKSTEP_LASER_TRIGGER						4//激光触发
#define WORKSTEP_LASER_EMITING						5//激光发射中
#define WORKSTEP_LASER_STOP							6//激光发射结束
#define WORKSTEP_FAULT								255//故障状态

/*****************************************************************************/
void hmiLoopInit(void){//初始化模块
	NVRAM0[EM_HMI_OPERA_STEP] = 0;
	NVRAM0[EM_HMI_PAGE] = 0x0;//HMI页面
	NVRAM0[EM_START_PROGRESS_BAR] = 0x0;//开机进度条
	//设置默认密码
	NVRAM0[EM_DEFAULT_PASSWORD0] = (CONFIG_DEFAULT_PASSSWORD0 << 8) | CONFIG_DEFAULT_PASSSWORD1;
	NVRAM0[EM_DEFAULT_PASSWORD1] = (CONFIG_DEFAULT_PASSSWORD2 << 8) | CONFIG_DEFAULT_PASSSWORD3;
	NVRAM0[EM_DEFAULT_PASSWORD2] = 0x0; 
	NVRAM0[EM_DEFAULT_PASSWORD3] = 0x0; 
	loadScheme();//从掉电存储寄存器中恢复方案参数
}
void hmiLoop(void){//HMI轮训程序
	if(NVRAM0[EM_HMI_OPERA_STEP] == WORKSTEP_FAULT){//故障步骤
		if(LD(R_SAFE_FAULT)){
			NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_FAULT;
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_STANDBY;
		}
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == WORKSTEP_IDLE){//IDLE
		NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_STANDBY;
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == WORKSTEP_STANDBY){//STANDBY
		if(LD(R_SAFE_FAULT)){//
			NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_FAULT;
		}
		else{
			if(LD(R_KEY_READY)){
				NVRAM0[SPREG_BEEM_MODE] = BEEM_MODE_0;
				NVRAM0[SPREG_BEEM_VOLUME] = NVRAM0[DM_BEEM_VOLUME];
				SET(SPCOIL_BEEM_ENABLE);//打开蜂鸣器			
				NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_READY_LOAD_PARA;
			}
			else{
				NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_STANDBY;
			}
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == WORKSTEP_READY_LOAD_PARA){//READY
		NVRAM0[SPREG_LASER_MODE] = NVRAM0[EM_LASER_PULSE_MODE];
		NVRAM0[SPREG_LASER_SELECT] = NVRAM0[EM_LASER_SELECT];
		NVRAM0[SPREG_LASER_TMATE] = NVRAM0[EM_LASER_POSWIDTH];//激光脉冲正脉宽 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = NVRAM0[EM_LASER_POSWIDTH] + NVRAM0[EM_LASER_NEGWIDTH];//激光脉冲周期 25mS
		NVRAM0[SPREG_LASER_PMATE] = NVRAM0[EM_LASER_GROUP];//10个脉冲
		NVRAM0[SPREG_LASER_POVERTIME] = NVRAM0[EM_LASER_SPACE];//间隔33mS
		PCLAR0(EM_LASER_POWER_CH0, SPREG_DAC_0);//功率->DAC CODE//功率->DAC电压
		PCLAR1(EM_LASER_POWER_CH1, SPREG_DAC_1);//功率->DAC CODE
		T100MS(T100MS_READY_BEEM_DELAY, true, 3);//启动计时器延时500mS//打开计时器
		//清空计时器
		if(LD(T_100MS_START * 16 + T100MS_READY_BEEM_DELAY)){
			T100MS(T100MS_READY_BEEM_DELAY, false, 3);
			NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_READY_LOAD_DONE;
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_READY_LOAD_PARA;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == WORKSTEP_READY_LOAD_DONE){//READY状态
		RES(SPCOIL_BEEM_ENABLE);//关闭蜂鸣器
		NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_LASER_TRIGGER;
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == WORKSTEP_LASER_TRIGGER){//等待触发激光
		if(LD(R_SAFE_FAULT)){
			NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_FAULT;	
		}
		else{
			if(LD(R_KEY_READY)){
				if(LD(X_FOOTSWITCH_OC) && LDB(X_FOOTSWITCH_ON)){//发射激光	
					NVRAM0[SPREG_BEEM_MODE] = BEEM_MODE_1;
					NVRAM0[SPREG_BEEM_VOLUME] = NVRAM0[DM_BEEM_VOLUME];
					SET(SPCOIL_BEEM_ENABLE);//打开蜂鸣器		
					STLAR();
					NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_LASER_EMITING;	
				}
					
			}
			else{
				NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_STANDBY;	
			}
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == WORKSTEP_LASER_EMITING){//等待触发激光
		if(LD(R_SAFE_FAULT)){//发现故障
			EDLAR();
			RES(SPCOIL_BEEM_ENABLE);//打开蜂鸣器	
			RES(R_KEY_READY);//取消准备状态
			NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_FAULT;
		}
		else{
			if(LD(X_FOOTSWITCH_OC) && LDB(X_FOOTSWITCH_ON)){//发射激光
				NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_LASER_EMITING;		
			}
			else{
				EDLAR();
				RES(SPCOIL_BEEM_ENABLE);//关闭蜂鸣器	
				NVRAM0[EM_HMI_OPERA_STEP] = WORKSTEP_LASER_TRIGGER;
			}
		}
	}
	return;
}

