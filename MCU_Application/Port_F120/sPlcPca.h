#ifndef __SPLCBEEM_H__
#define __SPLCBEEM_H__
/*****************************************************************************/
#define BEEM_TIMER_MODE_0						0
#define BEEM_TIMER_MODE_1						1
#define BEEM_TIMER_MODE_2						2
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
void sPlcPcaInit(void);//计时器阵列初始化
void sPlcAimInit(void);//蜂鸣器初始化
void sPlcAimLoop(void);
void sPlcBeemInit(void);//蜂鸣器初始化
void sPlcBeemLoop(void);
void testBenchBeem(uint8_t volume, uint8_t mode);//蜂鸣器测试
void testBenchAim(uint8_t port, uint8_t brightness);//指示光测试
#endif