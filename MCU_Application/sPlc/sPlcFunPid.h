#ifndef __PID_FUZZY_H__
#define __PID_FUZZY_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
typedef struct 
{
	//预设的PID参数
	fp32_t Kp;
	fp32_t Ki; 
	fp32_t Kd;
	
	fp32_t error;
	fp32_t error1; //Error[-1]
	fp32_t error2; // Error[-2]
	fp32_t dout;
	
}pidFuzzy_t;

/*****************************************************************************/
fp32_t pidFuzzyRealize(pidFuzzy_t *p, fp32_t set, fp32_t fb);
void pidFuzzyInit(pidFuzzy_t *p, fp32_t Kp, fp32_t Ki, fp32_t Kd);
/*****************************************************************************/
#endif
