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
float PID_Loc(float SetValue, float ActualValue, PID_LocTypeDef *PID)
{
	float PIDLoc;//位置 
	PID->Ek = SetValue - ActualValue;
	PID->LocSum += PID->Ek;//累计误差
	PIDLoc = PID->Kp * PID->Ek + (PID->Ki * PID->LocSum) + PID->Kd * (PID->Ek1 - PID->Ek);
	PID->Ek1 = PID->Ek;  
		return PIDLoc;
}
void loadDefault(void){//恢复默认值
	uint8_t i;
	NVRAM0[DM_SCHEME_NUM] = 0;
	NVRAM0[DM_BEEM_VOLUME] = 9;
	NVRAM0[DM_AIM_BRG] = CONFIG_MAX_AIM_BRG;
	NVRAM0[DM_LCD_BRG] = CONFIG_MAX_LCD_BRG;
	reloadCorrTab();
	for(i=0;i<CONFIG_HMI_SCHEME_NUM;i++){
		NVRAM0[DM_SCHEME_NUM] = i;
		defaultScheme();
		saveScheme();
	}
	FDSAV();
}
uint8_t getBeemDuty(int16_t volume){//获取蜂鸣器占空比设置
	switch(volume){
		case 0:{
			return BEEM_VOLUME_0;
			break;
		}
		case 1:{
			return BEEM_VOLUME_1;
			break;
		}
		case 2:{
			return BEEM_VOLUME_2;
			break;
		}
		case 3:{
			return BEEM_VOLUME_3;
			break;
		}
		case 4:{
			return BEEM_VOLUME_4;
			break;
		}
		case 5:{
			return BEEM_VOLUME_5;
			break;
		}
		case 6:{
			return BEEM_VOLUME_6;
			break;
		}
		case 7:{
			return BEEM_VOLUME_7;
			break;
		}
		case 8:{
			return BEEM_VOLUME_8;
			break;
		}
		case 9:{
			return BEEM_VOLUME_9;
			break;
		}
		default:{
			return BEEM_VOLUME_9;
		}break;
	}
}
void defaultScheme(void){//当前选择方案恢复默认值
	sprintf((char*)(&NVRAM0[EM_LASER_SCHEME_NAME]),"Hello dwLaser S%d",NVRAM0[DM_SCHEME_NUM]);		
	NVRAM0[EM_LASER_SELECT]	= LASER_SELECT_BOTH;//通道选择
	NVRAM0[EM_LASER_PULSE_MODE]	= LASER_MODE_CW;//脉冲模式
	NVRAM0[EM_LASER_POWER_CH0] = 0;//通道0功率
	NVRAM0[EM_LASER_POWER_CH1] = 0;//通道1功率
	NVRAM0[EM_LASER_SP_POSWIDTH]= 500;//单脉冲正脉宽
	NVRAM0[EM_LASER_MP_POSWIDTH]= 500;//多脉冲正脉宽
	NVRAM0[EM_LASER_MP_NEGWIDTH]= 500;//多脉冲负脉宽
	NVRAM0[EM_LASER_GP_POSWIDTH]= 500;//Group脉冲正脉宽
	NVRAM0[EM_LASER_GP_NEGWIDTH]= 500;//Group脉冲负脉宽
	NVRAM0[EM_LASER_GP_TIMES] =	100;//Group脉冲数
	NVRAM0[EM_LASER_GP_GROUP_OFF] = 600;//Group脉冲间隔
	NVRAM0[EM_LASER_SIGNAL_ENERGY_INTERVAL] = CONFIG_MIN_LASER_ENERGY_INTERVAL;//EVLA_SIGNAL能量间隔
	NVRAM0[EM_LASER_DERMA_POSWIDTH]	= 500;//DERMA正脉宽
	NVRAM0[EM_LASER_DERMA_NEGWIDTH]	= 500;//DERMA负脉宽
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
void saveScheme(void){//EM->FD
	uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > CONFIG_HMI_SCHEME_NUM)
		NVRAM0[DM_SCHEME_NUM] = CONFIG_HMI_SCHEME_NUM;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	pdist = (uint8_t*)&FDRAM[(FD_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 30)];
	psrc = (uint8_t*)&NVRAM0[EM_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, ((FD_SCHEME_END_0 - FD_SCHEME_START_0 + 1) * 2));
}
void PCLAR0(uint16_t POW, uint16_t CUR) reentrant{//功率->DAC CODE
	uint8_t index;
	fp32_t pert, k, b, out;
	pert = (fp32_t)NVRAM0[POW] / CONFIG_MAX_LASERPOWER_CH0;
	index = (uint8_t)(pert / 0.05);	
	if(index >= 20){
		NVRAM0[CUR] = NVRAM0[DM_CORR_TAB0_POWER20];
	}
	else{
		k = ((fp32_t)NVRAM0[(DM_CORR_TAB0_POWER0 + index + 1)] - (fp32_t)NVRAM0[DM_CORR_TAB0_POWER0 + index]) / 0.05;
		b = NVRAM0[DM_CORR_TAB0_POWER0 + index] - (k * index * 0.05);		
	}
	out = k * (fp32_t)pert - b;
	if(out > CONFIG_MAX_LASER_DAC_CH0){
		out = CONFIG_MAX_LASER_DAC_CH0;
	}
	NVRAM0[CUR] = (int16_t)out;
}
void PCLAR1(uint16_t POW, uint16_t CUR) reentrant{//功率->DAC CODE
	uint8_t index;
	fp32_t pert, k, b, out;
	pert = (fp32_t)NVRAM0[POW] / CONFIG_MAX_LASERPOWER_CH1;
	index = (uint8_t)(pert / 0.05);	
	if(index >= 20){
		NVRAM0[CUR] = NVRAM0[DM_CORR_TAB1_POWER20];
	}
	else{
		k = ((fp32_t)NVRAM0[(DM_CORR_TAB1_POWER0 + index + 1)] - (fp32_t)NVRAM0[DM_CORR_TAB1_POWER0 + index]) / 0.05;
		b = NVRAM0[DM_CORR_TAB1_POWER0 + index] - (k * index * 0.05);		
	}
	out = k * (fp32_t)pert - b;
	if(out > CONFIG_MAX_LASER_DAC_CH1){
		out = CONFIG_MAX_LASER_DAC_CH1;
	}
	NVRAM0[CUR] = (int16_t)out;
}
#endif