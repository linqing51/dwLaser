#ifndef __CHIPSMB_H__
#define __CHIPSMB_H__

#include "appConfig.h"
void SMB_Init(void);
void SMB_Write (uint8_t slaveAddr, uint8_t wrsize, uint8_t *pwdat);
void SMB_Read (uint8_t slaveAddr ,uint8_t rdsize, uint8_t *prdat);

#endif
