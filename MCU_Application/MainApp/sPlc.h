#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "appConfig.h"
//数据寄存器 保持 128个字
#define DM_START						0//掉电保持寄存器
#define DM_END							127
//线圈 保持 16 * 16 = 256BIT
#define MR_START						128//线圈寄存器
#define	MR_END							143//
//数据寄存器 非保持 64个字
#define EM_START						144//随机寄存器
#define EM_END							207
//线圈寄存器 非保持 16 * 16 = 256BIT
#define R_START							208//掉电保持线圈寄存器
#define R_END							223
//延时线圈
#define T_1MS_START						224//16个1mS
#define T_1MS_END						239
#define T_10MS_START					240//16个10mS
#define T_10MS_END						255
#define T_100MS_START					256//16个100mS
#define T_100MS_END						271
//延时计时器 
#define TD_1MS_START					272//16个1mS
#define TD_1MS_END						287
#define TD_10MS_START					288//16个10mS
#define TD_10MS_END						303
#define TD_100MS_START					304//16个100mS
#define TD_100MS_END					319
//计数器
#define C_START							320//16个计数器
#define C_END							335
//输入位寄存器 16 * 16 = 256个
#define X_START							336
#define X_END							351
//输出位寄存器 16 * 16 = 256个
#define Y_START							352
#define Y_END							367
//特殊寄存器 64个字
#define SPREG_START						368
#define SPREG_END						431
/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 				(SPREG_END + 1)
/*****************************************************************************/
#define SPREG_ADC_0						SPREG_START
#define SPREG_ADC_1						(SPREG_START + 1)
#define SPREG_ADC_2						(SPREG_START + 2)
#define SPREG_ADC_3						(SPREG_START + 3)
#define SPREG_ADC_4						(SPREG_START + 4)
#define SPREG_ADC_5						(SPREG_START + 5)
#define SPREG_ADC_6						(SPREG_START + 6)
#define SPREG_ADC_7						(SPREG_START + 7)
#define SPREG_ADC_8						(SPREG_START + 8)
#define SPREG_ADC_9						(SPREG_START + 9)
#define SPREG_ADC_10					(SPREG_START + 10)
#define SPREG_ADC_11					(SPREG_START + 11)
#define SPREG_ADC_12					(SPREG_START + 12)
#define SPREG_ADC_13					(SPREG_START + 13)
#define SPREG_ADC_14					(SPREG_START + 14)
#define SPREG_ADC_15					(SPREG_START + 15)
#define SPREG_ADC_16					(SPREG_START + 16)
#define SPREG_ADC_17					(SPREG_START + 17)
#define SPREG_ADC_18					(SPREG_START + 18)
#define SPREG_ADC_19					(SPREG_START + 19)
#define SPREG_ADC_20					(SPREG_START + 20)
#define SPREG_ADC_21					(SPREG_START + 21)
#define SPREG_ADC_22					(SPREG_START + 22)
#define SPREG_ADC_23					(SPREG_START + 23)
#define SPREG_ADC_24					(SPREG_START + 24)
#define SPREG_ADC_25					(SPREG_START + 25)
#define SPREG_ADC_26					(SPREG_START + 26)
#define SPREG_ADC_27					(SPREG_START + 27)
#define SPREG_ADC_28					(SPREG_START + 28)
#define SPREG_ADC_29					(SPREG_START + 29)
#define SPREG_ADC_30					(SPREG_START + 30)
#define SPREG_ADC_31					(SPREG_START + 31)

#define SPREG_DAC_0						(SPREG_ADC_31 + 1)
#define SPREG_DAC_1						(SPREG_DAC_0 + 1)
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
void sPlcInit(void);//软逻辑初始化
/*****************************************************************************/
void assertCoilAddress(uint16_t adr);
void assertRegisterAddress(uint16_t adr);
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
void chipDacInit(void);
void chipAdcInit(void);
void sPlcInit(void);
void refreshInput(void);
void refreshOutput(void);
void refreshDac(void);
/*****************************************************************************/
#endif