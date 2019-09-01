#ifndef __SPLCLASER_H__
#define __SPLCLASER_H__
/*****************************************************************************/
#include "sPlc.h"
#include "appSplcAdr.h"
#include "backgroundApp.h"
/*****************************************************************************/
#define LASER_MODE_CW							0x0001//连续模式
#define LASER_MODE_SP							0x0002//单脉冲模式
#define LASER_MODE_MP							0x0004//多脉冲模式
#define LASER_MODE_GP							0x0008//群脉冲模式
#define LASER_MODE_DERMA						0x0010//
#define LASER_MODE_SIGNAL						0x0020//单脉冲模式
#define LASER_SELECT_CH0						0x0001
#define LASER_SELECT_CH1						0x0002
#define LASER_SELECT_CH2						0x0004
#define LASER_SELECT_CH3						0x0008
#define LASER_SELECT_ALL						0x000F
/*****************************************************************************/
void sPlcLaserInit(void);
void laserTimerIsr(void);//TIMER4 中断 激光发射
void testBenchLaserTimer(uint8_t st);//LASER激光发射测试
void EDLAR(void)reentrant;//停止发射脉冲
void STLAR(void);//开始发射脉冲
#endif