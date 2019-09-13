#ifndef __SPLCBEEM_H__
#define __SPLCBEEM_H__
/*****************************************************************************/
#define BEEM_MODE_0											0x10//连续模式
#define BEEM_MODE_1											0x11//声光同步
#define BEEM_MODE_2											0x12//激光发射固定间隔
#define BEEM_MODE_3											0x13//异常报警
#define BEEM_FREQ_0											0xF2//正常频率
#define BEEM_FREQ_1											0xF1//变调
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
void sPlcPcaInit(void);//计时器阵列初始化
void sPlcAimInit(void);//蜂鸣器初始化
void sPlcAimLoop(void);
void sPlcBeemInit(void);//蜂鸣器初始化
void sPlcBeemLoop(void);
/*****************************************************************************/
extern uint8_t data BeemFreq;//蜂鸣器频率
extern uint8_t data BeemMode;//蜂鸣器模式
extern uint8_t data BeemDuty;//蜂鸣器占空比
extern uint16_t data BeemCounter;
extern int8_t data BeemEnable;
extern uint8_t data AimDuty0, AimDuty1;
extern int8_t data AimEnable0, AimEnable1;
#endif