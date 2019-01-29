#include "sPlcInt.h"
/*****************************************************************************/
uint8_t sPlcInterrupt;
void enterSplcIsr(void){//SPLC 进入中断
	sPlcInterrupt = EA;
	EA = false;
}
void exitSplcIsr(void){//SPLC 退出中断
	EA = sPlcInterrupt;
}
