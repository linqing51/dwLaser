#ifndef __INPCA9554_H__
#define __INPCA9554_H__
/*****************************************************************************/
#include "device.h"
/*****************************************************************************/
void inPca9554Init(void);
uint8_t inPca9554Read(void);
void inPca9554Write(uint8_t wdata);

#endif
