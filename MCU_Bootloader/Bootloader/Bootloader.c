#include "appConfig.h"
/*****************************************************************************/
#define FW_BOOT_ADR_START				0x0000//����������ʼ
#define FW_BOOT_ADR_END					0x0FFF//�����������
#define FW_OTA1_ADR_START				0x1000//Ӧ�ó���1��ʼ��ַ
#define FW_OTA1_ADR_END					0x8000
#define FW_OTA2_ADR_START				0x8000//Ӧ�ó���2��ʼ��ַ
#define FW_OTA2_ADR_END					0xF000
#define BOOT_OTA1						0xA5
#define BOOT_OTA2						0x5A
/*****************************************************************************/
void (*BOOT_APP)();//��������ָ��
void (*OTA1_APP)();//Ӧ�ó���1ָ��
void (*OTA2_APP)();//Ӧ�ó���2ָ��
/*****************************************************************************/
void main (void) 
{
	uint8_t flashEprom[EE_SIZE];//BOOT_MD5 16B | OTA1_MD5 16B | OTA2_MD5 16B | SN 15B | SELECT_BOOT 1B 
	uint32_t bootCrc32, ota1Crc32, ota2Crc32;
	uint8_t temp;
	uint32_t i;
	
	crc32Clear();
	for(i = FW_BOOT_ADR_START;i < FW_BOOT_ADR_END;i ++)
	{//����BOOT CRC32
		temp = crc32CalculateAdd(i);
		bootCrc32 = crc32CalculateAdd(temp);
	}
	
	for(i = FW_OTA1_ADR_START;i < FW_OTA1_ADR_END;i ++)
	{//����OTA1 CRC32
		temp = crc32CalculateAdd(i);
		ota1Crc32 = crc32CalculateAdd(temp);
	}
	
	for(i = FW_OTA2_ADR_START;i < FW_OTA2_ADR_END;i ++)
	{//����OTA2 CRC32
		temp = crc32CalculateAdd(i);
		ota2Crc32 = crc32CalculateAdd(temp);
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

//void loadAppFunction(void)
//{
//	//��ȡFEPROM��APP_HW MD5У��ֵ
//	if(f_valid){
//	appFunction = (void code *) CONFIG_APP_START_ADR;//��ȡAPP��ʼ��ַ
//	appFunction();//ִ��Ӧ�ó���
//}

