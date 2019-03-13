#ifndef __VGUS_H__
#define __VGUS_H__
/*****************************************************************************/
#include "lib.h"
#include "sPlc.h"
/*****************************************************************************/
void vGusRegRead(uint8_t addr, uint8_t length);//读取VGUS寄存器
void vGusRegWrite(uint8_t addr, uint8_t *pbuf ,uint8_t length);//写入VGUS寄存器
void vGusVarRead(uint8_t addr, uint8_t length);//读取VGUS变量
void vGusVarWrite(uint8_t addr, uint8_t *pbuf ,uint8_t length);//写入VGUS变量
/*****************************************************************************/

#endif