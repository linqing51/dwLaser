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
    DAC0CN    = 0x80;
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
	//配置交叉开关前设置IO状态避免DAC复位或错误
	P6 |= (uint8_t)(1 << 3);//DAC CLR0 = 1
	P5 |= (uint8_t)(1 << 6);//DAC CLR1 = 1
	P5 |= (uint8_t)(1 << 1);//DAC CLR2 = 1
	P4 |= (uint8_t)(1 << 2);//DAC CLR3 = 1
	
	P6 |= (uint8_t)(1 << 0);//DAC NSS0 = 1
    P5 |= (uint8_t)(1 << 3);//DAC NSS1 = 1
	P4 |= (uint8_t)(1 << 6);//DAC NSS2 = 1
	P4 |= (uint8_t)(1 << 3);//DAC NSS3 = 1
	
	P5 &= ~(uint8_t)(1 << 7);//DAC LDAC0 = 0
	P5 &= ~(uint8_t)(1 << 2);//DAC LDAC1 = 0
	P4 &= ~(uint8_t)(1 << 5);//DAC LDAC2 = 0
	P4 &= ~(uint8_t)(1 << 4);//DAC LDAC3 = 0
	
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
    for (i = 0; i < 3000; i++);  // Wait 1ms for initialization
    while ((OSCXCN & 0x80) == 0);
    OSCICN    = 0x0F;
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
