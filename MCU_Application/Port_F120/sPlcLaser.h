#ifndef __SPLCLASER_H__
#define __SPLCLASER_H__
/*****************************************************************************/
#include "sPlc.h"
#include "appSplcAdr.h"
/*****************************************************************************/
#define LASER_MODE_CW							0x0001//����ģʽ
#define LASER_MODE_SP							0x0002//������ģʽ
#define LASER_MODE_MP							0x0004//������ģʽ
#define LASER_MODE_GP							0x0008//Ⱥ����ģʽ
#define LASER_MODE_DERMA						0x0010//
#define LASER_MODE_SIGNAL						0x0020//������ģʽ
#define LASER_SELECT_CH0						0x0001
#define LASER_SELECT_CH1						0x0002
#define LASER_SELECT_BOTH						0x0004
/*****************************************************************************/
void sPlcLaserInit(void);
void laserTimerIsr(void);//TIMER4 �ж� ���ⷢ��
void testBenchLaserTimer(uint8_t st);//LASER���ⷢ�����
void EDLAR(void)reentrant;//ֹͣ��������
void STLAR(void);//��ʼ��������
#endif