
#line 1 "LibFlash\F580_FlashUtils.c" /0
 /-----------------------------------------------------------------------------
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
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
 
 
 
 
 
 
 
 
 
 
#line 23 "LibFlash\F580_FlashUtils.c" /0
 
  
#line 1 ".\Lib\c8051F580_defs.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
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
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 597 ".\Lib\c8051F580_defs.h" /1
 
 
 
 
#line 601 ".\Lib\c8051F580_defs.h" /0
 
 
 
 
 
 
 
 
 
 
#line 24 "LibFlash\F580_FlashUtils.c" /0
 
  
#line 1 "LibFlash\F580_FlashPrimitives.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 123 ".\Lib\compiler_defs.h" /1
  
 
  
  
 
 
 
 
 
 
  
 
 
  
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
 
  
 
  
 
  
  
  
 
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
 
  
  
 
 
 
 
  
  
  
 
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
#line 804 ".\Lib\compiler_defs.h" /0
 
 
 
 
#line 28 "LibFlash\F580_FlashPrimitives.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 61 "LibFlash\F580_FlashPrimitives.h" /1
 
 
  
 
 
 
  
 
 
 
#line 71 "LibFlash\F580_FlashPrimitives.h" /0
 
 
 
 typedef U32 FLADDR;                     
 
 
 
 
 
 
 
 
 U8   FLASH_ByteWrite (FLADDR addr, U8 byte, bit SFLE);
 U8   FLASH_ByteRead  (FLADDR addr, bit SFLE);
 U8   FLASH_PageErase (FLADDR addr, bit SFLE);
 
 
 
 
 
 
 
#line 25 "LibFlash\F580_FlashUtils.c" /0
 
  
#line 1 "LibFlash\F580_FlashUtils.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 ".\Lib\compiler_defs.h" /0
 
 
 
 
 
 
 
 
 

















 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 123 ".\Lib\compiler_defs.h" /1
  
 
  
  
 
 
 
 
 
 
  
 
 
  
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
 
  
  
  
  
 
  
  
 
 
  
  
  
  
  
 
 
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
 
  
  
 
 
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
  
  
 
  
  
  
 
  
 
  
 
  
  
  
 
  
  
  
  
 
 
 
  
  
 
 
  
  
  
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
 
 
 
 
 
 
  
  
 
  
  
  
  
  
  
  
 
  
  
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
  
 
  
  
 
 
 
 
  
  
  
 
  
 
 
  
  
 
 
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
  
  
  
  
  
  
 
 
 
 
 
 
 
 
  
  
  
  
  
  
  
 
 
 
 
 
 
 
 
#line 804 ".\Lib\compiler_defs.h" /0
 
 
 
 
#line 27 "LibFlash\F580_FlashUtils.h" /0
 
  
#line 1 "LibFlash\F580_FlashPrimitives.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 22 "LibFlash\F580_FlashPrimitives.h" /1
  
 
 
 
 
 
  
 
 
 
 
 
  
 
 
  
 
 
 
  
 
 
 
 
 
 
 
  
 
 
 
  
 
 
 
 
 
 
 
 
 
  
 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 88 "LibFlash\F580_FlashPrimitives.h" /0
 
 
 
 
 
#line 28 "LibFlash\F580_FlashUtils.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 extern void FLASH_Write (FLADDR dest, U8 *src, U16 numbytes, bit SFLE);
 extern U8 * FLASH_Read  (U8 *dest, FLADDR src, U16 numbytes, bit SFLE);
 extern void FLASH_Clear (FLADDR addr, U16 numbytes, bit SFLE);
 
 
 extern void FLASH_Update (FLADDR dest, U8 *src, U16 numbytes, bit SFLE);
 extern void FLASH_Copy   (FLADDR dest, bit destSFLE, FLADDR src, bit srcSFLE,
 U16 numbytes);
 
 
 extern void FLASH_Fill (FLADDR addr, U32 length, U8 fill, bit SFLE);
 
 
 
 
 
 
 
#line 26 "LibFlash\F580_FlashUtils.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void FLASH_Write (FLADDR dest, U8 *src, U16 numbytes, bit SFLE);
 U8 * FLASH_Read  (U8 *dest, FLADDR src, U16 numbytes, bit SFLE);
 void FLASH_Clear (FLADDR addr, U16 numbytes, bit SFLE);
 
 
 void FLASH_Update (FLADDR dest, U8 *src, U16 numbytes, bit SFLE);
 void FLASH_Copy   (FLADDR dest, bit destSFLE, FLADDR src, bit srcSFLE,
 U16 numbytes);
 
 
 void FLASH_Fill (FLADDR addr, U32 length, U8 fill, bit SFLE);
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void FLASH_Clear (FLADDR dest, U16 numbytes, bit SFLE)
 {
 FLADDR dest_1_page_start;            
 
 FLADDR dest_1_page_end;              
 
 FLADDR dest_2_page_start;            
 
 FLADDR dest_2_page_end;              
 
 U16 numbytes_remainder;              
 
 U16 FLASH_pagesize;                  
 
 FLADDR  wptr;                        
 FLADDR  rptr;                        
 
 U16 length;
 
 if (SFLE) {                          
 FLASH_pagesize = 256;
 } else {
 FLASH_pagesize = 512L;
 }
 
 dest_1_page_start = dest & (0x10000 | ~(FLASH_pagesize - 1));
 dest_1_page_end = dest_1_page_start + FLASH_pagesize - 1;
 dest_2_page_start = (dest + numbytes)  & (0x10000 | ~(FLASH_pagesize - 1));
 dest_2_page_end = dest_2_page_start + FLASH_pagesize - 1;
 
 if (dest_1_page_end == dest_2_page_end) {
 
 
 FLASH_PageErase (0x1F800L, 0);
 
 
 
 wptr = 0x1F800L;
 rptr = dest_1_page_start;
 length = dest - dest_1_page_start;
 FLASH_Copy (wptr, 0, rptr, SFLE, length);
 
 
 
 wptr = 0x1F800L + dest - dest_1_page_start + numbytes;
 rptr = dest + numbytes;
 length = dest_1_page_end - dest - numbytes + 1;
 FLASH_Copy (wptr, 0, rptr, SFLE, length);
 
 
 FLASH_PageErase (dest_1_page_start, SFLE);
 
 
 wptr = dest_1_page_start;
 rptr = 0x1F800L;
 length = FLASH_pagesize;
 FLASH_Copy (wptr, SFLE, rptr, 0, length);
 
 } else {                             
 
 FLASH_PageErase (0x1F800L, 0);
 
 
 
 wptr = 0x1F800L;
 rptr = dest_1_page_start;
 length = dest - dest_1_page_start;
 FLASH_Copy (wptr, 0, rptr, SFLE, length);
 
 
 FLASH_PageErase (dest_1_page_start, SFLE);
 
 
 wptr = dest_1_page_start;
 rptr = 0x1F800L;
 length = FLASH_pagesize;
 FLASH_Copy (wptr, SFLE, rptr, 0, length);
 
 
 
 
 FLASH_PageErase (0x1F800L, 0);
 
 
 
 numbytes_remainder = numbytes - (dest_1_page_end - dest + 1);
 wptr = 0x1F800L + numbytes_remainder;
 rptr = dest_2_page_start + numbytes_remainder;
 length = FLASH_pagesize - numbytes_remainder;
 FLASH_Copy (wptr, 0, rptr, SFLE, length);
 
 
 FLASH_PageErase (dest_2_page_start, SFLE);
 
 
 wptr = dest_2_page_start;
 rptr = 0x1F800L;
 length = FLASH_pagesize;
 FLASH_Copy (wptr, SFLE, rptr, 0, length);
 }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 void FLASH_Update (FLADDR dest, U8 *src, U16 numbytes, bit SFLE)
 {
 
 FLASH_Clear (dest, numbytes, SFLE);
 
 
 FLASH_Write (dest, src, numbytes, SFLE);
 }
 
 
 
 
 
 
 
 
 
 
 
 void FLASH_Write (FLADDR dest, U8 *src, U16 numbytes, bit SFLE)
 {
 U32 i;
 
 for (i = dest; i < dest+numbytes; i++) {
 FLASH_ByteWrite (i, *src++, SFLE);
 }
 }
 
 
 
 
 
 
 
 
 
 U8 * FLASH_Read (U8 *dest, FLADDR src, U16 numbytes, bit SFLE)
 {
 U32 i;
 
 for (i = 0; i < numbytes; i++) {
 *dest++ = FLASH_ByteRead (src+i, SFLE);
 }
 return dest;
 }
 
 
 
 
 
 
 
 
 
 void FLASH_Copy (FLADDR dest, bit destSFLE, FLADDR src, bit srcSFLE,
 U16 numbytes)
 {
 U32 i;
 
 for (i = 0; i < numbytes; i++) {
 
 FLASH_ByteWrite ((FLADDR) dest+i,
 FLASH_ByteRead((FLADDR) src+i, srcSFLE),
 destSFLE);
 }
 }
 
 
 
 
 
 
 
 
 
 void FLASH_Fill (FLADDR addr, U32 length, U8 fill, bit SFLE)
 {
 U32 i;
 
 for (i = 0; i < length; i++) {
 FLASH_ByteWrite (addr+i, fill, SFLE);
 }
 }
 
 
 
 
 
