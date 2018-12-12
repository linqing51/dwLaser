#include "appConfig.h"
/*****************************************************************************/
#define CONFIG_DEBUG						1
#define CMD_STX								0x24//$
#define CMD_END								0x25//%
#define CMD_SET_HW_VER						0x31//1
#define CMD_GET_HW_VER						0x32//2
#define CMD_RESET_MCU						0x33//3
#define CMD_GET_BOOTLOADER_VER				0x34//4
#define CMD_GET_OTA1_VER					0x35//5
#define CMD_GET_OTA2_VER					0x36//6
#define CMD_SET_BOOTLOADER_VER				0x37//7
#define CMD_SET_OTA1_VER					0x38//8
#define CMD_SET_OTA2_VER					0x39//9
#define CMD_GET_BOOT_CRC					0x41//A
#define CMD_GET_OTA1_CRC					0x42//B
#define CMD_GET_OTA2_CRC					0x43//C
#define CMD_WRITE_FLASH_PAGE				0x44//D д��FLASH PAGE
#define CMD_READ_FLASH_PAGE					0x45//E ��ȡFLASH PAGE
#define CMD_CLEAR_FLASH_PAGE				0x46//F	���FLASH PAGE
#define CMD_GOTO_OTA1						0x47//G
#define CMD_GOTO_OTA2						0x48//H
#define CMD_UPDATE_OTA1_CRC					0x49//I
#define CMD_UPDATE_OTA2_CRC					0x4A//J
#define CMD_RESPOND_OK 						0x31
#define CMD_RESPOND_FAIL					0x30
/*****************************************************************************/
#define BOOT_SELECT_OTA						0x5A
#define BOOT_SELECT_LOADER					0xA5
#define BOOT_SELECT_TIMEOUT					1000000UL
/*****************************************************************************/
#define FW_BOOT_ADR_START					0x0000//����������ʼ
#define FW_BOOT_ADR_END						0x1FFF//�����������
#define FW_OTA1_ADR_START					0x2000//Ӧ�ó���1��ʼ��ַ
#define FW_OTA1_ADR_END						0x7FFF
#define FW_OTA2_ADR_START					0x8000//Ӧ�ó���2��ʼ��ַ
#define FW_OTA2_ADR_END						0xEFFF
/*****************************************************************************/
#define SELECT_BOOT_LOADER					0x5555
#define SELECT_BOOT_OTA1                 	0xA5A5
#define SELECT_BOOT_OTA2					0x5A5A
/*****************************************************************************/
#define CMD_RX_BUFFER_SIZE					1100
#define CMD_TX_BUFFER_SIZE					1100
/*****************************************************************************/
#define EPROM_BOOT_CRC						0
#define EPROM_OTA1_CRC						4
#define EPROM_OTA2_CRC						8
#define EPROM_BOOT_VER						12
#define EPROM_OTA1_VER						13
#define EPROM_OTA2_VER						14
#define EPROM_HW_VER						15
#define EPROM_OTA1_START					16
#define EPROM_OTA1_END						20
#define EPROM_OTA2_START					24
#define EPROM_OTA2_END						28
#define EPROM_BOOT_ORDER					32
/*****************************************************************************/
void (*CmdGotoOTA1)();//Ӧ�ó���1ָ��
void (*CmdGotoOTA2)();//Ӧ�ó���2ָ��
void bootSequence(void);
SEG_XDATA uint8_t CmdRxBuf[CMD_RX_BUFFER_SIZE];
SEG_XDATA uint8_t CmdTxBuf[CMD_TX_BUFFER_SIZE];
SEG_XDATA uint8_t TempBuf[FL_PAGE_SIZE];//��ʱ������
SEG_XDATA uint8_t FlashEprom[EE_SIZE];//FLASH EPROMģ��
/*****************************************************************************/
static void uint32ToAscii(uint32_t *dat, uint8_t *pstr){//��32λ�з�����ת��Ϊ8��ASCII�ַ�
	SEG_DATA uint8_t temp;	
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
	SEG_DATA uint8_t temp[8];
	SEG_DATA uint32_t hex;
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
	SEG_DATA uint8_t temp;
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
	SEG_DATA uint8_t temp;
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
	SEG_DATA uint8_t temp[2];
	SEG_DATA uint8_t hex;
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[0] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[0] = *pstr - 0x30;	
	}
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[1] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[1] = *(pstr + 1) - 0x30;	
	}
	hex = 0;
	hex |= temp[1] & 0xF;
	hex |= ((temp[0] << 4) & 0xF0);
	return hex;
}

static uint16_t asciiToUint16(uint8_t *pstr){
	SEG_DATA uint8_t temp[4];
	SEG_DATA uint16_t hex;
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
static uint8_t LRC(uint8_t *buf, uint32_t len){//����LRC LRC�����ǽ���Ϣ�е�8Bit���ֽ������ۼӣ������˽�λ
	SEG_DATA uint32_t i;
	SEG_DATA uint8_t lrc = 0;        /*lrc�ֽڳ�ʼ��*/
	for( i = 0; i < len; i++ ){
		lrc = lrc + buf[i];
	}
	return lrc;
}
void uart0Send(uint8_t *buf, uint16_t count){//����0��ѯ����
	SEG_DATA uint8_t *ptr = buf;
	do{
	    SBUF0 = *ptr++;
		while(TI0 == 0);
		TI0 = 0;
	}while(--count);
}
void uart0Receive(uint8_t *buf, uint16_t count){//����0��ѯ����
	SEG_DATA uint8_t * ptr = buf;
	do{
		if(RI0 == 1)
		{
			*ptr++ = SBUF0;
			RI0 = 0;
			count--;
		}
	}while(count);
}
uint8_t uart0ReceiveBootOrder(void){//����0��ѯ���մ���ʱ
	SEG_DATA uint8_t temp;
	SEG_DATA uint32_t timeOutCounter;
#if CONFIG_DEBUG == 1
	printf("Bootloader->Debug:Input 'C' Into Loader Mode\n");
#endif
	timeOutCounter = 0;
	do{
		if(RI0 == 1){
			temp = SBUF0;
			RI0 = 0;
			if(temp == 'c')
			{
#if CONFIG_DEBUG == 1
				printf("Bootloader->Debug:BOOT_SELECT_LOADER\n");
#endif
				return BOOT_SELECT_LOADER;
			}
		}
		timeOutCounter ++;
	}while(timeOutCounter <= BOOT_SELECT_TIMEOUT);
#if CONFIG_DEBUG == 1
	printf("Bootloader->Debug:BOOT_SELECT_OTA\n");
#endif
	return BOOT_SELECT_OTA;
}
uint32_t bootFlashCrc(void){//BOOT CRC32У��	
	SEG_DATA uint32_t crc = 0, i;
	SEG_DATA uint8_t temp;
	crc32Clear();//CRC32���
	for(i = FW_BOOT_ADR_START;i < FW_BOOT_ADR_END;i ++)
	{//����BOOT CRC32
		FLASH_Read(&temp, i, 1);
		crc = crc32CalculateAdd(temp);
	}
	return crc;
}
uint32_t ota1FlashCrc(void){//OTA1 CRC32У��
	SEG_DATA uint32_t crc = 0 ,i;
	SEG_DATA uint8_t temp;
	crc32Clear();//CRC32���
	for(i = FW_OTA1_ADR_START;i < FW_OTA1_ADR_END;i ++)
	{//����OTA1 CRC32
		FLASH_Read(&temp, i, 1);
		crc = crc32CalculateAdd(temp);
	}
	return crc;
}
uint32_t ota2FlashCrc(void){//OTA2 CRC32У��
	SEG_DATA uint32_t crc = 0, i;
	SEG_DATA uint8_t temp;
	for(i = FW_OTA2_ADR_START;i < FW_OTA2_ADR_END;i ++)
	{//����OTA2 CRC32
		FLASH_Read(&temp, i, 1);
		crc = crc32CalculateAdd(temp);
	}
	return crc;
}
void CmdSetHwVer(void){//����Ӳ���汾
	FlashEprom[EPROM_HW_VER] = asciiToUint8(CmdRxBuf + 2);
#if CONFIG_DEBUG == 1
	printf("Bootloader->Debug->CMD_SET_HW_VER:%2X\n", (uint16_t)(FlashEprom[EPROM_HW_VER]));
#endif
	if(EEPROM_WriteBlock(EPROM_HW_VER, FlashEprom, 1) != EE_NO_ERROR){//��FLASH�ж�ȡOTA MD5ֵ
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_HW_VER;
		CmdTxBuf[2] = CMD_RESPOND_OK;
		CmdTxBuf[3] = CMD_END;	
	}
	else{
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_HW_VER;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_END;
	}
	uart0Send(CmdTxBuf, 4);
}
void CmdGetHwVer(void){//��ȡӲ���汾
	SEG_DATA uint8_t ctemp[2];
	uint8ToAscii((FlashEprom + EPROM_HW_VER), ctemp);
	if(EEPROM_ReadBlock(EPROM_HW_VER, FlashEprom, 1) != EE_NO_ERROR){
#if CONFIG_DEBUG == 1
	printf("Bootloader->Debug->CMD_GET_HW_VER:%2X\n", (uint16_t)(FlashEprom[EPROM_HW_VER]));
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_GET_HW_VER;
		CmdTxBuf[2] = ctemp[0];
		CmdTxBuf[3] = ctemp[1];
		CmdTxBuf[4] = CMD_END;
	}
	else
	{
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_GET_HW_VER->EPROM READ Fail\n");
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_GET_HW_VER;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_RESPOND_FAIL;
		CmdTxBuf[4] = CMD_END;
	}
	uart0Send(CmdTxBuf, 5);	
}
void CmdResetMcu(void){//ǿ�Ƹ�λ
#if CONFIG_DEBUG == 1
	printf("Bootloader->Debug->CMD_RESET_MCU\n");
#endif
	RSTSRC |= (1 << 4);
}
void CmdGetBootLoaderVer(void){//��ȡBOOTLOADER�汾
	SEG_DATA uint8_t ctemp[2];
	if(EEPROM_ReadBlock(EPROM_BOOT_VER, FlashEprom, 1) != EE_NO_ERROR){
		uint8ToAscii((FlashEprom + EPROM_BOOT_VER), ctemp);
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_GET_BOOT_VER:%2X\n", (uint16_t)FlashEprom[EPROM_BOOT_VER]);
#endif	
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_GET_BOOTLOADER_VER;
		CmdTxBuf[2] = ctemp[0];
		CmdTxBuf[3] = ctemp[1];
		CmdTxBuf[4] = CMD_END;	
	}
	else{
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_GET_BOOT_VER:EPROM Read Fail\n");
#endif		
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_GET_BOOTLOADER_VER;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_RESPOND_FAIL;
		CmdTxBuf[4] = CMD_END;	
	}
	uart0Send(CmdTxBuf, 5);	
}
void CmdSetBootLoaderVer(void){//����Bootloader�汾��
	FlashEprom[EPROM_BOOT_VER] = asciiToUint8(CmdRxBuf + 2);
	if(EEPROM_WriteBlock(EPROM_HW_VER, FlashEprom, 1) != EE_NO_ERROR){//��FLASH�ж�ȡOTA MD5ֵ
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_SET_BOOT_VER:%2X\n", (uint16_t)FlashEprom[EPROM_BOOT_VER]);
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_BOOTLOADER_VER;
		CmdTxBuf[2] = CMD_RESPOND_OK;
		CmdTxBuf[3] = CMD_END;	
	}
	else{
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_SET_BOOT_VER:EPROM Write Fail\n");
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_BOOTLOADER_VER;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_END;
	}
	uart0Send(CmdTxBuf, 4);
}
void CmdGetOTA1Ver(void){//��ȡOTA1�汾��
	SEG_DATA uint8_t ctemp[2];
	if(EEPROM_ReadBlock(EPROM_OTA1_VER, FlashEprom, 1) != EE_NO_ERROR){
		uint8ToAscii((FlashEprom + EPROM_OTA1_VER), ctemp);
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_GET_OTA1_VER:%2X\n", (uint16_t)FlashEprom[EPROM_OTA1_VER]);
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_GET_OTA1_VER;
		CmdTxBuf[2] = ctemp[0];
		CmdTxBuf[3] = ctemp[1];
		CmdTxBuf[4] = CMD_END;		
	}
	else{
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_GET_OTA1_VER;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_RESPOND_FAIL;
		CmdTxBuf[4] = CMD_END;
	}	
	uart0Send(CmdTxBuf, 5);
}
void CmdSetOTA1Ver(void){//����OTA1�汾��
	FlashEprom[EPROM_OTA1_VER] = asciiToUint8(CmdRxBuf + 2);
	if(EEPROM_WriteBlock(EPROM_OTA1_VER, FlashEprom, 1) != EE_NO_ERROR){//��FLASH�ж�ȡOTA MD5ֵ
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_SET_OTA1_VER:%2X\n", (uint16_t)FlashEprom[EPROM_OTA1_VER]);
#endif		
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_OTA1_VER;
		CmdTxBuf[2] = CMD_RESPOND_OK;
		CmdTxBuf[3] = CMD_END;	
	}
	else{
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_SET_OTA1_VER:EPROM Write Fail\n");
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_OTA1_VER;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_END;
	}
	uart0Send(CmdTxBuf, 4);
}
void CmdGetOTA2Ver(void){//��ȡOTA2�汾��
	SEG_DATA uint8_t ctemp[2];
	if(EEPROM_ReadBlock(EPROM_OTA2_VER, FlashEprom, 1) != EE_NO_ERROR){
		uint8ToAscii((FlashEprom + EPROM_OTA2_VER), ctemp);
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_GET_OTA2_VER:%2X\n", (uint16_t)FlashEprom[EPROM_OTA2_VER]);
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_GET_OTA2_VER;
		CmdTxBuf[2] = ctemp[0];
		CmdTxBuf[3] = ctemp[1];
		CmdTxBuf[4] = CMD_END;
	}
	else{
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_GET_OTA2_VER:%EPROM Write Fail\n");
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_GET_OTA2_VER;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_RESPOND_FAIL;
		CmdTxBuf[4] = CMD_END;
	}
	uart0Send(CmdTxBuf, 5);
}
void CmdSetOTA2Ver(void){//����OTA2�汾��
	FlashEprom[EPROM_OTA2_VER] = asciiToUint8(CmdRxBuf + 2);
	if(EEPROM_WriteBlock(EPROM_OTA2_VER, FlashEprom, 1) != EE_NO_ERROR){//��FLASH�ж�ȡOTA MD5ֵ
#if CONFIG_DEBUG == 1
	printf("Bootloader->Debug->CMD_SET_OTA2_VER:%2X\n", FlashEprom[EPROM_OTA2_VER]);
#endif		
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_OTA2_VER;
		CmdTxBuf[2] = CMD_RESPOND_OK;
		CmdTxBuf[3] = CMD_END;	
	}
	else{
#if CONFIG_DEBUG == 1
	printf("Bootloader->Debug->CMD_SET_OTA2_VER:EPROM Write Fail\n", FlashEprom[EPROM_OTA2_VER]);
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_OTA2_VER;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_END;
	}
	uart0Send(CmdTxBuf, 4);
}
void CmdGetBootCrc(void){//��ȡBOOT CRC
	SEG_DATA uint8_t ctemp[2];
	if(EEPROM_ReadBlock(EPROM_BOOT_CRC, FlashEprom, 1) != EE_NO_ERROR){
		uint8ToAscii((FlashEprom + EPROM_BOOT_CRC), ctemp);
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_GET_BOOT_CRC:%2X\n", *((uint32_t*)(&FlashEprom[EPROM_BOOT_CRC])));
#endif	
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_GET_BOOT_CRC;
		CmdTxBuf[2] = ctemp[0];
		CmdTxBuf[3] = ctemp[1];
		CmdTxBuf[4] = CMD_END;		
	}
	else{
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_GET_BOOT_CRC:EPROM Read Fail\n");
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_GET_BOOT_CRC;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_RESPOND_FAIL;
		CmdTxBuf[4] = CMD_END;	
	}
	uart0Send(CmdTxBuf, 5);
}
void CmdGetOTA1Crc(void){//��ȡOTA1 CRC
	SEG_DATA uint8_t ctemp[2];
	if(EEPROM_ReadBlock(EPROM_OTA1_CRC, FlashEprom, 1) != EE_NO_ERROR){
		uint8ToAscii((FlashEprom + EPROM_OTA1_CRC), ctemp);
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_GET_OTA1_CRC:%2X\n",  *((uint32_t*)(&FlashEprom[EPROM_OTA1_CRC])));
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_GET_OTA1_CRC;
		CmdTxBuf[2] = ctemp[0];
		CmdTxBuf[3] = ctemp[1];
		CmdTxBuf[4] = CMD_END;		
	}
	else{
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_GET_OTA1_CRC:EPROM Read Fail\n");
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_GET_OTA1_CRC;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_RESPOND_FAIL;
		CmdTxBuf[4] = CMD_END;	
	}
	uart0Send(CmdTxBuf, 5);
}
void CmdGetOTA2Crc(void){//��ȡOTA2 CRC
	SEG_DATA uint8_t ctemp[2];
	if(EEPROM_ReadBlock(EPROM_OTA2_CRC, FlashEprom, 1) != EE_NO_ERROR){
		uint8ToAscii((FlashEprom + EPROM_OTA2_CRC), ctemp);
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_GET_OTA2_CRC:%2X\n", *((uint32_t*)(&FlashEprom[EPROM_OTA2_CRC])));
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_GET_OTA2_CRC;
		CmdTxBuf[2] = ctemp[0];
		CmdTxBuf[3] = ctemp[1];
		CmdTxBuf[4] = CMD_END;
	}
	else{
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_GET_OTA2_CRC:EPROM Read Fail\n");
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_GET_OTA2_CRC;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_RESPOND_FAIL;
		CmdTxBuf[4] = CMD_END;	
	}
	uart0Send(CmdTxBuf, 5);
}
void CmdReadFlashPage(void){//��ȡFLASHָ��ҳ
	SEG_DATA uint16_t i;
	SEG_DATA uint32_t adr, crc;
	SEG_DATA uint8_t page;
	page = asciiToUint8(CmdRxBuf + 2);
	if(page > (FW_BOOT_ADR_END / FL_PAGE_SIZE) && (page < (FLASH_TEMP / FL_PAGE_SIZE)))
	{	
		adr = (uint32_t)(page) * FL_PAGE_SIZE;
		crc32Clear();crc = 0;
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_READ_FLASH_PAGE;
		CmdTxBuf[2] = CmdRxBuf[2];
		CmdTxBuf[3] = CmdRxBuf[3];
		FLASH_Read (TempBuf, adr, FL_PAGE_SIZE);//��ȡFLSAH
		
		crc = crc32Calculate(TempBuf, FL_PAGE_SIZE);
		for(i = 0;i < FL_PAGE_SIZE;i ++){
			uint8ToAscii((TempBuf + i), (CmdTxBuf + 4 + (i * 2)));
		}
		uint32ToAscii(&crc, (CmdTxBuf + 4 + 1024));
		CmdTxBuf[1032] = CMD_END;	
		uart0Send(CmdTxBuf, 1033);
	}
	else{
#if CONFIG_DEBUG == 1
			printf("Bootloader->Debug->CMD_READ_FLASH_PAGE:Page Overflow\n");
#endif
			CmdTxBuf[0] = CMD_STX;
			CmdTxBuf[1] = CMD_READ_FLASH_PAGE;
			CmdTxBuf[2] = CmdRxBuf[2];
			CmdTxBuf[3] = CmdRxBuf[3];
			CmdTxBuf[4] = CMD_RESPOND_FAIL;
			CmdTxBuf[5] = CMD_END;
			uart0Send(CmdTxBuf, 6);
	}
}
void CmdClearFlashPage(void){//���FLASHָ��ҳ
	SEG_DATA uint32_t adr;
	SEG_DATA uint8_t page;
	page = asciiToUint8(CmdRxBuf + 2);
	if(page > (FW_BOOT_ADR_END / FL_PAGE_SIZE) && (page < (FLASH_TEMP / FL_PAGE_SIZE))){
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_CLEAR_FLASH_PAGE:Done\n");
#endif		
		adr = (uint32_t)(page - 1) * FL_PAGE_SIZE;
		FLASH_Clear (adr, FL_PAGE_SIZE);
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_CLEAR_FLASH_PAGE;
		CmdTxBuf[2] = CmdRxBuf[2];
		CmdTxBuf[3] = CmdRxBuf[3];
		CmdTxBuf[4] = CMD_RESPOND_OK;
		CmdTxBuf[5] = CMD_END;	
		uart0Send(CmdTxBuf, 6);
	}
	else{
#if CONFIG_DEBUG == 1
			printf("Bootloader->Debug->CMD_CLEAR_FLASH_PAGE:Page Overflow\n");
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_CLEAR_FLASH_PAGE;
		CmdTxBuf[2] = CmdRxBuf[2];
		CmdTxBuf[3] = CmdRxBuf[3];
		CmdTxBuf[4] = CMD_RESPOND_FAIL;
		CmdTxBuf[5] = CMD_END;	
		uart0Send(CmdTxBuf, 6);
	}
	
}
void CmdWriteFlashPage(void){//д��FLASHָ��ҳ
	SEG_DATA uint32_t adr, crc0, crc1;
	SEG_DATA uint8_t page;
	SEG_DATA uint16_t i;
	page = asciiToUint8(CmdRxBuf + 2);
	adr = page * FL_PAGE_SIZE;
	uint32ToAscii(&crc0, (CmdTxBuf + 4 + 1024));//���յ���CRC32ֵ
	for(i = 0;i < FL_PAGE_SIZE;i ++){
		*(TempBuf + i) = asciiToUint8(CmdRxBuf + 2 + (i * 2));
	}
	crc32Clear();
	crc1 = crc32Calculate(TempBuf, FL_PAGE_SIZE);
	if(page > (FW_BOOT_ADR_END / FL_PAGE_SIZE) && (page < (FLASH_TEMP / FL_PAGE_SIZE)) && crc0 == crc1){	
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_WRITE_FLASH_PAGE:Done\n");
#endif	
		FLASH_Write(adr, TempBuf, FL_PAGE_SIZE);
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_WRITE_FLASH_PAGE;
		CmdTxBuf[2] = CmdRxBuf[2];
		CmdTxBuf[3] = CmdRxBuf[3];
		CmdTxBuf[4] = CMD_RESPOND_OK;
		CmdTxBuf[5] = CMD_END;	
		uart0Send(CmdTxBuf, 6);
	}
	else{
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_WRITE_FLASH_PAGE:Page Overflow\n");
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_WRITE_FLASH_PAGE;
		CmdTxBuf[2] = CmdRxBuf[2];
		CmdTxBuf[3] = CmdRxBuf[3];
		CmdTxBuf[4] = CMD_RESPOND_FAIL;
		CmdTxBuf[5] = CMD_END;	
		uart0Send(CmdTxBuf, 6);
	}
}
void CmdUpdateOTA1Crc(void){//ˢ��OTA1У����
	uint32_t crc, i;
	uint8_t temp;
	crc32Clear();crc = 0;
	//����OTA1����FLASH CRC
	for(i = FW_OTA1_ADR_START;i < FW_OTA1_ADR_END;i ++){
		FLASH_Read(&temp, i, 1);
		crc = crc32CalculateAdd(temp);
	}
	//CRCд��EPROM������
	*((uint32_t*)(&FlashEprom[EPROM_OTA1_CRC])) = crc;
	//EPROM������д��FLASH
	if(EEPROM_WriteBlock(EPROM_OTA1_CRC, FlashEprom, 4) != EE_NO_ERROR){//��FLASH�ж�ȡOTA MD5ֵ
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_UPDATE_OTA1_CRC;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_END;	
	}
	else{
#if CONFIG_DEBUG == 1
		printf("Bootloader->Debug->CMD_UPDATE_OTA1_CRC:EPROM write Fail\n");
#endif
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_UPDATE_OTA1_CRC;
		CmdTxBuf[2] = CMD_RESPOND_OK;
		CmdTxBuf[3] = CMD_END;
	}		
	uart0Send(CmdTxBuf, 4);
}
void CmdUpdateOTA2Crc(void){//ˢ��OTA2У����
	uint32_t crc, i;
	uint8_t temp;
	crc32Clear();crc = 0;
	//����OTA1����FLASH CRC
	for(i = FW_OTA2_ADR_START;i < FW_OTA2_ADR_END;i ++){
		FLASH_Read(&temp, i, 1);
		crc = crc32CalculateAdd(temp);
	}
	//CRCд��EPROM������
	*((uint32_t*)(&FlashEprom[EPROM_OTA2_CRC])) = crc;
	//EPROM������д��FLASH
	if(EEPROM_WriteBlock(EPROM_OTA2_CRC, FlashEprom, 4) != EE_NO_ERROR){//��FLASH�ж�ȡOTA MD5ֵ
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_UPDATE_OTA2_CRC;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_END;	
	}
	else{
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_UPDATE_OTA2_CRC;
		CmdTxBuf[2] = CMD_RESPOND_OK;
		CmdTxBuf[3] = CMD_END;
	}		
	uart0Send(CmdTxBuf, 4);	
}

void loaderCmdPoll(void){//����������ѯ
	uint8_t *ptr, *ptw;
	uart0Send("C", 1);
	while(1){
		ptr = CmdRxBuf;
		uart0Receive(ptr, 1);
		if(*ptr == CMD_STX){
			ptr ++;
			do{
				uart0Receive(ptr, 1);
				if(*ptr == CMD_END)
				{
					switch(CmdRxBuf[1])
					{
						case CMD_SET_HW_VER://1
						{
							CmdSetHwVer();
							break;
						}
						case CMD_GET_HW_VER://2
						{
							CmdGetHwVer();
							break;
						}
						case CMD_RESET_MCU://3
						{
							CmdResetMcu();
							break;
						}
						case CMD_GET_BOOTLOADER_VER://4
						{
							CmdGetBootLoaderVer();
							break;
						}
						case CMD_GET_OTA1_VER://5
						{
							CmdGetOTA1Ver();
							break;
						}
						case CMD_GET_OTA2_VER://6
						{
							CmdGetOTA2Ver();
							break;
						}
						case CMD_SET_BOOTLOADER_VER://7
						{
							CmdSetBootLoaderVer();
							break;
						}
						case CMD_SET_OTA1_VER://8
						{
							CmdSetOTA1Ver();
							break;
						}
						case CMD_SET_OTA2_VER://9
						{
							CmdSetOTA2Ver();
							break;
						}							
						case CMD_GET_OTA1_CRC://A
						{
							CmdGetOTA1Crc();
							break;
						}
						case CMD_GET_OTA2_CRC://B
						{
							CmdGetOTA2Crc();
							break;
						}
						case CMD_WRITE_FLASH_PAGE://C
						{
							CmdWriteFlashPage();
							break;
						}
						case CMD_READ_FLASH_PAGE://D
						{
							CmdReadFlashPage();
							break;
						}
						case CMD_CLEAR_FLASH_PAGE://E
						{
							CmdClearFlashPage();
							break;
						}
						case CMD_GOTO_OTA1://F
						{
							CmdGotoOTA1();
							break;
						}
						case CMD_GOTO_OTA2://G
						{
							CmdGotoOTA2();
							break;
						}
						case CMD_UPDATE_OTA1_CRC:
						{
							CmdUpdateOTA1Crc();
							break;
						}
						case CMD_UPDATE_OTA2_CRC:
						{
							CmdUpdateOTA2Crc();
							break;
						}
						default:break;
					}
					break;
				}
				else if(ptr >= (CmdRxBuf + CMD_RX_BUFFER_SIZE)){
					NOP();
					break;
				}
				ptr ++;
			}while(1);
		}
	}
}

void bootSequence(void){//����˳��ѡ��
	SEG_DATA uint32_t ota1Crc32, ota2Crc32;
	//��ʼ��ʱ��
	SEG_DATA uint8_t temp;
	temp = uart0ReceiveBootOrder();
	if(temp == BOOT_SELECT_OTA)
	{
		if(FlashEprom[EPROM_BOOT_ORDER] == SELECT_BOOT_OTA1)
		{//����˳��ѡ��BOOT_OTA1
			ota1Crc32 = ota1FlashCrc();
			if(ota1Crc32 == FlashEprom[EPROM_OTA1_CRC])
			{
				CmdGotoOTA1 = (void code *)(FW_OTA1_ADR_START & 0x1FFFF);//��ȡOTA1��ʼ��ַ
				CmdGotoOTA1();//ִ��Ӧ�ó���
			}
		}
		else if(FlashEprom[EPROM_BOOT_ORDER] == SELECT_BOOT_OTA2)
		{//����˳��ѡ��BOOT_OTA2
			ota2Crc32 = ota2FlashCrc();
			if(ota2Crc32 == FlashEprom[EPROM_OTA2_CRC])
			{
				CmdGotoOTA2 = (void code *)(FW_OTA2_ADR_START & 0x1FFFF);//��ȡOTA2��ʼ��ַ
				CmdGotoOTA2();//ִ��Ӧ�ó���
			}	
		}
		else{
#if CONFIG_DEBUG == 1
			printf("Bootloader->Debug:OTA CRC32 Check Fail,Into Loader Mode\n");
#endif
			loaderCmdPoll();
		}	
	}
	else if(temp == BOOT_SELECT_LOADER)
	{
		while(1)
		{
			loaderCmdPoll();
		}
	}	
}
void main (void) 
{
	Init_Device();
#if CONFIG_DEBUG == 1
	printf("Bootloader->Debug:Hello C8051 Bootloader\n");
#endif
	bootSequence();
	while(1);
}
