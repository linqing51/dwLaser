#include <dac8568_2.h>
/*****************************************************************************/
/*****************************************************************************/
static void setSYNC2(uint8_t dat){//P4_6
	if(dat){
		P4 |= (uint8_t)(1 << 3);
	}
	else{
		P4 &= ~(uint8_t)(1 << 3);
	}
}
static void setCLK2(uint8_t dat){//P4_7
	if(dat){
		P4 |= (uint8_t)(1 << 4);
	}
	else{
		P4 &= ~(uint8_t)(1 << 4);
	}
}
static void setDIN2(uint8_t dat){//P5_0
	if(dat){
		P4 |= (uint8_t)(1 << 5);
	}
	else{
		P4 &= ~(uint8_t)(1 << 5);
	}
}
//static void setCLR2(uint8_t dat){//P5_1
//	if(dat){
//		P5 |= (uint8_t)(1 << 1);
//	}
//	else{
//		P5 &= ~(uint8_t)(1 << 1);
//	}
//}
//static void setLDAC2(uint8_t dat){//P4_5
//	if(dat){
//		P4 |= (uint8_t)(1 << 5);
//	}
//	else{
//		P4 &= ~(uint8_t)(1 << 5);
//	}
//}
static void spi2Write(uint32_t dat){//DAC8568 SPI写入
	uint8_t tmp, i;
	setSYNC2(true);
	_nop_();_nop_();_nop_();
	setCLK2(true);
	_nop_();_nop_();_nop_();
	setSYNC2(false);
	for(i = 0;i < 32;i ++){
		tmp = (uint8_t)(dat >> (31 - i)) & 0x01;
		setDIN2(tmp);
		_nop_();_nop_();_nop_();
		setCLK2(false);
		_nop_();_nop_();_nop_();
		setCLK2(true);
	}
	_nop_();_nop_();_nop_();
	setSYNC2(true);
}
void dac8568_2_Init(void){//DAC8568初始化
	uint32_t tmp;
	//setCLR2(true);
	//setLDAC2(true);
	tmp = 0x07000000;//Software Reset
	spi2Write(tmp);
	tmp = 0x08000001;//Write Sequence for Enabling Internal Reference (Static Mode)
	spi2Write(tmp);
	//覆盖LDAC引脚
	tmp = 0x0600000F;
	spi2Write(tmp);
	//覆盖CLR引脚
	tmp = 0x05000003;
	spi2Write(tmp);
}
void dac8568_2_InitNoReset(void){//DAC8568初始化
	uint32_t tmp;
	//setCLR2(true);
	//setLDAC2(true);
	tmp = 0x08000001;//Write Sequence for Enabling Internal Reference (Static Mode)
	spi2Write(tmp);
	//覆盖LDAC引脚
	tmp = 0x0600000F;
	spi2Write(tmp);
	//覆盖CLR引脚
	tmp = 0x05000003;
	spi2Write(tmp);
}
void dac8568_2_WriteDacRegister(uint8_t ch, uint16_t dat){//写入输入寄存器并更新输出
	uint32_t tmp;
	ch &= 0x0F;
	tmp = 0x03000000;
	tmp |= (uint32_t)((uint32_t)ch << 20);
	tmp |= (uint32_t)((uint32_t)dat << 4);
	spi2Write(tmp);
}