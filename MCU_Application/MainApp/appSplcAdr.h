#ifndef __APPSPLCADR_H__
#define __APPSPLCADR_H__
/*****************************************************************************/
#define CONFIG_APP_DIODE_HIGH_TEMP				400
#define CONFIG_APP_DRIVE_HIGH_TEMP				650
#define CONFIG_APP_ENVI_HIGH_TEMP				500
/*****************************************************************************/
#define CONFIG_HMI_SCHEME_NUM					16//������
#define CONFIG_HMI_DEFAULT_PASSSWORD0			0x32//Ĭ������
#define CONFIG_HMI_DEFAULT_PASSSWORD1			0x35//Ĭ������
#define CONFIG_HMI_DEFAULT_PASSSWORD2			0x38//Ĭ������
#define CONFIG_HMI_DEFAULT_PASSSWORD3			0x30//Ĭ������
#define STATUS_LASER_READY						0x5A
#define STATUS_LASER_STANDBY					0xA5
#define ERROR_CODE_EPROM						0x0001
#define ERROR_CODE_INTBUS						0x0002
#define ERROR_CODE_LDR							0x0003
#define ERROR_CODE_TEMPER						0x0004
#define ERROR_CODE_USBHOST						0x0005
#define ERROR_CODE_NFC							0x0006
#define ERROR_CODE_NRF24L01						0x0007
#define ERRPR_CODE_NOERR						0xFFFF
/*****************************************************************************/
#define EM_LASER_SCHEME_NAME					(EM_START + 0)//��������
#define EM_LASER_SELECT							(EM_START + 17)//ͨ��ѡ��
#define EM_LASER_PULSE_MODE						(EM_START + 18)//����ģʽ
#define EM_LASER_POWER_CH0						(EM_START + 19)//ͨ��0����
#define EM_LASER_POWER_CH1						(EM_START + 20)//ͨ��1����
#define EM_LASER_POSWIDTH						(EM_START + 21)//������
#define EM_LASER_NEGWIDTH						(EM_START + 22)//������
#define EM_LASER_GROUP							(EM_START + 23)//������
#define EM_LASER_SPACE							(EM_START + 24)//������
#define EM_HMI_PAGE								(EM_START + 25)//HMIҳ����
#define EM_START_PROGRESS_BAR					(EM_START + 26)//HMI����������
#define EM_NEW_PASSWORD0						(EM_START + 27)//HMI����������0
#define EM_NEW_PASSWORD1						(EM_START + 28)//HMI����������1
#define EM_DEFAULT_PASSWORD0					(EM_START + 29)//HMI����Ĭ������0
#define EM_DEFAULT_PASSWORD1					(EM_START + 30)//HMI����Ĭ������1
#define EM_DIODE_TEMP0							(EM_START + 31)//�������¶�0
#define EM_DIODE_TEMP1							(EM_START + 32)//�������¶�1
#define EM_DRIVE_TEMP							(EM_START + 33)//�������¶�
#define EM_ENVI_TEMP							(EM_START + 34)//�����¶�
#define EM_DIODE_HIGH_TEMP						(EM_START + 35)//�����ܹ�����ֵ
#define EM_DRIVE_HIGH_TEMP						(EM_START + 36)//������������ֵ
#define EM_ENVI_HIGH_TEMP						(EM_START + 37)//����������ֵ
/*****************************************************************************/
#define EM_EPID0_TAB_OUT						(EM_START + 38)//EPID���ֵ��ַ
#define EM_EPID0_TAB_REF						(EM_START + 39)//EPID���ö�ֵ
#define EM_EPID0_TAB_VFB						(EM_START + 40)//EPID����ֵ
#define EM_EPID0_TAB_KP							(EM_START + 41)//EPID�������� XX.XXX 0-65.535
#define	EM_EPID0_TAB_KI							(EM_START +	42)//EPID���ֳ��� XX.XXX 0-65.535		
#define EM_EPID0_TAB_TD 						(EM_START + 43)//EPID΢��ʱ�䳣�� XX.XXX 0-65.535
#define EM_EPID0_TAB_TS							(EM_START + 44)//EPID����ʱ���� 1-3000 ��λ0.01S
#define EM_EPID0_TAB_EN_FP32L					(EM_START +	45)//EPID��ǰ���ֵ FP32 
#define EM_EPID0_TAB_EN_FP32H					(EM_START +	46)//EPID��ǰ���ֵ FP32 
#define EM_EPID0_TAB_VFB1_FP32L 				(EM_START +	47)//EPIDǰ1�����ֵ FP32
#define EM_EPID0_TAB_VFB1_FP32H					(EM_START +	48)//EPIDǰ1�����ֵ FP32
#define EM_EPID0_TAB_MAX						(EM_START + 49)//EPID����������		
#define EM_EPID0_TAB_MIN						(EM_START + 50)//EPID�����С����
#define EM_EPID0_TAB_BIAS						(EM_START +	51)//EPID���ƫ��
#define EM_EPID0_TAB_TSC						(EM_START + 52)//EPID�����ʱ��
#define EM_EPID0_TAB_KP_SUM_FP32L				(EM_START +	53)//EPID�����ۼ�ֵ FP32
#define EM_EPID0_TAB_KP_SUM_FP32H				(EM_START +	54)//EPID�����ۼ�ֵ FP32
#define EM_EPID0_TAB_KI_SUM_FP32L				(EM_START +	55)//EPID΢���ۼ�ֵ FP32
#define EM_EPID0_TAB_KI_SUM_FP32H				(EM_START +	56)//EPID΢���ۼ�ֵ FP32
#define EM_EPID0_TAB_KD_SUM_FP32L				(EM_START +	57)//EPID΢���ۼ�ֵ FP32
#define EM_EPID0_TAB_KD_SUM_FP32H				(EM_START +	58)//EPID΢���ۼ�ֵ FP32
#define EM_EPID0_TAB_FOUT_FP32L					(EM_START +	59)//EPID����ۼ�ֵ FP32
#define EM_EPID0_TAB_FOUT_FP32H					(EM_START +	60)//EPID����ۼ�ֵ FP32
#define EM_LASER_CURRENT_0						(EM_START +	61)//����������0
#define EM_LASER_CURRENT_1						(EM_START +	62)//����������1
#define EM_HMI_OPERA_STEP						(EM_START +	63)//��������
#define EM_ERROR_CODE							(EM_START + 64)//������
/*****************************************************************************/
#define DM_LASER_SCHEME_NAME					(DM_START + 0)//��������
#define DM_LASER_SELECT							(DM_START + 17)//ͨ��ѡ��
#define DM_LASER_PULSE_MODE						(DM_START + 18)//����ģʽ
#define DM_LASER_POWER_0						(DM_START + 19)//ͨ��0����
#define DM_LASER_POWER_1						(DM_START + 20)//ͨ��1����
#define DM_LASER_POSWIDTH						(DM_START + 21)//������
#define DM_LASER_NEGWIDTH						(DM_START + 22)//������
#define DM_LASER_GROUP							(DM_START + 23)//������
#define DM_LASER_SPACE							(DM_START + 24)//������

#define DM_SCHEME_START_0						(DM_START +   0)//����0�洢��
#define DM_SCHEME_END_0							(DM_START +  24)

#define DM_SCHEME_START_1						(DM_START +  25)//����1�洢��
#define DM_SCHEME_END_1							(DM_START +  49)

#define DM_SCHEME_START_2						(DM_START +  50)//����2�洢��
#define DM_SCHEME_END_2							(DM_START +  74)

#define DM_SCHEME_START_3						(DM_START +  75)//����3�洢��
#define DM_SCHEME_END_3							(DM_START +  99)

#define DM_SCHEME_START_4						(DM_START + 100)//����4�洢��
#define DM_SCHEME_END_4							(DM_START + 124)

#define DM_SCHEME_START_5						(DM_START + 125)//����5�洢��
#define DM_SCHEME_END_5							(DM_START + 149)

#define DM_SCHEME_START_6						(DM_START + 150)//����6�洢��
#define DM_SCHEME_END_6							(DM_START + 174)

#define DM_SCHEME_START_7						(DM_START + 175)//����7�洢��
#define DM_SCHEME_END_7							(DM_START + 199)

#define DM_SCHEME_START_8						(DM_START + 200)//����8�洢��
#define DM_SCHEME_END_8							(DM_START + 224)

#define DM_SCHEME_START_9						(DM_START + 225)//����11�洢��
#define DM_SCHEME_END_9							(DM_START + 249)

#define DM_SCHEME_START_10						(DM_START + 250)//����10�洢��
#define DM_SCHEME_END_10						(DM_START + 274)

#define DM_SCHEME_START_11						(DM_START + 275)//����11�洢��
#define DM_SCHEME_END_11						(DM_START + 299)

#define DM_SCHEME_START_12						(DM_START + 300)//����12�洢��
#define DM_SCHEME_END_12						(DM_START + 324)

#define DM_SCHEME_START_13						(DM_START + 325)//����13�洢��
#define DM_SCHEME_END_13						(DM_START + 349)

#define DM_SCHEME_START_14						(DM_START + 350)//����14�洢��
#define DM_SCHEME_END_14						(DM_START + 374)

#define DM_SCHEME_START_15						(DM_START + 375)//����15�洢��
#define DM_SCHEME_END_15						(DM_START + 399)

#define DM_CORR_TAB0_POWER						(DM_START + 400)//����У����0���� �̶�����дDAC CODE
#define DM_CORR_TAB1_POWER						(DM_START + 420)//����У����1���� �̶�����дDAC CODE			
#define DM_SCHEME_NUM							(DM_START + 440)//ѡ��ķ������
#define DM_BEEM_VOLUME							(DM_START + 441)
#define DM_OLD_PASSWORD0						(DM_START + 442)
#define DM_OLD_PASSWORD1						(DM_START + 443)
#define DM_SYS_RUNTIME_L						(DM_START + 444)//ϵͳ�ۼ�����ʱ����L 32BIT
#define DM_SYS_RUNTIME_H						(DM_START + 445)//ϵͳ�ۼ�����ʱ����H 32BIT
#define DM_LAR_RUNTIME_L						(DM_START + 446)//�����ۼƷ���ʱ����L 32BIT
#define DM_LAR_RUNTIME_H						(DM_START + 447)//�����ۼƷ���ʱ����L 32BIT
#define DM_RELEASE_DATA_YEAR					(DM_START + 448)//����������		
#define DM_RELEASE_DATA_MONTH					(DM_START + 449)//����������
#define DM_RELEASE_DATA_DAY						(DM_START + 450)//����������
/*****************************************************************************/
#define X_INTERLOCK								(X_START * 16 + 0)//XIN0 ��ȫ����
#define X_ESTOP									(X_START * 16 + 1)//XIN1 ����ֹͣ����
#define X_FOOTSWITCH_OC							(X_START * 16 + 2)//XIN2 ��̤����
#define X_FOOTSWITCH_ON							(X_START * 16 + 3)//XIN3 ��̤����
#define X_LDR_FAULT0							(X_START * 16 + 4)//XIN4 ����������0
#define X_LDR_FAULT1							(X_START * 16 + 5)//XIN5 ����������1
#define X_FBD0									(X_START * 16 + 6)//XIN6 ����̽��0
#define X_FBD1									(X_START * 16 + 7)//XIN7 ����̽��1
/*****************************************************************************/
#define Y_LED_POWERON							(Y_START * 16 + 0)//YOUT0 ��Դ��
#define Y_LED_EMIT								(Y_START * 16 + 1)//YOUT1 ����ָʾ��
#define Y_LED_ALARM								(Y_START * 16 + 2)//YOUT2 ����ָʾ��
#define Y_OUT3									(Y_START * 16 + 3)//YOUT3
#define Y_OUT4									(Y_START * 16 + 4)//YOUT4
#define Y_OUT5									(Y_START * 16 + 5)//YOUT5
#define Y_OUT6									(Y_START * 16 + 6)//YOUT6
#define Y_OUT7									(Y_START * 16 + 7)//YOUT7
#define Y_FAN0									(Y_START * 16 + 8)//YOUT8 ���ȿ���0
#define Y_FAN1									(Y_START * 16 + 9)//YOUT9 ���ȿ���1
#define Y_TEC0									(Y_START * 16 + 10)//YOUT10 ���俪��0
#define Y_TEC1									(Y_START * 16 + 11)//YOUT11 ���俪��1
/*****************************************************************************/
#define R_FIBER_MANUFACT_0						(R_START * 16 + 0)
#define R_FIBER_MANUFACT_1						(R_START * 16 + 1)
#define R_DIODE_TEMP_HIGH_0						(R_START * 16 + 2)
#define R_DIODE_TEMP_HIGH_1						(R_START * 16 + 3)
#define R_DRIVE_TEMP_HIGH						(R_START * 16 + 4)
#define R_ENVI_TEMP_HIGH						(R_START * 16 + 5)
#define R_DRIVE_FAULT_0							(R_START * 16 + 6)
#define R_DRIVE_FAULT_1							(R_START * 16 + 7)
#define R_SAFE_FAULT							(R_START * 16 + 8)//����
#define R_SCHEME_LOAD_REQ						(R_START * 16 + 9)//������������
#define R_SHCEME_SAVE_REQ						(R_START * 16 + 10)//������������
#define R_KEY_READY								(R_START * 16 + 11)//׼��

#define R_CHECK_EPROM_DONE						(R_START * 16 + 32)//�������Լ����
#define R_CHECK_INTBUS_DONE						(R_START * 16 + 33)//HMIͨ���Լ����
#define R_CHECK_LDR_DONE						(R_START * 16 + 34)//�����������Լ����
#define R_CHECK_TEMPER_DONE						(R_START * 16 + 35)//�¶��Լ����
#define R_CHECK_USBHOST_DONE					(R_START * 16 + 36)//USBHOSTģ�����
#define R_CHECK_NFC_DONE						(R_START * 16 + 37)//NFCģ�����
#define R_CHECK_NRF24L01_DONE					(R_START * 16 + 38)//NRF24L01ģ���Լ����
#define R_CHECK_EPROM_PASS						(R_START * 16 + 39)//�������Լ�ͨ��
#define R_CHECK_INTBUS_PASS						(R_START * 16 + 40)//HMIͨ���Լ�ͨ��
#define R_CHECK_LDR_PASS						(R_START * 16 + 41)//�����������Լ�ͨ��
#define R_CHECK_TEMPER_PASS						(R_START * 16 + 42)//�¶��Լ�ͨ��
#define R_CHECK_USBHOST_PASS					(R_START * 16 + 43)//USBHOSTģ��ͨ��
#define R_CHECK_NFC_PASS						(R_START * 16 + 44)//NFCģ��ͨ��
#define R_CHECK_NRF24L01_PASS					(R_START * 16 + 45)//NRF24L01ģ���Լ�ͨ��
#define R_CHECK_EPROM_FAIL						(R_START * 16 + 46)//�������Լ�ʧ��
#define R_CHECK_INTBUS_FAIL						(R_START * 16 + 47)//HMIͨ���Լ�ʧ��
#define R_CHECK_LDR_FAIL						(R_START * 16 + 48)//�����������Լ�ʧ��
#define R_CHECK_TEMPER_FAIL						(R_START * 16 + 49)//�¶��Լ�ʧ��
#define R_CHECK_USBHOST_FAIL					(R_START * 16 + 50)//USBHOSTģ��ʧ��
#define R_CHECK_NFC_FAIL						(R_START * 16 + 51)//NFCģ��ʧ��
#define R_CHECK_NRF24L01_FAIL					(R_START * 16 + 52)//NRF24L01ģ���Լ�ʧ��
/*****************************************************************************/
#define T100MS_READY_BEEM_DELAY					0//����READY״̬����������ӳ�
#define T100MS_CHECK_EPROM_DELAY				1
#define T100MS_CHECK_INTBUS_DELAY				2
#define T100MS_CHECK_LDR_DELAY					3
#define T100MS_CHECK_TEMPER_DELAY				4
#define T100MS_CHECK_USBHOST_DELAY				5
#define T100MS_CHECK_NFC_DELAY					6
#define T100MS_CHECK_NRF24L01_DELAY				7

#endif