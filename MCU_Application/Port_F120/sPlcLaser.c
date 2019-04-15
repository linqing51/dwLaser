#include "sPlcLaser.h"
/*****************************************************************************/
sbit LASER_980_MODPIN = P2^7;
sbit LASER_1470_MODPIN = P2^6;
#if CONFIG_DEBUG_TIMER4 == 1
bit debugTimer4;
#endif
/*****************************************************************************/
static void initTimer4(void);
/*****************************************************************************/
void testBenchLaserTimer(uint8_t st){//LASER���ⷢ�����
	EDLAR();
	if(st == 0){//980 CWģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_CW;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_980;
		NVRAM0[SPREG_LASER_TMATE] = 0;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 0;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_980] = 200;
		NVRAM0[SPREG_LASER_CURRENT_1470] = 300;
		STLAR();
	}
	if(st == 1){//1470 CWģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_CW;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_1470;
		NVRAM0[SPREG_LASER_TMATE] = 5;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 15;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_980] = 300;
		NVRAM0[SPREG_LASER_CURRENT_1470] = 400;
		STLAR();
	}
	if(st == 2){//980+1470 CWģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_CW;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		NVRAM0[SPREG_LASER_TMATE] = 12;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 21;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_980] = 500;
		NVRAM0[SPREG_LASER_CURRENT_1470] = 600;
		STLAR();
	}
	if(st == 3){//980 SPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_980;
		NVRAM0[SPREG_LASER_TMATE] = 50;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 200;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_980] = 700;
		NVRAM0[SPREG_LASER_CURRENT_1470] = 800;
		STLAR();
	}
	if(st == 4){//1480 SPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_1470;
		NVRAM0[SPREG_LASER_TMATE] = 25;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 100;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_980] = 900;
		NVRAM0[SPREG_LASER_CURRENT_1470] = 1000;
		STLAR();
	}
	if(st == 5){//980+1470 SPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_SP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		NVRAM0[SPREG_LASER_TMATE] = 30;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 90;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_980] = 1100;
		NVRAM0[SPREG_LASER_CURRENT_1470] = 1200;
		STLAR();
	}
	if(st == 6){//980 MPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_MP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_980;
		NVRAM0[SPREG_LASER_TMATE] = 30;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 90;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_980] = 1300;
		NVRAM0[SPREG_LASER_CURRENT_1470] = 1400;
		STLAR();
	}
	if(st == 7){//1470 MPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_MP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_1470;
		NVRAM0[SPREG_LASER_TMATE] = 74;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 96;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_980] = 1500;
		NVRAM0[SPREG_LASER_CURRENT_1470] = 1600;
		STLAR();
	}
	if(st == 8){//980+1470 MPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_MP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		NVRAM0[SPREG_LASER_TMATE] = 53;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 130;//������������ 25mS
		NVRAM0[SPREG_LASER_CURRENT_980] = 1700;
		NVRAM0[SPREG_LASER_CURRENT_1470] = 1800;
		STLAR();
	}
	if(st == 9){//980 GPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_GP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_980;
		NVRAM0[SPREG_LASER_TMATE] = 10;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 15;//������������ 25mS
		NVRAM0[SPREG_LASER_PMATE] = 10;//10������
		NVRAM0[SPREG_LASER_POVERTIME] = 33;//���33mS
		NVRAM0[SPREG_LASER_CURRENT_980] = 1900;
		NVRAM0[SPREG_LASER_CURRENT_1470] = 2000;
		STLAR();
	}
	if(st == 10){//1470 GPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_GP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_1470;
		NVRAM0[SPREG_LASER_TMATE] = 19;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 86;//������������ 25mS
		NVRAM0[SPREG_LASER_PMATE] = 12;//10������
		NVRAM0[SPREG_LASER_POVERTIME] = 43;//���33mS
		NVRAM0[SPREG_LASER_CURRENT_980] = 2100;
		NVRAM0[SPREG_LASER_CURRENT_1470] = 2200;
		STLAR();
	}
	if(st == 11){//980+1470 GPģʽ����
		NVRAM0[SPREG_LASER_MODE] = LASER_MODE_GP;
		NVRAM0[SPREG_LASER_SELECT] = LASER_SELECT_BOTH;
		NVRAM0[SPREG_LASER_TMATE] = 5;//�������������� 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = 24;//������������ 25mS
		NVRAM0[SPREG_LASER_PMATE] = 6;//10������
		NVRAM0[SPREG_LASER_POVERTIME] = 60;//���33mS
		NVRAM0[SPREG_LASER_CURRENT_980] = 2300;
		NVRAM0[SPREG_LASER_CURRENT_1470] = 2400;
		STLAR();
	}
}

void STLAR(void) reentrant{//��ʼ��������
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
}
void EDLAR(void) reentrant{//ֹͣ��������
	uint8_t SFRPAGE_save;
	SFRPAGE = TMR4_PAGE;
	TMR4CN &= ~(uint8_t)(1 << 2);//Stop Timer 4
	TMR4CN &= ~(uint8_t)(1 << 7);//Clear Timer 4 High Byte Overflow Flag.
	EIE2 &= ~(uint8_t)(1 << 2);//�ر�Timer4�ж�
	SFRPAGE = SFRPAGE_save;
	//�ر�DAC���
	NVRAM0[SPREG_DAC_0] = 0;
	NVRAM0[SPREG_DAC_1] = 1;
	UPDAC0();
	UPDAC1();
	RES(SPCOIL_LASER_EMITING);//�����־��λ
}
void sPlcLaserInit(void){//�������幦�ܳ�ʼ��
	LASER_980_MODPIN = 0;
	LASER_1470_MODPIN = 0;
	initTimer4();
	
}
static void initTimer4(void){//TIMER4��ʼ��
	xdata uint16_t temp;
	xdata uint8_t SFRPAGE_SAVE;
	SFRPAGE_SAVE = SFRPAGE;             // Preserve SFRPAGE
	SFRPAGE = TMR4_PAGE;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 12 / CONFIG_LASER_TIMER_TICK));
	TMR4CF = 0;//	
	RCAP4 = temp;// Reload value to be used in Timer3
	TMR4 = RCAP4;// Init the Timer3 register
	TMR4CN = 0;//16Bit AutoReload
	SFRPAGE = SFRPAGE_SAVE;   
}
void timer4Isr(void) interrupt INTERRUPT_TIMER4{//TIMER4 �ж� ���ⷢ��
	uint8_t SFRPAGE_save;	
#if CONFIG_DEBUG_TIMER4 == 1
	debugTimer4 = ~debugTimer4;
#endif
	SFRPAGE_save = SFRPAGE;
	SFRPAGE = TMR4_PAGE;
	TMR4CN &= ~(uint8_t)(1 << 7);//Clear Timer 4 High Byte Overflow Flag
	SFRPAGE = SFRPAGE_save;
	switch(NVRAM0[SPREG_LASER_MODE]){
		case LASER_MODE_CW:{//CW����ģʽ
			if(NVRAM0[SPREG_LASER_SELECT] == LASER_SELECT_980){//980����ͨ��
				NVRAM0[SPREG_DAC_0] = NVRAM0[SPREG_LASER_CURRENT_980];//����ֵд��DAC�Ĵ���
				UPDAC0();//DAC���������ʱ��ֵ
				LASER_980_MODPIN = true;				
			}
			else{
				NVRAM0[SPREG_DAC_0] = 0;//����ֵд��DAC�Ĵ���
				UPDAC0();//DAC���������ʱ��ֵ
				LASER_980_MODPIN = false;
			}
			if(NVRAM0[SPREG_LASER_SELECT] == LASER_SELECT_1470){//1470����ͨ��
				NVRAM0[SPREG_DAC_1] = NVRAM0[SPREG_LASER_CURRENT_1470];//����ֵд��DAC�Ĵ���
				UPDAC1();//DAC���������ʱ��ֵ
				LASER_1470_MODPIN = true; 
			}
			else{
				NVRAM0[SPREG_DAC_1] = 0;//����ֵд��DAC�Ĵ���
				UPDAC1();//DAC���������ʱ��ֵ
				LASER_1470_MODPIN = false; 
			}
			if(NVRAM0[SPREG_LASER_SELECT] == LASER_SELECT_BOTH){//980+1470����ͨ��
				NVRAM0[SPREG_DAC_0] = NVRAM0[SPREG_LASER_CURRENT_980];//����ֵд��DAC�Ĵ���
				NVRAM0[SPREG_DAC_1] = NVRAM0[SPREG_LASER_CURRENT_1470];//����ֵд��DAC�Ĵ���
				UPDAC0();//DAC���������ʱ��ֵ
				UPDAC1();//DAC���������ʱ��ֵ
				LASER_980_MODPIN = true;	
				LASER_1470_MODPIN = false; 				
			}
			break;
		}
		case LASER_MODE_SP:{//SP������ģʽ
			if(NVRAM0[SPREG_LASER_TCOUNTER] == 0){//��ת
				if(NVRAM0[SPREG_LASER_SELECT] == LASER_SELECT_980){//980����ͨ��
					NVRAM0[SPREG_DAC_0] = NVRAM0[SPREG_LASER_CURRENT_980];//����ֵд��DAC�Ĵ���
					UPDAC0();//DAC���������ʱ��ֵ
					LASER_980_MODPIN = true; 
				}
				else{
					NVRAM0[SPREG_DAC_0] = 0;//����ֵд��DAC�Ĵ���
					UPDAC0();//DAC���������ʱ��ֵ
					LASER_980_MODPIN = false;
				}
				if(NVRAM0[SPREG_LASER_SELECT] == LASER_SELECT_1470){//1470����ͨ��
					NVRAM0[SPREG_DAC_1] = NVRAM0[SPREG_LASER_CURRENT_1470];//����ֵд��DAC�Ĵ���
					UPDAC1();//DAC���������ʱ��ֵ
					LASER_1470_MODPIN = true; 
				}
				else{
					NVRAM0[SPREG_DAC_1] = 0;//����ֵд��DAC�Ĵ���
					UPDAC1();//DAC���������ʱ��ֵ
					LASER_1470_MODPIN = false; 
				}
				if(NVRAM0[SPREG_LASER_SELECT] == LASER_SELECT_BOTH){//980+1470����ͨ��
					NVRAM0[SPREG_DAC_0] = NVRAM0[SPREG_LASER_CURRENT_980];//����ֵд��DAC�Ĵ���
					NVRAM0[SPREG_DAC_1] = NVRAM0[SPREG_LASER_CURRENT_1470];//����ֵд��DAC�Ĵ���
					UPDAC0();//DAC���������ʱ��ֵ
					UPDAC1();//DAC���������ʱ��ֵ
					LASER_980_MODPIN = true;	
					LASER_1470_MODPIN = true; 	
				}
			}
			if(NVRAM0[SPREG_LASER_TCOUNTER] >= NVRAM0[SPREG_LASER_TMATE]){//��ʱ��ƥ��
				NVRAM0[SPREG_DAC_0] = 0x0;//����ֵд��DAC�Ĵ���
				UPDAC0();//DAC���������ʱ��ֵ
				NVRAM0[SPREG_DAC_1] = 0x0;//����ֵд��DAC�Ĵ���
				UPDAC1();//DAC���������ʱ��ֵ
				LASER_980_MODPIN = false;
				LASER_1470_MODPIN = false;//��ת���
				SET(SPCOIL_LASER_EMITOVER);
				EDLAR();//ֹͣ���巢��
			}
			NVRAM0[SPREG_LASER_TCOUNTER] ++;
			break;
		}
		case LASER_MODE_MP:{//MP������ģʽ	
			if(NVRAM0[SPREG_LASER_TCOUNTER] == 0){//��ת	
				if(NVRAM0[SPREG_LASER_SELECT] == LASER_SELECT_980){//980����ͨ��
					NVRAM0[SPREG_DAC_0] = NVRAM0[SPREG_LASER_CURRENT_980];//����ֵд��DAC�Ĵ���
					UPDAC0();//DAC���������ʱ��ֵ
					LASER_980_MODPIN = true; 
				}
				else{
					NVRAM0[SPREG_DAC_0] = 0;//����ֵд��DAC�Ĵ���
					UPDAC0();//DAC���������ʱ��ֵ
					LASER_980_MODPIN = false;
				}
				if(NVRAM0[SPREG_LASER_SELECT] == LASER_SELECT_1470){//1470����ͨ��
					NVRAM0[SPREG_DAC_1] = NVRAM0[SPREG_LASER_CURRENT_1470];//����ֵд��DAC�Ĵ���
					UPDAC1();//DAC���������ʱ��ֵ
					LASER_1470_MODPIN = true; 
				}
				else{
					NVRAM0[SPREG_DAC_1] = 0;//����ֵд��DAC�Ĵ���
					UPDAC1();//DAC���������ʱ��ֵ
					LASER_1470_MODPIN = false; 
				}
				if(NVRAM0[SPREG_LASER_SELECT] == LASER_SELECT_BOTH){
					NVRAM0[SPREG_DAC_0] = NVRAM0[SPREG_LASER_CURRENT_980];//����ֵд��DAC�Ĵ���
					NVRAM0[SPREG_DAC_1] = NVRAM0[SPREG_LASER_CURRENT_1470];//����ֵд��DAC�Ĵ���
					UPDAC0();//DAC���������ʱ��ֵ
					UPDAC1();//DAC���������ʱ��ֵ
					LASER_980_MODPIN = true; 
					LASER_1470_MODPIN = true; 
				}
			}
			if(NVRAM0[SPREG_LASER_TCOUNTER] == NVRAM0[SPREG_LASER_TMATE]){//��ʱ��ƥ��
				NVRAM0[SPREG_DAC_0] = 0x0;//����ֵд��DAC�Ĵ���
				UPDAC0();//DAC���������ʱ��ֵ
				NVRAM0[SPREG_DAC_1] = 0x0;//����ֵд��DAC�Ĵ���
				UPDAC1();//DAC���������ʱ��ֵ
				LASER_980_MODPIN = false;
				LASER_1470_MODPIN = false;//��ת���		
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
					if(NVRAM0[SPREG_LASER_SELECT] == LASER_SELECT_980){//980����ͨ��
						NVRAM0[SPREG_DAC_0] = NVRAM0[SPREG_LASER_CURRENT_980];//����ֵд��DAC�Ĵ���
						UPDAC0();//DAC���������ʱ��ֵ
						LASER_980_MODPIN = true; 
					}
					else{
						NVRAM0[SPREG_DAC_0] = 0;//����ֵд��DAC�Ĵ���
						UPDAC0();//DAC���������ʱ��ֵ
						LASER_980_MODPIN = false;
					}
					if(NVRAM0[SPREG_LASER_SELECT] == LASER_SELECT_1470){//1470����ͨ��
						NVRAM0[SPREG_DAC_1] = NVRAM0[SPREG_LASER_CURRENT_1470];//����ֵд��DAC�Ĵ���
						UPDAC1();//DAC���������ʱ��ֵ
						LASER_1470_MODPIN = true; 
					}
					else{
						NVRAM0[SPREG_DAC_1] = 0;//����ֵд��DAC�Ĵ���
						UPDAC1();//DAC���������ʱ��ֵ
						LASER_1470_MODPIN = false; 
					}
					if(NVRAM0[SPREG_LASER_SELECT] == LASER_SELECT_BOTH){//1470����ͨ��
						NVRAM0[SPREG_DAC_0] = NVRAM0[SPREG_LASER_CURRENT_980];//����ֵд��DAC�Ĵ���
						NVRAM0[SPREG_DAC_1] = NVRAM0[SPREG_LASER_CURRENT_1470];//����ֵд��DAC�Ĵ���
						UPDAC0();//DAC���������ʱ��ֵ
						UPDAC1();//DAC���������ʱ��ֵ
						LASER_980_MODPIN = true;
						LASER_1470_MODPIN = true; 
					}
				}
				if(NVRAM0[SPREG_LASER_TCOUNTER] == NVRAM0[SPREG_LASER_TMATE]){//��ʱ��ƥ��
					NVRAM0[SPREG_DAC_0] = 0x0;//����ֵд��DAC�Ĵ���
					UPDAC0();//DAC���������ʱ��ֵ
					NVRAM0[SPREG_DAC_1] = 0x0;//����ֵд��DAC�Ĵ���
					UPDAC1();//DAC���������ʱ��ֵ
					LASER_980_MODPIN = false;
					LASER_1470_MODPIN = false;//��ת���		
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
		default:break;
	}
}
