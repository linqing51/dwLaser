#include "usbApp.h"
/*****************************************************************************/
void saveSchemeUsb(void){
#if CONFIG_SPLC_USING_CH376 == 1
	uint8_t filePageSize, fileRemainSize, st;
	uint16_t fileCrc16, i;
	uint32_t fileSize;
	//FLADDR tempFAR;
	
	st = CH376DiskConnect();
	
	st = CH376DiskMount();
	
	
	st = CH376FileOpen(CONFIG_SCHEME_FILE_NAME);//���ļ�,���ļ��ڸ�Ŀ¼��
	if(st != USB_INT_SUCCESS){//�ļ���ʧ��
		SET(SPCOIL_USBDISK_OPEN_FILE_FAIL);
		//goto UPDATE_FW_ERROR;
	}
	fileSize = CH376GetFileSize();//��ȡ��ǰ�ļ�����
	st = CH376ByteLocate(0);//�Ƶ��ļ�ͷ
	//st = CH376ByteRead((uint8_t*)(&newFwConfig), sizeof(newFwConfig), NULL);
	if(st != USB_INT_SUCCESS){//�ļ���ȡʧ��
		SET(SPCOIL_USBDISK_READ_FILE_FAIL);
		//goto UPDATE_FW_ERROR;
	}
	st = CH376FileClose(true);//�ر��Զ������ļ�����
	if(st != USB_INT_SUCCESS){//�ļ��ر�ʧ��
		SET(SPCOIL_USBDISK_CLOSE_FILE_FAIL);
		//goto UPDATE_FW_ERROR;
	}
#endif	
}