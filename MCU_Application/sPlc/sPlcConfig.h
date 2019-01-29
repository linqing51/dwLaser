#ifndef __SPLCCONFIG_H__
#define __SPLCCONFIG_H__
/*****************************************************************************/
#define DEBUG_LED_ON						0
#define DEBUG_LED_OFF						1
/*****************************************************************************/
#ifdef C8051F580
#define CONFIG_SYSCLK                       (48000000L)//F580内部48M
#define CONFIG_SARCLK      					(2000000L)//ADC0时钟 <2.5MHz
#endif

#ifdef C8051F020
#define CONFIG_SYSCLK                       (22118400L)
#define CONFIG_SARCLK      					(2000000L)//ADC0时钟 <2.5MHz
#endif

//SPLC设置
#define SET_LED_RUN(b)
#define SET_LED_ERROR(b)
#define SET_LED_DAC(b)
#define SET_LED_ADC(b)
#define SET_LED_EPROM(b)
#define SET_LED_IO(b)
#define SET_LED_WDT(b)
#define SET_LED_PCA(b)

#define GET_LED_RUN(b)
#define GET_LED_ERROR(b)
#define GET_LED_DAC(b)
#define GET_LED_ADC(b)
#define GET_LED_EPROM(b)
#define GET_LED_IO(b)
#define GET_LED_WDT(b)
#define GET_LED_PCA(b)

#define REBOOT() 								RSTSRC |= 1 << 4//强制复位
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
#define CONFIG_SPLC_ASSERT					1//检查地址范围
#define CONFIG_SPLC_DEV						0x0A01//设备号
#define CONFIG_SPLC_CLEAR_CODE				0xA58E
#define CONFIG_SOFTPLC_HWTIME				1000L//1mS
#define CONFIG_INPUT_FILTER_TIME			3//输入数字滤波扫描周期 1mS * N
/*****************************************************************************/
#define CONFIG_SPLC_USING_LED				0//启用调试LED
#define CONFIG_SPLC_USING_CLEAR_NVRAM		0//启用清除NVRAM功能
/*****************************************************************************/
#define CONFIG_SPLC_USING_WDT				0//看门狗启用
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_INPUT			0//输入IO刷新启用
/*****************************************************************************/
#define CONFIG_SPLC_USING_IO_OUTPUT			0//输出IO刷新启用
/*****************************************************************************/
#define CONFIG_SPLC_USING_EPROM				0//EPROM掉电存储启用
/*****************************************************************************/
#define CONFIG_SPLC_USING_UART1				0//UART1串口启用
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
#define CONFIG_SPLC_USING_MB_RTU_SLAVE		0//是能MODBUS RTU从站
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
//线圈 保持 8 * 16 = 128BIT
#define MR_START						0
#define MR_END   						3
//线圈寄存器 非保持 8 * 16 = 128BIT
#define R_START							4
#define R_END							11
//数据寄存器 保持 8
#define DM_START						12
#define DM_END							19
//数据寄存器 非保持 140个字
#define EM_START						20
#define EM_END							159
//延时线圈
//1MS 1 * 16 = 16BIT
#define T_1MS_START						160
#define T_1MS_END						160
//10MS 1 * 16 = 16BIT
#define T_10MS_START					161
#define T_10MS_END						161
//100MS 1 * 16 = 16BIT
#define T_100MS_START					162
#define T_100MS_END						162
//延时计时器 
//1MS 16
#define TD_1MS_START					163
#define TD_1MS_END						178
//10MS 16
#define TD_10MS_START					179
#define TD_10MS_END						194
//100MS 16
#define TD_100MS_START					195
#define TD_100MS_END					210
//计数器 1
#define C_START							211
#define C_END							211
//输入位寄存器 1 * 16 = 16个
#define X_START							212
#define X_END							212		
//输出位寄存器 1 * 16 = 16个
#define Y_START							213
#define Y_END							213
//特殊寄存器 24个字
#define SPREG_START						214
#define SPREG_END						237
//特殊线圈	4 * 16 = 64个
#define SPCOIL_START					238
#define SPCOIL_END						241
/*****************************************************************************/
#define CONFIG_NVRAM_SIZE 				(SPCOIL_END + 1)
/*****************************************************************************/
#define SPCOIL_ON						(SPCOIL_START * 16 + 0)//长通线圈
#define SPCOIL_START_UP					(SPCOIL_START * 16 + 1)//初次上电
#define SPCOIL_PS1MS					(SPCOIL_START * 16 + 2)//1mS间隔 50%占空比脉冲
#define SPCOIL_PS10MS					(SPCOIL_START * 16 + 3)//10mS
#define SPCOIL_PS100MS					(SPCOIL_START * 16 + 4)//100mS	
#define SPCOIL_PS1000MS					(SPCOIL_START * 16 + 5)//1000mS	

#define SPCOIL_NVRAM_FAIL				(SPCOIL_START * 16 + 14)//NVRAM校验码错误
#define SPCOIL_WATCHDOG					(SPCOIL_START * 16 + 15)//看门狗溢出
#define SPCOIL_UART0_SEND_BUSY			(SPCOIL_START * 16 + 16)//UART1发送忙
#define SPCOIL_UART0_RECV_BUSY			(SPCOIL_START * 16 + 17)//UART1接收忙
#define SPCOIL_UART0_SEND_DONE			(SPCOIL_START * 16 + 18)//发送完成
#define SPCOIL_UART0_RECV_DONE			(SPCOIL_START * 16 + 19)//接收完成
#define SPCOIL_UART1_SEND_BUSY			(SPCOIL_START * 16 + 20)//UART1发送忙
#define SPCOIL_UART1_RECV_BUSY			(SPCOIL_START * 16 + 21)//UART1接收忙
#define SPCOIL_UART1_SEND_DONE			(SPCOIL_START * 16 + 22)//发送完成
#define SPCOIL_UART1_RECV_DONE			(SPCOIL_START * 16 + 23)//接收完成
/*****************************************************************************/
#define SPREG_RUNTIME_L					(SPREG_START + 0)//累计运行时间秒 32BIT
#define SPREG_RUNTIME_H					(SPREG_START + 1)//累计运行时间秒 32BIT		
/*****************************************************************************/
#define SPREG_UART0_SEND_BUFFER_ADR		(SPREG_START + 4)//UART0 发送缓冲NVRAM地址		
#define SPREG_UART0_SEND_LENGTH			(SPREG_START + 5)//UART0 发送数据长度
#define SPREG_UART0_SEND_NUM			(SPREG_START + 6)//UART0 已经发送数据长度
#define SPREG_UART0_RECV_BUFFER_ADR		(SPREG_START + 7)//UART0 接收缓冲NVRAM地址
#define SPREG_UART0_RECV_LENGTH			(SPREG_START + 8)//UART0 接收数据长度
#define SPREG_UART0_RECV_NUM			(SPREG_START + 9)//UART0 已经接收数据长度
/*****************************************************************************/
#define SPREG_UART1_SEND_BUFFER_ADR		(SPREG_START + 10)//UART1 发送缓冲NVRAM地址		
#define SPREG_UART1_SEND_LENGTH			(SPREG_START + 11)//UART1 发送数据长度
#define SPREG_UART1_SEND_NUM			(SPREG_START + 12)//UART1 已经发送数据长度
#define SPREG_UART1_RECV_BUFFER_ADR		(SPREG_START + 13)//UART1 接收缓冲NVRAM地址
#define SPREG_UART1_RECV_LENGTH			(SPREG_START + 14)//UART1 接收数据长度
#define SPREG_UART1_RECV_NUM			(SPREG_START + 15)//UART1 已经接收数据长度
/*****************************************************************************/
#define SPREG_CLEAR_NVRAM0				(SPREG_END)//清除NVRAM后重新启动
/*****************************************************************************/

#endif
