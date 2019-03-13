#include "sPlcUart.h"
/*****************************************************************************/
#if CONFIG_SPLC_USING_UART0 == 1
void initUart0(uint32_t baudrate){
	//��ʼ������0
	CKCON |= (1 << 5);//Timer2 uses the system clock
	
	TMR2CF    = 0x08;
    RCAP2L    = 0xD0;
    RCAP2H    = 0xFF;
	
	T2CON &= ~(1 << 0);//����ʱ��2 �����T2EX �Ϸ���������ʱ���Զ���װ�أ�EXEN2=1��
	T2CON &= ~(1 << 1);//��ʱ�����ܣ���ʱ��2 ��T2M��CKCON.5�������ʱ�Ӽ�1
	T2CON |= (1 << 4);//Timer 2 overflows used for transmit clock.
	T2CON |= (1 << 5);//Timer 2 overflows used for receive clock.	
	RCAP2  = - ((long) ((uint32_t)CONFIG_SYSCLK / baudrate) / 32L);
	TMR2 = RCAP2;
	TR2= 1;                             // Start Timer2
	
	SCON0 = 0x0;
	SCON0 |= (1 << 4);//��������
	SCON0 |= (1 << 6);//��ʽ1��8 λUART���ɱ䲨����
	
	SSTA0 = 0x0;
	SSTA0 |= (1 << 0);
	SSTA0 |= (1 << 2);
	
	//RS485_DIRECTION_RXD;//����״̬
	ES0 = 1;
	IP |= (1 << 4);//UART0 �жϸ����ȼ�
	TI0 = 0;//����������   		
	RI0 = 0;//����������
}
#endif
#if CONFIG_SPLC_USING_UART1 == 1
void initUart1(uint32_t baudrate){
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
#endif
void USSTP(uint8_t port){//����ǿ��ֹͣ����
}
void URSTP(uint8_t port){//����ǿ��ֹͣ����
}
void USEND(uint8_t port, uint8_t length){//������������
	if(port == UART0){
		NVRAM0[SPREG_UART0_SEND_LENGTH] = length;
		NVRAM0[SPREG_UART0_SEND_NUM] = 0x0;
		SET(SPCOIL_UART0_SEND_BUSY);
		RES(SPCOIL_UART0_SEND_DONE);
		TI0 = 1;//����
	}
	if(port == UART1){
		NVRAM0[SPREG_UART1_SEND_LENGTH] = length;
		NVRAM0[SPREG_UART1_SEND_NUM] = 0x0;
		SET(SPCOIL_UART1_SEND_BUSY);
		RES(SPCOIL_UART1_SEND_DONE);
		SCON1 |= 0x02;//��ʼ����			
	}
}
void URECV(uint8_t port, uint8_t length){//���ڽ���
	if(port == UART0){
		NVRAM0[SPREG_UART0_RECV_LENGTH] = length;
		NVRAM0[SPREG_UART0_RECV_NUM] = 0x0;
		SET(SPCOIL_UART0_RECV_BUSY);
		RES(SPCOIL_UART0_RECV_DONE);
		RI0 = 1;//����
	}
	if(port == UART1){
		NVRAM0[SPREG_UART1_RECV_LENGTH] = length;
		NVRAM0[SPREG_UART1_RECV_NUM] = 0x0;
		SET(SPCOIL_UART1_RECV_BUSY);
		RES(SPCOIL_UART1_RECV_DONE);
		SCON1 |=0x10;//REN1 = 1 ��������
	}
}

#if CONFIG_SPLC_USING_UART0 == 1
void Uart0Isr(void) interrupt INTERRUPT_UART0 {//UART0�ж�
	enterSplcIsr();
	if(TI0){  
		TI0 = 0;
		if(NVRAM0[SPREG_UART0_SEND_NUM] < NVRAM0[SPREG_UART0_SEND_LENGTH]){//
			SBUF0 = UART0_TXBUF[((uint8_t)NVRAM0[SPREG_UART0_SEND_NUM])];          
			NVRAM0[SPREG_UART0_SEND_NUM] ++;						                   
        }
		else{
			SET(SPCOIL_UART0_SEND_DONE);//�������
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
			REN0 = 0;//�رս���
			SET(SPCOIL_UART0_RECV_DONE);//�������
			RES(SPCOIL_UART0_RECV_BUSY);
		}
	}   
	exitSplcIsr();	
}
#endif

#if CONFIG_SPLC_USING_UART1 == 1
void Uart1Isr(void) interrupt INTERRUPT_UART1 {//UART1�ж�
	enterSplcIsr();
	if(SCON1 & 0x02){//TI1 == 1  
		SCON1 &= 0xFD;//TI1 = 0
		if(NVRAM0[SPREG_UART1_SEND_NUM] < NVRAM0[SPREG_UART1_SEND_LENGTH]){//
			SBUF1 = UART1_TXBUF[(uint8_t)NVRAM0[SPREG_UART1_SEND_NUM]];          
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
			UART1_RXBUF[(uint8_t)NVRAM0[SPREG_UART1_RECV_NUM]] = SBUF1;
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
#endif