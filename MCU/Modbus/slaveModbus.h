#ifndef __SLAVEMODBUS_H__
#define __SLAVEMODBUS_H__
/*****************************************************************************/
#include "AppConfig.h"
/*****************************************************************************/
void modbusSerialRxHandle(void);
void modbusSerialTxHandle(void);
void modbusTimerHandle(void);
void InitModbusHardware(uint32_t baudrate);//³õÊ¼»¯MODBUSÓ²¼þ
void modbusPoll(void);
void setModbusSlaveAddr(uint8_t addr);
#endif

