#ifndef __EPROMSIMULATION_H__
#define __EPROMSIMULATION_H__
/*****************************************************************************/
#include "device.h"
/*****************************************************************************/
void epromInit(void);
uint8_t epromReadOneByte(uint16_t ReadAddr);
void epromWriteOneByte(uint16_t WriteAddr, uint8_t DataToWrite);
void epromWriteLenByte(uint16_t WriteAddr, uint32_t DataToWrite, uint8_t Len);
uint32_t epromReadLenByte(uint16_t ReadAddr, uint8_t Len);
void epromRead(uint16_t ReadAddr,uint8_t *pBuffer,uint16_t NumToRead);
void epromWrite(uint16_t WriteAddr, uint8_t *pBuffer, uint16_t NumToWrite);
uint8_t epromTest(void);
#endif
