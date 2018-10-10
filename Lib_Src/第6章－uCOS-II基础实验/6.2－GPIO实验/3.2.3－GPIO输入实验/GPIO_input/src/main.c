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
** Descriptions:		EasyARM2131����uC/OS-II��GPIO����ʵ�顣
**                      ��KEY1��������������2������LPC2100ʵ���޸Ķ�����
**
********************************************************************************************************/
#include "config.h"
//#include "stdlib.h"

#define BEEP 1 << 7						// P0.7����BEEP
#define KEY1 1 << 16					// P0.16��KEY1

#define	TaskStkSize	64					// �����û�����0�Ķ�ջ����
 
OS_STK	TaskStk [TaskStkSize];			// �����û�����0�Ķ�ջ
OS_STK  TaskBeepStk [TaskStkSize];		// ����TaskBeep�Ķ�ջ
OS_STK  TaskKey1Stk [TaskStkSize];		// ����TaskKey1�Ķ�ջ

void 	Task0(void *pdata);				// Task0 ����0
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
**                            Task0 ����0
**                      Ŀ����ʼ����������������
*******************************************************************************************************
*/
void Task0	(void *pdata)
{
	pdata = pdata;

	TargetInit ();
   
    PINSEL0 = (PINSEL0 & 0xffff3fff);                         		 		// P0.16����GPIO
    PINSEL1 = (PINSEL1 & 0xfffffffc);
    IO0DIR &= ~KEY1;			                               				// ����KEY1Ϊ����
    IO0SET  = BEEP;
    IO0DIR |= BEEP;			                                  				// ���÷�����Ϊ���

    OSTaskCreate(TaskBeep, (void *)0, &TaskBeepStk[TaskStkSize - 1], 3); 	// ��������TaskBeep�����ȼ�Ϊ3
    OSTaskCreate(TaskKey1, (void *)0, &TaskKey1Stk[TaskStkSize - 1], 4); 	// ��������TaskKey1�����ȼ�Ϊ4

	while (1)
	{
		OSTimeDly(10);
	}
}

/*
********************************************************************************************************
**                            TaskBeep
**                            ����������
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
**                            �������
*******************************************************************************************************
*/
void TaskKey1 (void *pdata)
{
	pdata = pdata;
	
    for (;;)
    {
        OSTimeDly(OS_TICKS_PER_SEC / 50);    	// ��ʱ20����
        if ((IO0PIN & KEY1) != 0)
        {
            continue;
        }
        OSTimeDly(OS_TICKS_PER_SEC / 50);    	// ��ʱ20����
        if ((IO0PIN & KEY1) != 0)
        {
            continue;
        }
        OSTaskResume(3);						// �ָ�TaskBeep���񣬲���Ϊ���ȼ���Ҫ��TaskBeep�����ȼ�һ��
        while ((IO0PIN & KEY1) == 0)
        {
            OSTimeDly(OS_TICKS_PER_SEC / 50); 	// ��ʱ20����
        }
    }
}
    
/*
********************************************************************************************************
**                            End Of File
*******************************************************************************************************
*/
