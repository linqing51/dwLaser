#ifndef __I2C5_H__
#define __I2C5_H__
/*****************************************************************************/
#include "lib.h"
/*****************************************************************************/

/*****************************************************************************/
void iic5Init(void);
void iic5Start(void);
void iic5Stop(void);
uint8_t iic5WaitAck(void);
void iic5Ack(void);
void iic5NAck(void);
void iic5SendByte(uint8_t txd);
uint8_t iic5ReadByte(uint8_t ack);

#endif


