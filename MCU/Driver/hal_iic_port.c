#include "hal_iic_port.h"
/*****************************************************************************/
hal_iic_t iic0, iic1, iic2, iic3, iic4;
sbit IIC0_SDA = P3^5;
sbit IIC0_SCL = P3^6;
sbit IIC1_SDA = P3^1; 
sbit IIC1_SCL = P3^2;
sbit IIC2_SDA = P3^3;
sbit IIC2_SCL = P3^4;
sbit IIC3_SDA = P0^2;
sbit IIC3_SCL = P0^3;
sbit IIC4_SDA = P0^4;
sbit IIC4_SCL = P0^5;
/*****************************************************************************/
uint8_t setSDA0_H(void){
	IIC0_SDA = 1;
	return IIC_NOERR;
}
uint8_t setSDA0_L(void){
	IIC0_SDA = 0;
	return IIC_NOERR;
}
uint8_t setSCL0_H(void){
	uint8_t i;
	IIC0_SCL = 1;
	for(i = 0;i <= 255;i ++)
	{
		if(!IIC0_SCL)
		{
			hwDelayUs(iic0.busFreq);
			return IIC_NOERR;
		}
		else
			hwDelayUs(iic0.timeOut);
	}
	return IIC_TIMEOUT;
}
uint8_t setSCL0_L(void){
	IIC0_SCL = 0;
	return IIC_NOERR;
}
uint8_t getSDA0(void){
	return (IIC0_SDA & 0x01);
}
uint8_t getSCL0(void){
	return (IIC0_SCL & 0x01);
}
void iic0_init(void){
	iic0.setSDA_H = setSDA0_H;
	iic0.setSDA_L = setSDA0_L;
	iic0.setSCL_H = setSCL0_H;
	iic0.setSCL_L = setSCL0_L;
	iic0.getSDA = getSDA0;
	iic0.getSCL = getSCL0;
	iic0.busFreq = 10;
	iic0.timeOut = 10;
}