#include "appConfig.h"
/*****************************************************************************/
#define FW_BOOT_ADR_START				0x0000//引导程序起始
#define FW_BOOT_ADR_END					0x0FFF//引导程序结束
#define FW_OTA1_ADR_START				0x1000//应用程序1起始地址
#define FW_OTA1_ADR_END					0x8000
#define FW_OTA2_ADR_START				0x8000//应用程序2起始地址
#define FW_OTA2_ADR_END					0xF000
#define BOOT_OTA1						0xA5A5
#define BOOT_OTA2						0x5A5A
#define CMD_STX							‘$’//起始码
//#define CMD_FUN0//功能码
//#define CMD_FUN1
#define CMD_END							'#'//结束码
#define CMD_RX_BUFFER_SIZE			1024
#define CMD_TX_BUFFER_SIZE			128

	//FLASH EEPROM 32BYTE
	//BOOT_CRC 4B | BOOT_VER 4B
	//OTA1_CRC 4B | OTA1_VER 4B 
	//OTA2_CRC 4B | OTA2_VER 4B 
	//HW_VER   4B | NULL	 4B 	
	//SN_H     4B | SN_L     4B
	//NULL     4B | SEL_BOOT 4B
/*****************************************************************************/
void (*BOOT_Program)();//引导程序指针
void (*OTA1_Program)();//应用程序1指针
void (*OTA2_Program)();//应用程序2指针
uint8_t CmdRxBuffer[CMD_RX_BUFFER_SIZE], CmdTxBuffer[CMD_TX_BUFFER_SIZE];
uint8_t FlashEprom[EE_SIZE];//FLASH EPROM模拟
/*****************************************************************************/
void main (void) 
{
	data uint32_t bootCrc32, ota1Crc32, ota2Crc32;
	data uint8_t temp;
	data uint32_t i;
	SFRPAGE_SWITCH()
	ENABLE_VDDMON()
	DISABLE_WDT()
	SFRPAGE_RESTORE()                       
	//等待串口发送固件更新指令
	
	
	
	if(EEPROM_ReadBlock(0, flashEprom, EE_SIZE) != EE_NO_ERROR){//从FLASH中读取OTA MD5值
		while(1);// Error reading EEPROM
	}
	crc32Clear();//CRC32清除
	for(i = FW_BOOT_ADR_START;i < FW_BOOT_ADR_END;i ++)
	{//计算BOOT CRC32
		FLASH_Read(&temp, i, 1);
		bootCrc32 = crc32CalculateAdd(temp);
	}
	
	for(i = FW_OTA1_ADR_START;i < FW_OTA1_ADR_END;i ++)
	{//计算OTA1 CRC32
		FLASH_Read(&temp, i, 1);
		ota1Crc32 = crc32CalculateAdd(temp);
	}
	for(i = FW_OTA2_ADR_START;i < FW_OTA2_ADR_END;i ++)
	{//计算OTA2 CRC32
		FLASH_Read(&temp, i, 1);
		ota2Crc32 = crc32CalculateAdd(temp);
	}
	//	//读取FEPROM中APP_HW MD5校正值
	if(flashEprom[20] == BOOT_OTA1)
	{
		if(bootCrc32 == flashEprom[0] && ota1Crc32 == flashEprom[8]	)
		{
			OTA1_Program = (void code *) FW_OTA1_ADR_START;//获取OTA1起始地址
			OTA1_Program();//执行应用程序
		}
	}
	if(flashEprom[20] == BOOT_OTA2)
	{
		if(bootCrc32 == flashEprom[0] && ota2Crc32 == flashEprom[16]	)
		{
			OTA2_Program = (void code *) FW_OTA2_ADR_START;//获取OTA2起始地址
			OTA2_Program();//执行应用程序
		}	
	}
	
	//SFRPAGE_SWITCH()
//	ENABLE_VDDMON()
//	DISABLE_WDT()
//	SFRPAGE_RESTORE()                       
//	if(EEPROM_ReadBlock(0, FLASH_EPROM, EE_SIZE) != EE_NO_ERROR){//从FLASH中读取OTA MD5值
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
      //1秒内等待串口发出更新码
	  //FLASH_Clear(CONFIG_APP_START_ADR, (CONFIG_APP_END_ADR - CONFIG_APP_START_ADR));
	   //检测到更新码
	  //擦除FLASH
	  //执行固件更新
	  //执行应用程序
      
 
   }

}

