/*****************************************************************************/
#include "hmiUserUart.h"
/*****************************************************************************/
void hmiUartSendChar(uint8_t t){//UART1发送
//	uint8_t SFRPAGE_SAVE = SFRPAGE;        // Save Current SFR page
//	SFRPAGE = UART1_PAGE;   
//	EIE2 = ~(1<< 6);
//	SBUF1 = t;
//    while((SCON1 & 0x02) == 0);
//	SCON1 &= 0xFD;//TI1 = 0  
//	EIE2 |= 1 << 6;
//	SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page   

	uint8_t SFRPAGE_SAVE = SFRPAGE;        // Save Current SFR page
	SFRPAGE = UART0_PAGE;   
	//EIE2 = ~(1<< 6);
	SBUF0 = t;
    while(!TI0);
	TI0 = 0;  
	//EIE2 |= 1 << 6;
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page 	
} 

#if CONFIG_SPLC_USING_UART1 == 1
void Uart0Isr(void) interrupt INTERRUPT_UART0 {//UART1中断
	//if(SCON1 & 0x02){//TI1 == 1  
	//	SCON1 &= 0xFD;//TI1 = 0
	//}
//	if(SCON1 & 0x01){//RI1 == 1
//		SCON1 &= 0xFE;//RI1 = 0
//		queue_push(SBUF1);//压入到指令缓冲区
//	}
	
	if(RI){//RI1 == 1
		RI = 0;
		queue_push(SBUF0);//压入到指令缓冲区
	}
}
#endif