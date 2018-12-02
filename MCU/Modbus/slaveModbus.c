#include "slaveModbus.h"
/*****************************************************************************/
static data uint8_t localAddr; //单片机控制板的地址
static data uint8_t receTimeOut;//接收超时
static data uint8_t sendCount;//发送字节个数
static data uint8_t receCount;//接收到的字节个数
static xdata uint8_t receBuf[CONFIG_MODBUS_SLAVE_RX_BUFF_SIZE];
static xdata uint8_t sendBuf[CONFIG_MODBUS_SLAVE_TX_BUFF_SIZE];
static data uint8_t bt1ms;//定时标志位
static void timeProc(void);
static void checkComm0Modbus(void);
 
uint8_t code auchCRCHi[] = 
{//CRC 高位字节值表 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
	0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
	0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
	0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
	0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
	0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
	0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
	0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
	0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
	0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
	0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
	0x80, 0x41, 0x00, 0xC1, 0x81, 0x40 
} ; 

uint8_t code auchCRCLo[] = 
{//CRC低位字节值表
	0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 
	0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD, 
	0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09, 		  
	0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 
	0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4, 
	0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3, 
	0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 
	0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4, 
	0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A, 
	0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 
	0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED, 
	0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26, 
	0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 
	0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67, 
	0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F, 
	0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 
	0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 
	0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5, 
	0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 
	0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92, 
	0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C, 
	0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 
	0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B, 
	0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C, 
	0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 
	0x43, 0x83, 0x41, 0x81, 0x80, 0x40 
};

void presetSingleRegister(void);
void setCoilVal(uint16_t addr,uint16_t tempData);
void getCoilVal(uint16_t addr,uint16_t *tempData);
void getRegisterVal(uint16_t addr,uint16_t *tempData);
void setRegisterVal(uint16_t addr,uint16_t tempData);

/*****************************************************************************/
void InitModbusHardware(uint32_t baudrate)
{//初始化MODBUS硬件
	memset(receBuf, 0x00, sizeof(receBuf)); 
	memset(sendBuf, 0x00, sizeof(receBuf)); 
	InitModbusTimer();//初始化计时器
	InitModbusSerial(baudrate);//初始化串口
	
}
void modbusTimerHandle(void)
{//计时器中断
	bt1ms = 1;
}
void modbusSerialRxHandle(void)
{//串口接收中断
	receTimeOut = CONFIG_MODBUS_SLAVE_RX_TIMEOUT;//通讯超时值这个地方很重要	10ms
	receBuf[receCount] = SBUF0;
	receCount++;          //接收地址偏移寄存器加1	
}
void modbusSerialTxHandle(void)
{//串口发射中断
}
void modbusPoll(void)
{
	timeProc();
	checkComm0Modbus();	
}
void setModbusSlaveAddr(uint8_t addr)
{//设置从机地址
	localAddr = addr;
}
/*****************************************************************************/

static void timeProc(void)
{//定时处理
	if(bt1ms)
	{
		bt1ms = 0;
		if(receTimeOut > 0)
		{ 
			receTimeOut --;
			if(receTimeOut == 0 && receCount>0)   //判断通讯接收是否超时
			{
				RS485_DIRECTION_RXD;//将485置为接收状态                                                                                                                                                              
				receCount = 0;//      //将接收地址偏移寄存器清零
				memset(receBuf, 0x00, sizeof(receBuf)); 
			 }
		 }
	}
}
static uint16_t crc16(uint8_t *puchMsg, uint16_t usDataLen) 
{//CRC16生成器 
	data uint8_t uchCRCHi = 0xFF ; /* 高CRC字节初始化 */ 
	data uint8_t uchCRCLo = 0xFF ; /* 低CRC 字节初始化 */ 
	data uint16_t uIndex ; /* CRC循环中的索引 */ 
	while (usDataLen--) /* 传输消息缓冲区 */ 
	{ 
		uIndex = uchCRCHi ^ *puchMsg++ ; /* 计算CRC */ 
		uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex] ; 
		uchCRCLo = auchCRCLo[uIndex] ; 
	} 
	return (uchCRCLo << 8 | uchCRCHi) ; 
}		
static void beginSend(void)
{//发送数据
	RS485_DIRECTION_TXD;//处于发送
	modbusSerialSendBuffer(sendBuf, sendCount);
	RS485_DIRECTION_RXD;//发送完后将485置于接收状态
    receCount = 0;   //清接收地址偏移寄存器
}
static void readCoils(void)
{//fuction:01 读单个或多个线圈状态
	uint16_t addr;
	uint16_t tempAddr;
	uint16_t byteCount;
	uint16_t bitCount;
	uint16_t crcData;
	uint16_t position;
	uint16_t i, k;
	uint16_t tempData;
	uint8_t exit = 0;
	addr = (receBuf[2]<<8) + receBuf[3]; 
	tempAddr = addr;
	bitCount = (receBuf[4]<<8) + receBuf[5]; //读取的位个数
	byteCount = bitCount / 8;    //字节个数
	if(bitCount%8 != 0)
	{
	  byteCount++;
	}		
	for(k = 0; k < byteCount; k ++)//字节位置
	{
		position = k + 3;
		sendBuf[position] = 0;
		for(i = 0; i < 8; i ++)
		{
			getCoilVal(tempAddr, &tempData);
			sendBuf[position] |= tempData << i;
			tempAddr++;
			if(tempAddr >= addr + bitCount)//读完
			{ 
				exit = 1;
				break;
			} 
		}
		if(exit == 1)
		break;
	}
	sendBuf[0] = localAddr;
	sendBuf[1] = 0x01; 
	sendBuf[2] = byteCount;
	byteCount += 3;
	crcData = crc16(sendBuf,byteCount); 
	sendBuf[byteCount] = crcData & 0xff;
	byteCount++;
	sendBuf[byteCount] = crcData >> 8;
	sendCount = byteCount + 1;
	beginSend();   
}
static void readInPutCoils(void)
{//fuction:02 读取线圈输入（只读寄存器）状态
	uint16_t addr;
	uint16_t tempAddr;
	uint16_t byteCount;
	uint16_t  bitCount;
	uint16_t crcData;
	uint16_t  position;
	uint16_t  i,k;
	uint16_t tempData;
	uint8_t  exit = 0;
	addr = (receBuf[2]<<8) + receBuf[3]; 
	tempAddr = addr +10000;        //只读线圈寄存器偏移地址10000
	bitCount = (receBuf[4]<<8) + receBuf[5]; //读取的位个数
	byteCount = bitCount / 8;    //字节个数
	if(bitCount%8 != 0)
	{
		byteCount++;
	}		
	for(k=0;k<byteCount;k++)//字节位置
	{
		position = k + 3;
		sendBuf[position] = 0;
		for(i=0;i<8;i++)
		{
			getCoilVal(tempAddr,&tempData);
			sendBuf[position] |= tempData << i;
			tempAddr++;
			if(tempAddr >= addr+bitCount)//读完
			{ 
				exit = 1;
				break;
			} 
		}
		if(exit == 1)
		{
			break;
		}
	}
	sendBuf[0] = localAddr;
	sendBuf[1] = 0x02; 
	sendBuf[2] = byteCount;
	byteCount += 3;
	crcData = crc16(sendBuf,byteCount); 
	sendBuf[byteCount] = crcData & 0xff;
	byteCount++;
	sendBuf[byteCount] = crcData >> 8;
	sendCount = byteCount + 1;
	beginSend();   
}
static void readRegisters(void)
{//function code : 03，读取多个保持寄存器值
	uint16_t addr;
	uint16_t tempAddr;
	uint16_t crcData;
	uint16_t readCount;
	uint16_t byteCount;
	uint16_t i;
	uint16_t tempData = 0; 
	addr = (receBuf[2]<<8) + receBuf[3]; 
	tempAddr = addr+40000;      //+40000,保持寄存器偏移地址
	readCount = (receBuf[4]<<8) + receBuf[5]; //要读的个数 ,整型
	byteCount = readCount * 2;                  //每个寄存器内容占高，低两个字节
	for(i=0;i<byteCount;i+=2,tempAddr++)
	{
		getRegisterVal(tempAddr,&tempData);    
		sendBuf[i+3] = tempData >> 8;        
		sendBuf[i+4] = tempData & 0xff;  
	}
	sendBuf[0] = localAddr;
	sendBuf[1] = 3;  //function code : 03
	sendBuf[2] = byteCount;
	byteCount += 3;             //加上前面的地址，功能码，地址 共3+byteCount个字节
	crcData = crc16(sendBuf,byteCount);
	sendBuf[byteCount] = crcData & 0xff;   // CRC代码低位在前
	byteCount++;
	sendBuf[byteCount] = crcData >> 8 ;	   //高位在后
	sendCount = byteCount + 1;			//例如byteCount=49，则sendBuf[]中实际上有49+1个元素待发
	beginSend();
}
static void readInPutRegisters(void)
{//fuction 04:读取输入寄存器
	uint16_t addr;
	uint16_t tempAddr;
	uint16_t crcData;
	uint16_t readCount;
	uint16_t byteCount;
	uint16_t i;
	uint16_t tempData = 0; 
	addr = (receBuf[2]<<8) + receBuf[3]; 
	tempAddr = addr+30000;  //+输入寄存器偏移地址：30000
	readCount = (receBuf[4]<<8) + receBuf[5]; //要读的个数 ,整型
	byteCount = readCount * 2;                  //每个寄存器内容占高，低两个字节
	for(i=0;i<byteCount;i+=2,tempAddr++)
	{
		getRegisterVal(tempAddr,&tempData);    
		sendBuf[i+3] = tempData >> 8;        
		sendBuf[i+4] = tempData & 0xff;  
	}
	sendBuf[0] = localAddr;
	sendBuf[1] = 4;  //function code : 04
	sendBuf[2] = byteCount;
	byteCount += 3;             //加上前面的地址，功能码，地址 共3+byteCount个字节
	crcData = crc16(sendBuf,byteCount);
	sendBuf[byteCount] = crcData & 0xff;   // CRC代码低位在前
	byteCount++;
	sendBuf[byteCount] = crcData >> 8 ;	   //高位在后
	sendCount = byteCount + 1;			//例如byteCount=49，则sendBuf[]中实际上有49+1个元素待发
	beginSend();
}
static void forceSingleCoil(void)
{//fuction:05 ,强制单个线圈
	uint16_t addr;
	uint16_t tempAddr;
	uint16_t tempData;
	uint16_t  onOff;
	uint8_t i;
	addr = (receBuf[2]<<8) + receBuf[3]; 
	tempAddr = addr;
	onOff = (receBuf[4]<<8) + receBuf[5]; 
	if(onOff == 0xff00)
	{ 
		tempData = 1;//设为ON
	} 
	else if(onOff == 0x0000)//设为OFF
	{ 
		tempData = 0;
	}
	setCoilVal(tempAddr, tempData); 
	for(i=0;i<receCount; i++)
	{
		sendBuf[i] = receBuf[i];
	}
	sendCount = receCount;
	beginSend(); 
}

static void presetSingleRegister(void)
{//fuction:06设置单个寄存器
	uint16_t addr;
	uint16_t tempAddr;
	uint16_t tempData;
	uint16_t crcData;
	addr = (receBuf[2]<<8) + receBuf[3];
	tempAddr = (addr+40000);
	tempData = (receBuf[4]<<8) + receBuf[5];
	setRegisterVal(tempAddr,tempData);  
	sendBuf[0] = localAddr;
	sendBuf[1] = 6;    //function code : 16
	sendBuf[2] = addr >> 8;  //寄存器地址高位
	sendBuf[3] = addr & 0xff;//寄存器地址低位
	sendBuf[4] =receBuf[4];
	sendBuf[5] =receBuf[5];
	crcData = crc16(sendBuf,6);//生成CRC校验码
	sendBuf[6] = crcData & 0xff;  //CRC代码低位在前
	sendBuf[7] = crcData >> 8;	  //高位在后
	sendCount = 8;
	beginSend(); 
}

static void forceMultipleCoils(void)
{//function code : 15，强置多线圈值
	uint16_t addr;
	uint16_t tempAddr;
	uint16_t byteCount;
	uint16_t  bitCount;
	uint16_t crcData;
	uint16_t tempData;
	uint16_t  i,k;
	uint8_t  exit = 0;
	addr = (receBuf[2] << 8) + receBuf[3];
	tempAddr = addr;
	bitCount = (receBuf[4] << 8) + receBuf[5];
	byteCount = bitCount / 8;    //字节个数
	if(bitCount%8 != 0)
	{
		byteCount++;
	}		
	for(k = 0;k < byteCount;k ++)//字节位置
	{
		for(i = 0;i < 8;i ++)
		{
			tempData = (receBuf[k + 7] >> i) & 0x01;//对应位 位置  
			setCoilVal(tempAddr, tempData); 
			tempAddr++;
			if(tempAddr >= addr + bitCount)//读完
			{ 
				exit = 1;
				break;
			} 
		}
		if(exit == 1)
		break;
	}
	sendBuf[0] = localAddr;
	sendBuf[1] = 15;    //function code : 16
	sendBuf[2] = addr >> 8;  //寄存器地址高位
	sendBuf[3] = addr & 0xff;//寄存器地址低位
	sendBuf[4] = bitCount >> 8;//待设置寄存器数量高位
	sendBuf[5] = bitCount & 0xff;//待设置寄存器数量低位
	crcData = crc16(sendBuf, 6);//生成CRC校验码
	sendBuf[6] = crcData & 0xff;  //CRC代码低位在前
	sendBuf[7] = crcData >> 8;	  //高位在后
	sendCount = 8;
	beginSend(); 
}

static void presetMultipleRegisters(void)
{//function code : 16，设置多个寄存器值
	uint16_t addr;
	uint16_t tempAddr;
	uint16_t setCount;
	uint16_t crcData;
	uint16_t tempData;
	uint8_t i;
	addr = (receBuf[2]<<8) + receBuf[3];
	tempAddr = addr + 40000;
	setCount = (receBuf[4] << 8) + receBuf[5]; 
	for(i = 0;i < setCount;i ++,tempAddr ++)
	{
		tempData = (receBuf[i*2+7]<<8) + receBuf[i*2+8];//待设置寄存器值
		setRegisterVal(tempAddr,tempData);  
	}
	sendBuf[0] = localAddr;
	sendBuf[1] = 16;    //function code : 16
	sendBuf[2] = addr >> 8;  //寄存器地址高位
	sendBuf[3] = addr & 0xff;//寄存器地址低位
	sendBuf[4] = setCount >> 8;//待设置寄存器数量高位
	sendBuf[5] = setCount & 0xff;//待设置寄存器数量低位
	crcData = crc16(sendBuf,6);//生成CRC校验码
	sendBuf[6] = crcData & 0xff;  //CRC代码低位在前
	sendBuf[7] = crcData >> 8;	  //高位在后
	sendCount = 8;
	beginSend(); 
}
/*************************查询uart接收的数据包内容函数 **************************/
////函数功能：丛机根据串口接收到的数据包receBuf[1]里面的内容，即function code执行相应的命令
/********************************************************************************/
static void checkComm0Modbus(void)		   //10ms内必须响应接收数据
{
	uint16_t crcData;
	uint16_t tempData;
	uint16_t temp;
	if(receCount > 4)		 
	{//如果接收到数据	 
		switch(receBuf[1])
		{
			case 1:								
			{//读取寄存器(一个或多个)	 
				
				if(receCount >= 8)  //从询问数据包格式可知，receCount应该等于8	，接收完成一组数据应该关闭接收中断
				{	   	 
					if(receBuf[0] == localAddr)//核对地址
					{	 
						crcData = crc16(receBuf, 6);//核对校验码
						temp=receBuf[7];
						temp=(temp<<8)+receBuf[6];
						if(crcData == temp)
						{
							readCoils();//读取线圈输出状态(一个或多个) 
						}
						receCount = 0; 									  
					}					
				}      
				break;
			}
			case 2:								
			{//读取寄存器(一个或多个)	 
				if(receCount >= 8)  
				{//从询问数据包格式可知，receCount应该等于8	，接收完成一组数据应该关闭接收中断   	 
					if(receBuf[0] == localAddr)  
					{//核对地址	 
						crcData = crc16(receBuf,6);                     //核对校验码
						temp=receBuf[7];
						temp=(temp<<8)+receBuf[6];
						if(crcData == temp)
						{
							readInPutCoils();			//读取线圈输入状态(一个或多个) 
						}
						receCount = 0; 									  
					}				
				}      
				break;
			}
			
			case 3:
			{//读取寄存器(一个或多个)	 
				if(receCount >= 8)  
				{//从询问数据包格式可知，receCount应该等于8 接收完成一组数据应该关闭接收中断
					if(receBuf[0]==localAddr)   
					{//核对地址	 
						crcData = crc16(receBuf,6);                     //核对校验码
						temp=receBuf[7];
						temp=(temp<<8)+receBuf[6];
						if(crcData == temp)
						{
							readRegisters();//读取保持寄存器(一个或多个) 						  
						}	
						receCount = 0; 				
					}
				}					
				break;
			}
			case 4:								
			{//读取寄存器(一个或多个)	 
				if(receCount >= 8)  
				{//从询问数据包格式可知，receCount应该等于8 接收完成一组数据应该关闭接收中断   					
					if(receBuf[0]==localAddr)   //核对地址
					{	 
						crcData = crc16(receBuf,6);                     //核对校验码
						temp=receBuf[7];
						temp=(temp<<8)+receBuf[6];
						if(crcData == temp)
						{ 
							readInPutRegisters();//读取输入寄存器(一个或多个) 
						}
						receCount = 0; 									  
					}	
				}      
				break;
			}
			case 5:								
			{//读取寄存器(一个或多个)	 
				if(receCount >= 8)  
				{//从询问数据包格式可知 receCount应该等于8 接收完成一组数据应该关闭接收中断   		
					if(receBuf[0] == localAddr)   
					{//核对地址	 
						crcData = crc16(receBuf, 6);//核对校验码
						temp = receBuf[7];
						temp = (temp<<8) + receBuf[6];
						if(crcData == temp)
						{ 
							forceSingleCoil();//强置单个线圈 状态
						}
						receCount = 0; 									  
					}
				}      
				break;
			}
			case 6: 
			{//写单个保持寄存器	
				if(receCount >= 8)
				{//预设单个保持寄存器    
					if(receBuf[0]==localAddr)
					{
						crcData = crc16(receBuf, 6);
						temp = receBuf[7];
						temp = (temp<<8) + receBuf[6];
						if(crcData == temp)
						{ 
							presetSingleRegister();      //预置单个保持寄存器
							//可选保存设置数据到EPROM  
						} 
					receCount = 0;                                                                                                                                         
					}
				}
				break;
			}
			case 15:
			{//设置多个线圈
				tempData = receBuf[6]; 
				tempData += 9; //数据个数
				if(receCount >= tempData)
				{
					if(receBuf[0] == localAddr )
					{
						crcData = crc16(receBuf, tempData - 2);
						if(crcData == (receBuf[tempData-1] << 8)+ receBuf[tempData - 2])//更改了？？
						{
							forceMultipleCoils();  
							//可选保存设置数据到EPROM  
						}
					} 
					receCount = 0;
				}
				break;
			}				
			case 16:
			{//设置多个寄存器
				tempData = (receBuf[4]<<8) + receBuf[5];//设置寄存器个数
				tempData = tempData * 2;//数据个数=	寄存器*2
				tempData += 9;       //从询问数据包格式可知，receCount应该等于9+byteCount
				if(receCount >= tempData)
				{  	
					if(receBuf[0]==localAddr )	//核对地址
					{	 
						crcData = crc16(receBuf, tempData - 2);
						temp = receBuf[tempData - 1];
						temp=(temp << 8) + receBuf[tempData - 2]; 
						if(crcData == temp)
						{  
							presetMultipleRegisters();  
							//可选保存设置数据到EPROM  
						}
					} 
					receCount = 0;
				}
				break; 	
			}   
			default: break;  
		}
	}
}