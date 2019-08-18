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
	switch(screen_id){
		case GDDC_PAGE_SCHEME_RENAME:{
			switch(control_id){
				case GDDC_PAGE_SCHEME_RENAME_TEXTDISPLAY_NEWNAME:{
					//��str���Ƶ�scheme
					if(strlen(str) <= 30){
						strcpy((uint8_t*)(&NVRAM0[EM_LASER_SCHEME_NAME]), str);
					}
					else{
						strncpy((uint8_t*)(&NVRAM0[EM_LASER_SCHEME_NAME]), str, 30);
					}
					SetTextValue(GDDC_PAGE_SCHEME_RENAME, GDDC_PAGE_SCHEME_RENAME_TEXTDISPLAY_NEWNAME, "");
					
					//NVRAM0[EM_SCHEME_NUM_TMP]
					//saveScheme();
					//���·���������ʾ
					//updateSchemeDisplay();
					//�رռ���
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