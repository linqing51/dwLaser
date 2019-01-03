//MCP47x6 DAC ����
#include "mcp47x6.h"
/*****************************************************************************/
#define MCP47X6A0_ADDRESS							0x60
#define	WRITE_VOLATILE_DAC_REGISTER 				(0 << 5)
#define	WRITE_VOLATILE_MEMORY 						(2 << 5)
#define	WRITE_ALL_MEMORY 							(3 << 5)
#define	WRITE_VOLATILE_CONFIG_BIT 					(4 << 5)
#define	READ_MEMORY 								(6 << 5)
#define	REF_VDD 									(0 << 3)//��׼ԴVDD
#define	REF_UNBUFFERED 								(2 << 3)//δ����REF PIN
#define	REF_BUFFERED 								(3 << 3)//����REF PIN
#define GAIN1 										(0 << 0)//*1
#define	GAIN2 										(1 << 0)//*2
#define	NOT_POWERED_DOWN 							(0 << 1)//������
#define	POWERED_DOWN_1K 							(1 << 1//1K��������
#define	POWERED_DOWN_100K  							(2 << 1)//100K��������
#define	POWERED_DOWN_500K 	 						(3 << 1)//500K��������
/*****************************************************************************/
/*****************************************************************************/
uint8_t mcp47x6Init(void)
{//MCP47x6��ʼ��
	uint8_t temp, flag;
	//����λ
	NVRAM0[SPREG_START + SPREG_DAC_0] = 0;
	NVRAM0[SPREG_START + SPREG_DAC_1] = 0;
	NVRAM0[SPREG_START + SPREG_DAC_2] = 0;
	NVRAM0[SPREG_START + SPREG_DAC_3] = 0;
	temp = 	WRITE_VOLATILE_MEMORY |//Command
			REF_VDD 				|//REF
			NOT_POWERED_DOWN      |//PowerDown
	        GAIN1;				 //
	//��ʼ��DAC1
	iic4Start();
	
	iic4SendByte((MCP47X6A0_ADDRESS << 1) & 0xFE);
	flag = iic4WaitAck();
	
	iic4SendByte(temp);
	flag = iic4WaitAck();
	
	iic4SendByte(0x00);
	flag = iic4WaitAck();
	
	iic4SendByte(0x00);
	flag = iic4WaitAck();
	
	iic4Stop();
	//��ʼ��DAC2
	iic3Start();
	
	iic3SendByte((MCP47X6A0_ADDRESS << 1) & 0xFE);
	flag = iic3WaitAck();
	
	iic3SendByte(temp);
	flag = iic3WaitAck();
	
	iic3SendByte(0x00);
	flag = iic3WaitAck();
	
	iic3SendByte(0x00);
	flag = iic3WaitAck();
	
	iic3Stop();
	//��ʼ��DAC3
	iic1Start();
	
	iic1SendByte((MCP47X6A0_ADDRESS << 1) & 0xFE);
	flag = iic1WaitAck();
	
	iic1SendByte(temp);
	flag = iic1WaitAck();
	
	iic1SendByte(0x00);
	flag = iic1WaitAck();
	
	iic1SendByte(0x00);
	flag = iic1WaitAck();
	
	iic1Stop();
	//��ʼ��DAC4
	iic2Start();
	
	iic2SendByte((MCP47X6A0_ADDRESS << 1) & 0xFE);
	flag = iic2WaitAck();
	
	iic2SendByte(temp);
	flag = iic2WaitAck();
	
	iic2SendByte(0x00);
	flag = iic2WaitAck();
	
	iic2SendByte(0x00);
	flag = iic2WaitAck();
	
	iic2Stop();
	return flag;
}
void mcp47x6Write(uint8_t channel, uint16_t dat)
{//����ָʾ�����ѹCODE
	uint8_t temp, flag;
	temp = 0x0;
	switch(channel){
		case 1:{
			if(NVRAM0[SPREG_START + SPREG_DAC_0] != dat)
			{
				iic4Start();
				
				iic4SendByte((MCP47X6A0_ADDRESS << 1) & 0xFE);
				flag = iic4WaitAck();
				
				iic4SendByte((dat >> 8) & 0x0F);
				flag = iic4WaitAck();
				
				iic4SendByte(dat & 0xFF);
				flag = iic4WaitAck();
				
				iic4Stop();
				NVRAM0[SPREG_START + SPREG_DAC_0] = dat;
			}
			break;
		}
		case 2:{
			if(NVRAM0[SPREG_START + SPREG_DAC_1] != dat)
			{
				iic3Start();
				
				iic3SendByte((MCP47X6A0_ADDRESS << 1) & 0xFE);
				flag = iic3WaitAck();
				
				iic3SendByte((dat >> 8) & 0x0F);
				flag = iic3WaitAck();
				
				iic3SendByte(dat & 0xFF);
				flag = iic3WaitAck();
				
				iic3Stop();
				NVRAM0[SPREG_START + SPREG_DAC_1] = dat;
			}
			break;
		}
		case 3:{
			if(NVRAM0[SPREG_START + SPREG_DAC_2] != dat)
			{
				iic1Start();
				
				iic1SendByte((MCP47X6A0_ADDRESS << 1) & 0xFE);
				flag = iic1WaitAck();
				
				iic1SendByte((dat >> 8) & 0x0F);
				flag = iic1WaitAck();
				
				iic1SendByte(dat & 0xFF);
				flag = iic1WaitAck();
				
				iic1Stop();
				NVRAM0[SPREG_START + SPREG_DAC_2] = dat;
			}
			break;
		}
		case 4:{
			if(NVRAM0[SPREG_START + SPREG_DAC_3] != dat)
			{
				iic2Start();
				
				iic2SendByte((MCP47X6A0_ADDRESS << 1) & 0xFE);
				flag = iic2WaitAck();
				
				iic2SendByte((dat >> 8) & 0x0F);
				flag = iic2WaitAck();
				
				iic2SendByte(dat & 0xFF);
				flag = iic2WaitAck();
				
				iic2Stop();
				NVRAM0[SPREG_START + SPREG_DAC_3] = dat;
			}
			break;
		}
		default:break;
	}
}



