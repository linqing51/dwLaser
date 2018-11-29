#include "eprom.h"
/*****************************************************************************/
#define CONFIG_EPROM_I2C_BUS				&iic0
#define CONFIG_EPROM_ADDRESS				0xA0
#define CONFIG_EPROM_SIZE					8196
/*****************************************************************************/


void eprom_writePage(uint8_t *buffer, uint8_t addr)
{//EPROM–¥»Î“ª“≥
//	uint8_t acktemp;
//	int i;
//	/*write a page to at24c02*/
//	iic_start(CONFIG_EPROM_I2C_BUS);
//	iic_writeByte(CONFIG_EPROM_I2C_BUS, CONFIG_EPROM_ADDRESS);
//	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
//	iic_writeByte(CONFIG_EPROM_I2C_BUS, addr);//address
//	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
//	for(i = 0;i < 7;i ++)
//	{
//		iic_writeByte(CONFIG_EPROM_I2C_BUS, buffer[i]);
//		if(! iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS))
//		{
//			iic_stop(CONFIG_EPROM_I2C_BUS);
//		}
//	}
//	iic_stop(CONFIG_EPROM_I2C_BUS);
}


void eprom_readBytes(uint8_t addr, uint8_t *rbuf, uint32_t len)
{//EPROM¡¨–¯∂¡»°◊÷Ω⁄
	
}


//void eeprom_dump(void)
//{
//	uint8_t *pbuf;
//	rt_int16_t i,j;
//	rt_device_t dev;
//	pbuf = RT_NULL;
//	dev = RT_NULL;
//	pbuf = rt_malloc(CONFIG_EE_MEM_SIZE);
//	
//		rt_device_read(dev, 0, pbuf, CONFIG_EE_MEM_SIZE );
//		rt_device_close(dev);
//		for (i = 0; i < 512; i++)
//		{
//			rt_kprintf("0x%08X:",(i*16));
//			for (j = 0; j < 16; j++)
//			{	
//				rt_kprintf("0x%02X ", *(pbuf + i*16 +j));
//			}
//			rt_kprintf("\n");
//		}
//	}
//	else
//	{
//		rt_kprintf("Dump EEPROM Fail\n");
//	}
//	if(pbuf != RT_NULL)
//		rt_free(pbuf);
//}
//rt_int8_t eeprom_reset(void)
//{//≤¡≥˝EEPROM≤¢≤Âø’
//	uint8_t *pbuf;
//	rt_uint16_t i;

//	pbuf = RT_NULL;
//	pbuf = rt_malloc(CONFIG_EE_MEM_SIZE);
//	memset(pbuf, 0x0, CONFIG_EE_MEM_SIZE);
//	eprom_writeOneByte(uint8_t addr, uint8_t thedata);
//		if (rt_device_write(dev, 0, pbuf, CONFIG_EE_MEM_SIZE ) == CONFIG_EE_MEM_SIZE)
//			rt_kprintf("Write Success\n");
//		rt_device_read(dev, 0, pbuf, CONFIG_EE_MEM_SIZE );
//		rt_device_close(dev);
//		for (i = 0; i < CONFIG_EE_MEM_SIZE; i++)
//		{
//		if (*(pbuf + i) != 0x0)
//			rt_free(pbuf);
//			return 0;
//		}
//		rt_free(pbuf);
//		return 1;
//	}
//	else
//	{
//		if(pbuf != RT_NULL)
//		{
//			rt_free(pbuf);
//		}
//		return -1;
//	}
//}

//uint8_t eprom_test(void)
//{//eprom–¥»Î∂¡»°≤‚ ‘
//	uint8_t *pwbuf,*prbuf;
//	uint16_t size;
//	time_t now;
//	pwbuf = rt_malloc(CONFIG_EE_MEM_SIZE);
//	prbuf = rt_malloc(CONFIG_EE_MEM_SIZE);
//	size = CONFIG_EE_MEM_SIZE;
//	if ((pwbuf != RT_NULL) & (prbuf != RT_NULL))
//	{
//		time(&now);
//		rt_kprintf("EEPROM Test:Start At %s\n",ctime(&now));
//		rt_kprintf("EEPROM SIZE:0x%x Bytes\n",size);
//		//ÃÓ≥‰≤‚ ‘-ÃÓ≥‰0x00
//		rt_kprintf("EEPROM Test:Fill 0x00\n");
//		for(size = 0;size < CONFIG_EE_MEM_SIZE;size++)
//		{
//			*(pwbuf + size) = 0x00;
//		}
//		rt_device_open(dev, RT_DEVICE_FLAG_ACTIVATED);
//		if (rt_device_write(dev, 0, pwbuf, CONFIG_EE_MEM_SIZE ) == CONFIG_EE_MEM_SIZE)//–¥»Î
//		{
//			rt_kprintf("EEPROM Test:Fill 0x00 Write Success\n");
//		}
//		else
//		{
//			rt_kprintf("EEPROM Test:Fill 0x00 Write Fail\n");
//			/*  Õ∑≈ƒ⁄¥ÊøÈ*/
//			rt_free(pwbuf);
//			rt_free(prbuf);
//			rt_device_close(dev);
//			return 0;
//		}
//		rt_device_read(dev, 0, prbuf, CONFIG_EE_MEM_SIZE );//∂¡ªÿ
//		for (size = 0; size < CONFIG_EE_MEM_SIZE; size++)
//		{
//			if (*(pwbuf + size) != *(prbuf + size))
//			{
//				rt_kprintf("EEPROM Test:Fill 0x00 Failed %X != %X at %d\n", *(pwbuf + size), *(prbuf + size), size);
//				/*  Õ∑≈ƒ⁄¥ÊøÈ*/
//				rt_free(pwbuf);
//				rt_free(prbuf);
//				rt_device_close(dev);
//				return 0;
//			}
//		}
//		rt_kprintf("EEPROM Test:Fill 0x00 Sucess\n");
//		//ÃÓ≥‰≤‚ ‘-ÃÓ≥‰0x5A
//		rt_kprintf("EEPROM Test:Fill 0x5A\n");
//		for(size = 0;size < CONFIG_EE_MEM_SIZE;size++)
//		{
//			*(pwbuf + size) = 0x5A;
//		}
//		if (rt_device_write(dev, 0, pwbuf, CONFIG_EE_MEM_SIZE ) == CONFIG_EE_MEM_SIZE)//–¥»Î
//		{
//			rt_kprintf("EEPROM Test:Fill 0x5A Write Success\n");
//		}
//		else
//		{
//			rt_kprintf("EEPROM Test:Fill 0x5A Write Fail\n");
//			/*  Õ∑≈ƒ⁄¥ÊøÈ*/
//			rt_free(pwbuf);
//			rt_free(prbuf);
//			rt_device_close(dev);
//			return 0;
//		}
//		rt_device_read(dev, 0, prbuf, CONFIG_EE_MEM_SIZE );//∂¡ªÿ
//		for (size = 0; size < CONFIG_EE_MEM_SIZE; size++)
//		{
//			if (*(pwbuf + size) != *(prbuf + size))
//			{
//				rt_kprintf("EEPROM Test:Fill 0x5A Failed %X != %X at %d\n", *(pwbuf + size), *(prbuf + size), size);
//				/*  Õ∑≈ƒ⁄¥ÊøÈ*/
//				rt_free(pwbuf);
//				rt_free(prbuf);
//				rt_device_close(dev);
//				return 0;
//			}
//		}
//		rt_kprintf("EEPROM Test:Fill 0x5A Sucess\n");
//		//ÀÊª˙ÃÓ≥‰
//		rt_kprintf("EEPROM Test:Fill Random\n");
//		for(size =0;size < CONFIG_EE_MEM_SIZE;size++)
//		{
//			*(pwbuf + size) = RNG_GetRandomNumber();
//		}
//		if (rt_device_write(dev, 0, pwbuf, CONFIG_EE_MEM_SIZE ) == CONFIG_EE_MEM_SIZE)//–¥»Î
//		{
//			rt_kprintf("EEPROM Test:Fill Random Write Success\n");
//		}
//		else
//		{
//			rt_kprintf("EEPROM Test:Fill Random Write Fail\n");
//			/*  Õ∑≈ƒ⁄¥ÊøÈ*/
//			rt_free(pwbuf);
//			rt_free(prbuf);
//			rt_device_close(dev);
//			return 0;
//		}
//		rt_device_read(dev, 0, prbuf, CONFIG_EE_MEM_SIZE );//∂¡ªÿ
//		for (size = 0; size < CONFIG_EE_MEM_SIZE; size++)
//		{
//			if (*(pwbuf + size) != *(prbuf + size))
//			{
//				rt_kprintf("EEPROM Test:Fill Random Failed %X != %X at %d\n", *(pwbuf + size), *(prbuf + size), size);
//				/*  Õ∑≈ƒ⁄¥ÊøÈ*/
//				rt_free(pwbuf);
//				rt_free(prbuf);
//				rt_device_close(dev);
//				return 0;
//			}
//		}
//		rt_kprintf("EEPROM Test:Fill Random Sucess\n");
//		//≤Èø’ºÏ≤È
//		rt_kprintf("EEPROM Test:Check Blank\n");
//		for(size =0;size < CONFIG_EE_MEM_SIZE;size++)
//		{
//			*(pwbuf + size) = 0x00;
//		}
//		if (rt_device_write(dev, 0, pwbuf, CONFIG_EE_MEM_SIZE ) == CONFIG_EE_MEM_SIZE)//–¥»Î
//		{
//			rt_kprintf("EEPROM Test:Fill Blank Write Success\n");
//		}
//		else
//		{
//			rt_kprintf("EEPROM Test:Fill Blank Write Fail\n");
//			/*  Õ∑≈ƒ⁄¥ÊøÈ*/
//			rt_free(pwbuf);
//			rt_free(prbuf);
//			rt_device_close(dev);
//			return 0;
//		}
//		rt_device_read(dev, 0, prbuf, CONFIG_EE_MEM_SIZE );//∂¡ªÿ
//		for (size = 0; size < CONFIG_EE_MEM_SIZE; size++)
//		{
//			if (*(pwbuf + size) != *(prbuf + size))
//			{
//				rt_kprintf("EEPROM Test:Check Blank Failed %X != %X at %d\n", *(pwbuf + size), *(prbuf + size), size);
//				/*  Õ∑≈ƒ⁄¥ÊøÈ*/
//				rt_free(pwbuf);
//				rt_free(prbuf);
//				rt_device_close(dev);
//				return 0;
//			}
//		}
//		rt_kprintf("EEPROM Test:Check Blank Sucess\n");
//		/*  Õ∑≈ƒ⁄¥ÊøÈ*/
//		rt_free(pwbuf);
//		rt_free(prbuf);
//		rt_device_close(dev);
//		return 1;
//	}
//	else
//	{
//		rt_kprintf("EEPROM Test:rt_malloc failed!\n");
//		return -1;
//	}
//}