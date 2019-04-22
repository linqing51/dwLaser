#include "sPlcFunEPID.h"
/*****************************************************************************/
#define EPID_TAB_OUT				0//输出值地址
#define EPID_TAB_REF				1//反馈值
#define EPID_TAB_VFB				2//设置定值
#define EPID_TAB_KP					3//比例常数 XX.XXX 0-65.535
#define	EPID_TAB_KI					4//积分常数 XX.XXX 0-65.535		
#define EPID_TAB_TD 				5//微分时间常数 XX.XXX 0-65.535
#define EPID_TAB_TS					6//PID运算时间间隔 1-3000 单位0.01S
#define EPID_TAB_EN					7//当前误差值 FP32 
#define EPID_TAB_VFB1 				9//前1次误差值 FP32
#define EPID_TAB_MAX				11//输出最大限制		
#define EPID_TAB_MIN				12//输出最小限制
#define EPID_TAB_BIAS				13//输出偏置
#define EPID_TAB_TSC				14//间隔计时器
#define EPID_TAB_KP_SUM				15//比例累加值 FP32
#define EPID_TAB_KI_SUM				17//微分累加值 FP32
#define EPID_TAB_KD_SUM				19//微分累加值 FP32
#define EPID_TAB_FOUT				21//输出累加值 FP32
/*****************************************************************************/
#if CONFIG_SPLC_FUN_EPID == 1
void EPID(int16_t *tab){//泛用PID指令
	if(*(tab + EPID_TAB_TS) > 3000){//限制间隔时间不大于3000
		*(tab + EPID_TAB_TS) = 3000;
	}
	if(*(tab + EPID_TAB_TSC) >= *(tab + EPID_TAB_TS)){//TSC >= TS
		SPLC_FP32(tab + EPID_TAB_EN) = (fp32_t)(*(tab + EPID_TAB_REF)) - (fp32_t)(*(tab + EPID_TAB_VFB));//En = REF - VFB
		SPLC_FP32(tab + EPID_TAB_KP_SUM) = (fp32_t)(*(tab + EPID_TAB_KP)) / 100.0 * (SPLC_FP32(tab + EPID_TAB_EN));//KP_SUM = KP * En  
		SPLC_FP32(tab + EPID_TAB_KI_SUM) += (fp32_t)(*(tab + EPID_TAB_KP)) / 100.0 * ((fp32_t)*(tab + EPID_TAB_KI)) * ((fp32_t)*(tab + EPID_TAB_TS)) * (*(fp32_t*)(tab + EPID_TAB_EN));//KI_SUM = KP * KI * TS * EN
		SPLC_FP32(tab + EPID_TAB_KD_SUM) = (fp32_t)(*(tab + EPID_TAB_KP)) / 100.0 * (fp32_t)(*(tab + EPID_TAB_TD)) * ((fp32_t)*(tab + EPID_TAB_VFB) - (fp32_t)*(tab + EPID_TAB_VFB1)) / ((fp32_t)*(tab + EPID_TAB_TS));//KP * Td * (VFB -VFB1) / Ts
		//限制积分大小
		if(SPLC_FP32(tab + EPID_TAB_KI_SUM) >= ((fp32_t)*(tab + EPID_TAB_MAX))){
			SPLC_FP32(tab + EPID_TAB_KI_SUM) = (fp32_t)*(tab + EPID_TAB_MAX);
		}
		if(SPLC_FP32(tab + EPID_TAB_KI_SUM) <= ((fp32_t)*(tab + EPID_TAB_MIN))){
			SPLC_FP32(tab + EPID_TAB_KI_SUM) = (fp32_t)*(tab + EPID_TAB_MIN);
		}
		SPLC_FP32(tab + EPID_TAB_FOUT) = SPLC_FP32(tab + EPID_TAB_EN);
		SPLC_FP32(tab + EPID_TAB_FOUT) += SPLC_FP32(tab + EPID_TAB_KP_SUM);
		SPLC_FP32(tab + EPID_TAB_FOUT) += SPLC_FP32(tab + EPID_TAB_KI_SUM);
		SPLC_FP32(tab + EPID_TAB_FOUT) += SPLC_FP32(tab + EPID_TAB_KD_SUM);
		SPLC_FP32(tab + EPID_TAB_FOUT) += (fp32_t)(*(tab + EPID_TAB_BIAS));//out += bias
		//限制输出大小
		if(SPLC_FP32(tab + EPID_TAB_FOUT) >= ((fp32_t)*(tab + EPID_TAB_MAX))){
			SPLC_FP32(tab + EPID_TAB_FOUT) = (fp32_t)*(tab + EPID_TAB_MAX);
		}
		if(SPLC_FP32(tab + EPID_TAB_FOUT) <= ((fp32_t)*(tab + EPID_TAB_MIN))){
			SPLC_FP32(tab + EPID_TAB_FOUT) = (fp32_t)*(tab + EPID_TAB_MIN);
		}
		*(tab + EPID_TAB_VFB1) = *(tab + EPID_TAB_VFB);//VFB1 <- VFB
		*(tab + EPID_TAB_OUT) = (int16_t)(SPLC_FP32(tab + EPID_TAB_FOUT));//OUT <- FOUT
		*(tab + EPID_TAB_TSC) = 0;//TSC = 0	
	}
	else{
		*(tab + EPID_TAB_TSC) += 1;//TSC = 1
	}	
}
#endif