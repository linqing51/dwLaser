#ifndef __DCHMIRES_H__
#define __DCHMIRES_H__
/*****************************************************************************/
#define HMI_BLACK     										0x0000//黑色    
#define HMI_ NAVY      										0x000F//深蓝色  
#define HMI_DGREEN    										0x03E0//深绿色  
#define HMI_DCYAN     										0x03EF//深青色  
#define HMI_MAROON    										0x7800//深红色      
#define HMI_PURPLE    										0x780F//紫色  
#define HMI_OLIVE     										0x7BE0//橄榄绿      
#define HMI_LGRAY     										0xC618//灰白色
#define HMI_DGRAY     										0x7BEF//深灰色      
#define HMI_BLUE      										0x001F//蓝色    
#define HMI_GREEN     										0x07E0//绿色          
#define HMI_CYAN      										0x07FF//青色  
#define HMI_RED       										0xF800//红色       
#define HMI_MAGENTA   										0xF81F//品红    
#define HMI_YELLOW    										0xFFE0//黄色        
#define HMI_WHITE     										0xFFFF//白色  
/*****************************************************************************/
//HMI页面编号
#define GDDC_PAGE_POWERUP									0
#define GDDC_PAGE_PASSCODE									1
#define GDDC_PAGE_NEW_PASSCODE								2
#define GDDC_PAGE_STANDBY									3
#define GDDC_PAGE_READY										4
#define GDDC_PAGE_OPTION									5//选项页面
#define GDDC_PAGE_SCHEME									6//方案页面
#define GDDC_PAGE_POWER_CORRECTION							7//功率校正
#define GDDC_PAGE_INFORMATION								8//信息页面
#define GDDC_PAGE_DIAGNOSIS									9//诊断页面
/*****************************************************************************/
//GDDC页面控件编号
/*****************************************************************************/
#define GDDC_PAGE_POWERUP_TEXTDISPLAY_CHECK_INFO			1
#define GDDC_PAGE_POWERUP_PROGRESS_CHECK_INFO				2
/*****************************************************************************/
#define GDDC_PAGE_PASSCODE_KEY_NUM1							1
#define GDDC_PAGE_PASSCODE_KEY_NUM2							2
#define GDDC_PAGE_PASSCODE_KEY_NUM3							3
#define GDDC_PAGE_PASSCODE_KEY_NUM4							4
#define GDDC_PAGE_PASSCODE_KEY_NUM5							5
#define GDDC_PAGE_PASSCODE_KEY_NUM6							6
#define GDDC_PAGE_PASSCODE_KEY_NUM7							7
#define GDDC_PAGE_PASSCODE_KEY_NUM8							8
#define GDDC_PAGE_PASSCODE_KEY_NUM9							9
#define GDDC_PAGE_PASSCODE_KEY_NUM0							10
#define GDDC_PAGE_PASSCODE_KEY_CANCEL						11
#define GDDC_PAGE_PASSCODE_KEY_BACKSPACE					12
#define GDDC_PAGE_PASSCODE_KEY_CHANGEPASSCODE				13
#define GDDC_PAGE_PASSCODE_KEY_ENTER						14
#define GDDC_PAGE_PASSCODE_TEXTDISPLAY						15
/*****************************************************************************/
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM1						1
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM2						2
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM3						3
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM4						4
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM5				5
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM6				6
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM7				7
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM8				8
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM9				9
#define GDDC_PAGE_NEWPASSCODE_KEY_NUM0				10
#define GDDC_PAGE_NEWPASSCODE_KEY_CANCEL			11
#define GDDC_PAGE_NEWPASSCODE_KEY_BACKSPACE			12
#define GDDC_PAGE_NEWPASSCODE_KEY_SAVE				13
#define GDDC_PAGE_NEWPASSCODE_KEY_BACK				14
#define GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY					15
/*****************************************************************************/
#define GDDC_PAGE_STANDBY_KEY_POWER_CH0_ADD					1						
#define GDDC_PAGE_STANDBY_KEY_POWER_CH0_DEC			2
#define GDDC_PAGE_STANDBY_KEY_POWER_CH1_ADD			3
#define GDDC_PAGE_STANDBY_KEY_POWER_CH1_DEC			4
#define GDDC_PAGE_STANDBY_KEY_POSWIDTH_ADD			5		
#define GDDC_PAGE_STANDBY_KEY_POSWIDTH_DEC			6
#define GDDC_PAGE_STANDBY_KEY_NEGWIDTH_ADD			7
#define GDDC_PAGE_STANDBY_KEY_NEGWIDTH_DEC			8
#define GDDC_PAGE_STANDBY_KEY_GROUP_ADD				9
#define GDDC_PAGE_STANDBY_KEY_GROUP_DEC				10
#define GDDC_PAGE_STANDBY_KEY_SPACE_ADD				11
#define GDDC_PAGE_STANDBY_KEY_SPACE_DEC				12
#define GDDC_PAGE_STANDBY_KEY_STANDBY				13
#define GDDC_PAGE_STANDBY_KEY_MODE_CW				14
#define	GDDC_PAGE_STANDBY_KEY_MODE_MP				15
#define GDDC_PAGE_STANDBY_KEY_MODE_GP				16
#define GDDC_PAGE_STANDBY_KEY_MODE_EVLA_SEGMENT		17
#define GDDC_PAGE_STANDBY_KEY_MODE_EVLA_SIGNAL		18
#define GDDC_PAGE_STANDBY_KEY_MODE_DERMA			19
#define GDDC_PAGE_STANDBY_KEY_ENTER_OPTION			20
#define GDDC_PAGE_STANDBY_KEY_SCHEME_SAVE			21
#define GDDC_PAGE_STANDBY_KEY_SCHEME_NEXT			22//+
#define GDDC_PAGE_STANDBY_KEY_SCHEME_LAST			23//-
#define GDDC_PAGE_STANDBY_KEY_SELECT_CH0			24
#define GDDC_PAGE_STANDBY_KEY_SELECT_CH1			25
#define GDDC_PAGE_STANDBY_KEY_SELECT_BOTH			26
#define GDDC_PAGE_STANDBY_KEY_RESET					27
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_POSWIDTH		28
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_NEGWIDTH		29
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_GROUP			30
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_SPACE			31
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_NAME			32//方案名称显示
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH0		33//CH0功率显示
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_POWER_CH1		34//CH1功率显示
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_WARN			35//报警显示
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_ENERGY		36
#define GDDC_PAGE_STANDBY_TEXTDISPLAY_TIME			37
#define GDDC_PAGE_STANDBY_PROGRESS_CH0				38
#define GDDC_PAGE_STANDBY_PROGRESS_CH1				39
#define GDDC_PAGE_STANDBY_ICO_WARNING				40
#define GDDC_PAGE_STANDBY_KEY_SCHEME_DEFAULT		99
/*****************************************************************************/
#define GDDC_PAGE_READY_KEY_READY							1
#define GDDC_PAGE_READY_KEY_SELECT_CH0				2
#define GDDC_PAGE_READY_KEY_SELECT_CH1				3
#define GDDC_PAGE_READY_KEY_SELECT_BOTH				4
#define GDDC_PAGE_READY_KEY_MODE_CW					5
#define	GDDC_PAGE_READY_KEY_MODE_MP					6
#define GDDC_PAGE_READY_KEY_MODE_GP					7
#define GDDC_PAGE_READY_KEY_MODE_EVLA_SEGMENT		8
#define GDDC_PAGE_READY_KEY_MODE_EVLA_SIGNAL		9
#define GDDC_PAGE_READY_KEY_MODE_DERMA				10
#define GDDC_PAGE_READY_PROGRESS_CH0				11
#define GDDC_PAGE_READY_PROGRESS_CH1				12
#define GDDC_PAGE_READY_TEXTDISPLAY_POSWIDTH		13
#define GDDC_PAGE_READY_TEXTDISPLAY_NEGWIDTH		14
#define GDDC_PAGE_READY_TEXTDISPLAY_GROUP			15
#define GDDC_PAGE_READY_TEXTDISPLAY_SPACE			16
#define GDDC_PAGE_READY_TEXTDISPLAY_NAME			17//方案名称显示
#define GDDC_PAGE_READY_TEXTDISPLAY_TIME			18
#define GDDC_PAGE_READY_TEXTDISPLAY_ENERGY			19
#define GDDC_PAGE_READY_TEXTDISPLAY_WARN			20
#define GDDC_PAGE_READY_TEXTDISPLAY_POWER_CH0		21
#define GDDC_PAGE_READY_TEXTDISPLAY_POWER_CH1		22
#define GDDC_PAGE_READY_ICO_WARNING					23
/*****************************************************************************/
#define GDDC_PAGE_OPTION_KEY_BEEP					1//蜂鸣器声光同步				
#define GDDC_PAGE_OPTION_KEY_TONE					2//蜂鸣器
#define GDDC_PAGE_OPTION_KEY_AIM_GRREN				3			
#define GDDC_PAGE_OPTION_KEY_AIM_RED				4
#define GDDC_PAGE_OPTION_KEY_AIM_RED_BRG_ADD		5//指示光亮度加
#define GDDC_PAGE_OPTION_KEY_AIM_RED_BRG_DEC		6//指示光亮度减
#define GDDC_PAGE_OPTION_KEY_AIM_GREEN_BRG_ADD		7
#define GDDC_PAGE_OPTION_KEY_AIM_GREEN_BRG_DEC		8
#define GDDC_PAGE_OPTION_KEY_VOLUME_ADD				9//蜂鸣器音量加
#define GDDC_PAGE_OPTION_KEY_VOLUME_DEC				10//蜂鸣器音量减
#define GDDC_PAGE_OPTION_KEY_LCD_ADD				11//液晶屏亮度增加
#define GDDC_PAGE_OPTION_KEY_LCD_DEC				12//液晶屏亮度减少
#define GDDC_PAGE_OPTION_KEY_ENTER_SCHEEM			13//进入方案页面
#define GDDC_PAGE_OPTION_KEY_ENTER_OK				14//返回待机页面
#define GDDC_PAGE_OPTION_KEY_ENTER_INFORMATION		15//
#define GDDC_PAGE_OPTION_PROGRESS_AIM_RED_BRG		16//指示光亮度滑块条
#define GDDC_PAGE_OPTION_PROGRESS_AIM_GREEN_BRG		17//指示光亮度滑块条
#define GDDC_PAGE_OPTION_PROGRESS_VOLUME			18//蜂鸣器音量调节
#define GDDC_PAGE_OPTION_PROGRESS_LCD				19//屏幕亮度调节
#define GDDC_PAGE_OPTION_KEY_LANGUAGE_EN			20
#define GDDC_PAGE_OPTION_KEY_LANGUAGE_CN			21
#define GDDC_PAGE_OPTION_KEY_LANGUAGE_JP						22
#define GDDC_PAGE_OPTION_KEY_LANGUAGE_DE						23
#define GDDC_PAGE_OPTION_KEY_HAND_SWITCH_ON						24
#define GDDC_PAGE_OPTION_KEY_HAND_SWITCH_OFF					25
#define GDDC_PAGE_OPTION_KEY_ENTER_DIAGNOSIS					26
#define GDDC_PAGE_OPTION_KEY_ENTER_CORRECTION					99//进入参数校正菜单
/*****************************************************************************/
//方案页面
#define GDDC_PAGE_SCHEME_KEY_RENAME							1//更名按键
#define GDDC_PAGE_SCHEME_KEY_SAVE_USB				2//将方案信息储存到USB中
#define GDDC_PAGE_SCHEME_KEY_LOAD_USB				3//从USB载入方案信息
#define GDDC_PAGE_SCHEME_KEY_ENTER_STANDBY			4//返回
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_0					5		
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_1					6
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_2		7
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_3		8
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_4		9
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_5		10
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_6		11
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_7		12
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_8		13
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_9		14
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_10		15
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_11		16
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_12		17
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_13		18
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_14		19
#define GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_15		20
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_0		21
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_1		22
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_2		23
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_3		24
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_4		25
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_5		26
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_6		27
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_7		28
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_8		29
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_9		30
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_10		31
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_11		32
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_12		33
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_13		34
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_14		35
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_15		36
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_FULLNAME		37
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_POSWIDTH		38
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_NEGWIDTH		39
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_GROUP			40
#define GDDC_PAGE_SCHEME_TEXTDISPALY_SPACE			41
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_POWER_CH0		42
#define GDDC_PAGE_SCHEME_TEXTDISPLAY_POWER_CH1						43
/*****************************************************************************/
//更名界面
#define GDDC_PAGE_RENAME_OK											1//确定
#define GDDC_PAGE_RENAME_CANCLE										2//取消
/*****************************************************************************/
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_CODE_CH0					3
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_CODE_CH1					4	
#define GDDC_PAGE_CORRECTION_TEXTDISPLAY_POWER0_CH0					5
/*****************************************************************************/
#define GDDC_PAGE_INFORMATION_KEY_ENTER_OK							1
#define GDDC_PAGE_INFORMATION_TEXTDISPLAY_NFC_VER					2
#define GDDC_PAGE_INFORMATION_TEXTDISPLAY_FIBER_CODE				3
/*****************************************************************************/
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_INTERLOCK					1
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_ESTOP						2
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_FOOTSWITCH_NO				3
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_FOOTSWITCH_NC				4
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_LDR_FAULT0				5
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_LDR_FAULT1				6
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_FBD0						7
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_X_FBD1						8
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_LED_POWERON				9
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_LED_EMIT					10
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_LED_ALARM					11
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y3							12
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y4							13
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y5							14
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y6							15
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y7							16
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_FAN0						17
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_FAN1						18
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_TEC0						19
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_Y_TEC1						20
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC0						21
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC1						22
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC2						23
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC3						24
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC4						25
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC5						26
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC6						27
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC7						28
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_ADC8						29
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_DAC0						30
#define GDDC_PAGE_DIAGNOSIS_TEXTDISPLAY_DAC1						31
#endif