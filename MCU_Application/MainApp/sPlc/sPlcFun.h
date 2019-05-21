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
void ADD(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant;//16λ�Ǳ��ͼӷ� D = Sa + Sb
void ADDS(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant;//16λ������� D = Sa + Sb
void DADD(int32_t *Sa, int32_t *Sb, int32_t *D) reentrant;//32λ�Ǳ��ӷ� D = Sa + Sb
void SUB(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant;//16λ�Ǳ��ͼ���
void SUBS(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant;//16λ���ͼ���
void DSUB(int32_t *Sa, int32_t *Sb, int32_t *D) reentrant;//32λ�Ǳ��ͼ���
void MULT(int16_t *Sa, int16_t *Sb, int32_t *D) reentrant;//16*16�Ǳ��ͳ˷� D = Sa * Sb
void MULTS(int16_t *Sa, int16_t *Sb, int32_t *D) reentrant;//16*16->32���ͳ˷� D = Sa * Sb
/*****************************************************************************/
int16_t MAX(int16_t *s, uint8_t len) reentrant;//�ҳ�����Ϊlen������s�е����ֵ
int16_t MIN(int16_t *s, uint8_t len) reentrant;//�ҳ�����Ϊlen������s�е���Сֵ
#endif