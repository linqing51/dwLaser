#include "sPlc.h"
/*****************************************************************************/
xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
uint8_t Timer0_L, Timer0_H, DelayCounter;
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
	setLedRun(LED_ON);
	setLedDebug(LED_OFF);
	//setLedDac(LED_OFF);
	//setLedError(LED_OFF);
	if((RSTSRC & 0x02)){//�ϵ縴λ
		clearNvram();
#if CONFIG_SPLC_USING_DAC == 1
		initOffChipDac();//��ʼ��DACģ��
		//setLedDac(LED_ON);
#endif
	}	
	else if(RSTSRC & 0x01){//Ӳ�����Ÿ�λ
		//initOffChipDac();//��ʼ��DACģ��
		clearNvram();		
	}	
	else if(RSTSRC & 0x08){//���Ź���λ 
		//initOffChipDac();//��ʼ��DACģ��
		//setLedError(LED_ON);
	}
	else if(RSTSRC & 0x10){//���ǿ�Ƹ�λ�ͱ�־
		//initOffChipDac();//��ʼ��DACģ��
		clearNvram();
	}
	initUart1(CONFIG_UART1_BAUDRATE);//UART1��ʼ��
#if CONFIG_SPLC_USING_CADC == 1
	initChipAdc();//��ʼ��ADCģ��
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
	if(LD(SPCOIL_DELAY_DAC_RUN)){
		refreshDac();//����DAC���
	}
#endif
	updataNvram();//����NVRAM
	RES(SPCOIL_START_UP);
}