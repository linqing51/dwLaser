
#include "Bootloader.h"
#include "Fxxx_EEPROM_Configuration.h"
#include "Fxxx_EEPROM_Interface.h"
//#define CONFIG_MCU_TYPE_C8051F340		1
//#define CONFIG_APP_START_ADR			0x1000//Ӧ�ó�����ʼ��ַ
//#define CONFIG_APP_END_ADR				0xFFFF//Ӧ�ó��������ַ
//#define CONFIG_
//#ifdef CONFIG_MCU_TYPE_C8051F340 == 1
//#include "F340_FlashUtils.h"
//#endif
//#define APP_START_ADR					0x1000



void main (void);

// Support Subroutines
void receive_code(void);

void (*appFunction)();//Ӧ�ó���ָ��


void main (void) 
{
	uint8_t *pflash;
	uint8_t result[16];
	md5((uint8_t code*)(0x1000), 0x1000, result);
//	pflash = 0x4000;
//	//��ʼ��MCU
//	char i;
//	SEGMENT_VARIABLE(rBuffer[EE_SIZE], U8, SEG_DATA);
//	SEGMENT_VARIABLE(wBuffer[EE_SIZE], U8, SEG_DATA);
//	U8 bufferCount;
//	SFRPAGE_SWITCH()
//	ENABLE_VDDMON()
//	DISABLE_WDT()
//	SFRPAGE_RESTORE()                       
//   for(i = 0;i < EE_SIZE;i++)
//	{
//		wBuffer[i] = i;
//	}
//	// Read first byte of EEPROM
//   if (EEPROM_ReadBlock(0, rBuffer, EE_SIZE) != EE_NO_ERROR)
//   {
//      while(1);      // Error reading EEPROM
//   }
//   
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

