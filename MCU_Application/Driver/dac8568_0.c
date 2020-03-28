#include <dac8568_0.h>
/*****************************************************************************/
//AOUT0-7
/*****************************************************************************/
static void setSYNC0(uint8_t dat){//P6_0
	if(dat){
		P6 |= (uint8_t)(1 << 0);
	}
	else{
		P6 &= ~(uint8_t)(1 << 0);
	}
}
static void setCLK0(uint8_t dat){//P6_1
	if(dat){
		P6 |= (uint8_t)(1 << 1);
	}
	else{
		P6 &= ~(uint8_t)(1 << 1);
	}
}
static void setDIN0(uint8_t dat){//P6_2
	if(dat){
		P6 |= (uint8_t)(1 << 2);
	}
	else{
		P6 &= ~(uint8_t)(1 << 2);
	}
}
static void setCLR0(uint8_t dat){//P6_3
	if(dat){
		P6 |= (uint8_t)(1 << 3);
	}
	else{
		P6 &= ~(uint8_t)(1 << 3);
	}
}
static void setLDAC0(uint8_t dat){//P5_7
	if(dat){
		P5 |= (uint8_t)(1 << 7);
	}
	else{
		P5 &= ~(uint8_t)(1 << 7);
	}
}
static void spi0Write(uint32_t dat){//DAC8568 SPI写入
	uint8_t tmp, i;
	setSYNC0(true);
	_nop_();_nop_();_nop_();
	setCLK0(true);
	_nop_();_nop_();_nop_();
	setSYNC0(false);
	for(i = 0;i < 32;i ++){
		tmp = (uint8_t)(dat >> (31 - i)) & 0x01;
		setDIN0(tmp);
		_nop_();_nop_();_nop_();
		setCLK0(false);
		_nop_();_nop_();_nop_();
		setCLK0(true);
	}
	_nop_();_nop_();_nop_();
	setSYNC0(true);
}
void dac8568_0_Init(void){//DAC8568初始化
	uint32_t tmp;
	setCLR0(true);
	setLDAC0(false);
	tmp = 0x07000000;//Software Reset
	spi0Write(tmp);
	tmp = 0x08000001;//Write Sequence for Enabling Internal Reference (Static Mode)
	spi0Write(tmp);
	tmp = 0x05000000;//Clear all DAC outputs to zero scale (defaultmode)
	spi0Write(tmp);
}
void dac8568_0_WriteDacRegister(uint8_t ch, uint16_t dat){//写入输入寄存器并更新输出
	uint32_t tmp;
	ch &= 0x0F;
	tmp = 0x03000000;
	tmp |= (uint32_t)((uint32_t)ch << 20);
	tmp |= (uint32_t)((uint32_t)dat << 4);
	spi0Write(tmp);
}