#include "appConfig.h"
/*****************************************************************************/
#define FW_BOOT_ADR_START				0x0000//����������ʼ
#define FW_BOOT_ADR_END					0x0FFF//�����������
#define FW_OTA1_ADR_START				0x1000//Ӧ�ó���1��ʼ��ַ
#define FW_OTA1_ADR_END					0x8000
#define FW_OTA2_ADR_START				0x8000//Ӧ�ó���2��ʼ��ַ
#define FW_OTA2_ADR_END					0xF000
#define BOOT_OTA1						0xA5A5
#define BOOT_OTA2						0x5A5A
#define CMD_STX							'$'//��ʼ��
//#define CMD_FUN0//������
//#define CMD_FUN1
#define CMD_END							'#'//������
#define CMD_RX_BUFFER_SIZE			128
#define CMD_TX_BUFFER_SIZE			128

	//FLASH EEPROM 32BYTE
	//BOOT_CRC 4B | BOOT_VER 4B
	//OTA1_CRC 4B | OTA1_VER 4B 
	//OTA2_CRC 4B | OTA2_VER 4B 
	//HW_VER   4B | NULL	 4B 	
	//SN_H     4B | SN_L     4B
	//NULL     4B | SEL_BOOT 4B
/*****************************************************************************/
void (*BOOT_Program)();//��������ָ��
void (*OTA1_Program)();//Ӧ�ó���1ָ��
void (*OTA2_Program)();//Ӧ�ó���2ָ��
uint8_t CmdRxBuf[CMD_RX_BUFFER_SIZE];
uint8_t CmdTxBuf[CMD_TX_BUFFER_SIZE];
uint8_t FlashEprom[EE_SIZE];//FLASH EPROMģ��
/*****************************************************************************/
//-----------------------------------------------------------------------------
// receive_code
//-----------------------------------------------------------------------------
// This routine receives the new firmware through the UART in HEX record 
// format.
//
// Hex Record Format:
//
// +--------+--------+------+-------+--------+------(n bytes)------+----------+
// | RECORD | RECLEN |    OFFSET    | RECORD |                     | CHECKSUM |
// |  MARK  |  (n)   |   (2 BYTES)  |  TYPE  |        DATA         |          |
// |  ':'   |        |              |        |                     |          |
// +--------+--------+------+-------+--------+------(n bytes)------+----------+
//
//
void receive_code(void)
{
   char xdata* data pwrite;               // pointer used for writing FLASH
   char code* data pread;                 // pointer used for reading FLASH
   unsigned char len;                     // holds the HEX record length field
   unsigned char record_type;             // holds the HEX record type field
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

   // make sure FLASH has been erased
   if(!code_erased){
      printf("\n*** At least one FLASH page must be erased prior");
      printf(" to this operation.\n");
      return;
   } else {

      printf("\nReady to receive...\n");
   }

   // wait for the user send HEX file

   do{
      
      while( c = _getkey() != ':' );      // ignore all characters until 
                                          // reaching the record mark field
      
      // get the record length
      len = hex2char();
      
      // get the starting address (offset field in HEX record)
      offset = hex2char();                // get the MSB
      offset <<= 8;                       
      offset |= hex2char();               // get the LSB

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
           
      // write the record into flash
      for( i = 0; i < len; i++){
         
         // check for valid pointer
         if(pwrite < 0x1000){ 
            *pwrite = hex2char();         // write one byte to FLASH
            pwrite++;                     // increment FLASH write pointer
         } else {
            printf("\n\nExceeded Code Space.\n");  // print error message
         }
      }
      
      PSCTL = 0x00;                       // MOVX writes target XRAM
      FLSCL &= ~0x01;                     // disable FLASH write/erase
      EA = EA_state;                      // restore interrupts to previous state
            
      // verify the checksum
      pread =  (char code*) offset;       // initialize the read pointer
      checksum = hex2char();              // get the HEX record checksum field
      flash_checksum = 0;                 // set the flash_checksum to zero

      // add the data field stored in FLASH to the checksum
      for( i = 0; i < len; i++)
      {
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
         printf("*** Checksum failed, try again");
         return;
      }

   } while(record_type != 1); 
   
   f_valid = TRUE;                        // indicate that download is valid 
   
   printf("\n** Firmware Update Complete. **\n");
}

void main (void) 
{
	data uint32_t bootCrc32, ota1Crc32, ota2Crc32;
	data uint8_t temp, ctemp;
	data uint32_t i, rxCounter;
	uint8_t *pCmdRxBuf, *pWCmdTxBuf
	pCmdRxBuf = CmdRxBuf;
	 = CmdTxBuf;
	while(1)
	{
		ctemp = getkey();
		rxCounter ++;
		if(ctemp == CMD_STX)
		{
			CMD_RX_BUF[i ++] = ctemp;
			
		}
		rxCounter ++;
		
	}
	

	
	SFRPAGE_SWITCH()
	ENABLE_VDDMON()
	DISABLE_WDT()
	SFRPAGE_RESTORE()                       
	//�ȴ����ڷ��͹̼�����ָ��
	if(EEPROM_ReadBlock(0, FlashEprom, EE_SIZE) != EE_NO_ERROR){//��FLASH�ж�ȡOTA MD5ֵ
		while(1);// Error reading EEPROM
	}
	crc32Clear();//CRC32���
	for(i = FW_BOOT_ADR_START;i < FW_BOOT_ADR_END;i ++)
	{//����BOOT CRC32
		FLASH_Read(&temp, i, 1);
		bootCrc32 = crc32CalculateAdd(temp);
	}
	
	for(i = FW_OTA1_ADR_START;i < FW_OTA1_ADR_END;i ++)
	{//����OTA1 CRC32
		FLASH_Read(&temp, i, 1);
		ota1Crc32 = crc32CalculateAdd(temp);
	}
	for(i = FW_OTA2_ADR_START;i < FW_OTA2_ADR_END;i ++)
	{//����OTA2 CRC32
		FLASH_Read(&temp, i, 1);
		ota2Crc32 = crc32CalculateAdd(temp);
	}
	//	//��ȡFEPROM��APP_HW MD5У��ֵ
	if(FlashEprom[20] == BOOT_OTA1)
	{
		if(bootCrc32 == FlashEprom[0] && ota1Crc32 == FlashEprom[8]	)
		{
			OTA1_Program = (void code *) FW_OTA1_ADR_START;//��ȡOTA1��ʼ��ַ
			OTA1_Program();//ִ��Ӧ�ó���
		}
	}
	if(FlashEprom[20] == BOOT_OTA2)
	{
		if(bootCrc32 == FlashEprom[0] && ota2Crc32 == FlashEprom[16]	)
		{
			OTA2_Program = (void code *) FW_OTA2_ADR_START;//��ȡOTA2��ʼ��ַ
			OTA2_Program();//ִ��Ӧ�ó���
		}	
	}
	
	//SFRPAGE_SWITCH()
//	ENABLE_VDDMON()
//	DISABLE_WDT()
//	SFRPAGE_RESTORE()                       
//	if(EEPROM_ReadBlock(0, FLASH_EPROM, EE_SIZE) != EE_NO_ERROR){//��FLASH�ж�ȡOTA MD5ֵ
//		while(1);// Error reading EEPROM
//	}
//	if(FLASH_EPROM[(EE_SIZE - 1)] == BOOT_OTA1)
//	{
//		
//	}
//	else if(FLASH_EPROM[(EE_SIZE - 1)] == BOOT_OTA2)
//	{
//	}
	
//   // Write RAM buffer to EEPROM.
//   if (EEPROM_WriteBlock (0, wBuffer, EE_SIZE) != EE_NO_ERROR)
//   {
//      while(1);      // Error writing EEPROM
//   }

//   // Read EEPROM contents back into RAM 
//   if (EEPROM_ReadBlock(0, rBuffer, EE_SIZE) != EE_NO_ERROR)
//   {
//      while(1);      // Error reading EEPROM
//   }
   while (1){
      //1���ڵȴ����ڷ���������
	  //FLASH_Clear(CONFIG_APP_START_ADR, (CONFIG_APP_END_ADR - CONFIG_APP_START_ADR));
	   //��⵽������
	  //����FLASH
	  //ִ�й̼�����
	  //ִ��Ӧ�ó���
      
 
   }

}

