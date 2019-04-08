#ifndef __SPLCCONFIG_H__
#define __SPLCCONFIG_H__
/*****************************************************************************/
#define CONFIG_DEBUG 					 	0
/*****************************************************************************/
#define CONFIG_UART0_BAUDRATE				115200//串口0 波特率
#define CONFIG_UART1_BAUDRATE				115200//串口1 波特率
/*****************************************************************************/
#define CONFIG_SPLC_FUNTEST					0//功能指令测试
/*****************************************************************************/
#define CONFIG_SPLC_ASSERT					1//检查地址范围
#define CONFIG_SPLC_DEV						0x0A01//设备号
#define CONFIG_SPLC_CLEAR_CODE				0xA58E
#define CONFIG_SOFTPLC_TICK					1000L//1mS
#define CONFIG_INPUT_FILTER_TIME			3//输入数字滤波扫描周期 1mS * N
/*****************************************************************************/
#define CONFIG_SPLC_USING_LED				1//启用调试LED
/*****************************************************************************/
#define CONFIG_SPLC_USING_WDT				0//看门狗启用
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_INPUT			0//输入IO刷新启用
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_OUTPUT			0//输出IO刷新启用
/*****************************************************************************/
#define CONFIG_SPLC_USING_EPROM				0//EPROM 
#define CONFIG_SPLC_USING_CLEAR_NVRAM		0//启用清除NVRAM功能
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
#define CONFIG_SPLC_ADC_FILTER_TAP			14//ADC位移滤波次数
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
#define CONFIG_MB_RTU_SLAVE_TIMEOUT			100//接收通讯超时 10mS
#define CONFIG_MB_RTU_SLAVE_IO_DELAY		1//RX TX切换延时
/*****************************************************************************/
#define DISABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 0;
#define ENABLE_MODBUS_SERIAL_INTERRUPT		ES0 = 1;
#define DISABLE_INTERRUPT					EA = 0;
#define ENABLE_INTERRUPT					EA = 1;
/*****************************************************************************/
#if CONFIG_USING_RTU_SLAVE == 1
#define CONFIG_USING_HMI					0//使能MODBUS HMI
#endif
/*****************************************************************************/
#define CONFIG_USING_SIMEPROM				1
#define CONFIG_USING_USB					1
#define CONFIG_USING_ONCHIPFLASH			1
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
//线圈 保持 16*8=256 
#define MR_START							0
#define MR_END   							7
//线圈寄存器 非保持 16*8=256
#define R_START								8
#define R_END								15
//数据寄存器 保持 512
#define DM_START							16
#define DM_END								527
//数据寄存器 非保持 256
#define EM_START							528
#define EM_END								783
//延时线圈
//100US 2 * 16
#define T_100US_START						784
#define T_100US_END							785
//1MS 4*16
#define T_1MS_START							786
#define T_1MS_END							789
//10MS 4*16
#define T_10MS_START						790
#define T_10MS_END							793
//100MS 4*16
#define T_100MS_START						794
#define T_100MS_END							797
//延时计时器 
//100US 4*16
#define TD_100US_START						798
#define TD_100US_END						861	
//1MS 4*16
#define TD_1MS_START						862
#define TD_1MS_END							925
//10MS 4*16
#define TD_10MS_START						926
#define TD_10MS_END							989
//100MS 4*16
#define TD_100MS_START						990
#define TD_100MS_END						1053
//计数器 8
#define C_START								1054
#define C_END								1061
//输入位寄存器 4
#define X_START								1062
#define X_END								1065
//输出位寄存器 4
#define Y_START								1066
#define Y_END								1069
//特殊寄存器 32
#define SPREG_START							1070
#define SPREG_END							1101
//特殊线圈 4*16
#define SPCOIL_START						1102
#define SPCOIL_END							1105
/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 					(SPCOIL_END + 1)
/*****************************************************************************/
#define SPCOIL_ON							(SPCOIL_START * 16 + 0)//长通线圈
#define SPCOIL_START_UP						(SPCOIL_START * 16 + 1)//初次上电
#define SPCOIL_PS1MS						(SPCOIL_START * 16 + 2)//1mS间隔 50%占空比脉冲
#define SPCOIL_PS10MS						(SPCOIL_START * 16 + 3)//10mS
#define SPCOIL_PS100MS						(SPCOIL_START * 16 + 4)//100mS	
#define SPCOIL_PS1000MS						(SPCOIL_START * 16 + 5)//1000mS	
#define SPCOIL_MODBUS_S0_ERROR				(SPCOIL_START * 16 + 6)//Modbus Slave->Uart0 错误
#define SPCOIL_NVRAM_FAIL					(SPCOIL_START * 16 + 7)//NVRAM校验码错误
#define SPCOIL_WATCHDOG						(SPCOIL_START * 16 + 8)//看门狗溢出
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
#define SPCOIL_USB_INT_SUCCESS				(SPCOIL_START * 16 + 17)//USB 底层中断返回成功
#define SPCOIL_USB_UNKNOWN_ERROR			(SPCOIL_START * 16 + 18)//USB 底层未知错误
#define SPCOIL_USBHOST_CONNECT_REQ			(SPCOIL_START * 16 + 19)//USBHOST连接请求
#define SPCOIL_USBDISK_CONNECT_DOING		(SPCOIL_START * 16 + 20)//USBHOST连接进行中
#define SPCOIL_USBDISK_CONNECT_DONE			(SPCOIL_START * 16 + 21)//USBHOST连接完成
#define SPCOIL_USBDISK_MOUNT_REQ			(SPCOIL_START * 16 + 22)//USBDISK载入请求
#define SPCOIL_USBDISK_MOUNT_DOING			(SPCOIL_START * 16 + 23)//USBDISK装载进行中
#define SPCOIL_USBDISK_MOUNT_DONE			(SPCOIL_START * 16 + 24)//USBDISK装载完成
#define SPCOIL_USBDISK_REMOVE_REQ			(SPCOIL_START * 16 + 25)//USBHOST移除请求
#define SPCOIL_USBDISK_REMOVE_DOING			(SPCOIL_START * 16 + 26)//USBHOST移除进行中
#define SPCOIL_USBDISK_REMOVE_DONE			(SPCOIL_START * 16 + 27)//USBHOST移除完成
#define SPCOIL_USBDISK_READING				(SPCOIL_START * 16 + 28)//USBDISK读取进行中
#define SPCOIL_USBDISK_OPEN_FILE_FAIL		(SPCOIL_START * 16 + 29)//USBDISK打开文件失败
#define SPCOIL_USBDISK_READ_FILE_FAIL		(SPCOIL_START * 16 + 30)//USBDISK读取文件失败
#define SPCOIL_USBDISK_WRITE_FILE_FAIL		(SPCOIL_START * 16 + 31)//USBDISK写入文件失败
#define SPCOIL_USBDISK_CLOSE_FILE_FAIL		(SPCOIL_START * 16 + 32)//USBDISK关闭文件失败
#define SPCOIL_SIMEPROM_READ_FAIL			(SPCOIL_START * 16 + 33)//SIMEPROM读取失败
#define SPCOIL_SIMEPROM_WRITE_FAIL			(SPCOIL_START * 16 + 34)//USBDISK关闭文件失败
/*****************************************************************************/
#define SPREG_RUNTIME_L						(SPREG_START + 0)//累计运行时间秒 32BIT
#define SPREG_RUNTIME_H						(SPREG_START + 1)//累计运行时间秒 32BIT		
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
#define SPREG_ADC_4							(SPREG_START + 14)//ADC4采集值
#define SPREG_ADC_5							(SPREG_START + 15)//ADC5采集值
#define SPREG_ADC_6							(SPREG_START + 16)//ADC6采集值
#define SPREG_ADC_7							(SPREG_START + 17)//ADC7采集值
#define SPREG_ADC_8							(SPREG_START + 18)//ADC8采集值 Temperature Sensor
#define SPREG_DAC_0							(SPREG_START + 19)//DAC0设定值
#define SPREG_DAC_1							(SPREG_START + 20)//DAC0设定值
/*****************************************************************************/
#define SPREG_CLEAR_NVRAM0					(SPREG_START + 21)//清除NVRAM后重新启动
/*****************************************************************************/
#define T10MS_USBDISK_CONNECT_DELAY			0
#define T10MS_USBDISK_MOUNT_DELAY			1
#define T10MS_USBDISK_REMOVE_DELAY			2
/*****************************************************************************/

#endif
