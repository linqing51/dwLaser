#include "firmwareUpdata.h"
/*****************************************************************************/

/*****************************************************************************/
#define BOOTLOAD_SEL_FWM0			0xA5
#define BOOTLOAD_SEL_FWM1			0x5A
void bootLoad(void){
	uint8_t i, pNvram, buf[16];
	uint16_t crc;
	uint32_t temp;
	pNvram = (uint8_t*)&NVRAM0[FWREG_BOOT_SELECT];
	for(i = 0;i < (FWREG_FWM1_ADR_END_H - FWREG_BOOT_SELECT); i++){
		if(eeprom_read_byte(i, (pNvram + i)) == ERROR){//��ȡSIM EPROM���� ����̼�1
			break;
		}
	}
	switch(NVRAM0[FWREG_BOOT_SELECT]){
		case BOOTLOAD_SEL_FWM0:
			break;
		case BOOTLOAD_SEL_FWM1:{
//			//����̼�2 CRC
			temp = (uint32_t)NVRAM0[FWREG_FWM1_SIZE_L] + (uint32_t)(NVRAM0[FWREG_FWM1_SIZE_H] << 16);
			 FLASH_ByteRead((FLADDR) src+i, srcSFLE),
			if(crc == NVRAM0[FWREG_FWM1_CRC16]){//�̼�2 CRCУ��ɹ�
				
			}
			break;
		}
		default:break;
	}
}


void loadFirmware(uint8_t *fname){//���¹̼�
	
}
void saveFirmware(uint8_t *fname){//����̼�
	//
}

