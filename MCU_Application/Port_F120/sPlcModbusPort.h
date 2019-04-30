#ifndef __MODBUSPORT__H__
#define __MODBUSPORT__H__
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
#if (CONFIG_USING_RTU_SLAVE == 1 && CONFIG_MB_PORT == UART1)
extern void Uart1Isr(void);//UART1ÖÐ¶Ï
#endif
#if (CONFIG_USING_RTU_SLAVE == 1 && CONFIG_MB_PORT == UART0)
extern void Uart0Isr(void);//UART0ÖÐ¶Ï
#endif
extern void modBusTimerInitialise(void);
extern void modBusUartPutch(uint8_t c);
extern uint8_t modBusUartString(uint8_t *s, uint16_t Length);
extern void receiveInterrupt(uint8_t Data);
/*****************************************************************************/
#endif