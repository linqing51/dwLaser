#include "firmwareUpdata.h"
/*****************************************************************************/

/*****************************************************************************/
typedef struct firmwareInfo_t{
	uint16_t fw_ver;//�̼��汾
	uint16_t hw_ver;//Ӳ���汾
	uint16_t fw_crc;//�̼�CRCУ����
	uint32_t fw_size;//�̼�����
	uint8_t  fw_type;//�̼����� 
};

