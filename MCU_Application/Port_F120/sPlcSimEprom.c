#include "sPlcSimEprom.h"
/*****************************************************************************/
void sPlcSimEpromInit(void){
	SFRPAGE_SWITCH()
    ENABLE_VDDMON()
    DISABLE_WDT()
    SFRPAGE_RESTORE()
    eeprom_init();
}