#include "i2c6.h"
/*****************************************************************************/
sbit SDA6 = P2^2;
sbit SCL6 = P2^3;				
/*****************************************************************************/
void iic6Init(void){

}
static void setSCL6(uint8_t s){
	if(s)
		SCL6 = 1;
	else
		SCL6 = 0;
}
static void setSDA6(uint8_t s){
	if(s)
		SDA6 = 1;
	else
		SDA6 = 0;
}
static uint8_t getSCL6(void){
	return SCL6;
}
static uint8_t getSDA6(void){
	return SDA6; 
}
void iic6Start(void){//产生IIC起始信号
	setSDA6(1);	  	  
	setSCL6(1);
	delayUs(CONFIG_EPROM_FREQ);
 	setSDA6(0);//START:when CLK is high,DATA change form high to low 
	delayUs(CONFIG_EPROM_FREQ);
	setSCL6(0);//钳住I2C总线，准备发送或接收数据 
}	  
void iic6Stop(void){//产生IIC停止信号
	setSCL6(0);
	setSDA6(0);//STOP:when CLK is high DATA change form low to high
 	delayUs(CONFIG_EPROM_FREQ);
	setSCL6(1); 
	setSDA6(1);//发送I2C总线结束信号
	delayUs(CONFIG_EPROM_FREQ);							   	
}

uint8_t iic6WaitAck(void){
//发送数据后，等待应答信号到来
//返回值：1，接收应答失败，IIC直接退出
//        0，接收应答成功，什么都不做
	uint8_t ucErrTime=0;  
	setSDA6(1);
	delayUs(1);	   
	setSCL6(1);
	delayUs(1);	 
	while(getSDA6()){
		ucErrTime ++;
		if(ucErrTime >= CONFIG_I2C_WAITACT_TIME){
			iic6Stop();
			return 1;
		}
	}
	setSCL6(0);    //时钟输出0 	   
	return 0;  
}
void iic6Ack(void){//产生ACK应答
	setSCL6(0);
	setSDA6(0);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL6(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL6(0);
}
	    
void iic6NAck(void){//不产生ACK应答	
	setSCL6(0);
	setSDA6(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL6(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL6(0);
}					 				     	  
void iic6SendByte(uint8_t txd){//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答                        
    uint8_t t;    	    
    setSCL6(0);//拉低时钟开始数据传输
    for(t = 0;t < 8;t ++)
    {              
        //SDA6=(txd&0x80)>>7;
		if((txd & 0x80) >> 7)
			setSDA6(1);
		else
			setSDA6(0);
		txd <<= 1; 	  
		delayUs(CONFIG_EPROM_FREQ);
		setSCL6(1);
		delayUs(CONFIG_EPROM_FREQ); 
		setSCL6(0);	
		delayUs(CONFIG_EPROM_FREQ);
    }	 
} 	    
  
uint8_t iic6ReadByte(uint8_t ack){//读1个字节，ack=1时，发送ACK，ack=0，发送nACK 
	uint8_t i, receive=0;
    for(i=0;i<8;i++ ){
        setSCL6(0); 
        delayUs(CONFIG_EPROM_FREQ);
		setSCL6(1);
        receive <<= 1;
        if(getSDA6())
			receive ++;   
		delayUs(CONFIG_EPROM_FREQ); 
    }					 
    if(!ack)
        iic6NAck();        //发送nACK
    else
        iic6Ack();         //发送ACK   
    return receive;
}
