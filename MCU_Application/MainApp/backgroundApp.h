#ifndef __BACKGROUNDAPP_H__
#define __BACKGROUNDAPP_H__
/*****************************************************************************/
#include "sPlc.h"
#include "appConfig.h"
#include "appSplcAdr.h"
/*****************************************************************************/
uint8_t getBeemDuty(int16_t volume);
uint8_t getLcdDuty(int16_t LcdBrg);//屏幕亮度值转换为占空比
uint8_t getAimDuty(int16_t AimBrg);//指示光亮度值转换为占空比
int16_t pulseWidthAdd(int16_t ps);
int16_t pulseWidthDec(int16_t ps);
void loadScheme(void);//DM->EM
void updateSchemeName(void);//TMP->FD
void saveScheme(void);//EM->DM
int8_t checkScheme(int8_t cn);//方案检测
void reloadCorrTab(void);//恢复功率校正参数
void defaultScheme(void);//恢复默认设置
void loadDefault(void);
int16_t PCLAR(int16_t percent, int16_t table) reentrant;
#endif