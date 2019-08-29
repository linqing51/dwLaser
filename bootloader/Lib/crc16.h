#ifndef __CRC16_H__
#define __CRC16_H__
/*****************************************************************************/
#include "lib.h"
/*****************************************************************************/
uint16_t crc16Calculate(uint8_t *buf, uint32_t len);//CRC16 计算数组
uint16_t crc16CalculateAdd(uint8_t dat);//CRC16 计算连续字节
void crc16Clear(void);//清空旧CRC16结果
void crc16SetCrcOld(uint16_t old);
/*****************************************************************************/
#endif
