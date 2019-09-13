#include "sPlcPca.h"
/*****************************************************************************/
uint8_t data BeemFreq;//蜂鸣器频率
uint8_t data BeemMode;//蜂鸣器模式
uint8_t data BeemDuty;//蜂鸣器占空比
uint16_t data BeemCounter;
int8_t data BeemEnable;
uint8_t data AimDuty0, AimDuty1;
int8_t data AimEnable0, AimEnable1;
/*****************************************************************************/
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
	AimDuty0 = 0;
	AimDuty1 = 0;
	AimEnable0 = false;
	AimEnable0 = false;
}
void sPlcAimLoop(void){//
	data uint8_t SFRPAGE_save = SFRPAGE;// Save current SFR Page
	SFRPAGE = PCA0_PAGE;
	if(AimEnable0 && (AimDuty0 > 0)){
		PCA0CPM1 = 0x42;
		PCA0CPH1 = (0xFF - AimDuty0);
	}
	else{
		PCA0CPM1 = 0x00;
		PCA0CPH1  = 0xFF;
	}
	if(AimEnable1 && (AimDuty0 > 0)){
		PCA0CPM0 = 0x42;
		PCA0CPH0 = (0xFF - AimDuty1);
	}
	else{	
		PCA0CPM0 = 0x00;
		PCA0CPH0  = 0xFF;
	}
	SFRPAGE = SFRPAGE_save;
}
/*****************************************************************************/
void sPlcBeemLoop(void){//蜂鸣器轮询
	data uint8_t SFRPAGE_save = SFRPAGE;// Save current SFR Page
	if(BeemEnable){
		SFRPAGE = TIMER01_PAGE;
		if(TH0 != BeemFreq){//调频率
			TH0 = BeemFreq;
			TL0 = BeemFreq;
		}
		SFRPAGE = PCA0_PAGE;
		switch(BeemMode){//调模式
			case BEEM_MODE_0:{
				if(PCA0CPM2 != 0x42){
					PCA0CPM2 = 0x42;
				}
				if(PCA0CPH2 != BeemDuty){
					PCA0CPH2 = BeemDuty;
				}
				break;
			}
			case BEEM_MODE_1:{//模式1 声光同步
				if(P2 & 0xC0){//LT3763 ON
					if(PCA0CPM2 != 0x42){
						PCA0CPM2 = 0x42;
					}
					if(PCA0CPH2 != BeemDuty){
						PCA0CPH2 = BeemDuty;
					}
				}
				else{
					PCA0CPM2 = 0x00;
					PCA0CPH2 = 0xFF;
				}
				break;
			}
			case BEEM_MODE_2:{//模式2 长间隔 激光发射音		
				if(BeemCounter == 0){//1
					PCA0CPM2 = 0x42;		
					PCA0CPH2 = BeemDuty;
				}
				else if(BeemCounter == 10){//0
					PCA0CPM2 = 0x00;			
					PCA0CPH2 = 0xFF;
				}
				else if(BeemCounter == 59){
					BeemCounter = 0xffff;
				}
				BeemCounter ++;
				break;
			}
			case BEEM_MODE_3:{//模式3 滴滴两下一停 报警音		
				if(BeemCounter == 0){//1
					PCA0CPM2 = 0x42;		
					PCA0CPH2 = BeemDuty;
				}
				else if(BeemCounter == 5){//0
					PCA0CPM2 = 0x00;			
					PCA0CPH2 = 0xFF;
				}
				else if(BeemCounter == 10){//1
					PCA0CPM2 = 0x42;		
					PCA0CPH2 = BeemDuty;
				}
				else if(BeemCounter == 15){//0
					PCA0CPM2 = 0x00;			
					PCA0CPH2 = 0xFF;
				}
				else if(BeemCounter == 25){//停1秒
					BeemCounter = 0xffff;
				}
				BeemCounter ++;
				break;
			}
			default:break;
		}
	}
	else{
		SFRPAGE = PCA0_PAGE;
		PCA0CPM2 = 0x00;			
		PCA0CPH2 = 0xFF;
		BeemCounter = 0;
	}
	SFRPAGE = SFRPAGE_save;
}





