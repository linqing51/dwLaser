#include "MainApp.h"
//#include "sPlcTest.h"
/*****************************************************************************/
//T0->SPLC
//T1->UART1
//T2->UART0
//T3->MODBUS
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
	 //Cache_ISR_Entry( (unsigned int) Timer0_ISR, Timer0_ISR_NUM);
	while(1){
		debugLed0 = ~debugLed0;
		sPlcProcessStart();
		if(LD(SPCOIL_START_UP)){//ִ��һ�εĴ���
			testBenchLaserTimer(2);
		}
#if CONFIG_USING_HMI == 1
		hmiLoop();
#endif
		
		//testBenchLaserTimer(1);
		//testBenchLaserTimer(2);
		//testBenchLaserTimer(3);
		//testBenchLaserTimer(4);
		//testBenchLaserTimer(5);
		//testBenchLaserTimer(6);
		//testBenchLaserTimer(7);
		//testBenchLaserTimer(8);
		//testBenchLaserTimer(9);
		//testBenchLaserTimer(10);
		//testBenchLaserTimer(11);
#if CONFIG_SPLC_FUNTEST == 1
#endif
		sPlcProcessEnd();
	}
}


