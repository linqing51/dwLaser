#include "dcHmiLanguage.h"
/*****************************************************************************/
code char LANG_CHECK_DISPLAY_PROCESSOR_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Processor Pass",
	"自检:处理器正常"
};
code char LANG_CHECK_DISPLAY_PROCESSOR_FAIL[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Processor Fail",
	"自检:处理器失败"
};
code char LANG_CHECK_DISPLAY_EPROM_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:NVRAM Pass",
	"自检:NVRAM 通过"
};
code char LANG_CHECK_DISPLAY_EPROM_Fail[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:NVRAM Fail",
	"自检:NVRAM 失败"
};
code char LANG_CHECK_DISPLAY_SI7060_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:SI7060 Pass",
	"自检:SI7060通过"
};
code char LANG_CHECK_DISPLAY_SI7060_FAIL[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:SI7060 Fail",
	"自检:SI7060失败"
};
code char LANG_CHECK_DISPLAY_MCP79412_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:MCP79412 Pass",
	"自检:MCP79412通过"
};
code char LANG_CHECK_DISPLAY_MCP79412_FAIL[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:MCP79412 Fail",
	"自检: MCP79412失败"
};
code char LANG_CHECK_DISPLAY_BACKUP_FLASH_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Backup Memory Pass",
	"自检:Backup Flash通过"
};
code char LANG_CHECK_DISPLAY_BACKUP_FLASH_FAIL[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Backup Memeory Fail",
	"自检:备份内存失败"
};
code char LANG_CHECK_DISPLAY_CH376_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:CH376 Pass",
	"自检:CH376通过"
};
code char LANG_CHECK_DISPLAY_CH376_FAIL[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:CH376 Fail",
	"自检:CH376失败"
};
code char LANG_CHECK_DISPLAY_PN7150B0HN_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:PN7150B0HN Pass",
	"自检:PN7150B0HN通过"
};
code char LANG_CHECK_DISPLAY_PN7150B0HN_FAIL[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:PN7150B0HN Fail",
	"自检:PN7150B0HN失败"
};
code char LANG_CHECK_DISPLAY_NRF24L01_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:NRF24L01 Pass",
	"自检:NRF24L01通过"
};
code char LANG_CHECK_DISPLAY_NRF24L01_FAIL[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:NRF24L01 Fail",
	"自检:NRF24L01失败"
};
code char LANG_CHECK_DISPLAY_TEMPERATURE_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Temperature Pass",
	"自检:温度 通过"
};
code char LANG_CHECK_DISPLAY_TEMPERATURE_FAIL[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Temperature Fail",
	"自检:温度失败"
};
code char LANG_CHECK_DISPLAY_LASER_DRIVER_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Laser Driver Pass",
	"自检:驱动器通过"
};
code char LANG_CHECK_DISPLAY_LASER_DRIVER_FAIL[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Laser Driver Fail",
	"自检:驱动器失败"
};
code char LANG_CHECK_DISPLAY_SAFETY_INTERLOCK_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Safety Interlock Pass",
	"自检:安全连锁通过"
};
code char LANG_CHECK_DISPLAY_SAFETY_INTERLOCK_FAIL[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Safety Interlock Fail",
	"自检:安全连锁失败"
};
code char LANG_CHECK_DISPLAY_WIRE_FOOTCONTROL_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Wire Footcontrol Pass",
	"自检:有线脚踏通过"
};
code char LANG_CHECK_DISPLAY_WIRE_FOOTCONTROL_FAIL[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Wire Footcontrol Fail",
	"自检:有线脚踏失败"
};
code char LANG_CHECK_DISPLAY_FIBER_SENSOR_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Fiber Sensor Pass",
	"自检:光纤探测通过"
};
code char LANG_CHECK_DISPLAY_FIBER_SENSOR_FAIL[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Fiber Sensor Fail",
	"自检:光纤探测失败"
};
code char LANG_CHECK_DISPLAY_WIRELESS_FOOTCONTROL_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Wireless footcontrol Pass",
	"自检:无线脚踏通过"
};
code char LANG_CHECK_DISPLAY_WIRELESS_FOOTCONTROL_FAIL[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Wireless footcontrol Fail",
	"自检:无线脚踏失败"
};
code char LANG_CHECK_DISPLAY_PROBATION_PASS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Probation Pass",
	"自检:试用期通过"
};
code char LANG_CHECK_DISPLAY_PROBATION_FAIL[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"SELF-CHECK:Probation Fail",
	"自检:试用期失败"
};
code char LANG_TEXT_BEAM[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"Beam",
	"引导光"
};
code char LANG_TEXT_VOLUME[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"Volume",
	"音量"
};
code char LANG_TEXT_LCD_BRIGHTNESS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"Brightness",
	"亮度"
};
code char LANG_TEXT_LANGUAGE[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"Language",
	"语言"
};
code char LANG_WARN_MSG_NO_ERROR[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"No Error",
	"无故障"
};
code char LANG_WARN_MSG_INTERLOCK_UNPLUG[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"InterLock UnPlug",
	"安全连锁拔出"
};
code char LANG_WARN_MSG_FOOTSWITCH_UNPLUG[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"FootSwitch UnPlug",
	"脚踏拔出"
};
code char LANG_WARN_MSG_ESTOP_PRESS[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"ESTOP Press",
	"急停开关按下"
};
code char LANG_WARN_MSG_FIBER_UNPLUG[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"Fiber Unplug",
	"光纤未插入"
};
code char LANG_WARN_MSG_FIBER_MISSMATE[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"Fiber Unmate",
	"光纤不匹配"
};
code char LANG_WARN_MSG_DIODE0_HTEMP[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"Diode 0 High Temperature",
	"激光器 0 高温"
};
code char LANG_WARN_MSG_DIODE1_HTEMP[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"Diode 1 High Temperature",
	"激光器 1 高温"
};
code char LANG_WARN_MSG_ENVI_HTEMP[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"Envi High Temperature",
	"环境高温"
};
code char LANG_WARN_MSG_DRIVE_HTEMP[DEF_LANG_NUM][DEF_LANG_CHECK_DISPLAY_SIZE] = {
	"PowerSupply High Temperature",
	"电源高温"
};