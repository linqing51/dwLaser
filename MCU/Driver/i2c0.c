#include "i2c0.h"
/*****************************************************************************/
sbit SDA0 = P3^5;
sbit SCL0 = P3^6;				
/*****************************************************************************/
void iic0Init(void){

}
static void setSCL0(uint8_t s){
	if(s)
		SCL0 = 1;
	else
		SCL0 = 0;
}
static void setSDA0(uint8_t s){
	if(s)
		SDA0 = 1;
	else
		SDA0 = 0;
}
static uint8_t getSCL0(void){
	return SCL0;
}
static uint8_t getSDA0(void){
	return SDA0; 
}
void iic0Start(void){//����IIC��ʼ�ź�
	setSDA0(1);	  	  
	setSCL0(1);
	delayUs(CONFIG_EPROM_FREQ);
 	setSDA0(0);//START:when CLK is high,DATA change form high to low 
	delayUs(CONFIG_EPROM_FREQ);
	setSCL0(0);//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
void iic0Stop(void){//����IICֹͣ�ź�
	setSCL0(0);
	setSDA0(0);//STOP:when CLK is high DATA change form low to high
 	delayUs(CONFIG_EPROM_FREQ);
	setSCL0(1); 
	setSDA0(1);//����I2C���߽����ź�
	delayUs(CONFIG_EPROM_FREQ);							   	
}

uint8_t iic0WaitAck(void){
//�������ݺ󣬵ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ�ܣ�IICֱ���˳�
//        0������Ӧ��ɹ���ʲô������
	uint8_t ucErrTime=0;  
	setSDA0(1);
	delayUs(1);	   
	setSCL0(1);
	delayUs(1);	 
	while(getSDA0()){
		ucErrTime ++;
		if(ucErrTime >= 250){
			iic0Stop();
			return 1;
		}
	}
	setSCL0(0);    //ʱ�����0 	   
	return 0;  
}
void iic0Ack(void){//����ACKӦ��
	setSCL0(0);
	setSDA0(0);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL0(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL0(0);
}
	    
void iic0NAck(void){//������ACKӦ��	
	setSCL0(0);
	setSDA0(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL0(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL0(0);
}					 				     	  
void iic0SendByte(uint8_t txd){//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��                        
    uint8_t t;    	    
    setSCL0(0);//����ʱ�ӿ�ʼ���ݴ���
    for(t = 0;t < 8;t ++)
    {              
        //SDA0=(txd&0x80)>>7;
		if((txd & 0x80) >> 7)
			setSDA0(1);
		else
			setSDA0(0);
		txd <<= 1; 	  
		delayUs(CONFIG_EPROM_FREQ);
		setSCL0(1);
		delayUs(CONFIG_EPROM_FREQ); 
		setSCL0(0);	
		delayUs(CONFIG_EPROM_FREQ);
    }	 
} 	    
  
uint8_t iic0ReadByte(uint8_t ack){//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK 
	uint8_t i, receive=0;
    for(i=0;i<8;i++ ){
        setSCL0(0); 
        delayUs(CONFIG_EPROM_FREQ);
		setSCL0(1);
        receive <<= 1;
        if(getSDA0())
			receive ++;   
		delayUs(CONFIG_EPROM_FREQ); 
    }					 
    if(!ack)
        iic0NAck();        //����nACK
    else
        iic0Ack();         //����ACK   
    return receive;
}