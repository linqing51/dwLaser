#ifndef __SPLCCONFIG_H__
#define __SPLCCONFIG_H__
/*****************************************************************************/
#define CONFIG_DEBUG_PID					0//PID���Թ���
#define CONFIG_DEBUG_TIMER4					1//TIMER4����
/*****************************************************************************/
#define CONFIG_UART0_BAUDRATE				115200//����0 ������
#define CONFIG_UART1_BAUDRATE				115200//����1 ������
/*****************************************************************************/
#define CONFIG_SPLC_USING_SPWM				1//ʹ�����PWM����
/*****************************************************************************/
#define CONFIG_SPLC_FUN_EPID				1//ʹ��SPLC��չָ��
#define CONFIG_SPLC_FUNTEST					0//����ָ�����
/*****************************************************************************/
#define CONFIG_SPLC_ASSERT					1//����ַ��Χ
#define CONFIG_SPLC_DEV						0x0A01//�豸��
#define CONFIG_SPLC_CLEAR_CODE				0xA58E
#define CONFIG_SOFTPLC_TICK					1000L//1mS
#define CONFIG_INPUT_FILTER_TIME			3//���������˲�ɨ������ 1mS * N
/*****************************************************************************/
#define CONFIG_SPLC_USING_LED				1//���õ���LED
/*****************************************************************************/
#define CONFIG_SPLC_USING_WDT				0//���Ź�����
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_INPUT			1//����IOˢ������
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_OUTPUT			1//���IOˢ������
/*****************************************************************************/
#define CONFIG_SPLC_USING_PCA				1//Ƭ�ڼ���������
/*****************************************************************************/
#define CONFIG_SPLC_USING_EPROM				0//EPROM 
#define CONFIG_SPLC_USING_CLEAR_NVRAM		0//�������NVRAM����
/*****************************************************************************/
#define CONFIG_SPLC_USING_UART0				1//UART 0��������
#if CONFIG_SPLC_USING_UART0 == 1
#define UART0								0
#define CONFIG_UART0_RBUF_SIZE				256//���ջ���
#define CONFIG_UART0_TBUF_SIZE				256//���ͻ���
#endif

#define CONFIG_SPLC_USING_UART1				1//UART 1��������
#if CONFIG_SPLC_USING_UART1 == 1
#define UART1								1
#define CONFIG_UART1_RBUF_SIZE				256//���ջ���
#define CONFIG_UART1_TBUF_SIZE				256//���ͻ���
#endif
/*****************************************************************************/
#define CONFIG_SPLC_USING_ADC				1//ʹ��ADCģ��
#define CONFIG_SPLC_ADC_FILTER_TAP			14//ADCλ���˲�����
#define CONFIG_SPLC_ADC_CHANNLE				9//ADCͨ����
#define CONFIG_ADC_TEMP_SENSOR_GAIN    		3330L// Temp Sensor Gain in (uV / degC)
#define CONFIG_ADC_TEMP_SENSOR_OFFSET  		856L// Temp Sensor Offset in mV
#define CONFIG_ADC_INTERNAL_VREF     		2400L// ADC Voltage Reference (mV)
#define CONFIG_ADC_AMBIENT             		25L// Ambient temp in deg C
#define CONFIG_NTC_RS						3300L
#define CONFIG_NTC_B						3500L
#define CONFIG_NTC_RB						10000L
#define CONFIG_NTC_VREF						5000L
/*****************************************************************************/
#define CONFIG_SPLC_USING_DAC				1//����DACģ��
/*****************************************************************************/
#define CONFIG_USING_RTU_SLAVE				1//ʹ��MODBUS RTU��վ
#define CONFIG_MB_PORT						UART0
#define CONFIG_MB_RTU_SLAVE_TICK			1000L//1000uS
#define CONFIG_MB_RTU_SLAVE_ADDRESS			0x01//���豸��ַ
#define CONFIG_MB_RTU_SLAVE_BUFFER_SIZE		256//���ͽ��ջ�����
#define CONFIG_MB_RTU_SLAVE_TIMEOUT			100//����ͨѶ��ʱ 10mS
#define CONFIG_MB_RTU_SLAVE_IO_DELAY		1//RX TX�л���ʱ
/*****************************************************************************/
#define DISABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 0;
#define ENABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 1;
#define DISABLE_INTERRUPT					EA = 0;
#define ENABLE_INTERRUPT					EA = 1;
/*****************************************************************************/
#if CONFIG_USING_RTU_SLAVE == 1
#define CONFIG_USING_HMI					0//ʹ��MODBUS HMI
#endif
/*****************************************************************************/
#define CONFIG_USING_SIMEPROM				1
#define CONFIG_USING_USB					1
#define CONFIG_USING_ONCHIPFLASH			1
/*****************************************************************************/
#define CONFIG_FIRMWARE_UPDATE_PAGE_SIZE	128//FLASH���ζ�д����
#define CONFIG_FW_CONFIG_ADR				0x0000//�̼�������Ϣ��ʼ��ַ
#define CONFIG_FW_CONFIG_SIZE				0x0000//�̼�������Ϣ����
#define CONFIG_FW_STORAGE_ADR				0x0000//�̼��ݴ�����ʼ��ַ
#define CONFIG_FW_STORAGE_SIZE				0x0000//�̼��ݴ�������
/*****************************************************************************/
#define CONFIG_FW_ORIGINAL_SAVE				1//����ǰ����ɹ̼�
#define CONFIG_FW_UPDATE_REQ_FLAG			0x5A//�̼����±�־
#define CONFIG_FW_CONFIG_FILE_NAME			"/fwConfig.ini"//�̼������ļ�����
#define CONFIG_FW_MCU_FILE_LOAD_NAME		"/dwLaserNE.bin"//��Ƭ���̼�����
#define CONFIG_FW_MCU_FILE_SAVE_NAME		"/dwLaserOD.bib"//
/*****************************************************************************/
#define CONFIG_DEFAULT_PASSSWORD0			0x3031
#define CONFIG_DEFAULT_PASSSWORD1			0x3233
#define CONFIG_DEFAULT_PASSSWORD2			0x0000
#define CONFIG_DEFAULT_PASSSWORD3			0x0000
/*****************************************************************************/
#define CONFIG_SPLC_USING_LASER_TIMER		1
#define CONFIG_LASER_TIMER_TICK				1000
/*****************************************************************************/
#define CONFIG_SPLC_USING_BEEM 				1//ʹ�ܷ�����
/*****************************************************************************/
//��Ȧ ���� 16*8=256 
#define MR_START							0
#define MR_END   							7
//��Ȧ�Ĵ��� �Ǳ��� 16*8=256
#define R_START								8
#define R_END								15
//���ݼĴ��� ���� 512
#define DM_START							16
#define DM_END								527
//���ݼĴ��� �Ǳ��� 256
#define EM_START							528
#define EM_END								783
//��ʱ��Ȧ
//100US 2 * 16
#define T_100US_START						784
#define T_100US_END							785
//1MS 4*16
#define T_1MS_START							786
#define T_1MS_END							789
//10MS 4*16
#define T_10MS_START						790
#define T_10MS_END							793
//100MS 4*16
#define T_100MS_START						794
#define T_100MS_END							797
//��ʱ��ʱ�� 
//100US 4*16
#define TD_100US_START						798
#define TD_100US_END						861	
//1MS 4*16
#define TD_1MS_START						862
#define TD_1MS_END							925
//10MS 4*16
#define TD_10MS_START						926
#define TD_10MS_END							989
//100MS 4*16
#define TD_100MS_START						990
#define TD_100MS_END						1053
//������ 8
#define C_START								1054
#define C_END								1061
//����λ�Ĵ��� 4*16
#define X_START								1062
#define X_END								1065
//���λ�Ĵ��� 4*16
#define Y_START								1066
#define Y_END								1069
//����Ĵ��� 64
#define SPREG_START							1070
#define SPREG_END							1134
//������Ȧ 4*16
#define SPCOIL_START						1135
#define SPCOIL_END							1142
/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 					(SPCOIL_END + 1)
/*****************************************************************************/
#define SPCOIL_ON							(SPCOIL_START * 16 + 0)//��ͨ��Ȧ
#define SPCOIL_START_UP						(SPCOIL_START * 16 + 1)//�����ϵ�
#define SPCOIL_PS1MS						(SPCOIL_START * 16 + 2)//1mS��� 50%ռ�ձ�����
#define SPCOIL_PS10MS						(SPCOIL_START * 16 + 3)//10mS
#define SPCOIL_PS100MS						(SPCOIL_START * 16 + 4)//100mS	
#define SPCOIL_PS1000MS						(SPCOIL_START * 16 + 5)//1000mS	
#define SPCOIL_MODBUS_S0_ERROR				(SPCOIL_START * 16 + 6)//Modbus Slave->Uart0 ����
#define SPCOIL_NVRAM_FAIL					(SPCOIL_START * 16 + 7)//NVRAMУ�������
#define SPCOIL_WATCHDOG_OVERFLOW			(SPCOIL_START * 16 + 8)//���Ź����
/*****************************************************************************/
//����
#define SPCOIL_UART0_SEND_BUSY				(SPCOIL_START * 16 + 9)//UART1����æ
#define SPCOIL_UART0_RECV_BUSY				(SPCOIL_START * 16 + 10)//UART1����æ
#define SPCOIL_UART0_SEND_DONE				(SPCOIL_START * 16 + 11)//�������
#define SPCOIL_UART0_RECV_DONE				(SPCOIL_START * 16 + 12)//�������
#define SPCOIL_UART1_SEND_BUSY				(SPCOIL_START * 16 + 13)//UART1����æ
#define SPCOIL_UART1_RECV_BUSY				(SPCOIL_START * 16 + 14)//UART1����æ
#define SPCOIL_UART1_SEND_DONE				(SPCOIL_START * 16 + 15)//�������
#define SPCOIL_UART1_RECV_DONE				(SPCOIL_START * 16 + 16)//�������
//USB 
#define SPCOIL_USB_INT_ERROR				(SPCOIL_START * 16 + 17)//USB �ײ��жϷ��ش���
#define SPCOIL_USBHOST_CONNECT_REQ			(SPCOIL_START * 16 + 18)//USBHOST��������
#define SPCOIL_USBDISK_CONNECT_DOING		(SPCOIL_START * 16 + 19)//USBHOST���ӽ�����
#define SPCOIL_USBDISK_CONNECT_DONE			(SPCOIL_START * 16 + 20)//USBHOST�������
#define SPCOIL_USBDISK_MOUNT_REQ			(SPCOIL_START * 16 + 21)//USBDISK��������
#define SPCOIL_USBDISK_MOUNT_DOING			(SPCOIL_START * 16 + 22)//USBDISKװ�ؽ�����
#define SPCOIL_USBDISK_MOUNT_DONE			(SPCOIL_START * 16 + 23)//USBDISKװ�����
#define SPCOIL_USBDISK_REMOVE_REQ			(SPCOIL_START * 16 + 24)//USBHOST�Ƴ�����
#define SPCOIL_USBDISK_REMOVE_DOING			(SPCOIL_START * 16 + 25)//USBHOST�Ƴ�������
#define SPCOIL_USBDISK_REMOVE_DONE			(SPCOIL_START * 16 + 26)//USBHOST�Ƴ����
#define SPCOIL_USBDISK_READING				(SPCOIL_START * 16 + 27)//USBDISK��ȡ������
#define SPCOIL_USBDISK_OPEN_FILE_FAIL		(SPCOIL_START * 16 + 28)//USBDISK���ļ�ʧ��
#define SPCOIL_USBDISK_READ_FILE_FAIL		(SPCOIL_START * 16 + 29)//USBDISK��ȡ�ļ�ʧ��
#define SPCOIL_USBDISK_WRITE_FILE_FAIL		(SPCOIL_START * 16 + 30)//USBDISKд���ļ�ʧ��
#define SPCOIL_USBDISK_CLOSE_FILE_FAIL		(SPCOIL_START * 16 + 31)//USBDISK�ر��ļ�ʧ��
#define SPCOIL_SIMEPROM_READ_FAIL			(SPCOIL_START * 16 + 32)//SIMEPROM��ȡʧ��
#define SPCOIL_SIMEPROM_WRITE_FAIL			(SPCOIL_START * 16 + 33)//SIMEPROMд��ʧ��
/*****************************************************************************/
#define SPCOIL_SPWM_OUT_0					(SPCOIL_START * 16 + 34)//SPWM0���״̬
#define SPCOIL_SPWM_RESET_0					(SPCOIL_START * 16 + 35)//SPWM0��λ
#define SPCOIL_SPWM_OUT_1					(SPCOIL_START * 16 + 36)//SPWM1���״̬
#define SPCOIL_SPWM_RESET_1					(SPCOIL_START * 16 + 37)//SPWM1��λ
#define SPCOIL_SPWM_OUT_2					(SPCOIL_START * 16 + 38)//SPWM2���״̬
#define SPCOIL_SPWM_RESET_2					(SPCOIL_START * 16 + 39)//SPWM2��λ
#define SPCOIL_SPWM_OUT_3					(SPCOIL_START * 16 + 40)//SPWM3���״̬
#define SPCOIL_SPWM_RESET_3					(SPCOIL_START * 16 + 41)//SPWM3��λ
/*****************************************************************************/
//�������巢�������Ȧ
#define SPCOIL_LASER_EMITING				(SPCOIL_START * 16 + 42)//���ⷢ����
#define SPCOIL_LASER_EMITOVER				(SPCOIL_START * 16 + 43)//���ⷢ�����
/*****************************************************************************/
//�����������Ȧ
#define SPCOIL_BEEM_EMITING					(SPCOIL_START * 16 + 44)//������������
#define SPCOIL_BEEM_EMITOVER				(SPCOIL_START * 16 + 45)//�������������
/*****************************************************************************/
#define SPREG_RUNTIME_L						(SPREG_START + 0)//�ۼ�����ʱ����L 32BIT
#define SPREG_RUNTIME_H						(SPREG_START + 1)//�ۼ�����ʱ����H 32BIT		
/*****************************************************************************/
#define SPREG_UART0_SEND_LENGTH				(SPREG_START + 2)//UART0 �������ݳ���
#define SPREG_UART0_SEND_NUM				(SPREG_START + 3)//UART0 �Ѿ��������ݳ���
#define SPREG_UART0_RECV_LENGTH				(SPREG_START + 4)//UART0 �������ݳ���
#define SPREG_UART0_RECV_NUM				(SPREG_START + 5)//UART0 �Ѿ��������ݳ���
/*****************************************************************************/		
#define SPREG_UART1_SEND_LENGTH				(SPREG_START + 6)//UART1 �������ݳ���
#define SPREG_UART1_SEND_NUM				(SPREG_START + 7)//UART1 �Ѿ��������ݳ���
#define SPREG_UART1_RECV_LENGTH				(SPREG_START + 8)//UART1 �������ݳ���
#define SPREG_UART1_RECV_NUM				(SPREG_START + 9)//UART1 �Ѿ��������ݳ���
/*****************************************************************************/
#define SPREG_ADC_0							(SPREG_START + 10)//ADC0�ɼ�ֵ PD0
#define SPREG_ADC_1							(SPREG_START + 11)//ADC1�ɼ�ֵ PD1
#define SPREG_ADC_2							(SPREG_START + 12)//ADC2�ɼ�ֵ NTC0
#define SPREG_ADC_3							(SPREG_START + 13)//ADC3�ɼ�ֵ NTC1
#define SPREG_ADC_4							(SPREG_START + 14)//ADC4�ɼ�ֵ ISMON0
#define SPREG_ADC_5							(SPREG_START + 15)//ADC5�ɼ�ֵ IVINMON0
#define SPREG_ADC_6							(SPREG_START + 16)//ADC6�ɼ�ֵ ISMON1
#define SPREG_ADC_7							(SPREG_START + 17)//ADC7�ɼ�ֵ IVINMON1
#define SPREG_ADC_8							(SPREG_START + 18)//ADC8�ɼ�ֵ Temperature Sensor
#define SPREG_DAC_0							(SPREG_START + 19)//DAC0�趨ֵ LSET0
#define SPREG_DAC_1							(SPREG_START + 20)//DAC0�趨ֵ LSET1
/*****************************************************************************/
#define SPREG_SPWM_POS_0					(SPREG_START + 21)//���PWM0����������
#define SPREG_SPWM_POS_SHADOW_0				(SPREG_START + 22)//���PWM0��������Ӱ
#define SPREG_SPWM_CYCLE_0					(SPREG_START + 23)//���PWM0��������
#define SPREG_SPWM_CYCLE_SHADOW_0			(SPREG_START + 24)//���PWM0������Ӱ
#define SPREG_SPWM_COUNTER_0				(SPREG_START + 25)//���PWM0������

#define SPREG_SPWM_POS_1					(SPREG_START + 26)//���PWM1����������
#define SPREG_SPWM_POS_SHADOW_1				(SPREG_START + 27)//���PWM1��������Ӱ
#define SPREG_SPWM_CYCLE_1					(SPREG_START + 28)//���PWM1��������
#define SPREG_SPWM_CYCLE_SHADOW_1			(SPREG_START + 29)//���PWM1������Ӱ
#define SPREG_SPWM_COUNTER_1				(SPREG_START + 30)//���PWM1������

#define SPREG_SPWM_POS_2					(SPREG_START + 31)//���PWM2����������
#define SPREG_SPWM_POS_SHADOW_2				(SPREG_START + 32)//���PWM2��������Ӱ
#define SPREG_SPWM_CYCLE_2					(SPREG_START + 33)//���PWM2��������
#define SPREG_SPWM_CYCLE_SHADOW_2			(SPREG_START + 34)//���PWM2������Ӱ
#define SPREG_SPWM_COUNTER_2				(SPREG_START + 35)//���PWM2������

#define SPREG_SPWM_POS_3					(SPREG_START + 36)//���PWM3����������
#define SPREG_SPWM_POS_SHADOW_3				(SPREG_START + 37)//���PWM3��������Ӱ
#define SPREG_SPWM_CYCLE_3					(SPREG_START + 38)//���PWM3��������
#define SPREG_SPWM_CYCLE_SHADOW_3			(SPREG_START + 39)//���PWM3������Ӱ
#define SPREG_SPWM_COUNTER_3				(SPREG_START + 40)//���PWM3������
/*****************************************************************************/
#define SPREG_HPWM0_DUTYRATIO				(SPREG_START + 41)//ָʾ��0����
#define SPREG_HPWM1_DUTYRATIO				(SPREG_START + 42)//ָʾ��1����
#define SPREG_HPWM2_DUTYRATIO				(SPREG_START + 43)//����������
#define SPREG_HPWM3_DUTYRATIO				(SPREG_START + 44)//NULL
#define SPREG_HPWM4_DUTYRATIO				(SPREG_START + 45)//NULL
#define SPREG_HPWM5_DUTYRATIO				(SPREG_START + 46)//NULL
#define SPREG_HPWM6_DUTYRATIO				(SPREG_START + 47)//NULL
#define SPREG_HPWM7_DUTYRATIO				(SPREG_START + 48)//NULL
/*****************************************************************************/
#define SPREG_IDENTITY						(SPREG_START + 49)//ƽ̨ID��
#define SPREG_CLEAR_NVRAM0					(SPREG_START + 50)//���NVRAM����������
/*****************************************************************************/
//�������巢����ؼĴ���
#define SPREG_LASER_MODE					(SPREG_START + 51)//���ⷢ��ģʽ
#define SPREG_LASER_SELECT					(SPREG_START + 52)//����ͨ��ѡ��
#define SPREG_LASER_TCOUNTER				(SPREG_START + 53)//���������ʱ������ֵ
#define SPREG_LASER_TMATE					(SPREG_START + 54)//���������ʱ����ƥ��ֵ
#define SPREG_LASER_TOVERTIME				(SPREG_START + 55)//���������ʱ�����ֵ
#define SPREG_LASER_PCOUNTER 				(SPREG_START + 56)//���������������ֵ
#define SPREG_LASER_PMATE					(SPREG_START + 57)//�����������ƥ��ֵ
#define SPREG_LASER_POVERTIME				(SPREG_START + 58)//������������ʱֵ
#define SPREG_LASER_CURRENT_980				(SPREG_START + 59)//�������980
#define SPREG_LASER_CURRENT_1470			(SPREG_START + 60)//�������1470
/*****************************************************************************/
//��������ؼĴ���
#define SPREG_BEEM_VOLUME					(SPREG_START + 61)//����������
#define SPREG_BEEM_MODE						(SPREG_START + 62)//������ģʽ
#define SPREG_BEEM_TIME						(SPREG_START + 63)//����������ʱ��
#define SPREG_BEEM_TCOUNTER					(SPREG_START + 64)//�����������ʱ��
#define SPREG_BEEM_POS						(SPREG_START + 65)//��������ʱ��
#define SPREG_BEEM_CYCLE					(SPREG_START + 66)//����������ʱ��
#define SPREG_BEEM_PCOUNTER					(SPREG_START + 67)//������������ʱ��
#define SPREG_BEEM_RELEASE					(SPREG_START + 68)//����������ʱ��
/*****************************************************************************/
#define T10MS_USBDISK_CONNECT_DELAY			0
#define T10MS_USBDISK_MOUNT_DELAY			1
#define T10MS_USBDISK_REMOVE_DELAY			2
/*****************************************************************************/
#endif
