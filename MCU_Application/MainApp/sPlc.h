#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
//��Ȧ ���� 16 * 16 = 256BIT
#define MR_START						0
#define MR_END   						15
//��Ȧ�Ĵ��� �Ǳ��� 16 * 16 = 256BIT
#define R_START							16
#define R_END							31
//���ݼĴ��� ���� 128
#define DM_START						32
#define DM_END							159
//���ݼĴ��� �Ǳ��� 128����
#define EM_START						160
#define EM_END							287
//��ʱ��Ȧ
//1MS 2 * 16 = 32BIT
#define T_1MS_START						288
#define T_1MS_END						289
//10MS 2 * 16 = 32BIT
#define T_10MS_START					290
#define T_10MS_END						291
//100MS 2 * 16 = 32BIT
#define T_100MS_START					292
#define T_100MS_END						293
//��ʱ��ʱ�� 
//1MS 32
#define TD_1MS_START					294
#define TD_1MS_END						325
//10MS 32
#define TD_10MS_START					326
#define TD_10MS_END						357
//100MS 32
#define TD_100MS_START					358
#define TD_100MS_END					389
//������ 32
#define C_START							390
#define C_END							421
//����λ�Ĵ��� 16 * 16 = 256��
#define X_START							422
#define X_END							437
//���λ�Ĵ��� 16 * 16 = 256��
#define Y_START							438
#define Y_END							453
//����Ĵ��� 128����
#define SPREG_START						454
#define SPREG_END						581
//������Ȧ	16 * 16 = 256��
#define SPCOIL_START					582
#define SPCOIL_END						597
/*****************************************************************************/
#define SPREG_ADC_0						(SPREG_START + 0)//ADC0->MLD0
#define SPREG_ADC_24					(SPREG_START + 24)//ADC24->MLD24

#define SPREG_ADC_32					(SPREG_START + 25)//ADC25->MPD0
#define SPREG_ADC_63					(SPREG_START + 49)//ADC50->MPD24

#define SPREG_DAC_0						(SPREG_START + 50)//DAC0
#define SPREG_DAC_24					((SPREG_START + 74)//DAC24
/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 				(SPCOIL_END + 1)
/*****************************************************************************/
#define SPCOIL_ON						0//��ͨ��Ȧ
#define SPCOIL_PS1MS					1//1mS��� 50%ռ�ձ�����
#define SPCOIL_PS10MS					2//10mS
#define SPCOIL_PS100MS					3//100mS
/*****************************************************************************/
#define SP_EM_MODBUS_SLAVE_ERR			300
#define SP_R_ON							800//�ϵ�ON
#define SP_R_TICK_1MS					801//
#define SP_R_TICK_10MS					802//
#define SP_R_TICK_100MS					803//
#define SP_R_TICK_1S					804//
/*****************************************************************************/
extern uint16_t ModbusSlaveAsciiOverTimeCounter;//Modbus Slaveͨ�ų�ʱ��ʱ��
extern xdata int16_t NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
extern xdata int16_t NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
/*****************************************************************************/
void wdtDisable(void);//���Ź�����
void sPlcInit(void);//���߼���ʼ��
void sPlcProcessStart(void);//sPLC��ѯ��ʼ
void sPlcProcessEnd(void);//sPLC��ѯ����
/*****************************************************************************/
void assertCoilAddress(uint16_t adr);
void assertRegisterAddress(uint16_t adr);
/*****************************************************************************/
void nvramUpdata(void);
void clearDM(void);
void clearEM(void);
void clearR(void);
void clearT(void);
void clearTD(void);
void clearC(void);
void nvramLoad(void);
void nvramSave(void);
void nvramUpdata(void);
/*****************************************************************************/
void SET(uint16_t A);//��λ
void RESET(uint16_t A);//��λ
void FLIP(uint16_t A);//��ת
uint8_t LD(uint16_t A);//����
uint8_t LDP(uint16_t A);//����������
uint8_t LDN(uint16_t A);//�����½���
void T100US(uint8_t A, uint8_t start, uint16_t value);
void T1MS(uint8_t A, uint8_t start, uint16_t value);
void T10MS(uint8_t A, uint8_t start, uint16_t value);
void T100MS(uint8_t A, uint8_t start, uint16_t value);
/*****************************************************************************/
void chipDacInit(void);
void chipAdcInit(void);
void sPlcInit(void);
void refreshInput(void);
void refreshOutput(void);
void refreshDac(void);
/*****************************************************************************/
#endif