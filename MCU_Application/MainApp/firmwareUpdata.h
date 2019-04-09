#ifndef __FIRMWAREUPDATE_H__
#define __FIRMWAREUPDATE_H__
/*****************************************************************************/
#include "sPlcPort.h"
#include "sPlc.h"
/*****************************************************************************/
typedef struct{
	uint8_t UREQ;//固件更新请求
	uint8_t HW_CODE;//硬件型号
	uint8_t HW_VER;//硬件版本
	uint8_t FW_VER;//待更新固件版本
	uint16_t FW_CRC16;//待更新固件CRC8值
	uint16_t FW_SIZE;//待更新固件容量
}fwConfig_t;
/*****************************************************************************/
void upDateFirmwareInit(void);//固件配置初始化
void upDateFirmware(void);//更新MCU 2nd 固件
void upDateHmi(void);//更新HMI固件
/*****************************************************************************/
#endif

