#ifndef __I2C6_H__
#define __I2C6_H__
/*****************************************************************************/
#include "device.h"
/*****************************************************************************/
void iic6Init(void);
void iic6Start(void);
void iic6Stop(void);
uint8_t iic6WaitAck(void);
void iic6Ack(void);
void iic6NAck(void);
void iic6SendByte(uint8_t txd);
uint8_t iic6ReadByte(uint8_t ack);

#endif


