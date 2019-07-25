#ifndef __HMI_H__
#define __HMI_H__
/*****************************************************************************/
#define FSMSTEP_POWERUP												0//�ϵ�
//HMI��ʼ����
#define FSMSTEP_RESTORE_HMI											100//HMI �ָ���������
#define FSMSTEP_CHECK_FAIL_DISPLAY									200//ʧ���Լ�
//��������״̬
#define FSMSTEP_WAIT_ENTER_PASSCODE									300
#define FSMSTEP_PASSCODE_INPUT										301//��������״̬
#define FSMSTEP_PASSCODE_NEW0										302//�������״̬��һ������
#define FSMSTEP_PASSCODE_NEW1										303//�������״̬�ڶ�������
//STNADBY״̬
#define FSMSTEP_STANDBY												400//�ȴ�״̬
#define FSMSTEP_READY_LOAD_PARA										401//�������
#define FSMSTEP_READY_LOAD_DONE										402//����������
#define FSMSTEP_LASER_WAIT_TRIGGER									403//���ⴥ��
#define FSMSTEP_LASER_EMITING										404//���ⷢ����
#define FSMSTEP_LASER_STOP											405//���ⷢ�����
#define FSMSTEP_READY_ERROR											406//��̤���´���
//READY״̬
#define FSMSTEP_READY												500
//ѡ��״̬
#define FSMSTEP_OPTION												600//ѡ��˵�
#define FSMSTEP_INFORMATION											700
#define FSMSTEP_SCHEME												800//�����˵�
#define FSMSTEP_DIAGNOSIS  											900//��ϲ˵�
#define FSMSTEP_CORRECTION											10000//����У��
/*****************************************************************************/
#define FLASH_DATA_VERSION  										0XAABB0000
#define FLASH_DATA_ADDR     										0X00000000
/*****************************************************************************/
#include "sPlc.h"
#include "appSplcAdr.h"
#include "dcHmiRes.h"
#include "dcHmiLanguage.h"
#include "backgroundApp.h"
#include "hmiLib.h"
#include "dcHmiNotifyProgress.h"
#include "dcHmiNotifyButton.h"
/*****************************************************************************/
void dcHmiLoop(void);//HMI��ѵ����
void dcHmiLoopInit(void);
void updateStandbyDisplay(void);
void standbyTouchEnable(int8_t enable);
void updatePowerDisplay(int16_t ch, int16_t mode);
void updataPosWidthDisplay(int16_t mode);
void updataNegWidthDisplay(int16_t mode);
void unselectSchemeNum(sel);
void seletcSchemeNum(uint16_t sel);
#endif