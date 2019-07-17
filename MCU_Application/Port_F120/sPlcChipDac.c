#include "sPlcChipDac.h"
/*****************************************************************************/
void initChipDac(void){//DAC初始化
#if CONFIG_SPLC_USING_DAC == 1
	uint8_t SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE	
	SFRPAGE = DAC0_PAGE;
    DAC0CN = 0x80;
	DAC0 = 0x0;
	SFRPAGE = DAC1_PAGE;
    DAC1CN = 0x80;
	DAC0 = 0x0;
	SFRPAGE = CONFIG_PAGE;
	P4 &= 0xFB;//P4.2 = 0;//打开DAC输出
	SFRPAGE = SFRPAGE_SAVE;
#endif
}
void UPDAC0(void) reentrant{//立即从SPREG_DAC_0中更新DAC0
	uint8_t SFRPAGE_SAVE = SFRPAGE;
	SFRPAGE = DAC0_PAGE;
	DAC0 = NVRAM0[SPREG_DAC_0];
	SFRPAGE = SFRPAGE_SAVE;	
}
void UPDAC1(void) reentrant{//立即从SPREG_DAC_1更新DAC1
	uint8_t SFRPAGE_SAVE = SFRPAGE;
	SFRPAGE = DAC1_PAGE;
	
DAC1 = NVRAM0[SPREG_DAC_1];
	SFRPAGE = SFRPAGE_SAVE;
}
void CLDAC(void) reentrant{//立即清空DAC0和DAC1
	uint8_t SFRPAGE_SAVE = SFRPAGE;
	SFRPAGE = DAC1_PAGE;
	DAC0 = 0x0;
	DAC1 = 0x0;
	SFRPAGE = SFRPAGE_SAVE;
}








