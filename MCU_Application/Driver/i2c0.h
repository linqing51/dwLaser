#ifndef __I2C0_H__
#define __I2C0_H__
/*****************************************************************************/
#include "lib.h"
/*****************************************************************************/
void iic0Start(void);
void iic0Stop(void);
uint8_t iic0WaitAck(void);
void iic0Ack(void);
void iic0NAck(void);
void iic0SendByte(uint8_t txd);
uint8_t iic0ReadByte(uint8_t ack);

#endif


