#include "sPlc.h"
/*****************************************************************************/			
/*****************************************************************************/
xdata int16_t NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
xdata int16_t NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
static data uint8_t TimerCounter_1mS = 0;
static data uint8_t TimerCounter_10mS = 0;
static data uint8_t Timer0_L, Timer0_H;
/*****************************************************************************/
typedef struct{//ADC�˲���
	uint16_t dat[CONFIG_SPLC_ADC_FILTER_TAP];
	uint16_t out;
	uint8_t wIndex;//д��ָ��
}adcTempDat_t;

static xdata uint8_t InputFilter[CONFIG_SPLC_HW_INPUT_NUM];
static xdata adcTempDat_t adcTempDat[CONFIG_SPLC_ADC_CHANNLE];
data uint8_t adcSelect;//ADCͨ��ѡ��
static void refreshAdcData(adcTempDat_t *s , uint16_t dat);
void adcProcess(void);
static void initAdcData(adcTempDat_t *s);
static void chipDacInit(void);
static void chipAdcInit(void);
/******************************************************************************/
static void adcProcess(void){//ѭ���ɼ�ADC
	uint16_t result = 0;
#ifdef C8051F020
	while(!AD0INT);
#endif
	result = (uint16_t)(ADC0H << 8) + (uint16_t)(ADC0L);
	refreshAdcData(&adcTempDat[adcSelect], result);
	NVRAM0[SPREG_ADC_0 + adcSelect] = adcTempDat[adcSelect].out;
	if(adcSelect < (CONFIG_SPLC_ADC_CHANNLE - 1)){
		adcSelect ++;
	}
	else{
		adcSelect = 0;
	}
	switch(adcSelect){
		case 0:{
			AMX0SL = 0x00;break;
		}
		case 1:{
			AMX0SL = 0x01;break;
		}
		case 2:{
			AMX0SL = 0x02;break;
		}
		case 3:{
			AMX0SL = 0x03;break;
		}
		case 4:{
			AMX0SL = 0x04;break;
		}
		case 5:{
			AMX0SL = 0x05;break;
		}
		case 6:{
			AMX0SL = 0x06;break;
		}
		case 7:{
			AMX0SL = 0x07;  break;
		}
		case 8:{
			AMX0SL = 0x08;break;
		}
		case 9:{
			break;
		}
		default:{
			break;
		}
	}
	AD0INT = 0;
	AD0BUSY = 1;//AD0BUSYд��1
}
static void initAdcData(adcTempDat_t *s){//��ʼ��ADC�˲���
	uint8_t i;
	for(i = 0;i < CONFIG_SPLC_ADC_FILTER_TAP; i++){
		s->dat[i] = 0x0;
	}
	s->out = 0;
	s->wIndex = 0;
}
static void refreshAdcData(adcTempDat_t *s , uint16_t dat){//����ADC�ɼ�ֵ
	uint8_t i;
	uint16_t temp;
	uint32_t sum;
	s->dat[s->wIndex] = dat;
	s->wIndex ++;
	if(s->wIndex >= CONFIG_SPLC_ADC_FILTER_TAP){
		s->wIndex = 0;
	}
	sum = 0;
	for(i = 0;i < CONFIG_SPLC_ADC_FILTER_TAP;i ++){
		sum += s->dat[i];
	}
	temp = (uint16_t)(sum / (uint32_t)CONFIG_SPLC_ADC_FILTER_TAP);
	s->out = temp;
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
	for(i = C_START;i <= C_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void nvramLoad(void){//��EPROM������NVRAM
	memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//��ʼ��NVRAM
	epromRead(0, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));//��EPROM�лָ�MR
	clearEM();
	clearR();
	clearT();
	clearTD();
	clearC();
	memcpy(NVRAM1, NVRAM0, CONFIG_NVRAM_SIZE);
}
static void nvramSave(void){//ǿ�ƽ�NVRAM����EPROM
	DISABLE_INTERRUPT//�ر��ж�
	epromWrite(0x0, (uint8_t*)NVRAM0, ((MR_END + 1) * 2));
	ENABLE_INTERRUPT
}
static void nvramUpdata(void){//����NVRAM->EPROM
	uint8_t *sp0, *sp1;
	uint16_t i;
	sp0 = (uint8_t*)(NVRAM0 + (MR_START * 2));
	sp1 = (uint8_t*)(NVRAM1 + (MR_START * 2));
	for(i = MR_START;i < ((MR_END + 1) * 2);i ++){//����MR
		if(*(sp0 + i) != *(sp1 + i)){
			epromWriteOneByte(i, *(sp0 + i));
		}
	}
	sp0 = (uint8_t*)(NVRAM0 + (DM_START * 2));
	sp1 = (uint8_t*)(NVRAM1 + (DM_START * 2));
	for(i = DM_START;i < ((DM_END + 1) * 2);i ++){//����DM
		if(*(sp0 + i) != *(sp1 + i)){
			epromWriteOneByte(i, *(sp0 + i));
		}
	}
	memcpy(NVRAM1, NVRAM0, (CONFIG_NVRAM_SIZE * 2));
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
	uint16_t temp;
	assertCoilAddress(A);//����ַ��Χ
	temp= NVRAM0[(A / 16)] & (1 << (A % 16));
	if(temp)
		RESET(A);
	else
		SET(A);
}
uint8_t LD(uint16_t A){//����
	assertCoilAddress(A);//����ַ��Χ
	return (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
}
uint8_t LDP(uint16_t A){//����������
	uint8_t temp0, temp1;
	assertCoilAddress(A);//����ַ��Χ
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
	if(temp0 && !temp1)
		return 1;
	else
		return 0;
}
uint8_t LDN(uint16_t A){//�����½���
	uint8_t temp0, temp1;
	assertCoilAddress(A);
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
	if(!temp0 && temp1)
		return 1;
	else
		return 0;
}
void T1MS(uint8_t A, uint8_t start, uint16_t value){//1MS��ʱ��
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
void T10MS(uint8_t A, uint8_t start, uint16_t value){//10MS��ʱ��
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
void T100MS(uint8_t A, uint8_t start, uint16_t value){//100MS��ʱ��
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

static void timer0Init(void){//Ӳ��sTimer��ʱ����ʼ��
	data uint16_t temp;
	TimerCounter_1mS = 0;
	TimerCounter_10mS = 0;
#ifdef C8051F020
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 12 /CONFIG_SOFTPLC_HWTIME));
	Timer0_L = temp & 0xFF;
	Timer0_H = (temp >> 8) & 0xFF;
	TH0 = Timer0_H;// Init T0 High register
	TL0 = Timer0_L;// Init T0 Low register
	CKCON &= ~(1 << 3);//SYSCLK / 12	
	TMOD &= 0xF0;
	TMOD |= (1 << 0);// T0 in 16-bit mode
	ET0 = 1;// T0 interrupt enabled
	TR0 = 1;// T0 ON
#endif
}
static void timer0Isr(void) interrupt INTERRUPT_TIMER0{//Ӳ��sTimer��ʱ���ж� 1mS
	uint16_t i;
	TF0 = 0;
	TR0 = 0;
	TH0 = Timer0_H;
	TL0 = Timer0_L;
	TR0 = 1;
	for(i = TD_1MS_START;i <= TD_1MS_END;i ++){//1mS��ʱ
		if(NVRAM0[i] < SHRT_MAX){
			NVRAM0[i] ++;
		}
	}
	if(TimerCounter_1mS >= 10){//10mS����
		for(i = TD_10MS_START;i <= TD_10MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_10mS ++;
		TimerCounter_1mS = 0;
	}
	if(TimerCounter_10mS >= 10){//100ms����
		for(i = TD_100MS_START;i < TD_100MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_10mS = 0;
	}
	adcProcess();//ADCɨ��
	TimerCounter_1mS ++;
}

static void refreshInput(void){//��ȡ����IO
	uint8_t ctemp, i;
	//ctemp = inPca9554Read() ;
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
static void refreshOutput(void){//�������IO
	//outPca9554Write(NVRAM0[Y_START]);
}
static void chipAdcInit(void){//ADCģ���ʼ��
	uint8_t i;
#ifdef C8051F020
	ADC0CN = 0x0;//�������
	ADC0CN |= (1 << 6);//AD0TM = 1 ���ø���
	ADC0CN |= (1 << 7);//AD0EN = 1 
	ADC0CF = 0x0;
	ADC0CF |= (CONFIG_SYSCLK / SAR_CLK) << 3;     // ADC conversion clock = 2.5MHz
	AMX0CF = 0x00;                      // AIN inputs are single-ended (default)
	AMX0SL = 0x00;                      // Select AIN0.1 pin as ADC mux input
	AD0INT = 0;
	AD0BUSY = 1;//AD0BUSYд��1
#endif
	adcSelect = 0;
	for(i = 0;i <= CONFIG_SPLC_ADC_CHANNLE;i ++){
		initAdcData(&adcTempDat[i]);
	}
}
void sPlcInit(void){//���߼���ʼ��
#if CONFIG_SPLC_USING_EPROM == 1
	nvramLoad();//�ϵ�ָ�NVRAM
#endif
#if CONFIG_SPLC_USING_ADC == 1
	chipAdcInit();//��ʼ��ADCģ��
#endif
#if CONFIG_SPLC_USING_DAC == 1
	chipDacInit();//��ʼ��DACģ��
#endif
#if CONFIG_SPLC_USING_MB_RTU_SLAVE == 1
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
#endif
	timer0Init();//��ʼ��Ӳ����ʱ��ģ��
}
static void refreshDac(void){//ˢ��DAC
#ifdef C8051F020
	if(DAC0 != NVRAM0[SPREG_DAC_0]){
		DAC0 = NVRAM0[SPREG_DAC_0];
	}
	if(DAC1 != NVRAM0[SPREG_DAC_1]){
		DAC1 = NVRAM0[SPREG_DAC_1];
	}
#endif
}
static void chipDacInit(void){//��ʼ��DAC
#ifdef C8051F020
	DAC0CN = 0x0;
	DAC0CN |= (1 << 7);
	DAC0 = 0;
	DAC1 = 0;
#endif
}
void sPlcProcessStart(void){//sPLC��ѯ��ʼ
#if CONFIG_SPLC_USING_MB_RTU_SLAVE == 1
	modbusPorcess();//����MODBUS
#endif
	refreshInput();//��ȡX������
}
void sPlcProcessEnd(void){//sPLC��ѯ����
	refreshOutput();//����Y�����
#if CONFIG_SPLC_USING_DAC
	refreshDac();//����DAC���
#endif
#if CONFIG_SPLC_USING_EPROM == 1
	nvramUpdata();//����NVRAM
#endif
}