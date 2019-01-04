/////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////
#ifdef C8051F580
#include "InitDeviceF580.h"

void PCA0_Init()
{
    PCA0MD    &= ~0x40;
    PCA0MD    = 0x00;
}

// Initialization function for device,
// Call Init_Device() from your main program
void initDeviceF580(void)
{
    //Reset_Sources_Init();
    //DAC_Init();
    //Voltage_Reference_Init();
    //Port_IO_Init();
    //Oscillator_Init();
    //Interrupts_Init();
	PCA0_Init();
}
#endif
