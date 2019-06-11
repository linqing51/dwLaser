#include "sPlcDK25L.h"
/*****************************************************************************/
#if CONFIG_SPLC_USING_DK25L == 1
uint8_t xdata DK25L_TxBuffer[CONFIG_DK25L_TXBUF_SIZE];//ָ��ͻ�����
uint8_t xdata DK25L_RxBuffer[CONFIG_DK25L_RXBUF_SIZE];//ָ����ջ�����
static uint8_t DL25L_TxIndex;//����λ������
static uint8_t DL25L_RxIndex;//����λ������
static uint8_t DL25L_TXLength;//���ͳ���
/*****************************************************************************/
void DL25L_Init(void){//DK25L NFCģ���ʼ��
	memset(DK25L_TxBuffer, 0x00, CONFIG_DK25L_TXBUF_SIZE);
	memset(DK25L_RxBuffer, 0x00, CONFIG_DK25L_RXBUF_SIZE);
	DL25L_TxIndex = 0;
	DL25L_RxIndex = 0;
	DL25L_TXLength = 0;							
	RES(SPCOIL_DK25L_RXCMD_DONE);							
	RES(SPCOIL_DK25L_RXCMD_DOING);						
	RES(SPCOIL_DK25L_RXCMD_OVERFLOW);					
	RES(SPCOIL_DK25L_TXCMD_DONE);						
	RES(SPCOIL_DK25L_TXCMD_DOING);					
	RES(SPCOIL_DK25L_TXCMD_OVERFLOW);
	NVRAM0[SPREG_DK25L_VER] = 0;
	DK25L_GET_HWVER();
	while(LDB(SPCOIL_DK25L_TXCMD_DONE));
	delayMs(100);
	if(LD(SPCOIL_DK25L_RXCMD_DONE)){//DK25L ���سɹ�
		NVRAM0[SPREG_DK25L_VER] = DK25L_TxBuffer[2];
		DK25L_GET_FWVER();//��ȡģ��Ӳ���汾��
		delayMs(100);
		if(LD(SPCOIL_DK25L_RXCMD_DONE)){//DK25L ���سɹ�
			NVRAM0[SPREG_DK25L_VER] |= (DK25L_TxBuffer[2] << 8);
			RES(SPCOIL_DK25L_INIT_FAIL);	
		}
		else{
			SET(SPCOIL_DK25L_INIT_FAIL);	
		}
	}
	else{
		SET(SPCOIL_DK25L_INIT_FAIL);	
	}
}
static void DK25L_UartIsr() interrupt INTERRUPT_UART0{
	uint8_t rxDat, txDat;
	uint16_t rxSize, txSize;
	if(TI0){
        TI0 = 0;        
			if(DL25L_TxIndex == DL25L_TXLength){
				DL25L_TxIndex = 0;
				SET(SPCOIL_DK25L_TXCMD_DONE);
				RES(SPCOIL_DK25L_TXCMD_DOING);                
			}
			else if(DL25L_TxIndex < DL25L_TXLength){
				SBUF0 = DK25L_TxBuffer[DL25L_TxIndex];
				DL25L_TxIndex ++;
			}
			else{
				DL25L_TxIndex = 0;
				RES(SPCOIL_DK25L_TXCMD_DONE);
				RES(SPCOIL_DK25L_TXCMD_DOING);  
				RES(SPCOIL_DK25L_TXCMD_OVERFLOW);
			}
    }
	if(RI0){
		RI0 = 0;
		rxDat = SBUF0;
		if(rxDat == DK25L_STX){//���յ�֡ͷ
			DL25L_RxIndex = 1;	
			DK25L_RxBuffer[(DL25L_RxIndex - 1)] = DK25L_STX;
			return;
		}
		if(DL25L_RxIndex == 1){//���յ������ֽ�
			DL25L_RxIndex = 2;
			DK25L_RxBuffer[(DL25L_RxIndex - 1)] = rxDat;
			return;
		}
        if((DL25L_RxIndex >= 2) && (DL25L_RxIndex <  CONFIG_DK25L_RXBUF_SIZE) && (DL25L_RxIndex <= (DK25L_RxBuffer[1] + 1))){//ָ�������
			DK25L_RxBuffer[DL25L_RxIndex] = rxDat;
			DL25L_RxIndex ++;
			if(DL25L_RxIndex == (DK25L_RxBuffer[1] + 2)){//���������Ͽ�ʼ
				DL25L_RxIndex = 0;
				SET(SPCOIL_DK25L_RXCMD_DONE);
				RES(SPCOIL_DK25L_RXCMD_DOING);
				SCON0 &= 0xEF;//�رս����ж�
			}
			return;
		}
	}   
}


static void DK25L_CmdSend(void){//����DK25Lָ��
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Preserve SFRPAGE	
	RES(SPCOIL_DK25L_RXCMD_DONE);
	RES(SPCOIL_DK25L_RXCMD_DOING);	
	RES(SPCOIL_DK25L_RXCMD_OVERFLOW);
	RES(SPCOIL_DK25L_TXCMD_DONE);	
	RES(SPCOIL_DK25L_TXCMD_DOING);	
	RES(SPCOIL_DK25L_TXCMD_OVERFLOW);
	SFRPAGE = UART0_PAGE;
	DL25L_TXLength = (DK25L_TxBuffer[1] + 2);//�ڶ�λΪ���ͳ���
	SCON0 |= 0x10;
	TI0 = 1;
	SFRPAGE = SFRPAGE_SAVE;// Restore SFRPAGE
}
void DK25L_GET_UID(void){//��ȡ��Ƭ UID
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x01;
	DK25L_TxBuffer[2] = CMD_FIND_CARD_UID;
	DK25L_CmdSend();
}
void DK25L_GET_TPYE(void){//��ȡ��Ƭ����
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x01;
	DK25L_TxBuffer[2] = CMD_FIND_CARD_TYPE;
	DK25L_CmdSend();
}
void DK25L_GET_FWVER(void){//��ȡģ������汾��
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x01;
	DK25L_TxBuffer[2] = CMD_READ_FW_VER;
	DK25L_CmdSend();
}
void DK25L_GET_HWVER(void){//��ȡģ��Ӳ���汾��
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x01;
	DK25L_TxBuffer[2] = CMD_READ_HW_VER;
	DK25L_CmdSend();
}

void DK25L_MIFARE_SET_KEYA(uint8_t *pKey){//д��M1��KEYA��Կ��ģ��
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x07;
	DK25L_TxBuffer[2] = CMD_MIFARE_SET_KEYA;
	DK25L_TxBuffer[3] = *pKey;
	DK25L_TxBuffer[4] = *(pKey + 1);
	DK25L_TxBuffer[5] = *(pKey + 2);
	DK25L_TxBuffer[6] = *(pKey + 3);
	DK25L_TxBuffer[7] = *(pKey + 4);
	DK25L_TxBuffer[8] = *(pKey + 5);
	DK25L_CmdSend();
}
void DK25L_MIFARE_SET_KEYB(uint16_t *pKey){//д��M1��KEYB��Կ��ģ��
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x0B;
	DK25L_TxBuffer[2] = CMD_MIFARE_SET_KEYB;
	DK25L_TxBuffer[3] = *pKey;
	DK25L_TxBuffer[4] = *(pKey + 1);
	DK25L_TxBuffer[5] = *(pKey + 2);
	DK25L_TxBuffer[6] = *(pKey + 3);
	DK25L_TxBuffer[7] = *(pKey + 4);
	DK25L_TxBuffer[8] = *(pKey + 5);
	DK25L_CmdSend();
}
void DK25L_MIFARE_WALLET_INIT(uint8_t block){//M1������Ǯ����ʼ��ָ��
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x06;
	DK25L_TxBuffer[2] = CMD_MIFATE_WALLET_INIT;
	DK25L_TxBuffer[3] = block;
	DK25L_CmdSend();
}
void DK25L_MIFARE_WALLET_CHARGE(uint8_t block, uint8_t *pdat){//M1������Ǯ����ֵָ��
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x06;
	DK25L_TxBuffer[2] = CMD_MIFARE_WALLET_CHARGE;
	DK25L_TxBuffer[3] = block;
	DK25L_TxBuffer[3] = *pdat;
	DK25L_TxBuffer[3] = *(pdat + 1);
	DK25L_TxBuffer[3] = *(pdat + 2);
	DK25L_TxBuffer[3] = *(pdat + 3);
	DK25L_CmdSend();
}
void DK25L_MIFARE_WALLET_CHARGEBACK(uint8_t block, uint8_t *pdat){//M1������Ǯ���ۿ�ָ��
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x06;
	DK25L_TxBuffer[2] = CMD_MIFARE_WALLET_CHARGEBACK;
	DK25L_TxBuffer[3] = block;
	DK25L_TxBuffer[3] = *pdat;
	DK25L_TxBuffer[3] = *(pdat + 1);
	DK25L_TxBuffer[3] = *(pdat + 2);
	DK25L_TxBuffer[3] = *(pdat + 3);
	DK25L_CmdSend();
}
void DL25L_MIFARE_WRITE_BLOCK(uint8_t block, uint8_t *pdat){//M1��д��ָ��
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x12;
	DK25L_TxBuffer[2] = CMD_MIFARE_WRITE_BLOCK;
	DK25L_TxBuffer[3] = block;
	memcpy((DK25L_TxBuffer + 4), pdat, 16);
	DK25L_CmdSend();
}
void DL25L_MIFARE_READ_BLOCK(uint8_t block){//M1������ָ��
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x12;
	DK25L_TxBuffer[2] = CMD_MIFARE_READ_BLOCK;
	DK25L_TxBuffer[3] = block;
	
	DK25L_CmdSend();
}
void DL25L_MIFARE_SET_KEY_TYPE(uint8_t type){//����ģ��ʹ����Կ������
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x02;
	DK25L_TxBuffer[2] = CMD_MIFARE_SET_KEY_TYPE;
	DK25L_TxBuffer[3] = type;
	DK25L_CmdSend();	
}
void DL25L_ULTRALIGHT_READ_BLOCK(uint8_t block){//UL������ָ��
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x02;
	DK25L_TxBuffer[2] = CMD_ULTRALIGHT_READ_BLOCK;
	DK25L_TxBuffer[3] = block;
	DK25L_CmdSend();	
}
void DL25L_ULTRALIGHT_WRITE_BLOCK(uint8_t block, uint8_t *pdat){//UL��д��ָ��
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x06;
	DK25L_TxBuffer[2] = CMD_ULTRALIGHT_WRITE_BLOCK;
	DK25L_TxBuffer[3] = block;
	DK25L_TxBuffer[4] = *pdat;
	DK25L_TxBuffer[5] = *(pdat + 1);
	DK25L_TxBuffer[6] = *(pdat + 2);
	DK25L_TxBuffer[7] = *(pdat + 3);
	DK25L_CmdSend();
}
void DL25L_ULTRALIGHT_READ_MBLOCK(uint8_t blockStart, uint8_t blockEnd){//UL���������ָ��
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x03;
	DK25L_TxBuffer[2] = CMD_ULTRALIGHT_READ_MBLOCK;
	DK25L_TxBuffer[3] = blockStart;
	DK25L_TxBuffer[4] = blockEnd;
	DK25L_CmdSend();
}
void DL25L_ULTRALIGHT_WRITE_MBLOCK(uint8_t blockStart, uint8_t blockEnd, uint8_t *pdat){//UL��д�����ָ��
	
}
void DL25L_ISO14443A_ACTIVATE(void){//ISO14443A ������ָ��
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x01;
	DK25L_TxBuffer[2] = CMD_ISO14443A_ACTIVATE;
	DK25L_CmdSend();
}
void DL25L_ISO14443A_APDU(uint8_t length, uint8_t *pdat){//ISO14443A PDUָ��ӿ�
	
}
#endif
