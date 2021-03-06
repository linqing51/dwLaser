#include "i2c0.h"
/*****************************************************************************/		
/*****************************************************************************/
void iic0Init(void){

}
static void setSCL0(uint8_t s){
	if(s)
		P4 |= (1 << 7);
	else
		P4 &= ~((uint8_t)(1 << 7));
}
static void setSDA0(uint8_t s){
	if(s)
		P4 |= (uint8_t)(1 << 6);
	else
		P4 &= ~((uint8_t)(1 << 6));
}
static uint8_t getSCL0(void){
	return (P4 >> 7) & 0x01;
}
static uint8_t getSDA0(void){
	return (P4 >> 6) & 0x01;
}
void iic0Start(void){//产生IIC起始信号
	setSDA0(1);	  	  
	setSCL0(1);
	delayUs(CONFIG_I2C0_FREQ);
 	setSDA0(0);//START:when CLK is high,DATA change form high to low 
	delayUs(CONFIG_I2C0_FREQ);
	setSCL0(0);//钳住I2C总线，准备发送或接收数据 
}	  
void iic0Stop(void){//产生IIC停止信号
	setSCL0(0);
	setSDA0(0);//STOP:when CLK is high DATA change form low to high
 	delayUs(CONFIG_I2C0_FREQ);
	setSCL0(1); 
	setSDA0(1);//发送I2C总线结束信号
	delayUs(CONFIG_I2C0_FREQ);							   	
}

uint8_t iic0WaitAck(void){
//发送数据后，等待应答信号到来
//返回值：1，接收应答失败，IIC直接退出
//        0，接收应答成功，什么都不做
	uint8_t ucErrTime=0;  
	setSDA0(1);
	delayUs(1);	   
	setSCL0(1);
	delayUs(1);	 
	while(getSDA0()){
		ucErrTime ++;
		if(ucErrTime >= CONFIG_I2C_WAITACT_TIME){
			iic0Stop();
			return 1;
		}
	}
	setSCL0(0);    //时钟输出0 	   
	return 0;  
}
void iic0Ack(void){//产生ACK应答
	setSCL0(0);
	setSDA0(0);
	delayUs(CONFIG_I2C0_FREQ);
	setSCL0(1);
	delayUs(CONFIG_I2C0_FREQ);
	setSCL0(0);
}
	    
void iic0NAck(void){//不产生ACK应答	
	setSCL0(0);
	setSDA0(1);
	delayUs(CONFIG_I2C0_FREQ);
	setSCL0(1);
	delayUs(CONFIG_I2C0_FREQ);
	setSCL0(0);
}					 				     	  
void iic0SendByte(uint8_t txd){//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答                        
    uint8_t t;    	    
    setSCL0(0);//拉低时钟开始数据传输
    for(t = 0;t < 8;t ++)
    {              
        //SDA0=(txd&0x80)>>7;
		if((txd & 0x80) >> 7)
			setSDA0(1);
		else
			setSDA0(0);
		txd <<= 1; 	  
		delayUs(CONFIG_I2C0_FREQ);
		setSCL0(1);
		delayUs(CONFIG_I2C0_FREQ); 
		setSCL0(0);	
		delayUs(CONFIG_I2C0_FREQ);
    }	 
} 	    
  
uint8_t iic0ReadByte(uint8_t ack){//读1个字节，ack=1时，发送ACK，ack=0，发送nACK 
	uint8_t i, receive=0;
    for(i=0;i<8;i++ ){
        setSCL0(0); 
        delayUs(CONFIG_I2C0_FREQ);
		setSCL0(1);
        receive <<= 1;
        if(getSDA0())
			receive ++;   
		delayUs(CONFIG_I2C0_FREQ); 
    }					 
    if(!ack)
        iic0NAck();        //发送nACK
    else
        iic0Ack();         //发送ACK   
    return receive;
}
