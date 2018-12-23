#include "chipAdc.h"
/*****************************************************************************/
int16_t code2EnviTemp(int16_t dat)
{//ADC CODE转换为环境温度
	uint16_t temp;
	temp = (int16_t)(ADC_INTERNAL_VREF * dat / 4096);//单位mV
	temp = (int16_t)((temp - ADC_TEMP_SENSOR_OFFSET) * 1000 / ADC_TEMP_SENSOR_GAIN);
	return temp;
}
int16_t code2NtcTemp(int16_t dat)
{//ADC CODE转换为NTC测量温度温度
	uint16_t temp;
	fp32_t ftemp;
	if(dat >= ADC_INTERNAL_VREF) dat = ADC_INTERNAL_VREF;//限制输入最大值
	if(dat < 0) dat = 0;
	
	temp = (int16_t)(ADC_INTERNAL_VREF * dat / 4096);//单位mV
	temp = 10000 * 5000 / (5000 - temp);//电源5V 分压电阻10K
	
	ftemp = ((1.0 / 3477)*log((fp32_t)(temp) / 10000)) + (1 / (25+273.0));//limo R25=10740,B=3450	 uniquemode 3988
	ftemp = ( 1.0 / ftemp ) - 273.0;
	if(ftemp >= 100) ftemp = 100;
	if(ftemp <= -100) ftemp = -100;
	return (int16_t)(ftemp * 10);
}
