#ifndef __SPLCCONFIG_H__
#define __SPLCCONFIG_H__
/*****************************************************************************/
#define CONFIG_DEBUG						0//ʹ�ܵ���
#if CONFIG_DEBUG == 1
#define CONFIG_EPROM_DEBUG					0
#define CONFIG_DEBUG_CONSOLE				0//
#define CONFIG_DEBUG_PID					0//PID���Թ���
#define CONFIG_DEBUG_TIMER4					0//TIMER4����
#define CONFIG_DEBUG_PCA					0//PCA����
#else
#define CONFIG_EPROM_DEBUG					0
#define CONFIG_DEBUG_CONSOLE				0//
#define CONFIG_DEBUG_PID					0//PID���Թ���
#define CONFIG_DEBUG_TIMER4					0//TIMER4����
#define CONFIG_DEBUG_PCA					0//PCA����
#endif
/*****************************************************************************/
#define CONFIG_UART0_BAUDRATE				115200//����0 ������
#define CONFIG_UART1_BAUDRATE				115200//����1 ������
/*****************************************************************************/
#define CONFIG_SPLC_USING_I2C0				1//ʹ��I2C0
#define CONFIG_SPLC_USING_I2C1				1//ʹ��I2C1
#define CONFIG_SPLC_USING_I2C2				1//ʹ��I2C2
#define CONFIG_SPLC_USING_I2C3				1//ʹ��I2C3
/*****************************************************************************/
#define CONFIG_I2C0_FREQ 					1            
#define CONFIG_I2C1_FREQ 					4
#define CONFIG_I2C2_FREQ 					4
#define CONFIG_I2C3_FREQ 					4
#define CONFIG_I2C_WAITACT_TIME				10
/*****************************************************************************/
#define CONFIG_EPROM_SIZE 					CONFIG_AT24C64_SIZE
#define	CONFIG_AT24C02_SIZE 				256
#define	CONFIG_AT24C04_SIZE  				512
#define	CONFIG_AT24C08_SIZE 				1024
#define	CONFIG_AT24C16_SIZE 				2048
#define	CONFIG_AT24C32_SIZE 				4096
#define	CONFIG_AT24C64_SIZE					8192
#define	CONFIG_AT24C128_SIZE 				16384
#define	CONFIG_AT24C256_SIZE 				32768
#define CONFIG_EPROM_ADDRESS				0x50
#define CONFIG_EPROM_FRAM					1//����洢����д��ȴ�
#define CONFIG_EPROM_PAGEWRITE				0//ҳд��
/*****************************************************************************/
#define CONFIG_SPLC_USING_SPWM				1//ʹ�����PWM����
/*****************************************************************************/
#define CONFIG_SPLC_FUN_EPID				1//ʹ��SPLC��չָ��
#define CONFIG_SPLC_FUNTEST					0//����ָ�����
/*****************************************************************************/
#define CONFIG_SPLC_ASSERT					0//����ַ��Χ
#define CONFIG_SPLC_DEV						0x0A01//�豸��
#define CONFIG_SPLC_CLEAR_CODE				0xA58E
#define CONFIG_SOFTPLC_TICK					1000L//1mS
#define CONFIG_INPUT_FILTER_TIME			1//���������˲�ɨ������ 1mS * N
/*****************************************************************************/
#define CONFIG_SPLC_USING_WDT				0//���Ź�����
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_INPUT			1//����IOˢ������
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_OUTPUT			1//���IOˢ������
/*****************************************************************************/
#define CONFIG_SPLC_USING_PCA				1//Ƭ�ڼ���������
/*****************************************************************************/
#define CONFIG_SPLC_USING_EPROM				1//EPROM 
#define CONFIG_SPLC_USING_CLEAR_NVRAM		1//�������NVRAM����
/*****************************************************************************/
#define CONFIG_SPLC_USING_UART0				1//UART 0��������
#define CONFIG_SPLC_USING_UART0_ISR			1
#define UART0								0

#define CONFIG_SPLC_USING_UART1				1//UART 1��������
#define CONFIG_SPLC_USING_UART1_ISR			1
#define UART1								1
/*****************************************************************************/
#define CONFIG_SPLC_USING_ADC				1//ʹ��ADCģ��
#define CONFIG_SPLC_ADC_FILTER_TAP			4//ADCλ���˲�����
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
#define CONFIG_USING_RTU_SLAVE				0//ʹ��MODBUS RTU��վ
#define CONFIG_MB_PORT						UART0
#define CONFIG_MB_RTU_SLAVE_TICK			1000L//1000uS
#define CONFIG_MB_RTU_SLAVE_ADDRESS			0x01//���豸��ַ
#define CONFIG_MB_RTU_SLAVE_BUFFER_SIZE		256//���ͽ��ջ�����
#define CONFIG_MB_RTU_SLAVE_TIMEOUT			20//����ͨѶ��ʱ 10mS
#define CONFIG_MB_RTU_SLAVE_IO_DELAY		1//RX TX�л���ʱ
/*****************************************************************************/
#define CONFIG_USING_SI7060					1
#define CONFIG_USING_MCP79412				1
#define CONFIG_USING_CH376					0
#define CONFIG_USING_ONCHIPFLASH			0
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
#define CONFIG_SPLC_USING_LASER_TIMER		1
#define CONFIG_SPLC_USING_LASER_TIMER_TEST	0
/*****************************************************************************/
#define CONFIG_LASER_TIMER_TICK				1000
#define CONFIG_USING_DCHMI_APP				1//�㶫����˻�����Ӧ��
#define CONFIG_USING_BACKGROUND_APP			1//����Ӧ��

#define CONFIG_MAX_LASERPOWER_CH0			300//ͨ��0��󼤹⹦��
#define CONFIG_MIN_LASERPOWER_CH0			0//ͨ��0��С���⹦��
#define CONFIG_MAX_LASER_CURRENT_CH0		2000//
#define CONFIG_MAX_LASER_CURRENT_CH1		3000//
#define CONFIG_MAX_LASERPOWER_CH1			150//ͨ��1��󼤹⹦��
#define CONFIG_MIN_LASERPOWER_CH1			0//ͨ��1��С���⹦��
#define CONFIG_MAX_LASER_POSWIDTH			999//���������ʱ��
#define CONFIG_MIN_LASER_POSWIDTH			10//��С������ʱ��
#define CONFIG_MAX_LASER_NEGWIDTH			999//�������ʱ��
#define CONFIG_MIN_LASER_NEGWIDTH			10//��С������ʱ��
#define CONFIG_MAX_LASER_GROUP				999//���ɼ���������
#define CONFIG_MIN_LASER_GROUP				10//��С�ɼ���������
#define CONFIG_MAX_LASER_SPACE				999//���������ʱ��
#define CONFIG_MIN_LASER_SPACE				10//��С������ʱ��
#define CONFIG_MAX_AIM_RED_BRG				100//���������ռ�ձ�
#define CONFIG_MIN_AIM_RED_BRG				0//�����С����ռ�ձ�
#define CONFIG_MAX_AIM_GREEN_BRG			100//�̹�������ռ�ձ�
#define CONFIG_MIN_AIM_GREEN_BRG			0//�̹���С����ռ�ձ�
#define CONFIG_MAX_BEEM_VOLUME				100//�������������
#define CONFIG_MIN_BEEM_VOLUME				0//��������С����
#define CONFIG_MAX_LCD_BRG					100//��Ļ�������ֵ
#define CONFIG_MIN_LCD_BRG					0//��Ļ������Сֵ
/*****************************************************************************/
#define CONFIG_SPLC_USING_NFC				0
/*****************************************************************************/
//��Ȧ ���� 16*8=256 
#define MR_START							0
#define MR_END   							7
//��Ȧ�Ĵ��� �Ǳ��� 16*64=1024
#define R_START								8
#define R_END								71
//���ݼĴ��� ���� 576
#define DM_START							72
#define DM_END								647
//���ݼĴ��� �Ǳ��� 256
#define EM_START							648
#define EM_END								903
//��ʱ��Ȧ
//1MS 16*4=64
#define T_1MS_START							904
#define T_1MS_END							907
//10MS 16*4=64
#define T_10MS_START						908
#define T_10MS_END							911
//100MS 16*4=64
#define T_100MS_START						912
#define T_100MS_END							915
//��ʱ��ʹ��
//1MS 16*4=64
#define T_1MS_ENA_START						916						
#define T_1MS_ENA_END						919
//10MS 16*4=64
#define T_10MS_ENA_START					920
#define T_10MS_ENA_END						923
//100MS 16*4=64
#define T_100MS_ENA_START					924
#define T_100MS_ENA_END						927
//��ʱ��ʱ�� 
//1MS 16*4=64
#define TD_1MS_START						928
#define TD_1MS_END							991
//10MS 16*4=64
#define TD_10MS_START						992
#define TD_10MS_END							1055
//100MS 16*4=64
#define TD_100MS_START						1056
#define TD_100MS_END						1119
//����λ�Ĵ��� 16*4=64
#define X_START								1120
#define X_END								1123
//���λ�Ĵ��� 16*4=64
#define Y_START								1124
#define Y_END								1127
//����Ĵ��� 64
#define SPREG_START							1128
#define SPREG_END							1191
//������Ȧ 16*16=256
#define SPCOIL_START						1192
#define SPCOIL_END							1207
//��ʱ�Ĵ��� 16
#define TM_START							1208
#define TM_END								1223
/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 					(TM_END + 1)
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
//ָʾ�����й���Ȧ
#define SPCOIL_AIM0_ENABLE					(SPCOIL_START * 16 + 44)//����ָʾ��0ʹ��
#define SPCOIL_AIM1_ENABLE					(SPCOIL_START * 16 + 45)//����ָʾ��1ʹ��
/*****************************************************************************/
//�����������Ȧ
#define SPCOIL_BEEM_ENABLE					(SPCOIL_START * 16 + 46)//����������ʹ��		
/*****************************************************************************/
#define SPCOIL_SI7060_INIT_FAIL				(SPCOIL_START * 16 + 47)//SI7060�¶ȴ�������ʼ��ʧ��
#define SPCOIL_MCP79412_INIT_FAIL			(SPCOIL_START * 16 + 48)//MCP794212 RTC��ʼ��ʧ��
#define SPCOIL_CH376_INIT_FAIL				(SPCOIL_START * 16 + 49)//USB HOST CH376��ʼ��ʧ��
#define SPCOIL_SPI_FLASH_INIT_FAIL			(SPCOIL_START * 16 + 50)//SPI FLASH��ʼ��ʧ��
#define SPCOIL_PN7150B0HN_INIT_FAIL			(SPCOIL_START * 16 + 51)//NFC��ʼ��ʧ��
#define SPCOIL_NRF24L01_INIT_FAIL			(SPCOIL_START * 16 + 52)//NFC��ʼ��ʧ��
/*****************************************************************************/
#define SPREG_CLEAR_NVRAM					(SPREG_START + 0)//���NVRAM����������
/*****************************************************************************/
#define SPREG_ADC_0							(SPREG_START + 1)//ADC0�ɼ�ֵ PD0
#define SPREG_ADC_1							(SPREG_START + 2)//ADC1�ɼ�ֵ PD1
#define SPREG_ADC_2							(SPREG_START + 3)//ADC2�ɼ�ֵ NTC0
#define SPREG_ADC_3							(SPREG_START + 4)//ADC3�ɼ�ֵ NTC1
#define SPREG_ADC_4							(SPREG_START + 5)//ADC4�ɼ�ֵ ISMON0
#define SPREG_ADC_5							(SPREG_START + 6)//ADC5�ɼ�ֵ IVINMON0
#define SPREG_ADC_6							(SPREG_START + 7)//ADC6�ɼ�ֵ ISMON1
#define SPREG_ADC_7							(SPREG_START + 8)//ADC7�ɼ�ֵ IVINMON1
#define SPREG_ADC_8							(SPREG_START + 9)//ADC8�ɼ�ֵ Temperature Sensor
#define SPREG_DAC_0							(SPREG_START + 10)//DAC0�趨ֵ LSET0
#define SPREG_DAC_1							(SPREG_START + 11)//DAC0�趨ֵ LSET1
/*****************************************************************************/
#define SPREG_SPWM_POS_0					(SPREG_START + 20)//���PWM0����������
#define SPREG_SPWM_POS_SHADOW_0				(SPREG_START + 21)//���PWM0��������Ӱ
#define SPREG_SPWM_CYCLE_0					(SPREG_START + 22)//���PWM0��������
#define SPREG_SPWM_CYCLE_SHADOW_0			(SPREG_START + 23)//���PWM0������Ӱ
#define SPREG_SPWM_COUNTER_0				(SPREG_START + 24)//���PWM0������
#define SPREG_SPWM_POS_1					(SPREG_START + 25)//���PWM1����������
#define SPREG_SPWM_POS_SHADOW_1				(SPREG_START + 26)//���PWM1��������Ӱ
#define SPREG_SPWM_CYCLE_1					(SPREG_START + 27)//���PWM1��������
#define SPREG_SPWM_CYCLE_SHADOW_1			(SPREG_START + 28)//���PWM1������Ӱ
#define SPREG_SPWM_COUNTER_1				(SPREG_START + 29)//���PWM1������
#define SPREG_SPWM_POS_2					(SPREG_START + 30)//���PWM2����������
#define SPREG_SPWM_POS_SHADOW_2				(SPREG_START + 31)//���PWM2��������Ӱ
#define SPREG_SPWM_CYCLE_2					(SPREG_START + 32)//���PWM2��������
#define SPREG_SPWM_CYCLE_SHADOW_2			(SPREG_START + 33)//���PWM2������Ӱ
#define SPREG_SPWM_COUNTER_2				(SPREG_START + 34)//���PWM2������
#define SPREG_SPWM_POS_3					(SPREG_START + 35)//���PWM3����������
#define SPREG_SPWM_POS_SHADOW_3				(SPREG_START + 36)//���PWM3��������Ӱ
#define SPREG_SPWM_CYCLE_3					(SPREG_START + 37)//���PWM3��������
#define SPREG_SPWM_CYCLE_SHADOW_3			(SPREG_START + 38)//���PWM3������Ӱ
#define SPREG_SPWM_COUNTER_3				(SPREG_START + 39)//���PWM3������
/*****************************************************************************/
#define SPREG_AIM0_BRIGHTNESS				(SPREG_START + 40)//PCA0->ָʾ��0����
#define SPREG_AIM1_BRIGHTNESS				(SPREG_START + 41)//PCA1->ָʾ��1����
/*****************************************************************************/
//��������ؼĴ���
#define SPREG_BEEM_VOLUME					(SPREG_START + 42)//����������
#define SPREG_BEEM_MODE						(SPREG_START + 43)//������ģʽ
#define SPREG_BEEM_COUNTER					(SPREG_START + 44)//��������ʱ��
/*****************************************************************************/
//�������巢����ؼĴ���
#define SPREG_LASER_MODE					(SPREG_START + 45)//���ⷢ��ģʽ
#define SPREG_LASER_SELECT					(SPREG_START + 46)//����ͨ��ѡ��
#define SPREG_LASER_TCOUNTER				(SPREG_START + 47)//���������ʱ������ֵ
#define SPREG_LASER_TMATE					(SPREG_START + 48)//���������ʱ����ƥ��ֵ
#define SPREG_LASER_TOVERTIME				(SPREG_START + 49)//���������ʱ�����ֵ
#define SPREG_LASER_PCOUNTER 				(SPREG_START + 50)//���������������ֵ
#define SPREG_LASER_PMATE					(SPREG_START + 51)//�����������ƥ��ֵ
#define SPREG_LASER_POVERTIME				(SPREG_START + 52)//������������ʱֵ
#define SPREG_LASER_RELEASETIME				(SPREG_START + 53)//�������ʱ��
#define SPREG_LASER_RELEASE_COUNTER			(SPREG_START + 54)//�������ʱ���ʱ��
#define SPREG_LASER_CURRENT_0				(SPREG_START + 55)//�������0
#define SPREG_LASER_CURRENT_1				(SPREG_START + 56)//�������1
/*****************************************************************************/
#define SPREG_IDENTITY						(SPREG_END + 0)//ƽ̨ID��
/*****************************************************************************/
#define T10MS_USBDISK_CONNECT_DELAY			0
#define T10MS_USBDISK_MOUNT_DELAY			1
#define T10MS_USBDISK_REMOVE_DELAY			2
/*****************************************************************************/
#endif
