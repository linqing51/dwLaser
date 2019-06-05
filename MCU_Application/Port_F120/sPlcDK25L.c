#include "sPlcDK25L.h"
#define CARD_UNKNOWN					0x00
#define CARD_MIFARE						0x01
#define CARD_ULTRALIGHT					0x02
#define CARD_ISO14443B					0x03
#define CARD_ISO14443A					0x04
#define CARD_ISO15693					0x05
/*****************************************************************************/
#if CONFIG_SPLC_USING_DK25L == 1

void dk25l_uart_isr() interrupt INTERRUPT_UART0{
	int8_t *prx, *ptx;
	prx = (int8_t*)(&NVRAM0[SPREG_DK25L_RX_BUFFER]);
	ptx = (int8_t*)(&NVRAM0[SPREG_DK25L_TX_BUFFER]);
	if(TI0){
        TI0 = 0;        
//        if(SendNum == 0){
//            FlagSendOk = 0;                    
//        }
//        else {
//            SBUF0 = *SendRead;
//            if(SendRead == (SendBuf + SerialSEND - 1)){
//                SendRead = SendBuf;                        
//            }
//            else {
//                SendRead++;
//            }
//			SendNum--;						                   
//        }
    }
	if(RI0){
		RI0 = 0;
		if(SBUF0 == DK25L_STX){//接收到帧头
			NVRAM0[SPREG_DK25L_RXCMD_INDEX] = 1;	
			*(prx) = DK25L_STX;
		}
		else if(NVRAM0[SPREG_DK25L_RXCMD_INDEX] == 1){//接收到长度字节
			NVRAM0[SPREG_DK25L_RXCMD_INDEX] = 2;
			*(prx + 1) = SBUF0;
		}
        else if((NVRAM0[SPREG_DK25L_RXCMD_INDEX] > 2) && (NVRAM0[SPREG_DK25L_RXCMD_INDEX] <  (40 - 1))){
			*(prx + NVRAM0[SPREG_DK25L_RXCMD_INDEX]) = SBUF0;
			NVRAM0[SPREG_DK25L_RXCMD_INDEX] ++;
			if((NVRAM0[SPREG_DK25L_RXCMD_INDEX] - 2) == *(prx + 1)){//命令接收完毕开始
				switch(*(prx+2)){
					case CMD_FIND_CARD_UID:{
						switch(*(prx + 3)){
							case 0xE1:{//卡片未找到
								RES(SPCOIL_DK25L_VALID);
								SET(SPCOIL_DK25L_INVALID);
								RES(SPCOIL_DK25L_REMOVE);
								break;
							}
							case 0xEA:{//卡片离开
								RES(SPCOIL_DK25L_VALID);
								SET(SPCOIL_DK25L_INVALID);
								SET(SPCOIL_DK25L_REMOVE);
								break;
							}
							default:break;
						}
						break;
					}
					case CMD_FIND_CARD_TYPE:{
						NVRAM0[SPREG_DK25L_CARD_TYPE] = *(prx + 3);
						break;
					}
					case  CMD_READ_FW_VER:{
						NVRAM0[SPREG_DK25L_VER] &= 0x00FF;
						NVRAM0[SPREG_DK25L_VER] |= (*(prx + 3) << 8)
						break;
					}
					case CMD_READ_HW_VER:{
						NVRAM0[SPREG_DK25L_VER] &= 0xFF00;
						NVRAM0[SPREG_DK25L_VER] |= *(prx + 3);
						break;
					}				
					default:break;
				}
			}
		}

	}   
}

void DK25L_GET_UID(void){//获取卡片 UID
}
void DK25L_GET_TPYE(void){//获取卡片类型
}
void DK25L_GET_FWVER(void){//获取模块
}
void DK25L_GET_HWVER(void){//获取模块
}

#endif
