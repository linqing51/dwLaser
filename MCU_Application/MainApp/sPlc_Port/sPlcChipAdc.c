#include "sPlcChipAdc.h"
/*****************************************************************************/
//ADC MUX3253 CH0-CH3
sbit ADCMUX_0_3_S0 = P1^5;
sbit ADCMUX_0_3_S1 = P1^6;
sbit ADCMUX_0_3_OE1 = P1^7;
sbit ADCMUX_0_3_OE2 = P1^4;
//ADC MUX3253 CH4-CH7
sbit ADCMUX_4_7_S0 = P1^1;
sbit ADCMUX_4_7_S1 = P1^2;
sbit ADCMUC_4_7_OE1 = P1^3;
sbit ADCMUC_4_7_OE2 = P1^0;
//ADC MUX3253 CH8-CH11
sbit ADCMUX_8_11_S0 = P2^5;
sbit ADCMUX_8_11_S1 = P2^6;
sbit ADCMUX_8_11_OE1 = P2^7;
sbit ADCMUX_8_11_OE2 = P2^4;
//ADC MUX3253 CH12-CH15
sbit ADCMUX_12_15_S0 = P2^1;
sbit ADCMUX_12_15_S1 = P2^2;
sbit ADCMUX_12_15_OE1 = P2^3;
sbit ADCMUX_12_15_OE2 = P2^0;
//ADC MUX3253 CH16-CH19
sbit ADCMUX_16_19_S0 = P3^5;
sbit ADCMUX_16_19_S1 = P3^6;
sbit ADCMUX_16_19_OE1 = P3^7;
sbit ADCMUX_16_19_OE2 = P3^4;
//ADC MUX3253 CH20-CH23
sbit ADCMUX_20_23_S0 = P3^1;
sbit ADCMUX_20_23_S1 = P3^2;
sbit ADCMUX_20_23_OE1 = P3^3;
sbit ADCMUX_20_23_OE2 = P3^0;
//ADC MUX3253 CH24-CH27
sbit ADCMUX_24_27_S0 = P0^5;
sbit ADCMUX_24_27_S1 = P0^6;
sbit ADCMUX_24_27_OE1 = P0^7;
sbit ADCMUX_24_27_OE2 = P0^4;
/*****************************************************************************/
static uint8_t adcSelect;//ADC通道选择
/*****************************************************************************/
void initChipAdc(void){//ADC模块初始化
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
	ADC0CN = 0x0;//软件触发
	ADC0CN |= (1 << 7);//AD0EN = 1 
	ADC0CF = 0x0;
	ADC0CF |= (CONFIG_SYSCLK / SAR_CLK) << 3;// ADC conversion clock = 2.5MHz
	AMX0CF = 0x00;// AIN inputs are single-ended (default)
	AMX0SL = 0x00;// Select AIN0.1 pin as ADC mux input
	adcSelect = 0;
}
void chipAdcProcess(void){//循环采集ADC
	uint16_t result = 0;
	AD0INT = 0;
	AD0BUSY = 1;
	while(AD0INT == 0);//查询ADC标志
	result = (ADC0 & 0x0FFF);
	NVRAM0[EM_ADC_0 + adcSelect] = result;
	adcSelect ++;
	if(adcSelect >= 50){
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
			ADCMUX_24_27_OE1 = false;
			ADCMUX_24_27_OE2 = true;
			break;
		}
		case 25:{//MPD0
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
			ADCMUX_0_3_OE1 = false;
			ADCMUX_0_3_OE2 = true;
			break;
		}
		case 26:{//MPD1
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
			ADCMUX_0_3_OE1 = false;
			ADCMUX_0_3_OE2 = true;
			break;
		}
		case 27:{//MPD2
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
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = false;
			break;
		}
		case 28:{//MPD3
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
			ADCMUX_0_3_OE1 = true;
			ADCMUX_0_3_OE2 = false;
			break;
		}
		case 29:{//MPD4
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
			ADCMUC_4_7_OE1 = false;
			ADCMUC_4_7_OE2 = true;
			break;
		}
		case 30:{//MPD5
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
			ADCMUC_4_7_OE1 = false;
			ADCMUC_4_7_OE2 = true;
			break;
		}
		case 31:{//MPD6
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
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = false;
			break;
		}
		case 32:{//MPD7
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
			ADCMUC_4_7_OE1 = true;
			ADCMUC_4_7_OE2 = false;
			break;
		}
		case 33:{//MPD8
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
			ADCMUX_8_11_OE1 = false;
			ADCMUX_8_11_OE2 = true;
			break;
		}
		case 34:{//MPD9
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
			ADCMUX_8_11_OE1 = false;
			ADCMUX_8_11_OE2 = true;
			break;
		}
		case 35:{//MPD10
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
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = false;
			break;
		}
		case 36:{//MPD11
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
			ADCMUX_8_11_OE1 = true;
			ADCMUX_8_11_OE2 = false;
			break;
		}
		case 37:{//MPD12
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
			ADCMUX_12_15_OE1 = false;
			ADCMUX_12_15_OE2 = true;
			break;
		}
		case 38:{//MPD13
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
			ADCMUX_12_15_OE1 = false;
			ADCMUX_12_15_OE2 = true;
			break;
		}
		case 39:{//MPD14
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
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = false;
			break;
		}
		case 40:{//MPD15
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
			ADCMUX_12_15_OE1 = true;
			ADCMUX_12_15_OE2 = false;
			break;
		}
		case 41:{//MPD16
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
			ADCMUX_16_19_OE1 = false;
			ADCMUX_16_19_OE2 = true;
			break;
		}
		case 42:{//MPD17
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
			ADCMUX_16_19_OE1 = false;
			ADCMUX_16_19_OE2 = true;
			break;
		}
		case 43:{//MPD18
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
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = false;
			break;
		}
		case 44:{//MPD19
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
			ADCMUX_16_19_OE1 = true;
			ADCMUX_16_19_OE2 = false;
			break;
		}
		case 45:{//MPD20
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
			ADCMUX_20_23_OE1 = false;
			ADCMUX_20_23_OE2 = true;
			break;
		}
		case 46:{//MPD21
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
			ADCMUX_20_23_OE1 = false;
			ADCMUX_20_23_OE2 = true;
			break;
		}
		case 47:{//MPD22
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
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = false;
			break;
		}
		case 48:{//MPD23
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
			ADCMUX_20_23_OE1 = true;
			ADCMUX_20_23_OE2 = false;
			break;
		}
		case 49:{//MPD24
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
			ADCMUX_24_27_OE1 = false;
			ADCMUX_24_27_OE2 = true;	
			break;
		}
		default:{
			break;
		}
	}
}