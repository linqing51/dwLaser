#ifndef __CHIPADC_H__
#define __CHIPADC_H__
/*****************************************************************************/
#include "AppConfig.h"
/*****************************************************************************/
#define ADC_TEMP_SENSOR_GAIN     		3330L// Temp Sensor Gain in (uV / degC)
#define ADC_TEMP_SENSOR_OFFSET    		856L// Temp Sensor Offset in mV
#define ADC_INTERNAL_VREF             	2200L// ADC Voltage Reference (mV)
#define ADC_AMBIENT                		25L// Ambient temp in deg C

#define ADC_CHANNEL_NTC1				0x0//P1.0 激光器
#define ADC_CHANNEL_NTC2				0x1//P0.7 散热器
#define ADC_CHANNEL_ENVI				0x30//	  板载温度
#define ADC_CHANNEL_VDD					0x31//
#define ADC_CHANNEL_MPD1				0x14//P1.2
#define ADC_CHANNEL_MPD2				0x15//P1.1
/*****************************************************************************/
void chipAdcInit(void);//初始化板载ADC
void chipDacInit(void);//初始化板载DAC
int16_t getChipAdcCode(uint8_t mux);
int16_t code2EnviTemp(int16_t dat);
int16_t code2NtcTemp(int16_t dat);
#endif
