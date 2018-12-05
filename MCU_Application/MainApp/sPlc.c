#include "sPlc.h"
/*****************************************************************************/			
/*****************************************************************************/
xdata int16_t NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
xdata int16_t NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
static data uint8_t TimerCounter_100uS = 0;
static data uint8_t TimerCounter_1mS = 0;
static data uint8_t TimerCounter_10mS = 0;
static data uint8_t TimerCounter_100mS = 0;
static data uint8_t Timer0_L, Timer0_H;
static data int8_t InputFilter[CONFIG_SPLC_HW_INPUT_NUM];//����IO�˲���
data uint16_t ModbusSlaveOverTimeCounter;//Modbus Slaveͨ�ų�ʱ��ʱ��
/*****************************************************************************/
/******************************************************************************/

void ladder(void)
{
	//
}


void assertCoilAddress(uint16_t adr){//�����Ȧ��ַ
	if(adr > (SPREG_END * 16))
		while(1);
}
void assertRegisterAddress(uint16_t adr){//���Ĵ�����ַ
	if(adr >= SPREG_END)
		while(1);
}
void clearDM(void){//���DM�Ĵ���
	uint16_t i;
	for(i = 0;i <= DM_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearMR(void){//���MR�Ĵ���
	uint16_t i;
	for(i = MR_START;i <= MR_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearEM(void){//���EM�Ĵ���
	uint16_t i;
	for(i = EM_START;i <= EM_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearR(void){//���R�Ĵ���
	uint16_t i;
	for(i = R_START;i <= R_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearT(void){//���T�Ĵ���
	uint16_t i;
	for(i = T_1MS_START;i <= T_1MS_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
	for(i = T_10MS_START;i <= T_10MS_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
	for(i = T_100MS_START;i <= T_100MS_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearTD(void){//���TD�Ĵ���
	uint16_t i;
	for(i = TD_1MS_START;i <= TD_1MS_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
	for(i = TD_10MS_START;i <= TD_10MS_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
	for(i = TD_100MS_START;i <= TD_100MS_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearC(void){//���C�Ĵ���
	uint16_t i;
	for(i = C_START;i <= C_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void nvramLoad(void){//��EPROM������NVRAM
	DISABLE_INTERRUPT//�ر��ж�
	memset(NVRAM0, 0x0, CONFIG_NVRAM_SIZE);//��ʼ��NVRAM
	epromRead(0x0, (uint8_t*)NVRAM0, ((MR_END + 1) * 2));//��EPROM�лָ�NVRAM
	clearEM();
	clearR();
	clearT();
	clearTD();
	clearC();
	memcpy(NVRAM1, NVRAM0, CONFIG_NVRAM_SIZE);
	ENABLE_INTERRUPT
}
void nvramSave(void){//ǿ�ƽ�NVRAM����EPROM
	uint8_t flag;
	DISABLE_INTERRUPT//�ر��ж�
	//flag = iic0_write(CONFIG_EPROM_ADDRESS, ((MR_END + 1) * 2), (uint8_t*)NVRAM0);
	ENABLE_INTERRUPT
}
void nvramUpdata(void){//����NVRAM->EPROM
	uint8_t flag, *sp0, *sp1;
	uint16_t i;
	sp0 = (uint8_t*)NVRAM0;
	sp1 = (uint8_t*)NVRAM1;
	DISABLE_INTERRUPT
	for(i = 0;i <= ((MR_END + 1) * 2);i ++)
	{
		if(*(sp0 + i) != *(sp1 + i))
		{
			//flag = iic0_write(CONFIG_EPROM_ADDRESS, 1, (uint8_t*)(sp0 + i));
		}
	}
	memcpy(NVRAM1, NVRAM0, CONFIG_NVRAM_SIZE);
	ENABLE_INTERRUPT
}

void SET(uint16_t A){//��λ
	assertCoilAddress(A);//����ַ��Χ
	NVRAM0[(A / 16)] |= 1 << (A % 16);
}
void RESET(uint16_t A){//����
	assertCoilAddress(A);//����ַ��Χ
	NVRAM0[(A / 16)] &= ~(1 << (A % 16));
}
void FLIP(uint16_t A){//��ת
	data uint16_t temp;
	assertCoilAddress(A);//����ַ��Χ
	temp= NVRAM0[(A / 16)] & (1 << (A % 16));
	if(temp)
		RESET(A);
	else
		SET(A);
}
uint8_t LD(uint16_t A){
	assertCoilAddress(A);//����ַ��Χ
	return (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
}
uint8_t LDP(uint16_t A){//����������
	data uint8_t temp0, temp1;
	assertCoilAddress(A);//����ַ��Χ
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
	if(temp0 && !temp1)
		return 1;
	else
		return 0;
}
uint8_t LDN(uint16_t A){//�����½���
	data uint8_t temp0, temp1;
	assertCoilAddress(A);
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
	if(!temp0 && temp1)
		return 1;
	else
		return 0;
}

void T100US(uint8_t A, uint8_t start, uint16_t value){
#if CONFIG_DEBUG
	if(A > (TD_100US_END - TD_100US_START + 1))
		printf("T100US:%d Over Num\n", A);
#endif
	if(start){
		if(NVRAM0[(TD_100US_START + A)] >= value){
			NVRAM0[(T_100US_START + (A / 16))] |= 1 << (A % 16);
		}
		else{
			NVRAM0[(T_100US_START + (A / 16))] &= ~(1 << (A % 16));
		}
			
	}
	else{
		NVRAM0[(T_100US_START + (A / 16))] &= ~(1 << (A % 16));
		NVRAM0[(TD_100US_START + A)] = 0x0;
	}
}
void T1MS(uint8_t A, uint8_t start, uint16_t value){
#if CONFIG_DEBUG
	if(A > (TD_1MS_END - TD_1MS_START + 1))
		printf("T1MS:%d Over Num\n", A);
#endif
	if(start){
		if(NVRAM0[(TD_1MS_START + A)] >= value){
			NVRAM0[(T_1MS_START + (A / 16))] |= 1 << (A % 16);
		}
		else{
			NVRAM0[(T_1MS_START + (A / 16))] &= ~(1 << (A % 16));
		}
			
	}
	else{
		NVRAM0[(T_1MS_START + (A / 16))] &= ~(1 << (A % 16));
		NVRAM0[(TD_1MS_START + A)] = 0x0;
	}	
}
void T10MS(uint8_t A, uint8_t start, uint16_t value){
#if CONFIG_DEBUG
	if(A > (TD_10MS_END - TD_10MS_START + 1))
		printf("T10MS:%d Over Num\n", A);
#endif
	if(start){
		if(NVRAM0[(TD_10MS_START + A)] >= value){
			NVRAM0[(T_10MS_START + (A / 16))] |= 1 << (A % 16);
		}
		else{
			NVRAM0[(T_10MS_START + (A / 16))] &= ~(1 << (A % 16));
		}
	}
	else{
		NVRAM0[(T_10MS_START + (A / 16))] &= ~(1 << (A % 16));
		NVRAM0[(TD_10MS_START + A)] = 0x0;
	}	
}
void T100MS(uint8_t A, uint8_t start, uint16_t value){
#if CONFIG_DEBUG
	if(A > (TD_100MS_END - TD_100MS_START + 1))
		printf("T100MS:%d Over Num\n", A);
#endif
	if(start){
		if(NVRAM0[(TD_100MS_START + A)] >= value){
			NVRAM0[(T_100MS_START + (A / 16))] |= 1 << (A % 16);
		}
		else{
			NVRAM0[(T_100MS_START + (A / 16))] &= ~(1 << (A % 16));
		}	
	}
	else{
		NVRAM0[(T_100MS_START + (A / 16))] &= ~(1 << (A % 16));
		NVRAM0[(TD_100MS_START + A)] = 0x0;
	}
}

void timer0Init(void)
{//Ӳ��sTimer��ʱ����ʼ��
	uint16_t temp;
	TimerCounter_100uS = 0;
	TimerCounter_1mS = 0;
	TimerCounter_10mS = 0;
	TimerCounter_100mS = 0;
	ModbusSlaveOverTimeCounter = 0;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 10000 / 12));//SoftPLC Ӳ����ʱ����׼1ms
	Timer0_L = temp & 0xFF;
	Timer0_H = (temp >> 8) & 0xFF;
	TH0 = Timer0_H;// Init Timer0 High register
	TL0 = Timer0_L;// Init Timer0 Low register
	TMOD &= 0xFC;
	TMOD |= 0x01;// Timer0 in 16-bit mode
	ET0 = 1;// Timer1 interrupt enabled
	TR0 = 1;// Timer1 ON
}
void timer0Isr(void) interrupt INTERRUPT_TIMER0
{//Ӳ��sTimer��ʱ���ж� 1mS
	data uint16_t i;
	TimerCounter_100uS ++;
	ModbusSlaveOverTimeCounter ++;
	//100us
	for(i = TD_100US_START;i <= TD_100US_END;i ++){
		if(NVRAM0[i] < SHRT_MAX){
			NVRAM0[i] ++;
		}
	}
	//1ms
	if(TimerCounter_100uS >= 10){
		for(i = TD_1MS_START;i <= TD_1MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_1mS ++;
		TimerCounter_100uS = 0;
	}
	//10ms
	if(TimerCounter_1mS >= 10){
		for(i = TD_10MS_START;i < TD_10MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_10mS ++;
		TimerCounter_1mS = 0;
	}
	//100ms
	if(TimerCounter_10mS >= 10){
		for(i = TD_100MS_START;i < TD_100MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_10mS = 0;
		TimerCounter_100mS ++;
	}
	if(TimerCounter_100mS >= 10){
		TimerCounter_100mS = 0;
	}
	TimerCounter_100uS ++;
	TH0 = Timer0_H;
	TL0 = Timer0_L;
}

void refreshInput(void){//��ȡ����IO
	uint8_t ctemp, i;
	ctemp = inPca9554Read() ;
	for(i = 0;i < 8;i ++){
		if((ctemp >> i) & 0x01){
			if(InputFilter[i] < CONFIG_INPUT_FILTER_TIME){
				InputFilter[i] ++;
			}
			else{
				NVRAM0[X_START] |= (1 << i);
			}
		}
		else{
			if(InputFilter[i] > (CONFIG_INPUT_FILTER_TIME * -1)){
				InputFilter[i] --;
			}
			else{
				NVRAM0[X_START] &= ~(1 << i);
			}
		}
	}
}
void refreshOutput(void){//�������IO
	outPca9554Write(NVRAM0[Y_START]);
}
