#include "sPlcDK25L.h"
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
		if(SBUF0 == DK25L_STX){//���յ�֡ͷ
			NVRAM0[SPREG_DK25L_RXCMD_INDEX] = 1;	
			*(prx) = DK25L_STX;
		}
		else if(NVRAM0[SPREG_DK25L_RXCMD_INDEX] == 1){//���յ������ֽ�
			NVRAM0[SPREG_DK25L_RXCMD_INDEX] = 2;
			*(prx + 1) = SBUF0;
		}
        else if((NVRAM0[SPREG_DK25L_RXCMD_INDEX] > 2) && (NVRAM0[SPREG_DK25L_RXCMD_INDEX] <  (40 - 1))){
			*(prx + NVRAM0[SPREG_DK25L_RXCMD_INDEX]) = SBUF0;
			NVRAM0[SPREG_DK25L_RXCMD_INDEX] ++;
			if((NVRAM0[SPREG_DK25L_RXCMD_INDEX] - 2) == *(prx + 1)){//���������Ͽ�ʼ
				switch(*(prx+2)){
					case CMD_FIND_CARD_UID:{
						break;
					}
					case CMD_FIND_CARD_TYPE:{
						break;
					}
					default:break;
				}
			}
		}

	}   
}

void DK25L_GET_UID(void){//��ȡ��Ƭ UID
}
void DK25L_GET_TPYE(void){//��ȡ��Ƭ����
}
void DK25L_GET_FWVER(void){//��ȡģ��
}
void DK25L_GET_HWVER(void){//��ȡģ��
}

#endif
