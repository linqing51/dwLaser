#include "sPlcChipAdc.h"
/*****************************************************************************/
//ADC MUX3253 CH0-CH3
sbit ADCMUX_0_3_S0 = P1^4;
sbit ADCMUX_0_3_S1 = P1^7;
sbit ADCMUX_0_3_OE1 = P1^6;
sbit ADCMUX_0_3_OE2 = P1^5;
//ADC MUX3253 CH4-CH7
sbit ADCMUX_4_7_S0 = P1^2;
sbit ADCMUX_4_7_S1 = P1^1;
sbit ADCMUC_4_7_OE1 = P1^0;
sbit ADCMUC_4_7_OE2 = P1^3;
//ADC MUX3253 CH8-CH11
sbit ADCMUX_8_11_S0 = P2^4;
sbit ADCMUX_8_11_S1 = P2^6;
sbit ADCMUX_8_11_OE1 = P2^7;
sbit ADCMUX_8_11_OE2 = P2^5;
//ADC MUX3253 CH12-CH15
sbit ADCMUX_12_15_S0 = P2^0;
sbit ADCMUX_12_15_S1 = P2^2;
sbit ADCMUX_12_15_OE1 = P2^3;
sbit ADCMUX_12_15_OE2 = P2^1;
//ADC MUX3253 CH16-CH19
sbit ADCMUX_16_19_S0 = P3^5;
sbit ADCMUX_16_19_S1 = P3^7;
sbit ADCMUX_16_19_OE1 = P3^6;
sbit ADCMUX_16_19_OE2 = P3^4;
//ADC MUX3253 CH20-CH23
sbit ADCMUX_20_23_S0 = P3^1;
sbit ADCMUX_20_23_S1 = P3^3;
sbit ADCMUX_20_23_OE1 = P3^2;
sbit ADCMUX_20_23_OE2 = P3^0;
//ADC MUX3253 CH24-CH27
sbit ADCMUX_24_27_S0 = P0^5;
sbit ADCMUX_24_27_S1 = P0^7;
sbit ADCMUX_24_27_OE1 = P0^6;
sbit ADCMUX_24_27_OE2 = P0^4;
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
	//CHIP0
	ADCMUX_0_3_OE1 = true;
	ADCMUX_0_3_OE2 = true;
	//CHIP1
	ADCMUC_4_7_OE1 = true;
	ADCMUC_4_7_OE2 = true;
	//CHIP2
	ADCMUX_8_11_OE1 = true;
	ADCMUX_8_11_OE2 = true;
	//CHIP3
	ADCMUX_12_15_OE1 = true;
	ADCMUX_12_15_OE2 = true;
	//CHIP4
	ADCMUX_16_19_OE1 = true;
	ADCMUX_16_19_OE2 = true;
	//CHIP5
	ADCMUX_20_23_OE1 = true;
	ADCMUX_20_23_OE2 = true;
	//CHIP6
	ADCMUX_24_27_OE1 = true;
	ADCMUX_24_27_OE2 = true;
#ifdef C8051F020
	ADC0CN = 0x0;//软件触发
	ADC0CN |= (1 << 6);//AD0TM = 1 启用跟踪
	ADC0CN |= (1 << 7);//AD0EN = 1 
	ADC0CF = 0x0;
	ADC0CF |= (CONFIG_SYSCLK / SAR_CLK) << 3;     // ADC conversion clock = 2.5MHz
	AMX0CF = 0x00;                      // AIN inputs are single-ended (default)
	AMX0SL = 0x00;                      // Select AIN0.1 pin as ADC mux input
	AD0INT = 1;
	AD0BUSY = 1;//AD0BUSY写入1
#endif
	adcSelect = 0;
	for(i = 0;i <= CONFIG_SPLC_ADC_CHANNLE;i ++){
		initAdcData(&adcTempDat[i]);
	}
}
void chipAdcProcess(void){//循环采集ADC
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
	switch(adcSelect){
		case 0:{//MLD0
			//ADC MUX
			AMX0SL = 0x00;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			ADCMUX_0_3_S1 = false;
			ADCMUX_0_3_S0 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_0_3_OE1 = false;
			ADCMUX_0_3_OE2 = true;
			break;
		}
		case 1:{//MLD1
			//ADC MUX
			AMX0SL = 0x00;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			ADCMUX_0_3_S1 = true;
			ADCMUX_0_3_S0 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_0_3_OE1 = false;
			ADCMUX_0_3_OE2 = true;
			break;
		}
		case 2:{//MLD2
			//ADC MUX
			AMX0SL = 0x00;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			ADCMUX_0_3_S1 = false;
			ADCMUX_0_3_S0 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = false;
			break;
		}
		case 3:{//MLD3
			//ADC MUX
			AMX0SL = 0x00;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			ADCMUX_0_3_S1 = true;
			ADCMUX_0_3_S0 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = false;
			break;
		}
		case 4:{//MLD4
			//ADC MUX
			AMX0SL = 0x01;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			ADCMUX_4_7_S1 = false;
			ADCMUX_4_7_S0 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUC_4_7_OE1 = false;
			ADCMUC_4_7_OE2 = true;
			break;
		}
		case 5:{//MLD5
			//ADC MUX
			AMX0SL = 0x01;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			ADCMUX_0_3_S1 = true;
			ADCMUX_0_3_S0 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUC_4_7_OE1 = false;
			ADCMUC_4_7_OE2 = true;
			break;
		}
		case 6:{//MLD6
			//ADC MUX
			AMX0SL = 0x01;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			ADCMUX_4_7_S1 = true;
			ADCMUX_4_7_S0 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = false;
			break;
		}
		case 7:{//MLD7
			//ADC MUX
			AMX0SL = 0x01;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			ADCMUX_4_7_S1 = true;
			ADCMUX_4_7_S0 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = false;
			break;
		}
		case 8:{//MLD8
			//ADC MUX
			AMX0SL = 0x02;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			ADCMUX_8_11_S1 = false;
			ADCMUX_8_11_S0 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_8_11_OE1 = false;
			ADCMUX_8_11_OE2 = true;
			break;
		}
		case 9:{//MLD9
			//ADC MUX
			AMX0SL = 0x02;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			ADCMUX_8_11_S1 = true;
			ADCMUX_8_11_S0 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_8_11_OE1 = false;
			ADCMUX_8_11_OE2 = true;
			break;
		}
		case 10:{//MLD10
			//ADC MUX
			AMX0SL = 0x02;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			ADCMUX_8_11_S1 = false;
			ADCMUX_8_11_S0 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = false;
			break;
		}
		case 11:{//MLD11
			//ADC MUX
			AMX0SL = 0x02;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			ADCMUX_8_11_S1 = true;
			ADCMUX_8_11_S0 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = false;
			break;
		}
		case 12:{//MLD12
			//ADC MUX
			AMX0SL = 0x03;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			ADCMUX_12_15_S1 = false;
			ADCMUX_12_15_S0 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_12_15_OE1 = false;
			ADCMUX_12_15_OE2 = true;
			break;
		}
		case 13:{//MLD13
			//ADC MUX
			AMX0SL = 0x03;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			ADCMUX_12_15_S1 = true;
			ADCMUX_12_15_S0 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_12_15_OE1 = false;
			ADCMUX_12_15_OE2 = true;
			break;
		}
		case 14:{//MLD14
			//ADC MUX
			AMX0SL = 0x03;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			ADCMUX_12_15_S1 = false;
			ADCMUX_12_15_S0 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = false;
			break;
		}
		case 15:{//MLD15
			//ADC MUX
			AMX0SL = 0x03;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			ADCMUX_12_15_S1 = true;
			ADCMUX_12_15_S0 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = false;
			break;
		}
		case 16:{//MLD16
			//ADC MUX
			AMX0SL = 0x04;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			ADCMUX_16_19_S1 = false;
			ADCMUX_16_19_S0 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_16_19_OE1 = false;
			ADCMUX_16_19_OE2 = true;
			break;
		}
		case 17:{//MLD17
			//ADC MUX
			AMX0SL = 0x04;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			ADCMUX_16_19_S1 = true;
			ADCMUX_16_19_S0 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_16_19_OE1 = false;
			ADCMUX_16_19_OE2 = true;
			break;
		}
		case 18:{//MLD18
			//ADC MUX
			AMX0SL = 0x04;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			ADCMUX_16_19_S1 = false;
			ADCMUX_16_19_S0 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = false;
			break;
		}
		case 19:{//MLD19
			//ADC MUX
			AMX0SL = 0x04;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			ADCMUX_16_19_S1 = true;
			ADCMUX_16_19_S0 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = false;
			break;
		}
		case 20:{//MLD20
			//ADC MUX
			AMX0SL = 0x05;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			ADCMUX_20_23_S1 = false;
			ADCMUX_20_23_S0 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_20_23_OE1 = false;
			ADCMUX_20_23_OE2 = true;
			break;
		}
		case 21:{//MLD21
			//ADC MUX
			AMX0SL = 0x05;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = false;
			ADCMUX_20_23_OE2 = true;
			ADCMUX_20_23_S1 = true;
			ADCMUX_20_23_S0 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			ADCMUX_24_27_S1 = false;
			ADCMUX_24_27_S0 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_24_27_OE1 = false;
			ADCMUX_24_27_OE2 = true;
			break;
		}
		case 22:{//MLD22
			//ADC MUX
			AMX0SL = 0x05;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			ADCMUX_20_23_S1 = false;
			ADCMUX_20_23_S0 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;	
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = false;
			break;
		}
		case 23:{//MLD23
			//ADC MUX
			AMX0SL = 0x05;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			ADCMUX_20_23_S1 = true;
			ADCMUX_20_23_S0 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_20_23_OE1 = 1;
			ADCMUX_20_23_OE2 = 0;
			break;
		}
		case 24:{//MLD24
			//ADC MUX
			AMX0SL = 0x06;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			ADCMUX_24_27_S1 = false;
			ADCMUX_24_27_S0 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_24_27_OE1 = false;
			ADCMUX_24_27_OE2 = true;
			break;
		}
		case 25:{//MLD25
			//ADC MUX
			AMX0SL = 0x06;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			ADCMUX_24_27_S1 = true;
			ADCMUX_24_27_S0 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_24_27_OE1 = false;
			ADCMUX_24_27_OE2 = true;
			break;
		}
		case 26:{//MLD26
			//ADC MUX
			AMX0SL = 0x06;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			ADCMUX_24_27_S1 = false;
			ADCMUX_24_27_S0 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = false;
			break;
		}
		case 27:{//MLD27
			//ADC MUX
			AMX0SL = 0x06;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			ADCMUX_24_27_S1 = true;
			ADCMUX_24_27_S0 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = false;
			break;
		}
		case 32:{//MPD0
			//ADC MUX
			AMX0SL = 0x00;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			ADCMUX_0_3_S1 = false;
			ADCMUX_0_3_S0 = false;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_0_3_OE1 = false;
			ADCMUX_0_3_OE2 = true;
			break;
		}
		case 33:{//MPD1
			//ADC MUX
			AMX0SL = 0x00;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			ADCMUX_0_3_S1 = true;
			ADCMUX_0_3_S0 = false;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_0_3_OE1 = false;
			ADCMUX_0_3_OE2 = true;
			break;
		}
		case 34:{//MPD2
			//ADC MUX
			AMX0SL = 0x00;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			ADCMUX_0_3_S1 = false;
			ADCMUX_0_3_S0 = false;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = false;
			break;
		}
		case 35:{//MPD3
			//ADC MUX
			AMX0SL = 0x00;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			ADCMUX_0_3_S1 = true;
			ADCMUX_0_3_S0 = false;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = false;
			break;
		}
		case 36:{//MPD4
			//ADC MUX
			AMX0SL = 0x01;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			ADCMUX_4_7_S1 = false;
			ADCMUX_4_7_S0 = false;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUC_4_7_OE1 = false;
			ADCMUC_4_7_OE2 = true;
			break;
		}
		case 37:{//MPD5
			//ADC MUX
			AMX0SL = 0x01;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			ADCMUX_4_7_S1 = true;
			ADCMUX_4_7_S0 = false;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUC_4_7_OE1 = false;
			ADCMUC_4_7_OE2 = true;
			break;
		}
		case 38:{//MPD6
			//ADC MUX
			AMX0SL = 0x01;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			ADCMUX_4_7_S1 = false;
			ADCMUX_4_7_S0 = false;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = false;
			break;
		}
		case 39:{//MPD7
			//ADC MUX
			AMX0SL = 0x01;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			ADCMUX_4_7_S1 = true;
			ADCMUX_4_7_S0 = false;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = false;
			break;
		}
		case 40:{//MPD8
			//ADC MUX
			AMX0SL = 0x02;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			ADCMUX_8_11_S1 = false;
			ADCMUX_8_11_S0 = false;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_8_11_OE1 = false;
			ADCMUX_8_11_OE2 = true;
			break;
		}
		case 41:{//MPD9
			//ADC MUX
			AMX0SL = 0x02;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			ADCMUX_8_11_S1 = true;
			ADCMUX_8_11_S0 = false;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_8_11_OE1 = false;
			ADCMUX_8_11_OE2 = true;
			break;
		}
		case 42:{//MPD10
			//ADC MUX
			AMX0SL = 0x02;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			ADCMUX_8_11_S1 = false;
			ADCMUX_8_11_S0 = false;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_8_11_OE1 = false;
			ADCMUX_8_11_OE2 = true;
			break;
		}
		case 43:{//MPD11
			//ADC MUX
			AMX0SL = 0x02;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			ADCMUX_8_11_S1 = true;
			ADCMUX_8_11_S0 = false;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = false;
			break;
		}
		case 44:{//MPD12
			//ADC MUX
			AMX0SL = 0x03;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			ADCMUX_12_15_S1 = false;
			ADCMUX_12_15_S0 = false;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_12_15_OE1 = false;
			ADCMUX_12_15_OE2 = true;
			break;
		}
		case 45:{//MPD13
			//ADC MUX
			AMX0SL = 0x03;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			ADCMUX_12_15_S1 = true;
			ADCMUX_12_15_S0 = false;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_12_15_OE1 = false;
			ADCMUX_12_15_OE2 = true;
			break;
		}
		case 46:{//MPD14
			//ADC MUX
			AMX0SL = 0x03;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			ADCMUX_12_15_S1 = false;
			ADCMUX_12_15_S0 = false;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = false;
			break;
		}
		case 47:{//MPD15
			//ADC MUX
			AMX0SL = 0x03;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			ADCMUX_12_15_S1 = true;
			ADCMUX_12_15_S0 = false;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = false;
			break;
		}
		case 48:{//MPD16
			//ADC MUX
			AMX0SL = 0x04;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			ADCMUX_16_19_S1 = false;
			ADCMUX_16_19_S0 = false;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_16_19_OE1 = false;
			ADCMUX_16_19_OE2 = true;
			break;
		}
		case 49:{//MPD17
			//ADC MUX
			AMX0SL = 0x04;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			ADCMUX_16_19_S1 = true;
			ADCMUX_16_19_S0 = false;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_16_19_OE1 = false;
			ADCMUX_16_19_OE2 = true;
			break;
		}
		case 50:{//MPD18
			//ADC MUX
			AMX0SL = 0x04;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			ADCMUX_16_19_S1 = true;
			ADCMUX_16_19_S0 = false;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = false;
			break;
		}
		case 51:{//MPD19
			//ADC MUX
			AMX0SL = 0x04;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			ADCMUX_16_19_S1 = true;
			ADCMUX_16_19_S0 = false;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = false;
			break;
		}
		case 52:{//MPD20
			//ADC MUX
			AMX0SL = 0x05;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			ADCMUX_20_23_S1 = false;
			ADCMUX_20_23_S0 = false;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_20_23_OE1 = false;
			ADCMUX_20_23_OE2 = true;
			break;
		}
		case 53:{//MPD21
			//ADC MUX
			AMX0SL = 0x05;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			ADCMUX_20_23_S1 = true;
			ADCMUX_20_23_S0 = false;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_20_23_OE1 = false;
			ADCMUX_20_23_OE2 = true;
			break;
		}
		case 54:{//MPD22
			//ADC MUX
			AMX0SL = 0x05;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			ADCMUX_20_23_S1 = false;
			ADCMUX_20_23_S0 = false;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = false;
			break;
		}
		case 55:{//MPD23
			//ADC MUX
			AMX0SL = 0x05;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			ADCMUX_20_23_S1 = true;
			ADCMUX_20_23_S0 = false;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = false;
			break;
		}
		case 56:{//MPD24
			//ADC MUX
			AMX0SL = 0x06;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			ADCMUX_24_27_S1 = false;
			ADCMUX_24_27_S0 = false;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_24_27_OE1 = false;
			ADCMUX_24_27_OE2 = true;	
			break;
		}
		case 57:{//MPD25
			//ADC MUX
			AMX0SL = 0x06;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			ADCMUX_20_23_S1 = true;
			ADCMUX_20_23_S0 = false;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_24_27_OE1 = false;
			ADCMUX_24_27_OE2 = true;	
			break;
		}
		case 58:{//MPD26
			//ADC MUX
			AMX0SL = 0x06;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			ADCMUX_24_27_S1 = false;
			ADCMUX_24_27_S0 = false;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = false;
			break;
		}
		case 59:{//MPD27
			//ADC MUX
			AMX0SL = 0x06;
			//CHIP0
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = true;
			//CHIP1
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = true;
			//CHIP2
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = true;
			//CHIP3
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = true;
			//CHIP4
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = true;
			//CHIP5
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = true;
			//CHIP6
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = true;
			ADCMUX_24_27_S1 = true;
			ADCMUX_24_27_S0 = false;
			_nop_();_nop_();_nop_();_nop_();_nop_();
			ADCMUX_24_27_OE1 = true;
			ADCMUX_24_27_OE2 = false;
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