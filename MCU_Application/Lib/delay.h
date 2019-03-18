#ifndef __DELAY_H__
#define __DELAY_H__
/*****************************************************************************/
#include "lib.h"
#include "sPlc.h"
/*****************************************************************************/
void delayMs(uint8_t ms) reentrant;
void delayUs(uint8_t us) reentrant;
void delayHwMs(uint16_t delay);
/*****************************************************************************/
#endif

