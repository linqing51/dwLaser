#include "appConfig.h"


// Peripheral specific initialization functions,
// Called from the Init_Device() function
void Reset_Sources_Init()
{
    WDTCN     = 0xDE;
    WDTCN     = 0xAD;
    RSTSRC    = 0x06;
}

void Timer_Init()
{
    CKCON     = 0x30;
    TMOD      = 0x20;
    TH1       = 0xFA;
    RCAP2L    = 0xB8;
    RCAP2H    = 0xFF;
}

void UART_Init()
{
    SCON0     = 0x50;
    SCON1     = 0x50;
}

void DAC_Init()
{
    DAC0CN    = 0x80;
    DAC1CN    = 0x80;
}

void Voltage_Reference_Init()
{
    REF0CN    = 0x07;
}

void Port_IO_Init()
{
    // P0.0  -  TX0 (UART0), Push-Pull,  Digital
    // P0.1  -  RX0 (UART0), Open-Drain, Digital
    // P0.2  -  SDA (SMBus), Open-Drain, Digital
    // P0.3  -  SCL (SMBus), Open-Drain, Digital
    // P0.4  -  TX1 (UART1), Push-Pull,  Digital
    // P0.5  -  RX1 (UART1), Open-Drain, Digital
    // P0.6  -  CEX0 (PCA),  Push-Pull,  Digital
    // P0.7  -  CEX1 (PCA),  Push-Pull,  Digital

    // P1.0  -  CEX2 (PCA),  Push-Pull,  Digital
    // P1.1  -  CEX3 (PCA),  Push-Pull,  Digital
    // P1.2  -  Unassigned,  Open-Drain, Digital
    // P1.3  -  Unassigned,  Open-Drain, Digital
    // P1.4  -  Unassigned,  Open-Drain, Digital
    // P1.5  -  Unassigned,  Open-Drain, Digital
    // P1.6  -  Unassigned,  Push-Pull,  Digital
    // P1.7  -  Unassigned,  Push-Pull,  Digital

    // P2.0  -  Unassigned,  Open-Drain, Digital
    // P2.1  -  Unassigned,  Open-Drain, Digital
    // P2.2  -  Unassigned,  Open-Drain, Digital
    // P2.3  -  Unassigned,  Push-Pull,  Digital
    // P2.4  -  Unassigned,  Open-Drain, Digital
    // P2.5  -  Unassigned,  Open-Drain, Digital
    // P2.6  -  Unassigned,  Open-Drain, Digital
    // P2.7  -  Unassigned,  Open-Drain, Digital

    // P3.0  -  Unassigned,  Open-Drain, Digital
    // P3.1  -  Unassigned,  Open-Drain, Digital
    // P3.2  -  Unassigned,  Open-Drain, Digital
    // P3.3  -  Unassigned,  Open-Drain, Digital
    // P3.4  -  Unassigned,  Open-Drain, Digital
    // P3.5  -  Unassigned,  Open-Drain, Digital
    // P3.6  -  Unassigned,  Open-Drain, Digital
    // P3.7  -  Unassigned,  Open-Drain, Digital

    P0MDOUT   = 0xD1;
    P1MDOUT   = 0xC3;
    P2MDOUT   = 0x08;
    P74OUT    = 0x33;
    XBR0      = 0x25;
    XBR2      = 0x44;
}

void Oscillator_Init()
{
    int i = 0;
    OSCXCN    = 0x67;
    for (i = 0; i < 3000; i++);  // Wait 1ms for initialization
    while ((OSCXCN & 0x80) == 0);
    OSCICN    = 0x0C;
}

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    Reset_Sources_Init();
    Timer_Init();
    UART_Init();
    DAC_Init();
    Voltage_Reference_Init();
    Port_IO_Init();
    Oscillator_Init();
}