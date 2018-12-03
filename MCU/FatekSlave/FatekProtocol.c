/*****************************************************************************************************/
//Fatek PLC ͨ��Э�� MASTER
//2010-11-28		VER 0.1
/******************************************************************************************************/
#include  "FatekProtocol.H"
/*****************************************************************************/
static uint32_t EspRcvTime;//
//��վ��
static int8_t SlaveAddrH;
static int8_t SlaveAddrL;	
//�����
static int8_t CommandH;
static int8_t CommandL;
//У����
static int8_t ChecksumH;
static int8_t ChecksumL;
//Fatek Protocol ��ʼ�ַ�
const int8_t FATEK_STX = 0x02;
//Fatek Protocol �����ַ�
const int8_t FATEK_EXT = 0x03;	
static uint8_t LRC( uint8_t *buf, long len );
static  void hex2char(uint8_t num,int8_t *pcharH,int8_t *pcharL);
static uint8_t char2hex(int8_t *pcharH,int8_t *pcharL);
static void chrcpy(int8_t *src,int8_t *dis,uint8_t len);
/***************************************************************************/
static int8_t FatekRcvBuf[FATEK_RCVSIZE];	//Э����ջ�����
static int8_t FatekSendBuf[FATEK_SENDSIZE];//Э�鷢�ͻ�����
static int8_t *pRcv;//���ջ�����ָ��
static int8_t FlagRcving;//���ձ�־
static int8_t FlagRcvOK;//�������
/**************************************************************************/
static uint8_t getrcv(void){//��ȡPLC����   ���ؽ��յ����ַ�����
	int8_t rcvtemp,rcvnum;
	memset(FatekRcvBuf, 0x00, FATEK_RCVSIZE);
	while(1){
		rcvtemp = revchar();//�����ַ�
		if(FlagRcving && rcvtemp != FATEK_STX && rcvtemp != FATEK_EXT){
			*pRcv = rcvtemp;
			if(pRcv ==(FatekRcvBuf + FATEK_RCVSIZE -1))
			{
				pRcv = FatekRcvBuf;
			}
			else {
				pRcv++;
				rcvnum ++ ;
			}
		}
		if(rcvtemp == FATEK_STX){
			memset(FatekRcvBuf,0x00,FATEK_RCVSIZE);
			pRcv = FatekRcvBuf;
			FlagRcving = 1;
			FlagRcvOK = 0;
			rcvnum = 1;
			*pRcv = rcvtemp;
			pRcv++;
		}
		if(rcvtemp == 0){
			return 0;		
		}
		if(rcvtemp == FATEK_EXT){
			*pRcv = rcvtemp;
			FlagRcvOK = 1;
			FlagRcving = 0;
			return (rcvnum); 
		}
	}
}
void Fatek_ReadStatusPLC(Fatek_ReadStatusPLC_Reply *reply){//PLC����ϵͳ״̬��ȡ
	uint8_t checksum,temp,rcvnum;
	memset(FatekSendBuf,0x00,FATEK_SENDSIZE);//��շ��ͻ���
	hex2char(ReadStatusPLC,&CommandH,&CommandL);	
	sprintf(FatekSendBuf,"%c%c%c%c%c",FATEK_STX,SlaveAddrH,SlaveAddrL,CommandH,CommandL);
	checksum = LRC(FatekSendBuf,5);
	hex2char(checksum,&ChecksumH,&ChecksumL);
	RS485_DIRECTION_TXD;
    delayUs(RS485_TX_DELAY);
    sendchar(FATEK_STX);
	sendchar(SlaveAddrH);
	sendchar(SlaveAddrL);
	sendchar(CommandH);
	sendchar(CommandL);
	sendchar(ChecksumH);
	sendchar(ChecksumL);
	sendchar(FATEK_EXT);
    RS485_DIRECTION_RXD;
	rcvnum = getrcv();
	if(rcvnum > 0){
		checksum = LRC(FatekRcvBuf,12);
		temp = char2hex(&FatekRcvBuf[(rcvnum-2)],&FatekRcvBuf[(rcvnum-1)]);//
		if(checksum == temp){
			reply->status[0] = (char2hex(&FatekRcvBuf[6],&FatekRcvBuf[7]));
			reply->status[1] = (char2hex(&FatekRcvBuf[8],&FatekRcvBuf[9]));
			reply->status[2] = (char2hex(&FatekRcvBuf[10],&FatekRcvBuf[11]));
			reply->errorcode = No_Error;
		}
		else{
				reply->errorcode = Checksum_Error; 
		}
	}
	else{
			reply->errorcode = NOPLCCONT;
	}
}
void Fatek_ControlRUNSTOP(uint8_t plcon,Fatek_ControlRUNSTOP_Reply *reply){
	uint8_t checksum,temp,rcvnum;							    
	memset(FatekSendBuf,0x00,FATEK_SENDSIZE);//��շ��ͻ���
	hex2char(ControlRUNSTOP,&CommandH,&CommandL);
	if(plcon == 0 ) {temp = 0x30;}
	else {temp = 0x31;}	
	sprintf(FatekSendBuf,"%c%c%c%c%c%c",FATEK_STX,SlaveAddrH,SlaveAddrL,CommandH,CommandL,temp);
	checksum = LRC(FatekSendBuf,6);
	hex2char(checksum,&ChecksumH,&ChecksumL);	
	RS485_DIRECTION_TXD;
    delayUs(RS485_TX_DELAY);
    sendchar(FATEK_STX);
	sendchar(SlaveAddrH);
	sendchar(SlaveAddrL);
	sendchar(CommandH);
	sendchar(CommandL);
	sendchar(temp);
	sendchar(ChecksumH);
	sendchar(ChecksumL);
	sendchar(FATEK_EXT);
    RS485_DIRECTION_RXD;
	rcvnum = getrcv();
	if(rcvnum > 0){
		checksum = LRC(FatekRcvBuf,6);
		temp = char2hex(&FatekRcvBuf[(rcvnum-2)],&FatekRcvBuf[(rcvnum-1)]);//
		if(checksum == temp){
			reply->errorcode =  No_Error;
		}
		else{
			reply->errorcode = Checksum_Error;
		}
	}
	else{
		reply->errorcode = NOPLCCONT; 
	}	
}

void Fatek_OperationPoint(int8_t opera/*������*/,int8_t *ppoint/*�������*/,Fatek_OperationPoint_Reply *reply){
	//��һ�����㶯������
	uint8_t checksum,temp,rcvnum;
	memset(FatekSendBuf,0x00,FATEK_SENDSIZE);//��շ��ͻ���
	hex2char(OperationPoint,&CommandH,&CommandL);	
	sprintf(FatekSendBuf,"%c%c%c%c%c%c%c%c%c%c%c",
	FATEK_STX,SlaveAddrH,SlaveAddrL,CommandH,CommandL,opera,*ppoint,*(ppoint+1),*(ppoint+2),*(ppoint+3),*(ppoint+4));
	checksum = LRC(FatekSendBuf,11);
	hex2char(checksum,&ChecksumH,&ChecksumL);
	RS485_DIRECTION_TXD;
    delayUs(RS485_TX_DELAY);
    sendstring(FatekSendBuf,11);
	sendchar(ChecksumH);
	sendchar(ChecksumL);
	sendchar(FATEK_EXT);
	RS485_DIRECTION_RXD;
    rcvnum = getrcv();
	if(rcvnum > 0){
		checksum = LRC(FatekRcvBuf,6);
		temp = char2hex(&FatekRcvBuf[(rcvnum-2)],&FatekRcvBuf[(rcvnum-1)]);//
		if(checksum == temp){
			reply->errorcode = No_Error;
		}
		else{
			reply->errorcode = Checksum_Error;
		}
	}
	else{
		reply->errorcode =  NOPLCCONT;
	}
}
void Fatek_ReadMultiple(uint8_t num/*�������*/,int8_t *pstart/*��ʼ�������*/,Fatek_ReadMultiple_Reply *reply){
	uint8_t checksum,temp,rcvnum;
	int8_t pstl,psth;
	if(num > MAXOPERNUM) num = MAXOPERNUM;
	memset(FatekSendBuf,0x00,FATEK_SENDSIZE);//��շ��ͻ���
	hex2char(ReadMultipleENABLE,&CommandH,&CommandL);
	hex2char(num,&psth,&pstl);
	sprintf(FatekSendBuf,"%c%c%c%c%c%c%c%c%c%c%c%c",
	FATEK_STX,SlaveAddrH,SlaveAddrL,CommandH,CommandL,psth,pstl,*pstart,*(pstart+1),*(pstart+2),*(pstart+3),*(pstart+4));
	checksum = LRC(FatekSendBuf,12);
	hex2char(checksum,&ChecksumH,&ChecksumL);
	RS485_DIRECTION_TXD;
    delayUs(RS485_TX_DELAY);
    sendstring(FatekSendBuf,12);
	sendchar(ChecksumH);
	sendchar(ChecksumL);
	sendchar(FATEK_EXT);
    RS485_DIRECTION_RXD;
	rcvnum = getrcv();
	if(rcvnum > 0){
		checksum = LRC(FatekRcvBuf,(6+num));
		temp = char2hex(&FatekRcvBuf[(rcvnum-2)],&FatekRcvBuf[(rcvnum-1)]);//
		if(checksum == temp){
			chrcpy((FatekRcvBuf+6),reply->pstatus,num);
			reply->errorcode = No_Error;
			reply->num = num;
		}
		else{
			reply->errorcode =  Checksum_Error;
		}
	}
	else{
		reply->errorcode = NOPLCCONT;
	}
}
void Fatek_ReadMultipleConsecutive(uint8_t num/*����*/,int8_t *pstart/*��ʼ�������*/,Fatek_ReadMultipleConsecutive_Reply *reply){
 	uint8_t checksum,temp,rcvnum;
	int8_t pstl,psth;
	memset(FatekSendBuf,0x00,FATEK_SENDSIZE);//��շ��ͻ���
	hex2char(ReadMultipleConsecutive,&CommandH,&CommandL);
	hex2char(num,&psth,&pstl);
	sprintf(FatekSendBuf,"%c%c%c%c%c%c%c%c%c%c%c%c",
	FATEK_STX,SlaveAddrH,SlaveAddrL,CommandH,CommandL,psth,pstl,*pstart,*(pstart+1),*(pstart+2),*(pstart+3),*(pstart+4));
	checksum = LRC(FatekSendBuf,12);
	hex2char(checksum,&ChecksumH,&ChecksumL);
	RS485_DIRECTION_TXD;
    delayUs(RS485_TX_DELAY);
    sendstring(FatekSendBuf,12);
	sendchar(ChecksumH);
	sendchar(ChecksumL);
	sendchar(FATEK_EXT);
	RS485_DIRECTION_RXD;
    rcvnum = getrcv();
	if(rcvnum > 0){
		checksum = LRC(FatekRcvBuf,(6+num));
		temp = char2hex(&FatekRcvBuf[(rcvnum-2)],&FatekRcvBuf[(rcvnum-1)]);//
		if(checksum == temp){

			chrcpy((FatekRcvBuf+6),reply->status,num);
			reply->num = num;
			reply->errorcode = No_Error;
		}
		else{
			reply->errorcode = Checksum_Error;
		}
	}
	else{
		reply->errorcode = NOPLCCONT;
	}
}
void Fatek_WriteMultipleConsecutive(uint8_t num/*����*/,int8_t *pstart/*��ʼ�������*/,int8_t *pstatus/*״̬*/,Fatek_WriteMultipleConsecutive_Reply *reply){
	uint8_t checksum,temp,rcvnum,i;
	int8_t pstl,psth;
	memset(FatekSendBuf,0x00,FATEK_SENDSIZE);//��շ��ͻ���
	hex2char(WriteMultipleConsecutive,&CommandH,&CommandL);
	hex2char(num,&psth,&pstl);
	sprintf(FatekSendBuf,"%c%c%c%c%c%c%c%c%c%c%c%c",
	FATEK_STX,SlaveAddrH,SlaveAddrL,CommandH,CommandL,psth,pstl,*pstart,*(pstart+1),*(pstart+2),*(pstart+3),*(pstart+4));
	for(i = 0;i < num;i ++){//��״̬���Ƶ����ͻ���
		FatekSendBuf[12+i] = *(pstatus+i);
	}
	checksum = LRC(FatekSendBuf,(12+num));
	hex2char(checksum,&ChecksumH,&ChecksumL);
    RS485_DIRECTION_TXD;
    delayUs(RS485_TX_DELAY);
	sendstring(FatekSendBuf,(12+num));
	sendchar(ChecksumH);
	sendchar(ChecksumL);
	sendchar(FATEK_EXT);
    RS485_DIRECTION_RXD;
	rcvnum = getrcv();
	if(rcvnum > 0){
		checksum = LRC(FatekRcvBuf,(6+num));
		temp = char2hex(&FatekRcvBuf[(rcvnum-2)],&FatekRcvBuf[(rcvnum-1)]);//
		if(checksum == temp){
			reply->errorcode = No_Error;
		}
		else{ 
			reply->errorcode = Checksum_Error;
		}
	}
	else{ 
		reply->errorcode = NOPLCCONT;
	}
}
void Fatek_ReadMultipleRegisters(uint8_t num/*����*/,int8_t *pstart/*��ʼ��������*/,uint8_t isDword/*�Ƿ���˫��*/,Fatek_ReadMultipleRegisters_Reply *reply){
	uint8_t checksum,temp,rcvnum;
	int8_t pstl,psth;
	if(num > MAXOPERNUM ) num = MAXOPERNUM;
	memset(FatekSendBuf,0x00,FATEK_SENDSIZE);//��շ��ͻ���
	hex2char(ReadMultipleRegisters,&CommandH,&CommandL);
	if(isDword == 16){
		if(num > 0x40) num = 0x40;
		hex2char(num,&psth,&pstl);
		sprintf(FatekSendBuf,"%c%c%c%c%c%c%c%c%c%c%c%c%c",
		FATEK_STX,SlaveAddrH,SlaveAddrL,CommandH,CommandL,psth,pstl,*pstart,*(pstart+1),*(pstart+2),*(pstart+3),*(pstart+4),*(pstart+5));
		checksum = LRC(FatekSendBuf,13);
		hex2char(checksum,&ChecksumH,&ChecksumL);
		RS485_DIRECTION_TXD;
        delayUs(RS485_TX_DELAY);
        sendstring(FatekSendBuf,(13));
	}
	if(isDword == 32){
		if(num > 0x20) num = 0x20;
		sprintf(FatekSendBuf,"%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
		FATEK_STX,SlaveAddrH,SlaveAddrL,CommandH,CommandL,psth,pstl,*pstart,*(pstart+1),*(pstart+2),*(pstart+3),*(pstart+4),*(pstart+5),*(pstart+6));
		checksum = LRC(FatekSendBuf,14);
		hex2char(checksum,&ChecksumH,&ChecksumL);
		RS485_DIRECTION_TXD;
        delayUs(RS485_TX_DELAY);
        sendstring(FatekSendBuf,(14));
	}
	sendchar(ChecksumH);
	sendchar(ChecksumL);
	sendchar(FATEK_EXT);
	RS485_DIRECTION_RXD;
    rcvnum = getrcv();
	if(rcvnum > 0){
		if(isDword == 16) checksum = LRC(FatekRcvBuf,(6 + (num * 4)));
		if(isDword == 32) checksum = LRC(FatekRcvBuf,(6 + (num * 8)));
		temp = char2hex(&FatekRcvBuf[(rcvnum-2)],&FatekRcvBuf[(rcvnum-1)]);//
		if(checksum == temp){
			if(isDword == 16){ chrcpy((FatekRcvBuf+6),reply->status,(num*4)); reply->num = (num*4);reply->isdword = 16;}
			if(isDword == 32){ chrcpy((FatekRcvBuf+6),reply->status,(num*8)); reply->num = (num *8);reply->isdword = 32;}
			reply->errorcode = No_Error; 
		}
		else{
			reply->errorcode = Checksum_Error; 
		}
	}
	else{
		reply->errorcode =  NOPLCCONT;
	}	
}
void Fatek_WriteMultipleRegisters(uint8_t num/*����*/,int8_t *pstart/*��ʼ��������*/,int8_t *preg/*д������*/,uint8_t isDword,Fatek_WriteMultipleRegisters_Reply *reply){
	uint8_t checksum,temp,rcvnum,i;
	int8_t pstl,psth;
	memset(FatekSendBuf,0x00,FATEK_SENDSIZE);//��շ��ͻ���
	hex2char(WriteMultipleRegisters,&CommandH,&CommandL);
	if(isDword == 16){
		if(num > 0x40) num = 0x40;
		hex2char(num,&psth,&pstl);
		sprintf(FatekSendBuf,"%c%c%c%c%c%c%c%c%c%c%c%c%c",
		FATEK_STX,SlaveAddrH,SlaveAddrL,CommandH,CommandL,psth,pstl,*pstart,*(pstart+1),*(pstart+2),*(pstart+3),*(pstart+4),*(pstart+5));
        RS485_DIRECTION_TXD;
        delayUs(RS485_TX_DELAY);
        for(i = 0;i < (num * 4);i ++){
			FatekSendBuf[(13 + i)] = *(preg + i);	
		}
		checksum = LRC(FatekSendBuf,(13 + (num*4)));
		hex2char(checksum,&ChecksumH,&ChecksumL);

		sendstring(FatekSendBuf,(13 + (num*4)));
	}
	if(isDword == 32){
		if(num > 0x20) num = 0x20;
		sprintf(FatekSendBuf,"%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
		FATEK_STX,SlaveAddrH,SlaveAddrL,CommandH,CommandL,psth,pstl,*pstart,*(pstart+1),*(pstart+2),*(pstart+3),*(pstart+4),*(pstart+5),*(pstart+6));
		RS485_DIRECTION_TXD;
        delayUs(RS485_TX_DELAY);
        for(i = 0;i < (num*8);i ++){
			FatekSendBuf[(14 + i)] = *(preg +i);
		}
		checksum = LRC(FatekSendBuf,(14 + (num*8)));
		hex2char(checksum,&ChecksumH,&ChecksumL);
		sendstring(FatekSendBuf,(14 + (num*8)));
	}
	sendchar(ChecksumH);
	sendchar(ChecksumL);
	sendchar(FATEK_EXT);
    RS485_DIRECTION_RXD;
	rcvnum = getrcv();
	if(rcvnum > 0){
		checksum = LRC(FatekRcvBuf,6);
		temp = char2hex(&FatekRcvBuf[(rcvnum-2)],&FatekRcvBuf[(rcvnum-1)]);//
		if(checksum == temp){
			reply->errorcode = No_Error;
		}
		else{ 
			reply->errorcode = Checksum_Error;
		}
	}
	else{
		reply->errorcode = NOPLCCONT;
	}	
}
void Fatek_MixedRead(uint8_t num/*����*/,int8_t *pstart/*�������*/,uint16_t len/*д��������ݳ���*/,Fatek_MixedRead_Reply *reply){	
}
void Fatek_MixedWrite(uint8_t num/*����*/,int8_t *preg/*д��������*/,uint16_t len/*д�����ݳ���*/,Fatek_MixedWrite_Reply *reply){//������ⵥ��״̬�򻺴������ݻ��д��
}
void Fatek_LoopBackTest(int8_t *src/*��������*/,uint8_t len/*���ϳ���*/,Fatek_LoopBackTest_Reply *reply){
	uint8_t checksum,temp,rcvnum,i;
	memset(FatekSendBuf,0x00,FATEK_SENDSIZE);//��շ��ͻ���
	hex2char(LoopBackTest,&CommandH,&CommandL);
	sprintf(FatekSendBuf,"%c%c%c%c%c%c%c%c%c%c%c%c",
	FATEK_STX,SlaveAddrH,SlaveAddrL,CommandH,CommandL);
	RS485_DIRECTION_TXD;
    delayUs(RS485_TX_DELAY);
    for(i = 0;i < len;i++){
		FatekSendBuf[(5+i)]	 = *(src + i);
	}
	checksum = LRC(FatekSendBuf,(5 + len));
	hex2char(checksum,&ChecksumH,&ChecksumL);
	sendstring(FatekSendBuf,(5 + len));
	sendchar(ChecksumH);
	sendchar(ChecksumL);
	sendchar(FATEK_EXT);
    RS485_DIRECTION_RXD;
	rcvnum = getrcv();
	if(rcvnum > 0){
		checksum = LRC(FatekRcvBuf,(5+len));
		temp = char2hex(&FatekRcvBuf[(rcvnum-2)],&FatekRcvBuf[(rcvnum-1)]);//
		if(checksum == temp){
			chrcpy(FatekSendBuf+5,reply->status,len);
			reply->num = len;
			reply->errorcode = No_Error;
		}
		else{
			reply->errorcode = Checksum_Error;
		}
	}
	else{
		reply->errorcode = NOPLCCONT;
	}
}
void Fatek_ReadDetailStatus(Fatek_ReadDetailStatus_Reply *reply){//PLC��ϸϵͳ״̬��ȡ

}
void SetPLCID(uint8_t plcid){//����PLC��վ��
	hex2char(plcid,&SlaveAddrH,&SlaveAddrL);	
}


//����LRC LRC�����ǽ���Ϣ�е�8Bit���ֽ������ۼӣ������˽�λ
static uint8_t LRC( uint8_t *buf, int32_t len )
{
        int i;
        uint8_t lrc = 0;        /*lrc�ֽڳ�ʼ��*/

        for( i = 0; i < len; i++ )
        {
                lrc = lrc + buf[i];
        }
        return lrc;
}
static void hex2char(uint8_t num,int8_t *pcharH,int8_t *pcharL){//��16������ת��������ASCII�ַ�
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
static uint8_t char2hex(int8_t *pcharH,int8_t *pcharL){//������int8_t ��ϳ�һ��16������
	uint8_t temph,templ;
	int8_t hex;
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
int16_t Fatek_RegReply2Int(Fatek_ReadMultipleRegisters_Reply rep){//���������ַ�ת��Ϊ�з�������
	uint8_t temp[4],i;
	signed int sum;
	for(i=0;i<=3;i++){
		if( *(rep.status + i) >= '0' && *(rep.status + i) <= '9') temp[i] = *(rep.status + i) - 0x30;
		if( *(rep.status + i) >= 'A' && *(rep.status + i) <= 'F') temp[i] = *(rep.status + i) - 0x37;
	}
	sum = ((temp[0] << 12) + (temp[1] << 8) + (temp[2] << 4) +temp[3]);
	return sum;
}
int32_t Fatek_Char2long(int8_t *preg){//���������ַ�ת��Ϊ�з��ų�����
	uint8_t temp[8],i;
	int32_t sum;
	for(i=0;i<=8;i++){
		if( *(preg + i) >= '0' && *(preg + i) <= '9') temp[i] = *(preg+i) - 0x30;
		if( *(preg + i) >= 'A' && *(preg + i) <= 'F') temp[i] = *(preg+i) - 0x37;
	}
	sum = ((temp[0] << 28) + (temp[1] << 24) + (temp[2] << 20) +(temp[3] << 16) +
	(temp[4] << 12) + (temp[5] << 8) + (temp[6] << 4) + temp[7]);
	return sum;	
}
static void chrcpy(int8_t *src,int8_t * dis,uint8_t len){//�������ݵ�ָ���Ļ�����
	uint8_t i,temp;
	for(i = 0;i < len;i ++){
		temp = *(src+i);
		*(dis+i) = temp;
	}	
}