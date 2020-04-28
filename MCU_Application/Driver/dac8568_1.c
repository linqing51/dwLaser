#include <dac8568_1.h>
/*****************************************************************************/
/*****************************************************************************/
static void setSYNC1(uint8_t dat){//P5_3
	if(dat){
		P4 |= (uint8_t)(1 << 6);
	}
	else{
		P4 &= ~(uint8_t)(1 << 6);
	}
}
static void setCLK1(uint8_t dat){//P5_4
	if(dat){
		P4 |= (uint8_t)(1 << 7);
	}
	else{
		P4 &= ~(uint8_t)(1 << 7);
	}
}
static void setDIN1(uint8_t dat){//P5_5
	if(dat){
		P5 |= (uint8_t)(1 << 0);
	}
	else{
		P5 &= ~(uint8_t)(1 << 0);
	}
}
static void spi1Write(uint32_t dat){//DAC8568 SPI写入
	uint8_t tmp, i;
	setSYNC1(true);
	_nop_();_nop_();_nop_();
	setCLK1(true);
	_nop_();_nop_();_nop_();
	setSYNC1(false);
	for(i = 0;i < 32;i ++){
		tmp = (uint8_t)(dat >> (31 - i)) & 0x01;
		setDIN1(tmp);
		_nop_();_nop_();_nop_();
		setCLK1(false);
		_nop_();_nop_();_nop_();
		setCLK1(true);
	}
	_nop_();_nop_();_nop_();
	setSYNC1(true);
}
void dac8568_1_Init(void){//DAC8568初始化
	uint32_t tmp;
	//setCLR1(true);
	//setLDAC1(true);	
	tmp = 0x07000000;//Software Reset
	spi1Write(tmp);
	tmp = 0x08000001;//Write Sequence for Enabling Internal Reference (Static Mode)
	spi1Write(tmp);
	//覆盖LDAC引脚
	tmp = 0x0600000F;
	spi1Write(tmp);
	//覆盖CLR引脚
	tmp = 0x05000003;
	spi1Write(tmp);
}
void dac8568_1_InitNoReset(void){//DAC8568初始化
	uint32_t tmp;
	//setCLR1(true);
	//setLDAC1(true);	
	tmp = 0x08000001;//Write Sequence for Enabling Internal Reference (Static Mode)
	spi1Write(tmp);
	//覆盖LDAC引脚
	tmp = 0x0600000F;
	spi1Write(tmp);
	//覆盖CLR引脚
	tmp = 0x05000003;
	spi1Write(tmp);
}
void dac8568_1_WriteDacRegister(uint8_t ch, uint16_t dat){//写入输入寄存器并更新输出
	uint32_t tmp;
	ch &= 0x0F;
	tmp = 0x03000000;
	tmp |= (uint32_t)((uint32_t)ch << 20);
	tmp |= (uint32_t)((uint32_t)dat << 4);
	spi1Write(tmp);
}
