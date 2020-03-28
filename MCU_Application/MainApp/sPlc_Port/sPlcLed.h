#ifndef __SPLCLED_H__
#define __SPLCLED_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
void setLedRun(uint8_t st);
void setLedDebug(uint8_t st);
uint8_t getLedRun(void);
uint8_t getLedDebug(void);
void setLedDac(uint8_t st);
uint8_t getLedDac(void);
void setLedError(uint8_t st);
uint8_t getLedError(void);

#endif