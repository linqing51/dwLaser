/*****************************************************************************/
#include "hmiUserUart.h"
/*****************************************************************************/
void hmiUartSendChar(uint8_t t){//UART1����
	uint8_t SFRPAGE_SAVE = SFRPAGE;        // Save Current SFR page
	SFRPAGE = UART1_PAGE;
//	SCON1 &= ~(1 << 4);//REN = 0
//	SCON1 &= 0xFD;//TI1 = 0
	//EIE2 &= ~(1 << 6);//�رմ����ж�
	SCON1 &= 0xFD;//TI1 = 0
	SBUF1 = t;
    while(!(SCON1 & 0x02));
	SCON1 &= 0xFD;//TI1 = 0
	//EIE2 |= 1 << 6;
	//
	//	SCON1 |= 1 << 4;//REN = 1
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page   
} 

#if CONFIG_SPLC_USING_UART1 == 1
void Uart1Isr(void) interrupt INTERRUPT_UART1 {//UART1�ж�
	if(SCON1 & 0x01){//RI1 == 1
		SCON1 &= 0xFE;//RI1 = 0
		queue_push(SBUF1);//ѹ�뵽ָ�����
	}
}
#endif