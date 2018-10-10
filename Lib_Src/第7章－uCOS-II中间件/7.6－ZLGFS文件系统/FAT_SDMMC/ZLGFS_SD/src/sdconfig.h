/****************************************Copyright (c)**************************************************
**                               Guangzhou ZLG-MCU Development Co.,LTD.
**                                      graduate school
**                                 http://www.zlgmcu.com
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			sdconfig.h
** Last modified Date:	2005-3-11
** Last Version:		V2.0
** Descriptions:		SD/MMC 卡读写模块: 配置文件
**						Soft Packet of SD/MMC Card: configuration header file
**
**------------------------------------------------------------------------------------------------------
** Created by:			Ming Yuan Zheng
** Created date:		2005-1-6
** Version:				V1.0
** Descriptions:		初始版本 The original version
**
**------------------------------------------------------------------------------------------------------
** Modified by:			Ming Yuan Zheng
** Modified date:		2005-3-11
** Version:				V2.0
** Descriptions:		增加了对MMC卡的支持,增加了对UCOS-II的支持,使该模块不仅能运行于前后台系统,还可运行
**						于UCOS-II上
**------------------------------------------------------------------------------------------------------
** Modified by: 
** Modified date:
** Version:	
** Descriptions: 
**
********************************************************************************************************/

typedef unsigned char  INT8U;                   /* 无符号8位整型变量                        */
typedef signed   char  INT8;                    /* 有符号8位整型变量                        */
typedef unsigned short INT16U;                  /* 无符号16位整型变量                       */
typedef signed   short INT16;                   /* 有符号16位整型变量                       */
typedef unsigned int   INT32U;                  /* 无符号32位整型变量                       */
typedef signed   int   INT32;                   /* 有符号32位整型变量                       */
typedef float          FP32;                    /* 单精度浮点数（32位长度）                 */
typedef double         FP64;                    /* 双精度浮点数（64位长度）                 */

#define SD_UCOSII_EN			1			/* 是否在UCOS-II上运行本模块 */

#define SD_CRC_EN		   		0			/* 设置数据传输时是否使用CRC */

#define SPI_CLOCK				5529600		/* 正常通信时,SPI时钟频率(Hz) */

#define SD_BLOCKSIZE 			512			/* SD卡/MMC卡块的长度 */

#define SD_BLOCKSIZE_NBITS		9  

/* 下面函数不常用,如果用户不需要,可置为 0 裁剪指定函数 */

#define SD_ReadMultiBlock_EN    0			/* 是否使能读多块函数 */

#define SD_WriteMultiBlock_EN   0			/* 是否使能写多块函数 */

#define SD_EraseBlock_EN		0			/* 是否使能擦卡函数 */

#define SD_ProgramCSD_EN   		0			/* 是否使能写CSD寄存器函数 */
	
#define SD_ReadCID_EN	   		0			/* 是否使能读CID寄存器函数 */
	
#define	SD_ReadSD_Status_EN		0			/* 是否使能读SD_Status寄存器函数 */

#define	SD_ReadSCR_EN			0			/* 是否使能读SCR寄存器函数 */

/* LPC213x 硬件配置 */

/* SCK引脚 */
#define  SPI_SCK				(0x01 << 4)						
#define  SPI_SCK_GPIO()			PINSEL0 &= ~(0x03 << 8)			/* 设置 SCK 口为GPIO口 */
#define  SPI_SCK_OUT()			IODIR |= SPI_SCK				/* 设置 SCK 口为输出口 */
#define	 SPI_SCK_CLR()			IOCLR = SPI_SCK					/* 置 SCK 为低电平 */	

/* MISO 引脚 */	
#define  SPI_MISO				(0x01 << 5)						
#define  SPI_MISO_GPIO()		PINSEL0 &= ~(0x03 << 10)		/* 设置 MISO 口为GPIO口 */
#define  SPI_MISO_OUT()			IODIR |= SPI_MISO				/* 设置 MISO 口为输出口 */
#define	 SPI_MISO_CLR()			IOCLR = SPI_MISO				/* 置 MISO 为低电平 */

/* MOSI 引脚 */	
#define  SPI_MOSI				(0x01 << 6)
#define  SPI_MOSI_GPIO()		PINSEL0 &= ~(0x03 << 12)		/* 设置 MOSI 口为GPIO口 */
#define  SPI_MOSI_OUT()			IODIR |= SPI_MOSI				/* 设置 MOSI 口为输出口 */
#define	 SPI_MOSI_CLR()			IOCLR = SPI_MOSI				/* 置 MISO 为低电平 */

/* CS 引脚 */		
#define  SPI_CS      			(0x01 << 8)              	 	
#define  SPI_CS_GPIO()			PINSEL0 &= ~(0x03 << 16)	 	/* 设置 CS 口为GPIO口 */
#define  SPI_CS_OUT()			IODIR |= SPI_CS;			 	/* 设置 CS 口为输出口 */
#define	 SPI_CS_SET()			IOSET |= SPI_CS;				/* 置 CS 为高电平 */
#define	 SPI_CS_CLR()			IOCLR |= SPI_CS;				/* 置 CS 为低电平 */

/* 初始化 IO 口为SPI接口 */
#define  SPI_INIT()				PINSEL0 &= ~((0x03 << 8) + (0x03 << 10) + (0x03 << 12)); \
								PINSEL0 |= (0x01 << 8) + (0x01 << 10) + (0x01 << 12);
																
/* 电源控制引脚 */
#define  SD_POWER				(0x01 << 9)	
#define  SD_POWER_GPIO()		PINSEL0 &= ~(0x03 << 18)		/* 设置 POWER 口为GPIO口 */
#define  SD_POWER_OUT()			IODIR |= SD_POWER				/* 设置 POWER 口为输出口 */
#define  SD_POWER_OFF()			IOSET = SD_POWER				/* 置 POWER 为高电平 */
#define  SD_POWER_ON()			IOCLR = SD_POWER				/* 置 POWER 为低电平 */

/* 卡完全插入卡座检测引脚 */
#define  SD_INSERT				(0x01 << 10)		
#define  SD_INSERT_GPIO()		PINSEL0 &= ~(0x03 << 20)		/* 设置 INSERT 口为GPIO口 */	
#define  SD_INSERT_IN()			IODIR &= ~SD_INSERT				/* 设置 INSERT 口为输出口 */	
#define  SD_INSERT_STATUS()  	(IOPIN & SD_INSERT)				/* 读取 INSERT 口的状态 */

/* 卡写保护检测引脚 */
#define  SD_WP					(0x01 << 11)		
#define  SD_WP_GPIO()			PINSEL0 &= ~(0x03 << 22)		/* 设置 WP 口为GPIO口 */	
#define  SD_WP_IN()				IODIR &= ~SD_WP					/* 设置 WP 口为输出口 */	
#define  SD_WP_STATUS()  		(IOPIN & SD_WP)					/* 读取 WP 口的状态 */
