#ifndef __PETITMODBUS__H__
#define __PETITMODBUS__H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
extern void initModbus(uint8_t modbusSlaveAddress, uint32_t bd);
extern void processModbus(void);
#endif
