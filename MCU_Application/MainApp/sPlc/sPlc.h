#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
//��Ȧ�Ĵ��� �Ǳ��� 8 * 16 = 128BIT
#define R_START							0
#define R_END							7
//���ݼĴ��� �Ǳ��� 160 
#define EM_START						8
#define EM_END							167
//��ʱ��Ȧ
//100MS 1 * 16 = 16BIT
#define T_100MS_START					168
#define T_100MS_END						168
//��ʱ��ʱ�� 
//100MS 16
#define TD_100MS_START					169
#define TD_100MS_END					184
//����λ�Ĵ��� 1 * 16 = 16��
#define X_START							185
#define X_END							185		
//���λ�Ĵ��� 1 * 16 = 16��
#define Y_START							186
#define Y_END							186
//����Ĵ��� 24����
#define SPREG_START						187
#define SPREG_END						210
//������Ȧ	4 * 16 = 64��
#define SPCOIL_START					211
#define SPCOIL_END						214
/*****************************************************************************/
#define BOX_GLED_0						(R_START + 0)//ָʾ�����̵�0
#define BOX_GLED_1						(R_START + 1)//ָʾ�����̵�1
#define BOX_GLED_2						(R_START + 2)//ָʾ�����̵�2
#define BOX_GLED_3						(R_START + 3)//ָʾ�����̵�3
#define BOX_GLED_4						(R_START + 4)//ָʾ�����̵�4
#define BOX_GLED_5						(R_START + 5)//ָʾ�����̵�5
#define BOX_GLED_6						(R_START + 6)//ָʾ�����̵�6
#define BOX_GLED_7						(R_START + 7)//ָʾ�����̵�7
#define BOX_GLED_8						(R_START + 8)//ָʾ�����̵�8
#define BOX_GLED_9						(R_START + 9)//ָʾ�����̵�9
#define BOX_GLED_10						(R_START + 10)//ָʾ�����̵�10
#define BOX_GLED_11						(R_START + 11)//ָʾ�����̵�11
#define BOX_GLED_12						(R_START + 12)//ָʾ�����̵�12
#define BOX_GLED_13						(R_START + 13)//ָʾ�����̵�13
#define BOX_GLED_14						(R_START + 14)//ָʾ�����̵�14
#define BOX_GLED_15						(R_START + 15)//ָʾ�����̵�15
#define BOX_GLED_16						(R_START + 16)//ָʾ�����̵�16
#define BOX_GLED_17						(R_START + 17)//ָʾ�����̵�17
#define BOX_GLED_18						(R_START + 18)//ָʾ�����̵�18
#define BOX_GLED_19						(R_START + 19)//ָʾ�����̵�19
#define BOX_GLED_20						(R_START + 20)//ָʾ�����̵�20
#define BOX_GLED_21						(R_START + 21)//ָʾ�����̵�21
#define BOX_GLED_22						(R_START + 22)//ָʾ�����̵�22
#define BOX_GLED_23						(R_START + 23)//ָʾ�����̵�23
#define BOX_GLED_24						(R_START + 24)//ָʾ�����̵�24

#define BOX_RLED_0						(R_START + 32)//ָʾ���Ӻ��0
#define BOX_RLED_1						(R_START + 33)//ָʾ���Ӻ��1
#define BOX_RLED_2						(R_START + 34)//ָʾ���Ӻ��2
#define BOX_RLED_3						(R_START + 35)//ָʾ���Ӻ��3
#define BOX_RLED_4						(R_START + 36)//ָʾ���Ӻ��4
#define BOX_RLED_5						(R_START + 37)//ָʾ���Ӻ��5
#define BOX_RLED_6						(R_START + 38)//ָʾ���Ӻ��6
#define BOX_RLED_7						(R_START + 39)//ָʾ���Ӻ��7
#define BOX_RLED_8						(R_START + 40)//ָʾ���Ӻ��8
#define BOX_RLED_9						(R_START + 41)//ָʾ���Ӻ��9
#define BOX_RLED_10						(R_START + 42)//ָʾ���Ӻ��10
#define BOX_RLED_11						(R_START + 43)//ָʾ���Ӻ��11
#define BOX_RLED_12						(R_START + 44)//ָʾ���Ӻ��12
#define BOX_RLED_13						(R_START + 45)//ָʾ���Ӻ��13
#define BOX_RLED_14						(R_START + 46)//ָʾ���Ӻ��14
#define BOX_RLED_15						(R_START + 47)//ָʾ���Ӻ��15
#define BOX_RLED_16						(R_START + 48)//ָʾ���Ӻ��16
#define BOX_RLED_17						(R_START + 49)//ָʾ���Ӻ��17
#define BOX_RLED_18						(R_START + 50)//ָʾ���Ӻ��18
#define BOX_RLED_19						(R_START + 51)//ָʾ���Ӻ��19
#define BOX_RLED_20						(R_START + 52)//ָʾ���Ӻ��20
#define BOX_RLED_21						(R_START + 53)//ָʾ���Ӻ��21
#define BOX_RLED_22						(R_START + 54)//ָʾ���Ӻ��22
#define BOX_RLED_23						(R_START + 55)//ָʾ���Ӻ��23
#define BOX_RLED_24						(R_START + 56)//ָʾ���Ӻ��24

#define PLC_ALARM_0						(R_START + 64)
#define PLC_ALARM_1						(R_START + 65)
#define PLC_ALARM_2						(R_START + 66)
#define PLC_ALARM_3						(R_START + 67)
#define PLC_ALARM_4						(R_START + 68)
#define PLC_ALARM_5						(R_START + 69)
#define PLC_ALARM_6						(R_START + 70)
#define PLC_ALARM_7						(R_START + 71)
#define PLC_ALARM_8						(R_START + 72)
#define PLC_ALARM_9						(R_START + 73)
#define PLC_ALARM_10					(R_START + 74)
#define PLC_ALARM_11					(R_START + 75)
#define PLC_ALARM_12					(R_START + 76)
#define PLC_ALARM_13					(R_START + 77)
#define PLC_ALARM_14					(R_START + 78)
#define PLC_ALARM_15					(R_START + 79)
#define PLC_ALARM_16					(R_START + 80)
#define PLC_ALARM_17					(R_START + 81)
#define PLC_ALARM_18					(R_START + 82)
#define PLC_ALARM_19					(R_START + 83)
#define PLC_ALARM_20					(R_START + 84)
#define PLC_ALARM_21					(R_START + 85)
#define PLC_ALARM_22					(R_START + 86)
#define PLC_ALARM_23					(R_START + 87)
#define PLC_ALARM_24					(R_START + 88)

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
#define EM_ADC_16						(EM_START + 16)//ADC16->MLD16
#define EM_ADC_17						(EM_START + 17)//ADC17->MLD17
#define EM_ADC_18						(EM_START + 18)//ADC18->MLD18
#define EM_ADC_19						(EM_START + 19)//ADC19->MLD19
#define EM_ADC_20						(EM_START + 20)//ADC20->MLD20
#define EM_ADC_21						(EM_START + 21)//ADC21->MLD21
#define EM_ADC_22						(EM_START + 22)//ADC22->MLD22
#define EM_ADC_23						(EM_START + 23)//ADC23->MLD23
#define EM_ADC_24						(EM_START + 24)//ADC24->MLD24
#define EM_ADC_25						(EM_START + 25)//ADC25->MLD25
#define EM_ADC_26						(EM_START + 26)//ADC26->MLD26
#define EM_ADC_27						(EM_START + 27)//ADC27->MLD27
#define EM_ADC_28						(EM_START + 28)//ADC28->MLD28
#define EM_ADC_29						(EM_START + 29)//ADC29->MLD29
#define EM_ADC_30						(EM_START + 30)//ADC30->MLD30
#define EM_ADC_31						(EM_START + 31)//ADC31->MLD31
#define EM_ADC_32						(EM_START + 32)//ADC32->MPD0
#define EM_ADC_33						(EM_START + 33)//ADC33->MPD1
#define EM_ADC_34						(EM_START + 34)//ADC34->MPD2
#define EM_ADC_35						(EM_START + 35)//ADC35->MPD3
#define EM_ADC_36						(EM_START + 36)//ADC36->MPD4
#define EM_ADC_37						(EM_START + 37)//ADC37->MPD5
#define EM_ADC_38						(EM_START + 38)//ADC38->MPD6
#define EM_ADC_39						(EM_START + 39)//ADC39->MPD7
#define EM_ADC_40						(EM_START + 40)//ADC40->MPD8
#define EM_ADC_41						(EM_START + 41)//ADC41->MPD9
#define EM_ADC_42						(EM_START + 42)//ADC42->MPD10
#define EM_ADC_43						(EM_START + 43)//ADC42->MPD11
#define EM_ADC_44						(EM_START + 44)//ADC42->MPD12
#define EM_ADC_45						(EM_START + 45)//ADC42->MPD13
#define EM_ADC_46						(EM_START + 46)//ADC42->MPD14
#define EM_ADC_47						(EM_START + 47)//ADC42->MPD15
#define EM_ADC_48						(EM_START + 48)//ADC42->MPD16
#define EM_ADC_49						(EM_START + 49)//ADC42->MPD17
#define EM_ADC_50						(EM_START + 50)//ADC42->MPD18
#define EM_ADC_51						(EM_START + 51)//ADC42->MPD19
#define EM_ADC_52						(EM_START + 52)//ADC42->MPD20
#define EM_ADC_53						(EM_START + 53)//ADC43->MPD21
#define EM_ADC_54						(EM_START + 54)//ADC44->MPD22
#define EM_ADC_55						(EM_START + 55)//ADC45->MPD23
#define EM_ADC_56						(EM_START + 56)//ADC46->MPD24
#define EM_ADC_57						(EM_START + 57)//ADC47->MPD25
#define EM_ADC_58						(EM_START + 58)//ADC48->MPD26
#define EM_ADC_59						(EM_START + 59)//ADC49->MPD27
#define EM_ADC_60						(EM_START + 60)//ADC50->MPD28
#define EM_ADC_61						(EM_START + 61)//ADC50->MPD29
#define EM_ADC_62						(EM_START + 62)//ADC50->MPD30
#define EM_ADC_63						(EM_START + 63)//ADC50->MPD31

#define EM_DAC_0						(EM_START + 64)//DAC0
#define EM_DAC_1						(EM_START + 65)//DAC1
#define EM_DAC_2						(EM_START + 66)//DAC2
#define EM_DAC_3						(EM_START + 67)//DAC3
#define EM_DAC_4						(EM_START + 68)//DAC4
#define EM_DAC_5						(EM_START + 69)//DAC5
#define EM_DAC_6						(EM_START + 70)//DAC6
#define EM_DAC_7						(EM_START + 71)//DAC7
#define EM_DAC_8						(EM_START + 72)//DAC8
#define EM_DAC_9						(EM_START + 73)//DAC9
#define EM_DAC_10						(EM_START + 74)//DAC10
#define EM_DAC_11						(EM_START + 75)//DAC11
#define EM_DAC_12						(EM_START + 76)//DAC12
#define EM_DAC_13						(EM_START + 77)//DAC13
#define EM_DAC_14						(EM_START + 78)//DAC14
#define EM_DAC_15						(EM_START + 79)//DAC15
#define EM_DAC_16						(EM_START + 80)//DAC16
#define EM_DAC_17						(EM_START + 81)//DAC17
#define EM_DAC_18						(EM_START + 82)//DAC18
#define EM_DAC_19						(EM_START + 83)//DAC19
#define EM_DAC_20						(EM_START + 84)//DAC20
#define EM_DAC_21						(EM_START + 85)//DAC21
#define EM_DAC_22						(EM_START + 86)//DAC22
#define EM_DAC_23						(EM_START + 87)//DAC23
#define EM_DAC_24						(EM_START + 88)//DAC24
#define EM_DAC_25						(EM_START + 89)//DAC24
#define EM_DAC_26						(EM_START + 90)//DAC24
#define EM_DAC_27						(EM_START + 91)//DAC24

/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 				(SPCOIL_END + 1)
/*****************************************************************************/
#define SPCOIL_ON						(SPCOIL_START * 16 + 0)//��ͨ��Ȧ
#define SPCOIL_START_UP					(SPCOIL_START * 16 + 1)//�����ϵ�
#define SPCOIL_DELAY_DAC_INIT			(SPCOIL_START * 16 + 2)//DAC��ʱ��ʼ��
#define SPCOIL_DELAY_DAC_RUN			(SPCOIL_START * 16 + 3)//DAC��ʱ����
#define SPCOIL_PS100MS					(SPCOIL_START * 16 + 4)//100mS		
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
extern xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
extern xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
extern uint8_t Timer0_L, Timer0_H, DelayCounter;
/*****************************************************************************/
void sPlcInit(void);//���߼���ʼ��
extern void timer0Init(void);
void sPlcProcessStart(void);//sPLC��ѯ��ʼ
void sPlcProcessEnd(void);//sPLC��ѯ����
extern void initWatchDog(void);//���Ź���ʼ��
extern void feedWatchDog(void) reentrant;//ι��
extern void enableWatchDog(void);//ʹ�ܿ��Ź�
extern void disableWatchDog(void);//�رտ��Ź�(δ����)
/*****************************************************************************/
void nvramUpdata(void);
/*****************************************************************************/
void chipAdcInit(void);
void sPlcInit(void);
/*****************************************************************************/
#endif