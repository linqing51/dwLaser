
#line 1 "Lib\delay.c" /0
  
#line 1 "Lib\delay.h" /0
 
 
 
  
#line 1 ".\MainApp\appConfig.h" /0
 
 
 
 
 
 <<<<<<< HEAD
 
 =======
 
#error *** WARNING C317 IN LINE 9 OF .\MainApp\appConfig.h: attempt to redefine macro 'CONFIG_SYSCLK'
 
#line 11 ".\MainApp\appConfig.h" /1
 
  
  
 
  
  
  
  
  
  
  
 
 
 
 
  
  
  
  
 
  
  
  
  
 
 
  
  
  
  
  
 
  
 
  
 
  
  
  
  
  
  
  
  
  
  
  
  
 
  
  
 
  
 
  
  
  
  
  
  
  
  
  
  
 
  
 
 
 
  
  
  
  
  
 
  
 
  
 
  
 
  
 
  
 
  
 
  
 
 
  
  
  
  
  
  
  
 
  
 
  
  
  
  
  
  
 
 
 
  
  
  
  
 
 
 
  
  
  
  
  
  
  
 
  
  
  
 
 
  
 
 
 
 
  
  
  
  
 
 
  
  
  
  
  
  
 
  
  
  
  
  
 
  
 
  
 
 
  
  
  
  
  
  
  
 
 
  
  
  
  
  
  
  
  
  
  
  
  
  
 
 
 
 
  
  
  
  
  
  
  
  
 
 
  
 
 
  
 
 
  
 
 
  
  
 
  
 
  
 
  
  
  
  
  
 
 
 
#line 4 "Lib\delay.h" /0
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
 
#error *** WARNING C322 IN LINE 9 OF Lib\delay.c: unknown identifier
#line 10 "Lib\delay.c" /1
 
 
#line 12 "Lib\delay.c" /0
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
 
 
#error *** WARNING C316 IN LINE 23 OF Lib\delay.c: unterminated conditionals
