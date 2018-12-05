#ifndef __MODBUSPORT_H__
#define __MODBUSPORT_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
#define RS485_DIRECTION_TXD		
#define RS485_DIRECTION_RXD		

void InitModbusSerial(int32_t baudrate);//初始化串口
void InitModbusTimer(void);//初始化计时器
void modbusSerialSendBuffer(uint8_t *buf, uint8_t size);
#endif