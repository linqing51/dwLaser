#include "MainApp.h"
#include "vGus.h"
//#include "sPlcTest.h"
/*****************************************************************************/
//T0->PCA
//T1->UART0/UART1
//T2->MODBUS
//T3->SPLC
//T4->LASER
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
	while(1){
		debugLed0 = ~debugLed0;
		sPlcProcessStart();
		if(LD(SPCOIL_START_UP)){//ִ��һ�εĴ���
			RES(R_VGUS_UPLOAD_DONE);
			RES(R_VGUS_UPLOAD_DOING);
			RES(R_VGUS_POWERON_DONE);
			RES(R_VGUS_POWERON_DOING);
		}
		vGusWaitPowerOn();//�ȴ�vGus�ϵ�
		
//		if(LD(R_VGUS_POWERON_DONE)){//vGus����
//			vGusInit();
//		}
//		if(LD(R_VGUS_INIT_DONE)){
//			vGusUpload();//vGus�����ϴ�
//		}
#if CONFIG_SPLC_FUNTEST == 1
#endif
		sPlcProcessEnd();
	}
}


