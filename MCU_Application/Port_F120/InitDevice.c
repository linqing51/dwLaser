/////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////
#include "InitDevice.h"
// Peripheral specific initialization functions,
// Called from the Init_Device() function
static void Reset_Sources_Init()
{
    WDTCN     = 0xDE;
    WDTCN     = 0xAD;
}

static void DAC_Init()
{
    DAC0CN    = 0x80;
}

static void Voltage_Reference_Init()
{
    REF0CN    = 0x07;
}

void Port_IO_Init()
{

}

static void Oscillator_Init()
{
    int i = 0;
    SFRPAGE   = CONFIG_PAGE;
    OSCXCN    = 0x67;
    for (i = 0; i < 3000; i++);  // Wait 1ms for initialization
    while ((OSCXCN & 0x80) == 0);
    PLL0CN    = 0x04;
    CCH0CN    &= ~0x20;
    SFRPAGE   = LEGACY_PAGE;
    FLSCL     = 0xB0;
    SFRPAGE   = CONFIG_PAGE;
    CCH0CN    |= 0x20;
    PLL0CN    |= 0x01;
    PLL0DIV   = 0x01;
    PLL0FLT   = 0x01;
    PLL0MUL   = 0x04;
    for (i = 0; i < 15; i++);  // Wait 5us for initialization
    PLL0CN    |= 0x02;
    while ((PLL0CN & 0x10) == 0);
    CLKSEL    = 0x02;
}

static void Interrupts_Init()
{
}

// Initialization function for device,
// Call Init_Device() from your main program
void initDevice(void)
{
    Reset_Sources_Init();
    DAC_Init();
    Voltage_Reference_Init();
    Port_IO_Init();
    Oscillator_Init();
    Interrupts_Init();
}
