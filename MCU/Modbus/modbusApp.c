#include "modbusApp.h"
/*****************************************************************************/
/*****************************************************************************/
uint16_t getCoilVal(uint16_t addr, uint16_t *tempData)
{//ȡ��Ȧ״̬ ����0��ʾ�ɹ�
	*tempData = 0;
	switch(addr)
	{

		default:break;
	} 
	return  0;
}
uint16_t setCoilVal(uint16_t addr, uint16_t tempData)
{//�趨��Ȧ״̬ ����0��ʾ�ɹ�
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
