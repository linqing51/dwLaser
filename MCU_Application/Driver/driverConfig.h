#ifndef __DRIVERCONFIG_H__
#define __DRIVERCONFIG_H__
/*****************************************************************************/
#define CONFIG_I2C0_FREQ 					1            
#define CONFIG_I2C1_FREQ 					1
#define CONFIG_I2C2_FREQ 					1
#define CONFIG_I2C3_FREQ 					1
#define CONFIG_I2C4_FREQ 					1
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
