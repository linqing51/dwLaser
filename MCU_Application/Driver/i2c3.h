#ifndef __I2C3_H__
#define __I2C3_H__
/*****************************************************************************/
#include "lib.h"
/*****************************************************************************/
void iic3Start(void);
void iic3Stop(void);
uint8_t iic3WaitAck(void);
void iic3Ack(void);
void iic3NAck(void);
void iic3SendByte(uint8_t txd);
uint8_t iic3ReadByte(uint8_t ack);

#endif


