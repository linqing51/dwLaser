#include "dcHmiLanguage.h"
/*****************************************************************************/
code char *LANG_WARN_MSG_ID0_NO_ERROR = "";
code char *LANG_WARN_MSG_ID1_INTERLOCK_UNPLUG = "Door interlock disconnected";//安全连锁没插
code char *LANG_WARN_MSG_ID2_FOOTSWITCH_UNPLUG = "Footswitch not connected";//脚踏没插
code char *LANG_WARN_MSG_ID3_ESTOP_PRESS = "ESTOP Press";
code char *LANG_WARN_MSG_ID4_FIBER_UNPLUG = "No fiber connected ";//光纤没插或者RFID不识别
code char *LANG_WARN_MSG_ID5_OUT_ENERGY = "Energy out of tolerance";//功率偏差超20%，预留功能，可以以后实现
code char *LANG_WARN_MSG_ID6_DIODE0_HTEMP = "Laser overheating";//温度过高
code char *LANG_WARN_MSG_ID7_DIODE0_LTEMP = "Laser temperature too low";//温度过低
code char *LANG_WARN_MSG_ID8_DIODE0_OVERCURRENT = "Laser current exceeds set value";//电流超过限定值，保护激光器
code char *LANG_WARN_MSG_ID9_DIODE1_OVERCURRENT = "Laser current exceeds set value";//电流超过限定值，保护激光器
code char *LANG_WARN_MSG_ID10_NTC_ERROR = "Thermistor Error";//热敏电阻故障
code char *LANG_WARN_MSG_ID11_ENVI_HTEMP = "Envi High Temperature";//环境温度过高
code char *LANG_WARN_MSG_ID12_FOOT_DEPRESSED = "Foot/finger switch is depressed";//脚踏按下去没弹起来
code char *LANG_WARN_MSG_ID13_LASER_EMIT = "Laser is firing";//激光正在发射
code char *LANG_WARN_MSG_ID14_WAIT_TRIGGER ="Wait Laser Trigger";//等待激光触发

static uint8_t MsgId;//当前显示的信息ID
void updateWarnMsgDisplay(uint8_t id){//更新警号显示框
	if(MsgId != id){
		switch(id){
			case MSG_NO_ERROR:{
				SetTextValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_DERMA_TEXTDISPLAY_WARN);
			}
			case MSG_INTERLOCK_UNPLUG:{
			}
			case MSG_FOOTSWITCH_UNPLUG:{
			}
			case MSG_ESTOP_PRESS:
		}
		MsgId = id;
	}
}