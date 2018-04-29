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
}softTimer_t;

typedef struct
{//全局设备结构体
	int16_t	LaserCurrent[2];//设置激光器电流
	int16_t PhotoDiode[2];//PD电压
	int16_t LaserMode;//发射模式
	int16_t PosWidth;//正脉宽
	int16_t NegWidth;//负脉宽
	int16_t GroupNum;//群脉冲个数
	int16_t GroupSpace;//群脉冲间隔
	int16_t SelectChannel;//通道选择
	int16_t AimVoltage;//指示激光电压
	int16_t FanVoltage;//风扇电压
	int16_t LaserTemp;//激光器温度
	int16_t RadiatorTemp;//散热器温度
	int16_t EnviTemp;//芯片温度
	int16_t BeemVolume;//蜂鸣器音量
	
	int16_t IPID_Kp;//IPID参数比例增益
	int16_t IPID_Ti;//IPID参数积分时间
	int16_t IPID_Td;//IPID参数微分时间
	int16_t IPID_Ts;//IPID参数采样周期
	int16_t IPIDOutAdd;//IPID输出值增量
	int16_t IPIDOut;//IPID输出值
	int8_t  FlagStart;//发射触发
	int8_t	FlagReady;//准备标志
	int8_t	FiberSensor[2];//光纤检测
	int8_t	FlagIndicate;//激光发射标志
	int8_t	BeemEnabled;//蜂鸣器使能
	int8_t	AimEnable;//指示激光使能
	int8_t	CoolEnable;//制冷输出使能
	softTimer_t softTimer;
}myDevice_t;

#endif



