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
void ADD16(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16位非饱和加法 D = Sa + Sb
	*D = *Sa + *Sb;
}
void ADDS16(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16位饱和加法 D = Sa + Sb
	int32_t tmp;
	tmp =*Sa + *Sb;;
	if(tmp >= SHRT_MAX)
		tmp = SHRT_MAX;
	if(tmp <= SHRT_MIN)
		tmp = SHRT_MIN;
	*D = tmp;
}
void ADD32(int32_t *Sa, int32_t *Sb, int32_t *D) reentrant{//32位非饱加法 D = Sa + Sb
	*D = *Sa + *Sb;
}
void SUB16(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16位非饱和减法 D = Sa - Sb
	*D = *Sa - *Sb;
}
void SUBS16(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16位饱和减法 D = Sa - Sb
	int32_t tmp;
	tmp = (int32_t)(*Sa) - (int32_t)(*Sb);
	if(tmp >= SHRT_MAX)
		tmp = SHRT_MAX;
	if(tmp <= SHRT_MIN)
		tmp = SHRT_MIN;
	*D = tmp;
}
void SUB32(int32_t *Sa, int32_t *Sb, int32_t *D) reentrant{//32位非饱和减法 D = Sa - Sb
	*D = (int32_t)(*Sa) - (int32_t)(*Sb);
}
void MULT16(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16*16->16非饱和乘法 D = Sa * Sb
	int32_t tmp;
	tmp = (int32_t)(*Sa) * (int32_t)(*Sb);
	*D = (int16_t)(tmp & 0xFFFF);
}
void MULTS16(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16*16->16饱和乘法 D = Sa * Sb
	int32_t tmp;
	tmp = (int32_t)(*Sa) * (int32_t)(*Sb);
	if(tmp >= SHRT_MAX)
		tmp = SHRT_MAX;
	if(tmp <= SHRT_MIN)
		tmp = SHRT_MIN;
	*D = (int16_t)tmp;
}
void MULT32(int16_t *Sa, int16_t *Sb, int32_t *D) reentrant{//16*16->32非饱和乘法 D = Sa * Sb
	*D = (int32_t)(*Sa) * (int32_t)(*Sb);
}
void SUM16(int16_t *index, int16_t *length, int32_t *sum) reentrant{//16BIT数求和->32BIT
	int32_t tmp = 0;
	uint16_t i = 0;
	for(i = 0; i < *length; i++)
	{
		tmp += *(index + i);
	}
	*sum = tmp;
}
void UMAX16(uint16_t *index, uint16_t *length, uint16_t *max) reentrant{//16位无符号数组找最大值
	uint16_t i = 0;
	uint16_t tmp = 0;
	for(i = 0;i < *length;i ++ ){
		if(tmp < *(index + i)){
			tmp = *(index + i);
		}
	}
	*max = tmp;
}
void UMIN16(uint16_t *index, uint16_t *length, uint16_t *min)reentrant{//16位无符号数组找最小值
	uint16_t i = 0;
	uint16_t tmp = 0;
	for(i = 0;i < *length;i ++){
		if(tmp < *(index + i))
		{
			tmp = *(index + i);
		}
	}
	*min = tmp;
}
void SMAX16(int16_t *index, uint16_t *length, int16_t *max) reentrant{//16位有符号数组找最大值
	int16_t i = 0;
	int16_t tmp = 0;
	for(i = 0;i < *length;i ++ ){
		if(tmp < *(index + i)){
			tmp = *(index + i);
		}
	}
	*max = tmp;
}
void SMIN16(int16_t *index, uint16_t *length, int16_t *min) reentrant{//16位有符号数组找最小值
	int16_t i = 0;
	int16_t tmp = 0;
	for(i = 0;i < *length;i ++){
		if(tmp < *(index + i))
		{
			tmp = *(index + i);
		}
	}
	*min = tmp;
}
/*****************************************************************************/
void XTAB(int16_t *x, int16_t *index, int16_t *length) reentrant{//线性查表从X计算Y值
	uint16_t xIndex0, xIndex1, i;
	xIndex0 = 0; xIndex1 = 0;
	for(i = 0;i < *length;i ++){
		xIndex1 ++;
//	}
	
}
void YTAB(int16_t *y, int16_t tab, int16_t *length) reentrant{//线性查表从Y计算X值

}




uint16_t linear_interp_x(linear_interp_table * psource, uint16_t y, uint16_t size)//get x from y
{
	uint16_t i = 0;
	float x = 0;
	for(i = 0; i < size; i++)
	{
		if(y <= psource[i].y )
		{
			break;
		}
	}
	if(i == 0)
	{
		x = (float)y *psource[i].x /psource[i].y;
	}
	else if(i == size)
				{
					x = psource[i-2].x + (float)(y - psource[i-2].y)*(psource[i-1].x - psource[i-2].x)/(psource[i-1].y - psource[i-2].y);
				}
				else
				{
					x = psource[i-1].x + (float)(y - psource[i-1].y)*(psource[i].x - psource[i-1].x)/(psource[i].y - psource[i-1].y);
				}
#if debug_math == 1
	rt_kprintf("linear_interp_y result x = %d,para y = %d\n ",(uint16_t)x,y);
#endif
	return (uint16_t)x;
}
/*****************************************************************************/
//IO指令
void IMDIO(void) reentrant{//立即更新IO点状态含输入输出

}
/*****************************************************************************/