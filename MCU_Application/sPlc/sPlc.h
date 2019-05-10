#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "lib.h"
#include "sPlcConfig.h"
#include "sPlcFun.h"
#include "sPlcPort.h"
#include "debugLed.h"
#if CONFIG_SPLC_FUN_EPID == 1
#include "splcFunEPID.h"
#endif
#if CONFIG_SPLC_FUNTEST == 1
#include "sPlcTest.h"
#endif
/*****************************************************************************/
#define SPLC_FP32					*(fp32_t*)//指针取单精度浮点
#define SPLC_FP64					*(fp64_t*)//指针取双精度浮点
#define SPLC_INT32					*(int32_t*)//指针取长整数
/*****************************************************************************/
extern int16_t NVRAM0[CONFIG_NVRAM_SIZE];//掉电保持寄存器 当前
extern int16_t NVRAM1[CONFIG_NVRAM_SIZE];//掉电保持寄存器 上一次
extern uint8_t TimerCounter_1mS;
extern uint8_t TimerCounter_10mS;
extern uint8_t TimerCounter_100mS;
extern uint8_t TD_1MS_SP;
extern uint8_t TD_10MS_SP;
extern uint8_t TD_100MS_SP;
extern uint8_t TD_1000MS_SP;
/*****************************************************************************/
void sPlcInit(void);//软逻辑初始化
void sPlcProcessStart(void);//sPLC轮询起始
void sPlcProcessEnd(void);//sPLC轮询结束
extern void sPlcPortProcess(void);//sPLC平台程序
extern void initWatchDog(void);//看门狗初始化
extern void feedWatchDog(void) reentrant;//喂狗
extern void enableWatchDog(void);//使能看门狗
extern void disableWatchDog(void);//关闭看门狗(未锁定)
extern void checkWatchDog(void);//检查看门狗状态
extern void mucReboot(void) reentrant;//软件复位
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
void clearSPCOIL();
void clearSPREG(void);
/*****************************************************************************/
void enterSplcIsr(void) reentrant;
void exitSplcIsr(void) reentrant;
void disableSplcIsr(void) reentrant;
void enableSplcIsr(void) reentrant;
/*****************************************************************************/
void sPlcInit(void);
void updataNvram(void);//更新NVRAM->EPROM
void clearNvram(void);//清除NVRAM数据	
/*****************************************************************************/
#endif
