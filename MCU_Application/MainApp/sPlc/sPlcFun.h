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
void T100US(uint8_t A, uint8_t start, uint16_t value) reentrant;//100uS��ʱ������
void T1MS(uint8_t A, uint8_t start, uint16_t value) reentrant;//1mS��ʱ������
void T10MS(uint8_t A, uint8_t start, uint16_t value) reentrant;//10mS��ʱ������
void T100MS(uint8_t A, uint8_t start, uint16_t value) reentrant;//100mS��ʱ������
//����ָ��
/*****************************************************************************/
int16_t MAX(int16_t *s, uint8_t len) reentrant;//�ҳ�����Ϊlen������s�е����ֵ
int16_t MIN(int16_t *s, uint8_t len) reentrant;//�ҳ�����Ϊlen������s�е���Сֵ
#endif