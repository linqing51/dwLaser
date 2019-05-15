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



//#define R_CHECK_HMI_DONE						(R_START * 16 + 100)//HMI通信自检完毕
//#define R_CHECK_EPROM_DONE						(R_START * 16 + 101)//存储器自检完毕
//#define R_CHECK_SI7060_DONE						(R_START * 16 + 102)//SI7060温度传感器自检完毕
//#define R_CHECK_MCP79412_DONE					(R_START * 16 + 103)//板载RTC自检完毕
//#define R_CHECK_SPI_FLASH_DONE					(R_START * 16 + 104)//外部FLASH自检完毕
//#define R_CHECK_CH376_DONE						(R_START * 16 + 105)//USB CH376自检完毕
//#define R_CHECK_NFC_PN7150B0HN_DONE				(R_START * 16 + 106)//NFC模块完毕
//#define R_CHECK_NRF24L01_DONE					(R_START * 16 + 107)//NRF24L01模块自检完毕
//#define R_CHECK_LDR_DONE						(R_START * 16 + 108)//激光驱动器自检完毕
//#define R_CHECK_TEMPER_DONE						(R_START * 16 + 109)//温度自检完毕
//#define R_CHECK_SAFETY_INTERLOCK_DONE			(R_START * 16 + 110)//安全连锁自检完毕
//#define R_CHECK_WIRE_FOOTCONTROL_DONE			(R_START * 16 + 111)//有线脚踏自检完毕
//#define R_CHECK_FIBER_SENSOR_DONE				(R_START * 16 + 112)//光纤传感器自检完毕
//#define R_CHECK_WIRELESS_FOOTCONTROL_DONE		(R_START * 16 + 113)//无线脚踏自检完毕
//#define R_CHECK_PROBATION_DONE					(R_START * 16 + 114)//试用期自检完毕