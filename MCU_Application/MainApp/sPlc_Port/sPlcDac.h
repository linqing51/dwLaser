#ifndef __SPLCDAC_H__
#define __SPLCDAC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
void initChipDac(void);
void selfTestDac(void);
void refreshDac(void);
void forceRefreshDac(void);
void forceSetDac(uint8_t channel);
#endif