#ifndef __SPLCBEEM_H__
#define __SPLCBEEM_H__
/*****************************************************************************/
#define BEEM_MODE_0				0
#define BEEM_MODE_1				1
#define BEEM_MODE_2				2
/*****************************************************************************/
#include "sPlc.h"
/*****************************************************************************/
void sPlcBeemInit(void);//��������ʼ��
void sPlcBeemLoop(void);
void testBenchBeem(uint8_t volume, uint8_t mode);//����������
void EDBEEM(void);//ֹͣ������
void STBEEM(void);//��ʼ������

#endif