#include "dk25l.h"

#define DK25L_STX			0xAA//
//通用指令
#define CMD_FIND_CARD_UID				0x01//获取卡片UID
#define CMD_FIND_CARD_CLASS			0x02//获取卡片类型
#define CMD_AUTO_FIND_CARD			0x95//自动寻卡开关
#define CMD_MOD_BAUDRATE			0xA0//修改模块波特率
#define CMD_CONFIG_SYS_PARA			0xA1//配置系统参数指令
#define CMD_READ_SYS_PARA			0xA2//读取系统参数指令
#define CMD_READ_FW_VER				0xB0//获取模块固件版本号
#define CMD_READ_HW_VER				0xB1//获取模块硬件版本号
//Mifare指令
#define CMD_MIFARE_WRITE_KEYA		0x03//向模块写入需要验证的密钥(A密钥)
#define CMD_MIFARE_READ_BLOCK		0x04//Mifare 卡读块
#define CMD_MIFARE_WRITE_BLOCK		0x05//Mifare 卡写块
#define CMD_MIFATE_INIT				0x06//Mifare 卡增减值初始化
#define CMD_MIFARE_ADD				0x07//卡增值
#define CMD_MIFARE_DEC				0x08//卡减值

#define CONFIG_DK25L_RXD_BUFFER_SIZE			256
#define CONFIG_DK25L_TXD_BUFFER_SIZE			256
volatile unsigned char RcvNum;                    

uint8_t dk25lRcvBuf[CONFIG_DK25L_RXD_BUFFER_SIZE];
uint8_t dk25lSendBuf[CONFIG_DK25L_TXD_BUFFER_SIZE];
uint16_t dk25lRcvSize;//接收索引
uint16_t dk25lSendSize;//发送索引


void Int_serial() INTERRUPT_UART0{
	if(TI0){
        TI0 = 0;        
        if(SendNum == 0){
            FlagSendOk = 0;                    
        }
        else {
            SBUF0 = *SendRead;
            if(SendRead == (SendBuf + SerialSEND - 1)){
                SendRead = SendBuf;                        
            }
            else {
                SendRead++;
            }
			SendNum--;						                   
        }
    }
	if(RI0){
		RI0 = 0;  
	    if(SBUF0 == DK25L_STX){//接收到帧头
			dk25lRcvSize = 1;	
			dk25lRcvBuf[(dk25lRcvSize - 1)] = DK25L_STX;
		}
		else if(dk25lRcvSize == 1){//接收到长度字节
			dk25lRcvSize = 2;
			dk25lRcvBuf[(dk25lRcvSize - 1)] = SBUF0;
		}      
        else if((dk25lRcvSize >= 3) && 
			   ((dk25lRcvSize - 2) < dk25lRcvBuf[1]) &&
			   (dk25lRcvSize < CONFIG_DK25L_RXD_BUFFER_SIZE)){
			dk25lRcvSize ++;
			dk25lRcvBuf[dk25lRcvSize] = SBUF0;        
		}
		if(dk25lRcvSize == (dk25lRcvBuf[1] + 2)){//命令接收完毕开始
		}
   }   
}

