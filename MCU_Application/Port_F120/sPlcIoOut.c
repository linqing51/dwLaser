#include "sPlcIoOut.h"
/*****************************************************************************/
void outputInit(void){//IO输出初始化
#if CONFIG_SPLC_USING_IO_OUTPUT == 1	
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
	P2 |= (1 << 5);//74HC573 LE = 1
	P3 &= ~(1 << 4);//74HC573 OE = 0
	SFRPAGE = SFRPAGE_SAVE;
#endif
}

void outputRefresh(void){//设置输出IO
	//YOUT0
	data uint8_t SFRPAGE_SAVE; 
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
		P3 &= ~(uint8_t)(1 << 6);
	}
	//YOUT2
	if((NVRAM0[Y_START] >> 2) & 0x01){//P3_7
		P3 |= (uint8_t)(1 << 7);
	}
	else{
		P3 &= ~(uint8_t)(1 << 7);
	}
	//YOUT3
	if((NVRAM0[Y_START] >> 3) & 0x01){//P2_0
		P2 |= 0x01;
	}
	else{
		P2 &= 0xFE;
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
	SFRPAGE = SFRPAGE_SAVE;
}