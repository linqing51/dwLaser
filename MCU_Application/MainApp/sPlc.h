#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
/*****************************************************************************/
//线圈 保持 16 * 16 = 256BIT
#define MR_START						0
#define MR_END							15
//线圈寄存器 非保持 16 * 16 = 256BIT
#define R_START							16
#define R_END							31
//数据寄存器 保持 256
#define DM_START						32
#define DM_END							287
//数据寄存器 非保持 256个字
#define EM_START						288
#define EM_END							543
//延时线圈
#define T_1MS_START						544//32个1mS
#define T_1MS_END						545
#define T_10MS_START					546//32个10mS
#define T_10MS_END						547
#define T_100MS_START					548//32个100mS
#define T_100MS_END						549
//延时计时器 
#define TD_1MS_START					550//32个1mS
#define TD_1MS_END						581
#define TD_10MS_START					582//32个10mS
#define TD_10MS_END						613
#define TD_100MS_START					614//32个100mS
#define TD_100MS_END					645
//计数器
#define C_START							646//16个计数器
#define C_END							661//
//输入位寄存器 16 * 16 = 256个
#define X_START							662//
#define X_END							677// 
//输出位寄存器 16 * 16 = 256个
#define Y_START							678// 
#define Y_END							693//
//特殊寄存器 64个字
#define SPREG_START						694//
#define SPREG_END						757//
//特殊线圈	16 * 16 = 256个
#define SPCOIL_START					758
#define SPCOIL_END						773
/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 				(SPCOIL_END + 1)
/*****************************************************************************/
#define SPREG_ADC_0						(SPREG_START + 0)
#define SPREG_ADC_1						(SPREG_START + 1)
#define SPREG_ADC_2						(SPREG_START + 2)
#define SPREG_ADC_3						(SPREG_START + 3)
#define SPREG_DAC_0						(SPREG_START + 4)
#define SPREG_DAC_1						(SPREG_START + 5)
#define SPREG_DAC_2						(SPREG_START + 6)
#define SPREG_DAC_3						(SPREG_START + 7)
#define SPREG_CHECKCODE_L				(SPREG_END - 1)
#define SPREG_CHECKCODE_H				(SPREG_END)
#define SPCOIL_ON						(SPCOIL_START + 0)//长通线圈
#define SPCOIL_PSST						(SPCOIL_START + 1)//首次启动
#define SPCOIL_PS1MS					(SPCOIL_START + 2)//1mS间隔 50%占空比脉冲
#define SPCOIL_PS10MS					(SPCOIL_START + 3)//10mS 50%占空比脉冲
#define SPCOIL_PS100MS					(SPCOIL_START + 4)//100mS 50%占空比脉冲
/*****************************************************************************/

/*****************************************************************************/
extern uint16_t ModbusSlaveAsciiOverTimeCounter;//Modbus Slave通信超时计时器
extern xdata int16_t NVRAM0[CONFIG_NVRAM_SIZE];//掉电保持寄存器 当前
extern xdata int16_t NVRAM1[CONFIG_NVRAM_SIZE];//掉电保持寄存器 上一次
/*****************************************************************************/
void wdtDisable(void);//看门狗屏蔽

void sPlcInit(void);//软逻辑初始化
void sPlcProcessStart(void);//sPLC轮询起始
void sPlcProcessEnd(void);//sPLC轮询结束
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
int16_t ADD(int16_t A, int16_t B);//加法指令
void SET(uint16_t A);//置位
void RES(uint16_t A);//复位
void FLIP(uint16_t A);//翻转
uint8_t LD(uint16_t A);//载入
uint8_t LDP(uint16_t A);//脉冲上升沿
uint8_t LDF(uint16_t A);//脉冲下降沿
uint8_t LDB(uint16_t A);//取反载入
//void T100US(uint8_t A, uint8_t start, uint16_t value);
void T1MS(uint8_t A, uint8_t start, uint16_t value);//1mS延时器启动
void T10MS(uint8_t A, uint8_t start, uint16_t value);//10mS延时器启动
void T100MS(uint8_t A, uint8_t start, uint16_t value);//100mS延时器启动
void UPDAC(uint16_t dat);//立即更新DAC输出
void REBOOT(void);//SPLC复位指令
/*****************************************************************************/
void chipDacInit(void);
void chipAdcInit(void);
void sPlcInit(void);
void refreshInput(void);
void refreshOutput(void);
void refreshDac(void);
/*****************************************************************************/
#endif