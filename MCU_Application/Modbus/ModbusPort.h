#ifndef __PETITMODBUSPORT__H
#define __PETITMODBUSPORT__H
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
#ifndef TRUE
#define TRUE  1
#endif
#ifndef FALSE
#define FALSE 0
#endif

//extern volatile unsigned char    PetitReceiveBuffer[PETITMODBUS_RECEIVE_BUFFER_SIZE];
//extern volatile unsigned char    PetitReceiveCounter;

extern void PetitModBus_UART_Initialise(unsigned long bd);
extern void PetitModBus_TIMER_Initialise(void);
extern void PetitModBus_UART_Putch(unsigned char c);
extern uint8_t PetitModBus_UART_String(unsigned char *s, unsigned int Length);

extern void ReceiveInterrupt(unsigned char Data);
extern void PetitModBus_TimerValues(void);

#endif