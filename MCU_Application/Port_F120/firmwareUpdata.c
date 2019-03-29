#include "firmwareUpdata.h"
/*****************************************************************************/

/*****************************************************************************/
typedef struct firmwareInfo_t{
	uint16_t fw_ver;//固件版本
	uint16_t hw_ver;//硬件版本
	uint16_t fw_crc;//固件CRC校验码
	uint32_t fw_size;//固件容量
	uint8_t  fw_type;//固件类型 
};
void usbHostInit(void){//USB CH376初始化
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE	    
	//SPI总线初始化
	SFRPAGE = SPI0_PAGE;
	SPI0CKR = (CONFIG_SYSCLK / (2 * CONFIG_SPICLK));//设置SPI时钟频率
	SPI0CFG = 0x0;//CKPOL=0, CKPHA=0
	SPI0CFG |= 1 << 6;//MSTEN: Master Mode Enable.
	SPI0CN = 0x0;
	SPI0CN |= (1 << 2);
	SPI0CN |= (1 << 3);//1x: 4-Wire Single-Master Mode. NSS signal is mapped as an output from the device and will
					   //assume the value of NSSMD0.
	SPI0CN |= 1 << 0;//SPIEN: SPI0 Enable.
    SFRPAGE = SFRPAGE_save; 
}
