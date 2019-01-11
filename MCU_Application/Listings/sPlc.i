
#line 1 "MainApp\sPlc.c" /0
  
#line 1 "MainApp\sPlc.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
 
 
 
 
#line 6 "MainApp\appConfig.h" /1
  
  
 
#line 9 "MainApp\appConfig.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 ".\Lib\stdint.h" /0




 
 
 
 
 
 
 
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
 
 
#line 25 ".\Lib\stdint.h" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 51 ".\Lib\stdint.h" /0
 
 
#line 120 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\stdbool.h" /0




 
 
 
 
 
 
 
 typedef bit bool;
 enum{
 false = 0,
 true = 1,
 };
 
 
#line 19 ".\Lib\stdbool.h" /1
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
#line 43 ".\Lib\stdbool.h" /0
 
 
 
#line 121 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\endian.h" /0




 
 
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 31 ".\Lib\endian.h" /1
 
  
  
  
  
 
  
  
  
  
 
 
 
  
  
  
  
 
  
  
  
  
 
 
#line 55 ".\Lib\endian.h" /0
 
 
#line 122 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\si_toolchain.h" /0




 
 
 
 
 
  
#line 1 ".\Lib\stdint.h" /0




 
 
 
#line 8 ".\Lib\stdint.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 10 ".\Lib\si_toolchain.h" /0
#line 10 ".\Lib\si_toolchain.h" /0
 
  
#line 1 ".\Lib\stdbool.h" /0




 
 
 
#line 8 ".\Lib\stdbool.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 45 ".\Lib\stdbool.h" /0
 
#line 11 ".\Lib\si_toolchain.h" /0
 
 





















































 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 




 
 
 









 
 
 










 
 
 










 
 
 
 













 
 
 



















 
 

 














 
 
 


















 
 
 































 
 

 














 
 

 






































 
 

 
















 
 

 




























 
 
 



























 
 

 






























 
 

 





























 
 
 





























 
 

 
 
 
#line 501 ".\Lib\si_toolchain.h" /1
  
  
  
  
 
  
  
 
  
  
 
 
  
  
  
  
  
 
#line 519 ".\Lib\si_toolchain.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef union SI_UU16
 {
 uint16_t u16;    
 int16_t s16;     
 uint8_t u8[2];   
 int8_t s8[2];    
 } SI_UU16_t;
 
 
 
 
 typedef union SI_UU32
 {
 uint32_t u32;        
 int32_t s32;         
 SI_UU16_t uu16[2];   
 uint16_t u16[2];     
 int16_t s16[2];      
 uint8_t u8[4];       
 int8_t s8[4];        
 } SI_UU32_t;
 
 
 
 
 
 
 
 
 
 
 
 typedef struct
 {
 uint8_t memtype;     
 SI_UU16_t address;   
 } GPTR_t;
 
 
 
 
 typedef union SI_GEN_PTR
 {
 uint8_t u8[3];     
 GPTR_t gptr;       
 } SI_GEN_PTR_t;
 
 
 extern void _nop_(void);
 
 
 
 
 
 
 
 
#line 589 ".\Lib\si_toolchain.h" /1
 
 
 
  
  
  
  
  
  
  
 
 
 
 
  
  
  
 
 
 
  
  
  
  
  

  

  
  

  

  
  

 
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
  
 
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
 
 

  

  

 


  

  

 
 
 
 
 
 
 
  

  

 
  
  
  
 
  
 
  
 
  
 
 
 
  
  
  
  
 
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
#line 794 ".\Lib\si_toolchain.h" /0
 
 
 
 
#line 123 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "\GitHub\dwLaser\MCU_Application\Lib\stdbool.h" /0




 
 
 
#line 8 "\GitHub\dwLaser\MCU_Application\Lib\stdbool.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 45 "\GitHub\dwLaser\MCU_Application\Lib\stdbool.h" /0
 
#line 125 ".\Lib\compiler_defs.h" /0
 
  
#line 1 "\GitHub\dwLaser\MCU_Application\Lib\stdint.h" /0




 
 
 
#line 8 "\GitHub\dwLaser\MCU_Application\Lib\stdint.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 126 ".\Lib\compiler_defs.h" /0
#line 126 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 136 ".\Lib\compiler_defs.h" /1
  
 
#line 138 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
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
 
 
 
 
 
 
 
 
 
 
#line 124 "MainApp\appConfig.h" /0
 
 
#line 126 "MainApp\appConfig.h" /1
  
 
#line 128 "MainApp\appConfig.h" /0
 
#line 129 "MainApp\appConfig.h" /1
  
 
#line 131 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\C8051F580_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  sfr P0 = 0x80;                         
  sfr SP = 0x81;                         
  sfr DPL = 0x82;                        
  sfr DPH = 0x83;                        
  sfr SFR0CN = 0x84;                     
  sfr SFRNEXT = 0x85;                    
  sfr SFRLAST = 0x86;                    
  sfr PCON = 0x87;                       
  sfr TCON = 0x88;                       
  sfr TMOD = 0x89;                       
  sfr TL0 = 0x8A;                        
  sfr TL1 = 0x8B;                        
  sfr TH0 = 0x8C;                        
  sfr TH1 = 0x8D;                        
  sfr CKCON = 0x8E;                      
  sfr PSCTL = 0x8F;                      
  sfr CLKSEL = 0x8F;                     
  sfr P1 = 0x90;                         
  sfr TMR3CN = 0x91;                     
  sfr TMR5CN = 0x91;                     
  sfr TMR3RLL = 0x92;                    
  sfr TMR5CAPL = 0x92;                   
  sfr TMR3RLH = 0x93;                    
  sfr TMR5CAPH = 0x93;                   
  sfr TMR3L = 0x94;                      
  sfr TMR5L = 0x94;                      
  sfr TMR3H = 0x95;                      
  sfr TMR5H = 0x95;                      
  sfr TMR5CF = 0x96;                     
  sfr CLKMUL = 0x97;                     
  sfr SCON0 = 0x98;                      
  sfr SCON1 = 0x98;                      
  sfr SBUF0 = 0x99;                      
  sfr SBUF1 = 0x99;                      
  sfr CPT0CN = 0x9A;                     
  sfr CPT2CN = 0x9A;                     
  sfr CPT0MD = 0x9B;                     
  sfr CPT2MD = 0x9B;                     
  sfr CPT0MX = 0x9C;                     
  sfr CPT2MX = 0x9C;                     
  sfr CPT1CN = 0x9D;                     
  sfr CPT1MD = 0x9E;                     
  sfr OSCIFIN = 0x9E;                    
  sfr CPT1MX = 0x9F;                     
  sfr OSCXCN = 0x9F;                     
  sfr P2 = 0xA0;                         
  sfr SPI0CFG = 0xA1;                    
  sfr OSCICN = 0xA1;                     
  sfr SPI0CKR = 0xA2;                    
  sfr OSCICRS = 0xA2;                    
  sfr SPI0DAT = 0xA3;                    
  sfr P0MDOUT = 0xA4;                    
  sfr P1MDOUT = 0xA5;                    
  sfr P2MDOUT = 0xA6;                    
  sfr SFRPAGE = 0xA7;                    
  sfr IE = 0xA8;                         
  sfr SMOD0 = 0xA9;                      
  sfr EMI0CN = 0xAA;                     
  sfr EMI0TC = 0xAA;                     
  sfr SBCON0 = 0xAB;                     
  sfr SBRLL0 = 0xAC;                     
  sfr SBRLH0 = 0xAD;                     
  sfr P3MAT = 0xAE;                      
  sfr P3MDOUT = 0xAE;                    
  sfr P3MASK = 0xAF;                     
  sfr P4MDOUT = 0xAF;                    
  sfr P3 = 0xB0;                         
  sfr P2MAT = 0xB1;                      
  sfr P2MASK = 0xB2;                     
  sfr EMI0CF = 0xB2;                     
  sfr P4 = 0xB5;                         
  sfr FLSCL = 0xB6;                      
  sfr FLKEY = 0xB7;                      
  sfr IP = 0xB8;                         
  sfr SMB0ADR = 0xB9;                    
  sfr ADC0TK = 0xBA;                     
  sfr SMB0ADM = 0xBA;                    
  sfr ADC0MX = 0xBB;                     
  sfr ADC0CF = 0xBC;                     
  sfr ADC0L = 0xBD;                      
  sfr ADC0H = 0xBE;                      
  sfr SMB0CN = 0xC0;                     
  sfr SMB0CF = 0xC1;                     
  sfr SMB0DAT = 0xC2;                    
  sfr ADC0GTL = 0xC3;                    
  sfr ADC0GTH = 0xC4;                    
  sfr ADC0LTL = 0xC5;                    
  sfr ADC0LTH = 0xC6;                    
  sfr XBR3 = 0xC6;                       
  sfr XBR2 = 0xC7;                       
  sfr TMR2CN = 0xC8;                     
  sfr TMR4CN = 0xC8;                     
  sfr REG0CN = 0xC9;                     
  sfr LIN0CF = 0xC9;                     
  sfr TMR4CF = 0xC9;                     
  sfr TMR2RLL = 0xCA;                    
  sfr TMR4CAPL = 0xCA;                   
  sfr TMR2RLH = 0xCB;                    
  sfr TMR4CAPH = 0xCB;                   
  sfr TMR2L = 0xCC;                      
  sfr TMR4L = 0xCC;                      
  sfr TMR2H = 0xCD;                      
  sfr TMR4H = 0xCD;                      
  sfr PCA0CPL5 = 0xCE;                   
  sfr PCA1CPL11 = 0xCE;                  
  sfr PCA0CPH5 = 0xCF;                   
  sfr PCA1CPH11 = 0xCF;                  
  sfr PSW = 0xD0;                        
  sfr REF0CN = 0xD1;                     
  sfr LIN0DAT = 0xD2;                    
  sfr LIN0ADR = 0xD3;                    
  sfr P0SKIP = 0xD4;                     
  sfr P1SKIP = 0xD5;                     
  sfr P2SKIP = 0xD6;                     
  sfr P3SKIP = 0xD7;                     
  sfr PCA0CN = 0xD8;                     
  sfr PCA1CN = 0xD8;                     
  sfr PCA0MD = 0xD9;                     
  sfr PCA1MD = 0xD9;                     
  sfr PCA0PWM = 0xD9;                    
  sfr PCA0CPM0 = 0xDA;                   
  sfr PCA1CPM6 = 0xDA;                   
  sfr PCA1PWM = 0xDA;                    
  sfr PCA0CPM1 = 0xDB;                   
  sfr PCA1CPM7 = 0xDB;                   
  sfr PCA0CPM2 = 0xDC;                   
  sfr PCA1CPM8 = 0xDC;                   
  sfr PCA0CPM3 = 0xDD;                   
  sfr PCA1CPM9 = 0xDD;                   
  sfr PCA0CPM4 = 0xDE;                   
  sfr PCA1CPM10 = 0xDE;                   
  sfr PCA0CPM5 = 0xDF;                   
  sfr PCA1CPM11 = 0xDF;                   
  sfr ACC = 0xE0;                        
  sfr XBR0 = 0xE1;                       
  sfr XBR1 = 0xE2;                       
  sfr CCH0CN = 0xE3;                     
  sfr IT01CF = 0xE4;                     
  sfr EIE1 = 0xE6;                       
  sfr EIE2 = 0xE7;                       
  sfr ADC0CN = 0xE8;                     
  sfr PCA0CPL1 = 0xE9;                   
  sfr PCA1CPL1 = 0xE9;                   
  sfr PCA0CPH1 = 0xEA;                   
  sfr PCA1CPH1 = 0xEA;                   
  sfr PCA0CPL2 = 0xEB;                   
  sfr PCA1CPL2 = 0xEB;                   
  sfr PCA0CPH2 = 0xEC;                   
  sfr PCA1CPH2 = 0xEC;                   
  sfr PCA0CPL3 = 0xED;                   
  sfr PCA1CPL3 = 0xED;                   
  sfr PCA0CPH3 = 0xEE;                   
  sfr PCA1CPH3 = 0xEE;                   
  sfr RSTSRC = 0xEF;                     
  sfr B = 0xF0;                          
  sfr P0MAT = 0xF1;                      
  sfr P0MDIN = 0xF1;                     
  sfr P0MASK = 0xF2;                     
  sfr P1MDIN = 0xF2;                     
  sfr P1MAT = 0xF3;                      
  sfr P2MDIN = 0xF3;                     
  sfr P1MASK = 0xF4;                     
  sfr P3MDIN = 0xF4;                     
  sfr PSBANK = 0xF5;                     
  sfr EIP1 = 0xF6;                       
  sfr EIP2 = 0xF7;                       
  sfr SPI0CN = 0xF8;                     
  sfr PCA0L = 0xF9;                      
  sfr PCA1L = 0xF9;                      
  sfr SN0 = 0xF9;                        
  sfr PCA0H = 0xFA;                      
  sfr PCA1H = 0xFA;                      
  sfr SN1 = 0xFA;                        
  sfr PCA0CPL0 = 0xFB;                   
  sfr PCA1CPL6 = 0xFB;                   
  sfr SN2 = 0xFB;                        
  sfr PCA0CPH0 = 0xFC;                   
  sfr PCA1CPH6 = 0xFC;                   
  sfr SN3 = 0xFC;                        
  sfr PCA0CPL4 = 0xFD;                   
  sfr PCA1CPL10 = 0xFD;                  
  sfr PCA0CPH4 = 0xFE;                   
  sfr PCA1CPH10 = 0xFE;                  
  sfr VDM0CN = 0xFF;                     
 
 
 
 
 
  sfr CAN0CFG = 0x92;                    
  sfr CAN0STAT = 0x94;                   
  sfr CAN0ERRL = 0x96;                   
  sfr CAN0ERRH = 0x97;                   
  sfr CAN0BTL = 0x9A;                    
  sfr CAN0BTH = 0x9B;                    
  sfr CAN0IIDL = 0x9C;                   
  sfr CAN0IIDH = 0x9D;                   
  sfr CAN0TST = 0x9E;                    
  sfr CAN0BRPE = 0xA1;                   
  sfr CAN0TR1L = 0xA2;                   
  sfr CAN0TR1H = 0xA3;                   
  sfr CAN0TR2L = 0xA4;                   
  sfr CAN0TR2H = 0xA5;                   
  sfr CAN0ND1L = 0xAA;                   
  sfr CAN0ND1H = 0xAB;                   
  sfr CAN0ND2L = 0xAC;                   
  sfr CAN0ND2H = 0xAD;                   
  sfr CAN0IP1L = 0xAE;                   
  sfr CAN0IP1H = 0xAF;                   
  sfr CAN0IP2L = 0xB2;                   
  sfr CAN0IP2H = 0xB3;                   
  sfr CAN0MV1L = 0xBA;                   
  sfr CAN0MV1H = 0xBB;                   
  sfr CAN0MV2L = 0xBC;                   
  sfr CAN0MV2H = 0xBD;                   
  sfr CAN0IF1CRL = 0xBE;                 
  sfr CAN0IF1CRH = 0xBF;                 
  sfr CAN0CN = 0xC0;                     
  sfr CAN0IF1CML = 0xC2;                 
  sfr CAN0IF1CMH = 0xC3;                 
  sfr CAN0IF1M1L = 0xC4;                 
  sfr CAN0IF1M1H = 0xC5;                 
  sfr CAN0IF1M2L = 0xC6;                 
  sfr CAN0IF1M2H = 0xC7;                 
  sfr CAN0IF1A1L = 0xCA;                 
  sfr CAN0IF1A1H = 0xCB;                 
  sfr CAN0IF1A2L = 0xCC;                 
  sfr CAN0IF1A2H = 0xCD;                 
  sfr CAN0IF2MCL = 0xCE;                 
  sfr CAN0IF2MCH = 0xCF;                 
  sfr CAN0IF1MCL = 0xD2;                 
  sfr CAN0IF1MCH = 0xD3;                 
  sfr CAN0IF1DA1L = 0xD4;                
  sfr CAN0IF1DA1H = 0xD5;                
  sfr CAN0IF1DA2L = 0xD6;                
  sfr CAN0IF1DA2H = 0xD7;                
  sfr CAN0IF1DB1L = 0xDA;                
  sfr CAN0IF1DB1H = 0xDB;                
  sfr CAN0IF1DB2L = 0xDC;                
  sfr CAN0IF1DB2H = 0xDD;                
  sfr CAN0IF2CRL = 0xDE;                 
  sfr CAN0IF2CRH = 0xDF;                 
  sfr CAN0IF2CML = 0xE2;                 
  sfr CAN0IF2CMH = 0xE3;                 
  sfr CAN0IF2M1L = 0xEA;                 
  sfr CAN0IF2M1H = 0xEB;                 
  sfr CAN0IF2M2L = 0xEC;                 
  sfr CAN0IF2M2H = 0xED;                 
  sfr CAN0IF2A1L = 0xEE;                 
  sfr CAN0IF2A1H = 0xEF;                 
  sfr CAN0IF2A2L = 0xF2;                 
  sfr CAN0IF2A2H = 0xF3;                 
  sfr CAN0IF2DA1L = 0xF6;                
  sfr CAN0IF2DA1H = 0xF7;                
  sfr CAN0IF2DA2L = 0xFA;                
  sfr CAN0IF2DA2H = 0xFB;                
  sfr CAN0IF2DB1L = 0xFC;                
  sfr CAN0IF2DB1H = 0xFD;                
  sfr CAN0IF2DB2L = 0xFE;                
  sfr CAN0IF2DB2H = 0xFF;                
 
 
 
 
 
 
  sfr16 DP = 0x82;                       
  sfr16 TMR3RL = 0x92;                   
  sfr16 TMR5CAP = 0x92;                  
  sfr16 TMR3 = 0x94;                     
  sfr16 TMR5 = 0x94;                     
  sfr16 SBRL0 = 0xAC;                    
  sfr16 ADC0 = 0xBD;                     
  sfr16 ADC0GT = 0xC3;                   
  sfr16 ADC0LT = 0xC5;                   
  sfr16 TMR2RL = 0xCA;                   
  sfr16 TMR4CAP = 0xCA;                  
  sfr16 TMR2 = 0xCC;                     
  sfr16 TMR4 = 0xCC;                     
  sfr16 PCA0CP5 = 0xCE;                  
  sfr16 PCA1CP11 = 0xCE;                 
  sfr16 PCA0CP1 = 0xE9;                  
  sfr16 PCA1CP7 = 0xE9;                  
  sfr16 PCA0CP2 = 0xEB;                  
  sfr16 PCA1CP8 = 0xEB;                  
  sfr16 PCA0CP3 = 0xED;                  
  sfr16 PCA1CP9 = 0xED;                  
  sfr16 PCA0 = 0xF9;                     
  sfr16 PCA1 = 0xF9;                     
  sfr16 PCA0CP0 = 0xFB;                  
  sfr16 PCA1CP6 = 0xFB;                  
  sfr16 PCA0CP4 = 0xFD;                  
  sfr16 PCA1CP10 = 0xFD;                  
 
  sfr16 CAN0ERR = 0x96;                  
  sfr16 CAN0BT = 0x9A;                   
  sfr16 CAN0IID = 0x9C;                  
  sfr16 CAN0TR1 = 0xA2;                  
  sfr16 CAN0TR2 = 0xA4;                  
  sfr16 CAN0ND1 = 0xAA;                  
  sfr16 CAN0ND2 = 0xAC;                  
  sfr16 CAN0IP1 = 0xAE;                  
  sfr16 CAN0IP2 = 0xB2;                  
  sfr16 CAN0MV1 = 0xBA;                  
  sfr16 CAN0MV2 = 0xBC;                  
  sfr16 CAN0IF1CR = 0xBE;                
  sfr16 CAN0IF1CM = 0xC2;                
  sfr16 CAN0IF1M1 = 0xC4;                
  sfr16 CAN0IF1M2 = 0xC6;                
  sfr16 CAN0IF1A1 = 0xCA;                
  sfr16 CAN0IF1A2 = 0xCC;                
  sfr16 CAN0IF1MC = 0xD2;                
  sfr16 CAN0IF1DA1 = 0xD4;               
  sfr16 CAN0IF1DA2 = 0xD6;               
  sfr16 CAN0IF1DB1 = 0xDA;               
  sfr16 CAN0IF1DB2 = 0xDC;               
  sfr16 CAN0IF2CR = 0xDE;                
  sfr16 CAN0IF2CM = 0xE2;                
  sfr16 CAN0IF2M1 = 0xEA;                
  sfr16 CAN0IF2M2 = 0xEC;                
  sfr16 CAN0IF2A1 = 0xEE;                
  sfr16 CAN0IF2A2 = 0xF2;                
  sfr16 CAN0IF2MC = 0xCE;                
  sfr16 CAN0IF2DA1 = 0xF6;               
  sfr16 CAN0IF2DA2 = 0xFA;               
  sfr16 CAN0IF2DB1 = 0xFC;               
  sfr16 CAN0IF2DB2 = 0xFE;               
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  sbit TF1 = 0x88^7;                
  sbit TR1 = 0x88^6;                
  sbit TF0 = 0x88^5;                
  sbit TR0 = 0x88^4;                
  sbit IE1 = 0x88^3;                
  sbit IT1 = 0x88^2;                
  sbit IE0 = 0x88^1;                
  sbit IT0 = 0x88^0;                
 
 
  sbit OVR0 = 0x98^7;              
  sbit PERR0 = 0x98^6;             
  sbit THRE0 = 0x98^5;             
  sbit REN0 = 0x98^4;              
  sbit TBX0 = 0x98^3;              
  sbit RBX0 = 0x98^2;              
  sbit TI0 = 0x98^1;               
  sbit RI0 = 0x98^0;               
 
 
  sbit S1MODE = 0x98^7;            
 
  sbit MCE1 = 0x98^5;              
  sbit REN1 = 0x98^4;              
  sbit TB81 = 0x98^3;              
  sbit RB81 = 0x98^2;              
  sbit TI1 = 0x98^1;               
  sbit RI1 = 0x98^0;               
 
 
  sbit EA = 0xA8^7;                   
  sbit ESPI0 = 0xA8^6;                
  sbit ET2 = 0xA8^5;                  
  sbit ES0 = 0xA8^4;                  
  sbit ET1 = 0xA8^3;                  
  sbit EX1 = 0xA8^2;                  
  sbit ET0 = 0xA8^1;                  
  sbit EX0 = 0xA8^0;                  
 
 
 
  sbit PSPI0 = 0xB8^6;                
  sbit PT2 = 0xB8^5;                  
  sbit PS0 = 0xB8^4;                  
  sbit PS = 0xB8^4;                   
  sbit PT1 = 0xB8^3;                  
  sbit PX1 = 0xB8^2;                  
  sbit PT0 = 0xB8^1;                  
  sbit PX0 = 0xB8^0;                  
 
 
  sbit MASTER = 0xC0^7;           
  sbit TXMODE = 0xC0^6;           
  sbit STA = 0xC0^5;              
  sbit STO = 0xC0^4;              
  sbit ACKRQ = 0xC0^3;            
  sbit ARBLOST = 0xC0^2;          
  sbit ACK = 0xC0^1;              
  sbit SI = 0xC0^0;               
 
 
  sbit TF2H = 0xC8^7;             
  sbit TF2L = 0xC8^6;             
  sbit TF2LEN = 0xC8^5;           
  sbit TF2CEN = 0xC8^4;           
  sbit T2SPLIT = 0xC8^3;          
  sbit TR2 = 0xC8^2;              
  sbit T2RCLK = 0xC8^1;           
  sbit T2XCLK = 0xC8^0;           
 
 
  sbit TF4 = 0xC8^7;              
  sbit EXF4 = 0xC8^6;             
 
 
  sbit EXE4 = 0xC8^3;             
  sbit TR4 = 0xC8^2;              
  sbit CT4 = 0xC8^1;              
  sbit CPRL4 = 0xC8^0;            
 
 
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
  sbit CCF5 = 0xD8^5;             
  sbit CCF4 = 0xD8^4;             
  sbit CCF3 = 0xD8^3;             
  sbit CCF2 = 0xD8^2;             
  sbit CCF1 = 0xD8^1;             
  sbit CCF0 = 0xD8^0;             
 
 
  sbit CF1 = 0xD8^7;              
  sbit CR1 = 0xD8^6;              
  sbit CCF11 = 0xD8^5;            
  sbit CCF10 = 0xD8^4;            
  sbit CCF9 = 0xD8^3;             
  sbit CCF8 = 0xD8^2;             
  sbit CCF7 = 0xD8^1;             
  sbit CCF6 = 0xD8^0;             
 
 
  sbit AD0EN = 0xE8^7;            
  sbit BURSTEN = 0xE8^6;          
  sbit AD0INT = 0xE8^5;           
  sbit AD0BUSY = 0xE8^4;          
  sbit AD0WINT = 0xE8^3;          
  sbit AD0LJST = 0xE8^2;          
  sbit AD0CM1 = 0xE8^1;           
  sbit AD0CM0 = 0xE8^0;           
 
 
  sbit SPIF = 0xF8^7;             
  sbit WCOL = 0xF8^6;             
  sbit MODF = 0xF8^5;             
  sbit RXOVRN = 0xF8^4;           
  sbit NSSMD1 = 0xF8^3;           
  sbit NSSMD0 = 0xF8^2;           
  sbit TXBMT = 0xF8^1;            
  sbit SPIEN = 0xF8^0;            
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 597 ".\Lib\C8051F580_defs.h" /1
 
 
 
 
#line 601 ".\Lib\C8051F580_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 132 "MainApp\appConfig.h" /0
 
 
 
  
#line 1 "C:\Keil_v5\C51\Inc\stdio.h" /0






 
 
 
 
 
 
 
 
 
 
#line 17 "C:\Keil_v5\C51\Inc\stdio.h" /1
  
 
#line 19 "C:\Keil_v5\C51\Inc\stdio.h" /0
 
 
 
 typedef unsigned int size_t;
 
 
 #pragma SAVE
 #pragma REGPARMS
 extern char _getkey (void);
 extern char getchar (void);
 extern char ungetchar (char);
 extern char putchar (char);
 extern int printf   (const char *, ...);
 extern int sprintf  (char *, const char *, ...);
 extern int vprintf  (const char *, char *);
 extern int vsprintf (char *, const char *, char *);
 extern char *gets (char *, int n);
 extern int scanf (const char *, ...);
 extern int sscanf (char *, const char *, ...);
 extern int puts (const char *);
 
 #pragma RESTORE
 
 
 
#line 135 "MainApp\appConfig.h" /0
 
  
#line 1 "C:\Keil_v5\C51\Inc\stdlib.h" /0







 
 
 
 
 
 
#line 14 "C:\Keil_v5\C51\Inc\stdlib.h" /1
  
 
 
#line 17 "C:\Keil_v5\C51\Inc\stdlib.h" /0
 
 
#line 19 "C:\Keil_v5\C51\Inc\stdlib.h" /1
  
 
#line 21 "C:\Keil_v5\C51\Inc\stdlib.h" /0
 
 
 
 typedef char wchar_t;
 
 
 
#line 28 "C:\Keil_v5\C51\Inc\stdlib.h" /1
 
 
 
 
 
 
 
 
 
  
 
 
#line 40 "C:\Keil_v5\C51\Inc\stdlib.h" /0
 
 
 
 
 
 
#line 46 "C:\Keil_v5\C51\Inc\stdlib.h" /1
 
 
 
 
 
 
#line 52 "C:\Keil_v5\C51\Inc\stdlib.h" /0
 
 #pragma SAVE
 #pragma REGPARMS
 
 extern char   cabs (char  val);
 
 extern int    abs  (int   val);
 
 extern long   labs (long  val);
 
 extern float  atof (const char *s1);
 extern long   atol (const char *s1);
 extern int    atoi (const char *s1);
 extern int    rand (void);
 extern void   srand (unsigned int seed);
 
 
#line 69 "C:\Keil_v5\C51\Inc\stdlib.h" /1
 
  
 
 
#line 73 "C:\Keil_v5\C51\Inc\stdlib.h" /0
 
 extern float         strtod  (const char *nptr, char **endptr);
 extern long          strtol  (const char *nptr, char **endptr, unsigned char base);
 extern unsigned long strtoul (const char *nptr, char **endptr, unsigned char base);
 
 
 
 extern void init_mempool          (void xdata *p, size_t size);
 extern void xdata *malloc  (size_t size);
 extern void free                  (void xdata *p);
 extern void xdata *realloc (void xdata *p, size_t size);
 extern void xdata *calloc  (size_t nmemb, size_t size);
 
 
#line 87 "C:\Keil_v5\C51\Inc\stdlib.h" /1
 
 
#line 89 "C:\Keil_v5\C51\Inc\stdlib.h" /0
 
 #pragma RESTORE
 
 
#line 136 "MainApp\appConfig.h" /0
 
  
#line 1 "C:\Keil_v5\C51\Inc\string.h" /0







 
 
 
 
 
 
#line 14 "C:\Keil_v5\C51\Inc\string.h" /1
  
 
 
#line 17 "C:\Keil_v5\C51\Inc\string.h" /0
 
 
#line 19 "C:\Keil_v5\C51\Inc\string.h" /1
  
 
#line 21 "C:\Keil_v5\C51\Inc\string.h" /0
 
 #pragma SAVE
 #pragma REGPARMS
 extern char  *strcat  (char *s1, const char *s2);
 extern char  *strncat (char *s1, const char *s2, size_t n);
 
 extern char   strcmp  (const char *s1, const char *s2);
 extern char   strncmp (const char *s1, const char *s2, size_t n);
 
 extern char  *strcpy  (char *s1, const char *s2);
 extern char  *strncpy (char *s1, const char *s2, size_t n);
 
 extern size_t strlen  (const char *);
 
 extern char  *strchr  (const char *s, char c);
 extern int    strpos  (const char *s, char c);
 extern char  *strrchr (const char *s, char c);
 extern int    strrpos (const char *s, char c);
 
 extern size_t strspn  (const char *s, const char *set);
 extern size_t strcspn (const char *s, const char *set);
 extern char  *strpbrk (const char *s, const char *set);
 extern char  *strrpbrk(const char *s, const char *set);
 extern char  *strstr  (const char *s, const char *sub);
 extern char  *strtok  (char *str, const char *set);
 
 extern char   memcmp  (const void *s1, const void *s2, size_t n);
 extern void  *memcpy  (void *s1, const void *s2, size_t n);
 extern void  *memchr  (const void *s, char val, size_t n);
 extern void  *memccpy (void *s1, const void *s2, char val, size_t n);
 extern void  *memmove (void *s1, const void *s2, size_t n);
 extern void  *memset  (void *s, char val, size_t n);
 #pragma RESTORE
 
 
#line 137 "MainApp\appConfig.h" /0
 
  
#line 1 "C:\Keil_v5\C51\Inc\INTRINS.H" /0






 
 
 
 
 
 #pragma SAVE
 
 
#line 15 "C:\Keil_v5\C51\Inc\INTRINS.H" /1
 
 
 
#line 18 "C:\Keil_v5\C51\Inc\INTRINS.H" /0
 
 extern void          _nop_     (void);
 extern bit           _testbit_ (bit);
 extern unsigned char _cror_    (unsigned char, unsigned char);
 extern unsigned int  _iror_    (unsigned int,  unsigned char);
 extern unsigned long _lror_    (unsigned long, unsigned char);
 extern unsigned char _crol_    (unsigned char, unsigned char);
 extern unsigned int  _irol_    (unsigned int,  unsigned char);
 extern unsigned long _lrol_    (unsigned long, unsigned char);
 extern unsigned char _chkfloat_(float);
 
#line 29 "C:\Keil_v5\C51\Inc\INTRINS.H" /1
 
 
 
#line 32 "C:\Keil_v5\C51\Inc\INTRINS.H" /0
 
 extern void          _push_    (unsigned char _sfr);
 extern void          _pop_     (unsigned char _sfr);
 
 
 #pragma RESTORE
 
 
 
#line 138 "MainApp\appConfig.h" /0
 
  
#line 1 "C:\Keil_v5\C51\Inc\ctype.h" /0






 
 
 
 
 
 #pragma SAVE
 #pragma REGPARMS
 extern bit isalpha (unsigned char);
 extern bit isalnum (unsigned char);
 extern bit iscntrl (unsigned char);
 extern bit isdigit (unsigned char);
 extern bit isgraph (unsigned char);
 extern bit isprint (unsigned char);
 extern bit ispunct (unsigned char);
 extern bit islower (unsigned char);
 extern bit isupper (unsigned char);
 extern bit isspace (unsigned char);
 extern bit isxdigit (unsigned char);
 extern unsigned char tolower (unsigned char);
 extern unsigned char toupper (unsigned char);
 extern unsigned char toint (unsigned char);
 
 
 
 
 #pragma RESTORE
 
 
#line 139 "MainApp\appConfig.h" /0
 
  
#line 1 "C:\Keil_v5\C51\Inc\LIMITS.H" /0







 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 140 "MainApp\appConfig.h" /0
 
  
#line 1 "C:\Keil_v5\C51\Inc\math.h" /0







 
 
 
 
 
 
#line 14 "C:\Keil_v5\C51\Inc\math.h" /1
 
  
 
 
 
  
 
 
 
 
 
 
 
 
#line 28 "C:\Keil_v5\C51\Inc\math.h" /0
 
 #pragma SAVE
 #pragma REGPARMS
 
 extern char  cabs  (char  val);
 extern int    abs  (int   val);
 extern long  labs  (long  val);
 
 
 extern float fabs  (float val);
 extern float sqrt  (float val);
 extern float exp   (float val);
 extern float log   (float val);
 extern float log10 (float val);
 extern float sin   (float val);
 extern float cos   (float val);
 extern float tan   (float val);
 extern float asin  (float val);
 extern float acos  (float val);
 extern float atan  (float val);
 extern float sinh  (float val);
 extern float cosh  (float val);
 extern float tanh  (float val);
 extern float atan2 (float y, float x);
 
 extern float ceil  (float val);
 extern float floor (float val);
 extern float modf  (float val, float *n);
 extern float fmod  (float x, float y);
 extern float pow   (float x, float y);
 
 
#line 60 "C:\Keil_v5\C51\Inc\math.h" /1
 
 
 
#line 63 "C:\Keil_v5\C51\Inc\math.h" /0
 
 #pragma RESTORE
 
 
#line 141 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\crc32.h" /0
 
 
 
 
 
 
 
  
#line 1 "MainApp\AppConfig.h" /0
 
#line 2 "MainApp\AppConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 8 ".\Lib\crc32.h" /0
#line 8 ".\Lib\crc32.h" /0
 
 
 uint32_t crc32Calculate(uint8_t *buf, uint32_t len); 
 uint32_t crc32CalculateAdd(uint8_t dat); 
 void crc32Clear(void); 
 void crc32SetCrcOld(uint32_t old);
 
 
 
 
 
 
 
 
#line 142 "MainApp\appConfig.h" /0
 
 
 
#line 145 "MainApp\appConfig.h" /1
  
 
#line 147 "MainApp\appConfig.h" /0
 
  
#line 1 "MainApp\InitDeviceF580.h" /0
 
 
 
  
#line 1 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 123 ".\Lib\compiler_defs.h" /1
  
 
  
  
 
 
 
 
 
 
  
 
 
  
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
 
  
 
  
 
  
  
  
 
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
 
  
  
 
 
 
 
  
  
  
 
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
#line 804 ".\Lib\compiler_defs.h" /0
 
 
 
 
#line 4 "MainApp\InitDeviceF580.h" /0
 
  
#line 1 ".\Lib\C8051F580_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 41 ".\Lib\C8051F580_defs.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 607 ".\Lib\C8051F580_defs.h" /0
 
 
 
 
#line 5 "MainApp\InitDeviceF580.h" /0
 
 
 void initDeviceF580(void);
 
#line 148 "MainApp\appConfig.h" /0
 
 
 
  
#line 1 ".\Lib\delay.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Lib\delay.h" /0
#line 4 ".\Lib\delay.h" /0
 
 
 void delayMs(uint8_t ms) reentrant;
 void delayUs(uint8_t us) reentrant;
 void hwDelayInit(uint8_t reload_h, uint8_t reload_l);
 void hwDelay(uint8_t control, uint8_t reload_h, uint8_t reload_l);
 
 
 
#line 151 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\i2c0.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Driver\i2c0.h" /0
#line 4 ".\Driver\i2c0.h" /0
 
 
 
 
 void iic0Init(void);
 void iic0Start(void);
 void iic0Stop(void);
 uint8_t iic0WaitAck(void);
 void iic0Ack(void);
 void iic0NAck(void);
 void iic0SendByte(uint8_t txd);
 uint8_t iic0ReadByte(uint8_t ack);
 
 
 
 
#line 152 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\i2c1.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Driver\i2c1.h" /0
#line 4 ".\Driver\i2c1.h" /0
 
 
 
 
 void iic1Init(void);
 void iic1Start(void);
 void iic1Stop(void);
 uint8_t iic1WaitAck(void);
 void iic1Ack(void);
 void iic1NAck(void);
 void iic1SendByte(uint8_t txd);
 uint8_t iic1ReadByte(uint8_t ack);
 
 
 
 
#line 153 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\i2c2.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Driver\i2c2.h" /0
#line 4 ".\Driver\i2c2.h" /0
 
 
 
 
 void iic2Init(void);
 void iic2Start(void);
 void iic2Stop(void);
 uint8_t iic2WaitAck(void);
 void iic2Ack(void);
 void iic2NAck(void);
 void iic2SendByte(uint8_t txd);
 uint8_t iic2ReadByte(uint8_t ack);
 
 
 
 
#line 154 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\i2c3.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Driver\i2c3.h" /0
#line 4 ".\Driver\i2c3.h" /0
 
 
 
 
 void iic3Init(void);
 void iic3Start(void);
 void iic3Stop(void);
 uint8_t iic3WaitAck(void);
 void iic3Ack(void);
 void iic3NAck(void);
 void iic3SendByte(uint8_t txd);
 uint8_t iic3ReadByte(uint8_t ack);
 
 
 
 
#line 155 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\i2c4.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Driver\i2c4.h" /0
#line 4 ".\Driver\i2c4.h" /0
 
 
 
 
 void iic4Init(void);
 void iic4Start(void);
 void iic4Stop(void);
 uint8_t iic4WaitAck(void);
 void iic4Ack(void);
 void iic4NAck(void);
 void iic4SendByte(uint8_t txd);
 uint8_t iic4ReadByte(uint8_t ack);
 
 
 
 
#line 156 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\i2c5.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Driver\i2c5.h" /0
#line 4 ".\Driver\i2c5.h" /0
 
 
 
 
 void iic5Init(void);
 void iic5Start(void);
 void iic5Stop(void);
 uint8_t iic5WaitAck(void);
 void iic5Ack(void);
 void iic5NAck(void);
 void iic5SendByte(uint8_t txd);
 uint8_t iic5ReadByte(uint8_t ack);
 
 
 
 
#line 157 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\i2c6.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Driver\i2c6.h" /0
#line 4 ".\Driver\i2c6.h" /0
 
 
 
 
 void iic6Init(void);
 void iic6Start(void);
 void iic6Stop(void);
 uint8_t iic6WaitAck(void);
 void iic6Ack(void);
 void iic6NAck(void);
 void iic6SendByte(uint8_t txd);
 uint8_t iic6ReadByte(uint8_t ack);
 
 
 
 
#line 158 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\eprom.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Driver\eprom.h" /0
#line 4 ".\Driver\eprom.h" /0
 
 
 
 void epromInit(void);
 uint8_t epromReadOneByte(uint16_t ReadAddr);
 void epromWriteOneByte(uint16_t WriteAddr, uint8_t DataToWrite);
 void epromWriteLenByte(uint16_t WriteAddr, uint32_t DataToWrite, uint8_t Len);
 uint32_t epromReadLenByte(uint16_t ReadAddr, uint8_t Len);
 void epromRead(uint16_t ReadAddr,uint8_t *pBuffer,uint16_t NumToRead);
 void epromWrite(uint16_t WriteAddr, uint8_t *pBuffer, uint16_t NumToWrite);
 void epromTest(void);
 
#line 159 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\mcp47x6.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Driver\mcp47x6.h" /0
#line 4 ".\Driver\mcp47x6.h" /0
 
 
 uint8_t mcp47x6Init(void);
 void mcp47x6Write(uint8_t channel, uint16_t dat) reentrant;
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 160 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\inPca9554.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Driver\inPca9554.h" /0
#line 4 ".\Driver\inPca9554.h" /0
 
 
 void inPca9554Init(void);
 uint8_t inPca9554Read(void);
 void inPca9554Write(uint8_t wdata);
 
 
#line 161 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\outPca9554.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Driver\outPca9554.h" /0
#line 4 ".\Driver\outPca9554.h" /0
 
 
 void outPca9554Init(void);
 uint8_t outPca9554Read(void);
 void outPca9554Write(uint8_t wdata);
 
 
#line 162 "MainApp\appConfig.h" /0
 
 
  
#line 1 ".\Modbus\Modbus.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Modbus\Modbus.h" /0
#line 4 ".\Modbus\Modbus.h" /0
 
 
 extern volatile uint16_t modbusTimerValue;
 extern volatile uint8_t modbusReceiveCounter; 
 extern xdata volatile uint8_t modbusReceiveBuffer[256];
 
 extern void initModbus(uint8_t modbusSlaveAddress, uint32_t bd);
 extern void modbusPorcess(void);
 
#line 164 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Modbus\ModbusPort.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Modbus\ModbusPort.h" /0
#line 4 ".\Modbus\ModbusPort.h" /0
 
 
 extern void modBusUartInitialise(uint32_t baudrate);
 extern void modBusTimerInitialise(void);
 extern void modBusUartPutch(uint8_t c);
 extern uint8_t modBusUartString(uint8_t *s, uint16_t Length);
 extern void receiveInterrupt(uint8_t Data);
 
 
#line 165 "MainApp\appConfig.h" /0
 
 
  
#line 1 "MainApp\sPlc.h" /0
 
#line 2 "MainApp\sPlc.h" /1
  
 
  
 
 
 
  
  
 
  
  
 
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
 
  
  
 
  
  
 
  
  
 
  
  
 
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 167 "MainApp\appConfig.h" /0
#line 167 "MainApp\appConfig.h" /0
 
  
#line 1 "MainApp\sPlcLaser.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
 
 
  
  
 
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 "MainApp\sPlcLaser.h" /0
#line 4 "MainApp\sPlcLaser.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void sPlcLaser(void); 
 
#line 168 "MainApp\appConfig.h" /0
 
 
 
 
 
 
 
 
 
 
#line 4 "MainApp\sPlc.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 extern uint16_t ModbusSlaveAsciiOverTimeCounter; 
 extern xdata int16_t NVRAM0[(773 + 1)]; 
 extern xdata int16_t NVRAM1[(773 + 1)]; 
 
 void wdtDisable(void); 
 
 void sPlcInit(void); 
 void sPlcProcessStart(void); 
 void sPlcProcessEnd(void); 
 
 void assertCoilAddress(uint16_t adr);
 void assertRegisterAddress(uint16_t adr);
 
 void nvramUpdata(void);
 void clearDM(void);
 void clearEM(void);
 void clearR(void);
 void clearT(void);
 void clearTD(void);
 void clearC(void);
 void nvramLoad(void);
 void nvramSave(void);
 void nvramUpdata(void);
 
 int16_t ADD(int16_t A, int16_t B); 
 void SET(uint16_t A); 
 void RES(uint16_t A); 
 void FLIP(uint16_t A); 
 uint8_t LD(uint16_t A); 
 uint8_t LDP(uint16_t A); 
 uint8_t LDF(uint16_t A); 
 uint8_t LDB(uint16_t A); 
 
 void T1MS(uint8_t A, uint8_t start, uint16_t value); 
 void T10MS(uint8_t A, uint8_t start, uint16_t value); 
 void T100MS(uint8_t A, uint8_t start, uint16_t value); 
 void UPDAC(uint16_t dat); 
 void REBOOT(void); 
 
 void chipDacInit(void);
 void chipAdcInit(void);
 void sPlcInit(void);
 void refreshInput(void);
 void refreshOutput(void);
 void refreshDac(void);
 
 
#line 1 "MainApp\sPlc.c" /0
 
 
 
 xdata int16_t NVRAM0[(773 + 1)]; 
 xdata int16_t NVRAM1[(773 + 1)]; 
 static idata uint8_t TimerCounter_1mS = 0;
 static idata uint8_t TimerCounter_10mS = 0;
 static idata uint8_t Timer0_L, Timer0_H;
 
 typedef struct{ 
 uint16_t dat[48];
 uint16_t out;
 uint8_t wIndex; 
 }adcTempDat_t;
 
 static xdata int8_t inputFilter[16]; 
 static xdata adcTempDat_t adcTempDat[9];
 static idata uint8_t adcSelect; 
 static void refreshAdcData(adcTempDat_t *s , uint16_t dat);
 void adcProcess(void);
 static void initAdcData(adcTempDat_t *s);
 static void chipDacInit(void);
 static void chipAdcInit(void);
 
 
 static void adcProcess(void){ 
 uint16_t result = 0;
 
#line 29 "MainApp\sPlc.c" /1
 
 
#line 31 "MainApp\sPlc.c" /0
 result = (uint16_t)(ADC0H << 8) + (uint16_t)(ADC0L);
 refreshAdcData(&adcTempDat[adcSelect], result);
 NVRAM0[(694 + 0) + adcSelect] = adcTempDat[adcSelect].out;
 if(adcSelect < (9 - 1)){
 adcSelect ++;
 }
 else{
 adcSelect = 0;
 }
 switch(adcSelect){
 case 0:{
 
 break;
 }
 case 1:{
 
 break;
 }
 case 2:{
 
 break;
 }
 case 3:{
 
 break;
 }
 case 4:{
 
 break;
 }
 default:{
 break;
 }
 }
 AD0INT = 0;
 AD0BUSY = 1; 
 }
 static void initAdcData(adcTempDat_t *s){ 
 uint8_t i;
 for(i = 0;i < 48; i++){
 s->dat[i] = 0x0;
 }
 s->out = 0;
 s->wIndex = 0;
 }
 static void refreshAdcData(adcTempDat_t *s , uint16_t dat){ 
 uint8_t i;
 uint16_t temp;
 uint32_t sum;
 s->dat[s->wIndex] = dat;
 s->wIndex ++;
 if(s->wIndex >= 48){
 s->wIndex = 0;
 }
 sum = 0;
 for(i = 0;i < 48;i ++){
 sum += s->dat[i];
 }
 temp = (uint16_t)(sum / (uint32_t)48);
 s->out = temp;
 }
 void assertCoilAddress(uint16_t adr){ 
 if(adr > (757 * 16))
 while(1);
 }
 void assertRegisterAddress(uint16_t adr){ 
 if(adr >= 757)
 while(1);
 }
 void clearDM(void){ 
 uint16_t i;
 for(i = 0;i <= 287;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 void clearMR(void){ 
 uint16_t i;
 for(i = 0;i <= 15;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 void clearEM(void){ 
 uint16_t i;
 for(i = 288;i <= 543;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 void clearR(void){ 
 uint16_t i;
 for(i = 16;i <= 31;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 void clearT(void){ 
 uint16_t i;
 for(i = 544;i <= 545;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 for(i = 546;i <= 547;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 for(i = 548;i <= 549;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 void clearTD(void){ 
 uint16_t i;
 for(i = 550;i <= 581;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 for(i = 582;i <= 613;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 for(i = 614;i <= 645;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 void clearC(void){ 
 uint16_t i;
 for(i = 646;i <= 661;i ++){
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 void clearX(void){ 
 uint16_t i;
 for(i = 662;i <= 677;i ++){
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 void clearY(void){ 
 uint16_t i;
 for(i = 678;i <= 693;i ++){
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 void clearSPREG(void){
 uint16_t i;
 for(i = 694;i <= 757;i ++){
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 void clearSPCOIL(){
 uint16_t i;
 for(i = 758;i <= 773;i ++){
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 static void nvramLoad(void){ 
 memset(NVRAM0, 0x0, ((773 + 1) * 2)); 
 epromRead(0, (uint8_t*)NVRAM0, ((773 + 1) * 2)); 
 clearEM();
 clearR();
 clearT();
 clearTD();
 clearC();
 clearX();
 clearY();
 clearSPREG();
 clearSPCOIL();
 memcpy(NVRAM1, NVRAM0, (773 + 1));
 }
 static void nvramSave(void){ 
  EA = 0; 
 epromWrite(0x0, (uint8_t*)NVRAM0, ((15 + 1) * 2));
  EA = 1;
 }
 static void nvramUpdata(void){ 
 uint8_t *sp0, *sp1;
 uint16_t i;
 sp0 = (uint8_t*)(NVRAM0 + (0 * 2));
 sp1 = (uint8_t*)(NVRAM1 + (0 * 2));
 for(i = 0;i < ((15 + 1) * 2);i ++){ 
 if(*(sp0 + i) != *(sp1 + i)){
 epromWriteOneByte(i, *(sp0 + i));
 }
 }
 sp0 = (uint8_t*)(NVRAM0 + (32 * 2));
 sp1 = (uint8_t*)(NVRAM1 + (32 * 2));
 for(i = 32;i < ((287 + 1) * 2);i ++){ 
 if(*(sp0 + i) != *(sp1 + i)){
 epromWriteOneByte(i, *(sp0 + i));
 }
 }
 memcpy(NVRAM1, NVRAM0, ((773 + 1) * 2));
 }
 
 int16_t ADD(int16_t A, int16_t B){ 
 int32_t tmp;
 tmp = (int32_t)(A) + (int32_t)(B);
 if(tmp >= 32767)
 tmp = 32767;
 if(tmp <= (-32767-1))
 tmp = (-32767-1);
 return (int16_t)tmp;
 }
 void SET(uint16_t A){ 
 assertCoilAddress(A); 
 NVRAM0[(A / 16)] |= 1 << (A % 16);
 }
 void RES(uint16_t A){ 
 assertCoilAddress(A); 
 NVRAM0[(A / 16)] &= ~(1 << (A % 16));
 }
 void FLIP(uint16_t A){ 
 uint16_t temp;
 assertCoilAddress(A); 
 temp= NVRAM0[(A / 16)] & (1 << (A % 16));
 if(temp)
 RES(A);
 else
 SET(A);
 }
 uint8_t LD(uint16_t A){ 
 assertCoilAddress(A); 
 return (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
 }
 uint8_t LDB(uint16_t A){ 
 assertCoilAddress(A); 
 if((uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)])){
 return false;
 }
 else{
 return true;
 }
 
 }
 uint8_t LDP(uint16_t A){ 
 pdata uint8_t temp0, temp1;
 assertCoilAddress(A); 
 temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
 temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
 if(temp0 && !temp1)
 return true;
 else
 return false;
 }
 uint8_t LDF(uint16_t A){ 
 uint8_t temp0, temp1;
 assertCoilAddress(A);
 temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
 temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
 if(!temp0 && temp1)
 return 1;
 else
 return 0;
 }
 void T1MS(uint8_t A, uint8_t start, uint16_t value){ 
 
#line 304 "MainApp\sPlc.c" /1
 
 
 
#line 307 "MainApp\sPlc.c" /0
 if(start){
 if(NVRAM0[(550 + A)] >= value){
 NVRAM0[(544 + (A / 16))] |= 1 << (A % 16);
 }
 else{
 NVRAM0[(544 + (A / 16))] &= ~(1 << (A % 16));
 }
 
 }
 else{
 NVRAM0[(544 + (A / 16))] &= ~(1 << (A % 16));
 NVRAM0[(550 + A)] = 0x0;
 }	
 }
 void T10MS(uint8_t A, uint8_t start, uint16_t value){ 
 
#line 323 "MainApp\sPlc.c" /1
 
 
 
#line 326 "MainApp\sPlc.c" /0
 if(start){
 if(NVRAM0[(582 + A)] >= value){
 NVRAM0[(546 + (A / 16))] |= 1 << (A % 16);
 }
 else{
 NVRAM0[(546 + (A / 16))] &= ~(1 << (A % 16));
 }
 }
 else{
 NVRAM0[(546 + (A / 16))] &= ~(1 << (A % 16));
 NVRAM0[(582 + A)] = 0x0;
 }	
 }
 void T100MS(uint8_t A, uint8_t start, uint16_t value){ 
 
#line 341 "MainApp\sPlc.c" /1
 
 
 
#line 344 "MainApp\sPlc.c" /0
 if(start){
 if(NVRAM0[(614 + A)] >= value){
 NVRAM0[(548 + (A / 16))] |= 1 << (A % 16);
 }
 else{
 NVRAM0[(548 + (A / 16))] &= ~(1 << (A % 16));
 }	
 }
 else{
 NVRAM0[(548 + (A / 16))] &= ~(1 << (A % 16));
 NVRAM0[(614 + A)] = 0x0;
 }
 }
 
 int16_t TNTC(uint16_t A){ 
 idata uint16_t temp, dat;
 idata fp32_t ftemp;
 dat = NVRAM0[A];
 if(dat >= 2200L) dat = 2200L; 
 if(dat < 0) dat = 0;
 temp = (int16_t)(2200L * dat / 4096); 
 temp = 10000 * 5000 / (5000 - temp); 
 ftemp = ((1.0 / 3477)*log((fp32_t)(temp) / 10000)) + (1 / (25+273.0)); 
 ftemp = ( 1.0 / ftemp ) - 273.0;
 if(ftemp >= 100) ftemp = 100;
 if(ftemp <= -100) ftemp = -100;
 return (int16_t)(ftemp * 10);
 }
 int16_t TENV(uint16_t A){ 
 uint16_t temp;
 temp = (int16_t)(2200L * NVRAM0[A] / 4096); 
 temp = (int16_t)((temp - 856L) * 1000 / 3330L);
 return temp;
 }
 int16_t YTAB(uint16_t X, uint16_t tab, uint16_t len){ 
 
 idata uint16_t x1, x2, y1, y2, i;
 idata fp32_t k, b, y;
 for(i = 0;i < (len - 1);i ++){
 if(NVRAM0[X] == NVRAM0[tab + i]){
 return NVRAM0[(tab + i + len)];
 }
 else if(NVRAM0[X] > NVRAM0[(tab + i + 1)]){
 x1 = NVRAM0[(tab + i)];
 y1 = NVRAM0[(tab + len + i)];
 x2 = NVRAM0[(tab + i + 1)];
 y2 = NVRAM0[(tab + len + i + 1)];
 k = (y2 - y1) / (x2 - x1);
 b = y1 - (k * x1);
 y = k * NVRAM0[X] + b;
 return (int16_t)y;
 }
 }
 return NVRAM0[(tab + len + len)];
 }
 int16_t XTAB(uint16_t Y, uint16_t tab, uint16_t len){ 
 
 idata uint16_t x1, x2, y1, y2, i;
 idata fp32_t k, b, x;
 for(i = 0;i < (len - 1);i ++){
 if(NVRAM0[Y] = NVRAM0[tab + i + len]){
 return NVRAM0[(tab + i)];
 }
 else if(NVRAM0[Y] > NVRAM0[(tab + i + 1 + len)]){
 x1 = NVRAM0[(tab + i)];
 y1 = NVRAM0[(tab + len + i)];
 x2 = NVRAM0[(tab + i + 1)];
 y2 = NVRAM0[(tab + len + i + 1)];
 k = (y2 - y1) / (x2 - x1);
 b = y1 - (k * x1);
 x = (NVRAM0[Y] - b) / k;
 return (int16_t)x;
 }
 }
 return NVRAM0[(tab + len)];
 }
 void UPDAC(uint16_t dat){ 
 switch(dat){
 case 0:{
 mcp47x6Write(0, NVRAM0[694 + (694 + 4)]);
 break;
 }
 case 1:{
 mcp47x6Write(1, NVRAM0[694 + (694 + 5)]);
 break;
 }
 case 2:{
 mcp47x6Write(2, NVRAM0[694 + (694 + 6)]);
 break;
 }
 case 3:{
 mcp47x6Write(3, NVRAM0[694 + (694 + 7)]);
 break;
 }
 default:break;
 }
 }
 void REBOOT(void){ 
 
 uint8_t SFRPAGE_save;
 
 
#line 446 "MainApp\sPlc.c" /1
 
 
#line 448 "MainApp\sPlc.c" /0
 
 SFRPAGE_save = SFRPAGE;
 SFRPAGE = 0x00;
 RSTSRC |= (1 << 1); 
 SFRPAGE = SFRPAGE_save;
 
 
 }
 static void wdtInit(void){ 
 
#line 458 "MainApp\sPlc.c" /1
 
 
#line 460 "MainApp\sPlc.c" /0
 }
 static void wdtEnable(void){ 
 
#line 463 "MainApp\sPlc.c" /1
 
 
#line 465 "MainApp\sPlc.c" /0
 
 
 }
 void wdtDisable(void){ 
 uint8_t flagEA;
 flagEA = EA;
 EA = 0;
 
#line 473 "MainApp\sPlc.c" /1
 
 
 
#line 476 "MainApp\sPlc.c" /0
 
#line 477 "MainApp\sPlc.c" /1
 
#line 478 "MainApp\sPlc.c" /0
 EA = flagEA;
 
 }
 static void wdtFeed(void){ 
 
#line 483 "MainApp\sPlc.c" /1
 
 
#line 485 "MainApp\sPlc.c" /0
 }
 
 static void pcaInit(void){ 
 
#line 489 "MainApp\sPlc.c" /1
 
 
#line 491 "MainApp\sPlc.c" /0
 
 
 
 
 }
 
 static void timer0Init(void){ 
 uint16_t tmp;
 TimerCounter_1mS = 0;
 TimerCounter_10mS = 0;
 tmp = (uint16_t)(65536 - ((48000000L) / 12 /1000L));
 Timer0_L = tmp & 0xFF;
 Timer0_H = (tmp >> 8) & 0xFF;
 TH0 = Timer0_H; 
 TL0 = Timer0_L; 
 CKCON &= ~(1 << 3); 
 TMOD &= 0xF0;
 TMOD |= (1 << 0); 
 ET0 = 1; 
 TR0 = 1; 
 }
 static void timer0Isr(void) interrupt 1{ 
 uint16_t i;
 TF0 = 0;
 TR0 = 0;
 TH0 = Timer0_H;
 TL0 = Timer0_L;
 TR0 = 1;
 if((NVRAM0[(758 + ((758 + 2) / 16))] >> ((758 + 2) % 16)) & 0x01){ 
 NVRAM0[(758 + ((758 + 2) / 16))] &= ~(uint16_t)(1 << ((758 + 2) % 16));
 }
 else{ 
 NVRAM0[(758 + ((758 + 2) / 16))] |= (uint16_t)(1 << ((758 + 2) % 16));
 }
 
 for(i = 550;i <= 581;i ++){ 
 if(NVRAM0[i] < 32767){
 NVRAM0[i] ++;
 }
 }
 if(TimerCounter_1mS >= 10){ 
 if((NVRAM0[(758 + ((758 + 3) / 16))] >> ((758 + 3) % 16)) & 0x01){ 
 NVRAM0[(758 + ((758 + 3) / 16))] &= ~(uint16_t)(1 << ((758 + 3) % 16));
 }
 else{ 
 NVRAM0[(758 + ((758 + 3) / 16))] |= (uint16_t)(1 << ((758 + 3) % 16));
 }
 for(i = 582;i <= 613;i ++){
 if(NVRAM0[i] < 32767){
 NVRAM0[i] ++;
 }
 }
 TimerCounter_10mS ++;
 TimerCounter_1mS = 0;
 }
 if(TimerCounter_10mS >= 10){ 
 if((NVRAM0[(758 + ((758 + 4) / 16))] >> ((758 + 4) % 16)) & 0x01){ 
 NVRAM0[(758 + ((758 + 4) / 16))] &= ~(uint16_t)(1 << ((758 + 4) % 16));
 }
 else{ 
 NVRAM0[(758 + ((758 + 4) / 16))] |= (uint16_t)(1 << ((758 + 4) % 16));
 }
 for(i = 614;i < 645;i ++){
 if(NVRAM0[i] < 32767){
 NVRAM0[i] ++;
 }
 }
 TimerCounter_10mS = 0;
 }
 
#line 561 "MainApp\sPlc.c" /1
 
 
#line 563 "MainApp\sPlc.c" /0
 TimerCounter_1mS ++;
 }
 
 static void inputInit(void){
 memset(inputFilter, 0x0, 16);
 
#line 569 "MainApp\sPlc.c" /1
 
#line 570 "MainApp\sPlc.c" /0
 
 
 }
 static void outputInit(void){
 
#line 575 "MainApp\sPlc.c" /1
 
 
#line 577 "MainApp\sPlc.c" /0
 
 
 
 }
 static void inputRefresh(void){ 
 uint8_t ctemp0,ctemp1, i;
 ctemp0 = 0;
 ctemp0 = 0;
 
#line 586 "MainApp\sPlc.c" /1
 
 
 
 
#line 590 "MainApp\sPlc.c" /0
 
 ctemp0 = inPca9554Read() ;
 
 for(i = 0;i < 8;i ++){ 
 if((ctemp0 >> i) & 0x01){
 if(inputFilter[i] < 3){
 inputFilter[i] ++;
 }
 else{
 NVRAM0[662] |= (int16_t)(1 << i);
 }
 }
 else{
 if(inputFilter[i] > (3 * -1)){
 inputFilter[i] --;
 }
 else{
 NVRAM0[662] &= ~(uint16_t)(1 << i);
 }
 }
 }
 for(i = 8;i < 16;i ++){ 
 if((ctemp1 >> (i - 8)) & 0x01){
 if(inputFilter[i] < 3){
 inputFilter[i] ++;
 }
 else{
 NVRAM0[662] |= (int16_t)(1 << i);
 }
 }
 else{
 if(inputFilter[i] > (3 * -1)){
 inputFilter[i] --;
 }
 else{
 NVRAM0[662] &= ~(uint16_t)(1 << i);
 }
 }
 }
 }
 static void outputRefresh(void){ 
 
#line 632 "MainApp\sPlc.c" /1
 
 
 
 
#line 636 "MainApp\sPlc.c" /0
 
 outPca9554Write(NVRAM0[678]);
 
 }
 static void chipAdcInit(void){ 
 uint8_t i;
 
#line 643 "MainApp\sPlc.c" /1
 
 
 
 
 
 
 
 
 
 
#line 653 "MainApp\sPlc.c" /0
 adcSelect = 0;
 for(i = 0;i <= 9;i ++){
 initAdcData(&adcTempDat[i]);
 }
 }
 void sPlcInit(void){ 
 wdtInit(); 
 wdtDisable(); 
 
 
#line 663 "MainApp\sPlc.c" /1
 
 
#line 665 "MainApp\sPlc.c" /0
 
 
#line 667 "MainApp\sPlc.c" /1
 
 
#line 669 "MainApp\sPlc.c" /0
 
 
 chipDacInit(); 
 
 
 
 initModbus(0x01, 115200);
 
 timer0Init(); 
 NVRAM0[(758 + ((758 + 0) / 16))] |= (uint16_t)(1 << ((758 + 0) % 16));
 }
 static void refreshDac(void){ 
 
#line 682 "MainApp\sPlc.c" /1
 
 
 
 
 
 
 
#line 689 "MainApp\sPlc.c" /0
 }
 static void chipDacInit(void){ 
 
#line 692 "MainApp\sPlc.c" /1
 
 
 
 
 
#line 697 "MainApp\sPlc.c" /0
 }
 void sPlcProcessStart(void){ 
 
 modbusPorcess(); 
 
 
 inputRefresh(); 
 
 
#line 706 "MainApp\sPlc.c" /1
 
 
#line 708 "MainApp\sPlc.c" /0
 }
 void sPlcProcessEnd(void){ 
 
#line 711 "MainApp\sPlc.c" /1
 
 
#line 713 "MainApp\sPlc.c" /0
 
 outputRefresh(); 
 
 
 refreshDac(); 
 
 
#line 720 "MainApp\sPlc.c" /1
 
 
#line 722 "MainApp\sPlc.c" /0
 }
