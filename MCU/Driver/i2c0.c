#include "i2c0.h"
/*****************************************************************************/
sbit SDA0 = P3^5;
sbit SCL0 = P3^6;				
static uint8_t TimeReload_H, TimeReload_L;
/*****************************************************************************/
void iic0Init(void){
	uint16_t temp = 0;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 12 /CONFIG_I2C0_FREQ));
	TimeReload_H = (temp >> 8) & 0xFF;
	TimeReload_L = temp & 0xFF;
}
static void setSCL(uint8_t s){
	if(s)
		SCL0 = 1;
	else
		SCL0 = 0;
}
static void setSDA(uint8_t s){
	if(s)
		SDA0 = 1;
	else
		SDA0 = 0;
}
static uint8_t getSCL(void){
	return SCL0;
}
static uint8_t getSDA(void){
	return SDA0; 
}
void iic0Start(void){//产生IIC起始信号
	setSDA(1);	  	  
	setSCL(1);
	delayUs(CONFIG_EPROM_FREQ);
 	setSDA(0);//START:when CLK is high,DATA change form high to low 
	delayUs(CONFIG_EPROM_FREQ);
	setSCL(0);//钳住I2C总线，准备发送或接收数据 
}	  
void iic0Stop(void){//产生IIC停止信号
	setSCL(0);
	setSDA(0);//STOP:when CLK is high DATA change form low to high
 	delayUs(CONFIG_EPROM_FREQ);
	setSCL(1); 
	setSDA(1);//发送I2C总线结束信号
	delayUs(CONFIG_EPROM_FREQ);							   	
}

uint8_t iic0WaitAck(void){
//发送数据后，等待应答信号到来
//返回值：1，接收应答失败，IIC直接退出
//        0，接收应答成功，什么都不做
	uint8_t ucErrTime=0;  
	setSDA(1);
	delayUs(1);	   
	setSCL(1);
	delayUs(1);	 
	while(getSDA()){
		ucErrTime ++;
		if(ucErrTime >= 250){
			iic0Stop();
			return 1;
		}
	}
	setSCL(0);    //时钟输出0 	   
	return 0;  
}
void iic0Ack(void){//产生ACK应答
	setSCL(0);
	setSDA(0);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL(0);
}
	    
void iic0NAck(void){//不产生ACK应答	
	setSCL(0);
	setSDA(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL(0);
}					 				     	  
void iic0SendByte(uint8_t txd){//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答                        
    uint8_t t;    	    
    setSCL(0);//拉低时钟开始数据传输
    for(t = 0;t < 8;t ++)
    {              
        //SDA0=(txd&0x80)>>7;
		if((txd & 0x80) >> 7)
			setSDA(1);
		else
			setSDA(0);
		txd <<= 1; 	  
		delayUs(CONFIG_EPROM_FREQ);
		setSCL(1);
		delayUs(CONFIG_EPROM_FREQ); 
		setSCL(0);	
		delayUs(CONFIG_EPROM_FREQ);
    }	 
} 	    
  
uint8_t iic0ReadByte(uint8_t ack){//读1个字节，ack=1时，发送ACK，ack=0，发送nACK 
	uint8_t i, receive=0;
    for(i=0;i<8;i++ ){
        setSCL(0); 
        delayUs(CONFIG_EPROM_FREQ);
		setSCL(1);
        receive <<= 1;
        if(getSDA())
			receive ++;   
		delayUs(CONFIG_EPROM_FREQ); 
    }					 
    if(!ack)
        iic0NAck();        //发送nACK
    else
        iic0Ack();         //发送ACK   
    return receive;
}
