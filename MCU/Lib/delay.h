#ifndef __DELAY_H__
#define __DELAY_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
uint16_t hwGetTick(void);
void hwDelayInit(void);
void hwDelayMs(uint8_t ms) reentrant;
void hwDelayUs(uint8_t us) reentrant;
/*****************************************************************************/
#endif

