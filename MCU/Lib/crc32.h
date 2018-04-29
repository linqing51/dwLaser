#ifndef __CRC32_H__
#define __CRC32_H__

//#ifdef __cplusplus
//extern "C" {
//#endif
/*****************************************************************************/
#include "AppConfig.h"
/*****************************************************************************/
uint32_t Crc32Buf(uint8_t *buf, uint32_t len);//计算数组CRC32
void Crc32Clear(void);//清空旧CRC32结果
void SetCrcOld(uint32_t old);
/*****************************************************************************/
//#ifdef __cplusplus
//}
//#endif
#endif



