#include "hal_si2c.h"
/*****************************************************************************/

static void delayUs(uint16_t us) /*��ʱ����*/
{
	while(t!=0)
		t--;
}

static void start(Bus_Iic_T *i2c)
{//����I2C���ߵĺ�������SCLΪ�ߵ�ƽʱʹSDA����һ��������
	i2c->setSDA(1);
	i2c->setSCL(1);
	delayUs(i2c->busDelay);
	i2c->setSDA(0);
	delayUs(i2c->busDelay);
	i2c->setSCL(0);
	delayUs(i2c->busDelay);
}

static void stop(Bus_Iic_T *i2c)
{//��ֹI2C���ߣ���SCLΪ�ߵ�ƽʱʹSDA����һ��������
    i2c->setSDA(0);
    i2c->setSCL(1);
	delayUs(i2c->busDelay);
    i2c->setSDA(1);
    delayUs(i2c->busDelay);
    i2c->setSCL(0);
    delayUs(i2c->busDelay);
}

void send_Ack(void)
{//����0����SCLΪ�ߵ�ƽʱʹSDA�ź�Ϊ��
	SDA=0;
	SCL=1;
	DELAY(DELAY_TIME);
	SCL=0;
	DELAY(DELAY_TIME);
}

void send_Nack(void)
{//����1����SCLΪ�ߵ�ƽʱʹSDA�ź�Ϊ��
	SDA=1;
	SCL=1;
	DELAY(DELAY_TIME);
	SCL=0;
	DELAY(DELAY_TIME);
}

bit Check_Acknowledge(void)
{
	/*������һ���ֽں�����豸��Ӧ���ź�*/
	SDA=1;
	SCL=1;
	DELAY(DELAY_TIME/2);
	F0=SDA;
	DELAY(DELAY_TIME/2);
	SCL=0;
	DELAY(DELAY_TIME);
	if(F0==1)
		return FALSE;
	return TRUE;
}

void WriteI2CByte(char b)reentrant
{
	/*��I2C����дһ���ֽ�*/
	char i;
	for(i=0;i<8;i++)
		if((b<<i)&0x80)
			SEND_1();
		else
			SEND_0();
}



char ReadI2CByte(void)reentrant
{
	/*��I2C���߶�һ���ֽ�*/
	char b=0,i;
	for(i=0;i<8;i++)
	{
		SDA=1;    /*�ͷ�����*/
		SCL=1;    /*��������*/
		DELAY(10);
		F0=SDA;
		DELAY(10);
		SCL=0;
		if(F0==1)
			{
				b=b<<1;
				b=b|0x01;
			}
		else
			b=b<<1;
	}
	return b;
}


/**********����Ϊ��д24c02�ĺ���**********/
void Write_One_Byte(char addr,char thedata)
{
          bit acktemp=1;
          /*write a byte to mem*/
          I2C_Start();
          WriteI2CByte(0xa0);
          acktemp=Check_Acknowledge();
          WriteI2CByte(addr);/*address*/
          acktemp=Check_Acknowledge();
          WriteI2CByte(thedata);/*thedata*/
          acktemp=Check_Acknowledge();
          I2C_Stop();

}

void Write_A_Page(char *buffer,char addr)
{
          bit acktemp=1;
          bit wrtmp;
          int i;
          /*write a page to at24c02*/
          I2C_Start();
          WriteI2CByte(0xa0);
          acktemp=Check_Acknowledge();
          WriteI2CByte(addr);/*address*/
          acktemp=Check_Acknowledge();
          for(i=0;i<7;i++)
          {
            WriteI2CByte(buffer[i]);
            if(!Check_Acknowledge())
                {
                    I2C_Stop();

                }
           }


          I2C_Stop();

 


}

char Read_One_Byte(char addr)
{         bit acktemp=1;
          char mydata;
           /*read a byte from mem*/
          I2C_Start();
          WriteI2CByte(0xa0);
          acktemp=Check_Acknowledge();
          WriteI2CByte(addr);/*address*/
          acktemp=Check_Acknowledge();
          I2C_Start();
          WriteI2CByte(0xa1);
          acktemp=Check_Acknowledge();


          mydata=ReadI2CByte();
          acktemp=Check_Acknowledge();

          return mydata;
          I2C_Stop();
}

void Read_N_Bytes(char *buffer,char n,char addr)
{
          bit acktemp=1;

          int i=0;
           /*read 8 bytes from mem*/
          I2C_Start();
          WriteI2CByte(0xa0);
          acktemp=Check_Acknowledge();
          WriteI2CByte(addr);/*address*/
          acktemp=Check_Acknowledge();
          I2C_Start();
          WriteI2CByte(0xa1);

          acktemp=Check_Acknowledge();

 


          for(i=0;i<n;i++)
          {
                buffer[i]=ReadI2CByte();
                if(i!=n-1)
                    SEND_0();    /*����Ӧ��*/
                else
                    SEND_1();    /*���ͷ�Ӧ��*/
          }

   I2C_Stop();

}


void main()
{
          int i;
          char mybyte;
          char myarray[8];
          char myarray2[8];
          char rdarray[16];
         
          for(i=0;i<8;i++)
          {
                myarray[i]=i;
                myarray2[i]=i+0x08;    

          }

          Write_One_Byte(0x20,0x28);

          Write_A_Page(myarray,0x10);
          Write_A_Page(myarray2,0x18);

          mybyte=Read_One_Byte(0x20);
          Read_N_Bytes(rdarray,16,0x10);

}
