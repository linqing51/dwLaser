#ifndef __CRC32_H__
#define __CRC32_H__

//#ifdef __cplusplus
//extern "C" {
//#endif
/*****************************************************************************/
#include "lib.h"
/*****************************************************************************/
uint32_t crc32Calculate(uint8_t *buf, uint32_t len);//CRC32 计算数组
uint32_t crc32CalculateAdd(uint8_t dat);//CRC32 计算连续字节
void crc32Clear(void);//清空旧CRC32结果
void crc32SetCrcOld(uint32_t old);
/*****************************************************************************/
//#ifdef __cplusplus
//}
//#endif
#endif



