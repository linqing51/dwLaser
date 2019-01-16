#include "MainApp.h"
/*****************************************************************************/
//C8051F020 计时器功能定义
//TIMER0 ->SPLC
//TIMER1 ->Modbus RTU
//TIMER2 ->UART0 Buadrate
//TIMER3 ->NO FUNCTION
//TIMER4 ->UART1 Buadrate
/*****************************************************************************/
bit debugLed0, debugLed1, debugLed2, debugLed3, debugLed4;
void sPlcBoxLedRefresh(void){//刷新灯状态
//0x81,00,01,......,84///控制绿色灯的亮灭.AA为亮，55为灭。
//0x81,00,02,......,84///控制红色灯的亮灭.AA为亮，55为灭。
//0x81,00,06,84//灯全灭
//0x81,00,09,xx,yy,zz,84//控制灯通道xx的灯的亮灭，zz=0时红绿灯都灭，zz=01,yy=00时红亮绿灭，zz=01,yy=01时红灭绿亮	
	uint8_t i;	
	if(LDB(SPCOIL_UART1_SEND_BUSY) && LDB(R_BOX_GREEN_SENDED)){//刷新绿灯
		NVRAM0[BOX_SEND_BFADDR + 0] = BOX_CMD_STX;
		NVRAM0[BOX_SEND_BFADDR + 1] = 0x00;
		NVRAM0[BOX_SEND_BFADDR + 2] = 0x01;
		for(i = 3;i < 28;i ++){
			if(LD(R_START * 16 + i)){
				NVRAM0[BOX_SEND_BFADDR + i] = 0xAA;
			}
			else{
				NVRAM0[BOX_SEND_BFADDR + i] = 0x55;
			}			
		}
		NVRAM0[BOX_SEND_BFADDR + 28] = 0x84;
		USEND(SPLC_UART1, BOX_SEND_BFADDR, BOX_SEND_LENGTH);//启动发送
		SET(R_BOX_GREEN_SENDED);
		RES(R_BOX_RED_SENDED);
	}
	if(LDB(SPCOIL_UART1_SEND_BUSY) && LDB(R_BOX_RED_SENDED)){//刷新红灯
		NVRAM0[BOX_SEND_BFADDR + 0] = BOX_CMD_STX;
		NVRAM0[BOX_SEND_BFADDR + 1] = 0x00;
		NVRAM0[BOX_SEND_BFADDR + 2] = 0x02;
		for(i = 3;i < 28;i ++){
			if(LD(R_START * 16 + 32 + i)){
				NVRAM0[BOX_SEND_BFADDR + i] = 0xAA;
			}
			else{
				NVRAM0[BOX_SEND_BFADDR + i] = 0x55;
			}			
		}
		NVRAM0[BOX_SEND_BFADDR + 28] = 0x84;
		USEND(SPLC_UART1, BOX_SEND_BFADDR, BOX_SEND_LENGTH);//启动发送
		RES(R_BOX_GREEN_SENDED);
		SET(R_BOX_RED_SENDED);
	}
}

void main(void){
	uint8_t runOnce;
	initDeviceF020();
	sPlcInit();//初始化软逻辑
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
	ENABLE_INTERRUPT;
	runOnce = 0;
	while(1){
		debugLed2 = true;
		sPlcProcessStart();
		debugLed2 = false;
		if(runOnce == 0){//执行一次的代码
			NVRAM0[EM_END] = CONFIG_CHECK_CODE;
			RES(R_BOX_GREEN_SENDED);
			RES(R_BOX_RED_SENDED);
			runOnce = true;
		}
		if(LD(T_100MS_START * 16U + 0)){//每100mS执行一次BOX盒子刷新
			debugLed1 = true;
			sPlcBoxLedRefresh();
			T100MS(0, false, 1);
			debugLed1 = false;
		}
		else{
			T100MS(0, true, 1);
		}
		debugLed3 = true;
		sPlcProcessEnd();
		debugLed3 = false;
		debugLed0 = ~debugLed0;
	}
}