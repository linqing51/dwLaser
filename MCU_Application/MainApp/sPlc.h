#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "appConfig.h"
//��Ȧ ���� 16 * 16 = 256BIT
#define MR_START						0
#define MR_END							15
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
#define T_1MS_START						288//16��1mS
#define T_1MS_END						303
#define T_10MS_START					304//16��10mS
#define T_10MS_END						319
#define T_100MS_START					320//16��100mS
#define T_100MS_END						335
//��ʱ��ʱ�� 
#define TD_1MS_START					336//16��1mS
#define TD_1MS_END						351
#define TD_10MS_START					352//16��10mS
#define TD_10MS_END						367
#define TD_100MS_START					368//16��100mS
#define TD_100MS_END					383
//������
#define C_START							384//16��������
#define C_END							399//
//����λ�Ĵ��� 16 * 16 = 256��
#define X_START							400//
#define X_END							415// 
//���λ�Ĵ��� 16 * 16 = 256��
#define Y_START							416// 
#define Y_END							431//
//����Ĵ��� 64����
#define SPREG_START						432//
#define SPREG_END						495//
//������Ȧ	16 * 16 = 256��
#define SPCOIL_START					496
#define SPCOIL_END						511
/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 				(SPCOIL_END + 1)
/*****************************************************************************/
#define SPREG_ADC_0						(SPREG_START)
#define SPREG_ADC_1						(SPREG_START + 1)
#define SPREG_ADC_2						(SPREG_START + 2)
#define SPREG_ADC_3						(SPREG_START + 3)
#define SPREG_ADC_4						(SPREG_START + 4)
#define SPREG_ADC_5						(SPREG_START + 5)
#define SPREG_ADC_6						(SPREG_START + 6)
#define SPREG_ADC_7						(SPREG_START + 7)
#define SPREG_ADC_8						(SPREG_START + 8)
#define SPREG_ADC_9						(SPREG_START + 9)
#define SPREG_ADC_10					(SPREG_START + 10)
#define SPREG_ADC_11					(SPREG_START + 11)
#define SPREG_ADC_12					(SPREG_START + 12)
#define SPREG_ADC_13					(SPREG_START + 13)
#define SPREG_ADC_14					(SPREG_START + 14)
#define SPREG_ADC_15					(SPREG_START + 15)
#define SPREG_ADC_16					(SPREG_START + 16)
#define SPREG_ADC_17					(SPREG_START + 17)
#define SPREG_ADC_18					(SPREG_START + 18)
#define SPREG_ADC_19					(SPREG_START + 19)
#define SPREG_ADC_20					(SPREG_START + 20)
#define SPREG_ADC_21					(SPREG_START + 21)
#define SPREG_ADC_22					(SPREG_START + 22)
#define SPREG_ADC_23					(SPREG_START + 23)
#define SPREG_ADC_24					(SPREG_START + 24)
#define SPREG_ADC_25					(SPREG_START + 25)
#define SPREG_ADC_26					(SPREG_START + 26)
#define SPREG_ADC_27					(SPREG_START + 27)
#define SPREG_ADC_28					(SPREG_START + 28)
#define SPREG_ADC_29					(SPREG_START + 29)
#define SPREG_ADC_30					(SPREG_START + 30)
#define SPREG_ADC_31					(SPREG_START + 31)

#define SPREG_DAC_0						(SPREG_ADC_31 + 1)
#define SPREG_DAC_1						(SPREG_DAC_0 + 1)

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