/*****************************************************************************/
#include "hmiUserUart.h"
/*****************************************************************************/
void hmiUartSendChar(uint8_t t){//UART1发送
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;        // Save Current SFR page
	SFRPAGE = UART1_PAGE;
	EIE2 &= ~(1 << 6);//关闭中断
	SBUF1 = t;
    while((SCON1 & 0x02) == 0);
	SCON1 &= 0xFD;//TI1 = 0
	EIE2 |= (1 << 6);//打开中断
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page   
 	
} 

#if CONFIG_SPLC_USING_UART1 == 1
void Uart0Isr(void) interrupt INTERRUPT_UART0 {//UART1中断
	if(SCON1 & 0x01){//RI1 == 1
		SCON1 &= 0xFE;//RI1 = 0
		queue_push(SBUF1);//压入到指令缓冲区
	}
	

}
#endif