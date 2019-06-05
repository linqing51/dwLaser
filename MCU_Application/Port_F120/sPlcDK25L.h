#ifndef __SPLCDK25L_H__
#define __SPLCDK25L_H__

/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/

#define DK25L_STX								0xAA//
//ͨ��ָ��
#define CMD_FIND_CARD_UID						0x01//��ȡ��ƬUID
#define CMD_FIND_CARD_TYPE						0x02//��ȡ��Ƭ����
#define CMD_AUTO_FIND_CARD						0x95//�Զ�Ѱ������
#define CMD_MOD_BAUDRATE						0xA0//�޸�ģ�鲨����
#define CMD_CONFIG_SYS_PARA						0xA1//����ϵͳ����ָ��
#define CMD_READ_SYS_PARA						0xA2//��ȡϵͳ����ָ��
#define CMD_READ_FW_VER							0xB0//��ȡģ��̼��汾��
#define CMD_READ_HW_VER							0xB1//��ȡģ��Ӳ���汾��
//Mifareָ��
#define CMD_MIFARE_SET_KEYA						0x03//��ģ��д����Ҫ��֤����Կ(A��Կ)
#define CMD_MIFARE_GET_BLOCK					0x04//Mifare ������
#define CMD_MIFARE_SET_BLOCK					0x05//Mifare ��д��
#define CMD_MIFATE_INIT							0x06//Mifare ������ֵ��ʼ��
#define CMD_MIFARE_ADD							0x07//Mifare ����ֵ
#define CMD_MIFARE_DEC							0x08//Mifare ����ֵ
#define CMD_MIFARE_SET_KEYB						0x0B//����ģ��д����Ҫ��֤����Կ(B��Կ)
#define CMD_MIFARE_SET_KEY_CLASS				0x0C//����ģ��ʹ����Կ������
//Ultralight ������ָ��
#define CMD_ULTRALIGHT_GET_BLOCK				0x09//Ultralight������
#define CMD_ULTRALIGHT_GET_MBLOCK				0x1C//Ultralight���������
#define CMD_ULTRALIGHT_SET_MBLOCK				0x1D//Ultralight��д�����
//ISO14443-A CPU������ָ��
#define CMD_ISO14443_ACTIVATE					0x15//ISO14443-A CPU��Ƭ����ָ��
#define CMD_ISO14443_APDU						0x17//ISO14443-A CPU��APDUָ��ӿ�
#define CMD_ISO14443_POWEROFF					0x18//ISO14443-A CPU��Ƭ�ϵ�ָ��
//���֤
#define CMD_IDCARD_ACTIVATE						0x14//���֤����ָ��
#define CMD_IDCARD_APDU							0x16//���֤APDUָ��ӿ�
#define CMD_IDCARD_POWEROFF						0x18//��Ƭ�ϵ�ָ��ر�����ָ��ӿ�
//ISO15693
#define CMD_ISO15693_GET_BLOCK					0x09//ISO15693������
#define CMD_ISO15693_GET_MBLOCK					0x1C//ISO15693���������
#define CMD_ISO15693_SET_MBLOCK					0x1D//ISO15693��д�����
//ģ�鷴��
#define CMD_ERR_CLASS							0xE0//�����ʹ�����ָ��	
#define CMD_ERR_NOT_FIND						0xE1//δѰ�ҿ�������ָ��
#define CMD_ERR_NOT_MACH						0xE2//��Կ��ƥ�������ָ��
#define CMD_ERR_GET								0xE3//����ʧ�ܴ���ָ��
#define CMD_ERR_SET								0xE4//д��ʧ�ܴ���ָ��
#define CMD_ERR_M1_INIT							0xE5//M1��ֵ��ʼ��ʧ�ܴ���ָ��
#define CMD_ERR_M1_ADD							0xE6//M1����ֵʧ�ܴ���ָ��
#define CMD_ERR_M1_DEC							0xE7//M1����ֵʧ�ܴ���ָ��
#define CMD_ACK									0xFE//ACKȷ������
#define CMD_NACK								0xFF//NACK��������



#define CARD_UNKNOWN							0x00
#define CARD_MIFARE								0x01
#define CARD_ULTRALIGHT							0x02
#define CARD_ISO14443B							0x03
#define CARD_ISO14443A							0x04
#define CARD_ISO15693							0x05

#endif