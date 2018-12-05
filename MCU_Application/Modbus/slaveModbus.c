#include "slaveModbus.h"
/*****************************************************************************/
static data uint8_t localAddr; //��Ƭ�����ư�ĵ�ַ
static data uint8_t receTimeOut;//���ճ�ʱ
static data uint8_t sendCount;//�����ֽڸ���
static data uint8_t receCount;//���յ����ֽڸ���
static xdata uint8_t receBuf[CONFIG_MODBUS_SLAVE_RX_BUFF_SIZE];
static xdata uint8_t sendBuf[CONFIG_MODBUS_SLAVE_TX_BUFF_SIZE];
static data uint8_t bt1ms;//��ʱ��־λ
static void timeProc(void);
static void checkComm0Modbus(void);
 
uint8_t code auchCRCHi[] = 
{//CRC ��λ�ֽ�ֵ�� 
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
{//CRC��λ�ֽ�ֵ��
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
{//��ʼ��MODBUSӲ��
	memset(receBuf, 0x00, sizeof(receBuf)); 
	memset(sendBuf, 0x00, sizeof(receBuf)); 
	InitModbusTimer();//��ʼ����ʱ��
	InitModbusSerial(baudrate);//��ʼ������
	
}
void modbusTimerHandle(void)
{//��ʱ���ж�
	bt1ms = 1;
}
void modbusSerialRxHandle(void)
{//���ڽ����ж�
	receTimeOut = CONFIG_MODBUS_SLAVE_RX_TIMEOUT;//ͨѶ��ʱֵ����ط�����Ҫ	10ms
	receBuf[receCount] = SBUF0;
	receCount++;          //���յ�ַƫ�ƼĴ�����1	
}
void modbusSerialTxHandle(void)
{//���ڷ����ж�
}
void modbusPoll(void)
{
	timeProc();
	checkComm0Modbus();	
}
void setModbusSlaveAddr(uint8_t addr)
{//���ôӻ���ַ
	localAddr = addr;
}
/*****************************************************************************/

static void timeProc(void)
{//��ʱ����
	if(bt1ms)
	{
		bt1ms = 0;
		if(receTimeOut > 0)
		{ 
			receTimeOut --;
			if(receTimeOut == 0 && receCount>0)   //�ж�ͨѶ�����Ƿ�ʱ
			{
				RS485_DIRECTION_RXD;//��485��Ϊ����״̬                                                                                                                                                              
				receCount = 0;//      //�����յ�ַƫ�ƼĴ�������
				memset(receBuf, 0x00, sizeof(receBuf)); 
			 }
		 }
	}
}
static uint16_t crc16(uint8_t *puchMsg, uint16_t usDataLen) 
{//CRC16������ 
	data uint8_t uchCRCHi = 0xFF ; /* ��CRC�ֽڳ�ʼ�� */ 
	data uint8_t uchCRCLo = 0xFF ; /* ��CRC �ֽڳ�ʼ�� */ 
	data uint16_t uIndex ; /* CRCѭ���е����� */ 
	while (usDataLen--) /* ������Ϣ������ */ 
	{ 
		uIndex = uchCRCHi ^ *puchMsg++ ; /* ����CRC */ 
		uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex] ; 
		uchCRCLo = auchCRCLo[uIndex] ; 
	} 
	return (uchCRCLo << 8 | uchCRCHi) ; 
}		
static void beginSend(void)
{//��������
	RS485_DIRECTION_TXD;//���ڷ���
	modbusSerialSendBuffer(sendBuf, sendCount);
	RS485_DIRECTION_RXD;//�������485���ڽ���״̬
    receCount = 0;   //����յ�ַƫ�ƼĴ���
}
static void readCoils(void)
{//fuction:01 ������������Ȧ״̬
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
	bitCount = (receBuf[4]<<8) + receBuf[5]; //��ȡ��λ����
	byteCount = bitCount / 8;    //�ֽڸ���
	if(bitCount%8 != 0)
	{
	  byteCount++;
	}		
	for(k = 0; k < byteCount; k ++)//�ֽ�λ��
	{
		position = k + 3;
		sendBuf[position] = 0;
		for(i = 0; i < 8; i ++)
		{
			getCoilVal(tempAddr, &tempData);
			sendBuf[position] |= tempData << i;
			tempAddr++;
			if(tempAddr >= addr + bitCount)//����
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
{//fuction:02 ��ȡ��Ȧ���루ֻ���Ĵ�����״̬
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
	tempAddr = addr +10000;        //ֻ����Ȧ�Ĵ���ƫ�Ƶ�ַ10000
	bitCount = (receBuf[4]<<8) + receBuf[5]; //��ȡ��λ����
	byteCount = bitCount / 8;    //�ֽڸ���
	if(bitCount%8 != 0)
	{
		byteCount++;
	}		
	for(k=0;k<byteCount;k++)//�ֽ�λ��
	{
		position = k + 3;
		sendBuf[position] = 0;
		for(i=0;i<8;i++)
		{
			getCoilVal(tempAddr,&tempData);
			sendBuf[position] |= tempData << i;
			tempAddr++;
			if(tempAddr >= addr+bitCount)//����
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
{//function code : 03����ȡ������ּĴ���ֵ
	uint16_t addr;
	uint16_t tempAddr;
	uint16_t crcData;
	uint16_t readCount;
	uint16_t byteCount;
	uint16_t i;
	uint16_t tempData = 0; 
	addr = (receBuf[2]<<8) + receBuf[3]; 
	tempAddr = addr+40000;      //+40000,���ּĴ���ƫ�Ƶ�ַ
	readCount = (receBuf[4]<<8) + receBuf[5]; //Ҫ���ĸ��� ,����
	byteCount = readCount * 2;                  //ÿ���Ĵ�������ռ�ߣ��������ֽ�
	for(i=0;i<byteCount;i+=2,tempAddr++)
	{
		getRegisterVal(tempAddr,&tempData);    
		sendBuf[i+3] = tempData >> 8;        
		sendBuf[i+4] = tempData & 0xff;  
	}
	sendBuf[0] = localAddr;
	sendBuf[1] = 3;  //function code : 03
	sendBuf[2] = byteCount;
	byteCount += 3;             //����ǰ��ĵ�ַ�������룬��ַ ��3+byteCount���ֽ�
	crcData = crc16(sendBuf,byteCount);
	sendBuf[byteCount] = crcData & 0xff;   // CRC�����λ��ǰ
	byteCount++;
	sendBuf[byteCount] = crcData >> 8 ;	   //��λ�ں�
	sendCount = byteCount + 1;			//����byteCount=49����sendBuf[]��ʵ������49+1��Ԫ�ش���
	beginSend();
}
static void readInPutRegisters(void)
{//fuction 04:��ȡ����Ĵ���
	uint16_t addr;
	uint16_t tempAddr;
	uint16_t crcData;
	uint16_t readCount;
	uint16_t byteCount;
	uint16_t i;
	uint16_t tempData = 0; 
	addr = (receBuf[2]<<8) + receBuf[3]; 
	tempAddr = addr+30000;  //+����Ĵ���ƫ�Ƶ�ַ��30000
	readCount = (receBuf[4]<<8) + receBuf[5]; //Ҫ���ĸ��� ,����
	byteCount = readCount * 2;                  //ÿ���Ĵ�������ռ�ߣ��������ֽ�
	for(i=0;i<byteCount;i+=2,tempAddr++)
	{
		getRegisterVal(tempAddr,&tempData);    
		sendBuf[i+3] = tempData >> 8;        
		sendBuf[i+4] = tempData & 0xff;  
	}
	sendBuf[0] = localAddr;
	sendBuf[1] = 4;  //function code : 04
	sendBuf[2] = byteCount;
	byteCount += 3;             //����ǰ��ĵ�ַ�������룬��ַ ��3+byteCount���ֽ�
	crcData = crc16(sendBuf,byteCount);
	sendBuf[byteCount] = crcData & 0xff;   // CRC�����λ��ǰ
	byteCount++;
	sendBuf[byteCount] = crcData >> 8 ;	   //��λ�ں�
	sendCount = byteCount + 1;			//����byteCount=49����sendBuf[]��ʵ������49+1��Ԫ�ش���
	beginSend();
}
static void forceSingleCoil(void)
{//fuction:05 ,ǿ�Ƶ�����Ȧ
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
		tempData = 1;//��ΪON
	} 
	else if(onOff == 0x0000)//��ΪOFF
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
{//fuction:06���õ����Ĵ���
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
	sendBuf[2] = addr >> 8;  //�Ĵ�����ַ��λ
	sendBuf[3] = addr & 0xff;//�Ĵ�����ַ��λ
	sendBuf[4] =receBuf[4];
	sendBuf[5] =receBuf[5];
	crcData = crc16(sendBuf,6);//����CRCУ����
	sendBuf[6] = crcData & 0xff;  //CRC�����λ��ǰ
	sendBuf[7] = crcData >> 8;	  //��λ�ں�
	sendCount = 8;
	beginSend(); 
}

static void forceMultipleCoils(void)
{//function code : 15��ǿ�ö���Ȧֵ
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
	byteCount = bitCount / 8;    //�ֽڸ���
	if(bitCount%8 != 0)
	{
		byteCount++;
	}		
	for(k = 0;k < byteCount;k ++)//�ֽ�λ��
	{
		for(i = 0;i < 8;i ++)
		{
			tempData = (receBuf[k + 7] >> i) & 0x01;//��Ӧλ λ��  
			setCoilVal(tempAddr, tempData); 
			tempAddr++;
			if(tempAddr >= addr + bitCount)//����
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
	sendBuf[2] = addr >> 8;  //�Ĵ�����ַ��λ
	sendBuf[3] = addr & 0xff;//�Ĵ�����ַ��λ
	sendBuf[4] = bitCount >> 8;//�����üĴ���������λ
	sendBuf[5] = bitCount & 0xff;//�����üĴ���������λ
	crcData = crc16(sendBuf, 6);//����CRCУ����
	sendBuf[6] = crcData & 0xff;  //CRC�����λ��ǰ
	sendBuf[7] = crcData >> 8;	  //��λ�ں�
	sendCount = 8;
	beginSend(); 
}

static void presetMultipleRegisters(void)
{//function code : 16�����ö���Ĵ���ֵ
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
		tempData = (receBuf[i*2+7]<<8) + receBuf[i*2+8];//�����üĴ���ֵ
		setRegisterVal(tempAddr,tempData);  
	}
	sendBuf[0] = localAddr;
	sendBuf[1] = 16;    //function code : 16
	sendBuf[2] = addr >> 8;  //�Ĵ�����ַ��λ
	sendBuf[3] = addr & 0xff;//�Ĵ�����ַ��λ
	sendBuf[4] = setCount >> 8;//�����üĴ���������λ
	sendBuf[5] = setCount & 0xff;//�����üĴ���������λ
	crcData = crc16(sendBuf,6);//����CRCУ����
	sendBuf[6] = crcData & 0xff;  //CRC�����λ��ǰ
	sendBuf[7] = crcData >> 8;	  //��λ�ں�
	sendCount = 8;
	beginSend(); 
}
/*************************��ѯuart���յ����ݰ����ݺ��� **************************/
////�������ܣ��Ի����ݴ��ڽ��յ������ݰ�receBuf[1]��������ݣ���function codeִ����Ӧ������
/********************************************************************************/
static void checkComm0Modbus(void)		   //10ms�ڱ�����Ӧ��������
{
	uint16_t crcData;
	uint16_t tempData;
	uint16_t temp;
	if(receCount > 4)		 
	{//������յ�����	 
		switch(receBuf[1])
		{
			case 1:								
			{//��ȡ�Ĵ���(һ������)	 
				
				if(receCount >= 8)  //��ѯ�����ݰ���ʽ��֪��receCountӦ�õ���8	���������һ������Ӧ�ùرս����ж�
				{	   	 
					if(receBuf[0] == localAddr)//�˶Ե�ַ
					{	 
						crcData = crc16(receBuf, 6);//�˶�У����
						temp=receBuf[7];
						temp=(temp<<8)+receBuf[6];
						if(crcData == temp)
						{
							readCoils();//��ȡ��Ȧ���״̬(һ������) 
						}
						receCount = 0; 									  
					}					
				}      
				break;
			}
			case 2:								
			{//��ȡ�Ĵ���(һ������)	 
				if(receCount >= 8)  
				{//��ѯ�����ݰ���ʽ��֪��receCountӦ�õ���8	���������һ������Ӧ�ùرս����ж�   	 
					if(receBuf[0] == localAddr)  
					{//�˶Ե�ַ	 
						crcData = crc16(receBuf,6);                     //�˶�У����
						temp=receBuf[7];
						temp=(temp<<8)+receBuf[6];
						if(crcData == temp)
						{
							readInPutCoils();			//��ȡ��Ȧ����״̬(һ������) 
						}
						receCount = 0; 									  
					}				
				}      
				break;
			}
			
			case 3:
			{//��ȡ�Ĵ���(һ������)	 
				if(receCount >= 8)  
				{//��ѯ�����ݰ���ʽ��֪��receCountӦ�õ���8 �������һ������Ӧ�ùرս����ж�
					if(receBuf[0]==localAddr)   
					{//�˶Ե�ַ	 
						crcData = crc16(receBuf,6);                     //�˶�У����
						temp=receBuf[7];
						temp=(temp<<8)+receBuf[6];
						if(crcData == temp)
						{
							readRegisters();//��ȡ���ּĴ���(һ������) 						  
						}	
						receCount = 0; 				
					}
				}					
				break;
			}
			case 4:								
			{//��ȡ�Ĵ���(һ������)	 
				if(receCount >= 8)  
				{//��ѯ�����ݰ���ʽ��֪��receCountӦ�õ���8 �������һ������Ӧ�ùرս����ж�   					
					if(receBuf[0]==localAddr)   //�˶Ե�ַ
					{	 
						crcData = crc16(receBuf,6);                     //�˶�У����
						temp=receBuf[7];
						temp=(temp<<8)+receBuf[6];
						if(crcData == temp)
						{ 
							readInPutRegisters();//��ȡ����Ĵ���(һ������) 
						}
						receCount = 0; 									  
					}	
				}      
				break;
			}
			case 5:								
			{//��ȡ�Ĵ���(һ������)	 
				if(receCount >= 8)  
				{//��ѯ�����ݰ���ʽ��֪ receCountӦ�õ���8 �������һ������Ӧ�ùرս����ж�   		
					if(receBuf[0] == localAddr)   
					{//�˶Ե�ַ	 
						crcData = crc16(receBuf, 6);//�˶�У����
						temp = receBuf[7];
						temp = (temp<<8) + receBuf[6];
						if(crcData == temp)
						{ 
							forceSingleCoil();//ǿ�õ�����Ȧ ״̬
						}
						receCount = 0; 									  
					}
				}      
				break;
			}
			case 6: 
			{//д�������ּĴ���	
				if(receCount >= 8)
				{//Ԥ�赥�����ּĴ���    
					if(receBuf[0]==localAddr)
					{
						crcData = crc16(receBuf, 6);
						temp = receBuf[7];
						temp = (temp<<8) + receBuf[6];
						if(crcData == temp)
						{ 
							presetSingleRegister();      //Ԥ�õ������ּĴ���
							//��ѡ�����������ݵ�EPROM  
						} 
					receCount = 0;                                                                                                                                         
					}
				}
				break;
			}
			case 15:
			{//���ö����Ȧ
				tempData = receBuf[6]; 
				tempData += 9; //���ݸ���
				if(receCount >= tempData)
				{
					if(receBuf[0] == localAddr )
					{
						crcData = crc16(receBuf, tempData - 2);
						if(crcData == (receBuf[tempData-1] << 8)+ receBuf[tempData - 2])//�����ˣ���
						{
							forceMultipleCoils();  
							//��ѡ�����������ݵ�EPROM  
						}
					} 
					receCount = 0;
				}
				break;
			}				
			case 16:
			{//���ö���Ĵ���
				tempData = (receBuf[4]<<8) + receBuf[5];//���üĴ�������
				tempData = tempData * 2;//���ݸ���=	�Ĵ���*2
				tempData += 9;       //��ѯ�����ݰ���ʽ��֪��receCountӦ�õ���9+byteCount
				if(receCount >= tempData)
				{  	
					if(receBuf[0]==localAddr )	//�˶Ե�ַ
					{	 
						crcData = crc16(receBuf, tempData - 2);
						temp = receBuf[tempData - 1];
						temp=(temp << 8) + receBuf[tempData - 2]; 
						if(crcData == temp)
						{  
							presetMultipleRegisters();  
							//��ѡ�����������ݵ�EPROM  
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