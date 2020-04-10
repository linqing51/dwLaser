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
	setLedRun(LED_OFF);
	setLedDebug(LED_OFF);
	setLedDac(LED_OFF);
	setLedError(LED_OFF);
	if((RSTSRC & 0x02)){//�ϵ縴λ
		setLedRun(LED_ON);
	}
	else if(RSTSRC & 0x01){//Ӳ�����Ÿ�λ
		setLedDebug(LED_ON);
	}
	else if(RSTSRC & 0x04){//ʱ�Ӷ�ʧ�������־
	}
	else if(RSTSRC & 0x08){//���Ź���λ 
		setLedError(LED_ON);
	}
	else if(RSTSRC & 0x10){//���ǿ�Ƹ�λ�ͱ�־
	}
	clearNvram();
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
//	//CH0
//	if((NVRAM0[EM_DAC_0] > 0) && (NVRAM0[EM_ADC_0] < 100))){
//		forceSetDac(0);
//	}
//	//CH1
//	if((NVRAM0[EM_DAC_1] > 0) && (NVRAM0[EM_ADC_1] < 100))){
//		forceSetDac(1);
//	}
//	//CH2
//	if((NVRAM0[EM_DAC_2] > 0) && (NVRAM0[EM_ADC_2] < 100))){
//		forceSetDac(2);
//	}
//	//CH3
//	if((NVRAM0[EM_DAC_3] > 0) && (NVRAM0[EM_ADC_3] < 100))){
//		forceSetDac(3);
//	}
//	//CH4
//	if((NVRAM0[EM_DAC_4] > 0) && (NVRAM0[EM_ADC_4] < 100))){
//		forceSetDac(4);
//	}
//	//CH5
//	if((NVRAM0[EM_DAC_5] > 0) && (NVRAM0[EM_ADC_5] < 100))){
//		forceSetDac(5);
//	}
//	//CH6
//	if((NVRAM0[EM_DAC_6] > 0) && (NVRAM0[EM_ADC_6] < 100))){
//		forceSetDac(6);
//	}
//	//CH7
//	if((NVRAM0[EM_DAC_7] > 0) && (NVRAM0[EM_ADC_7] < 100))){
//		forceSetDac(7);
//	}
//	//CH8
//	if((NVRAM0[EM_DAC_8] > 0) && (NVRAM0[EM_ADC_8] < 100))){
//		forceSetDac(8);
//	}
//	//CH9
//	if((NVRAM0[EM_DAC_9] > 0) && (NVRAM0[EM_ADC_9] < 100))){
//		forceSetDac(9);
//	}
//	//CH10
//	if((NVRAM0[EM_DAC_10] > 0) && (NVRAM0[EM_ADC_10] < 100))){
//		forceSetDac(10);
//	}
//	//CH11
//	if((NVRAM0[EM_DAC_11] > 0) && (NVRAM0[EM_ADC_11] < 100))){
//		forceSetDac(11);
//	}
//	//CH12
//	if((NVRAM0[EM_DAC_12] > 0) && (NVRAM0[EM_ADC_12] < 100))){
//		forceSetDac(12);
//	}
//	//CH13
//	if((NVRAM0[EM_DAC_13] > 0) && (NVRAM0[EM_ADC_13] < 100))){
//		forceSetDac(13);
//	}
//	//CH14
//	if((NVRAM0[EM_DAC_14] > 0) && (NVRAM0[EM_ADC_14] < 100))){
//		forceSetDac(14);
//	}
//	//CH15
//	if((NVRAM0[EM_DAC_15] > 0) && (NVRAM0[EM_ADC_15] < 100))){
//		forceSetDac(15);
//	}
//	//CH16
//	if((NVRAM0[EM_DAC_16] > 0) && (NVRAM0[EM_ADC_16] < 100))){
//		forceSetDac(16);
//	}
//	//CH17
//	if((NVRAM0[EM_DAC_17] > 0) && (NVRAM0[EM_ADC_17] < 100))){
//		forceSetDac(17);
//	}
//	//CH18
//	if((NVRAM0[EM_DAC_18] > 0) && (NVRAM0[EM_ADC_18] < 100))){
//		forceSetDac(18);
//	}
//	//CH19
//	if((NVRAM0[EM_DAC_19] > 0) && (NVRAM0[EM_ADC_19] < 100))){
//		forceSetDac(19);
//	}
//	//CH20
//	if((NVRAM0[EM_DAC_20] > 0) && (NVRAM0[EM_ADC_20] < 100))){
//		forceSetDac(20);
//	}
//	//CH21
//	if((NVRAM0[EM_DAC_21] > 0) && (NVRAM0[EM_ADC_21] < 100))){
//		forceSetDac(21);
//	}
//	//CH22
//	if((NVRAM0[EM_DAC_22] > 0) && (NVRAM0[EM_ADC_22] < 100))){
//		forceSetDac(22);
//	}
//	//CH23
//	if((NVRAM0[EM_DAC_23] > 0) && (NVRAM0[EM_ADC_23] < 100))){
//		forceSetDac(23);
//	}
//	//CH24
//	if((NVRAM0[EM_DAC_24] > 0) && (NVRAM0[EM_ADC_24] < 100))){
//		forceSetDac(24);
//	}
#endif
	updataNvram();//����NVRAM
	RES(SPCOIL_START_UP);
}