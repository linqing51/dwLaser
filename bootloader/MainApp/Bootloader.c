#include "lib.h"
#include "InitDevice.h"
/*****************************************************************************/
typedef struct firmwareInfo_t{
	uint32_t address;//����������ʼ��ַ
	uint32_t length;//������������
	uint32_t version;//��������汾
	uint32_t crc32;//��������УCRC32����	
};



//typedef struct BootloadConfig_t{//
//	firmwareInfo_t BL_APP;//��������
//	firmwareInfo_t OTA0_APP;//�������̼�0
//	firmwareInfo_t OTA1_APP;//�������̼�1
//	firmwareInfo_t ORIGINAL_APP;//ԭʼ���ݹ̼�
//	uint8_t bootSequence;//����˳��
//};
//#define BOOT_OTA0				0x81
//#define BOOT_OTA1				0x82
//#define BOOT_ORIGINAL			0X83
//#define BOOT_USB				0x84



//void bootloader(void){
//	uint32_t *pboot;
//	firmwareInfo_t *st;
//	st = firmwareInfo;
//	//������
//	
//	//��ȡFLASH��information��Ϣ
//	
//	//�ж�bootSequence˳��
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
uint16_t getOnChipFlashCrc32(uint32_t adr, uint32_t len){//��ȡ�̼�CRC32ֵ
	return 0;
}
//void getEpromConfig(BootloadConfig_t *st){//��FLASH�ж�ȡ�̼�������Ϣ
//}


void main(void){
	initDevice();
	//��USB��ȡ���������ļ�
	//δ���ָ��������ļ�->����Ӧ�ó���
	//���ָ��������ļ�->�������³���
	//��ѯ�Ƿ���Ҫ����MCU Firmware
	//��ѯ��ǰ
}
