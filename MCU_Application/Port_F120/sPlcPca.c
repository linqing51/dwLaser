#include "sPlcPca.h"
/*****************************************************************************/
uint8_t data BeemFreq;//������Ƶ��
uint8_t data BeemMode;//������ģʽ
uint8_t data BeemDuty;//������ռ�ձ�
uint16_t data BeemCounter;
int8_t data BeemEnable;
/*****************************************************************************/
void sPlcPcaInit(void){//��ʱ�����г�ʼ��
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
void sPlcAimInit(void){//ָʾ���ʼ��
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
void sPlcBeemLoop(void){//��������ѯ
	uint8_t SFRPAGE_save = SFRPAGE;// Save current SFR Page
	if(BeemEnable){
		SFRPAGE = TIMER01_PAGE;
		if(TH0 != BeemDuty){//��Ƶ��
			TH0 = BeemDuty;
			TL0 = BeemDuty;
		}
		SFRPAGE = PCA0_PAGE;
		switch(BeemMode){//��ģʽ
			case BEEM_MODE_0:{
				if(PCA0CPM2 != 0x42){
					PCA0CPM2 = 0x42;
				}
				if(PCA0CPH2 != BeemDuty){
					PCA0CPH2 = BeemDuty;
				}
				break;
			}
			case BEEM_MODE_1:{//ģʽ1 ����ͬ��
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
			case BEEM_MODE_2:{//ģʽ2 �ε�����һͣ
				if(BeemCounter == 0){//1
					PCA0CPM2 = 0x42;		
					PCA0CPH2 = BeemDuty;
				}
				else if(BeemCounter == 300){//0
					PCA0CPM2 = 0x00;			
					PCA0CPH2 = 0xFF;
				}
				else if(BeemCounter == 600){//1
					PCA0CPM2 = 0x42;		
					PCA0CPH2 = BeemDuty;
				}
				else if(BeemCounter == 900){//0
					PCA0CPM2 = 0x00;			
					PCA0CPH2 = 0xFF;
				}
				else if(BeemCounter == 1900){//ͣ1��
					BeemCounter = 0xffff;
				}
				BeemCounter ++;
				break;
			}
			case BEEM_MODE_3:{//ģʽ3 �����
				if(BeemCounter == 0){//1
					PCA0CPM2 = 0x42;		
					PCA0CPH2 = BeemDuty;
				}
				else if(BeemCounter == 500){//0
					PCA0CPM2 = 0x00;			
					PCA0CPH2 = 0xFF;
				}
				else if(BeemCounter == 1500){
					BeemCounter = 0xffff;
				}
				break;
			}
			default:break;
		}
	}
	else{
		PCA0CPM2 = 0x00;			
		PCA0CPH2 = 0xFF;
		BeemCounter = 0;
	}
	SFRPAGE = SFRPAGE_save;
}





