#ifndef __APPSPLCADR_H__
#define __APPSPLCADR_H__
/*****************************************************************************/
#define CONFIG_APP_DIODE_HIGH_TEMP							400
#define CONFIG_APP_DRIVE_HIGH_TEMP							650
#define CONFIG_APP_ENVI_HIGH_TEMP							500
/*****************************************************************************/
#define CONFIG_HMI_SCHEME_NUM								16//������
#define CONFIG_HMI_DEFAULT_PASSSWORD0						0x3433//Ĭ������
#define CONFIG_HMI_DEFAULT_PASSSWORD1						0x3231//Ĭ������
#define STATUS_LASER_READY									0x5A
#define STATUS_LASER_STANDBY								0xA5
#define BEEM_MODE_SYNC										0x1234//����ͬ��
#define BEEM_MODE_TONE										0x4321
#define AIM_MODE_CW_GREEN									0x5678//������ɫ
#define AIM_MODE_CW_RED										0x9ABC//������ɫ
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
//���ֱ������
#define DERMA_SPOT_SIZE_0MM5					0x100A//���ֱ��0.5					
#define DERMA_SPOT_SIZE_1MM0					0x200B//���ֱ��1.0
#define DERMA_SPOT_SIZE_2MM0					0x300C//���ֱ��2.0
#define DERMA_SPOT_SIZE_3MM0					0x400D//���ֱ��3.0

/*****************************************************************************/
#define EM_LASER_SCHEME_NAME					(EM_START + 0)//��������
#define EM_LASER_SELECT							(EM_START + 15)//ͨ��ѡ��
#define EM_LASER_PULSE_MODE						(EM_START + 16)//����ģʽ
#define EM_LASER_POWER_CH0						(EM_START + 17)//ͨ��0����
#define EM_LASER_POWER_CH1						(EM_START + 18)//ͨ��1����
#define EM_LASER_SP_POSWIDTH					(EM_START + 19)//������������
#define EM_LASER_MP_POSWIDTH					(EM_START + 20)//������������
#define EM_LASER_MP_NEGWIDTH					(EM_START + 21)//�����帺����
#define EM_LASER_GP_POSWIDTH					(EM_START + 22)//Group����������
#define EM_LASER_GP_NEGWIDTH					(EM_START + 23)//Group���帺����
#define EM_LASER_GP_TIMES						(EM_START + 24)//Group������
#define EM_LASER_GP_GROUP_OFF					(EM_START + 25)//Group������
#define EM_LASER_SIGNAL_ENERGY_INTERVAL			(EM_START + 26)//SIGNAL�������
#define EM_LASER_DERMA_POSWIDTH					(EM_START + 27)//DERMA������
#define EM_LASER_DERMA_NEGWIDTH					(EM_START + 28)//DERMA������
#define EM_LASER_DERMA_SPOT_SIZE				(EM_START + 29)//DERMA���ֱ��
/*****************************************************************************/
#define EM_DIODE_TEMP0							(EM_START + 30)//�������¶�0
#define EM_DIODE_TEMP1							(EM_START + 31)//�������¶�1
#define EM_DRIVE_TEMP							(EM_START + 32)//�������¶�
#define EM_ENVI_TEMP							(EM_START + 33)//�����¶�
#define EM_DIODE_HIGH_TEMP						(EM_START + 34)//�����ܹ�����ֵ
#define EM_DRIVE_HIGH_TEMP						(EM_START + 35)//������������ֵ
#define EM_ENVI_HIGH_TEMP						(EM_START + 36)//����������ֵ
#define EM_COOL_SET_TEMP						(EM_START + 37)//�趨��ȴ�¶�
#define EM_COOL_DIFF_TEMP						(EM_START + 38)//�趨��ȴ�ز����
/*****************************************************************************/
#define EM_LASER_CURRENT_0						(EM_START +	40)//����������0			
#define EM_LASER_CURRENT_1						(EM_START +	41)//����������1			
#define EM_TOTAL_POWER							(EM_START + 42)//�趨�ܹ���
#define EM_RELEASE_TOTAL_TIME					(EM_START + 43)//������ʱ��			
#define EM_RELEASE_TOTAL_ENERGY					(EM_START + 44)//����������			
#define EM_HMI_OPERA_STEP						(EM_START +	48)//��������								
#define EM_ERROR_CODE							(EM_START + 49)//������					
#define EM_SCHEME_NUM_TMP						(EM_START + 50)//��ȷ�Ϸ������			
#define EM_DK25L_VER							(EM_START + 51)//DK25Lģ��汾			
/*****************************************************************************/
#define EM_DC_PAGE								(EM_START + 128)//HMIҳ���� 			
#define EM_DC_PASSCODE_INDEX					(EM_START + 129)//��������λ����		
#define EM_DC_NEW_PASSCODE0						(EM_START + 130)//����������0			
#define EM_DC_NEW_PASSCODE1						(EM_START + 131)//����������1			
#define EM_DC_NEW_PASSCODE2						(EM_START + 132)//����������0			
#define EM_DC_NEW_PASSCODE3						(EM_START + 133)//����������1			
#define EM_DC_DEFAULT_PASSCODE0					(EM_START + 134)//Ĭ������0				
#define EM_DC_DEFAULT_PASSCODE1					(EM_START + 135)//Ĭ������1				
#define EM_DC_DEFAULT_PASSCODE2					(EM_START + 136)//Ĭ������1	
#define EM_DC_DEFAULT_PASSCODE3					(EM_START + 137)//Ĭ������1				
#define EM_DC_DISPLAY_RELEASE_TIME				(EM_START + 138)//��ʾ����ʱ��			
#define EM_DC_DISPLAY_RELEASE_ENERGY			(EM_START + 139)//��ʾ��������			
/*****************************************************************************/
#define DM_LASER_SCHEME_NAME					(EM_START +  0)//��������
#define DM_LASER_SELECT							(EM_START +  15)//ͨ��ѡ��
#define DM_LASER_PULSE_MODE						(EM_START +  16)//����ģʽ
#define DM_LASER_POWER_CH0						(EM_START +  17)//ͨ��0����
#define DM_LASER_POWER_CH1						(EM_START +  18)//ͨ��1����
#define DM_LASER_SP_POSWIDTH					(EM_START +  19)//������������
#define DM_LASER_MP_POSWIDTH					(EM_START +  20)//������������
#define DM_LASER_MP_NEGWIDTH					(EM_START +  21)//�����帺����
#define DM_LASER_GP_POSWIDTH					(EM_START +  22)//Group����������
#define DM_LASER_GP_NEGWIDTH					(EM_START +  23)//Group���帺����
#define DM_LASER_GP_TIMES						(EM_START +  24)//Group������
#define DM_LASER_GP_GROUP_OFF					(EM_START +  25)//Group������
#define DM_LASER_SIGNAL_ENERGY_INTERVAL			(EM_START +  26)//SIGNAL�������
#define DM_LASER_DERMA_POSWIDTH					(EM_START +  27)//DERMA������
#define DM_LASER_DERMA_NEGWIDTH					(EM_START +  28)//DERMA������
#define DM_LASER_DERMA_SPOT_SIZE				(EM_START +  29)//DERMA���ֱ��

#define DM_SCHEME_START_0						(DM_START +   0)//����0�洢����ʼ
#define DM_SCHEME_END_0							(DM_START +  29)//����0�洢������		

#define DM_SCHEME_START_1						(DM_START +  30)//����1�洢����ʼ		
#define DM_SCHEME_END_1							(DM_START +  59)//����1�洢������

#define DM_SCHEME_START_2						(DM_START +  60)//����2�洢����ʼ
#define DM_SCHEME_END_2							(DM_START +  89)//����2�洢������

#define DM_SCHEME_START_3						(DM_START +  90)//����3�洢����ʼ
#define DM_SCHEME_END_3							(DM_START + 119)//����3�洢������

#define DM_SCHEME_START_4						(DM_START + 120)//����4�洢����ʼ
#define DM_SCHEME_END_4							(DM_START + 149)//����4�洢������

#define DM_SCHEME_START_5						(DM_START + 150)//����5�洢����ʼ
#define DM_SCHEME_END_5							(DM_START + 179)//����5�洢������

#define DM_SCHEME_START_6						(DM_START + 180)//����6�洢����ʼ
#define DM_SCHEME_END_6							(DM_START + 209)//����6�洢������

#define DM_SCHEME_START_7						(DM_START + 210)//����7�洢����ʼ
#define DM_SCHEME_END_7							(DM_START + 239)//����7�洢������

#define DM_SCHEME_START_8						(DM_START + 240)//����8�洢����ʼ
#define DM_SCHEME_END_8							(DM_START + 269)//����8�洢������

#define DM_SCHEME_START_9						(DM_START + 270)//����9�洢����ʼ
#define DM_SCHEME_END_9							(DM_START + 299)//����9�洢������

#define DM_SCHEME_START_10						(DM_START + 300)//����10�洢����ʼ
#define DM_SCHEME_END_10						(DM_START + 329)//����10�洢������

#define DM_SCHEME_START_11						(DM_START + 330)//����11�洢����ʼ
#define DM_SCHEME_END_11						(DM_START + 359)//����11�洢������

#define DM_SCHEME_START_12						(DM_START + 360)//����12�洢����ʼ
#define DM_SCHEME_END_12						(DM_START + 389)//����12�洢������

#define DM_SCHEME_START_13						(DM_START + 390)//����13�洢����ʼ
#define DM_SCHEME_END_13						(DM_START + 419)//����13�洢������

#define DM_SCHEME_START_14						(DM_START + 420)//����14�洢����ʼ
#define DM_SCHEME_END_14						(DM_START + 449)//����14�洢������

#define DM_SCHEME_START_15						(DM_START + 450)//����15�洢����ʼ
#define DM_SCHEME_END_15						(DM_START + 479)//����15�洢������

#define DM_CORR_TAB0_POWER0						(DM_START + 500)//����У����0����0 
#define DM_CORR_TAB0_POWER1						(DM_START + 501)//����У����0����2 
#define DM_CORR_TAB0_POWER2						(DM_START + 502)//����У����0����4 
#define DM_CORR_TAB0_POWER3						(DM_START + 503)//����У����0����6 
#define DM_CORR_TAB0_POWER4						(DM_START + 504)//����У����0����8 
#define DM_CORR_TAB0_POWER5						(DM_START + 505)//����У����0����10 
#define DM_CORR_TAB0_POWER6						(DM_START + 506)//����У����0����12 
#define DM_CORR_TAB0_POWER7						(DM_START + 507)//����У����0����14 
#define DM_CORR_TAB0_POWER8						(DM_START + 508)//����У����0����16 
#define DM_CORR_TAB0_POWER9						(DM_START + 509)//����У����0����18 
#define DM_CORR_TAB0_POWER10					(DM_START + 510)//����У����0����20 
#define DM_CORR_TAB0_POWER11					(DM_START + 511)//����У����0����22 
#define DM_CORR_TAB0_POWER12					(DM_START + 512)//����У����0����24 
#define DM_CORR_TAB0_POWER13					(DM_START + 513)//����У����0����26 
#define DM_CORR_TAB0_POWER14					(DM_START + 514)//����У����0����28 
#define DM_CORR_TAB0_POWER15					(DM_START + 515)//����У����0����30 
#define DM_CORR_TAB0_POWER16					(DM_START + 516)//����У����0����32 
#define DM_CORR_TAB0_POWER17					(DM_START + 517)//����У����0����34 
#define DM_CORR_TAB0_POWER18					(DM_START + 518)//����У����0����36
#define DM_CORR_TAB0_POWER19					(DM_START + 519)//����У����0����38
#define DM_CORR_TAB0_POWER20					(DM_START + 520)//����У����0����40

#define DM_CORR_TAB1_POWER0						(DM_START + 530)//����У����1����0 			
#define DM_CORR_TAB1_POWER1						(DM_START + 531)//����У����1����2
#define DM_CORR_TAB1_POWER2						(DM_START + 532)//����У����1����4
#define DM_CORR_TAB1_POWER3						(DM_START + 533)//����У����1����6 
#define DM_CORR_TAB1_POWER4						(DM_START + 534)//����У����1����8 
#define DM_CORR_TAB1_POWER5						(DM_START + 535)//����У����1����10 
#define DM_CORR_TAB1_POWER6						(DM_START + 536)//����У����1����12 
#define DM_CORR_TAB1_POWER7						(DM_START + 537)//����У����1����14 
#define DM_CORR_TAB1_POWER8						(DM_START + 538)//����У����1����16 
#define DM_CORR_TAB1_POWER9						(DM_START + 539)//����У����1����18 
#define DM_CORR_TAB1_POWER10					(DM_START + 540)//����У����1����20 
#define DM_CORR_TAB1_POWER11					(DM_START + 541)//����У����1����22 
#define DM_CORR_TAB1_POWER12					(DM_START + 542)//����У����1����24 
#define DM_CORR_TAB1_POWER13					(DM_START + 543)//����У����1����26 
#define DM_CORR_TAB1_POWER14					(DM_START + 544)//����У����1����28 
#define DM_CORR_TAB1_POWER15					(DM_START + 545)//����У����1����30 
#define DM_CORR_TAB1_POWER16					(DM_START + 546)//����У����1����32 
#define DM_CORR_TAB1_POWER17					(DM_START + 547)//����У����1����34 
#define DM_CORR_TAB1_POWER18					(DM_START + 548)//����У����1����36 
#define DM_CORR_TAB1_POWER19					(DM_START + 549)//����У����1����38
#define DM_CORR_TAB1_POWER20					(DM_START + 550)//����У����1����40
/*****************************************************************************/
#define DM_SCHEME_NUM							(DM_START + 551)//ѡ��ķ������ ��8λ������ ��8λ����ʹ��
#define DM_BEEM_VOLUME							(DM_START + 552)//����������
#define DM_BEEM_MODE							(DM_START + 553)//������ģʽ
#define DM_AIM_MODE								(DM_START + 554)//ָʾ����ģʽ
#define DM_AIM_BRG								(DM_START + 555)//ָʾ��������
#define DM_LCD_BRG								(DM_START + 556)//��Ļ����
#define DM_DC_OLD_PASSCODE0						(DM_START + 557)//��������0-1
#define DM_DC_OLD_PASSCODE1						(DM_START + 558)//��������2-3
#define DM_DC_OLD_PASSCODE2						(DM_START + 559)//��������0-1
#define DM_DC_OLD_PASSCODE3						(DM_START + 560)//��������2-3
#define DM_SYS_RUNTIME_L						(DM_START + 561)//ϵͳ�ۼ�����ʱ����L 32BIT
#define DM_SYS_RUNTIME_H						(DM_START + 562)//ϵͳ�ۼ�����ʱ����H 32BIT
#define DM_LAR_RUNTIME_L						(DM_START + 563)//�����ۼƷ���ʱ����L 32BIT
#define DM_LAR_RUNTIME_H						(DM_START + 564)//�����ۼƷ���ʱ����H 32BIT
#define DM_RELEASE_DATA_YEAR					(DM_START + 565)//����������		
#define DM_RELEASE_DATA_MONTH					(DM_START + 566)//����������
#define DM_RELEASE_DATA_DAY						(DM_START + 567)//����������
#define DM_LANGUAGE								(DM_START + 568)//����ѡ��
/*****************************************************************************/
#define X_INTERLOCK								(X_START * 16 + 0)//XIN0 ��ȫ����
#define X_ESTOP									(X_START * 16 + 1)//XIN1 ����ֹͣ����
#define X_FOOTSWITCH_NO							(X_START * 16 + 2)//XIN2 ��̤����
#define X_FOOTSWITCH_NC							(X_START * 16 + 3)//XIN3 ��̤����
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
#define R_FIBER_ID_PASS_0										(R_START * 16 + 0)//ͨ��0����ID��־
#define R_FIBER_ID_PASS_1										(R_START * 16 + 1)//ͨ��1����ID��־
#define R_DIODE_TEMP_HIGH_0										(R_START * 16 + 2)//ͨ��0�����ܸ��±�־
#define R_DIODE_TEMP_HIGH_1										(R_START * 16 + 3)//ͨ��1�����ܸ��±�־
#define R_DRIVE_TEMP_HIGH										(R_START * 16 + 4)//���������±�־
#define R_ENVI_TEMP_HIGH										(R_START * 16 + 5)//�����¶ȱ��
#define R_FAULT													(R_START * 16 + 8)//���ϱ�־
#define R_LASER_EMIT_0											(R_START * 16 + 8)//����ͨ��0����ָʾ
#define R_LASER_EMIT_1											(R_START * 16 + 8)//����ͨ��1����ָʾ
//HMI���״̬
#define R_DCHMI_RESET_REQ										(R_START * 16 + 47)//HMI��λ����
#define R_DCHMI_RESET_DOING										(R_START * 16 + 48)//HMI��λ��
#define R_DCHMI_RESET_DONE										(R_START * 16 + 49)//HMI��λ���	
#define R_DCHMI_UPDATEUI_REQ									(R_START * 16 + 50)//HMI���ݸ�������
#define R_DCHMI_UPDATEUI_DOING									(R_START * 16 + 51)//HMI���ݸ�����
#define R_DCHMO_UPDATEUI_DONE									(R_START * 16 + 52)//HMI���ݸ����������
#define R_DCHMI_RESTORE_REQ										(R_START * 16 + 53)//HMI��FLASH�лָ���������
#define R_DCHMI_RESTORE_DOING									(R_START * 16 + 54)//HMI��FLASH�лָ���
#define R_DCHMI_RESTORE_DONE									(R_START * 16 + 55)//HMI��FLASH�лָ��������	
//�Լ�״̬
#define R_CHECK_FLOAT_DONE										(R_START * 16 + 100)//�����Լ����
#define R_CHECK_EPROM_DONE										(R_START * 16 + 101)//�洢���Լ����
#define R_CHECK_SI7060_DONE										(R_START * 16 + 102)//SI7060�¶ȴ������Լ����
#define R_CHECK_MCP79412_DONE									(R_START * 16 + 103)//����RTC�Լ����
#define R_CHECK_SPI_MEMORY_DONE									(R_START * 16 + 104)//�ⲿFLASH�Լ����
#define R_CHECK_CH376_DONE										(R_START * 16 + 105)//USB CH376�Լ����
#define R_CHECK_DK25L_DONE										(R_START * 16 + 106)//DK25Lģ�����
#define R_CHECK_NRF24L01_DONE									(R_START * 16 + 107)//NRF24L01ģ���Լ����
#define R_CHECK_LASER_DRIVER_DONE								(R_START * 16 + 108)//�����������Լ����
#define R_CHECK_TEMPERATURE_DONE								(R_START * 16 + 109)//�¶��Լ����
#define R_CHECK_WIRELESS_FOOTCONTROL_DONE						(R_START * 16 + 110)//���߽�̤�Լ����
#define R_CHECK_PROBATION_DONE									(R_START * 16 + 111)//�������Լ����
 
#define R_CHECK_FLOAT_PASS										(R_START * 16 + 120)//�����Լ�ͨ��
#define R_CHECK_EPROM_PASS										(R_START * 16 + 121)//�洢���Լ�ͨ��
#define R_CHECK_SI7060_PASS										(R_START * 16 + 122)//SI7060�¶ȴ������Լ�ͨ��
#define R_CHECK_MCP79412_PASS									(R_START * 16 + 123)//����RTC�Լ�ͨ��
#define R_CHECK_SPI_MEMORY_PASS									(R_START * 16 + 124)//�ⲿFLASH�Լ�ͨ��
#define R_CHECK_CH376_PASS										(R_START * 16 + 125)//USB CH376�Լ��Լ�ͨ��
#define R_CHECK_DK25L_PASS										(R_START * 16 + 126)//DK25Lģ���Լ�ͨ��
#define R_CHECK_NRF24L01_PASS									(R_START * 16 + 127)//NRF24L01ģ���Լ�ͨ��
#define R_CHECK_LASER_DRIVER_PASS								(R_START * 16 + 128)//�����������Լ�ͨ��
#define R_CHECK_TEMPERATURE_PASS								(R_START * 16 + 129)//�¶��Լ�ͨ��
#define R_CHECK_WIRELESS_FOOTCONTROL_PASS						(R_START * 16 + 130)//���߽�̤�Լ�ͨ��
#define R_CHECK_PROBATION_PASS									(R_START * 16 + 131)//�������Լ�ͨ��

#define R_CHECK_FLOAT_FAIL										(R_START * 16 + 140)//�����Լ�ʧ�� 
#define R_CHECK_EPROM_FAIL										(R_START * 16 + 141)//�洢���Լ�ʧ��
#define R_CHECK_SI7060_FAIL										(R_START * 16 + 142)//SI7060�¶ȴ������Լ�ʧ��
#define R_CHECK_MCP79412_FAIL									(R_START * 16 + 143)//����RTC�Լ�ʧ��
#define R_CHECK_SPI_MEMORY_FAIL									(R_START * 16 + 144)//�ⲿFLASH�Լ�ʧ��
#define R_CHECK_CH376_FAIL										(R_START * 16 + 145)//USB CH376�Լ��Լ�ʧ��
#define R_CHECK_DK25L_FAIL										(R_START * 16 + 146)//NFCģ���Լ�ʧ��
#define R_CHECK_NRF24L01_FAIL									(R_START * 16 + 147)//NRF24L01ģ���Լ�ʧ��
#define R_CHECK_LASER_DRIVER_FAIL								(R_START * 16 + 148)//�����������Լ�ʧ��
#define R_CHECK_TEMPERATURE_FAIL								(R_START * 16 + 149)//�¶��Լ�ʧ��
#define R_CHECK_WIRELESS_FOOTCONTROL_FAIL						(R_START * 16 + 150)//���߽�̤�Լ�ʧ��
#define R_CHECK_PROBATION_FAIL									(R_START * 16 + 151)//�������Լ�ʧ��
/*****************************************************************************/
#define R_STANDBY_KEY_POSWIDTH_ADD_DOWN							(R_START * 16 + 160)
#define R_STANDBY_KEY_POSWIDTH_ADD_UP							(R_START * 16 + 161)
#define R_STANDBY_KEY_POSWIDTH_DEC_DOWN							(R_START * 16 + 168)
#define R_STANDBY_KEY_POSWIDTH_DEC_UP							(R_START * 16 + 169)
#define R_STANDBY_KEY_NEGWIDTH_ADD_DOWN							(R_START * 16 + 176)
#define R_STANDBY_KEY_NEGWIDTH_ADD_UP							(R_START * 16 + 177)
#define R_STANDBY_KEY_NEGWIDTH_DEC_DOWN							(R_START * 16 + 178)
#define R_STANDBY_KEY_NEGWIDTH_DEC_UP							(R_START * 16 + 179)
#define R_STANDBY_KEY_TIMES_ADD_DOWN							(R_START * 16 + 180)
#define R_STANDBY_KEY_TIMES_ADD_UP								(R_START * 16 + 181)
#define R_STANDBY_KEY_TIMES_DEC_DOWN							(R_START * 16 + 182)
#define R_STANDBY_KEY_TIMES_DEC_UP								(R_START * 16 + 183)
#define R_STANDBY_KEY_GROUP_OFF_ADD_DOWN						(R_START * 16 + 184)
#define R_STANDBY_KEY_GROUP_OFF_ADD_UP							(R_START * 16 + 185)
#define R_STANDBY_KEY_GROUP_OFF_DEC_DOWN						(R_START * 16 + 186)
#define R_STANDBY_KEY_GROUP_OFF_DEC_UP							(R_START * 16 + 187)
#define R_STANDBY_KEY_ENERGY_INTERVAL_ADD_DOWN					(R_START * 16 + 188)
#define R_STANDBY_KEY_ENERGY_INTERVAL_ADD_UP					(R_START * 16 + 189)
#define R_STANDBY_KEY_ENERGY_INTERVAL_DEC_DOWN					(R_START * 16 + 190)
#define R_STANDBY_KEY_ENERGY_INTERVAL_DEC_UP					(R_START * 16 + 191)

#define R_STANDBY_KEY_SPOT_0MM5_DOWN							(R_START * 16 + 192)
#define R_STANDBY_KEY_SPOT_0MM5_UP								(R_START * 16 + 193)

#define R_STANDBY_KEY_SPOT_1MM0_DOWN							(R_START * 16 + 194)
#define R_STANDBY_KEY_SPOT_1MM0_UP								(R_START * 16 + 195)
	
#define R_STANDBY_KEY_SPOT_2MM0_DOWN							(R_START * 16 + 196)
#define R_STANDBY_KEY_SPOT_2MM0_UP								(R_START * 16 + 197)

#define R_STANDBY_KEY_SPOT_3MM0_DOWN							(R_START * 16 + 198)
#define R_STANDBY_KEY_SPOT_3MM0_UP								(R_START * 16 + 199)

#define R_STANDBY_KEY_POWER_CH0_ADD_DOWN						(R_START * 16 + 200)
#define R_STANDBY_KEY_POWER_CH0_ADD_UP							(R_START * 16 + 201)

#define R_STANDBY_KEY_POWER_CH0_DEC_DOWN						(R_START * 16 + 202)
#define R_STANDBY_KEY_POWER_CH0_DEC_UP							(R_START * 16 + 203)

#define R_STANDBY_KEY_POWER_CH1_ADD_DOWN						(R_START * 16 + 204)
#define R_STANDBY_KEY_POWER_CH1_ADD_UP							(R_START * 16 + 205)

#define R_STANDBY_KEY_POWER_CH1_DEC_DOWN						(R_START * 16 + 206)
#define R_STANDBY_KEY_POWER_CH1_DEC_UP							(R_START * 16 + 207)

#define R_STANDBY_KEY_STNADBY_DOWN							(R_START * 16 + 208)
#define R_STANDBY_KEY_STNADBY_UP							(R_START * 16 + 209)

#define R_STANDBY_KEY_ENERGY_RESET_DOWN							(R_START * 16 + 210)
#define R_STANDBY_KEY_ENERGY_RESET_UP							(R_START * 16 + 211)

#define R_STANDBY_KEY_SELECT_CH0_DOWN							(R_START * 16 + 212)
#define R_STANDBY_KEY_SELECT_CH0_UP								(R_START * 16 + 213)

#define R_STANDBY_KEY_SELECT_CH1_DOWN							(R_START * 16 + 214)
#define R_STANDBY_KEY_SELECT_CH1_UP								(R_START * 16 + 215)
	
#define R_STANDBY_KEY_SELECT_BOTH_DOWN							(R_START * 16 + 216)
#define R_STANDBY_KEY_SELECT_BOTH_UP							(R_START * 16 + 217)

#define R_STANDB_KEY_MODE_CW_DOWN								(R_START * 16 + 218)
#define R_STANDB_KEY_MODE_CW_UP									(R_START * 16 + 219)

#define R_STANDBY_KEY_MODE_MP_DOWN								(R_START * 16 + 220)
#define R_STANDBY_KEY_MODE_MP_UP								(R_START * 16 + 221)

#define R_STANDBY_KEY_MODE_GP_DOWN								(R_START * 16 + 222)
#define R_STANDBY_KEY_MODE_GP_UP								(R_START * 16 + 223)

#define R_STANDBY_KEY_MODE_SP_DOWN								(R_START * 16 + 224)
#define R_STANDBY_KEY_MODE_SP_UP								(R_START * 16 + 225)

#define R_STANDBY_KEY_MODE_SIGNAL_DOWN							(R_START * 16 + 226)
#define R_STANDBY_KEY_MODE_SIGNAL_UP							(R_START * 16 + 227)

#define R_STANDBY_KEY_MODE_DERMA_DOWN							(R_START * 16 + 228)
#define R_STANDBY_KEY_MODE_DERMA_UP								(R_START * 16 + 229)

#define R_STANDBY_KEY_ENTER_OPTION_DOWN							(R_START * 16 + 230)
#define R_STANDBY_KEY_ENTER_OPTION_UP							(R_START * 16 + 231)

#define R_STANDBY_KEY_ENTER_SCHEME_DOWN							(R_START * 16 + 232)
#define R_STANDBY_KEY_ENTER_SCHEME_UP							(R_START * 16 + 233)
/*****************************************************************************/
#define R_OPTION_KEY_ENTER_CORRECTION_DOWN						(R_START * 16 + 230)
#define R_OPTION_KEY_ENTER_CORRECTION_UP						(R_START * 16 + 231)

#define R_OPTION_KEY_ENTER_INFORMATION_DOWN		(R_START * 16 + 232)
#define R_OPTION_KEY_ENTER_INFORMATION_UP		(R_START * 16 + 233)

#define R_OPTION_KEY_ENTER_SCHEME_DOWN			(R_START * 16 + 234)
#define R_OPTION_KEY_ENTER_SCHEME_UP			(R_START * 16 + 235)

#define R_OPTION_KEY_ENTER_OK_DOWN				(R_START * 16 + 236)
#define R_OPTION_KEY_ENTER_OK_UP				(R_START * 16 + 237)

#define R_OPTION_KEY_ENTER_DIAGNOSIS_DOWN		(R_START * 16 + 238)
#define R_OPTION_KEY_ENTER_DIAGNOSIS_UP			(R_START * 16 + 239)
/*****************************************************************************/
#define R_INFORMATION_KEY_OK_DOWN				(R_START * 16 + 250)
#define R_INFORMATION_KEY_OK_UP					(R_START * 16 + 251)
/*****************************************************************************/
#define R_SCHEME_KEY_RENAME_DOWN				(R_START * 16 + 260)
#define R_SCHEME_KEY_RENAME_UP					(R_START * 16 + 261)

#define R_SCHEME_KEY_SAVE_USB_DOWN				(R_START * 16 + 262)
#define R_SCHEME_KEY_SAVE_USB_UP				(R_START * 16 + 263)

#define R_SCHEME_KEY_LOAD_USB_DOWN				(R_START * 16 + 264)
#define R_SCHEME_KEY_LOAD_USB_UP				(R_START * 16 + 265)

#define R_SCHEME_KEY_ENTER_STANDBY_DOWN			(R_START * 16 + 266)
#define R_SCHEME_KEY_ENTER_STANDBY_UP			(R_START * 16 + 267)

#define R_SCHEME_KEY_SCHEME_SELECT_0_DOWN		(R_START * 16 + 268)		
#define R_SCHEME_KEY_SCHEME_SELECT_0_UP			(R_START * 16 + 269)

#define R_SCHEME_KEY_SCHEME_SELECT_1_DOWN		(R_START * 16 + 270)
#define R_SCHEME_KEY_SCHEME_SELECT_1_UP			(R_START * 16 + 271)

#define R_SCHEME_KEY_SCHEME_SELECT_2_DOWN		(R_START * 16 + 272)
#define R_SCHEME_KEY_SCHEME_SELECT_2_UP			(R_START * 16 + 273)

#define R_SCHEME_KEY_SCHEME_SELECT_3_DOWN		(R_START * 16 + 274)
#define R_SCHEME_KEY_SCHEME_SELECT_3_UP			(R_START * 16 + 275)

#define R_SCHEME_KEY_SCHEME_SELECT_4_DOWN		(R_START * 16 + 276)
#define R_SCHEME_KEY_SCHEME_SELECT_4_UP			(R_START * 16 + 277)

#define R_SCHEME_KEY_SCHEME_SELECT_5_DOWN		(R_START * 16 + 278)
#define R_SCHEME_KEY_SCHEME_SELECT_5_UP			(R_START * 16 + 279)

#define R_SCHEME_KEY_SCHEME_SELECT_6_DOWN		(R_START * 16 + 280)
#define R_SCHEME_KEY_SCHEME_SELECT_6_UP			(R_START * 16 + 281)

#define R_SCHEME_KEY_SCHEME_SELECT_7_DOWN		(R_START * 16 + 282)
#define R_SCHEME_KEY_SCHEME_SELECT_7_UP			(R_START * 16 + 283)

#define R_SCHEME_KEY_SCHEME_SELECT_8_DOWN		(R_START * 16 + 284)
#define R_SCHEME_KEY_SCHEME_SELECT_8_UP			(R_START * 16 + 285)

#define R_SCHEME_KEY_SCHEME_SELECT_9_DOWN		(R_START * 16 + 286)
#define R_SCHEME_KEY_SCHEME_SELECT_9_UP			(R_START * 16 + 287)

#define R_SCHEME_KEY_SCHEME_SELECT_10_DOWN		(R_START * 16 + 288)
#define R_SCHEME_KEY_SCHEME_SELECT_10_UP		(R_START * 16 + 289)

#define R_SCHEME_KEY_SCHEME_SELECT_11_DOWN		(R_START * 16 + 290)
#define R_SCHEME_KEY_SCHEME_SELECT_11_UP		(R_START * 16 + 291)

#define R_SCHEME_KEY_SCHEME_SELECT_12_DOWN		(R_START * 16 + 292)
#define R_SCHEME_KEY_SCHEME_SELECT_12_UP		(R_START * 16 + 293)

#define R_SCHEME_KEY_SCHEME_SELECT_13_DOWN		(R_START * 16 + 294)
#define R_SCHEME_KEY_SCHEME_SELECT_13_UP		(R_START * 16 + 295)

#define R_SCHEME_KEY_SCHEME_SELECT_14_DOWN		(R_START * 16 + 296)
#define R_SCHEME_KEY_SCHEME_SELECT_14_UP		(R_START * 16 + 297)

#define R_SCHEME_KEY_SCHEME_SELECT_15_DOWN		(R_START * 16 + 298)
#define R_SCHEME_KEY_SCHEME_SELECT_15_UP		(R_START * 16 + 299)

#define R_SCHEME_TEXTDISPLAY_SCHEME_0_DOWN		(R_START * 16 + 300)
#define R_SCHEME_TEXTDISPLAY_SCHEME_0_UP		(R_START * 16 + 301)

#define R_SCHEME_TEXTDISPLAY_SCHEME_1_DOWN		(R_START * 16 + 302)
#define R_SCHEME_TEXTDISPLAY_SCHEME_1_UP		(R_START * 16 + 303)

#define R_SCHEME_TEXTDISPLAY_SCHEME_2_DOWN		(R_START * 16 + 304)
#define R_SCHEME_TEXTDISPLAY_SCHEME_2_UP		(R_START * 16 + 305)

#define R_SCHEME_TEXTDISPLAY_SCHEME_3_DOWN		(R_START * 16 + 306)
#define R_SCHEME_TEXTDISPLAY_SCHEME_3_UP		(R_START * 16 + 307)

#define R_SCHEME_TEXTDISPLAY_SCHEME_4_DOWN		(R_START * 16 + 308)
#define R_SCHEME_TEXTDISPLAY_SCHEME_4_UP		(R_START * 16 + 309)

#define R_SCHEME_TEXTDISPLAY_SCHEME_5_DOWN		(R_START * 16 + 310)
#define R_SCHEME_TEXTDISPLAY_SCHEME_5_UP		(R_START * 16 + 311)

#define R_SCHEME_TEXTDISPLAY_SCHEME_6_DOWN		(R_START * 16 + 312)
#define R_SCHEME_TEXTDISPLAY_SCHEME_6_UP		(R_START * 16 + 313)

#define R_SCHEME_TEXTDISPLAY_SCHEME_7_DOWN		(R_START * 16 + 314)
#define R_SCHEME_TEXTDISPLAY_SCHEME_7_UP		(R_START * 16 + 315)

#define R_SCHEME_TEXTDISPLAY_SCHEME_8_DOWN		(R_START * 16 + 316)
#define R_SCHEME_TEXTDISPLAY_SCHEME_8_UP		(R_START * 16 + 317)

#define R_SCHEME_TEXTDISPLAY_SCHEME_9_DOWN		(R_START * 16 + 318)
#define R_SCHEME_TEXTDISPLAY_SCHEME_9_UP		(R_START * 16 + 319)

#define R_SCHEME_TEXTDISPLAY_SCHEME_10_DOWN		(R_START * 16 + 320)
#define R_SCHEME_TEXTDISPLAY_SCHEME_10_UP		(R_START * 16 + 321)

#define R_SCHEME_TEXTDISPLAY_SCHEME_11_DOWN		(R_START * 16 + 322)
#define R_SCHEME_TEXTDISPLAY_SCHEME_11_UP		(R_START * 16 + 323)

#define R_SCHEME_TEXTDISPLAY_SCHEME_12_DOWN		(R_START * 16 + 324)
#define R_SCHEME_TEXTDISPLAY_SCHEME_12_UP		(R_START * 16 + 325)

#define R_SCHEME_TEXTDISPLAY_SCHEME_13_DOWN		(R_START * 16 + 326)
#define R_SCHEME_TEXTDISPLAY_SCHEME_13_UP		(R_START * 16 + 327)

#define R_SCHEME_TEXTDISPLAY_SCHEME_14_DOWN		(R_START * 16 + 328)
#define R_SCHEME_TEXTDISPLAY_SCHEME_14_UP		(R_START * 16 + 329)

#define R_SCHEME_TEXTDISPLAY_SCHEME_15_DOWN		(R_START * 16 + 330)
#define R_SCHEME_TEXTDISPLAY_SCHEME_15_UP		(R_START * 16 + 331)

#define R_SCHEME_TEXTDISPLAY_POSWIDTH_DOWN		(R_START * 16 + 332)
#define R_SCHEME_TEXTDISPLAY_POSWIDTH_UP		(R_START * 16 + 333)

#define R_SCHEME_TEXTDISPLAY_NEGWIDTH_DOWN		(R_START * 16 + 334)
#define R_SCHEME_TEXTDISPLAY_NEGWIDTH_UP		(R_START * 16 + 335)

#define R_SCHEME_TEXTDISPLAY_GROUP_DOWN			(R_START * 16 + 336)
#define R_SCHEME_TEXTDISPLAY_GROUP_UP			(R_START * 16 + 337)

#define R_SCHEME_TEXTDISPALY_SPACE_DOWN			(R_START * 16 + 338)
#define R_SCHEME_TEXTDISPALY_SPACE_UP			(R_START * 16 + 339)
/*****************************************************************************/
#define R_DIAGNOSIS_OK_DOWN						(R_START * 16 + 350)
#define R_DIAGNOSIS_OK_UP						(R_START * 16 + 351)
/*****************************************************************************/
#define MR_FOOSWITCH_HAND_SWITCH				(MR_START * 16 + 100)//��̤HandSwitch �������
/*****************************************************************************/
#define T100MS_HMI_POWERUP_DELAY									0//HMI������λ��ʱ
#define T100MS_CHECK_PROCESSOR_DELAY								1//�洢���Լ�ȴ��ӳ�
#define T100MS_CHECK_EPROM_DELAY									2//�����Լ�ȴ��ӳ�
#define T100MS_CHECK_SI7060_DELAY									3//
#define T100MS_CHECK_MCP79412_DELAY									4//
#define T100MS_CHECK_SPI_FLASH_DELAY								5//
#define T100MS_CHECK_CH376_DELAY									6//
#define T100MS_CHECK_DK25L_DELAY									7//NFC����ģ��ȴ��ӳ�
#define T100MS_CHECK_NRF24L01_DELAY									8//�����������Լ�ȴ��ӳ�
#define T100MS_CHECK_TEMPERATURE_DELAY								9
#define T100MS_CHECK_LASER_DRIVER_DELAY								10
#define T100MS_CHECK_WIRELESS_FOOTCONTROL_DELAY						11
#define T100MS_CHECK_PROBATION_DELAY								12//USBHOSTģ��ȴ��ӳ�
#define T100MS_ENTER_PASSCODE_DELAY									13
#define T100MS_READY_BEEM_DELAY										20//����READY״̬����������ӳ�
/*****************************************************************************/
#define T10MS_POSWIDTH_ADD_KEYDOWN_DELAY							3
#define T10MS_POSWIDTH_DEC_KEYDOWN_DELAY							4
#define T10MS_NEGWIDTH_ADD_KEYDOWN_DELAY							5
#define T10MS_NEGWIDTH_DEC_KEYDOWN_DELAY							6
#define T10MS_TIMES_ADD_KEYDOWN_DELAY								7
#define T10MS_TIMES_DEC_KEYDOWN_DELAY								8
#define T10MS_GROUP_OFF_ADD_KEYDOWN_DELAY							9
#define T10MS_GROUP_OFF_DEC_KEYDOWN_DELAY							10
#define T10MS_ENERGY_INTERVAL_ADD_KEYDOWN_DELAY						11
#define T10MS_ENERGY_INTERVAL_DEC_KEYDOWN_DELAY						12
#endif