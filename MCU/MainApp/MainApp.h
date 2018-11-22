#ifndef __MAINAPP_H__
#define __MAINAPP_H__
//IO����uint8_t ��ʾ ���λ��ʾ��ǰ״̬ ���λ��ʾ7��ǰ״̬ ����λ����
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
typedef struct
{//���ʱ���ṹ��
	uint16_t tMate;//��ʱ��ƥ��ֵ
	uint16_t tOverflow;//��ʱ�����ֵ
	uint16_t tCounter;//��ʱ������ֵ

	uint16_t pMate;//�������ƥ��ֵ
	uint16_t sMate;//����������ֵ
	uint16_t pCounter;//�����������ֵ
	uint16_t sCounter;//����������ֵ
}laserTimer_t;

int16_t DM[1024];//PLC DM�Ĵ���
int16_t MR[16];//PLC MR�Ĵ���
int16_t LR[16];//PLC LR�Ĵ���
#define DM_LASER_CURRENT_0			0
#define DM_LASER_CURRENT_1			1
#deifne DM_PHOTODIODE_0				2
#define DM_PHOTODIODE_1				3
#define DM_LASER_MODE				
#define DM_LASER_POSWIDTH
#define DM_LASER_NEGWIDTH
typedef struct
{//ȫ���豸�ṹ��
	//
	laserTimer_t laserTimer;//�����ʱ��
	int16_t laserMode;//����ģʽ
	int16_t posWidth;//������
	int16_t negWidth;//������
	int16_t groupNum;//Ⱥ�������
	int16_t groupSpace;//Ⱥ������
	int16_t selectChannel;//ͨ��ѡ��
	int16_t pwmAnalogOut[4];//PWMģ�����
	int16_t ntcTemperature[4];//NTC�¶�
	int16_t fanSpeedLevel;//����ת�ٵȼ�
	//����״̬
	uint8_t overTempFault;//����
	uint8_t overTempIgnore;//���Թ���
	uint8_t overTempDiode;//��������ܹ���
	uint8_t overTempDiodeIgnore;//��������ܹ��Ⱥ���
	uint8_t overTempAmplifier;//�Ŵ�������
	uint8_t overTempAmplifierIgnore;//�Ŵ������Ⱥ���
	uint8_t overTempEnvironment;//�����¶ȹ���
	uint8_t overTempEnvironmentIgnore;//�����¶ȹ��Ⱥ���
	uint8_t overTempMcu;//�������¶ȹ���
	uint8_t overTempMcuIgnore;//�������¶ȹ���
	//��ȫ״̬
	uint8_t safeFault;//��ȫ����
	uint8_t safeFaultIgnore;//��ȫ���Ϻ���
	uint8_t safeInterlock;//��ȫ����
	uint8_t safeInterlockIgnore;//��ȫ��������
	uint8_t safeFiberDetect0;//���˼��ͨ��0
	uint8_t safeFiberDetect0Ignore;//���˼��ͨ��0����
	uint8_t safeFiberDetect1;//���˼��ͨ��1
	uint8_t safeFiberDetect1Ignore;//���˼��ͨ��1����
	uint8_t safeOpenCase;//������
	uint8_t safeOpenCaseIgnore;//���������
	//
	uint8_t footSwitch;//��̤���س���
	
	//ģ��PID����
	fp32_t pidOut;//IPID���ֵ
	int16_t onTimerPid;//pid��� ����ʱ��  
	int16_t offTimerPid;//pid��� �ر�ʱ��
	
	//int8_t  FlagStart;//���䴥��
	//int8_t	FlagReady;//׼����־
	//int8_t	FiberSensor[2];//���˼��
	//int8_t	FlagIndicate;//���ⷢ���־
	//int8_t	BeemEnabled;//������ʹ��
	//int8_t	AimEnable;//ָʾ����ʹ��
	//int8_t	CoolEnable;//�������ʹ��
	
	//int8_t laserTrigger;//���ⷢ�䴥��
	int8_t laserEmiting;//���ⷢ���б�־
	int8_t laserEmitOver;//���ⷢ�����	
	int16_t checkCode;//HMI����У���� ��8λУ���� ��8λ�汾
	int8_t heartFlag;//������־
	int8_t mcuReset;//��Ƭ����λ
	int8_t clearError;
	int16_t stepNum;//���ⷢ�䲽�����
	int8_t readyFlag;//����׼��״̬
	int8_t beemOn;//������
	
	
}my_t;

#endif



