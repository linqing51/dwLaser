#ifndef __APPCONFIG_H__
#define __APPCONFIG_H__
/*****************************************************************************/
#define CONFIG_APP_DIODE_HIGH_TEMP								400
#define CONFIG_APP_DRIVE_HIGH_TEMP								650
#define CONFIG_APP_ENVI_HIGH_TEMP								500
/*****************************************************************************/
#define CONFIG_USING_LASER_CHANNEL_0							1
#define CONFIG_USING_LASER_CHANNEL_1							1
#define CONFIG_USING_LASER_CHANNEL_2							1
#define CONFIG_USING_LASER_CHANNEL_3							1
#define CONFIG_HMI_SCHEME_NUM									32//方案数
#define CONFIG_HMI_DEFAULT_PASSSWORD0							0x3433//默认密码
#define CONFIG_HMI_DEFAULT_PASSSWORD1							0x3231//默认密码
#define CONFIG_SCHEME_NAME_SIZE									24//12*2
#define STATUS_LASER_READY										0x5A
#define STATUS_LASER_STANDBY									0xA5
#define AIM_MODE_CW_GREEN										0x5678//连续绿色
#define AIM_MODE_CW_RED											0x9ABC//连续红色
//故障码
#define ERROR_CODE_EPROM										0x0001//EPRON 错误
#define ERROR_CODE_SPI_FLASH									0x0002//SPI FLSAH错误
#define ERROR_CODE_SI7060										0x0003//温度传感器通信错误
#define ERROR_CODE_MCP79412										0x0004//RTC通信错误
#define ERROR_CODE_LDR0											0x0005//激光驱动器0错误
#define ERROR_CODE_LDR1											0x0006//激光驱动器1错误
#define ERROR_CODE_TEMPER										0x0007//温度传感器错误
#define ERROR_CODE_USBHOST										0x0008//USB HOST模块错误
#define ERROR_CODE_NFC											0x0009//NFC模块错误
#define ERROR_CODE_NRF24L01										0x0010//NRF24L01模块错误
#define ERRPR_CODE_NOERR										0xFFFF//无错误
//光斑直径定义
#define DERMA_SPOT_SIZE_0MM5									0x100A//光斑直径0.5					
#define DERMA_SPOT_SIZE_1MM0									0x200B//光斑直径1.0
#define DERMA_SPOT_SIZE_2MM0									0x300C//光斑直径2.0
#define DERMA_SPOT_SIZE_3MM0									0x400D//光斑直径3.0

#define CONFIG_MAX_LASER_DAC_CH0								0xFFF//
#define CONFIG_MAX_LASER_DAC_CH1								0xFFF//

#define CONFIG_MAX_LASERPOWER_CH0								300//通道0最大激光功率
#define CONFIG_MAX_LASERPOWER_CH1								150//通道1最大激光功率
#define CONFIG_MAX_LASERPOWER_CH2								100//通道2最大激光功率
#define CONFIG_MAX_LASERPOWER_CH3								100//通道3最大激光功率

#define CONFIG_MIN_LASERPOWER_CH0								0//通道0最小激光功率
#define CONFIG_MIN_LASERPOWER_CH1								0//通道1最小激光功率
#define CONFIG_MIN_LASERPOWER_CH2								0//通道2最大激光功率
#define CONFIG_MIN_LASERPOWER_CH3								0//通道3最大激光功率

#define CONFIG_MAX_LASER_POSWIDTH								10000
#define CONFIG_MIN_LASER_POSWIDTH								1
#define CONFIG_MAX_LASER_NEGWIDTH								10000
#define CONFIG_MIN_LASER_NEGWIDTH								1
#define CONFIG_MAX_LASER_TIMES									20//最大可计数脉冲数
#define CONFIG_MIN_LASER_TIMES									1//最小可计数脉冲数
#define CONFIG_MAX_LASER_GROUP_OFF								1000
#define CONFIG_MIN_LASER_GROUP_OFF								10
#define CONFIG_MAX_LASER_ENERGY_INTERVAL						200
#define CONFIG_MIN_LASER_ENERGY_INTERVAL						20
#define CONFIG_STEP_LASER_ENERGY_INTERVAL						10

#define CONFIG_MAX_AIM_BRG										100//红光最大调光占空比
#define CONFIG_MIN_AIM_BRG										0//红光最小调光占空比
#define CONFIG_MAX_BEEM_VOLUME									100//蜂鸣器最大音量
#define CONFIG_MIN_BEEM_VOLUME									0//蜂鸣器最小音量
#define CONFIG_MAX_LCD_BRG										100//屏幕亮度最大值
#define CONFIG_MIN_LCD_BRG										0//屏幕亮度最小值
#define CONFIG_COOL_SET_TEMP									280//冷却温度
#define CONFIG_COOL_DIFF_TEMP									20//冷却温度变化范围

#endif