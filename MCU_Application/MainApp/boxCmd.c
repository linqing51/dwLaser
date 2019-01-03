#include "boxCmd.h"
/*****************************************************************************/
static void boxSerialSendbyte(uint8_t *dt){//串口发送一个字节
	SCON1 &= ~(uint8_t)(1 << 1);//TI1 = 0
	SBUF1 = *dt;
	while(!((SCON1 >> 1) & 0x01));
	SCON1 &= ~(uint8_t)(1 << 1);//TI1 = 0
}
static void boxSerialSendString(uint8_t *s, uint16_t  Length){// This is used for send string, better to use DMA for it ;)
    uint16_t DummyCounter;
    for(DummyCounter=0; DummyCounter < Length; DummyCounter ++){
        boxSerialSendbyte(&s[DummyCounter]);
    }
}
void boxGreenLedRefresh(void){//刷新绿灯状态
//0x81,00,01,......,84///控制绿色灯的亮灭.AA为亮，55为灭。
//0x81,00,02,......,84///控制红色灯的亮灭.AA为亮，55为灭。
//0x81,00,06,84//灯全灭
//0x81,00,09,xx,yy,zz,84//控制灯通道xx的灯的亮灭，zz=0时红绿灯都灭，zz=01,yy=00时红亮绿灭，zz=01,yy=01时红灭绿亮
	xdata uint8_t sBuf[32], i;
	sBuf[0] = BOX_CMD_STX;
	sBuf[1] = 0x00;
	sBuf[2] = 0x01;
	for(i = 3;i < 28;i ++){
		if(LD(R_START * 16 + i)){
			sBuf[i] = 0xAA;
		}
		else{
			sBuf[i] = 0x55;
		}			
	}
	sBuf[28] = 0x84;
	boxSerialSendString(sBuf, 29);
}
void boxRedLedRefresh(void){//刷新红灯状态
//0x81,00,01,......,84///控制绿色灯的亮灭.AA为亮，55为灭。
//0x81,00,02,......,84///控制红色灯的亮灭.AA为亮，55为灭。
//0x81,00,06,84//灯全灭
//0x81,00,09,xx,yy,zz,84//控制灯通道xx的灯的亮灭，zz=0时红绿灯都灭，zz=01,yy=00时红亮绿灭，zz=01,yy=01时红灭绿亮
	xdata uint8_t sBuf[32], i;
	sBuf[0] = BOX_CMD_STX;
	sBuf[1] = 0x00;
	sBuf[2] = 0x02;
	for(i = 3;i < 28;i ++){
		if(LD(R_START * 16 + 32 + i)){
			sBuf[i] = 0xAA;
		}
		else{
			sBuf[i] = 0x55;
		}			
	}
	sBuf[28] = 0x84;
	boxSerialSendString(sBuf, 29);
}
void initboxSerial(uint32_t baudrate){//指示盒串口初始化
	CKCON &= (1 << 6);//Timer 4 uses the system clock
	T4CON = 0;
	T4CON |= 1 << 4;//Timer 4 overflows used for transmit clock.
	T4CON |= 1 << 5;//Timer 4 overflows used for receive clock.
	T4CON &= ~(1 << 0);//当定时器4 溢出或T2EX 上发生负跳变时将自动重装载（EXEN2=1）
	T4CON &= ~(1 << 1);//定时器功能：定时器4 由T2M（CKCON.5）定义的时钟加1
	RCAP4  = - ((long) ((uint32_t)CONFIG_SYSCLK / baudrate) / 32L);
	TMR4 = RCAP4;
	T4CON |= 1 << 2;//Timer 4 enabled
	SCON1 = 0x0;
	SCON1 |= (0x01 << 6);//Mode 1: 8-Bit UART, Variable Baud Rate
	SCON1 &= ~(uint8_t)(1 << 0);//RI1: Receive Interrupt Flag.
	SCON1 &= ~(uint8_t)(1 << 1);//TI1: Transmit Interrupt Flag.	
}