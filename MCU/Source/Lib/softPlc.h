#ifndef __SOFTPLC_H__
#define __SOFTPLC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
#define SOFTPLC_X							1
#define SOFTPLC_Y							2
#define SOFTPLC_M							3
#define SOFTPLC_T							4
#define SOFTPLC_C							5
//MODBUS 对应地址 线圈
#define SOFTPLC_MODBUS_X_START				1001
#define SOFTPLC_MODBUS_X_END				1256
#define SOFTPLC_MODBUS_Y_START				1
#define SOFTPLC_MODBUS_Y_END				256
#define SOFTPLC_MODBUS_M_START				2001
#define SOFTPLC_MODBUS_M_END				4002
#define SOFTPLC_MODBUS_T_START				9001
#define SOFTPLC_MODBUS_T_END				9256
//MODBUS 对应地址 寄存器

#define SOFTPLC_MODBUS_D_START				6001
#define SOFTPLC_MODBUS_D_END				8999
#define SOFTPLC_MODBUS_TD_START				9001
#define SOFTPLC_MODBUS_TD_END				9256

/*****************************************************************************/
typedef struct
{//定义软件PLC功能
	uint16_t X[CONFIG_PLC_X_NUM / 16 + 1];//输入寄存器 
	uint16_t X1[CONFIG_PLC_X_NUM / 16 + 1];//输入寄存器上次结果
	uint16_t M[CONFIG_PLC_M_NUM / 16 + 1];//位寄存器
	uint16_t M1[CONFIG_PLC_M_NUM / 16 + 1];//位寄存器上次结果
	uint16_t Y[CONFIG_PLC_Y_NUM / 16 + 1];//输出寄存器
	uint16_t Y1[CONFIG_PLC_Y_NUM / 16 + 1];//输出寄存器上次结果
	uint16_t T[CONFIG_PLC_T_NUM / 16 + 1];//计时器寄存器
	uint16_t T1[CONFIG_PLC_T_NUM / 16 + 1];//计时器寄存器
	uint16_t T_EN[CONFIG_PLC_T_NUM / 16 + 1];//计时器使能
	uint16_t T_MATE[CONFIG_PLC_T_NUM];//计时器匹配值
	uint16_t T_VALUE[CONFIG_PLC_T_NUM];//计时器计时值
	
	uint16_t C[CONFIG_PLC_C_NUM / 16 + 1];//计数器
	uint16_t C1[CONFIG_PLC_C_NUM / 16 + 1];//计数器上次结果
	uint16_t C_VALUE[CONFIG_PLC_C_NUM];//计数器值
	
	uint16_t D[CONFIG_PLC_D_NUM];//数据保持寄存器
	
}softPlc_t;


/*****************************************************************************/
extern softPlc_t softPlc;
/*****************************************************************************/
void SoftPlc_Init(softPlc_t *pt);//初始化
//void startTimer(softPlcTimer_t *pt, int16_t value);//开始计数器
//void stopTimer(softPlcTimer_t *pt);//停止计时器
void getInput(softPlc_t *pt);
void setOutput(void);//刷新输出
/*****************************************************************************/
//基本指令
int8_t LD(uint8_t reg, uint16_t num);//
int8_t TB(int8_t en, int16_t num, int16_t value);
void OUT(uint8_t reg, uint16_t num, int8_t ena);
#endif