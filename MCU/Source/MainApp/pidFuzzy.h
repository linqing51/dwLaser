#ifndef __PID_FUZZY_H__
#define __PID_FUZZY_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
typedef struct 
{
	fp32_t Kp; // 增量式积分系数
	fp32_t Ki; 
	fp32_t Kd;
	fp32_t T;
	
	fp32_t K1; // 增量式积分系数
	fp32_t K2; 
	fp32_t K3; 
	fp32_t LastError; //Error[-1]
	fp32_t PrevError; // Error[-2]
	fp32_t pwm_out;
	
	uint16_t flag;//温度状态标志位
}pidFuzzy_t;

/*****************************************************************************/
void PID_Set(pidFuzzy_t *structpid, fp32_t Kp, fp32_t Ki, fp32_t Kd, fp32_t T);
int16_t PID_realize(pidFuzzy_t *structpid, uint16_t s, uint16_t in);
void pidFuzzyInit(pidFuzzy_t *structpid);
/*****************************************************************************/
#endif
