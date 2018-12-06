
#line 1 "FlashEprom\Fxxx_EEPROM_Interface.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "\GitHub\dwLaser\MCU_Bootloader\Lib\stdbool.h" /0




 
 
 
 
 
 
 
 typedef bit bool;
 enum{
 false = 0,
 true = 1,
 };
 
 
#line 19 "\GitHub\dwLaser\MCU_Bootloader\Lib\stdbool.h" /1
 
 
 
 
 
 
 
  
  
  
 
  
 
 
 
 
 
 
 
 
 
 
 
 
#line 43 "\GitHub\dwLaser\MCU_Bootloader\Lib\stdbool.h" /0
 
 
 
#line 125 ".\Lib\compiler_defs.h" /0
 
  
#line 1 "\GitHub\dwLaser\MCU_Bootloader\Lib\stdint.h" /0




 
 
 
 
 
 
 
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
 
 
#line 25 "\GitHub\dwLaser\MCU_Bootloader\Lib\stdint.h" /1
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 51 "\GitHub\dwLaser\MCU_Bootloader\Lib\stdint.h" /0
 
 
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
 
 
 
 
 
 
 
 
 
 
#line 19 "FlashEprom\Fxxx_EEPROM_Interface.c" /0
 
  
#line 1 "FlashEprom\Fxxx_Flash_Interface.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 extern void EE_FLASH_WriteErase (U16, S8, S8);
 extern U8 EE_FLASH_BlankCheck(U16);
 extern U8 EE_FLASH_Read (U16);
 
 
 
 
 
 extern U8 data FlashKey1;
 extern U8 data FlashKey2;
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 20 "FlashEprom\Fxxx_EEPROM_Interface.c" /0
 
  
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
 
 
 
 

#line 146 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  















  
  
 
#line 177 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 


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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

#line 497 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 513 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 517 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 533 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 537 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 553 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 558 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 574 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 577 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 593 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 596 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 612 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 615 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
 
#line 617 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 



 
  
#line 1 ".\Lib\c8051f340_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 344 ".\Lib\c8051f340_defs.h" /1
 
 
 
 
#line 348 ".\Lib\c8051f340_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 625 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



#line 646 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 662 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 667 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 683 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 



#line 690 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 706 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 709 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 725 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 729 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 745 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 748 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 764 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 


#line 770 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 786 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 


#line 791 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 807 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 812 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 828 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 832 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 848 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 852 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
 
#line 854 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 

#line 859 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 875 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 879 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 895 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 





#line 904 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 920 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 





#line 928 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 944 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 


#line 950 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 966 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 


#line 971 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 987 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 


#line 993 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1009 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 1013 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1029 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 



#line 1035 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1051 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 





#line 1060 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1076 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 








#line 1087 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1103 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 


#line 1108 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1124 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 1128 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1144 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 1147 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1163 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
#line 1167 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1183 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 1186 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1202 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 



#line 1209 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1225 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 

#line 1229 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
#line 1245 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
#line 1248 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
 
#line 1250 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
#line 1252 "FlashEprom\Fxxx_Flash_Parameters.h" /1
 
 
#line 1254 "FlashEprom\Fxxx_Flash_Parameters.h" /0
 
 
 
 
 
 
#line 19 "FlashEprom\Fxxx_EEPROM_Configuration.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 54 "FlashEprom\Fxxx_EEPROM_Configuration.h" /1
 
 
#line 56 "FlashEprom\Fxxx_EEPROM_Configuration.h" /0
 
 
#line 58 "FlashEprom\Fxxx_EEPROM_Configuration.h" /1
 
 
#line 60 "FlashEprom\Fxxx_EEPROM_Configuration.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 21 "FlashEprom\Fxxx_EEPROM_Interface.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 U8 currentEepromSector = 0, currentEepromPage = 0;
 
 
 
 
 void copySector(U16, U16, U8, U8);
 U16 getBaseAddress(U8, U8);
 U8 findNextSector(void);
 U8 findCurrentSector(void);
 
 U8 EEPROM_WriteBlock (U8, U8 *, U8);
 U8 EEPROM_ReadBlock (U8, U8 *, U8);
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 U8 EEPROM_WriteBlock (U8 address, U8 *dataBuf, U8 length)
 {
 U16 readAddr, writeAddr;
 U8 nextSector;
 U8 currentTag;
 U8 byteCount;
 U8 pageEraseCounter;
 
 if ((U16)(address+length) > 256)
 {
 return 0x01;
 }
 
 currentTag = findCurrentSector();
 if (currentTag == 0x00)
 {
 return 0x02;
 }
 
 
 readAddr = getBaseAddress(currentEepromPage, currentEepromSector);
 
 nextSector = findNextSector();
 
 
 writeAddr = getBaseAddress(currentEepromPage, currentEepromSector);
 
 if (nextSector == 0x00)
 {
 pageEraseCounter = 0;
 
 while (pageEraseCounter < 1)
 {
 EE_FLASH_WriteErase (writeAddr, 0xFF, 0x03);
 if (!EE_FLASH_BlankCheck(writeAddr))
 {
 if (++pageEraseCounter == 1)
 {
 return 0x01;
 }
 }
 else
 {
 break;
 }
 }
 }
 
 
 EE_FLASH_WriteErase (writeAddr + 256, 0x7F, 0x01);
 
 
 copySector(readAddr, writeAddr, address, length);
 
 
 for (byteCount = 0; byteCount < length; byteCount++)
 {
 EE_FLASH_WriteErase (writeAddr + address + byteCount, *dataBuf++, 0x01);
 }
 if (currentTag == 0x7E)
 {
 currentTag = 0x01;
 }
 else
 {
 currentTag++;
 }
 
 
 EE_FLASH_WriteErase (writeAddr + 256, currentTag, 0x01);
 
 return 0x00;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 U8 EEPROM_ReadBlock (U8 address, U8 *dataBuf, U8 length)
 {
 U16 sectorAddress;
 U8 byteCount;
 
 if ((U16)(address+length) > 256)
 {
 return 0x03;
 }
 if (findCurrentSector() == 0x00)
 {
 return 0x02;
 }
 sectorAddress = getBaseAddress(currentEepromPage, currentEepromSector);
 
 for (byteCount = 0; byteCount < length; byteCount++)
 {
 *dataBuf++ = EE_FLASH_Read(sectorAddress+address+byteCount);
 }
 return 0x00;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void copySector(U16 fromAddr, U16 toAddr, U8 exclude, U8 length)
 {
 U8 offset_addr;
 U8 copy_byte;
 
 for (offset_addr = 0; offset_addr < 256; offset_addr++)
 {
 
 copy_byte = EE_FLASH_Read(fromAddr+offset_addr);
 
 if ((offset_addr < exclude)||(offset_addr >= exclude+length))
 {
 EE_FLASH_WriteErase ((toAddr+offset_addr), copy_byte, 0x01);
 }
 }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 U8 findNextSector(void)
 {
 U8 pageNow = currentEepromPage, sectorNow = currentEepromSector;
 U8 sectorFound = 2;
 U8 sectTag;
 U16 sectorAddress;
 
 while (sectorFound == 2)
 {
 currentEepromSector++;
 if (currentEepromSector == (U8)(512/(256+1)))
 {
 currentEepromSector = 0;
 currentEepromPage++;
 if (currentEepromPage == 2)
 {
 currentEepromPage = 0;
 }
 }
 sectorAddress = getBaseAddress(currentEepromPage, currentEepromSector);
 sectTag = EE_FLASH_Read(sectorAddress+256);
 if (sectTag == 0xFF)
 {
 sectorFound = 1;
 }
 else if ((pageNow == currentEepromPage)&&
 (sectorNow == currentEepromSector))
 {
 currentEepromSector = 0;
 currentEepromPage++;
 if (currentEepromPage == 2)
 {
 currentEepromPage = 0;
 }
 sectorFound = 0;
 }
 }
 return sectorFound;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 U8 findCurrentSector(void)
 {
 U8 pgCount, sectCount;
 U8 emptySectors = 0;
 U8 sectTag = 0x00, latestTag = 0x00, nextTag = 0x00;
 
 for (pgCount = 0; pgCount < 2; pgCount++)
 {
 for (sectCount = 0; sectCount < (U8)(512/(256+1)); sectCount++)
 {
 sectTag = EE_FLASH_Read(getBaseAddress(pgCount, sectCount)+256);
 
 if (sectTag == 0xFF)
 {
 emptySectors++;
 }
 if ((sectTag >= 0x01)&&(sectTag <= 0x7E))
 {
 if ((latestTag == 0x00)||(sectTag == nextTag))
 {
 latestTag = sectTag;
 currentEepromPage = pgCount;
 currentEepromSector = sectCount;
 
 if (sectTag == 0x7E)
 {
 nextTag = 0x01;
 }
 else
 {
 nextTag = sectTag + 1;
 }
 }
 }
 }
 }
 
 if (emptySectors == 2*(U8)(512/(256+1)))
 {
 latestTag = 0x01;
 currentEepromPage = 2-1;
 currentEepromSector = (U8)(512/(256+1))-1;
 }
 
 return latestTag;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 U16 getBaseAddress(U8 page, U8 sector)
 {
 return (0xF000+(512*page)+(256+1)*sector);
 }
 
 
 
 
