#ifndef __EPROM_H__
#define __EPROM_H__
#include "appConfig.h"
/*****************************************************************************/

void AT24CXX_Init(void);
uint8_t AT24CXX_ReadOneByte(uint16_t ReadAddr);
void AT24CXX_WriteOneByte(uint16_t WriteAddr, uint8_t DataToWrite);
void AT24CXX_WriteLenByte(uint16_t WriteAddr, uint32_t DataToWrite, uint8_t Len);
uint32_t AT24CXX_ReadLenByte(uint16_t ReadAddr, uint8_t Len);
void AT24CXX_Read(uint16_t ReadAddr,uint8_t *pBuffer,uint16_t NumToRead);
void AT24CXX_Write(uint16_t WriteAddr, uint8_t *pBuffer, uint16_t NumToWrite);
#endif
