#include "sPlc.h"
/*****************************************************************************/
xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
static idata volatile uint8_t TimerCounter_1mS = 0;
static idata volatile uint8_t TimerCounter_10mS = 0;
static idata volatile uint8_t TimerCounter_100mS = 0;
static idata volatile uint8_t Timer0_L, Timer0_H;
bit debugLed0, debugLed1, debugLed2, debugLed3;
/*****************************************************************************/
static idata volatile int8_t inputFilter[(X_END - X_START + 1) * 16];//IO�����˲���������
/******************************************************************************/
uint8_t getGlobalInterrupt(void){
	return EA;
}
void setLedRun(uint8_t st){//SETLED RUN
	debugLed0 = st;
}
uint8_t getLedRun(void){//GET LED RUN P7_0
	return debugLed0;
}
void setLedEprom(uint8_t st){//SET LED EPROM
	debugLed1 = st;
}
uint8_t getLedEprom(void){//GET LED EPROM
	return debugLed1;
}
void setLedDac(uint8_t st){//SET LED DAC
	debugLed2 = st;
}
uint8_t getLedDac(void){//GET LED DAC
	return debugLed2;
}
void setLedError(uint8_t st){//SET LED ERROR
	debugLed3 = st;
}
uint8_t getLedError(void){//GET LED ERROR
	return debugLed3;
}
void assertCoilAddress(uint16_t adr) reentrant{//�����Ȧ��ַ
#if CONFIG_SPLC_ASSERT == 1
	if(adr > (SPCOIL_END * 16))
		while(1);
#endif
}
void assertRegisterAddress(uint16_t adr) reentrant{//���Ĵ�����ַ
#if CONFIG_SPLC_ASSERT == 1
	if(adr >= SPCOIL_END)
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
#if CONFIG_SPLC_USING_WDT == 1
	if ((RSTSRC & 0x02) == 0x00){
		if(RSTSRC == 0x08){//���WDT���Ź� ���Ź���λ������
			SET(SPCOIL_WATCHDOG);
			setLedError(DEBUG_LED_ON);
			setLedRun(DEBUG_LED_ON);
			setLedDac(DEBUG_LED_OFF);
			setLedEprom(DEBUG_LED_OFF);
			delayMs(100);
		}
	}
#endif
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
/*****************************************************************************/

/*****************************************************************************/
static void wdtInit(void){//���Ź���ʼ��
	uint8_t	SFRPAGE_save = SFRPAGE;
	SFRPAGE = ACTIVE_PAGE;
    PCA0MD    &= ~0x40;
    PCA0MD    = 0x00;
    PCA0CPL5  = 0xFF;
	SFRPAGE = SFRPAGE_save;
}
void wdtEnable(void) reentrant{//ʹ�ܿ��Ź�
	PCA0MD    |= 0x40;
}
void wdtDisable(void) reentrant{//�رտ��Ź�(δ����)
	uint8_t flagEA;
	uint8_t	SFRPAGE_save = SFRPAGE;	
	flagEA = EA;
	EA = 0;
	SFRPAGE = ACTIVE_PAGE;
	PCA0MD &= 0xBF;
	SFRPAGE = SFRPAGE_save;
	EA = flagEA;
}
void wdtFeed(void) reentrant{//ι��
	PCA0CPH5 = 0x00;  
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

void sPlcInit(void){//���߼���ʼ��
#if CONFIG_SPLC_USING_WDT == 1
	if ((RSTSRC & 0x02) == 0x00){
		if(RSTSRC == 0x08)
		{//���WDT���Ź� ���Ź���λ������
			setLedError(DEBUG_LED_ON);
			setLedRun(DEBUG_LED_ON);
			setLedDac(DEBUG_LED_OFF);
			setLedEprom(DEBUG_LED_OFF);
			while(1);
		}
	}
#endif
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
			delayMs(10);
			setLedError(DEBUG_LED_OFF);
		}
		else{//EPROM����ʧ��
			setLedEprom(DEBUG_LED_OFF);
			setLedError(DEBUG_LED_ON);
			delayMs(50);
			setLedError(DEBUG_LED_OFF);
			delayMs(50);
			setLedError(DEBUG_LED_ON);
			delayMs(50);
			setLedError(DEBUG_LED_OFF);
			delayMs(50);
			setLedError(DEBUG_LED_ON);
			delayMs(50);
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