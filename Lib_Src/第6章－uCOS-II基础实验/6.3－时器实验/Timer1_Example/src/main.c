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
** Descriptions:		����uC/OS-II�Ķ�ʱ��1ʵ�顣
**
********************************************************************************************************/
#include "config.h"
#include "stdlib.h"

#define	TaskStkLengh	128			// Define the Task0 stack length �����û�����0�Ķ�ջ����
#define TaskStkSize		128			// �����û������ջ����
 
OS_STK	TaskStk [TaskStkLengh];		// Define the Task0 stack �����û�����0�Ķ�ջ
OS_STK  TaskStkTimer1[TaskStkSize];	// ����TaskTimer1�Ķ�ջ

void 	Task0(void *pdata);			// Task0 ����0
void 	TaskTimer1(void *pdata);	// TaskTimer1����

/*
*********************************************************************************************************
** �������� ��main����
** �������� ��uC/OS-II�����������������񻷾���
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
**                            Task0 ����0
**                           ��ʼ��Ŀ��壬����������TaskTimer1
********************************************************************************************************/

void Task0	(void *pdata)
{
	pdata = pdata;
	
	TargetInit ();			// Ŀ����ʼ��
	OSTaskCreate (TaskTimer1,(void *)0, &TaskStkTimer1[TaskStkSize - 1], 3);	// ����TaskTimer1	
	
	while (1)
	{
		OSTimeDly(10);
	}
}
  
/*********************************************************************************************************
**                            TaskTimer1 ����
**                           ������������ʱ�䣬���͵���λ����ʾ
********************************************************************************************************/

void TaskTimer1	(void *pdata)
{
	char s[40];
	pdata = pdata;
	
	T1MCR = 0x00;			// ��ֹ�ȽϹ���
	T1CCR = 0x00;			// ��ֹ������
		
	while (1)
	{
		T1TC = 0x00;					// �������ֵ
		T1TCR = 0x01;					// ������ʱ��
		OSTimeDly(OS_TICKS_PER_SEC);	// ��ʱ1��
		T1TCR = 0x00;					// ֹͣ������
		sprintf(s,"OSC is %uHz.", (uint32)T1TC);
		PC_DispStr(1, 1, s, DISP_FGND_YELLOW + DISP_BGND_BLUE);
	}
}
//DISP_FGND_YELLOW
//DISP_FGDN_YELLOW
    
/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
