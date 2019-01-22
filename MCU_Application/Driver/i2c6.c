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
void iic6Start(void){//����IIC��ʼ�ź�
	setSDA6(1);	  	  
	setSCL6(1);
	delayUs(CONFIG_EPROM_FREQ);
 	setSDA6(0);//START:when CLK is high,DATA change form high to low 
	delayUs(CONFIG_EPROM_FREQ);
	setSCL6(0);//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
void iic6Stop(void){//����IICֹͣ�ź�
	setSCL6(0);
	setSDA6(0);//STOP:when CLK is high DATA change form low to high
 	delayUs(CONFIG_EPROM_FREQ);
	setSCL6(1); 
	setSDA6(1);//����I2C���߽����ź�
	delayUs(CONFIG_EPROM_FREQ);							   	
}

uint8_t iic6WaitAck(void){
//�������ݺ󣬵ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ�ܣ�IICֱ���˳�
//        0������Ӧ��ɹ���ʲô������
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
	setSCL6(0);    //ʱ�����0 	   
	return 0;  
}
void iic6Ack(void){//����ACKӦ��
	setSCL6(0);
	setSDA6(0);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL6(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL6(0);
}
	    
void iic6NAck(void){//������ACKӦ��	
	setSCL6(0);
	setSDA6(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL6(1);
	delayUs(CONFIG_EPROM_FREQ);
	setSCL6(0);
}					 				     	  
void iic6SendByte(uint8_t txd){//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��                        
    uint8_t t;    	    
    setSCL6(0);//����ʱ�ӿ�ʼ���ݴ���
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
  
uint8_t iic6ReadByte(uint8_t ack){//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK 
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
        iic6NAck();        //����nACK
    else
        iic6Ack();         //����ACK   
    return receive;
}
