#include "sPlcLaser.h"
/*****************************************************************************/
#define MCP47X6_LASER_CHANNEL_CH1				0
#define MCP47X6_LASER_CHANNEL_CH2				1
#define LASER_CHANNEL_BOTH				9431
#define LASER_MODE_CW					0//����ģʽ
#define LASER_MODE_SP					1//������ģʽ
#define LASER_MODE_MP					2//������ģʽ
#define LASER_MODE_GP					3//Ⱥ����ģʽ
#define LASER_MODE_CC					4//У��ģʽ




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




void startLaser(void){//��ʼ��������
#ifdef C8051F580	
	uint8_t SFRPAGE_save;
#endif
	if(NVRAM0[EM_START + EM_LASER_MODE] == LASER_MODE_CW ){
		NVRAM0[SPREG_START + SPREG_DAC_0] = NVRAM0[EM_START + EM_LASER_CURRENT_CH1];
		NVRAM0[SPREG_START + SPREG_DAC_1] = NVRAM0[EM_START + EM_LASER_CURRENT_CH2];
		UPDAC(0);UPDAC(1);//��������DAC
	}
	else if((NVRAM0[EM_START + EM_LASER_MODE] == LASER_MODE_SP) | 
			(NVRAM0[EM_START + EM_LASER_MODE] == LASER_MODE_MP) |
			(NVRAM0[EM_START + EM_LASER_MODE] == LASER_MODE_GP)){
		NVRAM0[EM_START + EM_LASER_TMATE] = NVRAM0[EM_LASER_POSWIDTH];//����ƥ��ֵ
		NVRAM0[EM_START + EM_LASER_TOVERFLOW] = ADD(NVRAM0[EM_LASER_POSWIDTH], NVRAM0[EM_LASER_POSWIDTH]);//�������ֵ
		NVRAM0[EM_START + EM_LASER_TCOUNTER] = 0X00;	
		NVRAM0[EM_START + EM_LASER_PMATE] = 0x00;//�������ƥ��ֵ
		NVRAM0[EM_START + EM_LASER_SMATE] = 0x0;//���������ֵ
		NVRAM0[EM_START + EM_LASER_PCOUNTER] = 0X0;
		NVRAM0[EM_START + EM_LASER_SCOUNTER] = 0X0;
#ifdef C8051F580
		SFRPAGE_save = SFRPAGE;
		SFRPAGE = ACTIVE_PAGE;
		TMR3CN &= ~(uint8_t)(1 << 7);//T3�жϱ�־����
		EIE1 |= (1 << 6);//T3 ET3�ж�ʹ��
		TMR3L = 0xFF;
		TMR3H = 0xFF;
		TMR3CN |= (1 << 2);//TR3 ʹ��TIMER3��ʱ��
		SFRPAGE = SFRPAGE_save;
#endif
#ifdef C8051F020
		TMR3CN &= ~(uint8_t)(1 << 7);//TF3 �����־����
		EIE2 |= (1 << 0);//T3 ET3�ж�ʹ��
		TMR3L = 0xFF;
		TMR3H = 0xFF;
		TMR3CN |= (1 << 2);//TR3 ʹ��TIMER3��ʱ��
#endif
	}
	else if(NVRAM0[EM_START + EM_LASER_MODE] == LASER_MODE_CC)
	{//У��ģʽ
		NVRAM0[EM_START + EM_LASER_TMATE] = NVRAM0[EM_LASER_POSWIDTH];//����ƥ��ֵ
		NVRAM0[EM_START + EM_LASER_TOVERFLOW] = ADD(NVRAM0[EM_LASER_POSWIDTH], NVRAM0[EM_LASER_POSWIDTH]);//�������ֵ
		NVRAM0[EM_START + EM_LASER_TCOUNTER] = 0X00;	
		NVRAM0[EM_START + EM_LASER_PMATE] = NVRAM0[EM_START + EM_LASER_GROUP_NUM];//�������ƥ��ֵ
		NVRAM0[EM_START + EM_LASER_SMATE] = NVRAM0[EM_START + EM_LASER_GROUP_SPACE];//���������ֵ
		NVRAM0[EM_START + EM_LASER_PCOUNTER] = 0X0;
		NVRAM0[EM_START + EM_LASER_SCOUNTER] = 0X0;	
#ifdef C8051F580
		SFRPAGE_save = SFRPAGE;
		SFRPAGE = ACTIVE_PAGE;
		TMR3CN &= ~(uint8_t)(1 << 7);//TF3 �����־����
		EIE2 |= (1 << 0);//T3 ET3�ж�ʹ��
		TMR3L = 0xFF;
		TMR3L = 0xFF;
		TMR3CN |= (1 << 2);//TR3 ʹ��TIMER3��ʱ��
		SFRPAGE = SFRPAGE_save;
#endif
#ifdef C8051F020
		TMR3CN &= ~(uint8_t)(1 << 7);//TF3 �����־����
		EIE2 |= (1 << 0);//T3 ET3�ж�ʹ��
		TMR3L = 0xFF;
		TMR3H = 0xFF;
		TMR3CN |= (1 << 2);//TR3 ʹ��TIMER3��ʱ��
#endif
	}
	SET(R_START * 16+ R_FLAG_LASER_EMITING);//�����־��λ
}
static void stopLaser(void){//ֹͣ��������
#ifdef C8051F020
	TMR3CN &= ~(uint8_t)(1 << 2);//Stop Timer 3
	TMR3CN &= ~(uint8_t)(1 << 7);//Clear Timer 3 High Byte Overflow Flag.
	EIE1 &= ~(uint8_t)(1 << 6);//�ر�Timer3�ж�
#endif
#ifdef C8051F580
	uint8_t SFRPAGE_save;
	SFRPAGE_save = SFRPAGE;
	SFRPAGE = ACTIVE_PAGE;
	TMR3CN &= ~(uint8_t)(1 << 2);//Stop Timer 3
	TMR3CN &= ~(uint8_t)(1 << 7);//Clear Timer 3 High Byte Overflow Flag.
	EIE1 &= ~(uint8_t)(1 << 6);//�ر�Timer3�ж�
	SFRPAGE = SFRPAGE_save;
#endif
	//�ر�DAC���
	NVRAM0[SPREG_START + SPREG_DAC_0] = 0;
	NVRAM0[SPREG_START + SPREG_DAC_1] = 1;
	UPDAC(MCP47X6_LASER_CHANNEL_CH1);
	UPDAC(MCP47X6_LASER_CHANNEL_CH2);
	RESET(R_START * 16+ R_FLAG_LASER_EMITING);//�����־��λ
}
static void setLaserModCh1(uint8_t st){//CH1���ƿ���
	if(st){
		P4 |= (uint8_t)(1 << 6);
	}
	else{
		P4 &= ~(uint8_t)(1 << 6);
	}
}
static void setLaserModCh2(uint8_t st){//CH2���ƿ���
	if(st){
		P4 |= (uint8_t)(1 << 1);
	}
	else{
		P4 &= ~(uint8_t)(1 << 1);
	}
}
static void setLaserModBoth(uint8_t st){////CH1+CH2���ƿ���
	if(st){
		P4 |= (uint8_t)(1 << 6);
		P4 |= (uint8_t)(1 << 1);
	}
	else{
		P4 &= ~(uint8_t)(1 << 6);
		P4 &= ~(uint8_t)(1 << 1);
	}
}
static void setLaserCurrent(void){//����DAC���
	if(LD(R_START * 16 + R_LASER_SELECT_CH1)){
		mcp47x6Write(MCP47X6_LASER_CHANNEL_CH1, NVRAM0[EM_START + EM_LASER_CURRENT_CH1]);
	}
	else{
		mcp47x6Write(MCP47X6_LASER_CHANNEL_CH1, 0);
	}
	if(LD(R_START * 16 + R_LASER_SELECT_CH2)){
		mcp47x6Write(MCP47X6_LASER_CHANNEL_CH2, NVRAM0[EM_START + EM_LASER_CURRENT_CH2]);
	}
	else{
		mcp47x6Write(MCP47X6_LASER_CHANNEL_CH2, 0);
	}
}

void initTimer3(void){//TIMER3��ʼ��
	
}
void timer3Isr(void) interrupt INTERRUPT_TIMER3{//TIMER3 �ж� ���ⷢ��
#ifdef C8051F580
	uint8_t SFRPAGE_save;
	SFRPAGE_save = SFRPAGE;
	TMR3CN &= ~(uint8_t)(1 << 7);//Clear Timer 3 High Byte Overflow Flag
	SFRPAGE = SFRPAGE_save;
#endif
#ifdef C8051F020
#endif
	switch(NVRAM0[EM_START + EM_LASER_MODE){
		case LASER_MODE_CW:{//CW����ģʽ
			SetLaserCurrent();
			break;
		}
		case LASER_MODE_SP:{//SP������ģʽ
			break;
		}
		case LASER_MODE_MP:{//MP������ģʽ	
			if(p->softTimer.tCounter == p->softTimer.tMate){//��ʱ��ƥ��
				setLaserModBoth(LASER_OFF);//��ת���
			}
			if(p->softTimer.tCounter == p->softTimer.tOverflow){//��ʱ�����
				p->softTimer.tCounter = 0;//����
			}
			if(p->softTimer.tCounter == 0){//��ת
				setLaserModBoth(LASER_ON);//��ת���
			}
			p->softTimer.tCounter ++;
			break;
		}
		case LASER_MODE_GP:{//GP�ɱ������ģʽ
			if(p->softTimer.pCounter < p->softTimer.pMate){
				if(p->softTimer.tCounter == 0){
					if(p->softTimer.pCounter < p->softTimer.pMate){
						setLaserModBoth(LASER_ON);//��ת���						
					}
				}
				if(p->softTimer.tCounter == p->softTimer.tMate){//��ʱ��ƥ��
					setLaserModBoth(LASER_OFF);//��ת���
				}
				if(p->softTimer.tCounter == (p->softTimer.tOverflow - 1)){//��ʱ�����
					p->softTimer.tCounter = 0xFFFF;//����
					p->softTimer.pCounter ++;//����	
				}
				p->softTimer.tCounter ++;
			}
			if(p->softTimer.pCounter == p->softTimer.pMate && p->softTimer.tCounter == 0){//�����������ƥ��
				LaserMod_PIN = LASER_OFF;
				p->softTimer.pCounter = 0xFFFF;
				p->softTimer.sCounter = 0x0;
			}
			if(p->softTimer.pCounter == 0xFFFF){		
				if(p->softTimer.sCounter == p->softTimer.sMate){
					p->softTimer.pCounter = 0;	
				}
				p->softTimer.sCounter ++;
			}
			break;
		}
		default:break;
	}
}
