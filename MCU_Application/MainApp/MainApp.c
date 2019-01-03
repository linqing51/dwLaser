#include "MainApp.h"
/*****************************************************************************/
//C8051F020 ��ʱ�����ܶ���
//TIMER0 ->SPLC
//TIMER1 ->Modbus RTU
//TIMER2 ->UART0 Buadrate
//TIMER3 ->NO FUNCTION
//TIMER4 ->UART1 Buadrate
/*****************************************************************************/

void main(void){
	initDeviceF020();
	sPlcInit();//��ʼ�����߼�
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
	initboxSerial(CONFIG_UART1_BAUDRATE);
	ENABLE_INTERRUPT;
	while(1){
		sPlcProcessStart();
		if(LD(T_100MS_START * 16 + 0)){//ÿ100mSִ��һ��BOX����ˢ��
			boxRedLedRefresh();
			boxGreenLedRefresh();
			T100MS(0, 0, 1);
		}
		else{
			T100MS(0, 1, 1);
		}
		sPlcProcessEnd();

	}
}