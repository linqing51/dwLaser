#include "modbusApp.h"
/*****************************************************************************/


/*****************************************************************************/
void getCoilVal(uint16_t addr, uint16_t *tempData)
{//取线圈状态 返回0表示成功
	*tempData = 0;
	if(addr >= SOFTPLC_MODBUS_X_START && addr <= SOFTPLC_MODBUS_X_END)
	{//X
		addr -= SOFTPLC_MODBUS_X_START;
		*tempData = ((softPlc.Y[addr / 16] >> (addr % 16)) & 0x01);
	}
	if(addr >= SOFTPLC_MODBUS_Y_START && addr <= SOFTPLC_MODBUS_Y_END)
	{//Y
		addr -= SOFTPLC_MODBUS_Y_START;
		*tempData = ((softPlc.X[addr / 16] >> (addr % 16)) & 0x01);
	}
	if(addr >= SOFTPLC_MODBUS_M_START && addr <= SOFTPLC_MODBUS_M_END)
	{//M
		addr -= SOFTPLC_MODBUS_M_START;
		*tempData = ((softPlc.M[addr / 16] >> (addr % 16)) & 0x01);
	}
	if(addr >= SOFTPLC_MODBUS_T_START && addr <= SOFTPLC_MODBUS_T_END)
	{//T
		addr = SOFTPLC_MODBUS_T_START;
		*tempData = ((softPlc.T[addr / 16] >> (addr % 16)) & 0x01);
	}
}
setCoilVal(uint16_t addr, uint16_t tempData)
{//设定线圈状态 返回0表示成功
	if(addr >= SOFTPLC_MODBUS_Y_START && addr <= SOFTPLC_MODBUS_Y_END)
	{//Y
		addr -= SOFTPLC_MODBUS_Y_START;
		if(tempData)
			softPlc.Y[addr / 16] |= (1 << (addr % 16));
		else
			softPlc.Y[addr / 16] &= ~(1 << (addr % 16));
	}
	if(addr >= SOFTPLC_MODBUS_M_START && addr <= SOFTPLC_MODBUS_M_END)	
	{//M
		addr -= SOFTPLC_MODBUS_M_START;
		if(tempData)
			softPlc.Y[addr / 16] |= (1 << (addr % 16));
		else
			softPlc.Y[addr / 16] &= ~(1 << (addr % 16));
	}
}
	
void getRegisterVal(uint16_t addr, uint16_t *tempData)
{
	if(addr >= SOFTPLC_MODBUS_D_START && addr <= SOFTPLC_MODBUS_D_END)
	{
		addr -= SOFTPLC_MODBUS_D_START;
		*tempData = softPlc.D[addr];
	}
	if(addr >= SOFTPLC_MODBUS_TD_START && addr <= SOFTPLC_MODBUS_TD_END)
	{
		addr -= SOFTPLC_MODBUS_TD_START;
		*tempData = softPlc.T_VALUE[addr];
	}
}

void setRegisterVal(uint16_t addr, uint16_t tempData)
{
	if(addr >= SOFTPLC_MODBUS_D_START && addr <= SOFTPLC_MODBUS_D_END)
	{
		addr -= SOFTPLC_MODBUS_D_START;
		softPlc.D[addr] = tempData;
	}
	if(addr >= SOFTPLC_MODBUS_TD_START && addr <= SOFTPLC_MODBUS_TD_END)
	{
		addr -= SOFTPLC_MODBUS_TD_START;
		softPlc.T_VALUE[addr] = tempData;
	}
}
