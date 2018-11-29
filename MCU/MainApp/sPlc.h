#ifndef __SOFTPLC_H__
#define __SOFTPLC_H__
/*****************************************************************************/
#include "appConfig.h"
//数据寄存器 保持 256个字
#define DM_START						0//掉电保持寄存器
#define DM_END							255
//线圈 保持 128 * 16 = 2048个
#define MR_START						256//线圈寄存器
#define	MR_END							383
//数据寄存器 非保持 128个字
#define EM_START						384//随机寄存器
#define EM_END							511
//线圈寄存器 非保持 64 * 16 = 1024个
#define R_START							512//掉电保持线圈寄存器
#define R_END							575
//延时线圈
#define T_100US_START					576
#define T_100US_END						579
#define T_1MS_START						580
#define T_1MS_END						583
#define T_10MS_START					584
#define T_10MS_END						587
#define T_100MS_START					588	
#define T_100MS_END						591
//延时计时器 
#define TD_100US_START					592//64个100uS
#define TD_100US_END					655
#define TD_1MS_START					656//64个1mS
#define TD_1MS_END						719
#define TD_10MS_START					720//64个10mS
#define TD_10MS_END						783
#define TD_100MS_START					784//64个100mS
#define TD_100MS_END					847
//计数器
#define C_START							848//64个计数器
#define C_END							911
//输入位寄存器 16 * 16 = 256个
#define X_START							912
#define X_END							927
//输出位寄存器 16 * 16 = 256个
#define Y_START							928
#define Y_END							944

#define CONFIG_NVRAM_SIZE 				(Y_END + 1)
/*****************************************************************************/
void Timer0_Init(void);
void nvram_updata(void);
void clear_dm(void);
void clear_em(void);
void clear_r(void);
void clear_t(void);
void clear_td(void);
void clear_c(void);
void nvram_load(void);
void nvram_save(void);
void nvram_updata(void);

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
#endif