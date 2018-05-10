#ifndef __SOFTPLC_H__
#define __SOFTPLC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
#define	M500			500
#define M501			501
/*****************************************************************************/
typedef struct
{//�����ʱ���ṹ��	
	int16_t value;//��ʱ����ʱֵ
	int16_t mate;//��ʱ��ƥ��ֵ
	int16_t enable;//��ʱ��ʹ��
	int16_t output;//��ʱ�����
}softPlcTimer_t;

typedef struct
{//�������PLC����
	uint16_t X[CONFIG_PLC_X_NUM / 16 + 1];//����Ĵ��� 
	uint16_t M[CONFIG_PLC_M_NUM / 16 + 1];//�Ǳ��ָ����Ĵ���
	uint16_t N[CONFIG_PLC_N_NUM / 16 + 1];//���籣�ּĴ���
	uint16_t Y[CONFIG_PLC_Y_NUM / 16 + 1];//����Ĵ���
	uint16_t D[CONFIG_PLC_D_NUM];//���ּĴ���
	uint16_t R[CONFIG_PLC_R_NUM];//�Ǳ��ּĴ���
	uint16_t C[CONFIG_PLC_C_NUM];//������
	softPlcTimer_t T_1ms[CONFIG_PLC_T_1MS_NUM];
	softPlcTimer_t T_10ms[CONFIG_PLC_T_10MS_NUM];
	softPlcTimer_t T_100ms[CONFIG_PLC_T_100MS_NUM];
	softPlcTimer_t T_1000ms[CONFIG_PLC_T_1000MS_NUM];
	int16_t counter_1ms;
	int16_t counter_10ms;//�����ʱ����Ƶ 10mS
	int16_t counter_100ms;//�����ʱ����Ƶ 100mS
	int16_t counter_1000ms;//
}softPlc_t;
/*****************************************************************************/
extern softPlc_t softPlc;
/*****************************************************************************/
void SoftPlc_Init(softPlc_t *pt);//��ʼ��
void startTimer(softPlcTimer_t *pt, int16_t value);//��ʼ������
void stopTimer(softPlcTimer_t *pt);//ֹͣ��ʱ��
void getInput(void);//ˢ������
void setOutput(void);//ˢ�����
//λ�Ĵ�������
uint8_t getCoil(uint16_t *coil, uint16_t addr);
void setCoil(uint16_t *coil, uint16_t addr);
void resetCoil(uint16_t *coil, uint16_t addr);
void flipCoil(uint16_t *coil, uint16_t addr);

#endif