#include "i2c0.h"
/*****************************************************************************/
sbit SDA0 = P3^5;
sbit SCL0 = P3^6;				
static uint8_t TimeReload_H, TimeReload_L;
/*****************************************************************************/
void iic0_Init(void){
	uint16_t temp = 0;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 12 /CONFIG_I2C0_FREQ));
	TimeReload_H = (temp >> 8) & 0xFF;
	TimeReload_L = temp & 0xFF;
}
static void setSCL(uint8_t s){
	if(s)
		SCL0 = 1;
	else
		SCL0 = 0;
}
static void setSDA(uint8_t s){
	if(s)
		SDA0 = 1;
	else
		SDA0 = 0;
}
static uint8_t getSCL(void){
	return SCL0;
}
static uint8_t getSDA(void){
	return SDA0; 
}
void IIC0_Start(void){//����IIC��ʼ�ź�
	setSDA(1);	  	  
	setSCL(1);
	delayUs(4);
 	setSDA(0);//START:when CLK is high,DATA change form high to low 
	delayUs(4);
	setSCL(0);//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  
void IIC0_Stop(void){//����IICֹͣ�ź�
	setSCL(0);
	setSDA(0);//STOP:when CLK is high DATA change form low to high
 	delayUs(4);
	setSCL(1); 
	setSDA(1);//����I2C���߽����ź�
	delayUs(4);							   	
}

uint8_t IIC0_Wait_Ack(void){
//�������ݺ󣬵ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ�ܣ�IICֱ���˳�
//        0������Ӧ��ɹ���ʲô������
	uint8_t ucErrTime=0;  
	setSDA(1);delayUs(1);	   
	setSCL(1);delayUs(1);	 
	while(getSDA()){
		ucErrTime++;
		if(ucErrTime>250){
			IIC0_Stop();
			return 1;
		}
	}
	setSCL(0);    //ʱ�����0 	   
	return 0;  
} 

void IIC0_Ack(void){//����ACKӦ��
	setSCL(0);
	setSDA(0);
	delayUs(2);
	setSCL(1);
	delayUs(2);
	setSCL(0);
}
	    
void IIC0_NAck(void){//������ACKӦ��	
	setSCL(0);
	setSDA(1);
	delayUs(2);
	setSCL(1);
	delayUs(2);
	setSCL(0);
}					 				     
			  
void IIC0_Send_Byte(uint8_t txd){//IIC����һ���ֽ�
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
		delayUs(2);
		setSCL(1);
		delayUs(2); 
		setSCL(0);	
		delayUs(2);
    }	 
} 	    
  
uint8_t IIC0_Read_Byte(uint8_t ack){//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK 
	uint8_t i, receive=0;
    for(i=0;i<8;i++ ){
        setSCL(0); 
        delayUs(2);
		setSCL(1);
        receive <<= 1;
        if(getSDA())
			receive ++;   
		delayUs(1); 
    }					 
    if(!ack)
        IIC0_NAck();        //����nACK
    else
        IIC0_Ack();         //����ACK   
    return receive;
}
