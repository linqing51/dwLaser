#include "modbusSlaveAscii.h"
/****************************************************************************/
data uint8_t ModbusSlaveRxNum, ModbusSlaveTxNum;                    
xdata uint8_t ModbusSlaveRxBuf[CONFIG_MODBUS_SLAVE_RX_BUFFER_SIZE], ModbusSlaveTxBuf[CONFIG_MODBUS_SLAVE_TX_BUFFER_SIZE];
data uint8_t *pModbusSlaveTxRead;//�����ж϶�ȡָ��
data uint8_t *pModbusSlaveRxWrite;//�����ж�д��ָ��
data uint8_t ModbusSlaveFlagRxDone, ModbusSlaveFlagRxDoing, ModbusSlaveFlagTxDone, ModbusSlaveFlagTxDoing;
data uint8_t ModbusSlaveAsciiError;
/****************************************************************************/
static void hex2ascii(uint8_t num, uint8_t *pcharH, uint8_t *pcharL){//��16������ת��������ASCII�ַ�
	uint8_t temp;
	temp = (num & 0x0f);
	if(temp <= 0x09)
    {
		*pcharL = (temp + 0x30);
    }
    else{
		 *pcharL = (temp + 0x37);
    }
	temp = ((num & 0xf0) >> 4);
	if(temp <= 0x09){
		*pcharH = (temp + 0x30);
	}
	else{
		*pcharH = (temp + 0x37);
	}
}
static uint8_t ascii2hex(uint8_t *pcharH, uint8_t *pcharL){//������int8_t ��ϳ�һ��16������
	uint8_t temph,templ;
	uint8_t hex;
	if(*pcharH >= 'A' && *pcharH <='F'){//A-F
		temph = *pcharH - 0x37; 
	}
	else if(*pcharH >= '0' && *pcharH <='9'){
		temph = *pcharH - 0x30;	
	}
	if(*pcharL >= 'A' && *pcharL <='F'){//A-F
		templ = *pcharL - 0x37; 
	}
	else if(*pcharL >= '0' && *pcharL <='9'){
		templ = *pcharL - 0x30;	
	}
	hex = ( temph <<4 )  + templ;
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
	RS485_DIRECTION_RXD;//����״̬
	ES0 = 1;
	TI0 = 0;//����������   		
	RI0 = 0;//����������			
}

void modbusSlaveSerialIsr() interrupt 4
{
	if(TI0){
        TI0 = 0;        
        if(ModbusSlaveTxNum == 0){
            ModbusSlaveFlagTxDone = 0;                    
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
	data uint8_t temp0, temp1;
	prx = ModbusSlaveRxBuf;
	if(ModbusSlaveFlagRxDone){
		DISABLE_MODBUS_SERIAL_INTERRUPT//�ж�
		temp0 = LRC((ModbusSlaveRxBuf + 1), (ModbusSlaveRxNum - 5));
		temp1 = ascii2hex((ModbusSlaveRxBuf + ModbusSlaveRxNum - 4), (ModbusSlaveRxBuf + ModbusSlaveRxNum - 3));
		if(temp0 == temp1){//LRCУ����ȷ
			temp0 = ascii2hex((ModbusSlaveRxBuf + 1), (ModbusSlaveRxBuf + 2));
			if(temp0 == CONFIG_MODBUS_SLAVE_ADDRESS){//�ӵ�ַ��ȷ
				temp0 = ascii2hex((ModbusSlaveRxBuf + 3), (ModbusSlaveRxBuf + 4));//���ܺ�
				switch(temp0){
					case 0x01:{
						break;
					}
					case 0x05:{//ǿ�õ���Ȧ
						break;
					}
					case 0x09:{//���
						break;
					}
					default:break;
				}
			}
			else{//�ӵ�ַ����
				ModbusSlaveFlagRxDone = 0;//�����������
				//ModbusSlaveAsciiError = 				
			}
		}
		else{//LRCУ�����
			ModbusSlaveFlagRxDone = 0;//�����������
			//ModbusSlaveAsciiError = 
		}
		ENABLE_MODBUS_SERIAL_INTERRUPT//�ж�
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
