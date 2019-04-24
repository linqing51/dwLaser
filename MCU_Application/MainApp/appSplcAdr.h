#ifndef __APPSPLCADR_H__
#define __APPSPLCADR_H__
/*****************************************************************************/
#define CONFIG_APP_DIODE_HIGH_TEMP				400
#define CONFIG_APP_DRIVE_HIGH_TEMP				650
#define CONFIG_APP_ENVI_HIGH_TEMP				500
/*****************************************************************************/
#define CONFIG_HMI_SCHEME_NUM					16//方案数
#define CONFIG_HMI_DEFAULT_PASSSWORD0			0x32//默认密码
#define CONFIG_HMI_DEFAULT_PASSSWORD1			0x35//默认密码
#define CONFIG_HMI_DEFAULT_PASSSWORD2			0x38//默认密码
#define CONFIG_HMI_DEFAULT_PASSSWORD3			0x30//默认密码
#define STATUS_LASER_READY						0x5A
#define STATUS_LASER_STANDBY					0xA5
#define ERROR_CODE_EPROM						0x0001
#define ERROR_CODE_INTBUS						0x0002
#define ERROR_CODE_LDR							0x0003
#define ERROR_CODE_TEMPER						0x0004
#define ERROR_CODE_USBHOST						0x0005
#define ERROR_CODE_NFC							0x0006
#define ERROR_CODE_NRF24L01						0x0007
#define ERRPR_CODE_NOERR						0xFFFF
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
#define EM_HMI_PAGE								(EM_START + 25)//HMI页面编号
#define EM_START_PROGRESS_BAR					(EM_START + 26)//HMI开机进度条
#define EM_NEW_PASSWORD0						(EM_START + 27)//HMI输入新密码0
#define EM_NEW_PASSWORD1						(EM_START + 28)//HMI输入新密码1
#define EM_DEFAULT_PASSWORD0					(EM_START + 29)//HMI进入默认密码0
#define EM_DEFAULT_PASSWORD1					(EM_START + 30)//HMI进入默认密码1
#define EM_DIODE_TEMP0							(EM_START + 31)//二极管温度0
#define EM_DIODE_TEMP1							(EM_START + 32)//二极管温度1
#define EM_DRIVE_TEMP							(EM_START + 33)//驱动器温度
#define EM_ENVI_TEMP							(EM_START + 34)//环境温度
#define EM_DIODE_HIGH_TEMP						(EM_START + 35)//二极管过热阈值
#define EM_DRIVE_HIGH_TEMP						(EM_START + 36)//驱动器过热阈值
#define EM_ENVI_HIGH_TEMP						(EM_START + 37)//环境过热阈值
/*****************************************************************************/
#define EM_EPID0_TAB_OUT						(EM_START + 38)//EPID输出值地址
#define EM_EPID0_TAB_REF						(EM_START + 39)//EPID设置定值
#define EM_EPID0_TAB_VFB						(EM_START + 40)//EPID反馈值
#define EM_EPID0_TAB_KP							(EM_START + 41)//EPID比例常数 XX.XXX 0-65.535
#define	EM_EPID0_TAB_KI							(EM_START +	42)//EPID积分常数 XX.XXX 0-65.535		
#define EM_EPID0_TAB_TD 						(EM_START + 43)//EPID微分时间常数 XX.XXX 0-65.535
#define EM_EPID0_TAB_TS							(EM_START + 44)//EPID运算时间间隔 1-3000 单位0.01S
#define EM_EPID0_TAB_EN_FP32L					(EM_START +	45)//EPID当前误差值 FP32 
#define EM_EPID0_TAB_EN_FP32H					(EM_START +	46)//EPID当前误差值 FP32 
#define EM_EPID0_TAB_VFB1_FP32L 				(EM_START +	47)//EPID前1次误差值 FP32
#define EM_EPID0_TAB_VFB1_FP32H					(EM_START +	48)//EPID前1次误差值 FP32
#define EM_EPID0_TAB_MAX						(EM_START + 49)//EPID输出最大限制		
#define EM_EPID0_TAB_MIN						(EM_START + 50)//EPID输出最小限制
#define EM_EPID0_TAB_BIAS						(EM_START +	51)//EPID输出偏置
#define EM_EPID0_TAB_TSC						(EM_START + 52)//EPID间隔计时器
#define EM_EPID0_TAB_KP_SUM_FP32L				(EM_START +	53)//EPID比例累加值 FP32
#define EM_EPID0_TAB_KP_SUM_FP32H				(EM_START +	54)//EPID比例累加值 FP32
#define EM_EPID0_TAB_KI_SUM_FP32L				(EM_START +	55)//EPID微分累加值 FP32
#define EM_EPID0_TAB_KI_SUM_FP32H				(EM_START +	56)//EPID微分累加值 FP32
#define EM_EPID0_TAB_KD_SUM_FP32L				(EM_START +	57)//EPID微分累加值 FP32
#define EM_EPID0_TAB_KD_SUM_FP32H				(EM_START +	58)//EPID微分累加值 FP32
#define EM_EPID0_TAB_FOUT_FP32L					(EM_START +	59)//EPID输出累加值 FP32
#define EM_EPID0_TAB_FOUT_FP32H					(EM_START +	60)//EPID输出累加值 FP32
#define EM_LASER_CURRENT_0						(EM_START +	61)//激光器电流0
#define EM_LASER_CURRENT_1						(EM_START +	62)//激光器电流1
#define EM_HMI_OPERA_STEP						(EM_START +	63)//操作步骤
#define EM_ERROR_CODE							(EM_START + 64)//错误码
/*****************************************************************************/
#define DM_LASER_SCHEME_NAME					(DM_START + 0)//方案名称
#define DM_LASER_SELECT							(DM_START + 17)//通道选择
#define DM_LASER_PULSE_MODE						(DM_START + 18)//脉冲模式
#define DM_LASER_POWER_0						(DM_START + 19)//通道0功率
#define DM_LASER_POWER_1						(DM_START + 20)//通道1功率
#define DM_LASER_POSWIDTH						(DM_START + 21)//正脉宽
#define DM_LASER_NEGWIDTH						(DM_START + 22)//负脉宽
#define DM_LASER_GROUP							(DM_START + 23)//脉冲数
#define DM_LASER_SPACE							(DM_START + 24)//脉冲间隔

#define DM_SCHEME_START_0						(DM_START +   0)//方案0存储区
#define DM_SCHEME_END_0							(DM_START +  24)

#define DM_SCHEME_START_1						(DM_START +  25)//方案1存储区
#define DM_SCHEME_END_1							(DM_START +  49)

#define DM_SCHEME_START_2						(DM_START +  50)//方案2存储区
#define DM_SCHEME_END_2							(DM_START +  74)

#define DM_SCHEME_START_3						(DM_START +  75)//方案3存储区
#define DM_SCHEME_END_3							(DM_START +  99)

#define DM_SCHEME_START_4						(DM_START + 100)//方案4存储区
#define DM_SCHEME_END_4							(DM_START + 124)

#define DM_SCHEME_START_5						(DM_START + 125)//方案5存储区
#define DM_SCHEME_END_5							(DM_START + 149)

#define DM_SCHEME_START_6						(DM_START + 150)//方案6存储区
#define DM_SCHEME_END_6							(DM_START + 174)

#define DM_SCHEME_START_7						(DM_START + 175)//方案7存储区
#define DM_SCHEME_END_7							(DM_START + 199)

#define DM_SCHEME_START_8						(DM_START + 200)//方案8存储区
#define DM_SCHEME_END_8							(DM_START + 224)

#define DM_SCHEME_START_9						(DM_START + 225)//方案11存储区
#define DM_SCHEME_END_9							(DM_START + 249)

#define DM_SCHEME_START_10						(DM_START + 250)//方案10存储区
#define DM_SCHEME_END_10						(DM_START + 274)

#define DM_SCHEME_START_11						(DM_START + 275)//方案11存储区
#define DM_SCHEME_END_11						(DM_START + 299)

#define DM_SCHEME_START_12						(DM_START + 300)//方案12存储区
#define DM_SCHEME_END_12						(DM_START + 324)

#define DM_SCHEME_START_13						(DM_START + 325)//方案13存储区
#define DM_SCHEME_END_13						(DM_START + 349)

#define DM_SCHEME_START_14						(DM_START + 350)//方案14存储区
#define DM_SCHEME_END_14						(DM_START + 374)

#define DM_SCHEME_START_15						(DM_START + 375)//方案15存储区
#define DM_SCHEME_END_15						(DM_START + 399)

#define DM_CORR_TAB0_POWER						(DM_START + 400)//功率校正表0功率 固定功率写DAC CODE
#define DM_CORR_TAB1_POWER						(DM_START + 420)//功率校正表1功率 固定功率写DAC CODE			
#define DM_SCHEME_NUM							(DM_START + 440)//选择的方案编号
#define DM_BEEM_VOLUME							(DM_START + 441)
#define DM_OLD_PASSWORD0						(DM_START + 442)
#define DM_OLD_PASSWORD1						(DM_START + 443)
#define DM_SYS_RUNTIME_L						(DM_START + 444)//系统累计运行时间秒L 32BIT
#define DM_SYS_RUNTIME_H						(DM_START + 445)//系统累计运行时间秒H 32BIT
#define DM_LAR_RUNTIME_L						(DM_START + 446)//激光累计发射时间秒L 32BIT
#define DM_LAR_RUNTIME_H						(DM_START + 447)//激光累计发射时间秒L 32BIT
#define DM_RELEASE_DATA_YEAR					(DM_START + 448)//出厂日期年		
#define DM_RELEASE_DATA_MONTH					(DM_START + 449)//出厂日期月
#define DM_RELEASE_DATA_DAY						(DM_START + 450)//出厂如期日
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
#define Y_OUT3									(Y_START * 16 + 3)//YOUT3
#define Y_OUT4									(Y_START * 16 + 4)//YOUT4
#define Y_OUT5									(Y_START * 16 + 5)//YOUT5
#define Y_OUT6									(Y_START * 16 + 6)//YOUT6
#define Y_OUT7									(Y_START * 16 + 7)//YOUT7
#define Y_FAN0									(Y_START * 16 + 8)//YOUT8 风扇开关0
#define Y_FAN1									(Y_START * 16 + 9)//YOUT9 风扇开关1
#define Y_TEC0									(Y_START * 16 + 10)//YOUT10 制冷开关0
#define Y_TEC1									(Y_START * 16 + 11)//YOUT11 制冷开关1
/*****************************************************************************/
#define R_FIBER_MANUFACT_0						(R_START * 16 + 0)
#define R_FIBER_MANUFACT_1						(R_START * 16 + 1)
#define R_DIODE_TEMP_HIGH_0						(R_START * 16 + 2)
#define R_DIODE_TEMP_HIGH_1						(R_START * 16 + 3)
#define R_DRIVE_TEMP_HIGH						(R_START * 16 + 4)
#define R_ENVI_TEMP_HIGH						(R_START * 16 + 5)
#define R_DRIVE_FAULT_0							(R_START * 16 + 6)
#define R_DRIVE_FAULT_1							(R_START * 16 + 7)
#define R_SAFE_FAULT							(R_START * 16 + 8)//故障
#define R_SCHEME_LOAD_REQ						(R_START * 16 + 9)//方案载入请求
#define R_SHCEME_SAVE_REQ						(R_START * 16 + 10)//方案储存请求
#define R_KEY_READY								(R_START * 16 + 11)//准备

#define R_CHECK_EPROM_DONE						(R_START * 16 + 32)//处理器自检完毕
#define R_CHECK_INTBUS_DONE						(R_START * 16 + 33)//HMI通信自检完毕
#define R_CHECK_LDR_DONE						(R_START * 16 + 34)//激光驱动器自检完毕
#define R_CHECK_TEMPER_DONE						(R_START * 16 + 35)//温度自检完毕
#define R_CHECK_USBHOST_DONE					(R_START * 16 + 36)//USBHOST模块完毕
#define R_CHECK_NFC_DONE						(R_START * 16 + 37)//NFC模块完毕
#define R_CHECK_NRF24L01_DONE					(R_START * 16 + 38)//NRF24L01模块自检完毕
#define R_CHECK_EPROM_PASS						(R_START * 16 + 39)//处理器自检通过
#define R_CHECK_INTBUS_PASS						(R_START * 16 + 40)//HMI通信自检通过
#define R_CHECK_LDR_PASS						(R_START * 16 + 41)//激光驱动器自检通过
#define R_CHECK_TEMPER_PASS						(R_START * 16 + 42)//温度自检通过
#define R_CHECK_USBHOST_PASS					(R_START * 16 + 43)//USBHOST模块通过
#define R_CHECK_NFC_PASS						(R_START * 16 + 44)//NFC模块通过
#define R_CHECK_NRF24L01_PASS					(R_START * 16 + 45)//NRF24L01模块自检通过
#define R_CHECK_EPROM_FAIL						(R_START * 16 + 46)//处理器自检失败
#define R_CHECK_INTBUS_FAIL						(R_START * 16 + 47)//HMI通信自检失败
#define R_CHECK_LDR_FAIL						(R_START * 16 + 48)//激光驱动器自检失败
#define R_CHECK_TEMPER_FAIL						(R_START * 16 + 49)//温度自检失败
#define R_CHECK_USBHOST_FAIL					(R_START * 16 + 50)//USBHOST模块失败
#define R_CHECK_NFC_FAIL						(R_START * 16 + 51)//NFC模块失败
#define R_CHECK_NRF24L01_FAIL					(R_START * 16 + 52)//NRF24L01模块自检失败
/*****************************************************************************/
#define T100MS_READY_BEEM_DELAY					0//进入READY状态后蜂鸣器响延迟
#define T100MS_CHECK_EPROM_DELAY				1
#define T100MS_CHECK_INTBUS_DELAY				2
#define T100MS_CHECK_LDR_DELAY					3
#define T100MS_CHECK_TEMPER_DELAY				4
#define T100MS_CHECK_USBHOST_DELAY				5
#define T100MS_CHECK_NFC_DELAY					6
#define T100MS_CHECK_NRF24L01_DELAY				7

#endif