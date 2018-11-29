#include "sPlc.h"
/*****************************************************************************/			
/*****************************************************************************/
int16_t NVRAM0[CONFIG_NVRAM_SIZE];//掉电保持寄存器 当前
int16_t NVRAM1[CONFIG_NVRAM_SIZE];//掉电保持寄存器 上一次
static data uint8_t TimerCounter_100uS = 0;
static data uint8_t TimerCounter_1mS = 0;
static data uint8_t TimerCounter_10mS = 0;
static data uint8_t TimerCounter_100mS = 0;
static data uint8_t Timer0_L, Timer0_H;
/*****************************************************************************/
/******************************************************************************/
void clear_dm(void){//清除DM寄存器
	uint16_t i;
	for(i = 0;i <= DM_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clear_mr(void){//清除MR寄存器
	uint16_t i;
	for(i = MR_START;i <= MR_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clear_em(void){//清除EM寄存器
	uint16_t i;
	for(i = EM_START;i <= EM_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clear_r(void){//清除R寄存器
	uint16_t i;
	for(i = R_START;i <= R_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void clear_t(void){//清除T寄存器
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
void clear_td(void){//清除TD寄存器
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
void clear_c(void){//清除C寄存器
	uint16_t i;
	for(i = C_START;i <= C_END;i ++)
	{
		NVRAM0[i] = 0x0;
		NVRAM1[i] = 0x0;
	}
}
void nvram_load(void){//从EPROM中载入NVRAM
	uint8_t flag;
	DISABLE_INTERRUPT//关闭中断
	memset(NVRAM0, 0x0, CONFIG_NVRAM_SIZE);//初始化NVRAM
	//flag = iic0_read(CONFIG_EPROM_ADDRESS, ((MR_END + 1) * 2), (uint8_t*)NVRAM0);//从EPROM中恢复NVRAM
	clear_em();
	clear_r();
	clear_t();
	clear_td();
	clear_c();
	memcpy(NVRAM1, NVRAM0, CONFIG_NVRAM_SIZE);
	ENABLE_INTERRUPT
}
void nvram_save(void){//强制将NVRAM存入EPROM
	uint8_t flag;
	DISABLE_INTERRUPT//关闭中断
	//flag = iic0_write(CONFIG_EPROM_ADDRESS, ((MR_END + 1) * 2), (uint8_t*)NVRAM0);
	ENABLE_INTERRUPT
}
void nvram_updata(void){//更新NVRAM->EPROM
	uint8_t flag, *sp0, *sp1;
	uint16_t i;
	sp0 = (uint8_t*)NVRAM0;
	sp1 = (uint8_t*)NVRAM1;
	DISABLE_INTERRUPT
	for(i = 0;i <= ((MR_END + 1) * 2);i ++)
	{
		if(*(sp0 + i) != *(sp1 + i))
		{
			//flag = iic0_write(CONFIG_EPROM_ADDRESS, 1, (uint8_t*)(sp0 + i));
		}
	}
	memcpy(NVRAM1, NVRAM0, CONFIG_NVRAM_SIZE);
	ENABLE_INTERRUPT
}

void SET(uint16_t A){//置位
	NVRAM0[(A / 16)] |= 1 << (A % 16);
}
void RESET(uint16_t A){//置零
	NVRAM0[(A / 16)] &= ~(1 << (A % 16));
}
void FLIP(uint16_t A){//翻转
	data uint16_t temp;
	temp= NVRAM0[(A / 16)] & (1 << (A % 16));
	if(temp)
		RESET(A);
	else
		SET(A);
}
uint8_t LD(uint16_t A){
	return (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
}
uint8_t LDP(uint16_t A){//脉冲上升沿
	data uint8_t temp0, temp1;
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
	if(temp0 && !temp1)
		return 1;
	else
		return 0;
}
uint8_t LDN(uint16_t A){//脉冲下降沿
	data uint8_t temp0, temp1;
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
	if(!temp0 && temp1)
		return 1;
	else
		return 0;
}
void T100US(uint8_t A, uint8_t start, uint16_t value){
#if CONFIG_DEBUG
	if(A > (TD_100US_END - TD_100US_START + 1))
		printf("T100US:%d Over Num\n", A);
#endif
	if(start){
		if(NVRAM0[(TD_100US_START + A)] >= value){
			NVRAM0[(T_100US_START + (A / 16))] |= 1 << (A % 16);
		}
		else{
			NVRAM0[(T_100US_START + (A / 16))] &= ~(1 << (A % 16));
		}
			
	}
	else{
		NVRAM0[(T_100US_START + (A / 16))] &= ~(1 << (A % 16));
		NVRAM0[(TD_100US_START + A)] = 0x0;
	}
}
void T1MS(uint8_t A, uint8_t start, uint16_t value){
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
void T10MS(uint8_t A, uint8_t start, uint16_t value){
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
void T100MS(uint8_t A, uint8_t start, uint16_t value){
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

void Timer0_Init(void)
{//硬件sTimer计时器初始化
	uint16_t temp;
	TimerCounter_100uS = 0;
	TimerCounter_1mS = 0;
	TimerCounter_10mS = 0;
	TimerCounter_100mS = 0;
	temp = (uint16_t)(65536 - (CONFIG_SYSCLK / 10000 / 12));//SoftPLC 硬件计时器基准1ms
	Timer0_L = temp & 0xFF;
	Timer0_H = (temp >> 8) & 0xFF;
	TH0 = Timer0_H;// Init Timer0 High register
	TL0 = Timer0_L;// Init Timer0 Low register
	TMOD &= 0xFC;
	TMOD |= 0x01;// Timer0 in 16-bit mode
	ET0 = 1;// Timer1 interrupt enabled
	TR0 = 1;// Timer1 ON
}
void Timer0_ISR(void) interrupt INTERRUPT_TIMER0
{//硬件sTimer计时器中断 1mS
	data uint16_t i;
	TimerCounter_100uS ++;
	//100us
	for(i = TD_100US_START;i <= TD_100US_END;i ++){
		if(NVRAM0[i] < SHRT_MAX){
			NVRAM0[i] ++;
		}
	}
	//1ms
	if(TimerCounter_100uS >= 10){
		for(i = TD_1MS_START;i <= TD_1MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_1mS ++;
		TimerCounter_100uS = 0;
	}
	//10ms
	if(TimerCounter_1mS >= 10){
		for(i = TD_10MS_START;i < TD_10MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_10mS ++;
		TimerCounter_1mS = 0;
	}
	//100ms
	if(TimerCounter_10mS >= 10){
		for(i = TD_100MS_START;i < TD_100MS_END;i ++){
			if(NVRAM0[i] < SHRT_MAX){
				NVRAM0[i] ++;
			}
		}
		TimerCounter_10mS = 0;
		TimerCounter_100mS ++;
	}
	if(TimerCounter_100mS >= 10){
		TimerCounter_100mS = 0;
	}
	TimerCounter_100uS ++;
	TH0 = Timer0_H;
	TL0 = Timer0_L;
}

//void inputFilter(softPlc_t *plc)
//{//对P0-P3进行数字滤波滤波
//	uint8_t i, j;
//	uint8_t s1, s2;
//	plc->X_Input0[0] = 0x0000;
//	plc->X_Input0[1] = 0x0000;
//	plc->X_Input0[0] = (P0 | (P1 << 8));
//	plc->X_Input0[1] = (P2 | (P3 << 8));
//	
//	plc->X_Input1[0] = plc->X_Input0[0];
//	plc->X_Input1[1] = plc->X_Input0[1];
//	for(i = 0;i < CONFIG_PLC_X_NUM;i ++)
//	{//遍历所有X寄存器
//		for(j = 0; j < 16;j ++)
//		{
//			s1 = (plc->X_Input0[i] >> j) & 0x01;
//			s2 = (plc->X_Input1[i] >> j) & 0x01;
//			if(s1 == s2)
//			{
//				plc->X_Coil[i] &= ~(1 << j);
//			}
//		}
//	}
//}
//void outputRefush(softPlc_t *plc)
//{//输出端口刷新
//	uint8_t outbit;
//	outbit = (plc->Y_Coil[0] >> (8 + 3)) & 0x01;
//	if(outbit)
//		P1 |= 1 << 3;
//	else
//		P1 &= ~(1 << 3);
//}