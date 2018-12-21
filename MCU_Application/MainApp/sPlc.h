#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "appConfig.h"
//���ݼĴ��� ���� 128����
#define DM_START						0//���籣�ּĴ���
#define DM_END							127
//��Ȧ ���� 32 * 16 = 512��
#define MR_START						128//��Ȧ�Ĵ���
#define	MR_END							159//
//���ݼĴ��� �Ǳ��� 64����
#define EM_START						160//����Ĵ���
#define EM_END							223
//��Ȧ�Ĵ��� �Ǳ��� 32 * 16 = 512��
#define R_START							224//���籣����Ȧ�Ĵ���
#define R_END							255
//��ʱ��Ȧ
#define T_1MS_START						256//32��1mS
#define T_1MS_END						287
#define T_10MS_START					288//32��10mS
#define T_10MS_END						319
#define T_100MS_START					320//32��100mS
#define T_100MS_END						351
//��ʱ��ʱ�� 
#define TD_1MS_START					352//32��1mS
#define TD_1MS_END						383
#define TD_10MS_START					384//32��10mS
#define TD_10MS_END						415
#define TD_100MS_START					416//32��100mS
#define TD_100MS_END					447
//������
#define C_START							448//32��������
#define C_END							479
//����λ�Ĵ��� 16 * 16 = 256��
#define X_START							480
#define X_END							495
//���λ�Ĵ��� 16 * 16 = 256��
#define Y_START							496
#define Y_END							511
//����Ĵ��� 32����
#define SPREG_START						512
#define SPREG_END						544
/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 				(SPREG_END + 1)
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
void assertCoilAddress(uint16_t adr);
void assertRegisterAddress(uint16_t adr);
void timer0Init(void);
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
void refreshInput(void);
void refreshOutput(void);
/*****************************************************************************/
#endif