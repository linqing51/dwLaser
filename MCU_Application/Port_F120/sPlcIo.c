#include "sPlcIo.h"
/*****************************************************************************/
static volatile int8_t inputFilter[(X_END - X_START + 1) * 16];//IO输入滤波器缓冲区
/*****************************************************************************/
void inputInit(void){//IO输入滤波器初始化
	uint8_t SFRPAGE_SAVE = SFRPAGE;
	SFRPAGE = CPT0_PAGE;   
	CPT0MD = 0;
	CPT0CN = 0;
	CPT0CN |= 1 << 0;//Negative Hysteresis = 15 mV.
	CPT0CN |= 1 << 1;//Negative Hysteresis = 15 mV.
	CPT0CN |= 1 << 2;//Positive Hysteresis = 15 mV.
	CPT0CN |= 1 << 3;//Positive Hysteresis = 15 mV.
	CPT0CN |= 1 << 7;//Comparator0 Enabled.
	SFRPAGE = CPT1_PAGE;
	CPT1MD = 0;
	CPT1CN = 0;
	CPT1CN |= 1 << 0;//Negative Hysteresis = 15 mV.
	CPT1CN |= 1 << 1;//Negative Hysteresis = 15 mV.
	CPT1CN |= 1 << 2;//Positive Hysteresis = 15 mV.
	CPT1CN |= 1 << 3;//Positive Hysteresis = 15 mV.
	CPT1CN |= 1 << 7;//Comparator0 Enabled.
	SFRPAGE = SFRPAGE_SAVE;
	memset(inputFilter, 0x0, (X_END - X_START + 1) * 16);
}
void outputInit(void){//IO输出初始化
	uint8_t SFRPAGE_SAVE = SFRPAGE;
	SFRPAGE = CONFIG_PAGE;
	P3 &= ~(1 << 5);//Y5
	P3 &= ~(1 << 6);//Y6
	P3 &= ~(1 << 7);//Y7
	P2 &= ~(1 << 0);//Y3
	P2 &= ~(1 << 1);//Y4
	P2 &= ~(1 << 2);//Y5
	P2 &= ~(1 << 3);//Y5
	P2 &= ~(1 << 4);//Y7
	P6 &= ~(1 << 3);//Y8
	P6 &= ~(1 << 4);//Y9
	P6 &= ~(1 << 2);//Y10
	P6 &= ~(1 << 1);//Y11
	P6 &= ~(1 << 0);//Y12
	P5 &= ~(1 << 7);//Y13
	P5 &= ~(1 << 6);//Y14
	SFRPAGE = SFRPAGE_SAVE;
}
void inputRefresh(void){//获取输入IO
	uint8_t SFRPAGE_SAVE, temp; 
	//XIN0 P3_3
	SFRPAGE_SAVE = SFRPAGE;
	SFRPAGE = CONFIG_PAGE;
	temp = ((P3 >> 3) & 0x01);
	SFRPAGE = SFRPAGE_SAVE;
	if(temp){
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
	//XIN1 P3_2
	SFRPAGE = CONFIG_PAGE;
	temp = ((P3 >> 2) & 0x01);
	SFRPAGE = SFRPAGE_SAVE;
	if(temp){
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
	//XIN2 P3_1
	SFRPAGE = CONFIG_PAGE;
	temp = ((P3 >> 1) & 0x01);
	SFRPAGE = SFRPAGE_SAVE;
	if(temp){
		if(inputFilter[1] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[1] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 2);
		}
	}
	else{
		if(inputFilter[1] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[1] --;
		}
		else{
			NVRAM0[X_START] &= ~(uint16_t)(1 << 2);
		}
	}
	//XIN3 P3_0
	SFRPAGE = CONFIG_PAGE;
	temp = ((P3 >> 0) & 0x01);
	SFRPAGE = SFRPAGE_SAVE;
	if(temp){
		if(inputFilter[1] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[1] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 3);
		}
	}
	else{
		if(inputFilter[1] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[1] --;
		}
		else{
			NVRAM0[X_START] &= ~(uint16_t)(1 << 3);
		}
	}
	//XIN4
	SFRPAGE = CONFIG_PAGE;
	temp = ((P4 >> 1) & 0x01);
	SFRPAGE = SFRPAGE_SAVE;
	if(temp){
		if(inputFilter[1] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[1] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 4);
		}
	}
	else{
		if(inputFilter[1] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[1] --;
		}
		else{
			NVRAM0[X_START] &= ~(uint16_t)(1 << 4);
		}
	}	
	//XIN5
	SFRPAGE = CONFIG_PAGE;
	temp = ((P4 >> 0) & 0x01);
	SFRPAGE = SFRPAGE_SAVE;
	if(temp){
		if(inputFilter[1] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[1] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 5);
		}
	}
	else{
		if(inputFilter[1] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[1] --;
		}
		else{
			NVRAM0[X_START] &= ~(uint16_t)(1 << 5);
		}
	}
	//XIN6 光纤探测0
	SFRPAGE = CPT0_PAGE;  
	temp = ((CPT0CN >> 6) & 0x01);
	if(temp){
		if(inputFilter[1] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[1] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 6);
		}
	}
	else{
		if(inputFilter[1] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[1] --;
		}
		else{
			NVRAM0[X_START] &= ~(uint16_t)(1 << 6);
		}
	}	
	//XIN7 光纤探测1
	SFRPAGE = CPT1_PAGE;  
	temp = ((CPT1CN >> 6) & 0x01);
	if(temp){
		if(inputFilter[1] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[1] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 7);
		}
	}
	else{
		if(inputFilter[1] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[1] --;
		}
		else{
			NVRAM0[X_START] &= ~(uint16_t)(1 << 7);
		}
	}	
	SFRPAGE = SFRPAGE_SAVE;
}
void outputRefresh(void){//设置输出IO
	//YOUT0
	uint8_t SFRPAGE_SAVE; 
	SFRPAGE_SAVE = SFRPAGE;
	SFRPAGE = CONFIG_PAGE;
	if((NVRAM0[Y_START] >> 0) & 0x01){//P3_5
		P3 |= (uint8_t)(1 << 5);
	}
	else{
		P3 &= ~(uint8_t)(1 << 5);
	}
	//YOUT1
	if((NVRAM0[Y_START] >> 1) & 0x01){//P3_6
		P3 |= (uint8_t)(1 << 6);
	}
	else{
		P6 &= ~(uint8_t)(1 << 6);
	}
	//YOUT2
	if((NVRAM0[Y_START] >> 2) & 0x01){//P3_7
		P3 |= (uint8_t)(1 << 7);
	}
	else{
		P6 &= ~(uint8_t)(1 << 7);
	}
	//YOUT3
	if((NVRAM0[Y_START] >> 3) & 0x01){//P2_0
		P2 |= (uint8_t)(1 << 0);
	}
	else{
		P2 &= ~(uint8_t)(1 << 0);
	}
	//YOUT4
	if((NVRAM0[Y_START] >> 4) & 0x01){//P2_1
		P2 |= (uint8_t)(1 << 1);
	}
	else{
		P2 &= ~(uint8_t)(1 << 1);
	}
	//YOUT5
	if((NVRAM0[Y_START] >> 5) & 0x01){//P2_2
		P2 |= (uint8_t)(1 << 2);
	}
	else{
		P2 &= ~(uint8_t)(1 << 2);
	}	
	//YOUT6
	if((NVRAM0[Y_START] >> 6) & 0x01){//P2_3
		P2 |= (uint8_t)(1 << 3);
	}
	else{
		P2 &= ~(uint8_t)(1 << 3);
	}
	//YOUT7
	if((NVRAM0[Y_START] >> 7) & 0x01){//P2_4
		P2 |= (uint8_t)(1 << 4);
	}
	else{
		P2 &= ~(uint8_t)(1 << 4);
	}
	//YOUT8
	if((NVRAM0[Y_START] >> 8) & 0x01){//P6_3
		P6 |= (uint8_t)(1 << 3);
	}
	else{
		P6 &= ~(uint8_t)(1 << 3);
	}	
	//YOUT9
	if((NVRAM0[Y_START] >> 9) & 0x01){//P6_4
		P6 |= (uint8_t)(1 << 4);
	}
	else{
		P6 &= ~(uint8_t)(1 << 4);
	}
	//YOUT10
	if((NVRAM0[Y_START] >> 10) & 0x01){//P6_2
		P6 |= (uint8_t)(1 << 2);
	}
	else{
		P6 &= ~(uint8_t)(1 << 2);
	}	
	//YOUT11
	if((NVRAM0[Y_START] >> 11) & 0x01){//P6_1
		P6 |= (uint8_t)(1 << 1);
	}
	else{
		P6 &= ~(uint8_t)(1 << 1);
	}
	//YOUT12
	if((NVRAM0[Y_START] >> 12) & 0x01){//P6_0
		P6 |= (uint8_t)(1 << 0);
	}
	else{
		P6 &= ~(uint8_t)(1 << 0);
	}
	//YOUT13
	if((NVRAM0[Y_START] >> 13) & 0x01){//P5_7
		P5 |= (uint8_t)(1 << 7);
	}
	else{
		P5 &= ~(uint8_t)(1 << 7);
	}
	//YOUT14
	if((NVRAM0[Y_START] >> 13) & 0x01){//P5_6
		P5 |= (uint8_t)(1 << 6);
	}
	else{
		P5 &= ~(uint8_t)(1 << 6);
	}
	SFRPAGE = SFRPAGE_SAVE;
}