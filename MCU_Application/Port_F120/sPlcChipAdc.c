#include "sPlcChipAdc.h"
#if CONFIG_SPLC_USING_ADC == 1
/*****************************************************************************/
static xdata adcTempDat_t volatile adcTempDat[CONFIG_SPLC_ADC_CHANNLE];
static uint8_t volatile idata adcSelect;//ADC通道选择
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
	ADC0CN = 0x0;//软件触发
	ADC0CN |= (1 << 6);//AD0TM = 1 启用跟踪
	ADC0CN |= (1 << 7);//AD0EN = 1 
	ADC0CF = 0x0;
	ADC0CF |= (CONFIG_SYSCLK / CONFIG_SARCLK) << 3;// ADC conversion clock = 2.5MHz
	AMX0CF = 0x00;// AIN inputs are single-ended (default)
	AMX0SL = 0x00;// Select AIN0.1 pin as ADC mux input
	AD0INT = 1;
	AD0BUSY = 1;//AD0BUSY写入1

	adcSelect = 0;
	for(i = 0;i <= CONFIG_SPLC_ADC_CHANNLE;i ++){
		initAdcData(&adcTempDat[i]);
	}
}
void chipAdcProcess(void){//循环采集ADC
	idata uint16_t result = 0;
	//while(!AD0INT);
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
		case 0:{//MLD0
			//ADC MUX
			AMX0SL = 0x00;
			break;
		}
		case 1:{//MLD1
			//ADC MUX
			AMX0SL = 0x00;
			break;
		}
		case 2:{//MLD2
			//ADC MUX
			AMX0SL = 0x00;
			break;
		}
		case 3:{//MLD3
			//ADC MUX
			AMX0SL = 0x00;
			break;
		}
		case 4:{//MLD4
			//ADC MUX
			AMX0SL = 0x01;
			break;
		}
		case 5:{//MLD5
			//ADC MUX
			AMX0SL = 0x01;
			break;
		}
		case 6:{//MLD6
			//ADC MUX
			AMX0SL = 0x01;
			break;
		}
		case 7:{//MLD7
			//ADC MUX
			AMX0SL = 0x01;
			break;
		}
		case 8:{//MLD8
			//ADC MUX
			AMX0SL = 0x02;
			break;
		}
		default:{
			break;
		}
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

#endif
