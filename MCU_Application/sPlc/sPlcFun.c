#include "sPlc.h"
/*****************************************************************************/
void REBOOT(void) reentrant{//�����λ	
	mucReboot();
}
void ORG(uint16_t A) reentrant{
}
//λָ��
void OUT(uint16_t A) reentrant{
}
void SET(uint16_t A) reentrant{//��Ȧ��λ
	assertCoilAddress(A);//����ַ��Χ
	NVRAM0[(A / 16)] |= 1 << (A % 16);
}
void RES(uint16_t A) reentrant{//��Ȧ����
	assertCoilAddress(A);//����ַ��Χ
	NVRAM0[(A / 16)] &= ~(1 << (A % 16));
}
void FLIP(uint16_t A) reentrant{//��ת
	uint16_t temp;
	assertCoilAddress(A);//����ַ��Χ
	temp= NVRAM0[(A / 16)] & (1 << (A % 16));
	if(temp)
		RES(A);
	else
		SET(A);
}
uint8_t LD(uint16_t A) reentrant{//����
	uint8_t res = 0;
	assertCoilAddress(A);//����ַ��Χ
	res = (uint8_t)((uint16_t)NVRAM0[(A / 16)] >> (A % 16)) & 0x01;
	if(res)
		return true;
	else
		return false;
}
uint8_t LDB(uint16_t A) reentrant{//��������
	uint8_t res = 0;
	assertCoilAddress(A);//����ַ��Χ
	res = ((uint8_t)((uint16_t)NVRAM0[(A / 16)] >> (A % 16)) & 0x01);
	if(res)
		return false;
	else
		return true;
}
uint8_t LDP(uint16_t A) reentrant{//����������
	uint8_t temp0 = 0, temp1 = 0;
	assertCoilAddress(A);//����ַ��Χ
	temp0 = (uint8_t)(NVRAM0[(A / 16)] >> (A % 16)) & 0x01;
	temp1 = (uint8_t)(NVRAM1[(A / 16)] >> (A % 16)) & 0x01;
	if(temp0 == 1 && temp1 != 1)
		return true;
	else
		return false;
}
uint8_t LDN(uint16_t A) reentrant{//�����½���
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
//��ʱ��ָ��
void T100US(uint8_t A, uint8_t start, uint16_t value) reentrant{//100US��ʱ��
}
void T1MS(uint8_t A, uint8_t start, uint16_t value) reentrant{//1MS��ʱ��
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
void T10MS(uint8_t A, uint8_t start, uint16_t value) reentrant{//10MS��ʱ��
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
void T100MS(uint8_t A, uint8_t start, uint16_t value) reentrant{//100MS��ʱ��
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
//����ָ��
void TNTC(int16_t *dist, int16_t *src) reentrant{//CODEת��ΪNTC�����¶��¶�
	uint16_t temp;
	fp32_t ftemp;
	if(*src >= CONFIG_ADC_INTERNAL_VREF) *src = CONFIG_ADC_INTERNAL_VREF;//�����������ֵ
	if(*src < 0) *src = 0;
	temp = (int16_t)(CONFIG_ADC_INTERNAL_VREF * (*src) / 4096);//��λmV
	temp = (uint16_t)(CONFIG_NTC_RS * (CONFIG_NTC_VREF - temp) / temp);
	ftemp = ((1.0 / CONFIG_NTC_B) * log((fp32_t)(temp) / 10000)) + (1 / (CONFIG_ADC_AMBIENT + 273.0));//limo R25=10740,B=3450	 uniquemode 3988
	ftemp = ( 1.0 / ftemp ) - 273.0;
	if(ftemp >= 100) ftemp = 100;
	if(ftemp <= -100) ftemp = -100;
	*dist = (int16_t)(ftemp * 10);
}
void TENV(int16_t *dist, int16_t *src) reentrant{//CODEת��Ϊ�����¶�
	int16_t temp;
	temp = (int16_t)(CONFIG_ADC_INTERNAL_VREF * (*src) / 4096);//��λmV
	temp = (int16_t)((temp - CONFIG_ADC_TEMP_SENSOR_OFFSET) * 1000 / CONFIG_ADC_TEMP_SENSOR_GAIN);
	*dist = temp;
}
void ADD16(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16λ�Ǳ��ͼӷ� D = Sa + Sb
	*D = *Sa + *Sb;
}
void ADDS16(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16λ���ͼӷ� D = Sa + Sb
	int32_t tmp;
	tmp =*Sa + *Sb;;
	if(tmp >= SHRT_MAX)
		tmp = SHRT_MAX;
	if(tmp <= SHRT_MIN)
		tmp = SHRT_MIN;
	*D = tmp;
}
void ADD32(int32_t *Sa, int32_t *Sb, int32_t *D) reentrant{//32λ�Ǳ��ӷ� D = Sa + Sb
	*D = *Sa + *Sb;
}
void SUB16(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16λ�Ǳ��ͼ��� D = Sa - Sb
	*D = *Sa - *Sb;
}
void SUBS16(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16λ���ͼ��� D = Sa - Sb
	int32_t tmp;
	tmp = (int32_t)(*Sa) - (int32_t)(*Sb);
	if(tmp >= SHRT_MAX)
		tmp = SHRT_MAX;
	if(tmp <= SHRT_MIN)
		tmp = SHRT_MIN;
	*D = tmp;
}
void SUB32(int32_t *Sa, int32_t *Sb, int32_t *D) reentrant{//32λ�Ǳ��ͼ��� D = Sa - Sb
	*D = (int32_t)(*Sa) - (int32_t)(*Sb);
}
void MULT16(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16*16->16�Ǳ��ͳ˷� D = Sa * Sb
	int32_t tmp;
	tmp = (int32_t)(*Sa) * (int32_t)(*Sb);
	*D = (int16_t)(tmp & 0xFFFF);
}
void MULTS16(int16_t *Sa, int16_t *Sb, int16_t *D) reentrant{//16*16->16���ͳ˷� D = Sa * Sb
	int32_t tmp;
	tmp = (int32_t)(*Sa) * (int32_t)(*Sb);
	if(tmp >= SHRT_MAX)
		tmp = SHRT_MAX;
	if(tmp <= SHRT_MIN)
		tmp = SHRT_MIN;
	*D = (int16_t)tmp;
}
void MULT32(int16_t *Sa, int16_t *Sb, int32_t *D) reentrant{//16*16->32�Ǳ��ͳ˷� D = Sa * Sb
	*D = (int32_t)(*Sa) * (int32_t)(*Sb);
}
void SUM16(int16_t *index, int16_t *length, int32_t *sum) reentrant{//16BIT�����->32BIT
	int32_t tmp = 0;
	uint16_t i = 0;
	for(i = 0; i < *length; i++)
	{
		tmp += *(index + i);
	}
	*sum = tmp;
}
void UMAX16(uint16_t *index, uint16_t *length, uint16_t *max) reentrant{//16λ�޷������������ֵ
	uint16_t i = 0;
	uint16_t tmp = 0;
	for(i = 0;i < *length;i ++ ){
		if(tmp < *(index + i)){
			tmp = *(index + i);
		}
	}
	*max = tmp;
}
void UMIN16(uint16_t *index, uint16_t *length, uint16_t *min)reentrant{//16λ�޷�����������Сֵ
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
void SMAX16(int16_t *index, uint16_t *length, int16_t *max) reentrant{//16λ�з������������ֵ
	int16_t i = 0;
	int16_t tmp = 0;
	for(i = 0;i < *length;i ++ ){
		if(tmp < *(index + i)){
			tmp = *(index + i);
		}
	}
	*max = tmp;
}
void SMIN16(int16_t *index, uint16_t *length, int16_t *min) reentrant{//16λ�з�����������Сֵ
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
void ABS16(int16_t *dist, int16_t *src) reentrant{//16λ�������ֵ
	if(*src >= 0){
		*dist = *src;
	}
	else{
		*dist = ((*src) * -1);
	}
}
void ABS32(int32_t *dist, int32_t *src) reentrant{//32λ�������ֵ
	if(*src >= 0){
		*dist = *src;
	}
	else{
		*dist = ((*src) * -1);
	}
}
void SWAP(int16_t *dist, int32_t *src) reentrant{//����A�ĸߵ��ֽ�
	uint16_t tmpL = 0, tmpH = 0;
	tmpL = (*src & 0x00FF);
	tmpH = ((*src >> 8) & 0x00FF);
	tmpH |= tmpL;
	*dist = tmpH;
}
/*****************************************************************************/
//���ָ��
void XTAB(int16_t *distY, int16_t *srcX, int16_t *index, int16_t *length) reentrant{//���Բ���X����Yֵ
	fp32_t x0, x1, y0, y1, k, b, x, y;
	uint16_t i;
	for(i = 0;i < *length;i ++){
		if(*(index + i) >= *srcX){
			break;
		}
	}
	if(i == 0){
		*distY = *(index + *length);//��ʼλ��
	}
	else if(i >= *length){//����Ϊֹ
		*distY = *(index + *length + *length);
	}
	else{//�м�岹λ��
		x0 = (fp32_t)*(index + i);
		x1 = (fp32_t)*(index + i + 1);
		y0 = (fp32_t)*(index + i + *length);
		y1 = (fp32_t)*(index + i + 1 + *length);
		//���ֱ�߷���
		k = (y1 - y0) / (x1 - x0);
		b = y0 - k * x0;
		x = (fp32_t)(*srcX);
		y = k * x + b;
		*distY = (int16_t)y;
	}
}
void YTAB(int16_t *distX, int16_t *srcY, int16_t *index, int16_t *length) reentrant{//���Բ���Y����Xֵ
	int16_t x0, x1, y0, y1;
	uint16_t i;
	fp32_t k, b, x, y;
	for(i = 0;i < *length;i ++){
		if(*(index + *length + i) >= *srcY){
			break;
		}
	}
	if(i == 0){
		*distX = *index;//��ʼλ��
	}
	else if(i >= *length){//����Ϊֹ
		*distX = *(index + *length);
	}
	else{//�м�岹λ��
		x0 = *(index + i);
		x1 = *(index + i + 1);
		y0 = *(index + i + *length);
		y1 = *(index + i + 1 + *length);
		//���ֱ�߷���
		k = ((fp32_t)y1 - (fp32_t)y0) / ((fp32_t)x1 - (fp32_t)x0);
		b = y0 - k * x0;
		y = (fp32_t)(*srcY);
		x = (y - b) / k;
		*distX = (int16_t)x;
	}
}

void APID(int16_t *fb, int16_t *tab){//����PIDָ��

}
void FPID(int16_t *fb, int16_t *tab){//����ӦPIDָ��
}
/*****************************************************************************/
//IOָ��
void IMDIO(void) reentrant{//��������IO��״̬���������

}
/*****************************************************************************/
//��ָ��
void TO(uint16_t SA) reentrant{//������ʼָ��
}
void STP(uint16_t SA) reentrant{//����ָ��
}
void STPEND(void) reentrant{//��������ָ��
}
void FROM(uint16_t SA) reentrant{//����ִ��ָ��
}