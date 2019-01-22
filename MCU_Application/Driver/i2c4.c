#include "i2c4.h"
/*****************************************************************************/				
/*****************************************************************************/
void iic4Init(void){

}
static void setSCL(uint8_t s){
	if(s)
		P4 |= 1 << 5;
	else
		P4 &= ~(1 << 5);
}
static void setSDA(uint8_t s){
	if(s)
		P4 |= 1 << 4;
	else
		P4 &= ~(1 << 4);
}
static uint8_t getSCL(void){
	return ((P4 >> 5) & 0x01);
}
static uint8_t getSDA(void){
	return ((P4 >> 4) & 0x01); 
}
void iic4Start(void){//����IIC��ʼ�ź�
	setSDA(1);	  	  
	setSCL(1);
	delayUs(CONFIG_EPROM_FREQ);
 	setSDA(0);//START:when CLK is high,DATA change form high to low 
	delayUs(CONFIG_EPROM_FREQ);
	setSCL(0);//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
void iic4Stop(void){//����IICֹͣ�ź�
	setSCL(0);
	setSDA(0);//STOP:when CLK is high DATA change form low to high
 	delayUs(CONFIG_EPROM_FREQ);
	setSCL(1); 
	setSDA(1);//����I2C���߽����ź�
	delayUs(CONFIG_EPROM_FREQ);							   	
}

uint8_t iic4WaitAck(void){
//�������ݺ󣬵ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ�ܣ�IICֱ���˳�
//        0������Ӧ��ɹ���ʲô������
	uint8_t ucErrTime=0;  
	setSDA(1);
	delayUs(1);	   
	setSCL(1);
	delayUs(1);	 
	while(getSDA()){
		ucErrTime ++;
		if(ucErrTime >= CONFIG_I2C_WAITACT_TIME){
			iic4Stop();
			return 1;
		}
	}
	setSCL(0);    //ʱ�����0 	   
	return 0;  
}
void iic4Ack(void){//����ACKӦ��
	setSCL(0);
	setSDA(0);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL(0);
}
	    
void iic4NAck(void){//������ACKӦ��	
	setSCL(0);
	setSDA(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL(0);
}					 				     	  
void iic4SendByte(uint8_t txd){//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��                        
    uint8_t t;    	    
    setSCL(0);//����ʱ�ӿ�ʼ���ݴ���
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
  
uint8_t iic4ReadByte(uint8_t ack){//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK 
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
        iic4NAck();        //����nACK
    else
        iic4Ack();         //����ACK   
    return receive;
}
