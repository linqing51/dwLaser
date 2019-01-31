#ifndef __SPLCCONFIG_H__
#define __SPLCCONFIG_H__
/*****************************************************************************/
#define CONFIG_UART0_BAUDRATE				115200//串口波特率
#define CONFIG_UART0_PARITY					NONE
#define CONFIG_UART0_STOPBIT				1
#define CONFIG_UART0_DATABIT				8

#define CONFIG_UART1_BAUDRATE				9600//串口波特率
#define CONFIG_UART1_PARITY					NONE
#define CONFIG_UART1_STOPBIT				1
#define CONFIG_UART1_DATABIT				8
/*****************************************************************************/
#define CONFIG_SPLC_FUNTEST					1//功能指令测试
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
#define CONFIG_SPLC_USING_EPROMSIM			1//EPROM 仿真启用
#define CONFIG_SPLC_USING_CLEAR_NVRAM		1//启用清除NVRAM功能
/*****************************************************************************/
#define CONFIG_SPLC_USING_UART1				1//UART1串口启用
#if CONFIG_SPLC_USING_UART1 == 1
#define SPLC_UART1							0
#endif
#define CONFIG_SPLC_USING_UART2				0//UART1串口启用
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
#define CONFIG_SPLC_USING_MB_RTU_SLAVE		1//是能MODBUS RTU从站
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
#define SPLC_MR_SIZE						64//64*16 = 1024
#define SPLC_R_SIZE							61//64*16 = 1024
#define SPLC_DM_SIZE						256
#define SPLC_EM_SIZE						256

//线圈 保持 64 * 16 = 1024BIT
#define MR_START							0
#define MR_END   							63
//#message "MR_START ="MR_START

//线圈寄存器 非保持 8 * 16 = 128BIT
#define R_START								64
#define R_END								127
//数据寄存器 保持 128	
#define DM_START							128
#define DM_END								255
//数据寄存器 非保持 256个字
#define EM_START							256
#define EM_END								511
//延时线圈
//100US 4 * 16 = 64BIT
#define T_100US_START						512
#define T_100US_END							515
//1MS 4 * 16 = 64BIT
#define T_1MS_START							516
#define T_1MS_END							519
//10MS 4 * 16 = 16BIT
#define T_10MS_START						520
#define T_10MS_END							523
//100MS 4 * 16 = 16BIT
#define T_100MS_START						524
#define T_100MS_END							527
//延时计时器 
//100US 64
#define TD_100US_START						528
#define TD_100US_END						591	
//1MS 64
#define TD_1MS_START						592
#define TD_1MS_END							655
//10MS 64
#define TD_10MS_START						656
#define TD_10MS_END							719
//100MS 64
#define TD_100MS_START						720
#define TD_100MS_END						783
//计数器 8
#define C_START								784
#define C_END								791
//输入位寄存器 4 * 16 = 64个
#define X_START								792
#define X_END								795		
//输出位寄存器 4 * 16 = 64个
#define Y_START								796
#define Y_END								799
//特殊寄存器 32个字
#define SPREG_START							800
#define SPREG_END							831
//特殊线圈	8 * 16 = 128个
#define SPCOIL_START						832
#define SPCOIL_END							839
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
#define SPREG_UART0_SEND_BUFFER_ADR			(SPREG_START + 4)//UART0 发送缓冲NVRAM地址		
#define SPREG_UART0_SEND_LENGTH				(SPREG_START + 5)//UART0 发送数据长度
#define SPREG_UART0_SEND_NUM				(SPREG_START + 6)//UART0 已经发送数据长度
#define SPREG_UART0_RECV_BUFFER_ADR			(SPREG_START + 7)//UART0 接收缓冲NVRAM地址
#define SPREG_UART0_RECV_LENGTH				(SPREG_START + 8)//UART0 接收数据长度
#define SPREG_UART0_RECV_NUM				(SPREG_START + 9)//UART0 已经接收数据长度
/*****************************************************************************/
#define SPREG_UART1_SEND_BUFFER_ADR			(SPREG_START + 10)//UART1 发送缓冲NVRAM地址		
#define SPREG_UART1_SEND_LENGTH				(SPREG_START + 11)//UART1 发送数据长度
#define SPREG_UART1_SEND_NUM				(SPREG_START + 12)//UART1 已经发送数据长度
#define SPREG_UART1_RECV_BUFFER_ADR			(SPREG_START + 13)//UART1 接收缓冲NVRAM地址
#define SPREG_UART1_RECV_LENGTH				(SPREG_START + 14)//UART1 接收数据长度
#define SPREG_UART1_RECV_NUM				(SPREG_START + 15)//UART1 已经接收数据长度
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
#define SPREG_DAC_2							(SPREG_START + 32)//DAC0设定值
#define SPREG_DAC_3							(SPREG_START + 33)//DAC0设定值
#define SPREG_DAC_4							(SPREG_START + 34)//DAC0设定值
#define SPREG_DAC_5							(SPREG_START + 35)//DAC0设定值
#define SPREG_DAC_6							(SPREG_START + 36)//DAC0设定值
#define SPREG_DAC_7							(SPREG_START + 37)//DAC0设定值
/*****************************************************************************/
#define SPREG_CLEAR_NVRAM0					(SPREG_END)//清除NVRAM后重新启动
/*****************************************************************************/
#endif
