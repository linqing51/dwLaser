#ifndef __MCP47X6_H__
#define __MCP47X6_H__
/*****************************************************************************/
#include "device.h"
/*****************************************************************************/
uint8_t mcp47x6Init(void);
void mcp47x6Write(uint8_t channel, uint16_t dat) reentrant;
#endif
	











