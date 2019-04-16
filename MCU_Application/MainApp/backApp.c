#include "backApp.h"
/*****************************************************************************/
void loadScheme(void){//DM->EM
	xdata uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > CONFIG_HMI_SCHEME_NUM)
		NVRAM0[DM_SCHEME_NUM] = CONFIG_HMI_SCHEME_NUM;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	psrc = (uint8_t*)&NVRAM0[(DM_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 25)];
	pdist = (uint8_t*)&NVRAM0[EM_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, ((DM_SCHEME_END_0 - DM_SCHEME_START_0 +1 ) * 2));
}
void saveScheme(void){//EM->DM
	xdata uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > CONFIG_HMI_SCHEME_NUM)
		NVRAM0[DM_SCHEME_NUM] = CONFIG_HMI_SCHEME_NUM;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	pdist = (uint8_t*)&NVRAM0[(DM_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 25)];
	psrc = (uint8_t*)&NVRAM0[EM_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, ((DM_SCHEME_END_0 - DM_SCHEME_START_0 +1 ) * 2));
}

void bcakAppInit(void){
	SET(R_FIBER_MANUFACT_0);
	SET(R_FIBER_MANUFACT_1);
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
}
void backApp(void){//����Ӧ��
	if(LDP(SPCOIL_PS10MS)){//ÿ100mS����һ���¶�
		TNTC(&NVRAM0[EM_DIODE_TEMP0], &NVRAM0[SPREG_ADC_2]);//CODEת��ΪNTC�����¶��¶�
		TNTC(&NVRAM0[EM_DIODE_TEMP1], &NVRAM0[SPREG_ADC_3]);//CODEת��ΪNTC�����¶��¶�
		TENV(&NVRAM0[EM_ENVI_TEMP], &NVRAM0[SPREG_ADC_8]);//CODEת��Ϊ�����¶�	
	}
	//ִ���¿�PID
	NVRAM0[EM_EPID0_TAB_VFB] = NVRAM0[EM_DIODE_TEMP0];//�ɼ��¶ȴ���EPID������
	EPID(&NVRAM0[EM_EPID0_TAB_OUT]);//ִ���¿�PID
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
	//************************************************************************/
	if(LD(X_FBD0) || LD(X_FBD1) || LD(R_FIBER_MANUFACT_0) || LD(R_FIBER_MANUFACT_1) ||
	LD(R_DIODE_TEMP_HIGH_0) || LD(R_DIODE_TEMP_HIGH_1) || LD(R_DRIVE_TEMP_HIGH) || LD(R_ENVI_TEMP_HIGH) ||
	LD(R_DRIVE_FAULT_0)	|| LD(R_DRIVE_FAULT_1)){
		SET(R_SAFE_READY);
	}
	else{
		RES(R_SAFE_READY);
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
	if(LD(X_FBD0) || LD(X_FBD1) || LD(R_FIBER_MANUFACT_0) || LD(R_FIBER_MANUFACT_1) ||
	   LD(R_DIODE_TEMP_HIGH_0) || LD(R_DIODE_TEMP_HIGH_1) || LD(R_DRIVE_FAULT_0) || LD(R_DRIVE_FAULT_1) ||
	   LD(R_DRIVE_TEMP_HIGH) || LD(R_ENVI_TEMP_HIGH)){
		SET(R_SAFE_READY);
	}
	else{
		RES(R_SAFE_READY);
	}
	//************************************************************************/

}