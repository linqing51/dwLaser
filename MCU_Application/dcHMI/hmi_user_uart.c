/************************************��Ȩ����********************************************
**                             ���ݴ�ʹ��Ƽ����޹�˾
**                             http://www.gz-dc.com
**-----------------------------------�ļ���Ϣ--------------------------------------------
** �ļ�����:   hmi_user_uart.c
** �޸�ʱ��:   2018-05-18
** �ļ�˵��:   �û�MCU��������������
** ����֧�֣�  Tel: 020-82186683  Email: hmi@gz-dc.com Web:www.gz-dc.com
--------------------------------------------------------------------------------------*/
#include "hmi_user_uart.h"
extern void queue_push(qdata _data);
void initHmiUart1(uint32_t baudrate){
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
	RES(SPCOIL_UART1_SEND_BUSY);
	RES(SPCOIL_UART1_SEND_DONE);	
}

void  hmiUart1SendChar(uint8_t t){
    SBUF1 = t;
    while((SCON1 & 0x02) == 0);
	SCON1 &= 0xFD;//TI1 = 0      
} 


void hmiUart1Isr(void) interrupt INTERRUPT_UART1 {//UART1�ж�
	enterSplcIsr();
    if(SCON1 & 0x01){//RI1 == 1
        SCON1 &= 0xFE;//RI1 = 0
	    queue_push(SBUF);//ѹ�뵽ָ�����
	}		
	exitSplcIsr();
}