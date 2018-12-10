//-----------------------------------------------------------------------------
// receive_code
//-----------------------------------------------------------------------------
//
// This routine receives HEX records through the UART and writes the 
// function located at 0x1000.
//
// Hex Record Format:
//
// +--------+--------+------+-------+--------+------(n bytes)------+----------+
// | RECORD | RECLEN |    OFFSET    | RECORD |                     | CHECKSUM |
// |  MARK  |  (n)   |   (2 BYTES)  |  TYPE  |        DATA         |          |
// |  ':'   |        |              |        |                     |          |
// +--------+--------+------+-------+--------+------(n bytes)------+----------+
//
void receive_code(void)
{

   char xdata* data pwrite;               // pointer used for writing FLASH
   char code* data pread;                 // pointer used for reading FLASH
   unsigned int  len;                     // holds the HEX record length field
   char record_type;                      // holds the HEX record type field
   unsigned int offset;                   // holds the HEX record offset field
                                          // this is the starting address of
                                          // the code image contained in the 
                                          // record

   char checksum;                         // holds the HEX record checksum field
   char flash_checksum;                   // holds the checksum calculated after
                                          // the FLASH has been programmed
   bit EA_state;                          // temporary holder used to restore 
                                          // interrupts to their previous state

   char c;                                // temporary char
   int i;                                 // temporary int
   
   // make sure the FLASH page has been erased
   if(!code_erased){
      printf("\n*** At least one FLASH page must be erased prior");
      printf(" to this operation.\n");
      return;
   }
   
   // wait for the user to send HEX file

   do{
      
      while( c = _getkey() != ':' );      // ignore all characters until  
                                          // reaching the record mark field
      
      // get the record length
      len = hex2char();
      
      // get the starting address (offset field in HEX record)
      offset = hex2char();
      offset <<= 8;
      offset |= hex2char();

      // get the record type
      record_type = hex2char();
      if( record_type != 0 && record_type != 1 ){
         printf("\n*** Cannot decode HEX file.\n"); 
         return;
      }      
      
      EA_state = EA;                      // save the interrupt enable bit state
      
      EA = 0;                             // disable interrupts (precautionary)   
      FLSCL |= 0x01;                      // enable FLASH write/erase
      PSCTL  = 0x01;                      // MOVX writes FLASH
   
      pwrite = (char xdata*) offset;      // initialize the write pointer
            
      code_erased = FALSE;                // clear the code_erased flag
           
      // write the record into FLASH
      for( i = 0; i < len; i++){
         *pwrite = hex2char();            // write one byte to FLASH
         pwrite++;                        // increment FLASH write pointer
         
      }
      
      PSCTL = 0x00;                       // MOVX writes target XRAM
      FLSCL &= ~0x01;                     // disable FLASH write/erase
      EA = EA_state;                      // restore interrupts to previous state
      
      // verify the checksum
      pread =  (char code*) offset;       // initialize the read pointer
      checksum = hex2char();              // get the HEX record checksum field
      flash_checksum = 0;                 // set the flash_checksum to zero
      
      // add the data field stored in FLASH to the checksum
      for( i = 0; i < len; i++){
         flash_checksum += *pread++;
      } 
      
      // add the remaining fields
      flash_checksum += len;
      flash_checksum += (char) (offset >> 8);
      flash_checksum += (char) (offset & 0x00FF);
      flash_checksum += record_type;
      flash_checksum += checksum;
      
      // verify the checksum (the flash_checksum should equal zero)
      if(flash_checksum != 0){
         printf("*** Checksum failed, try again.");
         return;
      }
      
   } while(record_type != 1); 
  
   f_valid = TRUE;                     // flag that the "f()" function is valid
   
   _getkey();                          // remove carriage return from input
                                       // stream   

   printf("\nReceived OK\n");  
}