/*****************************************************************************/
#include "hmiUserUart.h"
/*****************************************************************************/
void hmiUartSendChar(uint8_t t){//UART1����
    SBUF1 = t;
    while((SCON1 & 0x02) == 0);
	SCON1 &= 0xFD;//TI1 = 0      
} 
//void hmiUartIsr(void) interrupt INTERRUPT_UART1 {//UART1�ж�
//	//enterSplcIsr();
//    if(SCON1 & 0x01){//RI1 == 1
//        SCON1 &= 0xFE;//RI1 = 0
//	    queue_push(SBUF);//ѹ�뵽ָ�����
//	}		
//	//exitSplcIsr();
//}