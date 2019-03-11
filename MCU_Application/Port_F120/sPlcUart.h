#ifndef __SPLCUART_H__
#define __SPLCUART_H__
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
void initUart1(uint32_t baudrate);
void USEND(uint16_t port, uint16_t sendBufAdr, uint16_t length);//串口发送
void URECV(uint16_t port, uint16_t recvBufAdr, uint16_t length);//串口接收
#endif
