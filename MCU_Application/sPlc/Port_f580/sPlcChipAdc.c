#include "sPlcChipAdc.h"
/*****************************************************************************/
static xdata adcTempDat_t volatile adcTempDat[CONFIG_SPLC_ADC_CHANNLE];
static uint8_t volatile idata adcSelect;//ADC通道选择
static void refreshAdcData(adcTempDat_t *s , uint16_t dat);
static void initAdcData(adcTempDat_t *s);
/*****************************************************************************/
static void initAdcData(adcTempDat_t *s){//初始化ADC滤波器
	idata uint8_t i;
	for(i = 0;i < CONFIG_SPLC_ADC_FILTER_TAP; i++){
		s->dat[i] = 0x0;
	}
	s->out = 0;
	s->wIndex = 0;
}
void initChipAdc(void){//ADC模块初始化
	idata uint8_t i;
	uint8_t SFRPAGE_save = SFRPAGE;
	SFRPAGE = ACTIVE_PAGE;
	//设置ADC GAIN=1
	ADC0CF |= 0x01;// Set GAINEN = 1
	ADC0H   = 0x04;// Load the ADC0GNH address
	ADC0L   = 0xFC;
	ADC0H   = 0x07;// Load the ADC0GNL address
	ADC0L   = 0x00;
	ADC0H   = 0x08;// Load the ADC0GNA address
	ADC0L   = 0x01;// Set the GAINADD bit
	ADC0CF &= ~0x01;// Set GAINEN = 0
	ADC0CF = 0x0;//
	ADC0CN = 0x0;//AD0BUSY触发
	REF0CN = 0x33;//打开基准源输出2.25V
	ADC0MX = 0x0;
	ADC0CF = ((SYSCLK / 3000000) - 1) << 3; // Set SAR clock to 3MHz
	EIE1 &=  ~(1 << 2);//关闭EADC0中断
	AD0EN = 1;// Enable ADC0
	SFRPAGE = SFRPAGE_save;
	adcSelect = 0;
	for(i = 0;i <= CONFIG_SPLC_ADC_CHANNLE;i ++){
		initAdcData(&adcTempDat[i]);
	}
}
void chipAdcProcess(void){//循环采集ADC
	idata uint16_t result = 0;
	while(!AD0INT);
	result = (ADC0 & 0x0FFF);
	refreshAdcData(&adcTempDat[adcSelect], result);
	NVRAM0[EM_ADC_0 + adcSelect] = adcTempDat[adcSelect].out;
	if(adcSelect < (CONFIG_SPLC_ADC_CHANNLE - 1)){
		adcSelect ++;
	}
	else{
		adcSelect = 0;
	}
	AD0INT = 0;
	AD0BUSY = 1;//AD0BUSY写入1
}
void refreshAdcData(adcTempDat_t *s , uint16_t dat){//更新ADC采集值 
	idata uint8_t i;
	idata uint16_t temp;
	idata uint32_t sum;
	s->dat[s->wIndex] = dat;
	s->wIndex ++;
	if(s->wIndex >= CONFIG_SPLC_ADC_FILTER_TAP){
		s->wIndex = 0;
	}
	//计算总和
	sum = 0;
	for(i = 0;i < CONFIG_SPLC_ADC_FILTER_TAP;i ++){
		sum += s->dat[i];
	}
	//去掉一个最大值和一个最小值
	temp = (uint16_t)(sum / (uint32_t)CONFIG_SPLC_ADC_FILTER_TAP);
	s->out = temp;
}