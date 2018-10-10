/****************************************Copyright (c)**************************************************
**                               广州周立功单片机发展有限公司
**                                     研    究    所
**                                        产品一部 
**
**                                 http://www.zlgmcu.com
**
**--------------文件信息--------------------------------------------------------------------------------
**文   件   名: uart0.c
**创   建   人: 陈明计
**最后修改日期: 2003年7月5日
**描        述: μCOS-II下LPC210x的SPI主模式底层驱动 
**              
**--------------历史版本信息----------------------------------------------------------------------------
** 创建人: 陈明计
** 版  本: v1.0
** 日　期: 2003年7月4日
** 描　述: 原始版本
**
**--------------当前版本修订------------------------------------------------------------------------------
** 修改人: 陈明计
** 日　期: 2003年7月11日
** 描　述: 更正注释
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/

#define IN_SPI
#include "config.h"

#ifndef  SPI_MOD
#define SPI_MOD     0
#endif 

static OS_EVENT *SPIReviceMbox;
static OS_EVENT *SPISem;
static uint8 UseSPITaskPro;
/*********************************************************************************************************
** 函数名称: SPIInit
** 功能描述: 初始化SPI总线为主模式
** 输　入: Fdiv：用于设定总线频率（总线频率=Fpclk/Fdiv)
**
** 输　出:TRUE  :成功
**        FALSE:失败
** 全局变量: UseSPITaskPro
** 调用模块: OSMboxCreate，OSSemCreate
**
** 作　者: 陈明计
** 日　期: 2003年7月4日
**-------------------------------------------------------------------------------------------------------
** 修改人: 陈明计
** 日　期: 2003年7月11日
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
        uint8 SPIInit(uint8 Fdiv)
{
    PINSEL0 = (PINSEL0 & 0xffff00ff) | 0x5500;  /* 选择管脚为SPI口 */

    SPI_SPCCR = Fdiv & 0xfe;                    /* 分频值 */
    SPI_SPCR = 0xa0 | SPI_MOD;                  /* 主机、允许中断 */

    UseSPITaskPro = OS_PRIO_SELF;               /* 避免任务不按照规范编写程序而使访问SPI混乱 */
    SPIReviceMbox = OSMboxCreate(NULL);         /* 用于中断返回收到的数据 */
    if (SPIReviceMbox == NULL)
    {
        return FALSE;
    }
    SPISem = OSSemCreate(1);                    /* 用于互斥访问SPI总线 */
    if (SPISem != NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*********************************************************************************************************
** 函数名称: GetSPIFlag
** 功能描述: 获取SPI状态 
** 输　入: 无
**
** 输　出:0  :空闲
**        1 :忙
** 全局变量: 无
** 调用模块: 无
**
** 作　者: 陈明计
** 日　期: 2003年7月5日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
        uint8 GetSPIFlag(void)
{
    OS_SEM_DATA SemData;
    
    if (OSSemQuery(SPISem, &SemData) == OS_NO_ERR)
    {
        if (SemData.OSCnt != 0)
        {
            return 0;
        }
    }
    return 1;
}

/*********************************************************************************************************
** 函数名称: SPIStart
** 功能描述: 开始访问SPI 
** 输　入: 无
**
** 输　出:TRUE  :成功
**        FALSE:失败
** 全局变量: 无
** 调用模块: 无
**
** 作　者: 陈明计
** 日　期: 2003年7月5日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
        uint8 SPIStart(void)
{
    uint8 err;
    
    OSSemPend(SPISem, 0, &err);
    UseSPITaskPro = GetOSPrioCur();
    return TRUE;
}

/*********************************************************************************************************
** 函数名称: SPIRW
** 功能描述: 读写SPI 
** 输　入: Rt  ：指向返回值存储位置
**        Data：发送的数据 
** 输　出:TRUE  :成功
**        FALSE:失败
** 全局变量: UseSPITaskPro
** 调用模块: OSMboxPend,GetOSPrioCur
**
** 作　者: 陈明计
** 日　期: 2003年7月5日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
        uint8 SPIRW(uint8 *Rt, uint8 Data)
{
    uint8 temp, err;
    
    temp = GetOSPrioCur();
    if (temp == UseSPITaskPro)
    {
        SPI_SPDR = Data;
        temp = (unsigned int)OSMboxPend(SPIReviceMbox, 0, &err);
        *Rt = temp;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*********************************************************************************************************
** 函数名称: SPIEnd
** 功能描述: 访问SPI结束
** 输　入: 无
**        
** 输　出:TRUE  :成功
**        FALSE:失败
** 全局变量: UseSPITaskPro
** 调用模块: OSSemPost,GetOSPrioCur
**
** 作　者: 陈明计
** 日　期: 2003年7月5日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
        uint8 SPIEnd(void)
{
    uint8 temp;
    
    temp = GetOSPrioCur();
    if (temp == UseSPITaskPro)
    {
        UseSPITaskPro = OS_PRIO_SELF;
        OSSemPost(SPISem);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*********************************************************************************************************
** 函数名称: SPI_Exception
** 功能描述: SPI中断服务程序
** 输　入: 无
**
** 输　出: 无
**         
** 全局变量: 无
** 调用模块: OSMboxPost
**
** 作　者: 陈明计
** 日　期: 2003年7月5日
**-------------------------------------------------------------------------------------------------------
** 修改人: 
** 日　期: 
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
        void SPI_Exception(void)
{
    uint8 temp, temp1;
    
    OS_ENTER_CRITICAL();
    temp = SPI_SPSR;
    if ((temp & 0x80) != 0)
    {
        temp1 = SPI_SPDR;
        OSMboxPost(SPIReviceMbox, (void *)temp1);
    }
    
    if ((temp & 0x10) != 0)
    {
        SPI_SPCR = 0xa0 | SPI_MOD;
    }
    SPI_SPINT = 0x01;    
    VICVectAddr = 0;            // 通知中断控制器中断结束
    OS_EXIT_CRITICAL();
}

/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
