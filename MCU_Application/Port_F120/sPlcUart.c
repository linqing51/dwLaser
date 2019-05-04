#include "sPlcUart.h"
/*****************************************************************************/
#if CONFIG_SPLC_USING_UART0 == 1
/*****************************************************************************/
uint8_t (*UART0_TX_CALLBACK)(void);//发送回调 
void (*UART0_RX_CALLBACK)(uint8_t dat);
uint8_t (*UART1_TX_CALLBACK)(void);//发送回调 
void (*UART1_RX_CALLBACK)(uint8_t dat);
/*****************************************************************************/
void initUart0(uint32_t baudrate){//初始化串口0
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE	
	xdata uint16_t temp;
	UART0_TX_CALLBACK = NULL;
	UART0_RX_CALLBACK = NULL;
	SFRPAGE = TMR2_PAGE;// Set SFR page
	temp =(uint16_t)(65536 - CONFIG_SYSCLK / 12 /16 / baudrate);
	TMR2CF = 0;//	
	RCAP2 = temp;//Reload value to be used in Timer2
	TMR2 = RCAP2;//Init the Timer2 register
	TMR2CN = 0x0;//16Bit AutoReload
	TMR2CN |= 1 << 2;//TR2 RUN
	SFRPAGE = UART0_PAGE;
	SCON0 = 0x50;// 8-bit variable baud rate;
	SSTA0 = 0;//T1->UART0
	SSTA0 |= (1 << 2);//Timer 2 Overflow generates UART0 TX baud rate
	SSTA0 |= (1 << 0);//Timer 2 Overflow generates UART0 RX baud rate
	SSTA0 |= 1 << 4;//UART0 baud rate divide-by-two disabled.
	IP |= (1 << 4);//UART0 Interrupt Priority Control
	ES0 = 1;
	TI0 = 0;//清除发送完成   		
	RI0 = 0;//清除接收完成	
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFRPAGE
	RES(SPCOIL_UART0_SEND_BUSY);
	RES(SPCOIL_UART0_SEND_DONE);
}
#endif

#if CONFIG_SPLC_USING_UART1 == 1
void initUart1(uint32_t baudrate){
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;        // Save Current SFR page
	UART1_TX_CALLBACK = NULL;
	UART1_RX_CALLBACK = NULL;
	SFRPAGE = UART1_PAGE;
	SCON1 = 0x10; 
	SCON1 |= 1 << 1;//TI1 = 1
	// SCON1: mode 0, 8-bit UART, enable RX
	SFRPAGE = TIMER01_PAGE;
	TMOD &= ~0xF0;
	TMOD |=  0x20;                    // TMOD: timer 1, mode 2, 8-bit reload
	TH1 = -(CONFIG_SYSCLK / baudrate / 2 / 48);
	CKCON &= ~0x13;                  // Clear all T1 related bits
    CKCON |=  0x02;                  // T1M = 0; SCA1:0 = 10
	TL1 = TH1;                          // init Timer1
	TR1 = 1;                            // START Timer1	
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
	EIE2 = 0x40;// Enable UART1 interrupts
	RES(SPCOIL_UART1_SEND_BUSY);
	RES(SPCOIL_UART1_SEND_DONE);
}
#endif


void USSTP(uint8_t port){//串口强制停止发送
	if(port == UART0){
		NVRAM0[SPREG_UART0_SEND_LENGTH] = 0x0;
		NVRAM0[SPREG_UART0_SEND_NUM] = 0x0;
		RES(SPCOIL_UART0_SEND_BUSY);
		RES(SPCOIL_UART0_SEND_DONE);
	}
	if(port == UART1){
		NVRAM0[SPREG_UART1_SEND_LENGTH] = 0x0;
		NVRAM0[SPREG_UART1_SEND_NUM] = 0x0;
		RES(SPCOIL_UART1_SEND_BUSY);
		RES(SPCOIL_UART1_SEND_DONE);	
	}
}
void URSTP(uint8_t port){//串口强制停止接收
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;        // Save Current SFR page
	SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE
	if(port == UART0){
		NVRAM0[SPREG_UART0_RECV_LENGTH] = 0x0;
		NVRAM0[SPREG_UART0_RECV_NUM] = 0x0;
		RES(SPCOIL_UART0_RECV_BUSY);
		RES(SPCOIL_UART0_RECV_DONE);
		SFRPAGE = UART0_PAGE;
		RI0 = false;//关闭接收
		SFRPAGE = SFRPAGE_SAVE;
	}
	if(port == UART1){
		NVRAM0[SPREG_UART1_RECV_LENGTH] = 0x0;
		NVRAM0[SPREG_UART1_RECV_NUM] = 0x0;
		RES(SPCOIL_UART1_RECV_BUSY);
		RES(SPCOIL_UART1_RECV_DONE);
		SFRPAGE = UART1_PAGE;
		SCON1 &=0xEF;//REN1 = 0关闭接收
		SFRPAGE = SFRPAGE_SAVE;
	}
}
void USEND(uint8_t port, uint8_t length){//串口启动发送
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;        // Save Current SFR page
	SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE
	if(port == UART0){
		NVRAM0[SPREG_UART0_SEND_LENGTH] = length;
		NVRAM0[SPREG_UART0_SEND_NUM] = 0x0;
		SET(SPCOIL_UART0_SEND_BUSY);
		RES(SPCOIL_UART0_SEND_DONE);
		SFRPAGE = UART0_PAGE;
		TI0 = 1;//发送
		SFRPAGE = SFRPAGE_SAVE;
	}
	if(port == UART1){
		NVRAM0[SPREG_UART1_SEND_LENGTH] = length;
		NVRAM0[SPREG_UART1_SEND_NUM] = 0x0;
		SET(SPCOIL_UART1_SEND_BUSY);
		RES(SPCOIL_UART1_SEND_DONE);
		SFRPAGE = UART1_PAGE;
		SCON1 |= 0x02;//开始发送
		SFRPAGE = SFRPAGE_SAVE;		
	}
}
void URECV(uint8_t port, uint8_t length){//串口接收
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;        // Save Current SFR page
	SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE
	if(port == UART0){
		NVRAM0[SPREG_UART0_RECV_LENGTH] = length;
		NVRAM0[SPREG_UART0_RECV_NUM] = 0x0;
		SET(SPCOIL_UART0_RECV_BUSY);
		RES(SPCOIL_UART0_RECV_DONE);
		SFRPAGE = UART0_PAGE;
		RI0 = 1;//接收
		SFRPAGE = SFRPAGE_SAVE;
	}
	if(port == UART1){
		NVRAM0[SPREG_UART1_RECV_LENGTH] = length;
		NVRAM0[SPREG_UART1_RECV_NUM] = 0x0;
		SET(SPCOIL_UART1_RECV_BUSY);
		RES(SPCOIL_UART1_RECV_DONE);
		SFRPAGE = UART1_PAGE;
		SCON1 |=0x10;//REN1 = 1 开发接收
		SFRPAGE = SFRPAGE_SAVE;
	}
}

#if CONFIG_SPLC_USING_UART0 == 1
void Uart0Isr(void) interrupt INTERRUPT_UART0 {//UART0中断
	if(TI0){  
		TI0 = 0;
		if(UART0_TX_CALLBACK != NULL){
			SBUF0 = (*UART0_TX_CALLBACK)();//发送回调
		}
    }
    if(RI0){
		RI0 = 0;
		if(UART0_RX_CALLBACK != NULL){
			(*UART0_RX_CALLBACK)(SBUF0);//接收回调
		}
	}	
}
#endif

#if CONFIG_SPLC_USING_UART1 == 1
void Uart1Isr(void) interrupt INTERRUPT_UART1 {//UART1中断
	if(SCON1 & 0x02){//TI1 == 1  
		SCON1 &= 0xFD;//TI1 = 0
		if(UART1_TX_CALLBACK != NULL){
			SBUF0 = (*UART1_TX_CALLBACK)();
		}
    }
	if(SCON1 & 0x01){//RI1 == 1
		SCON1 &= 0xFE;//RI1 = 0
		if(UART1_RX_CALLBACK != NULL){
			(*UART1_RX_CALLBACK)(SBUF0);
		}
	} 
}
#endif

void UDIRX(uint8_t port){//关闭串口接收中断
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;// Preserve SFRPAGE
	if(port == UART0){
		SFRPAGE = UART0_PAGE;
		SCON0 &= 0xEF;//UART0 reception disabled
		SFRPAGE = SFRPAGE_SAVE;		
	}
	if(port == UART1){
		SFRPAGE = UART1_PAGE;
		SCON1 &= 0xEF;//UART0 reception disabled
		SFRPAGE = SFRPAGE_SAVE;
	}
}
void UENRX(uint8_t port){//打开串口接收中断
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;// Preserve SFRPAGE	
	if(port == UART0){
		SFRPAGE = UART0_PAGE;
		SCON0 |= 0x10;//UART0 reception enabled.
		SFRPAGE = SFRPAGE_SAVE;
	}
	if(port == UART1){
		SFRPAGE = UART1_PAGE;
		SCON1 |= 0x10;//UART1 reception enabled.
		SFRPAGE = SFRPAGE_SAVE;
	}
}
