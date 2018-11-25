#ifndef __HAL_IIC_H__
#define __HAL_IIC_H__
#include "appConfig.h"
/*****************************************************************************/
#define IIC_NOERR			0
#define IIC_TIMEOUT			1
#define CONFIG_IIC_DEBUG	1

typedef struct 
{
	uint8_t (*setSDA_H)(void);
	uint8_t (*setSDA_L)(void);
	uint8_t (*setSCL_H)(void);
	uint8_t (*setSCL_L)(void);
	uint8_t (*getSDA)(void);
	uint8_t (*getSCL)(void);
	uint8_t busFreq;//总线频率 
	uint8_t timeOut;//SCL超时
}hal_iic_t;
/*****************************************************************************/
void iic_stop(hal_iic_t *i2c);
void iic_start(hal_iic_t *i2c);
void iic_restart(hal_iic_t *iic );
uint8_t iic_waitAck(hal_iic_t *iic);
uint8_t iic_writeByte(hal_iic_t *i2c, int8_t byte);
uint8_t iic_readByte(hal_iic_t *i2c);
#endif