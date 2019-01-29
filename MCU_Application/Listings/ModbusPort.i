
#line 1 "Modbus\ModbusPort.c" /0
  
#line 1 "Modbus\modbusPort.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
 
 
 
 
 <<<<<<< HEAD
 
 =======
 
#error *** WARNING C317 IN LINE 9 OF .\MainApp\appConfig.h: attempt to redefine macro 'CONFIG_SYSCLK'
 
#line 11 ".\MainApp\appConfig.h" /1
 
  
  
 
  
  
  
  
  
  
  
 
 
 
 
  
  
  
  
 
  
  
  
  
 
 
  
  
  
  
  
 
  
 
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
  
 
 
 
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
 
  
 
  
 
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
 
 
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
  
 
  
 
  
 
 
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
 
 
  
  
 
  
 
  
 
  
  
  
  
  
 
 
 
#line 4 "Modbus\modbusPort.h" /0
#line 4 "Modbus\modbusPort.h" /0
 
 
 extern void modBusUartInitialise(uint32_t baudrate);
 extern void modBusTimerInitialise(void);
 extern void modBusUartPutch(uint8_t c);
 extern uint8_t modBusUartString(uint8_t *s, uint16_t Length);
 extern void receiveInterrupt(uint8_t Data);
 
 
#line 1 "Modbus\ModbusPort.c" /0
 
 
 
 <<<<<<< HEAD
 void initModbusSerial(int32_t baudrate){ 
 uint8_t SFRPAGE_save;
 uint16_t tmp;
 SFRPAGE_save = SFRPAGE;	
 SFRPAGE = ACTIVE_PAGE;
 =======
 void initModbusSerial(int32_t baudrate)
 { 
 CKCON |= (1 << 5); 
 T2CON &= ~(1 << 0); 
 T2CON &= ~(1 << 1); 
 T2CON |= (1 << 4); 
 T2CON |= (1 << 5); 
 RCAP2  = - ((long) ((uint32_t)(48000000L) / baudrate) / 32L);
 TMR2 = RCAP2;
 TR2= 1;                              
 >>>>>>> MCFCL_25MP
 SCON0 = 0x0;
 SCON0 |= (1 << 4); 
 SFRPAGE   = CONFIG_PAGE;
 tmp = (uint16_t)(65536L - ((long) ((uint32_t)(48000000L) / baudrate) / 2L));
 SBRLL0    = (tmp & 0xFF);
 SBRLH0    = (tmp >> 8) & 0xFF;
 SBCON0 = 0x0;
 SBCON0 |= 1 << 0;
 SBCON0 |= 1 << 1; 
 SBCON0 |= 1 << 6; 
 SFRPAGE = SFRPAGE_save;
 
 ES0 = 1;
 IP |= (1 << 4); 
 <<<<<<< HEAD
 }
 void initModbusTimer(void){ 
 uint16_t tmp;	
 uint8_t SFRPAGE_save;
 SFRPAGE_save = SFRPAGE;
 tmp = (uint16_t)(65536L - (int32_t)((48000000L) / 12L / CONFIG_MB_RTU_SLAVE_TIMER));
 SFRPAGE = ACTIVE_PAGE;
 TMR3CN = 0x0; 
 TMR3RLH = (uint8_t)((tmp >> 8) & 0xFF);
 TMR3RLL = (uint8_t)(tmp & 0xFF);
 TMR3CN |= (1 << 2);
 SFRPAGE = SFRPAGE_save;
 EIE1 |= (1 << 6); 
 =======
 TI0 = 0; 
 RI0 = 0; 
 }
 void initModbusTimer(void){ 
 xdata uint16_t temp;
 temp = (uint16_t)(65536 - ((48000000L) / 12 / CONFIG_MB_RTU_SLAVE_TIMER));
 Timer1_L = (uint8_t)(temp & 0xFF);
 Timer1_H = (uint8_t)((temp >> 8) & 0xFF);
 CKCON &= ~(1 << 4); 
 TMOD &= 0x0F;
 TMOD |= (1 << 4); 
 TH1 = Timer1_H;
 TL1 = Timer1_L;	
 TF1 = 0;
 TR1 = 1;        
 ET1 = 1;  
 >>>>>>> MCFCL_25MP
 }
 static void modbusSerialSendbyte(uint8_t *dt){ 
 uint8_t SFRPAGE_save;
 SFRPAGE_save = SFRPAGE;
 SFRPAGE = ACTIVE_PAGE;
 ES0 = 0;
 TI0 = 0;
 SBUF0 = *dt;
 while( !TI0 ){
 
#error *** WARNING C322 IN LINE 77 OF Modbus\ModbusPort.c: unknown identifier
#line 78 "Modbus\ModbusPort.c" /1
 
 
#line 80 "Modbus\ModbusPort.c" /0
 }
 TI0 = 0;
 ES0 = 1;
 SFRPAGE = SFRPAGE_save;
 }
 void modBusUartInitialise(uint32_t baudrate){ 
 initModbusSerial(baudrate);
 }
 void modBusTimerInitialise(void){ 
 initModbusTimer();
 }
 void modBusUartPutch(uint8_t c){ 
 modbusSerialSendbyte(&c);
 }
 uint8_t modBusUartString(uint8_t *s, uint16_t  Length){ 
 uint16_t DummyCounter;
 for(DummyCounter=0; DummyCounter < Length; DummyCounter ++){
 modBusUartPutch(s[DummyCounter]);
 }
 return true;
 }
 void receiveInterrupt(uint8_t Data){ 
 modbusReceiveBuffer[modbusReceiveCounter] = Data;
 modbusReceiveCounter ++;
 if(modbusReceiveCounter > CONFIG_MB_RTU_SLAVE_BUFFER_SIZE){  
 modbusReceiveCounter = 0;
 }
 modbusTimerValue = 0;
 }
 
 static void modbusHandle() interrupt INTERRUPT_TIMER3 { 
 
#line 112 "Modbus\ModbusPort.c" /1
 
 
#line 114 "Modbus\ModbusPort.c" /0
 
#line 115 "Modbus\ModbusPort.c" /1
 
 
 
 
 
 
#line 121 "Modbus\ModbusPort.c" /0
 modbusTimerValue ++;
 <<<<<<< HEAD
 }
 static void serialHandle() interrupt INTERRUPT_UART0 { 
 
#line 126 "Modbus\ModbusPort.c" /1
 
 
 
 
 
 
 
 
#line 134 "Modbus\ModbusPort.c" /0
 
#line 135 "Modbus\ModbusPort.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 153 "Modbus\ModbusPort.c" /0
 } 
#error *** WARNING C316 IN LINE 153 OF Modbus\ModbusPort.c: unterminated conditionals
