#ifndef __EPROM_H__
#define __EPROM_H__
#include "appConfig.h"
/*****************************************************************************/
void eprom_init(void);
void eprom_writeOneByte(uint8_t addr, uint8_t thedata);
void eprom_writePage(uint8_t *buffer, uint8_t addr);
uint8_t eprom_readOneByte(uint8_t addr);
void eprom_writeOneByte(uint8_t addr, uint8_t thedata);
#endif
