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
** Modified by:			Chenxibing
** Modified date:		2005-03-10
** Version:
** Descriptions:		基于uC/OS-II的定时器1实验。
**
********************************************************************************************************/
#include "config.h"
#include "stdlib.h"

#define	TaskStkLengh	128			// Define the Task0 stack length 定义用户任务0的堆栈长度
#define TaskStkSize		128			// 定义用户任务堆栈长度
 
OS_STK	TaskStk [TaskStkLengh];		// Define the Task0 stack 定义用户任务0的堆栈
OS_STK  TaskStkTimer1[TaskStkSize];	// 定义TaskTimer1的堆栈

void 	Task0(void *pdata);			// Task0 任务0
void 	TaskTimer1(void *pdata);	// TaskTimer1任务

/*
*********************************************************************************************************
** 函数名称 ：main（）
** 函数功能 ：uC/OS-II主函数，启动多任务环境。
*********************************************************************************************************
*/
int main (void)
{
	OSInit ();																										
	OSTaskCreate (Task0,(void *)0, &TaskStk[TaskStkLengh - 1], 2);		
	OSStart ();
	return 0;															
}

/*********************************************************************************************************
**                            Task0 任务0
**                           初始化目标板，并创建任务TaskTimer1
********************************************************************************************************/

void Task0	(void *pdata)
{
	pdata = pdata;
	
	TargetInit ();			// 目标板初始化
	OSTaskCreate (TaskTimer1,(void *)0, &TaskStkTimer1[TaskStkSize - 1], 3);	// 创建TaskTimer1	
	
	while (1)
	{
		OSTimeDly(10);
	}
}
  
/*********************************************************************************************************
**                            TaskTimer1 任务
**                           测量程序运行时间，并送到上位机显示
********************************************************************************************************/

void TaskTimer1	(void *pdata)
{
	char s[40];
	pdata = pdata;
	
	T1MCR = 0x00;			// 禁止比较功能
	T1CCR = 0x00;			// 禁止捕获功能
		
	while (1)
	{
		T1TC = 0x00;					// 清除计数值
		T1TCR = 0x01;					// 启动定时器
		OSTimeDly(OS_TICKS_PER_SEC);	// 延时1秒
		T1TCR = 0x00;					// 停止计数器
		sprintf(s,"OSC is %uHz.", (uint32)T1TC);
		PC_DispStr(1, 1, s, DISP_FGND_YELLOW + DISP_BGND_BLUE);
	}
}
//DISP_FGND_YELLOW
//DISP_FGDN_YELLOW
    
/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
