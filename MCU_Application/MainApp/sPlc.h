#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "appConfig.h"
//数据寄存器 保持 256个字
#define DM_START						0//掉电保持寄存器
#define DM_END							127
//线圈 保持 128 * 16 = 2048个
#define MR_START						128//线圈寄存器
#define	MR_END							191
//数据寄存器 非保持 128个字
#define EM_START						192//随机寄存器
#define EM_END							319
//线圈寄存器 非保持 64 * 16 = 1024个
#define R_START							320//掉电保持线圈寄存器
#define R_END							383
//延时线圈
#define T_100US_START					384
#define T_100US_END						387
#define T_1MS_START						388
#define T_1MS_END						391
#define T_10MS_START					392
#define T_10MS_END						395
#define T_100MS_START					396	
#define T_100MS_END						399
//延时计时器 
#define TD_100US_START					400//64个100uS
#define TD_100US_END					463
#define TD_1MS_START					464//64个1mS
#define TD_1MS_END						527
#define TD_10MS_START					528//64个10mS
#define TD_10MS_END						591
#define TD_100MS_START					592//64个100mS
#define TD_100MS_END					655
//计数器
#define C_START							656//64个计数器
#define C_END							719
//输入位寄存器 16 * 16 = 256个
#define X_START							720
#define X_END							735
//输出位寄存器 16 * 16 = 256个
#define Y_START							736
#define Y_END							751
//特殊寄存器
#define SPREG_START						752
#define SPREG_END						784
/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 				(SPREG_END + 1)
/*****************************************************************************/
#define SP_EM_MODBUS_SLAVE_ERR			300
#define SP_R_ON							800//上电ON
#define SP_R_TICK_1MS					801//
#define SP_R_TICK_10MS					802//
#define SP_R_TICK_100MS					803//
#define SP_R_TICK_1S					804//
/*****************************************************************************/
extern uint16_t ModbusSlaveAsciiOverTimeCounter;//Modbus Slave通信超时计时器
extern xdata int16_t NVRAM0[CONFIG_NVRAM_SIZE];//掉电保持寄存器 当前
extern xdata int16_t NVRAM1[CONFIG_NVRAM_SIZE];//掉电保持寄存器 上一次
/*****************************************************************************/
void assertCoilAddress(uint16_t adr);
void assertRegisterAddress(uint16_t adr);
void timer0Init(void);
/*****************************************************************************/
void nvramUpdata(void);
void clearDM(void);
void clearEM(void);
void clearR(void);
void clearT(void);
void clearTD(void);
void clearC(void);
void nvramLoad(void);
void nvramSave(void);
void nvramUpdata(void);
/*****************************************************************************/
void SET(uint16_t A);//置位
void RESET(uint16_t A);//复位
void FLIP(uint16_t A);//翻转
uint8_t LD(uint16_t A);//载入
uint8_t LDP(uint16_t A);//脉冲上升沿
uint8_t LDN(uint16_t A);//脉冲下降沿
void T100US(uint8_t A, uint8_t start, uint16_t value);
void T1MS(uint8_t A, uint8_t start, uint16_t value);
void T10MS(uint8_t A, uint8_t start, uint16_t value);
void T100MS(uint8_t A, uint8_t start, uint16_t value);
/*****************************************************************************/
void refreshInput(void);
void refreshOutput(void);
/*****************************************************************************/
#endif