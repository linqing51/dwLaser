#ifndef __APPSPLCADR_H__
#define __APPSPLCADR_H__
/*****************************************************************************/
#define CONFIG_APP_DIODE_HIGH_TEMP				400
#define CONFIG_APP_DRIVE_HIGH_TEMP				650
#define CONFIG_APP_ENVI_HIGH_TEMP				500
/*****************************************************************************/
#define CONFIG_HMI_SCHEME_NUM					16//������
#define CONFIG_HMI_DEFAULT_PASSSWORD0			0x3433//Ĭ������
#define CONFIG_HMI_DEFAULT_PASSSWORD1			0x3231//Ĭ������
#define STATUS_LASER_READY						0x5A
#define STATUS_LASER_STANDBY					0xA5
#define BEEM_MODE_BEEP							0x1234
#define BEEM_MODE_TONE							0x4321
#define AIM_MODE_CW_GREEN						0x5678//������ɫ
#define AIM_MODE_CW_RED							0x9ABC//������ɫ
//������
#define ERROR_CODE_EPROM						0x0001//EPRON ����
#define ERROR_CODE_SPI_FLASH					0x0002//SPI FLSAH����
#define ERROR_CODE_SI7060						0x0003//�¶ȴ�����ͨ�Ŵ���
#define ERROR_CODE_MCP79412						0x0004//RTCͨ�Ŵ���
#define ERROR_CODE_LDR0							0x0005//����������0����
#define ERROR_CODE_LDR1							0x0006//����������1����
#define ERROR_CODE_TEMPER						0x0007//�¶ȴ���������
#define ERROR_CODE_USBHOST						0x0008//USB HOSTģ�����
#define ERROR_CODE_NFC							0x0009//NFCģ�����
#define ERROR_CODE_NRF24L01						0x0010//NRF24L01ģ�����
#define ERRPR_CODE_NOERR						0xFFFF//�޴���
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
#define EM_DIODE_TEMP0							(EM_START + 25)//�������¶�0
#define EM_DIODE_TEMP1							(EM_START + 26)//�������¶�1
#define EM_DRIVE_TEMP							(EM_START + 27)//�������¶�
#define EM_ENVI_TEMP							(EM_START + 28)//�����¶�
#define EM_DIODE_HIGH_TEMP						(EM_START + 29)//�����ܹ�����ֵ
#define EM_DRIVE_HIGH_TEMP						(EM_START + 30)//������������ֵ
#define EM_ENVI_HIGH_TEMP						(EM_START + 31)//����������ֵ
/*****************************************************************************/
#define EM_EPID0_TAB_OUT						(EM_START + 32)//EPID���ֵ��ַ
#define EM_EPID0_TAB_REF						(EM_START + 33)//EPID���ö�ֵ
#define EM_EPID0_TAB_VFB						(EM_START + 34)//EPID����ֵ
#define EM_EPID0_TAB_KP							(EM_START + 35)//EPID�������� XX.XXX 0-65.535
#define	EM_EPID0_TAB_KI							(EM_START +	36)//EPID���ֳ��� XX.XXX 0-65.535		
#define EM_EPID0_TAB_TD 						(EM_START + 37)//EPID΢��ʱ�䳣�� XX.XXX 0-65.535
#define EM_EPID0_TAB_TS							(EM_START + 38)//EPID����ʱ���� 1-3000 ��λ0.01S
#define EM_EPID0_TAB_EN_FP32L					(EM_START +	39)//EPID��ǰ���ֵ FP32 
#define EM_EPID0_TAB_EN_FP32H					(EM_START +	40)//EPID��ǰ���ֵ FP32 
#define EM_EPID0_TAB_VFB1_FP32L 				(EM_START +	41)//EPIDǰ1�����ֵ FP32
#define EM_EPID0_TAB_VFB1_FP32H					(EM_START +	42)//EPIDǰ1�����ֵ FP32
#define EM_EPID0_TAB_MAX						(EM_START + 43)//EPID����������		691
#define EM_EPID0_TAB_MIN						(EM_START + 44)//EPID�����С����		692
#define EM_EPID0_TAB_BIAS						(EM_START +	45)//EPID���ƫ��			693
#define EM_EPID0_TAB_TSC						(EM_START + 46)//EPID�����ʱ��			694
#define EM_EPID0_TAB_KP_SUM_FP32L				(EM_START +	47)//EPID�����ۼ�ֵ FP32	695
#define EM_EPID0_TAB_KP_SUM_FP32H				(EM_START +	48)//EPID�����ۼ�ֵ FP32	696
#define EM_EPID0_TAB_KI_SUM_FP32L				(EM_START +	49)//EPID΢���ۼ�ֵ FP32	697
#define EM_EPID0_TAB_KI_SUM_FP32H				(EM_START +	50)//EPID΢���ۼ�ֵ FP32	698
#define EM_EPID0_TAB_KD_SUM_FP32L				(EM_START +	51)//EPID΢���ۼ�ֵ FP32	699
#define EM_EPID0_TAB_KD_SUM_FP32H				(EM_START +	52)//EPID΢���ۼ�ֵ FP32	700
#define EM_EPID0_TAB_FOUT_FP32L					(EM_START +	53)//EPID����ۼ�ֵ FP32	701
#define EM_EPID0_TAB_FOUT_FP32H					(EM_START +	54)//EPID����ۼ�ֵ FP32	702
#define EM_LASER_CURRENT_0						(EM_START +	55)//����������0			703
#define EM_LASER_CURRENT_1						(EM_START +	56)//����������1			704
#define EM_HMI_OPERA_STEP						(EM_START +	57)//��������				705				
#define EM_ERROR_CODE							(EM_START + 58)//������					706

#define EM_DC_PAGE								(EM_START + 128)//HMIҳ���� 			776
#define EM_DC_PASSCODE_INDEX					(EM_START + 129)//��������λ����		777
#define EM_DC_NEW_PASSCODE0						(EM_START + 130)//����������0			778
#define EM_DC_NEW_PASSCODE1						(EM_START + 131)//����������1			779
#define EM_DC_NEW_PASSCODE2						(EM_START + 132)//����������0			778
#define EM_DC_NEW_PASSCODE3						(EM_START + 133)//����������1			779
#define EM_DC_DEFAULT_PASSCODE0					(EM_START + 134)//Ĭ������0				780
#define EM_DC_DEFAULT_PASSCODE1					(EM_START + 135)//Ĭ������1				781
#define EM_DC_DEFAULT_PASSCODE2					(EM_START + 136)//Ĭ������1				781
#define EM_DC_DEFAULT_PASSCODE3					(EM_START + 137)//Ĭ������1				781
#define EM_DC_DISPLAY_RELEASE_TIME				(EM_START + 138)//��ʾ����ʱ��			782
#define EM_DC_DISPLAY_RELEASE_ENERGY			(EM_START + 139)//��ʾ��������			783

/*****************************************************************************/
#define DM_LASER_SCHEME_NAME					(DM_START +  0)//��������				72
#define DM_LASER_SELECT							(DM_START +  17)//ͨ��ѡ��				89			
#define DM_LASER_PULSE_MODE						(DM_START +  18)//����ģʽ				90
#define DM_LASER_POWER_0						(DM_START +  19)//ͨ��0����				91
#define DM_LASER_POWER_1						(DM_START +  20)//ͨ��1����				92
#define DM_LASER_POSWIDTH						(DM_START +  21)//������				93
#define DM_LASER_NEGWIDTH						(DM_START +  22)//������				94
#define DM_LASER_GROUP							(DM_START +  23)//������				95
#define DM_LASER_SPACE							(DM_START +  24)//������				96

#define DM_SCHEME_START_0						(DM_START +   0)//����0�洢����ʼ		72
#define DM_SCHEME_END_0							(DM_START +  24)//����0�洢������		96

#define DM_SCHEME_START_1						(DM_START +  25)//����1�洢����ʼ		
#define DM_SCHEME_END_1							(DM_START +  49)//����1�洢������

#define DM_SCHEME_START_2						(DM_START +  50)//����2�洢����ʼ
#define DM_SCHEME_END_2							(DM_START +  74)//����2�洢������

#define DM_SCHEME_START_3						(DM_START +  75)//����3�洢����ʼ
#define DM_SCHEME_END_3							(DM_START +  99)//����3�洢������

#define DM_SCHEME_START_4						(DM_START + 100)//����4�洢����ʼ
#define DM_SCHEME_END_4							(DM_START + 124)//����4�洢������

#define DM_SCHEME_START_5						(DM_START + 125)//����5�洢����ʼ
#define DM_SCHEME_END_5							(DM_START + 149)//����5�洢������

#define DM_SCHEME_START_6						(DM_START + 150)//����6�洢����ʼ
#define DM_SCHEME_END_6							(DM_START + 174)//����6�洢������

#define DM_SCHEME_START_7						(DM_START + 175)//����7�洢����ʼ
#define DM_SCHEME_END_7							(DM_START + 199)//����7�洢������

#define DM_SCHEME_START_8						(DM_START + 200)//����8�洢����ʼ
#define DM_SCHEME_END_8							(DM_START + 224)//����8�洢������

#define DM_SCHEME_START_9						(DM_START + 225)//����9�洢����ʼ
#define DM_SCHEME_END_9							(DM_START + 249)//����9�洢������

#define DM_SCHEME_START_10						(DM_START + 250)//����10�洢����ʼ
#define DM_SCHEME_END_10						(DM_START + 274)//����10�洢������

#define DM_SCHEME_START_11						(DM_START + 275)//����11�洢����ʼ
#define DM_SCHEME_END_11						(DM_START + 299)//����11�洢������

#define DM_SCHEME_START_12						(DM_START + 300)//����12�洢����ʼ
#define DM_SCHEME_END_12						(DM_START + 324)//����12�洢������

#define DM_SCHEME_START_13						(DM_START + 325)//����13�洢����ʼ
#define DM_SCHEME_END_13						(DM_START + 349)//����13�洢������

#define DM_SCHEME_START_14						(DM_START + 350)//����14�洢����ʼ
#define DM_SCHEME_END_14						(DM_START + 374)//����14�洢������

#define DM_SCHEME_START_15						(DM_START + 375)//����15�洢����ʼ
#define DM_SCHEME_END_15						(DM_START + 399)//����15�洢������

#define DM_CORR_TAB0_POWER0						(DM_START + 400)//����У����0����0 
#define DM_CORR_TAB0_POWER1						(DM_START + 401)//����У����0����2 
#define DM_CORR_TAB0_POWER2						(DM_START + 402)//����У����0����4 
#define DM_CORR_TAB0_POWER3						(DM_START + 403)//����У����0����6 
#define DM_CORR_TAB0_POWER4						(DM_START + 404)//����У����0����8 
#define DM_CORR_TAB0_POWER5						(DM_START + 405)//����У����0����10 
#define DM_CORR_TAB0_POWER6						(DM_START + 406)//����У����0����12 
#define DM_CORR_TAB0_POWER7						(DM_START + 407)//����У����0����14 
#define DM_CORR_TAB0_POWER8						(DM_START + 408)//����У����0����16 
#define DM_CORR_TAB0_POWER9						(DM_START + 409)//����У����0����18 
#define DM_CORR_TAB0_POWER10					(DM_START + 410)//����У����0����20 
#define DM_CORR_TAB0_POWER11					(DM_START + 411)//����У����0����22 
#define DM_CORR_TAB0_POWER12					(DM_START + 412)//����У����0����24 
#define DM_CORR_TAB0_POWER13					(DM_START + 413)//����У����0����26 
#define DM_CORR_TAB0_POWER14					(DM_START + 414)//����У����0����28 
#define DM_CORR_TAB0_POWER15					(DM_START + 415)//����У����0����30 
#define DM_CORR_TAB0_POWER16					(DM_START + 416)//����У����0����32 
#define DM_CORR_TAB0_POWER17					(DM_START + 417)//����У����0����34 
#define DM_CORR_TAB0_POWER18					(DM_START + 418)//����У����0����36
#define DM_CORR_TAB0_POWER19					(DM_START + 419)//����У����0����38
#define DM_CORR_TAB0_POWER20					(DM_START + 420)//����У����0����40

#define DM_CORR_TAB1_POWER0						(DM_START + 421)//����У����1����0 			
#define DM_CORR_TAB1_POWER1						(DM_START + 422)//����У����1����2
#define DM_CORR_TAB1_POWER2						(DM_START + 423)//����У����1����4
#define DM_CORR_TAB1_POWER3						(DM_START + 424)//����У����1����6 
#define DM_CORR_TAB1_POWER4						(DM_START + 425)//����У����1����8 
#define DM_CORR_TAB1_POWER5						(DM_START + 426)//����У����1����10 
#define DM_CORR_TAB1_POWER6						(DM_START + 427)//����У����1����12 
#define DM_CORR_TAB1_POWER7						(DM_START + 428)//����У����1����14 
#define DM_CORR_TAB1_POWER8						(DM_START + 429)//����У����1����16 
#define DM_CORR_TAB1_POWER9						(DM_START + 430)//����У����1����18 
#define DM_CORR_TAB1_POWER10					(DM_START + 431)//����У����1����20 
#define DM_CORR_TAB1_POWER11					(DM_START + 432)//����У����1����22 
#define DM_CORR_TAB1_POWER12					(DM_START + 433)//����У����1����24 
#define DM_CORR_TAB1_POWER13					(DM_START + 434)//����У����1����26 
#define DM_CORR_TAB1_POWER14					(DM_START + 435)//����У����1����28 
#define DM_CORR_TAB1_POWER15					(DM_START + 436)//����У����1����30 
#define DM_CORR_TAB1_POWER16					(DM_START + 437)//����У����1����32 
#define DM_CORR_TAB1_POWER17					(DM_START + 438)//����У����1����34 
#define DM_CORR_TAB1_POWER18					(DM_START + 439)//����У����1����36 
#define DM_CORR_TAB1_POWER19					(DM_START + 440)//����У����1����38
#define DM_CORR_TAB1_POWER20					(DM_START + 441)//����У����1����40

#define DM_SCHEME_NUM							(DM_START + 442)//ѡ��ķ������ ��8λ������ ��8λ����ʹ��
#define DM_BEEM_VOLUME							(DM_START + 443)//����������
#define DM_BEEM_MODE							(DM_START + 444)//������ģʽ
#define DM_AIM_MODE								(DM_START + 445)//ָʾ����ģʽ
#define DM_AIM_RED_BRG							(DM_START + 446)//��ɫָʾ��������
#define DM_AIM_GREEN_BRG						(DM_START + 447)//��ɫָʾ��������
#define DM_LCD_BRG								(DM_START + 448)//��Ļ����
#define DM_DC_OLD_PASSCODE0						(DM_START + 449)//��������0-1
#define DM_DC_OLD_PASSCODE1						(DM_START + 450)//��������2-3
#define DM_DC_OLD_PASSCODE2						(DM_START + 451)//��������0-1
#define DM_DC_OLD_PASSCODE3						(DM_START + 452)//��������2-3
#define DM_SYS_RUNTIME_L						(DM_START + 453)//ϵͳ�ۼ�����ʱ����L 32BIT
#define DM_SYS_RUNTIME_H						(DM_START + 454)//ϵͳ�ۼ�����ʱ����H 32BIT
#define DM_LAR_RUNTIME_L						(DM_START + 455)//�����ۼƷ���ʱ����L 32BIT
#define DM_LAR_RUNTIME_H						(DM_START + 456)//�����ۼƷ���ʱ����H 32BIT
#define DM_RELEASE_DATA_YEAR					(DM_START + 457)//����������		
#define DM_RELEASE_DATA_MONTH					(DM_START + 458)//����������
#define DM_RELEASE_DATA_DAY						(DM_START + 459)//����������
#define DM_LANGUAGE								(DM_START + 460)//����ѡ��
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
#define Y_OUT3									(Y_START * 16 + 3)//YOUT3 ����
#define Y_OUT4									(Y_START * 16 + 4)//YOUT4 ����
#define Y_OUT5									(Y_START * 16 + 5)//YOUT5 ����
#define Y_OUT6									(Y_START * 16 + 6)//YOUT6 ����
#define Y_OUT7									(Y_START * 16 + 7)//YOUT7 ����
#define Y_FAN0									(Y_START * 16 + 8)//YOUT8 ���ȿ���0
#define Y_FAN1									(Y_START * 16 + 9)//YOUT9 ���ȿ���1
#define Y_TEC0									(Y_START * 16 + 10)//YOUT10 ���俪��0
#define Y_TEC1									(Y_START * 16 + 11)//YOUT11 ���俪��1
/*****************************************************************************/
#define R_FIBER_ID_PASS_0						(R_START * 16 + 0)//ͨ��0����ID��־
#define R_FIBER_ID_PASS_1						(R_START * 16 + 1)//ͨ��1����ID��־
#define R_DIODE_TEMP_HIGH_0						(R_START * 16 + 2)//ͨ��0�����ܸ��±�־
#define R_DIODE_TEMP_HIGH_1						(R_START * 16 + 3)//ͨ��1�����ܸ��±�־
#define R_DRIVE_TEMP_HIGH						(R_START * 16 + 4)//���������±�־
#define R_ENVI_TEMP_HIGH						(R_START * 16 + 5)//�����¶ȱ��
#define R_DRIVE_FAULT_0							(R_START * 16 + 6)//ͨ��0���������ϱ�־
#define R_DRIVE_FAULT_1							(R_START * 16 + 7)//ͨ��1���������ϱ�־
#define R_SAFE_FAULT							(R_START * 16 + 8)//��ȫ��־
#define R_SCHEME_LOAD_REQ						(R_START * 16 + 9)//������������
#define R_SHCEME_SAVE_REQ						(R_START * 16 + 10)//������������
//HMI���״̬
#define R_DCHMI_RESET_REQ						(R_START * 16 + 47)//HMI��λ����
#define R_DCHMI_RESET_DOING						(R_START * 16 + 48)//HMI��λ��
#define R_DCHMI_RESET_DONE						(R_START * 16 + 49)//HMI��λ���	
#define R_DCHMI_UPDATEUI_REQ					(R_START * 16 + 50)//HMI���ݸ�������
#define R_DCHMI_UPDATEUI_DOING					(R_START * 16 + 51)//HMI���ݸ�����
#define R_DCHMO_UPDATEUI_DONE					(R_START * 16 + 52)//HMI���ݸ����������
#define R_DCHMI_RESTORE_REQ						(R_START * 16 + 53)//HMI��FLASH�лָ���������
#define R_DCHMI_RESTORE_DOING					(R_START * 16 + 54)//HMI��FLASH�лָ���
#define R_DCHMI_RESTORE_DONE					(R_START * 16 + 55)//HMI��FLASH�лָ��������	
//�Լ�״̬
#define R_CHECK_FLOAT_DONE						(R_START * 16 + 100)//�����Լ����
#define R_CHECK_EPROM_DONE						(R_START * 16 + 101)//�洢���Լ����
#define R_CHECK_SI7060_DONE						(R_START * 16 + 102)//SI7060�¶ȴ������Լ����
#define R_CHECK_MCP79412_DONE					(R_START * 16 + 103)//����RTC�Լ����
#define R_CHECK_BACKUP_MEMORY_DONE				(R_START * 16 + 104)//�ⲿFLASH�Լ����
#define R_CHECK_CH376_DONE						(R_START * 16 + 105)//USB CH376�Լ����
#define R_CHECK_PN7150B0HN_DONE					(R_START * 16 + 106)//PN7150B0HNģ�����
#define R_CHECK_NRF24L01_DONE					(R_START * 16 + 107)//NRF24L01ģ���Լ����
#define R_CHECK_LASER_DRIVER_DONE				(R_START * 16 + 108)//�����������Լ����
#define R_CHECK_TEMPERATURE_DONE				(R_START * 16 + 109)//�¶��Լ����
#define R_CHECK_SAFETY_INTERLOCK_DONE			(R_START * 16 + 110)//��ȫ�����Լ����
#define R_CHECK_WIRE_FOOTCONTROL_DONE			(R_START * 16 + 111)//���߽�̤�Լ����
#define R_CHECK_FIBER_SENSOR_DONE				(R_START * 16 + 112)//���˴������Լ����
#define R_CHECK_WIRELESS_FOOTCONTROL_DONE		(R_START * 16 + 113)//���߽�̤�Լ����
#define R_CHECK_PROBATION_DONE					(R_START * 16 + 114)//�������Լ����
 
#define R_CHECK_FLOAT_PASS						(R_START * 16 + 120)//�����Լ�ͨ��
#define R_CHECK_EPROM_PASS						(R_START * 16 + 121)//�洢���Լ�ͨ��
#define R_CHECK_SI7060_PASS						(R_START * 16 + 122)//SI7060�¶ȴ������Լ�ͨ��
#define R_CHECK_MCP79412_PASS					(R_START * 16 + 123)//����RTC�Լ�ͨ��
#define R_CHECK_BACKUP_MEMORY_PASS				(R_START * 16 + 124)//�ⲿFLASH�Լ�ͨ��
#define R_CHECK_CH376_PASS						(R_START * 16 + 125)//USB CH376�Լ��Լ�ͨ��
#define R_CHECK_PN7150B0HN_PASS					(R_START * 16 + 126)//NFCģ���Լ�ͨ��
#define R_CHECK_NRF24L01_PASS					(R_START * 16 + 127)//NRF24L01ģ���Լ�ͨ��
#define R_CHECK_LASER_DRIVER_PASS				(R_START * 16 + 128)//�����������Լ�ͨ��
#define R_CHECK_TEMPERATURE_PASS				(R_START * 16 + 129)//�¶��Լ�ͨ��
#define R_CHECK_SAFETY_INTERLOCK_PASS			(R_START * 16 + 130)//��ȫ�����Լ�ͨ��
#define R_CHECK_WIRE_FOOTCONTROL_PASS			(R_START * 16 + 131)//���߽�̤�Լ�ͨ��
#define R_CHECK_FIBER_SENSOR_PASS				(R_START * 16 + 132)//���˴������Լ�ͨ��
#define R_CHECK_WIRELESS_FOOTCONTROL_PASS		(R_START * 16 + 133)//���߽�̤�Լ�ͨ��
#define R_CHECK_PROBATION_PASS					(R_START * 16 + 134)//�������Լ�ͨ��

#define R_CHECK_FLOAT_FAIL						(R_START * 16 + 140)//�����Լ�ʧ�� 
#define R_CHECK_EPROM_FAIL						(R_START * 16 + 141)//�洢���Լ�ʧ��
#define R_CHECK_SI7060_FAIL						(R_START * 16 + 142)//SI7060�¶ȴ������Լ�ʧ��
#define R_CHECK_MCP79412_FAIL					(R_START * 16 + 143)//����RTC�Լ�ʧ��
#define R_CHECK_BACKUP_MEMORY_FAIL				(R_START * 16 + 144)//�ⲿFLASH�Լ�ʧ��
#define R_CHECK_CH376_FAIL						(R_START * 16 + 145)//USB CH376�Լ��Լ�ʧ��
#define R_CHECK_PN7150B0HN_FAIL					(R_START * 16 + 146)//NFCģ���Լ�ʧ��
#define R_CHECK_NRF24L01_FAIL					(R_START * 16 + 147)//NRF24L01ģ���Լ�ʧ��
#define R_CHECK_LASER_DRIVER_FAIL				(R_START * 16 + 148)//�����������Լ�ʧ��
#define R_CHECK_TEMPERATURE_FAIL				(R_START * 16 + 149)//�¶��Լ�ʧ��
#define R_CHECK_SAFETY_INTERLOCK_FAIL			(R_START * 16 + 150)//��ȫ�����Լ�ʧ��
#define R_CHECK_WIRE_FOOTCONTROL_FAIL			(R_START * 16 + 151)//���߽�̤�Լ�ʧ��
#define R_CHECK_FIBER_SENSOR_FAIL				(R_START * 16 + 152)//���˴������Լ�ʧ��
#define R_CHECK_WIRELESS_FOOTCONTROL_FAIL		(R_START * 16 + 153)//���߽�̤�Լ�ʧ��
#define R_CHECK_PROBATION_FAIL					(R_START * 16 + 154)//�������Լ�ʧ��
/*****************************************************************************/
#define R_STANDBY_KEY_POSWIDTH_ADD_DOWN			(R_START * 16 + 149)
#define R_STANDBY_KEY_POSWIDTH_ADD_UP			(R_START * 16 + 150)

#define R_STANDBY_KEY_POSWIDTH_DEC_DOWN			(R_START * 16 + 151)
#define R_STANDBY_KEY_POSWIDTH_DEC_UP			(R_START * 16 + 152)

#define R_STANDBY_KEY_NEGWIDTH_ADD_DOWN			(R_START * 16 + 153)
#define R_STANDBY_KEY_NEGWIDTH_ADD_UP			(R_START * 16 + 154)

#define R_STANDBY_KEY_NEGWIDTH_DEC_DOWN			(R_START * 16 + 155)
#define R_STANDBY_KEY_NEGWIDTH_DEC_UP			(R_START * 16 + 156)

#define R_STANDBY_KEY_GROUP_ADD_DOWN			(R_START * 16 + 157)
#define R_STANDBY_KEY_GROUP_ADD_UP				(R_START * 16 + 158)

#define R_STANDBY_KEY_GROUP_DEC_DOWN			(R_START * 16 + 159)
#define R_STANDBY_KEY_GROUP_DEC_UP				(R_START * 16 + 160)

#define R_STANDBY_KEY_SPACE_ADD_DOWN			(R_START * 16 + 161)
#define R_STANDBY_KEY_SPACE_ADD_UP				(R_START * 16 + 162)

#define R_STANDBY_KEY_SPACE_DEC_DOWN			(R_START * 16 + 163)
#define R_STANDBY_KEY_SPACE_DEC_UP				(R_START * 16 + 164)

#define R_STANDBY_KEY_POWER_CH0_ADD_DOWN		(R_START * 16 + 165)
#define R_STANDBY_KEY_POWER_CH0_ADD_UP			(R_START * 16 + 166)

#define R_STANDBY_KEY_POWER_CH0_DEC_DOWN		(R_START * 16 + 167)
#define R_STANDBY_KEY_POWER_CH0_DEC_UP			(R_START * 16 + 168)

#define R_STANDBY_KEY_POWER_CH1_ADD_DOWN		(R_START * 16 + 169)
#define R_STANDBY_KEY_POWER_CH1_ADD_UP			(R_START * 16 + 170)

#define R_STANDBY_KEY_POWER_CH1_DEC_DOWN		(R_START * 16 + 171)
#define R_STANDBY_KEY_POWER_CH1_DEC_UP			(R_START * 16 + 172)

#define R_STANDBY_KEY_STANDBY_DOWN				(R_START * 16 + 173)
#define R_STANDBY_KEY_STANDBY_UP				(R_START * 16 + 174)

#define R_STANDBY_KEY_ENERGY_RESET_DOWN			(R_START * 16 + 175)
#define R_STANDBY_KEY_ENERGY_RESET_UP			(R_START * 16 + 176)

#define R_STANDBY_KEY_SELECT_CH0_DOWN			(R_START * 16 + 177)
#define R_STANDBY_KEY_SELECT_CH0_UP				(R_START * 16 + 178)

#define R_STANDBY_KEY_SELECT_CH1_DOWN			(R_START * 16 + 179)
#define R_STANDBY_KEY_SELECT_CH1_UP				(R_START * 16 + 180)
	
#define R_STANDBY_KEY_SELECT_BOTH_DOWN			(R_START * 16 + 181)
#define R_STANDBY_KEY_SELECT_BOTH_UP			(R_START * 16 + 182)

#define R_STANDB_KEY_MODE_CW_DOWN				(R_START * 16 + 183)
#define R_STANDB_KEY_MODE_CW_UP					(R_START * 16 + 184)

#define R_STANDBY_KEY_MODE_MP_DOWN				(R_START * 16 + 185)
#define R_STANDBY_KEY_MODE_MP_UP				(R_START * 16 + 186)

#define R_STANDBY_KEY_MODE_GP_DOWN				(R_START * 16 + 187)
#define R_STANDBY_KEY_MODE_GP_UP				(R_START * 16 + 188)

#define R_STANDBY_KEY_MODE_EVLA_SEGMENT_DOWN	(R_START * 16 + 189)
#define R_STANDBY_KEY_MODE_EVLA_SEGMENT_UP		(R_START * 16 + 190)

#define R_STANDBY_KEY_MODE_EVLA_SIGNAL_DOWN		(R_START * 16 + 191)
#define R_STANDBY_KEY_MODE_EVLA_SIGNAL_UP		(R_START * 16 + 192)

#define R_STANDBY_KEY_MODE_DERMA_DOWN			(R_START * 16 + 193)
#define R_STANDBY_KEY_MODE_DERMA_UP				(R_START * 16 + 194)

#define R_STANDBY_KEY_OPTION_DOWN				(R_START * 16 + 195)
#define R_STANDBY_KEY_OPTION_UP					(R_START * 16 + 196)
/*****************************************************************************/
#define R_READY_KEY_READY_DOWN					(R_START * 16 + 197)
#define R_READY_KEY_READY_UP					(R_START * 16 + 198)
/*****************************************************************************/
#define R_OPTION_KEY_ENTER_CORRECTION_DOWN		(R_START * 16 + 199)
#define R_OPTION_KEY_ENTER_CORRECTION_UP		(R_START * 16 + 200)

#define R_OPTION_KEY_ENTER_INFORMATION_DOWN		(R_START * 16 + 201)
#define R_OPTION_KEY_ENTER_INFORMATION_UP		(R_START * 16 + 202)

#define R_OPTION_KEY_ENTER_SCHEME_DOWN			(R_START * 16 + 203)
#define R_OPTION_KEY_ENTER_SCHEME_UP			(R_START * 16 + 204)

#define R_OPTION_KEY_ENTER_OK_DOWN				(R_START * 16 + 205)
#define R_OPTION_KEY_ENTER_OK_UP				(R_START * 16 + 206)
/*****************************************************************************/
#define R_INFORMATION_KEY_OK_DOWN				(R_START * 16 + 207)
#define R_INFORMATION_KEY_OK_UP					(R_START * 16 + 208)
/*****************************************************************************/
#define R_SCHEME_KEY_RENAME_DOWN				(R_START * 16 + 209)
#define R_SCHEME_KEY_RENAME_UP					(R_START * 16 + 210)

#define R_SCHEME_KEY_SAVE_USB_DOWN				(R_START * 16 + 211)
#define R_SCHEME_KEY_SAVE_USB_UP				(R_START * 16 + 212)

#define R_SCHEME_KEY_LOAD_USB_DOWN				(R_START * 16 + 213)
#define R_SCHEME_KEY_LOAD_USB_UP				(R_START * 16 + 214)

#define R_SCHEME_KEY_ENTER_STANDBY_DOWN			(R_START * 16 + 215)
#define R_SCHEME_KEY_ENTER_STANDBY_UP			(R_START * 16 + 216)

#define R_SCHEME_KEY_SCHEME_SELECT_0_DOWN		(R_START * 16 + 217)		
#define R_SCHEME_KEY_SCHEME_SELECT_0_UP			(R_START * 16 + 218)

#define R_SCHEME_KEY_SCHEME_SELECT_1_DOWN		(R_START * 16 + 219)
#define R_SCHEME_KEY_SCHEME_SELECT_1_UP			(R_START * 16 + 220)

#define R_SCHEME_KEY_SCHEME_SELECT_2_DOWN		(R_START * 16 + 221)
#define R_SCHEME_KEY_SCHEME_SELECT_2_UP			(R_START * 16 + 222)

#define R_SCHEME_KEY_SCHEME_SELECT_3_DOWN		(R_START * 16 + 223)
#define R_SCHEME_KEY_SCHEME_SELECT_3_UP			(R_START * 16 + 224)

#define R_SCHEME_KEY_SCHEME_SELECT_4_DOWN		(R_START * 16 + 225)
#define R_SCHEME_KEY_SCHEME_SELECT_4_UP			(R_START * 16 + 226)

#define R_SCHEME_KEY_SCHEME_SELECT_5_DOWN		(R_START * 16 + 227)
#define R_SCHEME_KEY_SCHEME_SELECT_5_UP			(R_START * 16 + 228)

#define R_SCHEME_KEY_SCHEME_SELECT_6_DOWN		(R_START * 16 + 229)
#define R_SCHEME_KEY_SCHEME_SELECT_6_UP			(R_START * 16 + 230)

#define R_SCHEME_KEY_SCHEME_SELECT_7_DOWN		(R_START * 16 + 231)
#define R_SCHEME_KEY_SCHEME_SELECT_7_UP			(R_START * 16 + 232)

#define R_SCHEME_KEY_SCHEME_SELECT_8_DOWN		(R_START * 16 + 233)
#define R_SCHEME_KEY_SCHEME_SELECT_8_UP			(R_START * 16 + 234)

#define R_SCHEME_KEY_SCHEME_SELECT_9_DOWN		(R_START * 16 + 235)
#define R_SCHEME_KEY_SCHEME_SELECT_9_UP			(R_START * 16 + 236)

#define R_SCHEME_KEY_SCHEME_SELECT_10_DOWN		(R_START * 16 + 237)
#define R_SCHEME_KEY_SCHEME_SELECT_10_UP		(R_START * 16 + 238)

#define R_SCHEME_KEY_SCHEME_SELECT_11_DOWN		(R_START * 16 + 239)
#define R_SCHEME_KEY_SCHEME_SELECT_11_UP		(R_START * 16 + 240)

#define R_SCHEME_KEY_SCHEME_SELECT_12_DOWN		(R_START * 16 + 241)
#define R_SCHEME_KEY_SCHEME_SELECT_12_UP		(R_START * 16 + 242)

#define R_SCHEME_KEY_SCHEME_SELECT_13_DOWN		(R_START * 16 + 243)
#define R_SCHEME_KEY_SCHEME_SELECT_13_UP		(R_START * 16 + 244)

#define R_SCHEME_KEY_SCHEME_SELECT_14_DOWN		(R_START * 16 + 245)
#define R_SCHEME_KEY_SCHEME_SELECT_14_UP		(R_START * 16 + 246)

#define R_SCHEME_KEY_SCHEME_SELECT_15_DOWN		(R_START * 16 + 247)
#define R_SCHEME_KEY_SCHEME_SELECT_15_UP		(R_START * 16 + 248)

#define R_SCHEME_TEXTDISPLAY_SCHEME_0_DOWN		(R_START * 16 + 249)
#define R_SCHEME_TEXTDISPLAY_SCHEME_0_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_1_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_1_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_2_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_2_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_3_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_3_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_4_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_4_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_5_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_5_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_6_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_6_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_7_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_7_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_8_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_8_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_9_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_9_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_10_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_10_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_11_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_11_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_12_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_12_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_13_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_13_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_14_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_14_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_15_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_15_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_POSWIDTH_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_POSWIDTH_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_NEGWIDTH_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_NEGWIDTH_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_GROUP_DOWN			(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_GROUP_UP			(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPALY_SPACE_DOWN			(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPALY_SPACE_UP			(R_START * 16 + 250)
/*****************************************************************************/
#define T100MS_HMI_POWERUP_DELAY				0//HMI������λ��ʱ
#define T100MS_CHECK_PROCESSOR_DELAY			1//�洢���Լ�ȴ��ӳ�
#define T100MS_CHECK_EPROM_DELAY				2//�����Լ�ȴ��ӳ�
#define T100MS_CHECK_SI7060_DELAY				3//
#define T100MS_CHECK_MCP79412_DELAY				4//
#define T100MS_CHECK_SPI_FLASH_DELAY			5//
#define T100MS_CHECK_CH376_DELAY				6//
#define T100MS_CHECK_PN7150B0HN_DELAY			7//NFC����ģ��ȴ��ӳ�
#define T100MS_CHECK_NRF24L01_DELAY				8//�����������Լ�ȴ��ӳ�
#define T100MS_CHECK_TEMPERATURE_DELAY			9
#define T100MS_CHECK_LASER_DRIVER_DELAY			10
#define T100MS_CHECK_SAFETY_INTERLOCK_DELAY		11
#define T100MS_CHECK_WIRE_FOOTCONTROL_DELAY		12
#define T100MS_CHECK_FIBER_SENSOR_DELAY			13
#define T100MS_CHECK_WIRELESS_FOOTCONTROL_DELAY	14
#define T100MS_CHECK_PROBATION_DELAY			15//USBHOSTģ��ȴ��ӳ�
#define T100MS_ENTER_PASSCODE_DELAY				16
#define T100MS_READY_BEEM_DELAY					20//����READY״̬����������ӳ�
/*****************************************************************************/
#define T10MS_POSWIDTH_ADD_KEYDOWN_DELAY		3
#define T10MS_POSWIDTH_DEC_KEYDOWN_DELAY		4
#define T10MS_NEGWIDTH_ADD_KEYDOWN_DELAY		5
#define T10MS_NEGWIDTH_DEC_KEYDOWN_DELAY		6

#define T10MS_GROUP_ADD_KEYDOWN_DELAY			7
#define T10MS_GROUP_DEC_KEYDOWN_DELAY			8
#define T10MS_SPACE_ADD_KEYDOWN_DELAY			9
#define T10MS_SPACE_DEC_KEYDOWN_DELAY			10

#endif