#include "sPlc.h"
/*****************************************************************************/
xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
uint8_t Timer0_L, Timer0_H;
/******************************************************************************/
static void updataNvram(void){//����NVRAM->EPROM
	memcpy((uint8_t*)NVRAM1, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));
}
static void clearNvram(void){//��ʼ��NVRAM
	memset((uint8_t*)NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//��ʼ��NVRAM
	memset((uint8_t*)NVRAM1, 0x0, (CONFIG_NVRAM_SIZE * 2));//��ʼ��NVRAM
}
/*****************************************************************************/
void sPlcInit(void){//���߼���ʼ��
#if CONFIG_SPLC_USING_WDT == 1
	lockWatchDog();//�������Ź�
#else
	disableWatchDog();//���ο��Ź�
#endif
	setLedError(DEBUG_LED_OFF);
	setLedRun(DEBUG_LED_OFF);
	setLedDac(DEBUG_LED_OFF);	
	initUart1(CONFIG_UART1_BAUDRATE);//UART1��ʼ��
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
}
void sPlcProcessEnd(void){//sPLC��ѯ����
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//ι��
#endif
#if CONFIG_SPLC_USING_DAC
	refreshDac();//����DAC���
#endif
	updataNvram();//����NVRAM
	RES(SPCOIL_START_UP);
}