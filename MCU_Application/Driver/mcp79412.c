#include "mcp79412.h"
/*****************************************************************************/
#define I2C_ADDRESS_MCP79412_EPROM 					0xAE
#define I2C_ADDRESS_MCP79412_SRAM					0xDE
#define I2C_ADDRESS_MCP79412_RTCC					0xDE
#define REG_MCP79412_RTCC_SECONDS					0x00                   
#define REG_MCP79412_RTCC_MINUTES					0x01
#define REG_MCP79412_RTCC_HOURS						0x02
#define REG_MCP79412_RTCC_DAY						0x03
#define REG_MCP79412_RTCC_DATE						0x04
#define REG_MCP79412_RTCC_MONTH						0x05
#define REG_MCP79412_RTCC_YEAR						0x06
#define REG_MCP79412_RTCC_CONTROL					0x07
#define REG_MCP79412_RTCC_CALIBRATION				0x08
#define REG_MCP79412_RTCC_UNLOCKID					0x09
#define REG_MCP79412_RTCC_ALARM0_SECONDS			0x0A
#define REG_MCP79412_RTCC_ALARM0_MINUTES			0x0B
#define REG_MCP79412_RTCC_ALARM0_HOURS				0x0C
#define REG_MCP79412_RTCC_ALARM0_DAY				0x0D
#define REG_MCP79412_RTCC_ALARM0_DATE				0x0E
#define REG_MCP79412_RTCC_ALARM0_MONTH				0x0F

#define REG_MCP79412_RTCC_ALARM1_SECONDES			0x11
#define REG_MCP79412_RTCC_ALARM1_MINUTES			0x12
#define REG_MCP79412_RTCC_ALARM1_HOURS				0x13
#define REG_MCP79412_RTCC_ALARM1_DAY				0x14
#define REG_MCP79412_RTCC_ALARM1_DATE				0x15
#define REG_MCP79412_RTCC_ALARM1_MONTH				0x16





////..........................................................................................................
////                              GLOBAL VARIABLES 
////..........................................................................................................
// char *tim  = "time "                          ;  // 'time' string 
// char *date = "date 20"                        ;  // 'date' string , add century 
// unsigned char sec, min, hr, day, dat, mon, yr ;  // time/date variables, BCD format  
// extern unsigned char err_flg                  ;  // error flag ; reacts at slave's wrong NACK
//                                                  // when the PicTail is unplugged 



////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
////                    INCREMENT TIME/DATE VARIABLES
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//   void incr_yr(void)                // increments YEARS value (2 digits)
//                                     // 99-->00 , yy-->y(y+1) , y9-->(y+1)0  
//   { if(yr==0x99) { yr = 0x00 ; }    // 99-->00  
//     else if ((yr&0x0f)==0x09)       // y9-->(y+1)0    
//          {  yr=(yr+16)&0xf0  ; }  
//          else {   yr++       ; }    // yy-->y(y+1)
//     yr_to_lcd(); back_lcd(2) ; }    // display year value; turn back cursor, 2 positions
////................................................................................................
//   void incr_mon(void) {             // increments MONTHS value 
//   if(mon>0x12) {mon = 0x01  ;  }    // just in case of an unexpected error 
//    switch(mon) {                    // LP bit was already masked at reads(display_time())
//     case 0x09: {mon=0x10;break;}    // 09 --> 10  
//     case 0x12: {mon=0x01;break;}    // 12 --> 01 
//       default: {mon++   ;break;} }  // in any other case, increment MONTH 
//     mon_to_lcd() ; back_lcd(2) ; }  // display month value, turn back cursor 2 positions 
////................................................................................................
//   void incr_dat(void) {             // increments DATE
//   if(dat>0x31) { dat = 0x01 ;  }    // just in case of an unexpected error 
//     switch(dat) {                   // DATE has no auxiliary flags  
//     case 0x31: {dat = 0x01;break;}  // overflow after 31 days 
//     case 0x09: {dat = 0x10;break;}  // 09 --> 10 (decimal) 
//     case 0x19: {dat = 0x20;break;}  // 19 --> 20 (decimal) 
//     case 0x29: {dat = 0x30;break;}  // 29 --> 30 )decimal) 
//     default:   {dat++;     break;}} // if no decimal overflow, incr DATE 
//     dat_to_lcd()  ; back_lcd(2) ; } // display date value, turn back cursor 2 positions  
////................................................................................................
//   void incr_hr(void){               // increments HOURS value
//   if(hr>0x23)  { hr = 0x00 ;    }   // just in case of an unexpected error   
//     switch(hr) {                    // none auxiliary control/status bits
//     case 0x23: {hr = 0x00;break;}   // '24h' format, overflow after '23'
//     case 0x19: {hr = 0x20;break;}   // 19 --> 20 
//     case 0x09: {hr = 0x10;break;}   // 09 --> 10 
//     default:   {hr++;     break;} } // in any other case, increment value
//     hr_to_lcd()  ; back_lcd(2) ;  } // display date value 
////................................................................................................
//   void incr_min(void)               // increments MINUTES ('minutes' have no aux flags)  
//   { if(min >= 0x59)  {min=0x00;}    // overflow after 59 minutes
//     else if ((min&0x0f)==0x09)      // m9 --> (m+1)0 
//          { min = (min+16)&0xf0 ; }  
//          else { min++ ; }           // mm --> m(m+1) 
//     min_to_lcd() ; back_lcd(2) ; }  // display new MINUTES value    
////................................................................................................ 
//   void incr_sec(void)               // increments SECONDS ; bit7 = ST = 1 
//  { sec = sec & (~START_32KHZ)    ;  // clear START bit 
//    if(sec >= 0x59)  { sec=0x00 ; }  // overflow after 59 seconds 
//     else if ((sec&0x0f)==0x09)      // s9 --> (s+1)0 
//          { sec = (sec+16)&0xf0 ; }  
//          else { sec++ ; }           // ss --> s(s+1)  
//    sec_to_lcd() ;  back_lcd(2) ; }  // display new SECONDS value    
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
////                      DISPLAY TIME/DATE FUNCTION 
////................................................................................................    
//     void display_time(void)      {  // DISPLAYS ALL TIME/DATE VARIABLES : 
//                                     // YEAR, MONTH, DATE, HOUR, MINUTES, SECONDS  
//    yr  = i2c_rtcc_rd(ADDR_YEAR)  ;  // read YEAR        
//    if(err_flg)          return   ;  // if an error occured at a PICTAIL removal,
//                                     // leave fast the interrupt routine
//    mon = i2c_rtcc_rd(ADDR_MNTH)  ;  // read MONTH 
//    if(err_flg) return            ;  // if error, leave fast the interrupt routine 
//    mon = mon & (~LP)             ;  // mask the leap year bit 
//    dat = i2c_rtcc_rd(ADDR_DATE)  ;  // read DATE 
//    if(err_flg)          return   ;  // if error, leave fast the interrupt routine
//    hr  = i2c_rtcc_rd(ADDR_HOUR)  ;  // read HOUR
//    if(err_flg)          return   ;  // if error, leave fast the interrupt routine                 
//    min = i2c_rtcc_rd(ADDR_MIN)   ;  // read MIN
//    if(err_flg)          return   ;  // if error, leave fast the interrupt routine 
//    sec = i2c_rtcc_rd(ADDR_SEC)   ;  // read SEC 
//    if(err_flg)          return   ;  // if error, leave fast the interrupt routine  
//wrcmnd_lcd(SET_DDRAM+N2_ROW1+07)  ;  // once finished the RTCC READ,set YEAR position on the first row     
//yr_to_lcd()  ;  wrdata_lcd(' ')   ;  // display YEAR  + separator    
//mon_to_lcd() ;  wrdata_lcd(' ')   ;  // display MONTH + separator  
//dat_to_lcd() ;                       // display DATE
//wrcmnd_lcd(SET_DDRAM+N2_ROW2+07)  ;  // set HOUR position on the second row   
//hr_to_lcd()  ;  wrdata_lcd(' ')   ;  // display HOUR  + separator          
//min_to_lcd()                      ;  // display MINUTES
//if(sec%2)    {wrdata_lcd(':') ;   }  // display separator for odd  seconds         
//else         {wrdata_lcd(' ') ;   }  // display separator for even seconds  
//sec_to_lcd()                  ;   }  // display SECONDS, end of DISPLAY function
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
////                        INIT, START/STOP INTERRUPTS 
////¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
//    void ini_intr(void)           {   // initialize INT1 
//    INTCON2bits.INT1EP = 1        ;   // +edge on INT1 = MFP 
//    IFS1bits.INT1IF    = 0        ;   // clear INT1 interrupt flag 
//    IEC1bits.INT1IE    = 0        ;   // disable INT1 
//    IPC5          = 0x0007   ;    }   // max priority for INT1 
// //...............................................................................................
//    void stop_intr(void)          {   // disable INT1 external interrupt 
//    IEC1bits.INT1IE    = 0   ;    }   // disable INT1
// //...............................................................................................
//    void start_intr(void)         {   // enable  INT1 external interrupt
//    IEC1bits.INT1IE    = 1   ;    }   // enable  INT1          
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//    void ini_tim1(void)      {        // initialization of TIMER1 
//    T1CON = 0x0010           ;        // stop TMR1, psc = 08 / 0.5usec  
//    PR1   = 200              ;        //   
//    TMR1  = 0x0000           ;   }    // clear the timer
////~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
////                             MAIN FUNCTION 
////................................................................................................
//int main(void){                       // electronic watch, with display and setup 
//ini_gpio()     		       		  ;   // init the GPIO ports
//TRISEbits.TRISE8 = 1              ;   // RE8 = IN for INT1 = MFP
//ini_tim1()                        ;   // init TMR1 for the time-out in the I2C comm         
//ini_i2c1()					      ;   // init the I2C module
//ini_i2c_rtcc()					  ;   // init the I2C RTCC device (enable the battery back-up)
//i2c_rtcc_wr(ADDR_CTRL,SQWE+ALM_NO+MFP_01H);  
//                                      // square wave on MFP, no alarms, MFP = 1Hz(CONTROL REG)
//ini_i2c_time()				      ;   // init time: 1.11.2011, 00:00:00 AM  
//ini_lcd()		              	  ;   // init the LCD module 
//									  // 8bits, 2 lines, shift right cursor MODE,display=ON
//clr_lcd()						  ;   // clear LCD
//wrcmnd_lcd(DISPLAY+D_ON)          ;   // shut down CURSOR & BLINK (keep the display)  
//wrstr_lcd(date)                   ;   // write in LCD : "date 20" 
//wrcmnd_lcd(SET_DDRAM+N2_ROW2)     ;   // set cursor on the second row 
//wrstr_lcd(tim)                    ;   // write in LCD : "time"
//ini_intr()                        ;   // initialize INT1: +edge, disable intr, max priority
//start_intr()                      ;   // enable INT1
//										  
//while(1){                             // infinite loop  
//while(keyb_press()==KEYB_INCR)    ;   // wait Interrupts till the MENU_KEY is pressed
//                                      // Interrupts display the current time/date 
//stop_intr()                       ;   // disable interrupts after entering the setup menu 
//wrcmnd_lcd(DISPLAY+D_ON+C_ON+B_ON);   // start cursor & blink 
//wrcmnd_lcd(SET_DDRAM+N2_ROW1+07)  ;   // set LCD_addr for YEAR 

//while(keyb_press()==KEYB_INCR)        // at every action of INCR KEY,
//{ incr_yr()  ;  }                     // year++ , exit only when MENU KEY = ON
//wrcmnd_lcd(SET_DDRAM+N2_ROW1+10)  ;   // set LCD_addr for MONTH
//   
//while(keyb_press()==KEYB_INCR)        // at every action of INCR KEY,
//{ incr_mon() ;  }                     // month++ , exit only when MENU KEY = ON
//wrcmnd_lcd(SET_DDRAM+N2_ROW1+13)  ;   // set LCD_addr for DATE 
// 
//while(keyb_press()==KEYB_INCR)        // at every action of INCR KEY,
//{ incr_dat() ;  }                     // date++ , exit only when MENU KEY = ON
//wrcmnd_lcd(SET_DDRAM+N2_ROW2+07)  ;   // set LCD_addr for HOUR
// 
//while(keyb_press()==KEYB_INCR)        // at every action of INCR KEY,
//{ incr_hr()  ;  }                     // hour++ , exit only when MENU KEY = ON
//wrcmnd_lcd(SET_DDRAM+N2_ROW2+10)  ;   // set LCD_addr for MINUTES

//while(keyb_press()==KEYB_INCR)        // at every action of INCR KEY,
//{ incr_min() ;  }                     // minutes++ , exit only when MENU KEY = ON
//wrcmnd_lcd(SET_DDRAM+N2_ROW2+13)  ;   // set LCD_addr for SECONDS 

//while(keyb_press()==KEYB_INCR)        // at every action of INCR KEY,
//{ incr_sec() ;  }                     // seconds++ , exit only when MENU KEY = ON
//                                      // once the SETUP MENU is exit
//wrcmnd_lcd(DISPLAY+D_ON)          ;   // stop cursor & blink 
//   
//err_flg = 0x00                    ;   // clear error variable 
//LATA    = 0x00                    ;   // clear the breakpoint on LEDs   
//i2c_rtcc_wr(ADDR_YEAR,yr)         ;   // update YEAR    value in RTCC
//i2c_rtcc_wr(ADDR_MNTH,mon)        ;   // update MONTH   value in RTCC
//                                      // LP bit is read only; you may clear it. 
//i2c_rtcc_wr(ADDR_DATE,dat)        ;   // update DATE    value in RTCC
//i2c_rtcc_wr(ADDR_HOUR,hr)         ;   // update HOUR    value in RTCC                
//i2c_rtcc_wr(ADDR_MIN,min)         ;   // update MINUTES value in RTCC
//sec = sec | START_32KHZ           ;   // restore oscillator START bit
//i2c_rtcc_wr(ADDR_SEC,sec)         ;   // update SECONDS value in RTCC   
//delayms(200)                      ;   // delay to avoid keyboard debounce 
//start_intr()                      ;   // enable again interrupts       
//                                  }   // END OF WHILE(1)   	
//return 0                       ;  }   // END OF MAIN
