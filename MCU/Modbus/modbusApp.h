#ifndef __MODBUSAPP_H__
#define __MODBUSAPP_H__
#include "AppConfig.h"
/*****************************************************************************/

//code char *R_LASER_POSWIDTH				= "R03002";//�����������趨
//code char *R_LASER_NEGWIDTH 			= "R03003";//���⸺�����趨
//code char *R_LASER_GROUP_SPACE			= "R03004";//Ⱥ������
//code char *R_LASER_GROUP_NUM 			= "R03005";//Ⱥ�������
//code char *R_LASER_MODE					= "R03006";//����ģʽ
//code char *R_LASER_SELECT				= "R03007";//ͨ��ѡ��
//code char *R_SETCUR_CH1		 			= "R03198";//����ͨ��1�����趨
//code char *R_SETCUR_CH2 				= "R03199";//����ͨ��2�����趨
//code char *W_VERSION					= "R03200";//�忨�̼��汾
//code char *W_IPID_OUT					= "R03201";//IPID���ֵ	
//code char *W_LASER_T					= "R03202";//�������¶�	NTC0
//code char *W_RADIATOR_T	 				= "R03203";//ɢ�����¶�	NTC1
//code char *W_ENVI_T						= "R03204";//�忨�¶�	TMCU
//code char *W_PHOTODIODE_CH1				= "R03205";//PD1����ֵ	mV
//code char *W_PHOTODIODE_CH2				= "R03206";//PD2����ֵ  mV
////����D�Ĵ�����ַ
//code char *R_IPID_KP					= "D00002";//IPID ����KP ��������
//code char *R_IPID_TI					= "D00003";//IPID ����TI����ʱ��
//code char *R_IPID_TD					= "D00004";//IPID ����TD΢��ʱ��
//code char *R_IPID_TS					= "D00005";//IPID ����TS��������
//code char *R_IPID_REFT					= "D00005";//IPID ����Ŀ���¶�
//code char *R_FAN_V						= "D00006";//����ת���趨 0-4095
//code char *R_AIM_VOLTAGE				= "D00007";//ָʾ��������
//code char *R_BEEM_VOLUME				= "D00008";//����������
////����M�Ĵ�����ַ
//code char *W_FLAG_MCUHEART				= "M0001";//������PLC����
//code char *R_MCU_RESET					= "M0003";//PLC��λMCU
//code char *R_BEEM_ENABLE				= "M0004";//������ʹ��
//code char *W_FIBER_SENSOR_CH1			= "M0005";//������ͨ��0���˱���
//code char *W_FIBER_SENSOR_CH2			= "M0006";//������ͨ��1���˱���
//code char *W_COOL_ENABLE				= "M0029";//�������MCU
//code char *R_FLAG_LASER_START 			= "M0034";//���⿪ʼ�����־
//code char *W_FLAG_LASER_INDICATE		= "M0035";//���ⷢ����ϱ�־
//code char *R_LASER_READY				= "M0050";//׼��״̬

//typedef enum
//{//��ɢ����
//	
//}MODBUS_DISCRETE_INPUT;

//typedef enum
//{//���ּĴ���
//	D_LASER_POWER = 40000,//���⹦��
//	D_LASER_FREQ  = 40001,//����Ƶ��
//	D_LASER_ALARM = 40002,//����״̬
//}MODBUS_HOLD_REGISTER;

//typdef enum
//{
//	
//}MODBUS_INPUT_REGISTER;

//typedef enum
//{
//	M_LASER_AP = 0,//����Ŵ�������
//	M_LASER_MO = 1,//����������
//	M_LASER_AIM = 2,//ָʾ����
//	M_LASER_ESTOP = 3,//����ֹͣ
//	M_LASER_PRR	= 4//��������
//}MOSBUS_COIL;
#endif


