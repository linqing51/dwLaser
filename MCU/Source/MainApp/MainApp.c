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
bit  COOL_OUT;
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

#define INPUT_FOOTSWITCH_NC				0
#define INPUT_FOOTSWITCH_NO				1
#define INPUT_INTERLOCK					2
#define INPUT_OPENCASE					3
#define INPUT_FIBERDETECT0				4
#define INPUT_FIBERDETECT1				5




/*****************************************************************************/
void main(void)
{
	int8_t temp;
	int16_t tecOnTime, tecOffTime;//���俪��ʱ��
	pidFuzzy_t pidFuzzy;
	Init_Device();//��ʼ��MCU
	//hwI2cInit();//��ʼ��Ӳ��I2C
	sTimerInit();//��ʼ�����߼�
	//SMB_Init();
	pidFuzzyInit(&pidFuzzy, 2, 0.5, 0.1);
	setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//���ôӻ���ַ
	InitModbusHardware(CONFIG_UART0_BAUDRATE);//��ʼ��MODBUS�ӻ�����
	/**********************************************************************/
	EA = 1;
	
	while(1)
	{//��ʼѭ��ɨ������
		//ÿ10mSɨ������IO
		if(sTimer[(CONFIG_STIMER_1MS_NUM - 1)].status)
		{
			if(((( P6 >> INPUT_FOOTSWITCH_NC) & 0x01) == 1) &&
			  ((( P6 >> INPUT_FOOTSWITCH_NO) & 0x01) == 0))
				laser.footSwitch = 1;
			else
				laser.footSwitch = 0;
			laser.safeInterlock = (P6 >> INPUT_INTERLOCK) & 0x01;
			laser.safeFiberDetect0 = (P6 >> INPUT_FIBERDETECT0) & 0x01;
			laser.safeFiberDetect1 = (P6 >> INPUT_FIBERDETECT1) & 0x01;
			sTimerCtrl(STIMER_OFF, (CONFIG_STIMER_1MS_NUM - 1), CONFIG_INPUT_FILTER_TIME);//T0 STOP
		}
		else
			sTimerCtrl(STIMER_ON, (CONFIG_STIMER_1MS_NUM - 1), CONFIG_INPUT_FILTER_TIME);//T0 STOP
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
		
		//Debug LED��˸
		if(LED_MCU)
		{
			if(sTimer[(CONFIG_STIMER_1000MS_NUM - 1)].status)//�ȴ�ʱ��A
			{
				LED_MCU = 0;
				sTimerCtrl(STIMER_OFF, (CONFIG_STIMER_1000MS_NUM - 1), 1);//T0 STOP
			}
			else
				sTimerCtrl(STIMER_ON, (CONFIG_STIMER_1000MS_NUM - 1), 1);//T0 STOP
		}
		if(!LED_MCU)
		{
			if(sTimer[(CONFIG_STIMER_1000MS_NUM - 2)].status)//�ȴ�ʱ��B
			{
				LED_MCU = 1;
				sTimerCtrl(STIMER_OFF, (CONFIG_STIMER_1000MS_NUM - 2), 1);//T0 STOP
			}
			else
				sTimerCtrl(STIMER_ON, (CONFIG_STIMER_1000MS_NUM - 2), 1);//T0 STOP
		}
		//PID �¿�ָ��
		if(sTimer[(CONFIG_STIMER_100MS_NUM - 3)].status)//�ȴ�Aʱ��
		{
			laser.pidOut += pidFuzzyRealize(&pidFuzzy, 25.0, 26.0);
			if(laser.pidOut > 1)
				laser.pidOut = 1;
			if(laser.pidOut < 0)
				laser.pidOut = 0;
			//laser.onTimerPid = (int16_t)(laser.pidOut * CONFIG_PIDOUT_PWM);
			//laser.offTimerPid = CONFIG_TECOUT_MAX_CYCLE - laser.onTimerPid; 
			sTimerCtrl(STIMER_OFF, (CONFIG_STIMER_100MS_NUM - 3), 10);
		}
		else
			sTimerCtrl(STIMER_ON, (CONFIG_STIMER_100MS_NUM - 3), 10);
		//PID������

		if(sTimer[1].value >= CONFIG_TECOUT_CYCLE || sTimer[1].enable == 0)
		{
			COOL_OUT = 1;
			//tecOnTime = (int16_t)(laser.pidOut * CONFIG_TECOUT_CYCLE);
			tecOnTime = (int16_t)(0.25 * CONFIG_TECOUT_CYCLE);
			sTimerCtrl(STIMER_OFF, 1, tecOnTime);
			sTimerCtrl(STIMER_ON, 1, tecOnTime);
		}
		if(sTimer[1].value >= tecOnTime)
		{
			COOL_OUT = 0;
		}
		modbusPoll();//ִ��MODBUS POLL
		
		//setOutput();//�������IO
		
		//���Ź�ι��
		
	}		
}



