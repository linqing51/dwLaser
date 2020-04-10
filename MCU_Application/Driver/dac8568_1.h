#include "appConfig.h"
/*****************************************************************************/
void dac8568_1_Init(void);
void dac8568_1_InitNoReset(void);
void dac8568_1_Update(uint8_t ch);
void dac8568_1_WriteInputRegister(uint8_t ch, uint16_t dat);
void dac8568_1_WriteDacRegister(uint8_t ch, uint16_t dat);
void dac8568_1_Clear(void);
void dac8568_1_Reset(void);