#include "appConfig.h"
/*****************************************************************************/
void dac8568_2_Init(void);
void dac8568_2_Update(uint8_t ch);
void dac8568_2_WriteInputRegister(uint8_t ch, uint16_t dat);
void dac8568_2_WriteDacRegister(uint8_t ch, uint16_t dat);
void dac8568_2_Clear(void);
void dac8568_2_Reset(void);