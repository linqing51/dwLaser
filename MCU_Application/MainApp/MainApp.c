#include "MainApp.h"
#include "hmiLib.h"
//#include "sPlcTest.h"
/*****************************************************************************/
#define T10MS_HMI_UPDATA					0//HMIˢ�¶�ʱ��
#define R_HMI_UPDATA_REQ					(R_START * 16 + 0)//HMI����ˢ�±�־
#define EM_HMI_CMD_QUEUE					(EM_START + 0)//HMIָ���������
///*****************************************************************************/
//#define DM_TOTAL_TIME_L					(DM_START + 0)
//#define DM_TOTAL_TIME_H					(DM_START + 1)
/*****************************************************************************/
//<<<<<<< HEAD
//#define ENUM_MODE_CW					0//����ģʽ
//#define ENUM_MODE_SP					1//������ģʽ
//#define ENUM_MODE_MP					2//������ģʽ
//#define ENUM_MODE_GP					3//Ⱥ����ģʽ
//#define ENUM_MODE_CC					4//У��ģʽ
///*****************************************************************************/
///*****************************************************************************/
//#define STEPNUM_FAULT					-1//����
//#define STEPNUM_INIT					0//��ʼ��
//#define STEPNUM_STANDBY					1//����
//#define STEPNUM_INTO_READY				2//����׼��
//#define STEPNUM_READY					3//׼��
//#define STEPNUM_LASERON					4//���⿪ʼ



bit debugLed0, debugLed1, debugLed2, debugLed3;

void main(void){ 
	initDevice();
	sPlcInit();//��ʼ�����߼�
	//NVRAM0[EM_VGUS_WAVE_SEL] = 999;
	queue_reset();//���ָ����ջ�����
	delayMs(100);//��ʱ�ȴ���������ʼ�����,����ȴ�
	while(1){
		debugLed0 = ~debugLed0;
		sPlcProcessStart();
		if(LD(SPCOIL_START_UP)){//�ȴ�vGus����
			//FlashRestoreControl(FLASH_DATA_VERSION, FLASH_DATA_ADDR);//���Դ�FLASH�лָ�����
			RES(R_HMI_UPDATA_REQ);
			NVRAM0[EM_HMI_CMD_QUEUE] = 0;
		}
		NVRAM0[EM_HMI_CMD_QUEUE] = queue_find_cmd(hmiCmdBuffer, CMD_MAX_SIZE);//�ӻ������л�ȡһ��ָ��         
		if(NVRAM0[EM_HMI_CMD_QUEUE] > 0){ //���յ�ָ�� �����ж��Ƿ�Ϊ������ʾ                                                                           
			ProcessMessage((PCTRL_MSG)hmiCmdBuffer, NVRAM0[EM_HMI_CMD_QUEUE]);//ָ���  
		}                                                                           
		T10MS(T10MS_HMI_UPDATA, true, 2);//HMIˢ������
		if(LD(T_10MS_START * 16 + T10MS_HMI_UPDATA) || LD(R_HMI_UPDATA_REQ)){
			RES(R_HMI_UPDATA_REQ);
			T10MS(T10MS_HMI_UPDATA, false, 1);//ֹͣ��ʱ��
			UpdateUI();	
		}
		
#if CONFIG_SPLC_FUNTEST == 1
#endif
		sPlcProcessEnd();
	}
}


