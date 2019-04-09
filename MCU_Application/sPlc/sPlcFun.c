#include "sPlc.h"
/*****************************************************************************/
void REBOOT(void) reentrant{//软件复位	
	mucReboot();
}
void ORG(uint16_t A) reentrant{
}
//位指令
void OUT(uint16_t A) reentrant{
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
	uint8_t res = 0;
	assertCoilAddress(A);//检查地址范围
	res = (uint8_t)((uint16_t)NVRAM0[(A / 16)] >> (A % 16)) & 0x01;
	if(res)
		return true;
	else
		return false;
}
uint8_t LDB(uint16_t A) reentrant{//反向载入
	uint8_t res = 0;
	assertCoilAddress(A);//检查地址范围
	res = ((uint8_t)((uint16_t)NVRAM0[(A / 16)] >> (A % 16)) & 0x01);
	if(res)
		return false;
	else
		return true;
}
uint8_t LDP(uint16_t A) reentrant{//脉冲上升沿
	uint8_t temp0 = 0, temp1 = 0;
	assertCoilAddress(A);//检查地址范围
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> (A % 16)) & 0x01;
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> (A % 16)) & 0x01;
	if(temp0 == 1 && temp1 != 1)
		return true;
	else
		return false;
}
uint8_t LDN(uint16_t A) reentrant{//脉冲下降沿
	uint8_t temp0 = 0, temp1 = 0;
	assertCoilAddress(A);
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> NVRAM0[(A % 16)]);
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> NVRAM1[(A % 16)]);
	if(!temp0 && temp1)
		return true;
	else
		return false;
}
/*****************************************************************************/
//延时器指令
void T100US(uint8_t A, uint8_t start, uint16_t value) reentrant{//100US延时器
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
/*****************************************************************************/
//计算指令
void TNTC(int16_t *dist, int16_t *src) reentrant{//CODE转换为NTC测量温度温度
	uint16_t temp;
	fp32_t ftemp;
	if(*src >= CONFIG_ADC_INTERNAL_VREF) *src = CONFIG_ADC_INTERNAL_VREF;//限制输入最大值
	if(*src < 0) *src = 0;
	temp = (int16_t)(CONFIG_ADC_INTERNAL_VREF * (*src) / 4096);//单位mV
	temp = (uint16_t)(CONFIG_NTC_RS * (CONFIG_NTC_VREF - temp) / temp);
	ftemp = ((1.0 / CONFIG_NTC_B) * log((fp32_t)(temp) / 10000)) + (1 / (CONFIG_ADC_AMBIENT + 273.0));//limo R25=10740,B=3450	 uniquemode 3988
	ftemp = ( 1.0 / ftemp ) - 273.0;
	if(ftemp >= 100) ftemp = 100;
	if(ftemp <= -100) ftemp = -100;
	*dist = (int16_t)(ftemp * 10);
}
void TENV(int16_t *dist, int16_t *src) reentrant{//CODE转换为环境温度
	int16_t temp;
	temp = (int16_t)(CONFIG_ADC_INTERNAL_VREF * (*src) / 4096);//单位mV
	temp = (int16_t)((temp - CONFIG_ADC_TEMP_SENSOR_OFFSET) * 1000 / CONFIG_ADC_TEMP_SENSOR_GAIN);
	*dist = temp;
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
void ABS16(int16_t *dist, int16_t *src) reentrant{//16位数球绝对值
	if(*src >= 0){
		*dist = *src;
	}
	else{
		*dist = ((*src) * -1);
	}
}
void ABS32(int32_t *dist, int32_t *src) reentrant{//32位数求绝对值
	if(*src >= 0){
		*dist = *src;
	}
	else{
		*dist = ((*src) * -1);
	}
}
void SWAP(int16_t *dist, int32_t *src) reentrant{//交换A的高低字节
	uint16_t tmpL = 0, tmpH = 0;
	tmpL = (*src & 0x00FF);
	tmpH = ((*src >> 8) & 0x00FF);
	tmpH |= tmpL;
	*dist = tmpH;
}
/*****************************************************************************/
//表格指令
void XTAB(int16_t *distY, int16_t *srcX, int16_t *index, int16_t *length) reentrant{//线性查表从X计算Y值
	fp32_t x0, x1, y0, y1, k, b, x, y;
	uint16_t i;
	for(i = 0;i < *length;i ++){
		if(*(index + i) >= *srcX){
			break;
		}
	}
	if(i == 0){
		*distY = *(index + *length);//开始位置
	}
	else if(i >= *length){//结束为止
		*distY = *(index + *length + *length);
	}
	else{//中间插补位置
		x0 = (fp32_t)*(index + i);
		x1 = (fp32_t)*(index + i + 1);
		y0 = (fp32_t)*(index + i + *length);
		y1 = (fp32_t)*(index + i + 1 + *length);
		//求解直线方程
		k = (y1 - y0) / (x1 - x0);
		b = y0 - k * x0;
		x = (fp32_t)(*srcX);
		y = k * x + b;
		*distY = (int16_t)y;
	}
}
void YTAB(int16_t *distX, int16_t *srcY, int16_t *index, int16_t *length) reentrant{//线性查表从Y计算X值
	int16_t x0, x1, y0, y1;
	uint16_t i;
	fp32_t k, b, x, y;
	for(i = 0;i < *length;i ++){
		if(*(index + *length + i) >= *srcY){
			break;
		}
	}
	if(i == 0){
		*distX = *index;//开始位置
	}
	else if(i >= *length){//结束为止
		*distX = *(index + *length);
	}
	else{//中间插补位置
		x0 = *(index + i);
		x1 = *(index + i + 1);
		y0 = *(index + i + *length);
		y1 = *(index + i + 1 + *length);
		//求解直线方程
		k = ((fp32_t)y1 - (fp32_t)y0) / ((fp32_t)x1 - (fp32_t)x0);
		b = y0 - k * x0;
		y = (fp32_t)(*srcY);
		x = (y - b) / k;
		*distX = (int16_t)x;
	}
}

void APID(int16_t *fb, int16_t *tab){//绝对PID指令

}
void FPID(int16_t *fb, int16_t *tab){//自适应PID指令
}
/*****************************************************************************/
//IO指令
void IMDIO(void) reentrant{//立即更新IO点状态含输入输出

}
/*****************************************************************************/
//步指令
void TO(uint16_t SA) reentrant{//步进开始指令
}
void STP(uint16_t SA) reentrant{//步进指令
}
void STPEND(void) reentrant{//步进结束指令
}
void FROM(uint16_t SA) reentrant{//步进执行指令
}