/////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////

#include "InitDeviceF020.h"

// Peripheral specific initialization functions,
// Called from the Init_Device() function
static void Reset_Sources_Init(){
    WDTCN     = 0xDE;
    WDTCN     = 0xAD;
}

static void DAC_Init(){
	DAC0CN    = 0x84;
    DAC1CN    = 0x84;
}

static void Voltage_Reference_Init(){
    REF0CN    = 0x07;
}

void Port_IO_Init(){
    // P0.0  -  TX0 (UART0), Push-Pull,  Digital
    // P0.1  -  RX0 (UART0), Open-Drain, Digital
    // P0.2  -  TX1 (UART1), Open-Drain, Digital
    // P0.3  -  RX1 (UART1), Open-Drain, Digital
    // P0.4  -  Unassigned,  Push-Pull,  Digital
    // P0.5  -  Unassigned,  Push-Pull,  Digital
    // P0.6  -  Unassigned,  Push-Pull,  Digital
    // P0.7  -  Unassigned,  Push-Pull,  Digital

    // P1.0  -  Unassigned,  Push-Pull,  Digital
    // P1.1  -  Unassigned,  Push-Pull,  Digital
    // P1.2  -  Unassigned,  Push-Pull,  Digital
    // P1.3  -  Unassigned,  Push-Pull,  Digital
    // P1.4  -  Unassigned,  Push-Pull,  Digital
    // P1.5  -  Unassigned,  Push-Pull,  Digital
    // P1.6  -  Unassigned,  Push-Pull,  Digital
    // P1.7  -  Unassigned,  Push-Pull,  Digital

    // P2.0  -  Unassigned,  Push-Pull,  Digital
    // P2.1  -  Unassigned,  Push-Pull,  Digital
    // P2.2  -  Unassigned,  Push-Pull,  Digital
    // P2.3  -  Unassigned,  Push-Pull,  Digital
    // P2.4  -  Unassigned,  Push-Pull,  Digital
    // P2.5  -  Unassigned,  Push-Pull,  Digital
    // P2.6  -  Unassigned,  Push-Pull,  Digital
    // P2.7  -  Unassigned,  Push-Pull,  Digital

    // P3.0  -  Unassigned,  Push-Pull,  Digital
    // P3.1  -  Unassigned,  Push-Pull,  Digital
    // P3.2  -  Unassigned,  Push-Pull,  Digital
    // P3.3  -  Unassigned,  Push-Pull,  Digital
    // P3.4  -  Unassigned,  Push-Pull,  Digital
    // P3.5  -  Unassigned,  Push-Pull,  Digital
    // P3.6  -  Unassigned,  Push-Pull,  Digital
    // P3.7  -  Unassigned,  Push-Pull,  Digital
	//≈‰÷√Ωª≤Êø™πÿ«∞…Ë÷√IO◊¥Ã¨±‹√‚DAC∏¥ŒªªÚ¥ÌŒÛ	
	P0MDOUT   = 0xF1;
    P1MDOUT   = 0xFF;
    P2MDOUT   = 0xFF;
    P3MDOUT   = 0xFF;
    P74OUT    = 0x1F;
    XBR0      = 0x04;
    XBR2      = 0x44;
}

static void Oscillator_Init(){
    int i = 0;
    OSCXCN    = 0x67;
    for (i = 0; i < 3000; i++){// Wait 1ms for initialization
		_nop_();
	}
    while ((OSCXCN & 0x80) == 0);
    OSCICN  = 0x0F;
	OSCICN |= 0x80;// πƒ‹ ±÷”∂™ ßºÏ≤‚∆˜
}

static void Interrupts_Init(){
}

// Initialization function for device,
// Call Init_Device() from your main program
void initDeviceF020(void){
    Reset_Sources_Init();
    DAC_Init();
    Voltage_Reference_Init();
    Port_IO_Init();
    Oscillator_Init();
    Interrupts_Init();
}
