#include "sPlcDac.h"
/*****************************************************************************/
void selfTestDac(void){//�Բ�DAC����
	//DAC0-7
	dac8568_0_WriteDacRegister(0x0, 0x3A4B);
	dac8568_0_WriteDacRegister(0x1, 0x3A4B);
	dac8568_0_WriteDacRegister(0x2, 0x3A4B);
	dac8568_0_WriteDacRegister(0x3, 0x3A4B);
	dac8568_0_WriteDacRegister(0x4, 0x3A4B);
	dac8568_0_WriteDacRegister(0x5, 0x3A4B);
	dac8568_0_WriteDacRegister(0x6, 0x3A4B);
	dac8568_0_WriteDacRegister(0x7, 0x3A4B);
	
	dac8568_1_WriteDacRegister(0x0, 20000);
	dac8568_1_WriteDacRegister(0x1, 20000);
	dac8568_1_WriteDacRegister(0x2, 20000);
	dac8568_1_WriteDacRegister(0x3, 20000);
	dac8568_1_WriteDacRegister(0x4, 20000);
	dac8568_1_WriteDacRegister(0x5, 20000);
	dac8568_1_WriteDacRegister(0x6, 20000);
	dac8568_1_WriteDacRegister(0x7, 20000);
	
	dac8568_2_WriteDacRegister(0x0, 30000);
	dac8568_2_WriteDacRegister(0x1, 30000);
	dac8568_2_WriteDacRegister(0x2, 30000);
	dac8568_2_WriteDacRegister(0x3, 30000);
	dac8568_2_WriteDacRegister(0x4, 30000);
	dac8568_2_WriteDacRegister(0x5, 30000);
	dac8568_2_WriteDacRegister(0x6, 30000);
	dac8568_2_WriteDacRegister(0x7, 30000);
	
	dac8568_3_WriteDacRegister(0x0, 40000);
	dac8568_3_WriteDacRegister(0x1, 40000);
	dac8568_3_WriteDacRegister(0x2, 40000);
	dac8568_3_WriteDacRegister(0x3, 40000);
	dac8568_3_WriteDacRegister(0x4, 40000);
	dac8568_3_WriteDacRegister(0x5, 40000);
	dac8568_3_WriteDacRegister(0x6, 40000);
	dac8568_3_WriteDacRegister(0x7, 40000);
}
void refreshDac(void){//ˢ��DAC
	//LD��0
	if(NVRAM0[EM_DAC_0] != NVRAM1[EM_DAC_0]){//CH0
		setLedDac(DEBUG_LED_ON);
		dac8568_0_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_0]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_1] != NVRAM1[EM_DAC_1]){//CH1
		setLedDac(DEBUG_LED_ON);
		dac8568_0_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_1]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_2] != NVRAM1[EM_DAC_2]){//CH2
		setLedDac(DEBUG_LED_ON);
		dac8568_0_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_2]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_3] != NVRAM1[EM_DAC_3]){//CH3
		setLedDac(DEBUG_LED_ON);
		dac8568_0_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_3]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_4] != NVRAM1[EM_DAC_4]){//CH4
		setLedDac(DEBUG_LED_ON);
		dac8568_0_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_4]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_5] != NVRAM1[EM_DAC_5]){//CH5
		setLedDac(DEBUG_LED_ON);
		dac8568_0_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_5]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_6] != NVRAM1[EM_DAC_6]){//CH6
		setLedDac(DEBUG_LED_ON);
		dac8568_0_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_6]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_7] != NVRAM1[EM_DAC_7]){//CH7
		setLedDac(DEBUG_LED_ON);
		dac8568_0_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_7]);
		setLedDac(DEBUG_LED_OFF);
	}
	//LD��1
	if(NVRAM0[EM_DAC_8] != NVRAM1[EM_DAC_8]){//CH8
		setLedDac(DEBUG_LED_ON);
		dac8568_1_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_8]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_9] != NVRAM1[EM_DAC_9]){//CH9
		setLedDac(DEBUG_LED_ON);
		dac8568_1_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_9]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_10] != NVRAM1[EM_DAC_10]){//CH10
		setLedDac(DEBUG_LED_ON);
		dac8568_1_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_10]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_11] != NVRAM1[EM_DAC_11]){//CH11
		setLedDac(DEBUG_LED_ON);
		dac8568_1_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_11]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_12] != NVRAM1[EM_DAC_12]){//CH12
		setLedDac(DEBUG_LED_ON);
		dac8568_1_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_12]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_13] != NVRAM1[EM_DAC_13]){//CH13
		setLedDac(DEBUG_LED_ON);
		dac8568_1_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_13]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_14] != NVRAM1[EM_DAC_14]){//CH14
		setLedDac(DEBUG_LED_ON);
		dac8568_1_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_14]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_15] != NVRAM1[EM_DAC_15]){//CH15
		setLedDac(DEBUG_LED_ON);
		dac8568_1_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_15]);
		setLedDac(DEBUG_LED_OFF);
	}
	//LD��2
	if(NVRAM0[EM_DAC_16] != NVRAM1[EM_DAC_16]){//CH16
		setLedDac(DEBUG_LED_ON);
		dac8568_2_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_16]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_17] != NVRAM1[EM_DAC_17]){//CH17
		setLedDac(DEBUG_LED_ON);
		dac8568_2_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_17]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_18] != NVRAM1[EM_DAC_18]){//CH18
		setLedDac(DEBUG_LED_ON);
		dac8568_2_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_18]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_19] != NVRAM1[EM_DAC_19]){//CH19
		setLedDac(DEBUG_LED_ON);
		dac8568_2_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_19]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_20] != NVRAM1[EM_DAC_20]){//CH20
		setLedDac(DEBUG_LED_ON);
		dac8568_2_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_20]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_21] != NVRAM1[EM_DAC_21]){//CH21
		setLedDac(DEBUG_LED_ON);
		dac8568_2_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_21]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_22] != NVRAM1[EM_DAC_22]){//CH22
		setLedDac(DEBUG_LED_ON);
		dac8568_2_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_22]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_23] != NVRAM1[EM_DAC_23]){//CH23
		setLedDac(DEBUG_LED_ON);
		dac8568_2_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_23]);
		setLedDac(DEBUG_LED_OFF);
	}
	//��4
	if(NVRAM0[EM_DAC_24] != NVRAM1[EM_DAC_24]){//CH24
		setLedDac(DEBUG_LED_ON);
		dac8568_3_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_24]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_25] != NVRAM1[EM_DAC_25]){//CH25
		setLedDac(DEBUG_LED_ON);
		dac8568_3_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_26]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_26] != NVRAM1[EM_DAC_26]){//CH26
		setLedDac(DEBUG_LED_ON);
		dac8568_3_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_26]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_27] != NVRAM1[EM_DAC_27]){//CH27
		setLedDac(DEBUG_LED_ON);
		dac8568_3_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_27]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_28] != NVRAM1[EM_DAC_28]){//CH28
		setLedDac(DEBUG_LED_ON);
		dac8568_3_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_28]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_29] != NVRAM1[EM_DAC_29]){//CH29
		setLedDac(DEBUG_LED_ON);
		dac8568_3_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_29]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_30] != NVRAM1[EM_DAC_30]){//CH30
		setLedDac(DEBUG_LED_ON);
		dac8568_3_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_31]);
		setLedDac(DEBUG_LED_OFF);
	}
	if(NVRAM0[EM_DAC_31] != NVRAM1[EM_DAC_31]){//CH31
		setLedDac(DEBUG_LED_ON);
		dac8568_3_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_31]);
		setLedDac(DEBUG_LED_OFF);
	}
}
void initChipDac(void){//��ʼ��DAC
	setLedDac(DEBUG_LED_ON);
	dac8568_0_Init();
	dac8568_1_Init();
	dac8568_2_Init();
	dac8568_3_Init();
	//UPDATA DAC
	
	dac8568_0_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_7]);
	dac8568_0_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_3]);
	dac8568_0_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_6]);
	dac8568_0_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_2]);
	dac8568_0_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_5]);
	dac8568_0_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_1]);
	dac8568_0_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_4]);
	dac8568_0_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_0]);
			
	dac8568_1_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_15]);
	dac8568_1_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_11]);
	dac8568_1_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_14]);
	dac8568_1_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_10]);
	dac8568_1_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_13]);
	dac8568_1_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_9]);
	dac8568_1_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_12]);
	dac8568_1_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_8]);
	
	dac8568_2_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_23]);
	dac8568_2_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_19]);
	dac8568_2_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_22]);
	dac8568_2_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_18]);
	dac8568_2_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_21]);
	dac8568_2_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_17]);
	dac8568_2_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_20]);
	dac8568_2_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_16]);
	
	dac8568_3_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_31]);
	dac8568_3_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_27]);
	dac8568_3_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_30]);
	dac8568_3_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_26]);
	dac8568_3_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_29]);
	dac8568_3_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_25]);
	dac8568_3_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_28]);
	dac8568_3_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_24]);
	
	setLedDac(DEBUG_LED_OFF);
}




