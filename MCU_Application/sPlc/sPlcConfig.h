#ifndef __SPLCCONFIG_H__
#define __SPLCCONFIG_H__
/*****************************************************************************/
#define CONFIG_UART0_BAUDRATE				115200//串口波特率
#define CONFIG_UART0_PARITY					NONE
#define CONFIG_UART0_STOPBIT				1
#define CONFIG_UART0_DATABIT				8

#define CONFIG_UART1_BAUDRATE				115200//串口波特率
#define CONFIG_UART1_PARITY					NONE
#define CONFIG_UART1_STOPBIT				1
#define CONFIG_UART1_DATABIT				8
/*****************************************************************************/
#define CONFIG_SPLC_FUNTEST					0//功能指令测试
/*****************************************************************************/
#define CONFIG_SPLC_ASSERT					1//检查地址范围
#define CONFIG_SPLC_DEV						0x0A01//设备号
#define CONFIG_SPLC_CLEAR_CODE				0xA58E
#define CONFIG_SOFTPLC_HWTIME				1000L//1mS
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

#define CONFIG_SPLC_USING_UART1				0//UART 1串口启用
#if CONFIG_SPLC_USING_UART1 == 1
#define UART1								1
#define CONFIG_UART1_RBUF_SIZE				256//接收缓冲
#define CONFIG_UART1_TBUF_SIZE				256//发送缓冲
#endif
/*****************************************************************************/
#define CONFIG_SPLC_USING_ADC				0//使能ADC模块
#define CONFIG_SPLC_ADC_FILTER_TAP			14//ADC位移滤波次数
#define CONFIG_SPLC_ADC_CHANNLE				64//ADC通道数
#define CONFIG_SPLC_ADC_TEMP_SENSOR_GAIN    3330L// Temp Sensor Gain in (uV / degC)
#define CONFIG_SPLC_ADC_TEMP_SENSOR_OFFSET  856L// Temp Sensor Offset in mV
#define CONFIG_SPLC_ADC_INTERNAL_VREF     	2400L// ADC Voltage Reference (mV)
#define CONFIG_SPLC_ADC_AMBIENT             25L// Ambient temp in deg C
/*****************************************************************************/
#define CONFIG_SPLC_USING_DAC				0//是能DAC模块
/*****************************************************************************/
#define CONFIG_SPLC_USING_MB_RTU_SLAVE		0//使能MODBUS RTU从站
#define CONFIG_MB_RTU_SLAVE_TIMER			1000L//1000uS
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
//线圈 保持 16*8=256 
#define MR_START							0
#define MR_END   							7
//线圈寄存器 非保持 16*8=256
#define R_START								8
#define R_END								15
//数据寄存器 保持 512
#define DM_START							16
#define DM_END								527
//数据寄存器 非保持 512
#define EM_START							528
#define EM_END								1039
//延时线圈
//100US 4*16
#define T_100US_START						1040
#define T_100US_END							1043
//1MS 4*16
#define T_1MS_START							1044
#define T_1MS_END							1047
//10MS 4*16
#define T_10MS_START						1048
#define T_10MS_END							1051
//100MS 4*16
#define T_100MS_START						1052
#define T_100MS_END							1055
//延时计时器 
//100US 4*16
#define TD_100US_START						1056
#define TD_100US_END						1119	
//1MS 4*16
#define TD_1MS_START						1120
#define TD_1MS_END							1183
//10MS 4*16
#define TD_10MS_START						1184
#define TD_10MS_END							1283
//100MS 4*16
#define TD_100MS_START						1284
#define TD_100MS_END						1311
//计数器 8
#define C_START								1312
#define C_END								1319
//输入位寄存器 4
#define X_START								1320
#define X_END								1323
//输出位寄存器 4
#define Y_START								1324
#define Y_END								1327
//特殊寄存器 32
#define SPREG_START							1328
#define SPREG_END							1359
//特殊线圈 4*16
#define SPCOIL_START						1360
#define SPCOIL_END							1363
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
#define SPCOIL_NVRAM_FAIL					(SPCOIL_START * 16 + 14)//NVRAM校验码错误
#define SPCOIL_WATCHDOG						(SPCOIL_START * 16 + 15)//看门狗溢出
/*****************************************************************************/
#define SPCOIL_UART0_SEND_BUSY				(SPCOIL_START * 16 + 16)//UART1发送忙
#define SPCOIL_UART0_RECV_BUSY				(SPCOIL_START * 16 + 17)//UART1接收忙
#define SPCOIL_UART0_SEND_DONE				(SPCOIL_START * 16 + 18)//发送完成
#define SPCOIL_UART0_RECV_DONE				(SPCOIL_START * 16 + 19)//接收完成
#define SPCOIL_UART1_SEND_BUSY				(SPCOIL_START * 16 + 20)//UART1发送忙
#define SPCOIL_UART1_RECV_BUSY				(SPCOIL_START * 16 + 21)//UART1接收忙
#define SPCOIL_UART1_SEND_DONE				(SPCOIL_START * 16 + 22)//发送完成
#define SPCOIL_UART1_RECV_DONE				(SPCOIL_START * 16 + 23)//接收完成
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
#define SPREG_ADC_0							(SPREG_START + 20)//ADC0采集值
#define SPREG_ADC_1							(SPREG_START + 21)//ADC1采集值
#define SPREG_ADC_2							(SPREG_START + 22)//ADC2采集值
#define SPREG_ADC_3							(SPREG_START + 23)//ADC3采集值
#define SPREG_ADC_4							(SPREG_START + 24)//ADC4采集值
#define SPREG_ADC_5							(SPREG_START + 25)//ADC5采集值
#define SPREG_ADC_6							(SPREG_START + 26)//ADC6采集值
#define SPREG_ADC_7							(SPREG_START + 27)//ADC7采集值
#define SPREG_DAC_0							(SPREG_START + 30)//DAC0设定值
#define SPREG_DAC_1							(SPREG_START + 31)//DAC0设定值

/*****************************************************************************/
#define SPREG_CLEAR_NVRAM0					(SPREG_END)//清除NVRAM后重新启动
/*****************************************************************************/
#endif
