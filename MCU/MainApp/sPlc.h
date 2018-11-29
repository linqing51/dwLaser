#ifndef __SOFTPLC_H__
#define __SOFTPLC_H__
/*****************************************************************************/
#include "appConfig.h"
//���ݼĴ��� ���� 256����
#define DM_START						0//���籣�ּĴ���
#define DM_END							255
//��Ȧ ���� 128 * 16 = 2048��
#define MR_START						256//��Ȧ�Ĵ���
#define	MR_END							383
//���ݼĴ��� �Ǳ��� 128����
#define EM_START						384//����Ĵ���
#define EM_END							511
//��Ȧ�Ĵ��� �Ǳ��� 64 * 16 = 1024��
#define R_START							512//���籣����Ȧ�Ĵ���
#define R_END							575
//��ʱ��Ȧ
#define T_100US_START					576
#define T_100US_END						579
#define T_1MS_START						580
#define T_1MS_END						583
#define T_10MS_START					584
#define T_10MS_END						587
#define T_100MS_START					588	
#define T_100MS_END						591
//��ʱ��ʱ�� 
#define TD_100US_START					592//64��100uS
#define TD_100US_END					655
#define TD_1MS_START					656//64��1mS
#define TD_1MS_END						719
#define TD_10MS_START					720//64��10mS
#define TD_10MS_END						783
#define TD_100MS_START					784//64��100mS
#define TD_100MS_END					847
//������
#define C_START							848//64��������
#define C_END							911
//����λ�Ĵ��� 16 * 16 = 256��
#define X_START							912
#define X_END							927
//���λ�Ĵ��� 16 * 16 = 256��
#define Y_START							928
#define Y_END							944

#define CONFIG_NVRAM_SIZE 				(Y_END + 1)
/*****************************************************************************/
void Timer0_Init(void);
void nvram_updata(void);
void clear_dm(void);
void clear_em(void);
void clear_r(void);
void clear_t(void);
void clear_td(void);
void clear_c(void);
void nvram_load(void);
void nvram_save(void);
void nvram_updata(void);

void SET(uint16_t A);//��λ
void RESET(uint16_t A);//��λ
void FLIP(uint16_t A);//��ת
uint8_t LD(uint16_t A);//����
uint8_t LDP(uint16_t A);//����������
uint8_t LDN(uint16_t A);//�����½���
void T100US(uint8_t A, uint8_t start, uint16_t value);
void T1MS(uint8_t A, uint8_t start, uint16_t value);
void T10MS(uint8_t A, uint8_t start, uint16_t value);
void T100MS(uint8_t A, uint8_t start, uint16_t value);
#endif