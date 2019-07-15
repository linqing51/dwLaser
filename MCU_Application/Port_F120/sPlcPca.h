#ifndef __SPLCBEEM_H__
#define __SPLCBEEM_H__
/*****************************************************************************/
#define BEEM_MODE_0											0//连续模式
#define BEEM_MODE_1											1//声光同步
#define BEEM_MODE_2											2//激光发射固定间隔
#define BEEM_MODE_3											3//异常报警
#define BEEM_FREQ_0											0xEE//正常频率
#define BEEM_FREQ_1											0xFA
#define BEEM_FREQ_2											0xFC
#define BEEM_FREQ_3											0xFF
#define BEEM_VOLUME_0										0xFF
#define BEEM_VOLUME_1										0xFC
#define BEEM_VOLUME_2										0xFA
#define BEEM_VOLUME_3										0xF2
#define BEEM_VOLUME_4										0xE2
#define BEEM_VOLUME_5										0xB0
#define BEEM_VOLUME_6										0x90
#define BEEM_VOLUME_7										0x80
#define BEEM_VOLUME_8										0x60
#define BEEM_VOLUME_9										0x40
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
void sPlcPcaInit(void);//计时器阵列初始化
void sPlcAimInit(void);//蜂鸣器初始化
void sPlcAimLoop(void);
void sPlcBeemInit(void);//蜂鸣器初始化
void sPlcBeemLoop(void);
#endif