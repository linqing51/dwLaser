#ifndef __HMIUSERUART_H__
#define __HMIUSERUART_H__
/*****************************************************************************/
#include "hmiLib.h"
/*****************************************************************************/
void hmiUartSendChar(uint8_t t);
void hmiInitUart(uint32_t baudrate);
void Uart0sr(void);
#endif
