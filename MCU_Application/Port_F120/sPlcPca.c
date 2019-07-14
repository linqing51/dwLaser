#include "sPlcPca.h"
#define CONFIG_BEEM_FREQ_0				0xF6//正常频率
#define CONFIG_BEEM_FREQ_1				0xFC
/*****************************************************************************/
//static void beemVolume[10] = {0x0, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90};
static void sPlcBeemEnable(uint8_t enable){//蜂鸣器关闭开启
	uint8_t SFRPAGE_save = SFRPAGE;// Save current SFR Page
	SFRPAGE = PCA0_PAGE;
	if(enable){
		PCA0CPM2 = 0x42;
	}
	else{
		PCA0CPM2 = 0x0;
	}
	SFRPAGE = SFRPAGE_save;
}
static void sPlcAimEnable(uint8_t ch, uint8_t enable){//指示激光关闭开启
	uint8_t SFRPAGE_save = SFRPAGE;// Save current SFR Page
	SFRPAGE = PCA0_PAGE;
	switch(ch){
		case 0:{
			if(enable){
				PCA0CPM0 = 0x42;
			}
			else{
				PCA0CPM0 = 0x0;
			}
			break;
		}
		case 1:{
			if(enable){
				PCA0CPM1 = 0x42;
			}
			else{
				PCA0CPM1 = 0x0;
			}
			break;
		}
		default:break;
	}
	SFRPAGE = SFRPAGE_save;
}
void sPlcPcaInit(void){//计时器阵列初始化
#if CONFIG_SPLC_USING_PCA == 1
	uint8_t SFRPAGE_save = SFRPAGE;// Save current SFR Page
	SFRPAGE = TIMER01_PAGE;
	//T0 CLK = SYSCLK /48
	TH0 = CONFIG_BEEM_FREQ_0;         
	TL0 = TH0;
	TMOD &= 0xF0;
	TMOD |= 0x02;// Timer0 in 8-bit reload mode
	TCON |= 0x10;// Timer0 ON
	SFRPAGE = PCA0_PAGE;
    PCA0MD    = 0x04;// Use Timer 0 overflow
	PCA0CPM0  = 0x42;//8BIT PWM
    PCA0CPM1  = 0x42;//8BIT PWM
    PCA0CPM2  = 0x00;//8BIT PWM
    PCA0CPH0  = 0xFF;
    PCA0CPH1  = 0xFF;
    PCA0CPH2  = 0xFF;
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
	uint8_t temp;
	if(LD(SPCOIL_AIM0_ENABLE)){
		if(NVRAM0[SPREG_AIM0_BRIGHTNESS] != NVRAM1[SPREG_AIM0_BRIGHTNESS]){
			if(NVRAM0[SPREG_AIM0_BRIGHTNESS] > 0xFF){
				temp = 0xFF;
			}
			else{
				temp = NVRAM0[SPREG_AIM0_BRIGHTNESS];
			}
			sPlcAimEnable(0, true);//指示激光关闭开启
			PCA0CPH0 = 0xFF - temp;
		}
	}
	else{
		sPlcAimEnable(0, false);//指示激光关闭开启
		PCA0CPH0  = 0xFF;
	}
	if(LD(SPCOIL_AIM1_ENABLE)){
		if(NVRAM0[SPREG_AIM1_BRIGHTNESS] != NVRAM1[SPREG_AIM1_BRIGHTNESS]){
			if(NVRAM0[SPREG_AIM1_BRIGHTNESS] > 0xFF){
				temp = 0xFF;
			}
			else{
				temp = NVRAM0[SPREG_AIM1_BRIGHTNESS];
			}
			sPlcAimEnable(1, true);//指示激光关闭开启
			PCA0CPH1 = 0xFF - temp;
		}
		else{	
			sPlcAimEnable(1, false);//指示激光关闭开启
			PCA0CPH1  = 0xFF;
		}
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
	uint8_t temp;
	uint8_t SFRPAGE_save = SFRPAGE;// Save current SFR Page
	
	if(NVRAM0[SPREG_BEEM_FREQ] != NVRAM1[SPREG_BEEM_FREQ]){//检测到频率设定改变
		TH0 = NVRAM0[SPREG_BEEM_FREQ];
	}
	SFRPAGE = PCA0_PAGE;
	switch(NVRAM0[SPREG_BEEM_MODE]){
		case BEEM_MODE_0:{//模式0 CW
			if(LD(SPCOIL_BEEM_ENABLE)){	
				if(NVRAM0[SPREG_BEEM_VOLUME] <= 9){
					temp = NVRAM0[SPREG_BEEM_VOLUME];
				}
				else{
					temp = 9;
				}
				sPlcBeemEnable(true);
				//PCA0CPH2 = 0xFF - beemVolume[temp];		
				PCA0CPH2 = 0xF0;
			}
			else{
				sPlcBeemEnable(false);
				PCA0CPH2 = 0xFF;
			}
			break;
		}
		case BEEM_MODE_1:{//模式1 滴滴两下一停
			if(LD(SPCOIL_BEEM_ENABLE)){
				if(NVRAM0[SPREG_BEEM_COUNTER] == 0x01){//1
					sPlcBeemEnable(true);		
					PCA0CPH2 = 0xF0;
					//PCA0CP2 = 0xFFFF - (uint16_t)NVRAM0[SPREG_BEEM_VOLUME];	
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] == 100){//0
					sPlcBeemEnable(false);		
					PCA0CPH2 = 0xFF;
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] == 200){//1
					sPlcBeemEnable(true);		
					PCA0CPH2 = 0xF0;
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] == 300){//0
					sPlcBeemEnable(false);		
					PCA0CPH2 = 0xFF;
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] >= 1500){//停1秒
					NVRAM0[SPREG_BEEM_COUNTER] = 0;
				}
				NVRAM0[SPREG_BEEM_COUNTER] ++;
			}
			else{
				sPlcBeemEnable(false);		
				PCA0CPH2 = 0xFF;
				NVRAM0[SPREG_BEEM_COUNTER] = 0;
			}
			break;
		}
		case BEEM_MODE_2:{//模式2 长间隔
			if(LD(SPCOIL_BEEM_ENABLE)){
				if(NVRAM0[SPREG_BEEM_COUNTER] == 1){//1
					sPlcBeemEnable(true);		
					PCA0CPH2 = 0xF0;
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] == 500){//0
					sPlcBeemEnable(false);		
					PCA0CPH2 = 0xFF;
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] == 1000){
					NVRAM0[SPREG_BEEM_COUNTER] = 0;
				}
				NVRAM0[SPREG_BEEM_COUNTER] ++;
			}
			else{
				sPlcBeemEnable(false);		
				PCA0CPH2 = 0xFF;
				NVRAM0[SPREG_BEEM_COUNTER] = 0;
			}
			break;
		}
		default:break;
	}
	SFRPAGE = SFRPAGE_save;
}
void testBenchBeem(uint8_t volume, uint8_t mode){//蜂鸣器测试
	uint16_t dc;
	if(volume > 100)
		volume = 100;
	dc = volume * 65534 / 100;
	NVRAM0[SPREG_BEEM_COUNTER] = 1;
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





