#ifndef __I2C2_H__
#define __I2C2_H__
/*****************************************************************************/
#include "lib.h"
/*****************************************************************************/
void iic2Start(void);
void iic2Stop(void);
uint8_t iic2WaitAck(void);
void iic2Ack(void);
void iic2NAck(void);
void iic2SendByte(uint8_t txd);
uint8_t iic2ReadByte(uint8_t ack);

#endif


