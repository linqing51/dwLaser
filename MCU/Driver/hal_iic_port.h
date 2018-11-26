#ifndef __HAL_IIC_PORT_H__
#define __HAL_IIC_PORT_H__
/*****************************************************************************/
#include "appConfig.h"
void iic0_init(void);
uint8_t setSDA0_H(void);
uint8_t setSDA0_L(void);
uint8_t setSCL0_H(void);
uint8_t setSCL0_L(void);
uint8_t getSDA0(void);
uint8_t getSCL0(void);

#endif