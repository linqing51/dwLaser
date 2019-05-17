#include "i2c1.h"
/*****************************************************************************/			
static void setSCL1(uint8_t s){//P5_1
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
    SFRPAGE = CONFIG_PAGE;
	if(s)
		P5 |= 0x02;
	else
		P5 &= 0xFD;
	SFRPAGE = SFRPAGE_SAVE;// Restore SFRPAGE
}
static void setSDA1(uint8_t s){//P5_2
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
    SFRPAGE = CONFIG_PAGE;
	if(s)
		P5 |= 0x04;
	else
		P5 &= 0xFB;
	SFRPAGE = SFRPAGE_SAVE;// Restore SFRPAGE
}
static uint8_t getSCL1(void){//p5.1
	uint8_t temp;
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
    SFRPAGE = CONFIG_PAGE;
	temp = (P5 >> 1) & 0x01;
	SFRPAGE = SFRPAGE_SAVE;        
	return temp;
	
}
static uint8_t getSDA1(void){//p5.2
	uint8_t temp;
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
    SFRPAGE = CONFIG_PAGE;
	temp = (P5 >> 2) & 0x01;
	SFRPAGE = SFRPAGE_SAVE;        
	return temp;
}
void iic1Start(void){//产生IIC起始信号
	setSDA1(1);	  	  
	setSCL1(1);
	delayUs(CONFIG_I2C0_FREQ);
 	setSDA1(0);//START:when CLK is high,DATA change form high to low 
	delayUs(CONFIG_I2C0_FREQ);
	setSCL1(0);//钳住I2C总线，准备发送或接收数据 
}	  
void iic1Stop(void){//产生IIC停止信号
	setSCL1(0);
	setSDA1(0);//STOP:when CLK is high DATA change form low to high
 	delayUs(CONFIG_I2C0_FREQ);
	setSCL1(1); 
	setSDA1(1);//发送I2C总线结束信号
	delayUs(CONFIG_I2C0_FREQ);							   	
}
void iic1Init(void){
	setSCL1(1); 
	setSDA1(1);
}
uint8_t iic1WaitAck(void){
//发送数据后，等待应答信号到来
//返回值：1，接收应答失败，IIC直接退出
//        0，接收应答成功，什么都不做
	uint8_t ucErrTime=0;  
	setSDA1(1);
	delayUs(1);	   
	setSCL1(1);
	delayUs(1);	 
	while(getSDA1()){
		ucErrTime ++;
		if(ucErrTime >= CONFIG_I2C_WAITACT_TIME){
			iic1Stop();
			return 1;
		}
	}
	setSCL1(0);    //时钟输出0 	   
	return 0;  
}
void iic1Ack(void){//产生ACK应答
	setSCL1(0);
	setSDA1(0);
	delayUs(CONFIG_I2C1_FREQ);
	setSCL1(1);
	delayUs(CONFIG_I2C1_FREQ);
	setSCL1(1);
}
	    
void iic1NAck(void){//不产生ACK应答	
	//setSCL1(0);
	setSDA1(1);
	delayUs(CONFIG_I2C1_FREQ);
	setSCL1(1);
	delayUs(CONFIG_I2C1_FREQ);
	setSCL1(0);
	delayUs(CONFIG_I2C1_FREQ);
	setSDA1(1);
}					 				     	  
void iic1SendByte(uint8_t txd){//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答                        
    uint8_t t;    	    
    setSCL1(0);//拉低时钟开始数据传输
    for(t = 0;t < 8;t ++)
    {              
        //SDA1=(txd&0x80)>>7;
		if((txd & 0x80) >> 7)
			setSDA1(1);
		else
			setSDA1(0);
		txd <<= 1; 	  
		delayUs(CONFIG_I2C1_FREQ);
		setSCL1(1);
		delayUs(CONFIG_I2C1_FREQ); 
		setSCL1(0);	
		delayUs(CONFIG_I2C1_FREQ);
    }	 
} 	    
  
uint8_t iic1ReadByte(uint8_t ack){//读1个字节，ack=1时，发送ACK，ack=0，发送nACK 
	uint8_t i, receive=0;
    for(i=0;i<8;i++ ){
        setSCL1(0); 
        delayUs(CONFIG_I2C1_FREQ);
		setSCL1(1);
        receive <<= 1;
        if(getSDA1())
			receive ++;   
		delayUs(CONFIG_I2C1_FREQ); 
    }					 
    if(!ack)
        iic1NAck();        //发送nACK
    else
        iic1Ack();         //发送ACK   
    return receive;
}
