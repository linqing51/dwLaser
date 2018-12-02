#include "inPca9554.h"
/*****************************************************************************/
#define CONFIG_PCA9554_ADDRESS			0x20
#define CONFIG_PCA9554A_ADDRESS			0x38
#define CONFIG_PCA9554_CMD_R_INPUT		0x00
#define CONFIG_PCA9554_CMD_RW_OUTPUT	0x01
#define CONFIG_PCA9554_CMD_RW_POLARITY	0x02
#define CONFIG_PCA9554_CMD_RW_CONFIG	0x03
/*****************************************************************************/
void inPca9554Init(void){
	//��������
	iic5Start();  
	iic5SendByte((CONFIG_PCA9554_ADDRESS << 1) & 0xFE);	    //����д����
	iic5WaitAck();
	iic5SendByte(CONFIG_PCA9554_CMD_RW_CONFIG);//����CMD
	iic5WaitAck();
	iic5SendByte(0xFF);//config input
	iic5WaitAck();
	iic5Stop();
	//�������뼫��
	iic5Start();  
	iic5SendByte((CONFIG_PCA9554_ADDRESS << 1) & 0xFE);	    //����д����
	iic5WaitAck();
	iic5SendByte(CONFIG_PCA9554_CMD_RW_POLARITY);//����CMD
	iic5WaitAck();
	iic5SendByte(0x00);//config input
	iic5WaitAck();
	iic5Stop();	
}

uint8_t inPca9554Read(void){
	uint8_t temp;
	iic5Start();  
	iic5SendByte((CONFIG_PCA9554_ADDRESS << 1) & 0xFE);	    //����д����
	iic5WaitAck();
	iic5SendByte(CONFIG_PCA9554_CMD_R_INPUT);//����CMD
	iic5WaitAck();
	iic5Start();  	 	   
	iic5SendByte(((CONFIG_PCA9554_ADDRESS << 1) | 0x01));//�������ģʽ			   
	iic5WaitAck();	 
	temp = iic5ReadByte(0);//��һ���ֽڣ���Ӧ���ź��ź�	
	iic5WaitAck();
	iic5Stop();	
	return temp;
}