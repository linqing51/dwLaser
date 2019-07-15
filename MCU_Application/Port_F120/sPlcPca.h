#ifndef __SPLCBEEM_H__
#define __SPLCBEEM_H__
/*****************************************************************************/
#define BEEM_MODE_0											0//����ģʽ
#define BEEM_MODE_1											1//����ͬ��
#define BEEM_MODE_2											2//���ⷢ��̶����
#define BEEM_MODE_3											3//�쳣����
#define BEEM_FREQ_0											0xEE//����Ƶ��
#define BEEM_FREQ_1											0xFA
#define BEEM_FREQ_2											0xFC
#define BEEM_FREQ_3											0xFF
#define BEEM_VOLUME_0										0xFF
#define BEEM_VOLUME_1										0xFC
#define BEEM_VOLUME_2										0xFA
#define BEEM_VOLUME_3										0xF2
#define BEEM_VOLUME_4										0xE2
#define BEEM_VOLUME_5										0xB0
#define BEEM_VOLUME_6										0x90
#define BEEM_VOLUME_7										0x80
#define BEEM_VOLUME_8										0x60
#define BEEM_VOLUME_9										0x40
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
void sPlcPcaInit(void);//��ʱ�����г�ʼ��
void sPlcAimInit(void);//��������ʼ��
void sPlcAimLoop(void);
void sPlcBeemInit(void);//��������ʼ��
void sPlcBeemLoop(void);
#endif