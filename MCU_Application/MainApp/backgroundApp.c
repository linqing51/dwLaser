#include "backgroundApp.h"
/*****************************************************************************/
#if CONFIG_USING_BACKGROUND_APP == 1
void defaultScheme(void){//当前选择方案恢复默认值
	sprintf((char*)(&NVRAM0[EM_LASER_SCHEME_NAME]),"Hello dwLaser S%d",NVRAM0[DM_SCHEME_NUM]);		
	NVRAM0[DM_BEEM_VOLUME] = 9;
	NVRAM0[EM_LASER_SELECT]	= LASER_SELECT_BOTH;//通道选择
	NVRAM0[EM_LASER_PULSE_MODE]	= LASER_MODE_CW;//脉冲模式
	NVRAM0[EM_LASER_POWER_CH0] = 199;//通道0功率
	NVRAM0[EM_LASER_POWER_CH1] = 59;//通道1功率
	NVRAM0[EM_LASER_SP_POSWIDTH]= 500;//单脉冲正脉宽
	NVRAM0[EM_LASER_MP_POSWIDTH]= 400;//多脉冲正脉宽
	NVRAM0[EM_LASER_MP_NEGWIDTH]= 20;//多脉冲负脉宽
	NVRAM0[EM_LASER_GP_POSWIDTH]= 300;//Group脉冲正脉宽
	NVRAM0[EM_LASER_GP_NEGWIDTH]= 600;//Group脉冲负脉宽
	NVRAM0[EM_LASER_GP_TIMES] =	10;//Group脉冲数
	NVRAM0[EM_LASER_GP_GROUP_OFF] = 700;//Group脉冲间隔
	NVRAM0[EM_LASER_SIGNAL_ENERGY_INTERVAL] = CONFIG_MIN_LASER_ENERGY_INTERVAL;//EVLA_SIGNAL能量间隔
	NVRAM0[EM_LASER_DERMA_POSWIDTH]	= 250;//DERMA正脉宽
	NVRAM0[EM_LASER_DERMA_NEGWIDTH]	= 550;//DERMA负脉宽
	NVRAM0[EM_LASER_DERMA_SPOT_SIZE] = DERMA_SPOT_SIZE_0MM5;//DERMA光斑直径
}
void reloadCorrTab(void){//恢复功率校正参数
	NVRAM0[DM_CORR_TAB0_POWER0] = POWER_REAL_CH0_0P;
	NVRAM0[DM_CORR_TAB0_POWER1] = POWER_REAL_CH0_5P;
	NVRAM0[DM_CORR_TAB0_POWER2] = POWER_REAL_CH0_10P;
	NVRAM0[DM_CORR_TAB0_POWER3] = POWER_REAL_CH0_15P;
	NVRAM0[DM_CORR_TAB0_POWER4] = POWER_REAL_CH0_20P;
	NVRAM0[DM_CORR_TAB0_POWER5] = POWER_REAL_CH0_25P;
	NVRAM0[DM_CORR_TAB0_POWER6] = POWER_REAL_CH0_30P;
	NVRAM0[DM_CORR_TAB0_POWER7] = POWER_REAL_CH0_35P;
	NVRAM0[DM_CORR_TAB0_POWER8] = POWER_REAL_CH0_40P;
	NVRAM0[DM_CORR_TAB0_POWER9] = POWER_REAL_CH0_45P;
	NVRAM0[DM_CORR_TAB0_POWER10] = POWER_REAL_CH0_50P;
	NVRAM0[DM_CORR_TAB0_POWER11] = POWER_REAL_CH0_55P;
	NVRAM0[DM_CORR_TAB0_POWER12] = POWER_REAL_CH0_60P;
	NVRAM0[DM_CORR_TAB0_POWER13] = POWER_REAL_CH0_65P;
	NVRAM0[DM_CORR_TAB0_POWER14] = POWER_REAL_CH0_70P;
	NVRAM0[DM_CORR_TAB0_POWER15] = POWER_REAL_CH0_75P;
	NVRAM0[DM_CORR_TAB0_POWER16] = POWER_REAL_CH0_80P;
	NVRAM0[DM_CORR_TAB0_POWER17] = POWER_REAL_CH0_85P;
	NVRAM0[DM_CORR_TAB0_POWER18] = POWER_REAL_CH0_90P;
	NVRAM0[DM_CORR_TAB0_POWER19] = POWER_REAL_CH0_95P;
	NVRAM0[DM_CORR_TAB0_POWER20] = POWER_REAL_CH0_100P;
	NVRAM0[DM_CORR_TAB1_POWER0] = POWER_REAL_CH1_0P;
	NVRAM0[DM_CORR_TAB1_POWER1] = POWER_REAL_CH1_5P;
	NVRAM0[DM_CORR_TAB1_POWER2] = POWER_REAL_CH1_10P;
	NVRAM0[DM_CORR_TAB1_POWER3] = POWER_REAL_CH1_15P;
	NVRAM0[DM_CORR_TAB1_POWER4] = POWER_REAL_CH1_20P;
	NVRAM0[DM_CORR_TAB1_POWER5] = POWER_REAL_CH1_25P;
	NVRAM0[DM_CORR_TAB1_POWER6] = POWER_REAL_CH1_30P;
	NVRAM0[DM_CORR_TAB1_POWER7] = POWER_REAL_CH1_35P;
	NVRAM0[DM_CORR_TAB1_POWER8] = POWER_REAL_CH1_40P;
	NVRAM0[DM_CORR_TAB1_POWER9] = POWER_REAL_CH1_45P;
	NVRAM0[DM_CORR_TAB1_POWER10] = POWER_REAL_CH1_50P;
	NVRAM0[DM_CORR_TAB1_POWER11] = POWER_REAL_CH1_55P;
	NVRAM0[DM_CORR_TAB1_POWER12] = POWER_REAL_CH1_60P;
	NVRAM0[DM_CORR_TAB1_POWER13] = POWER_REAL_CH1_65P;
	NVRAM0[DM_CORR_TAB1_POWER14] = POWER_REAL_CH1_70P;
	NVRAM0[DM_CORR_TAB1_POWER15] = POWER_REAL_CH1_75P;
	NVRAM0[DM_CORR_TAB1_POWER16] = POWER_REAL_CH1_80P;
	NVRAM0[DM_CORR_TAB1_POWER17] = POWER_REAL_CH1_85P;
	NVRAM0[DM_CORR_TAB1_POWER18] = POWER_REAL_CH1_90P;
	NVRAM0[DM_CORR_TAB1_POWER19] = POWER_REAL_CH1_95P;
	NVRAM0[DM_CORR_TAB0_POWER20] = POWER_REAL_CH1_100P;
	FSAV();//立即存储
}
void loadScheme(void){//DM->EM
	uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > CONFIG_HMI_SCHEME_NUM)
		NVRAM0[DM_SCHEME_NUM] = CONFIG_HMI_SCHEME_NUM;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	psrc = (uint8_t*)&NVRAM0[(DM_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 30)];
	pdist = (uint8_t*)&NVRAM0[EM_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, ((DM_SCHEME_END_0 - DM_SCHEME_START_0 + 1) * 2));
	switch(NVRAM0[EM_LASER_PULSE_MODE]){
		case LASER_MODE_CW:{
			break;
		}
		case LASER_MODE_SP:{
			break;
		}
		case LASER_MODE_MP:{
			break;
		}
		case LASER_MODE_GP:{
			break;
		}
		case LASER_MODE_SIGNAL:{
			break;
		}
		case LASER_MODE_DERMA:{
			break;
		}
		default:{
			defaultScheme();
			break;
		}
	}
}
void saveScheme(void){//EM->DM
	uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > CONFIG_HMI_SCHEME_NUM)
		NVRAM0[DM_SCHEME_NUM] = CONFIG_HMI_SCHEME_NUM;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	pdist = (uint8_t*)&NVRAM0[(DM_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 30)];
	psrc = (uint8_t*)&NVRAM0[EM_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, ((DM_SCHEME_END_0 - DM_SCHEME_START_0 + 1) * 2));
}
void backgroundAppInit(void){
	SET(R_FIBER_ID_PASS_0);
	SET(R_FIBER_ID_PASS_1);
	SET(X_FBD1);
	NVRAM0[EM_COOL_SET_TEMP] = CONFIG_COOL_SET_TEMP;
	NVRAM0[EM_COOL_DIFF_TEMP] = CONFIG_COOL_DIFF_TEMP;
	reloadCorrTab();
}
void backgroundApp(void){//背景应用
	int16_t temp;
	if(LDP(SPCOIL_PS100MS)){//每100mS更新一次温度
		temp = NVRAM0[SPREG_ADC_2];
		TNTC(EM_DIODE_TEMP0, SPREG_ADC_2);//CODE转换为NTC测量温度温度
		temp = NVRAM0[EM_DIODE_TEMP0];
		temp = NVRAM0[SPREG_ADC_3];
		TNTC(EM_DIODE_TEMP1, SPREG_ADC_3);//CODE转换为NTC测量温度温度
		temp = NVRAM0[EM_DIODE_TEMP1];
		temp = NVRAM0[SPREG_ADC_8];
		TENV(EM_ENVI_TEMP, SPREG_ADC_8);//CODE转换为环境温度
		temp = NVRAM0[EM_ENVI_TEMP];
		ADLS1(DM_SYS_RUNTIME_L);
		if(LD(SPCOIL_LASER_EMITING)){
			ADLS1(DM_LAR_RUNTIME_L);
		}
		if(NVRAM0[EM_DIODE_TEMP0] > (CONFIG_COOL_SET_TEMP + CONFIG_COOL_DIFF_TEMP)){
			SET(Y_TEC0);
			setLedVar(true);
		}
		if(NVRAM0[EM_DIODE_TEMP0] < (CONFIG_COOL_SET_TEMP + CONFIG_COOL_DIFF_TEMP)){
			RES(Y_TEC0);
			setLedVar(false);
		}
	}
	else{
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
	
	if(LDP(X_START + X_FBD0)){//上脉冲检测到光纤插入
		//DL25L_MIFARE_WRITE_BLOCK(4, uint8_t *pdat)//检测NFC ID是否合规
	}
	if(LDN(X_START + X_FBD0)){//下脉冲检测到光纤拔出
		//清除NFC ID
	}
	/************************************************************************/
//	if(LD(X_FBD0) || LD(R_FIBER_ID_PASS_0) || LD(R_DIODE_TEMP_HIGH_0) || LD(R_DRIVE_TEMP_HIGH) || LD(R_ENVI_TEMP_HIGH)){
//		SET(R_SAFE_FAULT);
//		 //RES(R_SAFE_FAULT);  
//	}
//	else{
//		RES(R_SAFE_FAULT);
//	}
	//************************************************************************/	
}
void PCLAR0(uint16_t POW, uint16_t CUR) reentrant{//功率->DAC CODE
	uint8_t index;
	fp32_t k, b, out;
	if(NVRAM0[POW] >= 400){
		index = 20;
	}else if(NVRAM0[POW] < 400 && NVRAM0[POW] >= 380){
		index = 19;
	}else if(NVRAM0[POW] < 380 && NVRAM0[POW] >= 360){
		index = 18;
	}else if(NVRAM0[POW] < 360 && NVRAM0[POW] >= 340){
		index = 17;
	}else if(NVRAM0[POW] < 340 && NVRAM0[POW] >= 320){
		index = 16;
	}else if(NVRAM0[POW] < 320 && NVRAM0[POW] >= 300){
		index = 15;
	}else if(NVRAM0[POW] < 300 && NVRAM0[POW] >= 280){
		index = 14;
	}else if(NVRAM0[POW] < 280 && NVRAM0[POW] >= 260){
		index = 13;
	}else if(NVRAM0[POW] < 260 && NVRAM0[POW] >= 240){
		index = 12;
	}else if(NVRAM0[POW] < 240 && NVRAM0[POW] >= 220){
		index = 11;
	}else if(NVRAM0[POW] < 220 && NVRAM0[POW] >= 200){
		index = 10;
	}else if(NVRAM0[POW] < 200 && NVRAM0[POW] >= 180){
		index = 9;
	}else if(NVRAM0[POW] < 180 && NVRAM0[POW] >= 160){
		index = 8;
	}else if(NVRAM0[POW] < 160 && NVRAM0[POW] >= 140){
		index = 7;
	}else if(NVRAM0[POW] < 140 && NVRAM0[POW] >= 120){
		index = 6;
	}else if(NVRAM0[POW] < 120 && NVRAM0[POW] >= 100){
		index = 5;
	}else if(NVRAM0[POW] < 100 && NVRAM0[POW] >=  80){
		index = 4;
	}else if(NVRAM0[POW] <  80 && NVRAM0[POW] >=  60){
		index = 3;
	}else if(NVRAM0[POW] <  60 && NVRAM0[POW] >=  40){
		index = 2;
	}else if(NVRAM0[POW] <  40 && NVRAM0[POW] >=  20){
		index = 1;
	}else if(NVRAM0[POW] <  20 && NVRAM0[POW] >=   0){
		index = 0;
	}
	if(index >= 20){
		NVRAM0[CUR] = NVRAM0[DM_CORR_TAB0_POWER20];
	}
	else{
		k = ((fp32_t)NVRAM0[(DM_CORR_TAB0_POWER0 + index + 1)] - (fp32_t)NVRAM0[DM_CORR_TAB0_POWER0 + index]) / 2;
		b = NVRAM0[DM_CORR_TAB0_POWER0 + index] - (k * index * 2);		
	}
	out = k * (fp32_t)NVRAM0[POW] - b;
	if(out > CONFIG_MAX_LASER_DAC_CH0){
		out = CONFIG_MAX_LASER_DAC_CH0;
	}
	NVRAM0[CUR] = (int16_t)out;
}
void PCLAR1(uint16_t POW, uint16_t CUR) reentrant{//功率->DAC CODE
	uint8_t index;
	fp32_t k, b, out;
	if(NVRAM0[POW] >= 400){
		index = 20;
	}else if(NVRAM0[POW] < 400 && NVRAM0[POW] >= 380){
		index = 19;
	}else if(NVRAM0[POW] < 380 && NVRAM0[POW] >= 360){
		index = 18;
	}else if(NVRAM0[POW] < 360 && NVRAM0[POW] >= 340){
		index = 17;
	}else if(NVRAM0[POW] < 340 && NVRAM0[POW] >= 320){
		index = 16;
	}else if(NVRAM0[POW] < 320 && NVRAM0[POW] >= 300){
		index = 15;
	}else if(NVRAM0[POW] < 300 && NVRAM0[POW] >= 280){
		index = 14;
	}else if(NVRAM0[POW] < 280 && NVRAM0[POW] >= 260){
		index = 13;
	}else if(NVRAM0[POW] < 260 && NVRAM0[POW] >= 240){
		index = 12;
	}else if(NVRAM0[POW] < 240 && NVRAM0[POW] >= 220){
		index = 11;
	}else if(NVRAM0[POW] < 220 && NVRAM0[POW] >= 200){
		index = 10;
	}else if(NVRAM0[POW] < 200 && NVRAM0[POW] >= 180){
		index = 9;
	}else if(NVRAM0[POW] < 180 && NVRAM0[POW] >= 160){
		index = 8;
	}else if(NVRAM0[POW] < 160 && NVRAM0[POW] >= 140){
		index = 7;
	}else if(NVRAM0[POW] < 140 && NVRAM0[POW] >= 120){
		index = 6;
	}else if(NVRAM0[POW] < 120 && NVRAM0[POW] >= 100){
		index = 5;
	}else if(NVRAM0[POW] < 100 && NVRAM0[POW] >=  80){
		index = 4;
	}else if(NVRAM0[POW] <  80 && NVRAM0[POW] >=  60){
		index = 3;
	}else if(NVRAM0[POW] <  60 && NVRAM0[POW] >=  40){
		index = 2;
	}else if(NVRAM0[POW] <  40 && NVRAM0[POW] >=  20){
		index = 1;
	}else if(NVRAM0[POW] <  20 && NVRAM0[POW] >=   0){
		index = 0;
	}
	if(index >= 20){
		NVRAM0[CUR] = NVRAM0[DM_CORR_TAB1_POWER20];
	}
	else{
		k = ((fp32_t)NVRAM0[(DM_CORR_TAB1_POWER0 + index + 1)] - (fp32_t)NVRAM0[DM_CORR_TAB1_POWER0 + index]) / 2;
		b = NVRAM0[DM_CORR_TAB1_POWER0 + index] - (k * index * 2);		
	}
	out = k * (fp32_t)NVRAM0[POW] - b;
	if(out > CONFIG_MAX_LASER_DAC_CH1){
		out = CONFIG_MAX_LASER_DAC_CH1;
	}
	NVRAM0[CUR] = (int16_t)out;
}
#endif