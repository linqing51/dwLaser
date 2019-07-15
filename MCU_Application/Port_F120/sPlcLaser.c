#include "sPlcLaser.h"
/*****************************************************************************/
sbit LASER_CH0_MODPIN = P2^7;
sbit LASER_CH1_MODPIN = P2^6;
int32_t LaserReleaseTime;//���ⷢ��ʱ��
int32_t BeemChangeEnergy;//������Ƶ�ʸı�����
/*****************************************************************************/
static void initTimer4(void);
/*****************************************************************************/
#if CONFIG_SPLC_USING_LASER_TIMER_TEST == 1
void testBenchLaserTimer(uint8_t st){//LASER���ⷢ�����
	EDLAR();
	if(st == 0){//CH0 CWģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_CW;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH0;
		NVRAM0[SPREG_LASER_CURRENT_0] = 200;
		NVRAM0[SPREG_LASER_CURRENT_1] = 300;
		STLAR();
	}
	if(st == 1){//CH1 CWģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_CW;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH1;
		NVRAM0[SPREG_LASER_CURRENT_0] = 300;
		NVRAM0[SPREG_LASER_CURRENT_1] = 400;
		STLAR();
	}
	if(st == 2){//CH0+CH1 CWģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_CW;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		NVRAM0[SPREG_LASER_CURRENT_0] = 500;
		NVRAM0[SPREG_LASER_CURRENT_1] = 600;
		STLAR();
	}
	if(st == 3){//CH0 SPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH0;
		NVRAM0[SPREG_LASER_TMATE] = 50;//�������������� 10mS
		NVRAM0[SPREG_LASER_CURRENT_0] = 700;
		NVRAM0[SPREG_LASER_CURRENT_1] = 800;
		STLAR();
	}
	if(st == 4){//CH1 SPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH1;
		NVRAM0[SPREG_LASER_TMATE] = 25;//�������������� 10mS
		NVRAM0[SPREG_LASER_CURRENT_0] = 900;
		NVRAM0[SPREG_LASER_CURRENT_1] = 1000;
		STLAR();
	}
	if(st == 5){//CH0+CH1 SPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		NVRAM0[SPREG_LASER_TMATE] = 30;//�������������� 10mS
		NVRAM0[SPREG_LASER_CURRENT_0] = 1100;
		NVRAM0[SPREG_LASER_CURRENT_1] = 1200;
		STLAR();
	}
	if(st == 6){//CH0 MPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_MP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH0;
		NVRAM0[SPREG_LASER_TMATE] = 30;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 90;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_0] = 1300;
		NVRAM0[SPREG_LASER_CURRENT_1] = 1400;
		STLAR();
	}
	if(st == 7){//CH1 MPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_MP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH1;
		NVRAM0[SPREG_LASER_TMATE] = 74;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 96;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_0] = 1500;
		NVRAM0[SPREG_LASER_CURRENT_1] = 1600;
		STLAR();
	}
	if(st == 8){//CH0+CH1 MPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_MP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		NVRAM0[SPREG_LASER_TMATE] = 53;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 130;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_0] = 1700;
		NVRAM0[SPREG_LASER_CURRENT_1] = 1800;
		STLAR();
	}
	if(st == 9){//CH0 GPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_GP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH0;
		NVRAM0[SPREG_LASER_TMATE] = 10;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 15;//������������ 25mS
		NVRAM0[SPREG_LASER_PMATE] = 10;//10������
		NVRAM0[SPREG_LASER_POVERTIME] = 33;//���33mS
		NVRAM0[SPREG_LASER_CURRENT_0] = 1900;
		NVRAM0[SPREG_LASER_CURRENT_1] = 2000;
		STLAR();
	}
	if(st == 10){//CH1 GPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_GP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH1;
		NVRAM0[SPREG_LASER_TMATE] = 19;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 86;//������������ 25mS
		NVRAM0[SPREG_LASER_PMATE] = 12;//10������
		NVRAM0[SPREG_LASER_POVERTIME] = 43;//���33mS
		NVRAM0[SPREG_LASER_CURRENT_0] = 2100;
		NVRAM0[SPREG_LASER_CURRENT_1] = 2200;
		STLAR();
	}
	if(st == 11){//CH0+CH1 GPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_GP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		NVRAM0[SPREG_LASER_TMATE] = 5;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 24;//������������ 25mS
		NVRAM0[SPREG_LASER_PMATE] = 6;//10������
		NVRAM0[SPREG_LASER_POVERTIME] = 60;//���33mS
		NVRAM0[SPREG_LASER_CURRENT_0] = 2300;
		NVRAM0[SPREG_LASER_CURRENT_1] = 2400;
		STLAR();
	}	
	if(st == 12){//CH0 DERMAģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_DERMA;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH0;
		NVRAM0[SPREG_LASER_TMATE] = 10;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 15;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_0] = 1900;
		NVRAM0[SPREG_LASER_CURRENT_1] = 2000;
		STLAR();
	}
	if(st == 13){//CH1 DERMAģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_DERMA;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH1;
		NVRAM0[SPREG_LASER_TMATE] = 19;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 86;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_0] = 2100;
		NVRAM0[SPREG_LASER_CURRENT_1] = 2200;
		STLAR();
	}
	if(st == 14){//CH0+CH1 DERMAģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_DERMA;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		NVRAM0[SPREG_LASER_TMATE] = 5;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 24;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_0] = 2300;
		NVRAM0[SPREG_LASER_CURRENT_1] = 2400;
		STLAR();
	}	
	if(st == 15){//CH0 SIGNALģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SIGNAL;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH0;
		NVRAM0[SPREG_LASER_TMATE] = 10;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 15;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_0] = 1900;
		NVRAM0[SPREG_LASER_CURRENT_1] = 2000;
		STLAR();
	}
	if(st == 16){//CH1 SIGNALģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SIGNAL;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_CH1;
		NVRAM0[SPREG_LASER_CURRENT_0] = 2100;
		NVRAM0[SPREG_LASER_CURRENT_1] = 2200;
		STLAR();
	}
	if(st == 17){//CH0+CH1 SIGNALģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SIGNAL;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		NVRAM0[SPREG_LASER_CURRENT_0] = 2300;
		NVRAM0[SPREG_LASER_CURRENT_1] = 2400;
		STLAR();
	}
}

#endif
void STLAR(void) reentrant{//��ʼ��������
#if CONFIG_SPLC_USING_LASER_TIMER == 1	
	uint8_t SFRPAGE_save;
	NVRAM0[SPREG_LASER_PCOUNTER] = 0X0;
	NVRAM0[SPREG_LASER_TCOUNTER] = 0X00;	
	SFRPAGE = TMR4_PAGE;
	TMR4CN &= ~(uint8_t)(1 << 7);//TF4 �����־����
	EIE2 |= (1 << 2);//T4 ET3�ж�ʹ��
	TMR4L = 0xFF;
	TMR4H = 0xFF;
	TMR4CN |= (1 << 2);//TR3 ʹ��TIMER3��ʱ��
	SFRPAGE = SFRPAGE_save;
	SET(SPCOIL_LASER_EMITING);//�����־��λ
	RES(SPCOIL_LASER_EMITOVER);
#endif
}
void EDLAR(void) reentrant{//ֹͣ��������
#if CONFIG_SPLC_USING_LASER_TIMER == 1 	
	uint8_t SFRPAGE_save;
	SFRPAGE = TMR4_PAGE;
	TMR4CN &= ~(uint8_t)(1 << 2);//Stop Timer 4
	TMR4CN &= ~(uint8_t)(1 << 7);//Clear Timer 4 High Byte Overflow Flag.
	EIE2 &= ~(uint8_t)(1 << 2);//�ر�Timer4�ж�
	SFRPAGE = SFRPAGE_save;
	//�ر�DAC���
	NVRAM0[SPREG_DAC_0] = 0;
	NVRAM0[SPREG_DAC_1] = 1;
#if CONFIG_SPLC_USING_DAC == 1
	UPDAC0();
	UPDAC1();
#endif
	RES(SPCOIL_LASER_EMITING);//�����־��λ
#endif
	
}
void sPlcLaserInit(void){//�������幦�ܳ�ʼ��
#if CONFIG_SPLC_USING_LASER_TIMER ==1
	uint16_t temp;
	uint8_t SFRPAGE_SAVE;
	LASER_CH0_MODPIN = 0;
	LASER_CH1_MODPIN = 0;
	SFRPAGE = TMR4_PAGE;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 12 / CONFIG_LASER_TIMER_TICK));
	TMR4CF = 0;//	
	RCAP4 = temp;// Reload value to be used in Timer3
	TMR4 = RCAP4;// Init the Timer3 register
	TMR4CN = 0;//16Bit AutoReload
	RES(SPCOIL_LASER_DRIVER_INIT_FAIL);
	SFRPAGE = SFRPAGE_SAVE; 
#endif
}
static void laserStart(void){//��ͨ��ѡ��򿪼���
	switch(NVRAM0[SPREG_LASER_SELECT]){
		case LASER_SELECT_CH0:{//0����ͨ��
			NVRAM0[SPREG_DAC_0] = NVRAM0[SPREG_LASER_CURRENT_0];//����ֵд��DAC�Ĵ���
			NVRAM0[SPREG_DAC_1] = 0;
#if CONFIG_SPLC_USING_DAC == 1
			UPDAC0();//DAC���������ʱ��ֵ
			UPDAC1();
#endif
			LASER_CH0_MODPIN = true; 
			LASER_CH1_MODPIN = false;
			break;
		}
		case LASER_SELECT_CH1:{ 
			NVRAM0[SPREG_DAC_0] = 0;//����ֵд��DAC�Ĵ���
			NVRAM0[SPREG_DAC_1] = NVRAM0[SPREG_LASER_CURRENT_1];//����ֵд��DAC�Ĵ���
#if CONFIG_SPLC_USING_DAC == 1
			UPDAC0();//DAC���������ʱ��ֵ
			UPDAC1();//DAC���������ʱ��ֵ
#endif
			LASER_CH0_MODPIN = false;
			LASER_CH1_MODPIN = true;
			break;
		}
		case LASER_SELECT_BOTH:{
			NVRAM0[SPREG_DAC_0] = NVRAM0[SPREG_LASER_CURRENT_0];//����ֵд��DAC�Ĵ���
			NVRAM0[SPREG_DAC_1] = NVRAM0[SPREG_LASER_CURRENT_1];//����ֵд��DAC�Ĵ���
#if CONFIG_SPLC_USING_DAC == 1
			UPDAC0();//DAC���������ʱ��ֵ
			UPDAC1();//DAC���������ʱ��ֵ
#endif
			LASER_CH0_MODPIN = true; 
			LASER_CH1_MODPIN = true; 
			break;
		}
	}		
}
static void laserStop(void){//��ͨ��ѡ��رռ���
	NVRAM0[SPREG_DAC_0] = 0x0;//����ֵд��DAC�Ĵ���
#if CONFIG_SPLC_USING_DAC == 1
	UPDAC0();//DAC���������ʱ��ֵ
#endif
	NVRAM0[SPREG_DAC_1] = 0x0;//����ֵд��DAC�Ĵ���
#if CONFIG_SPLC_USING_DAC == 1
	UPDAC1();//DAC���������ʱ��ֵ
#endif
	LASER_CH0_MODPIN = false;
	LASER_CH1_MODPIN = false;//��ת���		
}
void laserTimerIsr(void) interrupt INTERRUPT_TIMER4{//TIMER4 �ж� ���ⷢ��
	uint8_t SFRPAGE_save;	
	SFRPAGE_save = SFRPAGE;
	SFRPAGE = TMR4_PAGE;
	TMR4CN &= ~(uint8_t)(1 << 7);//Clear Timer 4 High Byte Overflow Flag
	SFRPAGE = SFRPAGE_save;
	switch(NVRAM0[SPREG_LASER_MODE]){
		case LASER_MODE_CW:{//CW����ģʽ
			if(NVRAM0[SPREG_LASER_TCOUNTER] == 0){
				laserStart();	
				NVRAM0[SPREG_LASER_TCOUNTER] ++;
			}
			else{
				if(LaserReleaseTime < 1000){
					LaserReleaseTime ++;//����ʱ���ۼ�
				}
				else{
					LaserReleaseTime = 0;
					ADDS1(EM_RELEASE_TOTAL_TIME);
				}
			}
			break;
		}
		case LASER_MODE_SIGNAL:{
			if(NVRAM0[SPREG_LASER_TCOUNTER] == 0){
				laserStart();
				NVRAM0[SPREG_LASER_TCOUNTER] ++;
				BeemChangeEnergy = 0;
			}
			else{
				BeemChangeEnergy += 1;
				if(LaserReleaseTime < 1000){
					LaserReleaseTime ++;//����ʱ���ۼ�
				}
				else{
					LaserReleaseTime = 0;
					ADDS1(EM_RELEASE_TOTAL_TIME);
				}
				if(BeemChangeEnergy >= NVRAM0[EM_LASER_SIGNAL_TIME_INTERVAL]){
					BeemChangeEnergy = 0;
					if(NVRAM0[SPREG_BEEM_FREQ] == BEEM_FREQ_0){
						NVRAM0[SPREG_BEEM_FREQ] = BEEM_FREQ_1;
					}
					else{
						NVRAM0[SPREG_BEEM_FREQ] = BEEM_FREQ_0;
					}
				}
			}		
			NVRAM0[SPREG_LASER_TCOUNTER] ++;
			break;
		}
		case LASER_MODE_DERMA:{//��MPģʽ��ͬ
		}
		case LASER_MODE_MP:{//MP������ģʽ	
			if(NVRAM0[SPREG_LASER_TCOUNTER] == 0){//��ת
				laserStart();
			}
			if((NVRAM0[SPREG_LASER_TCOUNTER] > 0) && (NVRAM0[SPREG_LASER_TCOUNTER] < NVRAM0[SPREG_LASER_TMATE])){//���ⷢ����
				if(LaserReleaseTime < 1000){
					LaserReleaseTime ++;//����ʱ���ۼ�
				}
				else{
					LaserReleaseTime = 0;
					ADDS1(EM_RELEASE_TOTAL_TIME);
				}
			}
			if(NVRAM0[SPREG_LASER_TCOUNTER] == NVRAM0[SPREG_LASER_TMATE]){//��ʱ��ƥ��
				laserStop();
				if(LaserReleaseTime < 1000){
					LaserReleaseTime ++;//����ʱ���ۼ�
				}
				else{
					LaserReleaseTime = 0;
					ADDS1(EM_RELEASE_TOTAL_TIME);
				}
				
			}
			if(NVRAM0[SPREG_LASER_TCOUNTER] >= NVRAM0[SPREG_LASER_TOVERTIME]){//��ʱ�����
				NVRAM0[SPREG_LASER_TCOUNTER] = -1;//����
			}
			NVRAM0[SPREG_LASER_TCOUNTER] ++;
			break;
		}
		case LASER_MODE_GP:{//GP�ɱ������ģʽ
			if(NVRAM0[SPREG_LASER_PCOUNTER] < NVRAM0[SPREG_LASER_PMATE]){//���崮���
				if(NVRAM0[SPREG_LASER_TCOUNTER] == 0){//��ת	
					laserStart();
				}
				if((NVRAM0[SPREG_LASER_TCOUNTER] > 0) && (NVRAM0[SPREG_LASER_TCOUNTER] < NVRAM0[SPREG_LASER_PMATE])){//���ⷢ����
					if(LaserReleaseTime < 1000){
						LaserReleaseTime ++;//����ʱ���ۼ�
					}
					else{
						LaserReleaseTime = 0;
						ADDS1(EM_RELEASE_TOTAL_TIME);
					}
				}
				if(NVRAM0[SPREG_LASER_TCOUNTER] == NVRAM0[SPREG_LASER_TMATE]){//��ʱ��ƥ��
					laserStop();
					if(LaserReleaseTime < 1000){
						LaserReleaseTime ++;//����ʱ���ۼ�
					}
					else{
						LaserReleaseTime = 0;
						ADDS1(EM_RELEASE_TOTAL_TIME);
					}
				}
				if(NVRAM0[SPREG_LASER_TCOUNTER] >= NVRAM0[SPREG_LASER_TOVERTIME]){//��ʱ�����
					NVRAM0[SPREG_LASER_TCOUNTER] = -1;//����
					NVRAM0[SPREG_LASER_PCOUNTER] ++;
				}
				NVRAM0[SPREG_LASER_TCOUNTER] ++;
			}
			if(NVRAM0[SPREG_LASER_PCOUNTER] >= NVRAM0[SPREG_LASER_PMATE]){//��������		
				if(NVRAM0[SPREG_LASER_PCOUNTER] >= (NVRAM0[SPREG_LASER_POVERTIME] + NVRAM0[SPREG_LASER_PMATE])){//�����������ƥ��
					NVRAM0[SPREG_LASER_PCOUNTER] = -1;
					NVRAM0[SPREG_LASER_TCOUNTER] = 0;
				}
				NVRAM0[SPREG_LASER_PCOUNTER] ++;
			}
			break;
		}
		case LASER_MODE_SP:{//������ģʽ
			if(NVRAM0[SPREG_LASER_TCOUNTER] == 0){//��ת	
				laserStart();
			}
			if((NVRAM0[SPREG_LASER_TCOUNTER] > 0) && (NVRAM0[SPREG_LASER_TCOUNTER] < NVRAM0[SPREG_LASER_TMATE])){
				if(LaserReleaseTime < 1000){
					LaserReleaseTime ++;//����ʱ���ۼ�
				}
				else{
					LaserReleaseTime = 0;
					ADDS1(EM_RELEASE_TOTAL_TIME);
				}
			}
			if(NVRAM0[SPREG_LASER_TCOUNTER] >= NVRAM0[SPREG_LASER_TMATE]){//��ʱ��ƥ��
				laserStop();
				if(LaserReleaseTime < 1000){
					LaserReleaseTime ++;//����ʱ���ۼ�
				}
				else{
					LaserReleaseTime = 0;
					ADDS1(EM_RELEASE_TOTAL_TIME);
				}
				EDLAR();
			}
			NVRAM0[SPREG_LASER_TCOUNTER] ++;
			break;
		}
		default:break;
	}
}