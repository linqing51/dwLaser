#include <dac8568_1.h>
/*****************************************************************************/
/*****************************************************************************/
static void setSYNC(uint8_t dat){
}
static void setCLK(uint8_t dat){
}
static void setDIN(uint8_t dat){
}
static void spiWrite(uint32_t dat){//DAC8568 SPIд��
	pdata uint8_t tmp, i;
	setSYNC(1);
	_nop_();_nop_();_nop_();
	setCLK(true);
	setSYNC(false);
	for(i = 0;i < 32;i ++){
		tmp = (uint8_t)((dat >> (31 - i)) & 0x01);
		setDIN(tmp);
		setCLK(false);
		_nop_();
		setCLK(true);
	}
	_nop_();
	setSYNC(true);
}

void dac8568_1_Init(void){//DAC8568��ʼ��
	pdata uint32_t tmp = 0;
	tmp = 0x1C000000;//Software Reset
	spiWrite(tmp);
	tmp = 0x08000001;////Write Sequence for Enabling Internal Reference (Static Mode)
	spiWrite(tmp);
	tmp = 0x14000000;//Clear all DAC outputs to zero scale (defaultmode)
	spiWrite(tmp);
	tmp = 0x14000003;//CLR��������
	spiWrite(tmp);
}
void dac8568_1_Update(uint8_t ch){//����UPDATA�Ĵ���
	pdata uint32_t tmp = 0;
	tmp |= (uint32_t)ch & 0x000000FF;
	tmp |= 0x18000000;
	spiWrite(tmp);
}
void dac8568_1_WriteInputRegister(uint8_t ch, uint16_t dat){//д������Ĵ���
	pdata uint32_t tmp = 0;
	tmp |= (uint32_t)((uint32_t)ch << 20);
	tmp |= (uint32_t)((uint32_t)dat << 4);
	spiWrite(tmp);
}
void dac8568_1_WriteDacRegister(uint8_t ch, uint16_t dat){//д������Ĵ������������
	pdata uint32_t tmp = 0;
	tmp |= (1 << 25);
	tmp |= (uint32_t)((uint32_t)ch << 20);
	tmp |= (uint32_t)((uint32_t)dat << 4);
	spiWrite(tmp);
}
void dac8568_1_Clear(void){//������мĴ���
	pdata uint32_t tmp;
	tmp = 0x14000000;//Clear all DAC outputs to zero scale (defaultmode)
	spiWrite(tmp);
}
void dac8568_1_Reset(void){//��λ	
	pdata uint32_t tmp;
	tmp = 0x1C000000;//Software Reset
	spiWrite(tmp);
}