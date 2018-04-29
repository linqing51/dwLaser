/*****************************************************************************/
#include "modbusPort.h"
/*****************************************************************************/
static data uint8_t ModbusTL, ModbusTH;

void ModbusTimer(void *yydata)
{
}

static void Timer1Handle() interrupt INTERRUPT_TIMER4
{//Ӳ����ʱ��TIMER1�жϺ��� 1mS
	//TL4       = ModbusTL;
    //TH4       = ModbusTH;
	modbusTimerHandle();
} 

static void SerialHandle() interrupt INTERRUPT_UART0
{//UART0 �����жϳ���
	OS_ENTER_CRITICAL(); //�ر�Ucos �ж�
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
	OS_EXIT_CRITICAL();
}  
static void modbusSerialSendbyte(uint8_t *dt)
{//���ڷ���һ���ֽ�
	ES0 = 0;
	TI0 = 0;
	SBUF0 = *dt;
	while( !TI0 );
	TI0 = 0;
	ES0 = 1;
}
void modbusSerialSendBuffer(uint8_t *buf, uint8_t size)
{//���ڷ���һ���ֽ�
	uint8_t i;
	for(i = 0;i < size;i ++)
	{
		modbusSerialSendbyte(buf + i);
	}
}
void InitModbusSerial(int32_t baudrate)
{//��ʼ��MODBUS����
	uint32_t temp;
	CKCON |= 1 << 5;//TIMER2 SYSCLK
	T2CON |= 1 << 4;//Timer 2 overflows used for transmit clock
	T2CON |= 1 << 5;//Timer 2 overflows used for receive clock
	temp = (uint32_t)(CONFIG_SYSCLK / 32 / baudrate);
	temp = 65536 - temp;	
    RCAP2L    =	(uint8_t)(temp & 0xff);
    RCAP2H    = (uint8_t)((temp >> 8) & 0xff);
	T2CON |= 1 << 2;//Timer 2 enabled
	RS485_DIRECTION_RXD;//����״̬
	ES0 = 1;
	TI0 = 0;//����������   		
	RI0 = 0;//����������			
}
void InitModbusTimer(void)
{//��ʼ��MODBUS��ʱ�� 1mS TIMER1
	uint16_t temp;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 12 / 1000));
	CKCON &= ~(1 << 4);//TIMER1 CLK = SYSCLK / 12
	TMOD &= 0x0F;
	TMOD |= (1 << 4);//Mode 1, 16-bit Counter/Timer
    ModbusTL = (uint8_t)(temp & 0xFF);
	ModbusTH = (uint8_t)((temp >> 8) & 0xFF);
	TL1       = ModbusTL;
    TH1       = ModbusTH;
	TF1 = 0;
	TR1 = 1;        
	ET1 = 1; //���ж�T0
}




