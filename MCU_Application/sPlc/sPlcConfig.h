#ifndef __SPLCCONFIG_H__
#define __SPLCCONFIG_H__
/*****************************************************************************/
#define CONFIG_UART0_BAUDRATE				115200//���ڲ�����
#define CONFIG_UART0_PARITY					NONE
#define CONFIG_UART0_STOPBIT				1
#define CONFIG_UART0_DATABIT				8

#define CONFIG_UART1_BAUDRATE				9600//���ڲ�����
#define CONFIG_UART1_PARITY					NONE
#define CONFIG_UART1_STOPBIT				1
#define CONFIG_UART1_DATABIT				8
/*****************************************************************************/
#define CONFIG_SPLC_FUNTEST					1//����ָ�����
/*****************************************************************************/
#define CONFIG_SPLC_ASSERT					1//����ַ��Χ
#define CONFIG_SPLC_DEV						0x0A01//�豸��
#define CONFIG_SPLC_CLEAR_CODE				0xA58E
#define CONFIG_SOFTPLC_HWTIME				1000L//1mS
#define CONFIG_INPUT_FILTER_TIME			3//���������˲�ɨ������ 1mS * N
/*****************************************************************************/
#define CONFIG_SPLC_USING_LED				1//���õ���LED
/*****************************************************************************/
#define CONFIG_SPLC_USING_WDT				0//���Ź�����
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_INPUT			0//����IOˢ������
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_OUTPUT			0//���IOˢ������
/*****************************************************************************/
#define CONFIG_SPLC_USING_EPROMSIM			1//EPROM ��������
#define CONFIG_SPLC_USING_CLEAR_NVRAM		1//�������NVRAM����
/*****************************************************************************/
#define CONFIG_SPLC_USING_UART1				1//UART1��������
#if CONFIG_SPLC_USING_UART1 == 1
#define SPLC_UART1							0
#endif
#define CONFIG_SPLC_USING_UART2				0//UART1��������
/*****************************************************************************/
#define CONFIG_SPLC_USING_ADC				0//ʹ��ADCģ��
#define CONFIG_SPLC_ADC_FILTER_TAP			14//ADCλ���˲�����
#define CONFIG_SPLC_ADC_CHANNLE				64//ADCͨ����
#define CONFIG_SPLC_ADC_TEMP_SENSOR_GAIN    3330L// Temp Sensor Gain in (uV / degC)
#define CONFIG_SPLC_ADC_TEMP_SENSOR_OFFSET  856L// Temp Sensor Offset in mV
#define CONFIG_SPLC_ADC_INTERNAL_VREF     	2400L// ADC Voltage Reference (mV)
#define CONFIG_SPLC_ADC_AMBIENT             25L// Ambient temp in deg C
/*****************************************************************************/
#define CONFIG_SPLC_USING_DAC				0//����DACģ��
/*****************************************************************************/
#define CONFIG_SPLC_USING_MB_RTU_SLAVE		1//����MODBUS RTU��վ
#define CONFIG_MB_RTU_SLAVE_TIMER			1000L//1000uS
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
#define SPLC_MR_SIZE						64//64*16 = 1024
#define SPLC_R_SIZE							61//64*16 = 1024
#define SPLC_DM_SIZE						256
#define SPLC_EM_SIZE						256

//��Ȧ ���� 64 * 16 = 1024BIT
#define MR_START							0
#define MR_END   							63
//#message "MR_START ="MR_START

//��Ȧ�Ĵ��� �Ǳ��� 8 * 16 = 128BIT
#define R_START								64
#define R_END								127
//���ݼĴ��� ���� 128	
#define DM_START							128
#define DM_END								255
//���ݼĴ��� �Ǳ��� 256����
#define EM_START							256
#define EM_END								511
//��ʱ��Ȧ
//100US 4 * 16 = 64BIT
#define T_100US_START						512
#define T_100US_END							515
//1MS 4 * 16 = 64BIT
#define T_1MS_START							516
#define T_1MS_END							519
//10MS 4 * 16 = 16BIT
#define T_10MS_START						520
#define T_10MS_END							523
//100MS 4 * 16 = 16BIT
#define T_100MS_START						524
#define T_100MS_END							527
//��ʱ��ʱ�� 
//100US 64
#define TD_100US_START						528
#define TD_100US_END						591	
//1MS 64
#define TD_1MS_START						592
#define TD_1MS_END							655
//10MS 64
#define TD_10MS_START						656
#define TD_10MS_END							719
//100MS 64
#define TD_100MS_START						720
#define TD_100MS_END						783
//������ 8
#define C_START								784
#define C_END								791
//����λ�Ĵ��� 4 * 16 = 64��
#define X_START								792
#define X_END								795		
//���λ�Ĵ��� 4 * 16 = 64��
#define Y_START								796
#define Y_END								799
//����Ĵ��� 32����
#define SPREG_START							800
#define SPREG_END							831
//������Ȧ	8 * 16 = 128��
#define SPCOIL_START						832
#define SPCOIL_END							839
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
#define SPCOIL_NVRAM_FAIL					(SPCOIL_START * 16 + 14)//NVRAMУ�������
#define SPCOIL_WATCHDOG						(SPCOIL_START * 16 + 15)//���Ź����
/*****************************************************************************/
#define SPCOIL_UART0_SEND_BUSY				(SPCOIL_START * 16 + 16)//UART1����æ
#define SPCOIL_UART0_RECV_BUSY				(SPCOIL_START * 16 + 17)//UART1����æ
#define SPCOIL_UART0_SEND_DONE				(SPCOIL_START * 16 + 18)//�������
#define SPCOIL_UART0_RECV_DONE				(SPCOIL_START * 16 + 19)//�������
#define SPCOIL_UART1_SEND_BUSY				(SPCOIL_START * 16 + 20)//UART1����æ
#define SPCOIL_UART1_RECV_BUSY				(SPCOIL_START * 16 + 21)//UART1����æ
#define SPCOIL_UART1_SEND_DONE				(SPCOIL_START * 16 + 22)//�������
#define SPCOIL_UART1_RECV_DONE				(SPCOIL_START * 16 + 23)//�������
/*****************************************************************************/
#define SPREG_RUNTIME_L						(SPREG_START + 0)//�ۼ�����ʱ���� 32BIT
#define SPREG_RUNTIME_H						(SPREG_START + 1)//�ۼ�����ʱ���� 32BIT		
/*****************************************************************************/
#define SPREG_UART0_SEND_BUFFER_ADR			(SPREG_START + 4)//UART0 ���ͻ���NVRAM��ַ		
#define SPREG_UART0_SEND_LENGTH				(SPREG_START + 5)//UART0 �������ݳ���
#define SPREG_UART0_SEND_NUM				(SPREG_START + 6)//UART0 �Ѿ��������ݳ���
#define SPREG_UART0_RECV_BUFFER_ADR			(SPREG_START + 7)//UART0 ���ջ���NVRAM��ַ
#define SPREG_UART0_RECV_LENGTH				(SPREG_START + 8)//UART0 �������ݳ���
#define SPREG_UART0_RECV_NUM				(SPREG_START + 9)//UART0 �Ѿ��������ݳ���
/*****************************************************************************/
#define SPREG_UART1_SEND_BUFFER_ADR			(SPREG_START + 10)//UART1 ���ͻ���NVRAM��ַ		
#define SPREG_UART1_SEND_LENGTH				(SPREG_START + 11)//UART1 �������ݳ���
#define SPREG_UART1_SEND_NUM				(SPREG_START + 12)//UART1 �Ѿ��������ݳ���
#define SPREG_UART1_RECV_BUFFER_ADR			(SPREG_START + 13)//UART1 ���ջ���NVRAM��ַ
#define SPREG_UART1_RECV_LENGTH				(SPREG_START + 14)//UART1 �������ݳ���
#define SPREG_UART1_RECV_NUM				(SPREG_START + 15)//UART1 �Ѿ��������ݳ���
/*****************************************************************************/
#define SPREG_ADC_0							(SPREG_START + 20)//ADC0�ɼ�ֵ
#define SPREG_ADC_1							(SPREG_START + 21)//ADC1�ɼ�ֵ
#define SPREG_ADC_2							(SPREG_START + 22)//ADC2�ɼ�ֵ
#define SPREG_ADC_3							(SPREG_START + 23)//ADC3�ɼ�ֵ
#define SPREG_ADC_4							(SPREG_START + 24)//ADC4�ɼ�ֵ
#define SPREG_ADC_5							(SPREG_START + 25)//ADC5�ɼ�ֵ
#define SPREG_ADC_6							(SPREG_START + 26)//ADC6�ɼ�ֵ
#define SPREG_ADC_7							(SPREG_START + 27)//ADC7�ɼ�ֵ
#define SPREG_DAC_0							(SPREG_START + 30)//DAC0�趨ֵ
#define SPREG_DAC_1							(SPREG_START + 31)//DAC0�趨ֵ
#define SPREG_DAC_2							(SPREG_START + 32)//DAC0�趨ֵ
#define SPREG_DAC_3							(SPREG_START + 33)//DAC0�趨ֵ
#define SPREG_DAC_4							(SPREG_START + 34)//DAC0�趨ֵ
#define SPREG_DAC_5							(SPREG_START + 35)//DAC0�趨ֵ
#define SPREG_DAC_6							(SPREG_START + 36)//DAC0�趨ֵ
#define SPREG_DAC_7							(SPREG_START + 37)//DAC0�趨ֵ
/*****************************************************************************/
#define SPREG_CLEAR_NVRAM0					(SPREG_END)//���NVRAM����������
/*****************************************************************************/
#endif
