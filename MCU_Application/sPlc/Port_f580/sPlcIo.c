#include "sPlcIo.h"
/*****************************************************************************/
static idata volatile int8_t inputFilter[(X_END - X_START + 1) * 16];//IO输入滤波器缓冲区
/*****************************************************************************/
void inputInit(void){//IO输入滤波器初始化
	memset(inputFilter, 0x0, (X_END - X_START + 1) * 16);
}
void outputInit(void){//IO输出初始化
#ifdef C8051F020
	
#endif
}
void inputRefresh(void){//获取输入IO
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
void outputRefresh(void){//设置输出IO
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