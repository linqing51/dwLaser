
#line 1 "LibFlash\F340_FlashPrimitives.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "LibFlash\F340_FlashPrimitives.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef unsigned long ULONG;
 typedef unsigned int  UINT;
 typedef unsigned char UCHAR;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef UINT FLADDR;
 
 
 
 
 
 
 extern void FLASH_ByteWrite (FLADDR addr, char byte);
 extern unsigned char FLASH_ByteRead (FLADDR addr);
 extern void FLASH_PageErase (FLADDR addr);
 
 
 
 
 
 
#line 26 "LibFlash\F340_FlashPrimitives.c" /0
 
  
#line 1 ".\Lib\c8051F340.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 sfr  P0           =  0x80;              
 sfr  SP           =  0x81;              
 sfr  DPL          =  0x82;              
 sfr  DPH          =  0x83;              
 sfr  EMI0TC       =  0x84;              
 sfr  EMI0CF       =  0x85;              
 sfr  OSCLCN       =  0x86;              
 sfr  PCON         =  0x87;              
 sfr  TCON         =  0x88;              
 sfr  TMOD         =  0x89;              
 sfr  TL0          =  0x8A;              
 sfr  TL1          =  0x8B;              
 sfr  TH0          =  0x8C;              
 sfr  TH1          =  0x8D;              
 sfr  CKCON        =  0x8E;              
 sfr  PSCTL        =  0x8F;              
 sfr  P1           =  0x90;              
 sfr  TMR3CN       =  0x91;              
 sfr  TMR3RLL      =  0x92;              
 sfr  TMR3RLH      =  0x93;              
 sfr  TMR3L        =  0x94;              
 sfr  TMR3H        =  0x95;              
 sfr  USB0ADR      =  0x96;              
 sfr  USB0DAT      =  0x97;              
 sfr  SCON0        =  0x98;              
 sfr  SBUF0        =  0x99;              
 sfr  CPT1CN       =  0x9A;              
 sfr  CPT0CN       =  0x9B;              
 sfr  CPT1MD       =  0x9C;              
 sfr  CPT0MD       =  0x9D;              
 sfr  CPT1MX       =  0x9E;              
 sfr  CPT0MX       =  0x9F;              
 sfr  P2           =  0xA0;              
 sfr  SPI0CFG      =  0xA1;              
 sfr  SPI0CKR      =  0xA2;              
 sfr  SPI0DAT      =  0xA3;              
 sfr  P0MDOUT      =  0xA4;              
 sfr  P1MDOUT      =  0xA5;              
 sfr  P2MDOUT      =  0xA6;              
 sfr  P3MDOUT      =  0xA7;              
 sfr  IE           =  0xA8;              
 sfr  CLKSEL       =  0xA9;              
 sfr  EMI0CN       =  0xAA;              
 sfr  SBCON1       =  0xAC;              
 sfr  P4MDOUT      =  0xAE;              
 sfr  PFE0CN       =  0xAF;              
 sfr  P3           =  0xB0;              
 sfr  OSCXCN       =  0xB1;              
 sfr  OSCICN       =  0xB2;              
 sfr  OSCICL       =  0xB3;              
 sfr  SBRLL1       =  0xB4;              
 sfr  SBRLH1       =  0xB5;              
 sfr  FLSCL        =  0xB6;              
 sfr  FLKEY        =  0xB7;              
 sfr  IP           =  0xB8;              
 sfr  CLKMUL       =  0xB9;              
 sfr  AMX0N        =  0xBA;              
 sfr  AMX0P        =  0xBB;              
 sfr  ADC0CF       =  0xBC;              
 sfr  ADC0L        =  0xBD;              
 sfr  ADC0H        =  0xBE;              
 sfr  SMB0CN       =  0xC0;              
 sfr  SMB0CF       =  0xC1;              
 sfr  SMB0DAT      =  0xC2;              
 sfr  ADC0GTL      =  0xC3;              
 sfr  ADC0GTH      =  0xC4;              
 sfr  ADC0LTL      =  0xC5;              
 sfr  ADC0LTH      =  0xC6;              
 sfr  P4           =  0xC7;              
 sfr  TMR2CN       =  0xC8;              
 sfr  REG0CN       =  0xC9;              
 sfr  TMR2RLL      =  0xCA;              
 sfr  TMR2RLH      =  0xCB;              
 sfr  TMR2L        =  0xCC;              
 sfr  TMR2H        =  0xCD;              
 sfr  PSW          =  0xD0;              
 sfr  REF0CN       =  0xD1;              
 sfr  SCON1        =  0xD2;              
 sfr  SBUF1        =  0xD3;              
 sfr  P0SKIP       =  0xD4;              
 sfr  P1SKIP       =  0xD5;              
 sfr  P2SKIP       =  0xD6;              
 sfr  USB0XCN      =  0xD7;              
 sfr  PCA0CN       =  0xD8;              
 sfr  PCA0MD       =  0xD9;              
 sfr  PCA0CPM0     =  0xDA;              
 sfr  PCA0CPM1     =  0xDB;              
 sfr  PCA0CPM2     =  0xDC;              
 sfr  PCA0CPM3     =  0xDD;              
 sfr  PCA0CPM4     =  0xDE;              
 sfr  P3SKIP       =  0xDF;              
 sfr  ACC          =  0xE0;              
 sfr  XBR0         =  0xE1;              
 sfr  XBR1         =  0xE2;              
 sfr  XBR2         =  0xE3;              
 sfr  IT01CF       =  0xE4;              
 sfr  SMOD1        =  0xE5;              
 sfr  EIE1         =  0xE6;              
 sfr  EIE2         =  0xE7;              
 sfr  ADC0CN       =  0xE8;              
 sfr  PCA0CPL1     =  0xE9;              
 sfr  PCA0CPH1     =  0xEA;              
 sfr  PCA0CPL2     =  0xEB;              
 sfr  PCA0CPH2     =  0xEC;              
 sfr  PCA0CPL3     =  0xED;              
 sfr  PCA0CPH3     =  0xEE;              
 sfr  RSTSRC       =  0xEF;              
 sfr  B            =  0xF0;              
 sfr  P0MDIN       =  0xF1;              
 sfr  P1MDIN       =  0xF2;              
 sfr  P2MDIN       =  0xF3;              
 sfr  P3MDIN       =  0xF4;              
 sfr  P4MDIN       =  0xF5;              
 sfr  EIP1         =  0xF6;              
 sfr  EIP2         =  0xF7;              
 sfr  SPI0CN       =  0xF8;              
 sfr  PCA0L        =  0xF9;              
 sfr  PCA0H        =  0xFA;              
 sfr  PCA0CPL0     =  0xFB;              
 sfr  PCA0CPH0     =  0xFC;              
 sfr  PCA0CPL4     =  0xFD;              
 sfr  PCA0CPH4     =  0xFE;              
 sfr  VDM0CN       =  0xFF;              
 
 
 
 
 
 
 
 sbit TF1     = 0x8F;                    
 sbit TR1     = 0x8E;                    
 sbit TF0     = 0x8D;                    
 sbit TR0     = 0x8C;                    
 sbit IE1     = 0x8B;                    
 sbit IT1     = 0x8A;                    
 sbit IE0     = 0x89;                    
 sbit IT0     = 0x88;                    
 
 
 sbit S0MODE  = 0x9F;                    
 
 sbit MCE0    = 0x9D;                    
 sbit REN0    = 0x9C;                    
 sbit TB80    = 0x9B;                    
 sbit RB80    = 0x9A;                    
 sbit TI0     = 0x99;                    
 sbit RI0     = 0x98;                    
 
 
 sbit EA      = 0xAF;                    
 sbit ESPI0   = 0xAE;                    
 sbit ET2     = 0xAD;                    
 sbit ES0     = 0xAC;                    
 sbit ET1     = 0xAB;                    
 sbit EX1     = 0xAA;                    
 sbit ET0     = 0xA9;                    
 sbit EX0     = 0xA8;                    
 
 
 
 sbit PSPI0   = 0xBE;                    
 sbit PT2     = 0xBD;                    
 sbit PS0     = 0xBC;                    
 sbit PT1     = 0xBB;                    
 sbit PX1     = 0xBA;                    
 sbit PT0     = 0xB9;                    
 sbit PX0     = 0xB8;                    
 
 
 sbit MASTER  = 0xC7;                    
 sbit TXMODE  = 0xC6;                    
 sbit STA     = 0xC5;                    
 sbit STO     = 0xC4;                    
 sbit ACKRQ   = 0xC3;                    
 sbit ARBLOST = 0xC2;                    
 sbit ACK     = 0xC1;                    
 sbit SI      = 0xC0;                    
 
 
 sbit TF2H    = 0xCF;                    
 sbit TF2L    = 0xCE;                    
 sbit TF2LEN  = 0xCD;                    
 sbit T2SOF   = 0xCC;                    
 sbit T2SPLIT = 0xCB;                    
 sbit TR2     = 0xCA;                    
 
 sbit T2XCLK  = 0xC8;                    
 
 
 sbit CY      = 0xD7;                    
 sbit AC      = 0xD6;                    
 sbit F0      = 0xD5;                    
 sbit RS1     = 0xD4;                    
 sbit RS0     = 0xD3;                    
 sbit OV      = 0xD2;                    
 sbit F1      = 0xD1;                    
 sbit P       = 0xD0;                    
 
 
 sbit CF      = 0xDF;                    
 sbit CR      = 0xDE;                    
 
 sbit CCF4    = 0xDC;                    
 sbit CCF3    = 0xDB;                    
 sbit CCF2    = 0xDA;                    
 sbit CCF1    = 0xD9;                    
 sbit CCF0    = 0xD8;                    
 
 
 sbit AD0EN   = 0xEF;                    
 sbit AD0TM   = 0xEE;                    
 sbit AD0INT  = 0xED;                    
 sbit AD0BUSY = 0xEC;                    
 sbit AD0WINT = 0xEB;                    
 sbit AD0CM2  = 0xEA;                    
 sbit AD0CM1  = 0xE9;                    
 sbit AD0CM0  = 0xE8;                    
 
 
 sbit SPIF    = 0xFF;                    
 sbit WCOL    = 0xFE;                    
 sbit MODF    = 0xFD;                    
 sbit RXOVRN  = 0xFC;                    
 sbit NSSMD1  = 0xFB;                    
 sbit NSSMD0  = 0xFA;                    
 sbit TXBMT   = 0xF9;                    
 sbit SPIEN   = 0xF8;                    
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 27 "LibFlash\F340_FlashPrimitives.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void FLASH_ByteWrite (FLADDR addr, char byte);
 unsigned char FLASH_ByteRead (FLADDR addr);
 void FLASH_PageErase (FLADDR addr);
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void FLASH_ByteWrite (FLADDR addr, char byte)
 {
 bit EA_SAVE = EA;                    
 char xdata * data pwrite;            
 
 EA = 0;                              
 
 
 
 VDM0CN = 0x80;                       
 
 
 RSTSRC = 0x02;                       
 
 pwrite = (char xdata *) addr;
 
 FLKEY  = 0xA5;                       
 FLKEY  = 0xF1;                       
 PSCTL |= 0x01;                       
 
 
 VDM0CN = 0x80;                       
 
 
 RSTSRC = 0x02;                       
 
 *pwrite = byte;                      
 
 PSCTL &= ~0x01;                      
 
 EA = EA_SAVE;                        
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 unsigned char FLASH_ByteRead (FLADDR addr)
 {
 bit EA_SAVE = EA;                    
 char code * data pread;              
 unsigned char byte;
 
 EA = 0;                              
 
 pread = (char code *) addr;
 
 byte = *pread;                       
 
 EA = EA_SAVE;                        
 
 return byte;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void FLASH_PageErase (FLADDR addr)
 {
 bit EA_SAVE = EA;                    
 char xdata * data pwrite;            
 
 EA = 0;                              
 
 
 VDM0CN = 0x80;                       
 
 
 RSTSRC = 0x02;                       
 
 pwrite = (char xdata *) addr;
 
 FLKEY  = 0xA5;                       
 FLKEY  = 0xF1;                       
 PSCTL |= 0x03;                       
 
 
 VDM0CN = 0x80;                       
 
 
 RSTSRC = 0x02;                       
 *pwrite = 0;                         
 
 PSCTL &= ~0x03;                      
 
 EA = EA_SAVE;                        
 }
 
 
 
 
