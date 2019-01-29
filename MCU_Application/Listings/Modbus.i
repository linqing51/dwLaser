
#line 1 "Modbus\Modbus.c" /0
  
#line 1 "Modbus\modbus.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
 
 
 
 
 <<<<<<< HEAD
 
 =======
 
#error *** WARNING C317 IN LINE 9 OF .\MainApp\appConfig.h: attempt to redefine macro 'CONFIG_SYSCLK'
 
#line 11 ".\MainApp\appConfig.h" /1
 
  
  
 
  
  
  
  
  
  
  
 
 
 
 
  
  
  
  
 
  
  
  
  
 
 
  
  
  
  
  
 
  
 
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
  
 
 
 
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
 
  
 
  
 
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
 
 
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
  
 
  
 
  
 
 
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
 
 
  
  
 
  
 
  
 
  
  
  
  
  
 
 
 
#line 4 "Modbus\modbus.h" /0
#line 4 "Modbus\modbus.h" /0
 
 
 extern idata volatile uint16_t modbusTimerValue;
 extern idata volatile uint8_t modbusReceiveCounter; 
 extern xdata volatile uint8_t modbusReceiveBuffer[CONFIG_MB_RTU_SLAVE_BUFFER_SIZE];
 
 extern void initModbus(uint8_t modbusSlaveAddress, uint32_t bd);
 extern void modbusPorcess(void);
 
#line 1 "Modbus\Modbus.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef enum{
 RXTX_IDLE,
 RXTX_START,
 RXTX_DATABUF,
 RXTX_WAIT_ANSWER,
 RXTX_TIMEOUT
 }MODBUS_RXTX_STATE;
 typedef struct{
 uint8_t address;
 uint8_t function;
 uint8_t dataBuf[CONFIG_MB_RTU_SLAVE_BUFFER_SIZE];
 uint16_t dataLen;
 }modbusRxTxData_t;
 
 idata uint8_t ModbusSlaveAddress = 1;
 xdata modbusRxTxData_t Tx_Data;
 idata uint32_t Tx_Current = 0;
 idata uint32_t Tx_CRC16 = 0xFFFF;
 idata MODBUS_RXTX_STATE Tx_State = RXTX_IDLE;
 xdata uint8_t Tx_Buf[CONFIG_MB_RTU_SLAVE_BUFFER_SIZE];
 idata uint32_t Tx_Buf_Size = 0;
 
 xdata modbusRxTxData_t Rx_Data;
 idata uint32_t Rx_CRC16 = 0xFFFF;
 idata MODBUS_RXTX_STATE Rx_State = RXTX_IDLE;
 idata uint8_t Rx_Data_Available = false;
 
 idata volatile uint16_t modbusTimerValue = 0;
 idata volatile uint8_t modbusReceiveCounter = 0; 
 xdata volatile uint8_t modbusReceiveBuffer[CONFIG_MB_RTU_SLAVE_BUFFER_SIZE]; 
 
 void modbusCrc16(const uint8_t Data, uint32_t* CRC){
 idata uint32_t i;
 *CRC = *CRC ^(uint32_t) Data;
 for (i = 8; i > 0; i--){
 if (*CRC & 0x0001)
 *CRC = (*CRC >> 1) ^ 0xA001;
 else
 *CRC >>= 1;
 }
 }
 uint8_t DoSlaveTX(void){ 
 modBusUartString(Tx_Buf, Tx_Buf_Size);
 Tx_Buf_Size = 0;
 return true;
 }
 uint8_t SendMessage(void){ 
 if (Tx_State != RXTX_IDLE){
 return false;
 }
 Tx_Current  =0;
 Tx_State    =RXTX_START;
 return true;
 }
 void HandleModbusError(char ErrorCode){ 
 setLedError(0);
 Tx_Data.function = ErrorCode | 0x80;
 Tx_Data.address = ModbusSlaveAddress;
 Tx_Data.dataLen = 0; 
 SendMessage();
 setLedError(1);
 }
 
 void HandleModbusReadCoils(void){ 
 idata uint16_t startAddress, numberOfCoil, byteCount, tempAddr, i, j;
 idata uint8_t tempData = 0;
 
 startAddress = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t) (Rx_Data.dataBuf[1]);
 numberOfCoil = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t) (Rx_Data.dataBuf[3]);
 if((startAddress + numberOfCoil) > (CONFIG_NVRAM_SIZE * 16)){ 
 HandleModbusError(0x02);
 }
 else{
 byteCount = numberOfCoil / 8;
 if((numberOfCoil % 8) != 0){
 byteCount += 1;
 }
 Tx_Data.function = 1;
 Tx_Data.address = ModbusSlaveAddress;
 Tx_Data.dataLen = 1;
 tempAddr = startAddress;
 for(i = 0; i < byteCount; i ++){
 Tx_Data.dataBuf[Tx_Data.dataLen] = 0;
 for(j = 0; j < 8; j ++){
 tempData = (NVRAM0[(tempAddr / 16)] >> (tempAddr % 16)) & 0x01;
 Tx_Data.dataBuf[Tx_Data.dataLen] |= (uint8_t)(tempData << j);
 tempAddr++;	
 
 
 
 
 }
 Tx_Data.dataLen ++;	
 }
 Tx_Data.dataBuf[0] = Tx_Data.dataLen - 1;
 SendMessage();
 }
 }
 void HandleModbusReadInputCoil(void){ 
 }
 void HandleModbusReadHoldingRegisters(void){ 
 idata uint16_t startAddress, numberOfRegisters, i, currentData;
 
 startAddress = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t) (Rx_Data.dataBuf[1]);
 numberOfRegisters = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t) (Rx_Data.dataBuf[3]);
 if((startAddress + numberOfRegisters) > CONFIG_NVRAM_SIZE){ 
 HandleModbusError(0x02);
 }
 else{ 
 Tx_Data.function = 3;
 Tx_Data.address = ModbusSlaveAddress;
 Tx_Data.dataLen = 1;
 Tx_Data.dataBuf[0] = 0;
 for (i = 0;i < numberOfRegisters;i ++){
 currentData = (uint16_t)NVRAM0[startAddress + i];
 Tx_Data.dataBuf[Tx_Data.dataLen] = (uint8_t)((currentData & 0xFF00) >> 8);
 Tx_Data.dataBuf[Tx_Data.dataLen + 1] = (uint8_t)(currentData & 0x00FF);
 Tx_Data.dataLen += 2;
 Tx_Data.dataBuf[0] = Tx_Data.dataLen - 1;
 }
 SendMessage();
 }
 }
 void HandleModbusWriteSingleCoil(void){ 
 idata uint16_t startAddress, value;
 
 startAddress = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t) (Rx_Data.dataBuf[1]);
 value = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t)(Rx_Data.dataBuf[3]);
 if((startAddress) > (CONFIG_NVRAM_SIZE * 16)){ 
 HandleModbusError(0x02);
 }
 else{
 Tx_Data.function = 5;
 Tx_Data.address = ModbusSlaveAddress;
 Tx_Data.dataLen = 4;
 Tx_Data.dataBuf[0] = Rx_Data.dataBuf[0];
 Tx_Data.dataBuf[1] = Rx_Data.dataBuf[1];
 if(value == 0x0000){ 
 NVRAM0[(startAddress / 16)] &= ~((uint16_t)(1 << (startAddress % 16)));
 Tx_Data.dataBuf[2] = 0x00;
 Tx_Data.dataBuf[3] = 0x00;
 }
 else if(value == 0xFF00){ 
 NVRAM0[(startAddress / 16)] |= (uint16_t)(1 << (startAddress % 16));
 Tx_Data.dataBuf[2] = 0xFF;
 Tx_Data.dataBuf[3] = 0x00;
 }
 else{		
 }
 SendMessage();
 }
 }
 void HandleModbusWriteSingleRegister(void){ 
 idata uint16_t address, value,i;
 
 address = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t)(Rx_Data.dataBuf[1]);
 value = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t)(Rx_Data.dataBuf[3]);
 
 Tx_Data.function = 6;
 Tx_Data.address = ModbusSlaveAddress;
 Tx_Data.dataLen = 4;
 if(address >= CONFIG_NVRAM_SIZE){
 HandleModbusError(0x03);
 }
 else{
 NVRAM0[address] = (int16_t)value;
 for (i = 0; i < 4; ++i){
 Tx_Data.dataBuf[i] = Rx_Data.dataBuf[i];
 }
 }
 SendMessage();
 }
 void HandleModbusWriteMultipleCoils(void){ 
 idata uint16_t startAddress, numberOfCoil, byteCount, tempAddr, i, j;
 idata uint8_t tempData = 0;
 
 startAddress = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t) (Rx_Data.dataBuf[1]);
 numberOfCoil = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t) (Rx_Data.dataBuf[3]);
 if((startAddress + numberOfCoil) > (CONFIG_NVRAM_SIZE * 16)){ 
 HandleModbusError(0x02);
 }
 else{
 byteCount = numberOfCoil / 8;
 if((numberOfCoil % 8) != 0){
 byteCount += 1;
 }
 Tx_Data.function = 15;
 Tx_Data.address = ModbusSlaveAddress;
 Tx_Data.dataLen = 4;
 Tx_Data.dataBuf[0] = Rx_Data.dataBuf[0];
 Tx_Data.dataBuf[1] = Rx_Data.dataBuf[1];
 Tx_Data.dataBuf[2] = Rx_Data.dataBuf[2];
 Tx_Data.dataBuf[3] = Rx_Data.dataBuf[3];
 tempAddr = startAddress;
 for(i = 0;i < byteCount;i ++){
 for(j = 0;j < 8;j ++){
 tempData = (uint8_t)((Rx_Data.dataBuf[(5 + i)] >> j) & 0x01);
 if(tempData){ 
 NVRAM0[(tempAddr / 16)] |= (uint16_t)(1 << (tempAddr % 16));
 }
 else{ 
 NVRAM0[(tempAddr / 16)] &= ~((uint16_t)(1 << (tempAddr % 16)));
 }
 tempAddr ++;
 numberOfCoil --;
 if(numberOfCoil == 0){
 break;
 }
 }
 
 }
 SendMessage();
 }
 }
 void HandleModbusWriteMultipleRegisters(void){ 
 
 idata uint16_t startAddress, numberOfRegisters, value;
 idata uint8_t byteCount , i;
 
 startAddress = ((uint16_t)(Rx_Data.dataBuf[0]) << 8) + (uint16_t)(Rx_Data.dataBuf[1]);
 numberOfRegisters = ((uint16_t)(Rx_Data.dataBuf[2]) << 8) + (uint16_t)(Rx_Data.dataBuf[3]);
 byteCount = Rx_Data.dataBuf[4];
 
 if((startAddress+numberOfRegisters) > CONFIG_NVRAM_SIZE){
 HandleModbusError(0x03);
 }
 else{
 
 Tx_Data.function = 16;
 Tx_Data.address = ModbusSlaveAddress;
 Tx_Data.dataLen = 4;
 Tx_Data.dataBuf[0] = Rx_Data.dataBuf[0];
 Tx_Data.dataBuf[1] = Rx_Data.dataBuf[1];
 Tx_Data.dataBuf[2] = Rx_Data.dataBuf[2];
 Tx_Data.dataBuf[3] = Rx_Data.dataBuf[3];
 
 for (i = 0;i < numberOfRegisters;i ++){
 value = (uint16_t)((Rx_Data.dataBuf[5 + 2 * i] << 8) & 0xFF00) + (uint16_t)((Rx_Data.dataBuf[6 + 2 * i]) & 0x00FF);
 NVRAM0[startAddress + i] = (int16_t)value;
 }
 SendMessage();
 }
 }
 uint8_t RxDataAvailable(void){ 
 idata uint8_t Result = Rx_Data_Available;   
 Rx_Data_Available = false;
 return Result;
 }
 uint8_t CheckRxTimeout(void){ 
 
 if (modbusTimerValue >= CONFIG_MB_RTU_SLAVE_BUFFER_SIZE){
 modbusTimerValue = 0;
 modbusReceiveCounter = 0;
 return true;
 }
 return false;
 }
 uint8_t checkModbusBufferComplete(void){ 
 idata int32_t expectedReceiveCount=0;
 if(modbusReceiveCounter > 4)
 {
 if(modbusReceiveBuffer[0] == ModbusSlaveAddress)
 {
 if(modbusReceiveBuffer[1]==0x01 || modbusReceiveBuffer[1]==0x02 || modbusReceiveBuffer[1]==0x03 || modbusReceiveBuffer[1]==0x04 || modbusReceiveBuffer[1]==0x05 || modbusReceiveBuffer[1]==0x06)   
 {
 expectedReceiveCount = 8;
 }
 else if(modbusReceiveBuffer[1] == 0x0F || modbusReceiveBuffer[1] == 0x10)
 {
 expectedReceiveCount=modbusReceiveBuffer[6] + 9;
 }
 else{
 modbusReceiveCounter = 0;
 return 0;
 }
 }
 else
 {
 modbusReceiveCounter=0;
 return 1;
 }
 }
 else
 return 2;
 
 if(modbusReceiveCounter==expectedReceiveCount)
 {
 return 3;
 }
 
 return 2;
 }
 void RxRTU(void){ 
 idata uint8_t i;
 idata uint8_t receiveBufferControl=0;
 receiveBufferControl = checkModbusBufferComplete();
 if(receiveBufferControl == 3){
 Rx_Data.address               =modbusReceiveBuffer[0];
 Rx_CRC16                      = 0xffff;
 modbusCrc16(Rx_Data.address, &Rx_CRC16);
 Rx_Data.function              =modbusReceiveBuffer[1];
 modbusCrc16(Rx_Data.function, &Rx_CRC16);
 
 Rx_Data.dataLen=0;
 
 for(i=2;i<modbusReceiveCounter;i++)
 Rx_Data.dataBuf[Rx_Data.dataLen++]=modbusReceiveBuffer[i];
 
 Rx_State =RXTX_DATABUF;
 
 modbusReceiveCounter=0;
 }
 
 CheckRxTimeout();
 
 if ((Rx_State == RXTX_DATABUF) && (Rx_Data.dataLen >= 2))
 {
 
 Rx_Data.dataLen -= 2;
 for (i = 0; i < Rx_Data.dataLen; ++i)
 {
 modbusCrc16(Rx_Data.dataBuf[i], &Rx_CRC16);
 }
 
 if (((uint32_t) Rx_Data.dataBuf[Rx_Data.dataLen] + ((uint32_t) Rx_Data.dataBuf[Rx_Data.dataLen + 1] << 8)) == Rx_CRC16)
 {
 
 Rx_Data_Available = true;
 }
 
 Rx_State = RXTX_IDLE;
 }
 }
 void TxRTU(void){ 
 Tx_CRC16 = 0xFFFF;
 Tx_Buf_Size = 0;
 Tx_Buf[Tx_Buf_Size++] = Tx_Data.address;
 modbusCrc16(Tx_Data.address, &Tx_CRC16);
 Tx_Buf[Tx_Buf_Size++] = Tx_Data.function;
 modbusCrc16(Tx_Data.function, &Tx_CRC16);
 for(Tx_Current=0; Tx_Current < Tx_Data.dataLen; Tx_Current++){
 Tx_Buf[Tx_Buf_Size++] = Tx_Data.dataBuf[Tx_Current];
 modbusCrc16(Tx_Data.dataBuf[Tx_Current], &Tx_CRC16);
 }
 Tx_Buf[Tx_Buf_Size++] = Tx_CRC16 & 0x00FF;
 Tx_Buf[Tx_Buf_Size++] = (Tx_CRC16 & 0xFF00) >> 8;
 DoSlaveTX();
 Tx_State = RXTX_IDLE;
 }
 void modbusPorcess(void){ 
 if (Tx_State != RXTX_IDLE){                                       
 TxRTU();
 }
 RxRTU();                                                               
 if (RxDataAvailable()){
 if (Rx_Data.address == ModbusSlaveAddress){
 switch (Rx_Data.function)                                      
 {
 case 1:{ 
 HandleModbusReadCoils();
 break;
 }
 case 3:{ 
 HandleModbusReadHoldingRegisters();
 break;  
 }
 case 5:{ 
 HandleModbusWriteSingleCoil();
 break;
 }
 case 6:{ 
 HandleModbusWriteSingleRegister();
 break;
 }
 case 15:{ 
 HandleModbusWriteMultipleCoils();
 break;
 }
 case 16:{ 
 HandleModbusWriteMultipleRegisters();
 break;
 }
 default:{
 HandleModbusError(0x01);
 break;
 }
 }
 }
 }
 }
 void InitModbus(uint8_t modbusSlaveAddress, uint32_t baudrate){ 
 ModbusSlaveAddress = modbusSlaveAddress;
 modBusUartInitialise(baudrate);
 modBusTimerInitialise();
 }
#error *** WARNING C316 IN LINE 414 OF Modbus\Modbus.c: unterminated conditionals
