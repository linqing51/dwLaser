#ifndef __APPSPLCADR_H__
#define __APPSPLCADR_H__
/*****************************************************************************/
#define EM_LASER_SCHEME_NAME									(EM_START + 0)//方案名称
#define EM_LASER_SELECT												(EM_START + 13)//通道选择
#define EM_LASER_PULSE_MODE										(EM_START + 14)//脉冲模式
#define EM_LASER_POWER_CH0										(EM_START + 15)//通道0功率
#define EM_LASER_POWER_CH1										(EM_START + 16)//通道1功率
#define EM_LASER_POWER_CH2										(EM_START + 17)//通道2功率
#define EM_LASER_POWER_CH3										(EM_START + 18)//通道3功率
#define EM_LASER_SP_POSWIDTH									(EM_START + 19)//单脉冲正脉宽
#define EM_LASER_MP_POSWIDTH									(EM_START + 20)//多脉冲正脉宽
#define EM_LASER_MP_NEGWIDTH									(EM_START + 21)//多脉冲负脉宽
#define EM_LASER_GP_POSWIDTH									(EM_START + 22)//Group脉冲正脉宽
#define EM_LASER_GP_NEGWIDTH									(EM_START + 23)//Group脉冲负脉宽
#define EM_LASER_GP_TIMES											(EM_START + 24)//Group脉冲数
#define EM_LASER_GP_GROUP_OFF									(EM_START + 25)//Group脉冲间隔
#define EM_LASER_SIGNAL_ENERGY_INTERVAL				(EM_START + 26)//SIGNAL能量间隔
#define EM_LASER_DERMA_POSWIDTH								(EM_START + 27)//DERMA正脉宽
#define EM_LASER_DERMA_NEGWIDTH								(EM_START + 28)//DERMA负脉宽
#define EM_LASER_DERMA_SPOT_SIZE							(EM_START + 29)//DERMA光斑直径
#define EM_LASER_AVERAGE_POWER								(EM_START + 30//当面模式平均功率
#define EM_LASER_FREQUENCY										(EM_START + 31)//当前模式频率
#define EM_LASER_DUTY_CYCLE										(EM_START + 32)//当前模式占空比
/*****************************************************************************/
#define EM_DIODE_TEMP0												(EM_START + 40)//二极管温度0
#define EM_DIODE_TEMP1												(EM_START + 41)//二极管温度1
#define EM_DRIVE_TEMP													(EM_START + 42)//驱动器温度
#define EM_ENVI_TEMP													(EM_START + 43)//环境温度
#define EM_DIODE_HIGH_TEMP										(EM_START + 44)//二极管过热阈值
#define EM_DRIVE_HIGH_TEMP										(EM_START + 45)//驱动器过热阈值
#define EM_ENVI_HIGH_TEMP											(EM_START + 46)//环境过热阈值
#define EM_COOL_SET_TEMP											(EM_START + 47)//设定冷却温度
#define EM_COOL_DIFF_TEMP											(EM_START + 48)//设定冷却回差调节
/*****************************************************************************/				
#define EM_TOTAL_POWER												(EM_START + 50)//发射总功率
#define EM_HMI_OPERA_STEP											(EM_START +	51)//操作步骤								
#define EM_ERROR_CODE													(EM_START + 52)//错误码					
#define EM_SCHEME_NUM_TMP											(EM_START + 53)//待确认方案编号			
#define EM_DK25L_VER													(EM_START + 54)//DK25L模块版本
/*****************************************************************************/
#define EM_DC_PAGE														(EM_START + 64)//HMI页面编号 			
#define EM_DC_PASSCODE_INDEX									(EM_START + 65)//密码输入位索引		
#define EM_DC_NEW_PASSCODE0										(EM_START + 66)//输入新密码0			
#define EM_DC_NEW_PASSCODE1										(EM_START + 67)//输入新密码1			
#define EM_DC_NEW_PASSCODE2										(EM_START + 68)//输入新密码0			
#define EM_DC_NEW_PASSCODE3										(EM_START + 69)//输入新密码1			
#define EM_DC_DEFAULT_PASSCODE0								(EM_START + 70)//默认密码0				
#define EM_DC_DEFAULT_PASSCODE1								(EM_START + 71)//默认密码1				
#define EM_DC_DEFAULT_PASSCODE2								(EM_START + 72)//默认密码1	
#define EM_DC_DEFAULT_PASSCODE3								(EM_START + 73)//默认密码1				
#define EM_DC_DISPLAY_RELEASE_TIME						(EM_START + 74)//显示发射时间			
#define EM_DC_DISPLAY_RELEASE_ENERGY					(EM_START + 75)//显示发射能量
/*****************************************************************************/
#define FD_LASER_SCHEME_NAME									(FD_START +  0)//方案名称
#define FD_LASER_SELECT												(FD_START +  13)//通道选择
#define FD_LASER_PULSE_MODE										(FD_START +  14)//脉冲模式
#define FD_LASER_POWER_CH0										(FD_START +  15)//通道0功率
#define FD_LASER_POWER_CH1										(FD_START +  16)//通道1功率
#define FD_LASER_POWER_CH2										(FD_START +  17)//通道2功率
#define FD_LASER_POWER_CH3										(FD_START +  18)//通道3功率
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
#define FD_SCHEME_START_16										(FD_START + 480)//方案16存储区起始
#define FD_SCHEME_END_16										(FD_START + 509)//方案16存储区结束

#define FD_SCHEME_START_17										(FD_START + 510)//方案17存储区起始
#define FD_SCHEME_END_17										(FD_START + 539)//方案17存储区结束

#define FD_SCHEME_START_18										(FD_START + 540)//方案18存储区起始
#define FD_SCHEME_END_18										(FD_START + 569)//方案18存储区结束

#define FD_SCHEME_START_19										(FD_START + 570)//方案19存储区起始
#define FD_SCHEME_END_19										(FD_START + 599)//方案19存储区结束

#define FD_SCHEME_START_20										(FD_START + 600)//方案20存储区起始
#define FD_SCHEME_END_20										(FD_START + 629)//方案20存储区结束

#define FD_SCHEME_START_21										(FD_START + 630)//方案21存储区起始
#define FD_SCHEME_END_21										(FD_START + 659)//方案21存储区结束

#define FD_SCHEME_START_22										(FD_START + 660)//方案22存储区起始
#define FD_SCHEME_END_22										(FD_START + 689)//方案22存储区结束

#define FD_SCHEME_START_23										(FD_START + 690)//方案23存储区起始
#define FD_SCHEME_END_23										(FD_START + 719)//方案23存储区结束

#define FD_SCHEME_START_24										(FD_START + 720)//方案24存储区起始
#define FD_SCHEME_END_24										(FD_START + 749)//方案24存储区结束

#define FD_SCHEME_START_25										(FD_START + 750)//方案25存储区起始
#define FD_SCHEME_END_25										(FD_START + 779)//方案25存储区结束

#define FD_SCHEME_START_26										(FD_START + 780)//方案26存储区起始
#define FD_SCHEME_END_26										(FD_START + 809)//方案26存储区结束

#define FD_SCHEME_START_27										(FD_START + 810)//方案27存储区起始
#define FD_SCHEME_END_27										(FD_START + 839)//方案27存储区结束

#define FD_SCHEME_START_28										(FD_START + 840)//方案28存储区起始
#define FD_SCHEME_END_28										(FD_START + 869)//方案28存储区结束

#define FD_SCHEME_START_29										(FD_START + 870)//方案29存储区起始
#define FD_SCHEME_END_29										(FD_START + 899)//方案29存储区结束

#define FD_SCHEME_START_30										(FD_START + 900)//方案30存储区起始
#define FD_SCHEME_END_30										(FD_START + 929)//方案30存储区结束

#define FD_SCHEME_START_31										(FD_START + 930)//方案31存储区起始
#define FD_SCHEME_END_31										(FD_START + 959)//方案31存储区结束
/*****************************************************************************/
#define TMP_NAME_0												(TMP_START + 0)//临时名称储存区
#define TMP_NAME_1												(TMP_START + 15)//临时名称储存区
#define TMP_NAME_2												(TMP_START + 30)//临时名称储存区
#define TMP_NAME_3												(TMP_START + 45)//临时名称储存区
#define TMP_NAME_4												(TMP_START + 60)//临时名称储存区
#define TMP_NAME_5												(TMP_START + 75)//临时名称储存区
#define TMP_NAME_6												(TMP_START + 90)//临时名称储存区
#define TMP_NAME_7												(TMP_START + 105)//临时名称储存区
#define TMP_NAME_8												(TMP_START + 120)//临时名称储存区
#define TMP_NAME_9												(TMP_START + 135)//临时名称储存区
#define TMP_NAME_10												(TMP_START + 150)//临时名称储存区
#define TMP_NAME_11												(TMP_START + 165)//临时名称储存区
#define TMP_NAME_12												(TMP_START + 180)//临时名称储存区
#define TMP_NAME_13												(TMP_START + 195)//临时名称储存区
#define TMP_NAME_14												(TMP_START + 210)//临时名称储存区
#define TMP_NAME_15												(TMP_START + 225)//临时名称储存区

#define TMP_NAME_16												(TMP_START + 240)//临时名称储存区
#define TMP_NAME_17												(TMP_START + 255)//临时名称储存区
#define TMP_NAME_18												(TMP_START + 270)//临时名称储存区
#define TMP_NAME_19												(TMP_START + 285)//临时名称储存区
#define TMP_NAME_20												(TMP_START + 300)//临时名称储存区
#define TMP_NAME_21												(TMP_START + 315)//临时名称储存区
#define TMP_NAME_22												(TMP_START + 330)//临时名称储存区
#define TMP_NAME_23												(TMP_START + 345)//临时名称储存区
#define TMP_NAME_24												(TMP_START + 360)//临时名称储存区
#define TMP_NAME_25												(TMP_START + 375)//临时名称储存区
#define TMP_NAME_26												(TMP_START + 390)//临时名称储存区
#define TMP_NAME_27												(TMP_START + 405)//临时名称储存区
#define TMP_NAME_28												(TMP_START + 420)//临时名称储存区
#define TMP_NAME_29												(TMP_START + 435)//临时名称储存区
#define TMP_NAME_30												(TMP_START + 450)//临时名称储存区
#define TMP_NAME_31												(TMP_START + 465)//临时名称储存区
/*****************************************************************************/
#define DM_SCHEME_NUM											(DM_START + 0)//选择的方案编号 低8位方案号 高8位方案使能
#define DM_BEEM_VOLUME											(DM_START + 1)//蜂鸣器音量
#define DM_AIM_BRG												(DM_START + 2)//指示激光亮度
#define DM_LCD_BRG												(DM_START + 3)//屏幕亮度
#define DM_DC_OLD_PASSCODE0										(DM_START + 4)//屏旧密码0-1
#define DM_DC_OLD_PASSCODE1										(DM_START + 5)//屏旧密码2-3
#define DM_DC_OLD_PASSCODE2										(DM_START + 6)//屏旧密码0-1
#define DM_DC_OLD_PASSCODE3										(DM_START + 7)//屏旧密码2-3
/*****************************************************************************/

#define X_FOOTSWITCH_NC											(X_START * 16 + 1)//XIN0 脚踏常闭
#define X_ESTOP													(X_START * 16 + 0)//XIN1 紧急停止开关
#define X_FOOTSWITCH_NO											(X_START * 16 + 2)//XIN2 脚踏常开
#define X_INTERLOCK												(X_START * 16 + 3)//XIN0 安全连锁

#define X_FIBER_PROBE											(X_START * 16 + 7)//XIN6 光纤探测0
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
#define R_FOOTSWITCH_NC											(R_START * 16 + 0)//
#define R_ESTOP													(R_START * 16 + 1)//
#define R_INTERLOCK												(R_START * 16 + 2)//
#define R_FIBER_PROBE											(R_START * 16 + 3)//
#define R_RFID_PASS												(R_START * 16 + 4)
#define R_DIODE_TEMP_HIGH										(R_START * 16 + 5)//通道0二极管高温标志
#define R_DIODE_TEMP_LOW										(R_START * 16 + 6)//通道0二极管高温标志
#define R_DRIVE_TEMP_HIGH										(R_START * 16 + 7)//驱动器高温标志
#define R_DRIVE_TEMP_LOW										(R_START * 16 + 8)//通道0二极管高温标志
#define R_ENVI_TEMP_HIGH										(R_START * 16 + 9)//环境温度标度
#define R_ENVI_TEMP_LOW											(R_START * 16 + 10)//通道0二极管高温标志
#define R_FAULT													(R_START * 16 + 11)//故障标志
#define R_FAN_ENABLE											(R_START * 16 + 12)//风扇使能
#define R_DISABLE_RFID											(R_START * 16 + 13)//屏蔽NFC检测
#define R_DISABLE_FIBER_PROBE									(R_START * 16 + 14)//屏蔽光纤探测
#define R_DISABLE_FAN_SPEED										(R_START * 16 + 15)//屏蔽风扇控制
#define R_CLEAR_EPROM											(R_START * 16 + 16)//完全清空EPROM
#define R_ENGINEER_MODE											(R_START * 16 + 17)//工程师模式
//HMI相关状态
#define R_DCHMI_RESET_REQ										(R_START * 16 + 20)//HMI复位请求
#define R_DCHMI_RESET_DOING										(R_START * 16 + 21)//HMI复位中
#define R_DCHMI_RESET_DONE										(R_START * 16 + 22)//HMI复位完成	
#define R_DCHMI_UPDATEUI_REQ									(R_START * 16 + 23)//HMI内容更新请求
#define R_DCHMI_UPDATEUI_DOING									(R_START * 16 + 24)//HMI内容更新中
#define R_DCHMI_UPDATEUI_DONE									(R_START * 16 + 25)//HMI内容更新请求完成
#define R_DCHMI_RESTORE_REQ										(R_START * 16 + 26)//HMI从FLASH中恢复设置请求
#define R_DCHMI_RESTORE_DOING									(R_START * 16 + 27)//HMI从FLASH中恢复中
#define R_DCHMI_RESTORE_DONE									(R_START * 16 + 28)//HMI从FLASH中恢复设置完成	
#define R_DCHMI_DISPLAY_WARN									(R_START * 16 + 30)//HMI显示报警信息
#define R_DCHMI_KEY_STANDBY_ENABLE								(R_START * 16 + 40)//STANDBY 使能
/*****************************************************************************/
#define R_STANDBY_KEY_POSWIDTH_ADD_DOWN							(R_START * 16 + 80)
#define R_STANDBY_KEY_POSWIDTH_DEC_DOWN							(R_START * 16 + 81)
#define R_STANDBY_KEY_NEGWIDTH_ADD_DOWN							(R_START * 16 + 82)
#define R_STANDBY_KEY_NEGWIDTH_DEC_DOWN							(R_START * 16 + 83)
#define R_STANDBY_KEY_TIMES_ADD_DOWN							(R_START * 16 + 84)
#define R_STANDBY_KEY_TIMES_DEC_DOWN							(R_START * 16 + 85)
#define R_STANDBY_KEY_GROUP_OFF_ADD_DOWN						(R_START * 16 + 86)
#define R_STANDBY_KEY_GROUP_OFF_DEC_DOWN						(R_START * 16 + 87)
#define R_STANDBY_KEY_ENERGY_INTERVAL_ADD_DOWN					(R_START * 16 + 88)
#define R_STANDBY_KEY_ENERGY_INTERVAL_DEC_DOWN					(R_START * 16 + 89)
#define R_STANDBY_KEY_STNADBY_DOWN								(R_START * 16 + 90)
#define R_STANDBY_KEY_STNADBY_UP								(R_START * 16 + 91)
#define R_STANDBY_KEY_ENTER_OPTION_DOWN							(R_START * 16 + 92)
#define R_STANDBY_KEY_ENTER_SCHEME_DOWN							(R_START * 16 + 93)
#define R_STANDBY_KEY_SCHEME_SAVE_DOWN							(R_START * 16 + 94)
/*****************************************************************************/
#define R_OPTION_KEY_ENTER_CORRECTION_DOWN						(R_START * 16 + 100)
#define R_OPTION_KEY_ENTER_INFORMATION_DOWN						(R_START * 16 + 101)
#define R_OPTION_KEY_ENTER_OK_DOWN								(R_START * 16 + 102)
#define R_OPTION_KEY_ENTER_DIAGNOSIS_DOWN						(R_START * 16 + 103)
/*****************************************************************************/
#define R_INFORMATION_KEY_OK_DOWN								(R_START * 16 + 110)
#define R_INFORMATION_KEY_OK_UP									(R_START * 16 + 111)
/*****************************************************************************/
#define R_SCHEME_KEY_RENAME_DOWN								(R_START * 16 + 120)
#define R_SCHEME_KEY_OK_DOWN									(R_START * 16 + 121)
#define R_SCHEME_KEY_CANCEL_DOWN								(R_START * 16 + 122)
#define R_SCHEME_KEY_SCHEME_SELECT_0_DOWN						(R_START * 16 + 123)		
#define R_SCHEME_KEY_SCHEME_SELECT_1_DOWN						(R_START * 16 + 124)
#define R_SCHEME_KEY_SCHEME_SELECT_2_DOWN						(R_START * 16 + 125)
#define R_SCHEME_KEY_SCHEME_SELECT_3_DOWN						(R_START * 16 + 126)
#define R_SCHEME_KEY_SCHEME_SELECT_4_DOWN						(R_START * 16 + 127)
#define R_SCHEME_KEY_SCHEME_SELECT_5_DOWN						(R_START * 16 + 128)
#define R_SCHEME_KEY_SCHEME_SELECT_6_DOWN						(R_START * 16 + 129)
#define R_SCHEME_KEY_SCHEME_SELECT_7_DOWN						(R_START * 16 + 130)
#define R_SCHEME_KEY_SCHEME_SELECT_8_DOWN						(R_START * 16 + 131)
#define R_SCHEME_KEY_SCHEME_SELECT_9_DOWN						(R_START * 16 + 132)
#define R_SCHEME_KEY_SCHEME_SELECT_10_DOWN						(R_START * 16 + 133)
#define R_SCHEME_KEY_SCHEME_SELECT_11_DOWN						(R_START * 16 + 134)
#define R_SCHEME_KEY_SCHEME_SELECT_12_DOWN						(R_START * 16 + 135)
#define R_SCHEME_KEY_SCHEME_SELECT_13_DOWN						(R_START * 16 + 136)
#define R_SCHEME_KEY_SCHEME_SELECT_14_DOWN						(R_START * 16 + 137)
#define R_SCHEME_KEY_SCHEME_SELECT_15_DOWN						(R_START * 16 + 138)
#define R_SCHEME_KEY_NEXT_SCHEME								(R_START * 16 + 139)
#define R_SCHEME_KEY_LAST_SCHEME								(R_START * 16 + 140)
/*****************************************************************************/
#define R_DIAGNOSIS_OK_DOWN										(R_START * 16 + 160)
#define R_DIAGNOSIS_OK_UP										(R_START * 16 + 161)
/*****************************************************************************/
#define R_RENAME_KEY_ENTER_DOWN									(R_START * 16 + 170)
#define R_RENAME_KEY_EXIT_DOWN									(R_START * 16 + 171)
#define R_RENAME_TEXTDISPLAY_READ_DONE							(R_START * 16 + 172)
/*****************************************************************************/
#define MR_FOOSWITCH_HAND_SWITCH								(MR_START * 16 + 10)//脚踏HandSwitch 脉冲控制
#define MR_BEEM_TONE											(MR_START * 16 + 11)//蜂鸣器模式
/*****************************************************************************/
#define T100MS_HMI_POWERUP_DELAY								0//HMI启动复位延时
#define T100MS_ENTER_PASSCODE_DELAY								1
#define T100MS_READY_BEEM_DELAY									2//进入READY状态后蜂鸣器响延迟
#define T100MS_PULSE_BEEM_DELAY									3//脉冲模式蜂鸣器延迟
/*****************************************************************************/
#define T10MS_POSWIDTH_ADD_KEYDOWN_DELAY						3
#define T10MS_POSWIDTH_DEC_KEYDOWN_DELAY						4
#define T10MS_NEGWIDTH_ADD_KEYDOWN_DELAY						5
#define T10MS_NEGWIDTH_DEC_KEYDOWN_DELAY						6
#define T10MS_TIMES_ADD_KEYDOWN_DELAY							7
#define T10MS_TIMES_DEC_KEYDOWN_DELAY							8
#define T10MS_GROUP_OFF_ADD_KEYDOWN_DELAY						9
#define T10MS_GROUP_OFF_DEC_KEYDOWN_DELAY						10
#endif