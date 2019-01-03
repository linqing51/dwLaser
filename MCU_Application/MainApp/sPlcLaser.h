#ifndef __SPLCLASER_H__
#define __SPLCLASER_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
#define R_KEY_MCU_RESET								0//MCU复位请求
#define R_KEY_MCU_ERROR_CLEAR						1//MCU错误清除
#define R_KEY_LASER_START							2//激光发射按键
#define R_KEY_LASER_STOP							3//激光停止按键
#define R_KEY_LASER_READY							4//准备按键
#define R_KEY_LASER_SELECT_CH1						5//激光选择CH1按键
#define R_KEY_LASER_SELECT_CH2						6//激光选择CH2按键
#define R_KEY_LASER_SELECT_BOTH						7//激光旋转CH1+CH2按键
#define R_KEY_INFO_RESET							8//激光发射信息复位按键
#define R_KEY_PARA_SAVE								9//参数储存按键
#define R_LASER_MODE_CW								10//激光模式连续按键
#define R_LASER_MODE_PULSE							11//激光模式脉冲连续按键
#define R_LASER_MODE_GP								12//激光模式可编程脉冲按键
#define R_FLAG_COOLING								13//冷却指示
#define R_FLAG_LASER_EMITING						14//激光发射指示
#define R_FLAG_LASER_EMIT_OVER						15//激光发射完毕
#define R_FLAG_LASER_TIGGER							16//激光发射触发
#define R_FLAG_READY								17//准备状态
#define R_FLAG_STANDBY								18//待机状态
#define	R_FLAG_FIBER_MECH_DETECT					19//光纤机械传感器
#define R_FLAG_FIBER_NFC_DETECT						20//光纤NFC传感器
#define R_FLAG_OPENCASE_DETECT						21//开箱检测
#define R_FLAG_WIRE_FOOTSWITCH						22//有线脚踏状态
#define R_FLAG_WIRELESS_FOOTSWITCH					23//无线脚踏状态
#define R_FLAG_MCU_HEART							24//MCU心跳
#define R_FLAG_BEEM									25//蜂鸣器状态

#define MR_FIBER_MECH_DETECT_IGNORE					0//光纤探测机械忽略
#define MR_FIBER_NFC_DETCET_IGNORE					1//光纤探测NFC忽略
#define MR_OPENCASE_DETECT_IGNORE					2//开箱检测忽略
#define MR_AIM_ENABLE								3//指示激光使能							
#define MR_BEEM_ENABLE								4//蜂鸣器使能

#define EM_MCU_CHECKSUM//MCU校验码
#define EM_MCU_HW_VER//MCU硬件版本
#define EM_MCU_FW_VER//MCU软件版本
#define EM_STEP_NUM//激光发射步骤号码
#define EM_TEXTBOX_LASER_POSWIDTH//激光正脉宽
#define EM_TEXTBOX_LASER_NEGWIDTH//激光负脉宽
#define EM_TEXTBOX_LASER_GROUP_SPACE//分组间隔//激光群脉冲间隔
#define EM_TEXTBOX_LASER_GROUP_NUM//分组脉冲数//激光群脉冲个数
#define EM_TEXTBOX_LASER_POWER_CH1//激光通道1功率设置
#define EM_TEXTBOX_LASER_POWER_CH2//激光通道2功率设置
#define EM_TEXTBOX_LASER_TOTAL_POWER//激光总功率显示
#define EM_TEXTBOX_LASER_RATIO_POWER//激光功率比例显示
#define EM_TEXTBOX_LASER_RELEASE_ENERY//激光发射能量显示
#define EM_TEXTBOX_LASER_RELEASE_TIME//激光发射时间显示
#define EM_LASER_CURRENT_CH1			//激光器电流0
#define EM_LASER_CURRENT_CH2			1//激光器电流1
#define EM_LASER_PD_CH1				2//激光器反馈0
#define EM_LASER_PD_CH2				3//激光器反馈1
#define EM_LASER_MODE				4//激光发射模式
#define EM_LASER_SELECT_CHANNLE//激光通道选择
#define EM_LASER_TEMPERATURE//激光器温度
#define EM_DRIVER_TEMPERATURE//驱动器温度
#define EM_MCHIP_TEMPERATURE//板卡温度
#define EM_FAN_GET_SPEED_0//风扇0转速读取
#define EM_FAN_GET_SPEED_1//风扇1转速读取
#define EM_FAN_GET_SPEED_2//风扇2转速读取

#define DM_PID_REF_TEMP//冷却温度设定
#define DM_PID_ON_TIME//PID输出开通时间
#define DM_PID_OFF_TIME//PID输出关闭时间
#define DM_PID_COEF_KP//PID系数比例KP
#define DM_PID_COEF_TI//PID系数积分时间TI
#define DM_PID_COEF_TD//PID系数微分时间TD
#define DM_FAN_SET_SPEED_0//风扇0转速设置
#define DM_FAN_SET_SPEED_1//风扇1转速设置
#define DM_FAN_SET_SPEED_2//风扇2转速设置
#define DM_SET_AIM_BRIGHT//指示激光亮度
#define DM_SET_BEEM_VOLUME//蜂鸣器音量
#define DM_SET_LCD_BRIGHT//液晶屏亮度
#define DM_LASER_PROTECT_HTEMP//激光器高温保护
#define DM_LASER_PROTCET_LTEMP//激光器低温保护
#define DM_DRIVE_PROTECT_HTEMP_//驱动器高温保护
#define DM_DRIVE_PROTECT_LTEMP//驱动器低温保护
#define DM_MCHIP_PROTECT_HTEMP//芯片高温保护
#define DM_MCHIP_PROTECT_LTEMP//芯片低温保护

#endif