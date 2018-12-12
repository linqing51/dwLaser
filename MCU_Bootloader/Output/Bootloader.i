
#line 1 "Bootloader\Bootloader.c" /0
  
#line 1 "Bootloader\appConfig.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
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
 
 
#line 24 "Bootloader\appConfig.h" /0
 
  
#line 1 ".\Lib\stdbool.h" /0




 
 
 
 
 
 
 
 typedef bit bool;
 enum{
 false = 0,
 true = 1,
 };
 
 
#line 19 ".\Lib\stdbool.h" /1
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
#line 43 ".\Lib\stdbool.h" /0
 
 
 
#line 25 "Bootloader\appConfig.h" /0
 
  
#line 1 ".\Lib\endian.h" /0




 
 
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 31 ".\Lib\endian.h" /1
 
  
  
  
  
 
  
  
  
  
 
 
 
  
  
  
  
 
  
  
  
  
 
 
#line 55 ".\Lib\endian.h" /0
 
 
#line 26 "Bootloader\appConfig.h" /0
 
  
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
 
 
 
 
#line 27 "Bootloader\appConfig.h" /0
 
  
#line 1 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "\GitHub\dwLaser\MCU_Bootloader\Lib\stdbool.h" /0




 
 
 
#line 8 "\GitHub\dwLaser\MCU_Bootloader\Lib\stdbool.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 45 "\GitHub\dwLaser\MCU_Bootloader\Lib\stdbool.h" /0
 
#line 125 ".\Lib\compiler_defs.h" /0
 
  
#line 1 "\GitHub\dwLaser\MCU_Bootloader\Lib\stdint.h" /0




 
 
 
#line 8 "\GitHub\dwLaser\MCU_Bootloader\Lib\stdint.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 
 
 
 
 
 
 
 
 
 
#line 28 "Bootloader\appConfig.h" /0
 
 
#line 30 "Bootloader\appConfig.h" /1
  
 
#line 32 "Bootloader\appConfig.h" /0
 
  
#line 1 ".\Lib\C8051F340_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 344 ".\Lib\C8051F340_defs.h" /1
 
 
 
 
#line 348 ".\Lib\C8051F340_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 33 "Bootloader\appConfig.h" /0
 
 
 
#line 36 "Bootloader\appConfig.h" /1
  
 
#line 38 "Bootloader\appConfig.h" /0
 
  
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
 
 
 
#line 39 "Bootloader\appConfig.h" /0
 
  
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
 
 
#line 40 "Bootloader\appConfig.h" /0
 
  
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
 
 
#line 41 "Bootloader\appConfig.h" /0
 
  
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
 
 
 
#line 42 "Bootloader\appConfig.h" /0
 
  
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
 
 
#line 43 "Bootloader\appConfig.h" /0
 
  
#line 1 "C:\Keil_v5\C51\Inc\LIMITS.H" /0







 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 44 "Bootloader\appConfig.h" /0
 
  
#line 1 ".\Lib\crc32.h" /0
 
 
 
  
#line 1 "Bootloader\AppConfig.h" /0
 
#line 2 "Bootloader\AppConfig.h" /1
  
 
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
  
 
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
 
  
  
  
  
  
 
 
  
  
 
 
 
  
  
 
 
 
#line 4 ".\Lib\crc32.h" /0
#line 4 ".\Lib\crc32.h" /0
 
 
 uint32_t crc32Calculate(uint8_t *buf, uint32_t len); 
 uint32_t crc32CalculateAdd(uint8_t dat); 
 void crc32Clear(void); 
 void crc32SetCrcOld(uint32_t old);
 
 
 
 
 
#line 45 "Bootloader\appConfig.h" /0
 
 
  
#line 1 "Bootloader\InitDevice.h" /0
 
 
 
 
 void Init_Device(void);
 
 
 
#line 47 "Bootloader\appConfig.h" /0
 
  
#line 1 ".\Lib\delay.h" /0
 
 
 
  
#line 1 "Bootloader\appConfig.h" /0
 
#line 2 "Bootloader\appConfig.h" /1
  
 
 
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
  
 
 
  
  
  
  
  
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
 
  
  
  
  
  
 
 
  
  
 
 
 
  
  
 
 
 
#line 4 ".\Lib\delay.h" /0
#line 4 ".\Lib\delay.h" /0
 
 
 void delayMs(uint8_t ms) reentrant;
 void delayUs(uint8_t us) reentrant;
 void hwDelayInit(uint8_t reload_h, uint8_t reload_l);
 void hwDelay(uint8_t control, uint8_t reload_h, uint8_t reload_l);
 
 
 
#line 48 "Bootloader\appConfig.h" /0
 
  
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 49 "Bootloader\appConfig.h" /0
 
  
#line 1 ".\FlashEprom\Fxxx_EEPROM_Interface.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 extern U8 EEPROM_WriteBlock (U8, U8 *, U8);
 extern U8 EEPROM_ReadBlock (U8, U8 *, U8);
 
 
 
 
 
 
#line 50 "Bootloader\appConfig.h" /0
 
  
#line 1 ".\FlashEprom\Fxxx_Flash_Interface.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 extern void EE_FLASH_WriteErase (U16, S8, S8);
 extern U8 EE_FLASH_BlankCheck(U16);
 extern U8 EE_FLASH_Read (U16);
 
 
 
 
 
 extern U8 data FlashKey1;
 extern U8 data FlashKey2;
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 51 "Bootloader\appConfig.h" /0
 
 
 
  
#line 1 ".\LibFlash\F340_FlashPrimitives.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef unsigned long ULONG;
 typedef unsigned int  UINT;
 typedef unsigned char UCHAR;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef UINT FLADDR;
 
 
 
 
 
 
 extern void FLASH_ByteWrite (FLADDR addr, char byte);
 extern unsigned char FLASH_ByteRead (FLADDR addr);
 extern void FLASH_PageErase (FLADDR addr);
 
 
 
 
 
 
#line 54 "Bootloader\appConfig.h" /0
 
  
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
 
 
 
 
 
 
#line 55 "Bootloader\appConfig.h" /0
 
 
 
 
#line 59 "Bootloader\appConfig.h" /1
  
  
 
#line 62 "Bootloader\appConfig.h" /0
 
 
#line 1 "Bootloader\Bootloader.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void (*CmdGotoOTA1)(); 
 void (*CmdGotoOTA2)(); 
 void bootSequence(void);
  xdata uint8_t CmdRxBuf[1100];
  xdata uint8_t CmdTxBuf[1100];
  xdata uint8_t TempBuf[512]; 
  xdata uint8_t FlashEprom[64]; 
 
 static void uint32ToAscii(uint32_t *dat, uint8_t *pstr){ 
  data uint8_t temp;	
 temp = *dat & 0xF; 
 if(temp <= 0x09){
 *(pstr + 0) = (temp + 0x30);
 }
 else{
 *(pstr + 0) = (temp + 0x37);
 }
 
 temp = (*dat >> 4) & 0xF; 
 if(temp <= 0x09){
 *(pstr + 1) = (temp + 0x30);
 }
 else{
 *(pstr + 1) = (temp + 0x37);
 }
 
 temp = (*dat >> 8) & 0xF; 
 if(temp <= 0x09){
 *(pstr + 2) = (temp + 0x30);
 }
 else{
 *(pstr + 2) = (temp + 0x37);
 }
 
 temp = (*dat >> 12) & 0xF; 
 if(temp <= 0x09){
 *pstr = (temp + 0x30);
 }
 else{
 *pstr = (temp + 0x37);
 }
 
 temp = (*dat >> 16) & 0xF; 
 if(temp <= 0x09){
 *(pstr + 4) = (temp + 0x30);
 }
 else{
 *(pstr + 4) = (temp + 0x37);
 }
 
 temp = (*dat >> 20) & 0xF; 
 if(temp <= 0x09){
 *(pstr + 5) = (temp + 0x30);
 }
 else{
 *(pstr + 5) = (temp + 0x37);
 }
 
 temp = (*dat >> 24) & 0xF; 
 if(temp <= 0x09){
 *(pstr + 6) = (temp + 0x30);
 }
 else{
 *(pstr + 6) = (temp + 0x37);
 }
 
 temp = (*dat >> 28) & 0xF; 
 if(temp <= 0x09){
 *(pstr + 7) = (temp + 0x30);
 }
 else{
 *(pstr + 7) = (temp + 0x37);
 }
 }
 static uint32_t asciiToUint32(uint8_t *pstr){ 
  data uint8_t temp[8];
  data uint32_t hex;
 
 if(*pstr >= 'A' && *pstr <='F'){ 
 temp[0] = *pstr - 0x37; 
 }
 else if(*pstr >= '0' && *pstr <='9'){
 temp[0] = *pstr - 0x30;	
 }
 
 if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){ 
 temp[1] = *(pstr + 1) - 0x37; 
 }
 else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
 temp[1] = *(pstr + 1) - 0x30;	
 }
 
 if(*pstr >= 'A' && *pstr <='F'){ 
 temp[2] = *pstr - 0x37; 
 }
 else if(*pstr >= '0' && *pstr <='9'){
 temp[2] = *pstr - 0x30;	
 }
 
 if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){ 
 temp[3] = *(pstr + 1) - 0x37; 
 }
 else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
 temp[3] = *(pstr + 1) - 0x30;	
 }
 
 
 if(*pstr >= 'A' && *pstr <='F'){ 
 temp[4] = *pstr - 0x37; 
 }
 else if(*pstr >= '0' && *pstr <='9'){
 temp[4] = *pstr - 0x30;	
 }
 
 if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){ 
 temp[5] = *(pstr + 1) - 0x37; 
 }
 else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
 temp[5] = *(pstr + 1) - 0x30;	
 }
 
 if(*pstr >= 'A' && *pstr <='F'){ 
 temp[6] = *pstr - 0x37; 
 }
 else if(*pstr >= '0' && *pstr <='9'){
 temp[6] = *pstr - 0x30;	
 }
 
 if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){ 
 temp[7] = *(pstr + 1) - 0x37; 
 }
 else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
 temp[7] = *(pstr + 1) - 0x30;	
 }
 hex = 0;
 hex |= (temp[0] & 0x0000000F);
 hex |= (((temp[1] & 0x0F) << 4) & 0x000000F0);
 hex |= (((temp[2] & 0x0F) << 8) & 0x00000F00);
 hex |= (((temp[3] & 0x0F) << 12) & 0x0000F000);
 hex |= (((temp[4] & 0x0F) << 16) & 0x000F0000);
 hex |= (((temp[5] & 0x0F) << 20) & 0x00F00000);
 hex |= (((temp[6] & 0x0F) << 24) & 0x00F00000);
 hex |= (((temp[7] & 0x0F) << 28) & 0x00F00000);
 return hex;
 }
 static void uint16ToAscii(uint16_t *dat, uint8_t *pstr){ 
  data uint8_t temp;
 temp = *dat & 0x000F; 
 if(temp <= 0x09){
 *(pstr + 0) = (temp + 0x30);
 }
 else{
 *(pstr + 0) = (temp + 0x37);
 }
 temp = (*dat >> 4) & 0x000F; 
 if(temp <= 0x09){
 *(pstr + 1) = (temp + 0x30);
 }
 else{
 *(pstr + 1) = (temp + 0x37);
 }
 temp = (*dat >> 8) & 0x000F; 
 if(temp <= 0x09){
 *(pstr + 2) = (temp + 0x30);
 }
 else{
 *(pstr + 2) = (temp + 0x37);
 }
 temp = (*dat >> 12) & 0x000F; 
 if(temp <= 0x09){
 *(pstr + 3) = (temp + 0x30);
 }
 else{
 *(pstr + 3) = (temp + 0x37);
 }
 }
 static void uint8ToAscii(uint8_t *dat, uint8_t *pstr){ 
  data uint8_t temp;
 temp = (*dat & 0x0f);
 if(temp <= 0x09){
 *(pstr + 1) = (temp + 0x30);
 }
 else{
 *(pstr + 1) = (temp + 0x37);
 }
 temp = ((*dat & 0xf0) >> 4);
 if(temp <= 0x09){
 *pstr = (temp + 0x30);
 }
 else{
 *pstr = (temp + 0x37);
 }
 }
 static uint8_t asciiToUint8(uint8_t *pstr){ 
  data uint8_t temp[2];
  data uint8_t hex;
 if(*pstr >= 'A' && *pstr <='F'){ 
 temp[0] = *pstr - 0x37; 
 }
 else if(*pstr >= '0' && *pstr <='9'){
 temp[0] = *pstr - 0x30;	
 }
 if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){ 
 temp[1] = *(pstr + 1) - 0x37; 
 }
 else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
 temp[1] = *(pstr + 1) - 0x30;	
 }
 hex = 0;
 hex |= temp[1] & 0xF;
 hex |= ((temp[0] << 4) & 0xF0);
 return hex;
 }
 
 static uint16_t asciiToUint16(uint8_t *pstr){
  data uint8_t temp[4];
  data uint16_t hex;
 
 if(*pstr >= 'A' && *pstr <='F'){ 
 temp[3] = *pstr - 0x37; 
 }
 else if(*pstr >= '0' && *pstr <='9'){
 temp[3] = *pstr - 0x30;	
 }
 
 if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){ 
 temp[2] = *(pstr + 1) - 0x37; 
 }
 else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
 temp[2] = *(pstr + 1) - 0x30;	
 }
 
 if(*pstr >= 'A' && *pstr <='F'){ 
 temp[1] = *pstr - 0x37; 
 }
 else if(*pstr >= '0' && *pstr <='9'){
 temp[1] = *pstr - 0x30;	
 }
 
 if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){ 
 temp[0] = *(pstr + 1) - 0x37; 
 }
 else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
 temp[0] = *(pstr + 1) - 0x30;	
 }
 hex = 0;
 hex |= temp[0] & 0x000F;
 hex |= ((temp[1] & 0x0F) << 4) & 0x00F0;
 hex |= ((temp[2] & 0x0F) << 8) & 0x0F00;
 hex |= ((temp[3] & 0x0F) << 12) & 0xF000;
 return hex;
 }
 static uint8_t LRC(uint8_t *buf, uint32_t len){ 
  data uint32_t i;
  data uint8_t lrc = 0;         
 for( i = 0; i < len; i++ ){
 lrc = lrc + buf[i];
 }
 return lrc;
 }
 void uart0Send(uint8_t *buf, uint16_t count){ 
  data uint8_t *ptr = buf;
 do{
 SBUF0 = *ptr++;
 while(TI0 == 0);
 TI0 = 0;
 }while(--count);
 }
 void uart0Receive(uint8_t *buf, uint16_t count){ 
  data uint8_t * ptr = buf;
 do{
 if(RI0 == 1)
 {
 *ptr++ = SBUF0;
 RI0 = 0;
 count--;
 }
 }while(count);
 }
 uint8_t uart0ReceiveBootOrder(void){ 
  data uint8_t temp;
  data uint32_t timeOutCounter;
 
 printf("Bootloader->Debug:Input 'C' Into Loader Mode\n");
 
 timeOutCounter = 0;
 do{
 if(RI0 == 1){
 temp = SBUF0;
 RI0 = 0;
 if(temp == 'c')
 {
 
 printf("Bootloader->Debug:BOOT_SELECT_LOADER\n");
 
 return 0xA5;
 }
 }
 timeOutCounter ++;
 }while(timeOutCounter <= 1000000UL);
 
 printf("Bootloader->Debug:BOOT_SELECT_OTA\n");
 
 return 0x5A;
 }
 uint32_t bootFlashCrc(void){ 
  data uint32_t crc = 0, i;
  data uint8_t temp;
 crc32Clear(); 
 for(i = 0x0000;i < 0x1FFF;i ++)
 { 
 FLASH_Read(&temp, i, 1);
 crc = crc32CalculateAdd(temp);
 }
 return crc;
 }
 uint32_t ota1FlashCrc(void){ 
  data uint32_t crc = 0 ,i;
  data uint8_t temp;
 crc32Clear(); 
 for(i = 0x2000;i < 0x7FFF;i ++)
 { 
 FLASH_Read(&temp, i, 1);
 crc = crc32CalculateAdd(temp);
 }
 return crc;
 }
 uint32_t ota2FlashCrc(void){ 
  data uint32_t crc = 0, i;
  data uint8_t temp;
 for(i = 0x8000;i < 0xEFFF;i ++)
 { 
 FLASH_Read(&temp, i, 1);
 crc = crc32CalculateAdd(temp);
 }
 return crc;
 }
 void CmdSetHwVer(void){ 
 FlashEprom[15] = asciiToUint8(CmdRxBuf + 2);
 
 printf("Bootloader->Debug->CMD_SET_HW_VER:%2X\n", (uint16_t)(FlashEprom[15]));
 
 if(EEPROM_WriteBlock(15, FlashEprom, 1) != 0x00){ 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x31;
 CmdTxBuf[2] = 0x31;
 CmdTxBuf[3] = 0x25;	
 }
 else{
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x31;
 CmdTxBuf[2] = 0x30;
 CmdTxBuf[3] = 0x25;
 }
 uart0Send(CmdTxBuf, 4);
 }
 void CmdGetHwVer(void){ 
  data uint8_t ctemp[2];
 uint8ToAscii((FlashEprom + 15), ctemp);
 if(EEPROM_ReadBlock(15, FlashEprom, 1) != 0x00){
 
 printf("Bootloader->Debug->CMD_GET_HW_VER:%2X\n", (uint16_t)(FlashEprom[15]));
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x32;
 CmdTxBuf[2] = ctemp[0];
 CmdTxBuf[3] = ctemp[1];
 CmdTxBuf[4] = 0x25;
 }
 else
 {
 
 printf("Bootloader->Debug->CMD_GET_HW_VER->EPROM READ Fail\n");
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x32;
 CmdTxBuf[2] = 0x30;
 CmdTxBuf[3] = 0x30;
 CmdTxBuf[4] = 0x25;
 }
 uart0Send(CmdTxBuf, 5);	
 }
 void CmdResetMcu(void){ 
 
 printf("Bootloader->Debug->CMD_RESET_MCU\n");
 
 RSTSRC |= (1 << 4);
 }
 void CmdGetBootLoaderVer(void){ 
  data uint8_t ctemp[2];
 if(EEPROM_ReadBlock(12, FlashEprom, 1) != 0x00){
 uint8ToAscii((FlashEprom + 12), ctemp);
 
 printf("Bootloader->Debug->CMD_GET_BOOT_VER:%2X\n", (uint16_t)FlashEprom[12]);
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x34;
 CmdTxBuf[2] = ctemp[0];
 CmdTxBuf[3] = ctemp[1];
 CmdTxBuf[4] = 0x25;	
 }
 else{
 
 printf("Bootloader->Debug->CMD_GET_BOOT_VER:EPROM Read Fail\n");
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x34;
 CmdTxBuf[2] = 0x30;
 CmdTxBuf[3] = 0x30;
 CmdTxBuf[4] = 0x25;	
 }
 uart0Send(CmdTxBuf, 5);	
 }
 void CmdSetBootLoaderVer(void){ 
 FlashEprom[12] = asciiToUint8(CmdRxBuf + 2);
 if(EEPROM_WriteBlock(15, FlashEprom, 1) != 0x00){ 
 
 printf("Bootloader->Debug->CMD_SET_BOOT_VER:%2X\n", (uint16_t)FlashEprom[12]);
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x37;
 CmdTxBuf[2] = 0x31;
 CmdTxBuf[3] = 0x25;	
 }
 else{
 
 printf("Bootloader->Debug->CMD_SET_BOOT_VER:EPROM Write Fail\n");
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x37;
 CmdTxBuf[2] = 0x30;
 CmdTxBuf[3] = 0x25;
 }
 uart0Send(CmdTxBuf, 4);
 }
 void CmdGetOTA1Ver(void){ 
  data uint8_t ctemp[2];
 if(EEPROM_ReadBlock(13, FlashEprom, 1) != 0x00){
 uint8ToAscii((FlashEprom + 13), ctemp);
 
 printf("Bootloader->Debug->CMD_GET_OTA1_VER:%2X\n", (uint16_t)FlashEprom[13]);
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x35;
 CmdTxBuf[2] = ctemp[0];
 CmdTxBuf[3] = ctemp[1];
 CmdTxBuf[4] = 0x25;		
 }
 else{
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x35;
 CmdTxBuf[2] = 0x30;
 CmdTxBuf[3] = 0x30;
 CmdTxBuf[4] = 0x25;
 }	
 uart0Send(CmdTxBuf, 5);
 }
 void CmdSetOTA1Ver(void){ 
 FlashEprom[13] = asciiToUint8(CmdRxBuf + 2);
 if(EEPROM_WriteBlock(13, FlashEprom, 1) != 0x00){ 
 
 printf("Bootloader->Debug->CMD_SET_OTA1_VER:%2X\n", (uint16_t)FlashEprom[13]);
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x38;
 CmdTxBuf[2] = 0x31;
 CmdTxBuf[3] = 0x25;	
 }
 else{
 
 printf("Bootloader->Debug->CMD_SET_OTA1_VER:EPROM Write Fail\n");
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x38;
 CmdTxBuf[2] = 0x30;
 CmdTxBuf[3] = 0x25;
 }
 uart0Send(CmdTxBuf, 4);
 }
 void CmdGetOTA2Ver(void){ 
  data uint8_t ctemp[2];
 if(EEPROM_ReadBlock(14, FlashEprom, 1) != 0x00){
 uint8ToAscii((FlashEprom + 14), ctemp);
 
 printf("Bootloader->Debug->CMD_GET_OTA2_VER:%2X\n", (uint16_t)FlashEprom[14]);
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x36;
 CmdTxBuf[2] = ctemp[0];
 CmdTxBuf[3] = ctemp[1];
 CmdTxBuf[4] = 0x25;
 }
 else{
 
 printf("Bootloader->Debug->CMD_GET_OTA2_VER:%EPROM Write Fail\n");
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x36;
 CmdTxBuf[2] = 0x30;
 CmdTxBuf[3] = 0x30;
 CmdTxBuf[4] = 0x25;
 }
 uart0Send(CmdTxBuf, 5);
 }
 void CmdSetOTA2Ver(void){ 
 FlashEprom[14] = asciiToUint8(CmdRxBuf + 2);
 if(EEPROM_WriteBlock(14, FlashEprom, 1) != 0x00){ 
 
 printf("Bootloader->Debug->CMD_SET_OTA2_VER:%2X\n", FlashEprom[14]);
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x39;
 CmdTxBuf[2] = 0x31;
 CmdTxBuf[3] = 0x25;	
 }
 else{
 
 printf("Bootloader->Debug->CMD_SET_OTA2_VER:EPROM Write Fail\n", FlashEprom[14]);
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x39;
 CmdTxBuf[2] = 0x30;
 CmdTxBuf[3] = 0x25;
 }
 uart0Send(CmdTxBuf, 4);
 }
 void CmdGetBootCrc(void){ 
  data uint8_t ctemp[2];
 if(EEPROM_ReadBlock(0, FlashEprom, 1) != 0x00){
 uint8ToAscii((FlashEprom + 0), ctemp);
 
 printf("Bootloader->Debug->CMD_GET_BOOT_CRC:%2X\n", *((uint32_t*)(&FlashEprom[0])));
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x41;
 CmdTxBuf[2] = ctemp[0];
 CmdTxBuf[3] = ctemp[1];
 CmdTxBuf[4] = 0x25;		
 }
 else{
 
 printf("Bootloader->Debug->CMD_GET_BOOT_CRC:EPROM Read Fail\n");
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x41;
 CmdTxBuf[2] = 0x30;
 CmdTxBuf[3] = 0x30;
 CmdTxBuf[4] = 0x25;	
 }
 uart0Send(CmdTxBuf, 5);
 }
 void CmdGetOTA1Crc(void){ 
  data uint8_t ctemp[2];
 if(EEPROM_ReadBlock(4, FlashEprom, 1) != 0x00){
 uint8ToAscii((FlashEprom + 4), ctemp);
 
 printf("Bootloader->Debug->CMD_GET_OTA1_CRC:%2X\n",  *((uint32_t*)(&FlashEprom[4])));
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x42;
 CmdTxBuf[2] = ctemp[0];
 CmdTxBuf[3] = ctemp[1];
 CmdTxBuf[4] = 0x25;		
 }
 else{
 
 printf("Bootloader->Debug->CMD_GET_OTA1_CRC:EPROM Read Fail\n");
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x42;
 CmdTxBuf[2] = 0x30;
 CmdTxBuf[3] = 0x30;
 CmdTxBuf[4] = 0x25;	
 }
 uart0Send(CmdTxBuf, 5);
 }
 void CmdGetOTA2Crc(void){ 
  data uint8_t ctemp[2];
 if(EEPROM_ReadBlock(8, FlashEprom, 1) != 0x00){
 uint8ToAscii((FlashEprom + 8), ctemp);
 
 printf("Bootloader->Debug->CMD_GET_OTA2_CRC:%2X\n", *((uint32_t*)(&FlashEprom[8])));
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x43;
 CmdTxBuf[2] = ctemp[0];
 CmdTxBuf[3] = ctemp[1];
 CmdTxBuf[4] = 0x25;
 }
 else{
 
 printf("Bootloader->Debug->CMD_GET_OTA2_CRC:EPROM Read Fail\n");
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x43;
 CmdTxBuf[2] = 0x30;
 CmdTxBuf[3] = 0x30;
 CmdTxBuf[4] = 0x25;	
 }
 uart0Send(CmdTxBuf, 5);
 }
 void CmdReadFlashPage(void){ 
  data uint16_t i;
  data uint32_t adr, crc;
  data uint8_t page;
 page = asciiToUint8(CmdRxBuf + 2);
 if(page > (0x1FFF / 512) && (page < (0x0F800L / 512)))
 {	
 adr = (uint32_t)(page) * 512;
 crc32Clear();crc = 0;
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x45;
 CmdTxBuf[2] = CmdRxBuf[2];
 CmdTxBuf[3] = CmdRxBuf[3];
 FLASH_Read (TempBuf, adr, 512); 
 
 crc = crc32Calculate(TempBuf, 512);
 for(i = 0;i < 512;i ++){
 uint8ToAscii((TempBuf + i), (CmdTxBuf + 4 + (i * 2)));
 }
 uint32ToAscii(&crc, (CmdTxBuf + 4 + 1024));
 CmdTxBuf[1032] = 0x25;	
 uart0Send(CmdTxBuf, 1033);
 }
 else{
 
 printf("Bootloader->Debug->CMD_READ_FLASH_PAGE:Page Overflow\n");
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x45;
 CmdTxBuf[2] = CmdRxBuf[2];
 CmdTxBuf[3] = CmdRxBuf[3];
 CmdTxBuf[4] = 0x30;
 CmdTxBuf[5] = 0x25;
 uart0Send(CmdTxBuf, 6);
 }
 }
 void CmdClearFlashPage(void){ 
 uint32_t adr;
 uint8_t page;
 page = asciiToUint8(CmdRxBuf + 2);
 if(page > (0x1FFF / 512) && (page < (0x0F800L / 512))){	
 adr = (uint32_t)(page - 1) * 512;
 FLASH_Clear (adr, 512);
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x46;
 CmdTxBuf[2] = CmdRxBuf[2];
 CmdTxBuf[3] = CmdRxBuf[3];
 CmdTxBuf[4] = 0x31;
 CmdTxBuf[5] = 0x25;	
 uart0Send(CmdTxBuf, 6);
 }
 else{
 
 printf("Bootloader->Debug->CMD_CLEAR_FLASH_PAGE:Page Overflow\n");
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x46;
 CmdTxBuf[2] = CmdRxBuf[2];
 CmdTxBuf[3] = CmdRxBuf[3];
 CmdTxBuf[4] = 0x30;
 CmdTxBuf[5] = 0x25;	
 uart0Send(CmdTxBuf, 6);
 }
 
 }
 void CmdWriteFlashPage(void){ 
 uint32_t adr, crc0, crc1;
 uint8_t page;
 uint16_t i;
 page = asciiToUint8(CmdRxBuf + 2);
 adr = page * 512;
 uint32ToAscii(&crc0, (CmdTxBuf + 4 + 1024)); 
 for(i = 0;i < 512;i ++){
 *(TempBuf + i) = asciiToUint8(CmdRxBuf + 2 + (i * 2));
 }
 crc32Clear();
 crc1 = crc32Calculate(TempBuf, 512);
 if(page > (0x1FFF / 512) && (page < (0x0F800L / 512)) && crc0 == crc1){	
 FLASH_Write(adr, TempBuf, 512);
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x44;
 CmdTxBuf[2] = CmdRxBuf[2];
 CmdTxBuf[3] = CmdRxBuf[3];
 CmdTxBuf[4] = 0x31;
 CmdTxBuf[5] = 0x25;	
 uart0Send(CmdTxBuf, 6);
 }
 else{
 
 printf("Bootloader->Debug->CMD_WRITE_FLASH_PAGE:Page Overflow\n");
 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x44;
 CmdTxBuf[2] = CmdRxBuf[2];
 CmdTxBuf[3] = CmdRxBuf[3];
 CmdTxBuf[4] = 0x30;
 CmdTxBuf[5] = 0x25;	
 uart0Send(CmdTxBuf, 6);
 }
 }
 void CmdUpdateOTA1Crc(void){ 
 uint32_t crc, i;
 crc32Clear();crc = 0;
 
 for(i = 0x2000;i < 0x7FFF;i ++){
 FLASH_Read(&temp, i, 1);
 crc = crc32CalculateAdd(temp);
 }
 
 *((uint32_t*)(&FlashEprom[4])) = crc;
 
 if(EEPROM_WriteBlock(4, FlashEprom, 4) != 0x00){ 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x49;
 CmdTxBuf[2] = 0x30;
 CmdTxBuf[3] = 0x25;	
 }
 else{
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x49;
 CmdTxBuf[2] = 0x31;
 CmdTxBuf[3] = 0x25;
 }		
 uart0Send(CmdTxBuf, 4);
 }
 void CmdUpdateOTA2Crc(void){ 
 uint32_t crc, i;
 uint8_t temp;
 crc32Clear();crc = 0;
 
 for(i = 0x8000;i < 0xEFFF;i ++){
 FLASH_Read(&temp, i, 1);
 crc = crc32CalculateAdd(temp);
 }
 
 *((uint32_t*)(&FlashEprom[8])) = crc;
 
 if(EEPROM_WriteBlock(8, FlashEprom, 4) != 0x00){ 
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x4A;
 CmdTxBuf[2] = 0x30;
 CmdTxBuf[3] = 0x25;	
 }
 else{
 CmdTxBuf[0] = 0x24;
 CmdTxBuf[1] = 0x4A;
 CmdTxBuf[2] = 0x31;
 CmdTxBuf[3] = 0x25;
 }		
 uart0Send(CmdTxBuf, 4);	
 }
 
 void loaderCmdPoll(void){ 
 uint8_t *ptr, *ptw;
 uart0Send("C", 1);
 while(1){
 ptr = CmdRxBuf;
 uart0Receive(ptr, 1);
 if(*ptr == 0x24){
 ptr ++;
 do{
 uart0Receive(ptr, 1);
 if(*ptr == 0x25)
 {
 switch(CmdRxBuf[1])
 {
 case 0x31: 
 {
 CmdSetHwVer();
 break;
 }
 case 0x32: 
 {
 CmdGetHwVer();
 break;
 }
 case 0x33: 
 {
 CmdResetMcu();
 break;
 }
 case 0x34: 
 {
 CmdGetBootLoaderVer();
 break;
 }
 case 0x35: 
 {
 CmdGetOTA1Ver();
 break;
 }
 case 0x36: 
 {
 CmdGetOTA2Ver();
 break;
 }
 case 0x37: 
 {
 CmdSetBootLoaderVer();
 break;
 }
 case 0x38: 
 {
 CmdSetOTA1Ver();
 break;
 }
 case 0x39: 
 {
 CmdSetOTA2Ver();
 break;
 }							
 case 0x42: 
 {
 CmdGetOTA1Crc();
 break;
 }
 case 0x43: 
 {
 CmdGetOTA2Crc();
 break;
 }
 case 0x44: 
 {
 CmdWriteFlashPage();
 break;
 }
 case 0x45: 
 {
 CmdReadFlashPage();
 break;
 }
 case 0x46: 
 {
 CmdClearFlashPage();
 break;
 }
 case 0x47: 
 {
 CmdGotoOTA1();
 break;
 }
 case 0x48: 
 {
 CmdGotoOTA2();
 break;
 }
 case 0x49:
 {
 CmdUpdateOTA1Crc();
 break;
 }
 case 0x4A:
 {
 CmdUpdateOTA2Crc();
 break;
 }
 default:break;
 }
 break;
 }
 else if(ptr >= (CmdRxBuf + 1100)){
  _nop_();
 break;
 }
 ptr ++;
 }while(1);
 }
 }
 }
 
 void bootSequence(void){ 
  data uint32_t ota1Crc32, ota2Crc32;
 
  data uint8_t temp;
 temp = uart0ReceiveBootOrder();
 if(temp == 0x5A)
 {
 if(FlashEprom[32] == 0xA5A5)
 { 
 ota1Crc32 = ota1FlashCrc();
 if(ota1Crc32 == FlashEprom[4])
 {
 CmdGotoOTA1 = (void code *)(0x2000 & 0x1FFFF); 
 CmdGotoOTA1(); 
 }
 }
 else if(FlashEprom[32] == 0x5A5A)
 { 
 ota2Crc32 = ota2FlashCrc();
 if(ota2Crc32 == FlashEprom[8])
 {
 CmdGotoOTA2 = (void code *)(0x8000 & 0x1FFFF); 
 CmdGotoOTA2(); 
 }	
 }
 else{
 
 printf("Bootloader->Debug:OTA CRC32 Check Fail,Into Loader Mode\n");
 
 loaderCmdPoll();
 }	
 }
 else if(temp == 0xA5)
 {
 while(1)
 {
 loaderCmdPoll();
 }
 }	
 }
 void main (void) 
 {
 Init_Device();
 
 printf("Bootloader->Debug:Hello C8051 Bootloader\n");
 
 bootSequence();
 while(1);
 }
