#ifndef __HMI_H__
#define __HMI_H__
/*****************************************************************************/
#define FSMSTEP_POWERUP												0//上电
//HMI初始操作
#define FSMSTEP_RESTORE_HMI											100//HMI 恢复储存数据
#define FSMSTEP_CHECK_FAIL_DISPLAY									200//失败自检
//密码输入状态
#define FSMSTEP_WAIT_ENTER_PASSCODE									300
#define FSMSTEP_PASSCODE_INPUT										301//密码输入状态
#define FSMSTEP_PASSCODE_NEW0										302//密码更改状态第一次输入
#define FSMSTEP_PASSCODE_NEW1										303//密码更改状态第二次输入
//STNADBY状态
#define FSMSTEP_STANDBY												400//等待状态
#define FSMSTEP_READY_LOAD_PARA										401//载入参数
#define FSMSTEP_READY_LOAD_DONE										402//载入参数完毕
#define FSMSTEP_LASER_WAIT_TRIGGER									403//激光触发
#define FSMSTEP_LASER_EMITING										404//激光发射中
#define FSMSTEP_READY_ERROR											405//脚踏踩下错误
//选项状态
#define FSMSTEP_OPTION												500//选项菜单
#define FSMSTEP_INFORMATION											600
#define FSMSTEP_SCHEME_0											700//方案菜单第一页
#define FSMSTEP_SCHEME_1											710//方案菜单第二页

#define FSMSTEP_DIAGNOSIS  											800//诊断菜单
#define FSMSTEP_RENAME												900
#define FSMSTEP_CORRECTION											1000//功率校正
/*****************************************************************************/
#define FLASH_DATA_VERSION  										0XAABB0000
#define FLASH_DATA_ADDR     										0X00000000
/*****************************************************************************/
#define MSG_NO_ERROR												0
#define MSG_INTERLOCK_UNPLUG										1
#define	MSG_FOOTSWITCH_UNPLUG										2
#define	MSG_ESTOP_PRESS												3
#define	MSG_FIBER_UNPLUG											4
#define	MSG_OUT_ENERGY												5
#define	MSG_DIODE_HTEMP												6
#define	MSG_DIODE_LTEMP												7
#define	MSG_DIODE0_OVERCURRENT										8
#define	MSG_DIODE1_OVERCURRENT										9
#define	MSG_NTC_ERROR												10
#define	MSG_ENVI_HTEMP												11
#define	MSG_FOOT_DEPRESSED											12
#define	MSG_LASER_EMIT												13
#define	MSG_WAIT_TRIGGER											14
#define	MSG_FIBER_MISSMATE											15
/*****************************************************************************/
#include "sPlc.h"
#include "appConfig.h"
#include "appSplcAdr.h"
#include "dcHmiRes.h"
#include "backgroundApp.h"
#include "hmiLib.h"
#include "dcHmiNotifyProgress.h"
#include "dcHmiNotifyButton.h"
/*****************************************************************************/
void dcHmiLoop(void);//HMI轮训程序
void dcHmiLoopInit(void);
void updateStandbyDisplay(void);
void standbyTouchEnable(int8_t enable);
void updatePowerDisplay(int16_t ch, int16_t mode);
void updatePosWidthDisplay(int16_t mode);
void updateNegWidthDisplay(int16_t mode);
void updateTimesDisplay(void);
void updateGroupOffDisplay(void);
void updateOptionDisplay(void);
/*****************************************************************************/
void updateScheme_0_Display(void);
void updateScheme_1_Display(void);
void unselectScheme_0_All(void);
void unselectScheme_1_All(void);
void seletcSchemeNum(int16_t sel);
void unselectSchemeNum(int16_t sel);
/*****************************************************************************/
void updateReleaseTimeEnergy(void);
void updateSchemeInfo(int16_t cn);
void updateWarnMsgDisplay(uint8_t id);
void returnStandbyDisplay(void);
void standbyKeyValue(uint8_t value);//设置Standby键值
void standbyKeyEnable(uint8_t ena);
/*****************************************************************************/
void updateEnergyDensity(void);
void updateExtralDisplay(int16_t mode);//更新额外显示
void standbyDebugInfoVisiable(int8_t enable);
void optionKeyEnable(uint8_t enable);
#endif