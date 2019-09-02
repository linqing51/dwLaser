#include "lib.h"
#include "InitDevice.h"
/*****************************************************************************/
typedef struct BinInfo_t{
	uint32_t address;//引导程序起始地址
	uint32_t length;//引导程序容量
	uint32_t version;//引导程序版本
	uint32_t crc32;//引导程序校CRC32验码	
};

typedef struct BootloadInfo_t{
	BinInfo_t BL_APP;//引导程序
	BinInfo_t OTA0_APP;//可升级固件0
	BinInfo_t OTA1_APP;//可升级固件1
	uint8_t bootOrder;//引导顺序
};

BootloadInfo_t BootloadInfo;

//void bootloader(void){
//	uint32_t *pboot;
//	firmwareInfo_t *st;
//	st = firmwareInfo;
//	//触摸屏
//	
//	//读取FLASH中information信息
//	
//	//判断bootSequence顺序
//	
//	switch(st->bootSequence){
//		case BOOT_OTA0:{
//			break;
//		}
//		case BOOT_OTA1:{
//			break;
//		}
//		case BOOT_ORIGINAL:{
//		}
//		default:BOOT_USB:{
//			break;
//		}
//	}
//}
uint16_t getOnChipFlashCrc32(uint32_t adr, uint32_t len){//获取固件CRC32值
	return 0;
}
//void getEpromConfig(BootloadConfig_t *st){//从FLASH中读取固件配置信息
//}


void main(void){
	initDevice();
	//从USB读取更新配置文件
	//未发现更新配置文件->启动应用程序
	//发现更新配置文件->启动更新程序
	//查询是否需要更新MCU Firmware
	//查询当前
}
