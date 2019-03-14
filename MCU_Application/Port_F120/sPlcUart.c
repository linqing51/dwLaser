#include "sPlcUart.h"
/*****************************************************************************/
#if CONFIG_SPLC_USING_UART0 == 1
void initUart0(uint32_t baudrate){//初始化串口0
	uint8_t SFRPAGE_SAVE;
	SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE
	SFRPAGE = TMR2_PAGE;
	TMR2CN = 0x00;                      // Timer in 16-bit auto-reload up timer mode
	TMR2CF = 0x08;                      // SYSCLK is time base; no output up count only
	RCAP2 = -((long)CONFIG_SYSCLK / baudrate / 16);
	TMR2 = RCAP2;
	TR2= 1;                             // Start Timer2
	SFRPAGE = UART0_PAGE;
	SCON0 = 0x50;                       // 8-bit variable baud rate;
                                       // 9th bit ignored; RX enabled
                                       // clear all flags
	SSTA0 = 0x15;                       // Clear all flags; enable baud rate
                                       // doubler (not relevant for these
                                       // timers);
                                       // Use Timer2 as RX and TX baud rate
                                       // source;
	ES0 = 1;  
	IP |= 0x10;
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFRPAGE
}
#endif
#if CONFIG_SPLC_USING_UART1 == 1
void initUart1(uint32_t baudrate){
	uint8_t SFRPAGE_SAVE = SFRPAGE;        // Save Current SFR page
	SFRPAGE = UART1_PAGE;
	SCON1   = 0x10;                     // SCON1: mode 0, 8-bit UART, enable RX
	SFRPAGE = TIMER01_PAGE;
	TMOD   &= ~0xF0;
	TMOD   |=  0x20;                    // TMOD: timer 1, mode 2, 8-bit reload

	TH1 = -(CONFIG_SYSCLK / baudrate /2 / 48);
	CKCON &= ~0x13;                  // Clear all T1 related bits
	CKCON |=  0x02;                  // T1M = 0; SCA1:0 = 10		
	TL1 = TH1;                          // init Timer1
	TR1 = 1;                            // START Timer1
	EIE2      = 0x40;                   // Enable UART1 interrupts	 
}
#endif
void USSTP(uint8_t port){//串口强制停止发送
}
void URSTP(uint8_t port){//串口强制停止接收
}
void USEND(uint8_t port, uint8_t length){//串口启动发送
	uint8_t SFRPAGE_SAVE = SFRPAGE;        // Save Current SFR page
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
	uint8_t SFRPAGE_SAVE = SFRPAGE;        // Save Current SFR page
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
	enterSplcIsr();
	if(TI0){  
		TI0 = 0;
		if(NVRAM0[SPREG_UART0_SEND_NUM] < NVRAM0[SPREG_UART0_SEND_LENGTH]){//
			SBUF0 = UART0_TXBUF[((uint8_t)NVRAM0[SPREG_UART0_SEND_NUM])];          
			NVRAM0[SPREG_UART0_SEND_NUM] ++;						                   
        }
		else{
			SET(SPCOIL_UART0_SEND_DONE);//发送完成
			RES(SPCOIL_UART0_SEND_BUSY);
		}
    }
    if(RI0){
		RI0 = 0;
	    if(NVRAM0[SPREG_UART0_RECV_NUM] < NVRAM0[SPREG_UART0_RECV_LENGTH]){
			UART0_RXBUF[((uint8_t)NVRAM0[SPREG_UART0_RECV_NUM])] = SBUF0;
			NVRAM0[SPREG_UART0_RECV_NUM] ++;
		}
		else{
			REN0 = 0;//关闭接收
			SET(SPCOIL_UART0_RECV_DONE);//接收完成
			RES(SPCOIL_UART0_RECV_BUSY);
		}
	}   
	exitSplcIsr();	
}
#endif

#if CONFIG_SPLC_USING_UART1 == 1
void Uart1Isr(void) interrupt INTERRUPT_UART1 {//UART1中断
	enterSplcIsr();
	if(SCON1 & 0x02){//TI1 == 1  
		SCON1 &= 0xFD;//TI1 = 0
		if(NVRAM0[SPREG_UART1_SEND_NUM] < NVRAM0[SPREG_UART1_SEND_LENGTH]){//
			SBUF1 = UART1_TXBUF[(uint8_t)NVRAM0[SPREG_UART1_SEND_NUM]];          
			NVRAM0[SPREG_UART1_SEND_NUM] ++;						                   
        }
		else{
			SET(SPCOIL_UART1_SEND_DONE);//发送完成
			RES(SPCOIL_UART1_SEND_BUSY);
		}
    }
    if(SCON1 & 0x01){//RI1 == 1
        SCON1 &= 0xFE;//RI1 = 0
	    if(NVRAM0[SPREG_UART1_RECV_NUM] < NVRAM0[SPREG_UART1_RECV_LENGTH]){
			UART1_RXBUF[(uint8_t)NVRAM0[SPREG_UART1_RECV_NUM]] = SBUF1;
			NVRAM0[SPREG_UART1_RECV_NUM] ++;
		}
		else{
			SCON1 &= 0xEF;//REN1 = 0 关闭接收
			SET(SPCOIL_UART1_RECV_DONE);//接收完成
			RES(SPCOIL_UART1_RECV_BUSY);
		}
	}   
	exitSplcIsr();
}
#endif