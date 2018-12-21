#ifndef __PETITMODBUSPORT__H__
#define __PETITMODBUSPORT__H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
#ifndef TRUE
#define TRUE  1
#endif
#ifndef FALSE
#define FALSE 0
#endif

extern void modBusUartInitialise(uint32_t baudrate);
extern void modBusTimerInitialise(void);
extern void modBusUartPutch(uint8_t c);
extern uint8_t modBusUartString(uint8_t *s, uint16_t Length);
extern void receiveInterrupt(uint8_t Data);
extern void modBusTimerValues(void);

#endif