
#line 1 "Driver\eprom.c" /0
  
#line 1 "Driver\eprom.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
 
 
 
 
 <<<<<<< HEAD
 
 =======
 
#error *** WARNING C317 IN LINE 9 OF .\MainApp\appConfig.h: attempt to redefine macro 'CONFIG_SYSCLK'
 
#line 11 ".\MainApp\appConfig.h" /1
 
  
  
 
  
  
  
  
  
  
  
 
 
 
 
  
  
  
  
 
  
  
  
  
 
 
  
  
  
  
  
 
  
 
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
  
 
 
 
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
 
  
 
  
 
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
 
 
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
  
 
  
 
  
 
 
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
 
 
  
  
 
  
 
  
 
  
  
  
  
  
 
 
 
#line 4 "Driver\eprom.h" /0
#line 4 "Driver\eprom.h" /0
 
 
 
 void epromInit(void);
 uint8_t epromReadOneByte(uint16_t ReadAddr);
 void epromWriteOneByte(uint16_t WriteAddr, uint8_t DataToWrite);
 void epromWriteLenByte(uint16_t WriteAddr, uint32_t DataToWrite, uint8_t Len);
 uint32_t epromReadLenByte(uint16_t ReadAddr, uint8_t Len);
 void epromRead(uint16_t ReadAddr,uint8_t *pBuffer,uint16_t NumToRead);
 void epromWrite(uint16_t WriteAddr, uint8_t *pBuffer, uint16_t NumToWrite);
 uint8_t epromTest(void);
 
#line 1 "Driver\eprom.c" /0
 
 
 
 void epromInit(void){ 
 iic0Init();
 }
 
 uint8_t epromReadOneByte(uint16_t ReadAddr){ 
 
 
 data uint8_t temp=0;		  	    																 
 iic0Start();  
 
#error *** WARNING C322 IN LINE 13 OF Driver\eprom.c: unknown identifier
#error *** WARNING C322 IN LINE 13 OF Driver\eprom.c: unknown identifier
#line 14 "Driver\eprom.c" /1
 
 
 
 
 
#line 19 "Driver\eprom.c" /0
 iic0SendByte(((CONFIG_EPROM_ADDRESS << 1) & 0xFE) + ((ReadAddr / 256) << 1)); 
 
 iic0WaitAck(); 
 iic0SendByte(ReadAddr % 256);    
 iic0WaitAck();	    
 iic0Start();  	 	   
 iic0SendByte(((CONFIG_EPROM_ADDRESS << 1) | 0x01)); 
 iic0WaitAck();	 
 temp = iic0ReadByte(0); 
 iic0Stop();         
 return temp;
 }
 
 void epromWriteOneByte(uint16_t WriteAddr, uint8_t DataToWrite){ 
 
 
 iic0Start();  
 
#error *** WARNING C322 IN LINE 36 OF Driver\eprom.c: unknown identifier
#error *** WARNING C322 IN LINE 36 OF Driver\eprom.c: unknown identifier
#line 37 "Driver\eprom.c" /1
 
 
 
 
#line 41 "Driver\eprom.c" /0
 iic0SendByte(((CONFIG_EPROM_ADDR << 1) & 0xFE) +( (WriteAddr / 256) << 1));    
 
 iic0WaitAck();	   
 iic0SendByte(WriteAddr % 256);    
 iic0WaitAck(); 	 										  		   
 iic0SendByte(DataToWrite);      
 iic0WaitAck();  		    	   
 iic0Stop(); 
 
#error *** WARNING C322 IN LINE 49 OF Driver\eprom.c: unknown identifier
 delayMs(10);	
 
 }
 
 void epromWriteLenByte(uint16_t WriteAddr, uint32_t DataToWrite, uint8_t Len){ 
 
 
 
 
 data uint8_t t;
 for(t = 0;t < Len;t ++){
 epromWriteOneByte(WriteAddr + t, (DataToWrite >> (8 * t)) & 0xff);
 }												    
 }
 uint32_t epromReadLenByte(uint16_t ReadAddr, uint8_t Len){ 
 
 
 
 
 data uint8_t t;
 uint32_t temp=0;
 for(t = 0;t < Len;t ++){
 temp <<= 8;
 temp += epromReadOneByte(ReadAddr + Len - t - 1); 	 				   
 }
 return temp;												    
 }
 
 void epromRead(uint16_t ReadAddr, uint8_t *pBuffer,uint16_t NumToRead){ 
 
 
 
 while(NumToRead){
 *pBuffer++ = epromReadOneByte(ReadAddr ++);	
 NumToRead --;
 }
 }  
 void epromWrite(uint16_t WriteAddr, uint8_t *pBuffer, uint16_t NumToWrite){ 
 
 
 
 while(NumToWrite --){
 epromWriteOneByte(WriteAddr, *pBuffer);
 WriteAddr ++;
 pBuffer ++;
 }
 }
 
#error *** WARNING C322 IN LINE 97 OF Driver\eprom.c: unknown identifier
#line 98 "Driver\eprom.c" /1
 
 
 
 
#line 102 "Driver\eprom.c" /0
 uint8_t epromTest(void){ 
 idata uint32_t i;	
 idata uint8_t result;
 for(i = 0;i < CONFIG_EPROM_SIZE;i ++){
 setLedEprom(0);
 epromWriteOneByte(i, (i & 0xFF));
 setLedEprom(1);
 }
 result = 0;
 for(i = 0;i < CONFIG_EPROM_SIZE;i ++){
 setLedEprom(0);
 if(epromReadOneByte(i) != (i & 0xFF)){
 return false;
 }
 setLedEprom(1);
 }
 return true;
 }
#error *** WARNING C316 IN LINE 119 OF Driver\eprom.c: unterminated conditionals
