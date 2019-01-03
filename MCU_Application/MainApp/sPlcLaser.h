#ifndef __SPLCLASER_H__
#define __SPLCLASER_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
#define R_KEY_MCU_RESET								0//MCU��λ����
#define R_KEY_MCU_ERROR_CLEAR						1//MCU�������
#define R_KEY_LASER_START							2//���ⷢ�䰴��
#define R_KEY_LASER_STOP							3//����ֹͣ����
#define R_KEY_LASER_READY							4//׼������
#define R_KEY_LASER_SELECT_CH1						5//����ѡ��CH1����
#define R_KEY_LASER_SELECT_CH2						6//����ѡ��CH2����
#define R_KEY_LASER_SELECT_BOTH						7//������תCH1+CH2����
#define R_KEY_INFO_RESET							8//���ⷢ����Ϣ��λ����
#define R_KEY_PARA_SAVE								9//�������水��
#define R_LASER_MODE_CW								10//����ģʽ��������
#define R_LASER_MODE_PULSE							11//����ģʽ������������
#define R_LASER_MODE_GP								12//����ģʽ�ɱ�����尴��
#define R_FLAG_COOLING								13//��ȴָʾ
#define R_FLAG_LASER_EMITING						14//���ⷢ��ָʾ
#define R_FLAG_LASER_EMIT_OVER						15//���ⷢ�����
#define R_FLAG_LASER_TIGGER							16//���ⷢ�䴥��
#define R_FLAG_READY								17//׼��״̬
#define R_FLAG_STANDBY								18//����״̬
#define	R_FLAG_FIBER_MECH_DETECT					19//���˻�е������
#define R_FLAG_FIBER_NFC_DETECT						20//����NFC������
#define R_FLAG_OPENCASE_DETECT						21//������
#define R_FLAG_WIRE_FOOTSWITCH						22//���߽�̤״̬
#define R_FLAG_WIRELESS_FOOTSWITCH					23//���߽�̤״̬
#define R_FLAG_MCU_HEART							24//MCU����
#define R_FLAG_BEEM									25//������״̬

#define MR_FIBER_MECH_DETECT_IGNORE					0//����̽���е����
#define MR_FIBER_NFC_DETCET_IGNORE					1//����̽��NFC����
#define MR_OPENCASE_DETECT_IGNORE					2//���������
#define MR_AIM_ENABLE								3//ָʾ����ʹ��							
#define MR_BEEM_ENABLE								4//������ʹ��

#define EM_MCU_CHECKSUM//MCUУ����
#define EM_MCU_HW_VER//MCUӲ���汾
#define EM_MCU_FW_VER//MCU����汾
#define EM_STEP_NUM//���ⷢ�䲽�����
#define EM_TEXTBOX_LASER_POSWIDTH//����������
#define EM_TEXTBOX_LASER_NEGWIDTH//���⸺����
#define EM_TEXTBOX_LASER_GROUP_SPACE//������//����Ⱥ������
#define EM_TEXTBOX_LASER_GROUP_NUM//����������//����Ⱥ�������
#define EM_TEXTBOX_LASER_POWER_CH1//����ͨ��1��������
#define EM_TEXTBOX_LASER_POWER_CH2//����ͨ��2��������
#define EM_TEXTBOX_LASER_TOTAL_POWER//�����ܹ�����ʾ
#define EM_TEXTBOX_LASER_RATIO_POWER//���⹦�ʱ�����ʾ
#define EM_TEXTBOX_LASER_RELEASE_ENERY//���ⷢ��������ʾ
#define EM_TEXTBOX_LASER_RELEASE_TIME//���ⷢ��ʱ����ʾ
#define EM_LASER_CURRENT_CH1			//����������0
#define EM_LASER_CURRENT_CH2			1//����������1
#define EM_LASER_PD_CH1				2//����������0
#define EM_LASER_PD_CH2				3//����������1
#define EM_LASER_MODE				4//���ⷢ��ģʽ
#define EM_LASER_SELECT_CHANNLE//����ͨ��ѡ��
#define EM_LASER_TEMPERATURE//�������¶�
#define EM_DRIVER_TEMPERATURE//�������¶�
#define EM_MCHIP_TEMPERATURE//�忨�¶�
#define EM_FAN_GET_SPEED_0//����0ת�ٶ�ȡ
#define EM_FAN_GET_SPEED_1//����1ת�ٶ�ȡ
#define EM_FAN_GET_SPEED_2//����2ת�ٶ�ȡ

#define DM_PID_REF_TEMP//��ȴ�¶��趨
#define DM_PID_ON_TIME//PID�����ͨʱ��
#define DM_PID_OFF_TIME//PID����ر�ʱ��
#define DM_PID_COEF_KP//PIDϵ������KP
#define DM_PID_COEF_TI//PIDϵ������ʱ��TI
#define DM_PID_COEF_TD//PIDϵ��΢��ʱ��TD
#define DM_FAN_SET_SPEED_0//����0ת������
#define DM_FAN_SET_SPEED_1//����1ת������
#define DM_FAN_SET_SPEED_2//����2ת������
#define DM_SET_AIM_BRIGHT//ָʾ��������
#define DM_SET_BEEM_VOLUME//����������
#define DM_SET_LCD_BRIGHT//Һ��������
#define DM_LASER_PROTECT_HTEMP//���������±���
#define DM_LASER_PROTCET_LTEMP//���������±���
#define DM_DRIVE_PROTECT_HTEMP_//���������±���
#define DM_DRIVE_PROTECT_LTEMP//���������±���
#define DM_MCHIP_PROTECT_HTEMP//оƬ���±���
#define DM_MCHIP_PROTECT_LTEMP//оƬ���±���

#endif