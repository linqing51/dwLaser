#include "MainApp.h"
/*****************************************************************************/
void hwTest(void){
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
	disableSplcIsr();
	setLedRun(true);//
	setLedEprom(true);
	setLedError(true);
	delayMs(500);
	setLedRun(false);//
	setLedEprom(false);
	setLedError(false);
//	if(epromTest()){//EPROM测试成功
//		setLedEprom(true);
//		clearNvram();
//	}
//		else{//EPROM测试失败
//		setLedError(true);	
//	}
	//清空NVRAM0和NVRAM1
	memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//初始化NVRAM
	memset(NVRAM1, 0x0, (CONFIG_NVRAM_SIZE * 2));//初始化NVRAM
	//SET DAC MAX
	SFRPAGE   = DAC0_PAGE;
	DAC0 = 0x0;
	SFRPAGE   = DAC1_PAGE;
	DAC1 = 0x0;
	SFRPAGE = CONFIG_PAGE;
	P2 |= (1 << 6);
	P2 |= (1 << 7);
	SFRPAGE_SAVE = SFRPAGE;
	//YOUT = 1
	SFRPAGE   = CONFIG_PAGE;
	P2 |= 1 << 5;
	P2 &= ~(1 << 4);
	P3 |= 1 << 5;
	P3 |= 1 << 6;
	P3 |= 1 << 7;
	P2 |= 1 << 0;
	P2 |= 1 << 1;
	P2 |= 1 << 2;
	P2 |= 1 << 3;
	P2 |= 1 << 4;
	P6 |= 1 << 3;
	P6 |= 1 << 4;
	P6 |= 1 << 1;
	P6 |= 1 << 2;
	while(1){
		SFRPAGE = DAC0_PAGE;
		DAC0 = 0xFFF;
		SFRPAGE = DAC1_PAGE;
		DAC1 = 0xFFF;
		delayMs(20);
		SFRPAGE = DAC0_PAGE;
		DAC0 = 0x0;
		SFRPAGE = DAC1_PAGE;
		DAC1 = 0x0;
		delayMs(20);
		SFRPAGE = DAC0_PAGE;
		DAC0 = 0x7FF;
		SFRPAGE = DAC1_PAGE;
		DAC1 = 0x7FF;
		delayMs(20);
		SFRPAGE = DAC0_PAGE;
		DAC0 = 0xFFF;
		SFRPAGE   = DAC1_PAGE;
		DAC1 = 0xFFF;
		delayMs(20);
		SFRPAGE = DAC0_PAGE;
		DAC0 = 0x7FF;
		SFRPAGE = DAC1_PAGE;
		DAC1 = 0x7FF;
		delayMs(20);
		SFRPAGE = DAC0_PAGE;
		DAC0 = 0x0;
		SFRPAGE = DAC1_PAGE;
		DAC1 = 0x0;
	}
}


void main(void){ 
	initDevice();
	sPlcInit();
	//hwTest();
#if CONFIG_DEBUG == 1
	printf("sPLC->main:Debug Port->UART1\n");
	printf("sPLC->main:sPlcInit Done\n");
#endif
	Cache_ISR_Entry((unsigned int)sPlcTimerIsr, INTERRUPT_TIMER0);
#if CONFIG_SPLC_USING_LASER_TIMER == 1
	//Cache_ISR_Entry((unsigned int)laserTimerIsr, INTERRUPT_TIMER4);
#endif
	//Cache_ISR_Entry((unsigned int)Uart0Isr, INTERRUPT_UART0);
	while(1){
		sPlcProcessStart();
		if(LD(SPCOIL_START_UP)){//
#if CONFIG_USING_BACKGROUND_APP == 1 
			backgroundAppInit();
#endif
#if CONFIG_USING_DCHMI_APP == 1			
			dcHmiLoopInit();
#endif			
		}
#if CONFIG_USING_BACKGROUND_APP == 1 
			backgroundApp();
#endif		
#if CONFIG_USING_DCHMI_APP == 1
			dcHmiLoop();
#endif
#if CONFIG_SPLC_FUNTEST == 1
#endif
		sPlcProcessEnd();
	}
}


