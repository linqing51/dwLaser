#include "MainApp.h"
/*****************************************************************************/
//C8051F020 计时器功能定义
//TIMER0 ->SPLC
//TIMER1 ->Modbus RTU
//TIMER2 ->UART0 Buadrate
//TIMER3 ->
//TIMER4 ->UART1 Buadrate
/*****************************************************************************/
//sbit LED_MCU = P2^3;//处理器指示LED
//sbit LED_LASER0 = P1^7;//激光发射指示LED0 980nM
//sbit LED_LASER1 = P1^6;//激光发射指示LED1 1470nM
//sbit TP0, TP1, TP2, TP3;
/*****************************************************************************/
#define EM_LD_0							0
#define EM_LD_1							1
#define EM_LD_2							2
#define EM_LD_3							3
#define EM_LD_4							4
#define EM_LD_5							4
#define EM_LD_6							4
#define EM_LD_7							4

/*****************************************************************************/
void main(void){
#ifdef C8051F020
	initDeviceF020();
#endif
	sPlcInit();//初始化软逻辑
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
	NVRAM0[0] = 0xA5;
	NVRAM0[1] = 0x5A;
	ENABLE_INTERRUPT;
	while(1){
		sPlcProcessStart();
		//LD0:100.0%->DAC CODE
		if(NVRAM0[(EM_START + EM_LD_0)] <= 1000 && NVRAM0[(EM_START + EM_LD_0)] >= 0){
			NVRAM0[(SPREG_START + SPREG_DAC_0)] = (int16_t)((int32_t)NVRAM0[(EM_START + EM_LD_0)] * 100L * 4096L / 1000L);
		}
		//LD1:100.0%->DAC CODE
		if(NVRAM0[(EM_START + EM_LD_1)] <= 1000 && NVRAM0[(EM_START + EM_LD_1)] >= 0){
			NVRAM0[(SPREG_START + SPREG_DAC_1)] = (int16_t)((int32_t)NVRAM0[(EM_START + EM_LD_1)] * 100L * 4096L / 1000L);
		}
		//LD2:100.0%->DAC CODE
		if(NVRAM0[(EM_START + EM_LD_2)] <= 1000 && NVRAM0[(EM_START + EM_LD_2)] >= 0){
			NVRAM0[(SPREG_START + SPREG_DAC_2)] = (int16_t)((int32_t)NVRAM0[(EM_START + EM_LD_2)] * 100L * 4096L / 1000L);
		}
		//LD3:100.0%->DAC CODE
		if(NVRAM0[(EM_START + EM_LD_3)] <= 1000 && NVRAM0[(EM_START + EM_LD_3)] >= 0){
			NVRAM0[(SPREG_START + SPREG_DAC_3)] = (int16_t)((int32_t)NVRAM0[(EM_START + EM_LD_3)] * 100L * 4096L / 1000L);
		}
		//LD4:100.0%->DAC CODE
		if(NVRAM0[(EM_START + EM_LD_4)] <= 1000 && NVRAM0[(EM_START + EM_LD_4)] >= 0){
			NVRAM0[(SPREG_START + SPREG_DAC_4)] = (int16_t)((int32_t)NVRAM0[(EM_START + EM_LD_4)] * 100L * 4096L / 1000L);
		}
		//LD5:100.0%->DAC CODE
		if(NVRAM0[(EM_START + EM_LD_5)] <= 1000 && NVRAM0[(EM_START + EM_LD_5)] >= 0){
			NVRAM0[(SPREG_START + SPREG_DAC_5)] = (int16_t)((int32_t)NVRAM0[(EM_START + EM_LD_5)] * 100L * 4096L / 1000L);
		}
		//LD6:100.0%->DAC CODE
		if(NVRAM0[(EM_START + EM_LD_6)] <= 1000 && NVRAM0[(EM_START + EM_LD_6)] >= 0){
			NVRAM0[(SPREG_START + SPREG_DAC_6)] = (int16_t)((int32_t)NVRAM0[(EM_START + EM_LD_6)] * 100L * 4096L / 1000L);
		}
		//LD7:100.0%->DAC CODE
		if(NVRAM0[(EM_START + EM_LD_7)] <= 1000 && NVRAM0[(EM_START + EM_LD_7)] >= 0){
			NVRAM0[(SPREG_START + SPREG_DAC_7)] = (int16_t)((int32_t)NVRAM0[(EM_START + EM_LD_7)] * 100L * 4096L / 1000L);
		}	
		//SPLC代码插入此处
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
////		//读取IO
////		//执行程序
////		//输出IO
////		T100MS(0, 1, 2);
////		if(LD(TD_100MS_START * 16 + 0));
////		{
////			SET(0);	
////		}
		sPlcProcessEnd();
	}
}
