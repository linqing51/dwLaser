#ifndef __I2C0_H__
#define __I2C0_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
#define IIC_NO_ERROR				0
#define IIC_NACK_ERROR 				-1
#define IIC_BUSY_ERROR			 	-2
/*****************************************************************************/
void IIC0_Init(void);
void IIC0_Start(void);
void IIC0_Stop(void);
uint8_t IIC0_Wait_Ack(void);
void IIC0_Ack(void);
void IIC0_NAck(void);
void IIC0_Send_Byte(uint8_t txd);
uint8_t IIC0_Read_Byte(uint8_t ack);

#endif


