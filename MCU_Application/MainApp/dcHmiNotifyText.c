#include "dcHmiNotifyText.h"
/*! 
*  \brief  文本控件通知
*  \details  当文本通过键盘更新(或调用GetControlValue)时，执行此函数
*  \details  文本控件的内容以字符串形式下发到MCU，如果文本控件内容是浮点值，
*  \details  则需要在此函数中将下发字符串重新转回浮点值。
*  \param screen_id 画面ID
*  \param control_id 控件ID
*  \param str 文本控件内容
*/
void NotifyText(uint16_t screen_id, uint16_t control_id, uint8_t *str){
   //TODO: 添加用户
	switch(screen_id){
		case GDDC_PAGE_SCHEME_RENAME:{
			switch(control_id){
				case GDDC_PAGE_SCHEME_RENAME_TEXTDISPLAY_NEWNAME:{
					//将str复制到scheme
					if(strlen(str) <= 30){
						strcpy((uint8_t*)(&NVRAM0[EM_LASER_SCHEME_NAME]), str);
					}
					else{
						strncpy((uint8_t*)(&NVRAM0[EM_LASER_SCHEME_NAME]), str, 30);
					}
					SetTextValue(GDDC_PAGE_SCHEME_RENAME, GDDC_PAGE_SCHEME_RENAME_TEXTDISPLAY_NEWNAME, "");
					
					//NVRAM0[EM_SCHEME_NUM_TMP]
					//saveScheme();
					//更新方案名称显示
					//updateSchemeDisplay();
					//关闭键盘
					SetScreen(NVRAM0[EM_DC_PAGE]);
				
					break;
				}
				default:break;
			}
			break;
		}
		default:break;
	}
}   