#include "hal_iic.h"
/*****************************************************************************/
void iic_start(hal_iic_t *i2c)
{//启动I2C总线的函数，当SCL为高电平时使SDA产生一个负跳变
	i2c->setSDA(1);
	NOP();
	i2c->setSCL(1);
	hwhwDelayUs(i2c->busFreq);
	i2c->setSDA(0);
	hwhwDelayUs(i2c->busFreq);
	i2c->setSCL(0);
	hwhwDelayUs(i2c->busFreq);
}

void iic_stop(hal_iic_t *i2c)
{//终止I2C总线，当SCL为高电平时使SDA产生一个正跳变
    i2c->setSDA(0);
	NOP();
    i2c->setSCL(1);
	hwhwDelayUs(i2c->busFreq);
    i2c->setSDA(1);
    hwDelayUs(i2c->busFreq);
    i2c->setSCL(0);
    hwDelayUs(i2c->busFreq);
}

void iic_sendAck(hal_iic_t *i2c)
{//发送0，在SCL为高电平时使SDA信号为低
	i2c->setSDA(0);
	NOP();
	i2c->setSCL(1);
	hwDelayUs(i2c->busFreq);
	i2c->setSCL(0);
	hwDelayUs(i2c->busFreq);
}

void iic_sendNack(hal_iic_t *i2c)
{//发送1，在SCL为高电平时使SDA信号为高
	i2c->setSDA(1);
	NOP();
	i2c->setSCL(1);
	hwDelayUs(i2c->busFreq);
	i2c->setSCL(0);
	hwDelayUs(i2c->busFreq);
}

uint8_t iic_checkAcknowledge(hal_iic_t *i2c)
{//发送完一个字节后检验设备的应答信号
	int8_t temp;
	i2c->setSDA(1);
	NOP();
	i2c->setSCL(1);
	hwDelayUs(i2c->busFreq);
	temp = i2c->getSDA();
	hwDelayUs(i2c->busFreq);
	i2c->setSCL(0);
	hwDelayUs(i2c->busFreq);
	return (temp & 0x01);
}

void iic_writeByte(hal_iic_t *i2c, uint8_t byte)
{//向I2C总线写一个字节*/
	int8_t i;
	for(i = 0;i < 8;i ++)
	{
		if((byte << i) & 0x80)
		{
			iic_sendAck(i2c);
		}
		else
		{
			iic_sendNack(i2c);
		}
	}
}

uint8_t iic_readByte(hal_iic_t *i2c)
{//从I2C总线读一个字节
	int8_t byte, i, temp;
	byte = 0x0;
	for(i = 0;i < 8;i ++)
	{
		i2c->setSDA(1);//释放总线
		NOP();
		i2c->setSCL(1);//接受数据
		hwDelayUs(i2c->busFreq);
		temp = i2c->getSDA();
		hwDelayUs(i2c->busFreq);
		i2c->setSCL(0);
		if(temp == 1)
		{
			byte = byte << 1;
			byte = byte | 0x01;
		}
		else
		{
			byte = byte << 1;
		}
	}
	return byte;
}


