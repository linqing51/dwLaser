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
#define CMD_STX							��$��//��ʼ��
//#define CMD_FUN0//������
//#define CMD_FUN1
#define CMD_END							'#'//������
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
void (*BOOT_Program)();//��������ָ��
void (*OTA1_Program)();//Ӧ�ó���1ָ��
void (*OTA2_Program)();//Ӧ�ó���2ָ��
uint8_t CmdRxBuffer[CMD_RX_BUFFER_SIZE], CmdTxBuffer[CMD_TX_BUFFER_SIZE];
uint8_t FlashEprom[EE_SIZE];//FLASH EPROMģ��
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
	//�ȴ����ڷ��͹̼�����ָ��
	
	
	
	if(EEPROM_ReadBlock(0, flashEprom, EE_SIZE) != EE_NO_ERROR){//��FLASH�ж�ȡOTA MD5ֵ
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
	if(flashEprom[20] == BOOT_OTA1)
	{
		if(bootCrc32 == flashEprom[0] && ota1Crc32 == flashEprom[8]	)
		{
			OTA1_Program = (void code *) FW_OTA1_ADR_START;//��ȡOTA1��ʼ��ַ
			OTA1_Program();//ִ��Ӧ�ó���
		}
	}
	if(flashEprom[20] == BOOT_OTA2)
	{
		if(bootCrc32 == flashEprom[0] && ota2Crc32 == flashEprom[16]	)
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

