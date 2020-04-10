#include "sPlcDac.h"
/*****************************************************************************/
void selfTestDac(void){//自测DAC软件
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
void forceRefreshDac(void){//强制刷新DAC
	//CH0
	dac8568_0_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_0]);
	DAC0 = (uint16_t)NVRAM0[EM_DAC_0];
	//CH1
	dac8568_0_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_1]);
	DAC1 = (uint16_t)NVRAM0[EM_DAC_1];
	//CH2
	dac8568_0_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_2]);
	//CH3
	dac8568_0_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_3]);
	//CH4
	dac8568_0_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_4]);
	//CH5
	dac8568_0_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_5]);
	//CH6
	dac8568_0_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_6]);
	//CH7
	dac8568_0_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_7]);
	//CH8
	dac8568_1_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_8]);
	//CH9
	dac8568_1_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_9]);
	//CH10
	dac8568_1_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_10]);
	//CH11
	dac8568_1_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_11]);
	//CH12
	dac8568_1_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_12]);
	//CH13
	dac8568_1_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_13]);
	//CH14
	dac8568_1_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_14]);
	//CH15
	dac8568_1_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_15]);
	//CH16
	dac8568_2_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_16]);
	//CH17
	dac8568_2_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_17]);
	//CH18
	dac8568_2_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_18]);
	//CH19
	dac8568_2_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_19]);
	//CH20
	dac8568_2_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_20]);
	//CH21
	dac8568_2_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_21]);
	//CH22
	dac8568_2_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_22]);
	//CH23
	dac8568_2_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_23]);
	//CH24
	dac8568_3_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_24]);
}
void refreshDac(void){//刷新DAC
	//LD板0
	if(NVRAM0[EM_DAC_0] != NVRAM1[EM_DAC_0]){//CH0
		dac8568_0_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_0]);
		DAC0 = (uint16_t)NVRAM0[EM_DAC_0];
	}
	if(NVRAM0[EM_DAC_1] != NVRAM1[EM_DAC_1]){//CH1
		dac8568_0_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_1]);
		DAC1 = (uint16_t)NVRAM0[EM_DAC_1];
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
	//LD板1
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
	//LD板2
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
	//板4
	if(NVRAM0[EM_DAC_24] != NVRAM1[EM_DAC_24]){//CH24
		dac8568_3_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_24]);
	}
}
void forceSetDac(uint8_t channel){
	switch(channel){
		case 0:{
			dac8568_0_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_0]);
			DAC0 = (uint16_t)NVRAM0[EM_DAC_0];
			break;
		}
		case 1:{
			dac8568_0_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_1]);
			DAC1 = (uint16_t)NVRAM0[EM_DAC_1];
			break;
		}
		case 2:{
			dac8568_0_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_2]);
			break;
		}
		case 3:{
			dac8568_0_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_3]);
			break;
		}
		case 4:{
			dac8568_0_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_4]);
			break;
		}
		case 5:{
			dac8568_0_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_5]);
			break;
		}
		case 6:{			
			dac8568_0_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_6]);
			break;
		}
		case 7:{
			dac8568_0_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_7]);
			break;
		}
		case 8:{
			dac8568_1_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_8]);
			break;
		}
		case 9:{
			dac8568_1_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_9]);
			break;
		}
		case 10:{
			dac8568_1_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_10]);
			break;
		}
		case 11:{
			dac8568_1_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_11]);
			break;
		}
		case 12:{
			dac8568_1_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_12]);
			break;
		}
		case 13:{
			dac8568_1_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_13]);
			break;
		}
		case 14:{
			dac8568_1_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_14]);
			break;
		}
		case 15:{		
			dac8568_1_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_15]);
			break;
		}
		case 16:{
			dac8568_2_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_16]);
			break;
		}
		case 17:{	
			dac8568_2_WriteDacRegister(0x5, (uint16_t)NVRAM0[EM_DAC_17]);
			break;
		}
		case 18:{
			dac8568_2_WriteDacRegister(0x3, (uint16_t)NVRAM0[EM_DAC_18]);
			break;
		}
		case 19:{
			dac8568_2_WriteDacRegister(0x1, (uint16_t)NVRAM0[EM_DAC_19]);
			break;
		}
		case 20:{
			dac8568_2_WriteDacRegister(0x6, (uint16_t)NVRAM0[EM_DAC_20]);
			break;
		}
		case 21:{
			dac8568_2_WriteDacRegister(0x4, (uint16_t)NVRAM0[EM_DAC_21]);
			break;
		}
		case 22:{
			dac8568_2_WriteDacRegister(0x2, (uint16_t)NVRAM0[EM_DAC_22]);
			break;
		}
		case 23:{
			dac8568_2_WriteDacRegister(0x0, (uint16_t)NVRAM0[EM_DAC_23]);
			break;
		}
		case 24:{
			dac8568_3_WriteDacRegister(0x7, (uint16_t)NVRAM0[EM_DAC_24]);
			break;
		}
		default:break;
	}
}
void initChipDac(void){//初始化DAC
	dac8568_0_Init();
	dac8568_1_Init();
	dac8568_2_Init();
	dac8568_3_Init();
	DAC0 = 0x0;
    DAC1 = 0x0;
	forceRefreshDac();
}




