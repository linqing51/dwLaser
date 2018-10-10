/****************************************Copyright (c)**************************************************
**                               Guangzhou ZLG-MCU Development Co.,LTD.
**                                      graduate school
**                                 http://www.zlgmcu.com
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			sdconfig.h
** Last modified Date:	2005-3-11
** Last Version:		V2.0
** Descriptions:		SD/MMC ����дģ��: �����ļ�
**						Soft Packet of SD/MMC Card: configuration header file
**
**------------------------------------------------------------------------------------------------------
** Created by:			Ming Yuan Zheng
** Created date:		2005-1-6
** Version:				V1.0
** Descriptions:		��ʼ�汾 The original version
**
**------------------------------------------------------------------------------------------------------
** Modified by:			Ming Yuan Zheng
** Modified date:		2005-3-11
** Version:				V2.0
** Descriptions:		�����˶�MMC����֧��,�����˶�UCOS-II��֧��,ʹ��ģ�鲻����������ǰ��̨ϵͳ,��������
**						��UCOS-II��
**------------------------------------------------------------------------------------------------------
** Modified by: 
** Modified date:
** Version:	
** Descriptions: 
**
********************************************************************************************************/

typedef unsigned char  INT8U;                   /* �޷���8λ���ͱ���                        */
typedef signed   char  INT8;                    /* �з���8λ���ͱ���                        */
typedef unsigned short INT16U;                  /* �޷���16λ���ͱ���                       */
typedef signed   short INT16;                   /* �з���16λ���ͱ���                       */
typedef unsigned int   INT32U;                  /* �޷���32λ���ͱ���                       */
typedef signed   int   INT32;                   /* �з���32λ���ͱ���                       */
typedef float          FP32;                    /* �����ȸ�������32λ���ȣ�                 */
typedef double         FP64;                    /* ˫���ȸ�������64λ���ȣ�                 */

#define SD_UCOSII_EN			1			/* �Ƿ���UCOS-II�����б�ģ�� */

#define SD_CRC_EN		   		0			/* �������ݴ���ʱ�Ƿ�ʹ��CRC */

#define SPI_CLOCK				5529600		/* ����ͨ��ʱ,SPIʱ��Ƶ��(Hz) */

#define SD_BLOCKSIZE 			512			/* SD��/MMC����ĳ��� */

#define SD_BLOCKSIZE_NBITS		9  

/* ���溯��������,����û�����Ҫ,����Ϊ 0 �ü�ָ������ */

#define SD_ReadMultiBlock_EN    0			/* �Ƿ�ʹ�ܶ���麯�� */

#define SD_WriteMultiBlock_EN   0			/* �Ƿ�ʹ��д��麯�� */

#define SD_EraseBlock_EN		0			/* �Ƿ�ʹ�ܲ������� */

#define SD_ProgramCSD_EN   		0			/* �Ƿ�ʹ��дCSD�Ĵ������� */
	
#define SD_ReadCID_EN	   		0			/* �Ƿ�ʹ�ܶ�CID�Ĵ������� */
	
#define	SD_ReadSD_Status_EN		0			/* �Ƿ�ʹ�ܶ�SD_Status�Ĵ������� */

#define	SD_ReadSCR_EN			0			/* �Ƿ�ʹ�ܶ�SCR�Ĵ������� */

/* LPC213x Ӳ������ */

/* SCK���� */
#define  SPI_SCK				(0x01 << 4)						
#define  SPI_SCK_GPIO()			PINSEL0 &= ~(0x03 << 8)			/* ���� SCK ��ΪGPIO�� */
#define  SPI_SCK_OUT()			IODIR |= SPI_SCK				/* ���� SCK ��Ϊ����� */
#define	 SPI_SCK_CLR()			IOCLR = SPI_SCK					/* �� SCK Ϊ�͵�ƽ */	

/* MISO ���� */	
#define  SPI_MISO				(0x01 << 5)						
#define  SPI_MISO_GPIO()		PINSEL0 &= ~(0x03 << 10)		/* ���� MISO ��ΪGPIO�� */
#define  SPI_MISO_OUT()			IODIR |= SPI_MISO				/* ���� MISO ��Ϊ����� */
#define	 SPI_MISO_CLR()			IOCLR = SPI_MISO				/* �� MISO Ϊ�͵�ƽ */

/* MOSI ���� */	
#define  SPI_MOSI				(0x01 << 6)
#define  SPI_MOSI_GPIO()		PINSEL0 &= ~(0x03 << 12)		/* ���� MOSI ��ΪGPIO�� */
#define  SPI_MOSI_OUT()			IODIR |= SPI_MOSI				/* ���� MOSI ��Ϊ����� */
#define	 SPI_MOSI_CLR()			IOCLR = SPI_MOSI				/* �� MISO Ϊ�͵�ƽ */

/* CS ���� */		
#define  SPI_CS      			(0x01 << 8)              	 	
#define  SPI_CS_GPIO()			PINSEL0 &= ~(0x03 << 16)	 	/* ���� CS ��ΪGPIO�� */
#define  SPI_CS_OUT()			IODIR |= SPI_CS;			 	/* ���� CS ��Ϊ����� */
#define	 SPI_CS_SET()			IOSET |= SPI_CS;				/* �� CS Ϊ�ߵ�ƽ */
#define	 SPI_CS_CLR()			IOCLR |= SPI_CS;				/* �� CS Ϊ�͵�ƽ */

/* ��ʼ�� IO ��ΪSPI�ӿ� */
#define  SPI_INIT()				PINSEL0 &= ~((0x03 << 8) + (0x03 << 10) + (0x03 << 12)); \
								PINSEL0 |= (0x01 << 8) + (0x01 << 10) + (0x01 << 12);
																
/* ��Դ�������� */
#define  SD_POWER				(0x01 << 9)	
#define  SD_POWER_GPIO()		PINSEL0 &= ~(0x03 << 18)		/* ���� POWER ��ΪGPIO�� */
#define  SD_POWER_OUT()			IODIR |= SD_POWER				/* ���� POWER ��Ϊ����� */
#define  SD_POWER_OFF()			IOSET = SD_POWER				/* �� POWER Ϊ�ߵ�ƽ */
#define  SD_POWER_ON()			IOCLR = SD_POWER				/* �� POWER Ϊ�͵�ƽ */

/* ����ȫ���뿨��������� */
#define  SD_INSERT				(0x01 << 10)		
#define  SD_INSERT_GPIO()		PINSEL0 &= ~(0x03 << 20)		/* ���� INSERT ��ΪGPIO�� */	
#define  SD_INSERT_IN()			IODIR &= ~SD_INSERT				/* ���� INSERT ��Ϊ����� */	
#define  SD_INSERT_STATUS()  	(IOPIN & SD_INSERT)				/* ��ȡ INSERT �ڵ�״̬ */

/* ��д����������� */
#define  SD_WP					(0x01 << 11)		
#define  SD_WP_GPIO()			PINSEL0 &= ~(0x03 << 22)		/* ���� WP ��ΪGPIO�� */	
#define  SD_WP_IN()				IODIR &= ~SD_WP					/* ���� WP ��Ϊ����� */	
#define  SD_WP_STATUS()  		(IOPIN & SD_WP)					/* ��ȡ WP �ڵ�״̬ */
