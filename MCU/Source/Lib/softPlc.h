#ifndef __SOFTPLC_H__
#define __SOFTPLC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
#define SOFTPLC_X							1
#define SOFTPLC_Y							2
#define SOFTPLC_M							3
#define SOFTPLC_T							4
#define SOFTPLC_C							5
//MODBUS ��Ӧ��ַ ��Ȧ
#define SOFTPLC_MODBUS_X_START				1001
#define SOFTPLC_MODBUS_X_END				1256
#define SOFTPLC_MODBUS_Y_START				1
#define SOFTPLC_MODBUS_Y_END				256
#define SOFTPLC_MODBUS_M_START				2001
#define SOFTPLC_MODBUS_M_END				4002
#define SOFTPLC_MODBUS_T_START				9001
#define SOFTPLC_MODBUS_T_END				9256
//MODBUS ��Ӧ��ַ �Ĵ���

#define SOFTPLC_MODBUS_D_START				6001
#define SOFTPLC_MODBUS_D_END				8999
#define SOFTPLC_MODBUS_TD_START				9001
#define SOFTPLC_MODBUS_TD_END				9256

/*****************************************************************************/
typedef struct
{//�������PLC����
	uint16_t X[CONFIG_PLC_X_NUM / 16 + 1];//����Ĵ��� 
	uint16_t X1[CONFIG_PLC_X_NUM / 16 + 1];//����Ĵ����ϴν��
	uint16_t M[CONFIG_PLC_M_NUM / 16 + 1];//λ�Ĵ���
	uint16_t M1[CONFIG_PLC_M_NUM / 16 + 1];//λ�Ĵ����ϴν��
	uint16_t Y[CONFIG_PLC_Y_NUM / 16 + 1];//����Ĵ���
	uint16_t Y1[CONFIG_PLC_Y_NUM / 16 + 1];//����Ĵ����ϴν��
	uint16_t T[CONFIG_PLC_T_NUM / 16 + 1];//��ʱ���Ĵ���
	uint16_t T1[CONFIG_PLC_T_NUM / 16 + 1];//��ʱ���Ĵ���
	uint16_t T_EN[CONFIG_PLC_T_NUM / 16 + 1];//��ʱ��ʹ��
	uint16_t T_MATE[CONFIG_PLC_T_NUM];//��ʱ��ƥ��ֵ
	uint16_t T_VALUE[CONFIG_PLC_T_NUM];//��ʱ����ʱֵ
	
	uint16_t C[CONFIG_PLC_C_NUM / 16 + 1];//������
	uint16_t C1[CONFIG_PLC_C_NUM / 16 + 1];//�������ϴν��
	uint16_t C_VALUE[CONFIG_PLC_C_NUM];//������ֵ
	
	uint16_t D[CONFIG_PLC_D_NUM];//���ݱ��ּĴ���
	
}softPlc_t;


/*****************************************************************************/
extern softPlc_t softPlc;
/*****************************************************************************/
void SoftPlc_Init(softPlc_t *pt);//��ʼ��
//void startTimer(softPlcTimer_t *pt, int16_t value);//��ʼ������
//void stopTimer(softPlcTimer_t *pt);//ֹͣ��ʱ��
void getInput(softPlc_t *pt);
void setOutput(void);//ˢ�����
/*****************************************************************************/
//����ָ��
int8_t LD(uint8_t reg, uint16_t num);//
int8_t TB(int8_t en, int16_t num, int16_t value);
void OUT(uint8_t reg, uint16_t num, int8_t ena);
#endif