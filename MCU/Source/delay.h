#ifndef __DELAY_H__
#define __DELAY_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
void hwDelayInit(void);
void hwDelayMs(int16_t ms);
void hwDelayUs(int16_t us);
void delayMs(uint32_t ms) reentrant;
void delayUs(uint32_t us) reentrant;
/*****************************************************************************/
#endif

