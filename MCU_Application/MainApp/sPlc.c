#include "sPlc.h"
/*****************************************************************************/
//ADC MUX3253 CH0-CH3
sbit ADCMUX_0_3_S0 = P1^4;
sbit ADCMUX_0_3_S1	= P1^7;
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
xdata int16_t NVRAM0[CONFIG_NVRAM_SIZE];//掉电保持寄存器 当前
xdata int16_t NVRAM1[CONFIG_NVRAM_SIZE];//掉电保持寄存器 上一次
static data uint8_t TimerCounter_1mS = 0;
static data uint8_t TimerCounter_10mS = 0;
static data uint8_t Timer0_L, Timer0_H;
/*****************************************************************************/
static pdata int8_t inputFilter[(X_END - X_START + 1) * 16];//IO输入滤波器缓冲区
static xdata adcTempDat_t adcTempDat[CONFIG_SPLC_ADC_CHANNLE];
static uint8_t adcSelect;//ADC通道选择
static void refreshAdcData(adcTempDat_t *s , uint16_t dat);
static void adcProcess(void);
static void initAdcData(adcTempDat_t *s);
static void chipDacInit(void);
static void chipAdcInit(void);
/******************************************************************************/
static uint8_t getGlobalInterrupt(void){
	return EA;
}
static void setLedRun(uint8_t st){//LED RUN P7_0
	if(st){
		P7 |= (uint8_t)(1 << 0);
	}
	else{
		P7 &= ~(uint8_t)(1 << 0);
	}
}
static uint8_t getLedRun(void){//LED RUN P7_0
	return (uint8_t)((P7 >> 0) & 0x01);
}
static void setLedEprom(uint8_t st){//LED EPROM P7_1
	if(st){
		P7 |= (uint8_t)(1 << 1);
	}
	else{
		P7 &= ~(uint8_t)(1 << 1);
	}
}
static uint8_t getLedEprom(void){//LED EPROM P7_1
	return (uint8_t)((P7 >> 1) & 0x01);
}
static void setLedDac(uint8_t st){//LED DAC P7_2
	if(st){
		P7 |= (uint8_t)(1 << 2);
	}
	else{
		P7 &= ~(uint8_t)(1 << 2);
	}
}
static uint8_t getLedDac(void){//LED DAC P7_2
	return (uint8_t)((P7 >> 2) & 0x01);
}
static void setLedError(uint8_t st){//LED ERROR P7_3
	if(st){
		P7 |= (uint8_t)(1 << 3);
	}
	else{
		P7 &= ~(uint8_t)(1 << 3);
	}
}
static uint8_t getLedError(void) reentrant{
	return (uint8_t)((P7 >> 3) & 0x01);
}
static void adcProcess(void){//循环采集ADC
	uint16_t result = 0;
#ifdef C8051F020
	//while(!AD0INT);
#endif
	result = (ADC0 & 0xFFF);
	refreshAdcData(&adcTempDat[adcSelect], result);
	NVRAM0[EM_ADC_0 + adcSelect] = adcTempDat[adcSelect].out;
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
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = false;
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
static void initAdcData(adcTempDat_t *s){//初始化ADC滤波器
	uint8_t i;
	for(i = 0;i < CONFIG_SPLC_ADC_FILTER_TAP; i++){
		s->dat[i] = 0x0;
	}
	s->out = 0;
	s->wIndex = 0;
}
static void refreshAdcData(adcTempDat_t *s , uint16_t dat){//更新ADC采集值 
	uint8_t i;
	uint16_t temp;
	uint32_t sum;
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
static void assertCoilAddress(uint16_t adr){//检查线圈地址
	if(adr > (SPREG_END * 16))
		while(1);
}
static void assertRegisterAddress(uint16_t adr){//检查寄存器地址
	if(adr >= SPREG_END)
		while(1);
}
static void clearDM(void){//清除DM寄存器
	uint16_t i;
	for(i = 0;i <= DM_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearMR(void){//清除MR寄存器
	uint16_t i;
	for(i = MR_START;i <= MR_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearEM(void){//清除EM寄存器
	uint16_t i;
	for(i = EM_START;i <= EM_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearR(void){//清除R寄存器
	uint16_t i;
	for(i = R_START;i <= R_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearT(void){//清除T寄存器
	uint16_t i;
	for(i = T_1MS_START;i <= T_1MS_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
	for(i = T_10MS_START;i <= T_10MS_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
	for(i = T_100MS_START;i <= T_100MS_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearTD(void){//清除TD寄存器
	uint16_t i;
	for(i = TD_1MS_START;i <= TD_1MS_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
	for(i = TD_10MS_START;i <= TD_10MS_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
	for(i = TD_100MS_START;i <= TD_100MS_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearC(void){//清除C寄存器
	uint16_t i;
	for(i = C_START;i <= C_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearX(void){//清除X寄存器
	uint16_t i;
	for(i = X_START;i <= X_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearY(void){//清除Y寄存器
	uint16_t i;
	for(i = Y_START;i <= Y_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearSPREG(void){
	uint16_t i;
	for(i = SPREG_START;i <= SPREG_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearSPCOIL(){
	uint16_t i;
	for(i = SPCOIL_START;i <= SPCOIL_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void nvramLoad(void){//从EPROM中载入NVRAM
	memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//初始化NVRAM
	epromRead(0, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));//从EPROM中恢复MR
	clearEM();
	clearR();
	clearT();
	clearTD();
	clearC();
	clearX();
	clearY();
	clearSPREG();
	clearSPCOIL();
	memcpy(NVRAM1, NVRAM0, CONFIG_NVRAM_SIZE);
}
static void nvramSave(void){//强制将NVRAM存入EPROM
	DISABLE_INTERRUPT;
	epromWrite(0x0, (uint8_t*)NVRAM0, ((MR_END + 1) * 2));
	ENABLE_INTERRUPT;
}
static void nvramUpdata(void){//更新NVRAM->EPROM
	uint8_t *sp0, *sp1;
	uint16_t i;
	sp0 = (uint8_t*)(NVRAM0 + (MR_START * 2));
	sp1 = (uint8_t*)(NVRAM1 + (MR_START * 2));
	for(i = MR_START;i < ((MR_END + 1) * 2);i ++){//储存MR
		if(*(sp0 + i) != *(sp1 + i)){
			epromWriteOneByte(i, *(sp0 + i));
		}
	}
	sp0 = (uint8_t*)(NVRAM0 + (DM_START * 2));
	sp1 = (uint8_t*)(NVRAM1 + (DM_START * 2));
	for(i = DM_START;i < ((DM_END + 1) * 2);i ++){//储存DM
		if(*(sp0 + i) != *(sp1 + i)){
			epromWriteOneByte(i, *(sp0 + i));
		}
	}
	memcpy(NVRAM1, NVRAM0, (CONFIG_NVRAM_SIZE * 2));
}
/*****************************************************************************/
//软逻辑指令
void SET(uint16_t A){//置位
	assertCoilAddress(A);//检查地址范围
	NVRAM0[(A / 16)] |= 1 << (A % 16);
}
void RESET(uint16_t A){//置零
	assertCoilAddress(A);//检查地址范围
	NVRAM0[(A / 16)] &= ~(1 << (A % 16));
}
void FLIP(uint16_t A){//翻转
	uint16_t temp;
	assertCoilAddress(A);//检查地址范围
	temp= NVRAM0[(A / 16)] & (1 << (A % 16));
	if(temp)
		RESET(A);
	else
		SET(A);
}
uint8_t LD(uint16_t A){//载入
	assertCoilAddress(A);//检查地址范围
	return (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
}
uint8_t LDP(uint16_t A){//脉冲上升沿
	uint8_t temp0, temp1;
	assertCoilAddress(A);//检查地址范围
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
	if(temp0 && !temp1)
		return 1;
	else
		return 0;
}
uint8_t LDN(uint16_t A){//脉冲下降沿
	uint8_t temp0, temp1;
	assertCoilAddress(A);
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
	if(!temp0 && temp1)
		return 1;
	else
		return 0;
}
void T1MS(uint8_t A, uint8_t start, uint16_t value){//1MS延时器
#if CONFIG_DEBUG
	if(A > (TD_1MS_END - TD_1MS_START + 1))
		printf("T1MS:%d Over Num\n", A);
#endif
	if(start){
		if(NVRAM0[(TD_1MS_START + A)] >= value){
			NVRAM0[(T_1MS_START + (A / 16))] |= 1 << (A % 16);
		}
		else{
			NVRAM0[(T_1MS_START + (A / 16))] &= ~(1 << (A % 16));
		}
			
	}
	else{
		NVRAM0[(T_1MS_START + (A / 16))] &= ~(1 << (A % 16));
		NVRAM0[(TD_1MS_START + A)] = 0x0;
	}	
}
void T10MS(uint8_t A, uint8_t start, uint16_t value){//10MS延时器
#if CONFIG_DEBUG
	if(A > (TD_10MS_END - TD_10MS_START + 1))
		printf("T10MS:%d Over Num\n", A);
#endif
	if(start){
		if(NVRAM0[(TD_10MS_START + A)] >= value){
			NVRAM0[(T_10MS_START + (A / 16))] |= 1 << (A % 16);
		}
		else{
			NVRAM0[(T_10MS_START + (A / 16))] &= ~(1 << (A % 16));
		}
	}
	else{
		NVRAM0[(T_10MS_START + (A / 16))] &= ~(1 << (A % 16));
		NVRAM0[(TD_10MS_START + A)] = 0x0;
	}	
}
void T100MS(uint8_t A, uint8_t start, uint16_t value){//100MS延时器
#if CONFIG_DEBUG
	if(A > (TD_100MS_END - TD_100MS_START + 1))
		printf("T100MS:%d Over Num\n", A);
#endif
	if(start){
		if(NVRAM0[(TD_100MS_START + A)] >= value){
			NVRAM0[(T_100MS_START + (A / 16))] |= 1 << (A % 16);
		}
		else{
			NVRAM0[(T_100MS_START + (A / 16))] &= ~(1 << (A % 16));
		}	
	}
	else{
		NVRAM0[(T_100MS_START + (A / 16))] &= ~(1 << (A % 16));
		NVRAM0[(TD_100MS_START + A)] = 0x0;
	}
}
int16_t TNTC(int16_t dat){//CODE转换为NTC测量温度温度
	uint16_t temp;
	fp32_t ftemp;
	if(dat >= CONFIG_SPLC_ADC_INTERNAL_VREF) dat = CONFIG_SPLC_ADC_INTERNAL_VREF;//限制输入最大值
	if(dat < 0) dat = 0;
	
	temp = (int16_t)(CONFIG_SPLC_ADC_INTERNAL_VREF * dat / 4096);//单位mV
	temp = 10000 * 5000 / (5000 - temp);//电源5V 分压电阻10K
	
	ftemp = ((1.0 / 3477)*log((fp32_t)(temp) / 10000)) + (1 / (25+273.0));//limo R25=10740,B=3450	 uniquemode 3988
	ftemp = ( 1.0 / ftemp ) - 273.0;
	if(ftemp >= 100) ftemp = 100;
	if(ftemp <= -100) ftemp = -100;
	return (int16_t)(ftemp * 10);
}
int16_t TENV(int16_t dat){//CODE转换为环境温度
	uint16_t temp;
	temp = (int16_t)(CONFIG_SPLC_ADC_INTERNAL_VREF * dat / 4096);//单位mV
	temp = (int16_t)((temp - CONFIG_SPLC_ADC_TEMP_SENSOR_OFFSET) * 1000 / CONFIG_SPLC_ADC_TEMP_SENSOR_GAIN);
	return temp;
}
int16_t MAX(int16_t *s, uint8_t len){//找出长度为len的数据s中的最大值
	int16_t max;
	uint8_t i;
	max = *s;
	for(i = 0;i < len;i ++){
		if(*(s +i) > max){
			max = *(s + i);
		}
	}
	return max;
}
int16_t MIN(int16_t *s, uint8_t len){//找出长度为len的数据s中的最小值
	int16_t min;
	uint8_t i;
	min = *s;
	for(i = 0;i < len;i ++){
		if(*(s +i) < min){
			min = *(s + i);
		}
	}
	return min;
}
/*****************************************************************************/
static void wdtInit(void){//看门狗初始化
#ifdef C8051F020
	WDTCN = 0;//47mS
#endif
}
static void wdtEnable(void){//使能看门狗
#ifdef C8051F020
	WDTCN = 0xA5;
#endif
}
static void wdtDisable(void){//关闭看门狗(未锁定)
	uint8_t flagEA;
	flagEA = EA;
	EA = 0;
#ifdef C8051F020
	WDTCN = 0xDE;
    WDTCN = 0xAD;
#endif
#ifdef C8051F020
#endif
	EA = flagEA;
}
static void wdtFeed(void){//喂狗
#ifdef C8051F020
	WDTCN = 0xA5;
#endif
}

static void pcaInit(void){//硬件PCA初始化
}
static void timer0Init(void){//硬件sTimer计时器初始化
	data uint16_t temp;
	TimerCounter_1mS = 0;
	TimerCounter_10mS = 0;
#ifdef C8051F020
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 12 /CONFIG_SOFTPLC_HWTIME));
	Timer0_L = temp & 0xFF;
	Timer0_H = (temp >> 8) & 0xFF;
	TH0 = Timer0_H;// Init T0 High register
	TL0 = Timer0_L;// Init T0 Low register
	CKCON &= ~(1 << 3);//SYSCLK / 12	
	TMOD &= 0xF0;
	TMOD |= (1 << 0);// T0 in 16-bit mode
	ET0 = 1;// T0 interrupt enabled
	TR0 = 1;// T0 ON
#endif
}
static void timer0Isr(void) interrupt INTERRUPT_TIMER0{//硬件sTimer计时器中断 1mS
	uint16_t i;
	TF0 = 0;
	TR0 = 0;
	TH0 = Timer0_H;
	TL0 = Timer0_L;
	TR0 = 1;
	if((NVRAM0[(SPCOIL_START + (SPCOIL_PS1MS / 16))] >> (SPCOIL_PS1MS % 16)) & 0x01){//ON
		NVRAM0[(SPCOIL_START + (SPCOIL_PS1MS / 16))] &= ~(uint16_t)(1 << (SPCOIL_PS1MS % 16));
	}
	else{//OFF
		NVRAM0[(SPCOIL_START + (SPCOIL_PS1MS / 16))] |= (uint16_t)(1 << (SPCOIL_PS1MS % 16));
	}
	
	for(i = TD_1MS_START;i <= TD_1MS_END;i ++){//1mS计时
		if(NVRAM0[i] < SHRT_MAX){
			NVRAM0[i] ++;
		}
	}
	if(TimerCounter_1mS >= 10){//10mS计算
		if((NVRAM0[(SPCOIL_START + (SPCOIL_PS10MS / 16))] >> (SPCOIL_PS10MS % 16)) & 0x01){//ON
			NVRAM0[(SPCOIL_START + (SPCOIL_PS10MS / 16))] &= ~(uint16_t)(1 << (SPCOIL_PS10MS % 16));
		}
		else{//OFF
			NVRAM0[(SPCOIL_START + (SPCOIL_PS10MS / 16))] |= (uint16_t)(1 << (SPCOIL_PS10MS % 16));
		}
		for(i = TD_10MS_START;i <= TD_10MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_10mS ++;
		TimerCounter_1mS = 0;
	}
	if(TimerCounter_10mS >= 10){//100ms计算
		if((NVRAM0[(SPCOIL_START + (SPCOIL_PS100MS / 16))] >> (SPCOIL_PS100MS % 16)) & 0x01){//ON
			NVRAM0[(SPCOIL_START + (SPCOIL_PS100MS / 16))] &= ~(uint16_t)(1 << (SPCOIL_PS100MS % 16));
		}
		else{//OFF
			NVRAM0[(SPCOIL_START + (SPCOIL_PS100MS / 16))] |= (uint16_t)(1 << (SPCOIL_PS100MS % 16));
		}
		for(i = TD_100MS_START;i < TD_100MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_10mS = 0;
		if(getLedRun()){
			setLedRun(false);
		}
		else{
			setLedRun(true);
		}
	}
#if CONFIG_SPLC_USING_ADC == 1
	adcProcess();//ADC扫描
#endif
	TimerCounter_1mS ++;
}

static void inputInit(void){//IO输入滤波器初始化
	memset(inputFilter, 0x0, (X_END - X_START + 1) * 16);
}
static void outputInit(void){
#ifdef C8051F020
	
#endif
}
static void inputRefresh(void){//获取输入IO
	uint8_t ctemp0;
	ctemp0 = ((P6 >> 7) & 0x01);
	if(ctemp0){
		if(inputFilter[0] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[0] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 0);
		}
	}
	else{
		if(inputFilter[0] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[0] --;
		}
		else{
			NVRAM0[X_START] &= ~(uint16_t)(1 << 0);
		}
	}
	ctemp0 = ((P6 >> 6) & 0x01);
	if(ctemp0){
		if(inputFilter[1] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[1] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 1);
		}
	}
	else{
		if(inputFilter[1] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[1] --;
		}
		else{
			NVRAM0[X_START] &= ~(uint16_t)(1 << 1);
		}
	}
}
static void outputRefresh(void){//设置输出IO
	if((NVRAM0[Y_START] >> 0) & 0x01){//P6_5
		P6 |= (uint8_t)(1 << 5);
	}
	else{
		P6 &= ~(uint8_t)(1 << 5);
	}
	if((NVRAM0[Y_START] >> 1) & 0x01){//P6_4
		P6 |= (uint8_t)(1 << 4);
	}
	else{
		P6 &= ~(uint8_t)(1 << 4);
	}
}
static void chipAdcInit(void){//ADC模块初始化
	uint8_t i;
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
	AD0INT = 0;
	AD0BUSY = 1;//AD0BUSY写入1
#endif
	adcSelect = 0;
	for(i = 0;i <= CONFIG_SPLC_ADC_CHANNLE;i ++){
		initAdcData(&adcTempDat[i]);
	}
}
static void refreshDac(void){//刷新DAC
	//LD板0
	if(NVRAM0[EM_DAC_0] != NVRAM1[EM_DAC_0]){//CH0
		setLedDac(true);
		dac8568_0_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_0]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_1] != NVRAM1[EM_DAC_1]){//CH1
		setLedDac(true);
		dac8568_0_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_1]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_2] != NVRAM1[EM_DAC_2]){//CH2
		setLedDac(true);
		dac8568_0_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_2]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_3] != NVRAM1[EM_DAC_3]){//CH3
		setLedDac(true);
		dac8568_0_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_3]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_4] != NVRAM1[EM_DAC_4]){//CH4
		setLedDac(true);
		dac8568_0_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_4]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_5] != NVRAM1[EM_DAC_5]){//CH5
		setLedDac(true);
		dac8568_0_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_5]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_6] != NVRAM1[EM_DAC_6]){//CH6
		setLedDac(true);
		dac8568_0_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_6]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_7] != NVRAM1[EM_DAC_7]){//CH7
		setLedDac(true);
		dac8568_0_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_7]);
		setLedDac(false);
	}
	//LD板1
	if(NVRAM0[EM_DAC_8] != NVRAM1[EM_DAC_8]){//CH8
		setLedDac(true);
		dac8568_1_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_8]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_9] != NVRAM1[EM_DAC_9]){//CH9
		setLedDac(true);
		dac8568_1_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_9]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_10] != NVRAM1[EM_DAC_10]){//CH10
		setLedDac(true);
		dac8568_1_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_10]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_11] != NVRAM1[EM_DAC_11]){//CH11
		setLedDac(true);
		dac8568_1_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_11]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_12] != NVRAM1[EM_DAC_12]){//CH12
		setLedDac(true);
		dac8568_1_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_12]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_13] != NVRAM1[EM_DAC_13]){//CH13
		setLedDac(true);
		dac8568_1_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_13]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_14] != NVRAM1[EM_DAC_14]){//CH14
		setLedDac(true);
		dac8568_1_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_14]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_15] != NVRAM1[EM_DAC_15]){//CH15
		setLedDac(true);
		dac8568_1_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_15]);
		setLedDac(false);
	}
	//LD板2
	if(NVRAM0[EM_DAC_16] != NVRAM1[EM_DAC_16]){//CH16
		setLedDac(true);
		dac8568_2_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_16]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_17] != NVRAM1[EM_DAC_17]){//CH17
		setLedDac(true);
		dac8568_2_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_17]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_18] != NVRAM1[EM_DAC_18]){//CH18
		setLedDac(true);
		dac8568_2_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_18]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_19] != NVRAM1[EM_DAC_19]){//CH19
		setLedDac(true);
		dac8568_2_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_19]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_20] != NVRAM1[EM_DAC_20]){//CH20
		setLedDac(true);
		dac8568_2_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_20]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_21] != NVRAM1[EM_DAC_21]){//CH21
		setLedDac(true);
		dac8568_2_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_21]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_22] != NVRAM1[EM_DAC_22]){//CH22
		setLedDac(true);
		dac8568_2_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_22]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_23] != NVRAM1[EM_DAC_23]){//CH23
		setLedDac(true);
		dac8568_2_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_23]);
		setLedDac(false);
	}
	//板4
	if(NVRAM0[EM_DAC_24] != NVRAM1[EM_DAC_24]){//CH24
		setLedDac(true);
		dac8568_3_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_24]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_25] != NVRAM1[EM_DAC_25]){//CH25
		setLedDac(true);
		dac8568_3_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_26]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_26] != NVRAM1[EM_DAC_26]){//CH26
		setLedDac(true);
		dac8568_3_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_26]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_27] != NVRAM1[EM_DAC_27]){//CH27
		setLedDac(true);
		dac8568_3_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_27]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_28] != NVRAM1[EM_DAC_28]){//CH28
		setLedDac(true);
		dac8568_3_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_28]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_29] != NVRAM1[EM_DAC_29]){//CH29
		setLedDac(true);
		dac8568_3_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_29]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_30] != NVRAM1[EM_DAC_30]){//CH30
		setLedDac(true);
		dac8568_3_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_30]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_31] != NVRAM1[EM_DAC_31]){//CH31
		setLedDac(true);
		dac8568_3_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_31]);
		setLedDac(false);
	}
}
static void chipDacInit(void){//初始化DAC
	dac8568_0_Init();
	dac8568_1_Init();
	dac8568_2_Init();
	dac8568_3_Init();
}
void sPlcInit(void){//软逻辑初始化
	setLedError(true);
	setLedRun(false);
	wdtInit();//看门狗使能
	wdtDisable();//屏蔽看门狗	
#if CONFIG_SPLC_USING_EPROM == 1
	nvramLoad();//上电恢复NVRAM
#endif
	
#if CONFIG_SPLC_USING_ADC == 1
	chipAdcInit();//初始化ADC模块
#endif
	
#if CONFIG_SPLC_USING_DAC == 1
	chipDacInit();//初始化DAC模块
#endif
	
#if CONFIG_SPLC_USING_MB_RTU_SLAVE == 1
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
#endif
	timer0Init();//初始化硬件计时器模块
	NVRAM0[(SPCOIL_START + (SPCOIL_ON / 16))] |= (uint16_t)(1 << (SPCOIL_ON % 16));
	setLedError(false);
}
void sPlcProcessStart(void){//sPLC轮询起始
#if CONFIG_SPLC_USING_MB_RTU_SLAVE == 1
	modbusPorcess();//处理MODBUS
#endif
#if CONFIG_SPLC_USING_IO_INPUT == 1
	inputRefresh();//读取X口输入
#endif
#if CONFIG_SPLC_USING_WDT == 1
	wdtFeed();
#endif
}
void sPlcProcessEnd(void){//sPLC轮询结束
#if CONFIG_SPLC_USING_WDT == 1
	wdtFeed();//喂狗
#endif
#if CONFIG_SPLC_USING_IO_OUTPUT == 1
	outputRefresh();//更新Y口输出
#endif
#if CONFIG_SPLC_USING_DAC
	refreshDac();//更新DAC输出
#endif
#if CONFIG_SPLC_USING_EPROM == 1
	nvramUpdata();//更新NVRAM
#endif
}