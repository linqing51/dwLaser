#include "eprom.h"
/*****************************************************************************/

/*****************************************************************************/
void epromInit(void){//��ʼ��IIC�ӿ�
	iic0Init();
}

uint8_t epromReadOneByte(uint16_t ReadAddr){//��AT24CXXָ����ַ����һ������
//ReadAddr:��ʼ�����ĵ�ַ  
//����ֵ  :����������				  
	uint8_t temp=0;		  	    																 
	iic0Start();  
#if CONFIG_EPROM_SIZE > CONFIG_AT24C16_SIZE
//����24Cxx�������İ汾
	((CONFIG_EPROM_ADDR << 1) & 0xFE)
	
	iic0SendByte(((CONFIG_EPROM_ADDR << 1) & 0xFE));//����д����
	iic0WaitAck();
	iic0SendByte(ReadAddr >> 8);//���͸ߵ�ַ
	iic0WaitAck();		 
#else 
	iic0SendByte(((CONFIG_EPROM_ADDR << 1) & 0xFE) + ((ReadAddr / 256) << 1));//����������ַ0XA0,д���� 	 
#endif
	iic0WaitAck(); 
	iic0SendByte(ReadAddr % 256);   //���͵͵�ַ
	iic0WaitAck();	    
	iic0Start();  	 	   
	iic0SendByte(((CONFIG_EPROM_ADDR << 1) | 0x01));//�������ģʽ			   
	iic0WaitAck();	 
	temp = iic0ReadByte(0);//��һ���ֽڣ���Ӧ���ź��ź�	   
	iic0Stop();        //����һ��ֹͣ����	    
	return temp;
}

void epromWriteOneByte(uint16_t WriteAddr, uint8_t DataToWrite){//��AT24CXXָ����ַд��һ������
//WriteAddr  :д�����ݵ�Ŀ�ĵ�ַ    
//DataToWrite:Ҫд�������				   	  	    																 
	iic0Start();  
#if CONFIG_EPROM_SIZE > CONFIG_AT24C16_SIZE
	iic0SendByte(((CONFIG_EPROM_ADDR << 1) & 0xFE));	    //����д����
	iic0WaitAck();
	iic0SendByte(WriteAddr >> 8);    //���͸ߵ�ַ
#else
	iic0SendByte(((CONFIG_EPROM_ADDR << 1) & 0xFE) +( (WriteAddr / 256) << 1));   //����������ַ0XA0,д���� 
#endif 
	iic0WaitAck();	   
	iic0SendByte(WriteAddr % 256);   //���͵͵�ַ
	iic0WaitAck(); 	 										  		   
	iic0SendByte(DataToWrite);     //�����ֽ�							   
	iic0WaitAck();  		    	   
	iic0Stop();//����һ��ֹͣ���� 
#if CONFIG_EPROM_FRAM != 1
	delayMs(10);	 
#endif
}

void epromWriteLenByte(uint16_t WriteAddr, uint32_t DataToWrite, uint8_t Len){//��AT24CXX�����ָ����ַ��ʼд�볤��ΪLen������
//�ú�������д��16bit����32bit������.
//WriteAddr  :��ʼд��ĵ�ַ  
//DataToWrite:���������׵�ַ
//Len        :Ҫд�����ݵĳ���2,4  	
	uint8_t t;
	for(t = 0;t < Len;t ++){
		epromWriteOneByte(WriteAddr + t, (DataToWrite >> (8 * t)) & 0xff);
	}												    
}
uint32_t epromReadLenByte(uint16_t ReadAddr, uint8_t Len)
{//��AT24CXX�����ָ����ַ��ʼ��������ΪLen������
//�ú������ڶ���16bit����32bit������.
//ReadAddr   :��ʼ�����ĵ�ַ 
//����ֵ     :����
//Len        :Ҫ�������ݵĳ���2,4  	
	uint8_t t;
	uint32_t temp=0;
	for(t = 0;t < Len;t ++){
		temp <<= 8;
		temp += epromReadOneByte(ReadAddr + Len - t - 1); 	 				   
	}
	return temp;												    
}
     
void epromRead(uint16_t ReadAddr,uint8_t *pBuffer,uint16_t NumToRead){//��AT24CXX�����ָ����ַ��ʼ����ָ������������
//ReadAddr :��ʼ�����ĵ�ַ ��24c02Ϊ0~255
//pBuffer  :���������׵�ַ
//NumToRead:Ҫ�������ݵĸ���
	while(NumToRead)
	{
		*pBuffer++ = epromReadOneByte(ReadAddr ++);	
		NumToRead --;
	}
}  
void epromWrite(uint16_t WriteAddr, uint8_t *pBuffer, uint16_t NumToWrite){//��AT24CXX�����ָ����ַ��ʼд��ָ������������
//WriteAddr :��ʼд��ĵ�ַ ��24c02Ϊ0~255
//pBuffer   :���������׵�ַ
//NumToWrite:Ҫд�����ݵĸ���
	while(NumToWrite --)
	{
		epromWriteOneByte(WriteAddr, *pBuffer);
		WriteAddr ++;
		pBuffer ++;
	}
}
void epromTest(void){//EPROM ��д�Բ���
	uint8_t temp;
	uint32_t i, j, crc32Src, crc32Dist;
	j = 10;
	do{
		crc32Clear();
		for(i = 0;i <= CONFIG_EPROM_SIZE;i ++){
			temp = rand() % 255;
			crc32Src = crc32CalculateAdd(temp);
			epromWriteOneByte(i, temp);
		}
		crc32Clear();
		for(i = 0;i <= CONFIG_EPROM_SIZE;i ++){
			temp = epromReadOneByte(i);
			crc32Dist = crc32CalculateAdd(temp);
		}
		if(crc32Src == crc32Dist)
			printf("EPROM:Self Test Loop %d OK\n", j);
		else
			printf("EPROM:Self Test Loop %d Fail\n", j);
	}while(j--);
}