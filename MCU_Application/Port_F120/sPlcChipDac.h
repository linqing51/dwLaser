#ifndef __SPLCCHIPDAC_H__
#define __SPLCCHIPDAC_H__
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
void initChipDac(void);//DAC初始化
void refreshChipDac(void);//刷新DAC
void UPDAC0(void);//立即更新DAC0
void UPDAC1(void);//立即更新DAC1
#endif


