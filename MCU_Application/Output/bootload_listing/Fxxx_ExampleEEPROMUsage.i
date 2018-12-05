
#line 1 "FlashEprom\Fxxx_ExampleEEPROMUsage.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "\GitHub\dwLaser\MCU\Lib\stdbool.h" /0




 
 
 
 
 
 
 
 typedef bit bool;
 enum{
 false = 0,
 true = 1,
 };
 
 
#line 19 "\GitHub\dwLaser\MCU\Lib\stdbool.h" /1
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
#line 43 "\GitHub\dwLaser\MCU\Lib\stdbool.h" /0
 
 
 
#line 125 ".\Lib\compiler_defs.h" /0
 
  
#line 1 "\GitHub\dwLaser\MCU\Lib\stdint.h" /0




 
 
 
 
 
 
 
 typedef unsigned char uint8_t;
 typedef unsigned short uint16_t;
 typedef unsigned long uint32_t;
 typedef uint32_t uint64_t[2];
 
 typedef signed char int8_t;
 typedef short int16_t;
 typedef long int32_t;
 typedef int32_t int64_t[2];
 typedef float fp32_t;
 typedef double fp64_t;
 
 
#line 25 "\GitHub\dwLaser\MCU\Lib\stdint.h" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 51 "\GitHub\dwLaser\MCU\Lib\stdint.h" /0
 
 
#line 126 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 144 ".\Lib\compiler_defs.h" /1
 
 
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 360 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 398 ".\Lib\compiler_defs.h" /1
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
#line 415 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 typedef unsigned char U8;
 typedef unsigned int U16;
 typedef unsigned long U32;
 
 typedef signed char S8;
 typedef signed int S16;
 typedef signed long S32;
 
 typedef union UU16
 {
 U16 U16;
 S16 S16;
 U8 U8[2];
 S8 S8[2];
 } UU16;
 
 typedef union UU32
 {
 U32 U32;
 S32 S32;
 UU16 UU16[2];
 U16 U16[2];
 S16 S16[2];
 U8 U8[4];
 S8 S8[4];
 } UU32;
 
 
 extern void _nop_ (void);
 
 
 
 
 
 
 
 
 
 
 
 
 typedef union SI_GENERIC_PTR
 {
 U8 U8[3];
 struct
 {
 U8 MTYPE;
 UU16 ADDR;
 } GPTR;
 } SI_GENERIC_PTR;
 
 
 
 
 
 
 
#line 483 ".\Lib\compiler_defs.h" /1
 
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
 
  
 
  
 
  
  
  
 
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
 
  
  
 
 
 
 
  
  
  
 
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
 
 
#line 798 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 27 "FlashEprom\Fxxx_ExampleEEPROMUsage.c" /0
 
  
#line 1 "FlashEprom\Fxxx_EEPROM_Configuration.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 123 ".\Lib\compiler_defs.h" /1
  
 
  
  
 
 
 
 
 
 
  
 
 
  
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
 
  
 
  
 
  
  
  
 
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
 
  
  
 
 
 
 
  
  
  
 
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
#line 804 ".\Lib\compiler_defs.h" /0
 
 
 
 
#line 56 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 





#line 76 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 107 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 110 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 141 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

 
  
#line 1 ".\Lib\c8051f020_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  sfr P0 = 0x80;                         
  sfr SP = 0x81;                         
  sfr DPL = 0x82;                        
  sfr DPH = 0x83;                        
  sfr P4 = 0x84;                         
  sfr P5 = 0x85;                         
  sfr P6 = 0x86;                         
  sfr PCON = 0x87;                       
  sfr TCON = 0x88;                       
  sfr TMOD = 0x89;                       
  sfr TL0 = 0x8A;                        
  sfr TL1 = 0x8B;                        
  sfr TH0 = 0x8C;                        
  sfr TH1 = 0x8D;                        
  sfr CKCON = 0x8E;                      
  sfr PSCTL = 0x8F;                      
  sfr P1 = 0x90;                         
  sfr TMR3CN = 0x91;                     
  sfr TMR3RLL = 0x92;                    
  sfr TMR3RLH = 0x93;                    
  sfr TMR3L = 0x94;                      
  sfr TMR3H = 0x95;                      
  sfr P7 = 0x96;                         
  sfr SCON0 = 0x98;                      
  sfr SBUF0 = 0x99;                      
  sfr SPI0CFG = 0x9A;                    
  sfr SPI0DAT = 0x9B;                    
  sfr ADC1 = 0x9C;                       
  sfr SPI0CKR = 0x9D;                    
  sfr CPT0CN = 0x9E;                     
  sfr CPT1CN = 0x9F;                     
  sfr P2 = 0xA0;                         
  sfr EMI0TC = 0xA1;                     
  sfr EMI0CF = 0xA3;                     
  sfr P0MDOUT = 0xA4;                    
  sfr P1MDOUT = 0xA5;                    
  sfr P2MDOUT = 0xA6;                    
  sfr P3MDOUT = 0xA7;                    
  sfr IE = 0xA8;                         
  sfr SADDR0 = 0xA9;                     
  sfr ADC1CN = 0xAA;                     
  sfr ADC1CF = 0xAB;                     
  sfr AMX1SL = 0xAC;                     
  sfr P3IF = 0xAD;                       
  sfr SADEN1 = 0xAE;                     
  sfr EMI0CN = 0xAF;                     
  sfr P3 = 0xB0;                         
  sfr OSCXCN = 0xB1;                     
  sfr OSCICN = 0xB2;                     
  sfr P74OUT = 0xB5;                     
  sfr FLSCL = 0xB6;                      
  sfr FLACL = 0xB7;                      
  sfr IP = 0xB8;                         
  sfr SADEN0 = 0xB9;                     
  sfr AMX0CF = 0xBA;                     
  sfr AMX0SL = 0xBB;                     
  sfr ADC0CF = 0xBC;                     
  sfr P1MDIN = 0xBD;                     
  sfr ADC0L = 0xBE;                      
  sfr ADC0H = 0xBF;                      
  sfr SMB0CN = 0xC0;                     
  sfr SMB0STA = 0xC1;                    
  sfr SMB0DAT = 0xC2;                    
  sfr SMB0ADR = 0xC3;                    
  sfr ADC0GTL = 0xC4;                    
  sfr ADC0GTH = 0xC5;                    
  sfr ADC0LTL = 0xC6;                    
  sfr ADC0LTH = 0xC7;                    
  sfr T2CON = 0xC8;                      
  sfr T4CON = 0xC9;                      
  sfr RCAP2L = 0xCA;                     
  sfr RCAP2H = 0xCB;                     
  sfr TL2 = 0xCC;                        
  sfr TH2 = 0xCD;                        
  sfr SMB0CR = 0xCF;                     
  sfr PSW = 0xD0;                        
  sfr REF0CN = 0xD1;                     
  sfr DAC0L = 0xD2;                      
  sfr DAC0H = 0xD3;                      
  sfr DAC0CN = 0xD4;                     
  sfr DAC1L = 0xD5;                      
  sfr DAC1H = 0xD6;                      
  sfr DAC1CN = 0xD7;                     
  sfr PCA0CN = 0xD8;                     
  sfr PCA0MD = 0xD9;                     
  sfr PCA0CPM0 = 0xDA;                   
  sfr PCA0CPM1 = 0xDB;                   
  sfr PCA0CPM2 = 0xDC;                   
  sfr PCA0CPM3 = 0xDD;                   
  sfr PCA0CPM4 = 0xDE;                   
  sfr ACC = 0xE0;                        
  sfr XBR0 = 0xE1;                       
  sfr XBR1 = 0xE2;                       
  sfr XBR2 = 0xE3;                       
  sfr RCAP4L = 0xE4;                     
  sfr RCAP4H = 0xE5;                     
  sfr EIE1 = 0xE6;                       
  sfr EIE2 = 0xE7;                       
  sfr ADC0CN = 0xE8;                     
  sfr PCA0L = 0xE9;                      
  sfr PCA0CPL0 = 0xEA;                   
  sfr PCA0CPL1 = 0xEB;                   
  sfr PCA0CPL2 = 0xEC;                   
  sfr PCA0CPL3 = 0xED;                   
  sfr PCA0CPL4 = 0xEE;                   
  sfr RSTSRC = 0xEF;                     
  sfr B = 0xF0;                          
  sfr SCON1 = 0xF1;                      
  sfr SBUF1 = 0xF2;                      
  sfr SADDR1 = 0xF3;                     
  sfr TL4 = 0xF4;                        
  sfr TH4 = 0xF5;                        
  sfr EIP1 = 0xF6;                       
  sfr EIP2 = 0xF7;                       
  sfr SPI0CN = 0xF8;                     
  sfr PCA0H = 0xF9;                      
  sfr PCA0CPH0 = 0xFA;                   
  sfr PCA0CPH1 = 0xFB;                   
  sfr PCA0CPH2 = 0xFC;                   
  sfr PCA0CPH3 = 0xFD;                   
  sfr PCA0CPH4 = 0xFE;                   
  sfr WDTCN = 0xFF;                      
 
 
 
 
 
  sfr16 DP = 0x82;                       
  sfr16 TMR3RL = 0x92;                   
  sfr16 TMR3 = 0x94;                     
  sfr16 ADC0 = 0xBE;                     
  sfr16 ADC0GT = 0xC4;                   
  sfr16 ADC0LT = 0xC6;                   
  sfr16 RCAP2 = 0xCA;                    
  sfr16 T2 = 0xCC;                       
  sfr16 TMR2RL = 0xCA;                   
  sfr16 TMR2 = 0xCC;                     
  sfr16 RCAP4 = 0xE4;                    
  sfr16 T4 = 0xF4;                       
  sfr16 TMR4RL = 0xE4;                   
  sfr16 TMR4 = 0xF4;                     
  sfr16 DAC0 = 0xD2;                     
  sfr16 DAC1 = 0xD5;                     
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  sbit TF1 = 0x88^7;                
  sbit TR1 = 0x88^6;                
  sbit TF0 = 0x88^5;                
  sbit TR0 = 0x88^4;                
  sbit IE1 = 0x88^3;                
  sbit IT1 = 0x88^2;                
  sbit IE0 = 0x88^1;                
  sbit IT0 = 0x88^0;                
 
 
  sbit SM00 = 0x98^7;              
  sbit SM10 = 0x98^6;              
  sbit SM20 = 0x98^5;              
  sbit REN0 = 0x98^4;              
  sbit TB80 = 0x98^3;              
  sbit RB80 = 0x98^2;              
  sbit TI0 = 0x98^1;               
  sbit RI0 = 0x98^0;               
 
 
  sbit EA = 0xA8^7;                   
  sbit IEGF0 = 0xA8^6;                
  sbit ET2 = 0xA8^5;                  
  sbit ES0 = 0xA8^4;                  
  sbit ET1 = 0xA8^3;                  
  sbit EX1 = 0xA8^2;                  
  sbit ET0 = 0xA8^1;                  
  sbit EX0 = 0xA8^0;                  
 
 
 
 
  sbit PT2 = 0xB8^5;                  
  sbit PS = 0xB8^4;                   
  sbit PT1 = 0xB8^3;                  
  sbit PX1 = 0xB8^2;                  
  sbit PT0 = 0xB8^1;                  
  sbit PX0 = 0xB8^0;                  
 
 
  sbit BUSY = 0xC0^7;             
  sbit ENSMB = 0xC0^6;            
  sbit STA = 0xC0^5;              
  sbit STO = 0xC0^4;              
  sbit SI = 0xC0^3;               
  sbit AA = 0xC0^2;               
  sbit SMBFTE = 0xC0^1;           
  sbit SMBTOE = 0xC0^0;           
 
 
  sbit TF2 = 0xC8^7;               
  sbit EXF2 = 0xC8^6;              
  sbit RCLK0 = 0xC8^5;             
  sbit TCLK0 = 0xC8^4;             
  sbit EXEN2 = 0xC8^3;             
  sbit TR2 = 0xC8^2;               
  sbit CT2 = 0xC8^1;               
  sbit CPRL2 = 0xC8^0;             
 
 
  sbit CY = 0xD0^7;                  
  sbit AC = 0xD0^6;                  
  sbit F0 = 0xD0^5;                  
  sbit RS1 = 0xD0^4;                 
  sbit RS0 = 0xD0^3;                 
  sbit OV = 0xD0^2;                  
  sbit F1 = 0xD0^1;                  
  sbit P = 0xD0^0;                   
 
 
  sbit CF = 0xD8^7;               
  sbit CR = 0xD8^6;               
 
  sbit CCF4 = 0xD8^4;             
  sbit CCF3 = 0xD8^3;             
  sbit CCF2 = 0xD8^2;             
  sbit CCF1 = 0xD8^1;             
  sbit CCF0 = 0xD8^0;             
 
 
  sbit AD0EN = 0xE8^7;            
  sbit AD0TM = 0xE8^6;            
  sbit AD0INT = 0xE8^5;           
  sbit AD0BUSY = 0xE8^4;          
  sbit AD0CM1 = 0xE8^3;           
  sbit AD0CM0 = 0xE8^2;           
  sbit AD0WINT = 0xE8^1;          
  sbit AD0LJST = 0xE8^0;          
 
 
  sbit SPIF = 0xF8^7;             
  sbit WCOL = 0xF8^6;             
  sbit MODF = 0xF8^5;             
  sbit RXOVRN = 0xF8^4;           
  sbit TXBSY = 0xF8^3;            
  sbit SLVSEL = 0xF8^2;           
  sbit MSTEN = 0xF8^1;            
  sbit SPIEN = 0xF8^0;            
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 337 ".\Lib\c8051f020_defs.h" /1
 
 
 
 
#line 341 ".\Lib\c8051f020_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 147 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
 
 
 
 
 
 
 
 















 
 
 
 
 
 
 


#line 183 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 214 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 217 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 248 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 


#line 254 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 285 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 288 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 319 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 




#line 327 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 358 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 361 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 392 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 



#line 399 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 430 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 435 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 450 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 453 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 469 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 472 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
 
#line 474 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

 
 
#error *** WARNING C318 IN LINE 480 OF FlashEprom\Fxxx_Flash_Parameters.h: can't open file 'c8051f310_defs.h'
 
#error *** WARNING C317 IN LINE 481 OF FlashEprom\Fxxx_Flash_Parameters.h: attempt to redefine macro 'ENABLE_VDDMON'
 
#error *** WARNING C317 IN LINE 482 OF FlashEprom\Fxxx_Flash_Parameters.h: attempt to redefine macro 'DISABLE_WDT'
 
 
 
 
 
 
 
#error *** WARNING C317 IN LINE 489 OF FlashEprom\Fxxx_Flash_Parameters.h: attempt to redefine macro 'LOCK_PAGE'
 
 
#error *** WARNING C317 IN LINE 491 OF FlashEprom\Fxxx_Flash_Parameters.h: attempt to redefine macro 'ENABLE_FL_MOD'
 
#error *** WARNING C317 IN LINE 492 OF FlashEprom\Fxxx_Flash_Parameters.h: attempt to redefine macro 'DISABLE_FL_MOD'
 
#error *** WARNING C317 IN LINE 493 OF FlashEprom\Fxxx_Flash_Parameters.h: attempt to redefine macro 'FL_PROTECT'
 
 
 
 

#line 499 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 515 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 519 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 535 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 539 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 555 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 560 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 576 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 579 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 595 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 598 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 614 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 617 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
 
#line 619 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 



#line 626 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 642 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 



#line 648 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 664 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 669 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 685 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 



#line 692 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 708 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 711 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 727 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 731 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 747 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 750 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 766 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 


#line 772 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 788 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 


#line 793 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 809 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 814 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 830 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 834 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 850 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 854 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
 
#line 856 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 861 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 877 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 881 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 897 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 





#line 906 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 922 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 





#line 930 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 946 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 


#line 952 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 968 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 


#line 973 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 989 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 


#line 995 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1011 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 1015 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1031 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 



#line 1037 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1053 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 





#line 1062 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1078 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 








#line 1089 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1105 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 


#line 1110 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1126 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 1130 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1146 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 1149 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1165 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 1169 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1185 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 1188 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1204 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 



#line 1211 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1227 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 1231 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1247 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 1250 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
 
#line 1252 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
#line 1254 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
 
#line 1256 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
 
 
#line 19 "FlashEprom\Fxxx_EEPROM_Configuration.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 54 "FlashEprom\Fxxx_EEPROM_Configuration.h" /1
 
 
#line 56 "FlashEprom\Fxxx_EEPROM_Configuration.h" /0
 
 
#line 58 "FlashEprom\Fxxx_EEPROM_Configuration.h" /1
 
 
#line 60 "FlashEprom\Fxxx_EEPROM_Configuration.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 28 "FlashEprom\Fxxx_ExampleEEPROMUsage.c" /0
 
  
#line 1 "FlashEprom\Fxxx_EEPROM_Interface.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 extern U8 EEPROM_WriteBlock (U8, U8 *, U8);
 extern U8 EEPROM_ReadBlock (U8, U8 *, U8);
 
 
 
 
 
 
#line 29 "FlashEprom\Fxxx_ExampleEEPROMUsage.c" /0
 
 
 
 
 
 void main (void) 
 {
  U8 data ramBuffer[32];
 U8 bufferCount;
  
  
  WDTCN = 0xDE; WDTCN = 0xAD;
  
 
 
 if (EEPROM_ReadBlock(0, ramBuffer, 1) != 0x00)
 {
 while(1);       
 }
 ramBuffer[0] += 5;
 
 
 for (bufferCount = 1; bufferCount < 32; bufferCount++)
 {
 ramBuffer[bufferCount] = ~ramBuffer[bufferCount-1];
 }
 
 
 if (EEPROM_WriteBlock (0, ramBuffer, 32) != 0x00)
 {
 while(1);       
 }
 
 
 if (EEPROM_ReadBlock(0, ramBuffer, 32) != 0x00)
 {
 while(1);       
 }
 
 while(1);          
 }
 
 
 
 
