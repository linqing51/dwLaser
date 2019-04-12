#include "sPlcChipDac.h"
/*****************************************************************************/
#if CONFIG_SPLC_USING_DAC == 1
void initChipDac(void){//DAC��ʼ��
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE	    
	SFRPAGE   = DAC0_PAGE;
    DAC0CN    = 0x80;
	
	SFRPAGE   = DAC1_PAGE;
    DAC1CN    = 0x80;
	SFRPAGE = SFRPAGE_SAVE;
}
void refreshChipDac(void){//ˢ��DAC
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE	
	//ˢ��DAC0
	SFRPAGE   = DAC0_PAGE;
	if(NVRAM0[SPREG_DAC_0] != DAC0){	
		DAC0 = NVRAM0[SPREG_DAC_0];	
		NVRAM1[SPREG_DAC_0] = NVRAM0[SPREG_DAC_0];
	}
	SFRPAGE = SFRPAGE_SAVE;
	//ˢ��DAC1
	SFRPAGE   = DAC1_PAGE;
	if(NVRAM0[SPREG_DAC_1] != DAC1){
		DAC1 = NVRAM0[SPREG_DAC_1];	
		NVRAM1[SPREG_DAC_1] = NVRAM0[SPREG_DAC_1];
	}
	SFRPAGE = SFRPAGE_SAVE;
}

void UPDAC0(void){//��������DAC0
	DAC0 = NVRAM0[SPREG_DAC_0];	
}
void UPDAC1(void){//��������DAC1
	DAC1 = NVRAM0[SPREG_DAC_1];	
}
#endif








