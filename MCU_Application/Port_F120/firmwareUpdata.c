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

