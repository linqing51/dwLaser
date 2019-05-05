/************************************��Ȩ����********************************************
**                             ���ݴ�ʹ��Ƽ����޹�˾
**                             http://www.gz-dc.com
**-----------------------------------�ļ���Ϣ--------------------------------------------
** �ļ�����:   hmi_driver.c
** �޸�ʱ��:   2018-05-18
** �ļ�˵��:   �û�MCU��������������
** ����֧�֣�  Tel: 020-82186683  Email: hmi@gz-dc.com Web:www.gz-dc.com
--------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------*/
#include "hmiLib.h"
/*****************************************************************************/
#define TX_8(P1) SEND_DATA((P1)&0xFF)                    //���͵����ֽ�
#define TX_8N(P,N) SendNU8((uint8_t *)P,N)                 //����N���ֽ�
#define TX_16(P1) TX_8((P1)>>8);TX_8(P1)                 //����16λ����
#define TX_16N(P,N) SendNU16((uint16_t *)P,N)              //����N��16λ����
#define TX_32(P1) TX_16((P1)>>16);TX_16((P1)&0xFFFF)     //����32λ����

#if(CRC16_ENABLE)

xdata  uint16_t _crc16 = 0xffff;
/*! 
*  \brief  ��������Ƿ����CRC16У��
*  \param buffer ��У�������
*  \param n ���ݳ��ȣ�����CRC16
*  \param pcrc У����
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
*  \brief  ��������Ƿ����CRC16У��
*  \param buffer ��У������ݣ�ĩβ�洢CRC16
*  \param n ���ݳ��ȣ�����CRC16
*  \return У��ͨ������1�����򷵻�0
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
*  \brief  ����һ���ֽ�
*  \param  c 
*/
void SEND_DATA(uint8_t c)
{
    AddCRC16(&c,1,&_crc16);
    hmiUartSendChar(c);
}
/*! 
*  \brief  ֡ͷ
*/
void BEGIN_CMD()
{
    TX_8(0XEE);
    _crc16 = 0XFFFF;                      //��ʼ����CRC16
}
/*! 
*  \brief  ֡β
*/
void END_CMD()
{
    xdata  uint16_t crc16 = _crc16;
    TX_16(crc16);                         //����CRC16
    TX_32(0XFFFCFFFF);
}

#else//NO CRC16

#define SEND_DATA(P) 					hmiUartSendChar(P)//����һ���ֽ�
#define BEGIN_CMD() 					TX_8(0XEE)//֡ͷ
#define END_CMD() 						TX_32(0XFFFCFFFF)//֡β

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
*  \brief  ���ڷ�����N��16λ������
*  \param  ����
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
*  \brief  ������������
*/
void SetHandShake()
{
    BEGIN_CMD();
    TX_8(0x04);
    END_CMD();
}


