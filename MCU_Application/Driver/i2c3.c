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
void iic3Start(void){//����IIC��ʼ�ź�
	setSDA3(1);	  	  
	setSCL3(1);
	delayUs(CONFIG_EPROM_FREQ);
 	setSDA3(0);//START:when CLK is high,DATA change form high to low 
	delayUs(CONFIG_EPROM_FREQ);
	setSCL3(0);//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
void iic3Stop(void){//����IICֹͣ�ź�
	setSCL3(0);
	setSDA3(0);//STOP:when CLK is high DATA change form low to high
 	delayUs(CONFIG_EPROM_FREQ);
	setSCL3(1); 
	setSDA3(1);//����I2C���߽����ź�
	delayUs(CONFIG_EPROM_FREQ);							   	
}

uint8_t iic3WaitAck(void){
//�������ݺ󣬵ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ�ܣ�IICֱ���˳�
//        0������Ӧ��ɹ���ʲô������
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
	setSCL3(0);    //ʱ�����0 	   
	return 0;  
}
void iic3Ack(void){//����ACKӦ��
	setSCL3(0);
	setSDA3(0);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL3(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL3(0);
}
	    
void iic3NAck(void){//������ACKӦ��	
	setSCL3(0);
	setSDA3(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL3(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL3(0);
}					 				     	  
void iic3SendByte(uint8_t txd){//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��                        
    uint8_t t;    	    
    setSCL3(0);//����ʱ�ӿ�ʼ���ݴ���
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
  
uint8_t iic3ReadByte(uint8_t ack){//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK 
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
        iic3NAck();        //����nACK
    else
        iic3Ack();         //����ACK   
    return receive;
}
