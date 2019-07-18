#ifndef __SPLCFUN_H__
#define __SPLCFUN_H__
/*****************************************************************************/
#include "sPlc.h"
/*****************************************************************************/
void REBOOT(void) ;//复位
//位指令
void SET(uint16_t A) reentrant;//线圈置位
void RES(uint16_t A) reentrant;//线圈复位
void FLIP(uint16_t A) ;//翻转
uint8_t LD(uint16_t A) ;//载入
uint8_t LDB(uint16_t A) ;//方向载入
uint8_t LDP(uint16_t A) ;//脉冲上升沿
uint8_t LDN(uint16_t A) ;//脉冲下降沿
//计时器指令
void T10MS(uint8_t A, uint8_t start, uint16_t value) ;//10mS计时器启动
void T100MS(uint8_t A, uint8_t start, uint16_t value) ;//100mS计时器启动
//运算指令
void CLR(uint16_t A) ;//寄存器清零
void CLRD(uint16_t A) ;//32位寄存器清零
void MOV(uint16_t dist, uint16_t src) ;//16位寄存器传输
void MOVD(uint16_t dist, uint16_t src) ;//32位寄存器传输
void SWAP(uint16_t dist, uint16_t src) ;//交换A的高低字节
void ABS16(uint16_t dist, uint16_t src) ;//16位数球绝对值
void ABS32(uint16_t dist, uint16_t src) ;//32位数求绝对值
void SMIN16(uint16_t index, uint16_t length, uint16_t min) ;//16位有符号数组找最小值
void SMAX16(uint16_t index, uint16_t length, uint16_t max) ;//16位有符号数组找最大值
void UMIN16(uint16_t index, uint16_t length, uint16_t min) ;//16位无符号数组找最小值
void UMAX16(uint16_t index, uint16_t length, uint16_t max) ;//16位无符号数组找最大值
void SUM16(uint16_t index, uint16_t length, uint16_t sum) ;//16BIT数求和->32BIT
void MULT32(uint16_t Sa, uint16_t Sb, uint16_t D) ;//16*16->32非饱和乘法 D = Sa * Sb
void MULTS16(uint16_t Sa, uint16_t Sb, uint16_t D) ;//16*16->16饱和乘法 D = Sa * Sb
void MULT16(uint16_t Sa, uint16_t Sb, uint16_t D) ;//16*16->16非饱和乘法 D = Sa * Sb
void SUB32(uint16_t Sa, uint16_t Sb, uint16_t D) ;//32位非饱和减法 D = Sa - Sb
void SUBS16(uint16_t Sa, uint16_t Sb, uint16_t D) ;//16位饱和减法 D = Sa - Sb
void SUB16(uint16_t Sa, uint16_t Sb, uint16_t D) ;//16位非饱和减法 D = Sa - Sb
void ADD32(uint16_t Sa, uint16_t Sb, uint16_t D) ;//32位非饱加法 D = Sa + Sb
void ADDS32(uint16_t Sa, uint16_t Sb, uint16_t D) ;//32位饱和加法 D = Sa + Sb
void ADDS16(uint16_t Sa, uint16_t Sb, uint16_t D) ;//16位饱和加法 D = Sa + Sb
void ADD16(uint16_t Sa, uint16_t Sb, uint16_t D) ;//16位非饱和加法 D = Sa + Sb
void ADD1(uint16_t Sa) ;//16位非饱和自加
void ADDS1(uint16_t Sa) ;//16位饱和自加
void DEC1(uint16_t Sa) ;//16位非饱和自减
void DECS1(uint16_t Sa) ;//16位饱和自减
void ADL1(uint16_t Sa) ;//32位非饱和自加
void ADLS1(uint16_t Sa) ;//32位饱和自加
void DEL1(uint16_t Sa) ;//32位非饱和自减
void DELS1(uint16_t Sa) ;//32位饱和自减
void TNTC(uint16_t dist, uint16_t src) ;//CODE转换为环境温度
void TENV(uint16_t dist, uint16_t src) ;//CODE转换为NTC测量温度温度
void BCPY(uint16_t dist, uint16_t src, uint16_t length) ;//块复制
/*****************************************************************************/
//void XTAB(int16_t *distY, int16_t *srcX, int16_t *index, int16_t *length) ;//线性查表从X计算Y值
//void YTAB(int16_t *distX, int16_t *srcY, int16_t *index, int16_t *length) ;//线性查表从Y计算X值
/*****************************************************************************/
void IMDIO(void) ;//立即更新IO点状态含输入输出
void TPCTL(int16_t *ref, int16_t *fb, int16_t buf) ;//温控PID指令
void HSPWM(int16_t *pos, int16_t *neg, int16_t pot) ;//硬件PWM输出
/*****************************************************************************/
void NVSAV(void);//强制立即更新NVRAM
void NVLOAD(void);
void FDSAV(void);
void FDLAD(void);
#endif


