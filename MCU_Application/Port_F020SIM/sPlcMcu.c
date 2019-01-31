#include "sPlcMcu.h"
/*****************************************************************************/
static uint8_t sPlcInterrupt;
void initWatchDog(void){//���Ź���ʼ��
	WDTCN = 0x07;//47mS
}
void enableWatchDog(void){//ʹ�ܿ��Ź�
	WDTCN = 0xA5;
}
void disableWatchDog(void){//�رտ��Ź�(δ����)
	uint8_t flagEA;
	flagEA = EA;
	EA = 0;
	WDTCN = 0xDE;
    WDTCN = 0xAD;
	EA = flagEA;
}
void feedWatchDog(void) reentrant{//ι��
	WDTCN = 0xA5;
}
void mucReboot(void) reentrant {//��λ
	RSTSRC |= 1 << 4;//ǿ�Ƹ�λ
}
void enterSplcIsr(void) reentrant{//SPLC �����ж�
	sPlcInterrupt = EA;
	EA = false;
}
void exitSplcIsr(void) reentrant{//SPLC �˳��ж�
	EA = sPlcInterrupt;
}
void disableSplcIsr(void) reentrant{//SPLC�ر�ȫ���ж�
	EA = 0;
}
void enableSplcIsr(void) reentrant{//SPLC��ȫ���ж�
	EA = 1;
}