#ifndef __SPLCUART_H__
#define __SPLCUART_H__
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
void initUart0(uint32_t baudrate);//串口初始化
void initUart1(uint32_t baudrate);//串口初始化
void USEND(uint8_t port, uint8_t length);//串口发送
void URECV(uint8_t port, uint8_t length);//串口接收
void USSTP(uint8_t port);//串口强制停止发送
void URSTP(uint8_t port);//串口强制停止接收
#endif
