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
	//配置输入
	iic5Start();  
	iic5SendByte((CONFIG_PCA9554_ADDRESS << 1) & 0xFE);	    //发送写命令
	iic5WaitAck();
	iic5SendByte(CONFIG_PCA9554_CMD_RW_CONFIG);//发送CMD
	iic5WaitAck();
	iic5SendByte(0xFF);//config input
	iic5WaitAck();
	iic5Stop();
	//配置输入极性
	iic5Start();  
	iic5SendByte((CONFIG_PCA9554_ADDRESS << 1) & 0xFE);	    //发送写命令
	iic5WaitAck();
	iic5SendByte(CONFIG_PCA9554_CMD_RW_POLARITY);//发送CMD
	iic5WaitAck();
	iic5SendByte(0x00);//config input
	iic5WaitAck();
	iic5Stop();	
}

uint8_t inPca9554Read(void){
	uint8_t temp;
	iic5Start();  
	iic5SendByte((CONFIG_PCA9554_ADDRESS << 1) & 0xFE);	    //发送写命令
	iic5WaitAck();
	iic5SendByte(CONFIG_PCA9554_CMD_R_INPUT);//发送CMD
	iic5WaitAck();
	iic5Start();  	 	   
	iic5SendByte(((CONFIG_PCA9554_ADDRESS << 1) | 0x01));//进入接收模式			   
	iic5WaitAck();	 
	temp = iic5ReadByte(0);//读一个字节，非应答信号信号	
	iic5WaitAck();
	iic5Stop();	
	return temp;
}