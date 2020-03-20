#ifndef __APPCONFIG_H__
#define __APPCONFIG_H__
/*****************************************************************************/
#define DEBUG_LED_ON						0
#define DEBUG_LED_OFF						1
#define CONFIG_SYSCLK                       (22118400L)
#ifdef C8051F020
#define SAR_CLK      						1500000L//ADC0ʱ�� <2.5MHz
#endif
#define CONFIG_DEBUG                        0//���Թ���
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
//SPLC����
#define CONFIG_SPLC_ASSERT					1//����ַ��Χ
#define CONFIG_INPUT_FILTER_TIME			3//���������˲�ɨ������ 1mS * N
/*****************************************************************************/
/*****************************************************************************/
#define CONFIG_SPLC_USING_WDT				1//���Ź�����
/*****************************************************************************/
#define CONFIG_SPLC_USING_UART1				1//UART1��������
#if CONFIG_SPLC_USING_UART1 == 1
#define SPLC_UART1							1
#endif
/*****************************************************************************/
#define CONFIG_SPLC_USING_CADC				1//ʹ��ADCģ��
#define CONFIG_SPLC_ADC_FILTER_TAP			14//ADCλ���˲�����
#define CONFIG_SPLC_ADC_CHANNLE				64//ADCͨ����
#define CONFIG_SPLC_ADC_TEMP_SENSOR_GAIN    3330L// Temp Sensor Gain in (uV / degC)
#define CONFIG_SPLC_ADC_TEMP_SENSOR_OFFSET  856L// Temp Sensor Offset in mV
#define CONFIG_SPLC_ADC_INTERNAL_VREF     	2400L// ADC Voltage Reference (mV)
#define CONFIG_SPLC_ADC_AMBIENT             25L// Ambient temp in deg C
/*****************************************************************************/
#define CONFIG_SPLC_USING_DAC				1//����DACģ��
/*****************************************************************************/
#define CONFIG_SPLC_USING_MB_RTU_SLAVE		1//����MODBUS RTU��վ
#define CONFIG_MB_RTU_SLAVE_TIMER			1000L//1000uS
#define CONFIG_MB_RTU_SLAVE_ADDRESS			0x01//���豸��ַ
#define CONFIG_MB_RTU_SLAVE_BUFFER_SIZE		256//���ͽ��ջ�����
#define CONFIG_MB_RTU_SLAVE_TIMEOUT			100//����ͨѶ��ʱ 10mS
/*****************************************************************************/
#define DISABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 0;
#define ENABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 1;
#define DISABLE_INTERRUPT					EA = 0;
#define ENABLE_INTERRUPT					EA = 1;
/*****************************************************************************/
//ָʾ����
#define R_BOX_RED_SENDED					(R_START * 16 + 126)//190
#define R_BOX_GREEN_SENDED					(R_START * 16 + 127)//191
#define BOX_CMD_STX							0x81
#define BOX_CMD_ETX							0x84
#define BOX_SEND_BFADDR						(EM_START + 100)//���ͻ�����λ��
#define BOX_SEND_LENGTH						29//����������
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
//#include "crc32.h"
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
#include "sPlcTimer.h"
#include "sPlcFun.h"
#include "sPlcLed.h"
#include "sPlcIo.h"
#include "sPlcWatchDog.h"
/*****************************************************************************/
#endif
