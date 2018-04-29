#ifndef __MAINAPP_H__
#define __MAINAPP_H__
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
}softTimer_t;

typedef struct
{//ȫ���豸�ṹ��
	int16_t	LaserCurrent[2];//���ü���������
	int16_t PhotoDiode[2];//PD��ѹ
	int16_t LaserMode;//����ģʽ
	int16_t PosWidth;//������
	int16_t NegWidth;//������
	int16_t GroupNum;//Ⱥ�������
	int16_t GroupSpace;//Ⱥ������
	int16_t SelectChannel;//ͨ��ѡ��
	int16_t AimVoltage;//ָʾ�����ѹ
	int16_t FanVoltage;//���ȵ�ѹ
	int16_t LaserTemp;//�������¶�
	int16_t RadiatorTemp;//ɢ�����¶�
	int16_t EnviTemp;//оƬ�¶�
	int16_t BeemVolume;//����������
	
	int16_t IPID_Kp;//IPID������������
	int16_t IPID_Ti;//IPID��������ʱ��
	int16_t IPID_Td;//IPID����΢��ʱ��
	int16_t IPID_Ts;//IPID������������
	int16_t IPIDOutAdd;//IPID���ֵ����
	int16_t IPIDOut;//IPID���ֵ
	int8_t  FlagStart;//���䴥��
	int8_t	FlagReady;//׼����־
	int8_t	FiberSensor[2];//���˼��
	int8_t	FlagIndicate;//���ⷢ���־
	int8_t	BeemEnabled;//������ʹ��
	int8_t	AimEnable;//ָʾ����ʹ��
	int8_t	CoolEnable;//�������ʹ��
	softTimer_t softTimer;
}myDevice_t;

#endif



