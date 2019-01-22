#include "sPlcFun.h"
/*****************************************************************************/
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
	return (uint8_t)((uint16_t)NVRAM0[(A / 16)] >> (A % 16)) & 0x01;
}
uint8_t LDB(uint16_t A) reentrant{//方向载入
	assertCoilAddress(A);//检查地址范围
	return !((uint8_t)((uint16_t)NVRAM0[(A / 16)] >> (A % 16)) & 0x01);
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
		return true;
	else
		return false;
}
void T1MS(uint8_t A, uint8_t start, uint16_t value) reentrant{//1MS延时器
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
void T10MS(uint8_t A, uint8_t start, uint16_t value) reentrant{//10MS延时器
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
void T100MS(uint8_t A, uint8_t start, uint16_t value) reentrant{//100MS延时器
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
int16_t TNTC(int16_t dat) reentrant{//CODE转换为NTC测量温度温度
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
int16_t TENV(int16_t dat) reentrant{//CODE转换为环境温度
	uint16_t temp;
	temp = (int16_t)(CONFIG_SPLC_ADC_INTERNAL_VREF * dat / 4096);//单位mV
	temp = (int16_t)((temp - CONFIG_SPLC_ADC_TEMP_SENSOR_OFFSET) * 1000 / CONFIG_SPLC_ADC_TEMP_SENSOR_GAIN);
	return temp;
}
int16_t MAX(int16_t *s, uint8_t len) reentrant{//找出长度为len的数据s中的最大值
	int16_t max;
	uint8_t i;
	max = *s;
	for(i = 0;i < len;i ++){
		if(*(s +i) > max){
			max = *(s + i);
		}
	}
	return max;
}
int16_t MIN(int16_t *s, uint8_t len) reentrant{//找出长度为len的数据s中的最小值
	int16_t min;
	uint8_t i;
	min = *s;
	for(i = 0;i < len;i ++){
		if(*(s +i) < min){
			min = *(s + i);
		}
	}
	return min;
}
void ADD(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16位非饱和加法 D = Sa + Sb
	*D = *Sa + *Sb;
}
void ADDS(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16位饱和加法 D = Sa + Sb
	int32_t tmp;
	tmp =*Sa + *Sb;;
	if(tmp >= SHRT_MAX)
		tmp = SHRT_MAX;
	if(tmp <= SHRT_MIN)
		tmp = SHRT_MIN;
	*D = tmp;
}
void DADD(int32_t *Sa, int32_t *Sb, int32_t *D) reentrant{//32位非饱加法 D = Sa + Sb
	*D = *Sa + *Sb;
}
void SUB(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16位非饱和减法 D = Sa - Sb
	*D = *Sa - *Sb;
}
void SUBS(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16位饱和减法 D = Sa - Sb
	int32_t tmp;
	tmp = (int32_t)(*Sa) - (int32_t)(*Sb);
	if(tmp >= SHRT_MAX)
		tmp = SHRT_MAX;
	if(tmp <= SHRT_MIN)
		tmp = SHRT_MIN;
	*D = tmp;
}
void DSUB(int32_t *Sa, int32_t *Sb, int32_t *D) reentrant{//32位非饱和减法 D = Sa - Sb
	*D = (int32_t)(*Sa) - (int32_t)(*Sb);
}
void MULT(int16_t *Sa, int16_t *Sb, int32_t *D) reentrant{//16*16->16非饱和乘法 D = Sa * Sb
	int32_t tmp;
	tmp = (int32_t)(*Sa) * (int32_t)(*Sb);
	if(tmp >= SHRT_MAX)
		tmp = SHRT_MAX;
	if(tmp <= SHRT_MIN)
		tmp = SHRT_MIN;
	*D = tmp;
}
void MULTS(int16_t *Sa, int16_t *Sb, int32_t *D) reentrant{//16*16->32饱和乘法 D = Sa * Sb
	*D = (int32_t)(*Sa) * (int32_t)(*Sb);
}
/*****************************************************************************/