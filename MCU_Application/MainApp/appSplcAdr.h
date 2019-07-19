#ifndef __APPSPLCADR_H__
#define __APPSPLCADR_H__
/*****************************************************************************/
#define CONFIG_APP_DIODE_HIGH_TEMP							400
#define CONFIG_APP_DRIVE_HIGH_TEMP							650
#define CONFIG_APP_ENVI_HIGH_TEMP							500
/*****************************************************************************/
#define CONFIG_HMI_SCHEME_NUM								16//方案数
#define CONFIG_HMI_DEFAULT_PASSSWORD0						0x3433//默认密码
#define CONFIG_HMI_DEFAULT_PASSSWORD1						0x3231//默认密码
#define STATUS_LASER_READY									0x5A
#define STATUS_LASER_STANDBY								0xA5
#define BEEM_MODE_SYNC										0x1234//声光同步
#define BEEM_MODE_TONE										0x4321
#define AIM_MODE_CW_GREEN									0x5678//连续绿色
#define AIM_MODE_CW_RED										0x9ABC//连续红色
//故障码
#define ERROR_CODE_EPROM									0x0001//EPRON 错误
#define ERROR_CODE_SPI_FLASH								0x0002//SPI FLSAH错误
#define ERROR_CODE_SI7060									0x0003//温度传感器通信错误
#define ERROR_CODE_MCP79412									0x0004//RTC通信错误
#define ERROR_CODE_LDR0							0x0005//激光驱动器0错误
#define ERROR_CODE_LDR1							0x0006//激光驱动器1错误
#define ERROR_CODE_TEMPER						0x0007//温度传感器错误
#define ERROR_CODE_USBHOST						0x0008//USB HOST模块错误
#define ERROR_CODE_NFC							0x0009//NFC模块错误
#define ERROR_CODE_NRF24L01						0x0010//NRF24L01模块错误
#define ERRPR_CODE_NOERR						0xFFFF//无错误
//光斑直径定义
#define DERMA_SPOT_SIZE_0MM5					0x100A//光斑直径0.5					
#define DERMA_SPOT_SIZE_1MM0					0x200B//光斑直径1.0
#define DERMA_SPOT_SIZE_2MM0					0x300C//光斑直径2.0
#define DERMA_SPOT_SIZE_3MM0					0x400D//光斑直径3.0
/*****************************************************************************/
#define EM_LASER_SCHEME_NAME					(EM_START + 0)//方案名称
#define EM_LASER_SELECT							(EM_START + 15)//通道选择
#define EM_LASER_PULSE_MODE						(EM_START + 16)//脉冲模式
#define EM_LASER_POWER_CH0						(EM_START + 17)//通道0功率
#define EM_LASER_POWER_CH1						(EM_START + 18)//通道1功率
#define EM_LASER_SP_POSWIDTH					(EM_START + 19)//单脉冲正脉宽
#define EM_LASER_MP_POSWIDTH					(EM_START + 20)//多脉冲正脉宽
#define EM_LASER_MP_NEGWIDTH					(EM_START + 21)//多脉冲负脉宽
#define EM_LASER_GP_POSWIDTH					(EM_START + 22)//Group脉冲正脉宽
#define EM_LASER_GP_NEGWIDTH					(EM_START + 23)//Group脉冲负脉宽
#define EM_LASER_GP_TIMES						(EM_START + 24)//Group脉冲数
#define EM_LASER_GP_GROUP_OFF					(EM_START + 25)//Group脉冲间隔
#define EM_LASER_SIGNAL_ENERGY_INTERVAL			(EM_START + 26)//SIGNAL能量间隔
#define EM_LASER_DERMA_POSWIDTH					(EM_START + 27)//DERMA正脉宽
#define EM_LASER_DERMA_NEGWIDTH					(EM_START + 28)//DERMA负脉宽
#define EM_LASER_DERMA_SPOT_SIZE				(EM_START + 29)//DERMA光斑直径
/*****************************************************************************/
#define EM_DIODE_TEMP0							(EM_START + 30)//二极管温度0
#define EM_DIODE_TEMP1							(EM_START + 31)//二极管温度1
#define EM_DRIVE_TEMP							(EM_START + 32)//驱动器温度
#define EM_ENVI_TEMP							(EM_START + 33)//环境温度
#define EM_DIODE_HIGH_TEMP						(EM_START + 34)//二极管过热阈值
#define EM_DRIVE_HIGH_TEMP						(EM_START + 35)//驱动器过热阈值
#define EM_ENVI_HIGH_TEMP						(EM_START + 36)//环境过热阈值
#define EM_COOL_SET_TEMP						(EM_START + 37)//设定冷却温度
#define EM_COOL_DIFF_TEMP						(EM_START + 38)//设定冷却回差调节
/*****************************************************************************/			
#define EM_RELEASE_TOTAL_TIME					(EM_START + 40)//发射总时间			
#define EM_RELEASE_TOTAL_ENERGY					(EM_START + 41)//发射总能量		
#define EM_TOTAL_POWER							(EM_START + 42)//发射总功率
#define EM_HMI_OPERA_STEP						(EM_START +	43)//操作步骤								
#define EM_ERROR_CODE							(EM_START + 44)//错误码					
#define EM_SCHEME_NUM_TMP						(EM_START + 45)//待确认方案编号			
#define EM_DK25L_VER							(EM_START + 46)//DK25L模块版本
#define EM_LASER_SIGNAL_TIME_INTERVAL			(EM_START + 47)//SIGNAL蜂鸣器改变的时间间隔
#define EM_BEEM_ON_TIME							(EM_START + 48)//蜂鸣器开启时间
#define EM_BEEM_DUTY							(EM_START + 49)//蜂鸣器占空比
/*****************************************************************************/
#define EM_DC_PAGE								(EM_START + 64)//HMI页面编号 			
#define EM_DC_PASSCODE_INDEX					(EM_START + 65)//密码输入位索引		
#define EM_DC_NEW_PASSCODE0						(EM_START + 66)//输入新密码0			
#define EM_DC_NEW_PASSCODE1						(EM_START + 67)//输入新密码1			
#define EM_DC_NEW_PASSCODE2						(EM_START + 68)//输入新密码0			
#define EM_DC_NEW_PASSCODE3						(EM_START + 69)//输入新密码1			
#define EM_DC_DEFAULT_PASSCODE0					(EM_START + 70)//默认密码0				
#define EM_DC_DEFAULT_PASSCODE1					(EM_START + 71)//默认密码1				
#define EM_DC_DEFAULT_PASSCODE2					(EM_START + 72)//默认密码1	
#define EM_DC_DEFAULT_PASSCODE3					(EM_START + 73)//默认密码1				
#define EM_DC_DISPLAY_RELEASE_TIME				(EM_START + 74)//显示发射时间			
#define EM_DC_DISPLAY_RELEASE_ENERGY			(EM_START + 75)//显示发射能量	
/*****************************************************************************/

/*****************************************************************************/
#define FD_LASER_SCHEME_NAME									(FD_START +  0)//方案名称
#define FD_LASER_SELECT											(FD_START +  15)//通道选择
#define FD_LASER_PULSE_MODE										(FD_START +  16)//脉冲模式
#define FD_LASER_POWER_CH0										(FD_START +  17)//通道0功率
#define FD_LASER_POWER_CH1										(FD_START +  18)//通道1功率
#define FD_LASER_SP_POSWIDTH									(FD_START +  19)//单脉冲正脉宽
#define FD_LASER_MP_POSWIDTH									(FD_START +  20)//多脉冲正脉宽
#define FD_LASER_MP_NEGWIDTH									(FD_START +  21)//多脉冲负脉宽
#define FD_LASER_GP_POSWIDTH									(FD_START +  22)//Group脉冲正脉宽
#define FD_LASER_GP_NEGWIDTH									(FD_START +  23)//Group脉冲负脉宽
#define FD_LASER_GP_TIMES										(FD_START +  24)//Group脉冲数
#define FD_LASER_GP_GROUP_OFF									(FD_START +  25)//Group脉冲间隔
#define FD_LASER_SIGNAL_ENERGY_INTERVAL							(FD_START +  26)//SIGNAL能量间隔
#define FD_LASER_DERMA_POSWIDTH									(FD_START +  27)//DERMA正脉宽
#define FD_LASER_DERMA_NEGWIDTH									(FD_START +  28)//DERMA负脉宽
#define FD_LASER_DERMA_SPOT_SIZE								(FD_START +  29)//DERMA光斑直径

#define FD_SCHEME_START_0										(FD_START +   0)//方案0存储区起始
#define FD_SCHEME_END_0											(FD_START +  29)//方案0存储区结束		

#define FD_SCHEME_START_1										(FD_START +  30)//方案1存储区起始		
#define FD_SCHEME_END_1											(FD_START +  59)//方案1存储区结束

#define FD_SCHEME_START_2										(FD_START +  60)//方案2存储区起始
#define FD_SCHEME_END_2											(FD_START +  89)//方案2存储区结束

#define FD_SCHEME_START_3										(FD_START +  90)//方案3存储区起始
#define FD_SCHEME_END_3											(FD_START + 119)//方案3存储区结束

#define FD_SCHEME_START_4										(FD_START + 120)//方案4存储区起始
#define FD_SCHEME_END_4											(FD_START + 149)//方案4存储区结束

#define FD_SCHEME_START_5										(FD_START + 150)//方案5存储区起始
#define FD_SCHEME_END_5											(FD_START + 179)//方案5存储区结束

#define FD_SCHEME_START_6										(FD_START + 180)//方案6存储区起始
#define FD_SCHEME_END_6											(FD_START + 209)//方案6存储区结束

#define FD_SCHEME_START_7										(FD_START + 210)//方案7存储区起始
#define FD_SCHEME_END_7											(FD_START + 239)//方案7存储区结束

#define FD_SCHEME_START_8										(FD_START + 240)//方案8存储区起始
#define FD_SCHEME_END_8											(FD_START + 269)//方案8存储区结束

#define FD_SCHEME_START_9										(FD_START + 270)//方案9存储区起始
#define FD_SCHEME_END_9											(FD_START + 299)//方案9存储区结束

#define FD_SCHEME_START_10										(FD_START + 300)//方案10存储区起始
#define FD_SCHEME_END_10										(FD_START + 329)//方案10存储区结束

#define FD_SCHEME_START_11										(FD_START + 330)//方案11存储区起始
#define FD_SCHEME_END_11										(FD_START + 359)//方案11存储区结束

#define FD_SCHEME_START_12										(FD_START + 360)//方案12存储区起始
#define FD_SCHEME_END_12										(FD_START + 389)//方案12存储区结束

#define FD_SCHEME_START_13										(FD_START + 390)//方案13存储区起始
#define FD_SCHEME_END_13										(FD_START + 419)//方案13存储区结束

#define FD_SCHEME_START_14										(FD_START + 420)//方案14存储区起始
#define FD_SCHEME_END_14										(FD_START + 449)//方案14存储区结束

#define FD_SCHEME_START_15										(FD_START + 450)//方案15存储区起始
#define FD_SCHEME_END_15										(FD_START + 479)//方案15存储区结束
/*****************************************************************************/
#define DM_SCHEME_NUM											(DM_START + 0)//选择的方案编号 低8位方案号 高8位方案使能
#define DM_BEEM_VOLUME											(DM_START + 1)//蜂鸣器音量
#define DM_BEEM_MODE											(DM_START + 2)//蜂鸣器模式
#define DM_AIM_BRG												(DM_START + 3)//指示激光亮度
#define DM_LCD_BRG												(DM_START + 4)//屏幕亮度
#define DM_DC_OLD_PASSCODE0										(DM_START + 5)//屏旧密码0-1
#define DM_DC_OLD_PASSCODE1										(DM_START + 6)//屏旧密码2-3
#define DM_DC_OLD_PASSCODE2										(DM_START + 7)//屏旧密码0-1
#define DM_DC_OLD_PASSCODE3										(DM_START + 8)//屏旧密码2-3
#define DM_SYS_RUNTIME_L										(DM_START + 9)//系统累计运行时间秒L 32BIT
#define DM_SYS_RUNTIME_H										(DM_START + 10)//系统累计运行时间秒H 32BIT
/*****************************************************************************/
#define DM_CORR_TAB0_POWER0										(DM_START + 20)//功率校正表0功率0 
#define DM_CORR_TAB0_POWER1										(DM_START + 21)//功率校正表0功率2 
#define DM_CORR_TAB0_POWER2										(DM_START + 22)//功率校正表0功率4 
#define DM_CORR_TAB0_POWER3										(DM_START + 23)//功率校正表0功率6 
#define DM_CORR_TAB0_POWER4										(DM_START + 24)//功率校正表0功率8 
#define DM_CORR_TAB0_POWER5										(DM_START + 25)//功率校正表0功率10 
#define DM_CORR_TAB0_POWER6										(DM_START + 26)//功率校正表0功率12 
#define DM_CORR_TAB0_POWER7										(DM_START + 27)//功率校正表0功率14 
#define DM_CORR_TAB0_POWER8										(DM_START + 28)//功率校正表0功率16 
#define DM_CORR_TAB0_POWER9										(DM_START + 29)//功率校正表0功率18 
#define DM_CORR_TAB0_POWER10									(DM_START + 30)//功率校正表0功率20 
#define DM_CORR_TAB0_POWER11									(DM_START + 31)//功率校正表0功率22 
#define DM_CORR_TAB0_POWER12									(DM_START + 32)//功率校正表0功率24 
#define DM_CORR_TAB0_POWER13									(DM_START + 33)//功率校正表0功率26 
#define DM_CORR_TAB0_POWER14									(DM_START + 34)//功率校正表0功率28 
#define DM_CORR_TAB0_POWER15									(DM_START + 35)//功率校正表0功率30 
#define DM_CORR_TAB0_POWER16									(DM_START + 36)//功率校正表0功率32 
#define DM_CORR_TAB0_POWER17									(DM_START + 37)//功率校正表0功率34 
#define DM_CORR_TAB0_POWER18									(DM_START + 38)//功率校正表0功率36
#define DM_CORR_TAB0_POWER19									(DM_START + 39)//功率校正表0功率38
#define DM_CORR_TAB0_POWER20									(DM_START + 40)//功率校正表0功率40

#define DM_CORR_TAB1_POWER0										(DM_START + 50)//功率校正表1功率0 			
#define DM_CORR_TAB1_POWER1										(DM_START + 51)//功率校正表1功率2
#define DM_CORR_TAB1_POWER2										(DM_START + 52)//功率校正表1功率4
#define DM_CORR_TAB1_POWER3										(DM_START + 53)//功率校正表1功率6 
#define DM_CORR_TAB1_POWER4										(DM_START + 54)//功率校正表1功率8 
#define DM_CORR_TAB1_POWER5										(DM_START + 55)//功率校正表1功率10 
#define DM_CORR_TAB1_POWER6										(DM_START + 56)//功率校正表1功率12 
#define DM_CORR_TAB1_POWER7										(DM_START + 57)//功率校正表1功率14 
#define DM_CORR_TAB1_POWER8										(DM_START + 58)//功率校正表1功率16 
#define DM_CORR_TAB1_POWER9										(DM_START + 59)//功率校正表1功率18 
#define DM_CORR_TAB1_POWER10									(DM_START + 60)//功率校正表1功率20 
#define DM_CORR_TAB1_POWER11									(DM_START + 61)//功率校正表1功率22 
#define DM_CORR_TAB1_POWER12									(DM_START + 62)//功率校正表1功率24 
#define DM_CORR_TAB1_POWER13									(DM_START + 63)//功率校正表1功率26 
#define DM_CORR_TAB1_POWER14									(DM_START + 64)//功率校正表1功率28 
#define DM_CORR_TAB1_POWER15									(DM_START + 65)//功率校正表1功率30 
#define DM_CORR_TAB1_POWER16									(DM_START + 66)//功率校正表1功率32 
#define DM_CORR_TAB1_POWER17									(DM_START + 67)//功率校正表1功率34 
#define DM_CORR_TAB1_POWER18									(DM_START + 68)//功率校正表1功率36 
#define DM_CORR_TAB1_POWER19									(DM_START + 69)//功率校正表1功率38
#define DM_CORR_TAB1_POWER20									(DM_START + 70)//功率校正表1功率40
/*****************************************************************************/
#define X_FOOTSWITCH_NC											(X_START * 16 + 0)//XIN0 脚踏常闭
#define X_ESTOP													(X_START * 16 + 1)//XIN1 紧急停止开关
#define X_FOOTSWITCH_NO											(X_START * 16 + 2)//XIN2 脚踏常开
#define X_INTERLOCK												(X_START * 16 + 3)//XIN3 安全连锁
#define X_LDR_FAULT0											(X_START * 16 + 4)//XIN4 驱动器故障0
#define X_LDR_FAULT1											(X_START * 16 + 5)//XIN5 驱动器故障1
#define X_FBD0													(X_START * 16 + 6)//XIN6 光纤探测0
#define X_FBD1													(X_START * 16 + 7)//XIN7 光纤探测1
/*****************************************************************************/
#define Y_LED_POWERON											(Y_START * 16 + 0)//YOUT0 电源灯
#define Y_LED_EMIT												(Y_START * 16 + 1)//YOUT1 激光指示灯
#define Y_LED_ALARM												(Y_START * 16 + 2)//YOUT2 故障指示灯
#define Y_OUT3													(Y_START * 16 + 3)//YOUT3 保留
#define Y_OUT4													(Y_START * 16 + 4)//YOUT4 保留
#define Y_OUT5													(Y_START * 16 + 5)//YOUT5 保留
#define Y_OUT6													(Y_START * 16 + 6)//YOUT6 保留
#define Y_OUT7													(Y_START * 16 + 7)//YOUT7 保留
#define Y_FAN0													(Y_START * 16 + 8)//YOUT8 风扇开关0
#define Y_FAN1													(Y_START * 16 + 9)//YOUT9 风扇开关1
#define Y_TEC0													(Y_START * 16 + 10)//YOUT10 制冷开关0
#define Y_TEC1													(Y_START * 16 + 11)//YOUT11 制冷开关1
/*****************************************************************************/
#define R_FIBER_ID_PASS_0										(R_START * 16 + 0)//通道0光纤ID标志
#define R_FIBER_ID_PASS_1										(R_START * 16 + 1)//通道1光纤ID标志
#define R_DIODE_TEMP_HIGH_0										(R_START * 16 + 2)//通道0二极管高温标志
#define R_DIODE_TEMP_HIGH_1										(R_START * 16 + 3)//通道1二极管高温标志
#define R_DRIVE_TEMP_HIGH										(R_START * 16 + 4)//驱动器高温标志
#define R_ENVI_TEMP_HIGH										(R_START * 16 + 5)//环境温度标度
#define R_FAULT													(R_START * 16 + 6)//故障标志
#define R_LASER_EMIT_0											(R_START * 16 + 7)//激光通道0发射指示
#define R_LASER_EMIT_1											(R_START * 16 + 8)//激光通道1发射指示
#define R_ADMIN													(R_START * 16 + 9)//管理员模式
//HMI相关状态
#define R_DCHMI_RESET_REQ										(R_START * 16 + 20)//HMI复位请求
#define R_DCHMI_RESET_DOING										(R_START * 16 + 21)//HMI复位中
#define R_DCHMI_RESET_DONE										(R_START * 16 + 22)//HMI复位完成	
#define R_DCHMI_UPDATEUI_REQ									(R_START * 16 + 23)//HMI内容更新请求
#define R_DCHMI_UPDATEUI_DOING									(R_START * 16 + 24)//HMI内容更新中
#define R_DCHMO_UPDATEUI_DONE									(R_START * 16 + 25)//HMI内容更新请求完成
#define R_DCHMI_RESTORE_REQ										(R_START * 16 + 26)//HMI从FLASH中恢复设置请求
#define R_DCHMI_RESTORE_DOING									(R_START * 16 + 27)//HMI从FLASH中恢复中
#define R_DCHMI_RESTORE_DONE									(R_START * 16 + 28)//HMI从FLASH中恢复设置完成	
//自检状态
#define R_CHECK_FLOAT_DONE										(R_START * 16 + 30)//浮点自检完毕
#define R_CHECK_EPROM_DONE										(R_START * 16 + 31)//存储器自检完毕
#define R_CHECK_SI7060_DONE										(R_START * 16 + 32)//SI7060温度传感器自检完毕
#define R_CHECK_MCP79412_DONE									(R_START * 16 + 33)//板载RTC自检完毕
#define R_CHECK_SPI_MEMORY_DONE									(R_START * 16 + 34)//外部FLASH自检完毕
#define R_CHECK_CH376_DONE										(R_START * 16 + 35)//USB CH376自检完毕
#define R_CHECK_DK25L_DONE										(R_START * 16 + 36)//DK25L模块完毕
#define R_CHECK_NRF24L01_DONE									(R_START * 16 + 37)//NRF24L01模块自检完毕
#define R_CHECK_LASER_DRIVER_DONE								(R_START * 16 + 38)//激光驱动器自检完毕
#define R_CHECK_TEMPERATURE_DONE								(R_START * 16 + 39)//温度自检完毕
#define R_CHECK_WIRELESS_FOOTCONTROL_DONE						(R_START * 16 + 40)//无线脚踏自检完毕
#define R_CHECK_PROBATION_DONE									(R_START * 16 + 41)//试用期自检完毕
 
#define R_CHECK_FLOAT_PASS										(R_START * 16 + 50)//浮点自检通过
#define R_CHECK_EPROM_PASS										(R_START * 16 + 51)//存储器自检通过
#define R_CHECK_SI7060_PASS										(R_START * 16 + 52)//SI7060温度传感器自检通过
#define R_CHECK_MCP79412_PASS									(R_START * 16 + 53)//板载RTC自检通过
#define R_CHECK_SPI_MEMORY_PASS									(R_START * 16 + 54)//外部FLASH自检通过
#define R_CHECK_CH376_PASS										(R_START * 16 + 55)//USB CH376自检自检通过
#define R_CHECK_DK25L_PASS										(R_START * 16 + 56)//DK25L模块自检通过
#define R_CHECK_NRF24L01_PASS									(R_START * 16 + 57)//NRF24L01模块自检通过
#define R_CHECK_LASER_DRIVER_PASS								(R_START * 16 + 58)//激光驱动器自检通过
#define R_CHECK_TEMPERATURE_PASS								(R_START * 16 + 59)//温度自检通过
#define R_CHECK_WIRELESS_FOOTCONTROL_PASS						(R_START * 16 + 60)//无线脚踏自检通过
#define R_CHECK_PROBATION_PASS									(R_START * 16 + 61)//试用期自检通过

#define R_CHECK_FLOAT_FAIL										(R_START * 16 + 70)//浮点自检失败 
#define R_CHECK_EPROM_FAIL										(R_START * 16 + 71)//存储器自检失败
#define R_CHECK_SI7060_FAIL										(R_START * 16 + 72)//SI7060温度传感器自检失败
#define R_CHECK_MCP79412_FAIL									(R_START * 16 + 73)//板载RTC自检失败
#define R_CHECK_SPI_MEMORY_FAIL									(R_START * 16 + 74)//外部FLASH自检失败
#define R_CHECK_CH376_FAIL										(R_START * 16 + 75)//USB CH376自检自检失败
#define R_CHECK_DK25L_FAIL										(R_START * 16 + 76)//NFC模块自检失败
#define R_CHECK_NRF24L01_FAIL									(R_START * 16 + 77)//NRF24L01模块自检失败
#define R_CHECK_LASER_DRIVER_FAIL								(R_START * 16 + 78)//激光驱动器自检失败
#define R_CHECK_TEMPERATURE_FAIL								(R_START * 16 + 79)//温度自检失败
#define R_CHECK_WIRELESS_FOOTCONTROL_FAIL						(R_START * 16 + 80)//无线脚踏自检失败
#define R_CHECK_PROBATION_FAIL									(R_START * 16 + 81)//试用期自检失败
/*****************************************************************************/
#define R_STANDBY_KEY_POSWIDTH_ADD_DOWN							(R_START * 16 + 90)
#define R_STANDBY_KEY_POSWIDTH_ADD_UP							(R_START * 16 + 91)
#define R_STANDBY_KEY_POSWIDTH_DEC_DOWN							(R_START * 16 + 92)
#define R_STANDBY_KEY_POSWIDTH_DEC_UP							(R_START * 16 + 93)
#define R_STANDBY_KEY_NEGWIDTH_ADD_DOWN							(R_START * 16 + 94)
#define R_STANDBY_KEY_NEGWIDTH_ADD_UP							(R_START * 16 + 95)
#define R_STANDBY_KEY_NEGWIDTH_DEC_DOWN							(R_START * 16 + 96)
#define R_STANDBY_KEY_NEGWIDTH_DEC_UP							(R_START * 16 + 97)
#define R_STANDBY_KEY_TIMES_ADD_DOWN							(R_START * 16 + 98)
#define R_STANDBY_KEY_TIMES_ADD_UP								(R_START * 16 + 99)
#define R_STANDBY_KEY_TIMES_DEC_DOWN							(R_START * 16 + 100)
#define R_STANDBY_KEY_TIMES_DEC_UP								(R_START * 16 + 101)
#define R_STANDBY_KEY_GROUP_OFF_ADD_DOWN						(R_START * 16 + 102)
#define R_STANDBY_KEY_GROUP_OFF_ADD_UP							(R_START * 16 + 103)
#define R_STANDBY_KEY_GROUP_OFF_DEC_DOWN						(R_START * 16 + 104)
#define R_STANDBY_KEY_GROUP_OFF_DEC_UP							(R_START * 16 + 105)
#define R_STANDBY_KEY_ENERGY_INTERVAL_ADD_DOWN					(R_START * 16 + 106)
#define R_STANDBY_KEY_ENERGY_INTERVAL_ADD_UP					(R_START * 16 + 107)
#define R_STANDBY_KEY_ENERGY_INTERVAL_DEC_DOWN					(R_START * 16 + 108)
#define R_STANDBY_KEY_ENERGY_INTERVAL_DEC_UP					(R_START * 16 + 109)
#define R_STANDBY_KEY_STNADBY_DOWN								(R_START * 16 + 110)
#define R_STANDBY_KEY_STNADBY_UP								(R_START * 16 + 111)
#define R_STANDBY_KEY_ENTER_OPTION_DOWN							(R_START * 16 + 112)
#define R_STANDBY_KEY_ENTER_OPTION_UP							(R_START * 16 + 113)
#define R_STANDBY_KEY_ENTER_SCHEME_DOWN							(R_START * 16 + 114)
#define R_STANDBY_KEY_ENTER_SCHEME_UP							(R_START * 16 + 115)
/*****************************************************************************/
#define R_OPTION_KEY_ENTER_CORRECTION_DOWN						(R_START * 16 + 120)
#define R_OPTION_KEY_ENTER_CORRECTION_UP						(R_START * 16 + 121)
#define R_OPTION_KEY_ENTER_INFORMATION_DOWN						(R_START * 16 + 122)
#define R_OPTION_KEY_ENTER_INFORMATION_UP						(R_START * 16 + 123)
#define R_OPTION_KEY_ENTER_OK_DOWN								(R_START * 16 + 124)
#define R_OPTION_KEY_ENTER_OK_UP								(R_START * 16 + 125)
#define R_OPTION_KEY_ENTER_DIAGNOSIS_DOWN						(R_START * 16 + 126)
#define R_OPTION_KEY_ENTER_DIAGNOSIS_UP							(R_START * 16 + 127)
/*****************************************************************************/
#define R_INFORMATION_KEY_OK_DOWN								(R_START * 16 + 130)
#define R_INFORMATION_KEY_OK_UP									(R_START * 16 + 131)
/*****************************************************************************/
#define R_SCHEME_KEY_RENAME_DOWN								(R_START * 16 + 140)
#define R_SCHEME_KEY_RENAME_UP									(R_START * 16 + 141)
#define R_SCHEME_KEY_SAVE_USB_DOWN								(R_START * 16 + 142)
#define R_SCHEME_KEY_SAVE_USB_UP								(R_START * 16 + 143)
#define R_SCHEME_KEY_LOAD_USB_DOWN								(R_START * 16 + 144)
#define R_SCHEME_KEY_LOAD_USB_UP								(R_START * 16 + 145)
#define R_SCHEME_KEY_ENTER_STANDBY_DOWN							(R_START * 16 + 146)
#define R_SCHEME_KEY_ENTER_STANDBY_UP							(R_START * 16 + 147)
#define R_SCHEME_KEY_SCHEME_SELECT_0_DOWN						(R_START * 16 + 148)		
#define R_SCHEME_KEY_SCHEME_SELECT_0_UP							(R_START * 16 + 149)
#define R_SCHEME_KEY_SCHEME_SELECT_1_DOWN						(R_START * 16 + 150)
#define R_SCHEME_KEY_SCHEME_SELECT_1_UP							(R_START * 16 + 151)
#define R_SCHEME_KEY_SCHEME_SELECT_2_DOWN						(R_START * 16 + 152)
#define R_SCHEME_KEY_SCHEME_SELECT_2_UP							(R_START * 16 + 153)
#define R_SCHEME_KEY_SCHEME_SELECT_3_DOWN						(R_START * 16 + 154)
#define R_SCHEME_KEY_SCHEME_SELECT_3_UP							(R_START * 16 + 155)
#define R_SCHEME_KEY_SCHEME_SELECT_4_DOWN						(R_START * 16 + 156)
#define R_SCHEME_KEY_SCHEME_SELECT_4_UP							(R_START * 16 + 157)
#define R_SCHEME_KEY_SCHEME_SELECT_5_DOWN						(R_START * 16 + 158)
#define R_SCHEME_KEY_SCHEME_SELECT_5_UP							(R_START * 16 + 159)
#define R_SCHEME_KEY_SCHEME_SELECT_6_DOWN						(R_START * 16 + 160)
#define R_SCHEME_KEY_SCHEME_SELECT_6_UP							(R_START * 16 + 161)
#define R_SCHEME_KEY_SCHEME_SELECT_7_DOWN						(R_START * 16 + 162)
#define R_SCHEME_KEY_SCHEME_SELECT_7_UP							(R_START * 16 + 163)
#define R_SCHEME_KEY_SCHEME_SELECT_8_DOWN						(R_START * 16 + 164)
#define R_SCHEME_KEY_SCHEME_SELECT_8_UP							(R_START * 16 + 165)
#define R_SCHEME_KEY_SCHEME_SELECT_9_DOWN						(R_START * 16 + 166)
#define R_SCHEME_KEY_SCHEME_SELECT_9_UP							(R_START * 16 + 167)
#define R_SCHEME_KEY_SCHEME_SELECT_10_DOWN						(R_START * 16 + 168)
#define R_SCHEME_KEY_SCHEME_SELECT_10_UP						(R_START * 16 + 169)
#define R_SCHEME_KEY_SCHEME_SELECT_11_DOWN						(R_START * 16 + 170)
#define R_SCHEME_KEY_SCHEME_SELECT_11_UP						(R_START * 16 + 171)
#define R_SCHEME_KEY_SCHEME_SELECT_12_DOWN						(R_START * 16 + 172)
#define R_SCHEME_KEY_SCHEME_SELECT_12_UP						(R_START * 16 + 173)
#define R_SCHEME_KEY_SCHEME_SELECT_13_DOWN						(R_START * 16 + 174)
#define R_SCHEME_KEY_SCHEME_SELECT_13_UP						(R_START * 16 + 175)
#define R_SCHEME_KEY_SCHEME_SELECT_14_DOWN						(R_START * 16 + 176)
#define R_SCHEME_KEY_SCHEME_SELECT_14_UP						(R_START * 16 + 177)
#define R_SCHEME_KEY_SCHEME_SELECT_15_DOWN						(R_START * 16 + 178)
#define R_SCHEME_KEY_SCHEME_SELECT_15_UP						(R_START * 16 + 179)
/*****************************************************************************/
#define R_DIAGNOSIS_OK_DOWN										(R_START * 16 + 190)
#define R_DIAGNOSIS_OK_UP										(R_START * 16 + 191)
/*****************************************************************************/
#define MR_FOOSWITCH_HAND_SWITCH								(MR_START * 16 + 10)//脚踏HandSwitch 脉冲控制
/*****************************************************************************/
#define T100MS_HMI_POWERUP_DELAY								0//HMI启动复位延时
#define T100MS_CHECK_PROCESSOR_DELAY							1//存储器自检等待延迟
#define T100MS_CHECK_EPROM_DELAY								2//总线自检等待延迟
#define T100MS_CHECK_SI7060_DELAY								3//
#define T100MS_CHECK_MCP79412_DELAY								4//
#define T100MS_CHECK_SPI_FLASH_DELAY							5//
#define T100MS_CHECK_CH376_DELAY								6//
#define T100MS_CHECK_DK25L_DELAY								7//NFC读卡模块等待延迟
#define T100MS_CHECK_NRF24L01_DELAY								8//激光驱动器自检等待延迟
#define T100MS_CHECK_TEMPERATURE_DELAY							9
#define T100MS_CHECK_LASER_DRIVER_DELAY							10
#define T100MS_CHECK_WIRELESS_FOOTCONTROL_DELAY					11
#define T100MS_CHECK_PROBATION_DELAY							12//USBHOST模块等待延迟
#define T100MS_ENTER_PASSCODE_DELAY								13
#define T100MS_READY_BEEM_DELAY									14//进入READY状态后蜂鸣器响延迟
/*****************************************************************************/
#define T10MS_POSWIDTH_ADD_KEYDOWN_DELAY						3
#define T10MS_POSWIDTH_DEC_KEYDOWN_DELAY						4
#define T10MS_NEGWIDTH_ADD_KEYDOWN_DELAY						5
#define T10MS_NEGWIDTH_DEC_KEYDOWN_DELAY						6
#define T10MS_TIMES_ADD_KEYDOWN_DELAY							7
#define T10MS_TIMES_DEC_KEYDOWN_DELAY							8
#define T10MS_GROUP_OFF_ADD_KEYDOWN_DELAY						9
#define T10MS_GROUP_OFF_DEC_KEYDOWN_DELAY						10
#define T10MS_ENERGY_INTERVAL_ADD_KEYDOWN_DELAY					11
#define T10MS_ENERGY_INTERVAL_DEC_KEYDOWN_DELAY					12
#endif