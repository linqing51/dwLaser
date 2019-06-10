#include "sPlc.h"
/*****************************************************************************/
int16_t NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
int16_t NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
uint8_t TimerCounter_1mS = 0;
uint8_t TimerCounter_10mS = 0;
uint8_t TimerCounter_100mS = 0;
uint8_t TD_1MS_SP = 0;
uint8_t TD_10MS_SP = 0;
uint8_t TD_100MS_SP = 0;
uint8_t TD_1000MS_SP = 0;
/******************************************************************************/
void assertCoilAddress(uint16_t adr) reentrant{//�����Ȧ��ַ
#if CONFIG_SPLC_ASSERT == 1
	uint16_t maxCoilAdr = CONFIG_NVRAM_SIZE * 16 - 1;
	if(adr > (maxCoilAdr)){
		while(1);
	}
#else
	adr = ~adr;
#endif
}
void assertRegisterAddress(uint16_t adr) reentrant{//���Ĵ�����ַ
#if CONFIG_SPLC_ASSERT == 1
	if(adr > (CONFIG_NVRAM_SIZE - 1)){
		while(1);
	}
#else
	adr = ~adr;
#endif
}
/*****************************************************************************/
void clearDM(void){//���DM�Ĵ���
	uint16_t i;
	for(i = 0;i <= DM_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearMR(void){//���MR�Ĵ���
	uint16_t i;
	for(i = MR_START;i <= MR_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearEM(void){//���EM�Ĵ���
	uint16_t i;
	for(i = EM_START;i <= EM_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearR(void){//���R�Ĵ���
	uint16_t i;
	for(i = R_START;i <= R_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearT(void){//���T�Ĵ���
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
void clearTD(void){//���TD�Ĵ���
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
void clearX(void){//���X�Ĵ���
	uint16_t i;
	for(i = X_START;i <= X_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearY(void){//���Y�Ĵ���
	uint16_t i;
	for(i = Y_START;i <= Y_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearSPREG(void){//�������Ĵ���
	uint16_t i;
	for(i = SPREG_START;i <= SPREG_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearSPCOIL(void){//�����������Ȧ
	uint16_t i;
	for(i = SPCOIL_START;i <= SPCOIL_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearTENA(void){//�����ʱ��ʹ����Ȧ
	uint16_t i;
	for(i = T_1MS_ENA_START;i <= T_100MS_ENA_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void loadNvram(void){//��EPROM������NVRAM
	enterSplcIsr();
	memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//��ʼ��NVRAM
#if CONFIG_SPLC_USING_EPROM == 1
	setLedEprom(true);
	epromRead(0, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));//��EPROM�лָ�MR
	setLedEprom(false);
#endif
	clearEM();
	clearR();
	clearT();
	clearTD();
	clearX();
	clearY();
	clearSPREG();
	clearSPCOIL();
	clearTENA();
	memcpy(NVRAM1, NVRAM0, (CONFIG_NVRAM_SIZE * 2));
	exitSplcIsr();
	SET(SPCOIL_SI7060_INIT_FAIL);
	SET(SPCOIL_MCP79412_INIT_FAIL);				
	SET(SPCOIL_CH376_INIT_FAIL);					
	SET(SPCOIL_SPI_FLASH_INIT_FAIL);				
	SET(SPCOIL_DK25L_INIT_FAIL);				
	SET(SPCOIL_NRF24L01_INIT_FAIL);		
	SET(SPCOIL_LASER_DRIVER_INIT_FAIL);				
	SET(SPCOIL_SAFETY_INTERLOCK_INIT_FAIL);
	SET(SPCOIL_WIRE_FOOTCONTROL_INIT_FAIL);	
	SET(SPCOIL_WIRELESS_FOOTCONTROL_INIT_FAIL);
	SET(SPCOIL_PROBATION_INIT_FAIL);
}
static void saveNvram(void){//ǿ�ƽ�NVRAM����EPROM
	enterSplcIsr();
#if CONFIG_SPLC_USING_EPROM == 1
	setLedEprom(true);
	epromWrite(0x0, (uint8_t*)NVRAM0, ((MR_END + 1) * 2));
	setLedEprom(false);
#endif
	exitSplcIsr();
}
void updataNvram(void){//����NVRAM->EPROM
	uint8_t *sp0, *sp1;
	uint16_t i;
	sp0 = (uint8_t*)NVRAM0;
	sp1 = (uint8_t*)NVRAM1;
	for(i = (MR_START * 2);i < ((MR_END + 1) * 2);i ++){//����MR
		if(*(sp0 + i) != *(sp1 + i)){
#if CONFIG_SPLC_USING_EPROM == 1
			setLedEprom(true);
			epromWriteOneByte(i, *(sp0 + i));
			setLedEprom(false);
#endif
		}	
	}
	for(i = (DM_START * 2);i < ((DM_END + 1) * 2);i ++){//����DM
		if(*(sp0 + i) != *(sp1 + i)){
#if CONFIG_SPLC_USING_EPROM == 1
			setLedEprom(true);
			epromWriteOneByte(i, *(sp0 + i));
			setLedEprom(false);
#endif
		}
	}
	memcpy((uint8_t*)NVRAM1, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));
}
void clearNvram(void){//���NVRAM����	
	uint16_t i = 0;
	enterSplcIsr();
	disableWatchDog();
#if CONFIG_SPLC_USING_EPROM == 1
	for(i = 0; i<= CONFIG_EPROM_SIZE;i ++){
		setLedEprom(true);
		epromWriteOneByte(i, 0x0);
		setLedEprom(false);
	}
#endif
	exitSplcIsr();//�ָ��ж�
}
void sPlcSpwmLoop(void){//SPWM��ѯ	
	if(LDP(SPCOIL_PS10MS)){//ÿ10mSִ��һ��
		//SPWM0
		if(LD(SPCOIL_SPWM_RESET_0)){//��λ
			NVRAM0[SPREG_SPWM_COUNTER_0] = SHRT_MAX;
			RES(SPCOIL_SPWM_RESET_0);
		}
		if(NVRAM0[SPREG_SPWM_COUNTER_0] == NVRAM0[SPREG_SPWM_POS_SHADOW_0]){//����ƥ�䷭ת���
			NVRAM0[SPREG_SPWM_COUNTER_0] = NVRAM0[SPREG_SPWM_COUNTER_0] + 1;
			RES(SPCOIL_SPWM_OUT_0);
		}
		else if(NVRAM0[SPREG_SPWM_COUNTER_0] >= NVRAM0[SPREG_SPWM_CYCLE_SHADOW_0]){//�������
			NVRAM0[SPREG_SPWM_COUNTER_0] = 0;
			NVRAM0[SPREG_SPWM_POS_SHADOW_0] = NVRAM0[SPREG_SPWM_POS_0];
			NVRAM0[SPREG_SPWM_CYCLE_SHADOW_0] = NVRAM0[SPREG_SPWM_CYCLE_0];
			SET(SPCOIL_SPWM_OUT_0);
		}
		else{
			NVRAM0[SPREG_SPWM_COUNTER_0] = NVRAM0[SPREG_SPWM_COUNTER_0] + 1;
		}
		//SPWM1
		if(LD(SPCOIL_SPWM_RESET_1)){//��λ
			NVRAM0[SPREG_SPWM_COUNTER_1] = SHRT_MAX;
			RES(SPCOIL_SPWM_RESET_1);
		}
		if(NVRAM0[SPREG_SPWM_COUNTER_1] == NVRAM0[SPREG_SPWM_POS_SHADOW_1]){//����ƥ�䷭ת���
			NVRAM0[SPREG_SPWM_COUNTER_1] = NVRAM0[SPREG_SPWM_COUNTER_1] + 1;
			RES(SPCOIL_SPWM_OUT_1);
		}
		else if(NVRAM0[SPREG_SPWM_COUNTER_1] >= NVRAM0[SPREG_SPWM_CYCLE_SHADOW_1]){//�������
			NVRAM0[SPREG_SPWM_COUNTER_1] = 0;
			NVRAM0[SPREG_SPWM_POS_SHADOW_1] = NVRAM0[SPREG_SPWM_POS_1];
			NVRAM0[SPREG_SPWM_CYCLE_SHADOW_1] = NVRAM0[SPREG_SPWM_CYCLE_1];
			SET(SPCOIL_SPWM_OUT_1);
		}
		else{
			NVRAM0[SPREG_SPWM_COUNTER_1] = NVRAM0[SPREG_SPWM_COUNTER_1] + 1;
		}
		//SPWM2
		if(LD(SPCOIL_SPWM_RESET_2)){//��λ
			NVRAM0[SPREG_SPWM_COUNTER_2] = SHRT_MAX;
			RES(SPCOIL_SPWM_RESET_2);
		}
		if(NVRAM0[SPREG_SPWM_COUNTER_2] == NVRAM0[SPREG_SPWM_POS_SHADOW_2]){//����ƥ�䷭ת���
			NVRAM0[SPREG_SPWM_COUNTER_2] = NVRAM0[SPREG_SPWM_COUNTER_2] + 1;
			RES(SPCOIL_SPWM_OUT_2);
		}
		else if(NVRAM0[SPREG_SPWM_COUNTER_2] >= NVRAM0[SPREG_SPWM_CYCLE_SHADOW_2]){//�������
			NVRAM0[SPREG_SPWM_COUNTER_2] = 0;
			NVRAM0[SPREG_SPWM_POS_SHADOW_2] = NVRAM0[SPREG_SPWM_POS_2];
			NVRAM0[SPREG_SPWM_CYCLE_SHADOW_2] = NVRAM0[SPREG_SPWM_CYCLE_2];
			SET(SPCOIL_SPWM_OUT_2);
		}
		else{
			NVRAM0[SPREG_SPWM_COUNTER_2] = NVRAM0[SPREG_SPWM_COUNTER_2] + 1;
		}
		//SPWM3
		if(LD(SPCOIL_SPWM_RESET_3)){//��λ
			NVRAM0[SPREG_SPWM_COUNTER_3] = SHRT_MAX;
			RES(SPCOIL_SPWM_RESET_3);
		}
		if(NVRAM0[SPREG_SPWM_COUNTER_3] == NVRAM0[SPREG_SPWM_POS_SHADOW_3]){//����ƥ�䷭ת���
			NVRAM0[SPREG_SPWM_COUNTER_3] = NVRAM0[SPREG_SPWM_COUNTER_3] + 1;
			RES(SPCOIL_SPWM_OUT_3);
		}
		else if(NVRAM0[SPREG_SPWM_COUNTER_3] >= NVRAM0[SPREG_SPWM_CYCLE_SHADOW_3]){//�������
			NVRAM0[SPREG_SPWM_COUNTER_3] = 0;
			NVRAM0[SPREG_SPWM_POS_SHADOW_3] = NVRAM0[SPREG_SPWM_POS_3];
			NVRAM0[SPREG_SPWM_CYCLE_SHADOW_3] = NVRAM0[SPREG_SPWM_CYCLE_3];
			SET(SPCOIL_SPWM_OUT_3);
		}
		else{
			NVRAM0[SPREG_SPWM_COUNTER_3] = NVRAM0[SPREG_SPWM_COUNTER_3] + 1;
		}
	}
}
/*****************************************************************************/
void sPlcInit(void){//���߼���ʼ��
	setLedRun(false);
	setLedError(false);
	setLedEprom(false);
	setLedRun(true);
	setLedError(true);
	setLedEprom(true);
	delayMs(100);
	setLedRun(false);
	setLedError(false);
	setLedRun(false);
	delayMs(100);
	setLedRun(true);
	setLedError(true);
	setLedEprom(true);
	delayMs(100);
	setLedError(false);
	setLedEprom(false);
#if CONFIG_USING_SI7060 == 1
	si7060Init();
#endif
	initSplcTimer();//��ʼ��Ӳ����ʱ��ģ��
	SET(SPCOIL_ON);
#if CONFIG_SPLC_USING_IO_INPUT == 1
	inputInit();
#endif
#if CONFIG_SPLC_USING_IO_OUTPUT == 1
	outputInit();
#endif
#if CONFIG_SPLC_USING_WDT == 1
	checkWatchDog();//��鿴�Ź�״̬
	initWatchDog();//���Ź�ʹ��
	disableWatchDog();//���ο��Ź�
#endif
#if CONFIG_SPLC_USING_UART0 == 1
	initUart0(CONFIG_UART0_BAUDRATE);//UART1��ʼ��
#endif
#if CONFIG_SPLC_USING_UART1 == 1
	initUart1(CONFIG_UART1_BAUDRATE);//UART1��ʼ��
#endif	
	loadNvram();//�ϵ�ָ�NVRAM
#if CONFIG_SPLC_USING_ADC == 1
	initChipAdc();//��ʼ��ADCģ��
#endif
#if CONFIG_SPLC_USING_DAC == 1
	initChipDac();//��ʼ��DACģ��
#endif
#if CONFIG_SPLC_USING_PCA == 1
	sPlcPcaInit();
#endif
#if CONFIG_SPLC_USING_LASER_TIMER == 1
	sPlcLaserInit();
#endif
	SET(SPCOIL_ON);
	SET(SPCOIL_START_UP);
	NVRAM0[SPREG_IDENTITY] = CONFIG_SPLC_DEV;
#if CONFIG_USING_RTU_SLAVE == 1	
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
#endif
#if CONFIG_SPLC_USING_CH376 == 1
	usbSpiInit();//��ʼ�� USB SPI	
	mStopIfError(usbHostInit());//Ĭ�ϳ�ʼ��ΪHOST
#endif
	enableSplcIsr();
#if CONFIG_SPLC_USING_DK25L == 1
	DL25L_Init();//���жϺ�����
#endif
}
void sPlcProcessStart(void){//sPLC��ѯ��ʼ
	if(TD_1MS_SP >= 1){
		FLIP(SPCOIL_PS1MS);
		TD_1MS_SP = 0;
	}
	if(TD_10MS_SP >= 1){
		FLIP(SPCOIL_PS10MS);
		TD_10MS_SP = 0;
	}
	if(TD_100MS_SP >= 1){
		FLIP(SPCOIL_PS100MS);
		TD_100MS_SP = 0;
	}
	if(TD_1000MS_SP >= 1){
		FLIP(SPCOIL_PS1000MS);
		TD_1000MS_SP = 0;
	}
	if(LD(SPCOIL_PS1000MS)){
		setLedRun(true);
	}
	else{
		setLedRun(false);
	}
#if CONFIG_SPLC_USING_CLEAR_NVRAM == 1 && CONFIG_SPLC_USING_EPROM == 1
	if(NVRAM0[SPREG_CLEAR_NVRAM] == CONFIG_SPLC_CLEAR_CODE){
		disableSplcIsr();//�ر��ж�	
		setLedRun(true);//
		setLedEprom(true);
		if(epromTest()){//EPROM���Գɹ�
			setLedEprom(false);
			setLedError(true);
			delayMs(10);
			setLedError(false);
		}
		else{//EPROM����ʧ��
		}
		clearNvram();
		//���NVRAM0��NVRAM1
		memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//��ʼ��NVRAM
		memset(NVRAM1, 0x0, (CONFIG_NVRAM_SIZE * 2));//��ʼ��NVRAM
		REBOOT();	
	}
#endif
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//ι��
#endif
#if CONFIG_USING_RTU_SLAVE == 1
	modbusPorcess();//����MODBUS
#endif
#if CONFIG_SPLC_USING_IO_INPUT == 1
	inputRefresh();//��ȡX������
#endif
#if CONFIG_SPLC_USING_SPWM == 1
	sPlcSpwmLoop();
#endif
#if CONFIG_SPLC_USING_PCA == 1	
	sPlcBeemLoop();	
	sPlcAimLoop();
#endif
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();
#endif
}
void sPlcProcessEnd(void){//sPLC��ѯ����
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//ι��
#endif
#if CONFIG_SPLC_USING_IO_OUTPUT == 1
	outputRefresh();//����Y�����
#endif
#if CONFIG_SPLC_USING_DAC == 1
	refreshChipDac();//����DAC���
#endif
#if CONFIG_SPLC_USING_CH376 == 1
	//sPlcUsbPoll();
#endif
	updataNvram();//����NVRAM
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//ι��
#endif
	RES(SPCOIL_START_UP);
}