#include "sPlcPca.h"
/*****************************************************************************/
#if CONFIG_SPLC_USING_PCA == 1
void sPlcPcaInit(void){//计时器阵列初始化
	xdata uint8_t SFRPAGE_save = SFRPAGE;// Save current SFR Page
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
	RES(SPCOIL_BEEM_ENABLE);
}
void sPlcBeemLoop(void){//蜂鸣器轮询
	switch(NVRAM0[SPREG_BEEM_MODE]){
		case BEEM_MODE_0:{//模式0 CW
			if(LD(SPCOIL_BEEM_ENABLE)){
				if(NVRAM0[SPREG_BEEM_VOLUME] != NVRAM1[SPREG_BEEM_VOLUME]){
					PCA0CP2 = 0xFFFF - (uint16_t)NVRAM0[SPREG_BEEM_VOLUME];
					NVRAM1[SPREG_BEEM_VOLUME] = NVRAM0[SPREG_BEEM_VOLUME];
					#if CONFIG_DEBUG_PCA == 1
					debugBeem = true;
					#endif
				}
			}
			else{
				PCA0CP2 = 0xFFFF;
				#if CONFIG_DEBUG_PCA == 1
				debugBeem = false;
				#endif
			}
			break;
		}
		case BEEM_MODE_1:{//模式1 短间隔
			if(NVRAM0[SPREG_BEEM_COUNTER] >= 50){
				if(PCA0CP2 == 0xFFFF){//BEEM OFF
					PCA0CP2 = 0xFFFF - (uint16_t)NVRAM0[SPREG_BEEM_VOLUME];			
					#if CONFIG_DEBUG_PCA == 1
					debugBeem = true;
					#endif
				}
				else{
					PCA0CP2 = 0xFFFF;
					#if CONFIG_DEBUG_PCA == 1
					debugBeem = false;
					#endif
				}
				NVRAM0[SPREG_BEEM_COUNTER] = 0;
			}
			break;
		}
		case BEEM_MODE_2:{//模式2 长间隔
			if(NVRAM0[SPREG_BEEM_COUNTER] >= 200){
				if(PCA0CP2 == 0xFFFF){//BEEM OFF
					PCA0CP2 = 0xFFFF - (uint16_t)NVRAM0[SPREG_BEEM_VOLUME];
					#if CONFIG_DEBUG_PCA == 1
					debugBeem = true;
					#endif
				}
				else{
					PCA0CP2 = 0xFFFF;
					#if CONFIG_DEBUG_PCA == 1
					debugBeem = true;
					#endif
				}
				NVRAM0[SPREG_BEEM_COUNTER] = 0;
			}
			break;
		}
		default:break;
	}
}
void testBenchBeem(uint8_t volume, uint8_t mode){//蜂鸣器测试
	xdata uint16_t dc;
	if(volume > 100)
		volume = 100;
	dc = volume * 65534 / 100;
	NVRAM0[SPREG_BEEM_VOLUME] = dc;
	NVRAM0[SPREG_BEEM_MODE] = mode;
	SET(SPCOIL_BEEM_ENABLE);
}
void testBenchAim(uint8_t port, uint8_t brightness){//指示光测试
	xdata uint16_t dc;
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

#endif





