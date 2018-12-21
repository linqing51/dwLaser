#include "modbusPort.h"
/*****************************************************************************/
volatile uint16_t modbusTimerValue;
extern volatile uint8_t modbusReceiveCounter;
volatile uint8_t modbusReceiveBuffer[];
/*****************************************************************************/
void initModbusSerial(int32_t baudrate)
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
void initModbusTimer(void){//初始化MODBUS计时器 1mS TIMER2
	uint16_t temp;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 1000));
	T2CON = 0x0;//RCLK0=0,TCLK0=0
    RCAP2L = (uint8_t)(temp & 0xFF);
	RCAP2H = (uint8_t)((temp >> 8) & 0xFF);
	TF2 = 0;
	TR2 = 1;        
	ET2 = 1; //开中断T0
}
static void modbusSerialSendbyte(uint8_t *dt){//串口发送一个字节
	ES0 = 0;
	TI0 = 0;
	SBUF0 = *dt;
	while( !TI0 );
	TI0 = 0;
	ES0 = 1;
}
void modBusUartInitialise(uint32_t baudrate){// UART Initialize for Microconrollers, yes you can use another phsycal layer!
    initModbusSerial(baudrate);
}
void modBusTimerInitialise(void){// Timer Initialize for Petit Modbus, 1ms Timer will be good for us!
    initModbusTimer();
}
void modBusUartPutch(uint8_t c){// This is used for send one character
	modbusSerialSendbyte(&c);
}
uint8_t modBusUartString(uint8_t *s, uint16_t  Length){// This is used for send string, better to use DMA for it ;)
    uint16_t DummyCounter;
    for(DummyCounter=0; DummyCounter < Length; DummyCounter ++){
        modBusUartPutch(s[DummyCounter]);
    }
    return TRUE;
}
void receiveInterrupt(uint8_t Data){//Call this function into your UART Interrupt. Collect data from it!
    modbusReceiveBuffer[modbusReceiveCounter] = Data;
    modbusReceiveCounter ++;
    if(modbusReceiveCounter > CONFIG_MODBUS_SLAVE_BUFFER_SIZE){  
        modbusReceiveCounter = 0;
	}
    modbusTimerValue = 0;
}


void modBusTimerValues(void){//Call this function into 1ms Interrupt or Event!
    modbusTimerValue ++;
}
/******************************************************************************/
static void modbusHandle() interrupt INTERRUPT_TIMER2
{//硬件计时器TIMER1中断函数 1mS
	TF2 = 0;
	modBusTimerValues();
} 

static void serialHandle() interrupt INTERRUPT_UART0
{//UART0 串口中断程序
	uint8_t ctemp;
	if(RI0){
		RI0 = 0;
		ctemp = SBUF0;		
		receiveInterrupt(ctemp);
		if(RI0)
		{
			RI0 = 0;
		}
	}
	if(TI0){
		TI0 = 0;
		//modbusSerialTxHandle();
	}
} 