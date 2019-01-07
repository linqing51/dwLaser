#include "i2c3.h"
/*****************************************************************************/				
/*****************************************************************************/
void iic3Init(void){

}
static void setSCL3(uint8_t s){
	if(s)
		P4 |= 1 << 3;
	else
		P4 &= ~(1 << 3);
}
static void setSDA3(uint8_t s){
	if(s)
		P4 |= 1 << 2;
	else
		P4 &= ~(1 << 2);
}
static uint8_t getSCL3(void){
	return ((P4 >> 3) & 0x01);
}
static uint8_t getSDA3(void){
	return ((P4 >> 2) & 0x01); 
}
void iic3Start(void){//产生IIC起始信号
	setSDA3(1);	  	  
	setSCL3(1);
	delayUs(CONFIG_EPROM_FREQ);
 	setSDA3(0);//START:when CLK is high,DATA change form high to low 
	delayUs(CONFIG_EPROM_FREQ);
	setSCL3(0);//钳住I2C总线，准备发送或接收数据 
}	  
void iic3Stop(void){//产生IIC停止信号
	setSCL3(0);
	setSDA3(0);//STOP:when CLK is high DATA change form low to high
 	delayUs(CONFIG_EPROM_FREQ);
	setSCL3(1); 
	setSDA3(1);//发送I2C总线结束信号
	delayUs(CONFIG_EPROM_FREQ);							   	
}

uint8_t iic3WaitAck(void){
//发送数据后，等待应答信号到来
//返回值：1，接收应答失败，IIC直接退出
//        0，接收应答成功，什么都不做
	uint8_t ucErrTime=0;  
	setSDA3(1);
	delayUs(1);	   
	setSCL3(1);
	delayUs(1);	 
	while(getSDA3()){
		ucErrTime ++;
		if(ucErrTime >= 250){
			iic3Stop();
			return 1;
		}
	}
	setSCL3(0);    //时钟输出0 	   
	return 0;  
}
void iic3Ack(void){//产生ACK应答
	setSCL3(0);
	setSDA3(0);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL3(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL3(0);
}
	    
void iic3NAck(void){//不产生ACK应答	
	setSCL3(0);
	setSDA3(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL3(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL3(0);
}					 				     	  
void iic3SendByte(uint8_t txd){//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答                        
    uint8_t t;    	    
    setSCL3(0);//拉低时钟开始数据传输
    for(t = 0;t < 8;t ++)
    {              
        //SDA3=(txd&0x80)>>7;
		if((txd & 0x80) >> 7)
			setSDA3(1);
		else
			setSDA3(0);
		txd <<= 1; 	  
		delayUs(CONFIG_EPROM_FREQ);
		setSCL3(1);
		delayUs(CONFIG_EPROM_FREQ); 
		setSCL3(0);	
		delayUs(CONFIG_EPROM_FREQ);
    }	 
} 	    
  
uint8_t iic3ReadByte(uint8_t ack){//读1个字节，ack=1时，发送ACK，ack=0，发送nACK 
	uint8_t i, receive=0;
    for(i=0;i<8;i++ ){
        setSCL3(0); 
        delayUs(CONFIG_EPROM_FREQ);
		setSCL3(1);
        receive <<= 1;
        if(getSDA3())
			receive ++;   
		delayUs(CONFIG_EPROM_FREQ); 
    }					 
    if(!ack)
        iic3NAck();        //发送nACK
    else
        iic3Ack();         //发送ACK   
    return receive;
}
