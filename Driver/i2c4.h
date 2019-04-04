#ifndef __I2C4_H__
#define __I2C4_H__
/*****************************************************************************/
#include "lib.h"
/*****************************************************************************/

/*****************************************************************************/
void iic4Init(void);
void iic4Start(void);
void iic4Stop(void);
uint8_t iic4WaitAck(void);
void iic4Ack(void);
void iic4NAck(void);
void iic4SendByte(uint8_t txd);
uint8_t iic4ReadByte(uint8_t ack);

#endif


