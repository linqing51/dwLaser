#ifndef __BACKGROUNDAPP_H__
#define __BACKGROUNDAPP_H__
/*****************************************************************************/
#include "sPlc.h"
#include "appSplcAdr.h"
/*****************************************************************************/
void loadScheme(void);//DM->EM
void saveScheme(void);//EM->DM
void defaultScheme(void);//�ָ�Ĭ������
void backgroundAppInit(void);
void backgroundApp(void);
void PCLAR0(uint16_t POW, uint16_t CUR) reentrant;//����->DAC CODE
void PCLAR1(uint16_t POW, uint16_t CUR) reentrant;//����->DAC CODE
#endif