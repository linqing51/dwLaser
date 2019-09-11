#include "sPlcUart.h"
/*****************************************************************************/
void initUart0(uint32_t baudrate){//初始化串口0
#if CONFIG_SPLC_USING_UART0 == 1	
	uint8_t SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE	
	uint16_t temp;
	SFRPAGE = TMR2_PAGE;// Set SFR page
	temp =(uint16_t)(65536 - CONFIG_SYSCLK / 12 /16 / baudrate);
	TMR2CF = 0;//	
	RCAP2 = temp;//Reload value to be used in Timer2
	TMR2 = RCAP2;//Init the Timer2 register
	TMR2CN = 0x0;//16Bit AutoReload
	TMR2CN |= 1 << 2;//TR2 RUN
	SFRPAGE = UART0_PAGE;
	SCON0 |= 0x40;// 8-bit variable baud rate;
	SCON0 |= (1 << 4);//UART0 reception enabled.
	SSTA0 = 0;//T1->UART0
	SSTA0 |= (1 << 2);//Timer 2 Overflow generates UART0 TX baud rate
	SSTA0 |= (1 << 0);//Timer 2 Overflow generates UART0 RX baud rate
	SSTA0 |= 1 << 4;//UART0 baud rate divide-by-two disabled.
	ES0 = 1;//关闭串口0中断
	PS0 = 1;//UART0 interrupts set to high priority
	TI0 = 0;//清除发送完成   		
	RI0 = 0;//清除接收完成	
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFRPAGE
#endif
}

void initUart1(uint32_t baudrate){
#if CONFIG_SPLC_USING_UART1 == 1
	uint8_t SFRPAGE_SAVE = SFRPAGE;        // Save Current SFR page
	SFRPAGE = UART1_PAGE;
	SCON1 |= 0x10;// SCON1: mode 0, 8-bit UART, enable RX
	SFRPAGE = TIMER01_PAGE;
	CKCON &= 0xFC;
	CKCON |= 1 << 1;//System clock divided by 48
	CKCON &= 0xEF;//Timer 1 uses the clock defined by the prescale bits, SCA1SCA0
	TMOD &= ~0xF0;
	TMOD |=  0x20;                    // TMOD: timer 1, mode 2, 8-bit reload
	TH1 = -(CONFIG_SYSCLK / baudrate / 2 / 48);
	TL1 = TH1;                          // init Timer1
	TR1 = 1;                            // START Timer1
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
	//EIE2 &= 0xBF;//关闭串口1中断
	EIE2 |= 1 << 6;
	EIP2 |= 1<<6;//UART1高优先级
#endif
}
