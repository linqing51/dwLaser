#include "appConfig.h"
/*****************************************************************************/
#define FW_BOOT_ADR_START				0x0000//引导程序起始
#define FW_BOOT_ADR_END					0x0FFF//引导程序结束
#define FW_OTA1_ADR_START				0x1000//应用程序1起始地址
#define FW_OTA1_ADR_END					0x8000
#define FW_OTA2_ADR_START				0x8000//应用程序2起始地址
#define FW_OTA2_ADR_END					0xF000
#define BOOT_OTA1						0xA5
#define BOOT_OTA2						0x5A
/*****************************************************************************/
void (*BOOT_APP)();//引导程序指针
void (*OTA1_APP)();//应用程序1指针
void (*OTA2_APP)();//应用程序2指针
/*****************************************************************************/
void main (void) 
{
	uint8_t flashEprom[EE_SIZE];//BOOT_MD5 16B | OTA1_MD5 16B | OTA2_MD5 16B | SN 15B | SELECT_BOOT 1B 
	uint32_t bootCrc32, ota1Crc32, ota2Crc32;
	uint8_t temp;
	uint32_t i;
	
	crc32Clear();
	for(i = FW_BOOT_ADR_START;i < FW_BOOT_ADR_END;i ++)
	{//计算BOOT CRC32
		temp = crc32CalculateAdd(i);
		bootCrc32 = crc32CalculateAdd(temp);
	}
	
	for(i = FW_OTA1_ADR_START;i < FW_OTA1_ADR_END;i ++)
	{//计算OTA1 CRC32
		temp = crc32CalculateAdd(i);
		ota1Crc32 = crc32CalculateAdd(temp);
	}
	
	for(i = FW_OTA2_ADR_START;i < FW_OTA2_ADR_END;i ++)
	{//计算OTA2 CRC32
		temp = crc32CalculateAdd(i);
		ota2Crc32 = crc32CalculateAdd(temp);
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

//void loadAppFunction(void)
//{
//	//读取FEPROM中APP_HW MD5校正值
//	if(f_valid){
//	appFunction = (void code *) CONFIG_APP_START_ADR;//获取APP起始地址
//	appFunction();//执行应用程序
//}

