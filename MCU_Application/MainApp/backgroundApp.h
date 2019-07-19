#ifndef __BACKGROUNDAPP_H__
#define __BACKGROUNDAPP_H__
/*****************************************************************************/
#include "sPlc.h"
#include "appSplcAdr.h"
/*****************************************************************************/
uint8_t getBeemDuty(int16_t volume);
void loadScheme(void);//DM->EM
void saveScheme(void);//EM->DM
void checkScheme(void);//�������
void reloadCorrTab(void);//�ָ�����У������
void defaultScheme(void);//�ָ�Ĭ������
void loadDefault(void);
void PCLAR0(uint16_t POW, uint16_t CUR) reentrant;//����->DAC CODE
void PCLAR1(uint16_t POW, uint16_t CUR) reentrant;//����->DAC CODE
#endif