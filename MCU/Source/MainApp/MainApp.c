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
//�Ǳ���λ����
#define MADR_START_CW							10//����CW
#define MADR_START_SP							11//����SP
#define MADR_START_MP							12//����MP
#define MADR_START_GP							13//����GP �ɱ������
#define MADR_START_CC							14//����CC У��ģʽ


#define MADR_LASER_OVERTEMP					1//����������
#define MADR_LASER_OVERTEMP_IGNORE			2//���������Ⱥ���
#define MADR_ENVI_OVERTEMP					3//��������
#define MADR_ENVI_OVERTEMP_IGNORE				4//�������Ⱥ���
#define MADR_DRIVE_OVERTEMP					5//����������
#define MADR_DRIVE_OVERTEMP_IGNORE			6//���������Ⱥ���
#define MADR_MCU_OVERTEMP						7//��Ƭ������
#define MADR_MCU_OVERTEMP_IGNORE				8//��Ƭ�����Ⱥ���

#define MADR_INTERLOCK						9//��ȫ����
#define MADR_INTERLOCK_IGNORE					10//��ȫ��������
#define MADR_FIBER_DETECT0					11//����̽��1
#define MADR_FIBER_DETECT0_IGNORE				12//����̽��1����
#define MADR_FIBER_DETECT1					13//����̽��2
#define MADR_FIBER_DETECT1_IGNORE				14//����̽��2����
#define MADR_OPEN_CASE						15//�������
#define MADR_OPEN_CASE_IGNORE					16//����������
#define MADR_OVERTEMP							17//�¶ȹ��ȹ���
#define MADR_OVERTEMP_IGNORE					18//�¶ȹ��ȹ��Ϻ���
#define MADR_SAFTFAULT						19//��ȫ���ʧ��
#define MADR_SAFTFAULT_IGNORE					20//��ȫ���ʧ�ܺ���

#define MADR_READY							21//����׼��״̬

#define MADR_FOOTSWITCH						22//��̤
//�Ǳ���16λ����
#define DADR_LASER_CURRENT0					1//ͨ��0�������ֵ mA
#define DADR_LASER_CURRENT1					2//ͨ��1�������ֵ mA
#define DADR_LASER_MODE						3//���ⷢ��ģʽ
#define DADR_LASER_POSWIDTH					4//���ⷢ�������� mS
#define DADR_LASER_NEGWIDTH					5//���ⷢ�为���� mS
#define DADR_LASER_GROUPNUM					6//���ⷢ��������
#define DADR_LASER_GROUPSPACE					7//���ⷢ��������ʱ�� mS
#define DADR_LASER_CHANNEL					8//����ͨ��ѡ��
#define DADR_PWNOUT0							9//PWMģ�����0
#define DADR_PWMOUT1							10//PWMģ�����1
#define DADR_PWMOUT2						11//PWMģ�����2
#define DADR_PWMOUT3						12//PWMģ�����3
#define DADR_NTCTEMP0						13//NTC�¶ȶ�ֵ0
#define DADR_NTCTEMP1						14//NTC�¶ȶ�ֵ1
#define DADR_NTCTEMP2						15//NTC�¶ȶ�ֵ2
#define DADR_NTCTEMP3						16//NTC�¶ȶ�ֵ3
#define DADR_MCUTEMP						17//��Ƭ���¶ȶ�ֵ

#define SP_TADR_INPUTFILTER					0//�����˲���ʱ��
/*****************************************************************************/
void main(void)
{
	int8_t temp;
	pidFuzzy_t pidFuzzy;
	Init_Device();//��ʼ��MCU
	//hwI2cInit();//��ʼ��Ӳ��I2C
	SoftPlc_Init(&softPlc);//��ʼ�����߼�
	//SMB_Init();
	//pidFuzzyInit(&pidFuzzy);//��ʼ��ģ��PID
	setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//���ôӻ���ַ
	InitModbusHardware(CONFIG_UART0_BAUDRATE);//��ʼ��MODBUS�ӻ�����
	/**********************************************************************/
	EA = 1;
	while(1)
	{//��ʼѭ��ɨ������
		if(LD(SOFTPLC_T, SP_TADR_INPUTFILTER))
		{
			getInput(&softPlc);//����IOɨ��
		}
		temp = (LD(SOFTPLC_M, MADR_LASER_OVERTEMP) && LD(SOFTPLC_M, MADR_LASER_OVERTEMP_IGNORE)) ||
		       (LD(SOFTPLC_M, MADR_ENVI_OVERTEMP) && LD(SOFTPLC_M, MADR_ENVI_OVERTEMP_IGNORE)) ||
			   (LD(SOFTPLC_M, MADR_DRIVE_OVERTEMP) && LD(SOFTPLC_M, MADR_ENVI_OVERTEMP_IGNORE)) ||
		       (LD(SOFTPLC_M, MADR_MCU_OVERTEMP) && LD(SOFTPLC_M, MADR_MCU_OVERTEMP_IGNORE));
		OUT(SOFTPLC_M, MADR_OVERTEMP, temp);
		//ģ������ɨ��
		//������
//		softPlc.M[MADR_OVERTEMP] = 
//								
//								
//								(softPlc.M[MADR_MCU_OVERTEMP] && softPlc.M[MADR_MCU_OVERTEMP_IGNORE]);
//		softPlc.M[MADR_OVERTEMP] &= !softPlc.M[MADR_OVERTEMP_IGNORE]; 
//		//��ȫ���
//		softPlc.M[MADR_SAFTFAULT] = (softPlc.M[MADR_INTERLOCK] && softPlc.M[MADR_INTERLOCK_IGNORE]) ||
//									(softPlc.M[MADR_FIBER_DETECT1] && softPlc.M[MADR_FIBER_DETECT1_IGNORE]) ||
//									(softPlc.M[MADR_FIBER_DETECT2] && softPlc.M[MADR_FIBER_DETECT2_IGNORE]) ||
//									(softPlc.M[MADR_OPEN_CASE] && softPlc.M[MADR_OPEN_CASE_IGNORE]);
//		softPlc.M[MADR_SAFTFAULT] &= !softPlc.M[MADR_SAFTFAULT_IGNORE];
//		
//		if(softPlc.M[MADR_OVERTEMP] || softPlc.M[MADR_SAFTFAULT])
//		{//��⵽���Ȼ�ȫ���Ͻ������״̬
//			softPlc.M[MADR_READY] = false;//�������״̬
//			//�رռ���
//		}
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
			if(LD(SOFTPLC_T, 0))//�ȴ�ʱ��A
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
		
		setOutput();//�������IO
		
		//���Ź�ι��
		
	}		
}



