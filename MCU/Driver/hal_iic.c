#include "hal_iic.h"
/*****************************************************************************/
void iic_start(hal_iic_t *i2c)
{//����I2C���ߵĺ�������SCLΪ�ߵ�ƽʱʹSDA����һ��������
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
{//��ֹI2C���ߣ���SCLΪ�ߵ�ƽʱʹSDA����һ��������
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
{//����0����SCLΪ�ߵ�ƽʱʹSDA�ź�Ϊ��
	i2c->setSDA(0);
	NOP();
	i2c->setSCL(1);
	hwDelayUs(i2c->busFreq);
	i2c->setSCL(0);
	hwDelayUs(i2c->busFreq);
}

void iic_sendNack(hal_iic_t *i2c)
{//����1����SCLΪ�ߵ�ƽʱʹSDA�ź�Ϊ��
	i2c->setSDA(1);
	NOP();
	i2c->setSCL(1);
	hwDelayUs(i2c->busFreq);
	i2c->setSCL(0);
	hwDelayUs(i2c->busFreq);
}

uint8_t iic_checkAcknowledge(hal_iic_t *i2c)
{//������һ���ֽں�����豸��Ӧ���ź�
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
{//��I2C����дһ���ֽ�*/
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
{//��I2C���߶�һ���ֽ�
	int8_t byte, i, temp;
	byte = 0x0;
	for(i = 0;i < 8;i ++)
	{
		i2c->setSDA(1);//�ͷ�����
		NOP();
		i2c->setSCL(1);//��������
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


