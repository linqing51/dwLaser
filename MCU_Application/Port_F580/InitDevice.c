/////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////
#include "InitDevice.h"
void Port_IO_Init()
{
    // P0.0  -  Skipped,     Open-Drain, Digital
    // P0.1  -  Skipped,     Open-Drain, Digital
    // P0.2  -  LIN_TX (LIN0), Push-Pull,  Digital
    // P0.3  -  LIN_RX (LIN0), Open-Drain, Digital
    // P0.4  -  UART_TX (UART0), Push-Pull,  Digital
    // P0.5  -  UART_RX (UART0), Open-Drain, Digital
    // P0.6  -  UART_TX (UART1), Push-Pull,  Digital
    // P0.7  -  UART_RX (UART1), Open-Drain, Digital

    // P1.0  -  CEX6  (PCA1), Open-Drain, Digital
    // P1.1  -  CEX7  (PCA1), Open-Drain, Digital
    // P1.2  -  CEX8  (PCA1), Open-Drain, Digital
    // P1.3  -  CEX9  (PCA1), Push-Pull,  Digital
    // P1.4  -  CEX10 (PCA1), Push-Pull,  Digital
    // P1.5  -  CEX11 (PCA1), Push-Pull,  Digital
    // P1.6  -  T4  (Timr4), Push-Pull,  Digital
    // P1.7  -  T5  (Timr5), Push-Pull,  Digital

    // P2.0  -  Unassigned,  Open-Drain, Analog
    // P2.1  -  Unassigned,  Open-Drain, Analog
    // P2.2  -  Unassigned,  Open-Drain, Digital
    // P2.3  -  Unassigned,  Open-Drain, Digital
    // P2.4  -  Unassigned,  Open-Drain, Analog
    // P2.5  -  Unassigned,  Open-Drain, Analog
    // P2.6  -  Unassigned,  Open-Drain, Digital
    // P2.7  -  Unassigned,  Open-Drain, Digital

    // P3.0  -  Unassigned,  Open-Drain, Digital
    // P3.1  -  Unassigned,  Open-Drain, Digital
    // P3.2  -  Unassigned,  Open-Drain, Digital
    // P3.3  -  Unassigned,  Open-Drain, Digital
    // P3.4  -  Unassigned,  Open-Drain, Digital
    // P3.5  -  Unassigned,  Open-Drain, Digital
    // P3.6  -  Unassigned,  Open-Drain, Digital
    // P3.7  -  Unassigned,  Push-Pull,  Digital

    // P4.0  -  Unassigned,  Push-Pull,  Digital [Fixed]
    // P4.1  -  Unassigned,  Push-Pull,  Digital [Fixed]
    // P4.2  -  Unassigned,  Open-Drain, Digital [Fixed]
    // P4.3  -  Unassigned,  Open-Drain, Digital [Fixed]
    // P4.4  -  Unassigned,  Open-Drain, Digital [Fixed]
    // P4.5  -  Unassigned,  Open-Drain, Digital [Fixed]
    // P4.6  -  Unassigned,  Push-Pull,  Digital [Fixed]
    // P4.7  -  Unassigned,  Push-Pull,  Digital [Fixed]

    SFRPAGE   = CONFIG_PAGE;
    P2MDIN    = 0xCC;
    P0MDOUT   = 0x54;
    P1MDOUT   = 0xF8;
    P3MDOUT   = 0x80;
    P4MDOUT   = 0xC3;
    P0SKIP    = 0x03;
    XBR0      = 0x01;
    XBR2      = 0x43;
    XBR3      = 0x56;
    SFRPAGE   = ACTIVE_PAGE;
}
void Voltage_Reference_Init()
{
    REF0CN    = 0x17;
}
void Oscillator_Init()
{
    int i = 0;
    SFRPAGE   = CONFIG_PAGE;
    CLKMUL    = 0x80;
    for (i = 0; i < 20; i++);    // Wait 5us for clock multiplier initialization
    CLKMUL    |= 0xC0;
    while ((CLKMUL & 0x20) == 0);
    CLKSEL    = 0x02;
    OSCICN    = 0xC7;
    SFRPAGE   = ACTIVE_PAGE;
}

void PCA0_Init()
{
    PCA0MD    &= ~0x40;
    PCA0MD    = 0x00;
}

// Initialization function for device,
// Call Init_Device() from your main program
void initDevice(void)
{
	//Reset_Sources_Init();
	//Voltage_Reference_Init();
	

	//Interrupts_Init();
	PCA0_Init();
	Oscillator_Init();
	Port_IO_Init();
}