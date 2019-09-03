#ifndef __DCHMIRES_H__
#define __DCHMIRES_H__
/*****************************************************************************/
#define HMI_BLACK     													0x0000//黑色    
#define HMI_ NAVY      													0x000F//深蓝色  
#define HMI_DGREEN    													0x03E0//深绿色  
#define HMI_DCYAN     													0x03EF//深青色  
#define HMI_MAROON    													0x7800//深红色      
#define HMI_PURPLE    													0x780F//紫色  
#define HMI_OLIVE     													0x7BE0//橄榄绿      
#define HMI_LGRAY     													0xC618//灰白色
#define HMI_DGRAY     													0x7BEF//深灰色      
#define HMI_BLUE      													0x001F//蓝色    
#define HMI_GREEN     													0x07E0//绿色          
#define HMI_CYAN      													0x07FF//青色  
#define HMI_RED       													0xF800//红色       
#define HMI_MAGENTA   													0xF81F//品红    
#define HMI_YELLOW    													0xFFE0//黄色        
#define HMI_WHITE     													0xFFFF//白色  
/*****************************************************************************/
//HMI页面编号
#define GDDC_PAGE_POWERUP												0
#define GDDC_PAGE_PASSCODE												1
#define GDDC_PAGE_NEW_PASSCODE											2
#define GDDC_PAGE_STANDBY_CW											3
#define GDDC_PAGE_STANDBY_SP											4
#define GDDC_PAGE_STANDBY_MP											5
#define GDDC_PAGE_STANDBY_GP											6
#define GDDC_PAGE_STANDBY_DERMA											7
#define GDDC_PAGE_STANDBY_SIGNAL										8
#define GDDC_PAGE_OPTION												9//选项页面
#define GDDC_PAGE_SCHEME_0												10//方案页面第一页
#define GDDC_PAGE_SCHEME_1												11//方案页面第二页
#define GDDC_PAGE_INFORMATION											12//信息页面
#define GDDC_PAGE_DIAGNOSIS												13//诊断页面
#define GDDC_PAGE_RENAME												14//SCHEME更名
/*****************************************************************************/
//GDDC页面控件编号
/*****************************************************************************/
#define GDDC_PAGE_POWERUP_TEXTDISPLAY_CHECK_INFO						1
#define GDDC_PAGE_POWERUP_PROGRESS_CHECK_INFO							2
/*****************************************************************************/
#define GDDC_PAGE_PASSCODE_KEY_NUM1										1
#define GDDC_PAGE_PASSCODE_KEY_NUM2										2
#define GDDC_PAGE_PASSCODE_KEY_NUM3										3
#define GDDC_PAGE_PASSCODE_KEY_NUM4										4
#define GDDC_PAGE_PASSCODE_KEY_NUM5										5
#define GDDC_PAGE_PASSCODE_KEY_NUM6										6
#define GDDC_PAGE_PASSCODE_KEY_NUM7										7
#define GDDC_PAGE_PASSCODE_KEY_NUM8										8
#define GDDC_PAGE_PASSCODE_KEY_NUM9										9
#define GDDC_PAGE_PASSCODE_KEY_NUM0										10
#define GDDC_PAGE_PASSCODE_KEY_CANCEL									11
#define GDDC_PAGE_PASSCODE_KEY_BACKSPACE								12
#define GDDC_PAGE_PASSCODE_KEY_CHANGEPASSCODE							13
#define GDDC_PAGE_PASSCODE_KEY_ENTER									14
#define GDDC_PAGE_PASSCODE_TEXTDISPLAY									15
/*****************************************************************************/
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM1									1
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM2									2
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM3									3
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM4									4
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM5									5
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM6									6
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM7									7
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM8									8
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM9									9
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM0									10
#define GDDC_PAGE_NEWPASSCODE_KEY_CANCEL								11
#define GDDC_PAGE_NEWPASSCODE_KEY_BACKSPACE								12
#define GDDC_PAGE_NEWPASSCODE_KEY_SAVE									13
#define GDDC_PAGE_NEWPASSCODE_KEY_BACK									14
#define GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY								15
/*****************************************************************************/
#define GDDC_PAGE_STANDBY_KEY_POWER_CH0_ADD								1//
#define GDDC_PAGE_STANDBY_KEY_POWER_CH0_DEC								2//
#if CONFIG_USING_DUAL_WAVE == 1
#define GDDC_PAGE_STANDBY_KEY_POWER_CH1_ADD								3//
#define GDDC_PAGE_STANDBY_KEY_POWER_CH1_DEC								4//
#endif
#define GDDC_PAGE_STANDBY_KEY_STANDBY									5//
#define GDDC_PAGE_STANDBY_KEY_MODE_CW									6//
#define	GDDC_PAGE_STANDBY_KEY_MODE_MP									7//
#define GDDC_PAGE_STANDBY_KEY_MODE_GP									8//
#define GDDC_PAGE_STANDBY_KEY_MODE_SP									9//
#define GDDC_PAGE_STANDBY_KEY_MODE_SIGNAL								10//
#define GDDC_PAGE_STANDBY_KEY_MODE_DERMA								11//
#define GDDC_PAGE_STANDBY_KEY_ENTER_OPTION								12//
#define GDDC_PAGE_STANDBY_KEY_ENTER_SCHEME								13//
#define GDDC_PAGE_STANDBY_KEY_SCHEME_SAVE								14//
#define GDDC_PAGE_STANDBY_KEY_SCHEME_NEXT								15//+
#define GDDC_PAGE_STANDBY_KEY_SCHEME_LAST								16//-
#if CONFIG_USING_DUAL_WAVE == 1
#define GDDC_PAGE_STANDBY_KEY_SELECT_CH0								17//
#define GDDC_PAGE_STANDBY_KEY_SELECT_CH1								18//
#define GDDC_PAGE_STANDBY_KEY_SELECT_BOTH								19//
#endif
#define GDDC_PAGE_STANDBY_KEY_RESET										20//
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_NAME								21//方案名称显示
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH0							22//CH0功率显示
#if CONFIG_USING_DUAL_WAVE == 1
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH1							23//CH1功率显示
#endif
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_WARN								24//报警显示
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_ENERGY							25//
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_RELEASE_TIME						26//
#if CONFIG_USING_DUAL_WAVE == 1
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_TOTAL_POWER						27//
#endif
#define GDDC_PAGE_STANDBY_PROGRESS_CH0									28//
#if CONFIG_USING_DUAL_WAVE == 1
#define GDDC_PAGE_STANDBY_PROGRESS_CH1									29//
#endif
/*****************************************************************************/
#define GDDC_PAGE_STANDBY_SP_KEY_POSWIDTH_ADD							30		
#define GDDC_PAGE_STANDBY_SP_KEY_POSWIDTH_DEC							31
#define GDDC_PAGE_STANDBY_SP_TEXTDISPLAY_POSWIDTH						32
/*****************************************************************************/
#define GDDC_PAGE_STANDBY_MP_KEY_POSWIDTH_ADD							30		
#define GDDC_PAGE_STANDBY_MP_KEY_POSWIDTH_DEC							31
#define GDDC_PAGE_STANDBY_MP_TEXTDISPLAY_POSWIDTH						32
#define GDDC_PAGE_STANDBY_MP_KEY_NEGWIDTH_ADD							33
#define GDDC_PAGE_STANDBY_MP_KEY_NEGWIDTH_DEC							34
#define GDDC_PAGE_STANDBY_MP_TEXTDISPLAY_NEGWIDTH						35
/*****************************************************************************/
#define GDDC_PAGE_STANDBY_GP_KEY_POSWIDTH_ADD							30		
#define GDDC_PAGE_STANDBY_GP_KEY_POSWIDTH_DEC							31
#define GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_POSWIDTH						32
#define GDDC_PAGE_STANDBY_GP_KEY_NEGWIDTH_ADD							33
#define GDDC_PAGE_STANDBY_GP_KEY_NEGWIDTH_DEC							34
#define GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_NEGWIDTH						35
#define GDDC_PAGE_STANDBY_GP_KEY_TIMES_ADD								36
#define GDDC_PAGE_STANDBY_GP_KEY_TIMES_DEC								37
#define GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_TIMES							38
#define GDDC_PAGE_STANDBY_GP_KEY_GROUP_OFF_ADD							39
#define GDDC_PAGE_STANDBY_GP_KEY_GROUP_OFF_DEC							40
#define GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_GROUP_OFF						41
/*****************************************************************************/
#define GDDC_PAGE_STANDBY_SIGNAL_KEY_ENERGY_INTERVAL_ADD				30	
#define GDDC_PAGE_STANDBY_SIGNAL_KEY_ENERGY_INTERVAL_DEC				31
#define GDDC_PAGE_STANDBY_SIGNAL_TEXTDISPLAY_ENERGY_INTERVAL			32//能量间隔
/*****************************************************************************/
#define GDDC_PAGE_STANDBY_DERMA_KEY_POSWIDTH_ADD						30			
#define GDDC_PAGE_STANDBY_DERMA_KEY_POSWIDTH_DEC						31
#define GDDC_PAGE_STANDBY_DERMA_TEXTDISPLAY_POSWIDTH					32
#define GDDC_PAGE_STANDBY_DERMA_KEY_NEGWIDTH_ADD						33
#define GDDC_PAGE_STANDBY_DERMA_KEY_NEGWIDTH_DEC						34	
#define GDDC_PAGE_STANDBY_DERMA_TEXTDISPLAY_NEGWIDTH					35
#define GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_0MM5							36
#define GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_1MM0							37	
#define GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_2MM0							38
#define GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_3MM0							39
#define GDDC_PAGE_STANDBY_DERMA_TEXTDISPLAY_ENERGY_DENSITY				40
/*****************************************************************************/
#define GDDC_PAGE_OPTION_KEY_TONE										1//蜂鸣器声光同步				
#define GDDC_PAGE_OPTION_KEY_AIM_BRG_ADD								2//指示光亮度加
#define GDDC_PAGE_OPTION_KEY_AIM_BRG_DEC								3//指示光亮度减
#define GDDC_PAGE_OPTION_KEY_BEEM_VOLUME_ADD							4//蜂鸣器音量加
#define GDDC_PAGE_OPTION_KEY_BEEM_VOLUME_DEC							5//蜂鸣器音量减
#define GDDC_PAGE_OPTION_KEY_LCD_BRG_ADD								6//液晶屏亮度增加
#define GDDC_PAGE_OPTION_KEY_LCD_BRG_DEC								7//液晶屏亮度减少
#define GDDC_PAGE_OPTION_KEY_ENTER_OK									8//返回待机页面
#define GDDC_PAGE_OPTION_KEY_ENTER_INFORMATION							9//
#define GDDC_PAGE_OPTION_KEY_HAND_SWITCH_ON								10
#define GDDC_PAGE_OPTION_KEY_ENTER_ENGINEER								11//进入工程师模式
#define GDDC_PAGE_OPTION_KEY_ENTER_CORRECTION							12//进入参数校正菜单
#define GDDC_PAGE_OPTION_PROGRESS_AIM_BRG								13//指示光亮度滑块条
#define GDDC_PAGE_OPTION_PROGRESS_BEEM_VOLUME							14//蜂鸣器音量调节
#define GDDC_PAGE_OPTION_PROGRESS_LCD_BRG								15//屏幕亮度调节
#define GDDC_PAGE_OPTION_TEXTDISPLAY_BEEM_VOLUME						16
#define GDDC_PAGE_OPTION_TEXTDISPLAY_LCD_BRG							17
#define GDDC_PAGE_OPTION_TEXTDISPLAY_AIM_BRG							18
#define GDDC_PAGE_OPTION_KEY_RESTORE									19//恢复默认设置
/*****************************************************************************/
//方案页面第一页
#define GDDC_PAGE_SCHEME_KEY_RENAME										1//更名按键
#define GDDC_PAGE_SCHEME_KEY_OK											2//确定
#define GDDC_PAGE_SCHEME_KEY_CANCEL										3//取消
#define GDDC_PAGE_SCHEME_KEY_SELECT_0									4	
#define GDDC_PAGE_SCHEME_KEY_SELECT_1									5
#define GDDC_PAGE_SCHEME_KEY_SELECT_2									6
#define GDDC_PAGE_SCHEME_KEY_SELECT_3									7
#define GDDC_PAGE_SCHEME_KEY_SELECT_4									8
#define GDDC_PAGE_SCHEME_KEY_SELECT_5									9
#define GDDC_PAGE_SCHEME_KEY_SELECT_6									10
#define GDDC_PAGE_SCHEME_KEY_SELECT_7									11
#define GDDC_PAGE_SCHEME_KEY_SELECT_8									12
#define GDDC_PAGE_SCHEME_KEY_SELECT_9									13
#define GDDC_PAGE_SCHEME_KEY_SELECT_10									14
#define GDDC_PAGE_SCHEME_KEY_SELECT_11									15
#define GDDC_PAGE_SCHEME_KEY_SELECT_12									16
#define GDDC_PAGE_SCHEME_KEY_SELECT_13									17
#define GDDC_PAGE_SCHEME_KEY_SELECT_14									18
#define GDDC_PAGE_SCHEME_KEY_SELECT_15									19
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_0							20
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_1							21
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_2							22
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_3							23
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_4							24
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_5							25
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_6							26
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_7							27
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_8							28
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_9							29
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_10							30
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_11							31
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_12							32
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_13							33
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_14							34
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_15							35
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_DETAIL0							36
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_DETAIL1							37
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_DETAIL2							38
#define GDDC_PAGE_SCHEME_KEY_LAST_PAGE									39
#define GDDC_PAGE_SCHEME_KEY_NEXT_PAGE									40
/*****************************************************************************/
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_CODE_CH0						1
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_CODE_CH1						2	
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER0_CH0						3
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER1_CH0						4
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER2_CH0						5
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER3_CH0						6
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER4_CH0						7
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER5_CH0						8
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER6_CH0						9
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER7_CH0						10
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER8_CH0						11
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER9_CH0						12
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER10_CH0					13
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER11_CH0					14
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER12_CH0					15
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER13_CH0					16
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER14_CH0					17
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER15_CH0					18
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER16_CH0					19
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER17_CH0					20
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER18_CH0					21
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER19_CH0					22
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER20_CH0					23

#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER0_CH1						24
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER1_CH1						25
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER2_CH1						26
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER3_CH1						27
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER4_CH1						28
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER5_CH1						29
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER6_CH1						30
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER7_CH1						31
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER8_CH1						32
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER9_CH1						33
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER10_CH1					34
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER11_CH1					35
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER12_CH1					36
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER13_CH1					37
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER14_CH1					38
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER15_CH1					39
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER16_CH1					40
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER17_CH1					41
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER18_CH1					42
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER19_CH1					43
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER20_CH1					44
/*****************************************************************************/
#define GDDC_PAGE_INFORMATION_KEY_ENTER_OK								1
#define GDDC_PAGE_INFORMATION_TEXTDISPLAY_TPYE							2
#define GDDC_PAGE_INFORMATION_TEXTDISPLAY_SN							3
#define GDDC_PAGE_INFORMATION_TEXTDISPLAY_LASER_WAVELENGTH				4
#define GDDC_PAGE_INFORMATION_TEXTDISPLAY_MAX_LASER_POWER				5
#define GDDC_PAGE_INFORMATION_TEXTDISPLAY_VERSION						6
#define GDDC_PAGE_INFORMATION_TEXTDISPLAY_MANUFACTURE_DATE				7
/*****************************************************************************/
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_INFO					1
//#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_INTERLOCK				1
//#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_ESTOP					2
//#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_FOOTSWITCH_NO			3
//#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_FOOTSWITCH_NC			4
//#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_FIBER_PROBE				7
//#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_FAN					17
//#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_TEC					20
//#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_LASER_TEMPER			21
//#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_CHIP_TEMPER				22
//#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_NFCVER					8
//#define GDDC_PAGE_DIAGNOIS_
#define GDDC_PAGE_DISGNOSIS_KEY_DISABLE_RFID					53//屏蔽RFID
#define GDDC_PAGE_DISGNOSIS_KEY_DISABLE_FIBER_PROBE				54//屏蔽光纤探测
#define GDDC_PAGE_DISGNOSIS_KEY_DISABLE_FAN_CONTRAL				55//屏蔽风扇控制
#define GDDC_PAGE_DISGNOSIS_KEY_CLEAR_EPROM						56//EPROM恢复默认值
#define GDDC_PAGE_DIAGNOSIS_KEY_ENTER_OK						99
/*****************************************************************************/
#define GDDC_PAGE_RENAME_TEXTDISPLAY_NEWNAME					1
#define GDDC_PAGE_RENAME_KEY_ENTER								2
#define GDDC_PAGE_RENAME_KEY_EXIT								3
#define GDDC_PAGE_RENAME_KEY_1									70
#define GDDC_PAGE_RENAME_KEY_2									4
#define GDDC_PAGE_RENAME_KEY_3									5
#define GDDC_PAGE_RENAME_KEY_4									6
#define GDDC_PAGE_RENAME_KEY_5									7
#define GDDC_PAGE_RENAME_KEY_6									8
#define GDDC_PAGE_RENAME_KEY_7									9
#define GDDC_PAGE_RENAME_KEY_8									10
#define GDDC_PAGE_RENAME_KEY_9									11
#define GDDC_PAGE_RENAME_KEY_0									12
#define GDDC_PAGE_RENAME_KEY_Q									26
#define GDDC_PAGE_RENAME_KEY_W									27	
#define GDDC_PAGE_RENAME_KEY_E									28
#define GDDC_PAGE_RENAME_KEY_R									29
#define GDDC_PAGE_RENAME_KEY_T									30
#define GDDC_PAGE_RENAME_KEY_Y									31
#define GDDC_PAGE_RENAME_KEY_U									32
#define GDDC_PAGE_RENAME_KEY_I									33
#define GDDC_PAGE_RENAME_KEY_O									34
#define GDDC_PAGE_RENAME_KEY_P									15
#define GDDC_PAGE_RENAME_KEY_A									16
#define GDDC_PAGE_RENAME_KEY_S									17
#define GDDC_PAGE_RENAME_KEY_D									18
#define GDDC_PAGE_RENAME_KEY_F									19
#define GDDC_PAGE_RENAME_KEY_G									20
#define GDDC_PAGE_RENAME_KEY_H									21
#define GDDC_PAGE_RENAME_KEY_J									22
#define GDDC_PAGE_RENAME_KEY_K									23
#define GDDC_PAGE_RENAME_KEY_L									24
#define GDDC_PAGE_RENAME_KEY_ADDDEC								25
#define GDDC_PAGE_RENAME_KEY_SHIFT								35
#define GDDC_PAGE_RENAME_KEY_Z									36
#define GDDC_PAGE_RENAME_KEY_X									37
#define GDDC_PAGE_RENAME_KEY_C									38
#define GDDC_PAGE_RENAME_KEY_V									39
#define GDDC_PAGE_RENAME_KEY_SPACE								40
#define GDDC_PAGE_RENAME_KEY_B									41
#define GDDC_PAGE_RENAME_KEY_N									42
#define GDDC_PAGE_RENAME_KEY_M									43
#define GDDC_PAGE_RENAME_KEY_DOT								44
/*****************************************************************************/
#endif