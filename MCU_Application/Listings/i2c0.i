
#line 1 "Driver\i2c0.c" /0
  
#line 1 "Driver\i2c0.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
 
 
 
 
 <<<<<<< HEAD
 
 =======
 
#error *** WARNING C317 IN LINE 9 OF .\MainApp\appConfig.h: attempt to redefine macro 'CONFIG_SYSCLK'
 
#line 11 ".\MainApp\appConfig.h" /1
 
  
  
 
  
  
  
  
  
  
  
 
 
 
 
  
  
  
  
 
  
  
  
  
 
 
  
  
  
  
  
 
  
 
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
  
 
 
 
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
 
  
 
  
 
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
 
 
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
  
 
  
 
  
 
 
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
 
 
  
  
 
  
 
  
 
  
  
  
  
  
 
 
 
#line 4 "Driver\i2c0.h" /0
#line 4 "Driver\i2c0.h" /0
 
 
 
 
 void iic0Init(void);
 void iic0Start(void);
 void iic0Stop(void);
 uint8_t iic0WaitAck(void);
 void iic0Ack(void);
 void iic0NAck(void);
 void iic0SendByte(uint8_t txd);
 uint8_t iic0ReadByte(uint8_t ack);
 
 
 
 
#line 1 "Driver\i2c0.c" /0
 
 
 
 void iic0Init(void){
 
 }
 static void setSCL0(uint8_t s){
 if(s)
 <<<<<<< HEAD
 P4 |= (1 << 7);
 else
 P4 &= ~((uint8_t)(1 << 7));
 }
 static void setSDA0(uint8_t s){
 if(s)
 P4 |= (uint8_t)(1 << 6);
 else
 P4 &= ~((uint8_t)(1 << 6));
 }
 static uint8_t getSCL0(void){
 return (P4 >> 7) & 0x01;
 }
 static uint8_t getSDA0(void){
 return (P4 >> 6) & 0x01;
 =======
 P7 |= (1 << 7);
 else
 P7 &= ~((uint8_t)(1 << 7));
 }
 static void setSDA0(uint8_t s){
 if(s)
 P7 |= (uint8_t)(1 << 6);
 else
 P7 &= ~((uint8_t)(1 << 6));
 }
 static uint8_t getSCL0(void){
 return (P7 >> 7) & 0x01;
 }
 static uint8_t getSDA0(void){
 return (P7 >> 6) & 0x01;
 >>>>>>> MCFCL_25MP
 }
 void iic0Start(void){ 
 setSDA0(1);	  	  
 setSCL0(1);
 delayUs(CONFIG_I2C0_FREQ);
 setSDA0(0); 
 delayUs(CONFIG_I2C0_FREQ);
 setSCL0(0); 
 }	  
 void iic0Stop(void){ 
 setSCL0(0);
 setSDA0(0); 
 delayUs(CONFIG_I2C0_FREQ);
 setSCL0(1); 
 setSDA0(1); 
 delayUs(CONFIG_I2C0_FREQ);							   	
 }
 
 uint8_t iic0WaitAck(void){
 
 
 
 uint8_t ucErrTime=0;  
 setSDA0(1);
 delayUs(1);	   
 setSCL0(1);
 delayUs(1);	 
 while(getSDA0()){
 ucErrTime ++;
 if(ucErrTime >= CONFIG_I2C_WAITACT_TIME){
 iic0Stop();
 return 1;
 }
 }
 setSCL0(0);     
 return 0;  
 }
 void iic0Ack(void){ 
 setSCL0(0);
 setSDA0(0);
 delayUs(CONFIG_I2C0_FREQ);
 setSCL0(1);
 delayUs(CONFIG_I2C0_FREQ);
 setSCL0(0);
 }
 
 void iic0NAck(void){ 
 setSCL0(0);
 setSDA0(1);
 delayUs(CONFIG_I2C0_FREQ);
 setSCL0(1);
 delayUs(CONFIG_I2C0_FREQ);
 setSCL0(0);
 }					 				     	  
 void iic0SendByte(uint8_t txd){ 
 
 
 
 uint8_t t;    	    
 setSCL0(0); 
 for(t = 0;t < 8;t ++)
 {              
 
 if((txd & 0x80) >> 7)
 setSDA0(1);
 else
 setSDA0(0);
 txd <<= 1; 	  
 delayUs(CONFIG_I2C0_FREQ);
 setSCL0(1);
 delayUs(CONFIG_I2C0_FREQ); 
 setSCL0(0);	
 delayUs(CONFIG_I2C0_FREQ);
 }	 
 } 	    
 
 uint8_t iic0ReadByte(uint8_t ack){ 
 uint8_t i, receive=0;
 for(i=0;i<8;i++ ){
 setSCL0(0); 
 delayUs(CONFIG_I2C0_FREQ);
 setSCL0(1);
 receive <<= 1;
 if(getSDA0())
 receive ++;   
 delayUs(CONFIG_I2C0_FREQ); 
 }					 
 if(!ack)
 iic0NAck();         
 else
 iic0Ack();          
 return receive;
 }
#error *** WARNING C316 IN LINE 134 OF Driver\i2c0.c: unterminated conditionals
