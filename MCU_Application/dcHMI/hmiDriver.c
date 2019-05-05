/************************************版权申明********************************************
**                             广州大彩光电科技有限公司
**                             http://www.gz-dc.com
**-----------------------------------文件信息--------------------------------------------
** 文件名称:   hmi_driver.c
** 修改时间:   2018-05-18
** 文件说明:   用户MCU串口驱动函数库
** 技术支持：  Tel: 020-82186683  Email: hmi@gz-dc.com Web:www.gz-dc.com
--------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------*/
#include "hmiLib.h"
/*****************************************************************************/
#define TX_8(P1) SEND_DATA((P1)&0xFF)                    //发送单个字节
#define TX_8N(P,N) SendNU8((uint8_t *)P,N)                 //发送N个字节
#define TX_16(P1) TX_8((P1)>>8);TX_8(P1)                 //发送16位整数
#define TX_16N(P,N) SendNU16((uint16_t *)P,N)              //发送N个16位整数
#define TX_32(P1) TX_16((P1)>>16);TX_16((P1)&0xFFFF)     //发送32位整数

#if(CRC16_ENABLE)

xdata  uint16_t _crc16 = 0xffff;
/*! 
*  \brief  检查数据是否符合CRC16校验
*  \param buffer 待校验的数据
*  \param n 数据长度，包含CRC16
*  \param pcrc 校验码
*/
void AddCRC16(uint8_t *buffer,uint16_t n,uint16_t *pcrc)
{
    uint16_t i,j,carry_flag,a;

    for (i=0; i<n; i++)
    {
        *pcrc=*pcrc^buffer[i];
        for (j=0; j<8; j++)
        {
            a=*pcrc;
            carry_flag=a&0x0001;
            *pcrc=*pcrc>>1;
            if (carry_flag==1)
                *pcrc=*pcrc^0xa001;
        }
    }
}
/*! 
*  \brief  检查数据是否符合CRC16校验
*  \param buffer 待校验的数据，末尾存储CRC16
*  \param n 数据长度，包含CRC16
*  \return 校验通过返回1，否则返回0
*/
uint16_t CheckCRC16(uint8_t *buffer,uint16_t n)
{
    uint16_t crc0 = 0x0;
    uint16_t crc1 = 0xffff;

    if(n>=2)
    {
        crc0 = ((buffer[n-2]<<8)|buffer[n-1]);
        AddCRC16(buffer,n-2,&crc1);
    }

    return (crc0==crc1);
}
/*! 
*  \brief  发送一个字节
*  \param  c 
*/
void SEND_DATA(uint8_t c)
{
    AddCRC16(&c,1,&_crc16);
    hmiUartSendChar(c);
}
/*! 
*  \brief  帧头
*/
void BEGIN_CMD()
{
    TX_8(0XEE);
    _crc16 = 0XFFFF;                      //开始计算CRC16
}
/*! 
*  \brief  帧尾
*/
void END_CMD()
{
    xdata  uint16_t crc16 = _crc16;
    TX_16(crc16);                         //发送CRC16
    TX_32(0XFFFCFFFF);
}

#else//NO CRC16

#define SEND_DATA(P) 					hmiUartSendChar(P)//发送一个字节
#define BEGIN_CMD() 					TX_8(0XEE)//帧头
#define END_CMD() 						TX_32(0XFFFCFFFF)//帧尾

#endif


void SendStrings(uint8_t *str)
{
    while(*str)
    {
        TX_8(*str);
        str++;
    }
}

void SendNU8(uint8_t *pData,uint16_t nDataLen)
{
    uint16_t i = 0;
    for (;i<nDataLen;++i)
    {
        TX_8(pData[i]);
    }
}
/*! 
*  \brief  串口发送送N个16位的数据
*  \param  个数
*/
void SendNU16(uint16_t *pData,uint16_t nDataLen)
{
    xdata  uint16_t i = 0;
    for (;i<nDataLen;++i)
    {
        TX_16(pData[i]);
    }
}
/*! 
*  \brief  发送握手命令
*/
void SetHandShake()
{
    BEGIN_CMD();
    TX_8(0x04);
    END_CMD();
}


