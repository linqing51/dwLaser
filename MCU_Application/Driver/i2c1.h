#ifndef __I2C1_H__
#define __I2C1_H__
/*****************************************************************************/
#include "lib.h"
/*****************************************************************************/
void iic1Init(void);
void iic1Start(void);
void iic1Stop(void);
uint8_t iic1WaitAck(void);
void iic1Ack(void);
void iic1NAck(void);
void iic1SendByte(uint8_t txd);
uint8_t iic1ReadByte(uint8_t ack);

#endif


