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
uint8_t ModbusSlaveAddress = 1;
typedef enum{
    RXTX_IDLE,
    RXTX_START,
    RXTX_DATABUF,
    RXTX_WAIT_ANSWER,
    RXTX_TIMEOUT
}RXTX_STATE;
typedef struct{
  uint8_t address;
  uint8_t function;
  uint8_t dataBuf[CONFIG_MODBUS_SLAVE_BUFFER_SIZE];
  uint16_t dataLen;
}RXTX_DATA;
/**********************Slave Transmit and Receive Variables********************/
RXTX_DATA Tx_Data;
uint32_t Tx_Current = 0;
uint32_t Tx_CRC16 = 0xFFFF;
RXTX_STATE Tx_State = RXTX_IDLE;
uint8_t Petit_Tx_Buf[CONFIG_MODBUS_SLAVE_BUFFER_SIZE];
uint32_t Tx_Buf_Size = 0;
/*****************************************************************************/
RXTX_DATA Rx_Data;
uint32_t Rx_CRC16 = 0xFFFF;
RXTX_STATE Rx_State = RXTX_IDLE;
uint8_t Rx_Data_Available = FALSE;
/*****************************************************************************/
volatile uint16_t ModbusTimerValue = 0;
volatile uint8_t ModbusReceiveBuffer[CONFIG_MODBUS_SLAVE_BUFFER_SIZE];// Buffer to collect data from hardware
volatile uint8_t ModbusReceiveCounter = 0;// Collected data number
/*****************************************************************************/
void Petit_CRC16(const uint8_t Data, uint32_t* CRC){
    data uint32_t i;
    *CRC = *CRC ^(uint32_t) Data;
    for (i = 8; i > 0; i--){
        if (*CRC & 0x0001)
            *CRC = (*CRC >> 1) ^ 0xA001;
        else
            *CRC >>= 1;
    }
}
/******************************************************************************/

/*
 * function Name        : DoTx
 * @param[out]          : TRUE
 * @How to use          : It is used for send data package over physical layer
 */
uint8_t Petit_DoSlaveTX(void)
{  
    PetitModBus_UART_String(Petit_Tx_Buf,Tx_Buf_Size);

    Tx_Buf_Size = 0;
    return TRUE;
}

/******************************************************************************/

/*
 * function Name        : SendMessage
 * @param[out]          : TRUE/FALSE
 * @How to use          : This function start to sending messages
 */
uint8_t PetitSendMessage(void)
{
    if (Tx_State != RXTX_IDLE)
        return FALSE;

    Tx_Current  =0;
    Tx_State    =RXTX_START;

    return TRUE;
}

/******************************************************************************/

/*
 * function Name        : HandleModbusError
 * @How to use          : This function generated errors to Modbus Master
 */
void HandlePetitModbusError(char ErrorCode){// Initialise the output buffer. The first byte in the buffer says how many registers we have read
    Tx_Data.function = ErrorCode | 0x80;
    Tx_Data.address = ModbusSlaveAddress;
    Tx_Data.dataLen = 0;
    PetitSendMessage();
}

void HandlePetitModbusReadHoldingRegisters(void){//Modbus function 03 - Read holding registers
    data uint16_t startAddress, numberOfRegisters, i;
    data int16_t currentData;
	// The message contains the requested start address and number of registers
    startAddress = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t) (Rx_Data.dataBuf[1]);
    numberOfRegisters = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t) (Rx_Data.dataBuf[3]);
	if((startAddress + numberOfRegisters) > CONFIG_NVRAM_SIZE){//If it is bigger than RegisterNumber return error to Modbus Master
        HandlePetitModbusError(ERROR_CODE_02);
	}
    else{//Initialise the output buffer. The first byte in the buffer says how many registers we have read
        Tx_Data.function = MODBUS_READ_HOLDING_REGISTERS;
        Tx_Data.address = ModbusSlaveAddress;
        Tx_Data.dataLen = 1;
        Tx_Data.dataBuf[0] = 0;
        for (i = 0;i < numberOfRegisters;i ++){
            currentData = NVRAM0[startAddress + i];
            Tx_Data.dataBuf[Tx_Data.dataLen] = (uint8_t) ((currentData & 0xFF00) >> 8);
            Tx_Data.dataBuf[Tx_Data.dataLen + 1] = (uint8_t) (currentData & 0xFF);
            Tx_Data.dataLen += 2;
            Tx_Data.dataBuf[0] = Tx_Data.dataLen - 1;
        }
        PetitSendMessage();
    }
}

void HandlePetitModbusWriteSingleRegister(void){//Modbus function 06 - Write single register
    data uint16_t address, value,i;
    // The message contains the requested start address and number of registers
    address = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t)(Rx_Data.dataBuf[1]);
    value = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t)(Rx_Data.dataBuf[3]);
    // Initialise the output buffer. The first byte in the buffer says how many registers we have read
    Tx_Data.function = MODBUS_WRITE_SINGLE_REGISTER;
    Tx_Data.address = ModbusSlaveAddress;
    Tx_Data.dataLen = 4;
    if(address >= CONFIG_NVRAM_SIZE){
        HandlePetitModbusError(ERROR_CODE_03);
	}
    else{
        NVRAM0[address] = value;
        // Output data buffer is exact copy of input buffer
        for (i = 0; i < 4; ++i){
            Tx_Data.dataBuf[i] = Rx_Data.dataBuf[i];
		}
    }
    PetitSendMessage();
}
void HandleMPetitodbusWriteMultipleRegisters(void){//Modbus function 16 - Write multiple registers
    // Write single numerical output
    data uint16_t startAddress, numberOfRegisters, value;
    data uint8_t byteCount , i;
    // The message contains the requested start address and number of registers
    startAddress = ((uint16_t)(Rx_Data.dataBuf[0]) << 8) + (uint16_t)(Rx_Data.dataBuf[1]);
    numberOfRegisters = ((uint16_t)(Rx_Data.dataBuf[2]) << 8) + (uint16_t)(Rx_Data.dataBuf[3]);
    byteCount = Rx_Data.dataBuf[4];
    // If it is bigger than RegisterNumber return error to Modbus Master
    if((startAddress+numberOfRegisters) > CONFIG_NVRAM_SIZE){
        HandlePetitModbusError(ERROR_CODE_03);
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
            value = (uint16_t)(Rx_Data.dataBuf[5 + 2 * i] << 8) + (uint16_t)(Rx_Data.dataBuf[6 + 2 * i]);
            NVRAM0[startAddress + i] = (int16_t)value;
        }
        PetitSendMessage();
    }
}


/******************************************************************************/

/*
 * function Name        : RxDataAvailable
 * @return              : If Data is Ready, Return TRUE
 *                        If Data is not Ready, Return FALSE
 */
uint8_t Petit_RxDataAvailable(void)
{
    uint8_t Result    = Rx_Data_Available;
    
    Rx_Data_Available       = FALSE;

    return Result;
}

/******************************************************************************/

/*
 * function Name        : CheckRxTimeout
 * @return              : If Time is out return TRUE
 *                        If Time is not out return FALSE
 */
uint8_t Petit_CheckRxTimeout(void)
{
    // A return value of true indicates there is a timeout    
    if (ModbusTimerValue >= PETITMODBUS_TIMEOUTTIMER)
    {
        ModbusTimerValue   =0;
        ModbusReceiveCounter     =0;
        return TRUE;
    }

    return FALSE;
}

/******************************************************************************/

/*
 * function Name        : CheckBufferComplete
 * @return              : If data is ready, return              DATA_READY
 *                        If slave address is wrong, return     FALSE_SLAVE_ADDRESS
 *                        If data is not ready, return          DATA_NOT_READY
 *                        If functions is wrong, return         FALSE_FUNCTION
 */
uint8_t CheckPetitModbusBufferComplete(void)
{
    int PetitExpectedReceiveCount=0;

    if(ModbusReceiveCounter>4)
    {
        if(ModbusReceiveBuffer[0]==ModbusSlaveAddress)
        {
            if(ModbusReceiveBuffer[1]==0x01 || ModbusReceiveBuffer[1]==0x02 || ModbusReceiveBuffer[1]==0x03 || ModbusReceiveBuffer[1]==0x04 || ModbusReceiveBuffer[1]==0x05 || ModbusReceiveBuffer[1]==0x06)  // RHR
            {
                PetitExpectedReceiveCount    =8;
            }
            else if(ModbusReceiveBuffer[1]==0x0F || ModbusReceiveBuffer[1]==0x10)
            {
                PetitExpectedReceiveCount=ModbusReceiveBuffer[6]+9;
            }
            else
            {
                ModbusReceiveCounter=0;
                return FALSE_FUNCTION;
            }
        }
        else
        {
            ModbusReceiveCounter=0;
            return FALSE_SLAVE_ADDRESS;
        }
    }
    else
        return DATA_NOT_READY;

    if(ModbusReceiveCounter==PetitExpectedReceiveCount)
    {
        return DATA_READY;
    }

    return DATA_NOT_READY;
}

/******************************************************************************/

/*
 * function Name        : RxRTU
 * @How to use          : Check for data ready, if it is good return answer
 */
void Petit_RxRTU(void)
{
    uint8_t   i;
    uint8_t   Petit_ReceiveBufferControl=0;

    Petit_ReceiveBufferControl    =CheckPetitModbusBufferComplete();

    if(Petit_ReceiveBufferControl==DATA_READY)
    {
        Rx_Data.address               =ModbusReceiveBuffer[0];
        Rx_CRC16                      = 0xffff;
        Petit_CRC16(Rx_Data.address, &Rx_CRC16);
        Rx_Data.function              =ModbusReceiveBuffer[1];
        Petit_CRC16(Rx_Data.function, &Rx_CRC16);

        Rx_Data.dataLen=0;

        for(i=2;i<ModbusReceiveCounter;i++)
            Rx_Data.dataBuf[Rx_Data.dataLen++]=ModbusReceiveBuffer[i];

        Rx_State =RXTX_DATABUF;

        ModbusReceiveCounter=0;
    }

    Petit_CheckRxTimeout();

    if ((Rx_State == RXTX_DATABUF) && (Rx_Data.dataLen >= 2))
    {
        // Finish off our CRC check
        Rx_Data.dataLen -= 2;
        for (i = 0; i < Rx_Data.dataLen; ++i)
        {
            Petit_CRC16(Rx_Data.dataBuf[i], &Rx_CRC16);
        }
        
        if (((uint32_t) Rx_Data.dataBuf[Rx_Data.dataLen] + ((uint32_t) Rx_Data.dataBuf[Rx_Data.dataLen + 1] << 8)) == Rx_CRC16)
        {
            // Valid message!
            Rx_Data_Available = TRUE;
        }

        Rx_State = RXTX_IDLE;
    }
}

/******************************************************************************/

/*
 * function Name        : TxRTU
 * @How to use          : If it is ready send answers!
 */
void Petit_TxRTU(void)
{
    Tx_CRC16                =0xFFFF;
    Tx_Buf_Size             =0;
    Petit_Tx_Buf[Tx_Buf_Size++]   =Tx_Data.address;
    Petit_CRC16(Tx_Data.address, &Tx_CRC16);
    Petit_Tx_Buf[Tx_Buf_Size++]   =Tx_Data.function;
    Petit_CRC16(Tx_Data.function, &Tx_CRC16);

    for(Tx_Current=0; Tx_Current < Tx_Data.dataLen; Tx_Current++)
    {
        Petit_Tx_Buf[Tx_Buf_Size++]=Tx_Data.dataBuf[Tx_Current];
        Petit_CRC16(Tx_Data.dataBuf[Tx_Current], &Tx_CRC16);
    }
    
    Petit_Tx_Buf[Tx_Buf_Size++] = Tx_CRC16 & 0x00FF;
    Petit_Tx_Buf[Tx_Buf_Size++] =(Tx_CRC16 & 0xFF00) >> 8;

    Petit_DoSlaveTX();

    Tx_State    =RXTX_IDLE;
}

/******************************************************************************/

/*
 * function Name        : ProcessModbus
 * @How to use          : ModBus main core! Call this function into main!
 */
void ProcessPetitModbus(void)
{
    if (Tx_State != RXTX_IDLE)                                      // If answer is ready, send it!
        Petit_TxRTU();

    Petit_RxRTU();                                                              // Call this function every cycle

    if (Petit_RxDataAvailable())                                                // If data is ready enter this!
    {
        if (Rx_Data.address == ModbusSlaveAddress)                 // Is Data for us?
        {
            switch (Rx_Data.function)                                     // Data is for us but which function?
            {
                #if PETITMODBUS_READ_HOLDING_REGISTERS_ENABLED > 0
                case MODBUS_READ_HOLDING_REGISTERS:    {   HandlePetitModbusReadHoldingRegisters();        break;  }
                #endif
                #if PETITMODBUSWRITE_SINGLE_REGISTER_ENABLED > 0
                case MODBUS_WRITE_SINGLE_REGISTER:     {   HandlePetitModbusWriteSingleRegister();         break;  }
                #endif
                #if PETITMODBUS_WRITE_MULTIPLE_REGISTERS_ENABLED > 0
                case MODBUS_WRITE_MULTIPLE_REGISTERS:  {   HandleMPetitodbusWriteMultipleRegisters();      break;  }
                #endif
                default:                                    {   HandlePetitModbusError(ERROR_CODE_01);    break;  }
            }
        }
    }
}

/******************************************************************************/

/*
 * function Name        : InitPetitModbus
 * @How to use          : Petite ModBus slave initialize
 */
void InitPetitModbus(uint8_t PetitModbusSlaveAddress, unsigned long baudrate)
{
    ModbusSlaveAddress = PetitModbusSlaveAddress;
    
    PetitModBus_UART_Initialise(baudrate);
    PetitModBus_TIMER_Initialise();
}

/******************************************************************************/
