#include "sPlc.h"
/*****************************************************************************/
xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//掉电保持寄存器 当前
xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//掉电保持寄存器 上一次
#if (CONFIG_SPLC_USING_UART0 == 1 && CONFIG_MB_PORT != UART0)
xdata uint8_t volatile UART0_TXBUF[CONFIG_UART0_RBUF_SIZE];//UART0发送缓冲
xdata uint8_t volatile UART0_RXBUF[CONFIG_UART0_TBUF_SIZE];//UART0接收缓冲
#endif
#if (CONFIG_SPLC_USING_UART1 == 1 && CONFIG_MB_PORT != UART1)
xdata uint8_t volatile UART1_TXBUF[CONFIG_UART1_RBUF_SIZE];//UART1发送缓冲
xdata uint8_t volatile UART1_RXBUF[CONFIG_UART1_TBUF_SIZE];//UART1接收缓冲
#endif
idata volatile uint8_t TimerCounter_1mS = 0;
idata volatile uint8_t TimerCounter_10mS = 0;
idata volatile uint8_t TimerCounter_100mS = 0;
/******************************************************************************/
void assertCoilAddress(uint16_t adr) reentrant{//检查线圈地址
#if CONFIG_SPLC_ASSERT == 1
	uint16_t maxCoilAdr = SPCOIL_END * 16;
	if(adr > (maxCoilAdr)){
		while(1);
	}
#endif
}
void assertRegisterAddress(uint16_t adr) reentrant{//检查寄存器地址
#if CONFIG_SPLC_ASSERT == 1
	if(adr > SPCOIL_END){
		while(1);
	}
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
void clearC(void){//清除C寄存器
	uint16_t i;
	for(i = C_START;i <= C_END;i ++){
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
void clearSPCOIL(){//清除特特殊线圈
	uint16_t i;
	for(i = SPCOIL_START;i <= SPCOIL_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void loadNvram(void){//从EPROM中载入NVRAM
	enterSplcIsr();
	memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//初始化NVRAM
#if CONFIG_SPLC_USING_EPROM == 1
	epromRead(0, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));//从EPROM中恢复MR
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
static void saveNvram(void){//强制将NVRAM存入EPROM
	enterSplcIsr();
#if CONFIG_SPLC_USING_EPROM == 1
	epromWrite(0x0, (uint8_t*)NVRAM0, ((MR_END + 1) * 2));
#endif
	exitSplcIsr();
}
static void updataNvram(void){//更新NVRAM->EPROM
	data uint8_t *sp0, *sp1;
	data uint16_t i;
	sp0 = (uint8_t*)NVRAM0;
	sp1 = (uint8_t*)NVRAM1;
	for(i = (MR_START * 2);i < ((MR_END + 1) * 2);i ++){//储存MR
		if(*(sp0 + i) != *(sp1 + i)){
#if CONFIG_SPLC_USING_EPROM == 1
			epromWriteOneByte(i, *(sp0 + i));
#endif
		}	
	}
	for(i = (DM_START * 2);i < ((DM_END + 1) * 2);i ++){//储存DM
		if(*(sp0 + i) != *(sp1 + i)){
#if CONFIG_SPLC_USING_EPROM == 1
			epromWriteOneByte(i, *(sp0 + i));
#endif
		}
	}
	memcpy((uint8_t*)NVRAM1, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));
}
static void clearNvram(void){//清除NVRAM数据	
	idata uint16_t i = 0;
	enterSplcIsr();
	disableWatchDog();
#if CONFIG_SPLC_USING_EPROM == 1
	for(i = 0; i<= CONFIG_EPROM_SIZE;i ++){
		epromWriteOneByte(i, 0x0);
#if CONFIG_SPLC_USING_LED == 1
		setLedEprom(false);
#endif
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
			NVRAM0[SPREG_SPWM_COUNTER_0] ++;
			RES(SPCOIL_SPWM_OUT_0);
		}
		else if(NVRAM0[SPREG_SPWM_COUNTER_0] >= NVRAM0[SPREG_SPWM_CYCLE_SHADOW_0]){//发生溢出
			NVRAM0[SPREG_SPWM_COUNTER_0] = 0;
			NVRAM0[SPREG_SPWM_POS_SHADOW_0] = NVRAM0[SPREG_SPWM_POS_0];
			NVRAM0[SPREG_SPWM_CYCLE_SHADOW_0] = NVRAM0[SPREG_SPWM_CYCLE_0];
			SET(SPCOIL_SPWM_OUT_0);
		}
		else{
			NVRAM0[SPREG_SPWM_COUNTER_0]++;
		}
		//SPWM1
		if(LD(SPCOIL_SPWM_RESET_1)){//复位
			NVRAM0[SPREG_SPWM_COUNTER_1] = SHRT_MAX;
			RES(SPCOIL_SPWM_RESET_1);
		}
		if(NVRAM0[SPREG_SPWM_COUNTER_1] == NVRAM0[SPREG_SPWM_POS_SHADOW_1]){//发生匹配翻转输出
			NVRAM0[SPREG_SPWM_COUNTER_1] ++;
			RES(SPCOIL_SPWM_OUT_1);
		}
		else if(NVRAM0[SPREG_SPWM_COUNTER_1] >= NVRAM0[SPREG_SPWM_CYCLE_SHADOW_1]){//发生溢出
			NVRAM0[SPREG_SPWM_COUNTER_1] = 0;
			NVRAM0[SPREG_SPWM_POS_SHADOW_1] = NVRAM0[SPREG_SPWM_POS_1];
			NVRAM0[SPREG_SPWM_CYCLE_SHADOW_1] = NVRAM0[SPREG_SPWM_CYCLE_1];
			SET(SPCOIL_SPWM_OUT_1);
		}
		else{
			NVRAM0[SPREG_SPWM_COUNTER_1]++;
		}
		//SPWM2
		if(LD(SPCOIL_SPWM_RESET_2)){//复位
			NVRAM0[SPREG_SPWM_COUNTER_2] = SHRT_MAX;
			RES(SPCOIL_SPWM_RESET_2);
		}
		if(NVRAM0[SPREG_SPWM_COUNTER_2] == NVRAM0[SPREG_SPWM_POS_SHADOW_2]){//发生匹配翻转输出
			NVRAM0[SPREG_SPWM_COUNTER_2] ++;
			RES(SPCOIL_SPWM_OUT_2);
		}
		else if(NVRAM0[SPREG_SPWM_COUNTER_2] >= NVRAM0[SPREG_SPWM_CYCLE_SHADOW_2]){//发生溢出
			NVRAM0[SPREG_SPWM_COUNTER_2] = 0;
			NVRAM0[SPREG_SPWM_POS_SHADOW_2] = NVRAM0[SPREG_SPWM_POS_2];
			NVRAM0[SPREG_SPWM_CYCLE_SHADOW_2] = NVRAM0[SPREG_SPWM_CYCLE_2];
			SET(SPCOIL_SPWM_OUT_2);
		}
		else{
			NVRAM0[SPREG_SPWM_COUNTER_2]++;
		}
		//SPWM3
		if(LD(SPCOIL_SPWM_RESET_3)){//复位
			NVRAM0[SPREG_SPWM_COUNTER_3] = SHRT_MAX;
			RES(SPCOIL_SPWM_RESET_3);
		}
		if(NVRAM0[SPREG_SPWM_COUNTER_3] == NVRAM0[SPREG_SPWM_POS_SHADOW_3]){//发生匹配翻转输出
			NVRAM0[SPREG_SPWM_COUNTER_3] ++;
			RES(SPCOIL_SPWM_OUT_3);
		}
		else if(NVRAM0[SPREG_SPWM_COUNTER_3] >= NVRAM0[SPREG_SPWM_CYCLE_SHADOW_3]){//发生溢出
			NVRAM0[SPREG_SPWM_COUNTER_3] = 0;
			NVRAM0[SPREG_SPWM_POS_SHADOW_3] = NVRAM0[SPREG_SPWM_POS_3];
			NVRAM0[SPREG_SPWM_CYCLE_SHADOW_3] = NVRAM0[SPREG_SPWM_CYCLE_3];
			SET(SPCOIL_SPWM_OUT_3);
		}
		else{
			NVRAM0[SPREG_SPWM_COUNTER_3]++;
		}
	}
}
/*****************************************************************************/
void sPlcInit(void){//软逻辑初始化
#if CONFIG_SPLC_USING_IO_INPUT == 1
	inputInit();
#endif
#if CONFIG_SPLC_USING_IO_OUTPUT == 1
	outputInit();
#endif
#if CONFIG_USING_SIMEPROM == 1
	sPlcSimEpromInit();
#endif
#if CONFIG_SPLC_USING_WDT == 1
	checkWatchDog();//检查看门狗状态
	initWatchDog();//看门狗使能
	disableWatchDog();//屏蔽看门狗
#endif
#if CONFIG_SPLC_USING_UART0 == 1
	initUart0(CONFIG_UART0_BAUDRATE);//UART1初始化
#endif
#if CONFIG_SPLC_USING_UART1 == 1
	initUart1(CONFIG_UART1_BAUDRATE);//UART1初始化
#endif	
	loadNvram();//上电恢复NVRAM
#if CONFIG_SPLC_USING_ADC == 1
	initChipAdc();//初始化ADC模块
#endif
#if CONFIG_SPLC_USING_DAC == 1
	initChipDac();//初始化DAC模块
#endif
	initSplcTimer();//初始化硬件计时器模块
	SET(SPCOIL_ON);
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
#if CONFIG_USING_USB == 1
	usbSpiInit();//初始化 USB SPI	
	mStopIfError(usbHostInit());//默认初始化为HOST
#endif
	ENABLE_INTERRUPT;
}
void sPlcProcessStart(void){//sPLC轮询起始
#if CONFIG_SPLC_USING_CLEAR_NVRAM == 1
	if(NVRAM0[SPREG_CLEAR_NVRAM0] == CONFIG_SPLC_CLEAR_CODE){
		DISABLE_INTERRUPT;//关闭中断
#if CONFIG_SPLC_USING_LED == 1	
		setLedRun(true);//
		setLedEprom(true);
#endif
		if(epromTest()){//EPROM测试成功
#if CONFIG_SPLC_USING_LED == 1			
			setLedEprom(false);
			setLedError(true);
			delayMs(10);
			setLedError(false);
#endif
		}
		else{//EPROM测试失败
		}
		clearNvram();
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
#if CONFIG_SPLC_USING_PCA == 1	
	sPlcBeemLoop();	
	sPlcAimLoop();
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
#if CONFIG_USING_USB == 1
	sPlcUsbPoll();
#endif	
	updataNvram();//更新NVRAM
#if CONFIG_SPLC_USING_WDT == 1
	feedWatchDog();//喂狗
#endif
	RES(SPCOIL_START_UP);
}