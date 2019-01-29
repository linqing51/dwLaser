#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "sPlcConfig.h"
#include "sPlcFun.h"
#include "sPlcPort.h"
#include "lib.h"
/*****************************************************************************/

/*****************************************************************************/
extern xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//掉电保持寄存器 当前
extern xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//掉电保持寄存器 上一次
extern idata volatile uint8_t TimerCounter_1mS;
extern idata volatile uint8_t TimerCounter_10mS;
extern idata volatile uint8_t TimerCounter_100mS;
extern idata volatile uint8_t Timer0_L, Timer0_H;
/*****************************************************************************/
void sPlcInit(void);//软逻辑初始化

void sPlcProcessStart(void);//sPLC轮询起始
void sPlcProcessEnd(void);//sPLC轮询结束
extern void initWatchDog(void);//看门狗初始化
extern void feedWatchDog(void) reentrant;//喂狗
extern void enableWatchDog(void);//使能看门狗
extern void disableWatchDog(void);//关闭看门狗(未锁定)
void checkWatchDog(void);//检查看门狗状态
/*****************************************************************************/
void assertCoilAddress(uint16_t adr) reentrant;
void assertRegisterAddress(uint16_t adr) reentrant;
/*****************************************************************************/
void clearX(void);
void clearY(void);
void clearDM(void);
void clearEM(void);
void clearR(void);
void clearT(void);
void clearTD(void);
void clearC(void);
void clearSPCOIL();
void clearSPREG(void);
extern void loadNvram(void);
extern void clearNvram(void);
extern void saveNvram(void);
extern void updataNvram(void);
/*****************************************************************************/
void enterSplcIsr(void);
void exitSplcIsr(void);
/*****************************************************************************/
void initSplcTimer(void);
void chipDacInit(void);
void chipAdcInit(void);
void sPlcInit(void);
void refreshDac(void);
/*****************************************************************************/
#endif
