#ifndef __APPCONFIG_H__
#define __APPCONFIG_H__
/*****************************************************************************/
#define CONFIG_APP_DIODE_HIGH_TEMP								400
#define CONFIG_APP_DRIVE_HIGH_TEMP								650
#define CONFIG_APP_ENVI_HIGH_TEMP								500
/*****************************************************************************/
#define CONFIG_USING_LASER_CHANNEL_0							1
#define CONFIG_USING_LASER_CHANNEL_1							1
#define CONFIG_USING_LASER_CHANNEL_2							1
#define CONFIG_USING_LASER_CHANNEL_3							1
#define CONFIG_HMI_SCHEME_NUM									32//������
#define CONFIG_HMI_DEFAULT_PASSSWORD0							0x3433//Ĭ������
#define CONFIG_HMI_DEFAULT_PASSSWORD1							0x3231//Ĭ������
#define CONFIG_SCHEME_NAME_SIZE									24//12*2
#define STATUS_LASER_READY										0x5A
#define STATUS_LASER_STANDBY									0xA5
#define AIM_MODE_CW_GREEN										0x5678//������ɫ
#define AIM_MODE_CW_RED											0x9ABC//������ɫ
//������
#define ERROR_CODE_EPROM										0x0001//EPRON ����
#define ERROR_CODE_SPI_FLASH									0x0002//SPI FLSAH����
#define ERROR_CODE_SI7060										0x0003//�¶ȴ�����ͨ�Ŵ���
#define ERROR_CODE_MCP79412										0x0004//RTCͨ�Ŵ���
#define ERROR_CODE_LDR0											0x0005//����������0����
#define ERROR_CODE_LDR1											0x0006//����������1����
#define ERROR_CODE_TEMPER										0x0007//�¶ȴ���������
#define ERROR_CODE_USBHOST										0x0008//USB HOSTģ�����
#define ERROR_CODE_NFC											0x0009//NFCģ�����
#define ERROR_CODE_NRF24L01										0x0010//NRF24L01ģ�����
#define ERRPR_CODE_NOERR										0xFFFF//�޴���
//���ֱ������
#define DERMA_SPOT_SIZE_0MM5									0x100A//���ֱ��0.5					
#define DERMA_SPOT_SIZE_1MM0									0x200B//���ֱ��1.0
#define DERMA_SPOT_SIZE_2MM0									0x300C//���ֱ��2.0
#define DERMA_SPOT_SIZE_3MM0									0x400D//���ֱ��3.0

#define CONFIG_MAX_LASER_DAC_CH0								0xFFF//
#define CONFIG_MAX_LASER_DAC_CH1								0xFFF//

#define CONFIG_MAX_LASERPOWER_CH0								300//ͨ��0��󼤹⹦��
#define CONFIG_MAX_LASERPOWER_CH1								150//ͨ��1��󼤹⹦��
#define CONFIG_MAX_LASERPOWER_CH2								100//ͨ��2��󼤹⹦��
#define CONFIG_MAX_LASERPOWER_CH3								100//ͨ��3��󼤹⹦��

#define CONFIG_MIN_LASERPOWER_CH0								0//ͨ��0��С���⹦��
#define CONFIG_MIN_LASERPOWER_CH1								0//ͨ��1��С���⹦��
#define CONFIG_MIN_LASERPOWER_CH2								0//ͨ��2��󼤹⹦��
#define CONFIG_MIN_LASERPOWER_CH3								0//ͨ��3��󼤹⹦��

#define CONFIG_MAX_LASER_POSWIDTH								10000
#define CONFIG_MIN_LASER_POSWIDTH								1
#define CONFIG_MAX_LASER_NEGWIDTH								10000
#define CONFIG_MIN_LASER_NEGWIDTH								1
#define CONFIG_MAX_LASER_TIMES									20//���ɼ���������
#define CONFIG_MIN_LASER_TIMES									1//��С�ɼ���������
#define CONFIG_MAX_LASER_GROUP_OFF								1000
#define CONFIG_MIN_LASER_GROUP_OFF								10
#define CONFIG_MAX_LASER_ENERGY_INTERVAL						200
#define CONFIG_MIN_LASER_ENERGY_INTERVAL						20
#define CONFIG_STEP_LASER_ENERGY_INTERVAL						10

#define CONFIG_MAX_AIM_BRG										100//���������ռ�ձ�
#define CONFIG_MIN_AIM_BRG										0//�����С����ռ�ձ�
#define CONFIG_MAX_BEEM_VOLUME									100//�������������
#define CONFIG_MIN_BEEM_VOLUME									0//��������С����
#define CONFIG_MAX_LCD_BRG										100//��Ļ�������ֵ
#define CONFIG_MIN_LCD_BRG										0//��Ļ������Сֵ
#define CONFIG_COOL_SET_TEMP									280//��ȴ�¶�
#define CONFIG_COOL_DIFF_TEMP									20//��ȴ�¶ȱ仯��Χ

#endif