#include "sPlc.h"
/*****************************************************************************/
xdata int16_t volatile NVRAM0[CONFIG_NVRAM_SIZE];//掉电保持寄存器 当前
xdata int16_t volatile NVRAM1[CONFIG_NVRAM_SIZE];//掉电保持寄存器 上一次
static idata volatile uint8_t TimerCounter_1mS = 0;
static idata volatile uint8_t TimerCounter_10mS = 0;
static idata volatile uint8_t TimerCounter_100mS = 0;
static idata volatile uint8_t Timer0_L, Timer0_H;
/*****************************************************************************/
static idata volatile int8_t inputFilter[(X_END - X_START + 1) * 16];//IO输入滤波器缓冲区
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
static void assertCoilAddress(uint16_t adr) reentrant{//检查线圈地址
#if CONFIG_SPLC_ASSERT == 1
	if(adr > (SPREG_END * 16))
		while(1);
#endif
}
static void assertRegisterAddress(uint16_t adr) reentrant{//检查寄存器地址
#if CONFIG_SPLC_ASSERT == 1
	if(adr >= SPREG_END)
		while(1);
#endif
}
static void clearDM(void){//清除DM寄存器
	uint16_t i;
	for(i = 0;i <= DM_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearMR(void){//清除MR寄存器
	uint16_t i;
	for(i = MR_START;i <= MR_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearEM(void){//清除EM寄存器
	uint16_t i;
	for(i = EM_START;i <= EM_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearR(void){//清除R寄存器
	uint16_t i;
	for(i = R_START;i <= R_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearT(void){//清除T寄存器
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
static void clearTD(void){//清除TD寄存器
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
static void clearC(void){//清除C寄存器
	uint16_t i;
	for(i = C_START;i <= C_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearX(void){//清除X寄存器
	uint16_t i;
	for(i = X_START;i <= X_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearY(void){//清除Y寄存器
	uint16_t i;
	for(i = Y_START;i <= Y_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearSPREG(void){//清除特殊寄存器
	uint16_t i;
	for(i = SPREG_START;i <= SPREG_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void clearSPCOIL(){//清除特特殊线圈
	uint16_t i;
	for(i = SPCOIL_START;i <= SPCOIL_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void loadNvram(void){//从EPROM中载入NVRAM
	memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//初始化NVRAM
	setLedEprom(DEBUG_LED_ON);
	epromRead(0, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));//从EPROM中恢复MR
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
static void saveNvram(void){//强制将NVRAM存入EPROM
	DISABLE_INTERRUPT;
	setLedEprom(DEBUG_LED_ON);
	epromWrite(0x0, (uint8_t*)NVRAM0, ((MR_END + 1) * 2));
	setLedEprom(DEBUG_LED_OFF);
	ENABLE_INTERRUPT;
}
static void updataNvram(void){//更新NVRAM->EPROM
	data uint8_t *sp0, *sp1;
	data uint16_t i;
	sp0 = (uint8_t*)NVRAM0;
	sp1 = (uint8_t*)NVRAM1;
	for(i = (MR_START * 2);i < ((MR_END + 1) * 2);i ++){//储存MR
		if(*(sp0 + i) != *(sp1 + i)){
			setLedEprom(DEBUG_LED_ON);
			epromWriteOneByte(i, *(sp0 + i));
			setLedEprom(DEBUG_LED_OFF);
		}	
	}
	sp0 = (uint8_t*)NVRAM0;
	sp1 = (uint8_t*)NVRAM1;
	for(i = (DM_START * 2);i < ((DM_END + 1) * 2);i ++){//储存DM
		if(*(sp0 + i) != *(sp1 + i)){
			setLedEprom(DEBUG_LED_ON);
			epromWriteOneByte(i, *(sp0 + i));
			setLedEprom(DEBUG_LED_OFF);
		}
	}
	memcpy((uint8_t*)NVRAM1, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));
}
static void clearNvram(void){//清除NVRAM数据	
	idata uint8_t oldEA;
	idata uint16_t i;
	oldEA = EA;//关闭中断
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
	EA = oldEA;//恢复中断
}
static void selfTestNvram(void){//自检NVRAM
	
}
/*****************************************************************************/
//软逻辑指令
void REBOOT(void) reentrant{//软件复位
	RSTSRC |= 1 << 4;//强制复位
}
void SET(uint16_t A) reentrant{//线圈置位
	assertCoilAddress(A);//检查地址范围
	NVRAM0[(A / 16)] |= 1 << (A % 16);
}
void RES(uint16_t A) reentrant{//线圈置零
	assertCoilAddress(A);//检查地址范围
	NVRAM0[(A / 16)] &= ~(1 << (A % 16));
}
void FLIP(uint16_t A) reentrant{//翻转
	uint16_t temp;
	assertCoilAddress(A);//检查地址范围
	temp= NVRAM0[(A / 16)] & (1 << (A % 16));
	if(temp)
		RES(A);
	else
		SET(A);
}
uint8_t LD(uint16_t A) reentrant{//载入
	assertCoilAddress(A);//检查地址范围
	return (uint8_t)(NVRAM0[(A / 16)] >> (A % 16)) & 0x01;
}
uint8_t LDB(uint16_t A) reentrant{//方向载入
	assertCoilAddress(A);//检查地址范围
	return !((uint8_t)(NVRAM0[(A / 16)] >> (A % 16)) & 0x01);
}
uint8_t LDP(uint16_t A) reentrant{//脉冲上升沿
	uint8_t temp0, temp1;
	assertCoilAddress(A);//检查地址范围
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> (A % 16)) & 0x01;
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> (A % 16)) & 0x01;
	if(temp0 == 1 && temp1 != 1)
		return true;
	else
		return false;
}
uint8_t LDN(uint16_t A) reentrant{//脉冲下降沿
	uint8_t temp0, temp1;
	assertCoilAddress(A);
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
	if(!temp0 && temp1)
		return 1;
	else
		return 0;
}
void T1MS(uint8_t A, uint8_t start, uint16_t value){//1MS延时器
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
void T10MS(uint8_t A, uint8_t start, uint16_t value){//10MS延时器
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
void T100MS(uint8_t A, uint8_t start, uint16_t value){//100MS延时器
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
int16_t TNTC(int16_t dat){//CODE转换为NTC测量温度温度
	idata uint16_t temp;
	idata fp32_t ftemp;
	if(dat >= CONFIG_SPLC_ADC_INTERNAL_VREF) dat = CONFIG_SPLC_ADC_INTERNAL_VREF;//限制输入最大值
	if(dat < 0) dat = 0;
	
	temp = (int16_t)(CONFIG_SPLC_ADC_INTERNAL_VREF * dat / 4096);//单位mV
	temp = 10000 * 5000 / (5000 - temp);//电源5V 分压电阻10K
	
	ftemp = ((1.0 / 3477)*log((fp32_t)(temp) / 10000)) + (1 / (25+273.0));//limo R25=10740,B=3450	 uniquemode 3988
	ftemp = ( 1.0 / ftemp ) - 273.0;
	if(ftemp >= 100) ftemp = 100;
	if(ftemp <= -100) ftemp = -100;
	return (int16_t)(ftemp * 10);
}
int16_t TENV(int16_t dat){//CODE转换为环境温度
	idata uint16_t temp;
	temp = (int16_t)(CONFIG_SPLC_ADC_INTERNAL_VREF * dat / 4096);//单位mV
	temp = (int16_t)((temp - CONFIG_SPLC_ADC_TEMP_SENSOR_OFFSET) * 1000 / CONFIG_SPLC_ADC_TEMP_SENSOR_GAIN);
	return temp;
}
int16_t MAX(int16_t *s, uint8_t len){//找出长度为len的数据s中的最大值
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
int16_t MIN(int16_t *s, uint8_t len){//找出长度为len的数据s中的最小值
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
//void ADD(uint16_t idata Sa, uint16_t idata Sb, uint16_t idata D){//16位求和 D = Sa + Sb
//	NVRAM0[D] = NVRAM0[Sa] + NVRAM0[Sb];
//}
void DADD(uint16_t Sa, uint16_t Sb, uint16_t D){//32位求和 D = Sa + Sb
	int32_t *tmp0, *tmp1, *tmp2;
	tmp0 = (int32_t*)(&NVRAM0[Sa]);
	tmp1 = (int32_t*)(&NVRAM0[Sb]);
	tmp2 = (int32_t*)(&NVRAM0[D]);
	*tmp2 = *tmp0 + *tmp1;
}
//void ADDS(uint16_t idata Sa, uint16_t idata Sb, uint16_t idata D){//16位饱和求和 D = Sa + Sb
//	idata int32_t tmp;
//	tmp = NVRAM0[Sa] + NVRAM0[Sb];
//	if(tmp >= SHRT_MAX)
//		tmp = SHRT_MAX;
//	if(tmp <= SHRT_MIN)
//		tmp = SHRT_MIN;
//	NVRAM0[D] = tmp;
//}
//void SUB(uint16_t Sa, uint16_t Sb, uint16_t D){//16位非饱和减法 D = Sa - Sb
//	NVRAM0[D] = NVRAM0[Sa] - NVRAM0[Sb];
//}
//void SUBS(uint16_t idata Sa, uint16_t idata Sb, uint16_t idata D){//16位饱和减法 D = Sa - Sb
//	idata int32_t tmp;
//	tmp = NVRAM0[Sa] - NVRAM0[Sb];
//	if(tmp >= SHRT_MAX)
//		tmp = SHRT_MAX;
//	if(tmp <= SHRT_MIN)
//		tmp = SHRT_MIN;
//	NVRAM0[D] = tmp;
//}
void DSUB(uint16_t Sa, uint16_t Sb, uint16_t D){//32位非饱和减法 D = Sa - Sb
	idata int32_t *tmp0, *tmp1, *tmp2;
	tmp0 = (int32_t*)(&NVRAM0[Sa]);
	tmp1 = (int32_t*)(&NVRAM0[Sb]);
	tmp2 = (int32_t*)(&NVRAM0[D]);
	*tmp2 = *tmp0 - *tmp1;
}
/*****************************************************************************/
static void wdtInit(void){//看门狗初始化
	WDTCN = 0x07;//47mS
}
void wdtEnable(void) reentrant{//使能看门狗
#ifdef C8051F020
	WDTCN = 0xA5;
#endif
}
void wdtDisable(void) reentrant{//关闭看门狗(未锁定)
	uint8_t flagEA;
	flagEA = EA;
	EA = 0;
	WDTCN = 0xDE;
    WDTCN = 0xAD;
	EA = flagEA;
}
void wdtFeed(void) reentrant{//喂狗
	WDTCN = 0xA5;
}
static void pcaInit(void){//硬件PCA初始化
}
static void timer0Init(void){//硬件sTimer计时器初始化
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
static void timer0Isr(void) interrupt INTERRUPT_TIMER0{//硬件sTimer计时器中断 1mS
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
	for(i = TD_1MS_START;i <= TD_1MS_END;i ++){//1mS计时
		if(NVRAM0[i] < SHRT_MAX){
			NVRAM0[i] ++;
		}
	}
	if(TimerCounter_1mS >= 10){//10mS计算
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
	if(TimerCounter_10mS >= 10){//100ms计算
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
	if(TimerCounter_100mS >= 10){//1000mS计算
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
	chipAdcProcess();//ADC扫描
#endif
	TimerCounter_1mS ++;
}
static void inputInit(void){//IO输入滤波器初始化
	memset(inputFilter, 0x0, (X_END - X_START + 1) * 16);
}
static void outputInit(void){//IO输出初始化
#ifdef C8051F020
	
#endif
}
static void inputRefresh(void){//获取输入IO
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
static void outputRefresh(void){//设置输出IO
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
void sPlcInit(void){//软逻辑初始化
	setLedError(DEBUG_LED_OFF);
	setLedRun(DEBUG_LED_OFF);
	setLedDac(DEBUG_LED_OFF);
	setLedEprom(DEBUG_LED_OFF);
	wdtInit();//看门狗使能
	wdtDisable();//屏蔽看门狗
#if CONFIG_SPLC_USING_UART1 == 1
	initUart1(CONFIG_UART1_BAUDRATE);//UART1初始化
#endif	
#if CONFIG_SPLC_USING_EPROM == 1
	loadNvram();//上电恢复NVRAM
#endif
#if CONFIG_SPLC_USING_CADC == 1
	initChipAdc();//初始化ADC模块
#endif
#if CONFIG_SPLC_USING_DAC == 1
	initChipDac();//初始化DAC模块
#endif
#if CONFIG_SPLC_USING_MB_RTU_SLAVE == 1
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
#endif
	timer0Init();//初始化硬件计时器模块
	SET(SPCOIL_ON);
	setLedError(DEBUG_LED_OFF);
	SET(SPCOIL_ON);
	SET(SPCOIL_START_UP);
	NVRAM0[EM_END] = CONFIG_SPLC_DEV;
}
void sPlcProcessStart(void){//sPLC轮询起始
#if CONFIG_SPLC_USING_CLEAR_NVRAM == 1
	if(NVRAM0[SPREG_CLEAR_NVRAM0] == CONFIG_SPLC_CLEAR_CODE){
		DISABLE_INTERRUPT;//关闭中断
		setLedRun(DEBUG_LED_ON);//
		setLedEprom(DEBUG_LED_ON);
		if(epromTest()){//EPROM测试成功
			setLedEprom(DEBUG_LED_OFF);
			setLedError(DEBUG_LED_ON);
			delayMs(500);
			setLedError(DEBUG_LED_OFF);
		}
		else{//EPROM测试失败
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
	wdtFeed();//喂狗
#endif
#if CONFIG_SPLC_USING_MB_RTU_SLAVE == 1
	modbusPorcess();//处理MODBUS
#endif
#if CONFIG_SPLC_USING_IO_INPUT == 1
	inputRefresh();//读取X口输入
#endif
#if CONFIG_SPLC_USING_WDT == 1
	wdtFeed();
#endif
}
void sPlcProcessEnd(void){//sPLC轮询结束
#if CONFIG_SPLC_USING_WDT == 1
	wdtFeed();//喂狗
#endif
#if CONFIG_SPLC_USING_IO_OUTPUT == 1
	outputRefresh();//更新Y口输出
#endif
#if CONFIG_SPLC_USING_DAC
	refreshDac();//更新DAC输出
#endif
#if CONFIG_SPLC_USING_EPROM == 1
	updataNvram();//更新NVRAM
#endif
#if CONFIG_SPLC_USING_WDT == 1
	wdtFeed();//喂狗
#endif
	RES(SPCOIL_START_UP);
}