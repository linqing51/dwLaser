#ifndef __SOFTPLC_H__
#define __SOFTPLC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
#define	M500			500
#define M501			501
/*****************************************************************************/
typedef struct
{//定义计时器结构体	
	int16_t value;//计时器计时值
	int16_t mate;//计时器匹配值
	int16_t enable;//计时器使能
	int16_t output;//计时器输出
}softPlcTimer_t;

typedef struct
{//定义软件PLC功能
	uint16_t X[CONFIG_PLC_X_NUM / 16 + 1];//输入寄存器 
	uint16_t M[CONFIG_PLC_M_NUM / 16 + 1];//非保持辅助寄存器
	uint16_t N[CONFIG_PLC_N_NUM / 16 + 1];//掉电保持寄存器
	uint16_t Y[CONFIG_PLC_Y_NUM / 16 + 1];//输出寄存器
	uint16_t D[CONFIG_PLC_D_NUM];//保持寄存器
	uint16_t R[CONFIG_PLC_R_NUM];//非保持寄存器
	uint16_t C[CONFIG_PLC_C_NUM];//计数器
	softPlcTimer_t T_1ms[CONFIG_PLC_T_1MS_NUM];
	softPlcTimer_t T_10ms[CONFIG_PLC_T_10MS_NUM];
	softPlcTimer_t T_100ms[CONFIG_PLC_T_100MS_NUM];
	softPlcTimer_t T_1000ms[CONFIG_PLC_T_1000MS_NUM];
	int16_t counter_1ms;
	int16_t counter_10ms;//软件计时器分频 10mS
	int16_t counter_100ms;//软件计时器分频 100mS
	int16_t counter_1000ms;//
}softPlc_t;
/*****************************************************************************/
extern softPlc_t softPlc;
/*****************************************************************************/
void SoftPlc_Init(softPlc_t *pt);//初始化
void startTimer(softPlcTimer_t *pt, int16_t value);//开始计数器
void stopTimer(softPlcTimer_t *pt);//停止计时器
void getInput(void);//刷新输入
void setOutput(void);//刷新输出
//位寄存器操作
uint8_t getCoil(uint16_t *coil, uint16_t addr);
void setCoil(uint16_t *coil, uint16_t addr);
void resetCoil(uint16_t *coil, uint16_t addr);
void flipCoil(uint16_t *coil, uint16_t addr);

#endif