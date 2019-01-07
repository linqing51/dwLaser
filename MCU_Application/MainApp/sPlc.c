#include "sPlc.h"
/*****************************************************************************/			
/*****************************************************************************/
xdata int16_t NVRAM0[CONFIG_NVRAM_SIZE];//掉电保持寄存器 当前
xdata int16_t NVRAM1[CONFIG_NVRAM_SIZE];//掉电保持寄存器 上一次
static data uint8_t TimerCounter_1mS = 0;
static data uint8_t TimerCounter_10mS = 0;
static data uint8_t Timer0_L, Timer0_H;
/*****************************************************************************/
typedef struct{//ADC滤波器
	uint16_t dat[CONFIG_SPLC_ADC_FILTER_TAP];
	uint16_t out;
	uint8_t wIndex;//写入指针
}adcTempDat_t;

static xdata int8_t inputFilter[CONFIG_SPLC_IO_INPUT_NUM];//IO输入滤波器缓冲区
static xdata adcTempDat_t adcTempDat[CONFIG_SPLC_ADC_CHANNLE];
uint8_t adcSelect;//ADC通道选择
static void refreshAdcData(adcTempDat_t *s , uint16_t dat);
void adcProcess(void);
static void initAdcData(adcTempDat_t *s);
static void chipDacInit(void);
static void chipAdcInit(void);
/******************************************************************************/

static void adcProcess(void){//循环采集ADC
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
			//AMX0SL = 0x00;
			break;
		}
		case 1:{
			//AMX0SL = 0x01;
			break;
		}
		case 2:{
			//AMX0SL = 0x02;
			break;
		}
		case 3:{
			//AMX0SL = 0x03;
			break;
		}
		case 4:{
			//AMX0SL = 0x04;
			break;
		}
		default:{
			break;
		}
	}
	AD0INT = 0;
	AD0BUSY = 1;//AD0BUSY写入1
}
static void initAdcData(adcTempDat_t *s){//初始化ADC滤波器
	uint8_t i;
	for(i = 0;i < CONFIG_SPLC_ADC_FILTER_TAP; i++){
		s->dat[i] = 0x0;
	}
	s->out = 0;
	s->wIndex = 0;
}
static void refreshAdcData(adcTempDat_t *s , uint16_t dat){//更新ADC采集值
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
void assertCoilAddress(uint16_t adr){//检查线圈地址
	if(adr > (SPREG_END * 16))
		while(1);
}
void assertRegisterAddress(uint16_t adr){//检查寄存器地址
	if(adr >= SPREG_END)
		while(1);
}
void clearDM(void){//清除DM寄存器
	uint16_t i;
	for(i = 0;i <= DM_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearMR(void){//清除MR寄存器
	uint16_t i;
	for(i = MR_START;i <= MR_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearEM(void){//清除EM寄存器
	uint16_t i;
	for(i = EM_START;i <= EM_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearR(void){//清除R寄存器
	uint16_t i;
	for(i = R_START;i <= R_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearT(void){//清除T寄存器
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
void clearTD(void){//清除TD寄存器
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
void clearSPREG(void){
	uint16_t i;
	for(i = SPREG_START;i <= SPREG_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clearSPCOIL(){
	uint16_t i;
	for(i = SPCOIL_START;i <= SPCOIL_END;i ++){
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
static void nvramLoad(void){//从EPROM中载入NVRAM
	memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//初始化NVRAM
	epromRead(0, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));//从EPROM中恢复MR
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
static void nvramSave(void){//强制将NVRAM存入EPROM
	DISABLE_INTERRUPT//关闭中断
	epromWrite(0x0, (uint8_t*)NVRAM0, ((MR_END + 1) * 2));
	ENABLE_INTERRUPT
}
static void nvramUpdata(void){//更新NVRAM->EPROM
	uint8_t *sp0, *sp1;
	uint16_t i;
	sp0 = (uint8_t*)(NVRAM0 + (MR_START * 2));
	sp1 = (uint8_t*)(NVRAM1 + (MR_START * 2));
	for(i = MR_START;i < ((MR_END + 1) * 2);i ++){//储存MR
		if(*(sp0 + i) != *(sp1 + i)){
			epromWriteOneByte(i, *(sp0 + i));
		}
	}
	sp0 = (uint8_t*)(NVRAM0 + (DM_START * 2));
	sp1 = (uint8_t*)(NVRAM1 + (DM_START * 2));
	for(i = DM_START;i < ((DM_END + 1) * 2);i ++){//储存DM
		if(*(sp0 + i) != *(sp1 + i)){
			epromWriteOneByte(i, *(sp0 + i));
		}
	}
	memcpy(NVRAM1, NVRAM0, (CONFIG_NVRAM_SIZE * 2));
}
int16_t ADD(int16_t A, int16_t B){//加法指令
	int32_t tmp;
	tmp = (int32_t)A + (int32_t)B;
	if(tmp >= INT_MAX)
		tmp = INT_MAX;
	if(tmp <= INT_MIN)
		tmp = INT_MIN;
	return (int16_t)tmp;
}
void SET(uint16_t A){//置位
	assertCoilAddress(A);//检查地址范围
	NVRAM0[(A / 16)] |= 1 << (A % 16);
}
void RES(uint16_t A){//置零
	assertCoilAddress(A);//检查地址范围
	NVRAM0[(A / 16)] &= ~(1 << (A % 16));
}
void FLIP(uint16_t A){//翻转
	uint16_t temp;
	assertCoilAddress(A);//检查地址范围
	temp= NVRAM0[(A / 16)] & (1 << (A % 16));
	if(temp)
		RES(A);
	else
		SET(A);
}
uint8_t LD(uint16_t A){//载入
	assertCoilAddress(A);//检查地址范围
	return (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
}
uint8_t LDB(uint16_t A){//取反载入
}
uint8_t LDP(uint16_t A){//脉冲上升沿
	uint8_t temp0, temp1;
	assertCoilAddress(A);//检查地址范围
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
	if(temp0 && !temp1)
		return 1;
	else
		return 0;
}
uint8_t LDF(uint16_t A){//脉冲下降沿
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
	uint16_t temp;
	fp32_t ftemp;
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
	uint16_t temp;
	temp = (int16_t)(CONFIG_SPLC_ADC_INTERNAL_VREF * dat / 4096);//单位mV
	temp = (int16_t)((temp - CONFIG_SPLC_ADC_TEMP_SENSOR_OFFSET) * 1000 / CONFIG_SPLC_ADC_TEMP_SENSOR_GAIN);
	return temp;
}
int16_t XTAB(int16_t x, uint16_t tab, uint16_t len){//输入X线性查表
	//从tab 0->len 为表X走
}
int16_t YTAB(int16_t y, uint16_t tab, uint16_t len){//输入Y线性查表
}
void UPDAC(uint16_t dat){//立即更新DAC输出
	switch(dat){
		case 0:{
			mcp47x6Write(0, NVRAM0[SPREG_START + SPREG_DAC_0]);
			break;
		}
		case 1:{
			mcp47x6Write(1, NVRAM0[SPREG_START + SPREG_DAC_1]);
			break;
		}
		case 2:{
			mcp47x6Write(2, NVRAM0[SPREG_START + SPREG_DAC_2]);
			break;
		}
		case 3:{
			mcp47x6Write(3, NVRAM0[SPREG_START + SPREG_DAC_3]);
			break;
		}
		default:break;
	}
}
void REBOOT(void){//MCU复位
#ifdef C8051F580	
	uint8_t SFRPAGE_save;
#endif
#ifdef C8051F020
	RSTSRC |= (1 << 1);//Forces a Power-On Reset. /RST is driven low.
#endif
#ifdef C8051F580
	SFRPAGE_save = SFRPAGE;
	SFRPAGE = ACTIVE_PAGE;
	RSTSRC |= (1 << 1);//Forces a Power-On Reset. /RST is driven low.
	SFRPAGE = SFRPAGE_save;
#endif
	
}
static void wdtInit(void){//看门狗初始化
#ifdef C8051F020
	WDTCN = 0;//47mS
#endif
}
static void wdtEnable(void){//使能看门狗
#ifdef C8051F020
	WDTCN = 0xA5;
#endif
#ifdef C8051F580
#endif
}
void wdtDisable(void){//关闭看门狗(未锁定)
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
static void wdtFeed(void){//喂狗
#ifdef C8051F020
	WDTCN = 0xA5;
#endif
}

static void pcaInit(void){//硬件PCA初始化
#ifdef C8051F020

#endif
#ifdef C8051F580
//F580 CEX6,7,8 PWM OUT
//F680 CEX9,10,11 PULSE IN
#endif
}

static void timer0Init(void){//硬件sTimer计时器初始化
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
#ifdef C8051F580
#endif
}
static void timer0Isr(void) interrupt INTERRUPT_TIMER0{//硬件sTimer计时器中断 1mS
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
	
	for(i = TD_1MS_START;i <= TD_1MS_END;i ++){//1mS计时
		if(NVRAM0[i] < SHRT_MAX){
			NVRAM0[i] ++;
		}
	}
	if(TimerCounter_1mS >= 10){//10mS计算
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
	if(TimerCounter_10mS >= 10){//100ms计算
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
	}
#if CONFIG_SPLC_USING_ADC == 1
	adcProcess();//ADC扫描
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
static void inputRefresh(void){//获取输入IO
	uint8_t ctemp0,ctemp1, i;
	ctemp0 = 0;
	ctemp0 = 0;
#ifdef C8051F020
	//P4,P5输入
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
static void outputRefresh(void){//设置输出IO
#ifdef C8051F020
	//P6,P7输出IO
	P6 = (NVRAM0[Y_START] & 0x00FF);
	P7 = ((NVRAM0[Y_START] >> 8) & 0x00FF);
#endif
#ifdef C8051F580
	outPca9554Write(NVRAM0[Y_START]);
#endif
}
static void chipAdcInit(void){//ADC模块初始化
	uint8_t i;
#ifdef C8051F020
	ADC0CN = 0x0;//软件触发
	ADC0CN |= (1 << 6);//AD0TM = 1 启用跟踪
	ADC0CN |= (1 << 7);//AD0EN = 1 
	ADC0CF = 0x0;
	ADC0CF |= (CONFIG_SYSCLK / SAR_CLK) << 3;     // ADC conversion clock = 2.5MHz
	AMX0CF = 0x00;                      // AIN inputs are single-ended (default)
	AMX0SL = 0x00;                      // Select AIN0.1 pin as ADC mux input
	AD0INT = 0;
	AD0BUSY = 1;//AD0BUSY写入1
#endif
	adcSelect = 0;
	for(i = 0;i <= CONFIG_SPLC_ADC_CHANNLE;i ++){
		initAdcData(&adcTempDat[i]);
	}
}
void sPlcInit(void){//软逻辑初始化
	wdtInit();//看门狗使能
	wdtDisable();//屏蔽看门狗
	
#if CONFIG_SPLC_USING_EPROM == 1
	nvramLoad();//上电恢复NVRAM
#endif
	
#if CONFIG_SPLC_USING_ADC == 1
	chipAdcInit();//初始化ADC模块
#endif
	
#if CONFIG_SPLC_USING_DAC == 1
	chipDacInit();//初始化DAC模块
#endif
	
#if CONFIG_SPLC_USING_MB_RTU_SLAVE == 1
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
#endif
	timer0Init();//初始化硬件计时器模块
	NVRAM0[(SPCOIL_START + (SPCOIL_ON / 16))] |= (uint16_t)(1 << (SPCOIL_ON % 16));
}
static void refreshDac(void){//刷新DAC
#ifdef C8051F020
	if(DAC0 != NVRAM0[SPREG_DAC_0]){
		DAC0 = NVRAM0[SPREG_DAC_0];
	}
	if(DAC1 != NVRAM0[SPREG_DAC_1]){
		DAC1 = NVRAM0[SPREG_DAC_1];
	}
#endif
}
static void chipDacInit(void){//初始化DAC
#ifdef C8051F020
	DAC0CN = 0x0;
	DAC0CN |= (1 << 7);
	DAC0 = 0;
	DAC1 = 0;
#endif
}
void sPlcProcessStart(void){//sPLC轮询起始
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
	nvramUpdata();//更新NVRAM
#endif
}