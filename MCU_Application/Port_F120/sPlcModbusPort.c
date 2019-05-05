#include "sPlcModbusPort.h"
#if CONFIG_USING_RTU_SLAVE == 1
/*****************************************************************************/
xdata uint8_t *pSendBuf;
/*****************************************************************************/
void initModbusTimer(void){//初始化MODBUS计时器 1mS TIMER1
	xdata uint16_t temp;
	xdata uint8_t SFRPAGE_SAVE;
	SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE
	SFRPAGE = TMR3_PAGE;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 12 / CONFIG_MB_RTU_SLAVE_TICK));
	TMR3CF = 0;//	
	RCAP3 = temp;// Reload value to be used in Timer3
	TMR3 = RCAP3;// Init the Timer3 register
	TMR3CN = 0;//16Bit AutoReload
	TMR3CN |= 1 << 2;//TR3 RUN
	SFRPAGE = SFRPAGE_SAVE;  
	EIE2 |= (1 << 0);// Timer3 interrupt enabled 
}
void modBusUartInitialise(uint32_t baudrate){// UART Initialize for Microconrollers, yes you can use another phsycal layer!
	baudrate = ~baudrate;
}
void modBusTimerInitialise(void){// Timer Initialize for Petit Modbus, 1ms Timer will be good for us!
    initModbusTimer();
}
uint8_t modBusUartString(uint8_t *s, uint16_t  Length){// This is used for send string, better to use DMA for it ;)
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;        // Save Current SFR page
	SFRPAGE = UART0_PAGE;
	pSendBuf = s;	
	NVRAM0[SPREG_UART0_SEND_LENGTH] = Length;
	NVRAM0[SPREG_UART0_SEND_NUM] = 0x0;
	SET(SPCOIL_UART0_SEND_BUSY);
	RES(SPCOIL_UART0_SEND_DONE);
	TI0 = 1;//开始发送			
	SFRPAGE = SFRPAGE_SAVE;
	return true;
}
void receiveInterrupt(uint8_t Data){//Call this function into your UART Interrupt. Collect data from it!
    modbusReceiveBuffer[modbusReceiveCounter] = Data;
    modbusReceiveCounter ++;
    if(modbusReceiveCounter > CONFIG_MB_RTU_SLAVE_BUFFER_SIZE){  
        modbusReceiveCounter = 0;
	}
    modbusTimerValue = 0;
}
/******************************************************************************/
static void modbusHandle() interrupt INTERRUPT_TIMER3
{//硬件计时器TIMER1中断函数 1mS
	modbusTimerDebug = ~modbusTimerDebug;
	TMR3CN &= 0x7F;//Overflow Underflow Flag Clear
	modbusTimerValue ++;
}

#if (CONFIG_USING_RTU_SLAVE == 1 && CONFIG_MB_PORT == UART0)
void Uart0Isr(void) interrupt INTERRUPT_UART0 {//UART0中断
	if(RI0){
		RI0 = 0;	
		receiveInterrupt(SBUF0);
	}
	if(TI0){
		TI0 = 0;
		if(NVRAM0[SPREG_UART0_SEND_NUM] < NVRAM0[SPREG_UART0_SEND_LENGTH]){//
            SBUF0 = *(pSendBuf + NVRAM0[SPREG_UART0_SEND_NUM]);
			NVRAM0[SPREG_UART0_SEND_NUM] ++;						                   
		}
		else{
			SET(SPCOIL_UART0_SEND_DONE);//发送完成
			RES(SPCOIL_UART0_SEND_BUSY);
		}
	}	
}
void Uart0DIR(uint8_t dir){
	if(dir){
	}
	else{
	}
}
#endif

#if (CONFIG_USING_RTU_SLAVE == 1 && CONFIG_MB_PORT == UART1)
void Uart1Isr(void) interrupt INTERRUPT_UART1 {//UART1中断
	if(SCON1 & 0x01){//RI1 == 1
		SCON1 &= 0xFE;//RI1 = 0	
		receiveInterrupt(SBUF1);
	}
	if(SCON1 & 0x02){//TI1 == 1  
		SCON1 &= 0xFD;//TI1 = 0
		if(NVRAM0[SPREG_UART1_SEND_NUM] < NVRAM0[SPREG_UART1_SEND_LENGTH]){//
            SBUF1 = *(pSendBuf + NVRAM0[SPREG_UART1_SEND_NUM]);
			NVRAM0[SPREG_UART1_SEND_NUM] ++;						                   
		}
		else{
			SET(SPCOIL_UART1_SEND_DONE);//发送完成
			RES(SPCOIL_UART1_SEND_BUSY);
		}
	}
}
#endif

#endif

