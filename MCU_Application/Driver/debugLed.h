#ifndef __DEBUGLED_H__
#define __DEBUGLED_H__
/*****************************************************************************/
#include "lib.h"
#include "sPlcConfig.h"
/*****************************************************************************/
void setLedRun(uint8_t st);//P6_0
void setLedEmit(uint8_t st);//P5_7
void setLedEprom(uint8_t st);//P5_6
void setLedVar(uint8_t st);//P5_0

#endif



