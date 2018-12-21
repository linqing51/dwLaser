#ifndef __APPCONFIG_H__
#define __APPCONFIG_H__
/*****************************************************************************/

/*****************************************************************************/

/*****************************************************************************/
#define CONFIG_SIMULATION					1//仿真模式 C8051F020
#define CONFIG_SYSCLK                       (16000000L)
#define CONFIG_DEBUG                        1//调试功能
#define CONFIG_USING_WDT					0//使能看门狗
#define CONFIG_USING_RESET					0//使能PLC复位MCU功能
#define CONFIG_LADDER_SECTORS_START			64//指令起始地址
#define CONFIG_LADDER_SECTORS_END			128//指令结束地址
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
#define CONFIG_I2C0_FREQ 					(10000L)               
#define CONFIG_I2C1_FREQ 					(100000L)
#define CONFIG_I2C2_FREQ 					(100000L)
#define CONFIG_I2C3_FREQ 					(100000L)
#define CONFIG_I2C4_FREQ 					(100000L)
/*****************************************************************************/
#define CONFIG_EPROM_SIZE 					CONFIG_AT24C64_SIZE
#define	CONFIG_AT24C02_SIZE 				256
#define	CONFIG_AT24C04_SIZE  				512
#define	CONFIG_AT24C08_SIZE 				1024
#define	CONFIG_AT24C16_SIZE 				2048
#define	CONFIG_AT24C32_SIZE 				4096
#define	CONFIG_AT24C64_SIZE					8192
#define	CONFIG_AT24C128_SIZE 				16384
#define	CONFIG_AT24C256_SIZE 				32768
#define CONFIG_EPROM_ADDRESS				0x50
#define CONFIG_EPROM_FRAM					0//铁电存储体无写入等待
#define CONFIG_EPROM_FREQ					1//
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
#define CONFIG_SPLC_HW_INPUT_NUM			16//硬件输入点数
#define CONFIG_SPLC_HW_OUTPUT_NUM			16//硬件输出点数
#define CONFIG_SOFTPLC_HWTIME				(uint16_t)(65536 - (CONFIG_SYSCLK / 1000 / 12 / 10))//SoftPLC 硬件计时器基准1ms
#define CONFIG_INPUT_FILTER_TIME			3//输入数字滤波扫描周期
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
#define CONFIG_MODBUS_SLAVE_ADDRESS			0x01//从设备地址
#define CONFIG_MODBUS_SLAVE_BUFFER_SIZE		(256 + 32)//发送接收缓冲区
#define CONFIG_MODBUS_SLAVE_TIMEOUT			250//接收通讯超时 10mS
#define CONFIG_MODBUS_SLAVE_IO_DELAY		1//RX TX切换延时
/*****************************************************************************/
#define DISABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 0;
#define ENABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 1;
//#define DISABLE_MODBUS_SERIAL_RX_INTERRUPT	RI0 = 0;
//#define ENABLE_MODBUS_SERIAL_RX_INTERRUPT	RI0 = 1;
#define DISABLE_INTERRUPT					EA = 0;
#define ENABLE_INTERRUPT					EA = 1;


#include "stdint.h"
#include "stdbool.h"
#include "endian.h"
#include "si_toolchain.h"
#include "compiler_defs.h"
#ifdef C8051F020
#include "C8051F020_defs.h"
#endif
#ifdef C8051F340
#include "C8051F340_defs.h"
#endif
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <INTRINS.H>
#include <ctype.h>
#include <LIMITS.H>
#include <math.h>
#include "crc32.h"
/*****************************************************************************/
#include "InitDevice.h"
#include "delay.h"
#include "i2c0.h"
//#include "i2c1.h"
//#include "i2c2.h"
//#include "i2c3.h"
//#include "i2c4.h"
//#include "i2c5.h"
//#include "i2c6.h"
#include "eprom.h"
//#include "mcp47x6.h"
//#include "inPca9554.h"
//#include "outPca9554.h"
/*****************************************************************************/
#include "Modbus.h"
#include "ModbusPort.h"
/*****************************************************************************/
#include "sPLC.h"
//#include "pidFuzzy.h"
/*****************************************************************************/
//#include "AppMath.h"
//#include "chipAdc.h"
//#include "ad5621.h"
//#include "chipBeem.h"

/*****************************************************************************/
#endif
