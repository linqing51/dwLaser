#include <dac8568_0.h>
/*****************************************************************************/
//AOUT0-7
/*****************************************************************************/
static void setSYNC(uint8_t dat){//P6_0
	if(dat){
		P6 |= (uint8_t)(1 << 0);
	}
	else{
		P6 &= ~(uint8_t)(1 << 0);
	}
}
static void setCLK(uint8_t dat){//P6_1
	if(dat){
		P6 |= (uint8_t)(1 << 1);
	}
	else{
		P6 &= ~(uint8_t)(1 << 1);
	}
}
static void setDIN(uint8_t dat){//P6_2
	if(dat){
		P6 |= (uint8_t)(1 << 2);
	}
	else{
		P6 &= ~(uint8_t)(1 << 2);
	}
}
static void setCLR(uint8_t dat){//P6_3
	if(dat){
		P6 |= (uint8_t)(1 << 3);
	}
	else{
		P6 &= ~(uint8_t)(1 << 3);
	}
}
static void setLDAC(uint8_t dat){//P5_7
	if(dat){
		P5 |= (uint8_t)(1 << 7);
	}
	else{
		P5 &= ~(uint8_t)(1 << 7);
	}
}
static void spiWrite(uint32_t dat){//DAC8568 SPI写入
	uint8_t tmp, i;
	setSYNC(true);
	_nop_();_nop_();_nop_();
	setCLK(true);
	_nop_();_nop_();_nop_();
	setSYNC(false);
	for(i = 0;i < 32;i ++){
		tmp = (uint8_t)(dat >> (31 - i)) & 0x01;
		setDIN(tmp);
		_nop_();_nop_();_nop_();
		setCLK(false);
		_nop_();_nop_();_nop_();
		setCLK(true);
	}
	_nop_();_nop_();_nop_();
	setSYNC(true);
}
void dac8568_0_Init(void){//DAC8568初始化
	uint32_t tmp = 0;
	setCLR(true);
	setLDAC(false);
	tmp = 0x1C000000;//Software Reset
	spiWrite(tmp);
	tmp = 0x08000001;////Write Sequence for Enabling Internal Reference (Static Mode)
	spiWrite(tmp);
	tmp = 0x14000000;//Clear all DAC outputs to zero scale (defaultmode)
	spiWrite(tmp);
	tmp = 0x14000003;//CLR引脚屏蔽
	spiWrite(tmp);
}
void dac8568_0_Update(uint8_t ch){//更新UPDATA寄存器
	uint32_t tmp = 0;
	tmp |= (uint32_t)ch & 0x000000FF;
	tmp |= 0x18000000;
	spiWrite(tmp);
}
void dac8568_0_WriteInputRegister(uint8_t ch, uint16_t dat){//写入输入寄存器
	uint32_t tmp = 0;
	tmp |= (uint32_t)((uint32_t)ch << 20);
	tmp |= (uint32_t)((uint32_t)dat << 4);
	spiWrite(tmp);
}
void dac8568_0_WriteDacRegister(uint8_t ch, uint16_t dat){//写入输入寄存器并更新输出
	uint32_t tmp = 0;
	tmp |= (uint32_t)(1 << 25);
	tmp |= (uint32_t)((uint32_t)ch << 20);
	tmp |= (uint32_t)((uint32_t)dat << 4);
	spiWrite(tmp);
}
void dac8568_0_Clear(void){//清除所有寄存器
	uint32_t tmp;
	tmp = 0x14000000;//Clear all DAC outputs to zero scale (defaultmode)
	spiWrite(tmp);
}
void dac8568_0_Reset(void){//复位	
	uint32_t tmp;
	tmp = 0x1C000000;//Software Reset
	spiWrite(tmp);
}