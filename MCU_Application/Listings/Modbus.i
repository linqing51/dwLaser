
#line 1 "Modbus\Modbus.c" /0
  
#line 1 "Modbus\modbus.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
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
 
 
#line 84 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\stdbool.h" /0




 
 
 
 
 
 
 
 typedef bit bool;
 enum{
 false = 0,
 true = 1,
 };
 
 
#line 19 ".\Lib\stdbool.h" /1
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
#line 43 ".\Lib\stdbool.h" /0
 
 
 
#line 85 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\endian.h" /0




 
 
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 31 ".\Lib\endian.h" /1
 
  
  
  
  
 
  
  
  
  
 
 
 
  
  
  
  
 
  
  
  
  
 
 
#line 55 ".\Lib\endian.h" /0
 
 
#line 86 ".\MainApp\appConfig.h" /0
 
  
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
 
 
 
 
#line 87 ".\MainApp\appConfig.h" /0
 
  
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
 
 
 
 
 
 
 
 
 
 
#line 88 ".\MainApp\appConfig.h" /0
 
  
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
 
 
 
 
 
 
 
 
 
 
#line 89 ".\MainApp\appConfig.h" /0
 
 
  
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
 
 
 
#line 91 ".\MainApp\appConfig.h" /0
 
  
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
 
 
#line 92 ".\MainApp\appConfig.h" /0
 
  
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
 
 
#line 93 ".\MainApp\appConfig.h" /0
 
  
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
 
 
 
#line 94 ".\MainApp\appConfig.h" /0
 
  
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
 
 
#line 95 ".\MainApp\appConfig.h" /0
 
  
#line 1 "C:\Keil_v5\C51\Inc\LIMITS.H" /0







 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 96 ".\MainApp\appConfig.h" /0
 
  
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
 
 
#line 97 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\crc32.h" /0
 
 
 
 
 
 
 
  
#line 1 ".\MainApp\AppConfig.h" /0
 
#line 2 ".\MainApp\AppConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 8 ".\Lib\crc32.h" /0
#line 8 ".\Lib\crc32.h" /0
 
 
 uint32_t crc32Calculate(uint8_t *buf, uint32_t len); 
 uint32_t crc32CalculateAdd(uint8_t dat); 
 void crc32Clear(void); 
 void crc32SetCrcOld(uint32_t old);
 
 
 
 
 
 
 
 
#line 98 ".\MainApp\appConfig.h" /0
 
 
  
#line 1 "\GitHub\dwLaser\MCU_Application\MainApp\InitDeviceF020.h" /0
 
 
 
  
#line 1 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 123 ".\Lib\compiler_defs.h" /1
  
 
  
  
 
 
 
 
 
 
  
 
 
  
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
 
  
 
  
 
  
  
  
 
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
 
  
  
 
 
 
 
  
  
  
 
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
#line 804 ".\Lib\compiler_defs.h" /0
 
 
 
 
#line 4 "\GitHub\dwLaser\MCU_Application\MainApp\InitDeviceF020.h" /0
 
  
#line 1 ".\Lib\C8051F020_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 30 ".\Lib\C8051F020_defs.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 347 ".\Lib\C8051F020_defs.h" /0
 
 
 
 
#line 5 "\GitHub\dwLaser\MCU_Application\MainApp\InitDeviceF020.h" /0
 
 
 void initDeviceF020(void);
 
#line 100 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Lib\delay.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 4 ".\Lib\delay.h" /0
#line 4 ".\Lib\delay.h" /0
 
 
 void delayMs(uint8_t ms) reentrant;
 void delayUs(uint8_t us) reentrant;
 void hwDelayInit(uint8_t reload_h, uint8_t reload_l);
 void hwDelay(uint8_t control, uint8_t reload_h, uint8_t reload_l);
 
 
 
#line 101 ".\MainApp\appConfig.h" /0
 
  
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
 
 
 
 
#line 102 ".\MainApp\appConfig.h" /0
 
  
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
 
#line 103 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\dac8568_0.h" /0
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 1 ".\Driver\dac8568_0.h" /0
#line 1 ".\Driver\dac8568_0.h" /0
 
 
 void dac8568_0_Init(void);
 void dac8568_0_Update(uint8_t ch);
 void dac8568_0_WriteInputRegister(uint8_t ch, uint16_t dat);
 void dac8568_0_WriteDacRegister(uint8_t ch, uint16_t dat);
 void dac8568_0_Clear(void);
 void dac8568_0_Reset(void);
#line 104 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\dac8568_1.h" /0
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 1 ".\Driver\dac8568_1.h" /0
#line 1 ".\Driver\dac8568_1.h" /0
 
 
 void dac8568_1_Init(void);
 void dac8568_1_Update(uint8_t ch);
 void dac8568_1_WriteInputRegister(uint8_t ch, uint16_t dat);
 void dac8568_1_WriteDacRegister(uint8_t ch, uint16_t dat);
 void dac8568_1_Clear(void);
 void dac8568_1_Reset(void);
#line 105 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\dac8568_2.h" /0
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 1 ".\Driver\dac8568_2.h" /0
#line 1 ".\Driver\dac8568_2.h" /0
 
 
 void dac8568_2_Init(void);
 void dac8568_2_Update(uint8_t ch);
 void dac8568_2_WriteInputRegister(uint8_t ch, uint16_t dat);
 void dac8568_2_WriteDacRegister(uint8_t ch, uint16_t dat);
 void dac8568_2_Clear(void);
 void dac8568_2_Reset(void);
#line 106 ".\MainApp\appConfig.h" /0
 
  
#line 1 ".\Driver\dac8568_3.h" /0
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 1 ".\Driver\dac8568_3.h" /0
#line 1 ".\Driver\dac8568_3.h" /0
 
 
 void dac8568_3_Init(void);
 void dac8568_3_Update(uint8_t ch);
 void dac8568_3_WriteInputRegister(uint8_t ch, uint16_t dat);
 void dac8568_3_WriteDacRegister(uint8_t ch, uint16_t dat);
 void dac8568_3_Clear(void);
 void dac8568_3_Reset(void);
#line 107 ".\MainApp\appConfig.h" /0
 
  
#line 1 "\GitHub\dwLaser\MCU_Application\MainApp\boxCmd.h" /0
 
 
 
  
#line 1 "\GitHub\dwLaser\MCU_Application\MainApp\appConfig.h" /0
 
#line 2 "\GitHub\dwLaser\MCU_Application\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 4 "\GitHub\dwLaser\MCU_Application\MainApp\boxCmd.h" /0
#line 4 "\GitHub\dwLaser\MCU_Application\MainApp\boxCmd.h" /0
 
 
 void initboxSerial(uint32_t baudrate);
 void boxRedLedRefresh(void);
 void boxGreenLedRefresh(void);
 
#line 108 ".\MainApp\appConfig.h" /0
 
 
  
#line 1 "Modbus\Modbus.h" /0
 
#line 2 "Modbus\Modbus.h" /1
  
 
  
 
 
 
 
 
 
 
 
#line 110 ".\MainApp\appConfig.h" /0
#line 110 ".\MainApp\appConfig.h" /0
 
  
#line 1 "Modbus\ModbusPort.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
#line 2 ".\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 4 "Modbus\ModbusPort.h" /0
#line 4 "Modbus\ModbusPort.h" /0
 
 
 extern void modBusUartInitialise(uint32_t baudrate);
 extern void modBusTimerInitialise(void);
 extern void modBusUartPutch(uint8_t c);
 extern uint8_t modBusUartString(uint8_t *s, uint16_t Length);
 extern void receiveInterrupt(uint8_t Data);
 
 
#line 111 ".\MainApp\appConfig.h" /0
 
 
  
#line 1 "\GitHub\dwLaser\MCU_Application\MainApp\sPLC.h" /0
 
 
 
  
#line 1 "\GitHub\dwLaser\MCU_Application\MainApp\appConfig.h" /0
 
#line 2 "\GitHub\dwLaser\MCU_Application\MainApp\appConfig.h" /1
  
 
  
 
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
  
  
 
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
 
  
 
  
 
  
 
  
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
  
  
  
  
 
  
  
 
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
 
#line 4 "\GitHub\dwLaser\MCU_Application\MainApp\sPLC.h" /0
#line 4 "\GitHub\dwLaser\MCU_Application\MainApp\sPLC.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 
 
#line 113 ".\MainApp\appConfig.h" /0
 
 
 
#line 4 "Modbus\modbus.h" /0
 
 
 extern volatile uint16_t modbusTimerValue;
 extern volatile uint8_t modbusReceiveCounter; 
 extern xdata volatile uint8_t modbusReceiveBuffer[256];
 
 extern void initModbus(uint8_t modbusSlaveAddress, uint32_t bd);
 extern void modbusPorcess(void);
 
#line 1 "Modbus\Modbus.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef enum{
 RXTX_IDLE,
 RXTX_START,
 RXTX_DATABUF,
 RXTX_WAIT_ANSWER,
 RXTX_TIMEOUT
 }MODBUS_RXTX_STATE;
 typedef struct{
 uint8_t address;
 uint8_t function;
 uint8_t dataBuf[256];
 uint16_t dataLen;
 }modbusRxTxData_t;
 
 pdata uint8_t ModbusSlaveAddress = 1;
 xdata modbusRxTxData_t Tx_Data;
 pdata uint32_t Tx_Current = 0;
 pdata uint32_t Tx_CRC16 = 0xFFFF;
 pdata MODBUS_RXTX_STATE Tx_State = RXTX_IDLE;
 xdata uint8_t Tx_Buf[256];
 pdata uint32_t Tx_Buf_Size = 0;
 
 xdata modbusRxTxData_t Rx_Data;
 pdata uint32_t Rx_CRC16 = 0xFFFF;
 pdata MODBUS_RXTX_STATE Rx_State = RXTX_IDLE;
 pdata uint8_t Rx_Data_Available = false;
 
 volatile uint16_t modbusTimerValue = 0;
 volatile uint8_t modbusReceiveCounter = 0; 
 xdata volatile uint8_t modbusReceiveBuffer[256]; 
 
 void modbusCrc16(const uint8_t Data, uint32_t* CRC){
 data uint32_t i;
 *CRC = *CRC ^(uint32_t) Data;
 for (i = 8; i > 0; i--){
 if (*CRC & 0x0001)
 *CRC = (*CRC >> 1) ^ 0xA001;
 else
 *CRC >>= 1;
 }
 }
 
 
 uint8_t DoSlaveTX(void){ 
 modBusUartString(Tx_Buf, Tx_Buf_Size);
 Tx_Buf_Size = 0;
 return true;
 }
 uint8_t SendMessage(void){ 
 if (Tx_State != RXTX_IDLE){
 return false;
 }
 Tx_Current  =0;
 Tx_State    =RXTX_START;
 return true;
 }
 void HandleModbusError(char ErrorCode){ 
 Tx_Data.function = ErrorCode | 0x80;
 Tx_Data.address = ModbusSlaveAddress;
 Tx_Data.dataLen = 0;
 SendMessage();
 }
 
 void HandleModbusReadCoils(void){ 
 uint16_t startAddress, numberOfCoil, byteCount, tempAddr, i, j;
 uint8_t tempData = 0;
 
 startAddress = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t) (Rx_Data.dataBuf[1]);
 numberOfCoil = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t) (Rx_Data.dataBuf[3]);
 if((startAddress + numberOfCoil) > ((205 + 1) * 16)){ 
 HandleModbusError(0x02);
 }
 else{
 byteCount = numberOfCoil / 8;
 if((numberOfCoil % 8) != 0){
 byteCount += 1;
 }
 Tx_Data.function = 1;
 Tx_Data.address = ModbusSlaveAddress;
 Tx_Data.dataLen = 1;
 tempAddr = startAddress;
 for(i = 0; i < byteCount; i ++){
 Tx_Data.dataBuf[Tx_Data.dataLen] = 0;
 for(j = 0; j < 8; j ++){
 tempData = (NVRAM0[(tempAddr / 16)] >> (tempAddr % 16)) & 0x01;
 Tx_Data.dataBuf[Tx_Data.dataLen] |= (uint8_t)(tempData << j);
 tempAddr++;	
 
 
 
 
 }
 Tx_Data.dataLen ++;	
 }
 Tx_Data.dataBuf[0] = Tx_Data.dataLen - 1;
 SendMessage();
 }
 }
 void HandleModbusReadInputCoil(void){ 
 }
 void HandleModbusReadHoldingRegisters(void){ 
 uint16_t startAddress, numberOfRegisters, i, currentData;
 
 startAddress = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t) (Rx_Data.dataBuf[1]);
 numberOfRegisters = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t) (Rx_Data.dataBuf[3]);
 if((startAddress + numberOfRegisters) > (205 + 1)){ 
 HandleModbusError(0x02);
 }
 else{ 
 Tx_Data.function = 3;
 Tx_Data.address = ModbusSlaveAddress;
 Tx_Data.dataLen = 1;
 Tx_Data.dataBuf[0] = 0;
 for (i = 0;i < numberOfRegisters;i ++){
 currentData = (uint16_t)NVRAM0[startAddress + i];
 Tx_Data.dataBuf[Tx_Data.dataLen] = (uint8_t)((currentData & 0xFF00) >> 8);
 Tx_Data.dataBuf[Tx_Data.dataLen + 1] = (uint8_t)(currentData & 0x00FF);
 Tx_Data.dataLen += 2;
 Tx_Data.dataBuf[0] = Tx_Data.dataLen - 1;
 }
 SendMessage();
 }
 }
 void HandleModbusWriteSingleCoil(void){ 
 uint16_t startAddress, value;
 
 startAddress = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t) (Rx_Data.dataBuf[1]);
 value = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t)(Rx_Data.dataBuf[3]);
 if((startAddress) > ((205 + 1) * 16)){ 
 HandleModbusError(0x02);
 }
 else{
 Tx_Data.function = 5;
 Tx_Data.address = ModbusSlaveAddress;
 Tx_Data.dataLen = 4;
 Tx_Data.dataBuf[0] = Rx_Data.dataBuf[0];
 Tx_Data.dataBuf[1] = Rx_Data.dataBuf[1];
 if(value == 0x0000){ 
 NVRAM0[(startAddress / 16)] &= ~((uint16_t)(1 << (startAddress % 16)));
 Tx_Data.dataBuf[2] = 0x00;
 Tx_Data.dataBuf[3] = 0x00;
 }
 else if(value == 0xFF00){ 
 NVRAM0[(startAddress / 16)] |= (uint16_t)(1 << (startAddress % 16));
 Tx_Data.dataBuf[2] = 0xFF;
 Tx_Data.dataBuf[3] = 0x00;
 }
 else{		
 }
 SendMessage();
 }
 }
 void HandleModbusWriteSingleRegister(void){ 
 uint16_t address, value,i;
 
 address = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t)(Rx_Data.dataBuf[1]);
 value = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t)(Rx_Data.dataBuf[3]);
 
 Tx_Data.function = 6;
 Tx_Data.address = ModbusSlaveAddress;
 Tx_Data.dataLen = 4;
 if(address >= (205 + 1)){
 HandleModbusError(0x03);
 }
 else{
 NVRAM0[address] = (int16_t)value;
 for (i = 0; i < 4; ++i){
 Tx_Data.dataBuf[i] = Rx_Data.dataBuf[i];
 }
 }
 SendMessage();
 }
 void HandleModbusWriteMultipleCoils(void){ 
 uint16_t startAddress, numberOfCoil, byteCount, tempAddr, i, j;
 uint8_t tempData = 0;
 
 startAddress = ((uint16_t) (Rx_Data.dataBuf[0]) << 8) + (uint16_t) (Rx_Data.dataBuf[1]);
 numberOfCoil = ((uint16_t) (Rx_Data.dataBuf[2]) << 8) + (uint16_t) (Rx_Data.dataBuf[3]);
 if((startAddress + numberOfCoil) > ((205 + 1) * 16)){ 
 HandleModbusError(0x02);
 }
 else{
 byteCount = numberOfCoil / 8;
 if((numberOfCoil % 8) != 0){
 byteCount += 1;
 }
 Tx_Data.function = 15;
 Tx_Data.address = ModbusSlaveAddress;
 Tx_Data.dataLen = 4;
 Tx_Data.dataBuf[0] = Rx_Data.dataBuf[0];
 Tx_Data.dataBuf[1] = Rx_Data.dataBuf[1];
 Tx_Data.dataBuf[2] = Rx_Data.dataBuf[2];
 Tx_Data.dataBuf[3] = Rx_Data.dataBuf[3];
 tempAddr = startAddress;
 for(i = 0;i < byteCount;i ++){
 for(j = 0;j < 8;j ++){
 tempData = (uint8_t)((Rx_Data.dataBuf[(5 + i)] >> j) & 0x01);
 if(tempData){ 
 NVRAM0[(tempAddr / 16)] |= (uint16_t)(1 << (tempAddr % 16));
 }
 else{ 
 NVRAM0[(tempAddr / 16)] &= ~((uint16_t)(1 << (tempAddr % 16)));
 }
 tempAddr ++;
 numberOfCoil --;
 if(numberOfCoil == 0){
 break;
 }
 }
 
 }
 SendMessage();
 }
 }
 void HandleModbusWriteMultipleRegisters(void){ 
 
 data uint16_t startAddress, numberOfRegisters, value;
 data uint8_t byteCount , i;
 
 startAddress = ((uint16_t)(Rx_Data.dataBuf[0]) << 8) + (uint16_t)(Rx_Data.dataBuf[1]);
 numberOfRegisters = ((uint16_t)(Rx_Data.dataBuf[2]) << 8) + (uint16_t)(Rx_Data.dataBuf[3]);
 byteCount = Rx_Data.dataBuf[4];
 
 if((startAddress+numberOfRegisters) > (205 + 1)){
 HandleModbusError(0x03);
 }
 else{
 
 Tx_Data.function = 16;
 Tx_Data.address = ModbusSlaveAddress;
 Tx_Data.dataLen = 4;
 Tx_Data.dataBuf[0] = Rx_Data.dataBuf[0];
 Tx_Data.dataBuf[1] = Rx_Data.dataBuf[1];
 Tx_Data.dataBuf[2] = Rx_Data.dataBuf[2];
 Tx_Data.dataBuf[3] = Rx_Data.dataBuf[3];
 
 for (i = 0;i < numberOfRegisters;i ++){
 value = (uint16_t)((Rx_Data.dataBuf[5 + 2 * i] << 8) & 0xFF00) + (uint16_t)((Rx_Data.dataBuf[6 + 2 * i]) & 0x00FF);
 NVRAM0[startAddress + i] = (int16_t)value;
 }
 SendMessage();
 }
 }
 uint8_t RxDataAvailable(void){ 
 uint8_t Result = Rx_Data_Available;   
 Rx_Data_Available = false;
 return Result;
 }
 uint8_t CheckRxTimeout(void){ 
 
 if (modbusTimerValue >= 256){
 modbusTimerValue = 0;
 modbusReceiveCounter = 0;
 return true;
 }
 return false;
 }
 uint8_t checkModbusBufferComplete(void){ 
 data int32_t expectedReceiveCount=0;
 if(modbusReceiveCounter > 4)
 {
 if(modbusReceiveBuffer[0] == ModbusSlaveAddress)
 {
 if(modbusReceiveBuffer[1]==0x01 || modbusReceiveBuffer[1]==0x02 || modbusReceiveBuffer[1]==0x03 || modbusReceiveBuffer[1]==0x04 || modbusReceiveBuffer[1]==0x05 || modbusReceiveBuffer[1]==0x06)   
 {
 expectedReceiveCount = 8;
 }
 else if(modbusReceiveBuffer[1] == 0x0F || modbusReceiveBuffer[1] == 0x10)
 {
 expectedReceiveCount=modbusReceiveBuffer[6] + 9;
 }
 else{
 modbusReceiveCounter = 0;
 return 0;
 }
 }
 else
 {
 modbusReceiveCounter=0;
 return 1;
 }
 }
 else
 return 2;
 
 if(modbusReceiveCounter==expectedReceiveCount)
 {
 return 3;
 }
 
 return 2;
 }
 void RxRTU(void){ 
 uint8_t i;
 uint8_t receiveBufferControl=0;
 receiveBufferControl = checkModbusBufferComplete();
 if(receiveBufferControl == 3){
 Rx_Data.address               =modbusReceiveBuffer[0];
 Rx_CRC16                      = 0xffff;
 modbusCrc16(Rx_Data.address, &Rx_CRC16);
 Rx_Data.function              =modbusReceiveBuffer[1];
 modbusCrc16(Rx_Data.function, &Rx_CRC16);
 
 Rx_Data.dataLen=0;
 
 for(i=2;i<modbusReceiveCounter;i++)
 Rx_Data.dataBuf[Rx_Data.dataLen++]=modbusReceiveBuffer[i];
 
 Rx_State =RXTX_DATABUF;
 
 modbusReceiveCounter=0;
 }
 
 CheckRxTimeout();
 
 if ((Rx_State == RXTX_DATABUF) && (Rx_Data.dataLen >= 2))
 {
 
 Rx_Data.dataLen -= 2;
 for (i = 0; i < Rx_Data.dataLen; ++i)
 {
 modbusCrc16(Rx_Data.dataBuf[i], &Rx_CRC16);
 }
 
 if (((uint32_t) Rx_Data.dataBuf[Rx_Data.dataLen] + ((uint32_t) Rx_Data.dataBuf[Rx_Data.dataLen + 1] << 8)) == Rx_CRC16)
 {
 
 Rx_Data_Available = true;
 }
 
 Rx_State = RXTX_IDLE;
 }
 }
 void TxRTU(void){ 
 Tx_CRC16 = 0xFFFF;
 Tx_Buf_Size = 0;
 Tx_Buf[Tx_Buf_Size++] = Tx_Data.address;
 modbusCrc16(Tx_Data.address, &Tx_CRC16);
 Tx_Buf[Tx_Buf_Size++] = Tx_Data.function;
 modbusCrc16(Tx_Data.function, &Tx_CRC16);
 for(Tx_Current=0; Tx_Current < Tx_Data.dataLen; Tx_Current++){
 Tx_Buf[Tx_Buf_Size++] = Tx_Data.dataBuf[Tx_Current];
 modbusCrc16(Tx_Data.dataBuf[Tx_Current], &Tx_CRC16);
 }
 Tx_Buf[Tx_Buf_Size++] = Tx_CRC16 & 0x00FF;
 Tx_Buf[Tx_Buf_Size++] = (Tx_CRC16 & 0xFF00) >> 8;
 DoSlaveTX();
 Tx_State = RXTX_IDLE;
 }
 void modbusPorcess(void){ 
 if (Tx_State != RXTX_IDLE){                                       
 TxRTU();
 }
 RxRTU();                                                               
 if (RxDataAvailable()){
 if (Rx_Data.address == ModbusSlaveAddress){
 switch (Rx_Data.function)                                      
 {
 case 1:{ 
 HandleModbusReadCoils();
 break;
 }
 case 3:{ 
 HandleModbusReadHoldingRegisters();
 break;  
 }
 case 5:{ 
 HandleModbusWriteSingleCoil();
 break;
 }
 case 6:{ 
 HandleModbusWriteSingleRegister();
 break;
 }
 case 15:{ 
 HandleModbusWriteMultipleCoils();
 break;
 }
 case 16:{ 
 HandleModbusWriteMultipleRegisters();
 break;
 }
 default:{
 HandleModbusError(0x01);
 break;
 }
 }
 }
 }
 }
 void InitModbus(uint8_t modbusSlaveAddress, uint32_t baudrate){ 
 ModbusSlaveAddress = modbusSlaveAddress;
 modBusUartInitialise(baudrate);
 modBusTimerInitialise();
 }
