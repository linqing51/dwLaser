#include <dac8568_3.h>
/*****************************************************************************/
/*****************************************************************************/
static void setSYNC3(uint8_t dat){//4_3
	if(dat){
		P4 |= (uint8_t)(1 << 3);
	}
	else{
		P4 &= ~(uint8_t)(1 << 3);
	}
}
static void setCLK3(uint8_t dat){//P4_0
	if(dat){
		P4 |= (uint8_t)(1 << 0);
	}
	else{
		P4 &= ~(uint8_t)(1 << 0);
	}
}
static void setDIN3(uint8_t dat){//P4_1
	if(dat){
		P4 |= (uint8_t)(1 << 1);
	}
	else{
		P4 &= ~(uint8_t)(1 << 1);
	}
}
static void setCLR3(uint8_t dat){//P4_2
	if(dat){
		P4 |= (uint8_t)(1 << 2);
	}
	else{
		P4 &= ~(uint8_t)(1 << 2);
	}
}
static void setLDAC3(uint8_t dat){//P4_4
	if(dat){
		P4 |= (uint8_t)(1 << 4);
	}
	else{
		P4 &= ~(uint8_t)(1 << 4);
	}
}
static void spi3Write(uint32_t dat){//DAC8568 SPI写入
	uint8_t tmp, i;
	setSYNC3(true);
	_nop_();_nop_();_nop_();
	setCLK3(true);
	_nop_();_nop_();_nop_();
	setSYNC3(false);
	for(i = 0;i < 32;i ++){
		tmp = (uint8_t)(dat >> (31 - i)) & 0x01;
		setDIN3(tmp);
		_nop_();_nop_();_nop_();
		setCLK3(false);
		_nop_();_nop_();_nop_();
		setCLK3(true);
	}
	_nop_();_nop_();_nop_();
	setSYNC3(true);
}
void dac8568_3_Init(void){//DAC8568初始化
	uint32_t tmp;
	setCLR3(true);
	setLDAC3(false);
	if((RSTSRC & 0x02)){//上电复位
		tmp = 0x07000000;//Software Reset
		spi3Write(tmp);
		tmp = 0x08000001;////Write Sequence for Enabling Internal Reference (Static Mode)
		spi3Write(tmp);
		tmp = 0x05000000;//Clear all DAC outputs to zero scale (defaultmode)
		spi3Write(tmp);
	}
	else if(RSTSRC & 0x01){//硬件引脚复位
		tmp = 0x07000000;//Software Reset
		spi3Write(tmp);
		tmp = 0x08000001;////Write Sequence for Enabling Internal Reference (Static Mode)
		spi3Write(tmp);
		tmp = 0x05000000;//Clear all DAC outputs to zero scale (defaultmode)
		spi3Write(tmp);
	}
	else if(RSTSRC & 0x04){//时钟丢失检测器标志
	}
	else if(RSTSRC == 0x08){//看门狗复位 
	}
	else if(RSTSRC == 0x10){//软件强制复位和标志
		tmp = 0x07000000;//Software Reset
		spi3Write(tmp);
		tmp = 0x08000001;////Write Sequence for Enabling Internal Reference (Static Mode)
		spi3Write(tmp);
		tmp = 0x05000000;//Clear all DAC outputs to zero scale (defaultmode)
		spi3Write(tmp);
	}
}
void dac8568_3_WriteDacRegister(uint8_t ch, uint16_t dat){//写入输入寄存器并更新输出
	uint32_t tmp;
	ch &= 0x0F;
	tmp = 0x03000000;
	tmp |= (uint32_t)((uint32_t)ch << 20);
	tmp |= (uint32_t)((uint32_t)dat << 4);
	spi3Write(tmp);
}