#include "MainApp.h"
/*****************************************************************************/
//TIMER0 ->Laser Pulse
//TIMER1 ->UART0/1 Buadrate
//TIMER2 ->Modbus Slave TIMER
//TIMER3 ->HW I2C
//TIMER4 ->SoftPLC HWTIMER
/*****************************************************************************/
sbit LED3 = P1^7;
sbit LED4 = P1^6;
/*****************************************************************************/
void main(void)
{
	uint8_t st;
	pidFuzzy_t pidFuzzy;
	Init_Device();//��ʼ��MCU
	
	SoftPlc_Init(&softPlc);
	pidFuzzyInit(&pidFuzzy);
	setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//���ôӻ���ַ
	InitModbusHardware(CONFIG_UART0_BAUDRATE);//��ʼ��MODBUS�ӻ�����
	/**********************************************************************/
	EA = 1;
	LED3 = 0;
	LED3 = 1;
	LED4 = 0;
	LED4 = 1;
	//setCoil(&softPlc.M, 1000);//M1000
	while(1)
	{//��ʼѭ��ɨ������
		if(LED3)
		{
			if(softPlc.T_10ms[0].output)//�ȴ�ʱ��A
			{
				LED3 = 0;
				stopTimer(&softPlc.T_10ms[0]);
			}
			else
				startTimer(&softPlc.T_10ms[0], 50);
		}
		if(!LED3)
		{
			if(softPlc.T_10ms[1].output)//�ȴ�ʱ��B
			{
				LED3 = 1;
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
			pidFuzzyRealize(&pidFuzzy, 25.0, 30.0);
			stopTimer(&softPlc.T_10ms[2]);//ֹͣ��ʱ��
		}
		else
		{
			startTimer(&softPlc.T_10ms[2], 100);//��ʼ������	
		}
		//}
		modbusPoll();//ִ��MODBUS POLL
		
		setOutput(&softPlc);//�������IO
		
		//���Ź�ι��
		
	}		
}



