#include "lib.h"

//enum{
//	"SELF-CHECK:Processor Pass",
//	""
//LANG_CHECK_DISPLAY_PROCESSOR_PASS

//enum{
//	"SELF-CHECK:Processor Fail!!!",
//	""
//}ENUM_CHECK_DISPLAY_PROCESSOR_FAIL

//enum{
//	"SELF-CHECK:NVRAM Pass",
//	""
//}ENUM_CHECK_DISPLAY_EPROM_PASS;

//enum{
//	"SELF-CHECK:NVRAM Fail",
//	""
//}ENUM_CHECK_DISPLAY_EPROM_Fail;



//#define R_CHECK_HMI_DONE						(R_START * 16 + 100)//HMIͨ���Լ����
//#define R_CHECK_EPROM_DONE						(R_START * 16 + 101)//�洢���Լ����
//#define R_CHECK_SI7060_DONE						(R_START * 16 + 102)//SI7060�¶ȴ������Լ����
//#define R_CHECK_MCP79412_DONE					(R_START * 16 + 103)//����RTC�Լ����
//#define R_CHECK_SPI_FLASH_DONE					(R_START * 16 + 104)//�ⲿFLASH�Լ����
//#define R_CHECK_CH376_DONE						(R_START * 16 + 105)//USB CH376�Լ����
//#define R_CHECK_NFC_PN7150B0HN_DONE				(R_START * 16 + 106)//NFCģ�����
//#define R_CHECK_NRF24L01_DONE					(R_START * 16 + 107)//NRF24L01ģ���Լ����
//#define R_CHECK_LDR_DONE						(R_START * 16 + 108)//�����������Լ����
//#define R_CHECK_TEMPER_DONE						(R_START * 16 + 109)//�¶��Լ����
//#define R_CHECK_SAFETY_INTERLOCK_DONE			(R_START * 16 + 110)//��ȫ�����Լ����
//#define R_CHECK_WIRE_FOOTCONTROL_DONE			(R_START * 16 + 111)//���߽�̤�Լ����
//#define R_CHECK_FIBER_SENSOR_DONE				(R_START * 16 + 112)//���˴������Լ����
//#define R_CHECK_WIRELESS_FOOTCONTROL_DONE		(R_START * 16 + 113)//���߽�̤�Լ����
//#define R_CHECK_PROBATION_DONE					(R_START * 16 + 114)//�������Լ����