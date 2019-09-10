#include "eprom.h"
/*****************************************************************************/
/*****************************************************************************/
void epromInit(void){//初始化IIC接口
}
uint8_t epromReadOneByte(uint16_t ReadAddr){//在AT24CXX指定地址读出一个数据
//ReadAddr:开始读数的地址  
//返回值  :读到的数据				  
	uint8_t temp=0;		  	    																 
	iic0Start();  
#if CONFIG_EPROM_SIZE > CONFIG_AT24C16_SIZE
//兼容24Cxx中其他的版本
	iic0SendByte(((CONFIG_EPROM_ADDRESS << 1) & 0xFE));//发送写命令
	iic0WaitAck();
	iic0SendByte(ReadAddr >> 8);//发送高地址		 
#else 
	iic0SendByte(((CONFIG_EPROM_ADDRESS << 1) & 0xFE) + ((ReadAddr / 256) << 1));//发送器件地址0XA0,写数据 	 
#endif
	iic0WaitAck(); 
	iic0SendByte(ReadAddr % 256);   //发送低地址
	iic0WaitAck();	    
	iic0Start();  	 	   
	iic0SendByte(((CONFIG_EPROM_ADDRESS << 1) | 0x01));//进入接收模式			   
	iic0WaitAck();	 
	temp = iic0ReadByte(0);//读一个字节，非应答信号信号	   
	iic0Stop();        //产生一个停止条件
	return temp;
}

void epromWriteOneByte(uint16_t WriteAddr, uint8_t DataToWrite){//在AT24CXX指定地址写入一个数据
//WriteAddr  :写入数据的目的地址    
//DataToWrite:要写入的数据				   	  	    																 
	iic0Start();  
#if CONFIG_EPROM_SIZE > CONFIG_AT24C16_SIZE
	iic0SendByte(((CONFIG_EPROM_ADDRESS << 1) & 0xFE));	    //发送写命令
	iic0WaitAck();
	iic0SendByte(WriteAddr >> 8);    //发送高地址
#else
	iic0SendByte(((CONFIG_EPROM_ADDRESS << 1) & 0xFE) +( (WriteAddr / 256) << 1));   //发送器件地址0XA0,写数据 
#endif 
	iic0WaitAck();	   
	iic0SendByte(WriteAddr % 256);   //发送低地址
	iic0WaitAck(); 	 										  		   
	iic0SendByte(DataToWrite);     //发送字节							   
	iic0WaitAck();  		    	   
	iic0Stop();//产生一个停止条件 
#if CONFIG_EPROM_FRAM != 1
	delayMs(10);	
#endif
}

void epromWriteLenByte(uint16_t WriteAddr, uint32_t DataToWrite, uint8_t Len){//在AT24CXX里面的指定地址开始写入长度为Len的数据
//该函数用于写入16bit或者32bit的数据.
//WriteAddr  :开始写入的地址  
//DataToWrite:数据数组首地址
//Len        :要写入数据的长度2,4  	
	uint8_t t;
	for(t = 0;t < Len;t ++){
		epromWriteOneByte(WriteAddr + t, (DataToWrite >> (8 * t)) & 0xff);
	}												    
}
uint32_t epromReadLenByte(uint16_t ReadAddr, uint8_t Len){//在AT24CXX里面的指定地址开始读出长度为Len的数据
//该函数用于读出16bit或者32bit的数据.
//ReadAddr   :开始读出的地址 
//返回值     :数据
//Len        :要读出数据的长度2,4  	
	uint8_t t;
	uint32_t temp=0;
	for(t = 0;t < Len;t ++){
		temp <<= 8;
		temp += epromReadOneByte(ReadAddr + Len - t - 1); 	 				   
	}
	return temp;												    
}
     
void epromRead(uint16_t ReadAddr, uint8_t *pBuffer,uint16_t NumToRead){//在AT24CXX里面的指定地址开始读出指定个数的数据
//ReadAddr :开始读出的地址 对24c02为0~255
//pBuffer  :数据数组首地址
//NumToRead:要读出数据的个数
	while(NumToRead){
		*pBuffer++ = epromReadOneByte(ReadAddr ++);	
		NumToRead --;
	}
}  
void epromWrite(uint16_t WriteAddr, uint8_t *pBuffer, uint16_t NumToWrite){//在AT24CXX里面的指定地址开始写入指定个数的数据
//WriteAddr :开始写入的地址 对24c02为0~255
//pBuffer   :数据数组首地址
//NumToWrite:要写入数据的个数
	while(NumToWrite --){
		epromWriteOneByte(WriteAddr, *pBuffer);
		WriteAddr ++;
		pBuffer ++;
	}
}
#if CONFIG_EPROM_PAGEWRITE == 1
void epromWritePage(uint16_t data pageAddr, uint8_t *pBuffer,uint8_t data NumToWrite){//24C32以上容量按页面写入

}
#endif
uint8_t epromTest(void){//EPROM 读写自测试
	uint32_t i, crc16Read = 0, crc16Write = 0;	
	uint8_t temp;
	crc16Clear();
	for(i = 0;i < CONFIG_EPROM_SIZE;i ++){
		temp = rand()%0xFF;
		crc16Write = crc16CalculateAdd(temp);
		setLedEprom(true);
		epromWriteOneByte(i, temp);
		setLedEprom(false);
	}
	crc16Clear();
	for(i = 0;i < CONFIG_EPROM_SIZE;i ++){
		setLedEprom(true);
		temp = epromReadOneByte(i);
		setLedEprom(false);
		crc16Read = crc16CalculateAdd(temp);
	}
	if(crc16Read == crc16Write){
		return true;
	}
	else{
		return false;
	}
}