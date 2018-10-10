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
** Descriptions:		EasyARM2131 基于uCOS-II的GPIO输出实验。
**
********************************************************************************************************/
#include "config.h"
//#include "stdlib.h"

#define	  LED1	(1 << 18)           	// P1.18控制LED1

#define	Task0StkLengh	64				// 定义用户任务0的堆栈长度
#define	TaskLED1StkSize	128				// 定义任务TaskLED1的堆栈长度
 
OS_STK	Task0Stk [Task0StkLengh];		// 定义用户任务0的堆栈
OS_STK	TaskLED1Stk [TaskLED1StkSize];	// 定义任务TaskLED1的堆栈

void  Task0(void *pdata);				// Task0 任务0
void  TaskLED1(void *data);				// 任务TaskLED1

/*
*********************************************************************************************************
** 函数名称 ：main()
** 函数功能 ：c语言的主函数，由它启动多任务环境
*********************************************************************************************************
*/
int main (void)
{
	OSInit ();																										
	OSTaskCreate (Task0,(void *)0, &Task0Stk[Task0StkLengh - 1], 2);		
	OSStart ();
	return 0;															
}

/*
********************************************************************************************************
** 									Task0 任务0
** 							完成目标板初始化和创建TaskLED1任务
********************************************************************************************************
*/

void Task0	(void *pdata)
{
	pdata = pdata;
	TargetInit ();
	OSTaskCreate (TaskLED1,(void *)0, &TaskLED1Stk[TaskLED1StkSize - 1], 3);		
	
	while (1)
	{
		OSTimeDly(10);
	}
}

/*
********************************************************************************************************
** 									TaskLED1
** 								    LED1任务
********************************************************************************************************
*/
void  TaskLED1(void *pdata)
{
    pdata = pdata;                          	 	// 避免编译警告

	PINSEL2 = PINSEL2 & (~0x08);				    // P1[25:16]选择GPIO
				
    IO1DIR |= LED1;			                    	// 设置LED1控制口输出
    IO1SET  = LED1;
    
    for (;;)
    {
        IO1CLR = LED1;
        OSTimeDly(OS_TICKS_PER_SEC / 4);
        IO1SET = LED1;
        OSTimeDly(OS_TICKS_PER_SEC / 2);
    }
}

   
/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
