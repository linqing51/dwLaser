#include "boxCmd.h"
/*****************************************************************************/
static void boxSerialSendbyte(uint8_t *dt){//���ڷ���һ���ֽ�
	SCON1 &= ~(uint8_t)(1 << 1);//TI1 = 0
	SBUF1 = *dt;
	while(!((SCON1 >> 1) & 0x01));
	SCON1 &= ~(uint8_t)(1 << 1);//TI1 = 0
}
static void boxSerialSendString(uint8_t *s, uint16_t  Length){// This is used for send string, better to use DMA for it ;)
    uint16_t DummyCounter;
    for(DummyCounter=0; DummyCounter < Length; DummyCounter ++){
        boxSerialSendbyte(&s[DummyCounter]);
    }
}
void boxGreenLedRefresh(void){//ˢ���̵�״̬
//0x81,00,01,......,84///������ɫ�Ƶ�����.AAΪ����55Ϊ��
//0x81,00,02,......,84///���ƺ�ɫ�Ƶ�����.AAΪ����55Ϊ��
//0x81,00,06,84//��ȫ��
//0x81,00,09,xx,yy,zz,84//���Ƶ�ͨ��xx�ĵƵ�����zz=0ʱ���̵ƶ���zz=01,yy=00ʱ��������zz=01,yy=01ʱ��������
	xdata uint8_t sBuf[32], i;
	sBuf[0] = BOX_CMD_STX;
	sBuf[1] = 0x00;
	sBuf[2] = 0x01;
	for(i = 3;i < 28;i ++){
		if(LD(R_START * 16 + i)){
			sBuf[i] = 0xAA;
		}
		else{
			sBuf[i] = 0x55;
		}			
	}
	sBuf[28] = 0x84;
	boxSerialSendString(sBuf, 29);
}
void boxRedLedRefresh(void){//ˢ�º��״̬
//0x81,00,01,......,84///������ɫ�Ƶ�����.AAΪ����55Ϊ��
//0x81,00,02,......,84///���ƺ�ɫ�Ƶ�����.AAΪ����55Ϊ��
//0x81,00,06,84//��ȫ��
//0x81,00,09,xx,yy,zz,84//���Ƶ�ͨ��xx�ĵƵ�����zz=0ʱ���̵ƶ���zz=01,yy=00ʱ��������zz=01,yy=01ʱ��������
	xdata uint8_t sBuf[32], i;
	sBuf[0] = BOX_CMD_STX;
	sBuf[1] = 0x00;
	sBuf[2] = 0x02;
	for(i = 3;i < 28;i ++){
		if(LD(R_START * 16 + 32 + i)){
			sBuf[i] = 0xAA;
		}
		else{
			sBuf[i] = 0x55;
		}			
	}
	sBuf[28] = 0x84;
	boxSerialSendString(sBuf, 29);
}
void initboxSerial(uint32_t baudrate){//ָʾ�д��ڳ�ʼ��
	CKCON &= (1 << 6);//Timer 4 uses the system clock
	T4CON = 0;
	T4CON |= 1 << 4;//Timer 4 overflows used for transmit clock.
	T4CON |= 1 << 5;//Timer 4 overflows used for receive clock.
	T4CON &= ~(1 << 0);//����ʱ��4 �����T2EX �Ϸ���������ʱ���Զ���װ�أ�EXEN2=1��
	T4CON &= ~(1 << 1);//��ʱ�����ܣ���ʱ��4 ��T2M��CKCON.5�������ʱ�Ӽ�1
	RCAP4  = - ((long) ((uint32_t)CONFIG_SYSCLK / baudrate) / 32L);
	TMR4 = RCAP4;
	T4CON |= 1 << 2;//Timer 4 enabled
	SCON1 = 0x0;
	SCON1 |= (0x01 << 6);//Mode 1: 8-Bit UART, Variable Baud Rate
	SCON1 &= ~(uint8_t)(1 << 0);//RI1: Receive Interrupt Flag.
	SCON1 &= ~(uint8_t)(1 << 1);//TI1: Transmit Interrupt Flag.	
}