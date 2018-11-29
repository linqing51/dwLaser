#include "eprom.h"
/*****************************************************************************/
#define AT24C01				127
#define AT24C02				255
#define AT24C04				511
#define AT24C08				1023
#define AT24C16				2047
#define AT24C32				4095
#define AT24C64	    		8191
#define AT24C128			16383
#define AT24C256			32767  
#define EE_TYPE 			AT24C02
/*****************************************************************************/
void AT24CXX_Init(void){//��ʼ��IIC�ӿ�
	IIC0_Init();
}

uint8_t AT24CXX_ReadOneByte(uint16_t ReadAddr){//��AT24CXXָ����ַ����һ������
//ReadAddr:��ʼ�����ĵ�ַ  
//����ֵ  :����������				  
	uint8_t temp=0;		  	    																 
		IIC0_Start();  
	if(EE_TYPE > AT24C16)            {//Ϊ�˼���24Cxx�������İ汾
		IIC0_Send_Byte(0XA0);//����д����
		IIC0_Wait_Ack();
		IIC0_Send_Byte(ReadAddr >> 8);//���͸ߵ�ַ
		IIC0_Wait_Ack();		 
	}else      
		IIC0_Send_Byte(0XA0 + ((ReadAddr / 256) << 1));//����������ַ0XA0,д���� 	 
	IIC0_Wait_Ack(); 
	IIC0_Send_Byte(ReadAddr % 256);   //���͵͵�ַ
	IIC0_Wait_Ack();	    
	IIC0_Start();  	 	   
	IIC0_Send_Byte(0XA1);           //�������ģʽ			   
	IIC0_Wait_Ack();	 
	temp=IIC0_Read_Byte(0);//��һ���ֽڣ���Ӧ���ź��ź�	   
	IIC0_Stop();        //����һ��ֹͣ����	    
	return temp;
}

void AT24CXX_WriteOneByte(uint16_t WriteAddr, uint8_t DataToWrite){//��AT24CXXָ����ַд��һ������
//WriteAddr  :д�����ݵ�Ŀ�ĵ�ַ    
//DataToWrite:Ҫд�������				   	  	    																 
	IIC0_Start();  
	if(EE_TYPE>AT24C16)
	{
		IIC0_Send_Byte(0XA0);	    //����д����
		IIC0_Wait_Ack();
		IIC0_Send_Byte(WriteAddr >> 8);    //���͸ߵ�ַ
	}else
	{
		IIC0_Send_Byte(0XA0 +( (WriteAddr / 256) << 1));   //����������ַ0XA0,д���� 
	}	 
	IIC0_Wait_Ack();	   
	IIC0_Send_Byte(WriteAddr % 256);   //���͵͵�ַ
	IIC0_Wait_Ack(); 	 										  		   
	IIC0_Send_Byte(DataToWrite);     //�����ֽ�							   
	IIC0_Wait_Ack();  		    	   
	IIC0_Stop();    //����һ��ֹͣ���� 
	delayMs(10);	 
}

void AT24CXX_WriteLenByte(uint16_t WriteAddr, uint32_t DataToWrite, uint8_t Len){//��AT24CXX�����ָ����ַ��ʼд�볤��ΪLen������
//�ú�������д��16bit����32bit������.
//WriteAddr  :��ʼд��ĵ�ַ  
//DataToWrite:���������׵�ַ
//Len        :Ҫд�����ݵĳ���2,4  	
	uint8_t t;
	for(t = 0;t < Len;t ++){
		AT24CXX_WriteOneByte(WriteAddr + t, (DataToWrite >> (8 * t)) & 0xff);
	}												    
}
uint32_t AT24CXX_ReadLenByte(uint16_t ReadAddr, uint8_t Len)
{//��AT24CXX�����ָ����ַ��ʼ��������ΪLen������
//�ú������ڶ���16bit����32bit������.
//ReadAddr   :��ʼ�����ĵ�ַ 
//����ֵ     :����
//Len        :Ҫ�������ݵĳ���2,4  	
	uint8_t t;
	uint32_t temp=0;
	for(t = 0;t < Len;t ++){
		temp <<= 8;
		temp += AT24CXX_ReadOneByte(ReadAddr + Len - t - 1); 	 				   
	}
	return temp;												    
}
     
void AT24CXX_Read(uint16_t ReadAddr,uint8_t *pBuffer,uint16_t NumToRead){//��AT24CXX�����ָ����ַ��ʼ����ָ������������
//ReadAddr :��ʼ�����ĵ�ַ ��24c02Ϊ0~255
//pBuffer  :���������׵�ַ
//NumToRead:Ҫ�������ݵĸ���
	while(NumToRead)
	{
		*pBuffer++ = AT24CXX_ReadOneByte(ReadAddr ++);	
		NumToRead --;
	}
}  
void AT24CXX_Write(uint16_t WriteAddr, uint8_t *pBuffer, uint16_t NumToWrite){//��AT24CXX�����ָ����ַ��ʼд��ָ������������
//WriteAddr :��ʼд��ĵ�ַ ��24c02Ϊ0~255
//pBuffer   :���������׵�ַ
//NumToWrite:Ҫд�����ݵĸ���
	while(NumToWrite --)
	{
		AT24CXX_WriteOneByte(WriteAddr, *pBuffer);
		WriteAddr ++;
		pBuffer ++;
	}
}
