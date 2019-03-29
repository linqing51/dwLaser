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

static void DAC_Init(){
    DAC0CN    = 0x80;
}

static void Voltage_Reference_Init(void){
    REF0CN    = 0x07;
}

void Port_IO_Init()
{

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
	if(CONFIG_SYSCLK <= 25000000){//Set FLASH read timing for <=25MHz
		FLSCL &= ~0x30;
	}else if (CONFIG_SYSCLK <= 50000000){//Set FLASH read timing for <=50MHz
		FLSCL &= ~0x20;
	}else if (CONFIG_SYSCLK <= 75000000){//Set FLASH read timing for <=75MHz
		FLSCL &= ~0x10;
	} else {                            // set FLASH read timing for <=100MHz
		FLSCL &= ~0x00;
	}
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
