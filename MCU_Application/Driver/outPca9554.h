#ifndef __OUTPCA9554_H__
#define __OUTPCA9554_H__
/*****************************************************************************/
#include "lib.h"
/*****************************************************************************/
void outPca9554Init(void);
uint8_t outPca9554Read(void);
void outPca9554Write(uint8_t wdata);

#endif
