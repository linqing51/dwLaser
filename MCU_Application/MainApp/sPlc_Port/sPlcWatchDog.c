#include "sPlcWatchDog.h"
/*****************************************************************************/
void lockWatchDog(void){//ʹ�ܿ��Ź�
	WDTCN = 0xA5;//ι��
	WDTCN = 0xFF;
    WDTCN = 0x07;//�������Ź�
}
void feedWatchDog(void) reentrant{//ι��
	WDTCN = 0xA5;
}
void disableWatchDog(void){//�رտ��Ź�(δ����)
	WDTCN = 0xDE;
    WDTCN = 0xAD;
}
