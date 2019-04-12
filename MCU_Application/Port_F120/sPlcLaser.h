#ifndef __SPLCLASER_H__
#define __SPLCLASER_H__
/*****************************************************************************/
#include "sPlc.h"
/*****************************************************************************/
#define MCP47X6_LASER_CHANNEL_CH1					0
#define MCP47X6_LASER_CHANNEL_CH2					1
#define LASER_MODE_CW								0//连续模式
#define LASER_MODE_SP								1//单脉冲模式
#define LASER_MODE_MP								2//多脉冲模式
#define LASER_MODE_GP								3//群脉冲模式

////R 线圈定义
//#define R_MCU_RESET									(R_START * 16 + 0)//MCU复位请求
//#define R_MCU_ERROR_CLEAR							(R_START * 16 + 1)//MCU错误清除
//#define R_LASER_START								(R_START * 16 + 2)//激光发射按键
//#define R_LASER_STOP								(R_START * 16 + 3)//激光停止按键
//#define R_LASER_READY								(R_START * 16 + 4)//准备按键
//#define R_LASER_SELECT_CH1							(R_START * 16 + 5)//激光选择CH1按键
//#define R_LASER_SELECT_CH2							(R_START * 16 + 6)//激光选择CH2按键
//#define R_LASER_SELECT_BOTH							(R_START * 16 + 7)//激光旋转CH1+CH2按键
//#define R_INFO_RESET								(R_START * 16 + 8)//激光发射信息复位按键
//#define R_PARA_SAVE									(R_START * 16 + 9)//参数储存按键
//#define R_LASER_MODE_CW								(R_START * 16 + 10)//激光模式连续按键
//#define R_LASER_MODE_PULSE							(R_START * 16 + 11)//激光模式脉冲连续按键
//#define R_LASER_MODE_GP								(R_START * 16 + 12)//激光模式可编程脉冲按键
//#define R_LASER_ERROR_CLEAR							(R_START * 16 + 13)//激光错误清除
//#define R_FLAG_COOLING								(R_START * 16 + 13)//冷却指示
//#define R_FLAG_LASER_EMITING						(R_START * 16 + 14)//激光发射指示
//#define R_FLAG_LASER_EMITOVER						(R_START * 16 + 15)//激光发射完毕
//#define R_FLAG_LASER_TIGGER							(R_START * 16 + 16)//激光发射触发
//#define R_FLAG_READY								(R_START * 16 + 17)//准备状态
//#define R_FLAG_STANDBY								(R_START * 16 + 18)//待机状态
//#define	R_FLAG_FIBER_MECH_DETECT					(R_START * 16 + 19)//光纤机械传感器
//#define R_FLAG_FIBER_MECH_DETECT_IGNORE 			(R_START * 16 + 20)//光纤机械传感器忽略
//#define R_FLAG_FIBER_NFC_DETECT						(R_START * 16 + 20)//光纤NFC传感器
//#define R_FLAG_FIBER_NFC_DETECT_IGNORE				(R_START * 16 + 21)//光纤NFC传感器忽略
//#define R_FLAG_OPENCASE_DETECT						(R_START * 16 + 21)//开箱检测
//#define R_FLAG_FOOTSWITCH							(R_START * 16 + 22)//脚踏状态
//#define R_FLAG_WIRE_FOOTSWITCH						(R_START * 16 + 23)//有线脚踏状态
//#define R_FLAG_WIRELESS_FOOTSWITCH					(R_START * 16 + 24)//无线脚踏状态
//#define R_FLAG_MCU_HEART							(R_START * 16 + 25)//MCU心跳
//#define R_FLAG_BEEM									(R_START * 16 + 26)//蜂鸣器状态
//#define R_FLAG_SAFE_FAULT							(R_START * 16 + 27)//安全故障
//#define R_FLAG_TEMP_FAULT							(R_START * 16 + 28)//温度故障
//#define R_FLAG_DRIVER_LTEMP_FAULT					(R_START * 16 + 29)
//#define R_FLAG_DRIVER_HTEMP_FAULT					(R_START * 16 + 30)
//#define R_FLAG_DRIVER_TEMP_FAULT_IGNORE				(R_START * 16 + 30)
//#define R_FLAG_MCHIP_LTEMP_FAULT					(R_START * 16 + 31)
//#define R_FLAG_MCHIP_HTEMP_FAULT					(R_START * 16 + 32)
//#define R_FLAG_MCHIP_TEMP_FAULT_IGNORE				(R_START * 16 + 30)
//#define R_FLAG_LASER_LTEMP_FAULT					(R_START * 16 + 33)
//#define R_FLAG_LASER_HTEMP_FAULT					(R_START * 16 + 34)
//#define R_FLAG_LASER_TEMP_FAULT_IGNORE				(R_START * 16 + 30)
////MR 线圈定义
//#define MR_FIBER_MECH_DETECT_IGNORE					(MR_START + 0)//光纤探测机械忽略
//#define MR_FIBER_NFC_DETCET_IGNORE					(MR_START + 1)//光纤探测NFC忽略
//#define MR_OPENCASE_DETECT_IGNORE					(MR_START + 2)//开箱检测忽略
//#define MR_AIM_ENABLE								(MR_START + 3)//指示激光使能							
//#define MR_BEEM_ENABLE								(MR_START + 4)//蜂鸣器使能
////EM 寄存器定义
//#define EM_MCU_CHECKCODE							(EM_START + 0)//MCU校验码
//#define EM_MCU_HW_VER								(EM_START + 1)//MCU硬件版本
//#define EM_MCU_FW_VER								(EM_START + 2)//MCU软件版本
//#define EM_STEP_NUM									(EM_START + 3)//激光发射步骤号码

//#define EM_LASER_NAME								(EM_START + 10)//方案名称 16字
//#define EM_LASER_POSWIDTH							(EM_START + 16)//激光正脉宽
//#define EM_LASER_NEGWIDTH							(EM_START + 17)//激光负脉宽
//#define EM_LASER_GROUP_SPACE						(EM_START + 18)//分组间隔//激光群脉冲间隔
//#define EM_LASER_GROUP_NUM							(EM_START + 19)//分组脉冲数//激光群脉冲个数
//#define EM_LASER_POWER_CH1							(EM_START + 20)//激光通道1功率设置
//#define EM_LASER_POWER_CH2							(EM_START + 21)//激光通道2功率设置

//#define EM_LASER_POWER_TOTAL						(EM_START + 22)//激光总功率显示
//#define EM_LASER_POWER_RATIO						(EM_START + 23)//激光功率比例显示
//#define EM_LASER_RELEASE_ENERY						(EM_START + 18)//激光发射能量显示
//#define EM_LASER_RELEASE_TIME						(EM_START + 19)//激光发射时间显示
//#define EM_LASER_CURRENT_CH1						(EM_START + 15)//激光器电流0
//#define EM_LASER_CURRENT_CH2						(EM_START + 16)//激光器电流1
//#define EM_LASER_PD_CH1								(EM_START + 17)//激光器反馈0
//#define EM_LASER_PD_CH2								(EM_START + 18)//激光器反馈1
//#define EM_LASER_MODE								(EM_START + 19)//激光发射模式
//#define EM_LASER_SELECT_CHANNLE						(EM_START + 20)//激光通道选择


//#define EM_LASER_TEMPERATURE						(EM_START + 21)//激光器温度
//#define EM_LASER_TMATE								(EM_START + 22)//计时器匹配值
//#define EM_LASER_PMATE								(EM_START + 23)//脉冲个数匹配值
//#define EM_LASER_SMATE								(EM_START + 24)//脉冲个数溢出值
//#define EM_LASER_TOVERFLOW							(EM_START + 25)//计时器溢出值
//#define EM_LASER_TCOUNTER							(EM_START + 26)//计时器计数值
//#define EM_LASER_PCOUNTER							(EM_START + 27)//脉冲个数计数值
//#define EM_LASER_SCOUNTER							(EM_START + 28)//脉冲间隔计数值
//#define EM_FAN_GET_SPEED_0							(EM_START + 29)//风扇0转速读取
//#define EM_FAN_GET_SPEED_1							(EM_START + 30)//风扇1转速读取
//#define EM_FAN_GET_SPEED_2							(EM_START + 31)//风扇2转速读取
//#define EM_DRIVER_TEMPERATURE						(EM_START + 32)//驱动器温度
//#define EM_MCHIP_TEMPERATURE						(EM_START + 33)//板卡温度
////DM 寄存器定义
//#define DM_SCHEME_NAME								(DM_START + 0)
//#define DM_
//#define DM_PID_REF_TEMP								(DM_START + 0)//冷却温度设定
//#define DM_PID_ON_TIME								(DM_START + 1)//PID输出开通时间
//#define DM_PID_OFF_TIME								(DM_START + 2)//PID输出关闭时间
//#define DM_PID_COEF_KP								(DM_START + 3)//PID系数比例KP
//#define DM_PID_COEF_TI								(DM_START + 4)//PID系数积分时间TI
//#define DM_PID_COEF_TD								(DM_START + 5)//PID系数微分时间TD
//#define DM_FAN_SET_SPEED_0							(DM_START + 6)//风扇0转速设置
//#define DM_FAN_SET_SPEED_1							(DM_START + 7)//风扇1转速设置
//#define DM_FAN_SET_SPEED_2							(DM_START + 8)//风扇2转速设置
//#define DM_SET_AIM_BRIGHT							(DM_START + 9)//指示激光亮度
//#define DM_SET_BEEM_VOLUME							(DM_START + 10)//蜂鸣器音量
//#define DM_SET_LCD_BRIGHT							(DM_START + 11)//液晶屏亮度
//#define DM_LASER_PROTECT_HTEMP						(DM_START + 12)//激光器高温保护
//#define DM_LASER_PROTCET_LTEMP						(DM_START + 13)//激光器低温保护
//#define DM_DRIVE_PROTECT_HTEMP						(DM_START + 14)//驱动器高温保护
//#define DM_DRIVE_PROTECT_LTEMP						(DM_START + 15)//驱动器低温保护
//#define DM_MCHIP_PROTECT_HTEMP						(DM_START + 16)//芯片高温保护
//#define DM_MCHIP_PROTECT_LTEMP						(DM_START + 17)//芯片低温保护
///*****************************************************************************/
//#define X_FOOTSWITCH								(X_START * 16 + 0)
//#define X_OPENCASE_DETECT							(X_START * 16 + 1)
//#define X_INTERLOCK									(X_START * 16 + 2)
//#define X_MECH_FIBER_DETECT							(X_START * 16 + 2)
void sPlcLaser(void);//
#endif