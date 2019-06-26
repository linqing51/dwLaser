#ifndef __SPLCLASER_H__
#define __SPLCLASER_H__
/*****************************************************************************/
#include "sPlc.h"
/*****************************************************************************/
#define LASER_MODE_CW							0x1A50//����ģʽ
#define LASER_MODE_MP							0x3C72//������ģʽ
#define LASER_MODE_GP							0x4D83//Ⱥ����ģʽ
#define LASER_MODE_DERMA						0x5F43//
#define LASER_MODE_EVLA_SEGMENT					0x65A5//
#define LASER_MODE_EVLA_SIGNAL					0x2B61//������ģʽ

#define LASER_SELECT_CH0						0x005A
#define LASER_SELECT_CH1						0xA500
#define LASER_SELECT_BOTH						0xA55A
/*****************************************************************************/
void sPlcLaserInit(void);
void laserTimerIsr(void);//TIMER4 �ж� ���ⷢ��
void testBenchLaserTimer(uint8_t st);//LASER���ⷢ�����
void EDLAR(void) reentrant;//ֹͣ��������
void STLAR(void) reentrant;//��ʼ��������
#endif