#include "sPlc.h"
/*****************************************************************************/
xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
static idata volatile uint8_t TimerCounter_1mS = 0;
static idata volatile uint8_t TimerCounter_10mS = 0;
static idata volatile uint8_t TimerCounter_100mS = 0;
static idata volatile uint8_t Timer0_L, Timer0_H;
/*****************************************************************************/
static idata volatile int8_t inputFilter[(X_END - X_START + 1) * 16];//IO�����˲���������
/******************************************************************************/
uint8_t getGlobalInterrupt(void){
	return EA;
}
void setLedRun(uint8_t idata st){//SETLED RUN P7_0
	if(st){
		P7 |= (uint8_t)(1 << 0);
	}
	else{
		P7 &= ~(uint8_t)(1 << 0);
	}
}
uint8_t getLedRun(void){//GET LED RUN P7_0
	return (uint8_t)((P7 >> 0) & 0x01);
}
void setLedEprom(uint8_t idata st){//SET LED EPROM P7_1
	if(st){
		P7 |= (uint8_t)(1 << 1);
	}
	else{
		P7 &= ~(uint8_t)(1 << 1);
	}
}
uint8_t getLedEprom(void){//GET LED EPROM P7_1
	return (uint8_t)((P7 >> 1) & 0x01);
}
void setLedDac(uint8_t idata st){//SET LED DAC P7_2
	if(st){
		P7 |= (uint8_t)(1 << 2);
	}
	else{
		P7 &= ~(uint8_t)(1 << 2);
	}
}
uint8_t getLedDac(void){//GET LED DAC P7_2
	return (uint8_t)((P7 >> 2) & 0x01);
}
void setLedError(uint8_t idata st){//SET LED ERROR P7_3
	if(st){
		P7 |= (uint8_t)(1 << 3);
	}
	else{
		P7 &= ~(uint8_t)(1 << 3);
	}
}
uint8_t getLedError(void){//GET LED ERROR
	return (uint8_t)((P7 >> 3) & 0x01);
}
static void assertCoilAddress(uint16_t adr) reentrant{//�����Ȧ��ַ
#if CONFIG_SPLC_ASSERT == 1
	if(adr > (SPREG_END * 16))
		while(1);
#endif
}
static void assertRegisterAddress(uint16_t adr) reentrant{//���Ĵ�����ַ
#if CONFIG_SPLC_ASSERT == 1
	if(adr >= SPREG_END)
		while(1);
#endif
}
static void clearDM(void){//���DM�Ĵ���
	uint16_t i;
	for(i = 0;i <= DM_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearMR(void){//���MR�Ĵ���
	uint16_t i;
	for(i = MR_START;i <= MR_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearEM(void){//���EM�Ĵ���
	uint16_t i;
	for(i = EM_START;i <= EM_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearR(void){//���R�Ĵ���
	uint16_t i;
	for(i = R_START;i <= R_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearT(void){//���T�Ĵ���
	uint16_t i;
	for(i = T_1MS_START;i <= T_1MS_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
	for(i = T_10MS_START;i <= T_10MS_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
	for(i = T_100MS_START;i <= T_100MS_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearTD(void){//���TD�Ĵ���
	uint16_t i;
	for(i = TD_1MS_START;i <= TD_1MS_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
	for(i = TD_10MS_START;i <= TD_10MS_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
	for(i = TD_100MS_START;i <= TD_100MS_END;i ++){
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
static void clearSPREG(void){//�������Ĵ���
	uint16_t i;
	for(i = SPREG_START;i <= SPREG_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearSPCOIL(){//�����������Ȧ
	uint16_t i;
	for(i = SPCOIL_START;i <= SPCOIL_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void loadNvram(void){//��EPROM������NVRAM
	memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//��ʼ��NVRAM
	setLedEprom(DEBUG_LED_ON);
	epromRead(0, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));//��EPROM�лָ�MR
	setLedEprom(DEBUG_LED_OFF);
	clearEM();
	clearR();
	clearT();
	clearTD();
	clearC();
	clearX();
	clearY();
	clearSPREG();
	clearSPCOIL();
	memcpy(NVRAM1, NVRAM0, (CONFIG_NVRAM_SIZE * 2));
}
static void saveNvram(void){//ǿ�ƽ�NVRAM����EPROM
	DISABLE_INTERRUPT;
	setLedEprom(DEBUG_LED_ON);
	epromWrite(0x0, (uint8_t*)NVRAM0, ((MR_END + 1) * 2));
	setLedEprom(DEBUG_LED_OFF);
	ENABLE_INTERRUPT;
}
static void updataNvram(void){//����NVRAM->EPROM
	data uint8_t *sp0, *sp1;
	data uint16_t i;
	sp0 = (uint8_t*)NVRAM0;
	sp1 = (uint8_t*)NVRAM1;
	for(i = (MR_START * 2);i < ((MR_END + 1) * 2);i ++){//����MR
		if(*(sp0 + i) != *(sp1 + i)){
			setLedEprom(DEBUG_LED_ON);
			epromWriteOneByte(i, *(sp0 + i));
			setLedEprom(DEBUG_LED_OFF);
		}	
	}
	sp0 = (uint8_t*)NVRAM0;
	sp1 = (uint8_t*)NVRAM1;
	for(i = (DM_START * 2);i < ((DM_END + 1) * 2);i ++){//����DM
		if(*(sp0 + i) != *(sp1 + i)){
			setLedEprom(DEBUG_LED_ON);
			epromWriteOneByte(i, *(sp0 + i));
			setLedEprom(DEBUG_LED_OFF);
		}
	}
	memcpy((uint8_t*)NVRAM1, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));
}
static void clearNvram(void){//���NVRAM����	
	idata uint8_t oldEA;
	idata uint16_t i;
	oldEA = EA;//�ر��ж�
	EA = 0;
	wdtDisable();
	for(i = 0; i<= CONFIG_EPROM_SIZE;i ++){
		if(getLedEprom()){
			setLedEprom(DEBUG_LED_OFF);
		}
		else{
			setLedEprom(DEBUG_LED_ON);
		}
		epromWriteOneByte(i, 0x0);
		
	}
	EA = oldEA;//�ָ��ж�
}
static void selfTestNvram(void){//�Լ�NVRAM
	
}
/*****************************************************************************/
//���߼�ָ��
void REBOOT(void) reentrant{//�����λ
	RSTSRC |= 1 << 4;//ǿ�Ƹ�λ
}
void SET(uint16_t A) reentrant{//��Ȧ��λ
	assertCoilAddress(A);//����ַ��Χ
	NVRAM0[(A / 16)] |= 1 << (A % 16);
}
void RES(uint16_t A) reentrant{//��Ȧ����
	assertCoilAddress(A);//����ַ��Χ
	NVRAM0[(A / 16)] &= ~(1 << (A % 16));
}
void FLIP(uint16_t A) reentrant{//��ת
	uint16_t temp;
	assertCoilAddress(A);//����ַ��Χ
	temp= NVRAM0[(A / 16)] & (1 << (A % 16));
	if(temp)
		RES(A);
	else
		SET(A);
}
uint8_t LD(uint16_t A) reentrant{//����
	assertCoilAddress(A);//����ַ��Χ
	return (uint8_t)(NVRAM0[(A / 16)] >> (A % 16)) & 0x01;
}
uint8_t LDB(uint16_t A) reentrant{//��������
	assertCoilAddress(A);//����ַ��Χ
	return !((uint8_t)(NVRAM0[(A / 16)] >> (A % 16)) & 0x01);
}
uint8_t LDP(uint16_t A) reentrant{//����������
	uint8_t temp0, temp1;
	assertCoilAddress(A);//����ַ��Χ
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> (A % 16)) & 0x01;
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> (A % 16)) & 0x01;
	if(temp0 == 1 && temp1 != 1)
		return true;
	else
		return false;
}
uint8_t LDN(uint16_t A) reentrant{//�����½���
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
	idata uint16_t temp;
	idata fp32_t ftemp;
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
	idata uint16_t temp;
	temp = (int16_t)(CONFIG_SPLC_ADC_INTERNAL_VREF * dat / 4096);//��λmV
	temp = (int16_t)((temp - CONFIG_SPLC_ADC_TEMP_SENSOR_OFFSET) * 1000 / CONFIG_SPLC_ADC_TEMP_SENSOR_GAIN);
	return temp;
}
int16_t MAX(int16_t *s, uint8_t len){//�ҳ�����Ϊlen������s�е����ֵ
	idata int16_t max;
	idata uint8_t i;
	max = *s;
	for(i = 0;i < len;i ++){
		if(*(s +i) > max){
			max = *(s + i);
		}
	}
	return max;
}
int16_t MIN(int16_t *s, uint8_t len){//�ҳ�����Ϊlen������s�е���Сֵ
	idata int16_t min;
	idata uint8_t i;
	min = *s;
	for(i = 0;i < len;i ++){
		if(*(s +i) < min){
			min = *(s + i);
		}
	}
	return min;
}
//void ADD(uint16_t idata Sa, uint16_t idata Sb, uint16_t idata D){//16λ��� D = Sa + Sb
//	NVRAM0[D] = NVRAM0[Sa] + NVRAM0[Sb];
//}
void DADD(uint16_t Sa, uint16_t Sb, uint16_t D){//32λ��� D = Sa + Sb
	int32_t *tmp0, *tmp1, *tmp2;
	tmp0 = (int32_t*)(&NVRAM0[Sa]);
	tmp1 = (int32_t*)(&NVRAM0[Sb]);
	tmp2 = (int32_t*)(&NVRAM0[D]);
	*tmp2 = *tmp0 + *tmp1;
}
//void ADDS(uint16_t idata Sa, uint16_t idata Sb, uint16_t idata D){//16λ������� D = Sa + Sb
//	idata int32_t tmp;
//	tmp = NVRAM0[Sa] + NVRAM0[Sb];
//	if(tmp >= SHRT_MAX)
//		tmp = SHRT_MAX;
//	if(tmp <= SHRT_MIN)
//		tmp = SHRT_MIN;
//	NVRAM0[D] = tmp;
//}
//void SUB(uint16_t Sa, uint16_t Sb, uint16_t D){//16λ�Ǳ��ͼ��� D = Sa - Sb
//	NVRAM0[D] = NVRAM0[Sa] - NVRAM0[Sb];
//}
//void SUBS(uint16_t idata Sa, uint16_t idata Sb, uint16_t idata D){//16λ���ͼ��� D = Sa - Sb
//	idata int32_t tmp;
//	tmp = NVRAM0[Sa] - NVRAM0[Sb];
//	if(tmp >= SHRT_MAX)
//		tmp = SHRT_MAX;
//	if(tmp <= SHRT_MIN)
//		tmp = SHRT_MIN;
//	NVRAM0[D] = tmp;
//}
void DSUB(uint16_t Sa, uint16_t Sb, uint16_t D){//32λ�Ǳ��ͼ��� D = Sa - Sb
	idata int32_t *tmp0, *tmp1, *tmp2;
	tmp0 = (int32_t*)(&NVRAM0[Sa]);
	tmp1 = (int32_t*)(&NVRAM0[Sb]);
	tmp2 = (int32_t*)(&NVRAM0[D]);
	*tmp2 = *tmp0 - *tmp1;
}
/*****************************************************************************/
static void wdtInit(void){//���Ź���ʼ��
	WDTCN = 0x07;//47mS
}
void wdtEnable(void) reentrant{//ʹ�ܿ��Ź�
#ifdef C8051F020
	WDTCN = 0xA5;
#endif
}
void wdtDisable(void) reentrant{//�رտ��Ź�(δ����)
	uint8_t flagEA;
	flagEA = EA;
	EA = 0;
	WDTCN = 0xDE;
    WDTCN = 0xAD;
	EA = flagEA;
}
void wdtFeed(void) reentrant{//ι��
	WDTCN = 0xA5;
}
static void pcaInit(void){//Ӳ��PCA��ʼ��
}
static void timer0Init(void){//Ӳ��sTimer��ʱ����ʼ��
	idata uint16_t temp;
	TimerCounter_1mS = 0;
	TimerCounter_10mS = 0;
	TimerCounter_100mS = 0;
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
}
static void timer0Isr(void) interrupt INTERRUPT_TIMER0{//Ӳ��sTimer��ʱ���ж� 1mS
	idata uint16_t i;
	idata uint32_t tmp;
	TF0 = 0;
	TR0 = 0;
	TH0 = Timer0_H;
	TL0 = Timer0_L;
	TR0 = 1;
	if(LD(SPCOIL_PS1MS)){//ON
		RES(SPCOIL_PS1MS);
	}
	else{//OFF
		SET(SPCOIL_PS1MS);
	}
	for(i = TD_1MS_START;i <= TD_1MS_END;i ++){//1mS��ʱ
		if(NVRAM0[i] < SHRT_MAX){
			NVRAM0[i] ++;
		}
	}
	if(TimerCounter_1mS >= 10){//10mS����
		if(LD(SPCOIL_PS10MS)){//ON
			RES(SPCOIL_PS10MS);
		}
		else{//OFF
			SET(SPCOIL_PS10MS);
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
		if(LD(SPCOIL_PS100MS)){//ON
			RES(SPCOIL_PS100MS);
		}
		else{//OFF
			SET(SPCOIL_PS100MS);
		}
		for(i = TD_100MS_START;i < TD_100MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_100mS ++;
		TimerCounter_10mS = 0;
		setLedRun(LD(SPCOIL_PS100MS));
	}
	if(TimerCounter_100mS >= 10){//1000mS����
		if(LD(SPCOIL_PS1000MS)){//ON
			RES(SPCOIL_PS1000MS);
		}
		else{
			SET(SPCOIL_PS1000MS);
		}
		tmp = 0;
		tmp = NVRAM0[SPREG_RUNTIME_L] + (uint32_t)(NVRAM0[SPREG_RUNTIME_H]) * 65536L;
		tmp += 1;
		NVRAM0[SPREG_RUNTIME_H] = (tmp >> 16) & 0xFFFF;
		NVRAM0[SPREG_RUNTIME_L] = tmp & 0xFFFF;
		TimerCounter_100mS = 0;
	}
#if CONFIG_SPLC_USING_CADC == 1
	chipAdcProcess();//ADCɨ��
#endif
	TimerCounter_1mS ++;
}
static void inputInit(void){//IO�����˲�����ʼ��
	memset(inputFilter, 0x0, (X_END - X_START + 1) * 16);
}
static void outputInit(void){//IO�����ʼ��
#ifdef C8051F020
	
#endif
}
static void inputRefresh(void){//��ȡ����IO
	idata uint8_t ctemp0;
	ctemp0 = ((P6 >> 7) & 0x01);
	if(ctemp0){
		if(inputFilter[0] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[0] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 0);
		}
	}
	else{
		if(inputFilter[0] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[0] --;
		}
		else{
			NVRAM0[X_START] &= ~(uint16_t)(1 << 0);
		}
	}
	ctemp0 = ((P6 >> 6) & 0x01);
	if(ctemp0){
		if(inputFilter[1] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[1] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 1);
		}
	}
	else{
		if(inputFilter[1] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[1] --;
		}
		else{
			NVRAM0[X_START] &= ~(uint16_t)(1 << 1);
		}
	}
}
static void outputRefresh(void){//�������IO
	if((NVRAM0[Y_START] >> 0) & 0x01){//P6_5
		P6 |= (uint8_t)(1 << 5);
	}
	else{
		P6 &= ~(uint8_t)(1 << 5);
	}
	if((NVRAM0[Y_START] >> 1) & 0x01){//P6_4
		P6 |= (uint8_t)(1 << 4);
	}
	else{
		P6 &= ~(uint8_t)(1 << 4);
	}
}
void sPlcInit(void){//���߼���ʼ��
	setLedError(DEBUG_LED_OFF);
	setLedRun(DEBUG_LED_OFF);
	setLedDac(DEBUG_LED_OFF);
	setLedEprom(DEBUG_LED_OFF);
	wdtInit();//���Ź�ʹ��
	wdtDisable();//���ο��Ź�
#if CONFIG_SPLC_USING_UART1 == 1
	initUart1(CONFIG_UART1_BAUDRATE);//UART1��ʼ��
#endif	
#if CONFIG_SPLC_USING_EPROM == 1
	loadNvram();//�ϵ�ָ�NVRAM
#endif
#if CONFIG_SPLC_USING_CADC == 1
	initChipAdc();//��ʼ��ADCģ��
#endif
#if CONFIG_SPLC_USING_DAC == 1
	initChipDac();//��ʼ��DACģ��
#endif
#if CONFIG_SPLC_USING_MB_RTU_SLAVE == 1
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
#endif
	timer0Init();//��ʼ��Ӳ����ʱ��ģ��
	SET(SPCOIL_ON);
	setLedError(DEBUG_LED_OFF);
	SET(SPCOIL_ON);
	SET(SPCOIL_START_UP);
	NVRAM0[EM_END] = CONFIG_SPLC_DEV;
}
void sPlcProcessStart(void){//sPLC��ѯ��ʼ
#if CONFIG_SPLC_USING_CLEAR_NVRAM == 1
	if(NVRAM0[SPREG_CLEAR_NVRAM0] == CONFIG_SPLC_CLEAR_CODE){
		DISABLE_INTERRUPT;//�ر��ж�
		setLedRun(DEBUG_LED_ON);//
		setLedEprom(DEBUG_LED_ON);
		if(epromTest()){//EPROM���Գɹ�
			setLedEprom(DEBUG_LED_OFF);
			setLedError(DEBUG_LED_ON);
			delayMs(500);
			setLedError(DEBUG_LED_OFF);
		}
		else{//EPROM����ʧ��
			setLedEprom(DEBUG_LED_OFF);
			setLedError(DEBUG_LED_ON);
			delayMs(500);
			setLedError(DEBUG_LED_OFF);
			delayMs(500);
			setLedError(DEBUG_LED_ON);
			delayMs(500);
			setLedError(DEBUG_LED_OFF);
			delayMs(500);
			setLedError(DEBUG_LED_ON);
			delayMs(500);
			setLedError(DEBUG_LED_OFF);	
		}
		clearNvram();
		REBOOT();	
	}
#endif
#if CONFIG_SPLC_USING_WDT == 1
	wdtFeed();//ι��
#endif
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
	updataNvram();//����NVRAM
#endif
#if CONFIG_SPLC_USING_WDT == 1
	wdtFeed();//ι��
#endif
	RES(SPCOIL_START_UP);
}