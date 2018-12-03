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
#define FATEK_RCVSIZE	       48                    //����Э���ջ�������С
#define FATEK_SENDSIZE		   48                    //����Э�鷢�ͻ�������С
#define MAXOPERNUM             8					 //���嵥�����ɶ�ȡ������
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
//Uart  ���մ������
#define NOPLCCONT						   0xFF
/********************************************************************************/
//Fatek ͨ���������
#define ReadStatusPLC	   				   0x40		//PLC����ϵͳ״̬��ȡ
#define ControlRUNSTOP					   0x41	    //PLC��RUN/STOP����
#define OperationPoint	    			   0x42	    //��һ������Ĳ�������
#define ReadMultipleENABLE				   0x43	    //��������������/����״̬��ȡ
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
extern int16_t Fatek_RegReply2Int(Fatek_ReadMultipleRegisters_Reply rep);//���������ַ�ת��Ϊ�з�������
extern long Fatek_Char2long(int8_t *preg);//���������ַ�ת��Ϊ�з��ų�����
extern void Fatek_ReadStatusPLC(Fatek_ReadStatusPLC_Reply *reply);//PLC����ϵͳ״̬��ȡ
extern void Fatek_ControlRUNSTOP(uint8_t plcon,Fatek_ControlRUNSTOP_Reply *reply);//PLC��RUN/STOP����
extern void Fatek_OperationPoint(uint8_t opera/*������*/,int8_t *ppoint/*�������*/,Fatek_OperationPoint_Reply *reply);//��һ�����㶯������
extern void Fatek_ReadMultiple(uint8_t num/*����*/,int8_t *pstart/*��ʼ�������*/,Fatek_ReadMultiple_Reply *reply);//������������������״̬��ȡ
extern void Fatek_ReadMultipleConsecutive(uint8_t num/*����*/,int8_t *pstart/*��ʼ�������*/,Fatek_ReadMultipleConsecutive_Reply *reply);//�����������״̬��ȡ
extern void Fatek_WriteMultipleConsecutive(uint8_t num/*����*/,int8_t *pstart/*��ʼ�������*/,int8_t *pstatus/*״̬*/,Fatek_WriteMultipleConsecutive_Reply *reply); 
extern void Fatek_ReadMultipleRegisters(uint8_t num/*����*/,int8_t *pstart/*��ʼ��������*/,uint8_t isDword/*�Ƿ���˫��*/,Fatek_ReadMultipleRegisters_Reply *reply);
extern void Fatek_WriteMultipleRegisters(uint8_t num/*����*/,int8_t *pstart/*��ʼ��������*/,int8_t *preg/*д������*/,uint8_t isDword/*�Ƿ���˫��*/,Fatek_WriteMultipleRegisters_Reply *reply);//�����������״̬д��
extern void Fatek_MixedRead(uint8_t num/*����*/,int8_t *pstart/*�������*/,uint16_t len/*д��������ݳ���*/,Fatek_MixedRead_Reply *reply);//������ⵥ��״̬�򻺴������ݻ�϶�ȡ
extern void Fatek_MixedWrite(uint8_t num/*����*/,int8_t *preg/*д��������*/,uint16_t len/*д�����ݳ���*/,Fatek_MixedWrite_Reply *reply);//������ⵥ��״̬�򻺴������ݻ��д��
extern void Fatek_LoopBackTest(int8_t *src/*��������*/,uint8_t len/*���ϳ���*/,Fatek_LoopBackTest_Reply *reply);//���Իش�loop back
extern void Fatek_ReadDetailStatus(Fatek_ReadDetailStatus_Reply *reply);//PLC��ϸϵͳ״̬��ȡ
extern void SetPLCID(uint8_t plcid);//�趨��Ҫͨ�ŵĴӻ�PLCID



#endif
