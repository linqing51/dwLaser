#include "sPlcChipAdc.h"
/*****************************************************************************/
static xdata adcTempDat_t volatile adcTempDat[CONFIG_SPLC_ADC_CHANNLE];
static uint8_t volatile idata adcSelect;//ADCͨ��ѡ��
static void refreshAdcData(adcTempDat_t *s , uint16_t dat);
static void initAdcData(adcTempDat_t *s);
/*****************************************************************************/
static void initAdcData(adcTempDat_t *s){//��ʼ��ADC�˲���
	idata uint8_t i;
	for(i = 0;i < CONFIG_SPLC_ADC_FILTER_TAP; i++){
		s->dat[i] = 0x0;
	}
	s->out = 0;
	s->wIndex = 0;
}
void initChipAdc(void){//ADCģ���ʼ��
	idata uint8_t i;
#ifdef C8051F020
	ADC0CN = 0x0;//�������
	ADC0CN |= (1 << 6);//AD0TM = 1 ���ø���
	ADC0CN |= (1 << 7);//AD0EN = 1 
	ADC0CF = 0x0;
	ADC0CF |= (CONFIG_SYSCLK / SAR_CLK) << 3;     // ADC conversion clock = 2.5MHz
	AMX0CF = 0x00;                      // AIN inputs are single-ended (default)
	AMX0SL = 0x00;                      // Select AIN0.1 pin as ADC mux input
	AD0INT = 1;
	AD0BUSY = 1;//AD0BUSYд��1
#endif
	adcSelect = 0;
	for(i = 0;i <= CONFIG_SPLC_ADC_CHANNLE;i ++){
		initAdcData(&adcTempDat[i]);
	}
}
void chipAdcProcess(void){//ѭ���ɼ�ADC
	idata uint16_t result = 0;
#ifdef C8051F020
	//while(!AD0INT);
#endif
	result = (ADC0 & 0x0FFF);
	refreshAdcData(&adcTempDat[adcSelect], result);
//	if(adcTempDat[adcSelect].out < 100){
//		NVRAM0[EM_ADC_0 + adcSelect] = 0;
//	}
//	else{
		NVRAM0[EM_ADC_0 + adcSelect] = adcTempDat[adcSelect].out;
//	}
	if(adcSelect < (CONFIG_SPLC_ADC_CHANNLE - 1)){
		adcSelect ++;
	}
	else{
		adcSelect = 0;
	}
	AD0INT = 0;
	AD0BUSY = 1;//AD0BUSYд��1
}
void refreshAdcData(adcTempDat_t *s , uint16_t dat){//����ADC�ɼ�ֵ 
	idata uint8_t i;
	idata uint16_t temp;
	idata uint32_t sum;
	s->dat[s->wIndex] = dat;
	s->wIndex ++;
	if(s->wIndex >= CONFIG_SPLC_ADC_FILTER_TAP){
		s->wIndex = 0;
	}
	//�����ܺ�
	sum = 0;
	for(i = 0;i < CONFIG_SPLC_ADC_FILTER_TAP;i ++){
		sum += s->dat[i];
	}
	//ȥ��һ�����ֵ��һ����Сֵ
	temp = (uint16_t)(sum / (uint32_t)CONFIG_SPLC_ADC_FILTER_TAP);
	s->out = temp;
}