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
#define CONFIG_LADDER_SECTORS_START			64//ָ����ʼ��ַ
#define CONFIG_LADDER_SECTORS_END			128//ָ�������ַ
#define CONFIG_LASERTIMER_OVERFLOW_US		1000L//��ʱ������ 1mS
#define CONFIG_VERSION  					0x0001
#define CONFIG_CHECK_CODE 					0x5A00

/*****************************************************************************/
#define CONFIG_UART0_BAUDRATE				57600//���ڲ�����
#define CONFIG_UART0_PARITY					NONE
#define CONFIG_UART0_STOPBIT				1
#define CONFIG_UART0_DATABIT				8

#define CONFIG_UART1_BAUDRATE				115200//���ڲ�����
#define CONFIG_UART1_PARITY					NONE
#define CONFIG_UART1_STOPBIT				1
#define CONFIG_UART1_DATABIT				8
/*****************************************************************************/
#define CONFIG_I2C0_FREQ 					(100000L)               
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
#define CONFIG_EPROM_FRAM					0//����洢����д��ȴ�
#define CONFIG_EPROM_FREQ					1//
/*****************************************************************************/
#define CONFIG_USE_IPID						1//ʹ��IPID�¶ȿ���
/*****************************************************************************/
#define CONFIG_USE_HWVER_SHOW				1//ʹ�ܹ̼��汾��ʾ
#define CONFIG_USE_MPD1_SHOW				1//ʹ��MPD1������ʾ
#define CONFIG_USE_MPD2_SHOW				1//ʹ��MPD2������ʾ
#define CONFIG_USE_FBS1						1//ʹ��FBS1���
#define CONFIG_USE_FBS2						1//ʹ��FBS2���
#define CONFIG_USE_LASER_TEMP				1//ʹ�ܼ������¶���ʾ
#define CONFIG_USE_RADIATOR_TEMP			1//ʹ��ɢ�����¶���ʾ
#define CONFIG_USE_ENVI_TEMP				1//ʹ�ܻ����¶���ʾ
#define CONFIG_USE_IPID_UPDATE				1//ʹ��IPID�������¹���
#define CONFIG_USE_IPID_OUTSHOW				1//ʹ��IPID�����ʾ
/*****************************************************************************/
//SPLC����
#define CONFIG_SPLC_IO_INPUT_NUM			16//Ӳ���������
#define CONFIG_SPLC_IO_OUTPUT_NUM			16//Ӳ���������
#define CONFIG_SOFTPLC_HWTIME				1000L//1mS
#define CONFIG_INPUT_FILTER_TIME			3//���������˲�ɨ������ 1mS * N
#define CONFIG_IPID_RUN_CYCLE				40//IPID�������� Ĭ�� 40 * 100mS
#define CONFIG_IPID_PWM_CYCLE				20//IPID������� Ĭ�� 20 * 100mS
/*****************************************************************************/
#define CONFIG_SPLC_USING_WDT				0//���Ź�����
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_INPUT			1//����IOˢ������
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_OUTPUT			1//���IOˢ������
/*****************************************************************************/
#define CONFIG_SPLC_USING_EPROM				0//EPROM����洢����
/*****************************************************************************/
#define CONFIG_SPLC_USING_ADC				0//ʹ��ADCģ��
#define CONFIG_SPLC_ADC_FILTER_TAP			48//ADCλ���˲�����
#define CONFIG_SPLC_ADC_CHANNLE				9//ADCͨ����
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
//PID FUZZY ģ��PID����
#define CONFIG_TECOUT_CYCLE					4000//PID���תPWM����
/*****************************************************************************/
/*****************************************************************************/
#define DISABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 0;
#define ENABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 1;
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
#include <math.h>
#include "crc32.h"
/*****************************************************************************/
#ifdef C8051F020
#include "InitDeviceF020.h"
#endif
#ifdef C8051F580
#include "InitDeviceF580.h"
#endif

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
