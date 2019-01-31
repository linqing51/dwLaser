#include "epromSimulation.h"
/*****************************************************************************/
xdata volatile uint8_t epromSim[CONFIG_EPROM_SIZE];
void epromInit(void){//��ʼ��IIC�ӿ�
	memset(epromSim, 0x0, CONFIG_EPROM_SIZE);
}

uint8_t epromReadOneByte(uint16_t ReadAddr){//��AT24CXXָ����ַ����һ������
	if(ReadAddr < CONFIG_EPROM_SIZE){
		return epromSim[ReadAddr];
	}
	else{
		return 0;
	}
}

void epromWriteOneByte(uint16_t WriteAddr, uint8_t DataToWrite){//��AT24CXXָ����ַд��һ������
	if(WriteAddr < CONFIG_EPROM_SIZE){
		epromSim[WriteAddr] = DataToWrite;
	}
}

void epromWriteLenByte(uint16_t WriteAddr, uint32_t DataToWrite, uint8_t Len){//��AT24CXX�����ָ����ַ��ʼд�볤��ΪLen������
//�ú�������д��16bit����32bit������.
//WriteAddr  :��ʼд��ĵ�ַ  
//DataToWrite:���������׵�ַ
//Len        :Ҫд�����ݵĳ���2,4  	
	data uint8_t t;
	for(t = 0;t < Len;t ++){
		epromWriteOneByte(WriteAddr + t, (DataToWrite >> (8 * t)) & 0xff);
	}												    
}
uint32_t epromReadLenByte(uint16_t ReadAddr, uint8_t Len){//��AT24CXX�����ָ����ַ��ʼ��������ΪLen������
//�ú������ڶ���16bit����32bit������.
//ReadAddr   :��ʼ�����ĵ�ַ 
//����ֵ     :����
//Len        :Ҫ�������ݵĳ���2,4  	
	data uint8_t t;
	uint32_t temp=0;
	for(t = 0;t < Len;t ++){
		temp <<= 8;
		temp += epromReadOneByte(ReadAddr + Len - t - 1); 	 				   
	}
	return temp;												    
}
     
void epromRead(uint16_t ReadAddr, uint8_t *pBuffer,uint16_t NumToRead){//��AT24CXX�����ָ����ַ��ʼ����ָ������������
//ReadAddr :��ʼ�����ĵ�ַ ��24c02Ϊ0~255
//pBuffer  :���������׵�ַ
//NumToRead:Ҫ�������ݵĸ���
	while(NumToRead){
		*pBuffer++ = epromReadOneByte(ReadAddr ++);	
		NumToRead --;
	}
}  
void epromWrite(uint16_t WriteAddr, uint8_t *pBuffer, uint16_t NumToWrite){//��AT24CXX�����ָ����ַ��ʼд��ָ������������
//WriteAddr :��ʼд��ĵ�ַ ��24c02Ϊ0~255
//pBuffer   :���������׵�ַ
//NumToWrite:Ҫд�����ݵĸ���
	while(NumToWrite --){
		epromWriteOneByte(WriteAddr, *pBuffer);
		WriteAddr ++;
		pBuffer ++;
	}
}
#if CONFIG_EPROM_PAGEWRITE == 1
void epromWritePage(uint16_t data pageAddr, uint8_t *pBuffer,uint8_t data NumToWrite){//24C32����������ҳ��д��

}
#endif
uint8_t epromTest(void){//EPROM ��д�Բ���
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