#include "sPlc.h"
/*****************************************************************************/
xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��ǰ
xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//���籣�ּĴ��� ��һ��
#if (CONFIG_SPLC_USING_UART0 == 1 && CONFIG_MB_PORT != UART0)
xdata uint8_t volatile UART0_TXBUF[CONFIG_UART0_RBUF_SIZE];//UART0���ͻ���
xdata uint8_t volatile UART0_RXBUF[CONFIG_UART0_TBUF_SIZE];//UART0���ջ���
#endif
#if (CONFIG_SPLC_USING_UART1 == 1 && CONFIG_MB_PORT != UART1)
xdata uint8_t volatile UART1_TXBUF[CONFIG_UART1_RBUF_SIZE];//UART1���ͻ���
xdata uint8_t volatile UART1_RXBUF[CONFIG_UART1_TBUF_SIZE];//UART1���ջ���
#endif
idata volatile uint8_t TimerCounter_1mS = 0;
idata volatile uint8_t TimerCounter_10mS = 0;
idata volatile uint8_t TimerCounter_100mS = 0;
/******************************************************************************/
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
void clearC(void){//���C�Ĵ���
	uint16_t i;
	for(i = C_START;i <= C_END;i ++){
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
void clearSPCOIL(){//�����������Ȧ
	uint16_t i;
	for(i = SPCOIL_START;i <= SPCOIL_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void loadNvram(void){//��EPROM������NVRAM
	enterSplcIsr();
	memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//��ʼ��NVRAM
#if CONFIG_SPLC_USING_LED == 1
	setLedEprom(true);
#endif
#if CONFIG_SPLC_USING_EPROM == 1
	epromRead(0, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));//��EPROM�лָ�MR
#endif
#if CONFIG_SPLC_USING_LED == 1
	setLedEprom(false);
#endif
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
	exitSplcIsr();
}
static void saveNvram(void){//ǿ�ƽ�NVRAM����EPROM
	enterSplcIsr();
#if CONFIG_SPLC_USING_LED == 1
	setLedEprom(true);
#endif
#if CONFIG_SPLC_USING_EPROM == 1
	epromWrite(0x0, (uint8_t*)NVRAM0, ((MR_END + 1) * 2));
#endif
#if CONFIG_SPLC_USING_LED == 1
	setLedEprom(false);
#endif
	exitSplcIsr();
}
static void updataNvram(void){//����NVRAM->EPROM
	data uint8_t *sp0, *sp1;
	data uint16_t i;
	sp0 = (uint8_t*)NVRAM0;
	sp1 = (uint8_t*)NVRAM1;
	for(i = (MR_START * 2);i < ((MR_END + 1) * 2);i ++){//����MR
		if(*(sp0 + i) != *(sp1 + i)){
#if CONFIG_SPLC_USING_LED == 1
			setLedEprom(true);
#endif
#if CONFIG_SPLC_USING_EPROM == 1
			epromWriteOneByte(i, *(sp0 + i));
#endif
#if CONFIG_SPLC_USING_LED == 1
			setLedEprom(false);
#endif
		}	
	}

	for(i = (DM_START * 2);i < ((DM_END + 1) * 2);i ++){//����DM
		if(*(sp0 + i) != *(sp1 + i)){
#if CONFIG_SPLC_USING_LED == 1
			setLedEprom(true);
#endif
#if CONFIG_SPLC_USING_EPROM == 1
			epromWriteOneByte(i, *(sp0 + i));
#endif
#if CONFIG_SPLC_USING_LED == 1
			setLedEprom(false);
#endif
		}
	}
	memcpy((uint8_t*)NVRAM1, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));
}
static void clearNvram(void){//���NVRAM����	
	idata uint16_t i = 0;
	enterSplcIsr();
	disableWatchDog();
#if CONFIG_SPLC_USING_EPROM == 1
	for(i = 0; i<= CONFIG_EPROM_SIZE;i ++){
#if CONFIG_SPLC_USING_LED == 1
		setLedEprom(true);
#endif
		epromWriteOneByte(i, 0x0);
#if CONFIG_SPLC_USING_LED == 1
		setLedEprom(false);
#endif
	}
#endif
	exitSplcIsr();//�ָ��ж�
}
/*****************************************************************************/
void sPlcInit(void){//���߼���ʼ��
	sPlcSimEpromInit();
#if CONFIG_SPLC_USING_LED == 1	
	setLedError(false);
	setLedRun(false);
	setLedDac(false);
	setLedAdc(false);
	setLedEprom(false);
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
	initSplcTimer();//��ʼ��Ӳ����ʱ��ģ��
	SET(SPCOIL_ON);
#if CONFIG_SPLC_USING_LED == 1	
	setLedError(false);
#endif
	SET(SPCOIL_ON);
	SET(SPCOIL_START_UP);
	NVRAM0[EM_END] = CONFIG_SPLC_DEV;
#if CONFIG_USING_RTU_SLAVE == 1	
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
#endif
#if CONFIG_USING_USB == 1
	usbSpiInit();//��ʼ�� USB SPI	
	mStopIfError(usbHostInit());//Ĭ�ϳ�ʼ��ΪHOST
#endif
	ENABLE_INTERRUPT;
}
void sPlcProcessStart(void){//sPLC��ѯ��ʼ
#if CONFIG_SPLC_USING_CLEAR_NVRAM == 1
	if(NVRAM0[SPREG_CLEAR_NVRAM0] == CONFIG_SPLC_CLEAR_CODE){
		DISABLE_INTERRUPT;//�ر��ж�
#if CONFIG_SPLC_USING_LED == 1	
		setLedRun(true);//
		setLedEprom(true);
#endif
		if(epromTest()){//EPROM���Գɹ�
#if CONFIG_SPLC_USING_LED == 1			
			setLedEprom(false);
			setLedError(true);
			delayMs(10);
			setLedError(false);
#endif
		}
		else{//EPROM����ʧ��
#if CONFIG_SPLC_USING_LED == 1
			setLedEprom(false);
			setLedError(true);
			delayMs(50);
			setLedError(false);
			delayMs(50);
			setLedError(true);
			delayMs(50);
			setLedError(false);
			delayMs(50);
			setLedError(true);
			delayMs(50);
			setLedError(false);	
#endif
		}
		clearNvram();
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
#if CONFIG_SPLC_USING_DAC
	refreshChipDac();//����DAC���
#endif
	updataNvram();//����NVRAM
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//ι��
#endif
	RES(SPCOIL_START_UP);
#if CONFIG_USING_HMI == 1
	hmiLoop();
#endif
#if CONFIG_USING_USB == 1
	sPlcUsbPoll();
#endif
}