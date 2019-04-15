#include "MainApp.h"
/*****************************************************************************/
//T0->SPLC
//T1->UART1
//T2->UART0
//T3->MODBUS
//T4->LASER
//*****************************************************************************/
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
	//ָʾ��ȫ��
	SET(Y_LED_POWERON);SET(Y_LED_EMIT);SET(Y_LED_ALARM);
	delayMs(20);
	RES(Y_LED_POWERON);RES(Y_LED_EMIT);RES(Y_LED_ALARM);
	delayMs(20);
	SET(Y_LED_POWERON);SET(Y_LED_EMIT);SET(Y_LED_ALARM);
	delayMs(20);
	SET(Y_LED_POWERON);RES(Y_LED_EMIT);RES(Y_LED_ALARM);
	//Cache_ISR_Entry( (unsigned int) Timer0_ISR, Timer0_ISR_NUM);
	while(1){
		debugLed0 = ~debugLed0;
		sPlcProcessStart();
		if(LD(SPCOIL_START_UP)){//ִ��һ�εĴ���
			//testBenchLaserTimer(11);
			//testBenchBeem(50, 1);
			
		}
#if CONFIG_USING_HMI == 1
		hmiLoop();
#endif
#if CONFIG_SPLC_FUNTEST == 1
#endif
		sPlcProcessEnd();
	}
}


