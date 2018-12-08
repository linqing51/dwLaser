#include "appConfig.h"
/*****************************************************************************/
#define CMD_STX								0x81
#define CMD_END								0x91
#define CMD_SET_HW_VER						0x30
#define CMD_GET_HW_VER						0x31
#define CMD_RESET_MCU						0x32
#define CMD_GET_BOOTLOADER_VER				0x33
#define CMD_GET_OTA1_VER					0x34
#define CMD_GET_OTA2_VER					0x35
#define CMD_SET_BOOTLOADER_VER				0x33
#define CMD_SET_OTA1_VER					0x34
#define CMD_SET_OTA2_VER					0x35
#define CMD_GET_BOOT_CRC					0x36
#define CMD_GET_OTA1_CRC					0x36
#define CMD_GET_OTA2_CRC					0x36
#define CMD_ERASE_FLASH_PAGE
#define CMD_WRITE_FLASH_BYTES
#define CMD_READ_FLASH_BYTES
#define CMD_GOTO_OTA1
#define CMD_GOTO_OTA2
#define CMD_GET_HW_VER_TX_SZ				3
#define CMD_GET_HW_VER_RX_SZ 				6
#define CMD_SET_HW_VER_TX_SZ				7
#define CMD_SET_HW_VER_RX_SZ				3
#define CMD_RESPOND_OK 						0xFF
#define CMD_RESPOND_FAIL					0x00
/*****************************************************************************/
#define FW_BOOT_ADR_START				0x0000//����������ʼ
#define FW_BOOT_ADR_END					0x0FFF//�����������
#define FW_OTA1_ADR_START				0x1000//Ӧ�ó���1��ʼ��ַ
#define FW_OTA1_ADR_END					0x8000
#define FW_OTA2_ADR_START				0x8000//Ӧ�ó���2��ʼ��ַ
#define FW_OTA2_ADR_END					0xF000
#define BOOT_LOADER						0x5555
#define BOOT_OTA1						0xA5A5
#define BOOT_OTA2						0x5A5A
/*****************************************************************************/
#define CMD_RX_BUFFER_SIZE				2048
#define CMD_TX_BUFFER_SIZE				1024
/*****************************************************************************/
#define EPROM_BOOT_CRC				0
#define EPROM_OTA1_CRC				4
#define EPROM_OTA2_CRC				8
#define EPROM_BOOT_VER				12
#define EPROM_OTA1_VER				13
#define EPROM_OTA2_VER				14
#define EPROM_HW_VER				15
#define EPROM_OTA1_START			16
#define EPROM_OTA1_END				20
#define EPROM_OTA2_START			24
#define EPROM_OTA2_END				28
#define EPROM_BOOT_ORDER			32


/*****************************************************************************/
void (*BOOT_Program)();//��������ָ��
void (*OTA1_Program)();//Ӧ�ó���1ָ��
void (*OTA2_Program)();//Ӧ�ó���2ָ��
void bootSequence(void);
uint32_t bootFlashCrc(void);
uint32_t ota1FlashCrc(void);
uint32_t ota2FlashCrc(void);
uint8_t CmdRxBuf[CMD_RX_BUFFER_SIZE];
uint8_t CmdTxBuf[CMD_TX_BUFFER_SIZE];
uint8_t FlashEprom[EE_SIZE];//FLASH EPROMģ��
/*****************************************************************************/
static void uint32ToAscii(uint32_t *dat, uint8_t *pstr){//��32λ�з�����ת��Ϊ8��ASCII�ַ�
	data uint8_t temp;	
	temp = *dat & 0xF;//0x0000000A
	if(temp <= 0x09){
		*(pstr + 0) = (temp + 0x30);
    }
    else{
		 *(pstr + 0) = (temp + 0x37);
    }
	
	temp = (*dat >> 4) & 0xF;//0x000000A0
	if(temp <= 0x09){
		*(pstr + 1) = (temp + 0x30);
    }
    else{
		 *(pstr + 1) = (temp + 0x37);
    }
	
	temp = (*dat >> 8) & 0xF;//0x00000A00
	if(temp <= 0x09){
		*(pstr + 2) = (temp + 0x30);
    }
    else{
		 *(pstr + 2) = (temp + 0x37);
    }
	
	temp = (*dat >> 12) & 0xF;//0x0000A000
	if(temp <= 0x09){
		*pstr = (temp + 0x30);
    }
    else{
		*pstr = (temp + 0x37);
    }
	
	temp = (*dat >> 16) & 0xF;//0x000A0000
	if(temp <= 0x09){
		*(pstr + 4) = (temp + 0x30);
    }
    else{
		 *(pstr + 4) = (temp + 0x37);
    }

	temp = (*dat >> 20) & 0xF;//0x00A00000
	if(temp <= 0x09){
		*(pstr + 5) = (temp + 0x30);
    }
    else{
		 *(pstr + 5) = (temp + 0x37);
    }
	
	temp = (*dat >> 24) & 0xF;//0x0A000000
	if(temp <= 0x09){
		*(pstr + 6) = (temp + 0x30);
    }
    else{
		 *(pstr + 6) = (temp + 0x37);
    }
	
	temp = (*dat >> 28) & 0xF;//0x00A00000
	if(temp <= 0x09){
		*(pstr + 7) = (temp + 0x30);
    }
    else{
		 *(pstr + 7) = (temp + 0x37);
    }
}
static uint32_t asciiToUint32(uint8_t *pstr){//��8��BCD��ϳ�һ��32������
	data uint8_t temp[8];
	data uint32_t hex;
	//ȡ��0x0000000A
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[0] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[0] = *pstr - 0x30;	
	}
	//ȡ��0x000000A0
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[1] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[1] = *(pstr + 1) - 0x30;	
	}
	//ȡ��0x00000A00
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[2] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[2] = *pstr - 0x30;	
	}
	//ȡ��0x0000A000
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[3] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[3] = *(pstr + 1) - 0x30;	
	}
	
	//ȡ��0x0000A000
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[4] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[4] = *pstr - 0x30;	
	}
	//ȡ��0x00000A00
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[5] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[5] = *(pstr + 1) - 0x30;	
	}
	//ȡ��0x000000A0
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[6] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[6] = *pstr - 0x30;	
	}
	//ȡ��0x0000000A
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[7] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[7] = *(pstr + 1) - 0x30;	
	}
	hex = 0;
	hex |= (temp[0] & 0x0000000F);
	hex |= (((temp[1] & 0x0F) << 4) & 0x000000F0);
	hex |= (((temp[2] & 0x0F) << 8) & 0x00000F00);
	hex |= (((temp[3] & 0x0F) << 12) & 0x0000F000);
	hex |= (((temp[4] & 0x0F) << 16) & 0x000F0000);
	hex |= (((temp[5] & 0x0F) << 20) & 0x00F00000);
	hex |= (((temp[6] & 0x0F) << 24) & 0x00F00000);
	hex |= (((temp[7] & 0x0F) << 28) & 0x00F00000);
	return hex;
}
static void uint16ToAscii(uint16_t *dat, uint8_t *pstr){//��16λ�з�����ת��Ϊ4��ASCII�ַ�
	data uint8_t temp;
	temp = *dat & 0x000F;//0x000A
	if(temp <= 0x09){
		*(pstr + 0) = (temp + 0x30);
    }
    else{
		 *(pstr + 0) = (temp + 0x37);
    }
	temp = (*dat >> 4) & 0x000F;//0x00A0
	if(temp <= 0x09){
		*(pstr + 1) = (temp + 0x30);
    }
    else{
		 *(pstr + 1) = (temp + 0x37);
    }
	temp = (*dat >> 8) & 0x000F;//0x0A00
	if(temp <= 0x09){
		*(pstr + 2) = (temp + 0x30);
    }
    else{
		 *(pstr + 2) = (temp + 0x37);
    }
	temp = (*dat >> 12) & 0x000F;//0xA000
	if(temp <= 0x09){
		*(pstr + 3) = (temp + 0x30);
    }
    else{
		*(pstr + 3) = (temp + 0x37);
    }
}
static void uint8ToAscii(uint8_t *dat, uint8_t *pstr){//��16������ת��������ASCII�ַ�
	data uint8_t temp;
	temp = (*dat & 0x0f);
	if(temp <= 0x09){
		*(pstr + 1) = (temp + 0x30);
    }
    else{
		 *(pstr + 1) = (temp + 0x37);
    }
	temp = ((*dat & 0xf0) >> 4);
	if(temp <= 0x09){
		*pstr = (temp + 0x30);
	}
	else{
		*pstr = (temp + 0x37);
	}
}
static uint8_t asciiToUint8(uint8_t *pstr){//������int8_t ��ϳ�һ��16������
	data uint8_t temp[2];
	data uint8_t hex;
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[1] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[1] = *pstr - 0x30;	
	}
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[0] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[0] = *(pstr + 1) - 0x30;	
	}
	hex = 0;
	hex |= temp[0] & 0xF;
	hex |= (temp[1] & 0x0F << 4) & 0xF0;
	return hex;
}

static uint16_t asciiToUint16(uint8_t *pstr){
	data uint8_t temp[4];
	data uint16_t hex;
	//ȡ��0xA000
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[3] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[3] = *pstr - 0x30;	
	}
	//ȡ��0x0A00
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[2] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[2] = *(pstr + 1) - 0x30;	
	}
	//ȡ��0x00A0
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[1] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[1] = *pstr - 0x30;	
	}
	//ȡ��0x000A
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[0] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[0] = *(pstr + 1) - 0x30;	
	}
	hex = 0;
	hex |= temp[0] & 0x000F;
	hex |= ((temp[1] & 0x0F) << 4) & 0x00F0;
	hex |= ((temp[2] & 0x0F) << 8) & 0x0F00;
	hex |= ((temp[3] & 0x0F) << 12) & 0xF000;
	return hex;
}
static uint8_t LRC(uint8_t *buf, int32_t len){//����LRC LRC�����ǽ���Ϣ�е�8Bit���ֽ������ۼӣ������˽�λ
	int i;
	uint8_t lrc = 0;        /*lrc�ֽڳ�ʼ��*/
	for( i = 0; i < len; i++ ){
		lrc = lrc + buf[i];
	}
	return lrc;
}
void uart0Send(uint8_t *buf, uint16_t count){//����0��ѯ����
	uint8_t *ptr = buf;
	do{
	    SBUF0 = *ptr++;
		while(TI0 == 0);
		TI0 = 0;
	}while(--count);
}
void uart0Receive(uint8_t *buf, uint16_t count){//����0��ѯ����
	uint8_t * ptr = buf;
	do{
		if(RI0 == 1)
		{
			*ptr++ = SBUF0;
			RI0 = 0;
			count--;
		}
	}while(count);
}
void CmdSetHwVer(void){//����Ӳ���汾
	FlashEprom[EPROM_HW_VER] = asciiToUint8(CmdRxBuf + 2);
	if(EEPROM_WriteBlock(EPROM_HW_VER, FlashEprom, 1) != EE_NO_ERROR){//��FLASH�ж�ȡOTA MD5ֵ
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_HW_VER;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_END;	
	}
	else{
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_HW_VER;
		CmdTxBuf[2] = CMD_RESPOND_OK;
		CmdTxBuf[3] = CMD_END;
	}
	uart0Send(CmdTxBuf, 4);
}
void CmdGetHwVer(void){//��ȡӲ���汾
	CmdTxBuf[0] = CMD_STX;
	CmdTxBuf[1] = CMD_SET_HW_VER;
	CmdTxBuf[2] = FlashEprom[EPROM_HW_VER];
	CmdTxBuf[3] = CMD_END;
	uart0Send(CmdTxBuf, 4);
}
void CmdResetMcu(void){//ǿ�Ƹ�λ
	RSTSRC |= (1 << 4);
}
void CmdGetBootLoaderVer(void){//��ȡBOOTLOADER�汾
	CmdTxBuf[0] = CMD_STX;
	CmdTxBuf[1] = CMD_GET_BOOTLOADER_VER;
	CmdTxBuf[2] = FlashEprom[EPROM_BOOT_VER];
	CmdTxBuf[3] = CMD_END;	
	uart0Send(CmdTxBuf, 4);
}
void CmdSetBootLoaderVer(void){//����Bootloader�汾��
	FlashEprom[EPROM_BOOT_VER] = asciiToUint8(CmdRxBuf + 2);
	if(EEPROM_WriteBlock(EPROM_HW_VER, FlashEprom, 1) != EE_NO_ERROR){//��FLASH�ж�ȡOTA MD5ֵ
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = EPROM_BOOT_VER;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_END;	
	}
	else{
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = EPROM_BOOT_VER;
		CmdTxBuf[2] = CMD_RESPOND_OK;
		CmdTxBuf[3] = CMD_END;
	}
	uart0Send(CmdTxBuf, 4);
}

void CmdGetOTA1Ver(void){//��ȡOTA1�汾��
	CmdTxBuf[0] = CMD_STX;
	CmdTxBuf[1] = CMD_GET_OTA1_VER;
	CmdTxBuf[2] = FlashEprom[EPROM_OTA1_VER];
	CmdTxBuf[3] = CMD_END;	
	uart0Send(CmdTxBuf, 4);
}
void CmdSetOTA1Ver(void){//����OTA1�汾��
	FlashEprom[EPROM_OTA1_VER] = asciiToUint8(CmdRxBuf + 2);
	if(EEPROM_WriteBlock(EPROM_OTA1_VER, FlashEprom, 1) != EE_NO_ERROR){//��FLASH�ж�ȡOTA MD5ֵ
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_OTA1_VER;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_END;	
	}
	else{
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_OTA1_VER;
		CmdTxBuf[2] = CMD_RESPOND_OK;
		CmdTxBuf[3] = CMD_END;
	}
	uart0Send(CmdTxBuf, 4);
}
void CmdGetOTA2Ver(void){//��ȡOTA2�汾��
	CmdTxBuf[0] = CMD_STX;
	CmdTxBuf[1] = CMD_GET_OTA2_VER;
	CmdTxBuf[2] = FlashEprom[EPROM_OTA2_VER];
	CmdTxBuf[3] = CMD_END;	
	uart0Send(CmdTxBuf, 4);
}
void CmdGetBootCrc(void){//��ȡBOOT CRC
	CmdTxBuf[0] = CMD_STX;
	CmdTxBuf[1] = CMD_GET_BOOT_CRC;
	CmdTxBuf[2] = FlashEprom[EPROM_BOOT_CRC];
	CmdTxBuf[3] = CMD_END;	
	uart0Send(CmdTxBuf, 4);
}
void CmdGetOTA1Crc(void){//��ȡOTA1 CRC
	CmdTxBuf[0] = CMD_STX;
	CmdTxBuf[1] = CMD_GET_OTA1_CRC;
	CmdTxBuf[2] = FlashEprom[EPROM_OTA1_CRC];
	CmdTxBuf[3] = CMD_END;	
	uart0Send(CmdTxBuf, 4);
}
void CmdGetOTA2Crc(void){//��ȡOTA2 CRC
	CmdTxBuf[0] = CMD_STX;
	CmdTxBuf[1] = CMD_GET_OTA2_CRC;
	CmdTxBuf[2] = FlashEprom[EPROM_OTA2_CRC];
	CmdTxBuf[3] = CMD_END;	
	uart0Send(CmdTxBuf, 4);
}
void CmdEraseFlashPage(void){//���FLASHָ��ҳ
	uint8_t page;
	page = asciiToUint8(CmdRxBuf + 2);
	//����page��Χ
	EE_FLASH_WriteErase (page, 0, 0x13);
}
CMD_ERASE_FLASH_PAGE
void cmdPoll(void){
	uint16_t i;
	uint8_t *ptr, *ptw;
	while(1){
		ptr = CmdRxBuf;
		uart0Receive(ptr, 1);
		if(*ptr == CMD_STX){
			ptr ++;
			do{
				uart0Receive(ptr, 1);
				if(*ptr == CMD_END){
					switch(CmdRxBuf[1])
					{
						case CMD_SET_HW_VER:
							CmdSetHwVer();
							break;
						case CMD_GET_HW_VER:
							break;
						case CMD_RESET_MCU:
							break;
						case CMD_GET_BOOTLOADER_VER:
							break;
						case CMD_GET_OTA1_VER:
							break;
						case CMD_GET_OTA2_VER:
							break;
						case CMD_GET_OTA1_CRC:
							break;
						default:break;
					}
					break;
				}
				else if(ptr >= (CmdRxBuf + CMD_RX_BUFFER_SIZE)){
					break;
				}
			}while(1);
		}
	}
}
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
//void receive_code(void)
//{
//   char xdata* data pwrite;               // pointer used for writing FLASH
//   char code* data pread;                 // pointer used for reading FLASH
//   unsigned char len;                     // holds the HEX record length field
//   unsigned char record_type;             // holds the HEX record type field
//   unsigned int offset;                   // holds the HEX record offset field
//                                          // this is the starting address of
//                                          // the code image contained in the 
//                                          // record

//   char checksum;                         // holds the HEX record checksum field
//   char flash_checksum;                   // holds the checksum calculated after
//                                          // the FLASH has been programmed
//   bit EA_state;                          // temporary holder used to restore 
//                                          // interrupts to their previous state

//   char c;                                // temporary char
//   int i;                                 // temporary int

//   // make sure FLASH has been erased
//   if(!code_erased){
//      printf("\n*** At least one FLASH page must be erased prior");
//      printf(" to this operation.\n");
//      return;
//   } else {

//      printf("\nReady to receive...\n");
//   }

//   // wait for the user send HEX file

//   do{
//      
//      while( c = _getkey() != ':' );      // ignore all characters until 
//                                          // reaching the record mark field
//      
//      // get the record length
//      len = hex2char();
//      
//      // get the starting address (offset field in HEX record)
//      offset = hex2char();                // get the MSB
//      offset <<= 8;                       
//      offset |= hex2char();               // get the LSB

//      // get the record type
//      record_type = hex2char();
//      if( record_type != 0 && record_type != 1 ){
//         printf("\n*** Cannot decode HEX file.\n"); 
//         return;
//      }      

//      EA_state = EA;                      // save the interrupt enable bit state
//      
//      EA = 0;                             // disable interrupts (precautionary)   
//      FLSCL |= 0x01;                      // enable FLASH write/erase
//      PSCTL  = 0x01;                      // MOVX writes FLASH

//      pwrite = (char xdata*) offset;      // initialize the write pointer
//      
//      
//      code_erased = FALSE;                // clear the code_erased flag      
//           
//      // write the record into flash
//      for( i = 0; i < len; i++){
//         
//         // check for valid pointer
//         if(pwrite < 0x1000){ 
//            *pwrite = hex2char();         // write one byte to FLASH
//            pwrite++;                     // increment FLASH write pointer
//         } else {
//            printf("\n\nExceeded Code Space.\n");  // print error message
//         }
//      }
//      
//      PSCTL = 0x00;                       // MOVX writes target XRAM
//      FLSCL &= ~0x01;                     // disable FLASH write/erase
//      EA = EA_state;                      // restore interrupts to previous state
//            
//      // verify the checksum
//      pread =  (char code*) offset;       // initialize the read pointer
//      checksum = hex2char();              // get the HEX record checksum field
//      flash_checksum = 0;                 // set the flash_checksum to zero

//      // add the data field stored in FLASH to the checksum
//      for( i = 0; i < len; i++)
//      {
//         flash_checksum += *pread++;
//      } 
//      
//      // add the remaining fields
//      flash_checksum += len;
//      flash_checksum += (char) (offset >> 8);
//      flash_checksum += (char) (offset & 0x00FF);
//      flash_checksum += record_type;
//      flash_checksum += checksum;
//      
//      // verify the checksum (the flash_checksum should equal zero)     
//      if(flash_checksum != 0){
//         printf("*** Checksum failed, try again");
//         return;
//      }

//   } while(record_type != 1); 
//   
//   f_valid = TRUE;                        // indicate that download is valid 
//   
//   printf("\n** Firmware Update Complete. **\n");
//}

void bootSequence(void)
{//����˳��ѡ��
	data uint32_t ota1Crc32, ota2Crc32;
	if(FlashEprom[20] == BOOT_OTA1){//����˳��ѡ��BOOT_OTA1
		ota1Crc32 = ota1FlashCrc();
		if(ota1Crc32 == FlashEprom[EPROM_OTA1_CRC])
		{
			OTA1_Program = (void code *)(FW_OTA1_ADR_START & 0x1FFFF);//��ȡOTA1��ʼ��ַ
			OTA1_Program();//ִ��Ӧ�ó���
		}
	}
	else if(FlashEprom[20] == BOOT_OTA2){//����˳��ѡ��BOOT_OTA2
		if(ota2Crc32 == FlashEprom[EPROM_OTA2_CRC]){
			OTA2_Program = (void code *)(FW_OTA2_ADR_START & 0x1FFFF);//��ȡOTA2��ʼ��ַ
			OTA2_Program();//ִ��Ӧ�ó���
		}	
	}
	else if(FlashEprom[20] == BOOT_LOADER){
	}
}
uint32_t bootFlashCrc(void)
{//BOOT CRC32У��	
	data uint32_t crc = 0, i;
	data uint8_t temp;
	
	crc32Clear();//CRC32���
	for(i = FW_BOOT_ADR_START;i < FW_BOOT_ADR_END;i ++)
	{//����BOOT CRC32
		FLASH_Read(&temp, i, 1);
		crc = crc32CalculateAdd(temp);
	}
	return crc;
}
uint32_t ota1FlashCrc(void)
{//OTA1 CRC32У��
	data uint32_t crc = 0 ,i;
	data uint8_t temp;
	crc32Clear();//CRC32���
	for(i = FW_OTA1_ADR_START;i < FW_OTA1_ADR_END;i ++)
	{//����OTA1 CRC32
		FLASH_Read(&temp, i, 1);
		crc = crc32CalculateAdd(temp);
	}
	return crc;
}
uint32_t ota2FlashCrc(void)
{//OTA2 CRC32У��
	data uint32_t crc = 0, i;
	data uint8_t temp;
	for(i = FW_OTA2_ADR_START;i < FW_OTA2_ADR_END;i ++)
	{//����OTA2 CRC32
		FLASH_Read(&temp, i, 1);
		crc = crc32CalculateAdd(temp);
	}
	return crc;
}

void main (void) 
{
	data uint32_t bootCrc32, ota1Crc32, ota2Crc32;
	data uint8_t temp, ctemp;
	data uint32_t i, rxCounter;
	
	cmdPoll();
	

	
//	SFRPAGE_SWITCH()
//	ENABLE_VDDMON()
//	DISABLE_WDT()
//	SFRPAGE_RESTORE()                       
//	//�ȴ����ڷ��͹̼�����ָ��
//	
//	if(EEPROM_ReadBlock(0, FlashEprom, EE_SIZE) != EE_NO_ERROR){//��FLASH�ж�ȡOTA MD5ֵ
//		while(1);// Error reading EEPROM
//	}	
	


   while (1){
      //1���ڵȴ����ڷ���������
	  //FLASH_Clear(CONFIG_APP_START_ADR, (CONFIG_APP_END_ADR - CONFIG_APP_START_ADR));
	   //��⵽������
	  //����FLASH
	  //ִ�й̼�����
	  //ִ��Ӧ�ó���
      
 
   }

}
