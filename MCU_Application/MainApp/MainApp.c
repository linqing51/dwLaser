#include "MainApp.h"
/*****************************************************************************/
//C8051F020 计时器功能定义
//TIMER0 ->SPLC
//TIMER1 ->Modbus RTU
//TIMER2 ->UART0 Buadrate
//TIMER3 ->NO FUNCTION
//TIMER4 ->UART1 Buadrate
/*****************************************************************************/
void sPlcBoxLedRefresh(void){//刷新灯状态
//0x81,00,01,......,84///控制绿色灯的亮灭.AA为亮，55为灭。
//0x81,00,02,......,84///控制红色灯的亮灭.AA为亮，55为灭。
//0x81,00,06,84//灯全灭
//0x81,00,09,xx,yy,zz,84//控制灯通道xx的灯的亮灭，zz=0时红绿灯都灭，zz=01,yy=00时红亮绿灭，zz=01,yy=01时红灭绿亮	
	uint8_t i;
	for(i = 0;i < 25;i ++){
		if((uint16_t)(NVRAM0[(EM_DAC_0 + i)]) > 0){
			SET(BOX_GLED_0 + i);
		}
		else{
			RES(BOX_GLED_0 + i);
		}
	}
	if(LDB(SPCOIL_UART1_SEND_BUSY) && LDB(R_BOX_GREEN_SENDED)){//刷新绿灯
		NVRAM0[BOX_SEND_BFADDR + 0] = BOX_CMD_STX;
		NVRAM0[BOX_SEND_BFADDR + 1] = 0x00;
		NVRAM0[BOX_SEND_BFADDR + 2] = 0x01;
		for(i = 3;i < 28;i ++){
			if(LD(R_START * 16 + i - 3)){
				NVRAM0[BOX_SEND_BFADDR + i] = 0xAA;
			}
			else{
				NVRAM0[BOX_SEND_BFADDR + i] = 0x55;
			}			
		}
		NVRAM0[(BOX_SEND_BFADDR + BOX_SEND_LENGTH - 1)] = 0x84;
		SET(R_BOX_GREEN_SENDED);
		RES(R_BOX_RED_SENDED);		
		USEND(SPLC_UART1, BOX_SEND_BFADDR, BOX_SEND_LENGTH);//启动发送
	}
	if(LDB(SPCOIL_UART1_SEND_BUSY) && LDB(R_BOX_RED_SENDED)){//刷新红灯
		NVRAM0[BOX_SEND_BFADDR + 0] = BOX_CMD_STX;
		NVRAM0[BOX_SEND_BFADDR + 1] = 0x00;
		NVRAM0[BOX_SEND_BFADDR + 2] = 0x02;
		for(i = 0;i < 25;i ++){ 
			if((NVRAM0[(EM_ADC_0 + i)] < 50) || (NVRAM0[(EM_ADC_0 + i)] > 4000) ||
			   (NVRAM0[(EM_ADC_32 + i)] <50) || (NVRAM0[(EM_ADC_32 + i)] > 4000) || LD(PLC_ALARM_0 + i)){
				NVRAM0[(BOX_SEND_BFADDR + i + 3)] = 0xAA;//红灯亮
				SET(BOX_RLED_0 + i);
			}
			else{
				NVRAM0[(BOX_SEND_BFADDR + i + 3)] = 0x55;//红灯灭
				RES(BOX_RLED_0 + i);
			}			
		}
		NVRAM0[(BOX_SEND_BFADDR + BOX_SEND_LENGTH - 1)] = 0x84;
		RES(R_BOX_GREEN_SENDED);
		SET(R_BOX_RED_SENDED);		
		USEND(SPLC_UART1, BOX_SEND_BFADDR, BOX_SEND_LENGTH);//启动发送				
	}
}
void main(void){
	initDeviceF020();
	sPlcInit();//初始化软逻辑
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
	ENABLE_INTERRUPT;
	while(1){
		sPlcProcessStart();
		if(LD(SPCOIL_START_UP)){//执行一次的代码
			RES(R_BOX_GREEN_SENDED);
			RES(R_BOX_RED_SENDED);
		}
		if(LD(SPCOIL_DELAY_DAC_INIT)){
			#if CONFIG_SPLC_USING_DAC == 1
			initChipDac();//初始化DAC模块
			#endif
			RES(SPCOIL_DELAY_DAC_INIT);
			SET(SPCOIL_DELAY_DAC_RUN);
			setLedDac(LED_ON);
		}
		if(LD(T_100MS_START * 16U + 0)){//每100mS执行一次BOX盒子刷新
			sPlcBoxLedRefresh();
			if(getLedRun()){
				setLedRun(LED_OFF);
			}
			else{
				setLedRun(LED_ON);
			}
			T100MS(0, false, 6);
		}
		else{
			T100MS(0, true, 6);
		}
		sPlcProcessEnd();
	}
}