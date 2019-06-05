#ifndef __SPLCDK25L_H__
#define __SPLCDK25L_H__

/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/

#define DK25L_STX								0xAA//
//通用指令
#define CMD_FIND_CARD_UID						0x01//获取卡片UID
#define CMD_FIND_CARD_TYPE						0x02//获取卡片类型
#define CMD_AUTO_FIND_CARD						0x95//自动寻卡开关
#define CMD_MOD_BAUDRATE						0xA0//修改模块波特率
#define CMD_CONFIG_SYS_PARA						0xA1//配置系统参数指令
#define CMD_READ_SYS_PARA						0xA2//读取系统参数指令
#define CMD_READ_FW_VER							0xB0//获取模块固件版本号
#define CMD_READ_HW_VER							0xB1//获取模块硬件版本号
//Mifare指令
#define CMD_MIFARE_SET_KEYA						0x03//向模块写入需要验证的密钥(A密钥)
#define CMD_MIFARE_GET_BLOCK					0x04//Mifare 卡读块
#define CMD_MIFARE_SET_BLOCK					0x05//Mifare 卡写块
#define CMD_MIFATE_INIT							0x06//Mifare 卡增减值初始化
#define CMD_MIFARE_ADD							0x07//Mifare 卡增值
#define CMD_MIFARE_DEC							0x08//Mifare 卡减值
#define CMD_MIFARE_SET_KEYB						0x0B//西安模块写入需要验证的密钥(B密钥)
#define CMD_MIFARE_SET_KEY_CLASS				0x0C//设置模块使用密钥的类型
//Ultralight 卡操作指令
#define CMD_ULTRALIGHT_GET_BLOCK				0x09//Ultralight卡读块
#define CMD_ULTRALIGHT_GET_MBLOCK				0x1C//Ultralight卡读多个块
#define CMD_ULTRALIGHT_SET_MBLOCK				0x1D//Ultralight卡写多个块
//ISO14443-A CPU卡操作指令
#define CMD_ISO14443_ACTIVATE					0x15//ISO14443-A CPU卡片激活指令
#define CMD_ISO14443_APDU						0x17//ISO14443-A CPU卡APDU指令接口
#define CMD_ISO14443_POWEROFF					0x18//ISO14443-A CPU卡片断电指令
//身份证
#define CMD_IDCARD_ACTIVATE						0x14//身份证激活指令
#define CMD_IDCARD_APDU							0x16//身份证APDU指令接口
#define CMD_IDCARD_POWEROFF						0x18//卡片断电指令、关闭天线指令接口
//ISO15693
#define CMD_ISO15693_GET_BLOCK					0x09//ISO15693卡读块
#define CMD_ISO15693_GET_MBLOCK					0x1C//ISO15693卡读多个块
#define CMD_ISO15693_SET_MBLOCK					0x1D//ISO15693卡写多个块
//模块反馈
#define CMD_ERR_CLASS							0xE0//卡类型错误反馈指令	
#define CMD_ERR_NOT_FIND						0xE1//未寻找卡错误反馈指令
#define CMD_ERR_NOT_MACH						0xE2//密钥不匹配错误反馈指令
#define CMD_ERR_GET								0xE3//读块失败错误指令
#define CMD_ERR_SET								0xE4//写块失败错误指令
#define CMD_ERR_M1_INIT							0xE5//M1卡值初始化失败错误指令
#define CMD_ERR_M1_ADD							0xE6//M1卡增值失败错误指令
#define CMD_ERR_M1_DEC							0xE7//M1卡减值失败错误指令
#define CMD_ACK									0xFE//ACK确认命令
#define CMD_NACK								0xFF//NACK否认命令



#define CARD_UNKNOWN							0x00
#define CARD_MIFARE								0x01
#define CARD_ULTRALIGHT							0x02
#define CARD_ISO14443B							0x03
#define CARD_ISO14443A							0x04
#define CARD_ISO15693							0x05

#endif