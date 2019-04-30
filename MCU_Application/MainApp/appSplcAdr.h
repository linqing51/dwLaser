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
//������
#define ERROR_CODE_EPROM						0x0001//EPRON ����
#define ERROR_CODE_SPI_FLASH					0x0002//SPI FLSAH����
#define ERROR_CODE_INTBUS						0x0003//����ͨ�Ŵ���
#define ERROR_CODE_LDR0							0x0004//����������0����
#define ERROR_CODE_LDR1							0x0005//����������1����
#define ERROR_CODE_TEMPER						0x0006//�¶ȴ���������
#define ERROR_CODE_USBHOST						0x0007//USB HOSTģ�����
#define ERROR_CODE_NFC							0x0008//NFCģ�����
#define ERROR_CODE_NRF24L01						0x0009//NRF24L01ģ�����
#define ERRPR_CODE_NOERR						0xFFFF//�޴���
/*****************************************************************************/
#define EM_LASER_SCHEME_NAME					(EM_START + 0)//�������� 648
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
#define EM_EPID0_TAB_MAX						(EM_START + 43)//EPID����������		
#define EM_EPID0_TAB_MIN						(EM_START + 44)//EPID�����С����
#define EM_EPID0_TAB_BIAS						(EM_START +	45)//EPID���ƫ��
#define EM_EPID0_TAB_TSC						(EM_START + 46)//EPID�����ʱ��
#define EM_EPID0_TAB_KP_SUM_FP32L				(EM_START +	47)//EPID�����ۼ�ֵ FP32
#define EM_EPID0_TAB_KP_SUM_FP32H				(EM_START +	48)//EPID�����ۼ�ֵ FP32
#define EM_EPID0_TAB_KI_SUM_FP32L				(EM_START +	49)//EPID΢���ۼ�ֵ FP32
#define EM_EPID0_TAB_KI_SUM_FP32H				(EM_START +	50)//EPID΢���ۼ�ֵ FP32
#define EM_EPID0_TAB_KD_SUM_FP32L				(EM_START +	51)//EPID΢���ۼ�ֵ FP32
#define EM_EPID0_TAB_KD_SUM_FP32H				(EM_START +	52)//EPID΢���ۼ�ֵ FP32
#define EM_EPID0_TAB_FOUT_FP32L					(EM_START +	53)//EPID����ۼ�ֵ FP32
#define EM_EPID0_TAB_FOUT_FP32H					(EM_START +	54)//EPID����ۼ�ֵ FP32
#define EM_LASER_CURRENT_0						(EM_START +	55)//����������0
#define EM_LASER_CURRENT_1						(EM_START +	56)//����������1
#define EM_HMI_OPERA_STEP						(EM_START +	57)//��������
#define EM_ERROR_CODE							(EM_START + 58)//������					

#define EM_DC_PAGE								(EM_START + 128)//HMIҳ���� 			776
#define EM_DC_PASSCODE_INDEX					(EM_START + 129)//��������λ����		777
#define EM_DC_NEW_PASSCODE0						(EM_START + 130)//����������0			778
#define EM_DC_NEW_PASSCODE1						(EM_START + 131)//����������1			779
#define EM_DC_DEFAULT_PASSCODE0					(EM_START + 132)//Ĭ������0				780
#define EM_DC_DEFAULT_PASSCODE1					(EM_START + 133)//Ĭ������1				781
#define EM_DC_DISPLAY_RELEASE_TIME				(EM_START + 134)//��ʾ����ʱ��			782
#define EM_DC_DISPLAY_RELEASE_ENERGY			(EM_START + 135)//��ʾ��������			783

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
#define DM_DC_OLD_PASSCODE0						(DM_START + 444)//��������0-1
#define DM_DC_OLD_PASSCODE1						(DM_START + 445)//��������2-3
#define DM_SYS_RUNTIME_L						(DM_START + 446)//ϵͳ�ۼ�����ʱ����L 32BIT
#define DM_SYS_RUNTIME_H						(DM_START + 447)//ϵͳ�ۼ�����ʱ����H 32BIT
#define DM_LAR_RUNTIME_L						(DM_START + 448)//�����ۼƷ���ʱ����L 32BIT
#define DM_LAR_RUNTIME_H						(DM_START + 449)//�����ۼƷ���ʱ����H 32BIT
#define DM_RELEASE_DATA_YEAR					(DM_START + 450)//����������		
#define DM_RELEASE_DATA_MONTH					(DM_START + 451)//����������
#define DM_RELEASE_DATA_DAY						(DM_START + 452)//����������
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

#define R_CHECK_EPROM_DONE						(R_START * 16 + 128)//�洢���Լ����
#define R_CHECK_INTBUS_DONE						(R_START * 16 + 129)//HMIͨ���Լ����
#define R_CHECK_LDR_DONE						(R_START * 16 + 130)//�����������Լ����
#define R_CHECK_TEMPER_DONE						(R_START * 16 + 131)//�¶��Լ����
#define R_CHECK_USBHOST_DONE					(R_START * 16 + 132)//USBHOSTģ�����
#define R_CHECK_NFC_DONE						(R_START * 16 + 133)//NFCģ�����
#define R_CHECK_NRF24L01_DONE					(R_START * 16 + 134)//NRF24L01ģ���Լ����
#define R_CHECK_EPROM_PASS						(R_START * 16 + 135)//�������Լ�ͨ��
#define R_CHECK_INTBUS_PASS						(R_START * 16 + 136)//HMIͨ���Լ�ͨ��
#define R_CHECK_LDR_PASS						(R_START * 16 + 137)//�����������Լ�ͨ��
#define R_CHECK_TEMPER_PASS						(R_START * 16 + 138)//�¶��Լ�ͨ��
#define R_CHECK_USBHOST_PASS					(R_START * 16 + 139)//USBHOSTģ��ͨ��
#define R_CHECK_NFC_PASS						(R_START * 16 + 140)//NFCģ��ͨ��
#define R_CHECK_NRF24L01_PASS					(R_START * 16 + 141)//NRF24L01ģ���Լ�ͨ��
#define R_CHECK_EPROM_FAIL						(R_START * 16 + 142)//�������Լ�ʧ��
#define R_CHECK_INTBUS_FAIL						(R_START * 16 + 143)//HMIͨ���Լ�ʧ��
#define R_CHECK_LDR_FAIL						(R_START * 16 + 144)//�����������Լ�ʧ��
#define R_CHECK_TEMPER_FAIL						(R_START * 16 + 145)//�¶��Լ�ʧ��
#define R_CHECK_USBHOST_FAIL					(R_START * 16 + 146)//USBHOSTģ��ʧ��
#define R_CHECK_NFC_FAIL						(R_START * 16 + 147)//NFCģ��ʧ��
#define R_CHECK_NRF24L01_FAIL					(R_START * 16 + 148)//NRF24L01ģ���Լ�ʧ��
/*****************************************************************************/
#define R_DC_PASSCODE_ENTER_REQ					(R_START * 16 + 150)//����ȷ������			278
#define R_DC_PASSCODE_CHANGE_REQ				(R_START * 16 + 151)//�����޸�����			279
#define R_DC_PASSCODE_CANCEL_REQ				(R_START * 16 + 152)//�����������			280
#define R_DC_PASSCODE_BACKSPACE_REQ				(R_START * 16 + 153)//���������˸�			281
#define R_DC_PASSCODE_KEY0						(R_START * 16 + 154)//�������밴��0			282
#define R_DC_PASSCODE_KEY1						(R_START * 16 + 155)//�������밴��1			283
#define R_DC_PASSCODE_KEY2						(R_START * 16 + 156)//�������밴��2			284
#define R_DC_PASSCODE_KEY3						(R_START * 16 + 157)//�������밴��3			285
#define R_DC_PASSCODE_KEY4						(R_START * 16 + 158)//�������밴��4			286
#define R_DC_PASSCODE_KEY5						(R_START * 16 + 159)//�������밴��5			287
#define R_DC_PASSCODE_KEY6						(R_START * 16 + 160)//�������밴��6			288
#define R_DC_PASSCODE_KEY7						(R_START * 16 + 161)//�������밴��7			289
#define R_DC_PASSCODE_KEY8						(R_START * 16 + 162)//�������밴��8			290
#define R_DC_PASSCODE_KEY9						(R_START * 16 + 163)//�������밴��9			291
/*****************************************************************************/
#define R_DC_NEW_PASSCODE_SAVE_REQ				(R_START * 16 + 170)//�����޸Ĵ���			298
#define R_DC_NEW_PASSCODE0_INPUT_DONE			(R_START * 16 + 171)//������ƥ���һ��		299
#define R_DC_NEW_PASSCODE1_INPUT_DONE			(R_START * 16 + 172)//������ƥ��ڶ���		300
#define R_DC_NEW_PASSCODE_ABANDON_REQ			(R_START * 16 + 173)//���������޸�			301
#define R_DC_NEW_PASSCODE_CANCEL_REQ			(R_START * 16 + 174)//�������������		302
#define R_DC_NEW_PASSCODE_BACKSPACE_REQ			(R_START * 16 + 175)//�����������˸�		303
#define R_DC_NEW_PASSCODE_KEY0					(R_START * 16 + 176)//���������밴��0		304
#define R_DC_NEW_PASSCODE_KEY1					(R_START * 16 + 177)//���������밴��1		305
#define R_DC_NEW_PASSCODE_KEY2					(R_START * 16 + 178)//���������밴��2		306
#define R_DC_NEW_PASSCODE_KEY3					(R_START * 16 + 179)//���������밴��3		307
#define R_DC_NEW_PASSCODE_KEY4					(R_START * 16 + 180)//���������밴��4		308
#define R_DC_NEW_PASSCODE_KEY5					(R_START * 16 + 181)//���������밴��5		309
#define R_DC_NEW_PASSCODE_KEY6					(R_START * 16 + 182)//���������밴��6		310
#define R_DC_NEW_PASSCODE_KEY7					(R_START * 16 + 183)//���������밴��7		311
#define R_DC_NEW_PASSCODE_KEY8					(R_START * 16 + 184)//���������밴��8		312
#define R_DC_NEW_PASSCODE_KEY9					(R_START * 16 + 185)//���������밴��9		313
/*****************************************************************************/
#define R_DC_STANDBY_READY						(R_START * 16 + 190)//׼������				318
#define R_DC_STANDBY_RESET_REQ					(R_START * 16 + 191)//������ʱ���ʱ		319
#define R_DC_STANDBY_SELECT_CH0_REQ				(R_START * 16 + 192)//����ͨ��ѡ��0			320
#define R_DC_STANDBY_SELECT_CH1_REQ				(R_START * 16 + 193)//����ͨ��ѡ��1			321
#define R_DC_STANDBY_SELECT_CH01_REQ			(R_START * 16 + 194)//����ͨ��ѡ��0+1		322
#define R_DC_STANDBY_MODE_CW_REQ				(R_START * 16 + 195)//���ⷢ��ģʽ����CW	323
#define R_DC_STANDBY_MODE_SP_REQ				(R_START * 16 + 196)//���ⷢ��ģʽ������SP	324
#define R_DC_STANDBY_MODE_MP_REQ				(R_START * 16 + 197)//���ⷢ��ģʽ������MP	325
#define R_DC_STANDBY_MODE_GP_REQ				(R_START * 16 + 198)//���ⷢ��ģʽ�������GP326
#define R_DC_STANDBY_POSWIDTH_ADD_REQ			(R_START * 16 + 199)//����������			327
#define R_DC_STANDBY_POSWIDTH_DEC_REQ			(R_START * 16 + 200)//�������С			328
#define R_DC_STANDBY_NEGWIDTH_ADD_REQ			(R_START * 16 + 201)//����������			329
#define R_DC_STANDBY_NEGWIDTH_DEC_REQ			(R_START * 16 + 202)//�������С			330
#define R_DC_STANDBY_GROUP_ADD_REQ				(R_START * 16 + 203)//�����������			331
#define R_DC_STANDBY_GROUP_DEC_REQ				(R_START * 16 + 204)//���������С			332
#define R_DC_STANDBY_SPACE_ADD_REQ				(R_START * 16 + 205)//����������			333
#define R_DC_STANDBY_SPACE_DEC_REQ				(R_START * 16 + 206)//��������С			334
#define R_DC_STANDBY_SCHEME_SAVE_REQ			(R_START * 16 + 207)//��������				335
#define R_DC_STANDBY_LASERPOWER0_ADD_REQ		(R_START * 16 + 208)//���⹦������0			336
#define R_DC_STANDBY_LASERPOWER1_ADD_REQ		(R_START * 16 + 209)//���⹦������1			337
#define R_DC_STANDBY_LASERPOWER0_DEC_REQ		(R_START * 16 + 210)//���⹦�ʼ�С0			338
#define R_DC_STANDBY_LASERPOWER1_DEC_REQ		(R_START * 16 + 211)//���⹦�ʼ�С1			339
#define R_DC_STANDBY_OPTION						(R_START * 16 + 212)//ѡ���				340
#define R_DC_STANDBY_LAST_SCHEME				(R_START * 16 + 213)//ѡ����һ������		341
#define R_DC_STANDBY_NEXT_SCHEME				(R_START * 16 + 214)//ѡ����һ������		342
/*****************************************************************************/
#define R_DC_OPTION_RETURN_REQ					(R_START * 16 + 220)//����					348
#define R_DC_OPTION_SCHEME_REQ					(R_START * 16 + 221)//��������				349
#define R_DC_OPTION_INFO_REQ					(R_START * 16 + 222)//��Ϣ����				350

#define MR_DC_OPTION_BEEM_TONE					(MR_START * 16 +  0)//����������ͬ��		0
#define MR_DC_OPTION_AIM_ON						(MR_START * 16 +  1)//ָʾ����				1
/*****************************************************************************/

/*****************************************************************************/
#define T100MS_READY_BEEM_DELAY					0//����READY״̬����������ӳ�
#define T100MS_CHECK_FLASH_DELAY				1//�洢���Լ�ȴ��ӳ�
#define T100MS_CHECK_INTBUS_DELAY				2//�����Լ�ȴ��ӳ�
#define T100MS_CHECK_LDR_DELAY					3//�����������Լ�ȴ��ӳ�
#define T100MS_CHECK_TEMPER_DELAY				4//�¶��Լ�ȴ��ӳ�
#define T100MS_CHECK_USBHOST_DELAY				5//USBHOSTģ��ȴ��ӳ�
#define T100MS_CHECK_NFC_DELAY					6//NFC����ģ��ȴ��ӳ�
#define T100MS_CHECK_NRF24L01_DELAY				7//NRF24L01��̤ģ��ȴ��ӳ�

#endif