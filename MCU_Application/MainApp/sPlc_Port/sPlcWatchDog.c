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
 void feedExtWtd(void){//�ⲿ���Ź�ι��
	if(P5 &  0x10){
		P5 &= ~(uint8_t)(1 << 4);
	}
	else{
		P5 |= (uint8_t)(1 << 4);
	}
}