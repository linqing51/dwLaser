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


#define	TaskStkLengh	256			//Define the Task0 stack length 定义用户任务0的堆栈长度
 
OS_STK	TaskStartStk[TaskStkLengh];		//Define the Task0 stack 定义用户任务0的堆栈
OS_STK  TaskStk[256];

        char *strupr(char *Str)
{
    char *cp;
    
    cp = Str;
    while (*cp != 0)
    {
        if (*cp >= 'a' && *cp <= 'z' )
        {
            *cp -=  'a' - 'A';
        }
        cp++;
    }
    return Str;
}

void 	Task0(void *pdata);			//Task0 任务0

        int main (void)
{
	OSInit ();																										
	OSTaskCreate(Task0,(void *)0, &TaskStartStk[TaskStkLengh - 1], 1);		
    OSTaskCreate(OSFileTask, (void *)0, &TaskStk[255], 0);
	OSStart ();
	return 0;															
}
/*********************************************************************************************************
**                            Task0 任务0
********************************************************************************************************/
char *FileName = "a:\\单片机.txt";
char WritFileData[]=
"\r\n******************Copyright (c) 周立功单片机发展有限公司***********************\r\n\
\r\n\
    ZLG/FS是广州周立功单片机发展有限公司开发的面向嵌入式系统开发的小型文件系统，\r\n\
是ZLG系列中间件的重要成员之一。它是与FAT12、FAT16、FAT32高度兼容的文件系统，可以\r\n\
直接与个人电脑交换文件。它是可移植的、可固化的文件系统，可以用于前后台系统，也可\r\n\
用于多任务环境。目前ZLG/FS的最新版本为1.0。\
\r\n\
\r\n*********************************ARM开发部门************************************\r\n";

		void Task0	(void *pdata)
{
    char buf1[4];
    char buf[20];
    HANDLE FHandle;

	pdata = pdata;
	TargetInit ();
	
	OSAddFileDriver(SDCammand);			/*增加ATA设备0*/

    strcpy(buf1, "rw");
    strcpy(buf, FileName);
    FHandle = OSFileOpen(buf, buf1);
    OSFileSeek(FHandle, 0, SEEK_END);
    OSFileWrite(WritFileData, sizeof(WritFileData), FHandle);
    OSFileClose(FHandle);
    strcpy(buf, "a:\\ARM&FATS");
	OSMakeDir(buf);
    strcpy(buf, "dir2.dir");
    OSRemoveDir(buf);

    OSAllCacheWriteBack();
    OSRemoveFileDriver(0);
    while (1);
}
   
/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
