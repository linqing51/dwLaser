#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
/*****************************************************************************/
//��Ȧ ���� 16 * 16 = 256BIT
#define MR_START						0
#define MR_END							15
//��Ȧ�Ĵ��� �Ǳ��� 16 * 16 = 256BIT
#define R_START							16
#define R_END							31
//���ݼĴ��� ���� 256
#define DM_START						32
#define DM_END							287
//���ݼĴ��� �Ǳ��� 256����
#define EM_START						288
#define EM_END							543
//��ʱ��Ȧ
#define T_1MS_START						544//32��1mS
#define T_1MS_END						545
#define T_10MS_START					546//32��10mS
#define T_10MS_END						547
#define T_100MS_START					548//32��100mS
#define T_100MS_END						549
//��ʱ��ʱ�� 
#define TD_1MS_START					550//32��1mS
#define TD_1MS_END						581
#define TD_10MS_START					582//32��10mS
#define TD_10MS_END						613
#define TD_100MS_START					614//32��100mS
#define TD_100MS_END					645
//������
#define C_START							646//16��������
#define C_END							661//
//����λ�Ĵ��� 16 * 16 = 256��
#define X_START							662//
#define X_END							677// 
//���λ�Ĵ��� 16 * 16 = 256��
#define Y_START							678// 
#define Y_END							693//
//����Ĵ��� 64����
#define SPREG_START						694//
#define SPREG_END						757//
//������Ȧ	16 * 16 = 256��
#define SPCOIL_START					758
#define SPCOIL_END						773
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
#define SPREG_CHECKCODE_L				(SPREG_END - 1)
#define SPREG_CHECKCODE_H				(SPREG_END)
#define SPCOIL_ON						(SPCOIL_START + 0)//��ͨ��Ȧ
#define SPCOIL_PSST						(SPCOIL_START + 1)//�״�����
#define SPCOIL_PS1MS					(SPCOIL_START + 2)//1mS��� 50%ռ�ձ�����
#define SPCOIL_PS10MS					(SPCOIL_START + 3)//10mS 50%ռ�ձ�����
#define SPCOIL_PS100MS					(SPCOIL_START + 4)//100mS 50%ռ�ձ�����
/*****************************************************************************/

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
void RES(uint16_t A);//��λ
void FLIP(uint16_t A);//��ת
uint8_t LD(uint16_t A);//����
uint8_t LDP(uint16_t A);//����������
uint8_t LDF(uint16_t A);//�����½���
uint8_t LDB(uint16_t A);//ȡ������
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