#ifndef __SPLCLASER_H__
#define __SPLCLASER_H__
/*****************************************************************************/
#include "sPlc.h"
/*****************************************************************************/
#define LASER_MODE_CW							0x1A50//连续模式
#define LASER_MODE_SP							0x2B61//单脉冲模式
#define LASER_MODE_MP							0x3C72//多脉冲模式
#define LASER_MODE_GP							0x4D83//群脉冲模式
#define LASER_SELECT_980						0x005A
#define LASER_SELECT_1470						0xA500
#define LASER_SELECT_BOTH						0xA55A
/*****************************************************************************/
void sPlcLaserInit(void);
void testBenchLaserTimer(uint8_t st);//LASER激光发射测试
void EDLAR(void) reentrant;//停止发射脉冲
void STLAR(void) reentrant;//开始发射脉冲
#endif