#include "MainApp.h"
/*****************************************************************************/
//C8051F020 ��ʱ�����ܶ���
//TIMER0 ->SPLC
//TIMER1 ->Modbus RTU
//TIMER2 ->UART0 Buadrate
//TIMER3 ->NO FUNCTION
//TIMER4 ->UART1 Buadrate
/*****************************************************************************/
bit debugLed0, debugLed1, debugLed2, debugLed3;
void main(void){
	initDeviceF020();
	sPlcInit();//��ʼ�����߼�
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
	initboxSerial(CONFIG_UART1_BAUDRATE);
	ENABLE_INTERRUPT;
	while(1){
		sPlcProcessStart();	
		if(LD(T_100MS_START * 16U + 0)){//ÿ100mSִ��һ��BOX����ˢ��
			debugLed1 = true;
			boxRedLedRefresh();
			boxGreenLedRefresh();
			T100MS(0, false, 1);
			debugLed1 = false;
		}
		else{
			T100MS(0, true, 1);
		}
		sPlcProcessEnd();
		debugLed0 = ~debugLed0;
	}
}