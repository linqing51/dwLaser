#ifndef __SPLCLASER_H__
#define __SPLCLASER_H__
/*****************************************************************************/
#include "sPlc.h"
#include "appSplcAdr.h"
#include "backgroundApp.h"
#include "dcHmiApp.h"
/*****************************************************************************/
#define LASER_MODE_CW							0x01//连续模式
#define LASER_MODE_SP							0x02//单脉冲模式
#define LASER_MODE_MP							0x04//多脉冲模式
#define LASER_MODE_GP							0x08//群脉冲模式
#define LASER_MODE_DERMA						0x10//
#define LASER_MODE_SIGNAL						0x20//单脉冲模式
#define LASER_SELECT_CH0						0x01
#define LASER_SELECT_CH1						0x02
#define LASER_SELECT_CH2						0x04
#define LASER_SELECT_CH3						0x08
#define LASER_SELECT_ALL						0x10
/*****************************************************************************/
extern volatile int8_t data LaserTimer_Mode;
extern volatile int8_t data LaserTimer_Select;
extern volatile int16_t data LaserTimer_TCounter;
extern volatile int16_t data LaserTimer_TMate;
extern volatile int16_t data LaserTimer_TOvertime;
extern volatile int16_t data LaserTimer_PCounter;
extern volatile int16_t data LaserTimer_PMate;
extern volatile int16_t data LaserTimer_POvertime;
extern volatile int16_t data LaserTimer_ReleaseTime;
extern volatile int16_t data LaserTimer_ReleaseCounter;
extern volatile int16_t data LaserTimer_BeemSwitchCounter;
extern volatile int16_t data LaserTimer_BeemSwtichLength;
extern volatile int8_t data  LaserFlag_Emiting;//激光发射中标志
extern volatile int8_t data  LaserFlag_Emitover;//激光发射完毕标志
extern volatile int32_t data LaserRelease_TotalTime;//激光发射总时间
extern volatile int32_t data LaserRelease_TotalEnergy;//激光发射总能量
/*****************************************************************************/
void sPlcLaserInit(void);
void laserTimerIsr(void);//TIMER4 中断 激光发射
void testBenchLaserTimer(uint8_t st);//LASER激光发射测试
void EDLAR(void)reentrant;//停止发射脉冲
void STLAR(void);//开始发射脉冲
#endif