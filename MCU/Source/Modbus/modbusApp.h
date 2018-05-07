#ifndef __MODBUSAPP_H__
#define __MODBUSAPP_H__
#include "AppConfig.h"
/*****************************************************************************/

//code char *R_LASER_POSWIDTH				= "R03002";//激光正脉宽设定
//code char *R_LASER_NEGWIDTH 			= "R03003";//激光负脉宽设定
//code char *R_LASER_GROUP_SPACE			= "R03004";//群脉冲间隔
//code char *R_LASER_GROUP_NUM 			= "R03005";//群脉冲个数
//code char *R_LASER_MODE					= "R03006";//发射模式
//code char *R_LASER_SELECT				= "R03007";//通道选择
//code char *R_SETCUR_CH1		 			= "R03198";//激光通道1电流设定
//code char *R_SETCUR_CH2 				= "R03199";//激光通道2电流设定
//code char *W_VERSION					= "R03200";//板卡固件版本
//code char *W_IPID_OUT					= "R03201";//IPID输出值	
//code char *W_LASER_T					= "R03202";//激光器温度	NTC0
//code char *W_RADIATOR_T	 				= "R03203";//散热器温度	NTC1
//code char *W_ENVI_T						= "R03204";//板卡温度	TMCU
//code char *W_PHOTODIODE_CH1				= "R03205";//PD1测量值	mV
//code char *W_PHOTODIODE_CH2				= "R03206";//PD2测量值  mV
////定义D寄存器地址
//code char *R_IPID_KP					= "D00002";//IPID 参数KP 比例增益
//code char *R_IPID_TI					= "D00003";//IPID 参数TI积分时间
//code char *R_IPID_TD					= "D00004";//IPID 参数TD微分时间
//code char *R_IPID_TS					= "D00005";//IPID 参数TS采样周期
//code char *R_IPID_REFT					= "D00005";//IPID 参数目标温度
//code char *R_FAN_V						= "D00006";//风扇转速设定 0-4095
//code char *R_AIM_VOLTAGE				= "D00007";//指示激光亮度
//code char *R_BEEM_VOLUME				= "D00008";//蜂鸣器音量
////定义M寄存器地址
//code char *W_FLAG_MCUHEART				= "M0001";//反馈到PLC心跳
//code char *R_MCU_RESET					= "M0003";//PLC复位MCU
//code char *R_BEEM_ENABLE				= "M0004";//蜂鸣器使能
//code char *W_FIBER_SENSOR_CH1			= "M0005";//激光器通道0光纤报警
//code char *W_FIBER_SENSOR_CH2			= "M0006";//激光器通道1光纤报警
//code char *W_COOL_ENABLE				= "M0029";//制冷输出MCU
//code char *R_FLAG_LASER_START 			= "M0034";//激光开始发射标志
//code char *W_FLAG_LASER_INDICATE		= "M0035";//激光发射完毕标志
//code char *R_LASER_READY				= "M0050";//准备状态

//typedef enum
//{//离散输入
//	
//}MODBUS_DISCRETE_INPUT;

//typedef enum
//{//保持寄存器
//	D_LASER_POWER = 40000,//激光功率
//	D_LASER_FREQ  = 40001,//激光频率
//	D_LASER_ALARM = 40002,//报警状态
//}MODBUS_HOLD_REGISTER;

//typdef enum
//{
//	
//}MODBUS_INPUT_REGISTER;

//typedef enum
//{
//	M_LASER_AP = 0,//激光放大器开关
//	M_LASER_MO = 1,//激光主振荡器
//	M_LASER_AIM = 2,//指示激光
//	M_LASER_ESTOP = 3,//紧急停止
//	M_LASER_PRR	= 4//调制引脚
//}MOSBUS_COIL;
#endif


