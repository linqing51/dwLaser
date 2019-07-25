#include "dcHmiLanguage.h"
/*****************************************************************************/
#define ID0_MSG_NO_ERROR						0
#define ID0_MSG_INTERLOCK_UNPLUG = "Door interlock disconnected";//安全连锁没插
#define ID0_MSG_FOOTSWITCH_UNPLUG = "Footswitch not connected";//脚踏没插
#define ID0_MSG_ESTOP_PRESS = "ESTOP Press";
#define ID0_MSG_FIBER_UNPLUG = "No fiber connected ";//光纤没插或者RFID不识别
#define ID0_MSG_OUT_ENERGY = "Energy out of tolerance";//功率偏差超20%，预留功能，可以以后实现
#define ID0_MSG_DIODE_HTEMP = "Laser overheating";//温度过高
#define *LANG_WARN_MSG_DIODE_LTEMP = "Laser temperature too low";//温度过低
#define *LANG_WARN_MSG_DIODE0_OVERCURRENT = "Laser current exceeds set value";//电流超过限定值，保护激光器
#define *LANG_WARN_MSG_DIODE1_OVERCURRENT = "Laser current exceeds set value";//电流超过限定值，保护激光器
#define *LANG_WARN_MSG_NTC_ERROR = "Thermistor Error";//热敏电阻故障
#define *LANG_WARN_MSG_ENVI_HTEMP = "Envi High Temperature";//环境温度过高
#define *LANG_WARN_MSG_FOOT_DEPRESSED = "Foot/finger switch is depressed";//脚踏按下去没弹起来
#define *LANG_WARN_MSG_LASER_EMIT = "Laser is firing";//激光正在发射
#define *LANG_WARN_MSG_WAIT_TRIGGER = "Wait Laser Trigger";//等待激光触发
#define *LANG_WARN_MSG_FIBER_MISSMATE = "fiber not mate";




code char *LANG_WARN_MSG_NO_ERROR = "";
code char *LANG_WARN_MSG_INTERLOCK_UNPLUG = "Door interlock disconnected";//安全连锁没插
code char *LANG_WARN_MSG_FOOTSWITCH_UNPLUG = "Footswitch not connected";//脚踏没插
code char *LANG_WARN_MSG_ESTOP_PRESS = "ESTOP Press";
code char *LANG_WARN_MSG_FIBER_UNPLUG = "No fiber connected ";//光纤没插或者RFID不识别
code char *LANG_WARN_MSG_OUT_ENERGY = "Energy out of tolerance";//功率偏差超20%，预留功能，可以以后实现
code char *LANG_WARN_MSG_DIODE_HTEMP = "Laser overheating";//温度过高
code char *LANG_WARN_MSG_DIODE_LTEMP = "Laser temperature too low";//温度过低
code char *LANG_WARN_MSG_DIODE0_OVERCURRENT = "Laser current exceeds set value";//电流超过限定值，保护激光器
code char *LANG_WARN_MSG_DIODE1_OVERCURRENT = "Laser current exceeds set value";//电流超过限定值，保护激光器
code char *LANG_WARN_MSG_NTC_ERROR = "Thermistor Error";//热敏电阻故障
code char *LANG_WARN_MSG_ENVI_HTEMP = "Envi High Temperature";//环境温度过高
code char *LANG_WARN_MSG_FOOT_DEPRESSED = "Foot/finger switch is depressed";//脚踏按下去没弹起来
code char *LANG_WARN_MSG_LASER_EMIT = "Laser is firing";//激光正在发射
code char *LANG_WARN_MSG_WAIT_TRIGGER = "Wait Laser Trigger";//等待激光触发
code char *LANG_WARN_MSG_FIBER_MISSMATE = "fiber not mate";

