#include "sPlcPca.h"
/*****************************************************************************/
static uint8_t setBeemVolume(void){//设置蜂鸣器音量
	switch(NVRAM0[SPREG_BEEM_VOLUME]){
		case 0:{
			return BEEM_VOLUME_0;
			break;
		}
		case 1:{
			return BEEM_VOLUME_1;
			break;
		}
		case 2:{
			return BEEM_VOLUME_2;
			break;
		}
		case 3:{
			return BEEM_VOLUME_3;
			break;
		}
		case 4:{
			return BEEM_VOLUME_4;
			break;
		}
		case 5:{
			return BEEM_VOLUME_5;
			break;
		}
		case 6:{
			return BEEM_VOLUME_6;
			break;
		}
		case 7:{
			return BEEM_VOLUME_7;
			break;
		}
		case 8:{
			return BEEM_VOLUME_8;
			break;
		}
		case 9:{
			return BEEM_VOLUME_9;
			break;
		}
		default:{
			return 0;
		}break;
	}
}	
void sPlcPcaInit(void){//计时器阵列初始化
#if CONFIG_SPLC_USING_PCA == 1
	uint8_t SFRPAGE_save = SFRPAGE;// Save current SFR Page
	SFRPAGE = TIMER01_PAGE;
	//T0 CLK = SYSCLK /48
	TH0 = BEEM_FREQ_0;         
	TL0 = TH0;
	TMOD &= 0xF0;
	TMOD |= 0x02;// Timer0 in 8-bit reload mode
	TCON |= 0x10;// Timer0 ON
	SFRPAGE = PCA0_PAGE;
    PCA0MD    = 0x04;// Use Timer 0 overflow
	PCA0CPM0  = 0x00;//8BIT PWM
    PCA0CPM1  = 0x00;//8BIT PWM
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
	uint8_t SFRPAGE_save = SFRPAGE;// Save current SFR Page
	SFRPAGE = PCA0_PAGE;
	if(LD(SPCOIL_AIM0_ENABLE)){
		PCA0CPM1 = 0x42;
		PCA0CPH1 = (0xFF - (NVRAM0[SPREG_AIM0_BRIGHTNESS] & 0x00FF));
	}
	else{
		PCA0CPM1 = 0x00;
		PCA0CPH1  = 0xFF;
	}
	if(LD(SPCOIL_AIM1_ENABLE)){
		PCA0CPM0 = 0x42;
		PCA0CPH0 = (0xFF - (NVRAM0[SPREG_AIM0_BRIGHTNESS] & 0x00FF));
	}
	else{	
		PCA0CPM0 = 0x00;
		PCA0CPH0  = 0xFF;
	}
	SFRPAGE = SFRPAGE_save;
}
/*****************************************************************************/
void sPlcBeemInit(void){//蜂鸣器初始化
	NVRAM0[SPREG_BEEM_VOLUME] = 0;
	NVRAM0[SPREG_BEEM_MODE] = 0;
	NVRAM0[SPREG_BEEM_COUNTER] = 0;
	RES(SPCOIL_BEEM_ENABLE);
}
uint8_t data BeemFreq;//蜂鸣器频率
uint8_t data BeemMode;//蜂鸣器模式
uint8_t data BeemVolume;//蜂鸣器音量
uint16_t data BeemCounter;
bit BeemEnable;
void sPlcBeemLoop(void){//蜂鸣器轮询
	uint8_t SFRPAGE_save = SFRPAGE;// Save current SFR Page
	SFRPAGE = PCA0_PAGE;
	if(BeemEnable){
		switch(BeemMode){
			case BEEM_MODE_0:{
				if(BeemCounter == 0x0){	
					PCA0CPM2 = 0x42;
					PCA0CPH2 = BeemVolume;
					BeemCounter ++;
				}
				break;
			}
			case BEEM_MODE_1:{
				if(LD(SPCOIL_LASER_EMITING)){
					PCA0CPM2 = 0x42;		
					PCA0CPH2 = BeemVolume;
				}
					else{
						PCA0CPM2 = 0x00;
						PCA0CPH2 = 0xFF;
					}
				}
				else{
					PCA0CPM2 = 0x00;
					PCA0CPH2 = 0xFF;
					NVRAM0[SPREG_BEEM_COUNTER] = 0;
				}
			break;	
		}
		else{
			PCA0CPM2 = 0x00;
			PCA0CPH2 = 0xFF;
			BeemCounter = 0;	
		}
		
		case BEEM_MODE_1:{//模式1 声光同步
			if(BeemEnable){
				if(LD(SPCOIL_LASER_EMITING)){
					PCA0CPM2 = 0x42;		
					PCA0CPH2 = BeemVolume;
				}
				else{
					PCA0CPM2 = 0x00;
					PCA0CPH2 = 0xFF;
				}
			}
			else{
				PCA0CPM2 = 0x00;
				PCA0CPH2 = 0xFF;
				NVRAM0[SPREG_BEEM_COUNTER] = 0;
			}
			break;
		}
		case BEEM_MODE_2:{//模式2 滴滴两下一停
			if(LD(SPCOIL_BEEM_ENABLE)){
				if(NVRAM0[SPREG_BEEM_COUNTER] == 0){//1
					PCA0CPM2 = 0x42;		
					PCA0CPH2 = setBeemVolume();
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] == 100){//0
					PCA0CPM2 = 0x00;			
					PCA0CPH2 = 0xFF;
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] == 200){//1
					PCA0CPM2 = 0x42;		
					PCA0CPH2 = setBeemVolume();
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] == 300){//0
					PCA0CPM2 = 0x00;			
					PCA0CPH2 = 0xFF;
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] >= 1500){//停1秒
					NVRAM0[SPREG_BEEM_COUNTER] = 0;
				}
				NVRAM0[SPREG_BEEM_COUNTER] ++;
			}
			else{
				PCA0CPM2 = 0x00;			
				PCA0CPH2 = 0xFF;
				NVRAM0[SPREG_BEEM_COUNTER] = 0;
			}
			break;
		}
		case BEEM_MODE_3:{//模式3 长间隔
			if(LD(SPCOIL_BEEM_ENABLE)){
				if(NVRAM0[SPREG_BEEM_COUNTER] == 0){//1
					PCA0CPM2 = 0x42;		
					PCA0CPH2 = setBeemVolume();
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] == 500){//0
					PCA0CPM2 = 0x00;			
					PCA0CPH2 = 0xFF;
				}
				else if(NVRAM0[SPREG_BEEM_COUNTER] == 1000){
					NVRAM0[SPREG_BEEM_COUNTER] = 0;
				}
				NVRAM0[SPREG_BEEM_COUNTER] ++;
			}
			else{
				PCA0CPM2 = 0x00;			
				PCA0CPH2 = 0xFF;
				NVRAM0[SPREG_BEEM_COUNTER] = 0;
			}
			break;
		}
		default:break;
	}
	SFRPAGE = SFRPAGE_save;
}





