#ifndef __SPLCUART_H__
#define __SPLCUART_H__
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
//extern (*UART0_TX_CALLBACK)(void);//���ͻص� 
//extern (*UART0_RX_CALLBACK)(uint8_t dat);
//extern uint8_t (*UART1_TX_CALLBACK)(void);//���ͻص� 
//extern void (*UART1_RX_CALLBACK)(uint8_t dat);
/*****************************************************************************/
void initUart0(uint32_t baudrate);//���ڳ�ʼ��
void initUart1(uint32_t baudrate);//���ڳ�ʼ��
void USEND(uint8_t port, uint8_t length);//���ڷ���
void URECV(uint8_t port, uint8_t length);//���ڽ���
void USSTP(uint8_t port);//����ǿ��ֹͣ����
void URSTP(uint8_t port);//����ǿ��ֹͣ����
void UDIRX(uint8_t port);//�رմ��ڽ����ж�
void UENRX(uint8_t port);//�򿪴��ڽ����ж�


#endif
