#ifndef __UART_H__
#define __UART_H__
#include "appConfig.h"
#include "string.h"
/*****************************************************************************/

sbit    RS485_DIR_PIN = P0^7;   //485控制脚
#define RS485_DIRECTION_TXD		RS485_DIR_PIN = 0
#define RS485_DIRECTION_RXD		RS485_DIR_PIN = 1
#define ENABLE_MODBUS_INT		ES0 = 1//打开MODBUS中断
#define DISABLE_MODBUS_INT		ES0 = 0//关闭MODBUS中断
#define RS485_TX_DELAY          1//1uS
#define RS485_RX_DELAY			1//
//定义串口缓冲区
#define REVOUTTIME				   100.0 //接收异常等待时间 mS  
extern void setrevouttime(uint32_t mtime);
extern uint8_t revchar(void);
extern void sendchar(uint8_t ch);
void sendstring(int8_t *pchar,uint16_t len);//发送字符串
#endif