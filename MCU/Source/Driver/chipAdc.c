#include "chipAdc.h"
/*****************************************************************************/
void chipAdcInit(void)
{//����ADC��ʼ��
	//ADC0MX = 0;// Set ADC input to initial setting
	//ADC0CF = ((CONFIG_SYSCLK / CONFIG_ADC_CLOCK) - 1) << 3;// Set SAR clock to 3MHz
	//AD0CM0 = 0;//�������
	//AD0CM1 = 0;
	//AD0INT = 1;//ʹ���жϱ�־
	//AD0EN = 1;// Enable ADC0
}

int16_t getChipAdcCode(uint8_t mux)
{//��ȡADC�ɼ�ֵ
	uint16_t temp;
//	ADC0MX = mux;
//	AD0INT = 0;
//	AD0BUSY = 1;//AD0BUSYд��1
//	while(!AD0INT);//�ȴ�AD0BUSY����
	temp = ADC0 ;
	return temp;
}

int16_t code2EnviTemp(int16_t dat)
{//ADC CODEת��Ϊ�����¶�
	uint16_t temp;
	temp = (int16_t)(ADC_INTERNAL_VREF * dat / 4096);//��λmV
	temp = (int16_t)((temp - ADC_TEMP_SENSOR_OFFSET) * 1000 / ADC_TEMP_SENSOR_GAIN);
	return temp;
}
int16_t code2NtcTemp(int16_t dat)
{//ADC CODEת��ΪNTC�����¶��¶�
	uint16_t temp;
	fp32_t ftemp;
	if(dat >= ADC_INTERNAL_VREF) dat = ADC_INTERNAL_VREF;//�����������ֵ
	if(dat < 0) dat = 0;
	
	temp = (int16_t)(ADC_INTERNAL_VREF * dat / 4096);//��λmV
	temp = 10000 * 5000 / (5000 - temp);//��Դ5V ��ѹ����10K
	
	ftemp = ((1.0 / 3477)*log((fp32_t)(temp) / 10000)) + (1 / (25+273.0));//limo R25=10740,B=3450	 uniquemode 3988
	ftemp = ( 1.0 / ftemp ) - 273.0;
	if(ftemp >= 100) ftemp = 100;
	if(ftemp <= -100) ftemp = -100;
	return (int16_t)(ftemp * 10);
}
