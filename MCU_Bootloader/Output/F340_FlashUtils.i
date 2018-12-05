
#line 1 "LibFlash\F340_FlashUtils.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "LibFlash\F340_FlashPrimitives.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef unsigned long ULONG;
 typedef unsigned int  UINT;
 typedef unsigned char UCHAR;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 typedef UINT FLADDR;
 
 
 
 
 
 
 extern void FLASH_ByteWrite (FLADDR addr, char byte);
 extern unsigned char FLASH_ByteRead (FLADDR addr);
 extern void FLASH_PageErase (FLADDR addr);
 
 
 
 
 
 
#line 26 "LibFlash\F340_FlashUtils.c" /0
 
  
#line 1 "LibFlash\F340_FlashUtils.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
#line 1 "LibFlash\F340_FlashPrimitives.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 23 "LibFlash\F340_FlashPrimitives.h" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
  
 
 
 
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 65 "LibFlash\F340_FlashPrimitives.h" /0
 
 
 
 
#line 29 "LibFlash\F340_FlashUtils.h" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 extern void FLASH_Write (FLADDR dest, char *src, unsigned numbytes);
 extern char * FLASH_Read (char *dest, FLADDR src, unsigned numbytes);
 extern void FLASH_Clear (FLADDR addr, unsigned numbytes);
 
 
 
 
 extern void FLASH_Update (FLADDR dest, char *src, unsigned numbytes);   
 
 extern void FLASH_Copy (FLADDR dest, FLADDR src, unsigned numbytes);    
 
 
 extern void FLASH_Fill (FLADDR addr, ULONG length, UCHAR fill);
 
 
 
 
 
 
#line 27 "LibFlash\F340_FlashUtils.c" /0
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void FLASH_Write (FLADDR dest, char *src, unsigned numbytes);
 char * FLASH_Read (char *dest, FLADDR src, unsigned numbytes);
 void FLASH_Clear (FLADDR addr, unsigned numbytes);
 
 
 void FLASH_Update (FLADDR dest, char *src, unsigned numbytes);
 void FLASH_Copy (FLADDR dest, FLADDR src, unsigned numbytes);
 
 
 void FLASH_Fill (FLADDR addr, ULONG length, UCHAR fill);
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void FLASH_Clear (FLADDR dest, unsigned numbytes)
 {
 FLADDR dest_1_page_start;            
 
 FLADDR dest_1_page_end;              
 
 FLADDR dest_2_page_start;            
 
 FLADDR dest_2_page_end;              
 
 unsigned numbytes_remainder;         
 
 unsigned FLASH_pagesize;             
 
 FLADDR  wptr;                        
 FLADDR  rptr;                        
 
 unsigned length;
 
 FLASH_pagesize = 512;
 
 dest_1_page_start = dest & ~(FLASH_pagesize - 1);
 dest_1_page_end = dest_1_page_start + FLASH_pagesize - 1;
 dest_2_page_start = (dest + numbytes)  & ~(FLASH_pagesize - 1);
 dest_2_page_end = dest_2_page_start + FLASH_pagesize - 1;
 
 if (dest_1_page_end == dest_2_page_end) {
 
 
 FLASH_PageErase (0x0F800L);
 
 
 
 wptr = 0x0F800L;
 rptr = dest_1_page_start;
 length = dest - dest_1_page_start;
 FLASH_Copy (wptr, rptr, length);
 
 
 
 wptr = 0x0F800L + dest - dest_1_page_start + numbytes;
 rptr = dest + numbytes;
 length = dest_1_page_end - dest - numbytes + 1;
 FLASH_Copy (wptr, rptr, length);
 
 
 FLASH_PageErase (dest_1_page_start);
 
 
 wptr = dest_1_page_start;
 rptr = 0x0F800L;
 length = FLASH_pagesize;
 FLASH_Copy (wptr, rptr, length);
 
 } else {                             
 
 FLASH_PageErase (0x0F800L);
 
 
 
 
 wptr = 0x0F800L;
 rptr = dest_1_page_start;
 length = dest - dest_1_page_start;
 FLASH_Copy (wptr, rptr, length);
 
 
 FLASH_PageErase (dest_1_page_start);
 
 
 wptr = dest_1_page_start;
 rptr = 0x0F800L;
 length = FLASH_pagesize;
 FLASH_Copy (wptr, rptr, length);
 
 
 
 
 FLASH_PageErase (0x0F800L);
 
 
 
 
 numbytes_remainder = numbytes - (dest_1_page_end - dest + 1);
 wptr = 0x0F800L + numbytes_remainder;
 rptr = dest_2_page_start + numbytes_remainder;
 length = FLASH_pagesize - numbytes_remainder;
 FLASH_Copy (wptr, rptr, length);
 
 
 FLASH_PageErase (dest_2_page_start);
 
 
 wptr = dest_2_page_start;
 rptr = 0x0F800L;
 length = FLASH_pagesize;
 FLASH_Copy (wptr, rptr, length);
 }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void FLASH_Update (FLADDR dest, char *src, unsigned numbytes)
 {
 
 FLASH_Clear (dest, numbytes);
 
 
 FLASH_Write (dest, src, numbytes);
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void FLASH_Write (FLADDR dest, char *src, unsigned numbytes)
 {
 FLADDR i;
 
 for (i = dest; i < dest+numbytes; i++) {
 FLASH_ByteWrite (i, *src++);
 }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 char * FLASH_Read (char *dest, FLADDR src, unsigned numbytes)
 {
 FLADDR i;
 
 for (i = 0; i < numbytes; i++) {
 *dest++ = FLASH_ByteRead (src+i);
 }
 return dest;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void FLASH_Copy (FLADDR dest, FLADDR src, unsigned numbytes)
 {
 FLADDR i;
 
 for (i = 0; i < numbytes; i++) {
 
 FLASH_ByteWrite ((FLADDR) dest+i, FLASH_ByteRead((FLADDR) src+i));
 }
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void FLASH_Fill (FLADDR addr, ULONG length, UCHAR fill)
 {
 FLADDR i;
 
 for (i = 0; i < length; i++) {
 FLASH_ByteWrite (addr+i, fill);
 }
 }
 
 
 
 
