#include "sPlcWatchDog.h"
/*****************************************************************************/
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
