
#line 1 "Lib\delay.c" /0
  
#line 1 "Lib\delay.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
 
 
 
 
#line 6 ".\MainApp\appConfig.h" /1
  
 
#line 8 ".\MainApp\appConfig.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "Lib\stdint.h" /0




 
 
 
 
 
 
 
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
 
 
#line 25 "Lib\stdint.h" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 51 "Lib\stdint.h" /0
 
 
#line 116 ".\MainApp\appConfig.h" /0
 
  
#line 1 "Lib\stdbool.h" /0




 
 
 
 
 
 
 
 typedef bit bool;
 enum{
 false = 0,
 true = 1,
 };
 
 
#line 19 "Lib\stdbool.h" /1
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
#line 43 "Lib\stdbool.h" /0
 
 
 
#line 117 ".\MainApp\appConfig.h" /0
 
  
#line 1 "Lib\endian.h" /0




 
 
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 31 "Lib\endian.h" /1
 
  
  
  
  
 
  
  
  
  
 
 
 
  
  
  
  
 
  
  
  
  
 
 
#line 55 "Lib\endian.h" /0
 
 
#line 118 ".\MainApp\appConfig.h" /0
 
  
#line 1 "Lib\si_toolchain.h" /0




 
 
 
 
 
  
#line 1 ".\Lib\stdint.h" /0




 
 
 
#line 8 ".\Lib\stdint.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 10 "Lib\si_toolchain.h" /0
#line 10 "Lib\si_toolchain.h" /0
 
  
#line 1 ".\Lib\stdbool.h" /0




 
 
 
#line 8 ".\Lib\stdbool.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 45 ".\Lib\stdbool.h" /0
 
#line 11 "Lib\si_toolchain.h" /0
 
 





















































 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 




 
 
 









 
 
 










 
 
 










 
 
 
 













 
 
 



















 
 

 














 
 
 


















 
 
 































 
 

 














 
 

 






































 
 

 
















 
 

 




























 
 
 



























 
 

 






























 
 

 





























 
 
 





























 
 

 
 
 
#line 501 "Lib\si_toolchain.h" /1
  
  
  
  
 
  
  
 
  
  
 
 
  
  
  
  
  
 
#line 519 "Lib\si_toolchain.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 
 
 
 
 
 
 
 
#line 589 "Lib\si_toolchain.h" /1
 
 
 
  
  
  
  
  
  
  
 
 
 
 
  
  
  
 
 
 
  
  
  
  
  

  

  
  

  

  
  

 
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
  
 
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
 
 

  

  

 


  

  

 
 
 
 
 
 
 
  

  

 
  
  
  
 
  
 
  
 
  
 
 
 
  
  
  
  
 
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
#line 794 "Lib\si_toolchain.h" /0
 
 
 
 
#line 119 ".\MainApp\appConfig.h" /0
 
  
#line 1 "Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "Lib\stdbool.h" /0




 
 
 
#line 8 "Lib\stdbool.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 45 "Lib\stdbool.h" /0
 
#line 125 "Lib\compiler_defs.h" /0
 
  
#line 1 "Lib\stdint.h" /0




 
 
 
#line 8 "Lib\stdint.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 126 "Lib\compiler_defs.h" /0
#line 126 "Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 136 "Lib\compiler_defs.h" /1
  
 
#line 138 "Lib\compiler_defs.h" /0
 
 
 
 
 
 
#line 144 "Lib\compiler_defs.h" /1
 
 
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 360 "Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 398 "Lib\compiler_defs.h" /1
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
#line 415 "Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
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
 
 
 
 
 
 
 
#line 483 "Lib\compiler_defs.h" /1
 
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
 
  
 
  
 
  
  
  
 
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
 
  
  
 
 
 
 
  
  
  
 
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
 
 
#line 798 "Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 120 ".\MainApp\appConfig.h" /0
 
 
#line 122 ".\MainApp\appConfig.h" /1
  
 
#line 124 ".\MainApp\appConfig.h" /0
 
#line 125 ".\MainApp\appConfig.h" /1
  
 
#line 127 ".\MainApp\appConfig.h" /0
 
  
#line 1 "Lib\C8051F580_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 597 "Lib\C8051F580_defs.h" /1
 
 
 
 
#line 601 "Lib\C8051F580_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 128 ".\MainApp\appConfig.h" /0
 
 
 
  
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
 
 
 
#line 131 ".\MainApp\appConfig.h" /0
 
  
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
 
 
#line 132 ".\MainApp\appConfig.h" /0
 
  
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
 
 
#line 133 ".\MainApp\appConfig.h" /0
 
  
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
 
 
 
#line 134 ".\MainApp\appConfig.h" /0
 
  
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
 
 
#line 135 ".\MainApp\appConfig.h" /0
 
  
#line 1 "C:\Keil_v5\C51\Inc\LIMITS.H" /0







 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 136 ".\MainApp\appConfig.h" /0
 
  
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
 
 
#line 137 ".\MainApp\appConfig.h" /0
 
  
#line 1 "Lib\crc32.h" /0
 
 
 
 
 
 
 
  
#line 1 ".\MainApp\AppConfig.h" /0
 
#line 2 ".\MainApp\AppConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 8 "Lib\crc32.h" /0
#line 8 "Lib\crc32.h" /0
 
 
 uint32_t crc32Calculate(uint8_t *buf, uint32_t len); 
 uint32_t crc32CalculateAdd(uint8_t dat); 
 void crc32Clear(void); 
 void crc32SetCrcOld(uint32_t old);
 
 
 
 
 
 
 
 
#line 138 ".\MainApp\appConfig.h" /0
 
 
 
#line 141 ".\MainApp\appConfig.h" /1
  
 
#line 143 ".\MainApp\appConfig.h" /0
 
  
#line 1 "\GitHub\dwLaser\MCU_Application\MainApp\InitDeviceF580.h" /0
 
 
 
  
#line 1 "Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 123 "Lib\compiler_defs.h" /1
  
 
  
  
 
 
 
 
 
 
  
 
 
  
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
 
  
 
  
 
  
  
  
 
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
 
  
  
 
 
 
 
  
  
  
 
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
#line 804 "Lib\compiler_defs.h" /0
 
 
 
 
#line 4 "\GitHub\dwLaser\MCU_Application\MainApp\InitDeviceF580.h" /0
 
  
#line 1 "Lib\C8051F580_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 41 "Lib\C8051F580_defs.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 607 "Lib\C8051F580_defs.h" /0
 
 
 
 
#line 5 "\GitHub\dwLaser\MCU_Application\MainApp\InitDeviceF580.h" /0
 
 
 void initDeviceF580(void);
 
#line 144 ".\MainApp\appConfig.h" /0
 
 
 
  
#line 1 "Lib\delay.h" /0
 
#line 2 "Lib\delay.h" /1
  
 
  
 
 
 
 
 
 
 
#line 12 "Lib\delay.h" /0
 
#line 147 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\i2c0.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
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
 
 
 
 
#line 148 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\i2c1.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
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
 
 
 
 
#line 149 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\i2c2.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
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
 
 
 
 
#line 150 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\i2c3.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
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
 
 
 
 
#line 151 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\i2c4.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
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
 
 
 
 
#line 152 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\i2c5.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
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
 
 
 
 
#line 153 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\i2c6.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
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
 
 
 
 
#line 154 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\eprom.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
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
 
#line 155 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\mcp47x6.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Driver\mcp47x6.h" /0
#line 4 ".\Driver\mcp47x6.h" /0
 
 
 uint8_t mcp47x6Init(void);
 void mcp47x6Write(uint8_t channel, uint16_t dat);
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 156 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\inPca9554.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Driver\inPca9554.h" /0
#line 4 ".\Driver\inPca9554.h" /0
 
 
 void inPca9554Init(void);
 uint8_t inPca9554Read(void);
 void inPca9554Write(uint8_t wdata);
 
 
#line 157 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\outPca9554.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Driver\outPca9554.h" /0
#line 4 ".\Driver\outPca9554.h" /0
 
 
 void outPca9554Init(void);
 uint8_t outPca9554Read(void);
 void outPca9554Write(uint8_t wdata);
 
 
#line 158 ".\MainApp\appConfig.h" /0
 
 
  
#line 1 ".\Modbus\Modbus.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Modbus\Modbus.h" /0
#line 4 ".\Modbus\Modbus.h" /0
 
 
 extern volatile uint16_t modbusTimerValue;
 extern volatile uint8_t modbusReceiveCounter; 
 extern xdata volatile uint8_t modbusReceiveBuffer[256];
 
 extern void initModbus(uint8_t modbusSlaveAddress, uint32_t bd);
 extern void modbusPorcess(void);
 
#line 160 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Modbus\ModbusPort.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 ".\Modbus\ModbusPort.h" /0
#line 4 ".\Modbus\ModbusPort.h" /0
 
 
 extern void modBusUartInitialise(uint32_t baudrate);
 extern void modBusTimerInitialise(void);
 extern void modBusUartPutch(uint8_t c);
 extern uint8_t modBusUartString(uint8_t *s, uint16_t Length);
 extern void receiveInterrupt(uint8_t Data);
 
 
#line 161 ".\MainApp\appConfig.h" /0
 
 
  
#line 1 "\GitHub\dwLaser\MCU_Application\MainApp\sPlc.h" /0
 
 
 
  
#line 1 "\GitHub\dwLaser\MCU_Application\MainApp\appConfig.h" /0
 
#line 2 "\GitHub\dwLaser\MCU_Application\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 "\GitHub\dwLaser\MCU_Application\MainApp\sPlc.h" /0
#line 4 "\GitHub\dwLaser\MCU_Application\MainApp\sPlc.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 
 
#line 163 ".\MainApp\appConfig.h" /0
 
  
#line 1 "\GitHub\dwLaser\MCU_Application\MainApp\sPlcLaser.h" /0
 
 
 
  
#line 1 "\GitHub\dwLaser\MCU_Application\MainApp\appConfig.h" /0
 
#line 2 "\GitHub\dwLaser\MCU_Application\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
  
  
  
  
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
  
 
 
 
 
 
 
 
 
 
#line 4 "\GitHub\dwLaser\MCU_Application\MainApp\sPlcLaser.h" /0
#line 4 "\GitHub\dwLaser\MCU_Application\MainApp\sPlcLaser.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void sPlcLaser(void); 
 
#line 164 ".\MainApp\appConfig.h" /0
 
 
 
 
 
 
 
 
 
 
#line 4 "Lib\delay.h" /0
 
 
 void delayMs(uint8_t ms) reentrant;
 void delayUs(uint8_t us) reentrant;
 void hwDelayInit(uint8_t reload_h, uint8_t reload_l);
 void hwDelay(uint8_t control, uint8_t reload_h, uint8_t reload_l);
 
 
 
#line 1 "Lib\delay.c" /0
 
 
 
 
 void delayUs(uint8_t data us) reentrant
 { 
 while(us)
 {
 us --;
 }
 }
 void delayMs(uint8_t data ms) reentrant
 { 
 while(ms--)
 {
 delayUs(100);
 }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
