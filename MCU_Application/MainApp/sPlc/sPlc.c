#include "sPlc.h"
/*****************************************************************************/
xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//掉电保持寄存器 当前
xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//掉电保持寄存器 上一次
uint8_t Timer0_L, Timer0_H;
/******************************************************************************/
uint8_t getGlobalInterrupt(void){
	return EA;
}
static void updataNvram(void){//更新NVRAM->EPROM
	memcpy((uint8_t*)NVRAM1, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));
}
static void clearNvram(void){//清除NVRAM数据	
	idata uint8_t oldEA;
	oldEA = EA;//关闭中断
	EA = 0;
	memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//初始化NVRAM
	EA = oldEA;//恢复中断
}
/*****************************************************************************/
static void pcaInit(void){//硬件PCA初始化
}
void sPlcInit(void){//软逻辑初始化
#if CONFIG_SPLC_USING_WDT == 1
	if ((RSTSRC & 0x02) == 0x00){
		if(RSTSRC == 0x08)
		{//检测WDT看门狗 看门狗复位后锁定
			setLedError(DEBUG_LED_ON);
			setLedRun(DEBUG_LED_ON);
			setLedDac(DEBUG_LED_OFF);
			while(1);
		}
	}
#endif
	setLedError(DEBUG_LED_OFF);
	setLedRun(DEBUG_LED_OFF);
	setLedDac(DEBUG_LED_OFF);
	initWatchDog();//看门狗使能
	disableWatchDog();//屏蔽看门狗
#if CONFIG_SPLC_USING_UART1 == 1
	initUart1(CONFIG_UART1_BAUDRATE);//UART1初始化
#endif
#if CONFIG_SPLC_USING_CADC == 1
	initChipAdc();//初始化ADC模块
#endif
#if CONFIG_SPLC_USING_DAC == 1
	initChipDac();//初始化DAC模块
#endif
#if CONFIG_SPLC_USING_MB_RTU_SLAVE == 1
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
#endif
	timer0Init();//初始化硬件计时器模块
	SET(SPCOIL_ON);
	setLedError(DEBUG_LED_OFF);
	SET(SPCOIL_ON);
	SET(SPCOIL_START_UP);
}
void sPlcProcessStart(void){//sPLC轮询起始
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//喂狗
#endif
#if CONFIG_SPLC_USING_MB_RTU_SLAVE == 1
	modbusPorcess();//处理MODBUS
#endif
#if CONFIG_SPLC_USING_CADC == 1
	chipAdcProcess();//ADC扫描
#endif
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();
#endif
}
void sPlcProcessEnd(void){//sPLC轮询结束
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//喂狗
#endif
#if CONFIG_SPLC_USING_DAC
	refreshDac();//更新DAC输出
#endif
	updataNvram();//更新NVRAM
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//喂狗
#endif
	RES(SPCOIL_START_UP);
}