#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "sPlcConfig.h"
#include "sPlcFun.h"
#include "sPlcPort.h"
#include "lib.h"
/*****************************************************************************/

/*****************************************************************************/
extern xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
extern xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
extern idata volatile uint8_t TimerCounter_1mS;
extern idata volatile uint8_t TimerCounter_10mS;
extern idata volatile uint8_t TimerCounter_100mS;
extern idata volatile uint8_t Timer0_L, Timer0_H;
/*****************************************************************************/
void sPlcInit(void);//���߼���ʼ��

void sPlcProcessStart(void);//sPLC��ѯ��ʼ
void sPlcProcessEnd(void);//sPLC��ѯ����
extern void initWatchDog(void);//���Ź���ʼ��
extern void feedWatchDog(void) reentrant;//ι��
extern void enableWatchDog(void);//ʹ�ܿ��Ź�
extern void disableWatchDog(void);//�رտ��Ź�(δ����)
void checkWatchDog(void);//��鿴�Ź�״̬
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
