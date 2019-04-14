#include "sPlcBeem.h"
/*****************************************************************************/
void sPlcBeemInit(void){//��������ʼ��
	NVRAM0[SPREG_BEEM_VOLUME] = 0;
	NVRAM0[SPREG_BEEM_MODE] = 0;
	NVRAM0[SPREG_BEEM_TCOUNTER] = 0;
	NVRAM0[SPREG_BEEM_PCOUNTER] = 0;
	NVRAM0[SPREG_BEEM_POS] = 0;
	NVRAM0[SPREG_BEEM_CYCLE] = 0;
	RES(SPCOIL_BEEM_EMITING);
	RES(SPCOIL_BEEM_EMITOVER);
}
void sPlcBeemLoop(void){//��������ѯ
	if(LD(SPCOIL_BEEM_EMITING) && (NVRAM0[SPREG_BEEM_PCOUNTER] <= NVRAM0[SPREG_BEEM_RELEASE])){
		if(NVRAM0[SPREG_BEEM_TCOUNTER] == 0){
			NVRAM1[SPREG_HPWM2_DUTYRATIO] = NVRAM0[SPREG_BEEM_VOLUME];//�򿪷�����		
		}
		if(NVRAM0[SPREG_BEEM_TCOUNTER] > NVRAM0[SPREG_BEEM_POS]){
			NVRAM1[SPREG_HPWM2_DUTYRATIO] = 0;//�رշ�����
		}
		if(NVRAM0[SPREG_BEEM_TCOUNTER] > NVRAM0[SPREG_BEEM_CYCLE]){
			(uint16_t)NVRAM0[SPREG_BEEM_TCOUNTER] = 0xFFFF;//��ʱ������
		}
	}
	else{//�������
		RES(SPCOIL_BEEM_EMITING);
		SET(SPCOIL_BEEM_EMITOVER);
		NVRAM1[SPREG_HPWM2_DUTYRATIO] = 0;//�رշ�����
	}
	
}
void testBenchBeem(uint8_t volume, uint8_t mode){//����������
}
void EDBEEM(void){//ֹͣ������
}
void STBEEM(void){//��ʼ������
	if(NVRAM0[SPREG_BEEM_MODE] == BEEM_MODE_0){//ģʽ0 CW
		
	}
	if(NVRAM0[SPREG_BEEM_MODE] == BEEM_MODE_1){//ģʽ1 �̼��
	}
	if(NVRAM0[SPREG_BEEM_MODE] == BEEM_MODE_2){//ģʽ2 �����
	}
}