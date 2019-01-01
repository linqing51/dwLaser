#include "appConfig.h"
/*****************************************************************************/
void dac8568_0_Init(void);
void dac8568_0_Update(uint8_t ch);
void dac8568_0_WriteInputRegister(uint8_t ch, uint16_t dat);
void dac8568_0_WriteDacRegister(uint8_t ch, uint16_t dat);
void dac8568_0_Clear(void);
void dac8568_0_Reset(void);