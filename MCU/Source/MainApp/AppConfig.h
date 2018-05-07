#ifndef __APPCONFIG_H__
#define __APPCONFIG_H__
/*****************************************************************************/
/*****************************************************************************/
#define CONFIG_USE_INTOSC_12000000			0
#define CONFIG_USE_INTOSC_24000000			0
#define CONFIG_USE_INTOSC_48000000			0
#define CONFIG_USE_EXTOSC_22184000			1
#define CONFIG_USE_EXTOSC_44236800			0
/*****************************************************************************/
#if CONFIG_USE_INTOSC_12000000 == 1
#define CONFIG_SYSCLK                       (12000000L)
#endif
#if CONFIG_USE_INTOSC_24000000 == 1
#define CONFIG_SYSCLK						(24000000L)
#endif
#if	CONFIG_USE_INTOSC_48000000 == 1
#define CONFIG_SYSCLK                       (48000000L)
#endif
#if	CONFIG_USE_EXTOSC_22184000 == 1
#define CONFIG_SYSCLK                       (22184000L)
#endif
#if	CONFIG_USE_EXTOSC_44236800 == 1
#define CONFIG_SYSCLK                       (44236800L)
#endif
/*****************************************************************************/
#define CONFIG_DEBUG                        1//调试功能
#define CONFIG_LOCAL_ADDRESS                0x01
#define CONFIG_MODBUSTASK_DELAY				2//MOSBUS查询周期
#define CONFIG_WATCHDOG_DELAY				5//WATCHDOG喂狗周期
#define CONFIG_LASERTIMER_OVERFLOW_US		1000L//定时器周期 1mS
#define CONFIG_VER_MAJOR  					0x01
#define CONFIG_VER_MINOR 					0x00
/*****************************************************************************/
#define CONFIG_UART0_BAUDRATE				115200//串口波特率
#define CONFIG_UART0_PARITY					NONE
#define CONFIG_UART0_STOPBIT				1
#define CONFIG_UART0_DATABIT				8
/*****************************************************************************/
#define CONFIG_USE_PLC_RESET				1//使能PLC复位MCU功能
#define CONFIG_USE_WDT						1//使能看门狗
#define CONFIG_RESET_WDT_TIME				5000//看门狗复位时间10mS
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
//SOFTPLC设置
#define CONFIG_SOFTPLC_HWTIME				(65536 - (uint16_t)(CONFIG_SYSCLK * 1000 /12 / 10))//SoftPLC 硬件计时器基准10ms
#define CONFIG_INPUT_FILTER_TIME			3//输入数字滤波周期
#define CONFIG_PLC_T_1MS_NUM			16//1ms计时器
#define CONFIG_PLC_T_10MS_NUM			16//10ms计时器
#define CONFIG_PLC_T_100MS_NUM			16//100mS计时器
#define CONFIG_PLC_T_1000MS_NUM			16//1S计时器
#define CONFIG_PLC_N_NUM					128//保持辅助寄存器
#define CONFIG_PLC_M_NUM					1024//非保持辅助寄存器
#define CONFIG_PLC_X_NUM					8//输入寄存器个数
#define CONFIG_PLC_Y_NUM					8//输出寄存器个数
#define CONFIG_PLC_D_NUM					32//保持寄存器
#define CONFIG_PLC_R_NUM					32//非保持
#define CONFIG_PLC_C_NUM					32//计数器
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
#define CONFIG_PID_FUZZY_EMIN				0.0
#define CONFIG_PID_FUZZY_EMID 				0.08
#define CONFIG_PID_FUZZY_EMAX				0.6
//调整值限幅，防止积分饱和
#define CONFIG_PID_FUZZY_UMAX				5
#define CONFIG_PID_FUZZY_UMIN 				-5
//输出值限幅
#define CONFIG_PID_FUZZY_PMAX 				7200
#define CONFIG_PID_FUZZY_PMIN 				0
/*****************************************************************************/
//MODBUS SALVE配置
#define CONFIG_MODBUS_SLAVE_RX_BUFF_SIZE	128
#define CONFIG_MODBUS_SLAVE_TX_BUFF_SIZE	128
/*****************************************************************************/
#include "stdint.h"
#include "stdbool.h"
#include "endian.h"
#include "si_toolchain.h"
#include "compiler_defs.h"
#include "C8051F020_defs.h"
/*****************************************************************************/
#include "stdio.h"
#include "string.h"
#include "INTRINS.H"
#include <ctype.h>
#include "LIMITS.H"
#include "math.h"
/*****************************************************************************/
#include "softPlc.h"
#include "pidFuzzy.h"
/*****************************************************************************/
#include "InitConfig.h"
//#include "AppMath.h"
//#include "chipAdc.h"
//#include "ad5621.h"
//#include "chipBeem.h"

#include "modbusApp.h"
#include "modbusPort.h"
#include "slaveModbus.h"
/*****************************************************************************/
#endif
