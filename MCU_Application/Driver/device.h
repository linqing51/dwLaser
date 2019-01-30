#ifndef __DEVICE_H__
#define __DEVICE_H__
/*****************************************************************************/
#include "lib.h"
#include "sPlc.h"
#include "i2c0.h"
#include "i2c1.h"
#include "i2c2.h"
#include "i2c3.h"
#include "i2c4.h"
#include "i2c5.h"
#include "i2c6.h"
#include "eprom.h"
#include "inPca9554.h"
#include "outPca9554.h"
#include "mcp47x6.h"
/*****************************************************************************/
#define CONFIG_I2C0_FREQ 					1            
#define CONFIG_I2C1_FREQ 					1
#define CONFIG_I2C2_FREQ 					1
#define CONFIG_I2C3_FREQ 					1
#define CONFIG_I2C4_FREQ 					1
#define CONFIG_I2C5_FREQ 					1
#define CONFIG_I2C6_FREQ 					1
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

#endif
