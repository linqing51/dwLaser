#include "hmi.h"
/*****************************************************************************/
#define CONFIG_HMI_DEFAULT_PASSSWORD0	0x32//默认密码
#define CONFIG_HMI_DEFAULT_PASSSWORD1	0x35//默认密码
#define CONFIG_HMI_DEFAULT_PASSSWORD2	0x38//默认密码
#define CONFIG_HMI_DEFAULT_PASSSWORD3	0x30//默认密码
#define STATUS_LASER_READY				0x5A
#define STATUS_LASER_STANDBY			0xA5

#define EM_HMI_START_PROGRESS_BAR		(EM_START + 0)
#define EM_HMI_HMI_PAGE					(EM_START + 0)
#define EM_HMI_NEW_PASSWORD0			(EM_START + 0)
#define EM_HMI_NEW_PASSWORD1			(EM_START + 1)
#define EM_HMI_NEW_PASSWORD2			(EM_START + 0)
#define EM_HMI_NEW_PASSWORD3			(EM_START + 1)
#define EM_HMI_DEFAULT_PASSWORD0		(EM_START + 1)
#define EM_HMI_DEFAULT_PASSWORD1		(EM_START + 1)
#define EM_HMI_DEFAULT_PASSWORD2		(EM_START + 1)
#define EM_HMI_DEFAULT_PASSWORD3		(EM_START + 1)

#define EM_HMI_LASER_SCHEME_NAME		(EM_START)//方案名称
#define EM_HMI_LASER_POWER_980			(EM_START + 0)//980功率
#define EM_HMI_LASER_POWER_1470			(EM_START + 0)//1470功率
#define EM_HMI_LASER_PULSE_MODE			(EM_START + 0)//脉冲模式
#define EM_HMI_LASER_POSWIDTH			(EM_START + 0)//正脉宽
#define EM_HMI_LASER_NEGWIDTH			(EM_START + 0)//负脉宽
#define EM_HMI_LASER_GROUP				(EM_START + 0)//脉冲数
#define EM_HMI_LASER_SPACE				(EM_START + 0)//脉冲间隔

#define EM_HMI_READY_STATUS				(EM_START + 0)
#define EM_DIODE_TEMP0					(EM_START + 0)//二极管温度0
#define EM_DIODE_TEMP1					(EM_START + 0)//二极管温度1
#define EM_DRIVE_TEMP					(EM_START + 0)//驱动器温度
#define EM_ENVI_TEMP					(EM_START + 0)//环境温度
/*****************************************************************************/
#define DM_SCHEME_NAME					(DM_START +   0)//25 
#define DM_SCHEME_LASER_POWER_980		(DM_START +  18)
#define DM_SCHEME_LASER_POWER_1470		(DM_START +  19)
#define DM_SCHEME_LASER_PULSE_MODE		(DM_START +  20)
#define DM_SCHEME_LASER_POSWIDTH		(DM_START +  21)
#define DM_SCHEME_LASER_NEGWIDTH		(DM_START +  22)
#define DM_SCHEME_LASER_GROUP			(DM_START +  23)
#define DM_SCHEME_LASER_LASER_SPACE		(DM_START +  24)

#define DM_SCHEME_START_0				(DM_START +   0)
#define DM_SCHEME_END_0					(DM_START +  24)

#define DM_SCHEME_START_1				(DM_START +  25)
#define DM_SCHEME_END_1					(DM_START +  49)

#define DM_SCHEME_START_2				(DM_START +  50)
#define DM_SCHEME_END_2					(DM_START +  74)

#define DM_SCHEME_START_3				(DM_START +  75)
#define DM_SCHEME_END_3					(DM_START +  99)

#define DM_SCHEME_START_4				(DM_START + 100)
#define DM_SCHEME_END_4					(DM_START + 124)

#define DM_SCHEME_START_5				(DM_START + 125)
#define DM_SCHEME_END_5					(DM_START + 149)

#define DM_SCHEME_START_6				(DM_START + 150)
#define DM_SCHEME_END_6					(DM_START + 174)

#define DM_SCHEME_START_7				(DM_START + 175)
#define DM_SCHEME_END_7					(DM_START + 199)

#define DM_SCHEME_START_8				(DM_START + 200)
#define DM_SCHEME_END_8					(DM_START + 224)

#define DM_SCHEME_START_9				(DM_START + 225)
#define DM_SCHEME_END_9					(DM_START + 249)

#define DM_SCHEME_START_10				(DM_START + 250)
#define DM_SCHEME_END_10				(DM_START + 274)

#define DM_SCHEME_START_11				(DM_START + 275)
#define DM_SCHEME_END_11				(DM_START + 299)

#define DM_SCHEME_START_12				(DM_START + 300)
#define DM_SCHEME_END_12				(DM_START + 324)

#define DM_SCHEME_START_13				(DM_START + 325)
#define DM_SCHEME_END_13				(DM_START + 349)

#define DM_SCHEME_START_14				(DM_START + 350)
#define DM_SCHEME_END_14				(DM_START + 374)

#define DM_SCHEME_START_15				(DM_START + 375)
#define DM_SCHEME_END_15				(DM_START + 399)

#define DM_SCHEME_NUM					(DM_START + 400)

#define DM_DIODE_HIGH_TEMP				(DM_START + 420)
#define DM_DRIVE_HIGH_TEMP				(DM_START + 420)
#define DM_ENVI_HIGH_TEMP				(DM_START + 420)
#define DM_HMI_OLD_PASSWORD0			(DM_START + 0)
#define DM_HMI_OLD_PASSWORD1			(DM_START + 1)
#define DM_HMI_OLD_PASSWORD2			(DM_START + 0)
#define DM_HMI_OLD_PASSWORD3			(DM_START + 1)

/*****************************************************************************/
#define X_FOOTSWITCH					(X_START * 16 + 0)//XIN0
#define X_INTERLOCK						(X_START * 16 + 1)//XIN1
/*****************************************************************************/
#define Y_LED_POWERON					(Y_START * 16 + 0)//YOUT0
#define Y_LED_EMIT						(Y_START * 16 + 1)//YOUT1
#define Y_LED_ALARM						(Y_START * 16 + 2)//YOUT2
/*****************************************************************************/
#define R_FIBER_DETECT_0				(R_START * 16 + 0)//光纤探测
#define R_FIBER_DETECT_1				(R_START * 16 + 0)
#define R_FIBER_MANUFACT_0				(R_START * 16 + 0)
#define R_FIBER_MANUFACT_1				(R_START * 16 + 0)
#define R_DIODE_TEMP_HIGH_0				(R_START * 16 + 0)
#define R_DIODE_TEMP_HIGH_1				(R_START * 16 + 0)
#define R_DRIVE_FAULT_0					(R_START * 16 + 0)
#define R_DRIVE_FAULT_1					(R_START * 16 + 0)
#define R_DRIVE_TEMP_HIGH				(R_START * 16 + 0)
#define R_ENVI_TEMP_HIGH				(R_START * 16 + 0)


#define R_SAFE_READY					(R_START * 16 + 0)//安全就绪
#define R_SCHEME_LOAD_REQ				(R_START * 16 + 0)//方案载入请求
#define R_SHCEME_SAVE_REQ				(R_START * 16 + 0)//方案储存请求
/*****************************************************************************/
static void loadScheme(void){//DM->EM
	idata uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > 16)
		NVRAM0[DM_SCHEME_NUM] = 16;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	psrc = (uint8_t*)&NVRAM0[(DM_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 25)];
	pdist = (uint8_t*)&NVRAM0[EM_HMI_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, 50);
}
static void saveScheme(void){//EM->DM
	idata uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > 16)
		NVRAM0[DM_SCHEME_NUM] = 16;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	pdist = (uint8_t*)&NVRAM0[(DM_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 25)];
	psrc = (uint8_t*)&NVRAM0[EM_HMI_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, 50);
}

static void processTemperature(void){//温度处理过程
	int16_t volt, res;
	volt = (int16_t)((int32_t)(NVRAM0[SPREG_ADC_2]) * CONFIG_SPLC_ADC_INTERNAL_VREF / 4096.L);
	res = (uint16_t)(CONFIG_SPLC_NTC_RS * (CONFIG_SPLC_NTC_VREF - volt) / volt);
		
}
void hmiLoop(void){//HMI轮训程序
	if(LD(SPCOIL_START_UP)){//执行一次的代码
		NVRAM0[EM_HMI_HMI_PAGE] = 0x0;//HMI页面
		NVRAM0[EM_HMI_START_PROGRESS_BAR] = 0x0;//开机进度条
		//设置默认密码
		NVRAM0[EM_HMI_DEFAULT_PASSWORD0] = (CONFIG_HMI_DEFAULT_PASSSWORD0 << 8) | CONFIG_HMI_DEFAULT_PASSSWORD1;
		NVRAM0[EM_HMI_DEFAULT_PASSWORD0] = (CONFIG_HMI_DEFAULT_PASSSWORD2 << 8) | CONFIG_HMI_DEFAULT_PASSSWORD3;
		NVRAM0[EM_HMI_DEFAULT_PASSWORD0] = 0x0; 
		NVRAM0[EM_HMI_DEFAULT_PASSWORD0] = 0x0; 
		loadScheme();
	}
	if(LDP(SPCOIL_PS100MS)){//每100mS更新一次温度
		processTemperature();
	}
	//判断二极管0是否过热
	if(NVRAM0[EM_DIODE_TEMP0] > NVRAM0[DM_DIODE_HIGH_TEMP]){
		SET(R_DIODE_TEMP_HIGH_0);
	}
	else{
		RES(R_DIODE_TEMP_HIGH_0);
	}
	//判断二极管1是否过热
	if(NVRAM0[EM_DIODE_TEMP1] > NVRAM0[DM_DIODE_HIGH_TEMP]){
		SET(R_DIODE_TEMP_HIGH_1);
	}
	else{
		RES(R_DIODE_TEMP_HIGH_1);
	}
	//判断驱动器是否过热
	if(NVRAM0[EM_DRIVE_TEMP] > NVRAM0[DM_DRIVE_HIGH_TEMP]){
		SET(R_DRIVE_TEMP_HIGH);
	}
	else{
		RES(R_DRIVE_TEMP_HIGH);
	}
	//判断环境是否过热
	if(NVRAM0[EM_ENVI_TEMP] > NVRAM0[DM_ENVI_HIGH_TEMP]){
		SET(R_ENVI_TEMP_HIGH);
	}
	else{
		RES(R_ENVI_TEMP_HIGH);
	}
	
	if(LD(R_FIBER_DETECT_0) ||
    LD(R_FIBER_DETECT_1) ||
	LD(R_FIBER_MANUFACT_0) ||
	LD(R_FIBER_MANUFACT_1) ||
	LD(R_DIODE_TEMP_HIGH_0) ||		
	LD(R_DIODE_TEMP_HIGH_1) ||
	LD(R_DRIVE_FAULT_0)	||
	LD(R_DRIVE_FAULT_1) ||
	LD(R_DRIVE_TEMP_HIGH) ||
	LD(R_ENVI_TEMP_HIGH)){
		SET(R_SAFE_READY);
	}
	
	
	if(NVRAM0[EM_HMI_READY_STATUS] == STATUS_LASER_READY){//READY状态
	}
	else if(NVRAM0[EM_HMI_READY_STATUS] == STATUS_LASER_STANDBY){//STAND状态
		if(LD(X_FOOTSWITCH) && LD(R_SAFE_READY)){//发射激光
			
		}
		else{//停止激光
			
		}
	}
}

