#include "modbusApp.h"
/*****************************************************************************/


/*****************************************************************************/
void getCoilVal(uint16_t addr, uint16_t *tempData)
{//取线圈状态 返回0表示成功
	addr = ~addr;
	*tempData = 0;
}
void setCoilVal(uint16_t addr, uint16_t tempData)
{//设定线圈状态 返回0表示成功
	addr = ~addr;
	tempData = 0;
}
	
void getRegisterVal(uint16_t addr, uint16_t *tempData)
{
	addr = ~addr;
	*tempData = 0;
}

void setRegisterVal(uint16_t addr, uint16_t tempData)
{
	addr = ~addr;
	tempData = 0;
}
