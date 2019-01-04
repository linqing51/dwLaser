#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
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
#define SPREG_ADC_0						(SPREG_START + 0)
#define SPREG_ADC_1						(SPREG_START + 1)
#define SPREG_ADC_2						(SPREG_START + 2)
#define SPREG_ADC_3						(SPREG_START + 3)
#define SPREG_DAC_0						(SPREG_START + 4)
#define SPREG_DAC_1						(SPREG_START + 5)
#define SPREG_DAC_2						(SPREG_START + 6)
#define SPREG_DAC_3						(SPREG_START + 7)

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
int16_t ADD(int16_t A, int16_t B);//�ӷ�ָ��
void SET(uint16_t A);//��λ
void RESET(uint16_t A);//��λ
void FLIP(uint16_t A);//��ת
uint8_t LD(uint16_t A);//����
uint8_t LDP(uint16_t A);//����������
uint8_t LDN(uint16_t A);//�����½���
//void T100US(uint8_t A, uint8_t start, uint16_t value);
void T1MS(uint8_t A, uint8_t start, uint16_t value);//1mS��ʱ������
void T10MS(uint8_t A, uint8_t start, uint16_t value);//10mS��ʱ������
void T100MS(uint8_t A, uint8_t start, uint16_t value);//100mS��ʱ������
void UPDAC(uint16_t dat);//��������DAC���
void REBOOT(void);//SPLC��λָ��
/*****************************************************************************/
void chipDacInit(void);
void chipAdcInit(void);
void sPlcInit(void);
void refreshInput(void);
void refreshOutput(void);
void refreshDac(void);
/*****************************************************************************/
#endif