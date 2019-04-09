#include "hmiApp.h"
/*****************************************************************************/
#define CONFIG_HMI_SCHEME_NUM			16//������
#define CONFIG_HMI_DEFAULT_PASSSWORD0	0x32//Ĭ������
#define CONFIG_HMI_DEFAULT_PASSSWORD1	0x35//Ĭ������
#define CONFIG_HMI_DEFAULT_PASSSWORD2	0x38//Ĭ������
#define CONFIG_HMI_DEFAULT_PASSSWORD3	0x30//Ĭ������
#define STATUS_LASER_READY				0x5A
#define STATUS_LASER_STANDBY			0xA5
/*****************************************************************************/
#define EM_HMI_LASER_SCHEME_NAME		(EM_START + 0)//��������
#define EM_HMI_LASER_POWER_980			(EM_START + 18)//980����
#define EM_HMI_LASER_POWER_1470			(EM_START + 19)//1470����
#define EM_HMI_LASER_PULSE_MODE			(EM_START + 20)//����ģʽ
#define EM_HMI_LASER_POSWIDTH			(EM_START + 21)//������
#define EM_HMI_LASER_NEGWIDTH			(EM_START + 22)//������
#define EM_HMI_LASER_GROUP				(EM_START + 23)//������
#define EM_HMI_LASER_SPACE				(EM_START + 24)//������

#define EM_HMI_HMI_PAGE					(EM_START + 25)
#define EM_HMI_START_PROGRESS_BAR		(EM_START + 26)
#define EM_HMI_NEW_PASSWORD0			(EM_START + 27)
#define EM_HMI_NEW_PASSWORD1			(EM_START + 28)
#define EM_HMI_NEW_PASSWORD2			(EM_START + 29)
#define EM_HMI_NEW_PASSWORD3			(EM_START + 30)
#define EM_HMI_DEFAULT_PASSWORD0		(EM_START + 31)
#define EM_HMI_DEFAULT_PASSWORD1		(EM_START + 32)
#define EM_HMI_DEFAULT_PASSWORD2		(EM_START + 33)
#define EM_HMI_DEFAULT_PASSWORD3		(EM_START + 34)

#define EM_HMI_READY_STATUS				(EM_START + 35)
#define EM_DIODE_TEMP0					(EM_START + 40)//�������¶�0
#define EM_DIODE_TEMP1					(EM_START + 41)//�������¶�1
#define EM_DRIVE_TEMP					(EM_START + 42)//�������¶�
#define EM_ENVI_TEMP					(EM_START + 43)//�����¶�

#define EM_DIODE_HIGH_TEMP				(EM_START + 44)//�����ܹ�����ֵ
#define EM_DRIVE_HIGH_TEMP				(EM_START + 45)//������������ֵ
#define EM_ENVI_HIGH_TEMP				(EM_START + 46)//����������ֵ
/*****************************************************************************/
#define DM_SCHEME_NAME					(DM_START +   0)//��������
#define DM_SCHEME_LASER_POWER_980		(DM_START +  18)//980����
#define DM_SCHEME_LASER_POWER_1470		(DM_START +  19)//1470����
#define DM_SCHEME_LASER_PULSE_MODE		(DM_START +  20)//����ģʽ
#define DM_SCHEME_LASER_POSWIDTH		(DM_START +  21)//��������
#define DM_SCHEME_LASER_NEGWIDTH		(DM_START +  22)//��������
#define DM_SCHEME_LASER_GROUP			(DM_START +  23)//Ⱥ������
#define DM_SCHEME_LASER_LASER_SPACE		(DM_START +  24)//Ⱥ������

#define DM_SCHEME_START_0				(DM_START +   0)//����0�洢��
#define DM_SCHEME_END_0					(DM_START +  24)

#define DM_SCHEME_START_1				(DM_START +  25)//����1�洢��
#define DM_SCHEME_END_1					(DM_START +  49)

#define DM_SCHEME_START_2				(DM_START +  50)//����2�洢��
#define DM_SCHEME_END_2					(DM_START +  74)

#define DM_SCHEME_START_3				(DM_START +  75)//����3�洢��
#define DM_SCHEME_END_3					(DM_START +  99)

#define DM_SCHEME_START_4				(DM_START + 100)//����4�洢��
#define DM_SCHEME_END_4					(DM_START + 124)

#define DM_SCHEME_START_5				(DM_START + 125)//����5�洢��
#define DM_SCHEME_END_5					(DM_START + 149)

#define DM_SCHEME_START_6				(DM_START + 150)//����6�洢��
#define DM_SCHEME_END_6					(DM_START + 174)

#define DM_SCHEME_START_7				(DM_START + 175)//����7�洢��
#define DM_SCHEME_END_7					(DM_START + 199)

#define DM_SCHEME_START_8				(DM_START + 200)//����8�洢��
#define DM_SCHEME_END_8					(DM_START + 224)

#define DM_SCHEME_START_9				(DM_START + 225)//����11�洢��
#define DM_SCHEME_END_9					(DM_START + 249)

#define DM_SCHEME_START_10				(DM_START + 250)//����10�洢��
#define DM_SCHEME_END_10				(DM_START + 274)

#define DM_SCHEME_START_11				(DM_START + 275)//����11�洢��
#define DM_SCHEME_END_11				(DM_START + 299)

#define DM_SCHEME_START_12				(DM_START + 300)//����12�洢��
#define DM_SCHEME_END_12				(DM_START + 324)

#define DM_SCHEME_START_13				(DM_START + 325)//����13�洢��
#define DM_SCHEME_END_13				(DM_START + 349)

#define DM_SCHEME_START_14				(DM_START + 350)//����14�洢��
#define DM_SCHEME_END_14				(DM_START + 374)

#define DM_SCHEME_START_15				(DM_START + 375)//����15�洢��
#define DM_SCHEME_END_15				(DM_START + 399)

#define DM_SCHEME_NUM					(DM_START + 400)//ѡ��ķ������

#define DM_DIODE_HIGH_TEMP				(EM_START + 420)
#define DM_DRIVE_HIGH_TEMP				(DM_START + 420)
#define DM_ENVI_HIGH_TEMP				(DM_START + 420)
#define DM_HMI_OLD_PASSWORD0			(DM_START + 0)
#define DM_HMI_OLD_PASSWORD1			(DM_START + 1)
#define DM_HMI_OLD_PASSWORD2			(DM_START + 0)
#define DM_HMI_OLD_PASSWORD3			(DM_START + 1)

/*****************************************************************************/
#define X_FOOTSWITCH					(X_START * 16 + 0)//XIN0
#define X_INTERLOCK						(X_START * 16 + 1)//XIN1
/*****************************************************************************/
#define Y_LED_POWERON					(Y_START * 16 + 0)//YOUT0
#define Y_LED_EMIT						(Y_START * 16 + 1)//YOUT1
#define Y_LED_ALARM						(Y_START * 16 + 2)//YOUT2
/*****************************************************************************/
#define R_FIBER_DETECT_0				(R_START * 16 + 0)//����̽��
#define R_FIBER_DETECT_1				(R_START * 16 + 0)
#define R_FIBER_MANUFACT_0				(R_START * 16 + 0)
#define R_FIBER_MANUFACT_1				(R_START * 16 + 0)
#define R_DIODE_TEMP_HIGH_0				(R_START * 16 + 0)
#define R_DIODE_TEMP_HIGH_1				(R_START * 16 + 0)
#define R_DRIVE_FAULT_0					(R_START * 16 + 0)
#define R_DRIVE_FAULT_1					(R_START * 16 + 0)
#define R_DRIVE_TEMP_HIGH				(R_START * 16 + 0)
#define R_ENVI_TEMP_HIGH				(R_START * 16 + 0)

#define R_SAFE_READY					(R_START * 16 + 0)//��ȫ����
#define R_SCHEME_LOAD_REQ				(R_START * 16 + 0)//������������
#define R_SHCEME_SAVE_REQ				(R_START * 16 + 0)//������������
/*****************************************************************************/
static void loadScheme(void){//DM->EM
	xdata uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > CONFIG_HMI_SCHEME_NUM)
		NVRAM0[DM_SCHEME_NUM] = CONFIG_HMI_SCHEME_NUM;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	psrc = (uint8_t*)&NVRAM0[(DM_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 25)];
	pdist = (uint8_t*)&NVRAM0[EM_HMI_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, ((DM_SCHEME_END_0 - DM_SCHEME_START_0 +1 ) * 2));
}
static void saveScheme(void){//EM->DM
	idata uint8_t *psrc, *pdist;
	if(NVRAM0[DM_SCHEME_NUM] > CONFIG_HMI_SCHEME_NUM)
		NVRAM0[DM_SCHEME_NUM] = CONFIG_HMI_SCHEME_NUM;
	if(NVRAM0[DM_SCHEME_NUM] < 0)
		NVRAM0[DM_SCHEME_NUM] = 0;
	pdist = (uint8_t*)&NVRAM0[(DM_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 25)];
	psrc = (uint8_t*)&NVRAM0[EM_HMI_LASER_SCHEME_NAME];
	memcpy(pdist, psrc, ((DM_SCHEME_END_0 - DM_SCHEME_START_0 +1 ) * 2));
}

void hmiLoop(void){//HMI��ѵ����
	if(LD(SPCOIL_START_UP)){//ִ��һ�εĴ���
		NVRAM0[EM_HMI_HMI_PAGE] = 0x0;//HMIҳ��
		NVRAM0[EM_HMI_START_PROGRESS_BAR] = 0x0;//����������
		//����Ĭ������
		NVRAM0[EM_HMI_DEFAULT_PASSWORD0] = (CONFIG_HMI_DEFAULT_PASSSWORD0 << 8) | CONFIG_HMI_DEFAULT_PASSSWORD1;
		NVRAM0[EM_HMI_DEFAULT_PASSWORD0] = (CONFIG_HMI_DEFAULT_PASSSWORD2 << 8) | CONFIG_HMI_DEFAULT_PASSSWORD3;
		NVRAM0[EM_HMI_DEFAULT_PASSWORD0] = 0x0; 
		NVRAM0[EM_HMI_DEFAULT_PASSWORD0] = 0x0; 
		loadScheme();//�ӵ���洢�Ĵ����лָ���������
	}
	if(LDP(SPCOIL_PS10MS)){//ÿ100mS����һ���¶�
		TNTC(&NVRAM0[EM_DIODE_TEMP0], &NVRAM0[SPREG_ADC_2]);//CODEת��ΪNTC�����¶��¶�
		TNTC(&NVRAM0[EM_DIODE_TEMP1], &NVRAM0[SPREG_ADC_3]);//CODEת��ΪNTC�����¶��¶�
		TENV(&NVRAM0[EM_ENVI_TEMP], &NVRAM0[SPREG_ADC_8]);//CODEת��Ϊ�����¶�
	}
	//�ж϶�����0�Ƿ����
	if(NVRAM0[EM_DIODE_TEMP0] > NVRAM0[DM_DIODE_HIGH_TEMP]){
		SET(R_DIODE_TEMP_HIGH_0);
	}
	else{
		RES(R_DIODE_TEMP_HIGH_0);
	}
	//�ж϶�����1�Ƿ����
	if(NVRAM0[EM_DIODE_TEMP1] > NVRAM0[DM_DIODE_HIGH_TEMP]){
		SET(R_DIODE_TEMP_HIGH_1);
	}
	else{
		RES(R_DIODE_TEMP_HIGH_1);
	}
	//�ж��������Ƿ����
	if(NVRAM0[EM_DRIVE_TEMP] > NVRAM0[DM_DRIVE_HIGH_TEMP]){
		SET(R_DRIVE_TEMP_HIGH);
	}
	else{
		RES(R_DRIVE_TEMP_HIGH);
	}
	//�жϻ����Ƿ����
	if(NVRAM0[EM_ENVI_TEMP] > NVRAM0[DM_ENVI_HIGH_TEMP]){
		SET(R_ENVI_TEMP_HIGH);
	}
	else{
		RES(R_ENVI_TEMP_HIGH);
	}
	
	if(LD(R_FIBER_DETECT_0) ||
    LD(R_FIBER_DETECT_1) ||
	LD(R_FIBER_MANUFACT_0) ||
	LD(R_FIBER_MANUFACT_1) ||
	LD(R_DIODE_TEMP_HIGH_0) ||		
	LD(R_DIODE_TEMP_HIGH_1) ||
	LD(R_DRIVE_FAULT_0)	||
	LD(R_DRIVE_FAULT_1) ||
	LD(R_DRIVE_TEMP_HIGH) ||
	LD(R_ENVI_TEMP_HIGH)){
		SET(R_SAFE_READY);
	}
	
	
	if(NVRAM0[EM_HMI_READY_STATUS] == STATUS_LASER_READY){//READY״̬
	}
	else if(NVRAM0[EM_HMI_READY_STATUS] == STATUS_LASER_STANDBY){//STAND״̬
		if(LD(X_FOOTSWITCH) && LD(R_SAFE_READY)){//���伤��
			
		}
		else{//ֹͣ����
			
		}
	}
}

