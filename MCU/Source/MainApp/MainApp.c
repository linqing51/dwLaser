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
#define ENUM_CHANNEL1					4321
#define ENUM_CHANNEL2					8765
#define ENUM_CHANNEL_BOTH				9431
#define ENUM_MODE_CW					7631//����ģʽ
#define ENUM_MODE_SP					8934//������ģʽ
#define ENUM_MODE_MP						2453//������ģʽ
#define ENUM_MODE_GP						3876//Ⱥ����ģʽ
#define ENUM_MODE_CC						14563//У��ģʽ
/*****************************************************************************/
laser_t laser;

/*****************************************************************************/
void main(void)
{
	int8_t temp;
	pidFuzzy_t pidFuzzy;
	Init_Device();//��ʼ��MCU
	//hwI2cInit();//��ʼ��Ӳ��I2C
	sTimerInit();//��ʼ�����߼�
	//SMB_Init();
	//pidFuzzyInit(&pidFuzzy);//��ʼ��ģ��PID
	setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//���ôӻ���ַ
	InitModbusHardware(CONFIG_UART0_BAUDRATE);//��ʼ��MODBUS�ӻ�����
	/**********************************************************************/
	EA = 1;
	
	while(1)
	{//��ʼѭ��ɨ������
		//ÿ10mSɨ������IO
		if(sTimer[0].status)
		{
		
		}
		//��ȡ����״̬
		laser.overTempFault = (laser.overTempDiode && !laser.overTempDiodeIgnore) ||
							  (laser.overTempAmplifier && !laser.overTempAmplifierIgnore) ||
	                          (laser.overTempEnvironment && !laser.overTempEnvironmentIgnore) ||
							  (laser.overTempMcu && !laser.overTempMcuIgnore);
	    laser.overTempFault = laser.overTempFault && !laser.overTempIgnore;
		//��ȡ��ȫ״̬
		laser.safeFault = (laser.safeInterlock && !laser.safeInterlockIgnore) ||
					(laser.safeFiberDetect0 && laser.safeFiberDetect0Ignore) ||
					(laser.safeFiberDetect1 && laser.safeFiberDetect1Ignore) ||
					(laser.safeOpenCase && laser.safeOpenCaseIgnore);
		laser.safeFault = laser.safeFault && !laser.safeFaultIgnore;
		//ģ������ɨ��
		//������

//		//ȷ������ģʽ
//		if(!softPlc.M[MADR_OVERTMP] &&//����޹���
//		   !softPlc.M[MADR_SAFTFAULT] &&//�ް�ȫ���� 
//		    softPlc.M[R_MADR_FOOTSWITCH] &&//��̤����
//		    softPlc.M[MADR_READY])//׼��״̬
//		{
//			switch(softPlc.R[RADR_LASER_MODE])
//			{
//				case ENUM_MODE_CW:
//				{//��ʼ����ģʽ
//					
//					break;
//				}
//				case ENUM_MODE_SP:
//				{//��ʼ������ģʽ
//					break;
//				}
//				case ENUM_MODE_MP:
//				{//��ʼ������ģʽ
//					break;
//				}
//				case ENUM_MODE_GP:
//				{//��ʼ�ɱ��ģʽ
//					break;
//				}
//				case ENUM_MODE_CC:
//				{//��ʼУ��ģʽ
//					break;
//				}
//				default:break;
//			}
//			
//		}
		
		
		if(LED_MCU)
		{
			if(sTimer[0].status)//�ȴ�ʱ��A
			{
				LED_MCU = 0;
				sTimerCtrl(0, 0, 10);//T0 STOP
			}
			else
				sTimerCtrl(1, 0, 10);//T0 STOP
		}
		if(!LED_MCU)
		{
			if(sTimer[0].status)//�ȴ�ʱ��B
			{
				LED_MCU = 1;
				sTimerCtrl(0, 1, 20);//T0 STOP
			}
			else
				sTimerCtrl(1, 1, 20);//T0 STOP
		}
		//PIDָ��
		//if(getCoil(&softPlc.M, 100))
		//{//ִ��PID �¿�ָ��
			//ִ��PID
//		if(softPlc.T_10ms[2].output)//�ȴ�Aʱ��
//		{
//			//pidFuzzyRealize(&pidFuzzy, 25.0, 30.0);
//			stopTimer(&softPlc.T_10ms[2]);//ֹͣ��ʱ��
//		}
//		else
//		{
//			startTimer(&softPlc.T_10ms[2], 100);//��ʼ������	
//		}
//		
//		if(softPlc.T_100ms[4].output)
//		{
//			stopTimer(&softPlc.T_100ms[4]);
//		}
//		else
//		{
//			startTimer(&softPlc.T_100ms[4],1);
//		}
//		
//		if(softPlc.T_1000ms[4].output)
//		{
//			stopTimer(&softPlc.T_1000ms[4]);
//		}
//		else
//		{
//			startTimer(&softPlc.T_1000ms[4],1);
//		}
		modbusPoll();//ִ��MODBUS POLL
		
		//setOutput();//�������IO
		
		//���Ź�ι��
		
	}		
}



