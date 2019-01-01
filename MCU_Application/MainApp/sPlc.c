#include "sPlc.h"
/*****************************************************************************/			
/*****************************************************************************/
xdata int16_t NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
xdata int16_t NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
static data uint8_t TimerCounter_1mS = 0;
static data uint8_t TimerCounter_10mS = 0;
static data uint8_t Timer0_L, Timer0_H;
/*****************************************************************************/
static pdata int8_t inputFilter[CONFIG_SPLC_IO_INPUT_NUM];//IO�����˲���������
static xdata adcTempDat_t adcTempDat[CONFIG_SPLC_ADC_CHANNLE];
static uint8_t adcSelect;//ADCͨ��ѡ��
static void refreshAdcData(adcTempDat_t *s , uint16_t dat);
static void adcProcess(void);
static void initAdcData(adcTempDat_t *s);
static void chipDacInit(void);
static void chipAdcInit(void);
/******************************************************************************/
static void setLedRun(uint8_t st) reentrant{
}
static uint8_t getLedRun(void) reentrant{
}
static void setLedEprom(uint8_t st) reentrant{
}
static uint8_t getLedEprom(void) reentrant{
}
static void setLedDac(uint8_t st) reentrant{
}
static uint8_t getLedDac(void) reentrant{
}
static void setLedError(uint8_t st) reentrant{
}
static uint8_t getLedError(void) reentrant{
}
static void adcProcess(void){//ѭ���ɼ�ADC
	uint16_t result = 0;
#ifdef C8051F020
	while(!AD0INT);
#endif
	result = (uint16_t)(ADC0H << 8) + (uint16_t)(ADC0L);
	refreshAdcData(&adcTempDat[adcSelect], result);
	NVRAM0[EM_ADC_0 + adcSelect] = adcTempDat[adcSelect].out;
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
		case 10:{
			break;
		}
		case 11:{
			break;
		}
		case 12:{
			break;
		}
		case 13:{
			break;
		}
		case 14:{
			break;
		}
		case 15:{
			break;
		}
		case 16:{
			break;
		}
		case 17:{
			break;
		}
		case 18:{
			break;
		}
		case 19:{
			break;
		}
		case 20:{
			break;
		}
		case 21:{
			break;
		}
		case 22:{
			break;
		}
		case 23:{
			break;
		}
		case 24:{
			break;
		}
		case 32:{
			break;
		}
		case 33:{
			break;
		}
		case 34:{
			break;
		}
		case 35:{
			break;
		}
		case 36:{
			break;
		}
		case 37:{
			break;
		}
		case 38:{
			break;
		}
		case 39:{
			break;
		}
		case 40:{
			break;
		}
		case 41:{
			break;
		}
		case 42:{
			break;
		}
		case 43:{
			break;
		}
		case 44:{
			break;
		}
		case 45:{
			break;
		}
		case 46:{
			break;
		}
		case 47:{
			break;
		}
		case 48:{
			break;
		}
		case 49:{
			break;
		}
		case 50:{
			break;
		}
		case 51:{
			break;
		}
		case 52:{
			break;
		}
		case 53:{
			break;
		}
		case 54:{
			break;
		}
		case 55:{
			break;
		}
		case 56:{
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
	//�����ܺ�
	sum = 0;
	for(i = 0;i < CONFIG_SPLC_ADC_FILTER_TAP;i ++){
		sum += s->dat[i];
	}
	//ȥ��һ�����ֵ��һ����Сֵ
	
	temp = (uint16_t)(sum / (uint32_t)CONFIG_SPLC_ADC_FILTER_TAP);
	s->out = temp;
}
static void assertCoilAddress(uint16_t adr){//�����Ȧ��ַ
	if(adr > (SPREG_END * 16))
		while(1);
}
static void assertRegisterAddress(uint16_t adr){//���Ĵ�����ַ
	if(adr >= SPREG_END)
		while(1);
}
static void clearDM(void){//���DM�Ĵ���
	uint16_t i;
	for(i = 0;i <= DM_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearMR(void){//���MR�Ĵ���
	uint16_t i;
	for(i = MR_START;i <= MR_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearEM(void){//���EM�Ĵ���
	uint16_t i;
	for(i = EM_START;i <= EM_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearR(void){//���R�Ĵ���
	uint16_t i;
	for(i = R_START;i <= R_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearT(void){//���T�Ĵ���
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
static void clearTD(void){//���TD�Ĵ���
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
static void clearC(void){//���C�Ĵ���
	uint16_t i;
	for(i = C_START;i <= C_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearX(void){//���X�Ĵ���
	uint16_t i;
	for(i = X_START;i <= X_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearY(void){//���Y�Ĵ���
	uint16_t i;
	for(i = Y_START;i <= Y_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearSPREG(void){
	uint16_t i;
	for(i = SPREG_START;i <= SPREG_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearSPCOIL(){
	uint16_t i;
	for(i = SPCOIL_START;i <= SPCOIL_END;i ++){
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
	clearX();
	clearY();
	clearSPREG();
	clearSPCOIL();
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
			setLedEprom(true);
			epromWriteOneByte(i, *(sp0 + i));
			setLedEprom(false);
		}
	}
	sp0 = (uint8_t*)(NVRAM0 + (DM_START * 2));
	sp1 = (uint8_t*)(NVRAM1 + (DM_START * 2));
	for(i = DM_START;i < ((DM_END + 1) * 2);i ++){//����DM
		if(*(sp0 + i) != *(sp1 + i)){
			setLedEprom(true);
			epromWriteOneByte(i, *(sp0 + i));
			setLedEprom(false);
		}
	}
	memcpy(NVRAM1, NVRAM0, (CONFIG_NVRAM_SIZE * 2));
}
/*****************************************************************************/
//���߼�ָ��
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

int16_t TNTC(int16_t dat){//CODEת��ΪNTC�����¶��¶�
	uint16_t temp;
	fp32_t ftemp;
	if(dat >= CONFIG_SPLC_ADC_INTERNAL_VREF) dat = CONFIG_SPLC_ADC_INTERNAL_VREF;//�����������ֵ
	if(dat < 0) dat = 0;
	
	temp = (int16_t)(CONFIG_SPLC_ADC_INTERNAL_VREF * dat / 4096);//��λmV
	temp = 10000 * 5000 / (5000 - temp);//��Դ5V ��ѹ����10K
	
	ftemp = ((1.0 / 3477)*log((fp32_t)(temp) / 10000)) + (1 / (25+273.0));//limo R25=10740,B=3450	 uniquemode 3988
	ftemp = ( 1.0 / ftemp ) - 273.0;
	if(ftemp >= 100) ftemp = 100;
	if(ftemp <= -100) ftemp = -100;
	return (int16_t)(ftemp * 10);
}
int16_t TENV(int16_t dat){//CODEת��Ϊ�����¶�
	uint16_t temp;
	temp = (int16_t)(CONFIG_SPLC_ADC_INTERNAL_VREF * dat / 4096);//��λmV
	temp = (int16_t)((temp - CONFIG_SPLC_ADC_TEMP_SENSOR_OFFSET) * 1000 / CONFIG_SPLC_ADC_TEMP_SENSOR_GAIN);
	return temp;
}
int16_t MAX(int16_t *s, uint8_t len){//�ҳ�����Ϊlen������s�е����ֵ
	int16_t max;
	uint8_t i;
	max = *s;
	for(i = 0;i < len;i ++){
		if(*(s +i) > max){
			max = *(s + i);
		}
	}
	return max;
}
int16_t MIN(int16_t *s, uint8_t len){//�ҳ�����Ϊlen������s�е���Сֵ
	int16_t min;
	uint8_t i;
	min = *s;
	for(i = 0;i < len;i ++){
		if(*(s +i) < min){
			min = *(s + i);
		}
	}
	return min;
}
/*****************************************************************************/
static void wdtInit(void){//���Ź���ʼ��
#ifdef C8051F020
	WDTCN = 0;//47mS
#endif
}
static void wdtEnable(void){//ʹ�ܿ��Ź�
#ifdef C8051F020
	WDTCN = 0xA5;
#endif
#ifdef C8051F580
#endif
}
static void wdtDisable(void){//�رտ��Ź�(δ����)
	uint8_t flagEA;
	flagEA = EA;
	EA = 0;
#ifdef C8051F020
	WDTCN = 0xDE;
    WDTCN = 0xAD;
#endif
#ifdef C8051F020
#endif
	EA = flagEA;
}
static void wdtFeed(void){//ι��
#ifdef C8051F020
	WDTCN = 0xA5;
#endif
}

static void pcaInit(void){//Ӳ��PCA��ʼ��
#ifdef C8051F020

#endif
#ifdef C8051F580
//F580 CEX6,7,8 PWM OUT
//F680 CEX9,10,11 PULSE IN
#endif
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
	if((NVRAM0[(SPCOIL_START + (SPCOIL_PS1MS / 16))] >> (SPCOIL_PS1MS % 16)) & 0x01){//ON
		NVRAM0[(SPCOIL_START + (SPCOIL_PS1MS / 16))] &= ~(uint16_t)(1 << (SPCOIL_PS1MS % 16));
	}
	else{//OFF
		NVRAM0[(SPCOIL_START + (SPCOIL_PS1MS / 16))] |= (uint16_t)(1 << (SPCOIL_PS1MS % 16));
	}
	
	for(i = TD_1MS_START;i <= TD_1MS_END;i ++){//1mS��ʱ
		if(NVRAM0[i] < SHRT_MAX){
			NVRAM0[i] ++;
		}
	}
	if(TimerCounter_1mS >= 10){//10mS����
		if((NVRAM0[(SPCOIL_START + (SPCOIL_PS10MS / 16))] >> (SPCOIL_PS10MS % 16)) & 0x01){//ON
			NVRAM0[(SPCOIL_START + (SPCOIL_PS10MS / 16))] &= ~(uint16_t)(1 << (SPCOIL_PS10MS % 16));
		}
		else{//OFF
			NVRAM0[(SPCOIL_START + (SPCOIL_PS10MS / 16))] |= (uint16_t)(1 << (SPCOIL_PS10MS % 16));
		}
		for(i = TD_10MS_START;i <= TD_10MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_10mS ++;
		TimerCounter_1mS = 0;
	}
	if(TimerCounter_10mS >= 10){//100ms����
		if((NVRAM0[(SPCOIL_START + (SPCOIL_PS100MS / 16))] >> (SPCOIL_PS100MS % 16)) & 0x01){//ON
			NVRAM0[(SPCOIL_START + (SPCOIL_PS100MS / 16))] &= ~(uint16_t)(1 << (SPCOIL_PS100MS % 16));
		}
		else{//OFF
			NVRAM0[(SPCOIL_START + (SPCOIL_PS100MS / 16))] |= (uint16_t)(1 << (SPCOIL_PS100MS % 16));
		}
		for(i = TD_100MS_START;i < TD_100MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_10mS = 0;
		if(getLedRun()){
			setLedRun(false);
		}
		else{
			setLedRun(true);
		}
	}
#if CONFIG_SPLC_USING_ADC == 1
	adcProcess();//ADCɨ��
#endif
	TimerCounter_1mS ++;
}

static void inputInit(void){
	memset(inputFilter, 0x0, CONFIG_SPLC_IO_INPUT_NUM);
#ifdef C8051F020
#endif
#ifdef C8051F580
#endif
}
static void outputInit(void){
#ifdef C8051F020
	
#endif
#ifdef C8051F580
	
#endif
}
static void inputRefresh(void){//��ȡ����IO
	uint8_t ctemp0,ctemp1, i;
	ctemp0 = 0;
	ctemp0 = 0;
#ifdef C8051F020
	//P4,P5����
	ctemp0 = P4;
	ctemp1 = P5;
#endif
#ifdef C8051F580
	ctemp0 = inPca9554Read() ;
#endif
	for(i = 0;i < 8;i ++){//X0-X7
		if((ctemp0 >> i) & 0x01){
			if(inputFilter[i] < CONFIG_INPUT_FILTER_TIME){
				inputFilter[i] ++;
			}
			else{
				NVRAM0[X_START] |= (int16_t)(1 << i);
			}
		}
		else{
			if(inputFilter[i] > (CONFIG_INPUT_FILTER_TIME * -1)){
				inputFilter[i] --;
			}
			else{
				NVRAM0[X_START] &= ~(uint16_t)(1 << i);
			}
		}
	}
	for(i = 8;i < 16;i ++){//X8-X15
		if((ctemp1 >> (i - 8)) & 0x01){
			if(inputFilter[i] < CONFIG_INPUT_FILTER_TIME){
				inputFilter[i] ++;
			}
			else{
				NVRAM0[X_START] |= (int16_t)(1 << i);
			}
		}
		else{
			if(inputFilter[i] > (CONFIG_INPUT_FILTER_TIME * -1)){
				inputFilter[i] --;
			}
			else{
				NVRAM0[X_START] &= ~(uint16_t)(1 << i);
			}
		}
	}
}
static void outputRefresh(void){//�������IO
#ifdef C8051F020
	//P6,P7���IO
	P6 = (NVRAM0[Y_START] & 0x00FF);
	P7 = ((NVRAM0[Y_START] >> 8) & 0x00FF);
#endif
#ifdef C8051F580
	outPca9554Write(NVRAM0[Y_START]);
#endif
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
static void refreshDac(void){//ˢ��DAC
	//LD��0
	if(NVRAM0[EM_DAC_0] != NVRAM1[EM_DAC_0]){//CH0
		setLedDac(true);
		dac8568_0_WriteDacRegister(0x0, NVRAM0[EM_DAC_0]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_1] != NVRAM1[EM_DAC_1]){//CH1
		dac8568_0_WriteDacRegister(0x1, NVRAM0[EM_DAC_1]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_2] != NVRAM1[EM_DAC_2]){//CH2
		dac8568_0_WriteDacRegister(0x2, NVRAM0[EM_DAC_2]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_3] != NVRAM1[EM_DAC_3]){//CH3
		dac8568_0_WriteDacRegister(0x3, NVRAM0[EM_DAC_3]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_4] != NVRAM1[EM_DAC_4]){//CH4
		dac8568_0_WriteDacRegister(0x4, NVRAM0[EM_DAC_4]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_5] != NVRAM1[EM_DAC_5]){//CH5
		dac8568_0_WriteDacRegister(0x5, NVRAM0[EM_DAC_5]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_6] != NVRAM1[EM_DAC_6]){//CH6
		dac8568_0_WriteDacRegister(0x6, NVRAM0[EM_DAC_6]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_7] != NVRAM1[EM_DAC_7]){//CH7
		dac8568_0_WriteDacRegister(0x7, NVRAM0[EM_DAC_7]);
		setLedDac(false);
	}
	//LD��1
	if(NVRAM0[EM_DAC_8] != NVRAM1[EM_DAC_8]){//CH8
		dac8568_1_WriteDacRegister(0x0, NVRAM0[EM_DAC_8]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_9] != NVRAM1[EM_DAC_9]){
		dac8568_1_WriteDacRegister(0x1, NVRAM0[EM_DAC_9]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_10] != NVRAM1[EM_DAC_10]){
		dac8568_1_WriteDacRegister(0x2, NVRAM0[EM_DAC_10]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_11] != NVRAM1[EM_DAC_11]){
		dac8568_1_WriteDacRegister(0x3, NVRAM0[EM_DAC_11]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_12] != NVRAM1[EM_DAC_12]){
		dac8568_1_WriteDacRegister(0x4, NVRAM0[EM_DAC_12]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_13] != NVRAM1[EM_DAC_13]){
		dac8568_1_WriteDacRegister(0x5, NVRAM0[EM_DAC_13]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_14] != NVRAM1[EM_DAC_14]){
		dac8568_1_WriteDacRegister(0x6, NVRAM0[EM_DAC_14]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_15] != NVRAM1[EM_DAC_15]){
		dac8568_1_WriteDacRegister(0x7, NVRAM0[EM_DAC_15]);
		setLedDac(false);
	}
	//LD��2
	if(NVRAM0[EM_DAC_16] != NVRAM1[EM_DAC_16]){
		dac8568_2_WriteDacRegister(0x0, NVRAM0[EM_DAC_16]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_17] != NVRAM1[EM_DAC_17]){
		dac8568_2_WriteDacRegister(0x1, NVRAM0[EM_DAC_17]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_18] != NVRAM1[EM_DAC_18]){
		dac8568_2_WriteDacRegister(0x2, NVRAM0[EM_DAC_18]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_19] != NVRAM1[EM_DAC_19]){
		dac8568_2_WriteDacRegister(0x3, NVRAM0[EM_DAC_19]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_20] != NVRAM1[EM_DAC_20]){
		dac8568_2_WriteDacRegister(0x4, NVRAM0[EM_DAC_20]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_21] != NVRAM1[EM_DAC_21]){
		dac8568_2_WriteDacRegister(0x5, NVRAM0[EM_DAC_21]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_22] != NVRAM1[EM_DAC_22]){
		dac8568_2_WriteDacRegister(0x6, NVRAM0[EM_DAC_22]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_23] != NVRAM1[EM_DAC_23]){
		dac8568_2_WriteDacRegister(0x7, NVRAM0[EM_DAC_23]);
		setLedDac(false);
	}
	//��4
	if(NVRAM0[EM_DAC_24] != NVRAM1[EM_DAC_24]){
		dac8568_3_WriteDacRegister(0x0, NVRAM0[EM_DAC_24]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_25] != NVRAM1[EM_DAC_25]){
		dac8568_3_WriteDacRegister(0x1, NVRAM0[EM_DAC_26]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_26] != NVRAM1[EM_DAC_26]){
		dac8568_3_WriteDacRegister(0x2, NVRAM0[EM_DAC_26]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_27] != NVRAM1[EM_DAC_27]){
		dac8568_3_WriteDacRegister(0x3, NVRAM0[EM_DAC_27]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_28] != NVRAM1[EM_DAC_28]){
		dac8568_3_WriteDacRegister(0x4, NVRAM0[EM_DAC_28]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_29] != NVRAM1[EM_DAC_29]){
		dac8568_3_WriteDacRegister(0x5, NVRAM0[EM_DAC_29]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_30] != NVRAM1[EM_DAC_30]){
		dac8568_3_WriteDacRegister(0x6, NVRAM0[EM_DAC_30]);
		setLedDac(false);
	}
	if(NVRAM0[EM_DAC_31] != NVRAM1[EM_DAC_31]){
		dac8568_3_WriteDacRegister(0x7, NVRAM0[EM_DAC_31]);
		setLedDac(false);
	}
}
static void chipDacInit(void){//��ʼ��DAC
	dac8568_0_Init();
	dac8568_1_Init();
	dac8568_2_Init();
	dac8568_3_Init();
}
void sPlcInit(void){//���߼���ʼ��
	setLedRun(false);
	wdtInit();//���Ź�ʹ��
	wdtDisable();//���ο��Ź�	
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
	NVRAM0[(SPCOIL_START + (SPCOIL_ON / 16))] |= (uint16_t)(1 << (SPCOIL_ON % 16));
}
void sPlcProcessStart(void){//sPLC��ѯ��ʼ
#if CONFIG_SPLC_USING_MB_RTU_SLAVE == 1
	modbusPorcess();//����MODBUS
#endif
#if CONFIG_SPLC_USING_IO_INPUT == 1
	inputRefresh();//��ȡX������
#endif
#if CONFIG_SPLC_USING_WDT == 1
	wdtFeed();
#endif
}
void sPlcProcessEnd(void){//sPLC��ѯ����
#if CONFIG_SPLC_USING_WDT == 1
	wdtFeed();//ι��
#endif
#if CONFIG_SPLC_USING_IO_OUTPUT == 1
	outputRefresh();//����Y�����
#endif
#if CONFIG_SPLC_USING_DAC
	refreshDac();//����DAC���
#endif
#if CONFIG_SPLC_USING_EPROM == 1
	nvramUpdata();//����NVRAM
#endif
}