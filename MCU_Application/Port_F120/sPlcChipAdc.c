#include "sPlcChipAdc.h"
/*****************************************************************************/
static adcTempDat_t adcTempDat[CONFIG_SPLC_ADC_CHANNLE];
static data uint8_t adcSelect;//ADC通道选择
static void initAdcData(adcTempDat_t *s);
/*****************************************************************************/
static void initAdcData(adcTempDat_t *s){//初始化ADC滤波器
    uint8_t i;
	for(i = 0;i < CONFIG_SPLC_ADC_FILTER_TAP; i++){
		s->dat[i] = 0x0;
	}
	s->out = 0;
	s->wIndex = 0;
}
void initChipAdc(void){//ADC模块初始化
#if CONFIG_SPLC_USING_ADC == 1
	uint8_t i;
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
	SFRPAGE = ADC0_PAGE;
	ADC0CN = 0x0;//软件触发
	ADC0CN |= (1 << 6);//AD0TM = 1 启用跟踪
	ADC0CN |= (1 << 7);//AD0EN = 1 
	ADC0CF = 0x0;
	ADC0CF |= ((CONFIG_SYSCLK / CONFIG_SARCLK / 2) - 1) << 3;// ADC conversion clock = 2.5MHz
	AMX0CF = 0x00;// AIN inputs are single-ended (default)
	AMX0SL = 0x00;// Select AIN0.1 pin as ADC mux input
	AD0INT = 1;
	AD0BUSY = 1;//AD0BUSY写入1
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
	adcSelect = 0;
	for(i = 0;i < CONFIG_SPLC_ADC_CHANNLE;i ++){
		initAdcData(&adcTempDat[i]);
	}
#endif
}
void chipAdcProcess(void){//循环采集ADC
	data uint16_t result = 0;
	data uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
	data uint8_t adcOverTime = 0;
	SFRPAGE = ADC0_PAGE;
	while(1){
		adcOverTime ++;
		if(AD0INT != 1 || (adcOverTime > 250))
			break;
	}
	result = (ADC0 & 0x0FFF);
	refreshAdcData(&adcTempDat[adcSelect], result);
	NVRAM0[SPREG_ADC_0 + adcSelect] = adcTempDat[adcSelect].out;
	if(adcSelect < (CONFIG_SPLC_ADC_CHANNLE - 1)){
		adcSelect ++;
	}
	else{
		adcSelect = 0;
	}
	switch(adcSelect){
		case 0:{//PD0
			AMX0SL = 0x00;//AIN0
			break;
		}
		case 1:{//PD1
			AMX0SL = 0x01;//AIN1
			break;
		}
		case 2:{//NTC0
			AMX0SL = 0x02;//AIN2
			break;
		}
		case 3:{//NTC1
			AMX0SL = 0x03;//AIN3
			break;
		}
		case 4:{//ISMON0
			AMX0SL = 0x04;//AIN4
			break;
		}
		case 5:{//IVINMON0
			AMX0SL = 0x05;//AIN5
			break;
		}
		case 6:{//ISMON1
			AMX0SL = 0x06;//AIN6
			break;
		}
		case 7:{//IVINMON1
			AMX0SL = 0x07;//AIN7
			break;
		}
		case 8:{//Chip Temperature
			AMX0SL = 0x08;
			break;
		}
		default:{
			break;
		}
	}
	AD0INT = 0;
	AD0BUSY = 1;//AD0BUSY写入1
	SFRPAGE = SFRPAGE_SAVE;
}
void refreshAdcData(adcTempDat_t *s , uint16_t dat){//更新ADC采集值 
	data uint8_t i;
	data uint16_t temp;
	data uint32_t sum;
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
