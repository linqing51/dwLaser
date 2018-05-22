#ifndef __STIMER_H__
#define __STIMER_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/

/*****************************************************************************/
typedef struct
{//定义软件PLC功能
	uint8_t status;//计时器寄存器
	uint8_t enable;//计时器使能
	uint16_t mate;//计时器匹配值
	uint16_t value;//计时器计时值	
}sTimer_t;
/*****************************************************************************/
extern sTimer_t sTimer[CONFIG_PLC_T_NUM];
/*****************************************************************************/
void sTimerInit(void);//初始化
int8_t sTimerCtrl(int8_t enable, uint16_t num, uint16_t value);//计数器控制
/*****************************************************************************/
#endif