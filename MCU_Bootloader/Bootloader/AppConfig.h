#ifndef __APPCONFIG_H__
#define __APPCONFIG_H__
/*****************************************************************************/

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
#define DISABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 0;
#define ENABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 1;
#define DISABLE_MODBUS_SERIAL_RX_INTERRUPT	RI0 = 0;
#define ENABLE_MODBUS_SERIAL_RX_INTERRUPT	RI0 = 1;
#define DISABLE_INTERRUPT					EA = 0;
#define ENABLE_INTERRUPT					EA = 1;

/*****************************************************************************/
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
#include "crc32.h"
/*****************************************************************************/
//#include "InitConfig.h"
#include "delay.h"
#include "Fxxx_EEPROM_Configuration.h"
#include "Fxxx_EEPROM_Interface.h"
/*****************************************************************************/
#endif
