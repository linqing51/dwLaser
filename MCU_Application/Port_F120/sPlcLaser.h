#ifndef __SPLCLASER_H__
#define __SPLCLASER_H__
/*****************************************************************************/
#include "sPlc.h"
/*****************************************************************************/
#define MCP47X6_LASER_CHANNEL_CH1					0
#define MCP47X6_LASER_CHANNEL_CH2					1
#define LASER_MODE_CW								0//����ģʽ
#define LASER_MODE_SP								1//������ģʽ
#define LASER_MODE_MP								2//������ģʽ
#define LASER_MODE_GP								3//Ⱥ����ģʽ

////R ��Ȧ����
//#define R_MCU_RESET									(R_START * 16 + 0)//MCU��λ����
//#define R_MCU_ERROR_CLEAR							(R_START * 16 + 1)//MCU�������
//#define R_LASER_START								(R_START * 16 + 2)//���ⷢ�䰴��
//#define R_LASER_STOP								(R_START * 16 + 3)//����ֹͣ����
//#define R_LASER_READY								(R_START * 16 + 4)//׼������
//#define R_LASER_SELECT_CH1							(R_START * 16 + 5)//����ѡ��CH1����
//#define R_LASER_SELECT_CH2							(R_START * 16 + 6)//����ѡ��CH2����
//#define R_LASER_SELECT_BOTH							(R_START * 16 + 7)//������תCH1+CH2����
//#define R_INFO_RESET								(R_START * 16 + 8)//���ⷢ����Ϣ��λ����
//#define R_PARA_SAVE									(R_START * 16 + 9)//�������水��
//#define R_LASER_MODE_CW								(R_START * 16 + 10)//����ģʽ��������
//#define R_LASER_MODE_PULSE							(R_START * 16 + 11)//����ģʽ������������
//#define R_LASER_MODE_GP								(R_START * 16 + 12)//����ģʽ�ɱ�����尴��
//#define R_LASER_ERROR_CLEAR							(R_START * 16 + 13)//����������
//#define R_FLAG_COOLING								(R_START * 16 + 13)//��ȴָʾ
//#define R_FLAG_LASER_EMITING						(R_START * 16 + 14)//���ⷢ��ָʾ
//#define R_FLAG_LASER_EMITOVER						(R_START * 16 + 15)//���ⷢ�����
//#define R_FLAG_LASER_TIGGER							(R_START * 16 + 16)//���ⷢ�䴥��
//#define R_FLAG_READY								(R_START * 16 + 17)//׼��״̬
//#define R_FLAG_STANDBY								(R_START * 16 + 18)//����״̬
//#define	R_FLAG_FIBER_MECH_DETECT					(R_START * 16 + 19)//���˻�е������
//#define R_FLAG_FIBER_MECH_DETECT_IGNORE 			(R_START * 16 + 20)//���˻�е����������
//#define R_FLAG_FIBER_NFC_DETECT						(R_START * 16 + 20)//����NFC������
//#define R_FLAG_FIBER_NFC_DETECT_IGNORE				(R_START * 16 + 21)//����NFC����������
//#define R_FLAG_OPENCASE_DETECT						(R_START * 16 + 21)//������
//#define R_FLAG_FOOTSWITCH							(R_START * 16 + 22)//��̤״̬
//#define R_FLAG_WIRE_FOOTSWITCH						(R_START * 16 + 23)//���߽�̤״̬
//#define R_FLAG_WIRELESS_FOOTSWITCH					(R_START * 16 + 24)//���߽�̤״̬
//#define R_FLAG_MCU_HEART							(R_START * 16 + 25)//MCU����
//#define R_FLAG_BEEM									(R_START * 16 + 26)//������״̬
//#define R_FLAG_SAFE_FAULT							(R_START * 16 + 27)//��ȫ����
//#define R_FLAG_TEMP_FAULT							(R_START * 16 + 28)//�¶ȹ���
//#define R_FLAG_DRIVER_LTEMP_FAULT					(R_START * 16 + 29)
//#define R_FLAG_DRIVER_HTEMP_FAULT					(R_START * 16 + 30)
//#define R_FLAG_DRIVER_TEMP_FAULT_IGNORE				(R_START * 16 + 30)
//#define R_FLAG_MCHIP_LTEMP_FAULT					(R_START * 16 + 31)
//#define R_FLAG_MCHIP_HTEMP_FAULT					(R_START * 16 + 32)
//#define R_FLAG_MCHIP_TEMP_FAULT_IGNORE				(R_START * 16 + 30)
//#define R_FLAG_LASER_LTEMP_FAULT					(R_START * 16 + 33)
//#define R_FLAG_LASER_HTEMP_FAULT					(R_START * 16 + 34)
//#define R_FLAG_LASER_TEMP_FAULT_IGNORE				(R_START * 16 + 30)
////MR ��Ȧ����
//#define MR_FIBER_MECH_DETECT_IGNORE					(MR_START + 0)//����̽���е����
//#define MR_FIBER_NFC_DETCET_IGNORE					(MR_START + 1)//����̽��NFC����
//#define MR_OPENCASE_DETECT_IGNORE					(MR_START + 2)//���������
//#define MR_AIM_ENABLE								(MR_START + 3)//ָʾ����ʹ��							
//#define MR_BEEM_ENABLE								(MR_START + 4)//������ʹ��
////EM �Ĵ�������
//#define EM_MCU_CHECKCODE							(EM_START + 0)//MCUУ����
//#define EM_MCU_HW_VER								(EM_START + 1)//MCUӲ���汾
//#define EM_MCU_FW_VER								(EM_START + 2)//MCU����汾
//#define EM_STEP_NUM									(EM_START + 3)//���ⷢ�䲽�����

//#define EM_LASER_NAME								(EM_START + 10)//�������� 16��
//#define EM_LASER_POSWIDTH							(EM_START + 16)//����������
//#define EM_LASER_NEGWIDTH							(EM_START + 17)//���⸺����
//#define EM_LASER_GROUP_SPACE						(EM_START + 18)//������//����Ⱥ������
//#define EM_LASER_GROUP_NUM							(EM_START + 19)//����������//����Ⱥ�������
//#define EM_LASER_POWER_CH1							(EM_START + 20)//����ͨ��1��������
//#define EM_LASER_POWER_CH2							(EM_START + 21)//����ͨ��2��������

//#define EM_LASER_POWER_TOTAL						(EM_START + 22)//�����ܹ�����ʾ
//#define EM_LASER_POWER_RATIO						(EM_START + 23)//���⹦�ʱ�����ʾ
//#define EM_LASER_RELEASE_ENERY						(EM_START + 18)//���ⷢ��������ʾ
//#define EM_LASER_RELEASE_TIME						(EM_START + 19)//���ⷢ��ʱ����ʾ
//#define EM_LASER_CURRENT_CH1						(EM_START + 15)//����������0
//#define EM_LASER_CURRENT_CH2						(EM_START + 16)//����������1
//#define EM_LASER_PD_CH1								(EM_START + 17)//����������0
//#define EM_LASER_PD_CH2								(EM_START + 18)//����������1
//#define EM_LASER_MODE								(EM_START + 19)//���ⷢ��ģʽ
//#define EM_LASER_SELECT_CHANNLE						(EM_START + 20)//����ͨ��ѡ��


//#define EM_LASER_TEMPERATURE						(EM_START + 21)//�������¶�
//#define EM_LASER_TMATE								(EM_START + 22)//��ʱ��ƥ��ֵ
//#define EM_LASER_PMATE								(EM_START + 23)//�������ƥ��ֵ
//#define EM_LASER_SMATE								(EM_START + 24)//����������ֵ
//#define EM_LASER_TOVERFLOW							(EM_START + 25)//��ʱ�����ֵ
//#define EM_LASER_TCOUNTER							(EM_START + 26)//��ʱ������ֵ
//#define EM_LASER_PCOUNTER							(EM_START + 27)//�����������ֵ
//#define EM_LASER_SCOUNTER							(EM_START + 28)//����������ֵ
//#define EM_FAN_GET_SPEED_0							(EM_START + 29)//����0ת�ٶ�ȡ
//#define EM_FAN_GET_SPEED_1							(EM_START + 30)//����1ת�ٶ�ȡ
//#define EM_FAN_GET_SPEED_2							(EM_START + 31)//����2ת�ٶ�ȡ
//#define EM_DRIVER_TEMPERATURE						(EM_START + 32)//�������¶�
//#define EM_MCHIP_TEMPERATURE						(EM_START + 33)//�忨�¶�
////DM �Ĵ�������
//#define DM_SCHEME_NAME								(DM_START + 0)
//#define DM_
//#define DM_PID_REF_TEMP								(DM_START + 0)//��ȴ�¶��趨
//#define DM_PID_ON_TIME								(DM_START + 1)//PID�����ͨʱ��
//#define DM_PID_OFF_TIME								(DM_START + 2)//PID����ر�ʱ��
//#define DM_PID_COEF_KP								(DM_START + 3)//PIDϵ������KP
//#define DM_PID_COEF_TI								(DM_START + 4)//PIDϵ������ʱ��TI
//#define DM_PID_COEF_TD								(DM_START + 5)//PIDϵ��΢��ʱ��TD
//#define DM_FAN_SET_SPEED_0							(DM_START + 6)//����0ת������
//#define DM_FAN_SET_SPEED_1							(DM_START + 7)//����1ת������
//#define DM_FAN_SET_SPEED_2							(DM_START + 8)//����2ת������
//#define DM_SET_AIM_BRIGHT							(DM_START + 9)//ָʾ��������
//#define DM_SET_BEEM_VOLUME							(DM_START + 10)//����������
//#define DM_SET_LCD_BRIGHT							(DM_START + 11)//Һ��������
//#define DM_LASER_PROTECT_HTEMP						(DM_START + 12)//���������±���
//#define DM_LASER_PROTCET_LTEMP						(DM_START + 13)//���������±���
//#define DM_DRIVE_PROTECT_HTEMP						(DM_START + 14)//���������±���
//#define DM_DRIVE_PROTECT_LTEMP						(DM_START + 15)//���������±���
//#define DM_MCHIP_PROTECT_HTEMP						(DM_START + 16)//оƬ���±���
//#define DM_MCHIP_PROTECT_LTEMP						(DM_START + 17)//оƬ���±���
///*****************************************************************************/
//#define X_FOOTSWITCH								(X_START * 16 + 0)
//#define X_OPENCASE_DETECT							(X_START * 16 + 1)
//#define X_INTERLOCK									(X_START * 16 + 2)
//#define X_MECH_FIBER_DETECT							(X_START * 16 + 2)
void sPlcLaser(void);//
#endif