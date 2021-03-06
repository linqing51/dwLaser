
#line 1 "Lib\crc32.c" /0
 
 
 
  
#line 1 "Lib\crc32.h" /0
 
 
 
  
#line 1 ".\Bootloader\AppConfig.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
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
 
 
#line 24 ".\Bootloader\AppConfig.h" /0
 
  
#line 1 "Lib\stdbool.h" /0




 
 
 
 
 
 
 
 typedef bit bool;
 enum{
 false = 0,
 true = 1,
 };
 
 
#line 19 "Lib\stdbool.h" /1
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
#line 43 "Lib\stdbool.h" /0
 
 
 
#line 25 ".\Bootloader\AppConfig.h" /0
 
  
#line 1 "Lib\endian.h" /0




 
 
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 31 "Lib\endian.h" /1
 
  
  
  
  
 
  
  
  
  
 
 
 
  
  
  
  
 
  
  
  
  
 
 
#line 55 "Lib\endian.h" /0
 
 
#line 26 ".\Bootloader\AppConfig.h" /0
 
  
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
 
 
 
 
#line 27 ".\Bootloader\AppConfig.h" /0
 
  
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
 
 
 
 
 
 
 
 
 
 
#line 28 ".\Bootloader\AppConfig.h" /0
 
 
#line 30 ".\Bootloader\AppConfig.h" /1
  
 
#line 32 ".\Bootloader\AppConfig.h" /0
 
  
#line 1 "Lib\C8051F340_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  sfr P0 = 0x80;                         
  sfr SP = 0x81;                         
  sfr DPL = 0x82;                        
  sfr DPH = 0x83;                        
  sfr EMI0TC = 0x84;                     
  sfr EMI0CF = 0x85;                     
  sfr OSCLCN = 0x86;                     
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
  sfr USB0ADR = 0x96;                    
  sfr USB0DAT = 0x97;                    
  sfr SCON0 = 0x98;                      
  sfr SBUF0 = 0x99;                      
  sfr CPT1CN = 0x9A;                     
  sfr CPT0CN = 0x9B;                     
  sfr CPT1MD = 0x9C;                     
  sfr CPT0MD = 0x9D;                     
  sfr CPT1MX = 0x9E;                     
  sfr CPT0MX = 0x9F;                     
  sfr P2 = 0xA0;                         
  sfr SPI0CFG = 0xA1;                    
  sfr SPI0CKR = 0xA2;                    
  sfr SPI0DAT = 0xA3;                    
  sfr P0MDOUT = 0xA4;                    
  sfr P1MDOUT = 0xA5;                    
  sfr P2MDOUT = 0xA6;                    
  sfr P3MDOUT = 0xA7;                    
  sfr IE = 0xA8;                         
  sfr CLKSEL = 0xA9;                     
  sfr EMI0CN = 0xAA;                     
  sfr SBCON1 = 0xAC;                     
  sfr P4MDOUT = 0xAE;                    
  sfr PFE0CN = 0xAF;                     
  sfr P3 = 0xB0;                         
  sfr OSCXCN = 0xB1;                     
  sfr OSCICN = 0xB2;                     
  sfr OSCICL = 0xB3;                     
  sfr SBRLL1 = 0xB4;                     
  sfr SBRLH1 = 0xB5;                     
  sfr FLSCL = 0xB6;                      
  sfr FLKEY = 0xB7;                      
  sfr IP = 0xB8;                         
  sfr CLKMUL = 0xB9;                     
  sfr AMX0N = 0xBA;                      
  sfr AMX0P = 0xBB;                      
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
  sfr P4 = 0xC7;                         
  sfr TMR2CN = 0xC8;                     
  sfr REG0CN = 0xC9;                     
  sfr TMR2RLL = 0xCA;                    
  sfr TMR2RLH = 0xCB;                    
  sfr TMR2L = 0xCC;                      
  sfr TMR2H = 0xCD;                      
  sfr PSW = 0xD0;                        
  sfr REF0CN = 0xD1;                     
  sfr SCON1 = 0xD2;                      
  sfr SBUF1 = 0xD3;                      
  sfr P0SKIP = 0xD4;                     
  sfr P1SKIP = 0xD5;                     
  sfr P2SKIP = 0xD6;                     
  sfr USB0XCN = 0xD7;                    
  sfr PCA0CN = 0xD8;                     
  sfr PCA0MD = 0xD9;                     
  sfr PCA0CPM0 = 0xDA;                   
  sfr PCA0CPM1 = 0xDB;                   
  sfr PCA0CPM2 = 0xDC;                   
  sfr PCA0CPM3 = 0xDD;                   
  sfr PCA0CPM4 = 0xDE;                   
  sfr P3SKIP = 0xDF;                     
  sfr ACC = 0xE0;                        
  sfr XBR0 = 0xE1;                       
  sfr XBR1 = 0xE2;                       
  sfr XBR2 = 0xE3;                       
  sfr IT01CF = 0xE4;                     
  sfr SMOD1 = 0xE5;                      
  sfr EIE1 = 0xE6;                       
  sfr EIE2 = 0xE7;                       
  sfr ADC0CN = 0xE8;                     
  sfr PCA0CPL1 = 0xE9;                   
  sfr PCA0CPH1 = 0xEA;                   
  sfr PCA0CPL2 = 0xEB;                   
  sfr PCA0CPH2 = 0xEC;                   
  sfr PCA0CPL3 = 0xED;                   
  sfr PCA0CPH3 = 0xEE;                   
  sfr RSTSRC = 0xEF;                     
  sfr B = 0xF0;                          
  sfr P0MDIN = 0xF1;                     
  sfr P1MDIN = 0xF2;                     
  sfr P2MDIN = 0xF3;                     
  sfr P3MDIN = 0xF4;                     
  sfr P4MDIN = 0xF5;                     
  sfr EIP1 = 0xF6;                       
  sfr EIP2 = 0xF7;                       
  sfr SPI0CN = 0xF8;                     
  sfr PCA0L = 0xF9;                      
  sfr PCA0H = 0xFA;                      
  sfr PCA0CPL0 = 0xFB;                   
  sfr PCA0CPH0 = 0xFC;                   
  sfr PCA0CPL4 = 0xFD;                   
  sfr PCA0CPH4 = 0xFE;                   
  sfr VDM0CN = 0xFF;                     
 
 
 
 
 
  sfr16 DP = 0x82;
  sfr16 TMR3RL = 0x92;
  sfr16 TMR3 = 0x94;
  sfr16 SBRL1 = 0xB4;
  sfr16 ADC0 = 0xBD;
  sfr16 ADC0GT = 0xC3;
  sfr16 ADC0LT = 0xC5;
  sfr16 TMR2RL = 0xCA;
  sfr16 TMR2 = 0xCC;
  sfr16 PCA0CP1 = 0xE9;
  sfr16 PCA0CP2 = 0xEB;
  sfr16 PCA0CP3 = 0xED;
  sfr16 PCA0 = 0xF9;
  sfr16 PCA0CP0 = 0xFB;
  sfr16 PCA0CP4 = 0xFD;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  sbit TF1 = 0x88^7;                
  sbit TR1 = 0x88^6;                
  sbit TF0 = 0x88^5;                
  sbit TR0 = 0x88^4;                
  sbit IE1 = 0x88^3;                
  sbit IT1 = 0x88^2;                
  sbit IE0 = 0x88^1;                
  sbit IT0 = 0x88^0;                
 
 
  sbit S0MODE = 0x98^7;            
 
  sbit MCE0 = 0x98^5;              
  sbit REN0 = 0x98^4;              
  sbit TB80 = 0x98^3;              
  sbit RB80 = 0x98^2;              
  sbit TI0 = 0x98^1;              
  sbit RI0 = 0x98^0;              
 
 
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
  sbit T2CE = 0xC8^4;          
  sbit T2SPLIT = 0xC8^3;          
  sbit TR2 = 0xC8^2;          
  sbit T2CSS = 0xC8^1;          
  sbit T2XCLK = 0xC8^0;          
 
 
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
  sbit AD0WINT = 0xE8^3;          
  sbit AD0CM2 = 0xE8^2;          
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 344 "Lib\C8051F340_defs.h" /1
 
 
 
 
#line 348 "Lib\C8051F340_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 33 ".\Bootloader\AppConfig.h" /0
 
 
 
#line 36 ".\Bootloader\AppConfig.h" /1
  
 
#line 38 ".\Bootloader\AppConfig.h" /0
 
  
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
 
 
 
#line 39 ".\Bootloader\AppConfig.h" /0
 
  
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
 
 
#line 40 ".\Bootloader\AppConfig.h" /0
 
  
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
 
 
#line 41 ".\Bootloader\AppConfig.h" /0
 
  
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
 
 
 
#line 42 ".\Bootloader\AppConfig.h" /0
 
  
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
 
 
#line 43 ".\Bootloader\AppConfig.h" /0
 
  
#line 1 "C:\Keil_v5\C51\Inc\LIMITS.H" /0







 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 44 ".\Bootloader\AppConfig.h" /0
 
  
#line 1 "Lib\crc32.h" /0
 
#line 2 "Lib\crc32.h" /1
  
 
  
 
 
 
 
 
 
 
#line 12 "Lib\crc32.h" /0
 
 
 
#line 45 ".\Bootloader\AppConfig.h" /0
 
 
  
#line 1 "\GitHub\dwLaser\MCU_Bootloader\Bootloader\InitDevice.h" /0
 
 
 
 
 void Init_Device(void);
 
 
 
#line 47 ".\Bootloader\AppConfig.h" /0
 
  
#line 1 "Lib\delay.h" /0
 
 
 
  
#line 1 ".\Bootloader\appConfig.h" /0
 
#line 2 ".\Bootloader\appConfig.h" /1
  
 
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
  
 
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
 
  
  
  
  
  
 
 
  
  
 
 
 
  
  
 
 
 
#line 4 "Lib\delay.h" /0
#line 4 "Lib\delay.h" /0
 
 
 void delayMs(uint8_t ms) reentrant;
 void delayUs(uint8_t us) reentrant;
 void hwDelayInit(uint8_t reload_h, uint8_t reload_l);
 void hwDelay(uint8_t control, uint8_t reload_h, uint8_t reload_l);
 
 
 
#line 48 ".\Bootloader\AppConfig.h" /0
 
  
#line 1 ".\FlashEprom\Fxxx_EEPROM_Configuration.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 123 ".\Lib\compiler_defs.h" /1
  
 
  
  
 
 
 
 
 
 
  
 
 
  
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
 
  
 
  
 
  
  
  
 
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
 
  
  
 
 
 
 
  
  
  
 
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
#line 804 ".\Lib\compiler_defs.h" /0
 
 
 
 
#line 56 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 





#line 76 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 107 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 110 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 141 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 146 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 177 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 


#line 183 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 214 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 217 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 248 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 


#line 254 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 285 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 288 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 319 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 




#line 327 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 358 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 361 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 392 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 



#line 399 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 430 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 435 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 450 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 453 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 469 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 472 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
 
#line 474 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

#line 497 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 513 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 517 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 533 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 537 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 553 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 558 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 574 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 577 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 593 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 596 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 612 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 615 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
 
#line 617 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 



 
  
#line 1 ".\Lib\c8051f340_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 40 ".\Lib\c8051f340_defs.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 354 ".\Lib\c8051f340_defs.h" /0
 
 
 
 
#line 625 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



#line 646 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 662 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 667 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 683 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 



#line 690 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 706 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 709 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 725 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 729 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 745 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 748 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 764 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 


#line 770 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 786 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 


#line 791 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 807 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 812 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 828 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 832 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 848 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 852 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
 
#line 854 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 859 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 875 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 879 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 895 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 





#line 904 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 920 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 





#line 928 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 944 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 


#line 950 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 966 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 


#line 971 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 987 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 


#line 993 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1009 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 1013 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1029 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 



#line 1035 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1051 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 





#line 1060 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1076 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 








#line 1087 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1103 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 


#line 1108 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1124 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 1128 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1144 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 1147 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1163 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 1167 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1183 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 1186 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1202 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 



#line 1209 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1225 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 1229 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1245 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 1248 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
 
#line 1250 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
#line 1252 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /1
 
 
#line 1254 "\GitHub\dwLaser\MCU_Bootloader\FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
 
 
#line 19 ".\FlashEprom\Fxxx_EEPROM_Configuration.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 54 ".\FlashEprom\Fxxx_EEPROM_Configuration.h" /1
 
 
#line 56 ".\FlashEprom\Fxxx_EEPROM_Configuration.h" /0
 
 
#line 58 ".\FlashEprom\Fxxx_EEPROM_Configuration.h" /1
 
 
#line 60 ".\FlashEprom\Fxxx_EEPROM_Configuration.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 49 ".\Bootloader\AppConfig.h" /0
 
  
#line 1 ".\FlashEprom\Fxxx_EEPROM_Interface.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 extern U8 EEPROM_WriteBlock (U8, U8 *, U8);
 extern U8 EEPROM_ReadBlock (U8, U8 *, U8);
 
 
 
 
 
 
#line 50 ".\Bootloader\AppConfig.h" /0
 
  
#line 1 ".\FlashEprom\Fxxx_Flash_Interface.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 extern void EE_FLASH_WriteErase (U16, S8, S8);
 extern U8 EE_FLASH_BlankCheck(U16);
 extern U8 EE_FLASH_Read (U16);
 
 
 
 
 
 extern U8 data FlashKey1;
 extern U8 data FlashKey2;
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 51 ".\Bootloader\AppConfig.h" /0
 
 
 
  
#line 1 ".\LibFlash\F340_FlashPrimitives.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef unsigned long ULONG;
 typedef unsigned int  UINT;
 typedef unsigned char UCHAR;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef UINT FLADDR;
 
 
 
 
 
 
 extern void FLASH_ByteWrite (FLADDR addr, char byte);
 extern unsigned char FLASH_ByteRead (FLADDR addr);
 extern void FLASH_PageErase (FLADDR addr);
 
 
 
 
 
 
#line 54 ".\Bootloader\AppConfig.h" /0
 
  
#line 1 ".\LibFlash\F340_FlashUtils.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "\GitHub\dwLaser\MCU_Bootloader\LibFlash\F340_FlashPrimitives.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 23 "\GitHub\dwLaser\MCU_Bootloader\LibFlash\F340_FlashPrimitives.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
  
 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 65 "\GitHub\dwLaser\MCU_Bootloader\LibFlash\F340_FlashPrimitives.h" /0
 
 
 
 
#line 29 ".\LibFlash\F340_FlashUtils.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 extern void FLASH_Write (FLADDR dest, char *src, unsigned numbytes);
 extern char * FLASH_Read (char *dest, FLADDR src, unsigned numbytes);
 extern void FLASH_Clear (FLADDR addr, unsigned numbytes);
 
 
 
 
 extern void FLASH_Update (FLADDR dest, char *src, unsigned numbytes);   
 
 extern void FLASH_Copy (FLADDR dest, FLADDR src, unsigned numbytes);    
 
 
 extern void FLASH_Fill (FLADDR addr, ULONG length, UCHAR fill);
 
 
 
 
 
 
#line 55 ".\Bootloader\AppConfig.h" /0
 
 
 
 
#line 59 ".\Bootloader\AppConfig.h" /1
  
  
 
#line 62 ".\Bootloader\AppConfig.h" /0
 
 
#line 4 "Lib\crc32.h" /0
 
 
 uint32_t crc32Calculate(uint8_t *buf, uint32_t len); 
 uint32_t crc32CalculateAdd(uint8_t dat); 
 void crc32Clear(void); 
 void crc32SetCrcOld(uint32_t old);
 
 
 
 
 
#line 4 "Lib\crc32.c" /0
 










 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 code uint32_t crc32Tab[] = {  
 0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f,
 0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
 0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
 0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
 0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
 0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
 0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 0x35b5a8fa, 0x42b2986c,
 0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
 0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
 0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
 0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x01db7106,
 0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
 0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d,
 0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
 0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
 0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
 0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
 0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
 0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
 0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
 0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
 0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
 0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
 0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
 0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
 0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
 0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
 0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
 0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
 0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
 0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
 0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
 0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f,
 0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
 0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
 0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
 0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
 0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
 0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
 0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
 0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
 0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
 0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
 };
 static uint32_t oldcrc32;
 
 uint32_t crc32Calculate(uint8_t *buf, uint32_t len){ 
 data uint32_t i;  
 for (i = 0; i < len; i++)
 {  
 oldcrc32 = crc32Tab[(oldcrc32 ^ buf[i]) & 0xff] ^ (oldcrc32 >> 8);  
 }  
 return (oldcrc32 ^ 0xFFFFFFFF);  
 }
 
 uint32_t crc32CalculateAdd(uint8_t dat){ 
 oldcrc32 = crc32Tab[(oldcrc32 ^ dat) & 0xff] ^ (oldcrc32 >> 8);
 return (oldcrc32 ^ 0xFFFFFFFF);
 }
 void crc32Clear(void){ 
 oldcrc32 = 0xFFFFFFFF;
 }
 void crc32SetCrcOld(uint32_t old){ 
 oldcrc32 = old;
 }
 
