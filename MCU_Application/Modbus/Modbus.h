#ifndef __MODBUS__H__
#define __MODBUS__H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
extern volatile uint16_t modbusTimerValue;
extern volatile uint8_t modbusReceiveCounter;// Collected data number
extern xdata volatile uint8_t modbusReceiveBuffer[CONFIG_MB_RTU_SLAVE_BUFFER_SIZE];
/*****************************************************************************/
extern void initModbus(uint8_t modbusSlaveAddress, uint32_t bd);
extern void modbusPorcess(void);
#endif
