#include "modbusSlaveAscii.h"
/****************************************************************************/
#define MODBUS_NO_ERR				0
#define MODBUS_ADR_ERR				1
#define MODBUS_LRC_ERR				2
#define MODBUS_OVERTIME_ERR			3
extern NVRAM0[];
data uint8_t ModbusSlaveRxNum, ModbusSlaveTxNum;                    
xdata uint8_t ModbusSlaveRxBuf[CONFIG_MODBUS_SLAVE_RX_BUFFER_SIZE], ModbusSlaveTxBuf[CONFIG_MODBUS_SLAVE_TX_BUFFER_SIZE];
data uint8_t *pModbusSlaveTxRead;//发送中断读取指针
data uint8_t *pModbusSlaveRxWrite;//接收中断写入指针
data uint8_t ModbusSlaveFlagRxDone, ModbusSlaveFlagRxDoing, ModbusSlaveFlagTxDone, ModbusSlaveFlagTxDoing;
data uint8_t ModbusSlaveAsciiError;
/****************************************************************************/
static void uint16ToAscii(uint16_t *dat, uint8_t *pstr){//将16位有符号数转换为4个ASCII字符
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
static void uint8ToAscii(uint8_t *dat, uint8_t *pstr){//将16进制数转换成两个ASCII字符
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
static uint8_t asciiToUint8(uint8_t *pstr){//将两个int8_t 组合成一个16进制数
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
	//取出0xA000
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[3] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[3] = *pstr - 0x30;	
	}
	//取出0x0A00
	if(*(pstr + 1) >= 'A' && *(pstr + 1) <='F'){//A-F
		temp[2] = *(pstr + 1) - 0x37; 
	}
	else if(*(pstr + 1) >= '0' && *(pstr + 1) <='9'){
		temp[2] = *(pstr + 1) - 0x30;	
	}
	//取出0x00A0
	if(*pstr >= 'A' && *pstr <='F'){//A-F
		temp[1] = *pstr - 0x37; 
	}
	else if(*pstr >= '0' && *pstr <='9'){
		temp[1] = *pstr - 0x30;	
	}
	//取出0x000A
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

static uint8_t LRC(uint8_t *buf, int32_t len){//计算LRC LRC方法是将消息中的8Bit的字节连续累加，丢弃了进位
	int i;
	uint8_t lrc = 0;        /*lrc字节初始化*/
	for( i = 0; i < len; i++ ){
		lrc = lrc + buf[i];
	}
	return lrc;
}

void modbusSerialInit(int32_t baudrate)
{//初始化MODBUS串口
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
	//RS485_DIRECTION_RXD;//接收状态
	ES0 = 1;
	TI0 = 0;//清除发送完成   		
	RI0 = 0;//清除接收完成			
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
	    if(SBUF0 == MODBUS_ASCII_STX){//接收到起始符号
			ModbusSlaveOverTimeCounter = 0;
			//memset(ModbusSlaveRxBuf, 0x00, SerialRCV);
			pModbusSlaveRxWrite = ModbusSlaveRxBuf;
			*pModbusSlaveRxWrite = SBUF0;
			ModbusSlaveFlagRxDoing = 1;
			ModbusSlaveFlagRxDone = 0;
			ModbusSlaveRxNum = 1;
		}
		else if(SBUF0 == MODBUS_ASCII_END1){ //接收到终止符号
			*pModbusSlaveRxWrite = SBUF0;
			ModbusSlaveRxNum++;
			pModbusSlaveRxWrite = ModbusSlaveRxBuf;
			ModbusSlaveFlagRxDone = 1;
			ModbusSlaveFlagRxDoing = 0;
		}
		else if(ModbusSlaveFlagRxDoing && !ModbusSlaveFlagRxDone){//接收数据中 
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
                                       
void modbusSlaveAsciiPoll(void){//Modbus Slave Ascii 轮询 
	data uint8_t *prx, *ptx;
	data uint8_t ctemp[4];
	data int16_t stemp[4], i, j, k;
	prx = ModbusSlaveRxBuf;
	if(ModbusSlaveFlagRxDone){
		DISABLE_MODBUS_SERIAL_RX_INTERRUPT//关闭协议接收中断
		ctemp[0] = asciiToUint8(ModbusSlaveRxBuf + 1);
		if(ctemp[0] == CONFIG_MODBUS_SLAVE_ADDRESS){//从地址正确
			ctemp[0] = LRC((ModbusSlaveRxBuf + 1), (ModbusSlaveRxNum - 5));//计算接收数据LRC校验值
			ctemp[1] = asciiToUint8(ModbusSlaveRxBuf + ModbusSlaveRxNum - 3);
			if(ctemp[0] == ctemp[1]){//LRC校验正确
				ctemp[0] = asciiToUint8(ModbusSlaveRxBuf + 3);//功能号
				switch(ctemp[0]){
					case 1:{//读取线圈状态
						//modbusSlaveFun1();
						break;
					}
					case 2:{//读取输入状态
						break;
					}
					case 3:{//读取保持寄存器
						break;
					}
					case 4:{//读取输入寄存器
						break;
					}
					case 5:{//强置单线圈
						stemp[0] = asciiToUint16(ModbusSlaveRxBuf + 5);//获取输出地址 
						stemp[1] = asciiToUint16(ModbusSlaveRxBuf + 9);//获取输出值
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
					case 6:{//预置单寄存器
						stemp[0] = asciiToUint16(ModbusSlaveRxBuf + 5);//获取输出地址 
						stemp[1] = asciiToUint16(ModbusSlaveRxBuf + 9);//获取输出值
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
					case 7:{//读取异常状态
					}
					case 8:{//回送诊断校验
					}
					case 9:{//编程
						break;
					}
					case 10:{//控询
						break;
					}
					case 11:{//读取事件计数
						break;
					}
					case 12:{//读取通信事件记录
						break;
					}
					case 13:{//编程（184/384 484 584）
						break;
					}
					case 14:{//探询（184/384 484 584）
						break;
					}
					case 15:{//强置多线圈
						stemp[0] = asciiToUint16(ModbusSlaveRxBuf + 5);//获取输出地址 
						stemp[1] = asciiToUint16(ModbusSlaveRxBuf + 9);//获取输出数量
						if(stemp[1] >= 1 && stemp[1] <= 0x07B0){//检查输出数量
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
					case 16:{//预置多寄存器
						stemp[0] = asciiToUint16(ModbusSlaveRxBuf + 5);//获取输出地址 
						stemp[1] = asciiToUint16(ModbusSlaveRxBuf + 9);//获取输出数量
						if(stemp[1] >= 1 && stemp[1] <= 0x0078){//检查输出数量
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
					case 17:{//报告从机标识
						break;
					}
					case 18:{//884和MICRO 84
						break;
					}
					case 19:{//重置通信链路
						break;
					}
					case 20:{//读取通用参数（584L）
						break;
					}
					case 21:{//写入通用参数（584L）
						break;
					}
					default:break;
				}
			}
			else{//从地址错误
				ModbusSlaveFlagRxDone = 0;//接收完成清零
				NVRAM0[SP_EM_MODBUS_SLAVE_ERR] = MODBUS_LRC_ERR; 				
			}
		}
		else{//LRC校验错误
			ModbusSlaveFlagRxDone = 0;//接收完成清零
			NVRAM0[SP_EM_MODBUS_SLAVE_ERR] = MODBUS_ADR_ERR;
		}
		ENABLE_MODBUS_SERIAL_INTERRUPT//打开协议接收中断
	}		
}
// INT16U wtemp;
// FP64   ftemp1,ftemp2;
// INT8U *queun_location,err;
// queun_location = ModbusSlaveRxBuf;
// if	(ModbusSlaveFlagRxDone)  
// {
//  //ModbusSlaveFlagRxDone = 0;
//  if( *(queun_location) == 'A' && Locked != 1)    //检测到A指令且不再锁定态调节设置
//  {//检测到调节 A 命令
//     /********************************************************************************/
//	 /*设定CH1 电流                                                                  */
//	 /********************************************************************************/
//	 CH1cur = ( *(queun_location + 1) - 0x30 ) * 100 + ( *(queun_location + 2) - 0x30 ) * 10 + ( *(queun_location + 3) - 0x30 );
//	 if(CH1cur >= CH1MAXCUR) CH1cur = CH1MAXCUR; //接收到的电流大于定义的最大电流时 以最大电流为限度
//	 ftemp1 = (FP64)CH1cur / CH1MAXCUR;   //归一化电流值 [0,1]
//   	 DACOut020(1,ftemp1);                 //设置新的电流值 CH1
//	 /********************************************************************************/
//	 /*设定CH2 电流                                                                  */
//	 /********************************************************************************/
//	 CH2cur = ( *(queun_location + 9) - 0x30 ) * 100 + ( *(queun_location +10) - 0x30 ) * 10 + ( *(queun_location +11) - 0x30 );
//	 if(CH2cur >= CH2MAXCUR) CH2cur = CH2MAXCUR; //接收到的电流大于定义的最大电流时 以最大电流为限度
//	 ftemp2 = (FP64)CH2cur / CH2MAXCUR;   //归一化电流值 [0,1]
//     DACOut020(2,ftemp2);                 //设置新的电流值 CH1
//	 /*********************************************************************************/
//	 /*设定CH1 占空比                                                                 */
//	 /*********************************************************************************/
//	 wtemp = ( *(queun_location + 5) - 0x30 ) * 100 + ( *(queun_location + 6) - 0x30 ) * 10 + ( *(queun_location + 7) - 0x30 );
//	 if(wtemp < 5 ) wtemp = 5;    //限定PWM 占空比在0-100%
//	 if(wtemp >= 100) wtemp = 100;
//	 ftemp1 = ( (FP64)wtemp / 100 ) * 255;   
//	 wtemp = (INT8U)ftemp1;
//	 if(wtemp < 0 ) wtemp = 0;    
//	 if(wtemp >= 255) wtemp = 255;
//	 //CH1cyc = wtemp;     //更新CH1占空比
//	 /*********************************************************************************/
//	 /*设定CH2 占空比                                                                 */
//	 /*********************************************************************************/
//	 wtemp = ( *(queun_location +13) - 0x30 ) * 100 + ( *(queun_location +14) - 0x30 ) * 10 + ( *(queun_location +15) - 0x30 );
//	 if(wtemp < 5 ) wtemp = 5;    //限定PWM 占空比在0-100%
//	 if(wtemp >= 100) wtemp = 100;
//	 ftemp1 = ( (FP64)wtemp / 100 ) * 255;   
//	 wtemp = (INT8U)ftemp1;
//	 if(wtemp < 0 ) wtemp = 0;    
//	 if(wtemp >= 255) wtemp = 255;
//	 //CH2cyc = wtemp;     //更新CH1占空比
//	 /*********************************************************************************/
//	 /*RCK*****************************************************************************/
//  	 memset(ModbusSlaveTxBuf,0x00,SerialRCV);
//	 ModbusSlaveTxBuf[0] = 'C';
//	 ModbusSlaveTxBuf[1]	= 'A';
//   	 ModbusSlaveTxBuf[2] = 13; //回车
//     StarSendUart0();
//	 /*********************************************************************************/	          
//   }




// }
// ModbusSlaveFlagRxDone = 0;
//}
