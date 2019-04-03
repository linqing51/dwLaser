#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "sPlcConfig.h"
#include "sPlcFun.h"
#include "sPlcPort.h"
#include "lib.h"
#if CONFIG_USING_HMI == 1
#include "hmi.h"
#endif
#if CONFIG_USING_USB == 1
#include "usbSpi.h"
#endif
/*****************************************************************************/
extern xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//掉电保持寄存器 当前
extern xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//掉电保持寄存器 上一次
#if (CONFIG_SPLC_USING_UART0 == 1 && CONFIG_MB_PORT != UART0)
extern xdata uint8_t volatile UART0_TXBUF[CONFIG_UART0_RBUF_SIZE];//UART0发送缓冲
extern xdata uint8_t volatile UART0_RXBUF[CONFIG_UART0_TBUF_SIZE];//UART0接收缓冲
#endif
#if (CONFIG_SPLC_USING_UART1 == 1 && CONFIG_MB_PORT != UART1)
extern xdata uint8_t volatile UART1_TXBUF[CONFIG_UART1_RBUF_SIZE];//UART1发送缓冲
extern xdata uint8_t volatile UART1_RXBUF[CONFIG_UART1_TBUF_SIZE];//UART1接收缓冲
#endif
extern idata volatile uint8_t TimerCounter_1mS;
extern idata volatile uint8_t TimerCounter_10mS;
extern idata volatile uint8_t TimerCounter_100mS;
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
//extern uint8_t getGlobalInterrupt(void);
extern void setLedRun(uint8_t st);
extern uint8_t getLedRun(void);
extern void setLedEprom(uint8_t st);
extern uint8_t getLedEprom(void);
extern void setLedDac(uint8_t st);
extern uint8_t getLedDac(void);
extern void setLedError(uint8_t st);
extern uint8_t getLedError(void);
extern void setLedAdc(uint8_t st);
extern uint8_t getLedAdc(void);
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
/*****************************************************************************/
void enterSplcIsr(void) reentrant;
void exitSplcIsr(void) reentrant;
void disableSplcIsr(void) reentrant;
void enableSplcIsr(void) reentrant;
/*****************************************************************************/
void sPlcInit(void);

/*****************************************************************************/
#endif
