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
** Modified date:		2005-02-23
** Version:
** Descriptions:		EasyARM2131基于uC/OS-II的GPIO输入实验。
**                      按KEY1键，蜂鸣器会响2声。由LPC2100实验修改而来。
**
********************************************************************************************************/
#include "config.h"
//#include "stdlib.h"

#define BEEP 1 << 7						// P0.7控制BEEP
#define KEY1 1 << 16					// P0.16－KEY1

#define	TaskStkSize	64					// 定义用户任务0的堆栈长度
 
OS_STK	TaskStk [TaskStkSize];			// 定义用户任务0的堆栈
OS_STK  TaskBeepStk [TaskStkSize];		// 定义TaskBeep的堆栈
OS_STK  TaskKey1Stk [TaskStkSize];		// 定义TaskKey1的堆栈

void 	Task0(void *pdata);				// Task0 任务0
void	TaskBeep(void *pdata);			// TaskBeep
void	TaskKey1(void *pdata);			// TaskKey1


int main (void)
{
	OSInit ();																										
	OSTaskCreate (Task0,(void *)0, &TaskStk[TaskStkSize - 1], 2);		
	OSStart ();
	return 0;															
}
/*
********************************************************************************************************
**                            Task0 任务0
**                      目标板初始化，创建其它任务
*******************************************************************************************************
*/
void Task0	(void *pdata)
{
	pdata = pdata;

	TargetInit ();
   
    PINSEL0 = (PINSEL0 & 0xffff3fff);                         		 		// P0.16连接GPIO
    PINSEL1 = (PINSEL1 & 0xfffffffc);
    IO0DIR &= ~KEY1;			                               				// 设置KEY1为输入
    IO0SET  = BEEP;
    IO0DIR |= BEEP;			                                  				// 设置蜂鸣器为输出

    OSTaskCreate(TaskBeep, (void *)0, &TaskBeepStk[TaskStkSize - 1], 3); 	// 创建任务TaskBeep，优先级为3
    OSTaskCreate(TaskKey1, (void *)0, &TaskKey1Stk[TaskStkSize - 1], 4); 	// 创建任务TaskKey1，优先级为4

	while (1)
	{
		OSTimeDly(10);
	}
}

/*
********************************************************************************************************
**                            TaskBeep
**                            蜂鸣器鸣叫
*******************************************************************************************************
*/
void TaskBeep (void *pdata)
{
	pdata = pdata;
	
    for (;;)
    {
        OSTaskSuspend(OS_PRIO_SELF);
        IO0CLR = BEEP;
        OSTimeDly(OS_TICKS_PER_SEC / 8);
        IO0SET = BEEP;
        OSTimeDly(OS_TICKS_PER_SEC / 4);

        IO0CLR = BEEP;
        OSTimeDly(OS_TICKS_PER_SEC / 8);
        IO0SET = BEEP;
        OSTimeDly(OS_TICKS_PER_SEC / 4);
    }
}

/*
********************************************************************************************************
**                            TaskKey1
**                            按键检测
*******************************************************************************************************
*/
void TaskKey1 (void *pdata)
{
	pdata = pdata;
	
    for (;;)
    {
        OSTimeDly(OS_TICKS_PER_SEC / 50);    	// 延时20毫秒
        if ((IO0PIN & KEY1) != 0)
        {
            continue;
        }
        OSTimeDly(OS_TICKS_PER_SEC / 50);    	// 延时20毫秒
        if ((IO0PIN & KEY1) != 0)
        {
            continue;
        }
        OSTaskResume(3);						// 恢复TaskBeep任务，参数为优先级，要和TaskBeep的优先级一致
        while ((IO0PIN & KEY1) == 0)
        {
            OSTimeDly(OS_TICKS_PER_SEC / 50); 	// 延时20毫秒
        }
    }
}
    
/*
********************************************************************************************************
**                            End Of File
*******************************************************************************************************
*/
