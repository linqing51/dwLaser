/****************************************Copyright (c)**************************************************
**                               ������������Ƭ����չ���޹�˾
**                                     ��    ��    ��
**                                        ARM������
**
**                                 http://www.zlgmcu.com
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: flash.c
**��   ��   ��: ������
**����޸�����:  2003��9��3��
**��        ��: FAT�ļ�ϵͳ��PC�ϱ���������������򣨵ײ�������
**              
**--------------��ʷ�汾��Ϣ----------------------------------------------------------------------------
** ������: ������
** ��  ��: V1.0
** �ա���: 2003��9��3��
** �衡��: ԭʼ�汾
**
**--------------��ǰ�汾�޶�------------------------------------------------------------------------------
** �޸���: 
** �ա���:
** �衡��:
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/

#define IN_FLOPPY
#include "config.h"

uint32 GetVolumeFirstSect(uint8 Device)
{
	uint8 buffer[512];
	uint32 RelaStaSect;
	
	SD_ReadBlock(0, buffer);						/* ��SD����0�� */
	if((buffer[510]==0x55)&&(buffer[511]==0xAA))
	{
		if(((buffer[0]==0xEB)&&(buffer[2]==0x90))||(buffer[0] == 0xE9))/**/
		{
			RelaStaSect = 0;
		}
		else
		{
			RelaStaSect = buffer[454]+ 
					 	  buffer[455]*0x100 + 
					 	  buffer[456]*0x10000 + 
					 	  buffer[457]*0x1000000;

		}
	}
	return RelaStaSect;	
}

/*********************************************************************************************************
** ��������: CFCammand
** ��������: �ײ������������ϲ�Ľӿڳ���
**
** �䡡��: Cammand��DISK_INIT�����������ʼ��
**                 DISK_CLOSE���ر����������Ƴ���������                 
**                 DISK_CREATE_BOOT_SECTOR���ؽ���������
**                 DISK_READ_SECTOR��������
**                 DISK_WRITE_SECTOR��д����
**        Parameter��ʣ�����
** �䡡��: DISK_READ_OK�����������
**        DISK_READ_NOT_OK��������ʧ��
**        DISK_WRITE_OK��д�������
**        DISK_WRITE_NOT_OK��д����ʧ��
**        DISK_INIT_OK����ʼ�����
**        DISK_INIT_NOT_OK����ʼ��ʧ��
**        BAD_DISK_COMMAND����Ч������
** ȫ�ֱ���: ��
** ����ģ��: ��
**
** ������: ������
** �ա���: 2003��9��3��
**-------------------------------------------------------------------------------------------------------
** �޸���:
** �ա���:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
        uint16 SDCammand(uint8 Cammand, void *Parameter)
{
	uint8 ret;
    uint16 rt;
    Disk_RW_Parameter * Dp;
    Disk_Info *DiskInfo;
    
    Dp = (Disk_RW_Parameter *)Parameter;

    switch (Cammand)
    {
        case DISK_INIT:			/*�豸��ʼ��*/
            rt = DISK_INIT_NOT_OK;
            ret = SD_Initialize();
            if (ret == SD_NO_ERR)
            {
            	DiskInfo = GetEmptyDiskInfoAddr();
            	if (DiskInfo != NULL)
            	{
                	DiskInfo->DiakCommand = SDCammand;
                	DiskInfo->RsvdForLow = GetVolumeFirstSect(0);/*��ȡ��������*/
                	rt = DISK_INIT_OK;
            	}
	        }
            break;
            
        case DISK_CLOSE:		
            rt = RETURN_OK;
            break;
            
        case DISK_READ_SECTOR:	/*������*/
            rt = DISK_READ_NOT_OK;
            if(SD_ReadBlock(Dp->SectorIndex + Dp->RsvdForLow,Dp->Buf) == SD_NO_ERR)
            	rt = DISK_READ_OK;
            break;
            
        case DISK_WRITE_SECTOR:	/*д����*/
            rt = DISK_WRITE_NOT_OK;
            if(SD_WriteBlock(Dp->SectorIndex + Dp->RsvdForLow,Dp->Buf) == SD_NO_ERR)
                rt = DISK_WRITE_OK;
            break;
            
        default:
            rt = BAD_DISK_COMMAND;
            break;
    }
    return rt;
}

/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
