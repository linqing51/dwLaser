#ifndef __SPLCUART_H__
#define __SPLCUART_H__
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
//#if CONFIG_SPLC_USING_UART0 == 1
//uint8_t (*UART0_TX_CALLBACK)(void);//发送回调 
//void (*UART0_RX_CALLBACK)(uint8_t dat);
//#endif
//#if CONFIG_SPLC_USING_UART1 == 1
//uint8_t (*UART1_TX_CALLBACK)(void);//发送回调 
//void (*UART1_RX_CALLBACK)(uint8_t dat);
//#endif
/*****************************************************************************/
void initUart0(uint32_t baudrate);//串口初始化
void initUart1(uint32_t baudrate);//串口初始化
void USEND(uint8_t port, uint8_t length);//串口发送
void URECV(uint8_t port, uint8_t length);//串口接收
void USSTP(uint8_t port);//串口强制停止发送
void URSTP(uint8_t port);//串口强制停止接收
void UDIRX(uint8_t port);//关闭串口接收中断
void UENRX(uint8_t port);//打开串口接收中断


#endif
