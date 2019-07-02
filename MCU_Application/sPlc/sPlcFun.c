#include "sPlcFun.h"
/*****************************************************************************/
void REBOOT(void) reentrant{//软件复位	
	mucReboot();
}
//void ORG(uint16_t A) reentrant{
//}
//位指令
//void OUT(uint16_t A) reentrant{
//}
void SET(uint16_t A) reentrant{//线圈置位
#if CONFIG_SPLC_ASSERT == 1
	assertCoilAddress(A);//检查地址范围
#endif
	NVRAM0[(A / 16)] |= 1 << (A % 16);
}
void RES(uint16_t A) reentrant{//线圈置零
#if CONFIG_SPLC_ASSERT == 1
	assertCoilAddress(A);//检查地址范围
#endif
	NVRAM0[(A / 16)] &= ~(1 << (A % 16));
}
void FLIP(uint16_t A) reentrant{//翻转
	uint16_t temp;
#if CONFIG_SPLC_ASSERT == 1
	assertCoilAddress(A);//检查地址范围
#endif
	temp= NVRAM0[(A / 16)] & (1 << (A % 16));
	if(temp)
		RES(A);
	else
		SET(A);
}
uint8_t LD(uint16_t A) reentrant{//载入
	uint8_t res = 0;
#if CONFIG_SPLC_ASSERT == 1
	assertCoilAddress(A);//检查地址范围
#endif
	res = (uint8_t)((uint16_t)NVRAM0[(A / 16)] >> (A % 16)) & 0x01;
	if(res)
		return true;
	else
		return false;
}
uint8_t LDB(uint16_t A) reentrant{//反向载入
	uint8_t res = 0;
#if CONFIG_SPLC_ASSERT == 1
	assertCoilAddress(A);//检查地址范围
#endif
	res = ((uint8_t)((uint16_t)NVRAM0[(A / 16)] >> (A % 16)) & 0x01);
	if(res)
		return false;
	else
		return true;
}
uint8_t LDP(uint16_t A) reentrant{//脉冲上升沿
	uint8_t temp0 = 0, temp1 = 0;
#if CONFIG_SPLC_ASSERT == 1
	assertCoilAddress(A);//检查地址范围
#endif
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> (A % 16)) & 0x01;
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> (A % 16)) & 0x01;
	if(temp0 == 1 && temp1 != 1)
		return true;
	else
		return false;
}
uint8_t LDN(uint16_t A) reentrant{//脉冲下降沿
	uint8_t temp0 = 0, temp1 = 0;
#if CONFIG_SPLC_ASSERT == 1
	assertCoilAddress(A);
#endif
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
	if(!temp0 && temp1)
		return true;
	else
		return false;
}
/*****************************************************************************/
//延时器指令
void T1MS(uint8_t A, uint8_t start, uint16_t value) reentrant{//1MS延时器
	if(start){
		SET(T_1MS_ENA_START * 16 + A);
		if(NVRAM0[(TD_1MS_START + A)] >= value){
			NVRAM0[(T_1MS_START + (A / 16))] |= 1 << (A % 16);
		}
		else{
			NVRAM0[(T_1MS_START + (A / 16))] &= ~(1 << (A % 16));
		}		
	}
	else{
		RES(T_1MS_ENA_START * 16 + A);
		NVRAM0[(T_1MS_START + (A / 16))] &= ~(1 << (A % 16));
		NVRAM0[(TD_1MS_START + A)] = 0x0;
	}	
}
void T10MS(uint8_t A, uint8_t start, uint16_t value) reentrant{//10MS延时器
	if(start){
		SET(T_10MS_ENA_START * 16 + A);
		if(NVRAM0[(TD_10MS_START + A)] >= value){
			NVRAM0[(T_10MS_START + (A / 16))] |= 1 << (A % 16);
		}
		else{
			NVRAM0[(T_10MS_START + (A / 16))] &= ~(1 << (A % 16));
		}
	}
	else{
		RES(T_10MS_ENA_START * 16 + A);
		NVRAM0[(T_10MS_START + (A / 16))] &= ~(1 << (A % 16));
		NVRAM0[(TD_10MS_START + A)] = 0x0;
	}	
}
void T100MS(uint8_t A, uint8_t start, uint16_t value) reentrant{//100MS延时器
	if(start){
		SET(T_100MS_ENA_START * 16 + A);
		if(NVRAM0[(TD_100MS_START + A)] >= value){
			NVRAM0[(T_100MS_START + (A / 16))] |= 1 << (A % 16);
		}
		else{		
			NVRAM0[(T_100MS_START + (A / 16))] &= ~(1 << (A % 16));
		}	
	}
	else{
		RES(T_100MS_ENA_START * 16 + A);
		NVRAM0[(T_100MS_START + (A / 16))] &= ~(1 << (A % 16));
		NVRAM0[(TD_100MS_START + A)] = 0x0;
	}
}
/*****************************************************************************/
//计算指令
void CLR(uint16_t A) reentrant{//16位寄存器清零
#if CONFIG_SPLC_ASSERT == 1
	assertRegisterAddress(A);//检查寄存器地址
#endif
	NVRAM0[A] = 0x0;
}
void CLRD(uint16_t A) reentrant{//32位寄存器清零
#if CONFIG_SPLC_ASSERT == 1
	assertRegisterAddress(A);//检查寄存器地址
	assertRegisterAddress(A + 1);//检查寄存器地址
#endif
	NVRAM0[A] = 0x0;NVRAM0[A + 1] = 0x0;
}
void MOV(uint16_t dist, uint16_t src) reentrant{//16位寄存器传输
#if CONFIG_SPLC_ASSERT == 1
	assertRegisterAddress(dist);//检查寄存器地址
	assertRegisterAddress(src);//检查寄存器地址
#endif
	NVRAM0[dist] = NVRAM0[src];
}
void MOVD(uint16_t dist, uint16_t src) reentrant{//32位寄存器传输
#if CONFIG_SPLC_ASSERT == 1
	assertRegisterAddress(dist);//检查寄存器地址
	assertRegisterAddress(dist+1);//检查寄存器地址
	assertRegisterAddress(src);//检查寄存器地址
	assertRegisterAddress(src+1);//检查寄存器地址
#endif
	NVRAM0[dist] = NVRAM0[src];
	NVRAM0[dist + 1] = NVRAM0[src + 1];
}
//void AND(uint16_t A, uint16_t A){//16位数 按位求与
//	
//}
//void ANDD(uint16_t dist){//32位数 按位求与
//}
void TNTC(uint16_t dist, uint16_t src) reentrant{//CODE转换为NTC测量温度温度
	uint16_t temp;
	fp32_t ftemp;
#if CONFIG_SPLC_ASSERT == 1
	assertRegisterAddress(dist);//检查寄存器地址
	assertRegisterAddress(src);//检查寄存器地址
#endif
	if(NVRAM0[src] >= CONFIG_ADC_INTERNAL_VREF) 
		NVRAM0[src] = CONFIG_ADC_INTERNAL_VREF;//限制输入最大值
	if(NVRAM0[src] < 0) 
		NVRAM0[src] = 0;
	temp = (int16_t)(CONFIG_ADC_INTERNAL_VREF * NVRAM0[src] / 4096);//单位mV
	temp = (uint16_t)(CONFIG_NTC_RS * (CONFIG_NTC_VREF - temp) / temp);
	ftemp = ((1.0 / CONFIG_NTC_B) * log((fp32_t)(temp) / 10000)) + (1 / (CONFIG_ADC_AMBIENT + 273.0));//limo R25=10740,B=3450	 uniquemode 3988
	ftemp = ( 1.0 / ftemp ) - 273.0;
	if(ftemp >= 100) ftemp = 100;
	if(ftemp <= -100) ftemp = -100;
	NVRAM0[dist] = (int16_t)(ftemp * 10);
}
void TENV(uint16_t dist, uint16_t src) reentrant{//CODE转换为环境温度
	int16_t temp;
	temp = (int16_t)(CONFIG_ADC_INTERNAL_VREF * NVRAM0[src] / 4096);//单位mV
	temp = (int16_t)((temp - CONFIG_ADC_TEMP_SENSOR_OFFSET) * 1000 / CONFIG_ADC_TEMP_SENSOR_GAIN);
	NVRAM0[dist] = temp;
}
void ADD1(uint16_t Sa) reentrant{//16位非饱和自加
	NVRAM0[Sa] += 1;
}
void ADDS1(uint16_t Sa) reentrant{//16位饱和自加
	if(NVRAM0[Sa] < SHRT_MAX){
		NVRAM0[Sa] += 1;
	}
}
void DEC1(uint16_t Sa) reentrant{//16位非饱和自减
	NVRAM0[Sa] -= 1;
}
void DECS1(uint16_t Sa) reentrant{//16位饱和自减
	if(NVRAM0[Sa] > SHRT_MIN){
		NVRAM0[Sa] -= 1;
	}
}
void ADL1(uint16_t Sa) reentrant{//32位非饱和自加
	int32_t temp = 0;
	temp = NVRAM0[(Sa + 1)];
	temp = (temp << 16) & 0xFFFF0000;
	temp |= NVRAM0[Sa];
	temp += 1;
	NVRAM0[Sa] = temp & 0x0000FFFF;
	NVRAM0[(Sa + 1)] = (temp >> 16) & 0x0000FFFF;
}
void ADLS1(uint16_t Sa) reentrant{//32位饱和自加
	int32_t temp = 0;
	temp = NVRAM0[(Sa + 1)];
	temp = (temp << 16) & 0xFFFF0000;
	temp |= NVRAM0[Sa];
	if(temp < LONG_MAX){
		temp ++;
		NVRAM0[Sa] = temp & 0x0000FFFF;
		NVRAM0[(Sa + 1)] = (temp >> 16) & 0x0000FFFF;
	}
}
void DEL1(uint16_t Sa) reentrant{//32位非饱和自减
	int32_t temp = 0;
	temp = NVRAM0[(Sa + 1)];
	temp = (temp << 16) & 0xFFFF0000;
	temp |= NVRAM0[Sa];
	temp -= 1;
	NVRAM0[Sa] = temp & 0x0000FFFF;
	NVRAM0[(Sa + 1)] = (temp >> 16) & 0x0000FFFF;
}
void DELS1(uint16_t Sa) reentrant{//32位饱和自减
	int32_t temp = 0;
	temp = NVRAM0[(Sa + 1)];
	temp = (temp << 16) & 0xFFFF0000;
	temp |= NVRAM0[Sa];
	if(temp < LONG_MAX){
		temp --;
		NVRAM0[Sa] = temp & 0x0000FFFF;
		NVRAM0[(Sa + 1)] = (temp >> 16) & 0x0000FFFF;
	}
}
void ADD16(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant{//16位非饱和加法 D = Sa + Sb
	NVRAM0[D] = NVRAM0[Sa] + NVRAM0[Sb];
}
void ADDS16(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant{//16位饱和加法 D = Sa + Sb
	int32_t tmp;
	tmp = NVRAM0[Sa] + NVRAM0[Sb];
	if(tmp >= SHRT_MAX)
		tmp = SHRT_MAX;
	if(tmp <= SHRT_MIN)
		tmp = SHRT_MIN;
	NVRAM0[D] = tmp;
}
void ADD32(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant{//32位非饱加法 D = Sa + Sb
	int32_t tmpSa = 0, tmpSb = 0, tmpD = 0;
	tmpSa = NVRAM0[(Sa + 1)];
	tmpSa = (tmpSa << 16) & 0xFFFF0000;
	tmpSa |= NVRAM0[Sa];
	
	tmpSb = NVRAM0[(Sb + 1)];
	tmpSb = (tmpSb << 16) & 0xFFFF0000;
	tmpSb |= NVRAM0[Sb];
	
	tmpD = tmpSa + tmpSb;
	NVRAM0[D] = tmpD & 0x0000FFFF;
	NVRAM0[(D + 1)] = (tmpD >> 16) & 0x0000FFFF;
}
void ADDS32(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant{//32位饱和加法 D = Sa + Sb
	int32_t tmpSa = 0, tmpSb = 0, tmpD = 0;
	fp64_t fD;
	tmpSa = NVRAM0[(Sa + 1)];
	tmpSa = (tmpSa << 16) & 0xFFFF0000;
	tmpSa |= NVRAM0[Sa];
	
	tmpSb = NVRAM0[(Sb + 1)];
	tmpSb = (tmpSb << 16) & 0xFFFF0000;
	tmpSb |= NVRAM0[Sb];

	fD = (fp64_t)tmpSa + (fp64_t)tmpSb;
	if(fD >= LONG_MAX){
		fD = LONG_MAX;
	}
	if(fD <= LONG_MIN){
		fD = LONG_MIN;
	}
	tmpD = (int32_t)fD;
	NVRAM0[D] = tmpD & 0x0000FFFF;
	NVRAM0[(D + 1)] = (tmpD >> 16) & 0x0000FFFF;
	
}
void ADDS32D(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant{//32位饱和加法 D(32) = Sa(32) + Sb(16)
	int32_t tmpSa = 0, tmpD = 0;
	fp64_t fD;
	tmpSa = NVRAM0[(Sa + 1)];
	tmpSa = (tmpSa << 16) & 0xFFFF0000;
	tmpSa |= NVRAM0[Sa];
	
	fD = (fp64_t)tmpSa + (fp64_t)NVRAM0[Sb];
	if(fD >= LONG_MAX){
		fD = LONG_MAX;
	}
	if(fD <= LONG_MIN){
		fD = LONG_MIN;
	}
	tmpD = (int32_t)fD;
	NVRAM0[D] = tmpD & 0x0000FFFF;
	NVRAM0[(D + 1)] = (tmpD >> 16) & 0x0000FFFF;
}
void SUB16(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant{//16位非饱和减法 D = Sa - Sb
	NVRAM0[D] = NVRAM0[Sa] - NVRAM0[Sb];
}
void SUBS16(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant{//16位饱和减法 D = Sa - Sb
	int32_t tmp;
	tmp = (int32_t)NVRAM0[Sa] - (int32_t)NVRAM0[Sb];
	if(tmp >= SHRT_MAX)
		tmp = SHRT_MAX;
	if(tmp <= SHRT_MIN)
		tmp = SHRT_MIN;
	NVRAM0[D] = tmp;
}
void SUB32(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant{//32位非饱和减法 D = Sa - Sb
	int32_t tmpSa = 0, tmpSb = 0, tmpD = 0;
	tmpSa = NVRAM0[(Sa + 1)];
	tmpSa = (tmpSa << 16) & 0xFFFF0000;
	tmpSa |= NVRAM0[Sa];
	
	tmpSb = NVRAM0[(Sb + 1)];
	tmpSb = (tmpSb << 16) & 0xFFFF0000;
	tmpSb |= NVRAM0[Sb];
	
	tmpD = tmpSa - tmpSb;
	NVRAM0[D] = tmpD & 0x0000FFFF;
	NVRAM0[(D + 1)] = (tmpD >> 16) & 0x0000FFFF;
}
void MULT16(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant{//16*16->16非饱和乘法 D = Sa * Sb
	int32_t tmp = (int32_t)NVRAM0[Sa] * (int32_t)NVRAM0[Sb];
	NVRAM0[D] = (int16_t)(tmp & 0xFFFF);
}
void MULTS16(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant{//16*16->16饱和乘法 D = Sa * Sb
	int32_t tmp = (int32_t)NVRAM0[Sa] * (int32_t)NVRAM0[Sb];
	if(tmp >= SHRT_MAX)
		tmp = SHRT_MAX;
	if(tmp <= SHRT_MIN)
		tmp = SHRT_MIN;
	NVRAM0[D] = (int16_t)tmp;
}
void MULT32(uint16_t Sa, uint16_t Sb, uint16_t D) reentrant{//16*16->32非饱和乘法 D = Sa * Sb
	int32_t tmpSa = 0, tmpSb = 0, tmpD = 0;
	tmpSa = NVRAM0[(Sa + 1)];
	tmpSa = (tmpSa << 16) & 0xFFFF0000;
	tmpSa |= NVRAM0[Sa];
	
	tmpSb = NVRAM0[(Sb + 1)];
	tmpSb = (tmpSb << 16) & 0xFFFF0000;
	tmpSb |= NVRAM0[Sb];
	
	tmpD = tmpSa * tmpSb;
	NVRAM0[D] = tmpD & 0x0000FFFF;
	NVRAM0[(D + 1)] = (tmpD >> 16) & 0x0000FFFF;
}
void SUM16(uint16_t index, uint16_t length, uint16_t sum) reentrant{//16BIT数求和->32BIT
	int32_t tmp = 0;
	uint16_t i = 0;
	for(i = 0; i < NVRAM0[length]; i++)
	{
		tmp += NVRAM0[index + i];
	}
	*((int32_t*)&NVRAM0[sum]) = tmp;
}
void UMAX16(uint16_t index, uint16_t length, uint16_t max) reentrant{//16位无符号数组找最大值
	uint16_t i = 0;
	uint16_t tmp = 0;
	for(i = 0;i < NVRAM0[length];i ++ ){
		if(tmp < NVRAM0[index + i]){
			tmp = NVRAM0[index + i];
		}
	}
	NVRAM0[max] = tmp;
}
void UMIN16(uint16_t index, uint16_t length, uint16_t min) reentrant{//16位无符号数组找最小值
	uint16_t i = 0;
	uint16_t tmp = 0;
	for(i = 0;i < NVRAM0[length];i ++){
		if(tmp < NVRAM0[index + i]){
			tmp = NVRAM0[index + i];
		}
	}
	NVRAM0[min] = tmp;
}
void SMAX16(uint16_t index, uint16_t length, uint16_t max) reentrant{//16位有符号数组找最大值
	uint16_t i = 0;
	int16_t tmp = 0;
	for(i = 0;i < NVRAM0[length];i ++ ){
		if(tmp < NVRAM0[index + i]){
			tmp = NVRAM0[index + i];
		}
	}
	NVRAM0[max] = tmp;
}
void SMIN16(uint16_t index, uint16_t length, uint16_t min) reentrant{//16位有符号数组找最小值
	uint16_t i = 0;
	int16_t tmp = 0;
	for(i = 0;i < NVRAM0[length];i ++){
		if(tmp < NVRAM0[index + i]){
			tmp = NVRAM0[index + i];
		}
	}
	NVRAM0[min] = tmp;
}
void ABS16(uint16_t dist, uint16_t src) reentrant{//16位数球绝对值
	if(NVRAM0[src] >= 0){
		NVRAM0[dist] = NVRAM0[src];
	}
	else{
		NVRAM0[dist] = NVRAM0[src] * -1;
	}
}
void ABS32(uint16_t dist, uint16_t src) reentrant{//32位数求绝对值
	if(NVRAM0[src] >= 0){
		NVRAM0[dist] = NVRAM0[src];
	}
	else{
		NVRAM0[dist] = NVRAM0[src] * -1;
	}
}
void SWAP(uint16_t dist, uint16_t src) reentrant{//交换A的高低字节
	uint16_t tmpL = 0, tmpH = 0;
	tmpL = (NVRAM0[src] & 0x00FF);
	tmpH = (NVRAM0[src] >> 8) & 0x00FF;
	tmpH |= tmpL;
	NVRAM0[dist] = tmpH;
}
/*****************************************************************************/
void BCPY(uint16_t dist, uint16_t src, uint16_t length) reentrant{//块复制
	uint16_t i;
	for(i = 0;i < length;i ++){
		NVRAM0[dist + i] = NVRAM0[src + i];
	}
}
void FSAV(void){//强制立即更新NVRAM
	disableSplcIsr();
	updataNvram();
	enableSplcIsr();
}


/*****************************************************************************/
//IO指令
void IMDIO(void) reentrant{//立即更新IO点状态含输入输出

}
/*****************************************************************************/

//步指令
//void TO(uint16_t SA) reentrant{//步进开始指令
//}
//void STP(uint16_t SA) reentrant{//步进指令
//}
//void STPEND(void) reentrant{//步进结束指令
//}
//void FROM(uint16_t SA) reentrant{//步进执行指令
//}