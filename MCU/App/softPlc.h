#ifndef __SOFTPLC_H__
#define __SOFTPLC_H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
typedef struct
{//定义软件PLC功能
	uint16_t X_Input0[CONFIG_PLC_X_NUM / 16 + 1];//输入端口 
	uint16_t X_Input1[CONFIG_PLC_X_NUM / 16 + 1];//输入端口 
	//M辅助寄存器
	uint16_t M_Coil[CONFIG_PLC_M_NUM / 16 + 1];//辅助寄存器
	uint16_t X_Coil[CONFIG_PLC_X_NUM / 16 + 1];//输入寄存器
	uint16_t Y_Coil[CONFIG_PLC_Y_NUM / 16 + 1];//输出寄存器
	//D寄存器
	uint16_t D_Reg[CONFIG_PLC_D_NUM];//D寄存器
	//计时器
	uint8_t TimerCounter_10mS;//软件计时器分频 10mS
	uint8_t TimerCounter_100mS;//软件计时器分频 100mS
	uint16_t Timer_1mS[CONFIG_PLC_TIMER_1MS_NUM];//1ms计时器
	uint16_t Timer_10mS[CONFIG_PLC_TIMER_10MS_NUM];//10ms计时器
	uint16_t Timer_100mS[CONFIG_PLC_TIMER_100MS_NUM];//100ms计时器	
	
}softPlc_t;
extern softPlc_t softPlc;
/*****************************************************************************/
void SoftPlc_Init(void);
void Timer0_Init(void);
void set_Coil(uint16_t addr, uint16_t *coil);
void reset_Coil(uint16_t addr, uint16_t *coil);
void flip_Coil(uint16_t addr, uint16_t *coil);
void inputFilter(softPlc_t *plc);
void outputRefush(softPlc_t *plc);
#endif