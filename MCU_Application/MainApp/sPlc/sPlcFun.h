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
void T100US(uint8_t A, uint8_t start, uint16_t value) reentrant;//100uS计时器启动
void T1MS(uint8_t A, uint8_t start, uint16_t value) reentrant;//1mS计时器启动
void T10MS(uint8_t A, uint8_t start, uint16_t value) reentrant;//10mS计时器启动
void T100MS(uint8_t A, uint8_t start, uint16_t value) reentrant;//100mS计时器启动
//运算指令
void ADD(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant;//16位非饱和加法 D = Sa + Sb
void ADDS(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant;//16位饱和求和 D = Sa + Sb
void DADD(int32_t *Sa, int32_t *Sb, int32_t *D) reentrant;//32位非饱加法 D = Sa + Sb
void SUB(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant;//16位非饱和减法
void SUBS(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant;//16位饱和减法
void DSUB(int32_t *Sa, int32_t *Sb, int32_t *D) reentrant;//32位非饱和减法
void MULT(int16_t *Sa, int16_t *Sb, int32_t *D) reentrant;//16*16非饱和乘法 D = Sa * Sb
void MULTS(int16_t *Sa, int16_t *Sb, int32_t *D) reentrant;//16*16->32饱和乘法 D = Sa * Sb
/*****************************************************************************/
int16_t MAX(int16_t *s, uint8_t len) reentrant;//找出长度为len的数据s中的最大值
int16_t MIN(int16_t *s, uint8_t len) reentrant;//找出长度为len的数据s中的最小值
#endif