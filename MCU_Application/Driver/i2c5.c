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
void iic5Start(void){//����IIC��ʼ�ź�
	setSDA5(1);	  	  
	setSCL5(1);
	delayUs(CONFIG_EPROM_FREQ);
 	setSDA5(0);//START:when CLK is high,DATA change form high to low 
	delayUs(CONFIG_EPROM_FREQ);
	setSCL5(0);//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
void iic5Stop(void){//����IICֹͣ�ź�
	setSCL5(0);
	setSDA5(0);//STOP:when CLK is high DATA change form low to high
 	delayUs(CONFIG_EPROM_FREQ);
	setSCL5(1); 
	setSDA5(1);//����I2C���߽����ź�
	delayUs(CONFIG_EPROM_FREQ);							   	
}

uint8_t iic5WaitAck(void){
//�������ݺ󣬵ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ�ܣ�IICֱ���˳�
//        0������Ӧ��ɹ���ʲô������
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
	setSCL5(0);    //ʱ�����0 	   
	return 0;  
}
void iic5Ack(void){//����ACKӦ��
	setSCL5(0);
	setSDA5(0);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL5(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL5(0);
}
	    
void iic5NAck(void){//������ACKӦ��	
	setSCL5(0);
	setSDA5(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL5(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL5(0);
}					 				     	  
void iic5SendByte(uint8_t txd){//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��                        
    uint8_t t;    	    
    setSCL5(0);//����ʱ�ӿ�ʼ���ݴ���
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
  
uint8_t iic5ReadByte(uint8_t ack){//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK 
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
        iic5NAck();        //����nACK
    else
        iic5Ack();         //����ACK   
    return receive;
}
