#include "MainApp.h"
/*****************************************************************************/
//C8051F020 ��ʱ�����ܶ���
//TIMER0 ->SPLC
//TIMER1 ->Modbus RTU
//TIMER2 ->UART0 Buadrate
//TIMER3 ->
//TIMER4 ->UART1 Buadrate
/*****************************************************************************/
//sbit LED_MCU = P2^3;//������ָʾLED
//sbit LED_LASER0 = P1^7;//���ⷢ��ָʾLED0 980nM
//sbit LED_LASER1 = P1^6;//���ⷢ��ָʾLED1 1470nM
//sbit TP0, TP1, TP2, TP3;
/*****************************************************************************/
#define EM_SLD_0								0//LD���üĴ���
#define EM_SLD_31								31
#define EM_MPD_0								32//PD��ȡ�Ĵ���
#define EM_MPD_31								63
#define EM_MLD_0								64//LD��ȡ�Ĵ���
#define EM_MLD_31								95
/*****************************************************************************/
void main(void){
	uint8_t i;
#ifdef C8051F020
	initDeviceF020();
#endif
	sPlcInit();//��ʼ�����߼�
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
	NVRAM0[0] = 0xA5;
	NVRAM0[1] = 0x5A;
	ENABLE_INTERRUPT;
	while(1){
		sPlcProcessStart();
		for(i = 0;i < 25;i ++){
			if(NVRAM0[(EM_START + EM_SLD_0)] <= 1000 && NVRAM0[(EM_START + EM_SLD_0)] >= 0){
				//NVRAM0[(SPREG_START + SPREG_DAC_0)] = (int16_t)((int32_t)NVRAM0[(EM_START + EM_LD_0)] * 100L * 4096L / 1000L);
			}	
		}
	
		//SPLC�������˴�
////		SET(10);
////		RESET(10);
////		SET(10);
////		RESET(10);
////		SET(10);
////		RESET(10);
////		SET(10);
////		RESET(10);
////		FLIP(10);
////		FLIP(10);
////		FLIP(10);
////		FLIP(10);
////		//��ȡIO
////		//ִ�г���
////		//���IO
////		T100MS(0, 1, 2);
////		if(LD(TD_100MS_START * 16 + 0));
////		{
////			SET(0);	
////		}
		sPlcProcessEnd();
	}
}
