#ifndef __DELAY_H__
#define __DELAY_H__
/*****************************************************************************/
#include "lib.h"
#include "sPlc.h"
/*****************************************************************************/
void delayMs(uint8_t ms) reentrant;
void delayUs(uint8_t us) reentrant;
void hwDelayInit(uint8_t reload_h, uint8_t reload_l);
void hwDelay(uint8_t control, uint8_t reload_h, uint8_t reload_l);
/*****************************************************************************/
#endif

