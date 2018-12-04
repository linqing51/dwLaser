#include "modbusSlaveAscii.h"
/****************************************************************************/
#define MODBUS_NO_ERR				0
#define MODBUS_ADR_ERR				1
#define MODBUS_LRC_ERR				2
#define MODBUS_OVERTIME_ERR			3
extern NVRAM0[];
data uint8_t ModbusSlaveRxNum, ModbusSlaveTxNum;                    
xdata uint8_t ModbusSlaveRxBuf[CONFIG_MODBUS_SLAVE_RX_BUFFER_SIZE], ModbusSlaveTxBuf[CONFIG_MODBUS_SLAVE_TX_BUFFER_SIZE];
data uint8_t *pModbusSlaveTxRead;//�����ж϶�ȡָ��
data uint8_t *pModbusSlaveRxWrite;//�����ж�д��ָ��
data uint8_t ModbusSlaveFlagRxDone, ModbusSlaveFlagRxDoing, ModbusSlaveFlagTxDone, ModbusSlaveFlagTxDoing;
data uint8_t ModbusSlaveAsciiError;
/****************************************************************************/
static void uint16ToAscii(uint16_t *dat, uint8_t *pstr){//��16λ�з�����ת��Ϊ4��ASCII�ַ�
	data uint8_t temp;
	temp = *dat & 0x000F;//0x000A
	if(temp <= 0x09){
		*(pstr + 3) = (temp + 0x30);
    }
    else{
		 *(pstr + 3) = (temp + 0x37);
    }
	temp = (*dat >> 4) & 0x000F;//0x00A0
	if(temp <= 0x09){
		*(pstr + 2) = (temp + 0x30);
    }
    else{
		 *(pstr + 2) = (temp + 0x37);
    }
	temp = (*dat >> 8) & 0x000F;//0x0A00
	if(temp <= 0x09){
		*(pstr + 1) = (temp + 0x30);
    }
    else{
		 *(pstr + 1) = (temp + 0x37);
    }
	temp = (*dat >> 12) & 0x000F;//0xA000
	if(temp <= 0x09){
		*pstr = (temp + 0x30);
    }
    else{
		*pstr = (temp + 0x37);
    }
}
static void uint8ToAscii(uint8_t *dat, uint8_t *pstr){//��16������ת��������ASCII�ַ�
	data uint8_t temp;
	temp = (*dat & 0x0f);
	if(temp <= 0x09){
		*(pstr + 1) = (temp + 0x30);
    }
    else{
		 *(pstr + 1) = (temp + 0x37);
    }
	temp = ((*dat & 0xf0) >> 4);
	if(temp <= 0x09){
		*pstr = (temp + 0x30);
	}
	else{
		*pstr = (temp + 0x37);
	}
}
static uint8_t asciiToUint8(uint8_t *pstr){//������int8_t ��ϳ�һ��16������
	data uint8_t temp[2];
	data uint8_t hex;
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[1] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[1] = *pstr - 0x30;	
	}
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[0] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[0] = *(pstr + 1) - 0x30;	
	}
	hex = 0;
	hex |= temp[0] & 0xF;
	hex |= (temp[1] & 0x0F << 4) & 0xF0;
	return hex;
}

static uint16_t asciiToUint16(uint8_t *pstr){
	data uint8_t temp[4];
	data uint16_t hex;
	//ȡ��0xA000
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[3] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[3] = *pstr - 0x30;	
	}
	//ȡ��0x0A00
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[2] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[2] = *(pstr + 1) - 0x30;	
	}
	//ȡ��0x00A0
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[1] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[1] = *pstr - 0x30;	
	}
	//ȡ��0x000A
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[0] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[0] = *(pstr + 1) - 0x30;	
	}
	hex = 0;
	hex |= temp[0] & 0x000F;
	hex |= ((temp[1] & 0x0F) << 4) & 0x00F0;
	hex |= ((temp[2] & 0x0F) << 8) & 0x0F00;
	hex |= ((temp[3] & 0x0F) << 12) & 0xF000;
	return hex;
}

static uint8_t LRC(uint8_t *buf, int32_t len){//����LRC LRC�����ǽ���Ϣ�е�8Bit���ֽ������ۼӣ������˽�λ
	int i;
	uint8_t lrc = 0;        /*lrc�ֽڳ�ʼ��*/
	for( i = 0; i < len; i++ ){
		lrc = lrc + buf[i];
	}
	return lrc;
}

void modbusSerialInit(int32_t baudrate)
{//��ʼ��MODBUS����
	uint32_t temp;
	temp = (uint32_t)(CONFIG_SYSCLK / 32 / baudrate);
	temp = 65536 - temp;	
	
	T2CON &= 1 << 4;//Timer 1 overflows used for transmit clock.
	T2CON &= 1 << 5;//Timer 1 overflows used for receive clock.
	
	TMOD &= 0x0F;
	TMOD |= 1 << 5;//Mode 2: 8-bit counter/timer with auto-reload
	
	TH1 = (uint8_t)(temp & 0xff);
	TL1 = (uint8_t)(temp & 0xff);
	TR1 = 1;
	//T2CON |= 1 << 2;//Timer 2 enabled
	//RS485_DIRECTION_RXD;//����״̬
	ES0 = 1;
	TI0 = 0;//����������   		
	RI0 = 0;//����������			
}
static void ModbusSlaveStartSend(void){
	ModbusSlaveFlagTxDone = 0;
	pModbusSlaveTxRead = ModbusSlaveTxBuf;
	TI0 = 1;
}
void modbusSlaveSerialIsr() interrupt INTERRUPT_UART0
{
	if(TI0){
        TI0 = 0;        
        if(ModbusSlaveTxNum == 0){
            ModbusSlaveFlagTxDone = 1;                    
        }
        else if(ModbusSlaveTxNum > 0)
			SBUF0 = *pModbusSlaveTxRead;			
            ModbusSlaveTxNum --;	
			if(pModbusSlaveTxRead == (ModbusSlaveTxBuf + CONFIG_MODBUS_SLAVE_TX_BUFFER_SIZE - 1)){
                pModbusSlaveTxRead = ModbusSlaveTxBuf;
				ModbusSlaveTxNum = 0;
            }
            else{
                pModbusSlaveTxRead ++;
            }               
	}
    if(RI0)
    {
        RI0 = 0;  
	    if(SBUF0 == MODBUS_ASCII_STX){//���յ���ʼ����
			ModbusSlaveOverTimeCounter = 0;
			//memset(ModbusSlaveRxBuf, 0x00, SerialRCV);
			pModbusSlaveRxWrite = ModbusSlaveRxBuf;
			*pModbusSlaveRxWrite = SBUF0;
			ModbusSlaveFlagRxDoing = 1;
			ModbusSlaveFlagRxDone = 0;
			ModbusSlaveRxNum = 1;
		}
		else if(SBUF0 == MODBUS_ASCII_END1){ //���յ���ֹ����
			*pModbusSlaveRxWrite = SBUF0;
			ModbusSlaveRxNum++;
			pModbusSlaveRxWrite = ModbusSlaveRxBuf;
			ModbusSlaveFlagRxDone = 1;
			ModbusSlaveFlagRxDoing = 0;
		}
		else if(ModbusSlaveFlagRxDoing && !ModbusSlaveFlagRxDone){//���������� 
			*pModbusSlaveRxWrite = SBUF0;        
			if(pModbusSlaveRxWrite == (ModbusSlaveRxBuf + CONFIG_MODBUS_SLAVE_RX_BUFFER_SIZE - 1)){
				pModbusSlaveRxWrite = ModbusSlaveRxBuf;
				ModbusSlaveRxNum = 0;
			}
			else {
				pModbusSlaveRxWrite++;
			}    
			ModbusSlaveRxNum++;
		}
   }   
}
                                       
void modbusSlaveAsciiPoll(void){//Modbus Slave Ascii ��ѯ 
	data uint8_t *prx, *ptx;
	data uint8_t ctemp[4];
	data int16_t stemp[4], i, j, k;
	prx = ModbusSlaveRxBuf;
	if(ModbusSlaveFlagRxDone){
		DISABLE_MODBUS_SERIAL_RX_INTERRUPT//�ر�Э������ж�
		ctemp[0] = asciiToUint8(ModbusSlaveRxBuf + 1);
		if(ctemp[0] == CONFIG_MODBUS_SLAVE_ADDRESS){//�ӵ�ַ��ȷ
			ctemp[0] = LRC((ModbusSlaveRxBuf + 1), (ModbusSlaveRxNum - 5));//�����������LRCУ��ֵ
			ctemp[1] = asciiToUint8(ModbusSlaveRxBuf + ModbusSlaveRxNum - 3);
			if(ctemp[0] == ctemp[1]){//LRCУ����ȷ
				ctemp[0] = asciiToUint8(ModbusSlaveRxBuf + 3);//���ܺ�
				switch(ctemp[0]){
					case 1:{//��ȡ��Ȧ״̬
						//modbusSlaveFun1();
						break;
					}
					case 2:{//��ȡ����״̬
						break;
					}
					case 3:{//��ȡ���ּĴ���
						break;
					}
					case 4:{//��ȡ����Ĵ���
						break;
					}
					case 5:{//ǿ�õ���Ȧ
						stemp[0] = asciiToUint16(ModbusSlaveRxBuf + 5);//��ȡ�����ַ 
						stemp[1] = asciiToUint16(ModbusSlaveRxBuf + 9);//��ȡ���ֵ
						if(stemp[1] == 0xFF00){
							SET(stemp[0]);
						}
						else{
							RESET(stemp[0]);
						}
						ModbusSlaveTxBuf[0] = ModbusSlaveRxBuf[0];//STX
						ModbusSlaveTxBuf[1] = ModbusSlaveRxBuf[1];//SLAVE ID
						ModbusSlaveTxBuf[2] = ModbusSlaveRxBuf[2];
						ModbusSlaveTxBuf[3] = ModbusSlaveRxBuf[3];//FUN
						ModbusSlaveTxBuf[4] = ModbusSlaveRxBuf[4];
						ModbusSlaveTxBuf[5] = ModbusSlaveRxBuf[5];//ADR
						ModbusSlaveTxBuf[6] = ModbusSlaveRxBuf[6];
						ModbusSlaveTxBuf[7] = ModbusSlaveRxBuf[7];
						ModbusSlaveTxBuf[8] = ModbusSlaveRxBuf[8];
						ModbusSlaveTxBuf[9] = ModbusSlaveRxBuf[9];//DAT
						ModbusSlaveTxBuf[10] = ModbusSlaveRxBuf[10];
						ModbusSlaveTxBuf[11] = ModbusSlaveRxBuf[11];
						ModbusSlaveTxBuf[12] = ModbusSlaveRxBuf[12];
						ModbusSlaveTxBuf[13] = MODBUS_ASCII_END0;
						ModbusSlaveTxBuf[14] = MODBUS_ASCII_END1;						
						ModbusSlaveTxNum = 15;	
						ModbusSlaveStartSend();
						NVRAM0[SP_EM_MODBUS_SLAVE_ERR] = MODBUS_NO_ERR; 
						break;
					}
					case 6:{//Ԥ�õ��Ĵ���
						stemp[0] = asciiToUint16(ModbusSlaveRxBuf + 5);//��ȡ�����ַ 
						stemp[1] = asciiToUint16(ModbusSlaveRxBuf + 9);//��ȡ���ֵ
						assertRegisterAddress(stemp[0]);
						NVRAM0[(stemp[0])] = stemp[1];
						ModbusSlaveTxBuf[0] = ModbusSlaveRxBuf[0];//STX
						ModbusSlaveTxBuf[1] = ModbusSlaveRxBuf[1];//SLAVE ID
						ModbusSlaveTxBuf[2] = ModbusSlaveRxBuf[2];
						ModbusSlaveTxBuf[3] = ModbusSlaveRxBuf[3];//FUN
						ModbusSlaveTxBuf[4] = ModbusSlaveRxBuf[4];
						ModbusSlaveTxBuf[5] = ModbusSlaveRxBuf[5];//ADR
						ModbusSlaveTxBuf[6] = ModbusSlaveRxBuf[6];
						ModbusSlaveTxBuf[7] = ModbusSlaveRxBuf[7];
						ModbusSlaveTxBuf[8] = ModbusSlaveRxBuf[8];
						ModbusSlaveTxBuf[9] = ModbusSlaveRxBuf[9];//DAT
						ModbusSlaveTxBuf[10] = ModbusSlaveRxBuf[10];
						ModbusSlaveTxBuf[11] = ModbusSlaveRxBuf[11];
						ModbusSlaveTxBuf[12] = ModbusSlaveRxBuf[12];
						ModbusSlaveTxBuf[13] = MODBUS_ASCII_END0;
						ModbusSlaveTxBuf[14] = MODBUS_ASCII_END1;
						ModbusSlaveTxNum = 15;	
						ModbusSlaveStartSend();
						NVRAM0[SP_EM_MODBUS_SLAVE_ERR] = MODBUS_NO_ERR; 
						break;
					}
					case 7:{//��ȡ�쳣״̬
					}
					case 8:{//�������У��
					}
					case 9:{//���
						break;
					}
					case 10:{//��ѯ
						break;
					}
					case 11:{//��ȡ�¼�����
						break;
					}
					case 12:{//��ȡͨ���¼���¼
						break;
					}
					case 13:{//��̣�184/384 484 584��
						break;
					}
					case 14:{//̽ѯ��184/384 484 584��
						break;
					}
					case 15:{//ǿ�ö���Ȧ
						stemp[0] = asciiToUint16(ModbusSlaveRxBuf + 5);//��ȡ�����ַ 
						stemp[1] = asciiToUint16(ModbusSlaveRxBuf + 9);//��ȡ�������
						if(stemp[1] >= 1 && stemp[1] <= 0x07B0){//����������
							for(i = 0;i <stemp[1];i ++){
								ctemp[0] = *(ModbusSlaveRxBuf + 13 + i);
								ctemp[0] = (ctemp[0] >> (stemp[1] % 8)) & 0x01;
								if(ctemp[0]){
									SET(stemp[0] - 1 + i);
								}
								else{
									RESET(stemp[0] - 1 + i);
								}
							}
						}
						ModbusSlaveTxBuf[0] = ModbusSlaveRxBuf[0];//STX
						ModbusSlaveTxBuf[1] = ModbusSlaveRxBuf[1];//SLAVE ID
						ModbusSlaveTxBuf[2] = ModbusSlaveRxBuf[2];
						ModbusSlaveTxBuf[3] = ModbusSlaveRxBuf[3];//FUN
						ModbusSlaveTxBuf[4] = ModbusSlaveRxBuf[4];
						ModbusSlaveTxBuf[5] = ModbusSlaveRxBuf[5];//ADR
						ModbusSlaveTxBuf[6] = ModbusSlaveRxBuf[6];
						ModbusSlaveTxBuf[7] = ModbusSlaveRxBuf[7];
						ModbusSlaveTxBuf[8] = ModbusSlaveRxBuf[8];
						ModbusSlaveTxBuf[9] = ModbusSlaveRxBuf[9];//NUM
						ModbusSlaveTxBuf[10] = ModbusSlaveRxBuf[10];
						ModbusSlaveTxBuf[11] = ModbusSlaveRxBuf[11];
						ModbusSlaveTxBuf[12] = ModbusSlaveRxBuf[12];
						ModbusSlaveTxBuf[13] = MODBUS_ASCII_END0;
						ModbusSlaveTxBuf[14] = MODBUS_ASCII_END1;						
						ModbusSlaveTxNum = 15;	
						ModbusSlaveStartSend();
						NVRAM0[SP_EM_MODBUS_SLAVE_ERR] = MODBUS_NO_ERR; 
						break;
					}
					case 16:{//Ԥ�ö�Ĵ���
						stemp[0] = asciiToUint16(ModbusSlaveRxBuf + 5);//��ȡ�����ַ 
						stemp[1] = asciiToUint16(ModbusSlaveRxBuf + 9);//��ȡ�������
						if(stemp[1] >= 1 && stemp[1] <= 0x0078){//����������
							for(i = 0;i <stemp[1];i ++){
								ctemp[0] = *(ModbusSlaveRxBuf + 13 + i);
								stemp[2] = asciiToUint16(ModbusSlaveRxBuf + 13 + (i * 4));
								NVRAM0[(stemp[0])] = stemp[2];
							}
						}
						ModbusSlaveTxBuf[0] = ModbusSlaveRxBuf[0];
						ModbusSlaveTxBuf[1] = ModbusSlaveRxBuf[1];
						ModbusSlaveTxBuf[2] = ModbusSlaveRxBuf[2];
						ModbusSlaveTxBuf[3] = ModbusSlaveRxBuf[3];
						ModbusSlaveTxBuf[4] = ModbusSlaveRxBuf[4];
						ModbusSlaveTxBuf[5] = ModbusSlaveRxBuf[5];
						ModbusSlaveTxBuf[6] = ModbusSlaveRxBuf[6];
						ModbusSlaveTxBuf[7] = ModbusSlaveRxBuf[7];
						ModbusSlaveTxBuf[8] = ModbusSlaveRxBuf[8];
						ModbusSlaveTxBuf[9] = ModbusSlaveRxBuf[9];
						ModbusSlaveTxBuf[10] = ModbusSlaveRxBuf[10];
						ModbusSlaveTxBuf[11] = ModbusSlaveRxBuf[11];
						ModbusSlaveTxBuf[12] = ModbusSlaveRxBuf[12];
						ModbusSlaveTxBuf[13] = MODBUS_ASCII_END0;
						ModbusSlaveTxBuf[14] = MODBUS_ASCII_END1;						
						ModbusSlaveTxNum = 15;	
						ModbusSlaveStartSend();
						NVRAM0[SP_EM_MODBUS_SLAVE_ERR] = MODBUS_NO_ERR; 
						break;
					}
					case 17:{//����ӻ���ʶ
						break;
					}
					case 18:{//884��MICRO 84
						break;
					}
					case 19:{//����ͨ����·
						break;
					}
					case 20:{//��ȡͨ�ò�����584L��
						break;
					}
					case 21:{//д��ͨ�ò�����584L��
						break;
					}
					default:break;
				}
			}
			else{//�ӵ�ַ����
				ModbusSlaveFlagRxDone = 0;//�����������
				NVRAM0[SP_EM_MODBUS_SLAVE_ERR] = MODBUS_LRC_ERR; 				
			}
		}
		else{//LRCУ�����
			ModbusSlaveFlagRxDone = 0;//�����������
			NVRAM0[SP_EM_MODBUS_SLAVE_ERR] = MODBUS_ADR_ERR;
		}
		ENABLE_MODBUS_SERIAL_INTERRUPT//��Э������ж�
	}		
}
// INT16U wtemp;
// FP64   ftemp1,ftemp2;
// INT8U *queun_location,err;
// queun_location = ModbusSlaveRxBuf;
// if	(ModbusSlaveFlagRxDone)  
// {
//  //ModbusSlaveFlagRxDone = 0;
//  if( *(queun_location) == 'A' && Locked != 1)    //��⵽Aָ���Ҳ�������̬��������
//  {//��⵽���� A ����
//     /********************************************************************************/
//	 /*�趨CH1 ����                                                                  */
//	 /********************************************************************************/
//	 CH1cur = ( *(queun_location + 1) - 0x30 ) * 100 + ( *(queun_location + 2) - 0x30 ) * 10 + ( *(queun_location + 3) - 0x30 );
//	 if(CH1cur >= CH1MAXCUR) CH1cur = CH1MAXCUR; //���յ��ĵ������ڶ����������ʱ ��������Ϊ�޶�
//	 ftemp1 = (FP64)CH1cur / CH1MAXCUR;   //��һ������ֵ [0,1]
//   	 DACOut020(1,ftemp1);                 //�����µĵ���ֵ CH1
//	 /********************************************************************************/
//	 /*�趨CH2 ����                                                                  */
//	 /********************************************************************************/
//	 CH2cur = ( *(queun_location + 9) - 0x30 ) * 100 + ( *(queun_location +10) - 0x30 ) * 10 + ( *(queun_location +11) - 0x30 );
//	 if(CH2cur >= CH2MAXCUR) CH2cur = CH2MAXCUR; //���յ��ĵ������ڶ����������ʱ ��������Ϊ�޶�
//	 ftemp2 = (FP64)CH2cur / CH2MAXCUR;   //��һ������ֵ [0,1]
//     DACOut020(2,ftemp2);                 //�����µĵ���ֵ CH1
//	 /*********************************************************************************/
//	 /*�趨CH1 ռ�ձ�                                                                 */
//	 /*********************************************************************************/
//	 wtemp = ( *(queun_location + 5) - 0x30 ) * 100 + ( *(queun_location + 6) - 0x30 ) * 10 + ( *(queun_location + 7) - 0x30 );
//	 if(wtemp < 5 ) wtemp = 5;    //�޶�PWM ռ�ձ���0-100%
//	 if(wtemp >= 100) wtemp = 100;
//	 ftemp1 = ( (FP64)wtemp / 100 ) * 255;   
//	 wtemp = (INT8U)ftemp1;
//	 if(wtemp < 0 ) wtemp = 0;    
//	 if(wtemp >= 255) wtemp = 255;
//	 //CH1cyc = wtemp;     //����CH1ռ�ձ�
//	 /*********************************************************************************/
//	 /*�趨CH2 ռ�ձ�                                                                 */
//	 /*********************************************************************************/
//	 wtemp = ( *(queun_location +13) - 0x30 ) * 100 + ( *(queun_location +14) - 0x30 ) * 10 + ( *(queun_location +15) - 0x30 );
//	 if(wtemp < 5 ) wtemp = 5;    //�޶�PWM ռ�ձ���0-100%
//	 if(wtemp >= 100) wtemp = 100;
//	 ftemp1 = ( (FP64)wtemp / 100 ) * 255;   
//	 wtemp = (INT8U)ftemp1;
//	 if(wtemp < 0 ) wtemp = 0;    
//	 if(wtemp >= 255) wtemp = 255;
//	 //CH2cyc = wtemp;     //����CH1ռ�ձ�
//	 /*********************************************************************************/
//	 /*RCK*****************************************************************************/
//  	 memset(ModbusSlaveTxBuf,0x00,SerialRCV);
//	 ModbusSlaveTxBuf[0] = 'C';
//	 ModbusSlaveTxBuf[1]	= 'A';
//   	 ModbusSlaveTxBuf[2] = 13; //�س�
//     StarSendUart0();
//	 /*********************************************************************************/	          
//   }




// }
// ModbusSlaveFlagRxDone = 0;
//}
