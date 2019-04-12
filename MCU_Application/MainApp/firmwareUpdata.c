#include "firmwareUpdata.h"
/*****************************************************************************/
xdata fwConfig_t oldFwConfig, newFwConfig;
/***************************************************************************/
void upDateHmi(void){//更新HMI固件
	
}
void upDateFirmwareInit(void){//固件配置初始化
	oldFwConfig.UREQ = 0;
	oldFwConfig.HW_CODE = 0;
	oldFwConfig.HW_VER = 0;
	oldFwConfig.FW_VER = 0;
	oldFwConfig.FW_SIZE = 0;
	
	newFwConfig.UREQ = 0;
	newFwConfig.HW_CODE = 0;
	newFwConfig.HW_VER = 0;
	newFwConfig.FW_VER = 0;
	newFwConfig.FW_SIZE = 0;
}
void upDateFirmware(void){//更新MCU 2nd 固件
	uint8_t filebuf[CONFIG_FIRMWARE_UPDATE_PAGE_SIZE];
	uint8_t filePageSize, fileRemainSize, st;
	uint16_t fileCrc16, i;
	uint32_t fileSize;
	FLADDR tempFAR;
	uint8_t *tempFP;
	//关闭全局中断
	disableSplcIsr();
	//关闭硬件DAC输出
	NVRAM0[SPREG_DAC_0] = 0;
	NVRAM1[SPREG_DAC_1] = 0;
	DAC0 = 0;DAC1 = 0;
	//打开风扇
	//关闭计时器中断
	//清空错误标志
	RES(SPCOIL_SIMEPROM_READ_FAIL);
	RES(SPCOIL_SIMEPROM_WRITE_FAIL);
	RES(SPCOIL_USBDISK_OPEN_FILE_FAIL);
	RES(SPCOIL_USBDISK_READ_FILE_FAIL);
	RES(SPCOIL_USBDISK_WRITE_FILE_FAIL);
	RES(SPCOIL_USBDISK_CLOSE_FILE_FAIL);
	//从SIMEPROM读取当前固件配置信息->oldFwConfig.ini
	for(i = 0;i< sizeof(oldFwConfig) ;i++){
		if(eeprom_read_byte(i, (uint8_t*)(&oldFwConfig)) == ERROR){//simEprom读取失败
			SET(SPCOIL_SIMEPROM_READ_FAIL);
			goto UPDATE_FW_ERROR;
		}
    }
	//从U盘读取固件配置信息->newFwConfig.ini
	st = CH376FileOpen(CONFIG_FW_CONFIG_FILE_NAME);//打开文件,该文件在根目录下
	if(st != USB_INT_SUCCESS){//文件打开失败
		SET(SPCOIL_USBDISK_OPEN_FILE_FAIL);
		goto UPDATE_FW_ERROR;
	}
	fileSize = CH376GetFileSize();//读取当前文件长度
	st = CH376ByteLocate(0);//移到文件头
	st = CH376ByteRead((uint8_t*)(&newFwConfig), sizeof(newFwConfig), NULL);
	if(st != USB_INT_SUCCESS){//文件读取失败
		SET(SPCOIL_USBDISK_READ_FILE_FAIL);
		goto UPDATE_FW_ERROR;
	}
	st = CH376FileClose(TRUE);//关闭自动计算文件长度
	if(st != USB_INT_SUCCESS){//文件关闭失败
		SET(SPCOIL_USBDISK_CLOSE_FILE_FAIL);
		goto UPDATE_FW_ERROR;
	}	
	if(oldFwConfig.HW_CODE != newFwConfig.HW_CODE){//比较硬件型号是否匹配
		//硬件型号不匹配
		goto UPDATE_FW_ERROR;
	}
	if(oldFwConfig.HW_VER != newFwConfig.HW_VER){//比较硬件版本是否匹配
		//硬件版本不匹配
		goto UPDATE_FW_ERROR;
	}
	if(oldFwConfig.FW_VER >= newFwConfig.FW_VER){//比较固件版本是否需要更新
		//待更新固件版本比运行固件旧掉过更新
		goto UPDATE_FW_ERROR;
	}		
	if(newFwConfig.FW_SIZE > CONFIG_FW_STORAGE_SIZE){//比较固件容量是否大于暂存区
		//待更新固件容量超过待存区
		goto UPDATE_FW_ERROR;
	}
	//保存当前运行MCU固件到UDISK
#if CONFIG_FW_ORIGINAL_SAVE == 1
	st = CH376FileOpen(CONFIG_FW_MCU_FILE_SAVE_NAME);//打开文件,该文件在根目录下
	if(st != USB_INT_SUCCESS){//文件打开失败
		SET(SPCOIL_USBDISK_OPEN_FILE_FAIL);
		goto UPDATE_FW_ERROR;
	}
#endif
	//从U盘读取固件firmware.bin并存储在待刷新区
	st = CH376FileOpen(CONFIG_FW_MCU_FILE_LOAD_NAME);//打开文件,该文件在根目录下
	if(st != USB_INT_SUCCESS){//文件打开失败
		SET(SPCOIL_USBDISK_OPEN_FILE_FAIL);
		goto UPDATE_FW_ERROR;
	}				
	fileSize = CH376GetFileSize();//读取当前文件长度
	if(fileSize != newFwConfig.FW_SIZE){//新固件文件长度错误
		goto UPDATE_FW_ERROR;
	}
	st = CH376ByteLocate(0);//移到文件头
	filePageSize = newFwConfig.FW_SIZE / CONFIG_FIRMWARE_UPDATE_PAGE_SIZE;
	fileRemainSize = newFwConfig.FW_SIZE % CONFIG_FIRMWARE_UPDATE_PAGE_SIZE;
	tempFAR = CONFIG_FW_STORAGE_ADR;
	tempFP = filebuf;
	for(i = 0;i < filePageSize;i ++){
		st = CH376ByteRead(tempFP, CONFIG_FIRMWARE_UPDATE_PAGE_SIZE, NULL);
		if(st != USB_INT_SUCCESS){//读取固件错误
			SET(SPCOIL_USBDISK_READ_FILE_FAIL);
			goto UPDATE_FW_ERROR;
		}
		FLASH_Clear(tempFAR, CONFIG_FIRMWARE_UPDATE_PAGE_SIZE, 0);//Clear Flash->0xFF
		FLASH_Write(tempFAR, tempFP, CONFIG_FIRMWARE_UPDATE_PAGE_SIZE, 0);//fileBuf->Flash
		tempFAR += CONFIG_FIRMWARE_UPDATE_PAGE_SIZE;
		tempFP += CONFIG_FIRMWARE_UPDATE_PAGE_SIZE;
	}
	if(fileRemainSize != 0){//持续写入剩余字节
		FLASH_Clear(tempFAR, fileRemainSize, 0);//Clear Flash->0xFF
		FLASH_Write(tempFAR, tempFP, fileRemainSize, 0);//fileBuf->Flash
		tempFAR += fileRemainSize;
		tempFP += fileRemainSize;
	}
	st = CH376FileClose(TRUE);//关闭自动计算文件长度
	if(st != USB_INT_SUCCESS){//文件读取失败
		SET(SPCOIL_USBDISK_CLOSE_FILE_FAIL);
		goto UPDATE_FW_ERROR;
	}
	//校验待刷新区固件CRC16
	fileCrc16 = 0;
	tempFAR = CONFIG_FW_STORAGE_ADR;
	crc16Clear();
	for(i = 0;i < filePageSize;i ++){
		FLASH_Read(filebuf, tempFAR, CONFIG_FIRMWARE_UPDATE_PAGE_SIZE, 0);
		tempFAR += CONFIG_FIRMWARE_UPDATE_PAGE_SIZE;
		crc16Calculate(filebuf, CONFIG_FIRMWARE_UPDATE_PAGE_SIZE);
	}
	if(fileRemainSize != 0){
		FLASH_Read(filebuf, tempFAR, fileRemainSize, 0);
		fileCrc16 = crc16Calculate(filebuf, fileRemainSize);
	}
	//比较计算得到CRC16与配置文件是否线头
	if(newFwConfig.FW_CRC16 != fileCrc16){//判断已写入暂存区内的固件CRC值正确
		goto UPDATE_FW_ERROR;	
	}
	//更新Bootload刷新执行区请求
	newFwConfig.UREQ = CONFIG_FW_UPDATE_REQ_FLAG;
    for(i = 0;i< sizeof(newFwConfig) ;i++){//更新FLASH配置文件
		if(eeprom_read_byte(i, (uint8_t*)(&newFwConfig)) == ERROR){//simEprom读取失败
			SET(SPCOIL_SIMEPROM_WRITE_FAIL);
			goto UPDATE_FW_ERROR;
		}
	}
#if CONFIG_DEBUG == 1
	printf("Info:Update 2nd firmware successful.\n");
#endif
	mucReboot();//复位单片机
	//return;
UPDATE_FW_ERROR:
	{
		delayMs(1);
		enableSplcIsr();
	}
}


