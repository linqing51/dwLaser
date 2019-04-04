#ifndef __USBSPI_H__
#define __USBSPI_H__
/*****************************************************************************/
#include "lib.h"
#include "ch376.h"
/*****************************************************************************/
#define ERR_USB_UNKNOWN						0
/*****************************************************************************/
void usbSpiInit(void);//USB CH376初始化
void xWriteCH376Cmd(uint8_t mCmd);//向CH376写命令
void xWriteCH376Data(uint8_t mData);
void xEndCH376Cmd(void);
uint8_t	xReadCH376Data(void);
uint8_t	usbSpiIntQuery( void );//查询CH376中断
uint8_t	usbHostInit(void);//初始化CH376
void mStopIfError(uint8_t iError);//检查操作状态,如果错误则显示错误代码并停机
/*****************************************************************************/
#endif