#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "appConfig.h"
//���ݼĴ��� ���� 256����
#define DM_START						0//���籣�ּĴ���
#define DM_END							127
//��Ȧ ���� 128 * 16 = 2048��
#define MR_START						128//��Ȧ�Ĵ���
#define	MR_END							191
//���ݼĴ��� �Ǳ��� 128����
#define EM_START						192//����Ĵ���
#define EM_END							319
//��Ȧ�Ĵ��� �Ǳ��� 64 * 16 = 1024��
#define R_START							320//���籣����Ȧ�Ĵ���
#define R_END							383
//��ʱ��Ȧ
#define T_100US_START					384
#define T_100US_END						387
#define T_1MS_START						388
#define T_1MS_END						391
#define T_10MS_START					392
#define T_10MS_END						395
#define T_100MS_START					396	
#define T_100MS_END						399
//��ʱ��ʱ�� 
#define TD_100US_START					400//64��100uS
#define TD_100US_END					463
#define TD_1MS_START					464//64��1mS
#define TD_1MS_END						527
#define TD_10MS_START					528//64��10mS
#define TD_10MS_END						591
#define TD_100MS_START					592//64��100mS
#define TD_100MS_END					655
//������
#define C_START							656//64��������
#define C_END							719
//����λ�Ĵ��� 16 * 16 = 256��
#define X_START							720
#define X_END							735
//���λ�Ĵ��� 16 * 16 = 256��
#define Y_START							736
#define Y_END							751
//����Ĵ���
#define SPREG_START						752
#define SPREG_END						784
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