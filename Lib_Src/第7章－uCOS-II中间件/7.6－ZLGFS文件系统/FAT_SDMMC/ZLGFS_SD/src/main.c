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


#define	TaskStkLengh	256			//Define the Task0 stack length �����û�����0�Ķ�ջ����
 
OS_STK	TaskStartStk[TaskStkLengh];		//Define the Task0 stack �����û�����0�Ķ�ջ
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

void 	Task0(void *pdata);			//Task0 ����0

        int main (void)
{
	OSInit ();																										
	OSTaskCreate(Task0,(void *)0, &TaskStartStk[TaskStkLengh - 1], 1);		
    OSTaskCreate(OSFileTask, (void *)0, &TaskStk[255], 0);
	OSStart ();
	return 0;															
}
/*********************************************************************************************************
**                            Task0 ����0
********************************************************************************************************/
char *FileName = "a:\\��Ƭ��.txt";
char WritFileData[]=
"\r\n******************Copyright (c) ��������Ƭ����չ���޹�˾***********************\r\n\
\r\n\
    ZLG/FS�ǹ�����������Ƭ����չ���޹�˾����������Ƕ��ʽϵͳ������С���ļ�ϵͳ��\r\n\
��ZLGϵ���м������Ҫ��Ա֮һ��������FAT12��FAT16��FAT32�߶ȼ��ݵ��ļ�ϵͳ������\r\n\
ֱ������˵��Խ����ļ������ǿ���ֲ�ġ��ɹ̻����ļ�ϵͳ����������ǰ��̨ϵͳ��Ҳ��\r\n\
���ڶ����񻷾���ĿǰZLG/FS�����°汾Ϊ1.0��\
\r\n\
\r\n*********************************ARM��������************************************\r\n";

		void Task0	(void *pdata)
{
    char buf1[4];
    char buf[20];
    HANDLE FHandle;

	pdata = pdata;
	TargetInit ();
	
	OSAddFileDriver(SDCammand);			/*����ATA�豸0*/

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
