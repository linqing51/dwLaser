#ifndef __FATEKPROTOCOL_H__
#define __FATEKPROTOCOL_H__
/*****************************************************************************/
#include "appConfig.h"
#include  "stdio.h"
#include  "ctype.h"
#include  "uart.h"
#include "string.h"
#include "INTRINS.H"
/*****************************************************************************/
#define FATEK_RCVSIZE	       48                    //定义协议收缓冲区大小
#define FATEK_SENDSIZE		   48                    //定义协议发送缓冲区大小
#define MAXOPERNUM             8					 //定义单次最大可读取单点数
/******************************************************************************/
#define No_Error					   	   0x0
#define Illegal_Value					   0x2
#define Write_Prohibited				   0x3
#define Illegal_Command_Formant			   0x4
#define Checksum_Error	     			   0x5
#define PLCID_Error 					   0x6
#define Syntax_Errror					   0x7
#define Ladder_Error					   0x9
#define Illegal_Reference_Address		   0xA
/********************************************************************************/
//Uart  接收错误代码
#define NOPLCCONT						   0xFF
/********************************************************************************/
//Fatek 通信命令代码
#define ReadStatusPLC	   				   0x40		//PLC概略系统状态读取
#define ControlRUNSTOP					   0x41	    //PLC的RUN/STOP控制
#define OperationPoint	    			   0x42	    //单一个单点的操作控制
#define ReadMultipleENABLE				   0x43	    //连续多个单点的抑/致能状态读取
#define ReadMultipleConsecutive            0x44
#define WriteMultipleConsecutive           0x45
#define ReadMultipleRegisters              0x46
#define WriteMultipleRegisters             0x47
#define MixedRead						   0x48
#define MixedWrite                         0x49
#define LoopBackTest					   0x4E
#define ReadProgram						   0x4F
#define WriteProgram                       0x50
#define ReadDetailStatus				   0x53
/*********************************************************************************/
typedef int8_t 								ErrorCode;
/***********************************************************************************/
#define FATEK_DISABLE					   0x31
#define FATEK_ENABLE					   0x32
#define FATEK_SET						   0x33
#define FATEK_RESET						   0x34
#define FATEK_ON						   0x31
#define FATEK_OFF						   0x30
/*************************************************************************************/
#define FATEK_DWORD                         32
#define FATEK_SWORD                         16

typedef struct {
int8_t errorcode;
int8_t status[3];
}Fatek_ReadStatusPLC_Reply;
/*************************************************************************************/
typedef struct {
int8_t errorcode;
}Fatek_ControlRUNSTOP_Reply;
/*************************************************************************************/
typedef struct {
int8_t errorcode;
}Fatek_OperationPoint_Reply;
/*************************************************************************************/
typedef struct{
int8_t errorcode;
uint8_t num;
int8_t pstatus[FATEK_RCVSIZE];
}Fatek_ReadMultiple_Reply;
/*************************************************************************************/
typedef struct{
int8_t errorcode;
uint8_t num;
int8_t status[FATEK_RCVSIZE];
}Fatek_ReadMultipleConsecutive_Reply;
/*************************************************************************************/
typedef struct{
int8_t errorcode;
}Fatek_WriteMultipleConsecutive_Reply;
/**************************************************************************************/
typedef struct{
int8_t errorcode;
uint8_t num;
int8_t status[FATEK_RCVSIZE];
int8_t isdword;
}Fatek_ReadMultipleRegisters_Reply;
/**************************************************************************************/
typedef struct{
int8_t errorcode;
}Fatek_WriteMultipleRegisters_Reply;
/***************************************************************************************/
typedef struct{
int8_t errorcode;
}Fatek_MixedRead_Reply;
/**************************************************************************************/
typedef struct{
int8_t errorcode;
}Fatek_MixedWrite_Reply;
/*****************************************************************************************/
typedef struct{
int8_t errorcode;
uint8_t num;
int8_t status[FATEK_RCVSIZE];
uint8_t len;
}Fatek_LoopBackTest_Reply;
/*****************************************************************************************/
typedef struct{
int8_t errorcode;
int8_t status[FATEK_RCVSIZE];
}Fatek_ReadDetailStatus_Reply;
/*****************************************************************************************/
extern int16_t Fatek_RegReply2Int(Fatek_ReadMultipleRegisters_Reply rep);//将单点由字符转换为有符号整数
extern long Fatek_Char2long(int8_t *preg);//将单点由字符转换为有符号长整数
extern void Fatek_ReadStatusPLC(Fatek_ReadStatusPLC_Reply *reply);//PLC概略系统状态读取
extern void Fatek_ControlRUNSTOP(uint8_t plcon,Fatek_ControlRUNSTOP_Reply *reply);//PLC的RUN/STOP控制
extern void Fatek_OperationPoint(uint8_t opera/*动作码*/,int8_t *ppoint/*单点号码*/,Fatek_OperationPoint_Reply *reply);//单一个单点动作控制
extern void Fatek_ReadMultiple(uint8_t num/*个数*/,int8_t *pstart/*起始单点号码*/,Fatek_ReadMultiple_Reply *reply);//多个连续单点的抑致能状态读取
extern void Fatek_ReadMultipleConsecutive(uint8_t num/*个数*/,int8_t *pstart/*起始单点号码*/,Fatek_ReadMultipleConsecutive_Reply *reply);//多个连续单点状态读取
extern void Fatek_WriteMultipleConsecutive(uint8_t num/*个数*/,int8_t *pstart/*起始单点号码*/,int8_t *pstatus/*状态*/,Fatek_WriteMultipleConsecutive_Reply *reply); 
extern void Fatek_ReadMultipleRegisters(uint8_t num/*个数*/,int8_t *pstart/*起始缓冲器号*/,uint8_t isDword/*是否是双字*/,Fatek_ReadMultipleRegisters_Reply *reply);
extern void Fatek_WriteMultipleRegisters(uint8_t num/*个数*/,int8_t *pstart/*起始缓冲器号*/,int8_t *preg/*写入资料*/,uint8_t isDword/*是否是双字*/,Fatek_WriteMultipleRegisters_Reply *reply);//多个连续单点状态写入
extern void Fatek_MixedRead(uint8_t num/*个数*/,int8_t *pstart/*组件号码*/,uint16_t len/*写入组件数据长度*/,Fatek_MixedRead_Reply *reply);//多个任意单点状态或缓存器数据混合读取
extern void Fatek_MixedWrite(uint8_t num/*个数*/,int8_t *preg/*写入数据组*/,uint16_t len/*写入数据长度*/,Fatek_MixedWrite_Reply *reply);//多个任意单点状态或缓存器数据混合写入
extern void Fatek_LoopBackTest(int8_t *src/*发送数据*/,uint8_t len/*资料长度*/,Fatek_LoopBackTest_Reply *reply);//测试回传loop back
extern void Fatek_ReadDetailStatus(Fatek_ReadDetailStatus_Reply *reply);//PLC详细系统状态读取
extern void SetPLCID(uint8_t plcid);//设定需要通信的从机PLCID



#endif
