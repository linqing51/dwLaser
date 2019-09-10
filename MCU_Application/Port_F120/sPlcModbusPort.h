#ifndef __MODBUSPORT__H__
#define __MODBUSPORT__H__
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
extern void modBusTimerInitialise(void);
extern void modBusUartPutch(uint8_t c);
extern uint8_t modBusUartString(uint8_t *s, uint16_t Length);
extern void receiveInterrupt(uint8_t Data);
/*****************************************************************************/
#endif