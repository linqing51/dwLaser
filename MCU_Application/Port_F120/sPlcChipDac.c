#include "sPlcChipDac.h"
/*****************************************************************************/
#if CONFIG_SPLC_USING_DAC == 1
void initChipDac(void){//DAC初始化
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE	    
	SFRPAGE   = DAC0_PAGE;
    DAC0CN    = 0x80;
	
	SFRPAGE   = DAC1_PAGE;
    DAC1CN    = 0x80;
	SFRPAGE = SFRPAGE_SAVE;
}
void refreshChipDac(void){//刷新DAC
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE	
	//刷新DAC0
	SFRPAGE = DAC0_PAGE;
	NVRAM0[SPREG_DAC_0] &= 0xFFF;
	if(NVRAM0[SPREG_DAC_0] != DAC0){	
		DAC0 = NVRAM0[SPREG_DAC_0];	
		NVRAM1[SPREG_DAC_0] = NVRAM0[SPREG_DAC_0];
	}
	SFRPAGE = SFRPAGE_SAVE;
	//刷新DAC1
	NVRAM0[SPREG_DAC_1] &= 0xFFF;
	SFRPAGE = DAC1_PAGE;
	if(NVRAM0[SPREG_DAC_1] != DAC1){
		DAC1 = NVRAM0[SPREG_DAC_1];	
		NVRAM1[SPREG_DAC_1] = NVRAM0[SPREG_DAC_1];
	}
	SFRPAGE = SFRPAGE_SAVE;
}

void UPDAC0(void) reentrant{//立即更新DAC0
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;
	SFRPAGE = DAC0_PAGE;
	NVRAM0[SPREG_DAC_0] &= 0xFFF;
	if(DAC0 != NVRAM0[SPREG_DAC_0]){
		DAC0 = NVRAM0[SPREG_DAC_0];
		NVRAM1[SPREG_DAC_0] = NVRAM0[SPREG_DAC_0];
	}
	SFRPAGE = SFRPAGE_SAVE;	
}
void UPDAC1(void) reentrant{//立即更新DAC1
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;
	SFRPAGE = DAC1_PAGE;
	NVRAM0[SPREG_DAC_1] &= 0xFFF;
	if(DAC1 != NVRAM0[SPREG_DAC_1]){
		DAC1 = NVRAM0[SPREG_DAC_1];
		NVRAM1[SPREG_DAC_1] = NVRAM0[SPREG_DAC_1];
	}
	SFRPAGE = SFRPAGE_SAVE;
}
#endif








