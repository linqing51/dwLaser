#ifndef __SPLC_H__
#define __SPLC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
//线圈 保持 4 * 16 = 64BIT
#define MR_START						0
#define MR_END   						3
//线圈寄存器 非保持 4 * 16 = 64BIT
#define R_START							4
#define R_END							7
//数据寄存器 保持 8
#define DM_START						8
#define DM_END							15
//数据寄存器 非保持 128个字
#define EM_START						16
#define EM_END							143
//延时线圈
//1MS 1 * 16 = 16BIT
#define T_1MS_START						144
#define T_1MS_END						144
//10MS 1 * 16 = 16BIT
#define T_10MS_START					145
#define T_10MS_END						145
//100MS 1 * 16 = 16BIT
#define T_100MS_START					146
#define T_100MS_END						146
//延时计时器 
//1MS 32
#define TD_1MS_START					147
#define TD_1MS_END						162
//10MS 32
#define TD_10MS_START					163
#define TD_10MS_END						178
//100MS 32
#define TD_100MS_START					179
#define TD_100MS_END					194
//计数器 1
#define C_START							195
#define C_END							195
//输入位寄存器 1 * 16 = 128个
#define X_START							196
#define X_END							196			
//输出位寄存器 1 * 16 = 128个
#define Y_START							197
#define Y_END							197
//特殊寄存器 4个字
#define SPREG_START						198
#define SPREG_END						201
//特殊线圈	4 * 16 = 64个
#define SPCOIL_START					202
#define SPCOIL_END						205
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
#define EM_ADC_16						(EM_START + 16)//ADC16->MLD16
#define EM_ADC_17						(EM_START + 17)//ADC17->MLD17
#define EM_ADC_18						(EM_START + 18)//ADC18->MLD18
#define EM_ADC_19						(EM_START + 19)//ADC19->MLD19
#define EM_ADC_20						(EM_START + 20)//ADC20->MLD20
#define EM_ADC_21						(EM_START + 21)//ADC21->MLD21
#define EM_ADC_22						(EM_START + 22)//ADC22->MLD22
#define EM_ADC_23						(EM_START + 23)//ADC23->MLD23
#define EM_ADC_24						(EM_START + 24)//ADC24->MLD24
#define EM_ADC_25						(EM_START + 25)//ADC25->MLD25
#define EM_ADC_26						(EM_START + 26)//ADC26->MLD26
#define EM_ADC_27						(EM_START + 27)//ADC27->MLD27
#define EM_ADC_28						(EM_START + 28)//ADC28->MLD28
#define EM_ADC_29						(EM_START + 29)//ADC29->MLD29
#define EM_ADC_30						(EM_START + 30)//ADC30->MLD30
#define EM_ADC_31						(EM_START + 31)//ADC31->MLD31
#define EM_ADC_32						(EM_START + 32)//ADC32->MPD0
#define EM_ADC_33						(EM_START + 33)//ADC33->MPD1
#define EM_ADC_34						(EM_START + 34)//ADC34->MPD2
#define EM_ADC_35						(EM_START + 35)//ADC35->MPD3
#define EM_ADC_36						(EM_START + 36)//ADC36->MPD4
#define EM_ADC_37						(EM_START + 37)//ADC37->MPD5
#define EM_ADC_38						(EM_START + 38)//ADC38->MPD6
#define EM_ADC_39						(EM_START + 39)//ADC39->MPD7
#define EM_ADC_40						(EM_START + 40)//ADC40->MPD8
#define EM_ADC_41						(EM_START + 41)//ADC41->MPD9
#define EM_ADC_42						(EM_START + 42)//ADC42->MPD10
#define EM_ADC_43						(EM_START + 43)//ADC42->MPD11
#define EM_ADC_44						(EM_START + 44)//ADC42->MPD12
#define EM_ADC_45						(EM_START + 45)//ADC42->MPD13
#define EM_ADC_46						(EM_START + 46)//ADC42->MPD14
#define EM_ADC_47						(EM_START + 47)//ADC42->MPD15
#define EM_ADC_48						(EM_START + 48)//ADC42->MPD16
#define EM_ADC_49						(EM_START + 49)//ADC42->MPD17
#define EM_ADC_50						(EM_START + 50)//ADC42->MPD18
#define EM_ADC_51						(EM_START + 51)//ADC42->MPD19
#define EM_ADC_52						(EM_START + 52)//ADC42->MPD20
#define EM_ADC_53						(EM_START + 53)//ADC43->MPD21
#define EM_ADC_54						(EM_START + 54)//ADC44->MPD22
#define EM_ADC_55						(EM_START + 55)//ADC45->MPD23
#define EM_ADC_56						(EM_START + 56)//ADC46->MPD24
#define EM_ADC_57						(EM_START + 57)//ADC47->MPD25
#define EM_ADC_58						(EM_START + 58)//ADC48->MPD26
#define EM_ADC_59						(EM_START + 59)//ADC49->MPD27
#define EM_ADC_60						(EM_START + 60)//ADC50->MPD28
#define EM_ADC_61						(EM_START + 61)//ADC50->MPD29
#define EM_ADC_62						(EM_START + 62)//ADC50->MPD30
#define EM_ADC_63						(EM_START + 63)//ADC50->MPD31
#define EM_DAC_0						(EM_START + 64)//DAC0
#define EM_DAC_1						(EM_START + 65)//DAC1
#define EM_DAC_2						(EM_START + 66)//DAC2
#define EM_DAC_3						(EM_START + 67)//DAC3
#define EM_DAC_4						(EM_START + 68)//DAC4
#define EM_DAC_5						(EM_START + 69)//DAC5
#define EM_DAC_6						(EM_START + 70)//DAC6
#define EM_DAC_7						(EM_START + 71)//DAC7
#define EM_DAC_8						(EM_START + 72)//DAC8
#define EM_DAC_9						(EM_START + 73)//DAC9
#define EM_DAC_10						(EM_START + 74)//DAC10
#define EM_DAC_11						(EM_START + 75)//DAC11
#define EM_DAC_12						(EM_START + 76)//DAC12
#define EM_DAC_13						(EM_START + 77)//DAC13
#define EM_DAC_14						(EM_START + 78)//DAC14
#define EM_DAC_15						(EM_START + 79)//DAC15
#define EM_DAC_16						(EM_START + 80)//DAC16
#define EM_DAC_17						(EM_START + 81)//DAC17
#define EM_DAC_18						(EM_START + 82)//DAC18
#define EM_DAC_19						(EM_START + 83)//DAC19
#define EM_DAC_20						(EM_START + 84)//DAC20
#define EM_DAC_21						(EM_START + 85)//DAC21
#define EM_DAC_22						(EM_START + 86)//DAC22
#define EM_DAC_23						(EM_START + 87)//DAC23
#define EM_DAC_24						(EM_START + 88)//DAC24
#define EM_DAC_25						(EM_START + 89)//DAC25
#define EM_DAC_26						(EM_START + 90)//DAC26
#define EM_DAC_27						(EM_START + 91)//DAC27
#define EM_DAC_28						(EM_START + 92)//DAC28
#define EM_DAC_29						(EM_START + 93)//DAC29
#define EM_DAC_30						(EM_START + 94)//DAC30
#define EM_DAC_31						(EM_START + 95)//DAC31
/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 				(SPCOIL_END + 1)
/*****************************************************************************/
#define SPCOIL_ON						0//长通线圈
#define SPCOIL_PS1MS					1//1mS间隔 50%占空比脉冲
#define SPCOIL_PS10MS					2//10mS
#define SPCOIL_PS100MS					3//100mS
/*****************************************************************************/
#define SP_EM_MODBUS_SLAVE_ERR			300
#define SP_R_ON							800//上电ON
#define SP_R_TICK_1MS					801//
#define SP_R_TICK_10MS					802//
#define SP_R_TICK_100MS					803//
#define SP_R_TICK_1S					804//
/*****************************************************************************/
typedef struct{//ADC滤波器
	uint16_t dat[CONFIG_SPLC_ADC_FILTER_TAP];
	uint16_t out;
	uint8_t wIndex;//写入指针
}adcTempDat_t;
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