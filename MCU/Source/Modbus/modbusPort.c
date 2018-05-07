/*****************************************************************************/
#include "modbusPort.h"
/*****************************************************************************/
static void ModbusHandle() interrupt INTERRUPT_TIMER2
{//硬件计时器TIMER1中断函数 1mS
	TF2 = 0;
	modbusTimerHandle();
} 

static void SerialHandle() interrupt INTERRUPT_UART0
{//UART0 串口中断程序
	if(RI0)
	{
		RI0 = 0;  
		modbusSerialRxHandle();
	}
	if(TI0)
	{
		TI0 = 0;
		modbusSerialTxHandle();
	}
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
void modbusSerialSendBuffer(uint8_t *buf, uint8_t size)
{//串口发送一组字节
	uint8_t i;
	for(i = 0;i < size;i ++)
	{
		modbusSerialSendbyte(buf + i);
	}
}
void InitModbusSerial(int32_t baudrate)
{//初始化MODBUS串口
	uint32_t temp;
	CKCON |= ~(1 << 4);//TIMER1 SYSCLK / 12
	temp = (uint32_t)(CONFIG_SYSCLK / 32 / baudrate);
	temp = 65536 - temp;	
	TMOD &= 0x0F;
	TMOD |= 1 << 5;//Mode 2: 8-bit counter/timer with auto-reload
	
	TH1 = (uint8_t)(temp & 0xff);
	TR1 = 1;
	//T2CON |= 1 << 2;//Timer 2 enabled
	RS485_DIRECTION_RXD;//接收状态
	ES0 = 1;
	TI0 = 0;//清除发送完成   		
	RI0 = 0;//清除接收完成			
}
void InitModbusTimer(void)
{//初始化MODBUS计时器 1mS TIMER2
	uint16_t temp;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 12 / 1000 * 10));
	CKCON &= ~(1 << 5);//TIMER1 CLK = SYSCLK / 12
	T2CON = 0x0;//RCLK0=0,TCLK0=0
    RCAP2L = (uint8_t)(temp & 0xFF);
	RCAP2H = (uint8_t)((temp >> 8) & 0xFF);
	TF2 = 0;
	TR2 = 1;        
	ET2 = 1; //开中断T0
}




