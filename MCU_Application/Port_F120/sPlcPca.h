#ifndef __SPLCBEEM_H__
#define __SPLCBEEM_H__
/*****************************************************************************/
#define BEEM_MODE_0									0//����ģʽ
#define BEEM_MODE_1							1//���ⷢ��̶����
#define BEEM_MODE_2								2//�쳣����
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
void sPlcPcaInit(void);//��ʱ�����г�ʼ��
void sPlcAimInit(void);//��������ʼ��
void sPlcAimLoop(void);
void sPlcBeemInit(void);//��������ʼ��
void sPlcBeemLoop(void);
void testBenchBeem(uint8_t volume, uint8_t mode);//����������
void testBenchAim(uint8_t port, uint8_t brightness);//ָʾ�����
#endif