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
/*****************************************************************************/
#define SPLC_FP32					*(fp32_t*)//ָ��ȡ�����ȸ���
#define SPLC_FP64					*(fp64_t*)//ָ��ȡ˫���ȸ���
#define SPLC_INT32					*(int32_t*)//ָ��ȡ������
/*****************************************************************************/
extern xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
extern xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
#if (CONFIG_SPLC_USING_UART0 == 1 && CONFIG_MB_PORT != UART0)
extern xdata uint8_t volatile UART0_TXBUF[CONFIG_UART0_RBUF_SIZE];//UART0���ͻ���
extern xdata uint8_t volatile UART0_RXBUF[CONFIG_UART0_TBUF_SIZE];//UART0���ջ���
#endif
#if (CONFIG_SPLC_USING_UART1 == 1 && CONFIG_MB_PORT != UART1)
extern xdata uint8_t volatile UART1_TXBUF[CONFIG_UART1_RBUF_SIZE];//UART1���ͻ���
extern xdata uint8_t volatile UART1_RXBUF[CONFIG_UART1_TBUF_SIZE];//UART1���ջ���
#endif
extern xdata volatile uint8_t TimerCounter_1mS;
extern xdata volatile uint8_t TimerCounter_10mS;
extern xdata volatile uint8_t TimerCounter_100mS;
extern xdata volatile uint8_t TD_1MS_SP;
extern xdata volatile uint8_t TD_10MS_SP;
extern xdata volatile uint8_t TD_100MS_SP;
extern xdata volatile uint8_t TD_1000MS_SP;
/*****************************************************************************/
void sPlcInit(void);//���߼���ʼ��
void sPlcProcessStart(void);//sPLC��ѯ��ʼ
void sPlcProcessEnd(void);//sPLC��ѯ����
extern void sPlcPortProcess(void);//sPLCƽ̨����
extern void initWatchDog(void);//���Ź���ʼ��
extern void feedWatchDog(void) reentrant;//ι��
extern void enableWatchDog(void);//ʹ�ܿ��Ź�
extern void disableWatchDog(void);//�رտ��Ź�(δ����)
extern void checkWatchDog(void);//��鿴�Ź�״̬
extern void mucReboot(void) reentrant;//�����λ
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

/*****************************************************************************/
#endif
