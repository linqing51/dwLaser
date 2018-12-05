#include "outPca9554.h"
/*****************************************************************************/
#define CONFIG_PCA9554_ADDRESS			0x20
#define CONFIG_PCA9554A_ADDRESS			0x38
#define CONFIG_PCA9554_CMD_R_INPUT		0x00
#define CONFIG_PCA9554_CMD_RW_OUTPUT	0x01
#define CONFIG_PCA9554_CMD_RW_POLARITY	0x02
#define CONFIG_PCA9554_CMD_RW_CONFIG	0x03
/*****************************************************************************/
void outPca9554Init(void){
	//配置输入
	iic6Start();  
	iic6SendByte((CONFIG_PCA9554_ADDRESS << 1) & 0xFE);	    //发送写命令
	iic6WaitAck();
	iic6SendByte(CONFIG_PCA9554_CMD_RW_CONFIG);//发送CMD
	iic6WaitAck();
	iic6SendByte(0x0);//config output
	iic6WaitAck();
	iic6Stop();
}
uint8_t outPca9554Read(void){
	uint8_t temp;
	iic6Start();  
	iic6SendByte((CONFIG_PCA9554_ADDRESS << 1) & 0xFE);	    //发送写命令
	iic6WaitAck();
	iic6SendByte(CONFIG_PCA9554_CMD_RW_OUTPUT);//发送CMD
	iic6WaitAck();
	iic6Start(); 
	iic6SendByte((CONFIG_PCA9554_ADDRESS << 1) | 0x01);//进入接收模式	
	iic6WaitAck();
	temp = iic6ReadByte(0);//读一个字节，非应答信号信号	 
	iic6WaitAck();
	iic6Stop();
	return 0;
}
void outPca9554Write(uint8_t wdata){
	iic6Start();  
	iic6SendByte((CONFIG_PCA9554_ADDRESS << 1) & 0xFE);	    //发送写命令
	iic6WaitAck();
	iic6SendByte(CONFIG_PCA9554_CMD_RW_OUTPUT);//发送CMD
	iic6WaitAck();
	iic6SendByte(wdata);//config output
	iic6WaitAck();
	iic6Stop();
}