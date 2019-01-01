#include "appConfig.h"
/*****************************************************************************/
void dac8568_3_Init(void);
void dac8568_3_Update(uint8_t ch);
void dac8568_3_WriteInputRegister(uint8_t ch, uint16_t dat);
void dac8568_3_WriteDacRegister(uint8_t ch, uint16_t dat);
void dac8568_3_Clear(void);
void dac8568_3_Reset(void);