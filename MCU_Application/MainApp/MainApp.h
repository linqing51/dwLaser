#ifndef __MAINAPP_H__
#define __MAINAPP_H__
//IO点用uint8_t 表示 最低位表示当前状态 最高位表示7次前状态 其它位依次
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
//typedef struct
//{//软计时器结构体
//	uint16_t tMate;//计时器匹配值
//	uint16_t tOverflow;//计时器溢出值
//	uint16_t tCounter;//计时器计数值

//	uint16_t pMate;//脉冲个数匹配值
//	uint16_t sMate;//脉冲个数溢出值
//	uint16_t pCounter;//脉冲个数计数值
//	uint16_t sCounter;//脉冲间隔计数值
//}laserTimer_t;


//#define DM_LASER_CURRENT_0			0//激光器电流0
//#define DM_LASER_CURRENT_1			1//激光器电流1
//#define DM_PHOTODIODE_0				2//激光器反馈0
//#define DM_PHOTODIODE_1				3//激光器反馈1
//#define DM_LASER_MODE				4//激光发射模式
//#define DM_LASER_POSWIDTH			5//激光脉冲正脉宽
//#define DM_LASER_NEGWIDTH			6//激光脉冲正脉宽
//#define DM_LASER_GROUP_NUM			7//激光群脉冲个数
//#define DM_LASER_GROUP_SPACE		8//激光群脉冲间隔
//#define DM_LASER_SELECT_CHANNEL		9//激光通道选择


//#define DM_LASER_HTEMP//激光器高温保护
//#define DM_LASER_LTEMP//激光器低温保护
//#define DM_DRIVER_HTEMP//驱动器高温保护
//#define DM_DRIVER_LTEMP//驱动器低温保护
//#define DM_CHIP_HTEMP//芯片高温保护
//#define DM_CHIP_LTEMP//芯片低温保护
//#define DM_ENVI_HTEMP//环境温度高温保护
//#define DM_EMVI_LTEMP//环境温度低温保护

//#define EM_FAN_SET_SPEED_0//风扇0转速设置
//#define EM_FAN_SET_SPEED_1//风扇1转速设置
//#define EM_FAN_SET_SPEED_2//风扇2转速设置
//#define EM_FAN_GET_SPEED_0//风扇0转速读取
//#define EM_FAN_GET_SPEED_1//风扇1转速读取
//#define EM_FAN_GET_SPEED_2//风扇2转速读取
//#define EM_EDAC0//扩展DAC0输出值
//#define EM_EDAC1//扩展DAC1输出值
//#define EM_EDAC2//扩展DAC2输出值
//#define EM_EDAC3//扩展DAC3输出值
//#define EM_CDAC0//板载DAC0输出值
//#define EM_CDAC1//板载DAC1输出值
//#define EM_CADC0//板载ADC0输入值
//#define EM_CADC1//板载ADC1输入值
//#define EM_CADC2//板载ADC2输入值
//#define EM_CADC3//板载ADC3输入值
//#define EM_CTEMP//板载温度值
//#define XR_0
//#define XR_1
//#define XR_2
//#define XR_3
//#define XR_4
//#define XR_5
//#define XR_6
//#define XR_7
//#define YR_0
//#define YR_1

//typedef struct
//{//全局设备结构体
//	//
//	laserTimer_t laserTimer;//激光计时器

//	//安全状态
//	uint8_t safeFault;//安全故障
//	uint8_t safeFaultIgnore;//安全故障忽略
//	uint8_t safeInterlock;//安全连锁
//	uint8_t safeInterlockIgnore;//安全连锁忽略
//	uint8_t safeFiberDetect0;//光纤检测通道0
//	uint8_t safeFiberDetect0Ignore;//光纤检测通道0忽略
//	uint8_t safeFiberDetect1;//光纤检测通道1
//	uint8_t safeFiberDetect1Ignore;//光纤检测通道1忽略
//	uint8_t safeOpenCase;//开箱检测
//	uint8_t safeOpenCaseIgnore;//开箱检测忽略
//	//
//	uint8_t footSwitch;//脚踏开关常开
//	
//	//模糊PID参数
//	fp32_t pidOut;//IPID输出值
//	int16_t onTimerPid;//pid输出 开启时间  
//	int16_t offTimerPid;//pid输出 关闭时间
//	
//	//int8_t  FlagStart;//发射触发
//	//int8_t	FlagReady;//准备标志
//	//int8_t	FiberSensor[2];//光纤检测
//	//int8_t	FlagIndicate;//激光发射标志
//	//int8_t	BeemEnabled;//蜂鸣器使能
//	//int8_t	AimEnable;//指示激光使能
//	//int8_t	CoolEnable;//制冷输出使能
//	
//	//int8_t laserTrigger;//激光发射触发
//	//int8_t laserEmiting;//激光发射中标志
//	//int8_t laserEmitOver;//激光发射完毕	
//	//int16_t checkCode;//HMI连接校验码 高8位校验码 低8位版本
//	//int8_t heartFlag;//心跳标志
//	//int8_t mcuReset;//单片机复位
//	//int8_t clearError;
//	//int16_t stepNum;//激光发射步骤号码
//	//	int8_t readyFlag;//待机准备状态
//	//	int8_t beemOn;//蜂鸣器
//	
//	
//}my_t;

#endif



