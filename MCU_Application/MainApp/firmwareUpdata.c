#include "firmwareUpdata.h"
/*****************************************************************************/
xdata fwConfig_t oldFwConfig, newFwConfig;
/***************************************************************************/
void upDateHmi(void){//����HMI�̼�
	
}
void upDateFirmwareInit(void){//�̼����ó�ʼ��
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
void upDateFirmware(void){//����MCU 2nd �̼�
	uint8_t filebuf[CONFIG_FIRMWARE_UPDATE_PAGE_SIZE];
	uint8_t filePageSize, fileRemainSize, st;
	uint16_t fileCrc16, i;
	uint32_t fileSize;
	FLADDR tempFAR;
	uint8_t *tempFP;
	//�ر�ȫ���ж�
	disableSplcIsr();
	//�ر�Ӳ��DAC���
	NVRAM0[SPREG_DAC_0] = 0;
	NVRAM1[SPREG_DAC_1] = 0;
	DAC0 = 0;DAC1 = 0;
	//�򿪷���
	//�رռ�ʱ���ж�
	//��մ����־
	RES(SPCOIL_SIMEPROM_READ_FAIL);
	RES(SPCOIL_SIMEPROM_WRITE_FAIL);
	RES(SPCOIL_USBDISK_OPEN_FILE_FAIL);
	RES(SPCOIL_USBDISK_READ_FILE_FAIL);
	RES(SPCOIL_USBDISK_WRITE_FILE_FAIL);
	RES(SPCOIL_USBDISK_CLOSE_FILE_FAIL);
	//��SIMEPROM��ȡ��ǰ�̼�������Ϣ->oldFwConfig.ini
	for(i = 0;i< sizeof(oldFwConfig) ;i++){
		if(eeprom_read_byte(i, (uint8_t*)(&oldFwConfig)) == ERROR){//simEprom��ȡʧ��
			SET(SPCOIL_SIMEPROM_READ_FAIL);
			goto UPDATE_FW_ERROR;
		}
    }
	//��U�̶�ȡ�̼�������Ϣ->newFwConfig.ini
	st = CH376FileOpen(CONFIG_FW_CONFIG_FILE_NAME);//���ļ�,���ļ��ڸ�Ŀ¼��
	if(st != USB_INT_SUCCESS){//�ļ���ʧ��
		SET(SPCOIL_USBDISK_OPEN_FILE_FAIL);
		goto UPDATE_FW_ERROR;
	}
	fileSize = CH376GetFileSize();//��ȡ��ǰ�ļ�����
	st = CH376ByteLocate(0);//�Ƶ��ļ�ͷ
	st = CH376ByteRead((uint8_t*)(&newFwConfig), sizeof(newFwConfig), NULL);
	if(st != USB_INT_SUCCESS){//�ļ���ȡʧ��
		SET(SPCOIL_USBDISK_READ_FILE_FAIL);
		goto UPDATE_FW_ERROR;
	}
	st = CH376FileClose(TRUE);//�ر��Զ������ļ�����
	if(st != USB_INT_SUCCESS){//�ļ��ر�ʧ��
		SET(SPCOIL_USBDISK_CLOSE_FILE_FAIL);
		goto UPDATE_FW_ERROR;
	}	
	if(oldFwConfig.HW_CODE != newFwConfig.HW_CODE){//�Ƚ�Ӳ���ͺ��Ƿ�ƥ��
		//Ӳ���ͺŲ�ƥ��
		goto UPDATE_FW_ERROR;
	}
	if(oldFwConfig.HW_VER != newFwConfig.HW_VER){//�Ƚ�Ӳ���汾�Ƿ�ƥ��
		//Ӳ���汾��ƥ��
		goto UPDATE_FW_ERROR;
	}
	if(oldFwConfig.FW_VER >= newFwConfig.FW_VER){//�ȽϹ̼��汾�Ƿ���Ҫ����
		//�����¹̼��汾�����й̼��ɵ�������
		goto UPDATE_FW_ERROR;
	}		
	if(newFwConfig.FW_SIZE > CONFIG_FW_STORAGE_SIZE){//�ȽϹ̼������Ƿ�����ݴ���
		//�����¹̼���������������
		goto UPDATE_FW_ERROR;
	}
	//���浱ǰ����MCU�̼���UDISK
#if CONFIG_FW_ORIGINAL_SAVE == 1
	st = CH376FileOpen(CONFIG_FW_MCU_FILE_SAVE_NAME);//���ļ�,���ļ��ڸ�Ŀ¼��
	if(st != USB_INT_SUCCESS){//�ļ���ʧ��
		SET(SPCOIL_USBDISK_OPEN_FILE_FAIL);
		goto UPDATE_FW_ERROR;
	}
#endif
	//��U�̶�ȡ�̼�firmware.bin���洢�ڴ�ˢ����
	st = CH376FileOpen(CONFIG_FW_MCU_FILE_LOAD_NAME);//���ļ�,���ļ��ڸ�Ŀ¼��
	if(st != USB_INT_SUCCESS){//�ļ���ʧ��
		SET(SPCOIL_USBDISK_OPEN_FILE_FAIL);
		goto UPDATE_FW_ERROR;
	}				
	fileSize = CH376GetFileSize();//��ȡ��ǰ�ļ�����
	if(fileSize != newFwConfig.FW_SIZE){//�¹̼��ļ����ȴ���
		goto UPDATE_FW_ERROR;
	}
	st = CH376ByteLocate(0);//�Ƶ��ļ�ͷ
	filePageSize = newFwConfig.FW_SIZE / CONFIG_FIRMWARE_UPDATE_PAGE_SIZE;
	fileRemainSize = newFwConfig.FW_SIZE % CONFIG_FIRMWARE_UPDATE_PAGE_SIZE;
	tempFAR = CONFIG_FW_STORAGE_ADR;
	tempFP = filebuf;
	for(i = 0;i < filePageSize;i ++){
		st = CH376ByteRead(tempFP, CONFIG_FIRMWARE_UPDATE_PAGE_SIZE, NULL);
		if(st != USB_INT_SUCCESS){//��ȡ�̼�����
			SET(SPCOIL_USBDISK_READ_FILE_FAIL);
			goto UPDATE_FW_ERROR;
		}
		FLASH_Clear(tempFAR, CONFIG_FIRMWARE_UPDATE_PAGE_SIZE, 0);//Clear Flash->0xFF
		FLASH_Write(tempFAR, tempFP, CONFIG_FIRMWARE_UPDATE_PAGE_SIZE, 0);//fileBuf->Flash
		tempFAR += CONFIG_FIRMWARE_UPDATE_PAGE_SIZE;
		tempFP += CONFIG_FIRMWARE_UPDATE_PAGE_SIZE;
	}
	if(fileRemainSize != 0){//����д��ʣ���ֽ�
		FLASH_Clear(tempFAR, fileRemainSize, 0);//Clear Flash->0xFF
		FLASH_Write(tempFAR, tempFP, fileRemainSize, 0);//fileBuf->Flash
		tempFAR += fileRemainSize;
		tempFP += fileRemainSize;
	}
	st = CH376FileClose(TRUE);//�ر��Զ������ļ�����
	if(st != USB_INT_SUCCESS){//�ļ���ȡʧ��
		SET(SPCOIL_USBDISK_CLOSE_FILE_FAIL);
		goto UPDATE_FW_ERROR;
	}
	//У���ˢ�����̼�CRC16
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
	//�Ƚϼ���õ�CRC16�������ļ��Ƿ���ͷ
	if(newFwConfig.FW_CRC16 != fileCrc16){//�ж���д���ݴ����ڵĹ̼�CRCֵ��ȷ
		goto UPDATE_FW_ERROR;	
	}
	//����Bootloadˢ��ִ��������
	newFwConfig.UREQ = CONFIG_FW_UPDATE_REQ_FLAG;
    for(i = 0;i< sizeof(newFwConfig) ;i++){//����FLASH�����ļ�
		if(eeprom_read_byte(i, (uint8_t*)(&newFwConfig)) == ERROR){//simEprom��ȡʧ��
			SET(SPCOIL_SIMEPROM_WRITE_FAIL);
			goto UPDATE_FW_ERROR;
		}
	}
#if CONFIG_DEBUG == 1
	printf("Info:Update 2nd firmware successful.\n");
#endif
	mucReboot();//��λ��Ƭ��
	//return;
UPDATE_FW_ERROR:
	{
		delayMs(1);
		enableSplcIsr();
	}
}


