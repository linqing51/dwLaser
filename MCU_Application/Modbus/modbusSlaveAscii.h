#ifndef __MODBUSSLAVEASCII_H__
#define __MODBUSSLAVEASCII_H__
/*****************************************************************************/
#define MODBUS_ASCII_STX						0x3A
#define MODBUS_ASCII_END0						0x0D
#define MODBUS_ASCII_END1						0x0A
#define MODBUS_ASCII_FLAG_RXDOING_MASK			0
#define MODBUS_ASCII_FLAG_RXDONE_MASK			1
/*****************************************************************************/
#include "appConfig.h"

void modbusSlaveAsciiPoll(void);
/*****************************************************************************/
#endif