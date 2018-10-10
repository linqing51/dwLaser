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
** Modified date:		2005-03-07
** Version:
** Descriptions:		EasyARM2131上的第一个基于uC/OS-II的例子。
**						按一下按键KEY1，松开后蜂鸣器响2声。
********************************************************************************************************/
#include "config.h"
#include "stdlib.h"

#define	TASK_STK_SIZE	64			// 定义用户任务的堆栈长度

OS_STK        TaskStartStk[TASK_STK_SIZE];									//(2)
OS_STK        TaskStk[TASK_STK_SIZE];										//(3)

/* 函数声明 */
void  Task1(void *pdata);
void  Task2(void *pdata);
void  BeeMoo(void);
void  BeeNoMoo(void);
uint32 GetKey(void);

#define 	KEY1	1 << 16		// P0.16-KEY1
#define		BEEP	1 << 7		// P0.7-BEEP

/*
*********************************************************************************************************
** 函数名称 ：main()
** 函数功能 ：uC/OS-II主函数，启动多任务环境。
*********************************************************************************************************
*/
int main (void)
{
    OSInit();																//(4)
    OSTaskCreate(Task1, (void *)0, &TaskStartStk[TASK_STK_SIZE - 1], 0);	//(5)
    OSStart();																//(6)
    return 0;																//(7)
}

/*
*********************************************************************************************************
** 						任务1－Task1()
**      				键盘扫描（具有去抖动功能）
*********************************************************************************************************
*/
void  Task1(void *pdata)
{
    pdata = pdata;                            	/* 避免编译警告 */
    TargetInit();                               /* 目标板初始化 */
    for (;;)																		//(1)
    {
        OSTimeDly(OS_TICKS_PER_SEC / 50);   	/* 延时20毫秒 */					//(2)
        if (GetKey() != KEY1)					/* GetKey用于获取键盘当前状态 */
        {
            continue;							/* 不是KEY1不理会 */
        }
        OSTimeDly(OS_TICKS_PER_SEC / 50);    	/* 延时20毫秒，用于去抖 */			//(3)
        if (GetKey() != KEY1)					/* 还是KEY1才正确  */
        {
            continue;
        }
        OSTaskCreate(Task2, (void *)0, &TaskStk[TASK_STK_SIZE - 1], 10);			//(4)
        while (GetKey() != 0)					/* 等待松开按键 */
        {
            OSTimeDly(OS_TICKS_PER_SEC / 50);   /* 延时20毫秒 */					//(5)
        }
    }
}

/*
*********************************************************************************************************
** 						任务2－Task2()
**      				蜂鸣器鸣叫
*********************************************************************************************************
*/
void  Task2(void *pdata)
{	/*  书中没有给出管脚连接的代码  */
	PINSEL0 = 0;				// 设置管脚连接
	IO0DIR = BEEP;				// 蜂鸣器控制口输出
	
    pdata = pdata;                           	/* 避免编译警告 */
    BeeMoo();									/* 使蜂鸣器鸣叫 */
    OSTimeDly(OS_TICKS_PER_SEC / 8);			/* 延时 */							//(1)
    BeeNoMoo();									/* 使蜂鸣器停止鸣叫 */
    OSTimeDly(OS_TICKS_PER_SEC / 4);			/* 延时 */							//(2)
    BeeMoo();									/* 使蜂鸣器鸣叫 */
    OSTimeDly(OS_TICKS_PER_SEC / 8); 			/* 延时 */							//(3)
    BeeNoMoo();									/* 使蜂鸣器停止鸣叫 */
    OSTaskDel(OS_PRIO_SELF);					/* 删除自己 */						//(4)
}

/*
*********************************************************************************************************
										BeeMoo()
										BeeNoMoo()
										GetKey()
									 函数的具体实现
*********************************************************************************************************
*/

/* 蜂鸣器鸣叫 */
void  BeeMoo(void)
{
	IO0CLR = BEEP;
}
/* 蜂鸣器不鸣叫 */
void  BeeNoMoo(void)
{
	IO0SET = BEEP;
}
/* 读取按键 */
uint32 GetKey(void)
{
	volatile uint32 key;

	key = IO0PIN & KEY1;
	return key;
}
   
/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
