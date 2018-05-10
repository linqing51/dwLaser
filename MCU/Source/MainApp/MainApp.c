#include "MainApp.h"
/*****************************************************************************/
//TIMER0 ->Laser Pulse
//TIMER1 ->UART0/1 Buadrate
//TIMER2 ->Modbus Slave TIMER
//TIMER3 ->HW I2C
//TIMER4 ->SoftPLC HWTIMER
/*****************************************************************************/
sbit LED_MCU = P2^3;//������ָʾLED
sbit LED_LASER0 = P1^7;//���ⷢ��ָʾLED0 980nM
sbit LED_LASER1 = P1^6;//���ⷢ��ָʾLED1 1470nM
/*****************************************************************************/
void main(void)
{
	pidFuzzy_t pidFuzzy;
	Init_Device();//��ʼ��MCU
	//hwI2cInit();//��ʼ��Ӳ��I2C
	SoftPlc_Init(&softPlc);//��ʼ�����߼�
	SMB_Init();
	//pidFuzzyInit(&pidFuzzy);//��ʼ��ģ��PID
	setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//���ôӻ���ַ
	InitModbusHardware(CONFIG_UART0_BAUDRATE);//��ʼ��MODBUS�ӻ�����
	/**********************************************************************/
	EA = 1;
	while(1)
	{//��ʼѭ��ɨ������
		getInput();
		if(LED_MCU)
		{
			if(softPlc.T_10ms[0].output)//�ȴ�ʱ��A
			{
				LED_MCU = 0;
				stopTimer(&softPlc.T_10ms[0]);
			}
			else
				startTimer(&softPlc.T_10ms[0], 50);
		}
		if(!LED_MCU)
		{
			if(softPlc.T_10ms[1].output)//�ȴ�ʱ��B
			{
				LED_MCU = 1;
				stopTimer(&softPlc.T_10ms[1]);
			}
			else
				startTimer(&softPlc.T_10ms[1], 20);
				
		}
		//PIDָ��
		//if(getCoil(&softPlc.M, 100))
		//{//ִ��PID �¿�ָ��
			//ִ��PID
		if(softPlc.T_10ms[2].output)//�ȴ�Aʱ��
		{
			//pidFuzzyRealize(&pidFuzzy, 25.0, 30.0);
			stopTimer(&softPlc.T_10ms[2]);//ֹͣ��ʱ��
		}
		else
		{
			startTimer(&softPlc.T_10ms[2], 100);//��ʼ������	
		}
		
		if(softPlc.T_100ms[4].output)
		{
			stopTimer(&softPlc.T_100ms[4]);
		}
		else
		{
			startTimer(&softPlc.T_100ms[4],1);
		}
		
		if(softPlc.T_1000ms[4].output)
		{
			stopTimer(&softPlc.T_1000ms[4]);
		}
		else
		{
			startTimer(&softPlc.T_1000ms[4],1);
		}
		modbusPoll();//ִ��MODBUS POLL
		
		setOutput();//�������IO
		
		//���Ź�ι��
		
	}		
}



