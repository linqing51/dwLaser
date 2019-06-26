#include "sPlc.h"
/*****************************************************************************/
int16_t NVRAM0[CONFIG_NVRAM_SIZE];//掉电保持寄存器 当前
int16_t NVRAM1[CONFIG_NVRAM_SIZE];//掉电保持寄存器 上一次
uint8_t TimerCounter_1mS = 0;
uint8_t TimerCounter_10mS = 0;
uint8_t TimerCounter_100mS = 0;
uint8_t TD_1MS_SP = 0;
uint8_t TD_10MS_SP = 0;
uint8_t TD_100MS_SP = 0;
uint8_t TD_1000MS_SP = 0;
/******************************************************************************/
void assertCoilAddress(uint16_t adr) reentrant{//检查线圈地址
#if CONFIG_SPLC_ASSERT == 1
	uint16_t maxCoilAdr = CONFIG_NVRAM_SIZE * 16 - 1;
	if(adr > (maxCoilAdr)){
		while(1);
	}
#else
	adr = ~adr;
#endif
}
void assertRegisterAddress(uint16_t adr) reentrant{//检查寄存器地址
#if CONFIG_SPLC_ASSERT == 1
	if(adr > (CONFIG_NVRAM_SIZE - 1)){
		while(1);
	}
#else
	adr = ~adr;
#endif
}
/*****************************************************************************/
void clearDM(void){//清除DM寄存器
	uint16_t i;
	for(i = 0;i <= DM_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearMR(void){//清除MR寄存器
	uint16_t i;
	for(i = MR_START;i <= MR_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearEM(void){//清除EM寄存器
	uint16_t i;
	for(i = EM_START;i <= EM_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearR(void){//清除R寄存器
	uint16_t i;
	for(i = R_START;i <= R_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearT(void){//清除T寄存器
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
void clearTD(void){//清除TD寄存器
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
void clearX(void){//清除X寄存器
	uint16_t i;
	for(i = X_START;i <= X_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearY(void){//清除Y寄存器
	uint16_t i;
	for(i = Y_START;i <= Y_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearSPREG(void){//清除特殊寄存器
	uint16_t i;
	for(i = SPREG_START;i <= SPREG_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearSPCOIL(void){//清除特特殊线圈
	uint16_t i;
	for(i = SPCOIL_START;i <= SPCOIL_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearTENA(void){//清楚计时器使能线圈
	uint16_t i;
	for(i = T_1MS_ENA_START;i <= T_100MS_ENA_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void loadNvram(void){//从EPROM中载入NVRAM
	enterSplcIsr();
	memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//初始化NVRAM
#if CONFIG_SPLC_USING_EPROM == 1
	setLedEprom(true);
	epromRead(0, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));//从EPROM中恢复MR
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
	SET(SPCOIL_WIRELESS_FOOTCONTROL_INIT_FAIL);
	SET(SPCOIL_PROBATION_INIT_FAIL);
}
static void saveNvram(void){//强制将NVRAM存入EPROM
	enterSplcIsr();
#if CONFIG_SPLC_USING_EPROM == 1
	setLedEprom(true);
	epromWrite(0x0, (uint8_t*)NVRAM0, ((MR_END + 1) * 2));
	setLedEprom(false);
#endif
	exitSplcIsr();
}
void updataNvram(void){//更新NVRAM->EPROM
	uint8_t *sp0, *sp1;
	uint16_t i;
	sp0 = (uint8_t*)NVRAM0;
	sp1 = (uint8_t*)NVRAM1;
	for(i = (MR_START * 2);i < ((MR_END + 1) * 2);i ++){//储存MR
		if(*(sp0 + i) != *(sp1 + i)){
#if CONFIG_SPLC_USING_EPROM == 1
			setLedEprom(true);
			epromWriteOneByte(i, *(sp0 + i));
			setLedEprom(false);
#endif
		}	
	}
	for(i = (DM_START * 2);i < ((DM_END + 1) * 2);i ++){//储存DM
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
void clearNvram(void){//清除NVRAM数据	
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
	exitSplcIsr();//恢复中断
}
void sPlcSpwmLoop(void){//SPWM轮询	
	if(LDP(SPCOIL_PS10MS)){//每10mS执行一次
		//SPWM0
		if(LD(SPCOIL_SPWM_RESET_0)){//复位
			NVRAM0[SPREG_SPWM_COUNTER_0] = SHRT_MAX;
			RES(SPCOIL_SPWM_RESET_0);
		}
		if(NVRAM0[SPREG_SPWM_COUNTER_0] == NVRAM0[SPREG_SPWM_POS_SHADOW_0]){//发生匹配翻转输出
			NVRAM0[SPREG_SPWM_COUNTER_0] = NVRAM0[SPREG_SPWM_COUNTER_0] + 1;
			RES(SPCOIL_SPWM_OUT_0);
		}
		else if(NVRAM0[SPREG_SPWM_COUNTER_0] >= NVRAM0[SPREG_SPWM_CYCLE_SHADOW_0]){//发生溢出
			NVRAM0[SPREG_SPWM_COUNTER_0] = 0;
			NVRAM0[SPREG_SPWM_POS_SHADOW_0] = NVRAM0[SPREG_SPWM_POS_0];
			NVRAM0[SPREG_SPWM_CYCLE_SHADOW_0] = NVRAM0[SPREG_SPWM_CYCLE_0];
			SET(SPCOIL_SPWM_OUT_0);
		}
		else{
			NVRAM0[SPREG_SPWM_COUNTER_0] = NVRAM0[SPREG_SPWM_COUNTER_0] + 1;
		}
		//SPWM1
		if(LD(SPCOIL_SPWM_RESET_1)){//复位
			NVRAM0[SPREG_SPWM_COUNTER_1] = SHRT_MAX;
			RES(SPCOIL_SPWM_RESET_1);
		}
		if(NVRAM0[SPREG_SPWM_COUNTER_1] == NVRAM0[SPREG_SPWM_POS_SHADOW_1]){//发生匹配翻转输出
			NVRAM0[SPREG_SPWM_COUNTER_1] = NVRAM0[SPREG_SPWM_COUNTER_1] + 1;
			RES(SPCOIL_SPWM_OUT_1);
		}
		else if(NVRAM0[SPREG_SPWM_COUNTER_1] >= NVRAM0[SPREG_SPWM_CYCLE_SHADOW_1]){//发生溢出
			NVRAM0[SPREG_SPWM_COUNTER_1] = 0;
			NVRAM0[SPREG_SPWM_POS_SHADOW_1] = NVRAM0[SPREG_SPWM_POS_1];
			NVRAM0[SPREG_SPWM_CYCLE_SHADOW_1] = NVRAM0[SPREG_SPWM_CYCLE_1];
			SET(SPCOIL_SPWM_OUT_1);
		}
		else{
			NVRAM0[SPREG_SPWM_COUNTER_1] = NVRAM0[SPREG_SPWM_COUNTER_1] + 1;
		}
		//SPWM2
		if(LD(SPCOIL_SPWM_RESET_2)){//复位
			NVRAM0[SPREG_SPWM_COUNTER_2] = SHRT_MAX;
			RES(SPCOIL_SPWM_RESET_2);
		}
		if(NVRAM0[SPREG_SPWM_COUNTER_2] == NVRAM0[SPREG_SPWM_POS_SHADOW_2]){//发生匹配翻转输出
			NVRAM0[SPREG_SPWM_COUNTER_2] = NVRAM0[SPREG_SPWM_COUNTER_2] + 1;
			RES(SPCOIL_SPWM_OUT_2);
		}
		else if(NVRAM0[SPREG_SPWM_COUNTER_2] >= NVRAM0[SPREG_SPWM_CYCLE_SHADOW_2]){//发生溢出
			NVRAM0[SPREG_SPWM_COUNTER_2] = 0;
			NVRAM0[SPREG_SPWM_POS_SHADOW_2] = NVRAM0[SPREG_SPWM_POS_2];
			NVRAM0[SPREG_SPWM_CYCLE_SHADOW_2] = NVRAM0[SPREG_SPWM_CYCLE_2];
			SET(SPCOIL_SPWM_OUT_2);
		}
		else{
			NVRAM0[SPREG_SPWM_COUNTER_2] = NVRAM0[SPREG_SPWM_COUNTER_2] + 1;
		}
		//SPWM3
		if(LD(SPCOIL_SPWM_RESET_3)){//复位
			NVRAM0[SPREG_SPWM_COUNTER_3] = SHRT_MAX;
			RES(SPCOIL_SPWM_RESET_3);
		}
		if(NVRAM0[SPREG_SPWM_COUNTER_3] == NVRAM0[SPREG_SPWM_POS_SHADOW_3]){//发生匹配翻转输出
			NVRAM0[SPREG_SPWM_COUNTER_3] = NVRAM0[SPREG_SPWM_COUNTER_3] + 1;
			RES(SPCOIL_SPWM_OUT_3);
		}
		else if(NVRAM0[SPREG_SPWM_COUNTER_3] >= NVRAM0[SPREG_SPWM_CYCLE_SHADOW_3]){//发生溢出
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
void sPlcInit(void){//软逻辑初始化
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
	//si7060Init();
	initSplcTimer();//初始化硬件计时器模块
	SET(SPCOIL_ON);
	inputInit();
	outputInit();
	//checkWatchDog();//检查看门狗状态
	initWatchDog();//看门狗使能
	disableWatchDog();//屏蔽看门狗
	initUart0(CONFIG_UART0_BAUDRATE);//UART1初始化
	initUart1(CONFIG_UART1_BAUDRATE);//UART1初始化	
	loadNvram();//上电恢复NVRAM
	initChipAdc();//初始化ADC模块
	initChipDac();//初始化DAC模块
	sPlcPcaInit();
	sPlcLaserInit();
	SET(SPCOIL_ON);
	SET(SPCOIL_START_UP);
	NVRAM0[SPREG_IDENTITY] = CONFIG_SPLC_DEV;
#if CONFIG_USING_RTU_SLAVE == 1	
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
#endif
#if CONFIG_SPLC_USING_CH376 == 1
	usbSpiInit();//初始化 USB SPI	
	mStopIfError(usbHostInit());//默认初始化为HOST
#endif
	enableSplcIsr();
#if CONFIG_SPLC_USING_DK25L == 1
	DL25L_Init();//打开中断后运行
#endif
}
void sPlcProcessStart(void){//sPLC轮询起始
	if(TD_1MS_SP >= 1){
#if CONFIG_SPLC_USING_PCA == 1	
		sPlcBeemLoop();	
		sPlcAimLoop();
#endif
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
		disableSplcIsr();//关闭中断	
		setLedRun(true);//
		setLedEprom(true);
		if(epromTest()){//EPROM测试成功
			setLedEprom(false);
			setLedError(true);
			delayMs(10);
			setLedError(false);
		}
		else{//EPROM测试失败
		}
		clearNvram();
		//清空NVRAM0和NVRAM1
		memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//初始化NVRAM
		memset(NVRAM1, 0x0, (CONFIG_NVRAM_SIZE * 2));//初始化NVRAM
		REBOOT();	
	}
#endif
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//喂狗
#endif
#if CONFIG_USING_RTU_SLAVE == 1
	modbusPorcess();//处理MODBUS
#endif
#if CONFIG_SPLC_USING_IO_INPUT == 1
	inputRefresh();//读取X口输入
#endif
#if CONFIG_SPLC_USING_SPWM == 1
	sPlcSpwmLoop();
#endif
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();
#endif
}
void sPlcProcessEnd(void){//sPLC轮询结束
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//喂狗
#endif
#if CONFIG_SPLC_USING_IO_OUTPUT == 1
	outputRefresh();//更新Y口输出
#endif
#if CONFIG_SPLC_USING_DAC == 1
	refreshChipDac();//更新DAC输出
#endif
#if CONFIG_SPLC_USING_CH376 == 1
	//sPlcUsbPoll();
#endif
	updataNvram();//更新NVRAM
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//喂狗
#endif
	RES(SPCOIL_START_UP);
}