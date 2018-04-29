
#line 1 "uCOSII\UCOS_II.C" /0













 
 
 
  
#line 1 ".\Lib\AppConfig.h" /0
 
 
 
 
 
 
 
 
 
 
 
#line 12 ".\Lib\AppConfig.h" /1
  
 
#line 14 ".\Lib\AppConfig.h" /0
 
#line 15 ".\Lib\AppConfig.h" /1
  
 
#line 17 ".\Lib\AppConfig.h" /0
 
#line 18 ".\Lib\AppConfig.h" /1
  
 
#line 20 ".\Lib\AppConfig.h" /0
 
 
 
 
#line 24 ".\Lib\AppConfig.h" /1
  
 
#line 26 ".\Lib\AppConfig.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "\GitHub\dwLaser\MCU\Lib\stdint.h" /0




 
 
 
 
 
 
 
 typedef unsigned char uint8_t;
 typedef unsigned short uint16_t;
 typedef unsigned long uint32_t;
 typedef uint32_t uint64_t[2];
 
 typedef signed char int8_t;
 typedef short int16_t;
 typedef long int32_t;
 typedef int32_t int64_t[2];
 
 
 
#line 24 "\GitHub\dwLaser\MCU\Lib\stdint.h" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 50 "\GitHub\dwLaser\MCU\Lib\stdint.h" /0
 
 
#line 83 ".\Lib\AppConfig.h" /0
 
  
#line 1 "\GitHub\dwLaser\MCU\Lib\stdbool.h" /0




 
 
 
 
 
 
 
 typedef bit bool;
 enum{
 false = 0,
 true = 1,
 };
 
 
#line 19 "\GitHub\dwLaser\MCU\Lib\stdbool.h" /1
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
#line 43 "\GitHub\dwLaser\MCU\Lib\stdbool.h" /0
 
 
 
#line 84 ".\Lib\AppConfig.h" /0
 
  
#line 1 "\GitHub\dwLaser\MCU\Lib\endian.h" /0




 
 
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 31 "\GitHub\dwLaser\MCU\Lib\endian.h" /1
 
  
  
  
  
 
  
  
  
  
 
 
 
  
  
  
  
 
  
  
  
  
 
 
#line 55 "\GitHub\dwLaser\MCU\Lib\endian.h" /0
 
 
#line 85 ".\Lib\AppConfig.h" /0
 
  
#line 1 "\GitHub\dwLaser\MCU\Lib\si_toolchain.h" /0




 
 
 
 
 
  
#line 1 ".\Lib\stdint.h" /0




 
 
 
#line 8 ".\Lib\stdint.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 10 "\GitHub\dwLaser\MCU\Lib\si_toolchain.h" /0
#line 10 "\GitHub\dwLaser\MCU\Lib\si_toolchain.h" /0
 
  
#line 1 ".\Lib\stdbool.h" /0




 
 
 
#line 8 ".\Lib\stdbool.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 45 ".\Lib\stdbool.h" /0
 
#line 11 "\GitHub\dwLaser\MCU\Lib\si_toolchain.h" /0
 
 





















































 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 




 
 
 









 
 
 










 
 
 










 
 
 
 













 
 
 



















 
 

 














 
 
 


















 
 
 































 
 

 














 
 

 






































 
 

 
















 
 

 




























 
 
 



























 
 

 






























 
 

 





























 
 
 





























 
 

 
 
 
#line 501 "\GitHub\dwLaser\MCU\Lib\si_toolchain.h" /1
  
  
  
  
 
  
  
 
  
  
 
 
  
  
  
  
  
 
#line 519 "\GitHub\dwLaser\MCU\Lib\si_toolchain.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 
 
 
 
 
 
 
 
#line 589 "\GitHub\dwLaser\MCU\Lib\si_toolchain.h" /1
 
 
 
  
  
  
  
  
  
  
 
 
 
 
  
  
  
 
 
 
  
  
  
  
  

  

  
  

  

  
  

 
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
  
 
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
 
 

  

  

 


  

  

 
 
 
 
 
 
 
  

  

 
  
  
  
 
  
 
  
 
  
 
 
 
  
  
  
  
 
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
#line 794 "\GitHub\dwLaser\MCU\Lib\si_toolchain.h" /0
 
 
 
 
#line 86 ".\Lib\AppConfig.h" /0
 
  
#line 1 "\GitHub\dwLaser\MCU\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "\GitHub\dwLaser\MCU\Lib\stdbool.h" /0




 
 
 
#line 8 "\GitHub\dwLaser\MCU\Lib\stdbool.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 45 "\GitHub\dwLaser\MCU\Lib\stdbool.h" /0
 
#line 125 "\GitHub\dwLaser\MCU\Lib\compiler_defs.h" /0
 
  
#line 1 "\GitHub\dwLaser\MCU\Lib\stdint.h" /0




 
 
 
#line 8 "\GitHub\dwLaser\MCU\Lib\stdint.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 126 "\GitHub\dwLaser\MCU\Lib\compiler_defs.h" /0
#line 126 "\GitHub\dwLaser\MCU\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 136 "\GitHub\dwLaser\MCU\Lib\compiler_defs.h" /1
  
 
#line 138 "\GitHub\dwLaser\MCU\Lib\compiler_defs.h" /0
 
 
 
 
 
 
#line 144 "\GitHub\dwLaser\MCU\Lib\compiler_defs.h" /1
 
 
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 360 "\GitHub\dwLaser\MCU\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 398 "\GitHub\dwLaser\MCU\Lib\compiler_defs.h" /1
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
#line 415 "\GitHub\dwLaser\MCU\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
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
 
 
 
 
 
 
 
#line 483 "\GitHub\dwLaser\MCU\Lib\compiler_defs.h" /1
 
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
 
  
 
  
 
  
  
  
 
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
 
  
  
 
 
 
 
  
  
  
 
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
 
 
#line 798 "\GitHub\dwLaser\MCU\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 87 ".\Lib\AppConfig.h" /0
 
  
#line 1 "\GitHub\dwLaser\MCU\Lib\C8051F020_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 337 "\GitHub\dwLaser\MCU\Lib\C8051F020_defs.h" /1
 
 
 
 
#line 341 "\GitHub\dwLaser\MCU\Lib\C8051F020_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 88 ".\Lib\AppConfig.h" /0
 
 
  
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
 
 
 
#line 90 ".\Lib\AppConfig.h" /0
 
  
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
 
 
#line 91 ".\Lib\AppConfig.h" /0
 
  
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
 
 
 
#line 92 ".\Lib\AppConfig.h" /0
 
  
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
 
 
#line 93 ".\Lib\AppConfig.h" /0
 
  
#line 1 "C:\Keil_v5\C51\Inc\LIMITS.H" /0







 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 94 ".\Lib\AppConfig.h" /0
 
 
  
#line 1 "uCOSII\os_cpu.h" /0














 
 
#line 17 "uCOSII\os_cpu.h" /1
  
 
#line 19 "uCOSII\os_cpu.h" /0
 
 
 





 
 
 
 typedef unsigned char  BOOLEAN;        
 typedef unsigned char  INT8U;          
 typedef signed   char  INT8S;          
 typedef unsigned int   INT16U;         
 typedef signed   int   INT16S;         
 typedef unsigned long  INT32U;         
 typedef signed   long  INT32S;         
 typedef float          FP32;           
 typedef double         FP64;           
 
 typedef unsigned char  OS_STK;         
 
 
 
 
 
 
 
 





 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 96 ".\Lib\AppConfig.h" /0
 
  
#line 1 "uCOSII\os_cfg.h" /0













 
 




 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 97 ".\Lib\AppConfig.h" /0
 
  
#line 1 "uCOSII\ucos_ii.h" /0













 
 




 
 
 
 
 
 
 
#line 27 "uCOSII\ucos_ii.h" /1
  
 
#line 29 "uCOSII\ucos_ii.h" /0
 
 
 
 
 
 
#line 35 "uCOSII\ucos_ii.h" /1
  
 
#line 37 "uCOSII\ucos_ii.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 




 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 




 
 
 
 typedef struct {
 void   *OSEventPtr;                     
 INT8U   OSEventTbl[((8) / 8 + 1)];  
 INT16U  OSEventCnt;                     
 INT8U   OSEventType;                    
 INT8U   OSEventGrp;                     
 } OS_EVENT;
 
 
 




 
 
 
 typedef struct {
 void   *OSMsg;                          
 INT8U   OSEventTbl[((8) / 8 + 1)];  
 INT8U   OSEventGrp;                     
 } OS_MBOX_DATA;
 
 




 
 
 
#line 161 "uCOSII\ucos_ii.h" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 179 "uCOSII\ucos_ii.h" /0
 
 




 
 
 
#line 188 "uCOSII\ucos_ii.h" /1
 
 
 
 
 
 
 
 
#line 196 "uCOSII\ucos_ii.h" /0
 




 
 
 
 typedef struct {
 INT16U  OSCnt;                           
 INT8U   OSEventTbl[((8) / 8 + 1)];   
 INT8U   OSEventGrp;                      
 } OS_SEM_DATA;
 
 




 
 
 
#line 218 "uCOSII\ucos_ii.h" /1
 
 
 
 
 
#line 223 "uCOSII\ucos_ii.h" /0
 
 




 
 
 typedef struct os_tcb {
 OS_STK        *OSTCBStkPtr;         
 
 
#line 235 "uCOSII\ucos_ii.h" /1
 
 
 
 
 
 
#line 241 "uCOSII\ucos_ii.h" /0
 
 struct os_tcb *OSTCBNext;           
 struct os_tcb *OSTCBPrev;           
 
 
 OS_EVENT      *OSTCBEventPtr;       
 
 
 
 void          *OSTCBMsg;            
 
 
 INT16U         OSTCBDly;            
 INT8U          OSTCBStat;           
 INT8U          OSTCBPrio;           
 
 INT8U          OSTCBX;              
 INT8U          OSTCBY;              
 INT8U          OSTCBBitX;           
 INT8U          OSTCBBitY;           
 
 
#line 263 "uCOSII\ucos_ii.h" /1
 
 
#line 265 "uCOSII\ucos_ii.h" /0
 } OS_TCB;
 
 




 
 
  INT32U       OSCtxSwCtr;                
 
 
  OS_EVENT    *OSEventFreeList;           
  OS_EVENT     OSEventTbl[20]; 
 
 
  INT32U       OSIdleCtr;                 
 
 
  INT8S        OSCPUUsage;                
  INT32U       OSIdleCtrMax;              
  INT32U       OSIdleCtrRun;              
  BOOLEAN      OSStatRdy;                 
 
 
  INT8U        OSIntNesting;              
 
  INT8U        OSLockNesting;             
 
  idata INT8U   OSPrioCur;                 
  idata INT8U   OSPrioHighRdy;             
 
  INT8U        OSRdyGrp;                         
  INT8U        OSRdyTbl[((8) / 8 + 1)];        
 
  idata BOOLEAN  OSRunning;                        
 
 
  INT8U        OSTaskCtr;                        
 
 
  idata OS_TCB   *OSTCBCur;                         
  OS_TCB        *OSTCBFreeList;                    
  idata OS_TCB   *OSTCBHighRdy;                     
  OS_TCB        *OSTCBList;                        
  OS_TCB        *OSTCBPrioTbl[8 + 1]; 
 
  INT32U       OSTime;                    
 
 
 extern  INT8U const  OSMapTbl[];                
 extern  INT8U const  OSUnMapTbl[];              
 
 





 
 




 
 
 void       *OSMboxAccept(OS_EVENT *pevent) ;
 OS_EVENT   *OSMboxCreate(void *msg) ;
 void       *OSMboxPend(OS_EVENT *pevent, INT16U timeout, INT8U *err) ;
 INT8U       OSMboxPost(OS_EVENT *pevent, void *msg) ;
 INT8U       OSMboxQuery(OS_EVENT *pevent, OS_MBOX_DATA *ppdata) ;
 




 
 
#line 344 "uCOSII\ucos_ii.h" /1
 
 
 
 
 
#line 349 "uCOSII\ucos_ii.h" /0




 
 
#line 355 "uCOSII\ucos_ii.h" /1
 
 
 
 
 
 
 
 
#line 363 "uCOSII\ucos_ii.h" /0
 




 
 
 INT16U      OSSemAccept(OS_EVENT *pevent) ;
 OS_EVENT   *OSSemCreate(INT16U value) ;
 void        OSSemPend(OS_EVENT *pevent, INT16U timeout, INT8U *err) ;
 INT8U       OSSemPost(OS_EVENT *pevent) ;
 INT8U       OSSemQuery(OS_EVENT *pevent, OS_SEM_DATA *ppdata) ;
 




 
 
#line 382 "uCOSII\ucos_ii.h" /1
 
 
#line 384 "uCOSII\ucos_ii.h" /0
 
 INT8U       OSTaskCreate(void (*task)(void *pd), void *ppdata, OS_STK *ptos, INT8U prio) ;
 
 
#line 388 "uCOSII\ucos_ii.h" /1
 
 
 
 
 
 
 
 
 
 
#line 398 "uCOSII\ucos_ii.h" /0
 
 
#line 400 "uCOSII\ucos_ii.h" /1
 
 
 
#line 403 "uCOSII\ucos_ii.h" /0
 
 
 INT8U       OSTaskResume(INT8U prio) ;
 INT8U       OSTaskSuspend(INT8U prio) ;
 
 
 
#line 410 "uCOSII\ucos_ii.h" /1
 
 
#line 412 "uCOSII\ucos_ii.h" /0
 
 INT8U       OSTaskQuery(INT8U prio, OS_TCB *ppdata) ;
 




 
 void        OSTimeDly(INT16U ticks) ;
 INT8U       OSTimeDlyHMSM(INT8U hours, INT8U minutes, INT8U seconds, INT16U milli) ;
 INT8U       OSTimeDlyResume(INT8U prio) ;
 INT32U      OSTimeGet(void) ;
 void        OSTimeSet(INT32U ticks) ;
 void        OSTimeTick(void) ;
 




 
 
 void        OSInit(void) ;
 
 void        OSIntEnter(void) ;
 void        OSIntExit(void) ;
 
 void        OSSchedLock(void) ;
 void        OSSchedUnlock(void) ;
 
 void        OSStart(void) ;
 
 void        OSStatInit(void) ;
 
 INT16U      OSVersion(void) ;
 
 





 
 
 
 void        OSEventTaskRdy(OS_EVENT *pevent, void *msg, INT8U msk) ;
 void        OSEventTaskWait(OS_EVENT *pevent) ;
 void        OSEventTO(OS_EVENT *pevent) ;
 void        OSEventWaitListInit(OS_EVENT *pevent) ;
 
 
 
#line 463 "uCOSII\ucos_ii.h" /1
 
 
#line 465 "uCOSII\ucos_ii.h" /0
 
 
#line 467 "uCOSII\ucos_ii.h" /1
 
 
#line 469 "uCOSII\ucos_ii.h" /0
 
 void        OSSched(void) ;
 
 void        OSTaskIdle(void *ddata) ;
 
 
 void        OSTaskStat(void *ddata) ;
 
 
 INT8U       OSTCBInit(INT8U prio, OS_STK *ptos, OS_STK *pbos, INT16U id, INT16U stk_size, void *pext, INT16U opt) ;
 
 





 
 
 void        OSCtxSw(void);
 
 void        OSIntCtxSw(void);
 
 void        OSStartHighRdy(void);
 
 void        OSTaskCreateHook(OS_TCB *ptcb) ;
 void        OSTaskDelHook(OS_TCB *ptcb) ;
 void        OSTaskStatHook(void) ;
 void       *OSTaskStkInit(void (*task)(void *pd), void *ppdata, void *ptos, INT16U opt) ;
 void        OSTaskSwHook(void) ;
 
 void        OSTickISR(void);
 
 void        OSTimeTickHook(void) ;
 
 
 void        InitOsTimer(void) ;
#line 98 ".\Lib\AppConfig.h" /0
 
 
 
 
 
 
 
 
 
  
#line 1 ".\App\InitConfig.h" /0
 
 
 
  
#line 1 ".\Lib\appConfig.h" /0
 
#line 2 ".\Lib\appConfig.h" /1
  
 
 
  
  
  
  
  
 
 
  
 
 
  
 
 
  
 
 
  
 
 
  
 
 
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
  
  
  
  
  
  
 
  
  
  
  
  
 
  
  
  
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
#line 4 ".\App\InitConfig.h" /0
#line 4 ".\App\InitConfig.h" /0
 
 
 void Init_Device(void);
 
 
 
#line 107 ".\Lib\AppConfig.h" /0
 
 
 
 
 
 
 
#line 17 "uCOSII\UCOS_II.C" /0
 
 
 
 
  
#line 1 "uCOSII\os_core.c" /0














 
 
 
#line 18 "uCOSII\os_core.c" /1
  
  
 
#line 21 "uCOSII\os_core.c" /0
 




 
 
 static  INT8U        OSIntExitY;                
 
 static  OS_STK       OSTaskIdleStk[255];        
 
 
 static  OS_STK       OSTaskStatStk[255];       
 
 
 static  OS_TCB       OSTCBTbl[8 + 2];    
 
 







 
 
 INT8U const OSMapTbl[]   = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
 







 
 
 INT8U const OSUnMapTbl[] = {
 0, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0
 };
 
 




















 
 
 void  OSEventTaskRdy (OS_EVENT *pevent, void *msg, INT8U msk) 
 {
 OS_TCB *ptcb;
 INT8U   x;
 INT8U   y;
 INT8U   bitx;
 INT8U   bity;
 INT8U   prio;
 
 
 y    = OSUnMapTbl[pevent->OSEventGrp];             
 bity = OSMapTbl[y];
 x    = OSUnMapTbl[pevent->OSEventTbl[y]];
 bitx = OSMapTbl[x];
 prio = (INT8U)((y << 3) + x);                      
 if ((pevent->OSEventTbl[y] &= ~bitx) == 0) {       
 pevent->OSEventGrp &= ~bity;
 }
 ptcb                 =  OSTCBPrioTbl[prio];        
 ptcb->OSTCBDly       =  0;                         
 ptcb->OSTCBEventPtr  = (OS_EVENT *)0;              
 
 ptcb->OSTCBMsg       = msg;                        
 
#line 125 "uCOSII\os_core.c" /1
 
 
#line 127 "uCOSII\os_core.c" /0
 ptcb->OSTCBStat     &= ~msk;                       
 if (ptcb->OSTCBStat == 0x00) {              
 OSRdyGrp        |=  bity;                      
 OSRdyTbl[y]     |=  bitx;
 }
 }
 
 













 
 
 void  OSEventTaskWait (OS_EVENT *pevent) 
 {
 OSTCBCur->OSTCBEventPtr = pevent;             
 if ((OSRdyTbl[OSTCBCur->OSTCBY] &= ~OSTCBCur->OSTCBBitX) == 0) {       
 OSRdyGrp &= ~OSTCBCur->OSTCBBitY;
 }
 pevent->OSEventTbl[OSTCBCur->OSTCBY] |= OSTCBCur->OSTCBBitX;           
 pevent->OSEventGrp                   |= OSTCBCur->OSTCBBitY;
 }
 
 













 
 
 void  OSEventTO (OS_EVENT *pevent) 
 {
 if ((pevent->OSEventTbl[OSTCBCur->OSTCBY] &= ~OSTCBCur->OSTCBBitX) == 0) {
 pevent->OSEventGrp &= ~OSTCBCur->OSTCBBitY;
 }
 OSTCBCur->OSTCBStat     = 0x00;        
 OSTCBCur->OSTCBEventPtr = (OS_EVENT *)0;      
 }
 
 












 
 
 void  OSEventWaitListInit (OS_EVENT *pevent) 
 {
 INT8U i;
 
 
 pevent->OSEventGrp = 0x00;                    
 for (i = 0; i < ((8) / 8 + 1); i++) {
 pevent->OSEventTbl[i] = 0x00;
 }
 }
 
 











 
 
 void OSInit (void) 
 {
 INT16U i;
 
 
 OSTime        = 0L;                                     
 OSIntNesting  = 0;                                      
 OSLockNesting = 0;                                      
 
 OSTaskCtr     = 0;                                      
 
 OSRunning     = 0;                                  
 OSIdleCtr     = 0L;                                     
 
#line 239 "uCOSII\os_core.c" /1
 
 
 
 
#line 243 "uCOSII\os_core.c" /0
 OSCtxSwCtr    = 0;                                      
 OSRdyGrp      = 0;                                      
 for (i = 0; i < ((8) / 8 + 1); i++) {
 OSRdyTbl[i] = 0;
 }
 
 OSPrioCur     = 0;
 OSPrioHighRdy = 0;                                           
 OSTCBHighRdy  = (OS_TCB *)0;                                  
 OSTCBCur      = (OS_TCB *)0;
 OSTCBList     = (OS_TCB *)0;
 for (i = 0; i < (8 + 1); i++) {                  
 OSTCBPrioTbl[i] = (OS_TCB *)0;
 }
 for (i = 0; i < (8 + 2 - 1); i++) {   
 OSTCBTbl[i].OSTCBNext = &OSTCBTbl[i + 1];
 }
 OSTCBTbl[8 + 2 - 1].OSTCBNext = (OS_TCB *)0;     
 OSTCBFreeList                                         = &OSTCBTbl[0];
 
 
 for (i = 0; i < (20 - 1); i++) {             
 OSEventTbl[i].OSEventPtr = (OS_EVENT *)&OSEventTbl[i + 1];
 }
 OSEventTbl[20 - 1].OSEventPtr = (OS_EVENT *)0;
 OSEventFreeList                          = &OSEventTbl[0];    
 
 
 
#line 272 "uCOSII\os_core.c" /1
 
 
#line 274 "uCOSII\os_core.c" /0
 
 
#line 276 "uCOSII\os_core.c" /1
 
 
#line 278 "uCOSII\os_core.c" /0
 
 
#line 280 "uCOSII\os_core.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 294 "uCOSII\os_core.c" /0
 
#line 295 "uCOSII\os_core.c" /1
 
 
 
 
 
 
 
 
 
 
#line 305 "uCOSII\os_core.c" /0
 OSTaskCreate(OSTaskIdle, (void *)0, &OSTaskIdleStk[0], (8));
 
 
 
 
 
#line 311 "uCOSII\os_core.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 333 "uCOSII\os_core.c" /0
 
#line 334 "uCOSII\os_core.c" /1
 
 
 
 
 
#line 339 "uCOSII\os_core.c" /0
 OSTaskCreate(OSTaskStat, 
 (void *)0,                                    
 &OSTaskStatStk[0],                            
  (8 - 1));                                
 
 
 
 }
 





















 
 
 void OSIntEnter (void) 
 {
  EA=0;
 OSIntNesting++;                               
  EA=1;
 }
 

















 
 
 void OSIntExit (void) 
 {
  EA=0;
 if ((--OSIntNesting | OSLockNesting) == 0) {  
 OSIntExitY    = OSUnMapTbl[OSRdyGrp];
 OSPrioHighRdy = (INT8U)((OSIntExitY << 3) + OSUnMapTbl[OSRdyTbl[OSIntExitY]]);
 if (OSPrioHighRdy != OSPrioCur) {         
 OSTCBHighRdy  = OSTCBPrioTbl[OSPrioHighRdy];
 OSCtxSwCtr++;                         
 OSIntCtxSw();                         
 }
 }
  EA=1;
 }
 















 
 
 void OSSched (void) 
 {
 INT8U y;
 
 
  EA=0;
 if ((OSLockNesting | OSIntNesting) == 0) {    
 y             = OSUnMapTbl[OSRdyGrp];     
 OSPrioHighRdy = (INT8U)((y << 3) + OSUnMapTbl[OSRdyTbl[y]]);
 if (OSPrioHighRdy != OSPrioCur) {          
 OSTCBHighRdy = OSTCBPrioTbl[OSPrioHighRdy];
 OSCtxSwCtr++;                         
  OSCtxSw();                         
 }
 }
  EA=1;
 }
 














 
 
 void OSSchedLock (void) 
 {
 if (OSRunning == 1) {                      
  EA=0;
 OSLockNesting++;                          
  EA=1;
 }
 }
 













 
 
 void OSSchedUnlock (void) 
 {
 if (OSRunning == 1) {                            
  EA=0;
 if (OSLockNesting > 0) {                        
 OSLockNesting--;                            
 if ((OSLockNesting | OSIntNesting) == 0) {  
  EA=1;
 OSSched();                              
 } else {
  EA=1;
 }
 } else {
  EA=1;
 }
 }
 }
 
















 
 
 void OSStart (void) 
 {
 INT8U y;
 INT8U x;
 
 
 if (OSRunning == 0) {
 y             = OSUnMapTbl[OSRdyGrp];         
 x             = OSUnMapTbl[OSRdyTbl[y]];
 OSPrioHighRdy = (INT8U)((y << 3) + x);
 OSPrioCur     = OSPrioHighRdy;
 OSTCBHighRdy  = OSTCBPrioTbl[OSPrioHighRdy];  
 OSTCBCur      = OSTCBHighRdy;
 OSStartHighRdy();                             
 }
 }
 


















 
 
 
 void OSStatInit (void) 
 {
 OSTimeDly(2);                                 
  EA=0;
 OSIdleCtr    = 0L;                            
  EA=1;
 OSTimeDly(200);                  
  EA=0;
 OSIdleCtrMax = OSIdleCtr;                     
 OSStatRdy    = 1;
  EA=1;
 }
 
 











 
 
 void OSTaskIdle (void *ppdata) 
 {
 ppdata = ppdata;                                
 for (;;) {
  EA=0;
 OSIdleCtr++;
  EA=1;
 }
 }
 
























 
 
 
 void OSTaskStat (void *ppdata) 
 {
 INT32U run;
 INT8S  usage;
 
 
 ppdata = ppdata;                                
 while (OSStatRdy == 0) {
 OSTimeDly(2 * 200);              
 }
 for (;;) {
  EA=0;
 OSIdleCtrRun = OSIdleCtr;                 
 run          = OSIdleCtr;
 OSIdleCtr    = 0L;                        
  EA=1;
 if (OSIdleCtrMax > 0L) {
 usage = (INT8S)(100L - 100L * run / OSIdleCtrMax);
 if (usage > 100) {
 OSCPUUsage = 100;
 } else if (usage < 0) {
 OSCPUUsage =   0;
 } else {
 OSCPUUsage = usage;
 }
 } else {
 OSCPUUsage = 0;
 }
 OSTaskStatHook();                         
 OSTimeDly(200);              
 }
 }
 
 









































 
 
 INT8U OSTCBInit (INT8U prio, OS_STK *ptos, OS_STK *pbos, INT16U id, INT16U stk_size, void *pext, INT16U opt) 
 {
 OS_TCB *ptcb;
 
 
  EA=0;
 ptcb = OSTCBFreeList;                                   
 if (ptcb != (OS_TCB *)0) {
 OSTCBFreeList        = ptcb->OSTCBNext;             
  EA=1;
 ptcb->OSTCBStkPtr    = ptos;                        
 ptcb->OSTCBPrio      = (INT8U)prio;                 
 ptcb->OSTCBStat      = 0x00;                 
 ptcb->OSTCBDly       = 0;                           
 
 
#line 718 "uCOSII\os_core.c" /1
 
 
 
 
 
 
#line 724 "uCOSII\os_core.c" /0
 pext                 = pext;                        
 stk_size             = stk_size;
 pbos                 = pbos;
 opt                  = opt;
 id                   = id;
 
 
 
#line 732 "uCOSII\os_core.c" /1
 
 
#line 734 "uCOSII\os_core.c" /0
 
 ptcb->OSTCBY         = prio >> 3;                   
 ptcb->OSTCBBitY      = OSMapTbl[ptcb->OSTCBY];
 ptcb->OSTCBX         = prio & 0x07;
 ptcb->OSTCBBitX      = OSMapTbl[ptcb->OSTCBX];
 
 
 ptcb->OSTCBEventPtr  = (OS_EVENT *)0;               
 
 
 
 ptcb->OSTCBMsg       = (void *)0;                   
 
 
  EA=0;
 OSTCBPrioTbl[prio]   = ptcb;
 ptcb->OSTCBNext      = OSTCBList;                   
 ptcb->OSTCBPrev      = (OS_TCB *)0;
 if (OSTCBList != (OS_TCB *)0) {
 OSTCBList->OSTCBPrev = ptcb;
 }
 OSTCBList               = ptcb;
 OSRdyGrp               |= ptcb->OSTCBBitY;          
 OSRdyTbl[ptcb->OSTCBY] |= ptcb->OSTCBBitX;
  EA=1;
 return (0);
 } else {
  EA=1;
 return (70);
 }
 }
 












 
 
 void OSTimeTick (void) 
 {
 OS_TCB *ptcb;
 
 
 OSTimeTickHook();                                       
 ptcb = OSTCBList;                                       
 while (ptcb->OSTCBPrio != (8)) {               
  EA=0;
 if (ptcb->OSTCBDly != 0) {                          
 if (--ptcb->OSTCBDly == 0) {                    
 if (!(ptcb->OSTCBStat & 0x08)) {     
 OSRdyGrp               |= ptcb->OSTCBBitY;  
 OSRdyTbl[ptcb->OSTCBY] |= ptcb->OSTCBBitX;
 } else {                                        
 ptcb->OSTCBDly = 1;                         
 }                                               
 }
 }
 ptcb = ptcb->OSTCBNext;                             
  EA=1;
 }
  EA=0;                                    
 OSTime++;
  EA=1;
 }
 












 
 
 INT16U OSVersion (void) 
 {
 return (200);
 }
#line 21 "uCOSII\UCOS_II.C" /0
 
  
#line 1 "uCOSII\os_mbox.c" /0














 
 
 
#line 18 "uCOSII\os_mbox.c" /1
  
 
#line 20 "uCOSII\os_mbox.c" /0
 
 













 
 
 void *OSMboxAccept (OS_EVENT *pevent) 
 {
 void  *msg;
 
 
  EA=0;
 if (pevent->OSEventType != 1) {       
  EA=1;
 return ((void *)0);
 }
 msg = pevent->OSEventPtr; 
 if (msg != (void *)0) {                                
 pevent->OSEventPtr = (void *)0;                    
 }
  EA=1;
 return (msg);                                          
 }
 














 
 
 OS_EVENT *OSMboxCreate (void *msg) 
 {
 OS_EVENT *pevent;
 
 
  EA=0;
 pevent = OSEventFreeList;                     
 if (OSEventFreeList != (OS_EVENT *)0) {       
 OSEventFreeList = (OS_EVENT *)OSEventFreeList->OSEventPtr;
 }
  EA=1;
 if (pevent != (OS_EVENT *)0) {
 pevent->OSEventType = 1;
 pevent->OSEventPtr  = msg;                
 OSEventWaitListInit(pevent);
 }
 return (pevent);                              
 }
 


























 
 
 void *OSMboxPend (OS_EVENT *pevent, INT16U timeout, INT8U *err) 
 {
 void  *msg;
 
 
  EA=0;
 if (pevent->OSEventType != 1) {   
  EA=1;
 *err = 1;
 return ((void *)0);
 }
 msg = pevent->OSEventPtr;
 if (msg != (void *)0) {                            
 pevent->OSEventPtr = (void *)0;                
  EA=1;
 *err = 0;
 } else if (OSIntNesting > 0) {                     
  EA=1;                            
 *err = 2;
 } else {
 OSTCBCur->OSTCBStat |= 0x02;           
 OSTCBCur->OSTCBDly   = timeout;                
 OSEventTaskWait(pevent);                       
  EA=1;
 OSSched();                                     
  EA=0;
 if ((msg = OSTCBCur->OSTCBMsg) != (void *)0) {      
 OSTCBCur->OSTCBMsg      = (void *)0;            
 OSTCBCur->OSTCBStat     = 0x00;
 OSTCBCur->OSTCBEventPtr = (OS_EVENT *)0;        
  EA=1;
 *err                    = 0;
 } else if (OSTCBCur->OSTCBStat & 0x02) {    
 OSEventTO(pevent);                              
  EA=1;
 msg                     = (void *)0;            
 *err                    = 10;           
 } else {
 msg                     = pevent->OSEventPtr;   
 pevent->OSEventPtr      = (void *)0;            
 OSTCBCur->OSTCBEventPtr = (OS_EVENT *)0;
  EA=1;
 *err                    = 0;
 }
 }
 return (msg);                                           
 }
 
















 
 
 INT8U OSMboxPost (OS_EVENT *pevent, void *msg) 
 {
  EA=0;
 if (pevent->OSEventType != 1) {   
  EA=1;
 return (1);
 }
 if (pevent->OSEventGrp) {                          
 OSEventTaskRdy(pevent, msg, 0x02);     
  EA=1;
 OSSched();                                     
 return (0);
 } else {
 if (pevent->OSEventPtr != (void *)0) {         
  EA=1;
 return (20);
 } else {
 pevent->OSEventPtr = msg;                  
  EA=1;
 return (0);
 }
 }
 }
 














 
 
 INT8U OSMboxQuery (OS_EVENT *pevent, OS_MBOX_DATA *ppdata) 
 {
 INT8U  i;
 INT8U *psrc;
 INT8U *pdest;
 
 
  EA=0;
 if (pevent->OSEventType != 1) {        
  EA=1;
 return (1);
 }
 ppdata->OSEventGrp = pevent->OSEventGrp;                 
 psrc              = &pevent->OSEventTbl[0];
 pdest             = &ppdata->OSEventTbl[0];
 for (i = 0; i < ((8) / 8 + 1); i++) {
 *pdest++ = *psrc++;   
 }
 ppdata->OSMsg = pevent->OSEventPtr;                      
  EA=1;
 return (0);
 }
 
#line 22 "uCOSII\UCOS_II.C" /0
 
  
#line 1 "uCOSII\os_mem.c" /0














 
 
 
#line 18 "uCOSII\os_mem.c" /1
  
 
#line 20 "uCOSII\os_mem.c" /0
 
 
#line 22 "uCOSII\os_mem.c" /1




 
 
 
 
 
























 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 











 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 














 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 














 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 23 "uCOSII\UCOS_II.C" /0
#line 23 "uCOSII\UCOS_II.C" /0
 
  
#line 1 "uCOSII\os_q.c" /0














 
 
 
#line 18 "uCOSII\os_q.c" /1
  
 
#line 20 "uCOSII\os_q.c" /0
 
 
#line 22 "uCOSII\os_q.c" /1




 
 
 
 
 
 
 
 
 
 
 
 




 
 
 
 
 
 















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 











 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 











 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

























 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 














 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 














 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 24 "uCOSII\UCOS_II.C" /0
#line 24 "uCOSII\UCOS_II.C" /0
 
  
#line 1 "uCOSII\os_sem.c" /0














 
 
 
#line 18 "uCOSII\os_sem.c" /1
  
 
#line 20 "uCOSII\os_sem.c" /0
 
 















 
 
 INT16U OSSemAccept (OS_EVENT *pevent) 
 {
 INT16U cnt;
 
 
  EA=0;
 if (pevent->OSEventType != 3) {    
  EA=1;
 return (0);
 }
 cnt = pevent->OSEventCnt;
 if (cnt > 0) {                                     
 pevent->OSEventCnt--;                          
 }
  EA=1;
 return (cnt);                                      
 }
 
 















 
 
 OS_EVENT *OSSemCreate (INT16U cnt) 
 {
 OS_EVENT *pevent;
 
 
  EA=0;
 pevent = OSEventFreeList;                               
 if (OSEventFreeList != (OS_EVENT *)0) {                 
 OSEventFreeList = (OS_EVENT *)OSEventFreeList->OSEventPtr;
 }
  EA=1;
 if (pevent != (OS_EVENT *)0) {                          
 pevent->OSEventType = 3;
 pevent->OSEventCnt  = cnt;                          
 OSEventWaitListInit(pevent);
 }
 return (pevent);
 }
 
 



























 
 
 void OSSemPend (OS_EVENT *pevent, INT16U timeout, INT8U *err) 
 {
  EA=0;
 if (pevent->OSEventType != 3) {    
  EA=1;
 *err = 1;
 }
 if (pevent->OSEventCnt > 0) {                      
 pevent->OSEventCnt--;                          
  EA=1;
 *err = 0;
 } else if (OSIntNesting > 0) {                     
  EA=1;                            
 *err = 2;
 } else {                                           
 OSTCBCur->OSTCBStat    |= 0x01;         
 OSTCBCur->OSTCBDly      = timeout;             
 OSEventTaskWait(pevent);                       
  EA=1;
 OSSched();                                     
  EA=0;
 if (OSTCBCur->OSTCBStat & 0x01) {       
 OSEventTO(pevent);
  EA=1;
 *err = 10;                         
 } else {
 OSTCBCur->OSTCBEventPtr = (OS_EVENT *)0;
  EA=1;
 *err = 0;
 }
 }
 }
 















 
 
 INT8U OSSemPost (OS_EVENT *pevent) 
 {
  EA=0;
 if (pevent->OSEventType != 3) {         
  EA=1;
 return (1);
 }
 if (pevent->OSEventGrp) {                               
 OSEventTaskRdy(pevent, (void *)0, 0x01);     
  EA=1;
 OSSched();                                     
 return (0);
 } else {
 if (pevent->OSEventCnt < 65535) {              
 pevent->OSEventCnt++;                      
  EA=1;
 return (0);
 } else {                                       
  EA=1;
 return (50);
 }
 }
 }















 
 
 INT8U OSSemQuery (OS_EVENT *pevent, OS_SEM_DATA *ppdata) 
 {
 INT8U  i;
 INT8U *psrc;
 INT8U *pdest;
 
 
  EA=0;
 if (pevent->OSEventType != 3) {         
  EA=1;
 return (1);
 }
 ppdata->OSEventGrp = pevent->OSEventGrp;                 
 psrc              = &pevent->OSEventTbl[0];
 pdest             = &ppdata->OSEventTbl[0];
 for (i = 0; i < ((8) / 8 + 1); i++) {
 *pdest++ = *psrc++;   
 }
 ppdata->OSCnt      = pevent->OSEventCnt;                 
  EA=1;
 return (0);
 }
 
#line 25 "uCOSII\UCOS_II.C" /0
 
  
#line 1 "uCOSII\os_task.c" /0














 
 
 
#line 18 "uCOSII\os_task.c" /1
  
 
#line 20 "uCOSII\os_task.c" /0
 




 
 
 
 static  void  OSDummy(void) ;
 











 
 
 static void  OSDummy (void) 
 {
 }
 
 


















 
 
 
#line 69 "uCOSII\os_task.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 132 "uCOSII\os_task.c" /0
 





































 
 
 
 INT8U OSTaskCreate (void (*task)(void *pd), void *ppdata, OS_STK *ptos, INT8U prio) 
 {
 void   *psp;
 INT8U   err;
 
 
 if (prio > 8) {              
 return (42);
 }
  EA=0;
 if (OSTCBPrioTbl[prio] == (OS_TCB *)0) {  
 OSTCBPrioTbl[prio] = (OS_TCB *)1;     
 
  EA=1;
 psp = (void *)OSTaskStkInit(task, ppdata, ptos, 0);  
 err = OSTCBInit(prio, psp, (void *)0, 0, 0, (void *)0, 0);         
 if (err == 0) {
  EA=0;
 OSTaskCtr++;                                    
 OSTaskCreateHook(OSTCBPrioTbl[prio]);           
  EA=1;
 if (OSRunning) {                  
 OSSched();
 }
 } else {
  EA=0;
 OSTCBPrioTbl[prio] = (OS_TCB *)0; 
  EA=1;
 }
 return (err);
 } else {
  EA=1;
 return (40);
 }
 }
 
 






























































 
 
 
#line 275 "uCOSII\os_task.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 335 "uCOSII\os_task.c" /0
 



































 
 
 
#line 374 "uCOSII\os_task.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 431 "uCOSII\os_task.c" /0
 











































 
 
 
#line 478 "uCOSII\os_task.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 509 "uCOSII\os_task.c" /0
 















 
 
 
 INT8U OSTaskResume (INT8U prio) 
 {
 OS_TCB   *ptcb;
 
 
 if (prio >= 8) {                                
 return (42);
 }
  EA=0;
 if ((ptcb = OSTCBPrioTbl[prio]) == (OS_TCB *)0) {            
  EA=1;
 return (100);
 } else {
 if (ptcb->OSTCBStat & 0x08) {                            
 if (((ptcb->OSTCBStat &= ~0x08) == 0x00) &&   
 (ptcb->OSTCBDly  == 0)) {                                  
 OSRdyGrp               |= ptcb->OSTCBBitY;                  
 OSRdyTbl[ptcb->OSTCBY] |= ptcb->OSTCBBitX;
  EA=1;
 OSSched();
 } else {
  EA=1;
 }
 return (0);
 } else {
  EA=1;
 return (101);
 }
 }
 }
 
 

















 
 
#line 579 "uCOSII\os_task.c" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 623 "uCOSII\os_task.c" /0
 




















 
 
 
 INT8U OSTaskSuspend (INT8U prio) 
 {
 BOOLEAN   self;
 OS_TCB   *ptcb;
 
 
 if (prio == (8)) {                                  
 return (91);
 }
 if (prio >= 8 && prio != 0xFF) {        
 return (42);
 }
  EA=0;
 if (prio == 0xFF) {                                  
 prio = OSTCBCur->OSTCBPrio;
 self = 1;
 } else if (prio == OSTCBCur->OSTCBPrio) {                    
 self = 1;
 } else {
 self = 0;                                            
 }
 if ((ptcb = OSTCBPrioTbl[prio]) == (OS_TCB *)0) {                 
  EA=1;
 return (90);
 } else {
 if ((OSRdyTbl[ptcb->OSTCBY] &= ~ptcb->OSTCBBitX) == 0) {      
 OSRdyGrp &= ~ptcb->OSTCBBitY;
 }
 ptcb->OSTCBStat |= 0x08;                           
  EA=1;
 if (self == 1) {                                           
 OSSched();
 }
 return (0);
 }
 }
 
 













 
 
 INT8U OSTaskQuery (INT8U prio, OS_TCB *ppdata) 
 {
 OS_TCB *ptcb;
 
 
 if (prio > 8 && prio != 0xFF) {    
 return (42);
 }
  EA=0;
 if (prio == 0xFF) {                             
 prio = OSTCBCur->OSTCBPrio;
 }
 if ((ptcb = OSTCBPrioTbl[prio]) == (OS_TCB *)0) {       
  EA=1;
 return (41);
 }
 *ppdata = *ptcb;                                         
  EA=1;
 return (0);
 }
#line 26 "uCOSII\UCOS_II.C" /0
 
  
#line 1 "uCOSII\os_time.c" /0














 
 
 
#line 18 "uCOSII\os_time.c" /1
  
 
#line 20 "uCOSII\os_time.c" /0
 














 
 
 void OSTimeDly (INT16U ticks) 
 {
 if (ticks > 0) {                                                       
  EA=0;
 if ((OSRdyTbl[OSTCBCur->OSTCBY] &= ~OSTCBCur->OSTCBBitX) == 0) {   
 OSRdyGrp &= ~OSTCBCur->OSTCBBitY;
 }
 OSTCBCur->OSTCBDly = ticks;                                        
  EA=1;
 OSSched();                                                         
 }
 }
 























 
 
 INT8U OSTimeDlyHMSM (INT8U hours, INT8U minutes, INT8U seconds, INT16U milli) 
 {
 INT32U ticks;
 INT16U loops;
 
 
 if (hours > 0 || minutes > 0 || seconds > 0 || milli > 0) {
 if (minutes > 59) {
 return (81);     
 }
 if (seconds > 59) {
 return (82);
 }
 if (milli > 999) {
 return (83);
 }
 
 
 ticks = ((INT32U)hours * 3600L + (INT32U)minutes * 60L + (INT32U)seconds) * 200
 + 200 * ((INT32U)milli + 500L / 200) / 1000L;
 loops = ticks / 65536L;                   
 ticks = ticks % 65536L;                   
 OSTimeDly(ticks);
 while (loops > 0) {
 OSTimeDly(32768);
 OSTimeDly(32768);
 loops--;
 }
 return (0);
 } else {
 return (84);
 }
 }
 






















 
 
 INT8U OSTimeDlyResume (INT8U prio) 
 {
 OS_TCB *ptcb;
 
 
 if (prio >= 8) {
 return (42);
 }
  EA=0;
 ptcb = (OS_TCB *)OSTCBPrioTbl[prio];                    
 if (ptcb != (OS_TCB *)0) {
 if (ptcb->OSTCBDly != 0) {                          
 ptcb->OSTCBDly  = 0;                            
 if (!(ptcb->OSTCBStat & 0x08)) {     
 OSRdyGrp               |= ptcb->OSTCBBitY;  
 OSRdyTbl[ptcb->OSTCBY] |= ptcb->OSTCBBitX;
  EA=1;
 OSSched();                                  
 } else {
  EA=1;                         
 }
 return (0);
 } else {
  EA=1;
 return (80);                       
 }
 } else {
  EA=1;
 return (11);                         
 }
 }
 











 
 
 INT32U OSTimeGet (void) 
 {
 INT32U ticks;
 
 
  EA=0;
 ticks = OSTime;
  EA=1;
 return (ticks);
 }
 










 
 
 void OSTimeSet (INT32U ticks) 
 {
  EA=0;
 OSTime = ticks;
  EA=1;
 }
#line 27 "uCOSII\UCOS_II.C" /0
 
 
 
 
 
