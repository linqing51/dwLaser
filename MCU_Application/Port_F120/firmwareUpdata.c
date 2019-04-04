#include "firmwareUpdata.h"
/*****************************************************************************/
#define FIRMWARE_UPDATE_REQ								0x5A;
typedef struct{
	uint8_t updateReq;//固件更新请求
	uint8_t hardwareCode;//硬件型号
	uint8_t hardwareVer;//硬件版本
	uint8_t firmwareVer;//待更新固件版本
	uint16_t firmwareCrc16;//待更新固件CRC8值
	uint16_t firmwareSize;//待更新固件容量
}fwConfig_t;
xdata fwConfig_t oldFwConfig, newFwConfig;
/***************************************************************************/


void upDateHmi(uint8_t *fname){//更新HMI固件
	
}
void upDateFirmware(uint8_t *fname){//更新MCU固件
	uint8_t fileReadbuf[CONFIG_FIRMWARE_UPDATE_PAGE_SIZE];
	uint8_t fileWritebuf[CONFIG_FIRMWARE_UPDATE_PAGE_SIZE];
	uint8_t filePageSize, fileRemainSize;
	uint16_t fileCrc16, i;
	uint32_t fileSize, fileAddr;
	//关闭硬件DAC输出
	//打开风扇
	//关闭计时器中断
	
	
	//从SIMEPROM读取当前固件配置信息->oldFwConfig.ini
	
	
	//从U盘读取固件配置信息->newFwConfig.ini
	if(oldFwConfig.hardwareCode == newFwConfig.hardwareCode){//比较硬件型号是否匹配
		if(oldFwConfig.hardwareVer == newFwConfig.hardwareVer){//比较硬件版本是否匹配
			if(oldFwConfig.firmwareVer < newFwConfig.firmwareVer){//比较固件版本是否需要更新
				if(newFwConfig.firmwareSize <= CONFIG_FW_STORAGE_SIZE){//比较固件容量是否大于暂存区
					//从U盘读取固件firmware.bin并存储在待刷新区
					
					//校验待刷新区固件CRC16
					fileCrc16 = 0;
					filePageSize = fileSize / CONFIG_FIRMWARE_UPDATE_PAGE_SIZE;
					fileRemainSize = fileSize % CONFIG_FIRMWARE_UPDATE_PAGE_SIZE;
					fileAddr = CONFIG_FW_STORAGE_ADR;
					crc16Clear();
					for(i = 0;i < filePageSize;i ++){
						FLASH_Read(fileReadbuf, fileAddr, CONFIG_FIRMWARE_UPDATE_PAGE_SIZE, 0);
						fileAddr += CONFIG_FIRMWARE_UPDATE_PAGE_SIZE;
						crc16Calculate(fileReadbuf, CONFIG_FIRMWARE_UPDATE_PAGE_SIZE);
					}
					FLASH_Read(fileReadbuf, fileAddr, fileRemainSize, 0);
					fileCrc16 = crc16Calculate(fileReadbuf, fileRemainSize);
					//比较计算得到CRC16与配置文件是否线头
					if(newFwConfig.firmwareCrc16 == fileCrc16){//判断已写入暂存区内的固件CRC值正确
						//更新Bootload刷新执行区请求
						newFwConfig.updateReq = FIRMWARE_UPDATE_REQ;
						mucReboot();//复位单片机
					}
				}
				else{
					//大于暂存区
					//显示错误
				}
				
			}
			else{
				//当前固件版本无需更新
				//显示错误信息
			}
		}
		else{
			//硬件版本不匹配
			//显示错误信息
		}
	}
	else{
		//硬件型号不匹配
		//显示错误信息
	}
	
	
	
	//比较计算得到CRC16与配置文件是否线头
	//比较相同 更新附件更新请求
	//重新启动MCU
}

