#include "sPlcDac.h"
/*****************************************************************************/
void selfTestDac(void){//×Ô²âDACÈí¼þ
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
void refreshDac(void){//Ë¢ÐÂDAC
	//LD°å0
	if(NVRAM0[EM_DAC_0] != NVRAM1[EM_DAC_0]){//CH0
		dac8568_0_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_0]);
	}
	if(NVRAM0[EM_DAC_1] != NVRAM1[EM_DAC_1]){//CH1
		dac8568_0_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_1]);
	}
	if(NVRAM0[EM_DAC_2] != NVRAM1[EM_DAC_2]){//CH2
		dac8568_0_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_2]);
	}
	if(NVRAM0[EM_DAC_3] != NVRAM1[EM_DAC_3]){//CH3
		dac8568_0_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_3]);
	}
	if(NVRAM0[EM_DAC_4] != NVRAM1[EM_DAC_4]){//CH4
		dac8568_0_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_4]);
	}
	if(NVRAM0[EM_DAC_5] != NVRAM1[EM_DAC_5]){//CH5
		dac8568_0_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_5]);
	}
	if(NVRAM0[EM_DAC_6] != NVRAM1[EM_DAC_6]){//CH6
		dac8568_0_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_6]);
	}
	if(NVRAM0[EM_DAC_7] != NVRAM1[EM_DAC_7]){//CH7
		dac8568_0_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_7]);
	}
	//LD°å1
	if(NVRAM0[EM_DAC_8] != NVRAM1[EM_DAC_8]){//CH8
		dac8568_1_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_8]);
	}
	if(NVRAM0[EM_DAC_9] != NVRAM1[EM_DAC_9]){//CH9
		dac8568_1_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_9]);
	}
	if(NVRAM0[EM_DAC_10] != NVRAM1[EM_DAC_10]){//CH10
		dac8568_1_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_10]);
	}
	if(NVRAM0[EM_DAC_11] != NVRAM1[EM_DAC_11]){//CH11
		dac8568_1_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_11]);
	}
	if(NVRAM0[EM_DAC_12] != NVRAM1[EM_DAC_12]){//CH12
		dac8568_1_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_12]);
	}
	if(NVRAM0[EM_DAC_13] != NVRAM1[EM_DAC_13]){//CH13
		dac8568_1_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_13]);
	}
	if(NVRAM0[EM_DAC_14] != NVRAM1[EM_DAC_14]){//CH14
		dac8568_1_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_14]);
	}
	if(NVRAM0[EM_DAC_15] != NVRAM1[EM_DAC_15]){//CH15
		dac8568_1_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_15]);
	}
	//LD°å2
	if(NVRAM0[EM_DAC_16] != NVRAM1[EM_DAC_16]){//CH16
		dac8568_2_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_16]);
	}
	if(NVRAM0[EM_DAC_17] != NVRAM1[EM_DAC_17]){//CH17
		dac8568_2_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_17]);
	}
	if(NVRAM0[EM_DAC_18] != NVRAM1[EM_DAC_18]){//CH18
		dac8568_2_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_18]);
	}
	if(NVRAM0[EM_DAC_19] != NVRAM1[EM_DAC_19]){//CH19
		dac8568_2_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_19]);
	}
	if(NVRAM0[EM_DAC_20] != NVRAM1[EM_DAC_20]){//CH20
		dac8568_2_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_20]);
	}
	if(NVRAM0[EM_DAC_21] != NVRAM1[EM_DAC_21]){//CH21
		dac8568_2_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_21]);
	}
	if(NVRAM0[EM_DAC_22] != NVRAM1[EM_DAC_22]){//CH22
		dac8568_2_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_22]);
	}
	if(NVRAM0[EM_DAC_23] != NVRAM1[EM_DAC_23]){//CH23
		dac8568_2_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_23]);
	}
	//°å4
	if(NVRAM0[EM_DAC_24] != NVRAM1[EM_DAC_24]){//CH24
		dac8568_3_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_24]);
	}
	if(NVRAM0[EM_DAC_25] != NVRAM1[EM_DAC_25]){//CH25
		dac8568_3_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_26]);
	}
	if(NVRAM0[EM_DAC_26] != NVRAM1[EM_DAC_26]){//CH26
		dac8568_3_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_26]);
	}
	if(NVRAM0[EM_DAC_27] != NVRAM1[EM_DAC_27]){//CH27
		dac8568_3_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_27]);
	}
}
void initChipDac(void){//³õÊ¼»¯DAC
	dac8568_0_Init();
	dac8568_1_Init();
	dac8568_2_Init();
	dac8568_3_Init();
}




