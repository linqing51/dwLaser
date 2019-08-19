#include "dcHmiNotifyText.h"
/*! 
*  \brief  �ı��ؼ�֪ͨ
*  \details  ���ı�ͨ�����̸���(�����GetControlValue)ʱ��ִ�д˺���
*  \details  �ı��ؼ����������ַ�����ʽ�·���MCU������ı��ؼ������Ǹ���ֵ��
*  \details  ����Ҫ�ڴ˺����н��·��ַ�������ת�ظ���ֵ��
*  \param screen_id ����ID
*  \param control_id �ؼ�ID
*  \param str �ı��ؼ�����
*/
void NotifyText(uint16_t screen_id, uint16_t control_id, uint8_t *str){
   //TODO: ����û�
	uint16_t tmp;
	switch(screen_id){
		case GDDC_PAGE_RENAME:{
			switch(control_id){
				case GDDC_PAGE_RENAME_TEXTDISPLAY_NEWNAME:{
					tmp = NVRAM0[EM_SCHEME_NUM_TMP];
					if(strlen(str) <= 30){
						strcpy((uint8_t*)(&TMPRAM[tmp * 15]), str);
					}
					else{
						strncpy((uint8_t*)(&TMPRAM[tmp * 15]), str, 30);
					}
					TMPRAM[tmp + 14] &= 0xFF00;
					SetTextValue(GDDC_PAGE_SCHEME, (GDDC_PAGE_SCHEME_TEXTDISPLAY_SCHEME_0 + tmp), (uint8_t*)&TMPRAM[tmp * 15]);
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