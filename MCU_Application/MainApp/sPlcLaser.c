#include "sPlcLaser.h"
/*****************************************************************************/
#define MCP47X6_LASER_CHANNEL_CH1				0
#define MCP47X6_LASER_CHANNEL_CH2				1
#define LASER_MODE_CW							0//����ģʽ
#define LASER_MODE_SP							1//������ģʽ
#define LASER_MODE_MP							2//������ģʽ
#define LASER_MODE_GP							3//Ⱥ����ģʽ
#define LASER_STEPNUM_INIT						0
#define LASER_STEPNUM_STANDBY					1
#define LASER_STEPNUM_INTO_READY				2
#define LASER_STEPNUM_READY						3
#define LASER_STEPNUM_LASERON					100
#define LASER_STEPNUM_FAULT						255
/*****************************************************************************/
#define LASER_CH1_MODPIN_ON		(P4 |= (uint8_t)(1 << 6))
#define LASER_CH1_MODPIN_OFF	(P4 &= ~(uint8_t)(1 << 6))

#define LASER_CH2_MODPIN_ON		(P4 |= (uint8_t)(1 << 1))
#define LASER_CH2_MODPIN_OFF	(P4 &= ~(uint8_t)(1 << 1))
#define SPLC_100MS_INTOREADY_BEEM				1
/*****************************************************************************/

static void STLAR(void);
static void EDLAR(void);
void sPlcLaser(void){
	if(LD(SPCOIL_PSST)){//�ϵ��ʼ��STEPNUM
		NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_INIT;
	}
	if((NVRAM0[EM_DRIVER_TEMPERATURE] > NVRAM0[DM_DRIVE_PROTECT_HTEMP]) && LDF(R_FLAG_DRIVER_TEMP_FAULT_IGNORE)){
		SET(R_FLAG_DRIVER_HTEMP_FAULT);
	}
	else{
		RES(R_FLAG_DRIVER_HTEMP_FAULT);
	}
	if((NVRAM0[EM_DRIVER_TEMPERATURE] < NVRAM0[DM_DRIVE_PROTECT_LTEMP]) && LDF(R_FLAG_DRIVER_TEMP_FAULT_IGNORE)){
		SET(R_FLAG_DRIVER_LTEMP_FAULT);
	}
	else{
		RES(R_FLAG_DRIVER_LTEMP_FAULT);
	}
	if((NVRAM0[EM_MCHIP_TEMPERATURE] > NVRAM0[DM_MCHIP_PROTECT_HTEMP]) && LDF(R_FLAG_MCHIP_TEMP_FAULT_IGNORE)){
		SET(R_FLAG_MCHIP_HTEMP_FAULT);
	}
	else{
		RES(R_FLAG_MCHIP_HTEMP_FAULT);
	}
	if((NVRAM0[EM_MCHIP_TEMPERATURE] < NVRAM0[DM_MCHIP_PROTECT_LTEMP]) && LDF(R_FLAG_MCHIP_TEMP_FAULT_IGNORE)){
		SET(R_FLAG_MCHIP_HTEMP_FAULT);
	}
	else{
		RES(R_FLAG_MCHIP_HTEMP_FAULT);
	}
	if((NVRAM0[EM_LASER_TEMPERATURE] > NVRAM0[DM_LASER_PROTECT_HTEMP]) && LDF(R_FLAG_LASER_TEMP_FAULT_IGNORE)){
		SET(R_FLAG_LASER_HTEMP_FAULT);
	}
	else{
		RES(R_FLAG_LASER_HTEMP_FAULT);
	}
	if((NVRAM0[EM_LASER_TEMPERATURE] < NVRAM0[DM_LASER_PROTCET_LTEMP]) && LDF(R_FLAG_LASER_TEMP_FAULT_IGNORE)){
		SET(R_FLAG_LASER_LTEMP_FAULT);
	}
	else{
		RES(R_FLAG_LASER_LTEMP_FAULT);
	}
		
	if(LD(R_FLAG_DRIVER_LTEMP_FAULT) || 
	   LD(R_FLAG_DRIVER_HTEMP_FAULT) || 
	   LD(R_FLAG_MCHIP_LTEMP_FAULT) ||
	   LD(R_FLAG_MCHIP_HTEMP_FAULT) || 
	   LD(R_FLAG_LASER_LTEMP_FAULT) ||
	   LD(R_FLAG_LASER_HTEMP_FAULT)){
		SET(R_FLAG_TEMP_FAULT);
	}
	else{
		RES(R_FLAG_TEMP_FAULT);
	}
	if(LDF(X_MECH_FIBER_DETECT)){
		SET(R_FLAG_FIBER_MECH_DETECT);
	}
	else{
		RES(R_FLAG_FIBER_MECH_DETECT);
	}
	if(LD(R_FLAG_FIBER_MECH_DETECT) && LDF(R_FLAG_FIBER_MECH_DETECT)){
		SET(R_FLAG_SAFE_FAULT);
	}
	else{
		RES(R_FLAG_SAFE_FAULT);
	}

//STEP_LOOP_START:
	if(NVRAM0[EM_STEP_NUM] == LASER_STEPNUM_INIT){//��ʼ��
		NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_STANDBY;//Goto next step
		goto STEP_LOOP_END;
	}
	if(NVRAM0[EM_STEP_NUM] == LASER_STEPNUM_STANDBY){//��һ�� ����״̬->��������ʾ
		if(LD(R_FLAG_SAFE_FAULT) || LD(R_FLAG_TEMP_FAULT)){
			NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_FAULT;
			goto STEP_LOOP_END;
		}
		if(LD(R_FLAG_READY)){//���׼��״̬
			SET(R_FLAG_BEEM);
			NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_INTO_READY;//����׼��״̬
			goto STEP_LOOP_END;
		}
		goto STEP_LOOP_END;
	}
	if(NVRAM0[EM_STEP_NUM] == LASER_STEPNUM_INTO_READY){//�ڶ��� �ȴ�1������
		T100MS(SPLC_100MS_INTOREADY_BEEM, true, 10);//����1����ʱ��	
		if(LD(T_100MS_START * 16 + SPLC_100MS_INTOREADY_BEEM)){//��ʱ�ﵽ����READY����
			SET(R_FLAG_BEEM);
			NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_READY;
			T100MS(SPLC_100MS_INTOREADY_BEEM, false, 10);//ֹͣ��ʱ��
			goto STEP_LOOP_END;
		}
		goto STEP_LOOP_END;
	}
	if(NVRAM0[EM_STEP_NUM] == LASER_STEPNUM_READY){//������ ׼��״̬ �ȴ���̤�źŷ��伤��
		if(LD(R_FLAG_SAFE_FAULT) || LD(R_FLAG_TEMP_FAULT)){
			NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_FAULT;
			goto STEP_LOOP_END;
		}
		if(LDP(R_FLAG_FOOTSWITCH)){//���footSwitch������
			NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_LASERON;
			RES(R_FLAG_LASER_EMITOVER);//������ɱ�־����
			SET(R_FLAG_LASER_EMITING);//�����б�־��λ
			//�����⹦��ֵת��Ϊ����ֵ
			STLAR();//��ʼ���伤��
			goto STEP_LOOP_END;
		}
		goto STEP_LOOP_END;
	}
	if(NVRAM0[EM_STEP_NUM] == LASER_STEPNUM_LASERON){
		if(LD(R_FLAG_SAFE_FAULT) || LD(R_FLAG_TEMP_FAULT)){
			NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_FAULT;
			goto STEP_LOOP_END;
		}
		if(LDB(R_FLAG_FOOTSWITCH)){//��⵽��̤��λ
			EDLAR();//�رռ���
			SET(R_FLAG_LASER_EMITOVER);//������ɱ�־����
			RES(R_FLAG_LASER_EMITING);//�����б�־��λ
			NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_FAULT;//����READY����
			goto STEP_LOOP_END;
		}
		goto STEP_LOOP_END;
	}
	if(NVRAM0[EM_STEP_NUM] == LASER_STEPNUM_FAULT){//����״̬
			if(LDB(R_FLAG_SAFE_FAULT) && LDB(R_FLAG_TEMP_FAULT)){//����������
				if(LD(R_LASER_ERROR_CLEAR)){//�����������ش���״̬
					RES(R_LASER_ERROR_CLEAR);
					NVRAM0[EM_STEP_NUM] = LASER_STEPNUM_STANDBY;
				}
				goto STEP_LOOP_END;
			}
			goto STEP_LOOP_END;
		}
STEP_LOOP_END:
	{}
}
		


static void STLAR(void){//��ʼ��������
	uint8_t SFRPAGE_save;
	NVRAM0[EM_LASER_TMATE] = NVRAM0[EM_LASER_POSWIDTH];//����ƥ��ֵ
	NVRAM0[EM_LASER_TOVERFLOW] = ADD(NVRAM0[EM_LASER_POSWIDTH], NVRAM0[EM_LASER_POSWIDTH]);//�������ֵ
	NVRAM0[EM_LASER_TCOUNTER] = 0X00;	
	NVRAM0[EM_LASER_PMATE] = 0x00;//�������ƥ��ֵ
	NVRAM0[EM_LASER_SMATE] = 0x0;//���������ֵ
	NVRAM0[EM_LASER_PCOUNTER] = 0X0;
	NVRAM0[EM_LASER_SCOUNTER] = 0X0;
#ifdef C8051F580
	SFRPAGE_save = SFRPAGE;
	SFRPAGE = ACTIVE_PAGE;
	TMR3CN &= ~(uint8_t)(1 << 7);//T3�жϱ�־����
	EIE1 |= (1 << 6);//T3 ET3�ж�ʹ��
	TMR3L = 0xFF;
	TMR3H = 0xFF;
	TMR3CN |= (1 << 2);//TR3 ʹ��TIMER3��ʱ��
	SFRPAGE = SFRPAGE_save;
#endif
#ifdef C8051F020
	TMR3CN &= ~(uint8_t)(1 << 7);//TF3 �����־����
	EIE2 |= (1 << 0);//T3 ET3�ж�ʹ��
	TMR3L = 0xFF;
	TMR3H = 0xFF;
	TMR3CN |= (1 << 2);//TR3 ʹ��TIMER3��ʱ��
#endif
	SET(R_FLAG_LASER_EMITING);//�����־��λ
	RES(R_FLAG_LASER_EMITOVER);
}
static void EDLAR(void){//ֹͣ��������
#ifdef C8051F020
	TMR3CN &= ~(uint8_t)(1 << 2);//Stop Timer 3
	TMR3CN &= ~(uint8_t)(1 << 7);//Clear Timer 3 High Byte Overflow Flag.
	EIE1 &= ~(uint8_t)(1 << 6);//�ر�Timer3�ж�
#endif
#ifdef C8051F580
	uint8_t SFRPAGE_save;
	SFRPAGE_save = SFRPAGE;
	SFRPAGE = ACTIVE_PAGE;
	TMR3CN &= ~(uint8_t)(1 << 2);//Stop Timer 3
	TMR3CN &= ~(uint8_t)(1 << 7);//Clear Timer 3 High Byte Overflow Flag.
	EIE1 &= ~(uint8_t)(1 << 6);//�ر�Timer3�ж�
	SFRPAGE = SFRPAGE_save;
#endif
	//�ر�DAC���
	NVRAM0[SPREG_DAC_0] = 0;
	NVRAM0[SPREG_DAC_1] = 1;
	UPDAC(MCP47X6_LASER_CHANNEL_CH1);
	UPDAC(MCP47X6_LASER_CHANNEL_CH2);
	RES(R_FLAG_LASER_EMITING);//�����־��λ
}
void initTimer3(void){//TIMER3��ʼ��
	
}
void timer3Isr(void) interrupt INTERRUPT_TIMER3{//TIMER3 �ж� ���ⷢ��
	uint8_t SFRPAGE_save;
#ifdef C8051F580	
	SFRPAGE_save = SFRPAGE;
	SFRPAGE = ACTIVE_PAGE;
	TMR3CN &= ~(uint8_t)(1 << 7);//Clear Timer 3 High Byte Overflow Flag
	SFRPAGE = SFRPAGE_save;
#endif
#ifdef C8051F020
#endif
	switch(NVRAM0[EM_LASER_MODE]){
		case LASER_MODE_CW:{//CW����ģʽ
			if(LD(R_LASER_SELECT_CH1)){
				mcp47x6Write(MCP47X6_LASER_CHANNEL_CH1, NVRAM0[EM_LASER_CURRENT_CH1]);
			}
			else{
				mcp47x6Write(MCP47X6_LASER_CHANNEL_CH1, 0);
			}
			if(LD(R_LASER_SELECT_CH2)){
				mcp47x6Write(MCP47X6_LASER_CHANNEL_CH2, NVRAM0[EM_LASER_CURRENT_CH2]);
			}
			else{
				mcp47x6Write(MCP47X6_LASER_CHANNEL_CH2, 0);
			}
			break;
		}
		case LASER_MODE_SP:{//SP������ģʽ
			break;
		}
		case LASER_MODE_MP:{//MP������ģʽ	
			if(NVRAM0[EM_LASER_TCOUNTER] ==  NVRAM0[EM_LASER_TMATE]){//��ʱ��ƥ��
				LASER_CH1_MODPIN_OFF;LASER_CH2_MODPIN_OFF;//��ת���		
			}
			if(NVRAM0[EM_LASER_TCOUNTER] == NVRAM0[EM_LASER_TOVERFLOW]){//��ʱ�����
				NVRAM0[EM_LASER_TCOUNTER] = 0;//����
			}
			if(NVRAM0[EM_LASER_TCOUNTER] == 0){//��ת
				LASER_CH1_MODPIN_ON;LASER_CH2_MODPIN_ON;//��ת���
			}
			NVRAM0[EM_LASER_TCOUNTER] ++;
			break;
		}
		case LASER_MODE_GP:{//GP�ɱ������ģʽ
			if(NVRAM0[EM_LASER_PCOUNTER] < NVRAM0[EM_START + EM_LASER_PMATE]){
				if(NVRAM0[EM_LASER_TCOUNTER] == 0){
					if(NVRAM0[EM_LASER_PCOUNTER] < NVRAM0[EM_LASER_PCOUNTER]){
						LASER_CH1_MODPIN_ON;LASER_CH2_MODPIN_ON;//��ת���						
					}
				}
				if(NVRAM0[EM_LASER_TCOUNTER] == NVRAM0[EM_LASER_TMATE]){//��ʱ��ƥ��
					LASER_CH1_MODPIN_OFF;LASER_CH2_MODPIN_OFF;//��ת���	
				}
				if(NVRAM0[EM_LASER_TCOUNTER] == (NVRAM0[EM_LASER_TOVERFLOW] - 1)){//��ʱ�����
					NVRAM0[EM_LASER_TCOUNTER] = 0xFFFF;//����
					NVRAM0[EM_LASER_PCOUNTER] ++;//����	
				}
				NVRAM0[EM_LASER_TCOUNTER] ++;
			}
			if((NVRAM0[EM_LASER_PCOUNTER] == NVRAM0[EM_LASER_PMATE]) && (NVRAM0[EM_LASER_TCOUNTER] == 0)){//�����������ƥ��
				LASER_CH1_MODPIN_OFF;LASER_CH2_MODPIN_OFF;//��ת���
				NVRAM0[EM_LASER_PCOUNTER] = 0xFFFF;
				NVRAM0[EM_LASER_SCOUNTER] = 0x0000;
			}
			if(NVRAM0[EM_LASER_PCOUNTER] == 0xFFFF){		
				if( NVRAM0[EM_LASER_SCOUNTER] == NVRAM0[EM_LASER_SMATE]){
					NVRAM0[EM_LASER_PCOUNTER] = 0;
				}
				NVRAM0[EM_LASER_SCOUNTER] ++;
			}
			break;
		}
		default:break;
	}
}
