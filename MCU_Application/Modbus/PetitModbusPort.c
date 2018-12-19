#include "appConfig.h"
#include "PetitModbus.h"
#include "PetitModbusPort.h"
// Modbus RTU Variables
volatile unsigned char   PetitReceiveBuffer[PETITMODBUS_RECEIVE_BUFFER_SIZE];   // Buffer to collect data from hardware
volatile unsigned char   PetitReceiveCounter=0;                                 // Collected data number
void InitModbusSerial(int32_t baudrate)
{//初始化MODBUS串口
	uint32_t temp;
	temp = (uint32_t)(CONFIG_SYSCLK / 32 / baudrate);
	temp = 65536 - temp;		
	T2CON &= 1 << 4;//Timer 1 overflows used for transmit clock.
	T2CON &= 1 << 5;//Timer 1 overflows used for receive clock.	
	TMOD &= 0x0F;
	TMOD |= 1 << 5;//Mode 2: 8-bit counter/timer with auto-reload
	TH1 = (uint8_t)(temp & 0xff);
	TL1 = (uint8_t)(temp & 0xff);
	TR1 = 1;
	T2CON |= 1 << 2;//Timer 2 enabled
	//RS485_DIRECTION_RXD;//接收状态
	ES0 = 1;
	TI0 = 0;//清除发送完成   		
	RI0 = 0;//清除接收完成			
}
void InitModbusTimer(void)
{//初始化MODBUS计时器 1mS TIMER2
	uint16_t temp;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 1000));
	T2CON = 0x0;//RCLK0=0,TCLK0=0
    RCAP2L = (uint8_t)(temp & 0xFF);
	RCAP2H = (uint8_t)((temp >> 8) & 0xFF);
	TF2 = 0;
	TR2 = 1;        
	ET2 = 1; //开中断T0
}
static void modbusSerialSendbyte(uint8_t *dt)
{//串口发送一个字节
	ES0 = 0;
	TI0 = 0;
	SBUF0 = *dt;
	while( !TI0 );
	TI0 = 0;
	ES0 = 1;
}
// UART Initialize for Microconrollers, yes you can use another phsycal layer!
void PetitModBus_UART_Initialise(unsigned long bd)
{
// Insert UART Init Code Here
    InitModbusSerial(bd);
}

// Timer Initialize for Petit Modbus, 1ms Timer will be good for us!
void PetitModBus_TIMER_Initialise(void)
{
// Insert TMR Init Code Here
    InitModbusTimer();
}

// This is used for send one character
void PetitModBus_UART_Putch(unsigned char c)
{
	modbusSerialSendbyte(&c);
}

// This is used for send string, better to use DMA for it ;)
unsigned char PetitModBus_UART_String(unsigned char *s, unsigned int Length)
{
    unsigned short  DummyCounter;
    
    for(DummyCounter=0;DummyCounter<Length;DummyCounter++)
        PetitModBus_UART_Putch(s[DummyCounter]);
    
    return TRUE;
}

/*************************Interrupt Fonction Slave*****************************/
// Call this function into your UART Interrupt. Collect data from it!
// Better to use DMA
void ReceiveInterrupt(unsigned char Data)
{
    PetitReceiveBuffer[PetitReceiveCounter]   =Data;
    PetitReceiveCounter++;

    if(PetitReceiveCounter>PETITMODBUS_RECEIVE_BUFFER_SIZE)  
        PetitReceiveCounter=0;

    PetitModbusTimerValue=0;
}

// Call this function into 1ms Interrupt or Event!
void PetitModBus_TimerValues(void)
{
    PetitModbusTimerValue++;
}
/******************************************************************************/
static void ModbusHandle() interrupt INTERRUPT_TIMER2
{//硬件计时器TIMER1中断函数 1mS
	TF2 = 0;
	PetitModBus_TimerValues();
} 

static void SerialHandle() interrupt INTERRUPT_UART0
{//UART0 串口中断程序
	uint8_t ctemp;
	if(RI0)
	{
		RI0 = 0;
		ctemp = SBUF0;		
		ReceiveInterrupt(ctemp);
		if(RI0)
		{
			RI0 = 0;
		}
	}
	if(TI0)
	{
		TI0 = 0;
		//modbusSerialTxHandle();
	}
} 