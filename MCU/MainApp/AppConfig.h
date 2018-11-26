#ifndef __APPCONFIG_H__
#define __APPCONFIG_H__
/*****************************************************************************/

/*****************************************************************************/

/*****************************************************************************/
#define CONFIG_SIMULATION					1//仿真模式 C8051F020
#if CONFIG_SIMULATION == 1
#define CONFIG_SYSCLK                       (12000000L)
#else
#define CONFIG_SYSCLK                       (48000000L)
#endif
#define CONFIG_DEBUG                        1//调试功能
#define CONFIG_USING_WDT					0//使能看门狗
#define CONFIG_USING_RESET					0//使能PLC复位MCU功能
#define CONFIG_USING_HW_DELAY				1//启用硬件计时器延时
#define CONFIG_LOCAL_ADDRESS                0x01
#define CONFIG_LASERTIMER_OVERFLOW_US		1000L//定时器周期 1mS
#define CONFIG_VERSION  					0x0001
#define CONFIG_CHECK_CODE 					0x5A00

/*****************************************************************************/
#define CONFIG_UART0_BAUDRATE				115200//串口波特率
#define CONFIG_UART0_PARITY					NONE
#define CONFIG_UART0_STOPBIT				1
#define CONFIG_UART0_DATABIT				8

#define CONFIG_UART1_BAUDRATE				115200//串口波特率
#define CONFIG_UART1_PARITY					NONE
#define CONFIG_UART1_STOPBIT				1
#define CONFIG_UART1_DATABIT				8

/*****************************************************************************/
               
/*****************************************************************************/
#define CONFIG_USE_IPID						1//使能IPID温度控制
/*****************************************************************************/
#define CONFIG_USE_HWVER_SHOW				1//使能固件版本显示
#define CONFIG_USE_MPD1_SHOW				1//使能MPD1测量显示
#define CONFIG_USE_MPD2_SHOW				1//使能MPD2测量显示
#define CONFIG_USE_FBS1						1//使能FBS1检测
#define CONFIG_USE_FBS2						1//使能FBS2检测
#define CONFIG_USE_LASER_TEMP				1//使能激光器温度显示
#define CONFIG_USE_RADIATOR_TEMP			1//使能散热器温度显示
#define CONFIG_USE_ENVI_TEMP				1//使能环境温度显示
#define CONFIG_USE_IPID_UPDATE				1//使能IPID参数更新功能
#define CONFIG_USE_IPID_OUTSHOW				1//使能IPID输出显示
/*****************************************************************************/
//STIMER设置
#define CONFIG_SOFTPLC_HWTIME				(uint16_t)(65536 - (CONFIG_SYSCLK / 1000 / 12 / 10))//SoftPLC 硬件计时器基准1ms
#define CONFIG_INPUT_FILTER_TIME			3//输入数字滤波周期
#define CONFIG_STIMER_1MS_START				0//1ms计时器开始编号
#define CONFIG_STIMER_1MS_END				15//1ms计时器结束编号
#define CONFIG_STIMER_10MS_START			16//10ms计时器开始编号
#define CONFIG_STIMER_10MS_END				31//10ms计时器结束编号
#define CONFIG_STIMER_100MS_START			32//100mS计时器开始编号
#define CONFIG_STIMER_100MS_END				47//100mS计时器结束编号
#define CONFIG_STIMER_1000MS_START			48//1S计时器开始编号
#define CONFIG_STIMER_1000MS_END			63//1S计时器结束编号
#define CONFIG_STIMER_NUM					64//延时计时器

#define CONFIG_IPID_RUN_CYCLE				40//IPID运行周期 默认 40 * 100mS
#define CONFIG_IPID_PWM_CYCLE				20//IPID输出周期 默认 20 * 100mS
/*****************************************************************************/
#define ID_ONLY_1_CHANNEL					4321
#define ID_ONLY_2_CHANNEL					8765
#define ID_BOTH_CHANNEL						9431
#define ID_LASER_MODE_CW					7631
#define ID_LASER_MODE_SP					8934
#define ID_LASER_MODE_MP					2453
#define ID_LASER_MODE_GP					3876
/*****************************************************************************/
#define FBS1_IN_PORT 						3
#define FBS2_IN_PORT						2
#define COOLON_OUT_PORT						(1 * 8 + 3)
/*****************************************************************************/
//PID FUZZY 模糊PID配置
#define CONFIG_TECOUT_CYCLE					4000//PID输出转PWM周期
/*****************************************************************************/
//MODBUS SALVE配置
#define CONFIG_MODBUS_SLAVE_RX_BUFF_SIZE	128
#define CONFIG_MODBUS_SLAVE_TX_BUFF_SIZE	128
#define CONFIG_MODBUS_SLAVE_RX_TIMEOUT		10//接收通讯超时 10mS
#define CONFIG_MODBUS_SLAVE_IO_DELAY		1//RX TX切换延时
/*****************************************************************************/

#include "stdint.h"
#include "stdbool.h"
#include "endian.h"
#include "si_toolchain.h"
#include "compiler_defs.h"
#if CONFIG_SIMULATION == 1
#include "C8051F020_defs.h"
#else
#endif
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <INTRINS.H>
#include <ctype.h>
#include <LIMITS.H>
#include <math.h>
/*****************************************************************************/
#include "InitConfig.h"
#include "delay.h"
#include "hal_iic.h"
#include "hal_iic_port.h"
#include "eprom.h"
/*****************************************************************************/
//#include "sTimer.h"
//#include "pidFuzzy.h"
/*****************************************************************************/
//#include "AppMath.h"
//#include "chipAdc.h"
//#include "ad5621.h"
//#include "chipBeem.h"

//#include "modbusApp.h"
//#include "modbusPort.h"
//#include "slaveModbus.h"
/*****************************************************************************/
#endif
