#include "i2c0.h"
/*****************************************************************************/
sbit SDA0 = P3^5;
sbit SCL0 = P3^7;
static uint8_t TimeReload_H, TimeReload_L;
/*****************************************************************************/
void iic0_Init(void)
{
	uint16_t temp = 0;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 12 /CONFIG_I2C0_FREQ));
	TimeReload_H = (temp >> 8) & 0xFF;
	TimeReload_L = temp & 0xFF;
}
uint8_t iic0_write(uint8_t dev_addr, uint8_t num_bytes, uint8_t *array_name)
{
	uint8_t return_val, num_bits, send_val, send_bit, index=0;
	if((SCL0 == 1) && (SDA0 == 1))
	{
		return_val = IIC_NO_ERROR;
	}
	else
	{
		return_val = IIC_BUSY_ERROR;
	}
	hwDelayInit(TimeReload_H, TimeReload_L);
	SDA0 = 0;
	send_val = (dev_addr << 1) & 0xFE;
	num_bytes ++;
	do
	{
		num_bits = 8;
		do
		{
			hwDelay(1, TimeReload_H, TimeReload_L);
			SCL0 = 0;
			num_bits --;
			send_bit = ((send_val>>num_bits)&0x01);
			SDA0 = (bit)send_bit;
			hwDelay(1, TimeReload_H, TimeReload_L);
			SCL0 = 1;
			while(SCL0 != 1);
			send_bit = SDA0;
			if(send_bit != send_bit) 
				return_val = IIC_BUSY_ERROR;
		}while((num_bits > 0)&& return_val==0);
		if(return_val != IIC_BUSY_ERROR)
		{
			hwDelay(1, TimeReload_H, TimeReload_L);
			SCL0 = 0;
			SDA0 = 1;
			hwDelay(1, TimeReload_H, TimeReload_L);
			SCL0 = 1;
			while(SCL0 != 1);
			send_bit = SDA0;
			if(send_bit != 0)
			{	
				return_val = IIC_NACK_ERROR;
			}
			send_val = array_name[index];
			index ++;
			num_bytes --;
		}
		}while((num_bytes > 0)&& (return_val == 0));
		if(return_val != IIC_BUSY_ERROR)
		{
			hwDelay(1, TimeReload_H, TimeReload_L);
			SCL0 = 0;
			SDA0 = 0;
			hwDelay(1, TimeReload_H, TimeReload_L);
			SCL0 = 1;
			while(SCL0 != 1);
			hwDelay(1, TimeReload_H, TimeReload_L);
			SDA0 = 1;
		}
	return return_val;
}

uint8_t iic0_read(uint8_t dev_addr,uint8_t num_bytes,uint8_t *array_name)
{
	uint8_t return_val, rcv_val, send_bit, send_val, num_bits, index=0;
	if((SCL0 == 1)&&(SDA0 == 1)){
		return_val = IIC_NO_ERROR;
	}
	else{
		return_val = IIC_BUSY_ERROR;
	}
	hwDelayInit(TimeReload_H, TimeReload_L);
	SDA0 = 0;
	send_val = (dev_addr << 1) & 0xFF;
	do{
		num_bits=8;
		do{
			hwDelay(1, TimeReload_H, TimeReload_L);
			SCL0 = 0;
			SDA0 = 1;
			hwDelay(1, TimeReload_H, TimeReload_L);
			SCL0 = 1;
			while(SCL0 != 1);
			send_bit = SDA0;
			rcv_val = ((rcv_val << 1) | send_bit);
			num_bits --;
		}while(num_bits > 0);
		array_name[index] = rcv_val;
		index ++;
		if(num_bytes == 1)
		{
			send_bit=1;
		}
		else
		{
			send_bit=0;
		}
		SDA0 = send_bit;
		num_bytes --;
	}while(num_bytes > 0);
	if(return_val != IIC_BUSY_ERROR)
	{
		hwDelay(1, TimeReload_H, TimeReload_L);
		SCL0 = 0;
		SDA0 = 0;
		hwDelay(1, TimeReload_H, TimeReload_L);
		SCL0 = 1;
		while(SCL0 != 1);
		hwDelay(1, TimeReload_H, TimeReload_L);
		SDA0 = 1;
	}
	return return_val;
}
