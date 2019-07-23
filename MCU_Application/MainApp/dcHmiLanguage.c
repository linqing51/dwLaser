#include "dcHmiLanguage.h"
/*****************************************************************************/
code char *LANG_WARN_MSG_ID0_NO_ERROR = "";
code char *LANG_WARN_MSG_ID1_INTERLOCK_UNPLUG = "Door interlock disconnected";//��ȫ����û��
code char *LANG_WARN_MSG_ID2_FOOTSWITCH_UNPLUG = "Footswitch not connected";//��̤û��
code char *LANG_WARN_MSG_ID3_ESTOP_PRESS = "ESTOP Press";
code char *LANG_WARN_MSG_ID4_FIBER_UNPLUG = "No fiber connected ";//����û�����RFID��ʶ��
code char *LANG_WARN_MSG_ID5_OUT_ENERGY = "Energy out of tolerance";//����ƫ�20%��Ԥ�����ܣ������Ժ�ʵ��
code char *LANG_WARN_MSG_ID6_DIODE0_HTEMP = "Laser overheating";//�¶ȹ���
code char *LANG_WARN_MSG_ID7_DIODE0_LTEMP = "Laser temperature too low";//�¶ȹ���
code char *LANG_WARN_MSG_ID8_DIODE0_OVERCURRENT = "Laser current exceeds set value";//���������޶�ֵ������������
code char *LANG_WARN_MSG_ID9_DIODE1_OVERCURRENT = "Laser current exceeds set value";//���������޶�ֵ������������
code char *LANG_WARN_MSG_ID10_NTC_ERROR = "Thermistor Error";//�����������
code char *LANG_WARN_MSG_ID11_ENVI_HTEMP = "Envi High Temperature";//�����¶ȹ���
code char *LANG_WARN_MSG_ID12_FOOT_DEPRESSED = "Foot/finger switch is depressed";//��̤����ȥû������
code char *LANG_WARN_MSG_ID13_LASER_EMIT = "Laser is firing";//�������ڷ���
code char *LANG_WARN_MSG_ID14_WAIT_TRIGGER ="Wait Laser Trigger";//�ȴ����ⴥ��

static uint8_t MsgId;//��ǰ��ʾ����ϢID
void updateWarnMsgDisplay(uint8_t id){//���¾�����ʾ��
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