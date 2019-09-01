#ifndef __SPLCCHIPDAC_H__
#define __SPLCCHIPDAC_H__
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
void initChipDac(void);//DAC初始化
void refreshChipDac(void);//刷新DAC
void UPDAC0(void) reentrant;//立即更新DAC0
void UPDAC1(void) reentrant;//立即更新DAC1
void UPDAC2(void) reentrant;
void UPDAC3(void) reentrant;
void CLDAC(void) reentrant;//立即清空DAC0和DAC1
#endif


