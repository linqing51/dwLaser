#include "epromSimulation.h"
/*****************************************************************************/
xdata volatile uint8_t epromSim[CONFIG_EPROM_SIZE];
void epromInit(void){//初始化IIC接口
	memset(epromSim, 0x0, CONFIG_EPROM_SIZE);
}

uint8_t epromReadOneByte(uint16_t ReadAddr){//在AT24CXX指定地址读出一个数据
	if(ReadAddr < CONFIG_EPROM_SIZE){
		return epromSim[ReadAddr];
	}
	else{
		return 0;
	}
}

void epromWriteOneByte(uint16_t WriteAddr, uint8_t DataToWrite){//在AT24CXX指定地址写入一个数据
	if(WriteAddr < CONFIG_EPROM_SIZE){
		epromSim[WriteAddr] = DataToWrite;
	}
}

void epromWriteLenByte(uint16_t WriteAddr, uint32_t DataToWrite, uint8_t Len){//在AT24CXX里面的指定地址开始写入长度为Len的数据
//该函数用于写入16bit或者32bit的数据.
//WriteAddr  :开始写入的地址  
//DataToWrite:数据数组首地址
//Len        :要写入数据的长度2,4  	
	data uint8_t t;
	for(t = 0;t < Len;t ++){
		epromWriteOneByte(WriteAddr + t, (DataToWrite >> (8 * t)) & 0xff);
	}												    
}
uint32_t epromReadLenByte(uint16_t ReadAddr, uint8_t Len){//在AT24CXX里面的指定地址开始读出长度为Len的数据
//该函数用于读出16bit或者32bit的数据.
//ReadAddr   :开始读出的地址 
//返回值     :数据
//Len        :要读出数据的长度2,4  	
	data uint8_t t;
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
	idata uint32_t i;	
	idata uint8_t result;
	for(i = 0;i < CONFIG_EPROM_SIZE;i ++){
#if CONFIG_SPLC_USING_LED == 1	
		setLedEprom(true);
#endif
		epromWriteOneByte(i, (i & 0xFF));
#if CONFIG_SPLC_USING_LED == 1	
		setLedEprom(false);
#endif
	}
	result = 0;
	for(i = 0;i < CONFIG_EPROM_SIZE;i ++){
#if CONFIG_SPLC_USING_LED == 1	
		setLedEprom(true);
#endif
		if(epromReadOneByte(i) != (i & 0xFF)){
			return false;
		}
#if CONFIG_SPLC_USING_LED == 1	
		setLedEprom(false);
#endif
	}
	return true;
}