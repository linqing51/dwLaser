#ifndef __APPCONFIG_H__
#define __APPCONFIG_H__
/*****************************************************************************/
#define DEBUG_LED_ON						0
#define DEBUG_LED_OFF						1
#define CONFIG_SYSCLK                       (22118400L)
#ifdef C8051F020
#define SAR_CLK      						2000000L//ADC0时钟 <2.5MHz
#endif
#define CONFIG_DEBUG                        0//调试功能
/*****************************************************************************/
#define CONFIG_UART0_BAUDRATE				115200//串口波特率
#define CONFIG_UART0_PARITY					NONE
#define CONFIG_UART0_STOPBIT				1
#define CONFIG_UART0_DATABIT				8

#define CONFIG_UART1_BAUDRATE				9600//串口波特率
#define CONFIG_UART1_PARITY					NONE
#define CONFIG_UART1_STOPBIT				1
#define CONFIG_UART1_DATABIT				8
/*****************************************************************************/
#define CONFIG_I2C0_FREQ 					1 
#define CONFIG_I2C_WAITACT_TIME				250
/*****************************************************************************/
#define CONFIG_EPROM_DEBUG					0
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
#define CONFIG_EPROM_PAGEWRITE				0//页写入
/*****************************************************************************/
//SPLC设置
#define CONFIG_SPLC_ASSERT					0//检查地址范围
#define CONFIG_SPLC_DEV						0x0A01//设备号
#define CONFIG_SPLC_CLEAR_CODE				0xA58E
#define CONFIG_SOFTPLC_HWTIME				1000L//1mS
#define CONFIG_INPUT_FILTER_TIME			3//输入数字滤波扫描周期 1mS * N
/*****************************************************************************/
#define CONFIG_SPLC_USING_CLEAR_NVRAM		1//启用清除NVRAM功能
/*****************************************************************************/
#define CONFIG_SPLC_USING_WDT				1//看门狗启用
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_INPUT			1//输入IO刷新启用
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_OUTPUT			1//输出IO刷新启用
/*****************************************************************************/
#define CONFIG_SPLC_USING_EPROM				1//EPROM掉电存储启用
/*****************************************************************************/
#define CONFIG_SPLC_USING_UART1				1//UART1串口启用
#if CONFIG_SPLC_USING_UART1 == 1
#define SPLC_UART1							1
#endif
/*****************************************************************************/
#define CONFIG_SPLC_USING_CADC				1//使能ADC模块
#define CONFIG_SPLC_ADC_FILTER_TAP			14//ADC位移滤波次数
#define CONFIG_SPLC_ADC_CHANNLE				64//ADC通道数
#define CONFIG_SPLC_ADC_TEMP_SENSOR_GAIN    3330L// Temp Sensor Gain in (uV / degC)
#define CONFIG_SPLC_ADC_TEMP_SENSOR_OFFSET  856L// Temp Sensor Offset in mV
#define CONFIG_SPLC_ADC_INTERNAL_VREF     	2200L// ADC Voltage Reference (mV)
#define CONFIG_SPLC_ADC_AMBIENT             25L// Ambient temp in deg C
/*****************************************************************************/
#define CONFIG_SPLC_USING_DAC				1//是能DAC模块
/*****************************************************************************/
#define CONFIG_SPLC_USING_MB_RTU_SLAVE		1//是能MODBUS RTU从站
#define CONFIG_MB_RTU_SLAVE_TIMER			1000L//1000uS
#define CONFIG_MB_RTU_SLAVE_ADDRESS			0x01//从设备地址
#define CONFIG_MB_RTU_SLAVE_BUFFER_SIZE		256//发送接收缓冲区
#define CONFIG_MB_RTU_SLAVE_TIMEOUT			100//接收通讯超时 10mS
#define CONFIG_MB_RTU_SLAVE_IO_DELAY		1//RX TX切换延时
/*****************************************************************************/
/*****************************************************************************/
#define DISABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 0;
#define ENABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 1;
#define DISABLE_INTERRUPT					EA = 0;
#define ENABLE_INTERRUPT					EA = 1;
/*****************************************************************************/
//指示盒子
#define R_BOX_RED_SENDED					(R_START * 16 + 126)
#define R_BOX_GREEN_SENDED					(R_START * 16 + 127)
#define BOX_CMD_STX							0x81
#define BOX_CMD_ETX							0x84
#define BOX_SEND_BFADDR						(EM_START + 100)//发送缓冲区位置
#define BOX_SEND_LENGTH						29//发送数据量
/*****************************************************************************/
#include "stdint.h"
#include "stdbool.h"
#include "endian.h"
#include "si_toolchain.h"
#include "compiler_defs.h"
#include "C8051F020_defs.h"
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
#include "InitDeviceF020.h"
#include "delay.h"
#include "i2c0.h"
#include "eprom.h"
#include "dac8568_0.h"
#include "dac8568_1.h"
#include "dac8568_2.h"
#include "dac8568_3.h"
#if CONFIG_SPLC_USING_UART1 == 1
#include "sPlcUart.h"
#endif
#if CONFIG_SPLC_USING_CADC == 1
#include "sPlcChipAdc.h"
#endif
#if CONFIG_SPLC_USING_DAC == 1
#include "sPlcDac.h"
#endif
/*****************************************************************************/
#include "Modbus.h"
#include "ModbusPort.h"
/*****************************************************************************/
#include "sPLC.h"
/*****************************************************************************/
#endif
