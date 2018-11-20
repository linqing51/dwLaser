#ifndef __SLAVEMODBUS_H__
#define __SLAVEMODBUS_H__
/*****************************************************************************/
#include "AppConfig.h"
/*****************************************************************************/
#define  MB_CONFIG_RECE_TIMEOUT				10//接收通讯超时 10mS
#define  MB_CONFIG_RS485_SWITCH_DELAY		1//RX TX切换延时

void modbusSerialRxHandle(void);
void modbusSerialTxHandle(void);
void modbusTimerHandle(void);
void InitModbusHardware(uint32_t baudrate);//初始化MODBUS硬件
void modbusPoll(void);
void setModbusSlaveAddr(uint8_t addr);
#endif

