#ifndef __SPLCDK25L_H__
#define __SPLCDK25L_H__
/*****************************************************************************/
#include "sPlcPort.h"
/*****************************************************************************/
#define DK25L_FWVER												0x12
#define DK25L_HWVER												0x34
/*****************************************************************************/
#define DK25L_STX												0xAA//
//通用指令
#define CMD_FIND_CARD_UID										0x01//获取卡片UID
#define CMD_FIND_CARD_TYPE										0x02//获取卡片类型
#define CMD_AUTO_FIND_CARD										0x95//自动寻卡开关
#define CMD_MOD_BAUDRATE										0xA0//修改模块波特率
#define CMD_CONFIG_SYS_PARA										0xA1//配置系统参数指令
#define CMD_READ_SYS_PARA										0xA2//读取系统参数指令
#define CMD_READ_FW_VER											0xB0//获取模块固件版本号
#define CMD_READ_HW_VER											0xB1//获取模块硬件版本号
//Mifare指令
#define CMD_MIFARE_SET_KEYA										0x03//向模块写入需要验证的密钥(A密钥)
#define CMD_MIFARE_READ_BLOCK									0x04//Mifare 卡读块
#define CMD_MIFARE_WRITE_BLOCK									0x05//Mifare 卡写块
#define CMD_MIFATE_WALLET_INIT									0x06//Mifare 卡增减值初始化
#define CMD_MIFARE_WALLET_CHARGE								0x07//Mifare 卡增值
#define CMD_MIFARE_WALLET_CHARGEBACK							0x08//Mifare 卡减值
#define CMD_MIFARE_SET_KEYB										0x0B//西安模块写入需要验证的密钥(B密钥)
#define CMD_MIFARE_SET_KEY_TYPE									0x0C//设置模块使用密钥的类型
//Ultralight 卡操作指令
#define CMD_ULTRALIGHT_READ_BLOCK								0x09//Ultralight卡读块
#define CMD_ULTRALIGHT_WRITE_BLOCK								0x0A//Ultralight卡写块
#define CMD_ULTRALIGHT_READ_MBLOCK								0x1C//Ultralight卡读多个块
#define CMD_ULTRALIGHT_SET_MBLOCK								0x1D//Ultralight卡写多个块
//ISO14443-A CPU卡操作指令
#define CMD_ISO14443A_ACTIVATE									0x15//ISO14443-A CPU卡片激活指令
#define CMD_ISO14443A_APDU										0x17//ISO14443-A CPU卡APDU指令接口
#define CMD_ISO14443A_POWEROFF									0x18//ISO14443-A CPU卡片断电指令
//ISO14443-B身份证
#define CMD_ISO14443B_ACTIVATE									0x14//身份证激活指令
#define CMD_ISO14443B_APDU										0x16//身份证APDU指令接口
#define CMD_ISO14443B_POWEROFF									0x18//卡片断电指令、关闭天线指令接口
//ISO15693
#define CMD_ISO15693_GET_BLOCK									0x09//ISO15693卡读块
#define CMD_ISO15693_GET_MBLOCK									0x1C//ISO15693卡读多个块
#define CMD_ISO15693_SET_MBLOCK									0x1D//ISO15693卡写多个块
//模块反馈
#define CMD_ERR_TAG_TYPE										0xE0//卡类型错误反馈指令	
#define CMD_ERR_NOT_FIND										0xE1//未寻找卡错误反馈指令
#define CMD_ERR_NOT_MACH										0xE2//密钥不匹配错误反馈指令
#define CMD_ERR_GET												0xE3//读块失败错误指令
#define CMD_ERR_SET												0xE4//写块失败错误指令
#define CMD_ERR_M1_INIT											0xE5//M1卡值初始化失败错误指令
#define CMD_ERR_M1_ADD											0xE6//M1卡增值失败错误指令
#define CMD_ERR_M1_DEC											0xE7//M1卡减值失败错误指令
#define CMD_ACK													0xFE//ACK确认命令
#define CMD_NACK												0xFF//NACK否认命令
/*****************************************************************************/
#define CARD_UNKNOWN											0x00
#define CARD_MIFARE												0x01
#define CARD_ULTRALIGHT											0x02
#define CARD_ISO14443B											0x03
#define CARD_ISO14443A											0x04
#define CARD_ISO15693											0x05
/*****************************************************************************/
extern uint8_t xdata DK25L_TxBuffer[CONFIG_DK25L_TXBUF_SIZE];//指令发送缓冲区
extern uint8_t xdata DK25L_RxBuffer[CONFIG_DK25L_RXBUF_SIZE];//指令接收缓冲区
/*****************************************************************************/
void DL25L_Init(void);//DK25L NFC模块初始化
void DK25L_GET_UID(void);//获取卡片 UID
void DK25L_GET_TPYE(void);//获取卡片类型
void DK25L_GET_FWVER(void);//获取模块软件版本号
void DK25L_GET_HWVER(void);//获取模块硬件版本号
void DK25L_MIFARE_SET_KEYA(uint8_t *pKey);//写入M1卡KEYA密钥到模块
void DK25L_MIFARE_SET_KEYB(uint16_t *pKey);//写入M1卡KEYB密钥到模块
void DK25L_MIFARE_WALLET_INIT(uint8_t block);//M1卡电子钱包初始化指令
void DK25L_MIFARE_WALLET_CHARGE(uint8_t block, uint8_t *pdat);//M1卡电子钱包充值指令
void DK25L_MIFARE_WALLET_CHARGEBACK(uint8_t block, uint8_t *pdat);//M1卡电子钱包扣款指令
void DL25L_MIFARE_WRITE_BLOCK(uint8_t block, uint8_t *pdat);//M1卡写块指令
void DL25L_MIFARE_READ_BLOCK(uint8_t block);//M1卡读块指令
void DL25L_MIFARE_SET_KEY_TYPE(uint8_t type);//设置模块使用密钥的类型
void DL25L_ULTRALIGHT_READ_BLOCK(uint8_t block);//UL卡读块指令
void DL25L_ULTRALIGHT_WRITE_BLOCK(uint8_t block, uint8_t *pdat);//UL卡写块指令
void DL25L_ULTRALIGHT_READ_MBLOCK(uint8_t blockStart, uint8_t blockEnd);//UL卡读多个块指令
void DL25L_ULTRALIGHT_WRITE_MBLOCK(uint8_t blockStart, uint8_t blockEnd, uint8_t *pdat);//UL卡写多个块指令
void DL25L_ISO14443A_ACTIVATE(void);//ISO14443A 卡激活指令
void DL25L_ISO14443A_APDU(uint8_t length, uint8_t *pdat);//ISO14443A PDU指令接口
void DK25L_EnableRx(int8_t ena);
#endif