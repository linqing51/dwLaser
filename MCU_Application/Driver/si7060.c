#include "si7060.h"
/*****************************************************************************/
uint8_t si7060ReadValue(const uint8_t registerAdd){ 																 
	uint8_t temp=0;	
	iic1Start();  
	iic1SendByte((I2C_ADDRESS_SI7060_00 << 1) & 0xFE);//发送写命令
	iic1WaitAck();
	iic1SendByte(registerAdd);//发送高地址		 
	iic1WaitAck(); 

	iic1Start();  	 	   
	iic1SendByte(((I2C_ADDRESS_SI7060_00 << 1) | 0x01));//进入接收模式			   
	iic1WaitAck();	 
	temp = iic1ReadByte(0);//读一个字节，非应答信号信号	   
	//iic1NAck();
	iic1Stop();        //产生一个停止条件
	return temp;
}
void si7060WriteValue(const uint8_t registerAdd, const uint8_t value){
	iic1Start(); 
	iic0SendByte((I2C_ADDRESS_SI7060_00 << 1) & 0xFE);//发送写命令
	iic0WaitAck();
	iic0SendByte(registerAdd);
	iic0WaitAck();
	iic0SendByte(value);
	iic0WaitAck();	   
	iic0Stop();//产生一个停止条件 
}


uint8_t si7060Init(void){
	uint8_t ret;
	ret = si7060ReadValue(CMD_SI7060_ID);
	if(ret != 0x14){
		return false;
	}
	ret = si7060ReadValue(CMD_SI7060_meas);
	si7060WriteValue(CMD_SI7060_meas, 0x04);
	ret = si7060ReadValue(CMD_SI7060_meas);
	
	
	//si7060WriteValue(CMD_SI7060_sltimeena, 0x01);
	
	si7060WriteValue(CMD_SI7060_sw_op,0x4E);
	si7060WriteValue(CMD_SI7060_sw_hyst,0x1C);
	
	si7060WriteValue(CMD_SI7060_opt_status, 0x02);
	si7060WriteValue(CMD_SI7060_otp_addr,0x14);
	ret = si7060ReadValue(CMD_SI7060_otp_data);//READ Base Part Number
	
	si7060WriteValue(CMD_SI7060_opt_status, 0x02);
	si7060WriteValue(CMD_SI7060_otp_addr,0x15);
	ret = si7060ReadValue(CMD_SI7060_otp_data);//READ Base Part Variant
	
	si7060WriteValue(CMD_SI7060_opt_status, 0x02);
	si7060WriteValue(CMD_SI7060_otp_addr,0x18);
	ret = si7060ReadValue(CMD_SI7060_otp_data);//READ Serial ID[32:24]
	
	si7060WriteValue(CMD_SI7060_opt_status, 0x02);
	si7060WriteValue(CMD_SI7060_otp_addr,0x19);
	ret = si7060ReadValue(CMD_SI7060_otp_data);//READ Serial ID[23:16]
	
	si7060WriteValue(CMD_SI7060_opt_status, 0x02);
	si7060WriteValue(CMD_SI7060_otp_addr,0x1A);
	ret = si7060ReadValue(CMD_SI7060_otp_data);//READ Serial ID[15:8]
	
	si7060WriteValue(CMD_SI7060_opt_status, 0x02);
	si7060WriteValue(CMD_SI7060_otp_addr,0x1B);
	ret = si7060ReadValue(CMD_SI7060_otp_data);//READ Serial ID[7:0]
	return true;
	
}
int16_t si7060ReadTemperature(void){
	fp32_t _temp;
	uint8_t _Dspsigm;
	uint8_t _Dspsigl;
	uint8_t _ret;
	_ret = si7060ReadValue(CMD_SI7060_Dspsigm);
	_Dspsigm = (_ret&0x7F);
	_ret = si7060ReadValue(CMD_SI7060_Dspsigl);
	_Dspsigl = _ret;
	_temp = 55+ ((float)(256*_Dspsigm)+(float)(_Dspsigl-16384))/160;
	return (int16_t)(_temp*10);
}






