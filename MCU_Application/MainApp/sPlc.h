#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
//线圈 保持 8 * 16 = 128BIT
#define MR_START						0
#define MR_END   						3
//线圈寄存器 非保持 8 * 16 = 128BIT
#define R_START							4
#define R_END							11
//数据寄存器 保持 8
#define DM_START						12
#define DM_END							19
//数据寄存器 非保持 140个字
#define EM_START						20
#define EM_END							159
//延时线圈
//1MS 1 * 16 = 16BIT
#define T_1MS_START						160
#define T_1MS_END						160
//10MS 1 * 16 = 16BIT
#define T_10MS_START					161
#define T_10MS_END						161
//100MS 1 * 16 = 16BIT
#define T_100MS_START					162
#define T_100MS_END						162
//延时计时器 
//1MS 16
#define TD_1MS_START					163
#define TD_1MS_END						178
//10MS 16
#define TD_10MS_START					179
#define TD_10MS_END						194
//100MS 16
#define TD_100MS_START					195
#define TD_100MS_END					210
//计数器 1
#define C_START							211
#define C_END							211
//输入位寄存器 1 * 16 = 16个
#define X_START							212
#define X_END							212		
//输出位寄存器 1 * 16 = 16个
#define Y_START							213
#define Y_END							213
//特殊寄存器 24个字
#define SPREG_START						214
#define SPREG_END						237
//特殊线圈	4 * 16 = 64个
#define SPCOIL_START					238
#define SPCOIL_END						241
/*****************************************************************************/
#define EM_ADC_0						(EM_START + 0)//ADC0->MLD0
#define EM_ADC_1						(EM_START + 1)//ADC1->MLD1
#define EM_ADC_2						(EM_START + 2)//ADC2->MLD2
#define EM_ADC_3						(EM_START + 3)//ADC3->MLD3
#define EM_ADC_4						(EM_START + 4)//ADC4->MLD4
#define EM_ADC_5						(EM_START + 5)//ADC5->MLD5
#define EM_ADC_6						(EM_START + 6)//ADC6->MLD6
#define EM_ADC_7						(EM_START + 7)//ADC7->MLD7
#define EM_ADC_8						(EM_START + 8)//ADC8->MLD8
#define EM_ADC_9						(EM_START + 9)//ADC9->MLD9
#define EM_ADC_10						(EM_START + 10)//ADC10->MLD10
#define EM_ADC_11						(EM_START + 11)//ADC11->MLD11
#define EM_ADC_12						(EM_START + 12)//ADC12->MLD12
#define EM_ADC_13						(EM_START + 13)//ADC13->MLD13
#define EM_ADC_14						(EM_START + 14)//ADC14->MLD14
#define EM_ADC_15						(EM_START + 15)//ADC15->MLD15
#define EM_DAC_0						(EM_START + 64)//DAC0
#define EM_DAC_1						(EM_START + 65)//DAC1
#define EM_DAC_2						(EM_START + 66)//DAC2
#define EM_DAC_3						(EM_START + 67)//DAC3
#define EM_DAC_4						(EM_START + 68)//DAC4
#define EM_DAC_5						(EM_START + 69)//DAC5
#define EM_DAC_6						(EM_START + 70)//DAC6
#define EM_DAC_7						(EM_START + 71)//DAC7
/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 				(SPCOIL_END + 1)
/*****************************************************************************/
#define SPCOIL_ON						(SPCOIL_START * 16 + 0)//长通线圈
#define SPCOIL_START_UP					(SPCOIL_START * 16 + 1)//初次上电
#define SPCOIL_PS1MS					(SPCOIL_START * 16 + 2)//1mS间隔 50%占空比脉冲
#define SPCOIL_PS10MS					(SPCOIL_START * 16 + 3)//10mS
#define SPCOIL_PS100MS					(SPCOIL_START * 16 + 4)//100mS	
#define SPCOIL_PS1000MS					(SPCOIL_START * 16 + 5)//1000mS	
#define SPCOIL_UART0_SEND_BUSY			(SPCOIL_START * 16 + 16)//UART1发送忙
#define SPCOIL_UART0_RECV_BUSY			(SPCOIL_START * 16 + 17)//UART1接收忙
#define SPCOIL_UART0_SEND_DONE			(SPCOIL_START * 16 + 18)//发送完成
#define SPCOIL_UART0_RECV_DONE			(SPCOIL_START * 16 + 19)//接收完成
#define SPCOIL_UART1_SEND_BUSY			(SPCOIL_START * 16 + 20)//UART1发送忙
#define SPCOIL_UART1_RECV_BUSY			(SPCOIL_START * 16 + 21)//UART1接收忙
#define SPCOIL_UART1_SEND_DONE			(SPCOIL_START * 16 + 22)//发送完成
#define SPCOIL_UART1_RECV_DONE			(SPCOIL_START * 16 + 23)//接收完成
/*****************************************************************************/
#define SPREG_RUNTIME_L					(SPREG_START + 0)//累计运行时间秒 32BIT
#define SPREG_RUNTIME_H					(SPREG_START + 1)//累计运行时间秒 32BIT		
/*****************************************************************************/
#define SPREG_UART0_SEND_BUFFER_ADR		(SPREG_START + 4)//UART0 发送缓冲NVRAM地址		
#define SPREG_UART0_SEND_LENGTH			(SPREG_START + 5)//UART0 发送数据长度
#define SPREG_UART0_SEND_NUM			(SPREG_START + 6)//UART0 已经发送数据长度
#define SPREG_UART0_RECV_BUFFER_ADR		(SPREG_START + 7)//UART0 接收缓冲NVRAM地址
#define SPREG_UART0_RECV_LENGTH			(SPREG_START + 8)//UART0 接收数据长度
#define SPREG_UART0_RECV_NUM			(SPREG_START + 9)//UART0 已经接收数据长度
/*****************************************************************************/
#define SPREG_UART1_SEND_BUFFER_ADR		(SPREG_START + 10)//UART1 发送缓冲NVRAM地址		
#define SPREG_UART1_SEND_LENGTH			(SPREG_START + 11)//UART1 发送数据长度
#define SPREG_UART1_SEND_NUM			(SPREG_START + 12)//UART1 已经发送数据长度
#define SPREG_UART1_RECV_BUFFER_ADR		(SPREG_START + 13)//UART1 接收缓冲NVRAM地址
#define SPREG_UART1_RECV_LENGTH			(SPREG_START + 14)//UART1 接收数据长度
#define SPREG_UART1_RECV_NUM			(SPREG_START + 15)//UART1 已经接收数据长度
/*****************************************************************************/
#define SPREG_CLEAR_NVRAM0				(SPREG_END)//清除NVRAM后重新启动
/*****************************************************************************/
extern xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//掉电保持寄存器 当前
extern xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//掉电保持寄存器 上一次
/*****************************************************************************/
uint8_t getGlobalInterrupt(void);
void setLedRun(uint8_t st);
uint8_t getLedRun(void);
void setLedEprom(uint8_t st);
uint8_t getLedEprom(void);
void setLedDac(uint8_t st);
uint8_t getLedDac(void);
void setLedError(uint8_t st);
uint8_t getLedError(void);
void sPlcInit(void);//软逻辑初始化
void sPlcProcessStart(void);//sPLC轮询起始
void sPlcProcessEnd(void);//sPLC轮询结束
void wdtFeed(void) reentrant;
void wdtEnable(void) reentrant;
void wdtDisable(void) reentrant;
/*****************************************************************************/
void assertCoilAddress(uint16_t adr) reentrant;
void assertRegisterAddress(uint16_t adr) reentrant;
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
void chipDacInit(void);
void chipAdcInit(void);
void sPlcInit(void);
void refreshInput(void);
void refreshOutput(void);
void refreshDac(void);
/*****************************************************************************/
#endif