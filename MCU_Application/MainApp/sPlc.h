#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
//��Ȧ ���� 8 * 16 = 128BIT
#define MR_START						0
#define MR_END   						3
//��Ȧ�Ĵ��� �Ǳ��� 8 * 16 = 128BIT
#define R_START							4
#define R_END							11
//���ݼĴ��� ���� 8
#define DM_START						12
#define DM_END							19
//���ݼĴ��� �Ǳ��� 140����
#define EM_START						20
#define EM_END							159
//��ʱ��Ȧ
//1MS 1 * 16 = 16BIT
#define T_1MS_START						160
#define T_1MS_END						160
//10MS 1 * 16 = 16BIT
#define T_10MS_START					161
#define T_10MS_END						161
//100MS 1 * 16 = 16BIT
#define T_100MS_START					162
#define T_100MS_END						162
//��ʱ��ʱ�� 
//1MS 16
#define TD_1MS_START					163
#define TD_1MS_END						178
//10MS 16
#define TD_10MS_START					179
#define TD_10MS_END						194
//100MS 16
#define TD_100MS_START					195
#define TD_100MS_END					210
//������ 1
#define C_START							211
#define C_END							211
//����λ�Ĵ��� 1 * 16 = 16��
#define X_START							212
#define X_END							212		
//���λ�Ĵ��� 1 * 16 = 16��
#define Y_START							213
#define Y_END							213
//����Ĵ��� 24����
#define SPREG_START						214
#define SPREG_END						237
//������Ȧ	4 * 16 = 64��
#define SPCOIL_START					238
#define SPCOIL_END						241
/*****************************************************************************/
#define EM_ADC_0						(EM_START + 0)//ADC0->MLD0
#define EM_ADC_1						(EM_START + 1)//ADC1->MLD1
#define EM_ADC_2						(EM_START + 2)//ADC2->MLD2
#define EM_ADC_3						(EM_START + 3)//ADC3->MLD3
#define EM_ADC_4						(EM_START + 4)//ADC4->MLD4
#define EM_ADC_5						(EM_START + 5)//ADC5->MLD5
#define EM_ADC_6						(EM_START + 6)//ADC6->MLD6
#define EM_ADC_7						(EM_START + 7)//ADC7->MLD7
#define EM_ADC_8						(EM_START + 8)//ADC8->MLD8
#define EM_ADC_9						(EM_START + 9)//ADC9->MLD9
#define EM_ADC_10						(EM_START + 10)//ADC10->MLD10
#define EM_ADC_11						(EM_START + 11)//ADC11->MLD11
#define EM_ADC_12						(EM_START + 12)//ADC12->MLD12
#define EM_ADC_13						(EM_START + 13)//ADC13->MLD13
#define EM_ADC_14						(EM_START + 14)//ADC14->MLD14
#define EM_ADC_15						(EM_START + 15)//ADC15->MLD15
#define EM_DAC_0						(EM_START + 64)//DAC0
#define EM_DAC_1						(EM_START + 65)//DAC1
#define EM_DAC_2						(EM_START + 66)//DAC2
#define EM_DAC_3						(EM_START + 67)//DAC3
#define EM_DAC_4						(EM_START + 68)//DAC4
#define EM_DAC_5						(EM_START + 69)//DAC5
#define EM_DAC_6						(EM_START + 70)//DAC6
#define EM_DAC_7						(EM_START + 71)//DAC7
/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 				(SPCOIL_END + 1)
/*****************************************************************************/
#define SPCOIL_ON						(SPCOIL_START * 16 + 0)//��ͨ��Ȧ
#define SPCOIL_START_UP					(SPCOIL_START * 16 + 1)//�����ϵ�
#define SPCOIL_PS1MS					(SPCOIL_START * 16 + 2)//1mS��� 50%ռ�ձ�����
#define SPCOIL_PS10MS					(SPCOIL_START * 16 + 3)//10mS
#define SPCOIL_PS100MS					(SPCOIL_START * 16 + 4)//100mS	
#define SPCOIL_PS1000MS					(SPCOIL_START * 16 + 5)//1000mS	
#define SPCOIL_UART0_SEND_BUSY			(SPCOIL_START * 16 + 16)//UART1����æ
#define SPCOIL_UART0_RECV_BUSY			(SPCOIL_START * 16 + 17)//UART1����æ
#define SPCOIL_UART0_SEND_DONE			(SPCOIL_START * 16 + 18)//�������
#define SPCOIL_UART0_RECV_DONE			(SPCOIL_START * 16 + 19)//�������
#define SPCOIL_UART1_SEND_BUSY			(SPCOIL_START * 16 + 20)//UART1����æ
#define SPCOIL_UART1_RECV_BUSY			(SPCOIL_START * 16 + 21)//UART1����æ
#define SPCOIL_UART1_SEND_DONE			(SPCOIL_START * 16 + 22)//�������
#define SPCOIL_UART1_RECV_DONE			(SPCOIL_START * 16 + 23)//�������
/*****************************************************************************/
#define SPREG_RUNTIME_L					(SPREG_START + 0)//�ۼ�����ʱ���� 32BIT
#define SPREG_RUNTIME_H					(SPREG_START + 1)//�ۼ�����ʱ���� 32BIT		
/*****************************************************************************/
#define SPREG_UART0_SEND_BUFFER_ADR		(SPREG_START + 4)//UART0 ���ͻ���NVRAM��ַ		
#define SPREG_UART0_SEND_LENGTH			(SPREG_START + 5)//UART0 �������ݳ���
#define SPREG_UART0_SEND_NUM			(SPREG_START + 6)//UART0 �Ѿ��������ݳ���
#define SPREG_UART0_RECV_BUFFER_ADR		(SPREG_START + 7)//UART0 ���ջ���NVRAM��ַ
#define SPREG_UART0_RECV_LENGTH			(SPREG_START + 8)//UART0 �������ݳ���
#define SPREG_UART0_RECV_NUM			(SPREG_START + 9)//UART0 �Ѿ��������ݳ���
/*****************************************************************************/
#define SPREG_UART1_SEND_BUFFER_ADR		(SPREG_START + 10)//UART1 ���ͻ���NVRAM��ַ		
#define SPREG_UART1_SEND_LENGTH			(SPREG_START + 11)//UART1 �������ݳ���
#define SPREG_UART1_SEND_NUM			(SPREG_START + 12)//UART1 �Ѿ��������ݳ���
#define SPREG_UART1_RECV_BUFFER_ADR		(SPREG_START + 13)//UART1 ���ջ���NVRAM��ַ
#define SPREG_UART1_RECV_LENGTH			(SPREG_START + 14)//UART1 �������ݳ���
#define SPREG_UART1_RECV_NUM			(SPREG_START + 15)//UART1 �Ѿ��������ݳ���
/*****************************************************************************/
#define SPREG_CLEAR_NVRAM0				(SPREG_END)//���NVRAM����������
/*****************************************************************************/
extern xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
extern xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
/*****************************************************************************/
uint8_t getGlobalInterrupt(void);
void setLedRun(uint8_t st);
uint8_t getLedRun(void);
void setLedEprom(uint8_t st);
uint8_t getLedEprom(void);
void setLedDac(uint8_t st);
uint8_t getLedDac(void);
void setLedError(uint8_t st);
uint8_t getLedError(void);
void sPlcInit(void);//���߼���ʼ��
void sPlcProcessStart(void);//sPLC��ѯ��ʼ
void sPlcProcessEnd(void);//sPLC��ѯ����
void wdtFeed(void) reentrant;
void wdtEnable(void) reentrant;
void wdtDisable(void) reentrant;
/*****************************************************************************/
void assertCoilAddress(uint16_t adr) reentrant;
void assertRegisterAddress(uint16_t adr) reentrant;
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
void chipDacInit(void);
void chipAdcInit(void);
void sPlcInit(void);
void refreshInput(void);
void refreshOutput(void);
void refreshDac(void);
/*****************************************************************************/
#endif