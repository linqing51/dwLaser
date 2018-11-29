#ifndef __I2C0_H__
#define __I2C0_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
#define IIC_NO_ERROR				0
#define IIC_NACK_ERROR 				-1
#define IIC_BUSY_ERROR			 	-2
/*****************************************************************************/
void iic0_Init(void);
uint8_t iic0_write(uint8_t dev_addr, uint8_t numbytes, uint8_t *array_name);
uint8_t iic0_read(uint8_t dev_addr, uint8_t numbytes, uint8_t *array_name);

#endif
