#include "backApp.h"
/*****************************************************************************/
void loadScheme(void){//DM->EM
	xdata uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > CONFIG_HMI_SCHEME_NUM)
		NVRAM0[DM_SCHEME_NUM] = CONFIG_HMI_SCHEME_NUM;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	psrc = (uint8_t*)&NVRAM0[(DM_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 25)];
	pdist = (uint8_t*)&NVRAM0[EM_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, ((DM_SCHEME_END_0 - DM_SCHEME_START_0 +1 ) * 2));
}
void saveScheme(void){//EM->DM
	xdata uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > CONFIG_HMI_SCHEME_NUM)
		NVRAM0[DM_SCHEME_NUM] = CONFIG_HMI_SCHEME_NUM;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	pdist = (uint8_t*)&NVRAM0[(DM_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 25)];
	psrc = (uint8_t*)&NVRAM0[EM_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, ((DM_SCHEME_END_0 - DM_SCHEME_START_0 +1 ) * 2));
}

void bcakAppInit(void){
	SET(R_FIBER_MANUFACT_0);
	SET(R_FIBER_MANUFACT_1);
	SET(X_FBD1);
	//初始化EPID参数
	NVRAM0[EM_EPID0_TAB_REF] = 250;
	NVRAM0[EM_EPID0_TAB_KP] = 1000;//比例常数 XX.XXX 0-65.535
	NVRAM0[EM_EPID0_TAB_KI] = 1000;//积分常数 XX.XXX 0-65.535		
	NVRAM0[EM_EPID0_TAB_TD] = 10;//微分时间常数 XX.XXX 0-65.535
	NVRAM0[EM_EPID0_TAB_TS]	= 100;//PID运算时间间隔 1-3000 单位0.01S
	NVRAM0[EM_EPID0_TAB_MAX] = 1000;//输出最大限制		
	NVRAM0[EM_EPID0_TAB_MIN] = 0;//输出最小限制
	NVRAM0[EM_EPID0_TAB_BIAS] = 0;//输出偏置
	NVRAM0[EM_EPID0_TAB_TSC] = 0;//间隔计时器
}
void backApp(void){//背景应用
	if(LDP(SPCOIL_PS10MS)){//每100mS更新一次温度
		TNTC(&NVRAM0[EM_DIODE_TEMP0], &NVRAM0[SPREG_ADC_2]);//CODE转换为NTC测量温度温度
		TNTC(&NVRAM0[EM_DIODE_TEMP1], &NVRAM0[SPREG_ADC_3]);//CODE转换为NTC测量温度温度
		TENV(&NVRAM0[EM_ENVI_TEMP], &NVRAM0[SPREG_ADC_8]);//CODE转换为环境温度	
	}
	//执行温控PID
	NVRAM0[EM_EPID0_TAB_VFB] = NVRAM0[EM_DIODE_TEMP0];//采集温度传入EPID参数表
	EPID(&NVRAM0[EM_EPID0_TAB_OUT]);//执行温控PID
	//PID输出传入SPWM0
	NVRAM0[SPREG_SPWM_CYCLE_0] = NVRAM0[EM_EPID0_TAB_MAX];
	NVRAM0[SPREG_SPWM_POS_0] = NVRAM0[EM_EPID0_TAB_OUT]; 
	//SPWM0绑定IO
	if(LD(SPCOIL_SPWM_OUT_0)){
		SET(Y_TEC0);SET(Y_TEC1);
	}
	else{
		RES(Y_TEC0);RES(Y_TEC1);
	}
	
	//判断二极管0是否过热
	if(NVRAM0[EM_DIODE_TEMP0] > CONFIG_APP_DIODE_HIGH_TEMP){
		SET(R_DIODE_TEMP_HIGH_0);
	}
	else{
		RES(R_DIODE_TEMP_HIGH_0);
	}
	//判断二极管1是否过热
	if(NVRAM0[EM_DIODE_TEMP1] > CONFIG_APP_DIODE_HIGH_TEMP){
		SET(R_DIODE_TEMP_HIGH_1);
	}
	else{
		RES(R_DIODE_TEMP_HIGH_1);
	}
	//判断驱动器是否过热
	if(NVRAM0[EM_DRIVE_TEMP] > CONFIG_APP_DRIVE_HIGH_TEMP){
		SET(R_DRIVE_TEMP_HIGH);
	}
	else{
		RES(R_DRIVE_TEMP_HIGH);
	}
	//判断环境是否过热
	if(NVRAM0[EM_ENVI_TEMP] > CONFIG_APP_ENVI_HIGH_TEMP){
		SET(R_ENVI_TEMP_HIGH);
	}
	else{
		RES(R_ENVI_TEMP_HIGH);
	}
	//************************************************************************/
	if(LD(X_FBD0) || LD(X_FBD1) || LD(R_FIBER_MANUFACT_0) || LD(R_FIBER_MANUFACT_1) ||
	LD(R_DIODE_TEMP_HIGH_0) || LD(R_DIODE_TEMP_HIGH_1) || LD(R_DRIVE_TEMP_HIGH) || LD(R_ENVI_TEMP_HIGH) ||
	LD(R_DRIVE_FAULT_0)	|| LD(R_DRIVE_FAULT_1)){
		SET(R_SAFE_READY);
	}
	else{
		RES(R_SAFE_READY);
	}
	/************************************************************************/
	if(LDP(R_SCHEME_LOAD_REQ)){//载入请求
		loadScheme();
		RES(R_SCHEME_LOAD_REQ);
	}
	if(LDP(R_SHCEME_SAVE_REQ)){//存储请求
		saveScheme();
		RES(R_SHCEME_SAVE_REQ);
	}
	//
	if(LD(X_FBD0) || LD(X_FBD1) || LD(R_FIBER_MANUFACT_0) || LD(R_FIBER_MANUFACT_1) ||
	   LD(R_DIODE_TEMP_HIGH_0) || LD(R_DIODE_TEMP_HIGH_1) || LD(R_DRIVE_FAULT_0) || LD(R_DRIVE_FAULT_1) ||
	   LD(R_DRIVE_TEMP_HIGH) || LD(R_ENVI_TEMP_HIGH)){
		SET(R_SAFE_READY);
	}
	else{
		RES(R_SAFE_READY);
	}
	//************************************************************************/

}