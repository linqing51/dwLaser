#ifndef __SPLCUART_H__
#define __SPLCUART_H__
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
void initUart0(uint32_t baudrate);//���ڳ�ʼ��
void initUart1(uint32_t baudrate);//���ڳ�ʼ��
void USEND(uint8_t port, uint8_t length);//���ڷ���
void URECV(uint8_t port, uint8_t length);//���ڽ���
void USSTP(uint8_t port);//����ǿ��ֹͣ����
void URSTP(uint8_t port);//����ǿ��ֹͣ����
#endif
