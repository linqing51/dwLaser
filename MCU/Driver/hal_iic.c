#include "hal_iic.h"
/*****************************************************************************/
void iic_start(hal_iic_t *i2c)
{//����I2C���ߵĺ�������SCLΪ�ߵ�ƽʱʹSDA����һ��������
	i2c->setSCL(0);
	NOP();
	i2c->setSDA(1);
	NOP();
	i2c->setSCL(1);
	hwDelayUs(i2c->busFreq);
	i2c->setSDA(0);
	hwDelayUs(i2c->busFreq);
	i2c->setSCL(0);
	hwDelayUs(i2c->busFreq);	
}

void iic_stop(hal_iic_t *i2c)
{//��ֹI2C���ߣ���SCLΪ�ߵ�ƽʱʹSDA����һ��������
    i2c->setSCL(0);
	NOP();
	i2c->setSDA(0);
	NOP();
    i2c->setSCL(1);
	hwDelayUs(i2c->busFreq);
    i2c->setSDA(1);
    hwDelayUs(i2c->busFreq);
    i2c->setSCL(0);
    hwDelayUs(i2c->busFreq);
}

void iic_sendAck(hal_iic_t *i2c)
{//����0����SCLΪ�ߵ�ƽʱʹSDA�ź�Ϊ��
	i2c->setSCL(0);
	NOP();
	i2c->setSDA(0);
	NOP();
	i2c->setSCL(1);
	hwDelayUs(i2c->busFreq);
	i2c->setSCL(0);
	hwDelayUs(i2c->busFreq);
}

void iic_sendNack(hal_iic_t *i2c)
{//����1����SCLΪ�ߵ�ƽʱʹSDA�ź�Ϊ��
	i2c->setSCL(0);
	NOP();
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

uint8_t iic_writeByte(hal_iic_t *i2c, uint8_t byte)
{//��I2C����дһ���ֽ�*/
   uint8_t i;
   uint8_t ack_bit;
   for(i = 0; i < 8; i++)   // ѭ������8��λ
   {
		i2c->setSDA(byte & 0x80);
		hwDelayUs(i2c->busFreq);
		i2c->setSCL(1);
		hwDelayUs(i2c->busFreq);
		i2c->setSCL(0);
		byte <<= 1;
   }
	i2c->setSDA(1);// ��ȡӦ��
	hwDelayUs(i2c->busFreq);
	i2c->setSCL(1);
	hwDelayUs(i2c->busFreq);
	ack_bit = i2c->getSDA();
	hwDelayUs(i2c->busFreq);
	i2c->setSCL(0);
	hwDelayUs(i2c->busFreq);	 
	return ack_bit;// ����AT24C02Ӧ��λ
}

uint8_t iic_readByte(hal_iic_t *i2c)
{//��I2C���߶�һ���ֽ�
   uint8_t i, read_data=0;
   i2c->setSDA(1);
   for(i = 0; i < 8; i++)
   {
		hwDelayUs(i2c->busFreq);
		i2c->setSCL(1);
		read_data <<= 1;
		read_data |= i2c->getSDA();
		hwDelayUs(i2c->busFreq);
		i2c->setSCL(0);
		hwDelayUs(i2c->busFreq);
   }
    return(read_data);
}


