#include "debugLed.h"
/*****************************************************************************/
void setLedRun(uint8_t st){//P6_0
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
    SFRPAGE   = CONFIG_PAGE;
	if(st){
		P6 &= 0xFE;
	}
	else{
		P6 |= 0x01;
	}
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFRPAGE
}
void setLedEmit(uint8_t st){//P5_7
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
    SFRPAGE   = CONFIG_PAGE;
	if(st){
		P5 &= ~(1 << 7);	
	}
	else{
		P5 |= (1 << 7);
	}
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFRPAGE
}
void setLedEprom(uint8_t st){//P5_6
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
    SFRPAGE   = CONFIG_PAGE;
	if(st){
		P5 &= 0xBF;
	}
	else{
		P5 |= 0x40;
	}
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFRPAGE
}
void setLedVar(uint8_t st){//P5_0
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
    SFRPAGE   = CONFIG_PAGE;
	if(st){
		P5 &= 0xFE;
	}
	else{
		P5 |= 0x01;
	}
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFRPAGE
}