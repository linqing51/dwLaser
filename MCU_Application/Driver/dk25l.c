#include "dk25l.h"

#define DK25L_STX			0xAA//
//ͨ��ָ��
#define CMD_FIND_CARD_UID				0x01//��ȡ��ƬUID
#define CMD_FIND_CARD_CLASS			0x02//��ȡ��Ƭ����
#define CMD_AUTO_FIND_CARD			0x95//�Զ�Ѱ������
#define CMD_MOD_BAUDRATE			0xA0//�޸�ģ�鲨����
#define CMD_CONFIG_SYS_PARA			0xA1//����ϵͳ����ָ��
#define CMD_READ_SYS_PARA			0xA2//��ȡϵͳ����ָ��
#define CMD_READ_FW_VER				0xB0//��ȡģ��̼��汾��
#define CMD_READ_HW_VER				0xB1//��ȡģ��Ӳ���汾��
//Mifareָ��
#define CMD_MIFARE_WRITE_KEYA		0x03//��ģ��д����Ҫ��֤����Կ(A��Կ)
#define CMD_MIFARE_READ_BLOCK		0x04//Mifare ������
#define CMD_MIFARE_WRITE_BLOCK		0x05//Mifare ��д��
#define CMD_MIFATE_INIT				0x06//Mifare ������ֵ��ʼ��
#define CMD_MIFARE_ADD				0x07//����ֵ
#define CMD_MIFARE_DEC				0x08//����ֵ

#define CONFIG_DK25L_RXD_BUFFER_SIZE			256
#define CONFIG_DK25L_TXD_BUFFER_SIZE			256
volatile unsigned char RcvNum;                    

uint8_t dk25lRcvBuf[CONFIG_DK25L_RXD_BUFFER_SIZE];
uint8_t dk25lSendBuf[CONFIG_DK25L_TXD_BUFFER_SIZE];
uint16_t dk25lRcvSize;//��������
uint16_t dk25lSendSize;//��������


void Int_serial() INTERRUPT_UART0{
	if(TI0){
        TI0 = 0;        
        if(SendNum == 0){
            FlagSendOk = 0;                    
        }
        else {
            SBUF0 = *SendRead;
            if(SendRead == (SendBuf + SerialSEND - 1)){
                SendRead = SendBuf;                        
            }
            else {
                SendRead++;
            }
			SendNum--;						                   
        }
    }
	if(RI0){
		RI0 = 0;  
	    if(SBUF0 == DK25L_STX){//���յ�֡ͷ
			dk25lRcvSize = 1;	
			dk25lRcvBuf[(dk25lRcvSize - 1)] = DK25L_STX;
		}
		else if(dk25lRcvSize == 1){//���յ������ֽ�
			dk25lRcvSize = 2;
			dk25lRcvBuf[(dk25lRcvSize - 1)] = SBUF0;
		}      
        else if((dk25lRcvSize >= 3) && 
			   ((dk25lRcvSize - 2) < dk25lRcvBuf[1]) &&
			   (dk25lRcvSize < CONFIG_DK25L_RXD_BUFFER_SIZE)){
			dk25lRcvSize ++;
			dk25lRcvBuf[dk25lRcvSize] = SBUF0;        
		}
		if(dk25lRcvSize == (dk25lRcvBuf[1] + 2)){//���������Ͽ�ʼ
		}
   }   
}

