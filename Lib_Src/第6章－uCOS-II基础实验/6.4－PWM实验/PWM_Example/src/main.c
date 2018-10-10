/****************************************Copyright (c)**************************************************
**                               Guangzou ZLG-MCU Development Co.,LTD.
**                                      graduate school
**                                 http://www.zlgmcu.com
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			main.c
** Last modified Date:  2004-09-16
** Last Version:		1.0
** Descriptions:		The main() function example template
**
**------------------------------------------------------------------------------------------------------
** Created by:			Chenmingji
** Created date:		2004-09-16
** Version:				1.0
** Descriptions:		The original version
**
**------------------------------------------------------------------------------------------------------
** Modified by:			chenxibing
** Modified date:		2005-03-10
** Version:				
** Descriptions:		按键改变PWM占空比，使用邮箱
**
********************************************************************************************************/
#include "config.h"
#include "stdlib.h"

#define KEY1			(1 << 16)	// P0.16连接KEY1
#define	TaskStkLengh	64			// Define the Task0 stack length 定义用户任务0的堆栈长度
#define TaskStkSize		64			// TaskPWM任务堆栈长度
 
OS_STK	TaskStk [TaskStkLengh];		// Define the Task0 stack 定义用户任务0的堆栈
OS_STK	TaskPWMStk[TaskStkSize];	// TaskPWM任务堆栈
OS_STK	TaskKEY1Stk[TaskStkSize];	// TaskKEY1任务堆栈

OS_EVENT *PWMBox;

void 	Task0(void *pdata);			// Task0 任务0
void 	TaskPWM(void *pdata);		// TaskPWM
void 	TaskKEY1(void *pdata);		// TaskKEY1

/*
**********************************************************************************************************
** 函数名称 ：main()
** 函数功能 ：uC/OS-II主函数，启动多任务环境。
**********************************************************************************************************
*/
int main (void)
{
	OSInit ();
	PWMBox = OSMboxCreate((void *)0);		// 创建邮箱																										;
	
	OSTaskCreate (Task0,(void *)0, &TaskStk[TaskStkLengh - 1], 2);		
	OSStart ();
	return 0;															
}

/*********************************************************************************************************
**                            Task0 任务0
**                    初始化目标板，并创建TaskPWM、TaskKEY1任务
********************************************************************************************************/
void Task0	(void *pdata)
{
	pdata = pdata;
	
	TargetInit ();
	
	PINSEL0 = (PINSEL0&(~(3<<18)))|(2<<18);	// P0.9选择
	IO0DIR &= ~KEY1;						// 设置KEY1为输入

	PWMPR = 0x00;							// 不分频，计数时钟为Fpclk
	PWMMCR = 0x02;							// 设置MR0匹配时复位TC
	PWMMR0 = (Fpclk+500)/1000;				// 设置PWM周期为1ms
	PWMMR6 = (Fpclk+500)/2000;				// 设置PWM占空比为50％
	PWMLER = 1 | (1<<6);					// MR0和MR6锁存
	PWMPCR = 1 << 14;						// 允许PWM6输出，单边PWM
	PWMTCR = 1 |(1 << 3);					// 启动PWM定时器
	
	OSTaskCreate (TaskPWM,(void *)0, &TaskPWMStk[TaskStkSize - 1], 3);	// 创建TaskPWM任务		
	OSTaskCreate (TaskKEY1,(void *)0, &TaskKEY1Stk[TaskStkSize - 1], 4);// 创建TaskKEY1任务
	
	while (1)
	{
		OSTimeDly(10);
	}
}

/*********************************************************************************************************
**                            TaskPWM 任务
**                       等待消息，并改变PWM占空比
********************************************************************************************************/
void TaskPWM(void *pdata)
{
	uint8 err;
	uint32 *msg;
	
	pdata = pdata;
	
	while (1)
	{
		msg = OSMboxPend(PWMBox, 0, &err);	// 接收TaskKey1发来的消息
		PWMMR6 = msg[0];					// 改变占空比
		PWMLER = 0x41;						// 锁存PWM，更新占空比
	}
}  

/*********************************************************************************************************
**                            TaskKEY1 任务
**                       查询按键，向TaskPWM发送改变后的消息
********************************************************************************************************/

void TaskKEY1(void *pdata)
{
	uint8 err;
	volatile  uint32 PWMData = (Fpclk+500)/2000;
	
	pdata = pdata;
	
	while (1)
	{
		OSTimeDly(OS_TICKS_PER_SEC/50);				//延时20ms
		if ((IO0PIN & KEY1) !=0)
		{
		 	continue;
		}
		OSTimeDly(OS_TICKS_PER_SEC/50);				//延时20ms
		if ((IO0PIN & KEY1) !=0)
		{
			continue;
		}
		
		PWMData += (Fpclk+500)/20000;				// 改变用于控制占空比的参数
		if (PWMData >= (Fpclk+500)/1000) PWMData=0;
		
		err = OSMboxPost(PWMBox, (void*)&PWMData);	// 向TaskPWM发送消息
		
		while((IO0PIN&KEY1) == 0)
		{
			OSTimeDly(OS_TICKS_PER_SEC/50);			//延时20ms
		}
	}
}

/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
