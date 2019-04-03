#include "firmwareUpdata.h"
/*****************************************************************************/

/*****************************************************************************/

void bootLoad(void){
	if(NVRAM0[SPREG_BOOT_SELECT] == 0){
	}
	else if()
	NVRAM0[SPREG_BOOT_SELECT] = 
	    	if(eeprom_read_byte(i,&test_buf[i]) == ERROR)
    		goto error;
	//读取固件配置参数
	//判断是否引导第二固件
	//引导第二固件
}


void loadFirmware(uint8_t *fname){//更新固件
	
}
void saveFirmware(uint8_t *fname){//保存固件
	//
}

