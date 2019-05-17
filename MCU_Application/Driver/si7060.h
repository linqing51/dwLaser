#include "lib.h"
/*****************************************************************************/
#define I2C_ADDRESS_SI7060_00 						0x30
#define I2C_ADDRESS_SI7060_01 						0x31
#define I2C_ADDRESS_SI7060_02 						0x32
#define I2C_ADDRESS_SI7060_03 						0x33
#define CMD_SI7060_ID                          		0xC0
#define CMD_SI7060_Dspsigm                     		0xC1
#define CMD_SI7060_Dspsigl                     		0xC2
#define CMD_SI7060_meas                        		0xC4
#define CMD_SI7060_sw_op                       		0xC6
#define CMD_SI7060_sw_hyst                     		0xC7 
#define CMD_SI7060_sltimeena						0xC9
#define CMD_SI7060_otp_addr							0xE1
#define CMD_SI7060_otp_data							0xE2
#define CMD_SI7060_opt_status						0xE3

#define SI7060_OPT_BASE_PART_NUMBER					0x14
#define SI7060_OPT_PART_NUMBER_VARIANT				0x15
#define SI7060_OPT_SERIAL_ID3224					0x18
#define SI7060_OPT_SERIAL_ID2316					0x19
#define SI7060_OPT_SERIAL_ID1508					0x1A
#define SI7060_OPT_SERIAL_ID0700					0x1B

/*****************************************************************************/
void si7060Init(void);
uint8_t si7060ReadValue(const uint8_t registerAdd);
void si7060WriteValue(const uint8_t registerAdd, const uint8_t value);
int16_t si7060ReadTemperature(void);