#ifndef __APPCONFIG_H__
#define __APPCONFIG_H__
/*****************************************************************************/
#define CONFIG_APP_DEBUG										1
/*****************************************************************************/
#define CONFIG_APP_DIODE_HIGH_TEMP								400
#define CONFIG_APP_DIODE_LOW_TEMP								-100
#define CONFIG_APP_DRIVE_HIGH_TEMP								650
#define CONFIG_APP_ENVI_HIGH_TEMP								750
/*****************************************************************************/
#define CONFIG_USING_SINGLE_WAVE								1//单波长
#define CONFIG_USING_DUAL_WAVE									0//双波长
#define CONFIG_HMI_SCHEME_NUM									32//方案数
#define CONFIG_HMI_DEFAULT_PASSSWORD0							0x3235//默认密码
#define CONFIG_HMI_DEFAULT_PASSSWORD1							0x3830//默认密码
#define CONFIG_SCHEME_NAME_SIZE									22//12*2
//故障码
#define ERROR_CODE_EPROM										0x0001//EPRON 错误
#define ERROR_CODE_USBHOST										0x0008//USB HOST模块错误
#define ERROR_CODE_NFC											0x0009//NFC模块错误
#define ERRPR_CODE_NOERR										0xFFFF//无错误
//光斑直径定义
#define DERMA_SPOT_SIZE_0MM5									0x100A//光斑直径0.5					
#define DERMA_SPOT_SIZE_1MM0									0x200B//光斑直径1.0
#define DERMA_SPOT_SIZE_2MM0									0x300C//光斑直径2.0
#define DERMA_SPOT_SIZE_3MM0									0x400D//光斑直径3.0

#define CONFIG_MAX_LASER_DAC_CH0								0xFFF//
#define CONFIG_MAX_LASER_DAC_CH1								0xFFF//
#define CONFIG_MAX_LASER_DAC_CH2								0xFFF
#define CONFIG_MAX_LASER_DAC_CH3								0xFFF

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
#define CONFIG_MIN_LASER_ENERGY_INTERVAL						40
#define CONFIG_STEP_LASER_ENERGY_INTERVAL						10
#define CONFIG_BEEM_ENERGY_INTERVAL_TIME						250//变音持续时间

#define CONFIG_MAX_AIM_BRG										100//红光最大调光占空比
#define CONFIG_MIN_AIM_BRG										0//红光最小调光占空比
#define CONFIG_MAX_BEEM_VOLUME									100//蜂鸣器最大音量
#define CONFIG_MIN_BEEM_VOLUME									0//蜂鸣器最小音量
#define CONFIG_MAX_LCD_BRG										100//屏幕亮度最大值
#define CONFIG_MIN_LCD_BRG										0//屏幕亮度最小值
#define CONFIG_COOL_SET_TEMP									280//冷却温度
#define CONFIG_COOL_DIFF_TEMP									20//冷却温度变化范围

#define LASER_CH0_NOTES_INTERCEPT								393.7F	
#define LASER_CH0_NOTES_B1										12.34F
#define LASER_CH0_NOTES_B2										0.0F
#define LASER_CH0_NOTES_B3										0.0F

#define LASER_CH1_NOTES_INTERCEPT								-10.0F	
#define LASER_CH1_NOTES_B1										4.096F
#define LASER_CH1_NOTES_B2										0.0
#define LASER_CH1_NOTES_B3										0.0

#define LASER_CH2_NOTES_INTERCEPT								-0.16355			
#define LASER_CH2_NOTES_B1										1.82066E-5
#define LASER_CH2_NOTES_B2										-2.75859E-13
#define LASER_CH2_NOTES_B3										7.12301E-20

#define LASER_CH3_NOTES_INTERCEPT								-0.16355			
#define LASER_CH3_NOTES_B1										1.82066E-5
#define LASER_CH3_NOTES_B2										-2.75859E-13
#define LASER_CH3_NOTES_B3										7.12301E-20

#define CONFIG_RELEASE_SECOND_DEF								1000//激光发射计时秒定义
#endif