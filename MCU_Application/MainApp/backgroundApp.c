#include "backgroundApp.h"
/*****************************************************************************/
#if CONFIG_USING_BACKGROUND_APP == 1
void defaultScheme(void){//��ǰѡ�񷽰��ָ�Ĭ��ֵ
	sprintf((char*)(&NVRAM0[EM_LASER_SCHEME_NAME]),"Hello dwLaser S%d",NVRAM0[DM_SCHEME_NUM]);
	NVRAM0[EM_LASER_SELECT]	= LASER_SELECT_BOTH;//ͨ��ѡ��
	NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_CW;//����ģʽ
	NVRAM0[EM_LASER_POWER_CH0] = 199;//ͨ��0����
	NVRAM0[EM_LASER_POWER_CH1] = 59;//ͨ��1����
	NVRAM0[EM_LASER_POSWIDTH] = 500;//������
	NVRAM0[EM_LASER_NEGWIDTH] = 400;//������
	NVRAM0[EM_LASER_GROUP] = 20;//������
	NVRAM0[EM_LASER_SPACE] = 100;//������
}
void reloadCorrTab(void){//�ָ�����У������
	NVRAM0[DM_CORR_TAB0_POWER0] = 0;
	NVRAM0[DM_CORR_TAB0_POWER1] = 100;
	NVRAM0[DM_CORR_TAB0_POWER2] = 200;
	NVRAM0[DM_CORR_TAB0_POWER3] = 300;
	NVRAM0[DM_CORR_TAB0_POWER4] = 400;
	NVRAM0[DM_CORR_TAB0_POWER5] = 500;
	NVRAM0[DM_CORR_TAB0_POWER6] = 600;
	NVRAM0[DM_CORR_TAB0_POWER7] = 700;
	NVRAM0[DM_CORR_TAB0_POWER8] = 800;
	NVRAM0[DM_CORR_TAB0_POWER9] = 900;
	NVRAM0[DM_CORR_TAB0_POWER10] = 1000;
	NVRAM0[DM_CORR_TAB0_POWER11] = 1100;
	NVRAM0[DM_CORR_TAB0_POWER12] = 1200;
	NVRAM0[DM_CORR_TAB0_POWER13] = 1300;
	NVRAM0[DM_CORR_TAB0_POWER14] = 1400;
	NVRAM0[DM_CORR_TAB0_POWER15] = 1500;
	NVRAM0[DM_CORR_TAB0_POWER16] = 1600;
	NVRAM0[DM_CORR_TAB0_POWER17] = 1700;
	NVRAM0[DM_CORR_TAB0_POWER18] = 2000;
	NVRAM0[DM_CORR_TAB0_POWER19] = 2400;
	NVRAM0[DM_CORR_TAB0_POWER20] = 2600;
	if(NVRAM0[DM_CORR_TAB0_POWER20] > CONFIG_MAX_LASER_CURRENT_CH0){
		NVRAM0[DM_CORR_TAB0_POWER20] = CONFIG_MAX_LASER_CURRENT_CH0;
	}
	NVRAM0[DM_CORR_TAB1_POWER0] = 0;
	NVRAM0[DM_CORR_TAB1_POWER1] = 100;
	NVRAM0[DM_CORR_TAB1_POWER2] = 200;
	NVRAM0[DM_CORR_TAB1_POWER3] = 300;
	NVRAM0[DM_CORR_TAB1_POWER4] = 400;
	NVRAM0[DM_CORR_TAB1_POWER5] = 500;
	NVRAM0[DM_CORR_TAB1_POWER6] = 600;
	NVRAM0[DM_CORR_TAB1_POWER7] = 700;
	NVRAM0[DM_CORR_TAB1_POWER8] = 800;
	NVRAM0[DM_CORR_TAB1_POWER9] = 900;
	NVRAM0[DM_CORR_TAB1_POWER10] = 1000;
	NVRAM0[DM_CORR_TAB1_POWER11] = 1100;
	NVRAM0[DM_CORR_TAB1_POWER12] = 1200;
	NVRAM0[DM_CORR_TAB1_POWER13] = 1300;
	NVRAM0[DM_CORR_TAB1_POWER14] = 1400;
	NVRAM0[DM_CORR_TAB1_POWER15] = 1500;
	NVRAM0[DM_CORR_TAB1_POWER16] = 1600;
	NVRAM0[DM_CORR_TAB1_POWER17] = 1700;
	NVRAM0[DM_CORR_TAB1_POWER18] = 2000;
	NVRAM0[DM_CORR_TAB1_POWER19] = 2400;
	NVRAM0[DM_CORR_TAB0_POWER20] = 2600;
	if(NVRAM0[DM_CORR_TAB1_POWER20] > CONFIG_MAX_LASER_CURRENT_CH1){
		NVRAM0[DM_CORR_TAB1_POWER20] = CONFIG_MAX_LASER_CURRENT_CH1;
	}
	FSAV();//�����洢
}
void loadScheme(void){//DM->EM
	uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > CONFIG_HMI_SCHEME_NUM)
		NVRAM0[DM_SCHEME_NUM] = CONFIG_HMI_SCHEME_NUM;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	psrc = (uint8_t*)&NVRAM0[(DM_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 25)];
	pdist = (uint8_t*)&NVRAM0[EM_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, ((DM_SCHEME_END_0 - DM_SCHEME_START_0 +1 ) * 2));
}
void saveScheme(void){//EM->DM
	uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > CONFIG_HMI_SCHEME_NUM)
		NVRAM0[DM_SCHEME_NUM] = CONFIG_HMI_SCHEME_NUM;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	pdist = (uint8_t*)&NVRAM0[(DM_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 25)];
	psrc = (uint8_t*)&NVRAM0[EM_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, ((DM_SCHEME_END_0 - DM_SCHEME_START_0 +1 ) * 2));
}

void backgroundAppInit(void){
	SET(R_FIBER_ID_PASS_0);
	SET(R_FIBER_ID_PASS_1);
	SET(X_FBD1);
	//��ʼ��EPID����
	NVRAM0[EM_EPID0_TAB_REF] = 250;
	NVRAM0[EM_EPID0_TAB_KP] = 1000;//�������� XX.XXX 0-65.535
	NVRAM0[EM_EPID0_TAB_KI] = 1000;//���ֳ��� XX.XXX 0-65.535		
	NVRAM0[EM_EPID0_TAB_TD] = 10;//΢��ʱ�䳣�� XX.XXX 0-65.535
	NVRAM0[EM_EPID0_TAB_TS]	= 100;//PID����ʱ���� 1-3000 ��λ0.01S
	NVRAM0[EM_EPID0_TAB_MAX] = 1000;//����������		
	NVRAM0[EM_EPID0_TAB_MIN] = 0;//�����С����
	NVRAM0[EM_EPID0_TAB_BIAS] = 0;//���ƫ��
	NVRAM0[EM_EPID0_TAB_TSC] = 0;//�����ʱ��
	NVRAM0[DM_RELEASE_DATA_YEAR] = 2019;
	NVRAM0[DM_RELEASE_DATA_MONTH] = 04;
	NVRAM0[DM_RELEASE_DATA_DAY] = 25;
}
void backgroundApp(void){//����Ӧ��
	if(LDP(SPCOIL_PS100MS)){//ÿ100mS����һ���¶�
		TNTC(EM_DIODE_TEMP0, SPREG_ADC_2);//CODEת��ΪNTC�����¶��¶�
		TNTC(EM_DIODE_TEMP1, SPREG_ADC_3);//CODEת��ΪNTC�����¶��¶�
		TENV(EM_ENVI_TEMP, SPREG_ADC_8);//CODEת��Ϊ�����¶�	
		ADLS1(DM_SYS_RUNTIME_L);
		if(LD(SPCOIL_LASER_EMITING)){
			ADLS1(DM_LAR_RUNTIME_L);
		}
	}
	else{
	}

	//ִ���¿�PID
	NVRAM0[EM_EPID0_TAB_VFB] = NVRAM0[EM_DIODE_TEMP0];//�ɼ��¶ȴ���EPID������
#if CONFIG_SPLC_FUN_EPID == 1
	EPID(&NVRAM0[EM_EPID0_TAB_OUT]);//ִ���¿�PID
#else
	NVRAM0[EM_EPID0_TAB_OUT] = 300;
	NVRAM0[EM_EPID0_TAB_MAX] = 1000;
#endif
	//PID�������SPWM0
	NVRAM0[SPREG_SPWM_CYCLE_0] = NVRAM0[EM_EPID0_TAB_MAX];
	NVRAM0[SPREG_SPWM_POS_0] = NVRAM0[EM_EPID0_TAB_OUT]; 
	//SPWM0��IO
	if(LD(SPCOIL_SPWM_OUT_0)){
		SET(Y_TEC0);SET(Y_TEC1);
	}
	else{
		RES(Y_TEC0);RES(Y_TEC1);
	}

	//�ж϶�����0�Ƿ����
	if(NVRAM0[EM_DIODE_TEMP0] > CONFIG_APP_DIODE_HIGH_TEMP){
		SET(R_DIODE_TEMP_HIGH_0);
	}
	else{
		RES(R_DIODE_TEMP_HIGH_0);
	}
	//�ж϶�����1�Ƿ����
	if(NVRAM0[EM_DIODE_TEMP1] > CONFIG_APP_DIODE_HIGH_TEMP){
		SET(R_DIODE_TEMP_HIGH_1);
	}
	else{
		RES(R_DIODE_TEMP_HIGH_1);
	}
	//�ж��������Ƿ����
	if(NVRAM0[EM_DRIVE_TEMP] > CONFIG_APP_DRIVE_HIGH_TEMP){
		SET(R_DRIVE_TEMP_HIGH);
	}
	else{
		RES(R_DRIVE_TEMP_HIGH);
	}
	//�жϻ����Ƿ����
	if(NVRAM0[EM_ENVI_TEMP] > CONFIG_APP_ENVI_HIGH_TEMP){
		SET(R_ENVI_TEMP_HIGH);
	}
	else{
		RES(R_ENVI_TEMP_HIGH);
	}
	/************************************************************************/
	if(LDP(R_SCHEME_LOAD_REQ)){//��������
		loadScheme();
		RES(R_SCHEME_LOAD_REQ);
	}
	if(LDP(R_SHCEME_SAVE_REQ)){//�洢����
		saveScheme();
		RES(R_SHCEME_SAVE_REQ);
	}
	//
	if(LD(X_FBD0) || LD(X_FBD1) || LD(R_FIBER_ID_PASS_0) || LD(R_FIBER_ID_PASS_1) || LD(R_DIODE_TEMP_HIGH_0) || LD(R_DIODE_TEMP_HIGH_1) ||
	   LD(R_DRIVE_TEMP_HIGH) || LD(R_ENVI_TEMP_HIGH) || LD(R_DRIVE_FAULT_0) || LD(R_DRIVE_FAULT_1) || LD(R_DRIVE_TEMP_HIGH)){
		//SET(R_SAFE_FAULT);
		 RES(R_SAFE_FAULT);  
	}
	else{
		RES(R_SAFE_FAULT);
	}
	//************************************************************************/
}
void PCLAR0(uint16_t POW, uint16_t CUR) reentrant{//����->DAC CODE
	uint8_t index;
	fp32_t k, b;
	if(NVRAM0[POW] >= 400){
		index = 20;
	}else if(NVRAM0[POW] < 400 && NVRAM0[POW] >= 380){
		index = 19;
	}else if(NVRAM0[POW] < 380 && NVRAM0[POW] >= 360){
		index = 18;
	}else if(NVRAM0[POW] < 360 && NVRAM0[POW] >= 340){
		index = 17;
	}else if(NVRAM0[POW] < 340 && NVRAM0[POW] >= 320){
		index = 16;
	}else if(NVRAM0[POW] < 320 && NVRAM0[POW] >= 300){
		index = 15;
	}else if(NVRAM0[POW] < 300 && NVRAM0[POW] >= 280){
		index = 14;
	}else if(NVRAM0[POW] < 280 && NVRAM0[POW] >= 260){
		index = 13;
	}else if(NVRAM0[POW] < 260 && NVRAM0[POW] >= 240){
		index = 12;
	}else if(NVRAM0[POW] < 240 && NVRAM0[POW] >= 220){
		index = 11;
	}else if(NVRAM0[POW] < 220 && NVRAM0[POW] >= 200){
		index = 10;
	}else if(NVRAM0[POW] < 200 && NVRAM0[POW] >= 180){
		index = 9;
	}else if(NVRAM0[POW] < 180 && NVRAM0[POW] >= 160){
		index = 8;
	}else if(NVRAM0[POW] < 160 && NVRAM0[POW] >= 140){
		index = 7;
	}else if(NVRAM0[POW] < 140 && NVRAM0[POW] >= 120){
		index = 6;
	}else if(NVRAM0[POW] < 120 && NVRAM0[POW] >= 100){
		index = 5;
	}else if(NVRAM0[POW] < 100 && NVRAM0[POW] >=  80){
		index = 4;
	}else if(NVRAM0[POW] <  80 && NVRAM0[POW] >=  60){
		index = 3;
	}else if(NVRAM0[POW] <  60 && NVRAM0[POW] >=  40){
		index = 2;
	}else if(NVRAM0[POW] <  40 && NVRAM0[POW] >=  20){
		index = 1;
	}else if(NVRAM0[POW] <  20 && NVRAM0[POW] >=   0){
		index = 0;
	}
	if(index >= 20){
		NVRAM0[CUR] = NVRAM0[DM_CORR_TAB0_POWER20];
	}
	else{
		k = ((fp32_t)NVRAM0[(DM_CORR_TAB0_POWER0 + index + 1)] - (fp32_t)NVRAM0[DM_CORR_TAB0_POWER0 + index]) / 2;
		b = NVRAM0[DM_CORR_TAB0_POWER0 + index] - (k * index * 2);		
	}
	NVRAM0[CUR] = (int16_t)(k * (fp32_t)NVRAM0[POW] - b);
}
void PCLAR1(uint16_t POW, uint16_t CUR) reentrant{//����->DAC CODE
	uint8_t index;
	fp32_t k, b;
	if(NVRAM0[POW] >= 400){
		index = 20;
	}else if(NVRAM0[POW] < 400 && NVRAM0[POW] >= 380){
		index = 19;
	}else if(NVRAM0[POW] < 380 && NVRAM0[POW] >= 360){
		index = 18;
	}else if(NVRAM0[POW] < 360 && NVRAM0[POW] >= 340){
		index = 17;
	}else if(NVRAM0[POW] < 340 && NVRAM0[POW] >= 320){
		index = 16;
	}else if(NVRAM0[POW] < 320 && NVRAM0[POW] >= 300){
		index = 15;
	}else if(NVRAM0[POW] < 300 && NVRAM0[POW] >= 280){
		index = 14;
	}else if(NVRAM0[POW] < 280 && NVRAM0[POW] >= 260){
		index = 13;
	}else if(NVRAM0[POW] < 260 && NVRAM0[POW] >= 240){
		index = 12;
	}else if(NVRAM0[POW] < 240 && NVRAM0[POW] >= 220){
		index = 11;
	}else if(NVRAM0[POW] < 220 && NVRAM0[POW] >= 200){
		index = 10;
	}else if(NVRAM0[POW] < 200 && NVRAM0[POW] >= 180){
		index = 9;
	}else if(NVRAM0[POW] < 180 && NVRAM0[POW] >= 160){
		index = 8;
	}else if(NVRAM0[POW] < 160 && NVRAM0[POW] >= 140){
		index = 7;
	}else if(NVRAM0[POW] < 140 && NVRAM0[POW] >= 120){
		index = 6;
	}else if(NVRAM0[POW] < 120 && NVRAM0[POW] >= 100){
		index = 5;
	}else if(NVRAM0[POW] < 100 && NVRAM0[POW] >=  80){
		index = 4;
	}else if(NVRAM0[POW] <  80 && NVRAM0[POW] >=  60){
		index = 3;
	}else if(NVRAM0[POW] <  60 && NVRAM0[POW] >=  40){
		index = 2;
	}else if(NVRAM0[POW] <  40 && NVRAM0[POW] >=  20){
		index = 1;
	}else if(NVRAM0[POW] <  20 && NVRAM0[POW] >=   0){
		index = 0;
	}
	if(index >= 20){
		NVRAM0[CUR] = NVRAM0[DM_CORR_TAB1_POWER20];
	}
	else{
		k = ((fp32_t)NVRAM0[(DM_CORR_TAB1_POWER0 + index + 1)] - (fp32_t)NVRAM0[DM_CORR_TAB1_POWER0 + index]) / 2;
		b = NVRAM0[DM_CORR_TAB1_POWER0 + index] - (k * index * 2);		
	}
	NVRAM0[CUR] = (int16_t)(k * (fp32_t)NVRAM0[POW] - b);
}
#endif