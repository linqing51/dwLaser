#include "sPlcChipDac.h"
/*****************************************************************************/
void initChipDac(void){//DAC��ʼ��
#if CONFIG_SPLC_USING_DAC == 1
	uint8_t SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE	
	SFRPAGE = DAC0_PAGE;
    DAC0CN = 0x80;
	DAC0 = 0x0;
	SFRPAGE = DAC1_PAGE;
    DAC1CN = 0x80;
	DAC0 = 0x0;
	SFRPAGE = CONFIG_PAGE;
	P4 &= 0xFB;//P4.2 = 0;//��DAC���
	SFRPAGE = SFRPAGE_SAVE;
#endif
}
void refreshChipDac(void){//ˢ��DAC
	uint8_t SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE	
	//ˢ��DAC0
	SFRPAGE = DAC0_PAGE;
	NVRAM0[SPREG_DAC_0] &= 0xFFF;
	if(NVRAM0[SPREG_DAC_0] != DAC0){	
		DAC0 = NVRAM0[SPREG_DAC_0];	
		NVRAM1[SPREG_DAC_0] = NVRAM0[SPREG_DAC_0];
	}
	SFRPAGE = SFRPAGE_SAVE;
	//ˢ��DAC1
	NVRAM0[SPREG_DAC_1] &= 0xFFF;
	SFRPAGE = DAC1_PAGE;
	if(NVRAM0[SPREG_DAC_1] != DAC1){
		DAC1 = NVRAM0[SPREG_DAC_1];	
		NVRAM1[SPREG_DAC_1] = NVRAM0[SPREG_DAC_1];
	}
	SFRPAGE = SFRPAGE_SAVE;
}

void UPDAC0(void) reentrant{//��������DAC0
	uint8_t SFRPAGE_SAVE = SFRPAGE;
	SFRPAGE = DAC0_PAGE;
	NVRAM0[SPREG_DAC_0] &= 0xFFF;
	if(DAC0 != NVRAM0[SPREG_DAC_0]){
		DAC0 = NVRAM0[SPREG_DAC_0];
		NVRAM1[SPREG_DAC_0] = NVRAM0[SPREG_DAC_0];
	}
	SFRPAGE = SFRPAGE_SAVE;	
}
void UPDAC1(void) reentrant{//��������DAC1
	uint8_t SFRPAGE_SAVE = SFRPAGE;
	SFRPAGE = DAC1_PAGE;
	NVRAM0[SPREG_DAC_1] &= 0xFFF;
	if(DAC1 != NVRAM0[SPREG_DAC_1]){
		DAC1 = NVRAM0[SPREG_DAC_1];
		NVRAM1[SPREG_DAC_1] = NVRAM0[SPREG_DAC_1];
	}
	SFRPAGE = SFRPAGE_SAVE;
}








