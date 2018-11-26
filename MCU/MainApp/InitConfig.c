#include "InitConfig.h"
/*****************************************************************************/

// Peripheral specific initialization functions,
// Called from the Init_Device() function
void Reset_Sources_Init()
{
    WDTCN     = 0xDE;
    WDTCN     = 0xAD;
}

void Voltage_Reference_Init()
{
    REF0CN    = 0x07;
}

void Oscillator_Init()
{
    OSCICN    = 0x17;
}

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    Reset_Sources_Init();
    Voltage_Reference_Init();
    Oscillator_Init();
}