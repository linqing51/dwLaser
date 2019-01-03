#include "modbus.h"
/*******************************ModBus Functions*******************************/
#define MODBUS_READ_COILS                  				1
#define MODBUS_READ_DISCRETE_INPUTS        				2
#define MODBUS_READ_HOLDING_REGISTERS      				3
#define MODBUS_READ_INPUT_REGISTERS        				4
#define MODBUS_WRITE_SINGLE_COIL           				5
#define MODBUS_WRITE_SINGLE_REGISTER       				6
#define MODBUS_WRITE_MULTIPLE_COILS        				15
#define MODBUS_WRITE_MULTIPLE_REGISTERS    				16
/****************************End of ModBus Functions***************************/
#define FALSE_FUNCTION                    				0
#define FALSE_SLAVE_ADDRESS               				1
#define DATA_NOT_READY                    				2
#define DATA_READY                        				3
#define ERROR_CODE_01                     				0x01// function code is not supported
#define ERROR_CODE_02                     				0x02// Register address is not allowed or write-protected
#define ERROR_CODE_03                     				0x03//Some data values are out of range, invalid number of register
/*****************************************************************************/
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
/**********************Slave Transmit and Receive Variables********************/
data uint8_t ModbusSlaveAddress = 1;
xdata modbusRxTxData_t Tx_Data;
data uint32_t Tx_Current = 0;
data uint32_t Tx_CRC16 = 0xFFFF;
data MODBUS_RXTX_STATE Tx_State = RXTX_IDLE;
xdata uint8_t Tx_Buf[CONFIG_MB_RTU_SLAVE_BUFFER_SIZE];
data uint32_t Tx_Buf_Size = 0;
/*****************************************************************************/
xdata modbusRxTxData_t Rx_Data;
data uint32_t Rx_CRC16 = 0xFFFF;
data MODBUS_RXTX_STATE Rx_State = RXTX_IDLE;
data uint8_t Rx_Data_Available = false;
/*****************************************************************************/
volatile uint16_t modbusTimerValue = 0;
volatile uint8_t modbusReceiveCounter = 0;// Collected data number
xdata volatile uint8_t modbusReceiveBuffer[CONFIG_MB_RTU_SLAVE_BUFFER_SIZE];// Buffer to collect data from hardware
/*****************************************************************************/
void modbusCrc16(const uint8_t Data, uint32_t* CRC){
    data uint32_t i;
    *CRC = *CRC ^(uint32_t) Data;
    for (i = 8; i > 0; i--){
        if (*CRC & 0x0001)
            *CRC = (*CRC >> 1) ^ 0xA001;
        else
            *CRC >>= 1;
    }
}
uint8_t DoSlaveTX(void){//It is used for send data package over physical layer
    modBusUartString(Tx_Buf, Tx_Buf_Size);
    Tx_Buf_Size = 0;
    return true;
}
uint8_t SendMessage(void){//This function start to sending messages
    if (Tx_State != RXTX_IDLE){
        return false;
	}
    Tx_Current  =0;
    Tx_State    =RXTX_START;
    return true;
}
void HandleModbusError(char ErrorCode){// Initialise the output buffer. The first byte in the buffer says how many registers we have read
    Tx_Data.function = ErrorCode | 0x80;
    Tx_Data.address = ModbusSlaveAddress;
    Tx_Data.dataLen = 0;
    SendMessage();
}

void HandleModbusReadCoils(void){//Modbus function 01 - 读取线圈状态
	uint16_t startAddress, numberOfCoil, byteCount, tempAddr, i, j;
	uint8_t tempData = 0;
	// The message contains the requested start address and number of registers
    startAddress = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t) (Rx_Data.dataBuf[1]);
    numberOfCoil = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t) (Rx_Data.dataBuf[3]);
	if((startAddress + numberOfCoil) > (CONFIG_NVRAM_SIZE * 16)){//If it is bigger than RegisterNumber return error to Modbus Master
        HandleModbusError(ERROR_CODE_02);
	}
	else{
		byteCount = numberOfCoil / 8;
		if((numberOfCoil % 8) != 0){
			byteCount += 1;
		}
		Tx_Data.function = MODBUS_READ_COILS;
		Tx_Data.address = ModbusSlaveAddress;
		Tx_Data.dataLen = 1;
		tempAddr = startAddress;
		for(i = 0; i < byteCount; i ++){
			Tx_Data.dataBuf[Tx_Data.dataLen] = 0;
			for(j = 0; j < 8; j ++){
				tempData = (NVRAM0[(tempAddr / 16)] >> (tempAddr % 16)) & 0x01;
				Tx_Data.dataBuf[Tx_Data.dataLen] |= (uint8_t)(tempData << j);
				tempAddr++;	
				//if(tempAddr >= startAddress + numberOfCoil){//读完
				//	exit = 1;
				//	break;
				//} 
			}
			Tx_Data.dataLen ++;	
		}
		Tx_Data.dataBuf[0] = Tx_Data.dataLen - 1;
		SendMessage();
	}
}
void HandleModbusReadInputCoil(void){//Modbus function 02 - 读取输入线圈状态
}
void HandleModbusReadHoldingRegisters(void){//Modbus function 03 - Read holding registers
    uint16_t startAddress, numberOfRegisters, i, currentData;
	// The message contains the requested start address and number of registers
    startAddress = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t) (Rx_Data.dataBuf[1]);
    numberOfRegisters = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t) (Rx_Data.dataBuf[3]);
	if((startAddress + numberOfRegisters) > CONFIG_NVRAM_SIZE){//If it is bigger than RegisterNumber return error to Modbus Master
        HandleModbusError(ERROR_CODE_02);
	}
    else{//Initialise the output buffer. The first byte in the buffer says how many registers we have read
        Tx_Data.function = MODBUS_READ_HOLDING_REGISTERS;
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
void HandleModbusWriteSingleCoil(void){//Modbus function 05 -强置单线圈
	uint16_t startAddress, value;
	// The message contains the requested start address and number of registers
    startAddress = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t) (Rx_Data.dataBuf[1]);
	value = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t)(Rx_Data.dataBuf[3]);
	if((startAddress) > (CONFIG_NVRAM_SIZE * 16)){//If it is bigger than RegisterNumber return error to Modbus Master
        HandleModbusError(ERROR_CODE_02);
	}
	else{
		Tx_Data.function = MODBUS_WRITE_SINGLE_COIL;
		Tx_Data.address = ModbusSlaveAddress;
		Tx_Data.dataLen = 4;
		Tx_Data.dataBuf[0] = Rx_Data.dataBuf[0];
		Tx_Data.dataBuf[1] = Rx_Data.dataBuf[1];
		if(value == 0x0000){//0
			NVRAM0[(startAddress / 16)] &= ~((uint16_t)(1 << (startAddress % 16)));
			Tx_Data.dataBuf[2] = 0x00;
			Tx_Data.dataBuf[3] = 0x00;
		}
		else if(value == 0xFF00){//1
			NVRAM0[(startAddress / 16)] |= (uint16_t)(1 << (startAddress % 16));
			Tx_Data.dataBuf[2] = 0xFF;
			Tx_Data.dataBuf[3] = 0x00;
		}
		else{		
		}
		SendMessage();
	}
}
void HandleModbusWriteSingleRegister(void){//Modbus function 06 - Write single register
    uint16_t address, value,i;
    // The message contains the requested start address and number of registers
    address = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t)(Rx_Data.dataBuf[1]);
    value = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t)(Rx_Data.dataBuf[3]);
    // Initialise the output buffer. The first byte in the buffer says how many registers we have read
    Tx_Data.function = MODBUS_WRITE_SINGLE_REGISTER;
    Tx_Data.address = ModbusSlaveAddress;
    Tx_Data.dataLen = 4;
    if(address >= CONFIG_NVRAM_SIZE){
        HandleModbusError(ERROR_CODE_03);
	}
    else{
		NVRAM0[address] = (int16_t)value;
        // Output data buffer is exact copy of input buffer
        for (i = 0; i < 4; ++i){
            Tx_Data.dataBuf[i] = Rx_Data.dataBuf[i];
		}
    }
    SendMessage();
}
void HandleModbusWriteMultipleCoils(void){//Modbus function 15 - Write multiple coils
	uint16_t startAddress, numberOfCoil, byteCount, tempAddr, i, j;
	uint8_t tempData = 0;
	// The message contains the requested start address and number of registers
    startAddress = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t) (Rx_Data.dataBuf[1]);
    numberOfCoil = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t) (Rx_Data.dataBuf[3]);
	if((startAddress + numberOfCoil) > (CONFIG_NVRAM_SIZE * 16)){//If it is bigger than RegisterNumber return error to Modbus Master
        HandleModbusError(ERROR_CODE_02);
	}
	else{
		byteCount = numberOfCoil / 8;
		if((numberOfCoil % 8) != 0){
			byteCount += 1;
		}
		Tx_Data.function = MODBUS_WRITE_MULTIPLE_COILS;
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
				if(tempData){//ON
					NVRAM0[(tempAddr / 16)] |= (uint16_t)(1 << (tempAddr % 16));
				}
				else{//OFF
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
void HandleModbusWriteMultipleRegisters(void){//Modbus function 16 - Write multiple registers
    // Write single numerical output
    data uint16_t startAddress, numberOfRegisters, value;
    data uint8_t byteCount , i;
    // The message contains the requested start address and number of registers
    startAddress = ((uint16_t)(Rx_Data.dataBuf[0]) << 8) + (uint16_t)(Rx_Data.dataBuf[1]);
    numberOfRegisters = ((uint16_t)(Rx_Data.dataBuf[2]) << 8) + (uint16_t)(Rx_Data.dataBuf[3]);
    byteCount = Rx_Data.dataBuf[4];
    // If it is bigger than RegisterNumber return error to Modbus Master
    if((startAddress+numberOfRegisters) > CONFIG_NVRAM_SIZE){
        HandleModbusError(ERROR_CODE_03);
	}
    else{
        // Initialise the output buffer. The first byte in the buffer says how many outputs we have set
        Tx_Data.function = MODBUS_WRITE_MULTIPLE_REGISTERS;
        Tx_Data.address = ModbusSlaveAddress;
        Tx_Data.dataLen = 4;
        Tx_Data.dataBuf[0] = Rx_Data.dataBuf[0];
        Tx_Data.dataBuf[1] = Rx_Data.dataBuf[1];
        Tx_Data.dataBuf[2] = Rx_Data.dataBuf[2];
        Tx_Data.dataBuf[3] = Rx_Data.dataBuf[3];
        // Output data buffer is exact copy of input buffer
        for (i = 0;i < numberOfRegisters;i ++){
            value = (uint16_t)((Rx_Data.dataBuf[5 + 2 * i] << 8) & 0xFF00) + (uint16_t)((Rx_Data.dataBuf[6 + 2 * i]) & 0x00FF);
            NVRAM0[startAddress + i] = (int16_t)value;
        }
        SendMessage();
    }
}
uint8_t RxDataAvailable(void){//RxDataAvailable
    uint8_t Result = Rx_Data_Available;   
    Rx_Data_Available = false;
    return Result;
}
uint8_t CheckRxTimeout(void){//CheckRxTimeout
    // A return value of true indicates there is a timeout    
    if (modbusTimerValue >= CONFIG_MB_RTU_SLAVE_BUFFER_SIZE){
        modbusTimerValue = 0;
        modbusReceiveCounter = 0;
        return true;
    }
    return false;
}
uint8_t checkModbusBufferComplete(void){//CheckBufferComplete
    data int32_t expectedReceiveCount=0;
    if(modbusReceiveCounter > 4)
    {
        if(modbusReceiveBuffer[0] == ModbusSlaveAddress)
        {
            if(modbusReceiveBuffer[1]==0x01 || modbusReceiveBuffer[1]==0x02 || modbusReceiveBuffer[1]==0x03 || modbusReceiveBuffer[1]==0x04 || modbusReceiveBuffer[1]==0x05 || modbusReceiveBuffer[1]==0x06)  // RHR
            {
                expectedReceiveCount = 8;
            }
            else if(modbusReceiveBuffer[1] == 0x0F || modbusReceiveBuffer[1] == 0x10)
            {
                expectedReceiveCount=modbusReceiveBuffer[6] + 9;
            }
            else{
                modbusReceiveCounter = 0;
                return FALSE_FUNCTION;
            }
        }
        else
        {
            modbusReceiveCounter=0;
            return FALSE_SLAVE_ADDRESS;
        }
    }
    else
        return DATA_NOT_READY;

    if(modbusReceiveCounter==expectedReceiveCount)
    {
        return DATA_READY;
    }

    return DATA_NOT_READY;
}
void RxRTU(void){//Check for data ready, if it is good return answer
    uint8_t i;
    uint8_t receiveBufferControl=0;
    receiveBufferControl = checkModbusBufferComplete();
    if(receiveBufferControl == DATA_READY){
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
        // Finish off our CRC check
        Rx_Data.dataLen -= 2;
        for (i = 0; i < Rx_Data.dataLen; ++i)
        {
            modbusCrc16(Rx_Data.dataBuf[i], &Rx_CRC16);
        }
        
        if (((uint32_t) Rx_Data.dataBuf[Rx_Data.dataLen] + ((uint32_t) Rx_Data.dataBuf[Rx_Data.dataLen + 1] << 8)) == Rx_CRC16)
        {
            // Valid message!
            Rx_Data_Available = true;
        }

        Rx_State = RXTX_IDLE;
    }
}
void TxRTU(void){//If it is ready send answers!
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
void modbusPorcess(void){//ModBus main core! Call this function into main!
    if (Tx_State != RXTX_IDLE){                                      // If answer is ready, send it!
        TxRTU();
	}
    RxRTU();                                                              // Call this function every cycle
    if (RxDataAvailable()){
        if (Rx_Data.address == ModbusSlaveAddress){
            switch (Rx_Data.function)                                     // Data is for us but which function?
            {
				case MODBUS_READ_COILS:{//FUN 01
					HandleModbusReadCoils();
					break;
				}
                case MODBUS_READ_HOLDING_REGISTERS:{//FUN 03
					HandleModbusReadHoldingRegisters();
					break;  
				}
				case MODBUS_WRITE_SINGLE_COIL:{//FUN 05
					HandleModbusWriteSingleCoil();
					break;
				}
                case MODBUS_WRITE_SINGLE_REGISTER:{//FUN 06
					HandleModbusWriteSingleRegister();
					break;
				}
				case MODBUS_WRITE_MULTIPLE_COILS:{//FUN 15
					HandleModbusWriteMultipleCoils();
					break;
				}
                case MODBUS_WRITE_MULTIPLE_REGISTERS:{//FUN 16
					HandleModbusWriteMultipleRegisters();
					break;
				}
                default:{
					HandleModbusError(ERROR_CODE_01);
					break;
				}
            }
        }
    }
}
void InitModbus(uint8_t modbusSlaveAddress, uint32_t baudrate){//ModBus slave initialize
    ModbusSlaveAddress = modbusSlaveAddress;
    modBusUartInitialise(baudrate);
    modBusTimerInitialise();
}