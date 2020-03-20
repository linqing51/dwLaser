#include "modbusPort.h"
/*****************************************************************************/
static uint8_t Timer1_L,Timer1_H;
/*****************************************************************************/
void initModbusSerial(int32_t baudrate)
{//初始化MODBUS串口
	CKCON |= (1 << 5);//Timer2 uses the system clock
	T2CON &= ~(1 << 0);//当定时器2 溢出或T2EX 上发生负跳变时将自动重装载（EXEN2=1）
	T2CON &= ~(1 << 1);//定时器功能：定时器2 由T2M（CKCON.5）定义的时钟加1
	T2CON |= (1 << 4);//Timer 2 overflows used for transmit clock.
	T2CON |= (1 << 5);//Timer 2 overflows used for receive clock.	
	RCAP2  = - ((long) ((uint32_t)CONFIG_SYSCLK / baudrate) / 32L);
	TMR2 = RCAP2;
	TR2= 1;                             // Start Timer2
	SCON0 = 0x0;
	SCON0 |= (1 << 4);//接收允许
	SCON0 |= (1 << 6);//方式1：8 位UART，可变波特率
	//RS485_DIRECTION_RXD;//接收状态
	ES0 = 1;
	IP |= (1 << 4);//UART0 中断高优先级
	TI0 = 0;//清除发送完成   		
	RI0 = 0;//清除接收完成
}
void initModbusTimer(void){//初始化MODBUS计时器 1mS TIMER1
	uint16_t temp;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 12 / CONFIG_MB_RTU_SLAVE_TIMER));
	Timer1_L = (uint8_t)(temp & 0xFF);
	Timer1_H = (uint8_t)((temp >> 8) & 0xFF);
	CKCON &= ~(1 << 4);//TIMER1 SYSCLK / 12
	TMOD &= 0x0F;
	TMOD |= (1 << 4);//方式1：16 位计数器/定时器
	TH1 = Timer1_H;
	TL1 = Timer1_L;	
	TF1 = 0;
	TR1 = 1;        
	ET1 = 1; //开中断T1
}
static void modbusSerialSendbyte(uint8_t *dt){//串口发送一个字节
	ES0 = 0;
	TI0 = 0;
	SBUF0 = *dt;
	while( !TI0 ){
#if CONFIG_SPLC_USING_WDT == 1
		feedWatchDog();
#endif
	}
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
    return true;
}
void receiveInterrupt(uint8_t Data){//Call this function into your UART Interrupt. Collect data from it!
    modbusReceiveBuffer[modbusReceiveCounter] = Data;
    modbusReceiveCounter ++;
    if(modbusReceiveCounter > CONFIG_MB_RTU_SLAVE_BUFFER_SIZE){  
        modbusReceiveCounter = 0;
	}
    modbusTimerValue = 0;
}
/******************************************************************************/
static void modbusHandle() interrupt INTERRUPT_TIMER1
{//硬件计时器TIMER1中断函数 1mS
	TF1 = 0;
	TR1 = 0;
	TH1 = Timer1_H;
	TL1 = Timer1_L;
	TR1 = 1;
	modbusTimerValue ++;
} 

static void uart0Isr() interrupt INTERRUPT_UART0
{//UART0 串口中断程序
	if(RI0){
		RI0 = 0;	
		receiveInterrupt(SBUF0);
	}
	if(TI0){
		TI0 = 0;
	}
} 