#ifndef __SOFTPLC_H__
#define __SOFTPLC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
typedef struct
{//�����ʱ���ṹ��
	int16_t value;//��ʱ����ʱֵ
	int16_t mate;//��ʱ��ƥ��ֵ
	int8_t enable;//��ʱ��ʹ��
	int8_t output;//��ʱ�����
}softPlcTimer_t;

typedef struct
{//�������PLC����
	uint16_t X_Input0[CONFIG_PLC_X_NUM / 16 + 1];//����˿� 
	uint16_t X_Input1[CONFIG_PLC_X_NUM / 16 + 1];//����˿� 
	//M�����Ĵ���
	uint16_t M_Coil[CONFIG_PLC_M_NUM / 16 + 1];//�����Ĵ���
	uint16_t X_Coil[CONFIG_PLC_X_NUM / 16 + 1];//����Ĵ���
	uint16_t Y_Coil[CONFIG_PLC_Y_NUM / 16 + 1];//����Ĵ���
	//D�Ĵ���
	uint16_t D_Reg[CONFIG_PLC_D_NUM];//D�Ĵ���
	softPlcTimer_t T_1ms[CONFIG_PLC_TIMER_1MS_NUM];
	softPlcTimer_t T_10ms[CONFIG_PLC_TIMER_10MS_NUM];
	softPlcTimer_t T_100ms[CONFIG_PLC_TIMER_100MS_NUM];
	softPlcTimer_t T_1000ms[CONFIG_PLC_TIMER_1000MS_NUM];
	int16_t counter_1ms;
	int16_t counter_10ms;
	int16_t counter_100ms;
}softPlc_t;

extern softPlc_t softPlc;
/*****************************************************************************/
void SoftPlc_Init(softPlc_t *pt);
void Timer0_Init(void);
void set_Coil(uint16_t addr, uint16_t *coil);
void reset_Coil(uint16_t addr, uint16_t *coil);
void flip_Coil(uint16_t addr, uint16_t *coil);
void inputFilter(softPlc_t *plc);
void outputRefush(softPlc_t *plc);

void stopTimer(softPlcTimer_t *pt);
void startTimer(softPlcTimer_t *pt, int16_t value);
#endif