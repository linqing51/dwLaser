#include "modbusApp.h"
/*****************************************************************************/
/*****************************************************************************/
uint16_t getCoilVal(uint16_t addr, uint16_t *tempData)
{//取线圈状态 返回0表示成功
	*tempData = 0;
	switch(addr)
	{

		default:break;
	} 
	return  0;
}
uint16_t setCoilVal(uint16_t addr, uint16_t tempData)
{//设定线圈状态 返回0表示成功
	switch(addr)
	{

		default: break;  
	} 
	return 0;
}
	
uint16_t getRegisterVal(uint16_t addr, uint16_t *tempData)
{
	switch(addr)								 
	{
		default: break;  
	}
	return 0;
}


uint16_t setRegisterVal(uint16_t addr, uint16_t tempData)
{

	switch(addr)
	{
		default:break;
	}
	return 0;
}
