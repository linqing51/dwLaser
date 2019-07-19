#ifndef __BACKGROUNDAPP_H__
#define __BACKGROUNDAPP_H__
/*****************************************************************************/
#include "sPlc.h"
#include "appSplcAdr.h"
/*****************************************************************************/
uint8_t getBeemDuty(int16_t volume);
void loadScheme(void);//DM->EM
void saveScheme(void);//EM->DM
void checkScheme(void);//方案检测
void reloadCorrTab(void);//恢复功率校正参数
void defaultScheme(void);//恢复默认设置
void loadDefault(void);
void PCLAR0(uint16_t POW, uint16_t CUR) reentrant;//功率->DAC CODE
void PCLAR1(uint16_t POW, uint16_t CUR) reentrant;//功率->DAC CODE
#endif