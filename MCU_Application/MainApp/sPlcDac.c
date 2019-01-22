#include "sPlcDac.h"
/*****************************************************************************/
void selfTestDac(void){//自测DAC软件
	//DAC0-7

}
void refreshDac(void){//刷新DAC
	//LD板0
	if(NVRAM0[EM_DAC_0] != NVRAM1[EM_DAC_0]){//CH0
		setLedDac(DEBUG_LED_ON);
		//dac8568_0_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_0]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_1] != NVRAM1[EM_DAC_1]){//CH1
		setLedDac(DEBUG_LED_ON);
		//dac8568_0_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_1]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_2] != NVRAM1[EM_DAC_2]){//CH2
		setLedDac(DEBUG_LED_ON);
		//dac8568_0_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_2]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_3] != NVRAM1[EM_DAC_3]){//CH3
		setLedDac(DEBUG_LED_ON);
		//dac8568_0_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_3]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_4] != NVRAM1[EM_DAC_4]){//CH4
		setLedDac(DEBUG_LED_ON);
		//dac8568_0_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_4]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_5] != NVRAM1[EM_DAC_5]){//CH5
		setLedDac(DEBUG_LED_ON);
		//dac8568_0_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_5]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_6] != NVRAM1[EM_DAC_6]){//CH6
		setLedDac(DEBUG_LED_ON);
		//dac8568_0_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_6]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_7] != NVRAM1[EM_DAC_7]){//CH7
		setLedDac(DEBUG_LED_ON);
		//dac8568_0_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_7]);
		setLedDac(DEBUG_LED_OFF);
	}
}
void initChipDac(void){//初始化DAC
	setLedDac(DEBUG_LED_ON);
	//dac8568_0_Init();
	//dac8568_1_Init();
	//dac8568_2_Init();
	//dac8568_3_Init();
	//UPDATA DAC
	
	//dac8568_0_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_7]);	
	setLedDac(DEBUG_LED_OFF);
}




