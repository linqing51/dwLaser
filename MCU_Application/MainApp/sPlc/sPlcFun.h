#ifndef __SPLCFUN_H__
#define __SPLCFUN_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
void REBOOT(void) reentrant;//ǿ�Ƹ�λ
//λָ��
void SET(uint16_t A) reentrant;//��Ȧ��λ
void RES(uint16_t A) reentrant;//��Ȧ��λ
void FLIP(uint16_t A) reentrant;//��ת
uint8_t LD(uint16_t A) reentrant;//����
uint8_t LDB(uint16_t A) reentrant;//��������
uint8_t LDP(uint16_t A) reentrant;//����������
uint8_t LDN(uint16_t A) reentrant;//�����½���
//��ʱ��ָ��
void T100MS(uint8_t A, uint8_t start, uint16_t value) reentrant;//100mS��ʱ������
#endif