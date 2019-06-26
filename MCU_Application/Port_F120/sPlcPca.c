#include "sPlcPca.h"
/*****************************************************************************/
void sPlcPcaInit(void){//计时器阵列初始化
#if CONFIG_SPLC_USING_PCA == 1
	uint8_t SFRPAGE_save = SFRPAGE;// Save current SFR Page
	SFRPAGE = PCA0_PAGE;
    PCA0MD    = 0x08;// Use SYSCLK as time base;
    PCA0CPM0  = 0xC2;
    PCA0CPM1  = 0xC2;
    PCA0CPM2  = 0xC2;
    PCA0CPH0  = 0x80;
    PCA0CPH1  = 0x80;
    PCA0CPH2  = 0x80;
	PCA0CN    = 0x40;
	SFRPAGE = SFRPAGE_save;
#endif
}
void sPlcAimInit(void){//指示光初始化
	NVRAM0[SPREG_AIM0_BRIGHTNESS] = 0;
	NVRAM0[SPREG_AIM1_BRIGHTNESS] = 0;
	RES(SPCOIL_AIM0_ENABLE);
	RES(SPCOIL_AIM1_ENABLE);
}
void sPlcAimLoop(void){//
	if(LD(SPCOIL_AIM0_ENABLE)){
		if(NVRAM0[SPREG_AIM0_BRIGHTNESS] != NVRAM1[SPREG_AIM0_BRIGHTNESS]){
			PCA0CP0 = 0xFFFF - (uint16_t)NVRAM0[SPREG_AIM0_BRIGHTNESS];
			NVRAM1[SPREG_AIM0_BRIGHTNESS] = NVRAM0[SPREG_AIM0_BRIGHTNESS];
			#if CONFIG_DEBUG_PCA == 1
			debugAim0 = true;
			#endif
		}
		
	}
	else{
		PCA0CP0 = 0xFFFF;
		#if CONFIG_DEBUG_PCA == 1
		debugAim0 = false;
		#endif
	}
	if(LD(SPCOIL_AIM1_ENABLE)){
		if(NVRAM0[SPREG_AIM1_BRIGHTNESS] != NVRAM1[SPREG_AIM1_BRIGHTNESS]){
			PCA0CP1 = 0xFFFF - (uint16_t)NVRAM0[SPREG_AIM1_BRIGHTNESS];
			NVRAM1[SPREG_AIM1_BRIGHTNESS] = NVRAM0[SPREG_AIM1_BRIGHTNESS];
			#if CONFIG_DEBUG_PCA == 1
			debugAim1 = true;
			#endif
		}
	}
	else{
		PCA0CP1 = 0xFFFF;
		#if CONFIG_DEBUG_PCA == 1
		debugAim1 = false;
		#endif
	}
}
/*****************************************************************************/
void sPlcBeemInit(void){//蜂鸣器初始化
	NVRAM0[SPREG_BEEM_VOLUME] = 0;
	NVRAM0[SPREG_BEEM_MODE] = 0;
	NVRAM0[SPREG_BEEM_COUNTER] = 0;
	RES(SPCOIL_BEEM_ENABLE);
}
void sPlcBeemLoop(void){//蜂鸣器轮询
	switch(NVRAM0[SPREG_BEEM_MODE]){
		case BEEM_MODE_0:{//模式0 CW
			if(LD(SPCOIL_BEEM_ENABLE)){
				if(NVRAM0[SPREG_BEEM_VOLUME] != NVRAM1[SPREG_BEEM_VOLUME]){
					PCA0CP2 = 0xFFFF - (uint16_t)NVRAM0[SPREG_BEEM_VOLUME];
					NVRAM1[SPREG_BEEM_VOLUME] = NVRAM0[SPREG_BEEM_VOLUME];
				}
			}
			else{
				PCA0CP2 = 0xFFFF;
			}
			break;
		}
		case BEEM_MODE_1:{//模式1 滴滴两下一停
			if(LD(SPCOIL_BEEM_ENABLE)){
				if(NVRAM0[SPREG_BEEM_COUNTER] == 1){//1
					PCA0CP2 = 0xFFFF - (uint16_t)NVRAM0[SPREG_BEEM_VOLUME];	
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] == 100){//0
					PCA0CP2 = 0xFFFF;
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] == 200){//1
					PCA0CP2 = 0xFFFF - (uint16_t)NVRAM0[SPREG_BEEM_VOLUME];	
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] == 300){//0
					PCA0CP2 = 0xFFFF;
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] >= 1500){//停1秒
					NVRAM0[SPREG_BEEM_COUNTER] = 0;
				}
				NVRAM0[SPREG_BEEM_COUNTER] ++;
			}
			else{
				PCA0CP2 = 0xFFFF;
				NVRAM0[SPREG_BEEM_COUNTER] = 0;
			}
			break;
		}
		case BEEM_MODE_2:{//模式2 长间隔
			if(NVRAM0[SPREG_BEEM_COUNTER] == 1){//1
				PCA0CP2 = 0xFFFF - (uint16_t)NVRAM0[SPREG_BEEM_VOLUME];
			}
			else if(NVRAM0[SPREG_BEEM_COUNTER] == 500){//0
				PCA0CP2 = 0xFFFF;
			}
			else if(NVRAM0[SPREG_BEEM_COUNTER] == 1000){
				NVRAM0[SPREG_BEEM_COUNTER] = 0;
			}
			NVRAM0[SPREG_BEEM_COUNTER] ++;
			break;
		}
		default:break;
	}
}
void testBenchBeem(uint8_t volume, uint8_t mode){//蜂鸣器测试
	uint16_t dc;
	if(volume > 100)
		volume = 100;
	dc = volume * 65534 / 100;
	NVRAM0[SPREG_BEEM_VOLUME] = dc;
	NVRAM0[SPREG_BEEM_MODE] = mode;
	SET(SPCOIL_BEEM_ENABLE);
}
void testBenchAim(uint8_t port, uint8_t brightness){//指示光测试
	uint16_t dc;
	if(brightness > 100)
		brightness = 100;
	dc = brightness * 65535 / 100;
	if(port == 0){
		NVRAM0[SPREG_AIM0_BRIGHTNESS] = 0xFFFF - dc;
	}
	if(port == 1){
		NVRAM0[SPREG_AIM1_BRIGHTNESS] = 0xFFFF - dc;
	}
}





