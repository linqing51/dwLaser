#ifndef __SPLCLED_H__
#define __SPLCLED_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
uint8_t getGlobalInterrupt(void);
void setLedRun(uint8_t st);
uint8_t getLedRun(void);
void setLedEprom(uint8_t st);
uint8_t getLedEprom(void);
void setLedDac(uint8_t st);
uint8_t getLedDac(void);
void setLedError(uint8_t st);
uint8_t getLedError(void);

#endif