#include "backgroundApp.h"
/*****************************************************************************/
#if CONFIG_USING_BACKGROUND_APP == 1
typedef struct{
  float Kp;                       //比例系数Proportional
  float Ki;                       //积分系数Integral
  float Kd;                       //微分系数Derivative
  float Ek;                       //当前误差
  float Ek1;                      //前一次误差 e(k-1)
  float Ek2;                      //再前一次误差 e(k-2)
  float LocSum;                   //累计积分位置
}PID_LocTypeDef;  
/************************************************
函数名称 ： PID_Loc
功    能 ： PID位置(Location)计算
参    数 ： SetValue ------ 设置值(期望值)
			ActualValue --- 实际值(反馈值)
			PID ----------- PID数据结构
返 回 值 ： PIDLoc -------- PID位置
作    者 ： strongerHuang
*************************************************/
PID_LocTypeDef tPid;



float PID_Loc(float SetValue, float ActualValue, PID_LocTypeDef *PID){
	float PIDLoc;//位置 
	PID->Ek = SetValue - ActualValue;
	PID->LocSum += PID->Ek;//累计误差
	PIDLoc = PID->Kp * PID->Ek + (PID->Ki * PID->LocSum) + PID->Kd * (PID->Ek1 - PID->Ek);
	PID->Ek1 = PID->Ek;  
		return PIDLoc;
}

int16_t pulseWidthAdd(int16_t ps){//脉宽增加
	if(ps >= 1 && ps < 10){
		ps += 1;
	}
	else if(ps >= 10 && ps < 100){
		ps += 10;
	}
	else if(ps >= 100 && ps < 1000){
		ps += 50;
	}
	else if(ps >= 1000 && ps < 10000){
		ps += 1000;
	}
	return ps;
}
int16_t pulseWidthDec(int16_t ps){//脉宽减少
	if(ps > 1 && ps <= 10){
		ps -= 1;
	}
	else if(ps > 10 && ps <= 100){
		ps -= 10;
	}
	else if(ps > 100 && ps <= 1000){
		ps -= 50;
	}
	else if(ps > 1000 && ps <= 10000){
		ps -= 1000;
	}
	return ps;
}
void loadDefault(void){//恢复默认值
	uint8_t i;	
	RES(MR_FOOSWITCH_HAND_SWITCH);
	RES(MR_BEEM_TONE);			
	RES(R_DISABLE_RFID);
	RES(R_DISABLE_FIBER_PROBE);
	RES(R_DISABLE_FAN_SPEED);
	NVRAM0[DM_SCHEME_NUM] = 0;
	NVRAM0[DM_BEEM_VOLUME] = CONFIG_MAX_BEEM_VOLUME;
	NVRAM0[DM_AIM_BRG] = CONFIG_MAX_AIM_BRG;
	NVRAM0[DM_LCD_BRG] = CONFIG_MAX_LCD_BRG;
	reloadCorrTab();
	NVSAV();//强制储存NVRAM
	for(i=0;i<CONFIG_HMI_SCHEME_NUM;i++){
		NVRAM0[DM_SCHEME_NUM] = i;
		defaultScheme();
		saveScheme();
	}
	FDSAV();
}
uint8_t getLcdDuty(int16_t LcdBrg){//屏幕亮度值转换为占空比
	uint16_t temp;
	LcdBrg = 100 - LcdBrg; 
	if(LcdBrg <= 0)
		LcdBrg = 0;
	if(LcdBrg >= 80)
		LcdBrg = 80;
	temp = LcdBrg * 255;
	temp = temp / 100;
	return (uint8_t)(temp);
}
uint8_t getAimDuty(int16_t AimBrg){//指示光亮度值转换为占空比
	uint16_t temp;
	temp = AimBrg * 255;
	temp = temp / 100;
	return (uint8_t)(temp);
	
}
uint8_t getBeemDuty(int16_t volume){//获取蜂鸣器占空比设置
	//最大音量占空比0xB0
	//最小音量占空比0xF1
	uint8_t temp;
	if(volume > 100)
		volume = 100;
	temp = (0xFD - (74* volume / 100));
	return temp;
}
void defaultScheme(void){//当前选择方案恢复默认值
	sprintf((char*)(&NVRAM0[EM_LASER_SCHEME_NAME]),"Hello dwLaser S%d",NVRAM0[DM_SCHEME_NUM]);		
	NVRAM0[EM_LASER_SELECT]	= LASER_SELECT_ALL;//通道选择
	NVRAM0[EM_LASER_PULSE_MODE]	= LASER_MODE_CW;//脉冲模式
	NVRAM0[EM_LASER_POWER_CH0] = NVRAM0[DM_SCHEME_NUM] * 5 + 20;//通道0功率
	NVRAM0[EM_LASER_POWER_CH1] = NVRAM0[DM_SCHEME_NUM] * 2 + 10;//通道1功率
	NVRAM0[EM_LASER_SP_POSWIDTH]= 500;//单脉冲正脉宽
	NVRAM0[EM_LASER_MP_POSWIDTH]= 400;//多脉冲正脉宽
	NVRAM0[EM_LASER_MP_NEGWIDTH]= 300;//多脉冲负脉宽
	NVRAM0[EM_LASER_GP_POSWIDTH]= 600;//Group脉冲正脉宽
	NVRAM0[EM_LASER_GP_NEGWIDTH]= 700;//Group脉冲负脉宽
	NVRAM0[EM_LASER_GP_TIMES] =	20;//Group脉冲数
	NVRAM0[EM_LASER_GP_GROUP_OFF] = 500;//Group脉冲间隔
	NVRAM0[EM_LASER_SIGNAL_ENERGY_INTERVAL] = CONFIG_MIN_LASER_ENERGY_INTERVAL;//EVLA_SIGNAL能量间隔
	NVRAM0[EM_LASER_DERMA_POSWIDTH]	= 550;//DERMA正脉宽
	NVRAM0[EM_LASER_DERMA_NEGWIDTH]	= 650;//DERMA负脉宽
	NVRAM0[EM_LASER_DERMA_SPOT_SIZE] = DERMA_SPOT_SIZE_0MM5;//DERMA光斑直径
}
void reloadCorrTab(void){//恢复功率校正参数
	NVRAM0[DM_CORR_TAB0_POWER0] = POWER_REAL_CH0_5P;
	NVRAM0[DM_CORR_TAB0_POWER1] = POWER_REAL_CH0_10P;
	NVRAM0[DM_CORR_TAB0_POWER2] = POWER_REAL_CH0_15P;
	NVRAM0[DM_CORR_TAB0_POWER3] = POWER_REAL_CH0_20P;
	NVRAM0[DM_CORR_TAB0_POWER4] = POWER_REAL_CH0_25P;
	NVRAM0[DM_CORR_TAB0_POWER5] = POWER_REAL_CH0_30P;
	NVRAM0[DM_CORR_TAB0_POWER6] = POWER_REAL_CH0_35P;
	NVRAM0[DM_CORR_TAB0_POWER7] = POWER_REAL_CH0_40P;
	NVRAM0[DM_CORR_TAB0_POWER8] = POWER_REAL_CH0_45P;
	NVRAM0[DM_CORR_TAB0_POWER9] = POWER_REAL_CH0_50P;
	NVRAM0[DM_CORR_TAB0_POWER10] = POWER_REAL_CH0_55P;
	NVRAM0[DM_CORR_TAB0_POWER11] = POWER_REAL_CH0_60P;
	NVRAM0[DM_CORR_TAB0_POWER12] = POWER_REAL_CH0_65P;
	NVRAM0[DM_CORR_TAB0_POWER13] = POWER_REAL_CH0_70P;
	NVRAM0[DM_CORR_TAB0_POWER14] = POWER_REAL_CH0_75P;
	NVRAM0[DM_CORR_TAB0_POWER15] = POWER_REAL_CH0_80P;
	NVRAM0[DM_CORR_TAB0_POWER16] = POWER_REAL_CH0_85P;
	NVRAM0[DM_CORR_TAB0_POWER17] = POWER_REAL_CH0_90P;
	NVRAM0[DM_CORR_TAB0_POWER18] = POWER_REAL_CH0_95P;
	NVRAM0[DM_CORR_TAB0_POWER19] = POWER_REAL_CH0_100P;
	
	NVRAM0[DM_CORR_TAB1_POWER0] = POWER_REAL_CH0_5P;
	NVRAM0[DM_CORR_TAB1_POWER1] = POWER_REAL_CH0_10P;
	NVRAM0[DM_CORR_TAB1_POWER2] = POWER_REAL_CH0_15P;
	NVRAM0[DM_CORR_TAB1_POWER3] = POWER_REAL_CH0_20P;
	NVRAM0[DM_CORR_TAB1_POWER4] = POWER_REAL_CH0_25P;
	NVRAM0[DM_CORR_TAB1_POWER5] = POWER_REAL_CH0_30P;
	NVRAM0[DM_CORR_TAB1_POWER6] = POWER_REAL_CH0_35P;
	NVRAM0[DM_CORR_TAB1_POWER7] = POWER_REAL_CH0_40P;
	NVRAM0[DM_CORR_TAB1_POWER8] = POWER_REAL_CH0_45P;
	NVRAM0[DM_CORR_TAB1_POWER9] = POWER_REAL_CH0_50P;
	NVRAM0[DM_CORR_TAB1_POWER10] = POWER_REAL_CH0_55P;
	NVRAM0[DM_CORR_TAB1_POWER11] = POWER_REAL_CH0_60P;
	NVRAM0[DM_CORR_TAB1_POWER12] = POWER_REAL_CH0_65P;
	NVRAM0[DM_CORR_TAB1_POWER13] = POWER_REAL_CH0_70P;
	NVRAM0[DM_CORR_TAB1_POWER14] = POWER_REAL_CH0_75P;
	NVRAM0[DM_CORR_TAB1_POWER15] = POWER_REAL_CH0_80P;
	NVRAM0[DM_CORR_TAB1_POWER16] = POWER_REAL_CH0_85P;
	NVRAM0[DM_CORR_TAB1_POWER17] = POWER_REAL_CH0_90P;
	NVRAM0[DM_CORR_TAB1_POWER18] = POWER_REAL_CH0_95P;
	NVRAM0[DM_CORR_TAB1_POWER19] = POWER_REAL_CH0_100P;
	
	NVRAM0[DM_CORR_TAB2_POWER0] = POWER_REAL_CH2_5P;
	NVRAM0[DM_CORR_TAB2_POWER1] = POWER_REAL_CH2_10P;
	NVRAM0[DM_CORR_TAB2_POWER2] = POWER_REAL_CH2_15P;
	NVRAM0[DM_CORR_TAB2_POWER3] = POWER_REAL_CH2_20P;
	NVRAM0[DM_CORR_TAB2_POWER4] = POWER_REAL_CH2_25P;
	NVRAM0[DM_CORR_TAB2_POWER5] = POWER_REAL_CH2_30P;
	NVRAM0[DM_CORR_TAB2_POWER6] = POWER_REAL_CH2_35P;
	NVRAM0[DM_CORR_TAB2_POWER7] = POWER_REAL_CH2_40P;
	NVRAM0[DM_CORR_TAB2_POWER8] = POWER_REAL_CH2_45P;
	NVRAM0[DM_CORR_TAB2_POWER9] = POWER_REAL_CH2_50P;
	NVRAM0[DM_CORR_TAB2_POWER10] = POWER_REAL_CH2_55P;
	NVRAM0[DM_CORR_TAB2_POWER11] = POWER_REAL_CH2_60P;
	NVRAM0[DM_CORR_TAB2_POWER12] = POWER_REAL_CH2_65P;
	NVRAM0[DM_CORR_TAB2_POWER13] = POWER_REAL_CH2_70P;
	NVRAM0[DM_CORR_TAB2_POWER14] = POWER_REAL_CH2_75P;
	NVRAM0[DM_CORR_TAB2_POWER15] = POWER_REAL_CH2_80P;
	NVRAM0[DM_CORR_TAB2_POWER16] = POWER_REAL_CH2_85P;
	NVRAM0[DM_CORR_TAB2_POWER17] = POWER_REAL_CH2_90P;
	NVRAM0[DM_CORR_TAB2_POWER18] = POWER_REAL_CH2_95P;
	NVRAM0[DM_CORR_TAB2_POWER19] = POWER_REAL_CH2_100P;
	
	NVRAM0[DM_CORR_TAB3_POWER0] = POWER_REAL_CH3_5P;
	NVRAM0[DM_CORR_TAB3_POWER1] = POWER_REAL_CH3_10P;
	NVRAM0[DM_CORR_TAB3_POWER2] = POWER_REAL_CH3_15P;
	NVRAM0[DM_CORR_TAB3_POWER3] = POWER_REAL_CH3_20P;
	NVRAM0[DM_CORR_TAB3_POWER4] = POWER_REAL_CH3_25P;
	NVRAM0[DM_CORR_TAB3_POWER5] = POWER_REAL_CH3_30P;
	NVRAM0[DM_CORR_TAB3_POWER6] = POWER_REAL_CH3_35P;
	NVRAM0[DM_CORR_TAB3_POWER7] = POWER_REAL_CH3_40P;
	NVRAM0[DM_CORR_TAB3_POWER8] = POWER_REAL_CH3_45P;
	NVRAM0[DM_CORR_TAB3_POWER9] = POWER_REAL_CH3_50P;
	NVRAM0[DM_CORR_TAB3_POWER10] = POWER_REAL_CH3_55P;
	NVRAM0[DM_CORR_TAB3_POWER11] = POWER_REAL_CH3_60P;
	NVRAM0[DM_CORR_TAB3_POWER12] = POWER_REAL_CH3_65P;
	NVRAM0[DM_CORR_TAB3_POWER13] = POWER_REAL_CH3_70P;
	NVRAM0[DM_CORR_TAB3_POWER14] = POWER_REAL_CH3_75P;
	NVRAM0[DM_CORR_TAB3_POWER15] = POWER_REAL_CH3_80P;
	NVRAM0[DM_CORR_TAB3_POWER16] = POWER_REAL_CH3_85P;
	NVRAM0[DM_CORR_TAB3_POWER17] = POWER_REAL_CH3_90P;
	NVRAM0[DM_CORR_TAB3_POWER18] = POWER_REAL_CH3_95P;
	NVRAM0[DM_CORR_TAB3_POWER19] = POWER_REAL_CH3_100P;
}
void loadScheme(void){//FD->EM
	uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > CONFIG_HMI_SCHEME_NUM)
		NVRAM0[DM_SCHEME_NUM] = CONFIG_HMI_SCHEME_NUM;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	psrc = (uint8_t*)&FDRAM[(FD_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 30)];
	pdist = (uint8_t*)&NVRAM0[EM_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, ((FD_SCHEME_END_0 - FD_SCHEME_START_0 + 1) * 2));
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
void updateSchemeName(void){//通过临时名称更新FDRAM
	uint8_t *psrc, *pdist, i;
	for(i = 0;i < CONFIG_HMI_SCHEME_NUM;i ++){
		psrc = (uint8_t*)&TMPRAM[i * 15];
		pdist = (uint8_t*)&FDRAM[i * 30];
		memcpy(pdist, psrc, 26);
	}
}
void saveScheme(void){//EM->FD
	uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > CONFIG_HMI_SCHEME_NUM)
		NVRAM0[DM_SCHEME_NUM] = CONFIG_HMI_SCHEME_NUM;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	pdist = (uint8_t*)&FDRAM[NVRAM0[DM_SCHEME_NUM] * 30];
	psrc = (uint8_t*)&NVRAM0[EM_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, 60);
}
int8_t checkScheme(int8_t cn){
	uint16_t strSize;
	int16_t temp;
	char *pstr;
	if(cn < 0){
		cn = 0;
	}
	if(cn > CONFIG_HMI_SCHEME_NUM){
		cn = CONFIG_HMI_SCHEME_NUM;
	}
	pstr = (char*)&FDRAM[cn * 30 + FD_LASER_SCHEME_NAME];//方案名称
	strSize = strlen(pstr);
	if(strSize > 30){//名称长度错误
		return false;
	}
	temp = FDRAM[cn * 30 + FD_LASER_SELECT];//通道选择
	if((temp != LASER_SELECT_CH0) || 
	   (temp != LASER_SELECT_CH1) ||
       (temp != LASER_SELECT_ALL)){
		return false;
	}		
	temp = FDRAM[cn * 30 + FD_LASER_PULSE_MODE];//脉冲模式
	if((temp != LASER_MODE_CW) || (temp != LASER_MODE_SP) || (temp != LASER_MODE_MP) || (temp != LASER_MODE_GP) ||
 	   (temp != LASER_MODE_SIGNAL) || (temp != LASER_MODE_DERMA)){
		return false;
	}
	
	temp = FDRAM[cn * 30 + FD_LASER_POWER_CH0];//通道0功率
	if(temp < CONFIG_MIN_LASERPOWER_CH0 || temp > CONFIG_MAX_LASERPOWER_CH0){
		return false;
	}
	
	temp = FDRAM[cn + 30 + FD_LASER_POWER_CH1];//通道1功率
	if(temp < CONFIG_MIN_LASERPOWER_CH1 || temp > CONFIG_MAX_LASERPOWER_CH1){
		return false;
	}
	temp = FDRAM[cn * 30 + FD_LASER_SP_POSWIDTH];//单脉冲正脉宽
	if(temp < CONFIG_MIN_LASER_POSWIDTH || temp > CONFIG_MAX_LASER_POSWIDTH){
		return false;
	}
	temp = FDRAM[cn * 30 + FD_LASER_MP_POSWIDTH];//多脉冲正脉宽
	if(temp < CONFIG_MIN_LASER_POSWIDTH || temp > CONFIG_MAX_LASER_POSWIDTH){
		return false;
	}
	temp = FDRAM[cn * 30 + FD_LASER_MP_NEGWIDTH];////多脉冲负脉宽
	if(temp < CONFIG_MIN_LASER_NEGWIDTH || temp > CONFIG_MAX_LASER_NEGWIDTH){
		return false;
	}
	temp = FDRAM[cn * 30 + FD_LASER_GP_POSWIDTH];//Group脉冲正脉宽
	if(temp < CONFIG_MIN_LASER_POSWIDTH || temp > CONFIG_MAX_LASER_POSWIDTH){
		return false;
	}
	temp = FDRAM[cn * 30 + FD_LASER_GP_NEGWIDTH];//Group脉冲负脉宽
	if(temp < CONFIG_MIN_LASER_POSWIDTH || temp > CONFIG_MAX_LASER_POSWIDTH){
		return false;
	}
	temp = FDRAM[cn * 30 + FD_LASER_GP_TIMES];//Group脉冲数
	if(temp < CONFIG_MIN_LASER_TIMES || temp > CONFIG_MAX_LASER_TIMES){
		return false;
	}
	temp = FDRAM[cn * 30 + FD_LASER_GP_GROUP_OFF];//Group脉冲间隔
	if(temp < CONFIG_MIN_LASER_GROUP_OFF || temp > CONFIG_MAX_LASER_GROUP_OFF){
		return false;
	}
	temp = FDRAM[cn * 30 + FD_LASER_SIGNAL_ENERGY_INTERVAL];////SIGNAL能量间隔
	if(temp < CONFIG_MIN_LASER_ENERGY_INTERVAL || temp > CONFIG_MAX_LASER_ENERGY_INTERVAL){
		return false;
	}
	temp = FDRAM[cn * 30 + FD_LASER_DERMA_POSWIDTH];//DERMA正脉宽
	if(temp < CONFIG_MIN_LASER_POSWIDTH || temp > CONFIG_MAX_LASER_POSWIDTH){
		return false;
	}
	temp = FDRAM[cn * 30 + FD_LASER_DERMA_NEGWIDTH];//DERMA负脉宽
	if(temp < CONFIG_MIN_LASER_NEGWIDTH || temp > CONFIG_MAX_LASER_NEGWIDTH){
		return false;
	}
	temp = FDRAM[cn * 30 + FD_LASER_DERMA_SPOT_SIZE];//DERMA光斑直径
	if((temp != DERMA_SPOT_SIZE_0MM5) ||
	   (temp != DERMA_SPOT_SIZE_1MM0) ||
	   (temp != DERMA_SPOT_SIZE_2MM0) ||
	   (temp != DERMA_SPOT_SIZE_3MM0)){
		return false;
	}
	return true;
}
int16_t PCLAR(int16_t percent, int16_t table) reentrant{//功率->DAC CODE
	int8_t index;
	fp32_t k, b, out;
	index = percent / 50;
	if(index >= 20){
		return NVRAM0[table + 20];
	}
	else{
		k = (fp32_t)(NVRAM0[table + index + 1] - NVRAM0[table + index]) / 50;
		b = NVRAM0[table + index] - (k * index * 50);		
	}
	out = k * percent + b;
	return (int16_t)out;
}

#endif