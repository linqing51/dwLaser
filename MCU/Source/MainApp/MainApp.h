#ifndef __MAINAPP_H__
#define __MAINAPP_H__
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


typedef struct
{//全局设备结构体
	int16_t	laserCurrent[2];//设置激光器电流
	int16_t photoDiode[2];//PD电压
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
	int16_t pidOut;//IPID输出值
	int8_t  FlagStart;//发射触发
	int8_t	FlagReady;//准备标志
	int8_t	FiberSensor[2];//光纤检测
	int8_t	FlagIndicate;//激光发射标志
	int8_t	BeemEnabled;//蜂鸣器使能
	int8_t	AimEnable;//指示激光使能
	int8_t	CoolEnable;//制冷输出使能
}laser_t;

#endif



