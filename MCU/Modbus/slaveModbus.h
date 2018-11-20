#ifndef __SLAVEMODBUS_H__
#define __SLAVEMODBUS_H__
/*****************************************************************************/
#include "AppConfig.h"
/*****************************************************************************/
#define  MB_CONFIG_RECE_TIMEOUT				10//����ͨѶ��ʱ 10mS
#define  MB_CONFIG_RS485_SWITCH_DELAY		1//RX TX�л���ʱ

void modbusSerialRxHandle(void);
void modbusSerialTxHandle(void);
void modbusTimerHandle(void);
void InitModbusHardware(uint32_t baudrate);//��ʼ��MODBUSӲ��
void modbusPoll(void);
void setModbusSlaveAddr(uint8_t addr);
#endif

