#include "sPlcInt.h"
/*****************************************************************************/
uint8_t sPlcInterrupt;
void enterSplcIsr(void){//SPLC �����ж�
	sPlcInterrupt = EA;
	EA = false;
}
void exitSplcIsr(void){//SPLC �˳��ж�
	EA = sPlcInterrupt;
}
