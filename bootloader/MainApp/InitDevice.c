/////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////
#include "InitDevice.h"
// Peripheral specific initialization functions,
// Called from the Init_Device() function
static void Reset_Sources_Init(){
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
	SFRPAGE = LEGACY_PAGE;
    RSTSRC    = 0x06;
    WDTCN     = 0xDE;
    WDTCN     = 0xAD;
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFRPAGE	
}
static void Voltage_Reference_Init(void){
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
	SFRPAGE = LEGACY_PAGE;
    REF0CN    = 0x07;
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFRPAGE
}

void Port_IO_Init(){ 
    // P0.0  -  TX0 (UART0), Push-Pull,  Digital
    // P0.1  -  RX0 (UART0), Open-Drain, Digital
    // P0.2  -  SCK  (SPI0), Push-Pull,  Digital
    // P0.3  -  MISO (SPI0), Open-Drain, Digital
    // P0.4  -  MOSI (SPI0), Push-Pull,  Digital
    // P0.5  -  NSS  (SPI0), Push-Pull,  Digital
    // P0.6  -  SDA (SMBus), Open-Drain, Digital
    // P0.7  -  SCL (SMBus), Open-Drain, Digital

    // P1.0  -  TX1 (UART1), Push-Pull,  Digital
    // P1.1  -  RX1 (UART1), Open-Drain, Digital
    // P1.2  -  CEX0 (PCA),  Push-Pull,  Digital
    // P1.3  -  CEX1 (PCA),  Push-Pull,  Digital
    // P1.4  -  CEX2 (PCA),  Push-Pull,  Digital
    // P1.5  -  Unassigned,  Push-Pull,  Digital
    // P1.6  -  Unassigned,  Push-Pull,  Digital
    // P1.7  -  Unassigned,  Open-Drain, Digital

    // P2.0  -  Unassigned,  Push-Pull,  Digital
    // P2.1  -  Unassigned,  Push-Pull,  Digital
    // P2.2  -  Unassigned,  Push-Pull,  Digital
    // P2.3  -  Unassigned,  Push-Pull,  Digital
    // P2.4  -  Unassigned,  Push-Pull,  Digital
    // P2.5  -  Unassigned,  Push-Pull,  Digital
    // P2.6  -  Unassigned,  Push-Pull,  Digital
    // P2.7  -  Unassigned,  Push-Pull,  Digital

    // P3.0  -  Unassigned,  Open-Drain, Digital
    // P3.1  -  Unassigned,  Open-Drain, Digital
    // P3.2  -  Unassigned,  Open-Drain, Digital
    // P3.3  -  Unassigned,  Open-Drain, Digital
    // P3.4  -  Unassigned,  Push-Pull,  Digital
    // P3.5  -  Unassigned,  Push-Pull,  Digital
    // P3.6  -  Unassigned,  Push-Pull,  Digital
    // P3.7  -  Unassigned,  Push-Pull,  Digital

  	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
	SFRPAGE = CONFIG_PAGE;// Set SFR page
    P0MDOUT   = 0x35;
    P1MDOUT   = 0x7D;
    P2MDOUT   = 0xFF;
    P3MDOUT   = 0xF0;
    P4MDOUT   = 0x04;
    P6MDOUT   = 0xFE;
    P7MDOUT   = 0x11;
    XBR0      = 0x1F;
    XBR2      = 0x44;                  // Set CEX0 (P0.0) to push-pull
	SFRPAGE = LEGACY_PAGE;
}

static void Oscillator_Init()
{
	int16_t i;// Software timer
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
	SFRPAGE = CONFIG_PAGE;// Set SFR page
	OSCICN = 0x80; // Set internal oscillator to run
                                       // at its slowest frequency
	CLKSEL = 0x00;                      // Select the internal osc. as
                                       // the SYSTEMCLOCK source
	// Initialize external crystal oscillator to use 22.1184 MHz crystal
	OSCXCN = 0x67;                      // Enable external crystal osc.
	for (i=0; i < 256; i++);            // Wait at least 1ms
	while (!(OSCXCN & 0x80));           // Wait for crystal osc to settle
	SFRPAGE = LEGACY_PAGE;
	FLSCL |=  0x30;                     // Initially set FLASH read timing for
									   // 100MHz SYSTEMCLOCK (most conservative
									   // setting)
#if	CONFIG_SYSCLK <= 25000000
		FLSCL &= ~0x30;//Set FLASH read timing for <=25MHz
#elseif CONFIG_SYSCLK <= 50000000
		FLSCL &= ~0x20;//Set FLASH read timing for <=50MHz
#elseif CONFIG_SYSCLK <= 75000000
		FLSCL &= ~0x10;//Set FLASH read timing for <=75MHz
#else                            
		FLSCL &= ~0x00;// set FLASH read timing for <=100MHz
#endif
	// Start PLL for 50MHz operation
	SFRPAGE = PLL0_PAGE;
	PLL0CN = 0x04;                      // Select EXTOSC as clk source
	PLL0CN |= 0x01;                     // Enable PLL power
	PLL0DIV = 0x01;                     // Divide by 1
	PLL0FLT &= ~0x0f;
	PLL0FLT |=  0x0f;                   // Set Loop Filt for (22/4)MHz input clock
	PLL0FLT &= ~0x30;                   // Set ICO for 30-60MHz
	PLL0FLT |=  0x10;
	PLL0MUL = 0x04;                     // Multiply by 4
	// wait at least 5us
	for (i = 0; i < 256; i++) ;
	PLL0CN |= 0x02;                     // Enable PLL
	while (PLL0CN & 0x10 == 0x00);      // Wait for PLL to lock
	SFRPAGE = CONFIG_PAGE;
	CLKSEL = 0x02;                      // Select PLL as SYSTEMCLOCK source
	SFRPAGE = SFRPAGE_SAVE;             // Restore SFRPAGE
}
// Initialization function for device,
// Call Init_Device() from your main program
void initDevice(void){
    Reset_Sources_Init();
    Voltage_Reference_Init();
    Port_IO_Init();
    Oscillator_Init();
}
