#ifndef __SPLCLASER_H__
#define __SPLCLASER_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
#define MCP47X6_LASER_CHANNEL_CH1					0
#define MCP47X6_LASER_CHANNEL_CH2					1
#define LASER_MODE_CW								0//连续模式
#define LASER_MODE_SP								1//单脉冲模式
#define LASER_MODE_MP								2//多脉冲模式
#define LASER_MODE_GP								3//群脉冲模式

//R 线圈定义
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
//MR 线圈定义
#define MR_FIBER_MECH_DETECT_IGNORE					0//光纤探测机械忽略
#define MR_FIBER_NFC_DETCET_IGNORE					1//光纤探测NFC忽略
#define MR_OPENCASE_DETECT_IGNORE					2//开箱检测忽略
#define MR_AIM_ENABLE								3//指示激光使能							
#define MR_BEEM_ENABLE								4//蜂鸣器使能
//EM 寄存器定义
#define EM_MCU_CHECKCODE							0//MCU校验码
#define EM_MCU_HW_VER								1//MCU硬件版本
#define EM_MCU_FW_VER								2//MCU软件版本
#define EM_STEP_NUM									3//激光发射步骤号码
#define EM_LASER_POSWIDTH							4//激光正脉宽
#define EM_LASER_NEGWIDTH							5//激光负脉宽
#define EM_LASER_GROUP_SPACE						6//分组间隔//激光群脉冲间隔
#define EM_LASER_GROUP_NUM							7//分组脉冲数//激光群脉冲个数
#define EM_LASER_POWER_CH1							8//激光通道1功率设置
#define EM_LASER_POWER_CH2							9//激光通道2功率设置
#define EM_LASER_POWER_TOTAL						10//激光总功率显示
#define EM_LASER_POWER_RATIO						11//激光功率比例显示
#define EM_LASER_RELEASE_ENERY						13//激光发射能量显示
#define EM_LASER_RELEASE_TIME						14//激光发射时间显示
#define EM_LASER_CURRENT_CH1						15//激光器电流0
#define EM_LASER_CURRENT_CH2						16//激光器电流1
#define EM_LASER_PD_CH1								17//激光器反馈0
#define EM_LASER_PD_CH2								18//激光器反馈1
#define EM_LASER_MODE								19//激光发射模式
#define EM_LASER_SELECT_CHANNLE						20//激光通道选择
#define EM_LASER_TEMPERATURE						21//激光器温度
#define EM_LASER_TMATE								22//计时器匹配值
#define EM_LASER_PMATE								23//脉冲个数匹配值
#define EM_LASER_SMATE								24//脉冲个数溢出值
#define EM_LASER_TOVERFLOW							25//计时器溢出值
#define EM_LASER_TCOUNTER							26//计时器计数值
#define EM_LASER_PCOUNTER							27//脉冲个数计数值
#define EM_LASER_SCOUNTER							28//脉冲间隔计数值
#define EM_FAN_GET_SPEED_0							29//风扇0转速读取
#define EM_FAN_GET_SPEED_1							30//风扇1转速读取
#define EM_FAN_GET_SPEED_2							31//风扇2转速读取
#define EM_DRIVER_TEMPERATURE						32//驱动器温度
#define EM_MCHIP_TEMPERATURE						33//板卡温度
//DM 寄存器定义
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