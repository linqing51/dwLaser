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
	
	
	st = CH376FileOpen(CONFIG_SCHEME_FILE_NAME);//打开文件,该文件在根目录下
	if(st != USB_INT_SUCCESS){//文件打开失败
		SET(SPCOIL_USBDISK_OPEN_FILE_FAIL);
		//goto UPDATE_FW_ERROR;
	}
	fileSize = CH376GetFileSize();//读取当前文件长度
	st = CH376ByteLocate(0);//移到文件头
	//st = CH376ByteRead((uint8_t*)(&newFwConfig), sizeof(newFwConfig), NULL);
	if(st != USB_INT_SUCCESS){//文件读取失败
		SET(SPCOIL_USBDISK_READ_FILE_FAIL);
		//goto UPDATE_FW_ERROR;
	}
	st = CH376FileClose(true);//关闭自动计算文件长度
	if(st != USB_INT_SUCCESS){//文件关闭失败
		SET(SPCOIL_USBDISK_CLOSE_FILE_FAIL);
		//goto UPDATE_FW_ERROR;
	}
#endif	
}