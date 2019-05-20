#ifndef __APPSPLCADR_H__
#define __APPSPLCADR_H__
/*****************************************************************************/
#define CONFIG_APP_DIODE_HIGH_TEMP				400
#define CONFIG_APP_DRIVE_HIGH_TEMP				650
#define CONFIG_APP_ENVI_HIGH_TEMP				500
/*****************************************************************************/
#define CONFIG_HMI_SCHEME_NUM					16//方案数
#define CONFIG_HMI_DEFAULT_PASSSWORD0			0x3433//默认密码
#define CONFIG_HMI_DEFAULT_PASSSWORD1			0x3231//默认密码
#define STATUS_LASER_READY						0x5A
#define STATUS_LASER_STANDBY					0xA5
#define BEEM_MODE_BEEP							0x1234
#define BEEM_MODE_TONE							0x4321
#define AIM_MODE_CW_GREEN						0x5678//连续绿色
#define AIM_MODE_CW_RED							0x9ABC//连续红色
//故障码
#define ERROR_CODE_EPROM						0x0001//EPRON 错误
#define ERROR_CODE_SPI_FLASH					0x0002//SPI FLSAH错误
#define ERROR_CODE_SI7060						0x0003//温度传感器通信错误
#define ERROR_CODE_MCP79412						0x0004//RTC通信错误
#define ERROR_CODE_LDR0							0x0005//激光驱动器0错误
#define ERROR_CODE_LDR1							0x0006//激光驱动器1错误
#define ERROR_CODE_TEMPER						0x0007//温度传感器错误
#define ERROR_CODE_USBHOST						0x0008//USB HOST模块错误
#define ERROR_CODE_NFC							0x0009//NFC模块错误
#define ERROR_CODE_NRF24L01						0x0010//NRF24L01模块错误
#define ERRPR_CODE_NOERR						0xFFFF//无错误
/*****************************************************************************/
#define EM_LASER_SCHEME_NAME					(EM_START + 0)//方案名称
#define EM_LASER_SELECT							(EM_START + 17)//通道选择
#define EM_LASER_PULSE_MODE						(EM_START + 18)//脉冲模式
#define EM_LASER_POWER_CH0						(EM_START + 19)//通道0功率
#define EM_LASER_POWER_CH1						(EM_START + 20)//通道1功率
#define EM_LASER_POSWIDTH						(EM_START + 21)//正脉宽
#define EM_LASER_NEGWIDTH						(EM_START + 22)//负脉宽
#define EM_LASER_GROUP							(EM_START + 23)//脉冲数
#define EM_LASER_SPACE							(EM_START + 24)//脉冲间隔
#define EM_DIODE_TEMP0							(EM_START + 25)//二极管温度0
#define EM_DIODE_TEMP1							(EM_START + 26)//二极管温度1
#define EM_DRIVE_TEMP							(EM_START + 27)//驱动器温度
#define EM_ENVI_TEMP							(EM_START + 28)//环境温度
#define EM_DIODE_HIGH_TEMP						(EM_START + 29)//二极管过热阈值
#define EM_DRIVE_HIGH_TEMP						(EM_START + 30)//驱动器过热阈值
#define EM_ENVI_HIGH_TEMP						(EM_START + 31)//环境过热阈值
/*****************************************************************************/
#define EM_EPID0_TAB_OUT						(EM_START + 32)//EPID输出值地址
#define EM_EPID0_TAB_REF						(EM_START + 33)//EPID设置定值
#define EM_EPID0_TAB_VFB						(EM_START + 34)//EPID反馈值
#define EM_EPID0_TAB_KP							(EM_START + 35)//EPID比例常数 XX.XXX 0-65.535
#define	EM_EPID0_TAB_KI							(EM_START +	36)//EPID积分常数 XX.XXX 0-65.535		
#define EM_EPID0_TAB_TD 						(EM_START + 37)//EPID微分时间常数 XX.XXX 0-65.535
#define EM_EPID0_TAB_TS							(EM_START + 38)//EPID运算时间间隔 1-3000 单位0.01S
#define EM_EPID0_TAB_EN_FP32L					(EM_START +	39)//EPID当前误差值 FP32 
#define EM_EPID0_TAB_EN_FP32H					(EM_START +	40)//EPID当前误差值 FP32 
#define EM_EPID0_TAB_VFB1_FP32L 				(EM_START +	41)//EPID前1次误差值 FP32
#define EM_EPID0_TAB_VFB1_FP32H					(EM_START +	42)//EPID前1次误差值 FP32
#define EM_EPID0_TAB_MAX						(EM_START + 43)//EPID输出最大限制		691
#define EM_EPID0_TAB_MIN						(EM_START + 44)//EPID输出最小限制		692
#define EM_EPID0_TAB_BIAS						(EM_START +	45)//EPID输出偏置			693
#define EM_EPID0_TAB_TSC						(EM_START + 46)//EPID间隔计时器			694
#define EM_EPID0_TAB_KP_SUM_FP32L				(EM_START +	47)//EPID比例累加值 FP32	695
#define EM_EPID0_TAB_KP_SUM_FP32H				(EM_START +	48)//EPID比例累加值 FP32	696
#define EM_EPID0_TAB_KI_SUM_FP32L				(EM_START +	49)//EPID微分累加值 FP32	697
#define EM_EPID0_TAB_KI_SUM_FP32H				(EM_START +	50)//EPID微分累加值 FP32	698
#define EM_EPID0_TAB_KD_SUM_FP32L				(EM_START +	51)//EPID微分累加值 FP32	699
#define EM_EPID0_TAB_KD_SUM_FP32H				(EM_START +	52)//EPID微分累加值 FP32	700
#define EM_EPID0_TAB_FOUT_FP32L					(EM_START +	53)//EPID输出累加值 FP32	701
#define EM_EPID0_TAB_FOUT_FP32H					(EM_START +	54)//EPID输出累加值 FP32	702
#define EM_LASER_CURRENT_0						(EM_START +	55)//激光器电流0			703
#define EM_LASER_CURRENT_1						(EM_START +	56)//激光器电流1			704
#define EM_HMI_OPERA_STEP						(EM_START +	57)//操作步骤				705				
#define EM_ERROR_CODE							(EM_START + 58)//错误码					706

#define EM_DC_PAGE								(EM_START + 128)//HMI页面编号 			776
#define EM_DC_PASSCODE_INDEX					(EM_START + 129)//密码输入位索引		777
#define EM_DC_NEW_PASSCODE0						(EM_START + 130)//输入新密码0			778
#define EM_DC_NEW_PASSCODE1						(EM_START + 131)//输入新密码1			779
#define EM_DC_NEW_PASSCODE2						(EM_START + 132)//输入新密码0			778
#define EM_DC_NEW_PASSCODE3						(EM_START + 133)//输入新密码1			779
#define EM_DC_DEFAULT_PASSCODE0					(EM_START + 134)//默认密码0				780
#define EM_DC_DEFAULT_PASSCODE1					(EM_START + 135)//默认密码1				781
#define EM_DC_DEFAULT_PASSCODE2					(EM_START + 136)//默认密码1				781
#define EM_DC_DEFAULT_PASSCODE3					(EM_START + 137)//默认密码1				781
#define EM_DC_DISPLAY_RELEASE_TIME				(EM_START + 138)//显示发射时间			782
#define EM_DC_DISPLAY_RELEASE_ENERGY			(EM_START + 139)//显示发射能量			783

/*****************************************************************************/
#define DM_LASER_SCHEME_NAME					(DM_START +  0)//方案名称				72
#define DM_LASER_SELECT							(DM_START +  17)//通道选择				89			
#define DM_LASER_PULSE_MODE						(DM_START +  18)//脉冲模式				90
#define DM_LASER_POWER_0						(DM_START +  19)//通道0功率				91
#define DM_LASER_POWER_1						(DM_START +  20)//通道1功率				92
#define DM_LASER_POSWIDTH						(DM_START +  21)//正脉宽				93
#define DM_LASER_NEGWIDTH						(DM_START +  22)//负脉宽				94
#define DM_LASER_GROUP							(DM_START +  23)//脉冲数				95
#define DM_LASER_SPACE							(DM_START +  24)//脉冲间隔				96

#define DM_SCHEME_START_0						(DM_START +   0)//方案0存储区起始		72
#define DM_SCHEME_END_0							(DM_START +  24)//方案0存储区结束		96

#define DM_SCHEME_START_1						(DM_START +  25)//方案1存储区起始		
#define DM_SCHEME_END_1							(DM_START +  49)//方案1存储区结束

#define DM_SCHEME_START_2						(DM_START +  50)//方案2存储区起始
#define DM_SCHEME_END_2							(DM_START +  74)//方案2存储区结束

#define DM_SCHEME_START_3						(DM_START +  75)//方案3存储区起始
#define DM_SCHEME_END_3							(DM_START +  99)//方案3存储区结束

#define DM_SCHEME_START_4						(DM_START + 100)//方案4存储区起始
#define DM_SCHEME_END_4							(DM_START + 124)//方案4存储区结束

#define DM_SCHEME_START_5						(DM_START + 125)//方案5存储区起始
#define DM_SCHEME_END_5							(DM_START + 149)//方案5存储区结束

#define DM_SCHEME_START_6						(DM_START + 150)//方案6存储区起始
#define DM_SCHEME_END_6							(DM_START + 174)//方案6存储区结束

#define DM_SCHEME_START_7						(DM_START + 175)//方案7存储区起始
#define DM_SCHEME_END_7							(DM_START + 199)//方案7存储区结束

#define DM_SCHEME_START_8						(DM_START + 200)//方案8存储区起始
#define DM_SCHEME_END_8							(DM_START + 224)//方案8存储区结束

#define DM_SCHEME_START_9						(DM_START + 225)//方案9存储区起始
#define DM_SCHEME_END_9							(DM_START + 249)//方案9存储区结束

#define DM_SCHEME_START_10						(DM_START + 250)//方案10存储区起始
#define DM_SCHEME_END_10						(DM_START + 274)//方案10存储区结束

#define DM_SCHEME_START_11						(DM_START + 275)//方案11存储区起始
#define DM_SCHEME_END_11						(DM_START + 299)//方案11存储区结束

#define DM_SCHEME_START_12						(DM_START + 300)//方案12存储区起始
#define DM_SCHEME_END_12						(DM_START + 324)//方案12存储区结束

#define DM_SCHEME_START_13						(DM_START + 325)//方案13存储区起始
#define DM_SCHEME_END_13						(DM_START + 349)//方案13存储区结束

#define DM_SCHEME_START_14						(DM_START + 350)//方案14存储区起始
#define DM_SCHEME_END_14						(DM_START + 374)//方案14存储区结束

#define DM_SCHEME_START_15						(DM_START + 375)//方案15存储区起始
#define DM_SCHEME_END_15						(DM_START + 399)//方案15存储区结束

#define DM_CORR_TAB0_POWER0						(DM_START + 400)//功率校正表0功率0 
#define DM_CORR_TAB0_POWER1						(DM_START + 401)//功率校正表0功率2 
#define DM_CORR_TAB0_POWER2						(DM_START + 402)//功率校正表0功率4 
#define DM_CORR_TAB0_POWER3						(DM_START + 403)//功率校正表0功率6 
#define DM_CORR_TAB0_POWER4						(DM_START + 404)//功率校正表0功率8 
#define DM_CORR_TAB0_POWER5						(DM_START + 405)//功率校正表0功率10 
#define DM_CORR_TAB0_POWER6						(DM_START + 406)//功率校正表0功率12 
#define DM_CORR_TAB0_POWER7						(DM_START + 407)//功率校正表0功率14 
#define DM_CORR_TAB0_POWER8						(DM_START + 408)//功率校正表0功率16 
#define DM_CORR_TAB0_POWER9						(DM_START + 409)//功率校正表0功率18 
#define DM_CORR_TAB0_POWER10					(DM_START + 410)//功率校正表0功率20 
#define DM_CORR_TAB0_POWER11					(DM_START + 411)//功率校正表0功率22 
#define DM_CORR_TAB0_POWER12					(DM_START + 412)//功率校正表0功率24 
#define DM_CORR_TAB0_POWER13					(DM_START + 413)//功率校正表0功率26 
#define DM_CORR_TAB0_POWER14					(DM_START + 414)//功率校正表0功率28 
#define DM_CORR_TAB0_POWER15					(DM_START + 415)//功率校正表0功率30 
#define DM_CORR_TAB0_POWER16					(DM_START + 416)//功率校正表0功率32 
#define DM_CORR_TAB0_POWER17					(DM_START + 417)//功率校正表0功率34 
#define DM_CORR_TAB0_POWER18					(DM_START + 418)//功率校正表0功率36
#define DM_CORR_TAB0_POWER19					(DM_START + 419)//功率校正表0功率38
#define DM_CORR_TAB0_POWER20					(DM_START + 420)//功率校正表0功率40

#define DM_CORR_TAB1_POWER0						(DM_START + 421)//功率校正表1功率0 			
#define DM_CORR_TAB1_POWER1						(DM_START + 422)//功率校正表1功率2
#define DM_CORR_TAB1_POWER2						(DM_START + 423)//功率校正表1功率4
#define DM_CORR_TAB1_POWER3						(DM_START + 424)//功率校正表1功率6 
#define DM_CORR_TAB1_POWER4						(DM_START + 425)//功率校正表1功率8 
#define DM_CORR_TAB1_POWER5						(DM_START + 426)//功率校正表1功率10 
#define DM_CORR_TAB1_POWER6						(DM_START + 427)//功率校正表1功率12 
#define DM_CORR_TAB1_POWER7						(DM_START + 428)//功率校正表1功率14 
#define DM_CORR_TAB1_POWER8						(DM_START + 429)//功率校正表1功率16 
#define DM_CORR_TAB1_POWER9						(DM_START + 430)//功率校正表1功率18 
#define DM_CORR_TAB1_POWER10					(DM_START + 431)//功率校正表1功率20 
#define DM_CORR_TAB1_POWER11					(DM_START + 432)//功率校正表1功率22 
#define DM_CORR_TAB1_POWER12					(DM_START + 433)//功率校正表1功率24 
#define DM_CORR_TAB1_POWER13					(DM_START + 434)//功率校正表1功率26 
#define DM_CORR_TAB1_POWER14					(DM_START + 435)//功率校正表1功率28 
#define DM_CORR_TAB1_POWER15					(DM_START + 436)//功率校正表1功率30 
#define DM_CORR_TAB1_POWER16					(DM_START + 437)//功率校正表1功率32 
#define DM_CORR_TAB1_POWER17					(DM_START + 438)//功率校正表1功率34 
#define DM_CORR_TAB1_POWER18					(DM_START + 439)//功率校正表1功率36 
#define DM_CORR_TAB1_POWER19					(DM_START + 440)//功率校正表1功率38
#define DM_CORR_TAB1_POWER20					(DM_START + 441)//功率校正表1功率40

#define DM_SCHEME_NUM							(DM_START + 442)//选择的方案编号 低8位方案号 高8位方案使能
#define DM_BEEM_VOLUME							(DM_START + 443)//蜂鸣器音量
#define DM_BEEM_MODE							(DM_START + 444)//蜂鸣器模式
#define DM_AIM_MODE								(DM_START + 445)//指示激光模式
#define DM_AIM_RED_BRG							(DM_START + 446)//红色指示激光亮度
#define DM_AIM_GREEN_BRG						(DM_START + 447)//绿色指示激光亮度
#define DM_LCD_BRG								(DM_START + 448)//屏幕亮度
#define DM_DC_OLD_PASSCODE0						(DM_START + 449)//屏旧密码0-1
#define DM_DC_OLD_PASSCODE1						(DM_START + 450)//屏旧密码2-3
#define DM_DC_OLD_PASSCODE2						(DM_START + 451)//屏旧密码0-1
#define DM_DC_OLD_PASSCODE3						(DM_START + 452)//屏旧密码2-3
#define DM_SYS_RUNTIME_L						(DM_START + 453)//系统累计运行时间秒L 32BIT
#define DM_SYS_RUNTIME_H						(DM_START + 454)//系统累计运行时间秒H 32BIT
#define DM_LAR_RUNTIME_L						(DM_START + 455)//激光累计发射时间秒L 32BIT
#define DM_LAR_RUNTIME_H						(DM_START + 456)//激光累计发射时间秒H 32BIT
#define DM_RELEASE_DATA_YEAR					(DM_START + 457)//出厂日期年		
#define DM_RELEASE_DATA_MONTH					(DM_START + 458)//出厂日期月
#define DM_RELEASE_DATA_DAY						(DM_START + 459)//出厂日期日
#define DM_LANGUAGE								(DM_START + 460)//语言选择
/*****************************************************************************/
#define X_INTERLOCK								(X_START * 16 + 0)//XIN0 安全连锁
#define X_ESTOP									(X_START * 16 + 1)//XIN1 紧急停止开关
#define X_FOOTSWITCH_OC							(X_START * 16 + 2)//XIN2 脚踏常开
#define X_FOOTSWITCH_ON							(X_START * 16 + 3)//XIN3 脚踏常闭
#define X_LDR_FAULT0							(X_START * 16 + 4)//XIN4 驱动器故障0
#define X_LDR_FAULT1							(X_START * 16 + 5)//XIN5 驱动器故障1
#define X_FBD0									(X_START * 16 + 6)//XIN6 光纤探测0
#define X_FBD1									(X_START * 16 + 7)//XIN7 光纤探测1
/*****************************************************************************/
#define Y_LED_POWERON							(Y_START * 16 + 0)//YOUT0 电源灯
#define Y_LED_EMIT								(Y_START * 16 + 1)//YOUT1 激光指示灯
#define Y_LED_ALARM								(Y_START * 16 + 2)//YOUT2 故障指示灯
#define Y_OUT3									(Y_START * 16 + 3)//YOUT3 保留
#define Y_OUT4									(Y_START * 16 + 4)//YOUT4 保留
#define Y_OUT5									(Y_START * 16 + 5)//YOUT5 保留
#define Y_OUT6									(Y_START * 16 + 6)//YOUT6 保留
#define Y_OUT7									(Y_START * 16 + 7)//YOUT7 保留
#define Y_FAN0									(Y_START * 16 + 8)//YOUT8 风扇开关0
#define Y_FAN1									(Y_START * 16 + 9)//YOUT9 风扇开关1
#define Y_TEC0									(Y_START * 16 + 10)//YOUT10 制冷开关0
#define Y_TEC1									(Y_START * 16 + 11)//YOUT11 制冷开关1
/*****************************************************************************/
#define R_FIBER_ID_PASS_0						(R_START * 16 + 0)//通道0光纤ID标志
#define R_FIBER_ID_PASS_1						(R_START * 16 + 1)//通道1光纤ID标志
#define R_DIODE_TEMP_HIGH_0						(R_START * 16 + 2)//通道0二极管高温标志
#define R_DIODE_TEMP_HIGH_1						(R_START * 16 + 3)//通道1二极管高温标志
#define R_DRIVE_TEMP_HIGH						(R_START * 16 + 4)//驱动器高温标志
#define R_ENVI_TEMP_HIGH						(R_START * 16 + 5)//环境温度标度
#define R_DRIVE_FAULT_0							(R_START * 16 + 6)//通道0驱动器故障标志
#define R_DRIVE_FAULT_1							(R_START * 16 + 7)//通道1驱动器故障标志
#define R_SAFE_FAULT							(R_START * 16 + 8)//安全标志
#define R_SCHEME_LOAD_REQ						(R_START * 16 + 9)//方案载入请求
#define R_SHCEME_SAVE_REQ						(R_START * 16 + 10)//方案储存请求
//HMI相关状态
#define R_DCHMI_RESET_REQ						(R_START * 16 + 47)//HMI复位请求
#define R_DCHMI_RESET_DOING						(R_START * 16 + 48)//HMI复位中
#define R_DCHMI_RESET_DONE						(R_START * 16 + 49)//HMI复位完成	
#define R_DCHMI_UPDATEUI_REQ					(R_START * 16 + 50)//HMI内容更新请求
#define R_DCHMI_UPDATEUI_DOING					(R_START * 16 + 51)//HMI内容更新中
#define R_DCHMO_UPDATEUI_DONE					(R_START * 16 + 52)//HMI内容更新请求完成
#define R_DCHMI_RESTORE_REQ						(R_START * 16 + 53)//HMI从FLASH中恢复设置请求
#define R_DCHMI_RESTORE_DOING					(R_START * 16 + 54)//HMI从FLASH中恢复中
#define R_DCHMI_RESTORE_DONE					(R_START * 16 + 55)//HMI从FLASH中恢复设置完成	
//自检状态
#define R_CHECK_FLOAT_DONE						(R_START * 16 + 100)//浮点自检完毕
#define R_CHECK_EPROM_DONE						(R_START * 16 + 101)//存储器自检完毕
#define R_CHECK_SI7060_DONE						(R_START * 16 + 102)//SI7060温度传感器自检完毕
#define R_CHECK_MCP79412_DONE					(R_START * 16 + 103)//板载RTC自检完毕
#define R_CHECK_BACKUP_MEMORY_DONE				(R_START * 16 + 104)//外部FLASH自检完毕
#define R_CHECK_CH376_DONE						(R_START * 16 + 105)//USB CH376自检完毕
#define R_CHECK_PN7150B0HN_DONE					(R_START * 16 + 106)//PN7150B0HN模块完毕
#define R_CHECK_NRF24L01_DONE					(R_START * 16 + 107)//NRF24L01模块自检完毕
#define R_CHECK_LASER_DRIVER_DONE				(R_START * 16 + 108)//激光驱动器自检完毕
#define R_CHECK_TEMPERATURE_DONE				(R_START * 16 + 109)//温度自检完毕
#define R_CHECK_SAFETY_INTERLOCK_DONE			(R_START * 16 + 110)//安全连锁自检完毕
#define R_CHECK_WIRE_FOOTCONTROL_DONE			(R_START * 16 + 111)//有线脚踏自检完毕
#define R_CHECK_FIBER_SENSOR_DONE				(R_START * 16 + 112)//光纤传感器自检完毕
#define R_CHECK_WIRELESS_FOOTCONTROL_DONE		(R_START * 16 + 113)//无线脚踏自检完毕
#define R_CHECK_PROBATION_DONE					(R_START * 16 + 114)//试用期自检完毕
 
#define R_CHECK_FLOAT_PASS						(R_START * 16 + 120)//浮点自检通过
#define R_CHECK_EPROM_PASS						(R_START * 16 + 121)//存储器自检通过
#define R_CHECK_SI7060_PASS						(R_START * 16 + 122)//SI7060温度传感器自检通过
#define R_CHECK_MCP79412_PASS					(R_START * 16 + 123)//板载RTC自检通过
#define R_CHECK_BACKUP_MEMORY_PASS				(R_START * 16 + 124)//外部FLASH自检通过
#define R_CHECK_CH376_PASS						(R_START * 16 + 125)//USB CH376自检自检通过
#define R_CHECK_PN7150B0HN_PASS					(R_START * 16 + 126)//NFC模块自检通过
#define R_CHECK_NRF24L01_PASS					(R_START * 16 + 127)//NRF24L01模块自检通过
#define R_CHECK_LASER_DRIVER_PASS				(R_START * 16 + 128)//激光驱动器自检通过
#define R_CHECK_TEMPERATURE_PASS				(R_START * 16 + 129)//温度自检通过
#define R_CHECK_SAFETY_INTERLOCK_PASS			(R_START * 16 + 130)//安全连锁自检通过
#define R_CHECK_WIRE_FOOTCONTROL_PASS			(R_START * 16 + 131)//有线脚踏自检通过
#define R_CHECK_FIBER_SENSOR_PASS				(R_START * 16 + 132)//光纤传感器自检通过
#define R_CHECK_WIRELESS_FOOTCONTROL_PASS		(R_START * 16 + 133)//无线脚踏自检通过
#define R_CHECK_PROBATION_PASS					(R_START * 16 + 134)//试用期自检通过

#define R_CHECK_FLOAT_FAIL						(R_START * 16 + 140)//浮点自检失败 
#define R_CHECK_EPROM_FAIL						(R_START * 16 + 141)//存储器自检失败
#define R_CHECK_SI7060_FAIL						(R_START * 16 + 142)//SI7060温度传感器自检失败
#define R_CHECK_MCP79412_FAIL					(R_START * 16 + 143)//板载RTC自检失败
#define R_CHECK_BACKUP_MEMORY_FAIL				(R_START * 16 + 144)//外部FLASH自检失败
#define R_CHECK_CH376_FAIL						(R_START * 16 + 145)//USB CH376自检自检失败
#define R_CHECK_PN7150B0HN_FAIL					(R_START * 16 + 146)//NFC模块自检失败
#define R_CHECK_NRF24L01_FAIL					(R_START * 16 + 147)//NRF24L01模块自检失败
#define R_CHECK_LASER_DRIVER_FAIL				(R_START * 16 + 148)//激光驱动器自检失败
#define R_CHECK_TEMPERATURE_FAIL				(R_START * 16 + 149)//温度自检失败
#define R_CHECK_SAFETY_INTERLOCK_FAIL			(R_START * 16 + 150)//安全连锁自检失败
#define R_CHECK_WIRE_FOOTCONTROL_FAIL			(R_START * 16 + 151)//有线脚踏自检失败
#define R_CHECK_FIBER_SENSOR_FAIL				(R_START * 16 + 152)//光纤传感器自检失败
#define R_CHECK_WIRELESS_FOOTCONTROL_FAIL		(R_START * 16 + 153)//无线脚踏自检失败
#define R_CHECK_PROBATION_FAIL					(R_START * 16 + 154)//试用期自检失败
/*****************************************************************************/
#define R_STANDBY_KEY_POSWIDTH_ADD_DOWN			(R_START * 16 + 149)
#define R_STANDBY_KEY_POSWIDTH_ADD_UP			(R_START * 16 + 150)

#define R_STANDBY_KEY_POSWIDTH_DEC_DOWN			(R_START * 16 + 151)
#define R_STANDBY_KEY_POSWIDTH_DEC_UP			(R_START * 16 + 152)

#define R_STANDBY_KEY_NEGWIDTH_ADD_DOWN			(R_START * 16 + 153)
#define R_STANDBY_KEY_NEGWIDTH_ADD_UP			(R_START * 16 + 154)

#define R_STANDBY_KEY_NEGWIDTH_DEC_DOWN			(R_START * 16 + 155)
#define R_STANDBY_KEY_NEGWIDTH_DEC_UP			(R_START * 16 + 156)

#define R_STANDBY_KEY_GROUP_ADD_DOWN			(R_START * 16 + 157)
#define R_STANDBY_KEY_GROUP_ADD_UP				(R_START * 16 + 158)

#define R_STANDBY_KEY_GROUP_DEC_DOWN			(R_START * 16 + 159)
#define R_STANDBY_KEY_GROUP_DEC_UP				(R_START * 16 + 160)

#define R_STANDBY_KEY_SPACE_ADD_DOWN			(R_START * 16 + 161)
#define R_STANDBY_KEY_SPACE_ADD_UP				(R_START * 16 + 162)

#define R_STANDBY_KEY_SPACE_DEC_DOWN			(R_START * 16 + 163)
#define R_STANDBY_KEY_SPACE_DEC_UP				(R_START * 16 + 164)

#define R_STANDBY_KEY_POWER_CH0_ADD_DOWN		(R_START * 16 + 165)
#define R_STANDBY_KEY_POWER_CH0_ADD_UP			(R_START * 16 + 166)

#define R_STANDBY_KEY_POWER_CH0_DEC_DOWN		(R_START * 16 + 167)
#define R_STANDBY_KEY_POWER_CH0_DEC_UP			(R_START * 16 + 168)

#define R_STANDBY_KEY_POWER_CH1_ADD_DOWN		(R_START * 16 + 169)
#define R_STANDBY_KEY_POWER_CH1_ADD_UP			(R_START * 16 + 170)

#define R_STANDBY_KEY_POWER_CH1_DEC_DOWN		(R_START * 16 + 171)
#define R_STANDBY_KEY_POWER_CH1_DEC_UP			(R_START * 16 + 172)

#define R_STANDBY_KEY_STANDBY_DOWN				(R_START * 16 + 173)
#define R_STANDBY_KEY_STANDBY_UP				(R_START * 16 + 174)

#define R_STANDBY_KEY_ENERGY_RESET_DOWN			(R_START * 16 + 175)
#define R_STANDBY_KEY_ENERGY_RESET_UP			(R_START * 16 + 176)

#define R_STANDBY_KEY_SELECT_CH0_DOWN			(R_START * 16 + 177)
#define R_STANDBY_KEY_SELECT_CH0_UP				(R_START * 16 + 178)

#define R_STANDBY_KEY_SELECT_CH1_DOWN			(R_START * 16 + 179)
#define R_STANDBY_KEY_SELECT_CH1_UP				(R_START * 16 + 180)
	
#define R_STANDBY_KEY_SELECT_BOTH_DOWN			(R_START * 16 + 181)
#define R_STANDBY_KEY_SELECT_BOTH_UP			(R_START * 16 + 182)

#define R_STANDB_KEY_MODE_CW_DOWN				(R_START * 16 + 183)
#define R_STANDB_KEY_MODE_CW_UP					(R_START * 16 + 184)

#define R_STANDBY_KEY_MODE_MP_DOWN				(R_START * 16 + 185)
#define R_STANDBY_KEY_MODE_MP_UP				(R_START * 16 + 186)

#define R_STANDBY_KEY_MODE_GP_DOWN				(R_START * 16 + 187)
#define R_STANDBY_KEY_MODE_GP_UP				(R_START * 16 + 188)

#define R_STANDBY_KEY_MODE_EVLA_SEGMENT_DOWN	(R_START * 16 + 189)
#define R_STANDBY_KEY_MODE_EVLA_SEGMENT_UP		(R_START * 16 + 190)

#define R_STANDBY_KEY_MODE_EVLA_SIGNAL_DOWN		(R_START * 16 + 191)
#define R_STANDBY_KEY_MODE_EVLA_SIGNAL_UP		(R_START * 16 + 192)

#define R_STANDBY_KEY_MODE_DERMA_DOWN			(R_START * 16 + 193)
#define R_STANDBY_KEY_MODE_DERMA_UP				(R_START * 16 + 194)

#define R_STANDBY_KEY_OPTION_DOWN				(R_START * 16 + 195)
#define R_STANDBY_KEY_OPTION_UP					(R_START * 16 + 196)
/*****************************************************************************/
#define R_READY_KEY_READY_DOWN					(R_START * 16 + 197)
#define R_READY_KEY_READY_UP					(R_START * 16 + 198)
/*****************************************************************************/
#define R_OPTION_KEY_ENTER_CORRECTION_DOWN		(R_START * 16 + 199)
#define R_OPTION_KEY_ENTER_CORRECTION_UP		(R_START * 16 + 200)

#define R_OPTION_KEY_ENTER_INFORMATION_DOWN		(R_START * 16 + 201)
#define R_OPTION_KEY_ENTER_INFORMATION_UP		(R_START * 16 + 202)

#define R_OPTION_KEY_ENTER_SCHEME_DOWN			(R_START * 16 + 203)
#define R_OPTION_KEY_ENTER_SCHEME_UP			(R_START * 16 + 204)

#define R_OPTION_KEY_ENTER_OK_DOWN				(R_START * 16 + 205)
#define R_OPTION_KEY_ENTER_OK_UP				(R_START * 16 + 206)
/*****************************************************************************/
#define R_INFORMATION_KEY_OK_DOWN				(R_START * 16 + 207)
#define R_INFORMATION_KEY_OK_UP					(R_START * 16 + 208)
/*****************************************************************************/
#define R_SCHEME_KEY_RENAME_DOWN				(R_START * 16 + 209)
#define R_SCHEME_KEY_RENAME_UP					(R_START * 16 + 210)

#define R_SCHEME_KEY_SAVE_USB_DOWN				(R_START * 16 + 211)
#define R_SCHEME_KEY_SAVE_USB_UP				(R_START * 16 + 212)

#define R_SCHEME_KEY_LOAD_USB_DOWN				(R_START * 16 + 213)
#define R_SCHEME_KEY_LOAD_USB_UP				(R_START * 16 + 214)

#define R_SCHEME_KEY_ENTER_STANDBY_DOWN			(R_START * 16 + 215)
#define R_SCHEME_KEY_ENTER_STANDBY_UP			(R_START * 16 + 216)

#define R_SCHEME_KEY_SCHEME_SELECT_0_DOWN		(R_START * 16 + 217)		
#define R_SCHEME_KEY_SCHEME_SELECT_0_UP			(R_START * 16 + 218)

#define R_SCHEME_KEY_SCHEME_SELECT_1_DOWN		(R_START * 16 + 219)
#define R_SCHEME_KEY_SCHEME_SELECT_1_UP			(R_START * 16 + 220)

#define R_SCHEME_KEY_SCHEME_SELECT_2_DOWN		(R_START * 16 + 221)
#define R_SCHEME_KEY_SCHEME_SELECT_2_UP			(R_START * 16 + 222)

#define R_SCHEME_KEY_SCHEME_SELECT_3_DOWN		(R_START * 16 + 223)
#define R_SCHEME_KEY_SCHEME_SELECT_3_UP			(R_START * 16 + 224)

#define R_SCHEME_KEY_SCHEME_SELECT_4_DOWN		(R_START * 16 + 225)
#define R_SCHEME_KEY_SCHEME_SELECT_4_UP			(R_START * 16 + 226)

#define R_SCHEME_KEY_SCHEME_SELECT_5_DOWN		(R_START * 16 + 227)
#define R_SCHEME_KEY_SCHEME_SELECT_5_UP			(R_START * 16 + 228)

#define R_SCHEME_KEY_SCHEME_SELECT_6_DOWN		(R_START * 16 + 229)
#define R_SCHEME_KEY_SCHEME_SELECT_6_UP			(R_START * 16 + 230)

#define R_SCHEME_KEY_SCHEME_SELECT_7_DOWN		(R_START * 16 + 231)
#define R_SCHEME_KEY_SCHEME_SELECT_7_UP			(R_START * 16 + 232)

#define R_SCHEME_KEY_SCHEME_SELECT_8_DOWN		(R_START * 16 + 233)
#define R_SCHEME_KEY_SCHEME_SELECT_8_UP			(R_START * 16 + 234)

#define R_SCHEME_KEY_SCHEME_SELECT_9_DOWN		(R_START * 16 + 235)
#define R_SCHEME_KEY_SCHEME_SELECT_9_UP			(R_START * 16 + 236)

#define R_SCHEME_KEY_SCHEME_SELECT_10_DOWN		(R_START * 16 + 237)
#define R_SCHEME_KEY_SCHEME_SELECT_10_UP		(R_START * 16 + 238)

#define R_SCHEME_KEY_SCHEME_SELECT_11_DOWN		(R_START * 16 + 239)
#define R_SCHEME_KEY_SCHEME_SELECT_11_UP		(R_START * 16 + 240)

#define R_SCHEME_KEY_SCHEME_SELECT_12_DOWN		(R_START * 16 + 241)
#define R_SCHEME_KEY_SCHEME_SELECT_12_UP		(R_START * 16 + 242)

#define R_SCHEME_KEY_SCHEME_SELECT_13_DOWN		(R_START * 16 + 243)
#define R_SCHEME_KEY_SCHEME_SELECT_13_UP		(R_START * 16 + 244)

#define R_SCHEME_KEY_SCHEME_SELECT_14_DOWN		(R_START * 16 + 245)
#define R_SCHEME_KEY_SCHEME_SELECT_14_UP		(R_START * 16 + 246)

#define R_SCHEME_KEY_SCHEME_SELECT_15_DOWN		(R_START * 16 + 247)
#define R_SCHEME_KEY_SCHEME_SELECT_15_UP		(R_START * 16 + 248)

#define R_SCHEME_TEXTDISPLAY_SCHEME_0_DOWN		(R_START * 16 + 249)
#define R_SCHEME_TEXTDISPLAY_SCHEME_0_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_1_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_1_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_2_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_2_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_3_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_3_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_4_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_4_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_5_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_5_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_6_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_6_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_7_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_7_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_8_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_8_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_9_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_9_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_10_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_10_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_11_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_11_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_12_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_12_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_13_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_13_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_14_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_14_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_SCHEME_15_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_SCHEME_15_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_POSWIDTH_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_POSWIDTH_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_NEGWIDTH_DOWN		(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_NEGWIDTH_UP		(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPLAY_GROUP_DOWN			(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPLAY_GROUP_UP			(R_START * 16 + 250)

#define R_SCHEME_TEXTDISPALY_SPACE_DOWN			(R_START * 16 + 250)
#define R_SCHEME_TEXTDISPALY_SPACE_UP			(R_START * 16 + 250)
/*****************************************************************************/
#define T100MS_HMI_POWERUP_DELAY				0//HMI启动复位延时
#define T100MS_CHECK_PROCESSOR_DELAY			1//存储器自检等待延迟
#define T100MS_CHECK_EPROM_DELAY				2//总线自检等待延迟
#define T100MS_CHECK_SI7060_DELAY				3//
#define T100MS_CHECK_MCP79412_DELAY				4//
#define T100MS_CHECK_SPI_FLASH_DELAY			5//
#define T100MS_CHECK_CH376_DELAY				6//
#define T100MS_CHECK_PN7150B0HN_DELAY			7//NFC读卡模块等待延迟
#define T100MS_CHECK_NRF24L01_DELAY				8//激光驱动器自检等待延迟
#define T100MS_CHECK_TEMPERATURE_DELAY			9
#define T100MS_CHECK_LASER_DRIVER_DELAY			10
#define T100MS_CHECK_SAFETY_INTERLOCK_DELAY		11
#define T100MS_CHECK_WIRE_FOOTCONTROL_DELAY		12
#define T100MS_CHECK_FIBER_SENSOR_DELAY			13
#define T100MS_CHECK_WIRELESS_FOOTCONTROL_DELAY	14
#define T100MS_CHECK_PROBATION_DELAY			15//USBHOST模块等待延迟
#define T100MS_ENTER_PASSCODE_DELAY				16
#define T100MS_READY_BEEM_DELAY					20//进入READY状态后蜂鸣器响延迟
/*****************************************************************************/
#define T10MS_POSWIDTH_ADD_KEYDOWN_DELAY		3
#define T10MS_POSWIDTH_DEC_KEYDOWN_DELAY		4
#define T10MS_NEGWIDTH_ADD_KEYDOWN_DELAY		5
#define T10MS_NEGWIDTH_DEC_KEYDOWN_DELAY		6

#define T10MS_GROUP_ADD_KEYDOWN_DELAY			7
#define T10MS_GROUP_DEC_KEYDOWN_DELAY			8
#define T10MS_SPACE_ADD_KEYDOWN_DELAY			9
#define T10MS_SPACE_DEC_KEYDOWN_DELAY			10

#endif