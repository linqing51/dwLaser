#include "MainApp.h"
/*****************************************************************************/
//C8051F020 ��ʱ�����ܶ���
//TIMER0 ->SPLC
//TIMER1 ->Modbus RTU
//TIMER2 ->UART0 Buadrate
//TIMER3 ->
//TIMER4 ->UART1 Buadrate
/*****************************************************************************/
//sbit LED_MCU = P2^3;//������ָʾLED
//sbit LED_LASER0 = P1^7;//���ⷢ��ָʾLED0 980nM
//sbit LED_LASER1 = P1^6;//���ⷢ��ָʾLED1 1470nM
//bit  TP0, TP1, TP2, TP3;
/*****************************************************************************/
#define ENUM_CHANNEL1					4321
#define ENUM_CHANNEL2					8765
#define ENUM_CHANNEL_BOTH				9431
#define ENUM_MODE_CW					0//����ģʽ
#define ENUM_MODE_SP					1//������ģʽ
#define ENUM_MODE_MP					2//������ģʽ
#define ENUM_MODE_GP					3//Ⱥ����ģʽ
#define ENUM_MODE_CC					4//У��ģʽ
/*****************************************************************************/
#define INPUT_FOOTSWITCH_NC				0
#define INPUT_FOOTSWITCH_NO				1
#define INPUT_INTERLOCK					2
#define INPUT_OPENCASE					3
#define INPUT_FIBERDETECT0				4
#define INPUT_FIBERDETECT1				5

#define STIMER_1MS_INPUT_FILTER			0//�����˲���ʱ��			
#define STIMER_1MS_SP_LASER_ON			1//������ON��ʱ��
#define STIMER_1MS_MP_LASER_ON			2//������ON��ʱ��
#define STIMER_1MS_MP_LASER_OFF			3//������OFF��ʱ��
#define STIMER_1MS_GP_LASER_ON			4//�ɱ�����ON��ʱ��
#define STIMER_IMS_GP_LASER_OFF			5//�ɱ�����OFF��ʱ��
#define STIMER_1MS_GP_SPACE				6//�ɱ���������ʱ��

#define STIMER_1000MS_PID				61//PID�¶����ڼ�ʱ��
#define STIMER_100MS_OFF_BEEM			44//���伤����ʱ������OFF��ʱ��
#define STIMER_100MS_ON_BEEM			45//���伤����ʱ������ON��ʱ��
#define STIMER_100MS_INTOREADY_BEEM		46//INTO READY���������ʱ��

#define STIMER_1000MS_LED_ON			62//LED��˸ON��ʱ��
#define STIMER_1000MS_LED_OFF			63//LED��˸OFF��ʱ��
/*****************************************************************************/

#define STEPNUM_FAULT					-1//����
#define STEPNUM_INIT					0//��ʼ��
#define STEPNUM_STANDBY					1//����
#define STEPNUM_INTO_READY				2//����׼��
#define STEPNUM_READY					3//׼��
#define STEPNUM_LASERON					4//���⿪ʼ



//#define DM_LASER_CURRENT_0			0//����������0
//#define DM_LASER_CURRENT_1			1//����������1
//#define DM_PHOTODIODE_0				2//����������0
//#define DM_PHOTODIODE_1				3//����������1
//#define DM_LASER_MODE				4//���ⷢ��ģʽ
//#define DM_LASER_POSWIDTH			5//��������������
//#define DM_LASER_NEGWIDTH			6//��������������
//#define DM_LASER_GROUP_NUM			7//����Ⱥ�������
//#define DM_LASER_GROUP_SPACE		8//����Ⱥ������
//#define DM_LASER_SELECT_CHANNEL		9//����ͨ��ѡ��


//#define DM_LASER_HTEMP//���������±���
//#define DM_LASER_LTEMP//���������±���
//#define DM_DRIVER_HTEMP//���������±���
//#define DM_DRIVER_LTEMP//���������±���
//#define DM_CHIP_HTEMP//оƬ���±���
//#define DM_CHIP_LTEMP//оƬ���±���
//#define DM_ENVI_HTEMP//�����¶ȸ��±���
//#define DM_EMVI_LTEMP//�����¶ȵ��±���

//#define EM_FAN_SET_SPEED_0//����0ת������
//#define EM_FAN_SET_SPEED_1//����1ת������
//#define EM_FAN_SET_SPEED_2//����2ת������
//#define EM_FAN_GET_SPEED_0//����0ת�ٶ�ȡ
//#define EM_FAN_GET_SPEED_1//����1ת�ٶ�ȡ
//#define EM_FAN_GET_SPEED_2//����2ת�ٶ�ȡ
//#define EM_EDAC0//��չDAC0���ֵ
//#define EM_EDAC1//��չDAC1���ֵ
//#define EM_EDAC2//��չDAC2���ֵ
//#define EM_EDAC3//��չDAC3���ֵ
//#define EM_CDAC0//����DAC0���ֵ
//#define EM_CDAC1//����DAC1���ֵ
//#define EM_CADC0//����ADC0����ֵ
//#define EM_CADC1//����ADC1����ֵ
//#define EM_CADC2//����ADC2����ֵ
//#define EM_CADC3//����ADC3����ֵ
//#define EM_CTEMP//�����¶�ֵ
//#define XR_0
//#define XR_1
//#define XR_2
//#define XR_3
//#define XR_4
//#define XR_5
//#define XR_6
//#define XR_7
//#define YR_0
//#define YR_1
#define MCP4768_DAC1		1
#define MCP4768_DAC2		2
#define MCP4768_DAC3		3
#define MCP4768_DAC4		4

void upDateDac0(uint16_t dat);
void upDateDac1(uint16_t dat);
/*****************************************************************************/
sbit loopFlag = P0^4;
sbit epromBusyFlag = P0^5;
void main(void){
#ifdef C8051F020
	initDeviceF020();
#endif
	//epromTest();
	sPlcInit();//��ʼ�����߼�
	//inPca9554Init();
	//outPca9554Init();
	//mcp47x6Init();
	initModbus(CONFIG_MODBUS_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
	ES0 = 1;
	ENABLE_INTERRUPT;
	while(1){
		loopFlag = ~loopFlag;
		processModbus();
		
		//refreshInput();//ˢ������IO
////		SET(10);
////		RESET(10);
////		SET(10);
////		RESET(10);
////		SET(10);
////		RESET(10);
////		SET(10);
////		RESET(10);
////		FLIP(10);
////		FLIP(10);
////		FLIP(10);
////		FLIP(10);
////		//��ȡIO
////		//ִ�г���
////		//���IO
////		T100MS(0, 1, 2);
////		if(LD(TD_100MS_START * 16 + 0));
////		{
////			SET(0);	
////		}
		refreshDac();
		nvramUpdata();//����NVRAM
		//refreshOutput();//ˢ�����IO
	}
}
//void main(void)
//{
//	int8_t temp;
//	int16_t tecOnTime, tecOffTime;//���俪��ʱ��
////	my_t *p = my;
////	pidFuzzy_t pidFuzzy;
//	Init_Device();//��ʼ��MCU
//#if CONFIG_USING_WDT == 1
//	if ((RSTSRC & 0x02) == 0x00)
//	{
//		if (RSTSRC == 0x08)
//		{//���WDT���Ź� ���Ź���λ������
//			//����IO ->LOW
//			//�ر�DAC
//			//�ر�
//			LED_MCU = true;
//			LED_LASER0 = false;
//			LED_LASER1 = true;
//			while(1);
//		}
//	}
//#endif

	//pidFuzzyInit(&pidFuzzy, 2, 0.5, 0.1);
//	setModbusSlaveAddr(CONFIG_LOCAL_ADDRESS);//���ôӻ���ַ
//	InitModbusHardware(CONFIG_UART0_BAUDRATE);//��ʼ��MODBUS�ӻ�����
//	/**********************************************************************/
////��ʼ��my�ṹ��
//	//my.stepNum = 0;
//	//my.checkCode = ((CONFIG_CHECK_CODE << 8) & 0xFF00);
//	//my.checkCode |= CONFIG_VERSION;
//	
////ʹ�ܿ��Ź�
//#if CONFIG_USING_WDT == 1
//	Watchdog_Init();
//#endif	
//	EA = 1;
//	
//	while(1)
//	{//��ʼѭ��ɨ������
////���Ź�ι��
//#if CONFIG_USING_WDT == 1
//		 WDTCN = 0xA5;//ι��
//#endif
////��λ��ʹ��MCU��λ
//#if CONFIG_USING_RESET == 1
//		if(my.mcuReset)
//		{
//			RSTSRC |= (1 << 1);//Forces a Power-On Reset. /RST is driven low.
//		}
//#endif
//		//�����˲�ɨ������IO

//		p->flagConnectErr = 0;//ÿ��ɨ������־����
//		//����->PLC
//		if(my.heartFlag)
//		{
//			my.heatFlag = 0;
//		}
//		else
//		{
//			my.heatFlag = 1;
//		}
//		
//		//��ȡ����״̬
//		my.overTempFault = (my.overTempDiode && !my.overTempDiodeIgnore) ||
//							  (my.overTempAmplifier && !my.overTempAmplifierIgnore) ||
//	                          (my.overTempEnvironment && !my.overTempEnvironmentIgnore) ||
//							  (my.overTempMcu && !my.overTempMcuIgnore);
//	    my.overTempFault = my.overTempFault && !my.overTempIgnore;
//		//��ȡ��ȫ״̬
//		my.safeFault = (my.safeInterlock && !my.safeInterlockIgnore) ||
//					(my.safeFiberDetect0 && my.safeFiberDetect0Ignore) ||
//					(my.safeFiberDetect1 && my.safeFiberDetect1Ignore) ||
//					(my.safeOpenCase && my.safeOpenCaseIgnore);
//		my.safeFault = my.safeFault && !my.safeFaultIgnore;
//		//ģ������ɨ��
//		STEP_LOOP_START:
//		if(my.stepNum == STEPNUM_INIT)
//		{//��ʼ��
//			my.stepNum = STEPNUM_STANDBY;//Goto next step
//			goto STEP_LOOP_END;
//		}
//		if(my.stepNum == STEPNUM_STANDBY)
//		{//��һ�� ����״̬->��������ʾ
//			if(my.safeFault ||
//               my.overTempFault)
//			{
//				my.stepNum = STEPNUM_FAULT;
//			}
//			else if(my.readyFlag)
//			{
//				my.beemOn = true;
//				my.stepNum = STEPNUM_INTO_READY;
//			}
//			else
//			{
//				my.stepNum = STEPNUM_STANDBY;
//			}
//			goto STEP_LOOP_END;
//		}
//		if(my.stepNum == STEPNUM_INTO_READY)
//		{//�ڶ��� �ȴ�1������
//			if(my.readyFlag)
//			{
//				my.beemOn = true;
//				sTimerCtrl(STIMER_ON, STIMER_100MS_INTOREADY_BEEM, 10);
//				if(sTimer[STIMER_100MS_INTOREADY_BEEM].status)
//				{//��ʱ�ﵽ����READY����
//					sTimerCtrl(STIMER_OFF, STIMER_100MS_INTOREADY_BEEM, 10);
//					my.beemOn = false;
//					my.stepNum = STEPNUM_READY;
//				}
//			}
//			goto STEP_LOOP_END;
//		}
//		if(my.stepNum == STEPNUM_READY)
//		{//������ ׼��״̬ �ȴ���̤�źŷ��伤��
//			if(my.safeFault ||
//               my.overTempFault)
//			{
//				my.stepNum = STEPNUM_FAULT;
//			}
//			else if((my.footSwitch && 0x01) &&
//				    !(my.footSwitch && 0x02))//���footSwitch������
//			{//���伤�ⲽ��
//				//�򿪼���
//				my.stepNum = STEPNUM_LASERON;
//				my.laserEmitOver = 0x0;//������ɱ�־����
//				switch(my.laserMode)
//				{
//					case ENUM_MODE_CW:
//					{
//						my.laserEmiting |=  1 << ENUM_MODE_CW;
//						break;
//					}
//					case ENUM_MODE_SP:
//					{
//						my.laserEmiting |=  1 << ENUM_MODE_SP;
//						break;
//					}
//					case ENUM_MODE_MP:
//					{
//						my.laserEmiting |=  1 << ENUM_MODE_MP;
//						break;
//					}
//					case ENUM_MODE_GP:
//					{
//						my.laserEmiting |=  1 << ENUM_MODE_GP;
//						break;
//					}
//					case ENUM_MODE_CC:
//					{
//						my.laserEmiting |=  1 << ENUM_MODE_CC;
//						break;
//					}
//					default:break;
//				}
//			}
//			goto STEP_LOOP_END;
//		}
//		if(my.stepNum == STEPNUM_LASERON)
//		{
//			if(my.safeFault || my.overTempFault)
//			{//����:
//				my.stepNum = STEPNUM_FAULT;
//			}
//			else if(!(my.footSwitch & 0x01))//��̤��λ
//			{
//				//�رռ���
//				my.stepNum = STEPNUM_READY;//����READY����
//			}
//			else
//			{
//				if( my.laserEmiting == ENUM_MODE_CW)
//				{//����ģʽ
//					switch(my.selectChannel)
//					{
//						case ENUM_CHANNEL_BOTH:
//						{
//							upDateDac0(laserCurrent[0]);
//							upDateDac1(laserCurrent[1]);
//							break;
//						}
//						case ENUM_CHANNEL1:
//						{
//							upDateDac0(laserCurrent[0]);
//							break;
//						}
//						case ENUM_CHANNEL2:
//						{
//							upDateDac1(laserCurrent[1]);
//							break;
//						}
//						default:break;
//					}
//				}
//				if( my.laserEmiting == ENUM_MODE_SP )
//				{//������ģʽ
//					if(selectChannel == ENUM_CHANNEL_BOTH)
//					{
//						upDateDac0(laserCurrent[0]);
//						upDateDac1(laserCurrent[1]);
//					}
//					if(selectChannel == ENUM_CHANNEL1)
//					{
//						upDateDac0(laserCurrent[0]);
//					}
//					if(selectChannel = ENUM_CHANNEL2)
//					{
//						upDateDac1(laserCurrent[1]);
//					}
//					sTimerCtrl(STIMER_ON, STIMER_1MS_SP_LASER_ON, my.posWidth);
//					if(sTimer[STIMER_1MS_LASER_ON].status)
//					{
//						upDateDac0(0x0);
//						upDateDac1(0x0);
//						my.laserEmiting &=  ~(1<< ENUM_MODE_CW);//�������������ڷ����־λ
//						my.laserEmitOver |= 1 << ENUM_MODE_CW;//������ɱ�־λ��λ
//						sTimerCtrl(STIMER_OFF, STIMER_1MS_SP_LASER_ON, my.posWidth);
//					}
//				}	
//				if( my.laserEmiting == ENUM_MODE_MP )
//				{//������ģʽ
//					if(!sTimer[STIMER_1MS_LASER_ON].enable)
//					{//�������ʱ
//					if(selectChannel == ENUM_CHANNEL_BOTH)
//				{
//					DAC0 = laserCurrent[0];
//					DAC1 = laserCurrent[1];
//				}
//				if(selectChannel == ENUM_CHANNEL1)
//				{
//					
//				}
//				if(selectChannel = ENUM_CHANNEL2)
//				{
//				}
//				sTimerCtrl(STIMER_ON, STIMER_1MS_LASER_ON, my.posWidth);
//				if(sTimer[STIMER_1MS_LASER_ON].status)
//				{
//					//�رռ���
//					//�رռ�ʱ��
//					my.laserOnFlag = 0;
//					sTimerCtrl(STIMER_OFF, STIMER_1MS_LASER_ON, my.posWidth);
//				}	
//			}
//			else if(!my.laserOnFlag)
//			{//�������ʱ
//				sTimerCtrl(STIMER_ON, STIMER_1MS_LASER_OFF, my.negWidth);
//				if(sTimer[STIMER_1MS_LASER_OFF].status)
//				{
//					my.laserOnFlag = 1;
//					sTimerCtrl(STIMER_OFF, STIMER_1MS_LASER_ON, my.posWidth);
//				}
//			}
//		}
//		if( !my.triggerCW || !my.triggerSP || !my.triggerMP || !my.triggerGP || my.triggerCC)
//		{//У��ģʽ
//			
//		}
//			}
//			goto STEP_LOOP_END;
//		}
//		if(my.stepNum == STEPNUM_FAULT)
//		{//����״̬
//			//�رռ���
//			if(!my.safeFault &&
//               !my.overTempFault)
//			{//��������
//				if(my.clearError)
//				{//�����������ش���״̬
//					my.clearError = 0;
//					my.stepNum = STEPNUM_STANDBY;
//				}
//			}
//			else
//			{
//				my.stepNum = STEPNUM_FAULT;
//			}
//			goto STEP_LOOP_END;
//		}
//		STEP_LOOP_END:
//		if( my.triggerCW || !my.triggerSP || !my.triggerMP || !my.triggerGP || !my.triggerCC)
//		{//����ģʽ
//			if(!my.laserOnFlag)
//			{	
//				switch(my.selectChannel)
//				{
//					case ENUM_CHANNEL_BOTH:
//					{
//						DAC0 = laserCurrent[0];
//						DAC1 = laserCurrent[1];
//						break;
//					}
//					case ENUM_CHANNEL1:
//					{
//						DAC0 = laserCurrent[0];	
//						break;
//					}
//					case ENUM_CHANNEL2:
//					{
//						DAC1 = laserCurrent[1];
//						break;
//					}
//					default:break;
//				}
//				my.laserOnFlag = 1;
//			}
//			
//		}
//		if( my.triggerCW || !my.triggerSP || !my.triggerMP || !my.triggerGP || !my.triggerCC)
//		{//������ģʽ
//			if(!my.laserOnFlag)
//			{
//				if(selectChannel == ENUM_CHANNEL_BOTH)
//				{
//					DAC0 = laserCurrent[0];
//					DAC1 = laserCurrent[1];
//				}
//				if(selectChannel == ENUM_CHANNEL1)
//				{
//					DAC0 = laserCurrent[0];
//				}
//				if(selectChannel = ENUM_CHANNEL2)
//				{
//					DAC1 = laserCurrent[1];
//				}
//				sTimerCtrl(STIMER_ON, STIMER_1MS_SP_LASER_ON, my.posWidth);
//				if(sTimer[STIMER_1MS_LASER_ON].status)
//				{
//					DAC0 = 0x0;
//					DAC1 = 0x0;
//					my.laserOnFlag = 0;
//					my.triggerSP = 0;
//					sTimerCtrl(STIMER_OFF, STIMER_1MS_SP_LASER_ON, my.posWidth);
//				}
//			}
//			
//		}
//		if( !my.triggerCW || !my.triggerSP || my.triggerMP || !my.triggerGP || !my.triggerCC)
//		{//������ģʽ
//			if(my.laserOnFlag)
//			{//�������ʱ
//				if(selectChannel == ENUM_CHANNEL_BOTH)
//				{
//					DAC0 = laserCurrent[0];
//					DAC1 = laserCurrent[1];
//				}
//				if(selectChannel == ENUM_CHANNEL1)
//				{
//					
//				}
//				if(selectChannel = ENUM_CHANNEL2)
//				{
//				}
//				sTimerCtrl(STIMER_ON, STIMER_1MS_LASER_ON, my.posWidth);
//				if(sTimer[STIMER_1MS_LASER_ON].status)
//				{
//					//�رռ���
//					//�رռ�ʱ��
//					my.laserOnFlag = 0;
//					sTimerCtrl(STIMER_OFF, STIMER_1MS_LASER_ON, my.posWidth);
//				}	
//			}
//			else if(!my.laserOnFlag)
//			{//�������ʱ
//				sTimerCtrl(STIMER_ON, STIMER_1MS_LASER_OFF, my.negWidth);
//				if(sTimer[STIMER_1MS_LASER_OFF].status)
//				{
//					my.laserOnFlag = 1;
//					sTimerCtrl(STIMER_OFF, STIMER_1MS_LASER_ON, my.posWidth);
//				}
//			}
//		}
//		if( !my.triggerCW || !my.triggerSP || !my.triggerMP || !my.triggerGP || my.triggerCC)
//		{//У��ģʽ
//			
//		}
//		
//		//Debug LED��˸
//		if(LED_MCU)
//		{
//			if(sTimer[STIMER_1000MS_LED_ON].status)//�ȴ�ʱ��A
//			{
//				LED_MCU = 0;
//				sTimerCtrl(STIMER_OFF, STIMER_1000MS_LED_ON, 1);
//			}
//			else
//				sTimerCtrl(STIMER_ON, STIMER_1000MS_LED_ON, 1);
//		}
//		if(!LED_MCU)
//		{
//			if(sTimer[STIMER_1000MS_LED_OFF].status)//�ȴ�ʱ��B
//			{
//				LED_MCU = 1;
//				sTimerCtrl(STIMER_OFF, STIMER_1000MS_LED_OFF, 1);
//			}
//			else
//				sTimerCtrl(STIMER_ON, STIMER_1000MS_LED_OFF, 1);
//		}
//		//PID �¿�ָ��
//		if(sTimer[(CONFIG_STIMER_100MS_END - 3)].status)//�ȴ�Aʱ��
//		{
//			my.pidOut += pidFuzzyRealize(&pidFuzzy, 25.0, 26.0);
//			if(my.pidOut > 1)
//				my.pidOut = 1;
//			if(my.pidOut < 0)
//				my.pidOut = 0;
//			//my.onTimerPid = (int16_t)(my.pidOut * CONFIG_PIDOUT_PWM);
//			//my.offTimerPid = CONFIG_TECOUT_MAX_CYCLE - my.onTimerPid; 
//			sTimerCtrl(STIMER_OFF, (CONFIG_STIMER_100MS_END - 3), 10);
//		}
//		else
//			sTimerCtrl(STIMER_ON, (CONFIG_STIMER_100MS_END - 3), 10);
//		//PID������

//		if(sTimer[1].value >= CONFIG_TECOUT_CYCLE || sTimer[1].enable == 0)
//		{
//			COOL_OUT = 1;
//			//tecOnTime = (int16_t)(my.pidOut * CONFIG_TECOUT_CYCLE);
//			tecOnTime = (int16_t)(0.25 * CONFIG_TECOUT_CYCLE);
//			sTimerCtrl(STIMER_OFF, 1, tecOnTime);
//			sTimerCtrl(STIMER_ON, 1, tecOnTime);
//		}
//		if(sTimer[1].value >= tecOnTime)
//		{
//			COOL_OUT = 0;
//		}
//		modbusPoll();//ִ��MODBUS POLL
//		
//		//setOutput();//�������IO
//	
//	}		
//}

//void startLaser(void)
//{//��ʼ��������	
//	if(my.laserMode == ENUM_MODE_CW )
//	{
//		DAC0 = my.laserCurrent[0];
//		DAC1 = my.laserCurrent[1];
//	}
//	else if((my.LaserMode == ENUM_MODE_SP) | 
//			(my.LaserMode == ENUM_MODE_MP) |
//			(my.LaserMode == ENUM_MODE_GP))
//	{
//		my.laserTimer.tMate = my.PosWidth;//����ƥ��ֵ
//		my.laserTimer.tOverflow = my.NegWidth + my.PosWidth;//�������ֵ
//		my.laserTimer.tCounter = 0x0;	
//		my.laserTimer.pMate = 0x0;//�������ƥ��ֵ
//		my.laserTimer.sMate = 0x0;//���������ֵ
//		my.laserTimer.pCounter = 0x0;
//		my.laserTimer.sCounter = 0x0;	
//		TF2H = 0;//Timer 2 High Byte Overflow Flag.
//		ET2 = 1;
//		TMR2L = 0xFF;
//		TMR2H = 0xFF;
//		TR2 = 1;//ʹ��TIMER2��ʱ��
//	}
//	else if(my.LaserMode == ENUM_MODE_CC)
//	{//У��ģʽ
//		my.laserTimer.tMate = my.PosWidth;//����ƥ��ֵ
//		my.laserTimer.tOverflow = my.NegWidth + my.PosWidth;//�������ֵ
//		my.laserTimer.tCounter = 0x0;	
//		my.laserTimer.pMate = my.GroupNum;//�������ƥ��ֵ
//		my.laserTimer.sMate = my.GroupSpace;//���������ֵ
//		my.laserTimer.pCounter = 0x0;
//		my.laserTimer.sCounter = 0x0;	
//		TF2H = 0;//Timer 2 High Byte Overflow Flag.
//		ET2 = 1;
//		TMR2L = 0xFF;
//		TMR2H = 0xFF;
//		TR2 = 1;//ʹ��TIMER2��ʱ��
//	}
//	my.FlagIndicate = 1;
//}
//void stopLaser(myDevice_t *p)
//{//ֹͣ��������
//	TR2 = 0;
//	ET2 = 0;
//	TF2H = 0;
//	DAC0 = 0;
//	DAC1 = 0;
//	my.FlagIndicate = 0;	
//}

//void Timer0_ISR(void) interrupt INTERRUPT_TIMER0
//{//TIMER2 �ж� ���ⷢ��
//	
//	TF2H = 0;
//	switch(my.LaserMode)
//	{
//		case ENUM_MODE_CC:
//		{//CCģʽ
//			SetLaserCurrent(p);
//			break;
//		}
//		case ENUM_MODE_SP:
//		{//SPģʽ
//			break;
//		}
//		case ENUM_MODE_MP:
//		{//MPģʽ	
//			if(p->softTimer.tCounter == p->softTimer.tMate)
//			{//��ʱ��ƥ��
//				LaserMod_PIN = LASER_OFF;//��ת���
//			}
//			if(p->softTimer.tCounter == p->softTimer.tOverflow)
//			{//��ʱ�����
//				p->softTimer.tCounter = 0;//����
//			}
//			if(p->softTimer.tCounter == 0)
//			{//��ת
//				LaserMod_PIN = LASER_ON;//��ת���
//			}
//			p->softTimer.tCounter ++;
//			break;
//		}
//		case ENUM_MODE_GP:
//		{//GPģʽ
//			if(p->softTimer.pCounter < p->softTimer.pMate)
//			{
//				if(p->softTimer.tCounter == 0)
//				{
//					if(p->softTimer.pCounter < p->softTimer.pMate)
//					{
//						LaserMod_PIN = LASER_ON;//��ת���						
//					}
//				}
//				if(p->softTimer.tCounter == p->softTimer.tMate)
//				{//��ʱ��ƥ��
//					LaserMod_PIN = LASER_OFF;//��ת���
//				}
//				if(p->softTimer.tCounter == (p->softTimer.tOverflow - 1))
//				{//��ʱ�����
//					p->softTimer.tCounter = 0xFFFF;//����
//					p->softTimer.pCounter ++;//����	
//				}
//				p->softTimer.tCounter ++;
//			}
//			if(p->softTimer.pCounter == p->softTimer.pMate && p->softTimer.tCounter == 0)
//			{//�����������ƥ��
//				LaserMod_PIN = LASER_OFF;
//				p->softTimer.pCounter = 0xFFFF;
//				p->softTimer.sCounter = 0x0;
//			}
//			if(p->softTimer.pCounter == 0xFFFF)
//			{		
//				if(p->softTimer.sCounter == p->softTimer.sMate)
//				{
//					p->softTimer.pCounter = 0;	
//				}
//				p->softTimer.sCounter ++;
//			}
//			break;
//		}
//		default:break;
//	}
//}
