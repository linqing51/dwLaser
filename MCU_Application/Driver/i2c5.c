#include "i2c5.h"
/*****************************************************************************/				
sbit SDA5 = P2^6;
sbit SCL5 = P2^7;	
/*****************************************************************************/
void iic5Init(void){

}
static void setSCL5(uint8_t s){
	if(s)
		SCL5 = 1;
	else
		SCL5 = 0;
}
static void setSDA5(uint8_t s){
	if(s)
		SDA5 = 1;
	else
		SDA5 = 0;
}
static uint8_t getSCL5(void){
	return SCL5;
}
static uint8_t getSDA5(void){
	return SDA5; 
}
void iic5Start(void){//产生IIC起始信号
	setSDA5(1);	  	  
	setSCL5(1);
	delayUs(CONFIG_EPROM_FREQ);
 	setSDA5(0);//START:when CLK is high,DATA change form high to low 
	delayUs(CONFIG_EPROM_FREQ);
	setSCL5(0);//钳住I2C总线，准备发送或接收数据 
}	  
void iic5Stop(void){//产生IIC停止信号
	setSCL5(0);
	setSDA5(0);//STOP:when CLK is high DATA change form low to high
 	delayUs(CONFIG_EPROM_FREQ);
	setSCL5(1); 
	setSDA5(1);//发送I2C总线结束信号
	delayUs(CONFIG_EPROM_FREQ);							   	
}

uint8_t iic5WaitAck(void){
//发送数据后，等待应答信号到来
//返回值：1，接收应答失败，IIC直接退出
//        0，接收应答成功，什么都不做
	uint8_t ucErrTime=0;  
	setSDA5(1);
	delayUs(1);	   
	setSCL5(1);
	delayUs(1);	 
	while(getSDA5()){
		ucErrTime ++;
		if(ucErrTime >= CONFIG_I2C_WAITACT_TIME){
			iic5Stop();
			return 1;
		}
	}
	setSCL5(0);    //时钟输出0 	   
	return 0;  
}
void iic5Ack(void){//产生ACK应答
	setSCL5(0);
	setSDA5(0);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL5(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL5(0);
}
	    
void iic5NAck(void){//不产生ACK应答	
	setSCL5(0);
	setSDA5(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL5(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL5(0);
}					 				     	  
void iic5SendByte(uint8_t txd){//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答                        
    uint8_t t;    	    
    setSCL5(0);//拉低时钟开始数据传输
    for(t = 0;t < 8;t ++)
    {              
        //SDA0=(txd&0x80)>>7;
		if((txd & 0x80) >> 7)
			setSDA5(1);
		else
			setSDA5(0);
		txd <<= 1; 	  
		delayUs(CONFIG_EPROM_FREQ);
		setSCL5(1);
		delayUs(CONFIG_EPROM_FREQ); 
		setSCL5(0);	
		delayUs(CONFIG_EPROM_FREQ);
    }	 
} 	    
  
uint8_t iic5ReadByte(uint8_t ack){//读1个字节，ack=1时，发送ACK，ack=0，发送nACK 
	uint8_t i, receive=0;
    for(i=0;i<8;i++ ){
        setSCL5(0); 
        delayUs(CONFIG_EPROM_FREQ);
		setSCL5(1);
        receive <<= 1;
        if(getSDA5())
			receive ++;   
		delayUs(CONFIG_EPROM_FREQ); 
    }					 
    if(!ack)
        iic5NAck();        //发送nACK
    else
        iic5Ack();         //发送ACK   
    return receive;
}
