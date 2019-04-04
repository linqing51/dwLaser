#include "firmwareUpdata.h"
/*****************************************************************************/
#define FIRMWARE_UPDATE_REQ								0x5A;
typedef struct{
	uint8_t updateReq;//�̼���������
	uint8_t hardwareCode;//Ӳ���ͺ�
	uint8_t hardwareVer;//Ӳ���汾
	uint8_t firmwareVer;//�����¹̼��汾
	uint16_t firmwareCrc16;//�����¹̼�CRC8ֵ
	uint16_t firmwareSize;//�����¹̼�����
}fwConfig_t;
xdata fwConfig_t oldFwConfig, newFwConfig;
/***************************************************************************/


void upDateHmi(uint8_t *fname){//����HMI�̼�
	
}
void upDateFirmware(uint8_t *fname){//����MCU�̼�
	uint8_t fileReadbuf[CONFIG_FIRMWARE_UPDATE_PAGE_SIZE];
	uint8_t fileWritebuf[CONFIG_FIRMWARE_UPDATE_PAGE_SIZE];
	uint8_t filePageSize, fileRemainSize;
	uint16_t fileCrc16, i;
	uint32_t fileSize, fileAddr;
	//�ر�Ӳ��DAC���
	//�򿪷���
	//�رռ�ʱ���ж�
	
	
	//��SIMEPROM��ȡ��ǰ�̼�������Ϣ->oldFwConfig.ini
	
	
	//��U�̶�ȡ�̼�������Ϣ->newFwConfig.ini
	if(oldFwConfig.hardwareCode == newFwConfig.hardwareCode){//�Ƚ�Ӳ���ͺ��Ƿ�ƥ��
		if(oldFwConfig.hardwareVer == newFwConfig.hardwareVer){//�Ƚ�Ӳ���汾�Ƿ�ƥ��
			if(oldFwConfig.firmwareVer < newFwConfig.firmwareVer){//�ȽϹ̼��汾�Ƿ���Ҫ����
				if(newFwConfig.firmwareSize <= CONFIG_FW_STORAGE_SIZE){//�ȽϹ̼������Ƿ�����ݴ���
					//��U�̶�ȡ�̼�firmware.bin���洢�ڴ�ˢ����
					
					//У���ˢ�����̼�CRC16
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
					//�Ƚϼ���õ�CRC16�������ļ��Ƿ���ͷ
					if(newFwConfig.firmwareCrc16 == fileCrc16){//�ж���д���ݴ����ڵĹ̼�CRCֵ��ȷ
						//����Bootloadˢ��ִ��������
						newFwConfig.updateReq = FIRMWARE_UPDATE_REQ;
						mucReboot();//��λ��Ƭ��
					}
				}
				else{
					//�����ݴ���
					//��ʾ����
				}
				
			}
			else{
				//��ǰ�̼��汾�������
				//��ʾ������Ϣ
			}
		}
		else{
			//Ӳ���汾��ƥ��
			//��ʾ������Ϣ
		}
	}
	else{
		//Ӳ���ͺŲ�ƥ��
		//��ʾ������Ϣ
	}
	
	
	
	//�Ƚϼ���õ�CRC16�������ļ��Ƿ���ͷ
	//�Ƚ���ͬ ���¸�����������
	//��������MCU
}

