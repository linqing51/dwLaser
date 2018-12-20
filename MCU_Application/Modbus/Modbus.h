#ifndef __PETITMODBUS__H__
#define __PETITMODBUS__H__
/*****************************************************************************/
#include "appConfig.h"
/*****************************************************************************/
#define PETITMODBUS_TIMEOUTTIMER                        250                    // Timeout Constant for Petit Modbus RTU Slave [millisecond]
#define PETITMODBUS_READ_HOLDING_REGISTERS_ENABLED      ( 1 )                   // If you want to use make it 1, or 0
#define PETITMODBUSWRITE_SINGLE_REGISTER_ENABLED        ( 1 )                   // If you want to use make it 1, or 0
#define PETITMODBUS_WRITE_MULTIPLE_REGISTERS_ENABLED    ( 1 )                   // If you want to use make it 1, or 0

/****************************Don't Touch This**********************************/
// Buffers for Petit Modbus RTU Slave
#define PETITMODBUS_RECEIVE_BUFFER_SIZE                 CONFIG_MODBUS_SLAVE_RX_BUFFER_SIZE
#define PETITMODBUS_TRANSMIT_BUFFER_SIZE               	CONFIG_MODBUS_SLAVE_TX_BUFFER_SIZE
#define PETITMODBUS_RXTX_BUFFER_SIZE                    CONFIG_MODBUS_SLAVE_RXTX_BUFFER_SIZE
/*****************************************************************************/


typedef struct{
	int16_t  ActValue;
}PetitRegStructure;

//extern PetitRegStructure    PetitRegisters[NUMBER_OF_OUTPUT_PETITREGISTERS];
extern volatile uint16_t PetitModbusTimerValue;
// Main Functions
extern void             InitPetitModbus(unsigned char PetitModbusSlaveAddress, unsigned long bd);
extern void             ProcessPetitModbus(void);

#endif
