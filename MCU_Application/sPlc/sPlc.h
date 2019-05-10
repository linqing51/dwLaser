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
#define SPLC_FP32					*(fp32_t*)//ָ��ȡ�����ȸ���
#define SPLC_FP64					*(fp64_t*)//ָ��ȡ˫���ȸ���
#define SPLC_INT32					*(int32_t*)//ָ��ȡ������
/*****************************************************************************/
extern int16_t NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
extern int16_t NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
extern uint8_t TimerCounter_1mS;
extern uint8_t TimerCounter_10mS;
extern uint8_t TimerCounter_100mS;
extern uint8_t TD_1MS_SP;
extern uint8_t TD_10MS_SP;
extern uint8_t TD_100MS_SP;
extern uint8_t TD_1000MS_SP;
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
void updataNvram(void);//����NVRAM->EPROM
void clearNvram(void);//���NVRAM����	
/*****************************************************************************/
#endif
