#ifndef __FILTER_H__
#define __FILTER_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
typedef struct{//FIR滤波器结构体
	int16_t _x[3];//中间变量
}firFilter_t;

/*****************************************************************************/
void firFilterInit(firFilter_t *st);
int16_t firFilterRun(firFilter_t *st, int16_t dat);
#endif