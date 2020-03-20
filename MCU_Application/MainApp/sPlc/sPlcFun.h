#ifndef __SPLCFUN_H__
#define __SPLCFUN_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
void REBOOT(void) reentrant;//强制复位
//位指令
void SET(uint16_t A) reentrant;//线圈置位
void RES(uint16_t A) reentrant;//线圈复位
void FLIP(uint16_t A) reentrant;//翻转
uint8_t LD(uint16_t A) reentrant;//载入
uint8_t LDB(uint16_t A) reentrant;//方向载入
uint8_t LDP(uint16_t A) reentrant;//脉冲上升沿
uint8_t LDN(uint16_t A) reentrant;//脉冲下降沿
//计时器指令
void T100MS(uint8_t A, uint8_t start, uint16_t value) reentrant;//100mS计时器启动
#endif