/****************************************Copyright (c)**************************************************
**                               广州周立功单片机发展有限公司
**                                     研    究    所
**                                        ARM开发组
**
**                                 http://www.zlgmcu.com
**
**--------------文件信息--------------------------------------------------------------------------------
**文   件   名: flash.c
**创   建   人: 陈明计
**最后修改日期:  2003年9月3日
**描        述: FAT文件系统在PC上编译的软盘驱动程序（底层驱动）
**              
**--------------历史版本信息----------------------------------------------------------------------------
** 创建人: 陈明计
** 版  本: V1.0
** 日　期: 2003年9月3日
** 描　述: 原始版本
**
**--------------当前版本修订------------------------------------------------------------------------------
** 修改人: 
** 日　期:
** 描　述:
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/

#define IN_FLOPPY
#include "config.h"

uint32 GetVolumeFirstSect(uint8 Device)
{
	uint8 buffer[512];
	uint32 RelaStaSect;
	
	SD_ReadBlock(0, buffer);						/* 读SD卡的0块 */
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
** 函数名称: CFCammand
** 功能描述: 底层驱动程序与上层的接口程序
**
** 输　入: Cammand：DISK_INIT：驱动程序初始化
**                 DISK_CLOSE：关闭驱动器（移除驱动程序）                 
**                 DISK_CREATE_BOOT_SECTOR：重建引导扇区
**                 DISK_READ_SECTOR：读扇区
**                 DISK_WRITE_SECTOR：写扇区
**        Parameter：剩余参数
** 输　出: DISK_READ_OK：读扇区完成
**        DISK_READ_NOT_OK：读扇区失败
**        DISK_WRITE_OK：写扇区完成
**        DISK_WRITE_NOT_OK：写扇区失败
**        DISK_INIT_OK：初始化完成
**        DISK_INIT_NOT_OK：初始化失败
**        BAD_DISK_COMMAND：无效的命令
** 全局变量: 无
** 调用模块: 无
**
** 作　者: 陈明计
** 日　期: 2003年9月3日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
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
        case DISK_INIT:			/*设备初始化*/
            rt = DISK_INIT_NOT_OK;
            ret = SD_Initialize();
            if (ret == SD_NO_ERR)
            {
            	DiskInfo = GetEmptyDiskInfoAddr();
            	if (DiskInfo != NULL)
            	{
                	DiskInfo->DiakCommand = SDCammand;
                	DiskInfo->RsvdForLow = GetVolumeFirstSect(0);/*获取卷首扇区*/
                	rt = DISK_INIT_OK;
            	}
	        }
            break;
            
        case DISK_CLOSE:		
            rt = RETURN_OK;
            break;
            
        case DISK_READ_SECTOR:	/*读扇区*/
            rt = DISK_READ_NOT_OK;
            if(SD_ReadBlock(Dp->SectorIndex + Dp->RsvdForLow,Dp->Buf) == SD_NO_ERR)
            	rt = DISK_READ_OK;
            break;
            
        case DISK_WRITE_SECTOR:	/*写扇区*/
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
