#include "i2c2.h"
/*****************************************************************************/			
/*****************************************************************************/
static void setSCL2(uint8_t s){//P5.4
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
    SFRPAGE   = CONFIG_PAGE;
	if(s)
		P5 |= 0x10;
	else
		P5 &= 0xEF;
	SFRPAGE = SFRPAGE_SAVE;// Restore SFRPAGE
}
static void setSDA2(uint8_t s){//P5.5
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
    SFRPAGE   = CONFIG_PAGE;
	if(s)
		P5 |= 0x20;
	else
		P5 &= 0xDF;
	SFRPAGE = SFRPAGE_SAVE;// Restore SFRPAGE
}
static uint8_t getSCL2(void){//P5.4
	uint8_t temp;
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
    SFRPAGE = CONFIG_PAGE;
	temp = (P5 >> 4) & 0x01;
	SFRPAGE = SFRPAGE_SAVE;
	return temp;
}
static uint8_t getSDA2(void){//P5.5
	uint8_t temp;
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
    SFRPAGE = CONFIG_PAGE;
	temp = (P5 >> 5) & 0x01;
	SFRPAGE = SFRPAGE_SAVE;
	return temp; 
}
void iic2Start(void){//产生IIC起始信号
	setSDA2(1);	  	  
	setSCL2(1);
	delayUs(CONFIG_I2C2_FREQ);
 	setSDA2(0);//START:when CLK is high,DATA change form high to low 
	delayUs(CONFIG_I2C2_FREQ);
	setSCL2(0);//钳住I2C总线，准备发送或接收数据 
}	  
void iic2Stop(void){//产生IIC停止信号
	setSCL2(0);
	setSDA2(0);//STOP:when CLK is high DATA change form low to high
 	delayUs(CONFIG_I2C2_FREQ);
	setSCL2(1); 
	setSDA2(1);//发送I2C总线结束信号
	delayUs(CONFIG_I2C2_FREQ);							   	
}

uint8_t iic2WaitAck(void){
//发送数据后，等待应答信号到来
//返回值：1，接收应答失败，IIC直接退出
//        0，接收应答成功，什么都不做
	uint8_t ucErrTime=0;  
	setSDA2(1);
	delayUs(1);	   
	setSCL2(1);
	delayUs(1);	 
	while(getSDA2()){
		ucErrTime ++;
		if(ucErrTime >= CONFIG_I2C_WAITACT_TIME){
			iic2Stop();
			return 1;
		}
	}
	setSCL2(0);    //时钟输出0 	   
	return 0;  
}
void iic2Ack(void){//产生ACK应答
	setSCL2(0);
	setSDA2(0);
	delayUs(CONFIG_I2C2_FREQ);
	setSCL2(1);
	delayUs(CONFIG_I2C2_FREQ);
	setSCL2(0);
}
	    
void iic2NAck(void){//不产生ACK应答	
	setSCL2(0);
	setSDA2(1);
	delayUs(CONFIG_I2C2_FREQ);
	setSCL2(1);
	delayUs(CONFIG_I2C2_FREQ);
	setSCL2(0);
}					 				     	  
void iic2SendByte(uint8_t txd){//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答                        
    uint8_t t;    	    
    setSCL2(0);//拉低时钟开始数据传输
    for(t = 0;t < 8;t ++)
    {              
        //SDA2=(txd&0x80)>>7;
		if((txd & 0x80) >> 7)
			setSDA2(1);
		else
			setSDA2(0);
		txd <<= 1; 	  
		delayUs(CONFIG_I2C2_FREQ);
		setSCL2(1);
		delayUs(CONFIG_I2C2_FREQ); 
		setSCL2(0);	
		delayUs(CONFIG_I2C2_FREQ);
    }	 
} 	    
  
uint8_t iic2ReadByte(uint8_t ack){//读1个字节，ack=1时，发送ACK，ack=0，发送nACK 
	uint8_t i, receive=0;
    for(i=0;i<8;i++ ){
        setSCL2(0); 
        delayUs(CONFIG_I2C2_FREQ);
		setSCL2(1);
        receive <<= 1;
        if(getSDA2())
			receive ++;   
		delayUs(CONFIG_I2C2_FREQ); 
    }					 
    if(!ack)
        iic2NAck();        //发送nACK
    else
        iic2Ack();         //发送ACK   
    return receive;
}
