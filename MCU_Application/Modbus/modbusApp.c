#include "modbusApp.h"
/*****************************************************************************/


/*****************************************************************************/
void getCoilVal(uint16_t addr, uint16_t *tempData)
{//ȡ��Ȧ״̬ ����0��ʾ�ɹ�
	addr = ~addr;
	*tempData = 0;
}
void setCoilVal(uint16_t addr, uint16_t tempData)
{//�趨��Ȧ״̬ ����0��ʾ�ɹ�
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
