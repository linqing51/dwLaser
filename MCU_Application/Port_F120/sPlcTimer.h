#ifndef __SPLCTIMER_H__
#define __SPLCTIMER_H__
/*****************************************************************************/
#include "sPlcPort.h"
void initSplcTimer(void);//硬件sTimer计时器初始化
extern void sPlcTimerIsr(void);//硬件sTimer计时器中断 1mS
#endif