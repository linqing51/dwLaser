#include "dcHmiApp.h"
/*****************************************************************************/
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
code char *LANG_WARN_MSG_FIBER_MISSMATE = "Fiber not mate";
/*****************************************************************************/
uint8_t hmiCmdBuffer[CMD_MAX_SIZE];//指令缓存
uint16_t data hmiCmdSize;//已缓冲的指令数
static data uint8_t MsgId;//当前显示的信息ID
static data uint8_t StandbyEnableState;//Standby按键状态
static data uint8_t StandbyTouchState;
void UpdateUI(void);
static void updateReleaseTimeEnergy(void);
void updateWarnMsgDisplay(uint8_t id);
void returnStandbyDisplay(void);
/*****************************************************************************/
#if CONFIG_USING_DCHMI_APP == 1
void updateEnergyDensity(void){
	fp32_t ftemp;
	ftemp = (fp32_t)NVRAM0[EM_TOTAL_POWER];
	switch(NVRAM0[EM_LASER_SELECT]){	
		case DERMA_SPOT_SIZE_0MM5:{
			SetTextInt32(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_DERMA_TEXTDISPLAY_ENERGY_DENSITY , (int32_t)(ftemp / 0.00019625F), 1, 0);
			break;
		}
		case DERMA_SPOT_SIZE_1MM0:{
			SetTextInt32(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_DERMA_TEXTDISPLAY_ENERGY_DENSITY, (int32_t)(ftemp / 0.000785F), 1 , 0);
			break;
		}
		case DERMA_SPOT_SIZE_2MM0:{
			SetTextInt32(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_DERMA_TEXTDISPLAY_ENERGY_DENSITY, (int32_t)(ftemp / 0.00314926F), 1 , 0);
			break;
		}
		case DERMA_SPOT_SIZE_3MM0:{
			SetTextInt32(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_DERMA_TEXTDISPLAY_ENERGY_DENSITY, (int32_t)(ftemp / 0.00706853), 1 , 0);
			break;
		}
	}
}
void updateSchemeDisplay(void){//更新选项界面方案名称
	char dispBuf[32];
	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_0]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_0]), (char*)(&FDRAM[FD_SCHEME_START_0]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_0, dispBuf);
	
	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_1]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_1]), (char*)(&FDRAM[FD_SCHEME_START_1]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_1, dispBuf);
	
	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_2]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_2]), (char*)(&FDRAM[FD_SCHEME_START_2]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_2, dispBuf);

	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_3]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_3]), (char*)(&FDRAM[FD_SCHEME_START_3]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_3, dispBuf);
	
	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_4]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_3]), (char*)(&FDRAM[FD_SCHEME_START_4]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_4, dispBuf);
	
	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_5]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_5]), (char*)(&FDRAM[FD_SCHEME_START_5]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_5, dispBuf);
	
	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_6]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_6]), (char*)(&FDRAM[FD_SCHEME_START_6]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_6, dispBuf);

	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_7]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_7]), (char*)(&FDRAM[FD_SCHEME_START_7]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_7, dispBuf);
	
	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_8]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_8]), (char*)(&FDRAM[FD_SCHEME_START_8]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_8, dispBuf);
	
	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_9]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_9]), (char*)(&FDRAM[FD_SCHEME_START_9]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_9, dispBuf);
	
	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_10]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_10]), (char*)(&FDRAM[FD_SCHEME_START_10]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_10, dispBuf);

	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_11]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_11]), (char*)(&FDRAM[FD_SCHEME_START_11]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_11, dispBuf);
	
	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_12]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_12]), (char*)(&FDRAM[FD_SCHEME_START_12]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_12, dispBuf);
	
	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_13]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_13]), (char*)(&FDRAM[FD_SCHEME_START_13]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_13, dispBuf);
	
	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_14]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_14]), (char*)(&FDRAM[FD_SCHEME_START_14]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_14, dispBuf);

	memcpy(dispBuf, (char*)(&FDRAM[FD_SCHEME_START_15]), 30);
	memcpy((char*)(&TMPRAM[TMP_NAME_15]), (char*)(&FDRAM[FD_SCHEME_START_15]), 30);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_15, dispBuf);	
	
	unselectSchemeAll();
	NVRAM0[EM_SCHEME_NUM_TMP] = NVRAM0[DM_SCHEME_NUM];
	seletcSchemeNum(NVRAM0[DM_SCHEME_NUM]);
}


void returnStandbyDisplay(void){//返回STANDBY界面
	switch(NVRAM0[EM_LASER_PULSE_MODE]){	
		case LASER_MODE_CW:{
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY_CW;
			break;
		}
		case LASER_MODE_SP:{
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY_SP;
			break;
		}
		case LASER_MODE_MP:{
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY_MP;
			break;
		}
		case LASER_MODE_GP:{
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY_GP;
			break;
		}
		case LASER_MODE_SIGNAL:{
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY_SIGNAL;
			break;
		}
		case LASER_MODE_DERMA:{
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY_DERMA;
			break;
		}
		default:{
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY_CW;
			break;

		}
	}
	NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;	
	SetScreen(NVRAM0[EM_DC_PAGE]);
}
void updateReleaseTimeEnergy(void){//刷新发射时间能量
	SetTextInt32(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_TEXTDISPLAY_RELEASE_TIME ,NVRAM0[EM_RELEASE_TOTAL_TIME], 1, 0);
	SetTextInt32(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_TEXTDISPLAY_ENERGY ,NVRAM0[EM_RELEASE_TOTAL_ENERGY], 1, 0);

	SetTextInt32(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_TEXTDISPLAY_RELEASE_TIME ,NVRAM0[EM_RELEASE_TOTAL_TIME], 1, 0);
	SetTextInt32(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_TEXTDISPLAY_ENERGY ,NVRAM0[EM_RELEASE_TOTAL_ENERGY], 1, 0);

	SetTextInt32(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_TEXTDISPLAY_RELEASE_TIME ,NVRAM0[EM_RELEASE_TOTAL_TIME], 1, 0);
	SetTextInt32(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_TEXTDISPLAY_ENERGY ,NVRAM0[EM_RELEASE_TOTAL_ENERGY], 1, 0);

	SetTextInt32(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_TEXTDISPLAY_RELEASE_TIME ,NVRAM0[EM_RELEASE_TOTAL_TIME], 1, 0);
	SetTextInt32(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_TEXTDISPLAY_ENERGY ,NVRAM0[EM_RELEASE_TOTAL_ENERGY], 1, 0);

	SetTextInt32(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_TEXTDISPLAY_RELEASE_TIME ,NVRAM0[EM_RELEASE_TOTAL_TIME], 1, 0);
	SetTextInt32(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_TEXTDISPLAY_ENERGY ,NVRAM0[EM_RELEASE_TOTAL_ENERGY], 1, 0);

	SetTextInt32(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_TEXTDISPLAY_RELEASE_TIME ,NVRAM0[EM_RELEASE_TOTAL_TIME], 1, 0);
	SetTextInt32(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_TEXTDISPLAY_ENERGY ,NVRAM0[EM_RELEASE_TOTAL_ENERGY], 1, 0);
}
void updateWarnMsgDisplay(uint8_t id){//更新警号显示框
	char *pstr;
	if(MsgId != id){
		switch(id){
			case MSG_NO_ERROR:{
				pstr = LANG_WARN_MSG_NO_ERROR;
				break;
			}
			case MSG_INTERLOCK_UNPLUG:{
				pstr = LANG_WARN_MSG_INTERLOCK_UNPLUG;
				break;
			}
			case MSG_FOOTSWITCH_UNPLUG:{
				pstr = LANG_WARN_MSG_FOOTSWITCH_UNPLUG;
				break;
			}
			case MSG_ESTOP_PRESS:{
				pstr = LANG_WARN_MSG_ESTOP_PRESS;
				break;
			}
			case MSG_FIBER_UNPLUG:{
				pstr = LANG_WARN_MSG_FIBER_UNPLUG;
				break;
			}
			case MSG_OUT_ENERGY:{
				pstr = LANG_WARN_MSG_OUT_ENERGY;
				break;
			}
			case MSG_DIODE_HTEMP:{
				pstr = LANG_WARN_MSG_DIODE_HTEMP;
				break;
			}
			case MSG_DIODE_LTEMP:{
				pstr = LANG_WARN_MSG_DIODE_LTEMP;
				break;
			}
			case MSG_DIODE0_OVERCURRENT:{
				pstr = LANG_WARN_MSG_DIODE0_OVERCURRENT;
				break;
			}
			case MSG_DIODE1_OVERCURRENT:{
				pstr = LANG_WARN_MSG_DIODE1_OVERCURRENT;
				break;
			}
			case MSG_NTC_ERROR:{
				pstr = LANG_WARN_MSG_NTC_ERROR;
				break;
			}
			case MSG_ENVI_HTEMP:{
				pstr = LANG_WARN_MSG_ENVI_HTEMP;
				break;
			}
			case MSG_FOOT_DEPRESSED:{
				pstr = LANG_WARN_MSG_FOOT_DEPRESSED;
				break;
			}
			case MSG_LASER_EMIT:{
				pstr = LANG_WARN_MSG_LASER_EMIT;
				break;
			}
			case MSG_WAIT_TRIGGER:{
				pstr = LANG_WARN_MSG_WAIT_TRIGGER;
				break;
			}
			case MSG_FIBER_MISSMATE:{
				pstr = LANG_WARN_MSG_FIBER_MISSMATE;
			}
			default:{
				pstr = LANG_WARN_MSG_NO_ERROR;
				break;
			}
		}
		SetTextValue(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_TEXTDISPLAY_WARN, pstr);
		SetTextValue(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_TEXTDISPLAY_WARN, pstr);
		SetTextValue(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_TEXTDISPLAY_WARN, pstr);
		SetTextValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_TEXTDISPLAY_WARN, pstr);
		SetTextValue(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_TEXTDISPLAY_WARN, pstr);
		SetTextValue(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_TEXTDISPLAY_WARN, pstr);
		MsgId = id;
	}
}
void updateSchemeInfo(int16_t cn){//更新SCHEME 详细参数
	char dispBuf1[64], dispBuf2[64];
	int16_t mode;
	int16_t	power0;
	int16_t power1;
	int16_t posWidth;
	int16_t negWidth;
	int16_t times;
	int16_t	groupOff;
	int16_t energyInterval;
	mode = FDRAM[cn * 30 + FD_LASER_PULSE_MODE]; 
	power0 = FDRAM[cn * 30 + FD_LASER_POWER_CH0];
	power1 = FDRAM[cn * 30 + FD_LASER_POWER_CH1];
	
	memset(dispBuf1, 0x0, 32);	
	memset(dispBuf2, 0x0, 32);
	switch(mode){
		case LASER_MODE_CW:{
			SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_DETAIL0, "Mode:CW");
			sprintf(dispBuf2, "");
			break;
		}
		case LASER_MODE_SP:{
			SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_DETAIL0, "Mode:Single");			
			posWidth = FDRAM[cn * 30 + FD_LASER_SP_POSWIDTH];
			sprintf(dispBuf2, "On Time: %dmS", posWidth);
			break;
		}
		case LASER_MODE_MP:{
			SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_DETAIL0, "Mode:Pulsed");
			posWidth = FDRAM[cn * 30 + FD_LASER_MP_POSWIDTH];
			negWidth = FDRAM[cn * 30 + FD_LASER_MP_NEGWIDTH];
			sprintf(dispBuf2, "On Time:%dmS,Off Time:%dmS", posWidth, negWidth);
			break;
		}
		case LASER_MODE_GP:{
			SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_DETAIL0, "Mode:Group");
			posWidth = FDRAM[cn * 30 + FD_LASER_GP_POSWIDTH];
			negWidth = FDRAM[cn * 30 + FD_LASER_GP_NEGWIDTH];
			times = FDRAM[cn * 30 + FD_LASER_GP_TIMES];
			groupOff = FDRAM[cn * 30 + FD_LASER_GP_GROUP_OFF];
			sprintf(dispBuf2, "On Time:%dmS,Off Time:%dmS,Times:%d,Group Off:%d", posWidth, negWidth, times, groupOff);
			break;
		}
		case LASER_MODE_DERMA:{
			posWidth = FDRAM[cn * 30 + FD_LASER_DERMA_POSWIDTH];
			negWidth = FDRAM[cn * 30 + FD_LASER_DERMA_NEGWIDTH];
			SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_DETAIL0, "Mode:DERAM");
			sprintf(dispBuf2, "On Time:%dmS,Off Time:%dmS,Times:%d,Group Off:%d", posWidth, negWidth);
			break;
		}
		case LASER_MODE_SIGNAL:{
			energyInterval = FDRAM[cn * 30 + FD_LASER_SIGNAL_ENERGY_INTERVAL];
			SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_DETAIL0, "Mode:SIGNAL");
			sprintf(dispBuf2, "Energy Interval:%dJ", energyInterval);
			break;
		}
		default:break;
	}
	sprintf(dispBuf1, "1470nM Power:%4.1fW;980nM Power:%4.1fW", ((fp32_t)power0 / 10.0F), ((fp32_t)power1 / 10.0F));
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_DETAIL1, dispBuf1);
	SetTextValue(GDDC_PAGE_SCHEME, GDDC_PAGE_SCHEME_TEXTDISPLAY_DETAIL2, dispBuf2);
	
}
void unselectSchemeNum(sel){//反选方案条
	SetButtonValue(GDDC_PAGE_SCHEME, (GDDC_PAGE_SCHEME_KEY_SELECT_0 + sel), 0x0);	
}
void unselectSchemeAll(void){//反选全部方案条
	BatchBegin(GDDC_PAGE_SCHEME);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_0, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_1, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_2, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_3, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_4, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_5, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_6, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_7, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_8, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_9, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_10, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_11, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_12, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_13, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_14, 0x0);
	BatchSetButtonValue(GDDC_PAGE_SCHEME_KEY_SELECT_15, 0x0);
	BatchEnd();
}
void seletcSchemeNum(uint16_t sel){//选中方案条
	SetButtonValue(GDDC_PAGE_SCHEME, (GDDC_PAGE_SCHEME_KEY_SELECT_0 + sel), 0x1);
	NVRAM0[EM_SCHEME_NUM_TMP] = sel;
	updateSchemeInfo(NVRAM0[EM_SCHEME_NUM_TMP]);
}
void standbyTouchEnable(int8_t enable){//使能STANDBY界面触摸
	if(StandbyTouchState != enable){
		switch(NVRAM0[EM_LASER_PULSE_MODE]){
			case LASER_MODE_CW:{
				BatchBegin(GDDC_PAGE_STANDBY_CW);
				
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH0_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH0_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH1_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH1_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_CW, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_MP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_GP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_SP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_SIGNAL, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_DERMA, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_ENTER_OPTION, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_ENTER_SCHEME, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_SAVE, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_NEXT, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_LAST, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_RESET, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_PROGRESS_CH0, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_PROGRESS_CH1, enable);
				
				BatchEnd();
				break;
			}
			case LASER_MODE_SP:{
				BatchBegin(GDDC_PAGE_STANDBY_SP);
				
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH0_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH0_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH1_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH1_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_CW, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_MP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_GP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_SP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_SIGNAL, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_DERMA, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_ENTER_OPTION, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_ENTER_SCHEME, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_SAVE, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_NEXT, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_LAST, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_RESET, enable);
				
				BatchSetEnable(GDDC_PAGE_STANDBY_PROGRESS_CH0, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_PROGRESS_CH1, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_SP_KEY_POSWIDTH_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_SP_KEY_POSWIDTH_DEC, enable);
				
				BatchEnd();
				break;
			}
			case LASER_MODE_MP:{
				BatchBegin(GDDC_PAGE_STANDBY_MP);
				
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH0_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH0_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH1_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH1_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_CW, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_MP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_GP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_SP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_SIGNAL, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_DERMA, enable);		
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_ENTER_OPTION, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_ENTER_SCHEME, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_SAVE, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_NEXT, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_LAST, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_RESET, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_PROGRESS_CH0, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_PROGRESS_CH1, enable);
				               
				BatchSetEnable(GDDC_PAGE_STANDBY_MP_KEY_POSWIDTH_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_MP_KEY_POSWIDTH_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_MP_KEY_NEGWIDTH_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_MP_KEY_NEGWIDTH_DEC, enable);
				
				BatchEnd();
				break;
			}
			case LASER_MODE_GP:{
				BatchBegin(GDDC_PAGE_STANDBY_GP);
				
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH0_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH0_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH1_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH1_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_CW, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_MP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_GP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_SP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_SIGNAL, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_DERMA, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_ENTER_OPTION, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_ENTER_SCHEME, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_SAVE, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_NEXT, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_LAST, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_RESET, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_PROGRESS_CH0, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_PROGRESS_CH1, enable);
				
				BatchSetEnable(GDDC_PAGE_STANDBY_GP_KEY_POSWIDTH_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_GP_KEY_POSWIDTH_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_GP_KEY_NEGWIDTH_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_GP_KEY_NEGWIDTH_DEC, enable);

				BatchSetEnable(GDDC_PAGE_STANDBY_GP_KEY_TIMES_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_GP_KEY_TIMES_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_GP_KEY_GROUP_OFF_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_GP_KEY_GROUP_OFF_DEC, enable);
				
				BatchEnd();
				break;
			}
			case LASER_MODE_DERMA:{
				BatchBegin(GDDC_PAGE_STANDBY_DERMA);
				
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH0_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH0_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH1_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH1_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_CW, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_MP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_GP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_SP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_SIGNAL, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_DERMA, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_ENTER_OPTION, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_ENTER_SCHEME, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_SAVE, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_NEXT, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_LAST, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_RESET, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_PROGRESS_CH0, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_PROGRESS_CH1, enable);
				
				BatchSetEnable(GDDC_PAGE_STANDBY_DERMA_KEY_POSWIDTH_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_DERMA_KEY_POSWIDTH_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_DERMA_KEY_NEGWIDTH_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_DERMA_KEY_NEGWIDTH_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_0MM5, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_1MM0, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_2MM0, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_3MM0, enable);	
				
				BatchEnd();
				break;
			}
			case LASER_MODE_SIGNAL:{
				BatchBegin(GDDC_PAGE_STANDBY_DERMA);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH0_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH0_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH1_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_POWER_CH1_DEC, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_CW, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_MP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_GP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_SP, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_SIGNAL, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_MODE_DERMA, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_ENTER_OPTION, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_ENTER_SCHEME, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_SAVE, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_NEXT, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SCHEME_LAST, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_KEY_RESET, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_PROGRESS_CH0, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_PROGRESS_CH1, enable);
				
				BatchSetEnable(GDDC_PAGE_STANDBY_SIGNAL_KEY_ENERGY_INTERVAL_ADD, enable);
				BatchSetEnable(GDDC_PAGE_STANDBY_SIGNAL_KEY_ENERGY_INTERVAL_DEC, enable);
			
				BatchEnd();
				break;
			}
			default:break;
		}		
		StandbyTouchState = enable;
	}
}
void updatePowerDisplay(int16_t ch, int16_t mode){//更新功率显示
	uint8_t dispBuf[16];
	switch(mode){
		case LASER_MODE_CW:{
			switch(ch){
				case LASER_SELECT_CH0:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH0]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH0, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				case LASER_SELECT_CH1:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH1]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH1, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				case LASER_SELECT_BOTH:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH0]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH0, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH1]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH1, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				default:break;
			}
		}
		case LASER_MODE_SP:{
			switch(ch){
				case LASER_SELECT_CH0:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH0]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH0, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				case LASER_SELECT_CH1:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH1]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH1, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				case LASER_SELECT_BOTH:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH0]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH0, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH1]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH1, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				default:break;
			}					
			break;
		}
		case LASER_MODE_MP:{
			switch(ch){
				case LASER_SELECT_CH0:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH0]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH0, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				case LASER_SELECT_CH1:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH1]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH1, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				case LASER_SELECT_BOTH:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH0]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH0, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH1]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH1, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				default:break;
			}					
			break;
		}
		case LASER_MODE_GP:{
			switch(ch){
				case LASER_SELECT_CH0:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH0]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH0, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				case LASER_SELECT_CH1:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH1]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH1, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				case LASER_SELECT_BOTH:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH0]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH0, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH1]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH1, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				default:break;
			}
			break;
		}
		
		case LASER_MODE_DERMA:{
			switch(ch){
				case LASER_SELECT_CH0:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH0]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH0, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				case LASER_SELECT_CH1:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH1]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH1, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				case LASER_SELECT_BOTH:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH0]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH0, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH1]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH1, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				default:break;
			}
			break;
		}
		case LASER_MODE_SIGNAL:{
			switch(ch){
				case LASER_SELECT_CH0:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH0]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH0, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				case LASER_SELECT_CH1:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH1]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH1, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				case LASER_SELECT_BOTH:{
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH0]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH0, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_LASER_POWER_CH1]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH1, dispBuf);
					sprintf(dispBuf, "%4.1f W", ((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10));
					SetTextValue(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER, dispBuf);
					break;
				}
				default:break;
			}
			break;
		}
		default:break;
	}
}
void updateStandbyDisplay(void){//更新方案显示
	uint8_t dispBuf[16];
	NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
	updateReleaseTimeEnergy();
	switch(NVRAM0[EM_LASER_PULSE_MODE]){
		case LASER_MODE_CW:{
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY_CW;//切换待机页面						
			updatePowerDisplay(LASER_SELECT_BOTH, LASER_MODE_CW);
			SetProgressValue(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));
			SetProgressValue(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
			SetTextValue(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_TEXTDISPLAY_NAME, (char*)(&NVRAM0[EM_LASER_SCHEME_NAME]));				
			switch(NVRAM0[EM_LASER_SELECT]){
				case LASER_SELECT_CH0:{
					BatchBegin(GDDC_PAGE_STANDBY_CW);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x01);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x00);
					BatchEnd();
					break;
				}
				case LASER_SELECT_CH1:{
					BatchBegin(GDDC_PAGE_STANDBY_CW);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x01);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x00);
					BatchEnd();
					break;
				}
				case LASER_SELECT_BOTH:{
					BatchBegin(GDDC_PAGE_STANDBY_CW);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x01);
					BatchEnd();
					break;
				}
				default:break;
			}
			break;			
		}
		case LASER_MODE_SP:{
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY_SP;//切换待机页面		
			updatePowerDisplay(LASER_SELECT_BOTH, LASER_MODE_SP);	
			SetProgressValue(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));
			SetProgressValue(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
			SetTextValue(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_TEXTDISPLAY_NAME, (char*)(&NVRAM0[EM_LASER_SCHEME_NAME]));		
			updatePosWidthDisplay(LASER_MODE_SP);
			switch(NVRAM0[EM_LASER_SELECT]){
				case LASER_SELECT_CH0:{
					BatchBegin(GDDC_PAGE_STANDBY_SP);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x01);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x00);
					BatchEnd();
					break;
				}
				case LASER_SELECT_CH1:{
					BatchBegin(GDDC_PAGE_STANDBY_SP);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x01);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x00);
					BatchEnd();
					break;
				}
				case LASER_SELECT_BOTH:{
					BatchBegin(GDDC_PAGE_STANDBY_SP);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x01);
					BatchEnd();
					break;
				}
				default:break;
			}
			break;		
		}
		case LASER_MODE_MP:{
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY_MP;//切换待机页面
			updatePowerDisplay(LASER_SELECT_BOTH, LASER_MODE_MP);
			SetProgressValue(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));
			SetProgressValue(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
			SetTextValue(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_TEXTDISPLAY_NAME, (char*)(&NVRAM0[EM_LASER_SCHEME_NAME]));				
			updatePosWidthDisplay(LASER_MODE_MP);
			updateNegWidthDisplay(LASER_MODE_MP);	
			switch(NVRAM0[EM_LASER_SELECT]){
				case LASER_SELECT_CH0:{
					BatchBegin(GDDC_PAGE_STANDBY_MP);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x01);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x00);
					BatchEnd();
					break;
				}
				case LASER_SELECT_CH1:{
					BatchBegin(GDDC_PAGE_STANDBY_MP);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x01);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x00);
					BatchEnd();
					break;
				}
				case LASER_SELECT_BOTH:{
					BatchBegin(GDDC_PAGE_STANDBY_MP);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x01);
					BatchEnd();
					break;
				}
				default:break;
			}
			break;
		}
		case LASER_MODE_GP:{
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY_GP;//切换待机页面
			updatePowerDisplay(LASER_SELECT_BOTH, LASER_MODE_GP);
			SetProgressValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));
			SetProgressValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
			SetTextValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_TEXTDISPLAY_NAME, (char*)(&NVRAM0[EM_LASER_SCHEME_NAME]));				
			updatePosWidthDisplay(LASER_MODE_GP);
			updateNegWidthDisplay(LASER_MODE_GP);
			sprintf(dispBuf, "%d", NVRAM0[EM_LASER_GP_TIMES]);
			SetTextValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_TIMES, dispBuf);			
			updateGroupOffDisplay();
			switch(NVRAM0[EM_LASER_SELECT]){
				case LASER_SELECT_CH0:{	
					BatchBegin(GDDC_PAGE_STANDBY_GP);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x01);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x00);
					BatchEnd();
					break;
				}
				case LASER_SELECT_CH1:{
					BatchBegin(GDDC_PAGE_STANDBY_GP);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x01);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x00);
					BatchEnd();
					break;
				}
				case LASER_SELECT_BOTH:{
					BatchBegin(GDDC_PAGE_STANDBY_GP);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x01);
					BatchEnd();
					break;
				}
				default:break;
			}
			break;
		}
		case LASER_MODE_DERMA:{
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY_DERMA;//切换待机页面
			updatePowerDisplay(LASER_SELECT_BOTH, LASER_MODE_DERMA);
			SetProgressValue(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));
			SetProgressValue(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
			SetTextValue(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_TEXTDISPLAY_NAME, (char*)(&NVRAM0[EM_LASER_SCHEME_NAME]));					
			updatePosWidthDisplay(LASER_MODE_DERMA);
			updateNegWidthDisplay(LASER_MODE_DERMA);
			updateEnergyDensity();
			switch(NVRAM0[EM_LASER_SELECT]){
				case LASER_SELECT_CH0:{
					BatchBegin(GDDC_PAGE_STANDBY_DERMA);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x01);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x00);
					BatchEnd();
					break;
				}
				case LASER_SELECT_CH1:{
					BatchBegin(GDDC_PAGE_STANDBY_DERMA);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x01);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x00);
					BatchEnd();
					break;
				}
				case LASER_SELECT_BOTH:{
					BatchBegin(GDDC_PAGE_STANDBY_DERMA);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x01);
					BatchEnd();
					break;
				}
				default:break;
			}
			break;
		}
		case LASER_MODE_SIGNAL:{
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY_SIGNAL;//切换待机页面
			updatePowerDisplay(LASER_SELECT_BOTH, LASER_MODE_SIGNAL);
			SetProgressValue(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));
			SetProgressValue(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
			SetTextValue(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_TEXTDISPLAY_NAME, (char*)(&NVRAM0[EM_LASER_SCHEME_NAME]));				
			SetTextInt32(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_SIGNAL_TEXTDISPLAY_ENERGY_INTERVAL ,NVRAM0[EM_LASER_SIGNAL_ENERGY_INTERVAL], 1, 0);
			switch(NVRAM0[EM_LASER_SELECT]){
				case LASER_SELECT_CH0:{
					BatchBegin(GDDC_PAGE_STANDBY_SIGNAL);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x01);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x00);
					BatchEnd();
					break;
				}
				case LASER_SELECT_CH1:{
					BatchBegin(GDDC_PAGE_STANDBY_SIGNAL);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x01);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x00);
					BatchEnd();
					break;
				}
				case LASER_SELECT_BOTH:{
					BatchBegin(GDDC_PAGE_STANDBY_SIGNAL);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH0, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_CH1, 0x00);
					BatchSetButtonValue(GDDC_PAGE_STANDBY_KEY_SELECT_BOTH, 0x01);
					BatchEnd();
					break;
				}
				default:break;
			}	
			break;
		}
		default:break;
	}
	SetScreen(NVRAM0[EM_DC_PAGE]);
}

void updateOptionDisplay(void){//更新选项显示	
	if(LD(MR_FOOSWITCH_HAND_SWITCH)){
		SetButtonValue(GDDC_PAGE_OPTION, GDDC_PAGE_OPTION_KEY_HAND_SWITCH_ON, 0x01);
	}
	else{
		SetButtonValue(GDDC_PAGE_OPTION, GDDC_PAGE_OPTION_KEY_HAND_SWITCH_ON, 0x00);
	}
	if(LD(MR_BEEM_TONE)){
		SetButtonValue(GDDC_PAGE_OPTION, GDDC_PAGE_OPTION_KEY_TONE, 0x01);
	}
	else{
		SetButtonValue(GDDC_PAGE_OPTION, GDDC_PAGE_OPTION_KEY_TONE, 0x00);
	}
	BatchBegin(GDDC_PAGE_OPTION);
	BatchSetProgressValue(GDDC_PAGE_OPTION_PROGRESS_BEEM_VOLUME, NVRAM0[DM_BEEM_VOLUME]);//更新BEEM音量进度条
	BatchSetProgressValue(GDDC_PAGE_OPTION_PROGRESS_AIM_BRG, NVRAM0[DM_AIM_BRG]);//更新AIM亮度进度条
	BatchSetProgressValue(GDDC_PAGE_OPTION_PROGRESS_LCD_BRG, NVRAM0[DM_LCD_BRG]);//更新LCD亮度
	BatchEnd();
	SetTextInt32(GDDC_PAGE_OPTION, GDDC_PAGE_OPTION_TEXTDISPLAY_BEEM_VOLUME ,NVRAM0[DM_BEEM_VOLUME], 1, 0);
	SetTextInt32(GDDC_PAGE_OPTION, GDDC_PAGE_OPTION_TEXTDISPLAY_LCD_BRG ,NVRAM0[DM_LCD_BRG], 1, 0);
	SetTextInt32(GDDC_PAGE_OPTION, GDDC_PAGE_OPTION_TEXTDISPLAY_AIM_BRG ,NVRAM0[DM_AIM_BRG], 1, 0);
}

void updatePosWidthDisplay(int16_t mode){//更新正脉宽显示
	uint8_t dispBuf[16];
	switch(mode){
		case LASER_MODE_SP:{
			if(NVRAM0[EM_LASER_SP_POSWIDTH] < 1000){
				sprintf(dispBuf, "%d mS", NVRAM0[EM_LASER_SP_POSWIDTH]);
			}
			else{
				sprintf(dispBuf, "%d S", (NVRAM0[EM_LASER_SP_POSWIDTH] / 1000));
			}
			SetTextValue(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_SP_TEXTDISPLAY_POSWIDTH, dispBuf);
			break;
		}
		case LASER_MODE_MP:{
			if(NVRAM0[EM_LASER_MP_POSWIDTH] < 1000){
				sprintf(dispBuf, "%d mS", NVRAM0[EM_LASER_MP_POSWIDTH]);
			}
			else{
				sprintf(dispBuf, "%d S", (NVRAM0[EM_LASER_MP_POSWIDTH] / 1000));
			}
			SetTextValue(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_MP_TEXTDISPLAY_POSWIDTH, dispBuf);
			break;
		}			
		case LASER_MODE_GP:{
			if(NVRAM0[EM_LASER_GP_POSWIDTH] < 1000){
				sprintf(dispBuf, "%d mS", NVRAM0[EM_LASER_GP_POSWIDTH]);
			}
			else{
				sprintf(dispBuf, "%d S", (NVRAM0[EM_LASER_GP_POSWIDTH] / 1000));
			}
			SetTextValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_POSWIDTH, dispBuf);
			break;
		}
		case LASER_MODE_DERMA:{
			if(NVRAM0[EM_LASER_DERMA_POSWIDTH] < 1000){
				sprintf(dispBuf, "%d mS", NVRAM0[EM_LASER_DERMA_POSWIDTH]);
			}
			else{
				sprintf(dispBuf, "%d S", (NVRAM0[EM_LASER_DERMA_POSWIDTH] / 1000));
			}
			SetTextValue(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_DERMA_TEXTDISPLAY_POSWIDTH, dispBuf);
			break;		
		}
		default:break;
	}
}
void updateNegWidthDisplay(int16_t mode){//更新负脉宽显示
	uint8_t dispBuf[16];
	switch(mode){
		case LASER_MODE_MP:{
			if(NVRAM0[EM_LASER_MP_NEGWIDTH] < 1000){
				sprintf(dispBuf, "%d mS", NVRAM0[EM_LASER_MP_NEGWIDTH]);
			}
			else{
				sprintf(dispBuf, "%d S", (NVRAM0[EM_LASER_MP_NEGWIDTH] / 1000));
			}
			SetTextValue(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_MP_TEXTDISPLAY_NEGWIDTH, dispBuf);
			break;
		}
		case LASER_MODE_GP:{
			if(NVRAM0[EM_LASER_GP_NEGWIDTH] < 1000){
				sprintf(dispBuf, "%d mS", NVRAM0[EM_LASER_GP_NEGWIDTH]);
			}
			else{
				sprintf(dispBuf, "%d S", (NVRAM0[EM_LASER_GP_NEGWIDTH] / 1000));
			}
			SetTextValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_NEGWIDTH, dispBuf);
			break;
		
		
		}
		case LASER_MODE_DERMA:{
			if(NVRAM0[EM_LASER_DERMA_NEGWIDTH] < 1000){
				sprintf(dispBuf, "%d mS", NVRAM0[EM_LASER_DERMA_NEGWIDTH]);
			}
			else{
				sprintf(dispBuf, "%d S", (NVRAM0[EM_LASER_DERMA_NEGWIDTH] / 1000));
			}
			SetTextValue(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_DERMA_TEXTDISPLAY_NEGWIDTH, dispBuf);
			break;
		}
		default:break;
	}
}
void updateGroupOffDisplay(void){//更新GroupOff显示
	uint8_t dispBuf[16];
	if(NVRAM0[EM_LASER_GP_GROUP_OFF] < 1000){
		sprintf(dispBuf, "%d mS", NVRAM0[EM_LASER_GP_GROUP_OFF]);
	}
	else{
		sprintf(dispBuf, "%d S", (NVRAM0[EM_LASER_GP_GROUP_OFF] / 1000));
	}
	SetTextValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_GROUP_OFF, dispBuf);		
}
void standbyKeyEnable(uint8_t ena){//设置Standby使能
	if(StandbyEnableState != ena){
		StandbyEnableState = ena;
		SetControlEnable(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_KEY_STANDBY, ena);
		SetControlEnable(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_KEY_STANDBY, ena);
		SetControlEnable(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_KEY_STANDBY, ena);
		SetControlEnable(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_KEY_STANDBY, ena);
		SetControlEnable(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_KEY_STANDBY, ena);
		SetControlEnable(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_KEY_STANDBY, ena);
	}
}
void standbyKeyValue(uint8_t value){//设置Standby键值
	SetButtonValue(GDDC_PAGE_STANDBY_CW, GDDC_PAGE_STANDBY_KEY_STANDBY, value);
	SetButtonValue(GDDC_PAGE_STANDBY_SP, GDDC_PAGE_STANDBY_KEY_STANDBY, value);
	SetButtonValue(GDDC_PAGE_STANDBY_MP, GDDC_PAGE_STANDBY_KEY_STANDBY, value);
	SetButtonValue(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_KEY_STANDBY, value);
	SetButtonValue(GDDC_PAGE_STANDBY_SIGNAL, GDDC_PAGE_STANDBY_KEY_STANDBY, value);
	SetButtonValue(GDDC_PAGE_STANDBY_DERMA, GDDC_PAGE_STANDBY_KEY_STANDBY, value);
}
void dcHmiLoopInit(void){//初始化模块
	NVRAM0[EM_HMI_OPERA_STEP] = 0;
	//检查BEEM VOLUME储存值是否合规
	if(NVRAM0[DM_BEEM_VOLUME] > CONFIG_MAX_BEEM_VOLUME){
		NVRAM0[DM_BEEM_VOLUME] = CONFIG_MAX_BEEM_VOLUME;
	}
	if(NVRAM0[DM_BEEM_VOLUME] < CONFIG_MIN_BEEM_VOLUME){
		NVRAM0[DM_BEEM_VOLUME] = CONFIG_MIN_BEEM_VOLUME;
	}
	NVRAM0[EM_COOL_SET_TEMP] = CONFIG_COOL_SET_TEMP;
	NVRAM0[EM_COOL_DIFF_TEMP] = CONFIG_COOL_DIFF_TEMP;
	reloadCorrTab();
	RES(Y_TEC0);
	RES(Y_TEC1);
	SET(Y_FAN0);
	SET(Y_FAN1);
	RES(R_DRIVE_TEMP_HIGH);//屏蔽驱动器过热报警
	SET(R_FIBER_ID_PASS_0);
	SET(R_FIBER_ID_PASS_1);//屏蔽光纤ID检测
}
static void temperatureLoop(void){//温度轮询顺序
	int16_t temp;
	temp = NVRAM0[SPREG_ADC_2];
	TNTC(EM_DIODE_TEMP0, SPREG_ADC_2);//CODE转换为NTC测量温度温度
	temp = NVRAM0[EM_DIODE_TEMP0];
	temp = NVRAM0[SPREG_ADC_3];
	TNTC(EM_DIODE_TEMP1, SPREG_ADC_3);//CODE转换为NTC测量温度温度
	temp = NVRAM0[EM_DIODE_TEMP1];
	temp = NVRAM0[SPREG_ADC_8];
	TENV(EM_ENVI_TEMP, SPREG_ADC_8);//CODE转换为环境温度
	temp = NVRAM0[EM_ENVI_TEMP];
	//判断二极管0是否过热
	if(NVRAM0[EM_DIODE_TEMP0] > CONFIG_APP_DIODE_HIGH_TEMP){
		SET(R_DIODE_TEMP_HIGH_0);
	}
	else{
		RES(R_DIODE_TEMP_HIGH_0);
	}
	//判断环境是否过热
	if(NVRAM0[EM_ENVI_TEMP] > CONFIG_APP_ENVI_HIGH_TEMP){
		SET(R_ENVI_TEMP_HIGH);
	}
	else{
		RES(R_ENVI_TEMP_HIGH);
	}
	//温控执行
	if(NVRAM0[EM_DIODE_TEMP0] > (CONFIG_COOL_SET_TEMP + CONFIG_COOL_DIFF_TEMP)){
		SET(Y_TEC0);
		setLedVar(true);
	}
	if(NVRAM0[EM_DIODE_TEMP0] < (CONFIG_COOL_SET_TEMP + CONFIG_COOL_DIFF_TEMP)){
		RES(Y_TEC0);
		setLedVar(false);
	}
}
static void faultLoop(void){//故障轮询
	uint8_t temp;
	temp = 0;
	temp |= LDB(X_ESTOP);//正常1 
	temp |=	LDB(X_INTERLOCK);//正常1
	temp |= LDB(X_FOOTSWITCH_NC);//正常1
	temp |= LDB(X_FBD0);//正常1
	temp |= LD(R_DIODE_TEMP_HIGH_0);//正常0
	temp |= LD(R_ENVI_TEMP_HIGH);//正常0
	if(temp){
		SET(R_FAULT);
		SET(Y_LED_ALARM);
	}
	else{
		RES(R_FAULT);
		RES(Y_LED_ALARM);
	}
}
void dcHmiLoop(void){//HMI轮训程序
	if(LDP(SPCOIL_PS100MS)){//每100mS更新一次温度
		temperatureLoop();
		faultLoop();
	}
	if(LDP(SPCOIL_PS1000MS)){//每100mS更新一次累计时间
		ADLS1(DM_SYS_RUNTIME_L);	
	}
	if(LD(R_DCHMI_RESET_DONE) && LD(R_DCHMI_RESTORE_DONE)){//HMI复位完成后处理串口指令
		hmiCmdSize = queue_find_cmd(hmiCmdBuffer, CMD_MAX_SIZE);//从缓冲区中获取一条指令         
        if(hmiCmdSize > 0){//接收到指令及判断是否为开机提示                                                            
            ProcessMessage((PCTRL_MSG)hmiCmdBuffer, hmiCmdSize);//指令处理  
        }                                                                             
	}
	//状态机
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_POWERUP){//上电步骤	
		SET(Y_LED_POWERON);//电源灯常亮
#if CONFIG_USING_BACKGROUND_APP == 1
		loadScheme();//从掉电存储寄存器中恢复方案参数
#endif		
		NVRAM0[EM_DC_DEFAULT_PASSCODE0] = CONFIG_HMI_DEFAULT_PASSSWORD0;
		NVRAM0[EM_DC_DEFAULT_PASSCODE1] = CONFIG_HMI_DEFAULT_PASSSWORD1;
		NVRAM0[EM_DC_DEFAULT_PASSCODE2] = 0;
		NVRAM0[EM_DC_DEFAULT_PASSCODE3] = 0;
		NVRAM0[DM_DC_OLD_PASSCODE2] = 0;
		NVRAM0[DM_DC_OLD_PASSCODE3] = 0;
		
		NVRAM0[EM_DC_NEW_PASSCODE2] = 0;
		NVRAM0[EM_DC_NEW_PASSCODE3] = 0;
		//检查储存密码是否合规
		NVRAM0[TM_START + 0] = NVRAM0[DM_DC_OLD_PASSCODE0] & 0x00FF;
		NVRAM0[TM_START + 1] = (NVRAM0[DM_DC_OLD_PASSCODE0] >> 8) & 0x00FF;
		NVRAM0[TM_START + 2] = NVRAM0[DM_DC_OLD_PASSCODE1] & 0x00FF;
		NVRAM0[TM_START + 3] = (NVRAM0[DM_DC_OLD_PASSCODE1] >> 8) & 0x00FF;
		if((NVRAM0[TM_START + 0] < 0x30) || (NVRAM0[TM_START + 0] > 0x39) ||
		   (NVRAM0[TM_START + 1] < 0x30) || (NVRAM0[TM_START + 1] > 0x39) ||
		   (NVRAM0[TM_START + 2] < 0x30) || (NVRAM0[TM_START + 2] > 0x39) ||
		   (NVRAM0[TM_START + 3] < 0x30) || (NVRAM0[TM_START + 3] > 0x39)){
			NVRAM0[DM_DC_OLD_PASSCODE0] = CONFIG_HMI_DEFAULT_PASSSWORD0;
			NVRAM0[DM_DC_OLD_PASSCODE1] = CONFIG_HMI_DEFAULT_PASSSWORD1;  
		}	
		SET(R_DCHMI_RESET_DOING);
		hmiCmdSize = 0;
		queue_reset();//清空HMI指令接收缓冲区	
		NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_RESTORE_HMI;
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_RESTORE_HMI){//等待HMI复位
		T100MS(T100MS_HMI_POWERUP_DELAY, true, CONFIG_CHECK_DELAY_TIME);
		if(LD(T_100MS_START * 16 + T100MS_HMI_POWERUP_DELAY)){
			T100MS(T100MS_HMI_POWERUP_DELAY, false, CONFIG_CHECK_DELAY_TIME);
			RES(R_DCHMI_RESET_DOING);
			SET(R_DCHMI_RESET_DONE);	
			//HMI从内置FLASH中恢复设置	
			SET(R_DCHMI_RESTORE_DOING);
			FlashRestoreControl(FLASH_DATA_VERSION, FLASH_DATA_ADDR);
			RES(R_DCHMI_RESTORE_DOING);
			SET(R_DCHMI_RESTORE_DONE);
			//设置HMI页面
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_WAIT_ENTER_PASSCODE;
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_POWERUP;//HMI页面
			MsgId = 0xFF;//当前显示的信息ID
			StandbyEnableState = 0xFF;//Standby按键状态
			StandbyTouchState = 0xFF;
			standbyKeyValue(false);
			standbyKeyEnable(true);
			SetTextValue(GDDC_PAGE_PASSCODE, GDDC_PAGE_PASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
			SetTextValue(GDDC_PAGE_NEW_PASSCODE, GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));	
			SetBackLight(getLcdDuty(NVRAM0[DM_LCD_BRG]));
			SetScreen(NVRAM0[EM_DC_PAGE]);	
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_RESTORE_HMI;	
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_CHECK_FAIL_DISPLAY){//自检错误显示
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_WAIT_ENTER_PASSCODE){//等待开机密码输入
		T100MS(T100MS_ENTER_PASSCODE_DELAY, true, CONFIG_CHECK_DELAY_TIME);
		if(LD(T_100MS_START * 16 + T100MS_ENTER_PASSCODE_DELAY)){
			T100MS(T100MS_ENTER_PASSCODE_DELAY, false, CONFIG_CHECK_DELAY_TIME);
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_INPUT;
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_PASSCODE;
			SetScreen(NVRAM0[EM_DC_PAGE]);
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_WAIT_ENTER_PASSCODE;
		}
		return;
	}
	
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_PASSCODE_INPUT){//输入开机密码
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_PASSCODE_NEW0){//等待输入新密码
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_STANDBY){//待机状态机
		switch(NVRAM0[EM_LASER_PULSE_MODE]){//脉宽自动加减
			case LASER_MODE_SP:{
				if(LD(R_STANDBY_KEY_POSWIDTH_ADD_DOWN)){//正脉宽加按键
					T10MS(T10MS_POSWIDTH_ADD_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_POSWIDTH_ADD_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_SP_POSWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_SP_POSWIDTH]);	
							updatePosWidthDisplay(LASER_MODE_SP);
						}
					}
				}		
				if(LD(R_STANDBY_KEY_POSWIDTH_DEC_DOWN)){//正脉宽减按键
					T10MS(T10MS_POSWIDTH_DEC_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_POSWIDTH_DEC_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_SP_POSWIDTH] = pulseWidthDec(NVRAM0[EM_LASER_SP_POSWIDTH]);	
							updatePosWidthDisplay(LASER_MODE_SP);
						}
					}
				}
				break;
			}
			case LASER_MODE_MP:{
				if(LD(R_STANDBY_KEY_POSWIDTH_ADD_DOWN)){//正脉宽加按键
					T10MS(T10MS_POSWIDTH_ADD_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_POSWIDTH_ADD_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_MP_POSWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_MP_POSWIDTH]);
							updatePosWidthDisplay(LASER_MODE_MP);
						}
					}
				}				
				if(LD(R_STANDBY_KEY_POSWIDTH_DEC_DOWN)){//正脉宽减按键
					T10MS(T10MS_POSWIDTH_DEC_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_POSWIDTH_DEC_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_MP_POSWIDTH] = pulseWidthDec(NVRAM0[EM_LASER_MP_POSWIDTH]);	
							updatePosWidthDisplay(LASER_MODE_MP);
						}
					}
				}
				if(LD(R_STANDBY_KEY_NEGWIDTH_ADD_DOWN)){//负脉宽加按键
					T10MS(T10MS_NEGWIDTH_ADD_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_NEGWIDTH_ADD_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_MP_NEGWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_MP_NEGWIDTH]);
							updateNegWidthDisplay(LASER_MODE_MP);
						}
					}
				}
				if(LD(R_STANDBY_KEY_NEGWIDTH_DEC_DOWN)){//负脉宽减按键
					T10MS(T10MS_NEGWIDTH_DEC_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_NEGWIDTH_DEC_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_MP_NEGWIDTH] = pulseWidthDec(NVRAM0[EM_LASER_MP_NEGWIDTH]);
							updateNegWidthDisplay(LASER_MODE_MP);
						}
					}
				}
				break;
			}
			case LASER_MODE_GP:{
				if(LD(R_STANDBY_KEY_POSWIDTH_ADD_DOWN)){//正脉宽加按键
					T10MS(T10MS_POSWIDTH_ADD_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_POSWIDTH_ADD_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_GP_POSWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_GP_POSWIDTH]);	
							updatePosWidthDisplay(LASER_MODE_GP);
						}
					}
				}				
				if(LD(R_STANDBY_KEY_POSWIDTH_DEC_DOWN)){//正脉宽减按键
					T10MS(T10MS_POSWIDTH_DEC_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_POSWIDTH_DEC_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_GP_POSWIDTH] = pulseWidthDec(NVRAM0[EM_LASER_GP_POSWIDTH]);		
							updatePosWidthDisplay(LASER_MODE_GP);
						}
					}
				}
				if(LD(R_STANDBY_KEY_NEGWIDTH_ADD_DOWN)){//负脉宽加按键
					T10MS(T10MS_NEGWIDTH_ADD_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_NEGWIDTH_ADD_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_GP_NEGWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_GP_NEGWIDTH]);		
							updateNegWidthDisplay(LASER_MODE_GP);
						}
					}
				}
				if(LD(R_STANDBY_KEY_NEGWIDTH_DEC_DOWN)){//负脉宽减按键
					T10MS(T10MS_NEGWIDTH_DEC_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_NEGWIDTH_DEC_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_GP_NEGWIDTH] = pulseWidthDec(NVRAM0[EM_LASER_GP_NEGWIDTH]);	
							updateNegWidthDisplay(LASER_MODE_GP);
						}
					}
				}
				if(LD(R_STANDBY_KEY_TIMES_ADD_DOWN)){//脉冲数加按键
					T10MS(T10MS_TIMES_ADD_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_TIMES_ADD_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							if(NVRAM0[EM_LASER_GP_TIMES] < CONFIG_MAX_LASER_TIMES){
								NVRAM0[EM_LASER_GP_TIMES] += 1;
								SetTextInt32(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_TIMES, NVRAM0[EM_LASER_GP_TIMES], 1, 0);	
							}
						}
					}
				}
				if(LD(R_STANDBY_KEY_TIMES_DEC_DOWN)){//脉冲数减按键
					T10MS(T10MS_TIMES_DEC_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_TIMES_DEC_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							if(NVRAM0[EM_LASER_GP_TIMES] > CONFIG_MIN_LASER_TIMES){
								NVRAM0[EM_LASER_GP_TIMES] -= 1;
								SetTextInt32(GDDC_PAGE_STANDBY_GP, GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_TIMES, NVRAM0[EM_LASER_GP_TIMES], 1, 0);	
							}
						}
					}
				}			
				if(LD(R_STANDBY_KEY_GROUP_OFF_ADD_DOWN)){//脉冲间隔加按键
					T10MS(T10MS_GROUP_OFF_ADD_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_GROUP_OFF_ADD_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_GP_GROUP_OFF] =	pulseWidthAdd(NVRAM0[EM_LASER_GP_GROUP_OFF]);	
							updateGroupOffDisplay();			
						}								
					}
				}
				if(LD(R_STANDBY_KEY_GROUP_OFF_DEC_DOWN)){//脉冲间隔减按键
					T10MS(T10MS_GROUP_OFF_DEC_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_GROUP_OFF_DEC_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_GP_GROUP_OFF] =	pulseWidthDec(NVRAM0[EM_LASER_GP_GROUP_OFF]);	
							updateGroupOffDisplay();	
						}
					}
				}
				break;
			}
			case LASER_MODE_DERMA:{
				if(LD(R_STANDBY_KEY_POSWIDTH_ADD_DOWN)){//正脉宽加按键
					T10MS(T10MS_POSWIDTH_ADD_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_POSWIDTH_ADD_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_DERMA_POSWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_DERMA_POSWIDTH]);		
							updatePosWidthDisplay(LASER_MODE_DERMA);
						}
					}
				}				
				if(LD(R_STANDBY_KEY_POSWIDTH_DEC_DOWN)){//正脉宽减按键
					T10MS(T10MS_POSWIDTH_DEC_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_POSWIDTH_DEC_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_DERMA_POSWIDTH] = pulseWidthDec(NVRAM0[EM_LASER_DERMA_POSWIDTH]);	
							updatePosWidthDisplay(LASER_MODE_DERMA);
						}
					}
				}
				if(LD(R_STANDBY_KEY_NEGWIDTH_ADD_DOWN)){//负脉宽加按键
					T10MS(T10MS_NEGWIDTH_ADD_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_NEGWIDTH_ADD_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_DERMA_NEGWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_DERMA_NEGWIDTH]);	
							updateNegWidthDisplay(LASER_MODE_DERMA);
						}
					}
				}
				if(LD(R_STANDBY_KEY_NEGWIDTH_DEC_DOWN)){//负脉宽减按键
					T10MS(T10MS_NEGWIDTH_DEC_KEYDOWN_DELAY, true, CONFIG_KEY_REPEAT_DELAY_TIME);
					if(LD(T_10MS_START * 16 + T10MS_NEGWIDTH_DEC_KEYDOWN_DELAY)){	
						if(LDP(SPCOIL_PS100MS) || LDN(SPCOIL_PS100MS)){
							NVRAM0[EM_LASER_DERMA_NEGWIDTH] = pulseWidthDec(NVRAM0[EM_LASER_DERMA_NEGWIDTH]);
							updateNegWidthDisplay(LASER_MODE_DERMA);
						}
					}
				}					
				break;
			}
			default:break;
		}
		if(LD(R_FAULT)){//有故障显示
			//打开蜂鸣器报警
			standbyKeyEnable(false);//禁止Standby触摸
			if(LDB(X_ESTOP)){//急停按下
				updateWarnMsgDisplay(MSG_ESTOP_PRESS);		
			}
			else if(LDB(X_INTERLOCK)){//安全连锁拔出
				updateWarnMsgDisplay(MSG_INTERLOCK_UNPLUG);
			}
			else if(LDB(X_FBD0)){//光纤拔出
				updateWarnMsgDisplay(MSG_FIBER_UNPLUG);
			}
			else if(LDB(X_FOOTSWITCH_NC)){//脚踏拔出
				updateWarnMsgDisplay(MSG_FOOTSWITCH_UNPLUG);
			}
			else if(LDB(R_FIBER_ID_PASS_0)){//光纤ID不匹配
				updateWarnMsgDisplay(MSG_FIBER_MISSMATE);
			}
			else if(LD(R_DIODE_TEMP_HIGH_0)){//激光器高温保护
				updateWarnMsgDisplay(MSG_DIODE_HTEMP);
			}
			else if(LD(R_ENVI_TEMP_HIGH)){//环境高温保护
				updateWarnMsgDisplay(MSG_ENVI_HTEMP);
			}
			BeemMode = BEEM_MODE_3;
			BeemDuty = getBeemDuty(NVRAM0[DM_BEEM_VOLUME]);
			BeemFreq = BEEM_FREQ_0;
			BeemEnable = 1;;
		}
		else{//无故障显示
			standbyKeyEnable(true);
			BeemEnable = 0;
			updateWarnMsgDisplay(MSG_NO_ERROR);
		}
		if(LD(R_STANDBY_KEY_ENTER_OPTION_DOWN)){//点击OPTION
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_OPTION;
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_OPTION;
			updateOptionDisplay();
			SetScreen(NVRAM0[EM_DC_PAGE]);
			RES(R_STANDBY_KEY_ENTER_OPTION_DOWN);
		}else if(LD(R_STANDBY_KEY_ENTER_SCHEME_DOWN)){//点击SCHEME
			updateSchemeDisplay();//更新方案界面名称
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_SCHEME;
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_SCHEME;
			SetScreen(NVRAM0[EM_DC_PAGE]);
			RES(R_STANDBY_KEY_ENTER_SCHEME_DOWN);
		}else if(LD(R_STANDBY_KEY_STNADBY_DOWN)){//点击READY	
			if(LD(X_FOOTSWITCH_NO)){//检测脚踏踩下
				standbyTouchEnable(false);
				//打开蜂鸣器
				BeemMode = BEEM_MODE_3;
				BeemDuty = getBeemDuty(NVRAM0[DM_BEEM_VOLUME]);
				BeemCounter = 0;
				BeemFreq = BEEM_FREQ_0;
				BeemEnable = 1;
				standbyKeyEnable(false);//Standby禁止点击
				updateWarnMsgDisplay(MSG_FOOT_DEPRESSED);//显示错误信息
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_READY_ERROR;	
			}
			else if(LDB(R_FAULT)){//无故障进入Standby->Ready启动过程
				standbyTouchEnable(false);
				standbyKeyEnable(false);
				NVRAM0[SPREG_LASER_SELECT] = NVRAM0[EM_LASER_SELECT];
				NVRAM0[SPREG_LASER_MODE] = NVRAM0[EM_LASER_PULSE_MODE];
				switch(NVRAM0[SPREG_LASER_MODE]){
					case LASER_MODE_SP:{
						NVRAM0[SPREG_LASER_TMATE] 			= NVRAM0[EM_LASER_SP_POSWIDTH];//激光脉冲正脉宽 10mS
						break;
					}
					case LASER_MODE_MP:{
						NVRAM0[SPREG_LASER_TMATE] 			= NVRAM0[EM_LASER_MP_POSWIDTH];//激光脉冲正脉宽 10mS
						NVRAM0[SPREG_LASER_TOVERTIME] 		= NVRAM0[EM_LASER_MP_POSWIDTH] + NVRAM0[EM_LASER_MP_NEGWIDTH];//激光脉冲周期 25mS
						break;
					}
					case LASER_MODE_GP:{
						NVRAM0[SPREG_LASER_TMATE] 			= NVRAM0[EM_LASER_GP_POSWIDTH];//激光脉冲正脉宽 10mS
						NVRAM0[SPREG_LASER_TOVERTIME] 		= NVRAM0[EM_LASER_GP_POSWIDTH] + NVRAM0[EM_LASER_GP_NEGWIDTH];//激光脉冲周期 25mS
						NVRAM0[SPREG_LASER_PMATE] 			= NVRAM0[EM_LASER_GP_TIMES];//10个脉冲
						NVRAM0[SPREG_LASER_POVERTIME] 		= NVRAM0[EM_LASER_GP_GROUP_OFF];//间隔33mS
						break;
					}
					case LASER_MODE_DERMA:{
						NVRAM0[SPREG_LASER_TMATE] 			= NVRAM0[EM_LASER_DERMA_POSWIDTH];//激光脉冲正脉宽 10mS
						NVRAM0[SPREG_LASER_TOVERTIME] 		= NVRAM0[EM_LASER_DERMA_POSWIDTH] + NVRAM0[EM_LASER_DERMA_NEGWIDTH];//激光脉冲周期 25mS
						break;
					}
					default:break;
			}
#if CONFIG_USING_BACKGROUND_APP == 1
				PCLAR0(EM_LASER_POWER_CH0, SPREG_DAC_0);//功率->DAC CODE
				PCLAR1(EM_LASER_POWER_CH1, SPREG_DAC_1);//功率->DAC CODE
#endif
				//打开蜂鸣器
				BeemMode = BEEM_MODE_0;
				BeemDuty = getBeemDuty(NVRAM0[DM_BEEM_VOLUME]);
				BeemCounter = 0;
				BeemFreq = BEEM_FREQ_0;
				BeemEnable = 1;
				//打开指示激光
				AimDuty0 = getAimDuty(NVRAM0[DM_AIM_BRG]);
				AimEnable0 = true;	
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_READY_LOAD_PARA;	
			}
			RES(R_STANDBY_KEY_STNADBY_DOWN);
		}else if(LD(R_STANDBY_KEY_SCHEME_SAVE_DOWN)){	
			//禁止屏幕触摸
			standbyTouchEnable(false);
			saveScheme();//EM->FD
			FDSAV_ONE(NVRAM0[DM_SCHEME_NUM]);//FDRAM->EPROM
			RES(R_STANDBY_KEY_SCHEME_SAVE_DOWN);
			//SetScreen(NVRAM0[EM_DC_PAGE]);
			standbyTouchEnable(true);
			//使能屏幕触摸
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_READY_LOAD_PARA){//等待蜂鸣器
		T100MS(T100MS_READY_BEEM_DELAY, true, 20);//启动计时器延时2000mS//打开计时器
		//清空计时器
		if(LD(T_100MS_START * 16 + T100MS_READY_BEEM_DELAY)){
			T100MS(T100MS_READY_BEEM_DELAY, false, 3);
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_READY_LOAD_DONE;
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_READY_LOAD_PARA;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_READY_LOAD_DONE){//参数载入完毕并停止蜂鸣器
		BeemEnable = 0;//关闭蜂鸣器
		NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_LASER_WAIT_TRIGGER;
		standbyKeyEnable(true);
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_LASER_WAIT_TRIGGER){//等待触发激光	
		updateWarnMsgDisplay(MSG_WAIT_TRIGGER);
		if(LD(R_FAULT)){//Ready状态检测到故障
			EDLAR();//停止发射
			NVRAM0[SPREG_DAC_0] = 0;
			NVRAM0[SPREG_DAC_1] = 1;
			AimEnable0 = false;	
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;
			standbyKeyValue(false);//Standby按键恢复到Standby
			standbyTouchEnable(true);//恢复触摸屏触摸
		}
		else if(LD(R_STANDBY_KEY_STNADBY_UP)){//回到等待状态
			EDLAR();//停止发射
			NVRAM0[SPREG_DAC_0] = 0;
			NVRAM0[SPREG_DAC_1] = 1;
			AimEnable0 = false;	
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;
			standbyTouchEnable(true);
			RES(R_STANDBY_KEY_STNADBY_UP);
		}
		else if(LD(MR_FOOSWITCH_HAND_SWITCH)){//上升沿触发
			if(LDP(X_FOOTSWITCH_NO)){//发射激光
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_LASER_EMITING;				
				STLAR();
				updateWarnMsgDisplay(MSG_LASER_EMIT);
			}
		}
		else{//电平触发
			if(LD(X_FOOTSWITCH_NO)){//发射激光			
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_LASER_EMITING;				
				STLAR();
				updateWarnMsgDisplay(MSG_LASER_EMIT);
			}	
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_LASER_EMITING){//发激光中
		if(LDP(SPCOIL_PS1000MS) || LDN(SPCOIL_PS1000MS)){//每隔1S刷新累计时间和能量
			NVRAM0[TM_START] = (int16_t)((fp32_t)(NVRAM0[EM_TOTAL_POWER]) / 10);
			MULTS16(EM_RELEASE_TOTAL_TIME, TM_START, EM_RELEASE_TOTAL_ENERGY);//计算发射能量
			updateReleaseTimeEnergy();//更新累计发射时间和能量
		}
		if(LD(R_FAULT)){//发现故障
			EDLAR();
			NVRAM0[SPREG_DAC_0] = 0;
			NVRAM0[SPREG_DAC_1] = 0;
			AimEnable0 = false;//关闭指示光	
			BeemEnable =false;//关闭蜂鸣器			
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;
			standbyKeyValue(false);
			standbyTouchEnable(true);
			updateWarnMsgDisplay(MSG_NO_ERROR);
		}
		else if(LD(R_STANDBY_KEY_STNADBY_UP)){//Ready->Standby
			EDLAR();
			NVRAM0[SPREG_DAC_0] = 0;
			NVRAM0[SPREG_DAC_1] = 0;
			AimEnable0 = false;//关闭指示光	
			BeemEnable =false;//关闭蜂鸣器			
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;
			standbyKeyValue(false);
			standbyTouchEnable(true);
			updateWarnMsgDisplay(MSG_NO_ERROR);
			RES(R_STANDBY_KEY_STNADBY_UP);
		}
		else if(LD(MR_FOOSWITCH_HAND_SWITCH)){//上升沿触发
			if(LDP(X_FOOTSWITCH_NO)){//关闭激光
				EDLAR();
				updateWarnMsgDisplay(MSG_NO_ERROR);
				BeemEnable = false;//关闭蜂鸣器	
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_LASER_WAIT_TRIGGER;
			}
		}
		else{
			if(LDB(X_FOOTSWITCH_NO)){//关闭激光
				EDLAR(); 
				updateWarnMsgDisplay(MSG_NO_ERROR);
				BeemEnable = false;//关闭蜂鸣器	
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_LASER_WAIT_TRIGGER;
			}
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_READY_ERROR){//Ready检测到脚踏踩下
		if(LDB(X_FOOTSWITCH_NO)){//检测到脚踏状态恢复正常
			BeemEnable = 0;
			standbyKeyValue(false);
			standbyKeyEnable(true);
			updateWarnMsgDisplay(MSG_NO_ERROR);
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_READY_ERROR;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_OPTION){//选项界面
		if(LD(R_OPTION_KEY_ENTER_INFORMATION_DOWN)){
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_INFORMATION;
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_INFORMATION;
			SetScreen(NVRAM0[EM_DC_PAGE]);
			RES(R_OPTION_KEY_ENTER_INFORMATION_DOWN);
		}
		if(LD(R_OPTION_KEY_ENTER_OK_DOWN)){//确定
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;
			updateStandbyDisplay();
			RES(R_OPTION_KEY_ENTER_OK_DOWN);
		}
		if(LD(R_OPTION_KEY_ENTER_DIAGNOSIS_DOWN)){//进入诊断状态
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_DIAGNOSIS;
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_DIAGNOSIS;
			SetScreen(NVRAM0[EM_DC_PAGE]);
			RES(R_OPTION_KEY_ENTER_DIAGNOSIS_DOWN);
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_INFORMATION){//信息界面
		if(LD(R_INFORMATION_KEY_OK_DOWN)){
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_OPTION;
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_OPTION;
			SetScreen(NVRAM0[EM_DC_PAGE]);
			RES(R_INFORMATION_KEY_OK_DOWN);	
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_SCHEME){//方案界面
		if(LD(R_SCHEME_KEY_OK_DOWN)){//确定
			NVRAM0[DM_SCHEME_NUM] = NVRAM0[EM_SCHEME_NUM_TMP];
			loadSchemeTmpName();
			updateStandbyDisplay();
			returnStandbyDisplay();
			RES(R_SCHEME_KEY_OK_DOWN);
		}
		else if(LD(R_SCHEME_KEY_CANCEL_DOWN)){//取消
			loadFdram();//NVRAM->FD
			loadScheme();//FD->EM
			updateStandbyDisplay();
			returnStandbyDisplay();
			RES(R_SCHEME_KEY_CANCEL_DOWN);
		}
		else if(LD(R_SCHEME_KEY_RENAME_DOWN)){//改名
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_RENAME;
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_RENAME;
			//将EM_SCHEME_NUM_TMP指向的名称更新RENAME输入框
			SetTextValue(GDDC_PAGE_RENAME, GDDC_PAGE_RENAME_TEXTDISPLAY_NEWNAME, (uint8_t*)(&TMPRAM[(NVRAM0[EM_SCHEME_NUM_TMP] * 15)]));
			SetScreen(NVRAM0[EM_DC_PAGE]);
			RES(R_SCHEME_KEY_RENAME_DOWN);
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_RENAME){//方案改名
		if(LD(R_RENAME_TEXTDISPLAY_READ_DONE)){//更名完毕				
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_SCHEME;
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_SCHEME;
			SetScreen(NVRAM0[EM_DC_PAGE]);
			RES(R_RENAME_TEXTDISPLAY_READ_DONE);	
		}
		else if(LD(R_RENAME_KEY_EXIT_DOWN)){
			SetTextValue(GDDC_PAGE_RENAME, GDDC_PAGE_RENAME_TEXTDISPLAY_NEWNAME, "");//清空出入框
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_SCHEME;
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_SCHEME;
			SetScreen(NVRAM0[EM_DC_PAGE]);
			RES(R_RENAME_KEY_EXIT_DOWN);
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_DIAGNOSIS){//诊断界面
		if(LD(R_DIAGNOSIS_OK_DOWN)){//返回Option
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_OPTION;
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_OPTION;
			SetScreen(NVRAM0[EM_DC_PAGE]);
			RES(R_DIAGNOSIS_OK_DOWN);
		}
		else{
			if(LDP(SPCOIL_PS1000MS)){
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_INTERLOCK , LD(X_INTERLOCK), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_ESTOP , LD(X_ESTOP), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_FOOTSWITCH_NO , LD(X_FOOTSWITCH_NO), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_FOOTSWITCH_NC , LD(X_FOOTSWITCH_NC), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_LDR_FAULT0 , LD(X_LDR_FAULT0), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_LDR_FAULT1 , LD(X_LDR_FAULT1), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_FBD0 , LD(X_FBD0), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_FBD1 , LD(X_FBD1), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_LED_POWERON , LD(Y_LED_POWERON), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_LED_EMIT , LD(Y_LED_EMIT), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_LED_ALARM , LD(Y_LED_ALARM), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y3 , LD(Y_OUT3), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y4 , LD(Y_OUT4), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y5 , LD(Y_OUT5), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y6 , LD(Y_OUT6), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y7 , LD(Y_OUT7), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_FAN0 , LD(Y_FAN0), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_FAN1 , LD(Y_FAN1), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_TEC0 , LD(Y_TEC0), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_TEC1 , LD(Y_TEC1), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_OUT0 , LD(SPCOIL_SPWM_OUT_0), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_OUT1 , LD(SPCOIL_SPWM_OUT_1), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_OUT2 , LD(SPCOIL_SPWM_OUT_2), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_OUT3 , LD(SPCOIL_SPWM_OUT_3), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_RESET0 , LD(SPCOIL_SPWM_RESET_0), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_RESET1 , LD(SPCOIL_SPWM_RESET_1), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_RESET2 , LD(SPCOIL_SPWM_RESET_2), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_RESET3 , LD(SPCOIL_SPWM_RESET_3), 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC0 , NVRAM0[SPREG_ADC_0], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC1 , NVRAM0[SPREG_ADC_1], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC2 , NVRAM0[SPREG_ADC_2], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC3 , NVRAM0[SPREG_ADC_3], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC4 , NVRAM0[SPREG_ADC_4], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC5 , NVRAM0[SPREG_ADC_5], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC6 , NVRAM0[SPREG_ADC_6], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC7 , NVRAM0[SPREG_ADC_7], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC8 , NVRAM0[SPREG_ADC_8], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_DAC0 , NVRAM0[SPREG_DAC_0], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_DAC1 , NVRAM0[SPREG_DAC_1], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_POS0 , NVRAM0[SPREG_SPWM_POS_0], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_POS1 , NVRAM0[SPREG_SPWM_POS_1], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_POS2 , NVRAM0[SPREG_SPWM_POS_2], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_POS3 , NVRAM0[SPREG_SPWM_POS_3], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_CYCLE0 , NVRAM0[SPREG_SPWM_CYCLE_0], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_CYCLE1 , NVRAM0[SPREG_SPWM_CYCLE_1], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_CYCLE2 , NVRAM0[SPREG_SPWM_CYCLE_2], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_SPWM_CYCLE3 , NVRAM0[SPREG_SPWM_CYCLE_3], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_DT0 , NVRAM0[EM_DIODE_TEMP0], 1, 0);
				SetTextInt32(GDDC_PAGE_DIAGNOSIS, GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_DT1 , NVRAM0[EM_DIODE_TEMP1], 1, 0);
			}
		}
		return;
	}
}

//消息处理流程
//msg 待处理消息
//size 消息长度
void ProcessMessage( PCTRL_MSG msg, uint16_t size ){
	uint8_t cmd_type = msg->cmd_type;                                                     //指令类型
    uint8_t ctrl_msg = msg->ctrl_msg;                                                     //消息的类型
    uint8_t control_type = msg->control_type;                                             //控件类型
    uint16_t screen_id = PTR2U16(&msg->screen_id);                                        //画面ID
    uint16_t control_id = PTR2U16(&msg->control_id);                                      //控件ID
    uint32_t value = PTR2U32(msg->param);                                                 //数值
    switch(cmd_type){  
		case NOTIFY_TOUCH_PRESS:{//触摸屏按下
			break;
		}
		case NOTIFY_TOUCH_RELEASE:{//触摸屏松开
			NotifyTouchXY(hmiCmdBuffer[1],PTR2U16(hmiCmdBuffer + 2),PTR2U16(hmiCmdBuffer + 4)); 
			break;
		}			
		case NOTIFY_WRITE_FLASH_OK:{//写FLASH成功
			NotifyWriteFlash(1);                                                      
			break;              
		}			
		case NOTIFY_WRITE_FLASH_FAILD:{//写FLASH失败
			NotifyWriteFlash(0);                        	                              
			break;            
		}			
		case NOTIFY_READ_FLASH_OK:{//读取FLASH成功
			NotifyReadFlash(1, hmiCmdBuffer + 2, size - 6);//去除帧头帧尾
			break;                                  
		}			
		case NOTIFY_READ_FLASH_FAILD:{//读取FLASH失败
			NotifyReadFlash(0,0,0);                                                   
			break;  
		}			
		case NOTIFY_READ_RTC:{//读取RTC时间
			NotifyReadRTC(hmiCmdBuffer[2], hmiCmdBuffer[3], hmiCmdBuffer[4], hmiCmdBuffer[5], hmiCmdBuffer[6], hmiCmdBuffer[7], hmiCmdBuffer[8]);
			break;
		}
		case NOTIFY_CONTROL:{
			if(ctrl_msg==MSG_GET_CURRENT_SCREEN){//画面ID变化通知
                NotifyScreen(screen_id);//画面切换调动的函数
            }
            else{
				switch(control_type){
					case kCtrlButton:{//按钮控件
						NotifyButton(screen_id,control_id,msg->param[1]);                  
						break;  
					}
					case kCtrlText:{//文本控件
						NotifyText(screen_id,control_id,msg->param);                       
						break;
					}						
					case kCtrlProgress:{//进度条控件
						NotifyProgress(screen_id,control_id,value);                        
						break;
					}						
					case kCtrlSlider:{//滑动条控件
						NotifySlider(screen_id,control_id,value);                          
						break;
					}						
					case kCtrlMeter:{//仪表控件
						NotifyMeter(screen_id,control_id,value);                           
						break;
					}
					case kCtrlMenu:{//菜单控件
						NotifyMenu(screen_id,control_id,msg->param[0],msg->param[1]);      
						break;
					}
					case kCtrlSelector:{//选择控件
						NotifySelector(screen_id,control_id,msg->param[0]);                
						break;
					}						
					case kCtrlRTC:{//倒计时控件
						NotifyTimer(screen_id,control_id);
						break;
					}
					default:{
						break;
					}
				}
            } 
            break;  
        } 
    case NOTIFY_HandShake:
        //NOTIFYHandShake();
        break;
    default:
        break;
    }
}


void NotifyScreen(uint16_t screen_id){
    //TODO: 添加用户代码

}

//触摸坐标事件响应
//press 1按下触摸屏，3松开触摸屏;x x坐标;y y坐标
void NotifyTouchXY(uint8_t press,uint16_t x,uint16_t y){
    //TODO: 添加用户代码
}


/*! 
*  \brief  更新数据
*/ 
void UpdateUI(void){

}


                                                                          
/*!                                                                              
*  \brief  滑动条控件通知                                                       
*  \details  当滑动条改变(或调用GetControlValue)时，执行此函数                  
*  \param screen_id 画面ID                                                      
*  \param control_id 控件ID                                                     
*  \param value 值                                                              
*/                                                                              
void NotifySlider(uint16_t screen_id, uint16_t control_id, uint32_t value){                                                                                                                                  

}

/*! 
*  \brief  仪表控件通知
*  \details  调用GetControlValue时，执行此函数
*  \param screen_id 画面ID
*  \param control_id 控件ID
*  \param value 值
*/
void NotifyMeter(uint16_t screen_id, uint16_t control_id, uint32_t value){
    //TODO: 添加用户代码
}

/*! 
*  \brief  菜单控件通知
*  \details  当菜单项按下或松开时，执行此函数
*  \param screen_id 画面ID
*  \param control_id 控件ID
*  \param item 菜单项索引
*  \param state 按钮状态：0松开，1按下
*/
void NotifyMenu(uint16_t screen_id, uint16_t control_id, uint8_t item, uint8_t state){

}

/*! 
*  \brief  选择控件通知
*  \details  当选择控件变化时，执行此函数
*  \param screen_id 画面ID
*  \param control_id 控件ID
*  \param item 当前选项
*/
void NotifySelector(uint16_t screen_id, uint16_t control_id, uint8_t  item){


}

/*! 
*  \brief  定时器超时通知处理
*  \param screen_id 画面ID
*  \param control_id 控件ID
*/
void NotifyTimer(uint16_t screen_id, uint16_t control_id){
}

/*! 
*  \brief  读取用户FLASH状态返回
*  \param status 0失败，1成功
*  \param _data 返回数据
*  \param length 数据长度
*/
void NotifyReadFlash(uint8_t status,uint8_t *_data,uint16_t length){
    //TODO: 添加用户代码
}

/*! 
*  \brief  写用户FLASH状态返回
*  \param status 0失败，1成功
*/
void NotifyWriteFlash(uint8_t status){
    //TODO: 添加用户代码
}


void NotifyReadRTC(uint8_t year,uint8_t month,uint8_t week,uint8_t day,uint8_t hour,uint8_t minute,uint8_t second){
     
}

/*! 
*  \brief  string 转 int
*  \param char *str  数字字符串
*/
int str2int(const char *str){
    int temp = 0;
    const char *ptr = str;                                                            //记录字符串

    if(*str == '-' || *str == '+')                                                    //判断第一个字符是否是正负
    {                                                                            
        str++;                                                                        //偏移一位
    }                                                                            
    while(*str != 0)                                                             
    {                                                                            
        if ((*str < '0') || (*str > '9'))                                             //检测是否为数字字符 
        {                                                                        
            break;                                                               
        }                                                                        
        temp = temp * 10 + (*str - '0');                                              //转换
        str++;                                                                        //偏移一位
    }                                                                            
    if (*ptr == '-')                                                                  //如果为负数就取反
    {
        temp = -temp;
    }

    return temp;   
}

#endif