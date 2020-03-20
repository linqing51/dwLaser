#include "sPlc.h"
/*****************************************************************************/
xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
uint8_t Timer0_L, Timer0_H;
/******************************************************************************/
uint8_t getGlobalInterrupt(void){
	return EA;
}
static void updataNvram(void){//����NVRAM->EPROM
	memcpy((uint8_t*)NVRAM1, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));
}
static void clearNvram(void){//���NVRAM����	
	idata uint8_t oldEA;
	oldEA = EA;//�ر��ж�
	EA = 0;
	memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//��ʼ��NVRAM
	EA = oldEA;//�ָ��ж�
}
/*****************************************************************************/
static void pcaInit(void){//Ӳ��PCA��ʼ��
}
void sPlcInit(void){//���߼���ʼ��
#if CONFIG_SPLC_USING_WDT == 1
	if ((RSTSRC & 0x02) == 0x00){
		if(RSTSRC == 0x08)
		{//���WDT���Ź� ���Ź���λ������
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
	initWatchDog();//���Ź�ʹ��
	disableWatchDog();//���ο��Ź�
#if CONFIG_SPLC_USING_UART1 == 1
	initUart1(CONFIG_UART1_BAUDRATE);//UART1��ʼ��
#endif
#if CONFIG_SPLC_USING_CADC == 1
	initChipAdc();//��ʼ��ADCģ��
#endif
#if CONFIG_SPLC_USING_DAC == 1
	initChipDac();//��ʼ��DACģ��
#endif
#if CONFIG_SPLC_USING_MB_RTU_SLAVE == 1
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
#endif
	timer0Init();//��ʼ��Ӳ����ʱ��ģ��
	SET(SPCOIL_ON);
	setLedError(DEBUG_LED_OFF);
	SET(SPCOIL_ON);
	SET(SPCOIL_START_UP);
}
void sPlcProcessStart(void){//sPLC��ѯ��ʼ
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//ι��
#endif
#if CONFIG_SPLC_USING_MB_RTU_SLAVE == 1
	modbusPorcess();//����MODBUS
#endif
#if CONFIG_SPLC_USING_CADC == 1
	chipAdcProcess();//ADCɨ��
#endif
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();
#endif
}
void sPlcProcessEnd(void){//sPLC��ѯ����
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//ι��
#endif
#if CONFIG_SPLC_USING_DAC
	refreshDac();//����DAC���
#endif
	updataNvram();//����NVRAM
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//ι��
#endif
	RES(SPCOIL_START_UP);
}