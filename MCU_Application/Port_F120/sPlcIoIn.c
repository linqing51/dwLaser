#include "sPlcIoIn.h"
/*****************************************************************************/
data int8_t inputFilter[(X_END - X_START + 1) * 16];//IO ‰»Î¬À≤®∆˜ª∫≥Â«¯
/*****************************************************************************/
void inputInit(void){//IO ‰»Î¬À≤®∆˜≥ı ºªØ
#if CONFIG_SPLC_USING_IO_INPUT == 1
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
#endif
}

void inputRefresh(void){//ªÒ»° ‰»ÎIO
	data uint8_t SFRPAGE_SAVE;
	data uint8_t	temp; 
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
		if(inputFilter[2] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[2] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 2);
		}
	}
	else{
		if(inputFilter[2] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[2] --;
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
		if(inputFilter[3] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[3] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 3);
		}
	}
	else{
		if(inputFilter[3] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[3] --;
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
		if(inputFilter[4] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[4] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 4);
		}
	}
	else{
		if(inputFilter[4] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[4] --;
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
		if(inputFilter[5] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[5] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 5);
		}
	}
	else{
		if(inputFilter[5] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[5] --;
		}
		else{
			NVRAM0[X_START] &= ~(uint16_t)(1 << 5);
		}
	}
	//XIN6 π‚œÀÃΩ≤‚0
	SFRPAGE = CPT0_PAGE;  
	temp = CPT0CN >> 6;
	temp &= 0x01;
	if(!temp){
		if(inputFilter[6] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[6] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 6);
		}
	}
	else{
		if(inputFilter[6] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[6] --;
		}
		else{
			NVRAM0[X_START] &= ~(uint16_t)(1 << 6);
		}
	}	
	//XIN7 π‚œÀÃΩ≤‚1
	SFRPAGE = CPT1_PAGE;  
	temp = CPT0CN >> 6;
	temp &= 0x01;
	if(!temp){
		if(inputFilter[7] < CONFIG_INPUT_FILTER_TIME){
			inputFilter[7] ++;
		}
		else{
			NVRAM0[X_START] |= (int16_t)(1 << 7);
		}
	}
	else{
		if(inputFilter[7] > (CONFIG_INPUT_FILTER_TIME * -1)){
			inputFilter[7] --;
		}
		else{
			NVRAM0[X_START] &= ~(uint16_t)(1 << 7);
		}
	}	
	SFRPAGE = SFRPAGE_SAVE;
}