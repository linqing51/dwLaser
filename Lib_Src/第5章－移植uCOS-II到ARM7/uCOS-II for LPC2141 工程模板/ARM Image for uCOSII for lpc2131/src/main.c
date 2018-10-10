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
** Modified by:
** Modified date:
** Version:
** Descriptions:
**
********************************************************************************************************/
#include "config.h"
#include "stdlib.h"

#define	TaskStkLengh	64			//Define the Task0 stack length 定义用户任务0的堆栈长度
 
OS_STK	TaskStk [TaskStkLengh];		//Define the Task0 stack 定义用户任务0的堆栈

void 	Task0(void *pdata);			//Task0 任务0

        int main (void)
{
	OSInit ();																										
	OSTaskCreate (Task0,(void *)0, &TaskStk[TaskStkLengh - 1], 2);		
	OSStart ();
	return 0;															
}
/*********************************************************************************************************
**                            Task0 任务0
********************************************************************************************************/

		void Task0	(void *pdata)
{
	pdata = pdata;
	TargetInit ();
	
	while (1)
	{
		OSTimeDly(10);
	}
}
   
/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
