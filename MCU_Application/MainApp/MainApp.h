#ifndef __MAINAPP_H__
#define __MAINAPP_H__
//IO����uint8_t ��ʾ ���λ��ʾ��ǰ״̬ ���λ��ʾ7��ǰ״̬ ����λ����
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
//typedef struct
//{//���ʱ���ṹ��
//	uint16_t tMate;//��ʱ��ƥ��ֵ
//	uint16_t tOverflow;//��ʱ�����ֵ
//	uint16_t tCounter;//��ʱ������ֵ

//	uint16_t pMate;//�������ƥ��ֵ
//	uint16_t sMate;//����������ֵ
//	uint16_t pCounter;//�����������ֵ
//	uint16_t sCounter;//����������ֵ
//}laserTimer_t;


//#define DM_LASER_CURRENT_0			0//����������0
//#define DM_LASER_CURRENT_1			1//����������1
//#define DM_PHOTODIODE_0				2//����������0
//#define DM_PHOTODIODE_1				3//����������1
//#define DM_LASER_MODE				4//���ⷢ��ģʽ
//#define DM_LASER_POSWIDTH			5//��������������
//#define DM_LASER_NEGWIDTH			6//��������������
//#define DM_LASER_GROUP_NUM			7//����Ⱥ�������
//#define DM_LASER_GROUP_SPACE		8//����Ⱥ������
//#define DM_LASER_SELECT_CHANNEL		9//����ͨ��ѡ��


//#define DM_LASER_HTEMP//���������±���
//#define DM_LASER_LTEMP//���������±���
//#define DM_DRIVER_HTEMP//���������±���
//#define DM_DRIVER_LTEMP//���������±���
//#define DM_CHIP_HTEMP//оƬ���±���
//#define DM_CHIP_LTEMP//оƬ���±���
//#define DM_ENVI_HTEMP//�����¶ȸ��±���
//#define DM_EMVI_LTEMP//�����¶ȵ��±���

//#define EM_FAN_SET_SPEED_0//����0ת������
//#define EM_FAN_SET_SPEED_1//����1ת������
//#define EM_FAN_SET_SPEED_2//����2ת������
//#define EM_FAN_GET_SPEED_0//����0ת�ٶ�ȡ
//#define EM_FAN_GET_SPEED_1//����1ת�ٶ�ȡ
//#define EM_FAN_GET_SPEED_2//����2ת�ٶ�ȡ
//#define EM_EDAC0//��չDAC0���ֵ
//#define EM_EDAC1//��չDAC1���ֵ
//#define EM_EDAC2//��չDAC2���ֵ
//#define EM_EDAC3//��չDAC3���ֵ
//#define EM_CDAC0//����DAC0���ֵ
//#define EM_CDAC1//����DAC1���ֵ
//#define EM_CADC0//����ADC0����ֵ
//#define EM_CADC1//����ADC1����ֵ
//#define EM_CADC2//����ADC2����ֵ
//#define EM_CADC3//����ADC3����ֵ
//#define EM_CTEMP//�����¶�ֵ
//#define XR_0
//#define XR_1
//#define XR_2
//#define XR_3
//#define XR_4
//#define XR_5
//#define XR_6
//#define XR_7
//#define YR_0
//#define YR_1

//typedef struct
//{//ȫ���豸�ṹ��
//	//
//	laserTimer_t laserTimer;//�����ʱ��

//	//��ȫ״̬
//	uint8_t safeFault;//��ȫ����
//	uint8_t safeFaultIgnore;//��ȫ���Ϻ���
//	uint8_t safeInterlock;//��ȫ����
//	uint8_t safeInterlockIgnore;//��ȫ��������
//	uint8_t safeFiberDetect0;//���˼��ͨ��0
//	uint8_t safeFiberDetect0Ignore;//���˼��ͨ��0����
//	uint8_t safeFiberDetect1;//���˼��ͨ��1
//	uint8_t safeFiberDetect1Ignore;//���˼��ͨ��1����
//	uint8_t safeOpenCase;//������
//	uint8_t safeOpenCaseIgnore;//���������
//	//
//	uint8_t footSwitch;//��̤���س���
//	
//	//ģ��PID����
//	fp32_t pidOut;//IPID���ֵ
//	int16_t onTimerPid;//pid��� ����ʱ��  
//	int16_t offTimerPid;//pid��� �ر�ʱ��
//	
//	//int8_t  FlagStart;//���䴥��
//	//int8_t	FlagReady;//׼����־
//	//int8_t	FiberSensor[2];//���˼��
//	//int8_t	FlagIndicate;//���ⷢ���־
//	//int8_t	BeemEnabled;//������ʹ��
//	//int8_t	AimEnable;//ָʾ����ʹ��
//	//int8_t	CoolEnable;//�������ʹ��
//	
//	//int8_t laserTrigger;//���ⷢ�䴥��
//	//int8_t laserEmiting;//���ⷢ���б�־
//	//int8_t laserEmitOver;//���ⷢ�����	
//	//int16_t checkCode;//HMI����У���� ��8λУ���� ��8λ�汾
//	//int8_t heartFlag;//������־
//	//int8_t mcuReset;//��Ƭ����λ
//	//int8_t clearError;
//	//int16_t stepNum;//���ⷢ�䲽�����
//	//	int8_t readyFlag;//����׼��״̬
//	//	int8_t beemOn;//������
//	
//	
//}my_t;

#endif



