#include "eprom.h"
/*****************************************************************************/
hal_iic_t i2c0;
#define CONFIG_EPROM_I2C_BUS	&i2c0
void eprom_writeOneByte(uint8_t addr, uint8_t thedata)
{
	int8_t acktemp = 1;
	//write a byte to mem
	iic_start(CONFIG_EPROM_I2C_BUS);
	iic_writeByte(CONFIG_EPROM_I2C_BUS, 0xa0);
	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
	iic_writeByte(CONFIG_EPROM_I2C_BUS, addr);//address
	acktemp=iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
	iic_writeByte(CONFIG_EPROM_I2C_BUS, thedata);//thedata
	acktemp=iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
	iic_stop(CONFIG_EPROM_I2C_BUS);
}

void eprom_writePage(uint8_t *buffer, uint8_t addr)
{
	uint8_t acktemp;
	int i;
	/*write a page to at24c02*/
	iic_start(CONFIG_EPROM_I2C_BUS);
	iic_writeByte(CONFIG_EPROM_I2C_BUS, 0xa0);
	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
	iic_writeByte(CONFIG_EPROM_I2C_BUS, addr);//address
	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
	for(i = 0;i < 7;i ++)
	{
		iic_writeByte(CONFIG_EPROM_I2C_BUS, buffer[i]);
		if(! iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS))
		{
			iic_stop(CONFIG_EPROM_I2C_BUS);
		}
	}
	iic_stop(CONFIG_EPROM_I2C_BUS);
}

uint8_t eprom_readOneByte(uint8_t addr)
{         
	uint8_t acktemp;
	uint8_t mydata;
	//read a byte from mem
	iic_start(CONFIG_EPROM_I2C_BUS);
	iic_writeByte(CONFIG_EPROM_I2C_BUS, 0xa0);
	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
	iic_writeByte(CONFIG_EPROM_I2C_BUS, addr);//address
	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
	iic_start(CONFIG_EPROM_I2C_BUS);
	iic_writeByte(CONFIG_EPROM_I2C_BUS, 0xa1);
	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
	mydata = iic_readByte(CONFIG_EPROM_I2C_BUS);
	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
	iic_stop(CONFIG_EPROM_I2C_BUS);
	return mydata;	
}

void eprom_readBytes(uint8_t *buffer,uint8_t addr, uint8_t len)
{
	uint8_t acktemp;
	int i=0;
	//read 8 bytes from mem
	iic_start(CONFIG_EPROM_I2C_BUS);
	iic_writeByte(CONFIG_EPROM_I2C_BUS, 0xa0);
	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
	iic_writeByte(CONFIG_EPROM_I2C_BUS, addr);
	acktemp = iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
	iic_start(CONFIG_EPROM_I2C_BUS);
	iic_writeByte(CONFIG_EPROM_I2C_BUS, 0xa1);
	acktemp= iic_checkAcknowledge(CONFIG_EPROM_I2C_BUS);
	for(i = 0;i < len;i ++)
	{
		buffer[i]=ii2_readByte(CONFIG_EPROM_I2C_BUS);
		if(i!=n-1)
			iic_sendNack(CONFIG_EPROM_I2C_BUS);//发送应答
		else
			iic_sendAckS(CONFIG_EPROM_I2C_BUS);//发送非应答
	}

	I2C_Stop();

}


//void main()
//{
//          int i;
//          char mybyte;
//          char myarray[8];
//          char myarray2[8];
//          char rdarray[16];
//         
//          for(i=0;i<8;i++)
//          {
//                myarray[i]=i;
//                myarray2[i]=i+0x08;    

//          }

//          Write_One_Byte(0x20,0x28);

//          Write_A_Page(myarray,0x10);
//          Write_A_Page(myarray2,0x18);

//          mybyte=Read_One_Byte(0x20);
//          Read_N_Bytes(rdarray,16,0x10);

//}