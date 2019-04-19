#include "sPlcSimEprom.h"
#if CONFIG_USING_SIMEPROM == 1
/*****************************************************************************/
void sPlcSimEpromInit(void){
	SFRPAGE_SWITCH()
    ENABLE_VDDMON()
    DISABLE_WDT()
    SFRPAGE_RESTORE()
    eeprom_init();
}
#endif