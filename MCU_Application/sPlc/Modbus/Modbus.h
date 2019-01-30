#ifndef __MODBUS_H__
#define __MODBUS_H__
/*****************************************************************************/
#include "lib.h"
#include "modbusPort.h"
/*****************************************************************************/
extern idata volatile uint16_t modbusTimerValue;
extern idata volatile uint8_t modbusReceiveCounter;// Collected data number
extern xdata volatile uint8_t modbusReceiveBuffer[CONFIG_MB_RTU_SLAVE_BUFFER_SIZE];
/*****************************************************************************/
extern void initModbus(uint8_t modbusSlaveAddress, uint32_t bd);
extern void modbusPorcess(void);
extern void modBusUartInitialise(uint32_t baudrate);
extern void modBusTimerInitialise(void);
extern void modBusUartPutch(uint8_t c);
extern uint8_t modBusUartString(uint8_t *s, uint16_t Length);
extern void receiveInterrupt(uint8_t Data);
#endif
