#ifndef __DCHMILANGUAGE_H__
#define __DCHMILANGUAGE_H__
/*****************************************************************************/
extern code char *LANG_WARN_MSG_NO_ERROR;
extern code char *LANG_WARN_MSG_INTERLOCK_UNPLUG;//安全连锁没插
extern code char *LANG_WARN_MSG_FOOTSWITCH_UNPLUG;//脚踏没插
extern code char *LANG_WARN_MSG_ESTOP_PRESS;
extern code char *LANG_WARN_MSG_FIBER_UNPLUG;//光纤没插或者RFID不识别
extern code char *LANG_WARN_MSG_OUT_ENERGY;//功率偏差超20%，预留功能，可以以后实现
extern code char *LANG_WARN_MSG_DIODE_HTEMP;//温度过高
extern code char *LANG_WARN_MSG_DIODE_LTEMP;//温度过低
extern code char *LANG_WARN_MSG_DIODE0_OVERCURRENT;//电流超过限定值，保护激光器
extern code char *LANG_WARN_MSG_DIODE1_OVERCURRENT;//电流超过限定值，保护激光器
extern code char *LANG_WARN_MSG_NTC_ERROR;//热敏电阻故障
extern code char *LANG_WARN_MSG_ENVI_HTEMP;//环境温度过高
extern code char *LANG_WARN_MSG_FOOT_DEPRESSED;//脚踏按下去没弹起来
extern code char *LANG_WARN_MSG_LASER_EMIT;//激光正在发射
extern code char *LANG_WARN_MSG_WAIT_TRIGGER;//等待激光触发
extern code char *LANG_WARN_MSG_FIBER_MISSMATE;
#endif
