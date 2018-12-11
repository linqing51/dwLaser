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
#define CMD_WRITE_FLASH_PAGE				0x44//D 写入FLASH PAGE
#define CMD_READ_FLASH_PAGE					0x45//E 读取FLASH PAGE
#define CMD_CLEAR_FLASH_PAGE				0x46//F	清除FLASH PAGE
#define CMD_GOTO_OTA1						0x47//G
#define CMD_GOTO_OTA2						0x48//H
#define CMD_GET_HW_VER_TX_SZ				3
#define CMD_GET_HW_VER_RX_SZ 				6
#define CMD_SET_HW_VER_TX_SZ				7
#define CMD_SET_HW_VER_RX_SZ				3
#define CMD_RESPOND_OK 						0x31
#define CMD_RESPOND_FAIL					0x30
/*****************************************************************************/
#define BOOT_SELECT_OTA						0x5A
#define BOOT_SELECT_LOADER					0xA5
#define BOOT_SELECT_TIMEOUT					1000000UL
#define BOOT_SELECT_CHECKSUM				0x8A//BOOTLOADER选择校验码
/*****************************************************************************/
#define FW_BOOT_ADR_START					0x0000//引导程序起始
#define FW_BOOT_ADR_END						0x1FFF//引导程序结束
#define FW_OTA1_ADR_START					0x2000//应用程序1起始地址
#define FW_OTA1_ADR_END						0x7FFF
#define FW_OTA2_ADR_START					0x8000//应用程序2起始地址
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
void (*BOOT_Program)();//引导程序指针
void (*OTA1_Program)();//应用程序1指针
void (*OTA2_Program)();//应用程序2指针
void bootSequence(void);
uint32_t bootFlashCrc(void);
uint32_t ota1FlashCrc(void);
uint32_t ota2FlashCrc(void);
xdata uint8_t CmdRxBuf[CMD_RX_BUFFER_SIZE];
xdata uint8_t CmdTxBuf[CMD_TX_BUFFER_SIZE];
xdata uint8_t TempBuf[FL_PAGE_SIZE];//临时缓冲区
xdata uint8_t FlashEprom[EE_SIZE];//FLASH EPROM模拟
/*****************************************************************************/
static void uint32ToAscii(uint32_t *dat, uint8_t *pstr){//将32位有符号数转换为8个ASCII字符
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
static uint32_t asciiToUint32(uint8_t *pstr){//将8个BCD组合成一个32进制数
	data uint8_t temp[8];
	data uint32_t hex;
	//取出0x0000000A
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[0] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[0] = *pstr - 0x30;	
	}
	//取出0x000000A0
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[1] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[1] = *(pstr + 1) - 0x30;	
	}
	//取出0x00000A00
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[2] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[2] = *pstr - 0x30;	
	}
	//取出0x0000A000
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[3] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[3] = *(pstr + 1) - 0x30;	
	}
	
	//取出0x0000A000
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[4] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[4] = *pstr - 0x30;	
	}
	//取出0x00000A00
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[5] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[5] = *(pstr + 1) - 0x30;	
	}
	//取出0x000000A0
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[6] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[6] = *pstr - 0x30;	
	}
	//取出0x0000000A
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
static void uint16ToAscii(uint16_t *dat, uint8_t *pstr){//将16位有符号数转换为4个ASCII字符
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
static void uint8ToAscii(uint8_t *dat, uint8_t *pstr){//将16进制数转换成两个ASCII字符
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
static uint8_t asciiToUint8(uint8_t *pstr){//将两个int8_t 组合成一个16进制数
	data uint8_t temp[2];
	data uint8_t hex;
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
	data uint8_t temp[4];
	data uint16_t hex;
	//取出0xA000
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[3] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[3] = *pstr - 0x30;	
	}
	//取出0x0A00
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[2] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[2] = *(pstr + 1) - 0x30;	
	}
	//取出0x00A0
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[1] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[1] = *pstr - 0x30;	
	}
	//取出0x000A
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
static uint8_t LRC(uint8_t *buf, int32_t len){//计算LRC LRC方法是将消息中的8Bit的字节连续累加，丢弃了进位
	int i;
	uint8_t lrc = 0;        /*lrc字节初始化*/
	for( i = 0; i < len; i++ ){
		lrc = lrc + buf[i];
	}
	return lrc;
}
void uart0Send(uint8_t *buf, uint16_t count){//串口0查询发送
	uint8_t *ptr = buf;
	do{
	    SBUF0 = *ptr++;
		while(TI0 == 0);
		TI0 = 0;
	}while(--count);
}
void uart0Receive(uint8_t *buf, uint16_t count){//串口0查询接收
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
uint8_t uart0ReceiveBootOrder(void){//串口0查询接收带超时
	uint8_t temp;
	uint32_t timeOutCounter;
#if CONFIG_DEBUG == 1
	sprintf(CmdTxBuf,"Bootloader->Debug:Input 'C' Into Loader Mode\n");
	printf(CmdTxBuf);
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
void CmdSetHwVer(void){//设置硬件版本
	uint16_t itemp;
	FlashEprom[EPROM_HW_VER] = asciiToUint8(CmdRxBuf + 2);
#if CONFIG_DEBUG == 1
	itemp = FlashEprom[EPROM_HW_VER];
	printf("Bootloader->Debug->CMD_SET_HW_VER:%2X\n", itemp);
#endif
	if(EEPROM_WriteBlock(EPROM_HW_VER, FlashEprom, 1) != EE_NO_ERROR){//从FLASH中读取OTA MD5值
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
void CmdGetHwVer(void){//获取硬件版本
	uint8_t ctemp[2];
	uint16_t itemp;
	uint8ToAscii((FlashEprom + EPROM_HW_VER), ctemp);
	EEPROM_ReadBlock(EPROM_HW_VER, FlashEprom, 1);
#if CONFIG_DEBUG == 1
	itemp = FlashEprom[EPROM_HW_VER];
	printf("Bootloader->Debug->CMD_GET_HW_VER:%2X\n", itemp);
#endif
	CmdTxBuf[0] = CMD_STX;
	CmdTxBuf[1] = CMD_GET_HW_VER;
	CmdTxBuf[2] = ctemp[0];
	CmdTxBuf[3] = ctemp[1];
	CmdTxBuf[4] = CMD_END;
	uart0Send(CmdTxBuf, 5);
}
void CmdResetMcu(void){//强制复位
	RSTSRC |= (1 << 4);
}
void CmdGetBootLoaderVer(void){//获取BOOTLOADER版本
	uint8_t ctemp[2];
	uint16_t itemp;
	EEPROM_ReadBlock(EPROM_BOOT_VER, FlashEprom, 1);
	uint8ToAscii((FlashEprom + EPROM_BOOT_VER), ctemp);
#if CONFIG_DEBUG == 1
	itemp = FlashEprom[EPROM_BOOT_VER];
	printf("Bootloader->Debug->CMD_GET_BOOT_VER:%2X\n", itemp);
#endif
	CmdTxBuf[0] = CMD_STX;
	CmdTxBuf[1] = CMD_GET_BOOTLOADER_VER;
	CmdTxBuf[2] = ctemp[0];
	CmdTxBuf[3] = ctemp[1];
	CmdTxBuf[4] = CMD_END;	
	uart0Send(CmdTxBuf, 5);
}
void CmdSetBootLoaderVer(void){//设置Bootloader版本号
	uint16_t itemp;
	FlashEprom[EPROM_BOOT_VER] = asciiToUint8(CmdRxBuf + 2);
#if CONFIG_DEBUG == 1
	itemp = FlashEprom[EPROM_BOOT_VER];
	printf("Bootloader->Debug->CMD_SET_BOOT_VER:%2X\n", itemp);
#endif
	if(EEPROM_WriteBlock(EPROM_HW_VER, FlashEprom, 1) != EE_NO_ERROR){//从FLASH中读取OTA MD5值
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_BOOTLOADER_VER;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_END;	
	}
	else{
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_BOOTLOADER_VER;
		CmdTxBuf[2] = CMD_RESPOND_OK;
		CmdTxBuf[3] = CMD_END;
	}
	uart0Send(CmdTxBuf, 4);
}
void CmdGetOTA1Ver(void){//获取OTA1版本号
	uint8_t ctemp[2];
	uint16_t itemp;
	EEPROM_ReadBlock(EPROM_OTA1_VER, FlashEprom, 1);
	uint8ToAscii((FlashEprom + EPROM_OTA1_VER), ctemp);
#if CONFIG_DEBUG == 1
	itemp = FlashEprom[EPROM_OTA1_VER];
	printf("Bootloader->Debug->CMD_GET_OTA1_VER:%2X\n", itemp);
#endif
	CmdTxBuf[0] = CMD_STX;
	CmdTxBuf[1] = CMD_GET_OTA1_VER;
	CmdTxBuf[2] = ctemp[0];
	CmdTxBuf[3] = ctemp[1];
	CmdTxBuf[4] = CMD_END;	
	uart0Send(CmdTxBuf, 5);
}
void CmdSetOTA1Ver(void){//设置OTA1版本号
	uint16_t itemp;
	FlashEprom[EPROM_OTA1_VER] = asciiToUint8(CmdRxBuf + 2);
#if CONFIG_DEBUG == 1
	itemp = FlashEprom[EPROM_OTA1_VER];
	printf("Bootloader->Debug->CMD_SET_OTA1_VER:%2X\n", itemp);
#endif
	if(EEPROM_WriteBlock(EPROM_OTA1_VER, FlashEprom, 1) != EE_NO_ERROR){//从FLASH中读取OTA MD5值
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
void CmdGetOTA2Ver(void){//获取OTA2版本号
	uint8_t ctemp[2];
	uint16_t itemp;
	EEPROM_ReadBlock(EPROM_OTA2_VER, FlashEprom, 1);
	uint8ToAscii((FlashEprom + EPROM_OTA2_VER), ctemp);
#if CONFIG_DEBUG == 1
	itemp = FlashEprom[EPROM_OTA2_VER];
	printf("Bootloader->Debug->CMD_GET_OTA2_VER:%2X\n", itemp);
#endif
	CmdTxBuf[0] = CMD_STX;
	CmdTxBuf[1] = CMD_GET_OTA2_VER;
	CmdTxBuf[2] = ctemp[0];
	CmdTxBuf[3] = ctemp[1];
	CmdTxBuf[4] = CMD_END;	
	uart0Send(CmdTxBuf, 5);
}
void CmdSetOTA2Ver(void){//设置OTA2版本号
	uint16_t itemp;
	FlashEprom[EPROM_OTA2_VER] = asciiToUint8(CmdRxBuf + 2);
#if CONFIG_DEBUG == 1
	itemp = FlashEprom[EPROM_OTA2_VER];
	printf("Bootloader->Debug->CMD_SET_OTA2_VER:%2X\n", itemp);
#endif
	if(EEPROM_WriteBlock(EPROM_OTA2_VER, FlashEprom, 1) != EE_NO_ERROR){//从FLASH中读取OTA MD5值
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_OTA2_VER;
		CmdTxBuf[2] = CMD_RESPOND_FAIL;
		CmdTxBuf[3] = CMD_END;	
	}
	else{
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_SET_OTA2_VER;
		CmdTxBuf[2] = CMD_RESPOND_OK;
		CmdTxBuf[3] = CMD_END;
	}
	uart0Send(CmdTxBuf, 4);
}
void CmdGetBootCrc(void){//获取BOOT CRC
	uint8_t ctemp[2];
	uint16_t itemp;
	EEPROM_ReadBlock(EPROM_BOOT_CRC, FlashEprom, 1);
	uint8ToAscii((FlashEprom + EPROM_BOOT_CRC), ctemp);
#if CONFIG_DEBUG == 1
	itemp = FlashEprom[EPROM_BOOT_CRC];
	printf("Bootloader->Debug->CMD_GET_BOOT_CRC:%2X\n", itemp);
#endif	
	CmdTxBuf[0] = CMD_STX;
	CmdTxBuf[1] = CMD_GET_BOOT_CRC;
	CmdTxBuf[2] = ctemp[0];
	CmdTxBuf[3] = ctemp[1];
	CmdTxBuf[4] = CMD_END;	
	uart0Send(CmdTxBuf, 5);
}
void CmdGetOTA1Crc(void){//获取OTA1 CRC
	uint8_t ctemp[2];
	uint16_t itemp;
	EEPROM_ReadBlock(EPROM_OTA1_CRC, FlashEprom, 1);
	uint8ToAscii((FlashEprom + EPROM_OTA1_CRC), ctemp);
#if CONFIG_DEBUG == 1
	itemp = FlashEprom[EPROM_OTA1_CRC];
	printf("Bootloader->Debug->CMD_GET_OTA1_CRC:%2X\n", itemp);
#endif
	CmdTxBuf[0] = CMD_STX;
	CmdTxBuf[1] = CMD_GET_OTA1_CRC;
	CmdTxBuf[2] = ctemp[0];
	CmdTxBuf[3] = ctemp[1];
	CmdTxBuf[4] = CMD_END;	
	uart0Send(CmdTxBuf, 5);
}
void CmdGetOTA2Crc(void){//获取OTA2 CRC
	uint8_t ctemp[2];
	uint16_t itemp;
	EEPROM_ReadBlock(EPROM_OTA2_CRC, FlashEprom, 1);
	uint8ToAscii((FlashEprom + EPROM_OTA2_CRC), ctemp);
#if CONFIG_DEBUG == 1
	itemp = FlashEprom[EPROM_OTA2_CRC];
	printf("Bootloader->Debug->CMD_GET_OTA2_CRC:%2X\n", itemp);
#endif
	CmdTxBuf[0] = CMD_STX;
	CmdTxBuf[1] = CMD_GET_OTA2_CRC;
	CmdTxBuf[2] = ctemp[0];
	CmdTxBuf[3] = ctemp[1];
	CmdTxBuf[4] = CMD_END;	
	uart0Send(CmdTxBuf, 5);
}
void CmdReadFlashPage(void){//读取FLASH指定页
	uint16_t i;
	uint32_t adr, crc;
	uint8_t temp, page;
	page = asciiToUint8(CmdRxBuf + 2);
	if(page > (FW_BOOT_ADR_END / FL_PAGE_SIZE) && (page < (FLASH_TEMP / FL_PAGE_SIZE)))
	{	
		adr = (uint32_t)(page - 1) * FL_PAGE_SIZE;
		crc32Clear();crc = 0;
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_READ_FLASH_PAGE;
		uint8ToAscii(&page, (CmdTxBuf + 2));
		for(i = 0;i < FL_PAGE_SIZE;i ++){
			FLASH_Read (&temp, (adr + i), 1);//读取FLSAH
			crc = crc32CalculateAdd(temp);
			uint8ToAscii(&temp, (CmdTxBuf + 4 + (i * 2)));
		}
		uint32ToAscii(&crc, (CmdTxBuf + 4 + 1024));
		CmdTxBuf[1032] = CMD_END;	
		uart0Send(CmdTxBuf, 1033);
	}
	else{
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_READ_FLASH_PAGE;
		uint8ToAscii(&page, (CmdTxBuf + 2));
		CmdTxBuf[4] = CMD_RESPOND_FAIL;
		CmdTxBuf[5] = CMD_END;	
		uart0Send(CmdTxBuf, 6);
	}
}
void CmdClearFlashPage(void){//清除FLASH指定页
	uint32_t adr;
	uint8_t page;
	page = asciiToUint8(CmdRxBuf + 2);
	if(page > (FW_BOOT_ADR_END / FL_PAGE_SIZE) && (page < (FLASH_TEMP / FL_PAGE_SIZE))){	
		adr = (uint32_t)(page - 1) * FL_PAGE_SIZE;
		FLASH_Clear (adr, FL_PAGE_SIZE);
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_CLEAR_FLASH_PAGE;
		uint8ToAscii(&page, (CmdTxBuf + 2));
		CmdTxBuf[4] = CMD_RESPOND_OK;
		CmdTxBuf[5] = CMD_END;	
		uart0Send(CmdTxBuf, 6);
	}
	else{
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_CLEAR_FLASH_PAGE;
		uint8ToAscii(&page, (CmdTxBuf + 2));
		CmdTxBuf[4] = CMD_RESPOND_FAIL;
		CmdTxBuf[5] = CMD_END;	
		uart0Send(CmdTxBuf, 6);
	}
}
void CmdWriteFlashPage(void){//写入FLASH指定页
	uint32_t adr, crc0, crc1;
	uint8_t page, dat;
	uint16_t i;
	page = asciiToUint8(CmdRxBuf + 2);
	adr = page * FL_PAGE_SIZE;
	uint32ToAscii(&crc0, (CmdTxBuf + 4 + 1024));//接收到的CRC32值
	for(i = 0;i < FL_PAGE_SIZE;i ++){
		*(TempBuf + i) = asciiToUint8(CmdRxBuf + 2 + (i * 2));
	}
	crc32Clear();
	crc1 = crc32Calculate(TempBuf, FL_PAGE_SIZE);
	if(page > (FW_BOOT_ADR_END / FL_PAGE_SIZE) && (page < (FLASH_TEMP / FL_PAGE_SIZE)) && crc0 == crc1){	
		FLASH_Write(adr, TempBuf, FL_PAGE_SIZE);
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_WRITE_FLASH_PAGE;
		uint8ToAscii(&page, (CmdTxBuf + 2));
		CmdTxBuf[4] = CMD_RESPOND_OK;
		CmdTxBuf[5] = CMD_END;	
		uart0Send(CmdTxBuf, 6);
	}
	else{
		CmdTxBuf[0] = CMD_STX;
		CmdTxBuf[1] = CMD_WRITE_FLASH_PAGE;
		uint8ToAscii(&page, (CmdTxBuf + 2));
		CmdTxBuf[4] = CMD_RESPOND_FAIL;
		CmdTxBuf[5] = CMD_END;	
		uart0Send(CmdTxBuf, 6);
	}
}
void loaderCmdPoll(void){//串口命令轮询
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
							OTA1_Program();
							break;
						}
						case CMD_GOTO_OTA2://G
						{
							OTA2_Program();
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

void bootSequence(void){//启动顺序选择
	data uint32_t ota1Crc32, ota2Crc32;
	//开始计时器
	data uint8_t temp;
	temp = uart0ReceiveBootOrder();
	if(temp == BOOT_SELECT_OTA)
	{
		if(FlashEprom[EPROM_BOOT_ORDER] == SELECT_BOOT_OTA1)
		{//启动顺序选择BOOT_OTA1
			ota1Crc32 = ota1FlashCrc();
			if(ota1Crc32 == FlashEprom[EPROM_OTA1_CRC])
			{
				OTA1_Program = (void code *)(FW_OTA1_ADR_START & 0x1FFFF);//获取OTA1起始地址
				OTA1_Program();//执行应用程序
			}
		}
		else if(FlashEprom[EPROM_BOOT_ORDER] == SELECT_BOOT_OTA2)
		{//启动顺序选择BOOT_OTA2
			if(ota2Crc32 == FlashEprom[EPROM_OTA2_CRC])
			{
				OTA2_Program = (void code *)(FW_OTA2_ADR_START & 0x1FFFF);//获取OTA2起始地址
				OTA2_Program();//执行应用程序
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
uint32_t bootFlashCrc(void){//BOOT CRC32校验	
	data uint32_t crc = 0, i;
	data uint8_t temp;
	
	crc32Clear();//CRC32清除
	for(i = FW_BOOT_ADR_START;i < FW_BOOT_ADR_END;i ++)
	{//计算BOOT CRC32
		FLASH_Read(&temp, i, 1);
		crc = crc32CalculateAdd(temp);
	}
	return crc;
}
uint32_t ota1FlashCrc(void){//OTA1 CRC32校验
	data uint32_t crc = 0 ,i;
	data uint8_t temp;
	crc32Clear();//CRC32清除
	for(i = FW_OTA1_ADR_START;i < FW_OTA1_ADR_END;i ++)
	{//计算OTA1 CRC32
		FLASH_Read(&temp, i, 1);
		crc = crc32CalculateAdd(temp);
	}
	return crc;
}
uint32_t ota2FlashCrc(void){//OTA2 CRC32校验
	data uint32_t crc = 0, i;
	data uint8_t temp;
	for(i = FW_OTA2_ADR_START;i < FW_OTA2_ADR_END;i ++)
	{//计算OTA2 CRC32
		FLASH_Read(&temp, i, 1);
		crc = crc32CalculateAdd(temp);
	}
	return crc;
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
