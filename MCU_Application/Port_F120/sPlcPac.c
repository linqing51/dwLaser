#include "sPlcPca.h"
/*****************************************************************************/
void sPlcPcaInit(void){//计时器阵列初始化
	uint8_t SFRPAGE_save = SFRPAGE;// Save current SFR Page
	SFRPAGE = PCA0_PAGE;
	PCA0CN = 0;
	PCA0MD = 0;
	PCA0MD |= (1 << 3);//System clock
	PCA0CPM0 = 0;
	PCA0CPM0 |= (1 << 1);//Pulse Width Modulation Mode Enable.
	PCA0CPM0 |= (1 << 7);//16-bit PWM selected.
	PCA0CPM1 = 0;
	PCA0CPM1 |= (1 << 1);//Pulse Width Modulation Mode Enable.
	PCA0CPM1 |= (1 << 7);//16-bit PWM selected.
	PCA0CPM2 = 0;
	PCA0CPM2 |= (1 << 1);//Pulse Width Modulation Mode Enable.
	PCA0CPM2 |= (1 << 7);//16-bit PWM selected.
	//CEX3 -> LPWM0
	//PCA0CPM3 = 0;
	//PCA0CPM3 |= (1 << 1);//Pulse Width Modulation Mode Enable.
	//PCA0CPM3 |= (1 << 7);//16-bit PWM selected.
	//CEX4 -> LPWM1
 	PCA0CP0 = 0xFFFF;
	PCA0CP1 = 0xFFFF;
	PCA0CP2 = 0xFFFF;
	PCA0CN |= (1 << 6);//Start PCA counter
	SFRPAGE = SFRPAGE_save;
}
void sPlcPcaRefresh(void){//PCA PWM刷新
	if(NVRAM0[SPREG_HPWM0_DUTYRATIO] != NVRAM1[SPREG_HPWM0_DUTYRATIO]){
		PCA0CP0 = 0xFFFF - NVRAM0[SPREG_HPWM0_DUTYRATIO];
	}
	if(NVRAM0[SPREG_HPWM1_DUTYRATIO] != NVRAM1[SPREG_HPWM1_DUTYRATIO]){
		PCA0CP1 = 0xFFFF - NVRAM0[SPREG_HPWM1_DUTYRATIO];
	}
	if(NVRAM0[SPREG_HPWM2_DUTYRATIO] != NVRAM1[SPREG_HPWM2_DUTYRATIO]){
		PCA0CP0 = 0xFFFF - NVRAM0[SPREG_HPWM2_DUTYRATIO];
	}
}









