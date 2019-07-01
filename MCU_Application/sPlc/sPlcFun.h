#ifndef __SPLCFUN_H__
#define __SPLCFUN_H__
/*****************************************************************************/
#include "sPlc.h"
/*****************************************************************************/
void REBOOT(void) reentrant;//��λ
//λָ��
void SET(uint16_t A) reentrant;//��Ȧ��λ
void RES(uint16_t A) reentrant;//��Ȧ��λ
void FLIP(uint16_t A) reentrant;//��ת
uint8_t LD(uint16_t A) reentrant;//����
uint8_t LDB(uint16_t A) reentrant;//��������
uint8_t LDP(uint16_t A) reentrant;//����������
uint8_t LDN(uint16_t A) reentrant;//�����½���
//��ʱ��ָ��
//void T100US(uint8_t A, uint8_t start, uint16_t value);//100uS��ʱ������
void T1MS(uint8_t A, uint8_t start, uint16_t value) reentrant;//1mS��ʱ������
void T10MS(uint8_t A, uint8_t start, uint16_t value) reentrant;//10mS��ʱ������
void T100MS(uint8_t A, uint8_t start, uint16_t value) reentrant;//100mS��ʱ������
//����ָ��
void CLR(uint16_t A) reentrant;//�Ĵ�������
void CLRD(uint16_t A) reentrant;//32λ�Ĵ�������
void MOV(uint16_t dist, uint16_t src) reentrant;//16λ�Ĵ�������
void MOVD(uint16_t dist, uint16_t src) reentrant;//32λ�Ĵ�������
void SWAP(uint16_t dist, uint16_t src) reentrant;//����A�ĸߵ��ֽ�
void ABS16(uint16_t dist, uint16_t src) reentrant;//16λ�������ֵ
void ABS32(uint16_t dist, uint16_t src) reentrant;//32λ�������ֵ
void SMIN16(uint16_t index, uint16_t length, uint16_t min) reentrant;//16λ�з�����������Сֵ
void SMAX16(uint16_t index, uint16_t length, uint16_t max) reentrant;//16λ�з������������ֵ
void UMIN16(uint16_t index, uint16_t length, uint16_t min) reentrant;//16λ�޷�����������Сֵ
void UMAX16(uint16_t index, uint16_t length, uint16_t max) reentrant;//16λ�޷������������ֵ
void SUM16(uint16_t index, uint16_t length, uint16_t sum) reentrant;//16BIT�����->32BIT
void MULT32(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant;//16*16->32�Ǳ��ͳ˷� D = Sa * Sb
void MULTS16(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant;//16*16->16���ͳ˷� D = Sa * Sb
void MULT16(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant;//16*16->16�Ǳ��ͳ˷� D = Sa * Sb
void SUB32(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant;//32λ�Ǳ��ͼ��� D = Sa - Sb
void SUBS16(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant;//16λ���ͼ��� D = Sa - Sb
void SUB16(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant;//16λ�Ǳ��ͼ��� D = Sa - Sb
void ADD32(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant;//32λ�Ǳ��ӷ� D = Sa + Sb
void ADDS32(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant;//32λ���ͼӷ� D = Sa + Sb
void ADDS16(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant;//16λ���ͼӷ� D = Sa + Sb
void ADD16(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant;//16λ�Ǳ��ͼӷ� D = Sa + Sb
void ADD1(uint16_t Sa) reentrant;//16λ�Ǳ����Լ�
void ADDS1(uint16_t Sa) reentrant;//16λ�����Լ�
void DEC1(uint16_t Sa) reentrant;//16λ�Ǳ����Լ�
void DECS1(uint16_t Sa) reentrant;//16λ�����Լ�
void ADL1(uint16_t Sa) reentrant;//32λ�Ǳ����Լ�
void ADLS1(uint16_t Sa) reentrant;//32λ�����Լ�
void DEL1(uint16_t Sa) reentrant;//32λ�Ǳ����Լ�
void DELS1(uint16_t Sa) reentrant;//32λ�����Լ�
void TNTC(uint16_t dist, uint16_t src) reentrant;//CODEת��Ϊ�����¶�
void TENV(uint16_t dist, uint16_t src) reentrant;//CODEת��ΪNTC�����¶��¶�
void BCPY(uint16_t dist, uint16_t src, uint16_t length) reentrant;//�鸴��
/*****************************************************************************/
//void XTAB(int16_t *distY, int16_t *srcX, int16_t *index, int16_t *length) reentrant;//���Բ���X����Yֵ
//void YTAB(int16_t *distX, int16_t *srcY, int16_t *index, int16_t *length) reentrant;//���Բ���Y����Xֵ
/*****************************************************************************/
void IMDIO(void) reentrant;//��������IO��״̬���������
void TPCTL(int16_t *ref, int16_t *fb, int16_t buf) reentrant;//�¿�PIDָ��
void HSPWM(int16_t *pos, int16_t *neg, int16_t pot) reentrant;//Ӳ��PWM���
/*****************************************************************************/
void FSAV(void);//ǿ����������NVRAM
#endif


