#ifndef __SPLCCONFIG_H__
#define __SPLCCONFIG_H__
/*****************************************************************************/
#define CONFIG_DEBUG_PID					0//PID调试功能
#define CONFIG_DEBUG_TIMER4					0//TIMER4调试
#define CONFIG_DEBUG_PCA					0//PCA调试
/*****************************************************************************/
#define CONFIG_UART0_BAUDRATE				115200//串口0 波特率
#define CONFIG_UART1_BAUDRATE				115200//串口1 波特率
/*****************************************************************************/
#define CONFIG_SPLC_USING_I2C0				1//使能I2C0
#define CONFIG_SPLC_USING_I2C1				1//使能I2C1
#define CONFIG_SPLC_USING_I2C2				1//使能I2C2
#define CONFIG_SPLC_USING_I2C3				1//使能I2C3
/*****************************************************************************/
#define CONFIG_I2C0_FREQ 					1            
#define CONFIG_I2C1_FREQ 					1
#define CONFIG_I2C2_FREQ 					1
#define CONFIG_I2C3_FREQ 					1
#define CONFIG_I2C_WAITACT_TIME				10
/*****************************************************************************/
#define CONFIG_EPROM_DEBUG					0
#define CONFIG_EPROM_SIZE 					CONFIG_AT24C64_SIZE
#define	CONFIG_AT24C02_SIZE 				256
#define	CONFIG_AT24C04_SIZE  				512
#define	CONFIG_AT24C08_SIZE 				1024
#define	CONFIG_AT24C16_SIZE 				2048
#define	CONFIG_AT24C32_SIZE 				4096
#define	CONFIG_AT24C64_SIZE					8192
#define	CONFIG_AT24C128_SIZE 				16384
#define	CONFIG_AT24C256_SIZE 				32768
#define CONFIG_EPROM_ADDRESS				0x50
#define CONFIG_EPROM_FRAM					1//铁电存储体无写入等待
#define CONFIG_EPROM_PAGEWRITE				0//页写入
/*****************************************************************************/
#define CONFIG_SPLC_USING_SPWM				1//使了软件PWM功能
/*****************************************************************************/
#define CONFIG_SPLC_FUN_EPID				1//使能SPLC扩展指令
#define CONFIG_SPLC_FUNTEST					0//功能指令测试
/*****************************************************************************/
#define CONFIG_SPLC_ASSERT					1//检查地址范围
#define CONFIG_SPLC_DEV						0x0A01//设备号
#define CONFIG_SPLC_CLEAR_CODE				0xA58E
#define CONFIG_SOFTPLC_TICK					1000L//1mS
#define CONFIG_INPUT_FILTER_TIME			3//输入数字滤波扫描周期 1mS * N
/*****************************************************************************/
#define CONFIG_SPLC_USING_WDT				0//看门狗启用
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_INPUT			1//输入IO刷新启用
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_OUTPUT			1//输出IO刷新启用
/*****************************************************************************/
#define CONFIG_SPLC_USING_PCA				1//片内计数器阵列
/*****************************************************************************/
#define CONFIG_SPLC_USING_EPROM				0//EPROM 
#define CONFIG_SPLC_USING_CLEAR_NVRAM		1//启用清除NVRAM功能
/*****************************************************************************/
#define CONFIG_SPLC_USING_UART0				1//UART 0串口启用
#if CONFIG_SPLC_USING_UART0 == 1
#define UART0								0
#define CONFIG_UART0_RBUF_SIZE				256//接收缓冲
#define CONFIG_UART0_TBUF_SIZE				256//发送缓冲
#endif

#define CONFIG_SPLC_USING_UART1				1//UART 1串口启用
#if CONFIG_SPLC_USING_UART1 == 1
#define UART1								1
#define CONFIG_UART1_RBUF_SIZE				256//接收缓冲
#define CONFIG_UART1_TBUF_SIZE				256//发送缓冲
#endif
/*****************************************************************************/
#define CONFIG_SPLC_USING_ADC				1//使能ADC模块
#define CONFIG_SPLC_ADC_FILTER_TAP			8//ADC位移滤波次数
#define CONFIG_SPLC_ADC_CHANNLE				9//ADC通道数
#define CONFIG_ADC_TEMP_SENSOR_GAIN    		3330L// Temp Sensor Gain in (uV / degC)
#define CONFIG_ADC_TEMP_SENSOR_OFFSET  		856L// Temp Sensor Offset in mV
#define CONFIG_ADC_INTERNAL_VREF     		2400L// ADC Voltage Reference (mV)
#define CONFIG_ADC_AMBIENT             		25L// Ambient temp in deg C
#define CONFIG_NTC_RS						3300L
#define CONFIG_NTC_B						3500L
#define CONFIG_NTC_RB						10000L
#define CONFIG_NTC_VREF						5000L
/*****************************************************************************/
#define CONFIG_SPLC_USING_DAC				1//是能DAC模块
/*****************************************************************************/
#define CONFIG_USING_RTU_SLAVE				1//使能MODBUS RTU从站
#define CONFIG_MB_PORT						UART0
#define CONFIG_MB_RTU_SLAVE_TICK			1000L//1000uS
#define CONFIG_MB_RTU_SLAVE_ADDRESS			0x01//从设备地址
#define CONFIG_MB_RTU_SLAVE_BUFFER_SIZE		256//发送接收缓冲区
#define CONFIG_MB_RTU_SLAVE_TIMEOUT			20//接收通讯超时 10mS
#define CONFIG_MB_RTU_SLAVE_IO_DELAY		1//RX TX切换延时
/*****************************************************************************/
#define DISABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 0;
#define ENABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 1;
#define DISABLE_INTERRUPT					EA = 0;
#define ENABLE_INTERRUPT					EA = 1;
/*****************************************************************************/
#define CONFIG_USING_SIMEPROM				0
#define CONFIG_USING_USB					0
#define CONFIG_USING_ONCHIPFLASH			0
/*****************************************************************************/
#define CONFIG_FIRMWARE_UPDATE_PAGE_SIZE	128//FLASH单次读写容量
#define CONFIG_FW_CONFIG_ADR				0x0000//固件配置信息起始地址
#define CONFIG_FW_CONFIG_SIZE				0x0000//固件配置信息容量
#define CONFIG_FW_STORAGE_ADR				0x0000//固件暂存区起始地址
#define CONFIG_FW_STORAGE_SIZE				0x0000//固件暂存区容量
/*****************************************************************************/
#define CONFIG_FW_ORIGINAL_SAVE				1//更新前保存旧固件
#define CONFIG_FW_UPDATE_REQ_FLAG			0x5A//固件更新标志
#define CONFIG_FW_CONFIG_FILE_NAME			"/fwConfig.ini"//固件配置文件名称
#define CONFIG_FW_MCU_FILE_LOAD_NAME		"/dwLaserNE.bin"//单片机固件名称
#define CONFIG_FW_MCU_FILE_SAVE_NAME		"/dwLaserOD.bib"//
/*****************************************************************************/
#define CONFIG_SPLC_USING_LASER_TIMER		1
#define CONFIG_SPLC_USING_LASER_TIMER_TEST	0
#define CONFIG_LASER_TIMER_TICK				1000
#define CONFIG_USING_DCHMI_APP				1//广东大彩人机交互应用
#define CONFIG_USING_BACKGROUND_APP			1//背景应用
#define CONFIG_MAX_LASERPOWER_CH0			300
#define CONFIG_MAX_LASERPOWER_CH1			150
#define CONFIG_MAX_LASER_POSWIDTH			999
#define CONFIG_MAX_LASER_NEGWIDTH			999
#define CONFIG_MAX_LASER_TIMER				999
#define CONFIG_MAX_LASER_SPACE				999
/*****************************************************************************/
//#define CONFIG_SPLC_USING_NFC				0
//#define RW_SUPPORT	
//#endif
/*****************************************************************************/
//线圈 保持 16*8=256 
#define MR_START							0
#define MR_END   							7
//线圈寄存器 非保持 16*8=256
#define R_START								8
#define R_END								15
//数据寄存器 保持 576
#define DM_START							16
#define DM_END								591
//数据寄存器 非保持 256
#define EM_START							592
#define EM_END								847
//延时线圈
//1MS 4*16
#define T_1MS_START							848
#define T_1MS_END							851
//10MS 4*16
#define T_10MS_START						852
#define T_10MS_END							855
//100MS 4*16
#define T_100MS_START						856
#define T_100MS_END							859
//延时计时器 
//1MS 4*16
#define TD_1MS_START						860
#define TD_1MS_END							923
//10MS 4*16
#define TD_10MS_START						924
#define TD_10MS_END							987
//100MS 4*16
#define TD_100MS_START						988
#define TD_100MS_END						1051
//输入位寄存器 4*16
#define X_START								1052
#define X_END								1055
//输出位寄存器 4*16
#define Y_START								1056
#define Y_END								1059
//特殊寄存器 64
#define SPREG_START							1060
#define SPREG_END							1123
//特殊线圈 8*16
#define SPCOIL_START						1124
#define SPCOIL_END							1131
//延时器使能
//1MS 4*16
#define T_1MS_ENA_START						1132						
#define T_1MS_ENA_END						1135
//10MS 4*16
#define T_10MS_ENA_START					1136
#define T_10MS_ENA_END						1139
//100MS 4*16
#define T_100MS_ENA_START					1140
#define T_100MS_ENA_END						1143
/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 					(T_100MS_ENA_END + 1)
/*****************************************************************************/
#define SPCOIL_ON							(SPCOIL_START * 16 + 0)//长通线圈
#define SPCOIL_START_UP						(SPCOIL_START * 16 + 1)//初次上电
#define SPCOIL_PS1MS						(SPCOIL_START * 16 + 2)//1mS间隔 50%占空比脉冲
#define SPCOIL_PS10MS						(SPCOIL_START * 16 + 3)//10mS
#define SPCOIL_PS100MS						(SPCOIL_START * 16 + 4)//100mS	
#define SPCOIL_PS1000MS						(SPCOIL_START * 16 + 5)//1000mS	
#define SPCOIL_MODBUS_S0_ERROR				(SPCOIL_START * 16 + 6)//Modbus Slave->Uart0 错误
#define SPCOIL_NVRAM_FAIL					(SPCOIL_START * 16 + 7)//NVRAM校验码错误
#define SPCOIL_WATCHDOG_OVERFLOW			(SPCOIL_START * 16 + 8)//看门狗溢出
/*****************************************************************************/
//串口
#define SPCOIL_UART0_SEND_BUSY				(SPCOIL_START * 16 + 9)//UART1发送忙
#define SPCOIL_UART0_RECV_BUSY				(SPCOIL_START * 16 + 10)//UART1接收忙
#define SPCOIL_UART0_SEND_DONE				(SPCOIL_START * 16 + 11)//发送完成
#define SPCOIL_UART0_RECV_DONE				(SPCOIL_START * 16 + 12)//接收完成
#define SPCOIL_UART1_SEND_BUSY				(SPCOIL_START * 16 + 13)//UART1发送忙
#define SPCOIL_UART1_RECV_BUSY				(SPCOIL_START * 16 + 14)//UART1接收忙
#define SPCOIL_UART1_SEND_DONE				(SPCOIL_START * 16 + 15)//发送完成
#define SPCOIL_UART1_RECV_DONE				(SPCOIL_START * 16 + 16)//接收完成
//USB 
#define SPCOIL_USB_INT_ERROR				(SPCOIL_START * 16 + 17)//USB 底层中断返回错误
#define SPCOIL_USBHOST_CONNECT_REQ			(SPCOIL_START * 16 + 18)//USBHOST连接请求
#define SPCOIL_USBDISK_CONNECT_DOING		(SPCOIL_START * 16 + 19)//USBHOST连接进行中
#define SPCOIL_USBDISK_CONNECT_DONE			(SPCOIL_START * 16 + 20)//USBHOST连接完成
#define SPCOIL_USBDISK_MOUNT_REQ			(SPCOIL_START * 16 + 21)//USBDISK载入请求
#define SPCOIL_USBDISK_MOUNT_DOING			(SPCOIL_START * 16 + 22)//USBDISK装载进行中
#define SPCOIL_USBDISK_MOUNT_DONE			(SPCOIL_START * 16 + 23)//USBDISK装载完成
#define SPCOIL_USBDISK_REMOVE_REQ			(SPCOIL_START * 16 + 24)//USBHOST移除请求
#define SPCOIL_USBDISK_REMOVE_DOING			(SPCOIL_START * 16 + 25)//USBHOST移除进行中
#define SPCOIL_USBDISK_REMOVE_DONE			(SPCOIL_START * 16 + 26)//USBHOST移除完成
#define SPCOIL_USBDISK_READING				(SPCOIL_START * 16 + 27)//USBDISK读取进行中
#define SPCOIL_USBDISK_OPEN_FILE_FAIL		(SPCOIL_START * 16 + 28)//USBDISK打开文件失败
#define SPCOIL_USBDISK_READ_FILE_FAIL		(SPCOIL_START * 16 + 29)//USBDISK读取文件失败
#define SPCOIL_USBDISK_WRITE_FILE_FAIL		(SPCOIL_START * 16 + 30)//USBDISK写入文件失败
#define SPCOIL_USBDISK_CLOSE_FILE_FAIL		(SPCOIL_START * 16 + 31)//USBDISK关闭文件失败
#define SPCOIL_SIMEPROM_READ_FAIL			(SPCOIL_START * 16 + 32)//SIMEPROM读取失败
#define SPCOIL_SIMEPROM_WRITE_FAIL			(SPCOIL_START * 16 + 33)//SIMEPROM写入失败
/*****************************************************************************/
#define SPCOIL_SPWM_OUT_0					(SPCOIL_START * 16 + 34)//SPWM0输出状态
#define SPCOIL_SPWM_RESET_0					(SPCOIL_START * 16 + 35)//SPWM0复位
#define SPCOIL_SPWM_OUT_1					(SPCOIL_START * 16 + 36)//SPWM1输出状态
#define SPCOIL_SPWM_RESET_1					(SPCOIL_START * 16 + 37)//SPWM1复位
#define SPCOIL_SPWM_OUT_2					(SPCOIL_START * 16 + 38)//SPWM2输出状态
#define SPCOIL_SPWM_RESET_2					(SPCOIL_START * 16 + 39)//SPWM2复位
#define SPCOIL_SPWM_OUT_3					(SPCOIL_START * 16 + 40)//SPWM3输出状态
#define SPCOIL_SPWM_RESET_3					(SPCOIL_START * 16 + 41)//SPWM3复位
/*****************************************************************************/
//激光脉冲发射相关线圈
#define SPCOIL_LASER_EMITING				(SPCOIL_START * 16 + 42)//激光发射中
#define SPCOIL_LASER_EMITOVER				(SPCOIL_START * 16 + 43)//激光发射结束
/*****************************************************************************/
//指示激光有关线圈
#define SPCOIL_AIM0_ENABLE					(SPCOIL_START * 16 + 44)//激光指示光0使能
#define SPCOIL_AIM1_ENABLE					(SPCOIL_START * 16 + 45)//激光指示光1使能
/*****************************************************************************/
//蜂鸣器相关线圈
#define SPCOIL_BEEM_ENABLE					(SPCOIL_START * 16 + 46)//蜂鸣器发射使能		
/*****************************************************************************/
#define SPREG_IDENTITY						(SPREG_START + 0)//平台ID号
#define SPREG_CLEAR_NVRAM					(SPREG_START + 1)//清除NVRAM后重新启动
/*****************************************************************************/
#define SPREG_UART0_SEND_LENGTH				(SPREG_START + 2)//UART0 发送数据长度
#define SPREG_UART0_SEND_NUM				(SPREG_START + 3)//UART0 已经发送数据长度
#define SPREG_UART0_RECV_LENGTH				(SPREG_START + 4)//UART0 接收数据长度
#define SPREG_UART0_RECV_NUM				(SPREG_START + 5)//UART0 已经接收数据长度
/*****************************************************************************/		
#define SPREG_UART1_SEND_LENGTH				(SPREG_START + 6)//UART1 发送数据长度
#define SPREG_UART1_SEND_NUM				(SPREG_START + 7)//UART1 已经发送数据长度
#define SPREG_UART1_RECV_LENGTH				(SPREG_START + 8)//UART1 接收数据长度
#define SPREG_UART1_RECV_NUM				(SPREG_START + 9)//UART1 已经接收数据长度
/*****************************************************************************/
#define SPREG_ADC_0							(SPREG_START + 10)//ADC0采集值 PD0
#define SPREG_ADC_1							(SPREG_START + 11)//ADC1采集值 PD1
#define SPREG_ADC_2							(SPREG_START + 12)//ADC2采集值 NTC0
#define SPREG_ADC_3							(SPREG_START + 13)//ADC3采集值 NTC1
#define SPREG_ADC_4							(SPREG_START + 14)//ADC4采集值 ISMON0
#define SPREG_ADC_5							(SPREG_START + 15)//ADC5采集值 IVINMON0
#define SPREG_ADC_6							(SPREG_START + 16)//ADC6采集值 ISMON1
#define SPREG_ADC_7							(SPREG_START + 17)//ADC7采集值 IVINMON1
#define SPREG_ADC_8							(SPREG_START + 18)//ADC8采集值 Temperature Sensor
#define SPREG_DAC_0							(SPREG_START + 19)//DAC0设定值 LSET0
#define SPREG_DAC_1							(SPREG_START + 20)//DAC0设定值 LSET1
/*****************************************************************************/
#define SPREG_SPWM_POS_0					(SPREG_START + 21)//软件PWM0正脉宽设置
#define SPREG_SPWM_POS_SHADOW_0				(SPREG_START + 22)//软件PWM0正脉宽阴影
#define SPREG_SPWM_CYCLE_0					(SPREG_START + 23)//软件PWM0周期设置
#define SPREG_SPWM_CYCLE_SHADOW_0			(SPREG_START + 24)//软件PWM0周期阴影
#define SPREG_SPWM_COUNTER_0				(SPREG_START + 25)//软件PWM0计数器
#define SPREG_SPWM_POS_1					(SPREG_START + 26)//软件PWM1正脉宽设置
#define SPREG_SPWM_POS_SHADOW_1				(SPREG_START + 27)//软件PWM1正脉宽阴影
#define SPREG_SPWM_CYCLE_1					(SPREG_START + 28)//软件PWM1周期设置
#define SPREG_SPWM_CYCLE_SHADOW_1			(SPREG_START + 29)//软件PWM1周期阴影
#define SPREG_SPWM_COUNTER_1				(SPREG_START + 30)//软件PWM1计数器
#define SPREG_SPWM_POS_2					(SPREG_START + 31)//软件PWM2正脉宽设置
#define SPREG_SPWM_POS_SHADOW_2				(SPREG_START + 32)//软件PWM2正脉宽阴影
#define SPREG_SPWM_CYCLE_2					(SPREG_START + 33)//软件PWM2周期设置
#define SPREG_SPWM_CYCLE_SHADOW_2			(SPREG_START + 34)//软件PWM2周期阴影
#define SPREG_SPWM_COUNTER_2				(SPREG_START + 35)//软件PWM2计数器
#define SPREG_SPWM_POS_3					(SPREG_START + 36)//软件PWM3正脉宽设置
#define SPREG_SPWM_POS_SHADOW_3				(SPREG_START + 37)//软件PWM3正脉宽阴影
#define SPREG_SPWM_CYCLE_3					(SPREG_START + 38)//软件PWM3周期设置
#define SPREG_SPWM_CYCLE_SHADOW_3			(SPREG_START + 39)//软件PWM3周期阴影
#define SPREG_SPWM_COUNTER_3				(SPREG_START + 40)//软件PWM3计数器
/*****************************************************************************/
#define SPREG_AIM0_BRIGHTNESS				(SPREG_START + 41)//PCA0->指示光0亮度
#define SPREG_AIM1_BRIGHTNESS				(SPREG_START + 42)//PCA1->指示光1亮度
/*****************************************************************************/
//激光脉冲发射相关寄存器
#define SPREG_LASER_MODE					(SPREG_START + 43)//激光发射模式
#define SPREG_LASER_SELECT					(SPREG_START + 44)//激光通道选择
#define SPREG_LASER_TCOUNTER				(SPREG_START + 45)//激光脉冲计时器计数值
#define SPREG_LASER_TMATE					(SPREG_START + 46)//激光脉冲计时器器匹配值
#define SPREG_LASER_TOVERTIME				(SPREG_START + 47)//激光脉冲计时器溢出值
#define SPREG_LASER_PCOUNTER 				(SPREG_START + 48)//激光脉冲个数计数值
#define SPREG_LASER_PMATE					(SPREG_START + 49)//激光脉冲个数匹配值
#define SPREG_LASER_POVERTIME				(SPREG_START + 50)//激光脉冲间隔计时值
#define SPREG_LASER_RELEASETIME				(SPREG_START + 51)//激光持续时间
#define SPREG_LASER_RELEASE_COUNTER			(SPREG_START + 52)//激光持续时间计时器
#define SPREG_LASER_CURRENT_0				(SPREG_START + 53)//激光电流0
#define SPREG_LASER_CURRENT_1				(SPREG_START + 54)//激光电流1
/*****************************************************************************/
//蜂鸣器相关寄存器
#define SPREG_BEEM_VOLUME					(SPREG_START + 55)//蜂鸣器音量
#define SPREG_BEEM_MODE						(SPREG_START + 56)//蜂鸣器模式
#define SPREG_BEEM_COUNTER					(SPREG_START + 57)//蜂鸣器计时器
/*****************************************************************************/
#define T10MS_USBDISK_CONNECT_DELAY			0
#define T10MS_USBDISK_MOUNT_DELAY			1
#define T10MS_USBDISK_REMOVE_DELAY			2
/*****************************************************************************/
#endif
