#include "appConfig.h"
/*****************************************************************************/
typedef struct 
{
	void (*setSDA)(uint8_t st);
	void (*setSCL)(uint8_t st);
	int8_t (*getSDA)(void);
	int8_t (*getSCL)(void);
	uint8_t busFreq;//×ÜÏßÆµÂÊ 
}hal_iic_t;
/*****************************************************************************/
void iic_stop(hal_iic_t *i2c);
void iic_start(hal_iic_t *i2c);
void iic_sendAck(hal_iic_t *i2c);
void iic_sendNack(hal_iic_t *i2c);
uint8_t iic_checkAcknowledge(hal_iic_t *i2c);
void iic_writeByte(hal_iic_t *i2c, int8_t byte);
uint8_t iic_readByte(hal_iic_t *i2c)