#ifndef __MAINAPP_H__
#define __MAINAPP_H__
//IO点用uint8_t 表示 最低位表示当前状态 最高位表示7次前状态 其它位依次
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
typedef struct
{//软计时器结构体
	uint16_t tMate;//计时器匹配值
	uint16_t tOverflow;//计时器溢出值
	uint16_t tCounter;//计时器计数值

	uint16_t pMate;//脉冲个数匹配值
	uint16_t sMate;//脉冲个数溢出值
	uint16_t pCounter;//脉冲个数计数值
	uint16_t sCounter;//脉冲间隔计数值
}laserTimer_t;

int16_t DM[1024];//PLC DM寄存器
int16_t MR[16];//PLC MR寄存器
int16_t LR[16];//PLC LR寄存器
#define DM_LASER_CURRENT_0			0
#define DM_LASER_CURRENT_1			1
#deifne DM_PHOTODIODE_0				2
#define DM_PHOTODIODE_1				3
#define DM_LASER_MODE				
#define DM_LASER_POSWIDTH
#define DM_LASER_NEGWIDTH
typedef struct
{//全局设备结构体
	//
	laserTimer_t laserTimer;//激光计时器
	int16_t laserMode;//发射模式
	int16_t posWidth;//正脉宽
	int16_t negWidth;//负脉宽
	int16_t groupNum;//群脉冲个数
	int16_t groupSpace;//群脉冲间隔
	int16_t selectChannel;//通道选择
	int16_t pwmAnalogOut[4];//PWM模拟输出
	int16_t ntcTemperature[4];//NTC温度
	int16_t fanSpeedLevel;//风扇转速等级
	//过热状态
	uint8_t overTempFault;//过热
	uint8_t overTempIgnore;//忽略过热
	uint8_t overTempDiode;//激光二极管过热
	uint8_t overTempDiodeIgnore;//激光二极管过热忽略
	uint8_t overTempAmplifier;//放大器过热
	uint8_t overTempAmplifierIgnore;//放大器过热忽略
	uint8_t overTempEnvironment;//环境温度过热
	uint8_t overTempEnvironmentIgnore;//环境温度过热忽略
	uint8_t overTempMcu;//处理器温度过热
	uint8_t overTempMcuIgnore;//处理器温度过热
	//安全状态
	uint8_t safeFault;//安全故障
	uint8_t safeFaultIgnore;//安全故障忽略
	uint8_t safeInterlock;//安全连锁
	uint8_t safeInterlockIgnore;//安全连锁忽略
	uint8_t safeFiberDetect0;//光纤检测通道0
	uint8_t safeFiberDetect0Ignore;//光纤检测通道0忽略
	uint8_t safeFiberDetect1;//光纤检测通道1
	uint8_t safeFiberDetect1Ignore;//光纤检测通道1忽略
	uint8_t safeOpenCase;//开箱检测
	uint8_t safeOpenCaseIgnore;//开箱检测忽略
	//
	uint8_t footSwitch;//脚踏开关常开
	
	//模糊PID参数
	fp32_t pidOut;//IPID输出值
	int16_t onTimerPid;//pid输出 开启时间  
	int16_t offTimerPid;//pid输出 关闭时间
	
	//int8_t  FlagStart;//发射触发
	//int8_t	FlagReady;//准备标志
	//int8_t	FiberSensor[2];//光纤检测
	//int8_t	FlagIndicate;//激光发射标志
	//int8_t	BeemEnabled;//蜂鸣器使能
	//int8_t	AimEnable;//指示激光使能
	//int8_t	CoolEnable;//制冷输出使能
	
	//int8_t laserTrigger;//激光发射触发
	int8_t laserEmiting;//激光发射中标志
	int8_t laserEmitOver;//激光发射完毕	
	int16_t checkCode;//HMI连接校验码 高8位校验码 低8位版本
	int8_t heartFlag;//心跳标志
	int8_t mcuReset;//单片机复位
	int8_t clearError;
	int16_t stepNum;//激光发射步骤号码
	int8_t readyFlag;//待机准备状态
	int8_t beemOn;//蜂鸣器
	
	
}my_t;

#endif



