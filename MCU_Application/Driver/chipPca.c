#include "chipPca.h"
//-----------------------------------------------------------------------------
// Global Constants
//-----------------------------------------------------------------------------

#define SYSCLK       24000000          // Internal oscillator frequency in Hz

#define CEX0_FREQUENCY  10000          // Frequency to output in Hz

#define DIVIDE_RATIO (SYSCLK/CEX0_FREQUENCY/2) // SYSCLK cycles per interrupt

//-----------------------------------------------------------------------------
// PCA0_Init
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None
//
// This function configures the PCA time base, and sets up High-Speed output
// mode for Module 0 (CEX0 pin).
//
// The frequency of the square wave generated at the CEX0 pin is defined by
// the parameter CEX0_FREQUENCY.
//
// The maximum square wave frequency output for this example is about 230 kHz.
// The minimum square wave frequency output for this example is about 190 Hz
//
// The PCA time base in this example is configured to use SYSCLK, and SYSCLK
// is set up to use the internal oscillator running at 24 MHz.
// Using different PCA clock sources or a different processor clock will
// result in a different frequency for the square wave, and different
// maximum and minimum options.
//
//    -------------------------------------------------------------------------
//    How "High Speed Output Mode" Works:
//
//       The PCA's High Speed Output Mode works by toggling the output pin
//    associated with the module every time the PCA0 register increments and
//    the new 16-bit PCA0 counter value matches the module's capture/compare
//    register (PCA0CPn). When initially enabled in high-speed output mode, the
//    CEXn pin associated with the module will be at a logic high state.  The
//    first match will cause a falling edge on the pin.  The next match will
//    cause a rising edge on the pin, and so on.
//
//    By loading the PCA0CPn register with the next match value every time a
//    match happens, arbitrary waveforms can be generated on the pin with high
//    levels of precision.
//    -------------------------------------------------------------------------
//
// When setting the capture/compare register for the next edge value, the low
//  byte of the PCA0CPn register (PCA0CPLn) should be written first, followed
//  by the high byte (PCA0CPHn).  Writing the low byte clears the ECOMn bit,
//  and writing the high byte will restore it.  This ensures that a match does
//  not occur until the full 16-bit value has been written to the compare
//  register.  Writing the high byte first will result in the ECOMn bit being
//  set to '0' after the 16-bit write, and the next match will not occur at
// the correct time.
//
// It is best to update the capture/compare register as soon after a match
//  occurs as possible so that the PCA counter will not have incremented past
//  the next desired edge value. This code implements the compare register
//  update in the PCA ISR upon a match interrupt.
//
//-----------------------------------------------------------------------------
//void PCA0_Init (void)
//{
//   U8 SFRPAGE_save = SFRPAGE;
//   SFRPAGE = ACTIVE_PAGE;
//   // Configure PCA time base; overflow interrupt disabled
//   PCA0CN = 0x00;                      // Stop counter; clear all flags
//   PCA0MD = 0x08;                      // Use SYSCLK as time base
//   PCA0CPM0 = 0x4D;                    // Module 0 = High Speed Output mode,
//                                       // Enable Module 0 Interrupt flag,
//                                       // Enable ECOM bit
//   PCA0L = 0x00;                       // Reset PCA Counter Value to 0x0000
//   PCA0H = 0x00;
//   PCA0CPL0 = DIVIDE_RATIO & 0x00FF;   // Set up first edge
//   PCA0CPH0 = (DIVIDE_RATIO & 0xFF00) >> 8;
//   // Set up the variable for the following edge
//   Next_Compare_Value = PCA0CP0 + DIVIDE_RATIO;
//   EIE1 |= 0x08;                       // Enable PCA interrupts
//   CR = 1;                             // Start PCA
//   SFRPAGE = SFRPAGE_save;
//}

////-----------------------------------------------------------------------------
//// Interrupt Service Routines
////-----------------------------------------------------------------------------

////-----------------------------------------------------------------------------
//// PCA0_ISR
////-----------------------------------------------------------------------------
////
//// Return Value : None
//// Parameters   : None
////
//// This is the ISR for the PCA.  It handles the case when a match occurs on
//// channel 0, and updates the PCA0CPn compare register with the value held in
//// the global variable "Next_Compare_Value".
////
////-----------------------------------------------------------------------------
//INTERRUPT(PCA0_ISR, INTERRUPT_PCA0)
//{
//   if (CCF0)                           // If Module 0 caused the interrupt
//   {
//      CCF0 = 0;                        // Clear module 0 interrupt flag.

//      PCA0CPL0 = (Next_Compare_Value & 0x00FF);
//      PCA0CPH0 = (Next_Compare_Value & 0xFF00) >> 8;

//      // Set up the variable for the following edge
//      Next_Compare_Value = PCA0CP0 + DIVIDE_RATIO;
//   }
//   else                                // Interrupt was caused by other bits.
//   {
//      PCA0CN &= ~0xBE;                 // Clear other interrupt flags for PCA
//   }
//}

//void loadPara(void *p)
//{//载入运行参数
////	p->
////	int16_t CurrentCh0;//激光器电流
////int16_t CurrentCh1;
////int8_t ModeCw;//连续
////int8_t ModeSp;//单脉冲
////int8_t ModeMp;//多脉冲
////int8_t ModeGp;//群脉冲
////int16_t PosWidth;//正脉宽
////int16_t NegWidth;//负脉宽
////int16_t GroupTime;//群脉冲间隔时间
////int8_t TimeBaseUS;//时基 uS
////int8_t TimeBaseMS;//时基 mS
////int8_t TimeBase_S;//时基 S
////int8_t SelectCh0;//only ch1
////int8_t SelectCh1;//only ch2
////int8_t SelectBoth;//both ch1 & ch2
//}
//void startLaser(void)
//{//开始发射脉冲
//	
//}
//void stopLaser(void)
//{//停止发射脉冲
//	ad5621_write(AD5621_LASER_CH1, 0);
//    ad5621_write(AD5621_LASER_CH2, 0);
//}

//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------