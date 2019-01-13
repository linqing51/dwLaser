#ifndef __APPCONFIG_H__
#define __APPCONFIG_H__
/*****************************************************************************/
#define CONFIG_SYSCLK                       (22118400L)
#ifdef C8051F020
#define SAR_CLK      						2000000L//ADC0ʱ�� <2.5MHz
#endif
#define CONFIG_DEBUG                        0//���Թ���
#define CONFIG_USING_WDT					0//ʹ�ܿ��Ź�
#define CONFIG_USING_RESET					0//ʹ��PLC��λMCU����
#define CONFIG_VERSION  					0x0001
#define CONFIG_CHECK_CODE 					0x5A00
#define CONFIG_USING_SIMULATION				1
/*****************************************************************************/
#define CONFIG_UART0_BAUDRATE				115200//���ڲ�����
#define CONFIG_UART0_PARITY					NONE
#define CONFIG_UART0_STOPBIT				1
#define CONFIG_UART0_DATABIT				8

#define CONFIG_UART1_BAUDRATE				9600//���ڲ�����
#define CONFIG_UART1_PARITY					NONE
#define CONFIG_UART1_STOPBIT				1
#define CONFIG_UART1_DATABIT				8
/*****************************************************************************/
#define CONFIG_I2C0_FREQ 					1               
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
#define CONFIG_EPROM_FRAM					0//����洢����д��ȴ�
#define CONFIG_EPROM_PAGEWRITE				0//ҳд��
/*****************************************************************************/
//SPLC����
#define CONFIG_SPLC_ASSERT					0//����ַ��Χ
#define CONFIG_SOFTPLC_HWTIME				1000L//1mS
#define CONFIG_INPUT_FILTER_TIME			3//���������˲�ɨ������ 1mS * N
/*****************************************************************************/
#define CONFIG_SPLC_USING_WDT				0//���Ź�����
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_INPUT			1//����IOˢ������
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_OUTPUT			1//���IOˢ������
/*****************************************************************************/
#define CONFIG_SPLC_USING_EPROM				1//EPROM����洢����
/*****************************************************************************/
#define CONFIG_SPLC_USING_ADC				1//ʹ��ADCģ��
#define CONFIG_SPLC_ADC_FILTER_TAP			14//ADCλ���˲�����
#define CONFIG_SPLC_ADC_CHANNLE				64//ADCͨ����
#define CONFIG_SPLC_ADC_TEMP_SENSOR_GAIN    3330L// Temp Sensor Gain in (uV / degC)
#define CONFIG_SPLC_ADC_TEMP_SENSOR_OFFSET  856L// Temp Sensor Offset in mV
#define CONFIG_SPLC_ADC_INTERNAL_VREF     	2200L// ADC Voltage Reference (mV)
#define CONFIG_SPLC_ADC_AMBIENT             25L// Ambient temp in deg C
/*****************************************************************************/
#define CONFIG_SPLC_USING_DAC				1//����DACģ��
/*****************************************************************************/
#define CONFIG_SPLC_USING_MB_RTU_SLAVE		1//����MODBUS RTU��վ
#define CONFIG_MB_RTU_SLAVE_TIMER			1000L//1000uS
#define CONFIG_MB_RTU_SLAVE_ADDRESS			0x01//���豸��ַ
#define CONFIG_MB_RTU_SLAVE_BUFFER_SIZE		256//���ͽ��ջ�����
#define CONFIG_MB_RTU_SLAVE_TIMEOUT			100//����ͨѶ��ʱ 10mS
#define CONFIG_MB_RTU_SLAVE_IO_DELAY		1//RX TX�л���ʱ
/*****************************************************************************/
/*****************************************************************************/
#define DISABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 0;
#define ENABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 1;
#define DISABLE_INTERRUPT					EA = 0;
#define ENABLE_INTERRUPT					EA = 1;
/*****************************************************************************/
#define BOX_CMD_STX							0x81
#define BOX_CMD_ETX							0x84
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
#include "boxCmd.h"
/*****************************************************************************/
#include "Modbus.h"
#include "ModbusPort.h"
/*****************************************************************************/
#include "sPLC.h"
/*****************************************************************************/
#endif
