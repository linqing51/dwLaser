#include "sPlcUart.h"
/*****************************************************************************/
void USSTP(uint16_t port){//����ǿ��ֹͣ����
}
void USEND(uint16_t port, uint16_t sendBufAdr, uint16_t length){//������������
	if(port == 0){
	}
	if(port == 1){
		NVRAM0[SPREG_UART1_SEND_BUFFER_ADR] = sendBufAdr;
		NVRAM0[SPREG_UART1_SEND_LENGTH] = length;
		NVRAM0[SPREG_UART1_SEND_NUM] = 0x0;
		SET(SPCOIL_UART1_SEND_BUSY);
		RES(SPCOIL_UART1_SEND_DONE);
		SCON1 |= 0x02;//��ʼ����			
	}
}
void URSTP(uint16_t port){//����ǿ��ֹͣ����
	
}
void URECV(uint16_t port, uint16_t recvBufAdr, uint16_t length){//���ڽ���
	if(port == 0){
	}
	if(port == 1){
		NVRAM0[SPREG_UART1_RECV_BUFFER_ADR] = recvBufAdr;
		NVRAM0[SPREG_UART1_RECV_LENGTH] = length;
		NVRAM0[SPREG_UART1_RECV_NUM] = 0x0;
		SET(SPCOIL_UART1_RECV_BUSY);
		RES(SPCOIL_UART1_RECV_DONE);
		SCON1 |=0x10;//REN1 = 1 ��������
	}
}
void Uart1Isr() interrupt INTERRUPT_UART1{//UART1�ж�
	enterSplcIsr();
	if(SCON1 & 0x02){//TI1 == 1  
		SCON1 &= 0xFD;//TI1 = 0
		if(NVRAM0[SPREG_UART1_SEND_NUM] < NVRAM0[SPREG_UART1_SEND_LENGTH]){//
            SBUF1 = (uint8_t)NVRAM0[(NVRAM0[SPREG_UART1_SEND_BUFFER_ADR] + NVRAM0[SPREG_UART1_SEND_NUM])];
			NVRAM0[SPREG_UART1_SEND_NUM] ++;						                   
        }
		else{
			SET(SPCOIL_UART1_SEND_DONE);//�������
			RES(SPCOIL_UART1_SEND_BUSY);
		}
    }
    if(SCON1 & 0x01){//RI1 == 1
        SCON1 &= 0xFE;//RI1 = 0
	    if(NVRAM0[SPREG_UART1_RECV_NUM] < NVRAM0[SPREG_UART1_RECV_LENGTH]){
			NVRAM0[SPREG_UART1_RECV_BUFFER_ADR + SPREG_UART1_RECV_NUM] = (uint16_t)SBUF1;
			NVRAM0[SPREG_UART1_RECV_NUM] ++;
		}
		else{
			SCON1 &= 0xEF;//REN1 = 0 �رս���
			SET(SPCOIL_UART1_RECV_DONE);//�������
			RES(SPCOIL_UART1_RECV_BUSY);
		}
	}   
	exitSplcIsr();
}
void initUart1(uint32_t baudrate){//ָʾ�д��ڳ�ʼ��
	CKCON &= (1 << 6);//Timer 4 uses the system clock
	T4CON = 0;
	T4CON |= 1 << 4;//Timer 4 overflows used for transmit clock.
	T4CON |= 1 << 5;//Timer 4 overflows used for receive clock.
	T4CON &= ~(1 << 0);//����ʱ��4 �����T2EX �Ϸ���������ʱ���Զ���װ�أ�EXEN2=1��
	T4CON &= ~(1 << 1);//��ʱ�����ܣ���ʱ��4 ��T2M��CKCON.5�������ʱ�Ӽ�1
	RCAP4  = - ((long) ((uint32_t)CONFIG_SYSCLK / baudrate) / 32L);
	TMR4 = RCAP4;
	T4CON |= (1 << 2);//Timer 4 enabled
	SCON1 = 0x0;
	SCON1 |= (uint8_t)(1 << 6);//Mode 1: 8-Bit UART, Variable Baud Rate
	SCON1 &= ~(uint8_t)(1 << 0);//RI1: Receive Interrupt Flag.
	SCON1 &= ~(uint8_t)(1 << 1);//TI1: Transmit Interrupt Flag.	
	EIE2 |= (1 << 6);//ES1: Enable UART1 Interrupt.
}