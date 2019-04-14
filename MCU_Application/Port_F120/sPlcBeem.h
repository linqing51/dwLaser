#ifndef __SPLCBEEM_H__
#define __SPLCBEEM_H__
/*****************************************************************************/
#define BEEM_MODE_0				0
#define BEEM_MODE_1				1
#define BEEM_MODE_2				2
/*****************************************************************************/
#include "sPlc.h"
/*****************************************************************************/
void sPlcBeemInit(void);//·äÃùÆ÷³õÊ¼»¯
void sPlcBeemLoop(void);
void testBenchBeem(uint8_t volume, uint8_t mode);//·äÃùÆ÷²âÊÔ
void EDBEEM(void);//Í£Ö¹·äÃùÆ÷
void STBEEM(void);//¿ªÊ¼·äÃùÆ÷

#endif