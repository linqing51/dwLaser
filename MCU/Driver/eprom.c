#include "eprom.h"
/*****************************************************************************/
static uint8_t setSDA_H(void);
static uint8_t setSDA_L(void);
static uint8_t setSCL_H(void);
static uint8_t setSCL_L(void);
static uint8_t getSDA(void);
static uint8_t getSCL(void);
/*****************************************************************************/
#define CONFIG_EPROM_I2C_BUS				&iic0
#define CONFIG_EPROM_SIZE					8196
hal_iic_t iic0;
sbit IIC0_SDA = P3^5;
sbit IIC0_SCL = P3^6;
/*****************************************************************************/
static uint8_t setSDA_H(void){
	IIC0_SDA = 1;
	return IIC_NOERR;
}
static uint8_t setSDA_L(void){
	IIC0_SDA = 0;
	return IIC_NOERR;
}
static uint8_t setSCL_H(void){
	uint8_t i;
	IIC0_SCL = 1;
	for(i = 0;i <= 255;i ++)
	{
		if(!getSCL())
		{
			hwDelayUs(iic0.busFreq);
			return IIC_NOERR;
		}
		else
			hwDelayUs(iic0.timeOut);
	}
#if CONFIG_IIC_DEBUG ==1 
	printf("wait %ld tick for SCL line to go high\n");
#endif	
	return IIC_TIMEOUT;
}
static uint8_t setSCL_L(void){
	IIC0_SCL = 0;
	return IIC_NOERR;
}
static uint8_t getSDA(void){
	return (IIC0_SDA & 0x01);
}
static uint8_t getSCL(void){
	return (IIC0_SCL & 0x01);
}
void eprom_init(void){
	iic0.setSDA_H = setSDA_H;
	iic0.setSDA_L = setSDA_L;
	iic0.setSCL_H = setSCL_H;
	iic0.setSCL_L = setSCL_L;
	iic0.getSDA = getSDA;
	iic0.getSCL = getSCL;
	iic0.busFreq = 10;
}
void eprom_writeOneByte(uint8_t addr, uint8_t thedata)
{//EPROMд��һ���ֽ�
//	int8_t acktemp = 1;
//	//write a byte to mem
//	iic_start(CONFIG_EPROM_I2C_BUS);
//	iic_writeByte(CONFIG_EPROM_I2C_BUS, 0xa0);
//	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
//	iic_writeByte(CONFIG_EPROM_I2C_BUS, addr);//address
//	acktemp=iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
//	iic_writeByte(CONFIG_EPROM_I2C_BUS, thedata);//thedata
//	acktemp=iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
//	iic_stop(CONFIG_EPROM_I2C_BUS);
}

void eprom_writePage(uint8_t *buffer, uint8_t addr)
{//EPROMд��һҳ
//	uint8_t acktemp;
//	int i;
//	/*write a page to at24c02*/
//	iic_start(CONFIG_EPROM_I2C_BUS);
//	iic_writeByte(CONFIG_EPROM_I2C_BUS, 0xa0);
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

uint8_t eprom_readOneByte(uint8_t addr)
{//EPROM��ȡһ���ֽ�         
//	uint8_t acktemp;
//	uint8_t mydata;
//	//read a byte from mem
//	iic_start(CONFIG_EPROM_I2C_BUS);
//	iic_writeByte(CONFIG_EPROM_I2C_BUS, 0xa0);
//	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
//	iic_writeByte(CONFIG_EPROM_I2C_BUS, addr);//address
//	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
//	iic_start(CONFIG_EPROM_I2C_BUS);
//	iic_writeByte(CONFIG_EPROM_I2C_BUS, 0xa1);
//	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
//	mydata = iic_readByte(CONFIG_EPROM_I2C_BUS);
//	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
//	iic_stop(CONFIG_EPROM_I2C_BUS);
//	return mydata;	
}

void eprom_readBytes(uint8_t *buffer,uint8_t addr, uint8_t len)
{//EPROM������ȡ�ֽ�
//	uint8_t acktemp;
//	int i=0;
//	//read 8 bytes from mem
//	iic_start(CONFIG_EPROM_I2C_BUS);
//	iic_writeByte(CONFIG_EPROM_I2C_BUS, 0xa0);
//	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
//	iic_writeByte(CONFIG_EPROM_I2C_BUS, addr);
//	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
//	iic_start(CONFIG_EPROM_I2C_BUS);
//	iic_writeByte(CONFIG_EPROM_I2C_BUS, 0xa1);
//	acktemp= iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
//	for(i = 0;i < len;i ++)
//	{
//		buffer[i] = iic_readByte(CONFIG_EPROM_I2C_BUS);
//		if(i != (len - 1))
//			iic_sendNack(CONFIG_EPROM_I2C_BUS);//����Ӧ��
//		else
//			iic_sendAck(CONFIG_EPROM_I2C_BUS);//���ͷ�Ӧ��
//	}
//	iic_stop(CONFIG_EPROM_I2C_BUS);

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
//{//����EEPROM�����
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
//{//epromд���ȡ����
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
//		//������-���0x00
//		rt_kprintf("EEPROM Test:Fill 0x00\n");
//		for(size = 0;size < CONFIG_EE_MEM_SIZE;size++)
//		{
//			*(pwbuf + size) = 0x00;
//		}
//		rt_device_open(dev, RT_DEVICE_FLAG_ACTIVATED);
//		if (rt_device_write(dev, 0, pwbuf, CONFIG_EE_MEM_SIZE ) == CONFIG_EE_MEM_SIZE)//д��
//		{
//			rt_kprintf("EEPROM Test:Fill 0x00 Write Success\n");
//		}
//		else
//		{
//			rt_kprintf("EEPROM Test:Fill 0x00 Write Fail\n");
//			/* �ͷ��ڴ��*/
//			rt_free(pwbuf);
//			rt_free(prbuf);
//			rt_device_close(dev);
//			return 0;
//		}
//		rt_device_read(dev, 0, prbuf, CONFIG_EE_MEM_SIZE );//����
//		for (size = 0; size < CONFIG_EE_MEM_SIZE; size++)
//		{
//			if (*(pwbuf + size) != *(prbuf + size))
//			{
//				rt_kprintf("EEPROM Test:Fill 0x00 Failed %X != %X at %d\n", *(pwbuf + size), *(prbuf + size), size);
//				/* �ͷ��ڴ��*/
//				rt_free(pwbuf);
//				rt_free(prbuf);
//				rt_device_close(dev);
//				return 0;
//			}
//		}
//		rt_kprintf("EEPROM Test:Fill 0x00 Sucess\n");
//		//������-���0x5A
//		rt_kprintf("EEPROM Test:Fill 0x5A\n");
//		for(size = 0;size < CONFIG_EE_MEM_SIZE;size++)
//		{
//			*(pwbuf + size) = 0x5A;
//		}
//		if (rt_device_write(dev, 0, pwbuf, CONFIG_EE_MEM_SIZE ) == CONFIG_EE_MEM_SIZE)//д��
//		{
//			rt_kprintf("EEPROM Test:Fill 0x5A Write Success\n");
//		}
//		else
//		{
//			rt_kprintf("EEPROM Test:Fill 0x5A Write Fail\n");
//			/* �ͷ��ڴ��*/
//			rt_free(pwbuf);
//			rt_free(prbuf);
//			rt_device_close(dev);
//			return 0;
//		}
//		rt_device_read(dev, 0, prbuf, CONFIG_EE_MEM_SIZE );//����
//		for (size = 0; size < CONFIG_EE_MEM_SIZE; size++)
//		{
//			if (*(pwbuf + size) != *(prbuf + size))
//			{
//				rt_kprintf("EEPROM Test:Fill 0x5A Failed %X != %X at %d\n", *(pwbuf + size), *(prbuf + size), size);
//				/* �ͷ��ڴ��*/
//				rt_free(pwbuf);
//				rt_free(prbuf);
//				rt_device_close(dev);
//				return 0;
//			}
//		}
//		rt_kprintf("EEPROM Test:Fill 0x5A Sucess\n");
//		//������
//		rt_kprintf("EEPROM Test:Fill Random\n");
//		for(size =0;size < CONFIG_EE_MEM_SIZE;size++)
//		{
//			*(pwbuf + size) = RNG_GetRandomNumber();
//		}
//		if (rt_device_write(dev, 0, pwbuf, CONFIG_EE_MEM_SIZE ) == CONFIG_EE_MEM_SIZE)//д��
//		{
//			rt_kprintf("EEPROM Test:Fill Random Write Success\n");
//		}
//		else
//		{
//			rt_kprintf("EEPROM Test:Fill Random Write Fail\n");
//			/* �ͷ��ڴ��*/
//			rt_free(pwbuf);
//			rt_free(prbuf);
//			rt_device_close(dev);
//			return 0;
//		}
//		rt_device_read(dev, 0, prbuf, CONFIG_EE_MEM_SIZE );//����
//		for (size = 0; size < CONFIG_EE_MEM_SIZE; size++)
//		{
//			if (*(pwbuf + size) != *(prbuf + size))
//			{
//				rt_kprintf("EEPROM Test:Fill Random Failed %X != %X at %d\n", *(pwbuf + size), *(prbuf + size), size);
//				/* �ͷ��ڴ��*/
//				rt_free(pwbuf);
//				rt_free(prbuf);
//				rt_device_close(dev);
//				return 0;
//			}
//		}
//		rt_kprintf("EEPROM Test:Fill Random Sucess\n");
//		//��ռ��
//		rt_kprintf("EEPROM Test:Check Blank\n");
//		for(size =0;size < CONFIG_EE_MEM_SIZE;size++)
//		{
//			*(pwbuf + size) = 0x00;
//		}
//		if (rt_device_write(dev, 0, pwbuf, CONFIG_EE_MEM_SIZE ) == CONFIG_EE_MEM_SIZE)//д��
//		{
//			rt_kprintf("EEPROM Test:Fill Blank Write Success\n");
//		}
//		else
//		{
//			rt_kprintf("EEPROM Test:Fill Blank Write Fail\n");
//			/* �ͷ��ڴ��*/
//			rt_free(pwbuf);
//			rt_free(prbuf);
//			rt_device_close(dev);
//			return 0;
//		}
//		rt_device_read(dev, 0, prbuf, CONFIG_EE_MEM_SIZE );//����
//		for (size = 0; size < CONFIG_EE_MEM_SIZE; size++)
//		{
//			if (*(pwbuf + size) != *(prbuf + size))
//			{
//				rt_kprintf("EEPROM Test:Check Blank Failed %X != %X at %d\n", *(pwbuf + size), *(prbuf + size), size);
//				/* �ͷ��ڴ��*/
//				rt_free(pwbuf);
//				rt_free(prbuf);
//				rt_device_close(dev);
//				return 0;
//			}
//		}
//		rt_kprintf("EEPROM Test:Check Blank Sucess\n");
//		/* �ͷ��ڴ��*/
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