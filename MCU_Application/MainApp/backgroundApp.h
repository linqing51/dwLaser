#ifndef __BACKGROUNDAPP_H__
#define __BACKGROUNDAPP_H__
/*****************************************************************************/
#include "sPlc.h"
#include "appConfig.h"
#include "appSplcAdr.h"
/*****************************************************************************/
typedef struct{
  float Kp;                       //比例系数Proportional
  float Ki;                       //积分系数Integral
  float Kd;                       //微分系数Derivative
  float Ek;                       //当前误差
  float Ek1;                      //前一次误差 e(k-1)
  float Ek2;                      //再前一次误差 e(k-2)
  float LocSum;                   //累计积分位置
}PID_LocTypeDef; 
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
/*****************************************************************************/
void PidRegulateInit(void);
fp32_t PidRegulate(fp32_t ref, fp32_t feedback);//限制输入幅度，归一化到[-1，1]区间
#endif