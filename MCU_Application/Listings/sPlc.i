
#line 1 "MainApp\sPlc.c" /0
  
#line 1 "MainApp\sPlc.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
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
 
 
#line 78 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\stdbool.h" /0




 
 
 
 
 
 
 
 typedef bit bool;
 enum{
 false = 0,
 true = 1,
 };
 
 
#line 19 ".\Lib\stdbool.h" /1
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
#line 43 ".\Lib\stdbool.h" /0
 
 
 
#line 79 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\endian.h" /0




 
 
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 31 ".\Lib\endian.h" /1
 
  
  
  
  
 
  
  
  
  
 
 
 
  
  
  
  
 
  
  
  
  
 
 
#line 55 ".\Lib\endian.h" /0
 
 
#line 80 "MainApp\appConfig.h" /0
 
  
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
 
 
 
 
#line 81 "MainApp\appConfig.h" /0
 
  
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
 
 
 
 
 
 
 
 
 
 
#line 82 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\C8051F020_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 337 ".\Lib\C8051F020_defs.h" /1
 
 
 
 
#line 341 ".\Lib\C8051F020_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 83 "MainApp\appConfig.h" /0
 
 
  
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
 
 
 
#line 85 "MainApp\appConfig.h" /0
 
  
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
 
 
#line 86 "MainApp\appConfig.h" /0
 
  
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
 
 
#line 87 "MainApp\appConfig.h" /0
 
  
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
 
 
 
#line 88 "MainApp\appConfig.h" /0
 
  
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
 
 
#line 89 "MainApp\appConfig.h" /0
 
  
#line 1 "C:\Keil_v5\C51\Inc\LIMITS.H" /0







 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 90 "MainApp\appConfig.h" /0
 
  
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
 
 
#line 91 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\crc32.h" /0
 
 
 
 
 
 
 
  
#line 1 "MainApp\AppConfig.h" /0
 
#line 2 "MainApp\AppConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 8 ".\Lib\crc32.h" /0
#line 8 ".\Lib\crc32.h" /0
 
 
 uint32_t crc32Calculate(uint8_t *buf, uint32_t len); 
 uint32_t crc32CalculateAdd(uint8_t dat); 
 void crc32Clear(void); 
 void crc32SetCrcOld(uint32_t old);
 
 
 
 
 
 
 
 
#line 92 "MainApp\appConfig.h" /0
 
 
  
#line 1 "MainApp\InitDeviceF020.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 4 "MainApp\InitDeviceF020.h" /0
#line 4 "MainApp\InitDeviceF020.h" /0
 
 
 void initDeviceF020(void);
 
#line 94 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\delay.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 4 ".\Lib\delay.h" /0
#line 4 ".\Lib\delay.h" /0
 
 
 void delayMs(uint8_t ms) reentrant;
 void delayUs(uint8_t us) reentrant;
 void hwDelayInit(uint8_t reload_h, uint8_t reload_l);
 void hwDelay(uint8_t control, uint8_t reload_h, uint8_t reload_l);
 
 
 
#line 95 "MainApp\appConfig.h" /0
 
  
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
 
 
 
 
#line 96 "MainApp\appConfig.h" /0
 
  
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
 
#line 97 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\dac8568_0.h" /0
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 1 ".\Driver\dac8568_0.h" /0
#line 1 ".\Driver\dac8568_0.h" /0
 
 
 void dac8568_0_Init(void);
 void dac8568_0_Update(uint8_t ch);
 void dac8568_0_WriteInputRegister(uint8_t ch, uint16_t dat);
 void dac8568_0_WriteDacRegister(uint8_t ch, uint16_t dat);
 void dac8568_0_Clear(void);
 void dac8568_0_Reset(void);
#line 98 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\dac8568_1.h" /0
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 1 ".\Driver\dac8568_1.h" /0
#line 1 ".\Driver\dac8568_1.h" /0
 
 
 void dac8568_1_Init(void);
 void dac8568_1_Update(uint8_t ch);
 void dac8568_1_WriteInputRegister(uint8_t ch, uint16_t dat);
 void dac8568_1_WriteDacRegister(uint8_t ch, uint16_t dat);
 void dac8568_1_Clear(void);
 void dac8568_1_Reset(void);
#line 99 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\dac8568_2.h" /0
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 1 ".\Driver\dac8568_2.h" /0
#line 1 ".\Driver\dac8568_2.h" /0
 
 
 void dac8568_2_Init(void);
 void dac8568_2_Update(uint8_t ch);
 void dac8568_2_WriteInputRegister(uint8_t ch, uint16_t dat);
 void dac8568_2_WriteDacRegister(uint8_t ch, uint16_t dat);
 void dac8568_2_Clear(void);
 void dac8568_2_Reset(void);
#line 100 "MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\dac8568_3.h" /0
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 1 ".\Driver\dac8568_3.h" /0
#line 1 ".\Driver\dac8568_3.h" /0
 
 
 void dac8568_3_Init(void);
 void dac8568_3_Update(uint8_t ch);
 void dac8568_3_WriteInputRegister(uint8_t ch, uint16_t dat);
 void dac8568_3_WriteDacRegister(uint8_t ch, uint16_t dat);
 void dac8568_3_Clear(void);
 void dac8568_3_Reset(void);
#line 101 "MainApp\appConfig.h" /0
 
  
#line 1 "MainApp\boxCmd.h" /0
 
 
 
  
#line 1 "MainApp\appConfig.h" /0
 
#line 2 "MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 4 "MainApp\boxCmd.h" /0
#line 4 "MainApp\boxCmd.h" /0
 
 
 void initboxSerial(uint32_t baudrate);
 void boxRedLedRefresh(void);
 void boxGreenLedRefresh(void);
 
#line 102 "MainApp\appConfig.h" /0
 
 
  
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
 
#line 104 "MainApp\appConfig.h" /0
 
  
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
 
 
#line 105 "MainApp\appConfig.h" /0
 
 
  
#line 1 "MainApp\sPLC.h" /0
 
#line 2 "MainApp\sPLC.h" /1
  
 
  
 
 
  
  
 
  
  
 
  
  
 
  
  
 
 
  
  
 
  
  
 
  
  
 
 
  
  
 
  
  
 
  
  
 
  
  
 
  
  
 
  
  
 
  
  
 
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
 
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 107 "MainApp\appConfig.h" /0
#line 107 "MainApp\appConfig.h" /0
 
 
 
#line 4 "MainApp\sPlc.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef struct{ 
 uint16_t dat[14];
 uint16_t out;
 uint8_t wIndex; 
 }adcTempDat_t;
 
 extern uint16_t ModbusSlaveAsciiOverTimeCounter; 
 extern xdata int16_t NVRAM0[(205 + 1)]; 
 extern xdata int16_t NVRAM1[(205 + 1)]; 
 
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
 
 void SET(uint16_t A); 
 void RESET(uint16_t A); 
 void FLIP(uint16_t A); 
 uint8_t LD(uint16_t A); 
 uint8_t LDP(uint16_t A); 
 uint8_t LDN(uint16_t A); 
 void T100US(uint8_t A, uint8_t start, uint16_t value);
 void T1MS(uint8_t A, uint8_t start, uint16_t value);
 void T10MS(uint8_t A, uint8_t start, uint16_t value);
 void T100MS(uint8_t A, uint8_t start, uint16_t value);
 
 void chipDacInit(void);
 void chipAdcInit(void);
 void sPlcInit(void);
 void refreshInput(void);
 void refreshOutput(void);
 void refreshDac(void);
 
 
#line 1 "MainApp\sPlc.c" /0
 
 
 
 sbit ADCMUX_0_3_S0 = P1^4;
 sbit ADCMUX_0_3_S1	= P1^7;
 sbit ADCMUX_0_3_OE1 = P1^6;
 sbit ADCMUX_0_3_OE2 = P1^5;
 
 sbit ADCMUX_4_7_S0 = P1^2;
 sbit ADCMUX_4_7_S1 = P1^1;
 sbit ADCMUC_4_7_OE1 = P1^0;
 sbit ADCMUC_4_7_OE2 = P1^3;
 
 sbit ADCMUX_8_11_S0 = P2^4;
 sbit ADCMUX_8_11_S1 = P2^6;
 sbit ADCMUX_8_11_OE1 = P2^7;
 sbit ADCMUX_8_11_OE2 = P2^5;
 
 sbit ADCMUX_12_15_S0 = P2^0;
 sbit ADCMUX_12_15_S1 = P2^2;
 sbit ADCMUX_12_15_OE1 = P2^3;
 sbit ADCMUX_12_15_OE2 = P2^1;
 
 sbit ADCMUX_16_19_S0 = P3^5;
 sbit ADCMUX_16_19_S1 = P3^7;
 sbit ADCMUX_16_19_OE1 = P3^6;
 sbit ADCMUX_16_19_OE2 = P3^4;
 
 sbit ADCMUX_20_23_S0 = P3^1;
 sbit ADCMUX_20_23_S1 = P3^3;
 sbit ADCMUX_20_23_OE1 = P3^2;
 sbit ADCMUX_20_23_OE2 = P3^0;
 
 sbit ADCMUX_24_27_S0 = P0^5;
 sbit ADCMUX_24_27_S1 = P0^7;
 sbit ADCMUX_24_27_OE1 = P0^6;
 sbit ADCMUX_24_27_OE2 = P0^4;
 
 xdata int16_t NVRAM0[(205 + 1)]; 
 xdata int16_t NVRAM1[(205 + 1)]; 
 static data uint8_t TimerCounter_1mS = 0;
 static data uint8_t TimerCounter_10mS = 0;
 static data uint8_t Timer0_L, Timer0_H;
 
 static pdata int8_t inputFilter[(196 - 196 + 1) * 16]; 
 static xdata adcTempDat_t adcTempDat[64];
 static uint8_t adcSelect; 
 static void refreshAdcData(adcTempDat_t *s , uint16_t dat);
 static void adcProcess(void);
 static void initAdcData(adcTempDat_t *s);
 static void chipDacInit(void);
 static void chipAdcInit(void);
 
 static uint8_t getGlobalInterrupt(void){
 return EA;
 }
 static void setLedRun(uint8_t st){ 
 if(st){
 P7 |= (uint8_t)(1 << 0);
 }
 else{
 P7 &= ~(uint8_t)(1 << 0);
 }
 }
 static uint8_t getLedRun(void){ 
 return (uint8_t)((P7 >> 0) & 0x01);
 }
 static void setLedEprom(uint8_t st){ 
 if(st){
 P7 |= (uint8_t)(1 << 1);
 }
 else{
 P7 &= ~(uint8_t)(1 << 1);
 }
 }
 static uint8_t getLedEprom(void){ 
 return (uint8_t)((P7 >> 1) & 0x01);
 }
 static void setLedDac(uint8_t st){ 
 if(st){
 P7 |= (uint8_t)(1 << 2);
 }
 else{
 P7 &= ~(uint8_t)(1 << 2);
 }
 }
 static uint8_t getLedDac(void){ 
 return (uint8_t)((P7 >> 2) & 0x01);
 }
 static void setLedError(uint8_t st){ 
 if(st){
 P7 |= (uint8_t)(1 << 3);
 }
 else{
 P7 &= ~(uint8_t)(1 << 3);
 }
 }
 static uint8_t getLedError(void) reentrant{
 return (uint8_t)((P7 >> 3) & 0x01);
 }
 static void adcProcess(void){ 
 uint16_t result = 0;
 
 
 
 result = (ADC0 & 0xFFF);
 refreshAdcData(&adcTempDat[adcSelect], result);
 NVRAM0[(16 + 0) + adcSelect] = adcTempDat[adcSelect].out;
 if(adcSelect < (64 - 1)){
 adcSelect ++;
 }
 else{
 adcSelect = 0;
 }
 switch(adcSelect){
 case 0:{ 
 
 AMX0SL = 0x00;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 ADCMUX_0_3_S1 = false;
 ADCMUX_0_3_S0 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_0_3_OE1 = false;
 ADCMUX_0_3_OE2 = true;
 break;
 }
 case 1:{ 
 
 AMX0SL = 0x00;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 ADCMUX_0_3_S1 = true;
 ADCMUX_0_3_S0 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_0_3_OE1 = false;
 ADCMUX_0_3_OE2 = true;
 break;
 }
 case 2:{ 
 
 AMX0SL = 0x00;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 ADCMUX_0_3_S1 = false;
 ADCMUX_0_3_S0 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = false;
 break;
 }
 case 3:{ 
 
 AMX0SL = 0x00;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 ADCMUX_0_3_S1 = true;
 ADCMUX_0_3_S0 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = false;
 break;
 }
 case 4:{ 
 
 AMX0SL = 0x01;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 ADCMUX_4_7_S1 = false;
 ADCMUX_4_7_S0 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUC_4_7_OE1 = false;
 ADCMUC_4_7_OE2 = true;
 break;
 }
 case 5:{ 
 
 AMX0SL = 0x01;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 ADCMUX_0_3_S1 = true;
 ADCMUX_0_3_S0 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUC_4_7_OE1 = false;
 ADCMUC_4_7_OE2 = true;
 break;
 }
 case 6:{ 
 
 AMX0SL = 0x01;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 ADCMUX_4_7_S1 = true;
 ADCMUX_4_7_S0 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = false;
 break;
 }
 case 7:{ 
 
 AMX0SL = 0x01;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 ADCMUX_4_7_S1 = true;
 ADCMUX_4_7_S0 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = false;
 break;
 }
 case 8:{ 
 
 AMX0SL = 0x02;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 ADCMUX_8_11_S1 = false;
 ADCMUX_8_11_S0 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_8_11_OE1 = false;
 ADCMUX_8_11_OE2 = true;
 break;
 }
 case 9:{ 
 
 AMX0SL = 0x02;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 ADCMUX_8_11_S1 = true;
 ADCMUX_8_11_S0 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_8_11_OE1 = false;
 ADCMUX_8_11_OE2 = true;
 break;
 }
 case 10:{ 
 
 AMX0SL = 0x02;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 ADCMUX_8_11_S1 = false;
 ADCMUX_8_11_S0 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = false;
 break;
 }
 case 11:{ 
 
 AMX0SL = 0x02;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 ADCMUX_8_11_S1 = true;
 ADCMUX_8_11_S0 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = false;
 break;
 }
 case 12:{ 
 
 AMX0SL = 0x03;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 ADCMUX_12_15_S1 = false;
 ADCMUX_12_15_S0 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_12_15_OE1 = false;
 ADCMUX_12_15_OE2 = true;
 break;
 }
 case 13:{ 
 
 AMX0SL = 0x03;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 ADCMUX_12_15_S1 = true;
 ADCMUX_12_15_S0 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_12_15_OE1 = false;
 ADCMUX_12_15_OE2 = true;
 break;
 }
 case 14:{ 
 
 AMX0SL = 0x03;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 ADCMUX_12_15_S1 = false;
 ADCMUX_12_15_S0 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = false;
 break;
 }
 case 15:{ 
 
 AMX0SL = 0x03;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 ADCMUX_12_15_S1 = true;
 ADCMUX_12_15_S0 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = false;
 break;
 }
 case 16:{ 
 
 AMX0SL = 0x04;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 ADCMUX_16_19_S1 = false;
 ADCMUX_16_19_S0 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_16_19_OE1 = false;
 ADCMUX_16_19_OE2 = true;
 break;
 }
 case 17:{ 
 
 AMX0SL = 0x04;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 ADCMUX_16_19_S1 = true;
 ADCMUX_16_19_S0 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_16_19_OE1 = false;
 ADCMUX_16_19_OE2 = true;
 break;
 }
 case 18:{ 
 
 AMX0SL = 0x04;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 ADCMUX_16_19_S1 = false;
 ADCMUX_16_19_S0 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = false;
 break;
 }
 case 19:{ 
 
 AMX0SL = 0x04;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 ADCMUX_16_19_S1 = true;
 ADCMUX_16_19_S0 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = false;
 break;
 }
 case 20:{ 
 
 AMX0SL = 0x04;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 ADCMUX_20_23_S1 = false;
 ADCMUX_20_23_S0 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_20_23_OE1 = false;
 ADCMUX_20_23_OE2 = true;
 break;
 }
 case 21:{ 
 
 AMX0SL = 0x05;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = false;
 ADCMUX_20_23_OE2 = true;
 ADCMUX_20_23_S1 = true;
 ADCMUX_20_23_S0 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 ADCMUX_24_27_S1 = false;
 ADCMUX_24_27_S0 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_24_27_OE1 = false;
 ADCMUX_24_27_OE2 = true;
 break;
 }
 case 22:{ 
 
 AMX0SL = 0x05;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 ADCMUX_20_23_S1 = false;
 ADCMUX_20_23_S0 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;	
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = false;
 break;
 }
 case 23:{ 
 
 AMX0SL = 0x05;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 ADCMUX_20_23_S1 = true;
 ADCMUX_20_23_S0 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = false;
 break;
 }
 case 24:{ 
 
 AMX0SL = 0x06;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 ADCMUX_24_27_S1 = false;
 ADCMUX_24_27_S0 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_24_27_OE1 = false;
 ADCMUX_24_27_OE2 = true;
 break;
 }
 case 25:{ 
 
 AMX0SL = 0x06;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 ADCMUX_24_27_S1 = true;
 ADCMUX_24_27_S0 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_24_27_OE1 = false;
 ADCMUX_24_27_OE2 = true;
 break;
 }
 case 26:{ 
 
 AMX0SL = 0x06;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 ADCMUX_24_27_S1 = false;
 ADCMUX_24_27_S0 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = false;
 break;
 }
 case 27:{ 
 
 AMX0SL = 0x06;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 ADCMUX_24_27_S1 = true;
 ADCMUX_24_27_S0 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = false;
 break;
 }
 case 32:{ 
 
 AMX0SL = 0x00;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 ADCMUX_0_3_S1 = false;
 ADCMUX_0_3_S0 = false;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_0_3_OE1 = false;
 ADCMUX_0_3_OE2 = true;
 break;
 }
 case 33:{ 
 
 AMX0SL = 0x00;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 ADCMUX_0_3_S1 = true;
 ADCMUX_0_3_S0 = false;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_0_3_OE1 = false;
 ADCMUX_0_3_OE2 = true;
 break;
 }
 case 34:{ 
 
 AMX0SL = 0x00;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 ADCMUX_0_3_S1 = false;
 ADCMUX_0_3_S0 = false;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = false;
 break;
 }
 case 35:{ 
 
 AMX0SL = 0x00;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 ADCMUX_0_3_S1 = true;
 ADCMUX_0_3_S0 = false;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = false;
 break;
 }
 case 36:{ 
 
 AMX0SL = 0x01;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 ADCMUX_4_7_S1 = false;
 ADCMUX_4_7_S0 = false;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUC_4_7_OE1 = false;
 ADCMUC_4_7_OE2 = true;
 break;
 }
 case 37:{ 
 
 AMX0SL = 0x01;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 ADCMUX_4_7_S1 = true;
 ADCMUX_4_7_S0 = false;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUC_4_7_OE1 = false;
 ADCMUC_4_7_OE2 = true;
 break;
 }
 case 38:{ 
 
 AMX0SL = 0x01;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 ADCMUX_4_7_S1 = false;
 ADCMUX_4_7_S0 = false;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = false;
 break;
 }
 case 39:{ 
 
 AMX0SL = 0x01;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 ADCMUX_4_7_S1 = true;
 ADCMUX_4_7_S0 = false;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = false;
 break;
 }
 case 40:{ 
 
 AMX0SL = 0x02;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 ADCMUX_8_11_S1 = false;
 ADCMUX_8_11_S0 = false;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_8_11_OE1 = false;
 ADCMUX_8_11_OE2 = true;
 break;
 }
 case 41:{ 
 
 AMX0SL = 0x02;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 ADCMUX_8_11_S1 = true;
 ADCMUX_8_11_S0 = false;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_8_11_OE1 = false;
 ADCMUX_8_11_OE2 = true;
 break;
 }
 case 42:{ 
 
 AMX0SL = 0x02;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 ADCMUX_8_11_S1 = false;
 ADCMUX_8_11_S0 = false;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_8_11_OE1 = false;
 ADCMUX_8_11_OE2 = true;
 break;
 }
 case 43:{ 
 
 AMX0SL = 0x02;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 ADCMUX_8_11_S1 = true;
 ADCMUX_8_11_S0 = false;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = false;
 break;
 }
 case 44:{ 
 
 AMX0SL = 0x03;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 ADCMUX_12_15_S1 = false;
 ADCMUX_12_15_S0 = false;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_12_15_OE1 = false;
 ADCMUX_12_15_OE2 = true;
 break;
 }
 case 45:{ 
 
 AMX0SL = 0x03;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 ADCMUX_12_15_S1 = true;
 ADCMUX_12_15_S0 = false;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_12_15_OE1 = false;
 ADCMUX_12_15_OE2 = true;
 break;
 }
 case 46:{ 
 
 AMX0SL = 0x03;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 ADCMUX_12_15_S1 = false;
 ADCMUX_12_15_S0 = false;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = false;
 break;
 }
 case 47:{ 
 
 AMX0SL = 0x03;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 ADCMUX_12_15_S1 = true;
 ADCMUX_12_15_S0 = false;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = false;
 break;
 }
 case 48:{ 
 
 AMX0SL = 0x04;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 ADCMUX_16_19_S1 = false;
 ADCMUX_16_19_S0 = false;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_16_19_OE1 = false;
 ADCMUX_16_19_OE2 = true;
 break;
 }
 case 49:{ 
 
 AMX0SL = 0x04;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 ADCMUX_16_19_S1 = true;
 ADCMUX_16_19_S0 = false;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_16_19_OE1 = false;
 ADCMUX_16_19_OE2 = true;
 break;
 }
 case 50:{ 
 
 AMX0SL = 0x04;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 ADCMUX_16_19_S1 = true;
 ADCMUX_16_19_S0 = false;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = false;
 break;
 }
 case 51:{ 
 
 AMX0SL = 0x04;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 ADCMUX_16_19_S1 = true;
 ADCMUX_16_19_S0 = false;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = false;
 break;
 }
 case 52:{ 
 
 AMX0SL = 0x05;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 ADCMUX_20_23_S1 = false;
 ADCMUX_20_23_S0 = false;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_20_23_OE1 = false;
 ADCMUX_20_23_OE2 = true;
 break;
 }
 case 53:{ 
 
 AMX0SL = 0x05;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 ADCMUX_20_23_S1 = true;
 ADCMUX_20_23_S0 = false;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_20_23_OE1 = false;
 ADCMUX_20_23_OE2 = true;
 break;
 }
 case 54:{ 
 
 AMX0SL = 0x05;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 ADCMUX_20_23_S1 = false;
 ADCMUX_20_23_S0 = false;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = false;
 break;
 }
 case 55:{ 
 
 AMX0SL = 0x06;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 ADCMUX_20_23_S1 = true;
 ADCMUX_20_23_S0 = false;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = false;
 break;
 }
 case 56:{ 
 
 AMX0SL = 0x06;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 ADCMUX_24_27_S1 = false;
 ADCMUX_24_27_S0 = false;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_24_27_OE1 = false;
 ADCMUX_24_27_OE2 = true;	
 break;
 }
 case 57:{ 
 
 AMX0SL = 0x06;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 ADCMUX_20_23_S1 = true;
 ADCMUX_20_23_S0 = false;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_24_27_OE1 = false;
 ADCMUX_24_27_OE2 = true;	
 break;
 }
 case 58:{ 
 
 AMX0SL = 0x06;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 ADCMUX_24_27_S1 = false;
 ADCMUX_24_27_S0 = false;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = false;
 break;
 }
 case 59:{ 
 
 AMX0SL = 0x06;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 ADCMUX_24_27_S1 = true;
 ADCMUX_24_27_S0 = false;
 _nop_();_nop_();_nop_();_nop_();_nop_();
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = false;
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
 for(i = 0;i < 14; i++){
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
 if(s->wIndex >= 14){
 s->wIndex = 0;
 }
 
 sum = 0;
 for(i = 0;i < 14;i ++){
 sum += s->dat[i];
 }
 
 
 temp = (uint16_t)(sum / (uint32_t)14);
 s->out = temp;
 }
 static void assertCoilAddress(uint16_t adr){ 
 if(adr > (201 * 16))
 while(1);
 }
 static void assertRegisterAddress(uint16_t adr){ 
 if(adr >= 201)
 while(1);
 }
 static void clearDM(void){ 
 uint16_t i;
 for(i = 0;i <= 15;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 static void clearMR(void){ 
 uint16_t i;
 for(i = 0;i <= 3;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 static void clearEM(void){ 
 uint16_t i;
 for(i = 16;i <= 143;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 static void clearR(void){ 
 uint16_t i;
 for(i = 4;i <= 7;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 static void clearT(void){ 
 uint16_t i;
 for(i = 144;i <= 144;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 for(i = 145;i <= 145;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 for(i = 146;i <= 146;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 static void clearTD(void){ 
 uint16_t i;
 for(i = 147;i <= 162;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 for(i = 163;i <= 178;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 for(i = 179;i <= 194;i ++)
 {
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 static void clearC(void){ 
 uint16_t i;
 for(i = 195;i <= 195;i ++){
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 static void clearX(void){ 
 uint16_t i;
 for(i = 196;i <= 196;i ++){
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 static void clearY(void){ 
 uint16_t i;
 for(i = 197;i <= 197;i ++){
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 static void clearSPREG(void){
 uint16_t i;
 for(i = 198;i <= 201;i ++){
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 static void clearSPCOIL(){
 uint16_t i;
 for(i = 202;i <= 205;i ++){
 NVRAM0[i] = 0x0;
 NVRAM1[i] = 0x0;
 }
 }
 static void nvramLoad(void){ 
 memset(NVRAM0, 0x0, ((205 + 1) * 2)); 
 epromRead(0, (uint8_t*)NVRAM0, ((205 + 1) * 2)); 
 clearEM();
 clearR();
 clearT();
 clearTD();
 clearC();
 clearX();
 clearY();
 clearSPREG();
 clearSPCOIL();
 memcpy(NVRAM1, NVRAM0, (205 + 1));
 }
 static void nvramSave(void){ 
  EA = 0;;
 epromWrite(0x0, (uint8_t*)NVRAM0, ((3 + 1) * 2));
  EA = 1;;
 }
 static void nvramUpdata(void){ 
 uint8_t *sp0, *sp1;
 uint16_t i;
 sp0 = (uint8_t*)(NVRAM0 + (0 * 2));
 sp1 = (uint8_t*)(NVRAM1 + (0 * 2));
 for(i = 0;i < ((3 + 1) * 2);i ++){ 
 if(*(sp0 + i) != *(sp1 + i)){
 epromWriteOneByte(i, *(sp0 + i));
 }
 }
 sp0 = (uint8_t*)(NVRAM0 + (8 * 2));
 sp1 = (uint8_t*)(NVRAM1 + (8 * 2));
 for(i = 8;i < ((15 + 1) * 2);i ++){ 
 if(*(sp0 + i) != *(sp1 + i)){
 epromWriteOneByte(i, *(sp0 + i));
 }
 }
 memcpy(NVRAM1, NVRAM0, ((205 + 1) * 2));
 }
 
 
 void SET(uint16_t A){ 
 assertCoilAddress(A); 
 NVRAM0[(A / 16)] |= 1 << (A % 16);
 }
 void RESET(uint16_t A){ 
 assertCoilAddress(A); 
 NVRAM0[(A / 16)] &= ~(1 << (A % 16));
 }
 void FLIP(uint16_t A){ 
 uint16_t temp;
 assertCoilAddress(A); 
 temp= NVRAM0[(A / 16)] & (1 << (A % 16));
 if(temp)
 RESET(A);
 else
 SET(A);
 }
 uint8_t LD(uint16_t A){ 
 assertCoilAddress(A); 
 return (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
 }
 uint8_t LDP(uint16_t A){ 
 uint8_t temp0, temp1;
 assertCoilAddress(A); 
 temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
 temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
 if(temp0 && !temp1)
 return 1;
 else
 return 0;
 }
 uint8_t LDN(uint16_t A){ 
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
 
#line 2082 "MainApp\sPlc.c" /1
 
 
 
#line 2085 "MainApp\sPlc.c" /0
 if(start){
 if(NVRAM0[(147 + A)] >= value){
 NVRAM0[(144 + (A / 16))] |= 1 << (A % 16);
 }
 else{
 NVRAM0[(144 + (A / 16))] &= ~(1 << (A % 16));
 }
 
 }
 else{
 NVRAM0[(144 + (A / 16))] &= ~(1 << (A % 16));
 NVRAM0[(147 + A)] = 0x0;
 }	
 }
 void T10MS(uint8_t A, uint8_t start, uint16_t value){ 
 
#line 2101 "MainApp\sPlc.c" /1
 
 
 
#line 2104 "MainApp\sPlc.c" /0
 if(start){
 if(NVRAM0[(163 + A)] >= value){
 NVRAM0[(145 + (A / 16))] |= 1 << (A % 16);
 }
 else{
 NVRAM0[(145 + (A / 16))] &= ~(1 << (A % 16));
 }
 }
 else{
 NVRAM0[(145 + (A / 16))] &= ~(1 << (A % 16));
 NVRAM0[(163 + A)] = 0x0;
 }	
 }
 void T100MS(uint8_t A, uint8_t start, uint16_t value){ 
 
#line 2119 "MainApp\sPlc.c" /1
 
 
 
#line 2122 "MainApp\sPlc.c" /0
 if(start){
 if(NVRAM0[(179 + A)] >= value){
 NVRAM0[(146 + (A / 16))] |= 1 << (A % 16);
 }
 else{
 NVRAM0[(146 + (A / 16))] &= ~(1 << (A % 16));
 }	
 }
 else{
 NVRAM0[(146 + (A / 16))] &= ~(1 << (A % 16));
 NVRAM0[(179 + A)] = 0x0;
 }
 }
 int16_t TNTC(int16_t dat){ 
 uint16_t temp;
 fp32_t ftemp;
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
 int16_t TENV(int16_t dat){ 
 uint16_t temp;
 temp = (int16_t)(2200L * dat / 4096); 
 temp = (int16_t)((temp - 856L) * 1000 / 3330L);
 return temp;
 }
 int16_t MAX(int16_t *s, uint8_t len){ 
 int16_t max;
 uint8_t i;
 max = *s;
 for(i = 0;i < len;i ++){
 if(*(s +i) > max){
 max = *(s + i);
 }
 }
 return max;
 }
 int16_t MIN(int16_t *s, uint8_t len){ 
 int16_t min;
 uint8_t i;
 min = *s;
 for(i = 0;i < len;i ++){
 if(*(s +i) < min){
 min = *(s + i);
 }
 }
 return min;
 }
 
 static void wdtInit(void){ 
 
 WDTCN = 0; 
 
 }
 static void wdtEnable(void){ 
 
 WDTCN = 0xA5;
 
 }
 static void wdtDisable(void){ 
 uint8_t flagEA;
 flagEA = EA;
 EA = 0;
 
 WDTCN = 0xDE;
 WDTCN = 0xAD;
 
 
 
 EA = flagEA;
 }
 static void wdtFeed(void){ 
 
 WDTCN = 0xA5;
 
 }
 
 static void pcaInit(void){ 
 }
 static void timer0Init(void){ 
 data uint16_t temp;
 TimerCounter_1mS = 0;
 TimerCounter_10mS = 0;
 
 temp = (uint16_t)(65536 - ((22118400L) / 12 /1000L));
 Timer0_L = temp & 0xFF;
 Timer0_H = (temp >> 8) & 0xFF;
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
 if((NVRAM0[(202 + (1 / 16))] >> (1 % 16)) & 0x01){ 
 NVRAM0[(202 + (1 / 16))] &= ~(uint16_t)(1 << (1 % 16));
 }
 else{ 
 NVRAM0[(202 + (1 / 16))] |= (uint16_t)(1 << (1 % 16));
 }
 
 for(i = 147;i <= 162;i ++){ 
 if(NVRAM0[i] < 32767){
 NVRAM0[i] ++;
 }
 }
 if(TimerCounter_1mS >= 10){ 
 if((NVRAM0[(202 + (2 / 16))] >> (2 % 16)) & 0x01){ 
 NVRAM0[(202 + (2 / 16))] &= ~(uint16_t)(1 << (2 % 16));
 }
 else{ 
 NVRAM0[(202 + (2 / 16))] |= (uint16_t)(1 << (2 % 16));
 }
 for(i = 163;i <= 178;i ++){
 if(NVRAM0[i] < 32767){
 NVRAM0[i] ++;
 }
 }
 TimerCounter_10mS ++;
 TimerCounter_1mS = 0;
 }
 if(TimerCounter_10mS >= 10){ 
 if((NVRAM0[(202 + (3 / 16))] >> (3 % 16)) & 0x01){ 
 NVRAM0[(202 + (3 / 16))] &= ~(uint16_t)(1 << (3 % 16));
 }
 else{ 
 NVRAM0[(202 + (3 / 16))] |= (uint16_t)(1 << (3 % 16));
 }
 for(i = 179;i < 194;i ++){
 if(NVRAM0[i] < 32767){
 NVRAM0[i] ++;
 }
 }
 TimerCounter_10mS = 0;
 if(getLedRun()){
 setLedRun(false);
 }
 else{
 setLedRun(true);
 }
 }
 
 adcProcess(); 
 
 TimerCounter_1mS ++;
 }
 
 static void inputInit(void){ 
 memset(inputFilter, 0x0, (196 - 196 + 1) * 16);
 }
 static void outputInit(void){
 
 
 
 }
 static void inputRefresh(void){ 
 uint8_t ctemp0;
 ctemp0 = ((P6 >> 7) & 0x01);
 if(ctemp0){
 if(inputFilter[0] < 3){
 inputFilter[0] ++;
 }
 else{
 NVRAM0[196] |= (int16_t)(1 << 0);
 }
 }
 else{
 if(inputFilter[0] > (3 * -1)){
 inputFilter[0] --;
 }
 else{
 NVRAM0[196] &= ~(uint16_t)(1 << 0);
 }
 }
 ctemp0 = ((P6 >> 6) & 0x01);
 if(ctemp0){
 if(inputFilter[1] < 3){
 inputFilter[1] ++;
 }
 else{
 NVRAM0[196] |= (int16_t)(1 << 1);
 }
 }
 else{
 if(inputFilter[1] > (3 * -1)){
 inputFilter[1] --;
 }
 else{
 NVRAM0[196] &= ~(uint16_t)(1 << 1);
 }
 }
 }
 static void outputRefresh(void){ 
 if((NVRAM0[197] >> 0) & 0x01){ 
 P6 |= (uint8_t)(1 << 5);
 }
 else{
 P6 &= ~(uint8_t)(1 << 5);
 }
 if((NVRAM0[197] >> 1) & 0x01){ 
 P6 |= (uint8_t)(1 << 4);
 }
 else{
 P6 &= ~(uint8_t)(1 << 4);
 }
 }
 static void chipAdcInit(void){ 
 uint8_t i;
 
 ADCMUX_0_3_OE1 = true;
 ADCMUX_0_3_OE2 = true;
 
 ADCMUC_4_7_OE1 = true;
 ADCMUC_4_7_OE2 = true;
 
 ADCMUX_8_11_OE1 = true;
 ADCMUX_8_11_OE2 = true;
 
 ADCMUX_12_15_OE1 = true;
 ADCMUX_12_15_OE2 = true;
 
 ADCMUX_16_19_OE1 = true;
 ADCMUX_16_19_OE2 = true;
 
 ADCMUX_20_23_OE1 = true;
 ADCMUX_20_23_OE2 = true;
 
 ADCMUX_24_27_OE1 = true;
 ADCMUX_24_27_OE2 = true;
 
 ADC0CN = 0x0; 
 ADC0CN |= (1 << 6); 
 ADC0CN |= (1 << 7); 
 ADC0CF = 0x0;
 ADC0CF |= ((22118400L) / 2000000L) << 3;      
 AMX0CF = 0x00;                       
 AMX0SL = 0x00;                       
 AD0INT = 0;
 AD0BUSY = 1; 
 
 adcSelect = 0;
 for(i = 0;i <= 64;i ++){
 initAdcData(&adcTempDat[i]);
 }
 }
 static void refreshDac(void){ 
 
 if(NVRAM0[(16 + 64)] != NVRAM1[(16 + 64)]){ 
 setLedDac(true);
 dac8568_0_WriteDacRegister(0x7, (uint16_t)NVRAM0[(16 + 64)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 65)] != NVRAM1[(16 + 65)]){ 
 setLedDac(true);
 dac8568_0_WriteDacRegister(0x5, (uint16_t)NVRAM0[(16 + 65)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 66)] != NVRAM1[(16 + 66)]){ 
 setLedDac(true);
 dac8568_0_WriteDacRegister(0x3, (uint16_t)NVRAM0[(16 + 66)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 67)] != NVRAM1[(16 + 67)]){ 
 setLedDac(true);
 dac8568_0_WriteDacRegister(0x1, (uint16_t)NVRAM0[(16 + 67)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 68)] != NVRAM1[(16 + 68)]){ 
 setLedDac(true);
 dac8568_0_WriteDacRegister(0x6, (uint16_t)NVRAM0[(16 + 68)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 69)] != NVRAM1[(16 + 69)]){ 
 setLedDac(true);
 dac8568_0_WriteDacRegister(0x4, (uint16_t)NVRAM0[(16 + 69)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 70)] != NVRAM1[(16 + 70)]){ 
 setLedDac(true);
 dac8568_0_WriteDacRegister(0x4, (uint16_t)NVRAM0[(16 + 70)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 71)] != NVRAM1[(16 + 71)]){ 
 setLedDac(true);
 dac8568_0_WriteDacRegister(0x0, (uint16_t)NVRAM0[(16 + 71)]);
 setLedDac(false);
 }
 
 if(NVRAM0[(16 + 72)] != NVRAM1[(16 + 72)]){ 
 setLedDac(true);
 dac8568_1_WriteDacRegister(0x7, (uint16_t)NVRAM0[(16 + 72)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 73)] != NVRAM1[(16 + 73)]){ 
 setLedDac(true);
 dac8568_1_WriteDacRegister(0x5, (uint16_t)NVRAM0[(16 + 73)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 74)] != NVRAM1[(16 + 74)]){ 
 setLedDac(true);
 dac8568_1_WriteDacRegister(0x3, (uint16_t)NVRAM0[(16 + 74)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 75)] != NVRAM1[(16 + 75)]){ 
 setLedDac(true);
 dac8568_1_WriteDacRegister(0x1, (uint16_t)NVRAM0[(16 + 75)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 76)] != NVRAM1[(16 + 76)]){ 
 setLedDac(true);
 dac8568_1_WriteDacRegister(0x6, (uint16_t)NVRAM0[(16 + 76)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 77)] != NVRAM1[(16 + 77)]){ 
 setLedDac(true);
 dac8568_1_WriteDacRegister(0x4, (uint16_t)NVRAM0[(16 + 77)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 78)] != NVRAM1[(16 + 78)]){ 
 setLedDac(true);
 dac8568_1_WriteDacRegister(0x2, (uint16_t)NVRAM0[(16 + 78)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 79)] != NVRAM1[(16 + 79)]){ 
 setLedDac(true);
 dac8568_1_WriteDacRegister(0x0, (uint16_t)NVRAM0[(16 + 79)]);
 setLedDac(false);
 }
 
 if(NVRAM0[(16 + 80)] != NVRAM1[(16 + 80)]){ 
 setLedDac(true);
 dac8568_2_WriteDacRegister(0x7, (uint16_t)NVRAM0[(16 + 80)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 81)] != NVRAM1[(16 + 81)]){ 
 setLedDac(true);
 dac8568_2_WriteDacRegister(0x5, (uint16_t)NVRAM0[(16 + 81)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 82)] != NVRAM1[(16 + 82)]){ 
 setLedDac(true);
 dac8568_2_WriteDacRegister(0x3, (uint16_t)NVRAM0[(16 + 82)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 83)] != NVRAM1[(16 + 83)]){ 
 setLedDac(true);
 dac8568_2_WriteDacRegister(0x1, (uint16_t)NVRAM0[(16 + 83)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 84)] != NVRAM1[(16 + 84)]){ 
 setLedDac(true);
 dac8568_2_WriteDacRegister(0x6, (uint16_t)NVRAM0[(16 + 84)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 85)] != NVRAM1[(16 + 85)]){ 
 setLedDac(true);
 dac8568_2_WriteDacRegister(0x4, (uint16_t)NVRAM0[(16 + 85)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 86)] != NVRAM1[(16 + 86)]){ 
 setLedDac(true);
 dac8568_2_WriteDacRegister(0x2, (uint16_t)NVRAM0[(16 + 86)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 87)] != NVRAM1[(16 + 87)]){ 
 setLedDac(true);
 dac8568_2_WriteDacRegister(0x0, (uint16_t)NVRAM0[(16 + 87)]);
 setLedDac(false);
 }
 
 if(NVRAM0[(16 + 88)] != NVRAM1[(16 + 88)]){ 
 setLedDac(true);
 dac8568_3_WriteDacRegister(0x7, (uint16_t)NVRAM0[(16 + 88)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 89)] != NVRAM1[(16 + 89)]){ 
 setLedDac(true);
 dac8568_3_WriteDacRegister(0x5, (uint16_t)NVRAM0[(16 + 90)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 90)] != NVRAM1[(16 + 90)]){ 
 setLedDac(true);
 dac8568_3_WriteDacRegister(0x3, (uint16_t)NVRAM0[(16 + 90)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 91)] != NVRAM1[(16 + 91)]){ 
 setLedDac(true);
 dac8568_3_WriteDacRegister(0x1, (uint16_t)NVRAM0[(16 + 91)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 92)] != NVRAM1[(16 + 92)]){ 
 setLedDac(true);
 dac8568_3_WriteDacRegister(0x6, (uint16_t)NVRAM0[(16 + 92)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 93)] != NVRAM1[(16 + 93)]){ 
 setLedDac(true);
 dac8568_3_WriteDacRegister(0x4, (uint16_t)NVRAM0[(16 + 93)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 94)] != NVRAM1[(16 + 94)]){ 
 setLedDac(true);
 dac8568_3_WriteDacRegister(0x2, (uint16_t)NVRAM0[(16 + 94)]);
 setLedDac(false);
 }
 if(NVRAM0[(16 + 95)] != NVRAM1[(16 + 95)]){ 
 setLedDac(true);
 dac8568_3_WriteDacRegister(0x0, (uint16_t)NVRAM0[(16 + 95)]);
 setLedDac(false);
 }
 }
 static void chipDacInit(void){ 
 dac8568_0_Init();
 dac8568_1_Init();
 dac8568_2_Init();
 dac8568_3_Init();
 }
 void sPlcInit(void){ 
 setLedError(true);
 setLedRun(false);
 wdtInit(); 
 wdtDisable(); 
 
 nvramLoad(); 
 
 
 
 chipAdcInit(); 
 
 
 
 chipDacInit(); 
 
 
 
 initModbus(0x01, 57600);
 
 timer0Init(); 
 NVRAM0[(202 + (0 / 16))] |= (uint16_t)(1 << (0 % 16));
 setLedError(false);
 }
 void sPlcProcessStart(void){ 
 
 modbusPorcess(); 
 
 
 inputRefresh(); 
 
 
#line 2588 "MainApp\sPlc.c" /1
 
 
#line 2590 "MainApp\sPlc.c" /0
 }
 void sPlcProcessEnd(void){ 
 
#line 2593 "MainApp\sPlc.c" /1
 
 
#line 2595 "MainApp\sPlc.c" /0
 
 outputRefresh(); 
 
 
 refreshDac(); 
 
 
 nvramUpdata(); 
 
 }
