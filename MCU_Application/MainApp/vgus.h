#ifndef __VGUS_H__
#define __VGUS_H__
/*****************************************************************************/
#include "lib.h"
#include "sPlc.h"
/*****************************************************************************/
void vGusRegRead(uint8_t addr, uint8_t length);//��ȡVGUS�Ĵ���
void vGusRegWrite(uint8_t addr, uint8_t *pbuf ,uint8_t length);//д��VGUS�Ĵ���
void vGusVarRead(uint16_t addr, uint8_t length);//��ȡVGUS����
void vGusVarWrite(uint16_t addr, uint16_t *pbuf ,uint8_t length);//д��VGUS����
/*****************************************************************************/

#endif