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
** Descriptions:		�����ı�PWMռ�ձȣ�ʹ������
**
********************************************************************************************************/
#include "config.h"
#include "stdlib.h"

#define KEY1			(1 << 16)	// P0.16����KEY1
#define	TaskStkLengh	64			// Define the Task0 stack length �����û�����0�Ķ�ջ����
#define TaskStkSize		64			// TaskPWM�����ջ����
 
OS_STK	TaskStk [TaskStkLengh];		// Define the Task0 stack �����û�����0�Ķ�ջ
OS_STK	TaskPWMStk[TaskStkSize];	// TaskPWM�����ջ
OS_STK	TaskKEY1Stk[TaskStkSize];	// TaskKEY1�����ջ

OS_EVENT *PWMBox;

void 	Task0(void *pdata);			// Task0 ����0
void 	TaskPWM(void *pdata);		// TaskPWM
void 	TaskKEY1(void *pdata);		// TaskKEY1

/*
**********************************************************************************************************
** �������� ��main()
** �������� ��uC/OS-II�����������������񻷾���
**********************************************************************************************************
*/
int main (void)
{
	OSInit ();
	PWMBox = OSMboxCreate((void *)0);		// ��������																										;
	
	OSTaskCreate (Task0,(void *)0, &TaskStk[TaskStkLengh - 1], 2);		
	OSStart ();
	return 0;															
}

/*********************************************************************************************************
**                            Task0 ����0
**                    ��ʼ��Ŀ��壬������TaskPWM��TaskKEY1����
********************************************************************************************************/
void Task0	(void *pdata)
{
	pdata = pdata;
	
	TargetInit ();
	
	PINSEL0 = (PINSEL0&(~(3<<18)))|(2<<18);	// P0.9ѡ��
	IO0DIR &= ~KEY1;						// ����KEY1Ϊ����

	PWMPR = 0x00;							// ����Ƶ������ʱ��ΪFpclk
	PWMMCR = 0x02;							// ����MR0ƥ��ʱ��λTC
	PWMMR0 = (Fpclk+500)/1000;				// ����PWM����Ϊ1ms
	PWMMR6 = (Fpclk+500)/2000;				// ����PWMռ�ձ�Ϊ50��
	PWMLER = 1 | (1<<6);					// MR0��MR6����
	PWMPCR = 1 << 14;						// ����PWM6���������PWM
	PWMTCR = 1 |(1 << 3);					// ����PWM��ʱ��
	
	OSTaskCreate (TaskPWM,(void *)0, &TaskPWMStk[TaskStkSize - 1], 3);	// ����TaskPWM����		
	OSTaskCreate (TaskKEY1,(void *)0, &TaskKEY1Stk[TaskStkSize - 1], 4);// ����TaskKEY1����
	
	while (1)
	{
		OSTimeDly(10);
	}
}

/*********************************************************************************************************
**                            TaskPWM ����
**                       �ȴ���Ϣ�����ı�PWMռ�ձ�
********************************************************************************************************/
void TaskPWM(void *pdata)
{
	uint8 err;
	uint32 *msg;
	
	pdata = pdata;
	
	while (1)
	{
		msg = OSMboxPend(PWMBox, 0, &err);	// ����TaskKey1��������Ϣ
		PWMMR6 = msg[0];					// �ı�ռ�ձ�
		PWMLER = 0x41;						// ����PWM������ռ�ձ�
	}
}  

/*********************************************************************************************************
**                            TaskKEY1 ����
**                       ��ѯ��������TaskPWM���͸ı�����Ϣ
********************************************************************************************************/

void TaskKEY1(void *pdata)
{
	uint8 err;
	volatile  uint32 PWMData = (Fpclk+500)/2000;
	
	pdata = pdata;
	
	while (1)
	{
		OSTimeDly(OS_TICKS_PER_SEC/50);				//��ʱ20ms
		if ((IO0PIN & KEY1) !=0)
		{
		 	continue;
		}
		OSTimeDly(OS_TICKS_PER_SEC/50);				//��ʱ20ms
		if ((IO0PIN & KEY1) !=0)
		{
			continue;
		}
		
		PWMData += (Fpclk+500)/20000;				// �ı����ڿ���ռ�ձȵĲ���
		if (PWMData >= (Fpclk+500)/1000) PWMData=0;
		
		err = OSMboxPost(PWMBox, (void*)&PWMData);	// ��TaskPWM������Ϣ
		
		while((IO0PIN&KEY1) == 0)
		{
			OSTimeDly(OS_TICKS_PER_SEC/50);			//��ʱ20ms
		}
	}
}

/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
