#include "sPlcDK25L.h"
/*****************************************************************************/
#if CONFIG_SPLC_USING_DK25L == 1
uint8_t xdata DK25L_TxBuffer[CONFIG_DK25L_TXBUF_SIZE];//指令发送缓冲区
uint8_t xdata DK25L_RxBuffer[CONFIG_DK25L_RXBUF_SIZE];//指令接收缓冲区
static uint8_t DL25L_TxIndex;//发送位置索引
static uint8_t DL25L_RxIndex;//接收位置索引
static uint8_t DL25L_TXLength;//发送长度
/*****************************************************************************/
void DL25L_Init(void){//DK25L NFC模块初始化
	uint8_t fwver, hwver;
	uint16_t overTime;
	RES(SPCOIL_DK25L_INIT_FAIL);
	NVRAM0[SPREG_DK25L_VER] = 0xFFFF;
	DK25L_GET_HWVER();
	while(LDB(SPCOIL_DK25L_TXCMD_DONE));
	DK25L_EnableRx(true);
	overTime = 0;
	while(LDB(SPCOIL_DK25L_RXCMD_DONE) && (overTime < CONFIG_SPLC_USING_DK25L_OVERTIME)){//DK25L 返回成功
		delayMs(1);
		overTime ++;
	}
	if(overTime >= CONFIG_SPLC_USING_DK25L_OVERTIME){
		SET(SPCOIL_DK25L_INIT_FAIL);
		return;
	}
	fwver = DK25L_TxBuffer[2];
	DK25L_GET_FWVER();//获取模块硬件版本号
	while(LDB(SPCOIL_DK25L_TXCMD_DONE));
	overTime = 0;
	while(LDB(SPCOIL_DK25L_RXCMD_DONE) && (overTime < CONFIG_SPLC_USING_DK25L_OVERTIME)){//DK25L 返回成功
		delayMs(1);
		overTime ++;
	}
	if(overTime >= CONFIG_SPLC_USING_DK25L_OVERTIME){
		SET(SPCOIL_DK25L_INIT_FAIL);
		return;
	}
	hwver = DK25L_TxBuffer[2];
	NVRAM0[SPREG_DK25L_VER] = ((int16_t)hwver << 8) + fwver;
	if(NVRAM0[SPREG_DK25L_VER] == 0x01B1){
		setLedEprom(true);
	}
	
}
void DK25L_EnableRx(int8_t ena){//接收中断使能
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Preserve SFRPAGE	
	SFRPAGE = UART0_PAGE;
	if(ena){
		RI0 = 0;
		SCON0 |= 0x10;//UART0 reception enabled
	}
	else{
		SCON0 &= 0x7F;
		RI0 = 0;
	}
	SFRPAGE = SFRPAGE_SAVE;// Restore SFRPAGE
}
static void DK25L_UartIsr() interrupt INTERRUPT_UART0{
	uint8_t rxDat;
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
		if((SSTA0 & 0x80)){//FE0: Frame Error Flag.
			RI0 = 0;
			return;
		}
		RI0 = 0;
		rxDat = SBUF0;
		if(rxDat == DK25L_STX){//接收到帧头
			DL25L_RxIndex = 0;	
			DK25L_RxBuffer[0] = DK25L_STX;
			RES(SPCOIL_DK25L_RXCMD_DONE);
			SET(SPCOIL_DK25L_RXCMD_DOING);
			RES(SPCOIL_DK25L_RXCMD_OVERFLOW);
			RES(SPCOIL_DK25L_RXCMD_ERROR);
			return;
		}
		if(DL25L_RxIndex == 1){//接收到长度字节
			DL25L_RxIndex ++;
			DK25L_RxBuffer[2] = rxDat;
			return;
		}
		if(DL25L_RxIndex >= CONFIG_DK25L_RXBUF_SIZE){//超出缓冲区
			SET(SPCOIL_DK25L_RXCMD_DONE);
			RES(SPCOIL_DK25L_RXCMD_DOING);
			SET(SPCOIL_DK25L_RXCMD_OVERFLOW);
			SET(SPCOIL_DK25L_RXCMD_ERROR);		
			DL25L_RxIndex = 0;
			return;
		}
        if((DL25L_RxIndex >= 2) && (DL25L_RxIndex <  CONFIG_DK25L_RXBUF_SIZE) && (DL25L_RxIndex <= (DK25L_RxBuffer[1] + 2))){//指令接收中
			DK25L_RxBuffer[DL25L_RxIndex] = rxDat;
			if(DL25L_RxIndex == (DK25L_RxBuffer[1] + 2)){//命令接收完毕开始
				DL25L_RxIndex = 0;
				SET(SPCOIL_DK25L_RXCMD_DONE);
				RES(SPCOIL_DK25L_RXCMD_DOING);
				RES(SPCOIL_DK25L_RXCMD_OVERFLOW);
				RES(SPCOIL_DK25L_RXCMD_ERROR);
				SCON0 &= 0xEF;//关闭接收中断
			}
			DL25L_RxIndex ++;
			return;
		}
	}   
}
static void DK25L_CmdSend(void){//发送DK25L指令
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Preserve SFRPAGE	
	RES(SPCOIL_DK25L_RXCMD_DONE);
	RES(SPCOIL_DK25L_RXCMD_DOING);	
	RES(SPCOIL_DK25L_RXCMD_OVERFLOW);
	RES(SPCOIL_DK25L_RXCMD_ERROR);
	
	RES(SPCOIL_DK25L_TXCMD_DONE);	
	RES(SPCOIL_DK25L_TXCMD_DOING);	
	RES(SPCOIL_DK25L_TXCMD_OVERFLOW);
	RES(SPCOIL_DK25L_TXCMD_ERROR);
	DL25L_TxIndex = 0;
	DL25L_RxIndex = 0;
	memset(DK25L_RxBuffer, 0x00, CONFIG_DK25L_RXBUF_SIZE);
	DK25L_EnableRx(false);
	SFRPAGE = UART0_PAGE;
	DL25L_TXLength = (DK25L_TxBuffer[1] + 2);//第二位为发送长度
	TI0 = 1;
	SFRPAGE = SFRPAGE_SAVE;// Restore SFRPAGE
}
void DK25L_GET_UID(void){//获取卡片 UID
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x01;
	DK25L_TxBuffer[2] = CMD_FIND_CARD_UID;
	DK25L_CmdSend();
}
void DK25L_GET_TPYE(void){//获取卡片类型
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x01;
	DK25L_TxBuffer[2] = CMD_FIND_CARD_TYPE;
	DK25L_CmdSend();
}
void DK25L_GET_FWVER(void){//获取模块软件版本号
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x01;
	DK25L_TxBuffer[2] = CMD_READ_FW_VER;
	DK25L_CmdSend();
}
void DK25L_GET_HWVER(void){//获取模块硬件版本号
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x01;
	DK25L_TxBuffer[2] = CMD_READ_HW_VER;
	DK25L_CmdSend();
}

void DK25L_MIFARE_SET_KEYA(uint8_t *pKey){//写入M1卡KEYA密钥到模块
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
void DK25L_MIFARE_SET_KEYB(uint16_t *pKey){//写入M1卡KEYB密钥到模块
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
void DK25L_MIFARE_WALLET_INIT(uint8_t block){//M1卡电子钱包初始化指令
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x06;
	DK25L_TxBuffer[2] = CMD_MIFATE_WALLET_INIT;
	DK25L_TxBuffer[3] = block;
	DK25L_CmdSend();
}
void DK25L_MIFARE_WALLET_CHARGE(uint8_t block, uint8_t *pdat){//M1卡电子钱包充值指令
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
void DK25L_MIFARE_WALLET_CHARGEBACK(uint8_t block, uint8_t *pdat){//M1卡电子钱包扣款指令
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
void DL25L_MIFARE_WRITE_BLOCK(uint8_t block, uint8_t *pdat){//M1卡写块指令
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x12;
	DK25L_TxBuffer[2] = CMD_MIFARE_WRITE_BLOCK;
	DK25L_TxBuffer[3] = block;
	memcpy((DK25L_TxBuffer + 4), pdat, 16);
	DK25L_CmdSend();
}
void DL25L_MIFARE_READ_BLOCK(uint8_t block){//M1卡读块指令
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x12;
	DK25L_TxBuffer[2] = CMD_MIFARE_READ_BLOCK;
	DK25L_TxBuffer[3] = block;
	
	DK25L_CmdSend();
}
void DL25L_MIFARE_SET_KEY_TYPE(uint8_t type){//设置模块使用密钥的类型
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x02;
	DK25L_TxBuffer[2] = CMD_MIFARE_SET_KEY_TYPE;
	DK25L_TxBuffer[3] = type;
	DK25L_CmdSend();	
}
void DL25L_ULTRALIGHT_READ_BLOCK(uint8_t block){//UL卡读块指令
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x02;
	DK25L_TxBuffer[2] = CMD_ULTRALIGHT_READ_BLOCK;
	DK25L_TxBuffer[3] = block;
	DK25L_CmdSend();	
}
void DL25L_ULTRALIGHT_WRITE_BLOCK(uint8_t block, uint8_t *pdat){//UL卡写块指令
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
void DL25L_ULTRALIGHT_READ_MBLOCK(uint8_t blockStart, uint8_t blockEnd){//UL卡读多个块指令
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x03;
	DK25L_TxBuffer[2] = CMD_ULTRALIGHT_READ_MBLOCK;
	DK25L_TxBuffer[3] = blockStart;
	DK25L_TxBuffer[4] = blockEnd;
	DK25L_CmdSend();
}
void DL25L_ULTRALIGHT_WRITE_MBLOCK(uint8_t blockStart, uint8_t blockEnd, uint8_t *pdat){//UL卡写多个块指令
	
}
void DL25L_ISO14443A_ACTIVATE(void){//ISO14443A 卡激活指令
	DK25L_TxBuffer[0] = DK25L_STX;
	DK25L_TxBuffer[1] = 0x01;
	DK25L_TxBuffer[2] = CMD_ISO14443A_ACTIVATE;
	DK25L_CmdSend();
}
void DL25L_ISO14443A_APDU(uint8_t length, uint8_t *pdat){//ISO14443A PDU指令接口
	
}
#endif
