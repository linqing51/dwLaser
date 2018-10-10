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
** Descriptions:		EasyARM2131 ����uCOS-II��GPIO���ʵ��2��
**
********************************************************************************************************/
#include "config.h"
//#include "stdlib.h"

#define	  LED1	(1 << 18)           	// P1.18����LED1
#define	  LED2	(1 << 19)           	// P1.19����LED2

#define	Task0StkLengh	64				// �����û�����0�Ķ�ջ����
#define	TaskLED1StkSize	128				// ��������TaskLED1�Ķ�ջ����
#define	TaskLED2StkSize	128				// ��������TaskLED2�Ķ�ջ����
 
OS_STK	Task0Stk [Task0StkLengh];		// �����û�����0�Ķ�ջ
OS_STK	TaskLED1Stk [TaskLED1StkSize];	// ��������TaskLED1�Ķ�ջ
OS_STK	TaskLED2Stk [TaskLED2StkSize];	// ��������TaskLED2�Ķ�ջ

void  Task0(void *pdata);				// Task0 ����0
void  TaskLED1(void *data);				// ����TaskLED1
void  TaskLED2(void *data);				// ����TaskLED2

/*
*********************************************************************************************************
** �������� ��main()
** �������� ��c���Ե����������������������񻷾�
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
** 									Task0 ����0
** 							���Ŀ����ʼ���ʹ���TaskLED1/2����
********************************************************************************************************
*/

void Task0	(void *pdata)
{
	pdata = pdata;
	TargetInit ();
	OSTaskCreate (TaskLED1,(void *)0, &TaskLED1Stk[TaskLED1StkSize - 1], 3);		
	OSTaskCreate (TaskLED2,(void *)0, &TaskLED2Stk[TaskLED2StkSize - 1], 4);		
	
	while (1)
	{
		OSTimeDly(10);
	}
}

/*
********************************************************************************************************
** 									TaskLED1
** 								    LED1����
********************************************************************************************************
*/
void  TaskLED1(void *pdata)
{
    pdata = pdata;                          	 	// ������뾯��

	PINSEL2 = PINSEL2 & (~0x08);				    // P1[25:16]ѡ��GPIO
				
    IO1DIR |= LED1;			                    	// ����LED1���ƿ����
    IO1SET  = LED1;
    
    for (;;)
    {
        IO1CLR = LED1;
        OSTimeDly(OS_TICKS_PER_SEC / 4);
        IO1SET = LED1;
        OSTimeDly(OS_TICKS_PER_SEC / 2);
    }
}

/*
********************************************************************************************************
** 									TaskLED2
** 								    LED2����
********************************************************************************************************
*/
void  TaskLED2(void *pdata)
{
    pdata = pdata;                          	 	// ������뾯��

	PINSEL2 = PINSEL2 & (~0x08);			    	// P1[25:16]ѡ��GPIO			
    IO1DIR |= LED2;			                    	// ����LED2���ƿ����
    IO1SET  = LED2;
    
    for (;;)
    {
        IO1CLR = LED2;
        OSTimeDly(OS_TICKS_PER_SEC / 2);
        IO1SET = LED2;
        OSTimeDly(OS_TICKS_PER_SEC / 1);
    }
}

   
/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
