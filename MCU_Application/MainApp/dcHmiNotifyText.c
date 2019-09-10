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
	data uint16_t tmp;
	switch(screen_id){
		case GDDC_PAGE_RENAME:{
			switch(control_id){
				case GDDC_PAGE_RENAME_TEXTDISPLAY_NEWNAME:{
					tmp = NVRAM0[EM_SCHEME_NUM_TMP];
					if(strlen(str) <= CONFIG_SCHEME_NAME_SIZE){
						strcpy((uint8_t*)(FDRAM + (tmp * 30)), str);
						if(tmp < 16){
							SetTextValue(GDDC_PAGE_SCHEME_0, (GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_0 + tmp), str);
						}
						else{
							SetTextValue(GDDC_PAGE_SCHEME_1, (GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_0 + tmp - 16), str);
						}
					}
					SET(R_RENAME_TEXTDISPLAY_READ_DONE);
					break;
				}
				default:break;
			}
			break;
		}
		default:break;
	}
}   