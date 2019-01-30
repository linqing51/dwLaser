#include "sPlcWatchDog.h"
/*****************************************************************************/
void initWatchDog(void){//���Ź���ʼ��
#if CONFIG_SPLC_USING_WDT == 1
	WDTCN = 0x07;//47mS
#endif
}
void enableWatchDog(void){//ʹ�ܿ��Ź�
#if CONFIG_SPLC_USING_WDT == 1
	WDTCN = 0xA5;
#endif
}
void disableWatchDog(void){//�رտ��Ź�(δ����)
#if CONFIG_SPLC_USING_WDT == 1
	uint8_t flagEA;
	flagEA = EA;
	EA = 0;
	WDTCN = 0xDE;
    WDTCN = 0xAD;
	EA = flagEA;
#endif
}
void feedWatchDog(void) reentrant{//ι��
#if CONFIG_SPLC_USING_WDT == 1
	WDTCN = 0xA5;
#endif
}
void checkWatchDog(void){//��鿴�Ź�״̬
#if CONFIG_SPLC_USING_WDT == 1
	if ((RSTSRC & 0x02) == 0x00){
		if(RSTSRC == 0x08){//���WDT���Ź� ���Ź���λ������
			SET(SPCOIL_WATCHDOG);
			setLedError(DEBUG_LED_ON);
			setLedRun(DEBUG_LED_ON);
			setLedDac(DEBUG_LED_OFF);
			setLedEprom(DEBUG_LED_OFF);
			delayMs(100);
		}
	}
#endif
}