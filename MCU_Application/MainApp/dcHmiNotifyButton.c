#include "dcHmiNotifyButton.h"
//按钮控件通知当按钮状态改变(或调用GetControlValue)时，执行此函数
//screen_id 画面ID;control_id 控件ID;state 按钮状态：0弹起，1按下
void NotifyButton(uint16_t screen_id, uint16_t control_id, uint8_t state){ 
	//PASSCODE 密码输入页面
	switch(screen_id){
		case GDDC_PAGE_PASSCODE_0:{//等待密码输入
			switch(control_id){
				case GDDC_PAGE_PASSCODE_KEY_NUM1:{//按键1
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3100;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0031;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3100;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0031;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;
					}
					SetTextValue(screen_id, 15, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_PASSCODE_KEY_NUM2:{//按键2
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3200;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0032;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3200;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0032;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;
					}
					SetTextValue(screen_id, 15, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_PASSCODE_KEY_NUM3:{//按键3
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3300;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0033;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3300;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0033;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;	
					}
					SetTextValue(screen_id, 15, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));					
					break;
				}
				case GDDC_PAGE_PASSCODE_KEY_NUM4:{//按键4
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3400;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0034;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3400;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0034;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;	
					}
					SetTextValue(screen_id, 15 , (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));	
					break;
				}
				case GDDC_PAGE_PASSCODE_KEY_NUM5:{//按键5
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3500;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0035;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3500;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0035;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;	
					}
					SetTextValue(screen_id, 15 , (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_PASSCODE_KEY_NUM6:{//按键6
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3600;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0036;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3600;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0036;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;	
					}
					SetTextValue(screen_id, 15 , (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));		
					break;
				}
				case GDDC_PAGE_PASSCODE_KEY_NUM7:{//按键7
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3700;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0037;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3700;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0037;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;
					}
					SetTextValue(screen_id, 15 , (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_PASSCODE_KEY_NUM8:{//按键8
						if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3800;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0038;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3800;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0038;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;
					}
					SetTextValue(screen_id, 15 , (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_PASSCODE_KEY_NUM9:{//按键9
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3900;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0039;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3900;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0039;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;
					}
					SetTextValue(screen_id, 15 , (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_PASSCODE_KEY_NUM0:{//按键0
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3000;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0030;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3000;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0030;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;
					}
					SetTextValue(screen_id, 15 , (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_PASSCODE_KEY_CANCEL:{//按键CANCEL
					CLR(EM_DC_NEW_PASSCODE0);//清空已输入密码
					CLR(EM_DC_NEW_PASSCODE1);
					CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引
					NVRAM0[EM_DC_PAGE] = GDDC_PAGE_PASSCODE_0;
					SetTextValue(screen_id, 15 , (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_PASSCODE_KEY_BACKSPACE:{//按键BACKSPACE
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 4){
						NVRAM0[EM_DC_NEW_PASSCODE1] &= 0xFF00;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 0x3;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] &= 0x00FF;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 0x2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE0] &= 0xFF00;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 0x1;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] &= 0x00FF;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 0x0;	
					}
					SetTextValue(screen_id, 15 , (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_PASSCODE_KEY_CHANGEPASSCODE:{//按键CHANGEPASSCODE
					if((NVRAM0[EM_DC_NEW_PASSCODE0] == NVRAM0[DM_DC_OLD_PASSCODE0]) && (NVRAM0[EM_DC_NEW_PASSCODE1] == NVRAM0[DM_DC_OLD_PASSCODE1])){
						NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_NEW0;
						NVRAM0[EM_DC_PAGE] = GDDC_PAGE_NEW_PASSCODE_0;
						SetScreen(NVRAM0[EM_DC_PAGE]);	
					}
					else if((NVRAM0[EM_DC_NEW_PASSCODE0] == NVRAM0[EM_DC_DEFAULT_PASSCODE0]) && (NVRAM0[EM_DC_NEW_PASSCODE1] == NVRAM0[DM_DC_OLD_PASSCODE1])){
						NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_NEW0;
						NVRAM0[EM_DC_PAGE] = GDDC_PAGE_NEW_PASSCODE_0;
						SetScreen(NVRAM0[EM_DC_PAGE]);
					}
					CLR(EM_DC_NEW_PASSCODE0);//清空已输入密码
					CLR(EM_DC_NEW_PASSCODE1);
					CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引
					SetTextValue(screen_id, 15 , (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_PASSCODE_KEY_ENTER:{//按键ENTER
					if((NVRAM0[EM_DC_NEW_PASSCODE0] == NVRAM0[DM_DC_OLD_PASSCODE0]) && (NVRAM0[EM_DC_NEW_PASSCODE1] == NVRAM0[DM_DC_OLD_PASSCODE1])){
						NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;
						updateStandbyDisplay();
						standbyTouchEnable(true);
					}		
					else if((NVRAM0[EM_DC_NEW_PASSCODE0] == NVRAM0[EM_DC_DEFAULT_PASSCODE0]) && (NVRAM0[EM_DC_NEW_PASSCODE1] == NVRAM0[EM_DC_DEFAULT_PASSCODE1])){
						NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;
						SET(R_ADMIN);//工程师密码登录
						updateStandbyDisplay();
						standbyTouchEnable(true);	
						
					}
					CLR(EM_DC_NEW_PASSCODE0);//清空已输入密码
					CLR(EM_DC_NEW_PASSCODE1);
					CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引 
					SetTextValue(screen_id, GDDC_PAGE_PASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_NEW_PASSCODE_0:{//新密码输入页面
			switch(control_id){
				case GDDC_PAGE_NEWPASSCODE_KEY_NUM1:{//按键1
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3100;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0031;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3100;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0031;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;
					}
					SetTextValue(GDDC_PAGE_NEW_PASSCODE_0, GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_NEWPASSCODE_KEY_NUM2:{//按键2	
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3200;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0032;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3200;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0032;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;
					}
					SetTextValue(GDDC_PAGE_NEW_PASSCODE_0, GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_NEWPASSCODE_KEY_NUM3:{//按键3
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3300;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0033;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3300;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0033;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;	
					}
					SetTextValue(GDDC_PAGE_NEW_PASSCODE_0, GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_NEWPASSCODE_KEY_NUM4:{//按键4
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3400;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0034;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3400;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0034;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;	
					}
					SetTextValue(GDDC_PAGE_NEW_PASSCODE_0, GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_NEWPASSCODE_KEY_NUM5:{//按键5
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3500;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0035;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3500;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0035;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;	
					}
					SetTextValue(GDDC_PAGE_NEW_PASSCODE_0, GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_NEWPASSCODE_KEY_NUM6:{//按键6
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3600;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0036;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3600;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0036;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;	
					}
					SetTextValue(GDDC_PAGE_NEW_PASSCODE_0, GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_NEWPASSCODE_KEY_NUM7:{//按键7
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3700;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0037;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3700;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0037;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;
					}
					SetTextValue(GDDC_PAGE_NEW_PASSCODE_0, GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_NEWPASSCODE_KEY_NUM8:{//按键8
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3800;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0038;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3800;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0038;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;
					}
					SetTextValue(GDDC_PAGE_NEW_PASSCODE_0, GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_NEWPASSCODE_KEY_NUM9:{//按键9
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3900;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0039;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3900;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0039;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;
					}
					SetTextValue(GDDC_PAGE_NEW_PASSCODE_0, GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));	
					break;	
				}
				case GDDC_PAGE_NEWPASSCODE_KEY_NUM0:{//按键0
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3000;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x0030;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x3000;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 3;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] |= 0x0030;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 4;
					}
					SetTextValue(GDDC_PAGE_NEW_PASSCODE_0, GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_NEWPASSCODE_KEY_CANCEL:{
					CLR(EM_DC_NEW_PASSCODE0);
					CLR(EM_DC_NEW_PASSCODE1);
					CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引 
					SetTextValue(GDDC_PAGE_NEW_PASSCODE_0, GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;	
				}
				case GDDC_PAGE_NEWPASSCODE_KEY_BACKSPACE:{
					if(NVRAM0[EM_DC_PASSCODE_INDEX] == 4){
						NVRAM0[EM_DC_NEW_PASSCODE1] &= 0xFF00;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 0x3;
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
						NVRAM0[EM_DC_NEW_PASSCODE1] &= 0x00FF;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 0x2;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
						NVRAM0[EM_DC_NEW_PASSCODE0] &= 0xFF00;	
						NVRAM0[EM_DC_PASSCODE_INDEX] = 0x1;	
					}
					else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
						NVRAM0[EM_DC_NEW_PASSCODE0] &= 0x00FF;
						NVRAM0[EM_DC_PASSCODE_INDEX] = 0x0;	
					}
					SetTextValue(GDDC_PAGE_NEW_PASSCODE_0, GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_NEWPASSCODE_KEY_SAVE:{
					if((NVRAM0[EM_DC_PASSCODE_INDEX] >= 4) && (NVRAM0[EM_DC_NEW_PASSCODE0] != 0x0000) && (NVRAM0[EM_DC_NEW_PASSCODE0] != 0x0000)){
						MOV(DM_DC_OLD_PASSCODE0, EM_DC_NEW_PASSCODE0);
						MOV(DM_DC_OLD_PASSCODE1, EM_DC_NEW_PASSCODE1);
						CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引 
						CLR(EM_DC_NEW_PASSCODE0);
						CLR(EM_DC_NEW_PASSCODE1);
						NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_INPUT;
						NVRAM0[EM_DC_PAGE] = GDDC_PAGE_PASSCODE_0;
						SetScreen(NVRAM0[EM_DC_PAGE]);
					}
					else{
						CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引 
						CLR(EM_DC_NEW_PASSCODE0);
						CLR(EM_DC_NEW_PASSCODE1);
						NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_NEW0;
						NVRAM0[EM_DC_PAGE] = GDDC_PAGE_NEW_PASSCODE_0;
					}
					SetTextValue(GDDC_PAGE_NEW_PASSCODE_0, GDDC_PAGE_NEWPASSCODE_TEXTDISPLAY, (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					break;
				}
				case GDDC_PAGE_NEWPASSCODE_KEY_BACK:{//放弃新密码修改
					CLR(EM_DC_NEW_PASSCODE0);
					CLR(EM_DC_NEW_PASSCODE1);
					CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引 
					NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_INPUT;
					NVRAM0[EM_DC_PAGE] = GDDC_PAGE_PASSCODE_0;
					SetTextValue(screen_id, GDDC_PAGE_NEWPASSCODE_KEY_BACK , (uint8_t*)(&(NVRAM0[EM_DC_NEW_PASSCODE0])));
					SetScreen(NVRAM0[EM_DC_PAGE]);
					break;
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_CW_0:{//主界面STANDBY CW
			switch(control_id){				
				case GDDC_PAGE_STANDBY_CW_KEY_POWER_CH0_ADD:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH0] < CONFIG_MAX_LASERPOWER_CH0){
							NVRAM0[EM_LASER_POWER_CH0]++;
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_CW);
							SetProgressValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));						
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_POWER_CH0_DEC:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH0] > CONFIG_MIN_LASERPOWER_CH0){
							DECS1(EM_LASER_POWER_CH0);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_CW);						
							SetProgressValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_POWER_CH1_ADD:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH1] < CONFIG_MAX_LASERPOWER_CH1){
							ADDS1(EM_LASER_POWER_CH1);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_CW);
							SetProgressValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_POWER_CH1_DEC:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH1] > CONFIG_MIN_LASERPOWER_CH1){
							DECS1(EM_LASER_POWER_CH1);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_CW);
							SetProgressValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_SCHEME_SAVE:{
					if(state == 0x01){
						saveScheme();
						FDSAV();//FDRAM->EPROM
					}
					else if(state == 0x00){
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_SCHEME_LAST:{//选择上一个方案
					if(state == 0){
						if(NVRAM0[DM_SCHEME_NUM] > 0){
							DECS1(DM_SCHEME_NUM);//+1
							loadScheme();//DM->EM
							NVSAV();//立即更新NVRAM
							updateStandbyDisplay();
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_SCHEME_NEXT:{//选择下一个方案
					if(state == 0){
						if(NVRAM0[DM_SCHEME_NUM] < (CONFIG_HMI_SCHEME_NUM - 1)){
							ADDS1(DM_SCHEME_NUM);//+1
							loadScheme();//DM->EM
							updateStandbyDisplay();
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_STANDBY:{
					if(state == 0x01){
						SET(R_STANDBY_KEY_STNADBY_DOWN);
					}
					else if(state == 0x00){
						SET(R_STANDBY_KEY_STNADBY_UP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_SELECT_CH0:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_CH0;
						SetButtonValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_KEY_SELECT_CH1, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_KEY_SELECT_BOTH, 0x00);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_SELECT_CH1:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_CH1;
						SetButtonValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_KEY_SELECT_CH0, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_KEY_SELECT_BOTH, 0x00);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_SELECT_BOTH:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_BOTH;
						SetButtonValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_KEY_SELECT_CH0, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_KEY_SELECT_CH1, 0x00);
					}
					break;
				}	
				case GDDC_PAGE_STANDBY_CW_KEY_MODE_CW:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_CW;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_MODE_MP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_MP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_MODE_GP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_GP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_MODE_SP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_SP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_MODE_SIGNAL:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_SIGNAL;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_MODE_DERMA:{	
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_DERMA;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_CW_KEY_RESET:{
					if(state == 0x01){
						NVRAM0[EM_RELEASE_TOTAL_TIME] = 0;
						NVRAM0[EM_RELEASE_TOTAL_ENERGY] = 0;
						SetTextInt32(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_TEXTDISPLAY_ENERGY ,NVRAM0[EM_RELEASE_TOTAL_ENERGY], 1, 0);
						SetTextInt32(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_TEXTDISPLAY_RELEASE_TIME ,NVRAM0[EM_RELEASE_TOTAL_TIME], 1, 0);
						SetButtonValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_KEY_RESET, 0x00);
					}
					break;
				}	
				case GDDC_PAGE_STANDBY_CW_KEY_ENTER_OPTION:{
					if(state == 0x01){
						SET(R_STANDBY_KEY_ENTER_OPTION_DOWN);
					}
					else if(state == 0x00){
						SET(R_STANDBY_KEY_ENTER_OPTION_UP);
					}
					break;
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_SP_0:{//主界面STANDBY SP
			switch(control_id){
				case GDDC_PAGE_STANDBY_SP_KEY_POWER_CH0_ADD:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH0] < CONFIG_MAX_LASERPOWER_CH0){
							ADDS1(EM_LASER_POWER_CH0);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];	
							updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_SP);
							SetProgressValue(GDDC_PAGE_STANDBY_SP_0, GDDC_PAGE_STANDBY_SP_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));						
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_POWER_CH0_DEC:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH0] > CONFIG_MIN_LASERPOWER_CH0){
							DECS1(EM_LASER_POWER_CH0);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_SP);
							SetProgressValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_POWER_CH1_ADD:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH1] < CONFIG_MAX_LASERPOWER_CH1){
							ADDS1(EM_LASER_POWER_CH1);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_SP);
							SetProgressValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_POWER_CH1_DEC:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH1] > CONFIG_MIN_LASERPOWER_CH1){
							DECS1(EM_LASER_POWER_CH1);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_SP);
							SetProgressValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_POSWIDTH_ADD:{	
					if(state == 0x00){
						RES(R_STANDBY_KEY_POSWIDTH_ADD_DOWN);
						T10MS(T10MS_POSWIDTH_ADD_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_POSWIDTH_ADD_DOWN);
						NVRAM0[EM_LASER_SP_POSWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_SP_POSWIDTH]);
						updataPosWidthDisplay(LASER_MODE_SP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_POSWIDTH_DEC:{
					if(state == 0x00){
						RES(R_STANDBY_KEY_POSWIDTH_DEC_DOWN);
						T10MS(T10MS_POSWIDTH_DEC_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_POSWIDTH_DEC_DOWN);	
						NVRAM0[EM_LASER_SP_POSWIDTH] = pulseWidthDec(NVRAM0[EM_LASER_SP_POSWIDTH]);
						updataPosWidthDisplay(LASER_MODE_SP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_SCHEME_SAVE:{
					if(state == 0x01){
						saveScheme();
						FDSAV();//立即更新NVRAM
					}
					else if(state == 0x00){
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_SCHEME_LAST:{//选择上一个方案
					if(state == 0){
						if(NVRAM0[DM_SCHEME_NUM] > 0){
							DECS1(DM_SCHEME_NUM);//+1
							loadScheme();//DM->EM
							updateStandbyDisplay();
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_SCHEME_NEXT:{//选择下一个方案
					if(state == 0){
						if(NVRAM0[DM_SCHEME_NUM] < (CONFIG_HMI_SCHEME_NUM - 1)){
							ADDS1(DM_SCHEME_NUM);//+1
							loadScheme();//DM->EM
							updateStandbyDisplay();
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_STANDBY:{
					if(state == 0x01){
						SET(R_STANDBY_KEY_STNADBY_DOWN);
					}
					else if(state == 0x00){
						SET(R_STANDBY_KEY_STNADBY_UP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_SELECT_CH0:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_CH0;
						SetButtonValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_KEY_SELECT_CH1, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_KEY_SELECT_BOTH, 0x00);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_SELECT_CH1:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_CH1;
						SetButtonValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_KEY_SELECT_CH0, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_KEY_SELECT_BOTH, 0x00);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_SELECT_BOTH:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_BOTH;
						SetButtonValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_KEY_SELECT_CH0, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_KEY_SELECT_CH1, 0x00);
					}
					break;
				}	
				case GDDC_PAGE_STANDBY_SP_KEY_MODE_CW:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_CW;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_MODE_MP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_MP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_MODE_GP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_GP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_MODE_SP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_SP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_MODE_SIGNAL:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_SIGNAL;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_MODE_DERMA:{	
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_DERMA;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SP_KEY_RESET:{
					if(state == 0x01){
						NVRAM0[EM_RELEASE_TOTAL_TIME] = 0;
						NVRAM0[EM_RELEASE_TOTAL_ENERGY] = 0;
						SetTextInt32(GDDC_PAGE_STANDBY_SP_0, GDDC_PAGE_STANDBY_SP_TEXTDISPLAY_ENERGY ,NVRAM0[EM_RELEASE_TOTAL_ENERGY], 1, 0);
						SetTextInt32(GDDC_PAGE_STANDBY_SP_0, GDDC_PAGE_STANDBY_SP_TEXTDISPLAY_RELEASE_TIME ,NVRAM0[EM_RELEASE_TOTAL_TIME], 1, 0);
						SetButtonValue(GDDC_PAGE_STANDBY_CW_0, GDDC_PAGE_STANDBY_CW_KEY_RESET, 0x00);
					}
					break;
				}	
				case GDDC_PAGE_STANDBY_SP_KEY_ENTER_OPTION:{
					if(state == 0x01){
						SET(R_STANDBY_KEY_ENTER_OPTION_DOWN);
					}
					else if(state == 0x00){
						SET(R_STANDBY_KEY_ENTER_OPTION_UP);
					}
					break;
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_MP_0:{//主界面STANDBY MP
			switch(control_id){				
				case GDDC_PAGE_STANDBY_MP_KEY_POWER_CH0_ADD:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH0] < CONFIG_MAX_LASERPOWER_CH0){
							ADDS1(EM_LASER_POWER_CH0);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_MP);
							SetProgressValue(GDDC_PAGE_STANDBY_MP_0, GDDC_PAGE_STANDBY_MP_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));						
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_POWER_CH0_DEC:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH0] > CONFIG_MIN_LASERPOWER_CH0){
							DECS1(EM_LASER_POWER_CH0);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_MP);
							SetProgressValue(GDDC_PAGE_STANDBY_MP_0, GDDC_PAGE_STANDBY_MP_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_POWER_CH1_ADD:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH1] < CONFIG_MAX_LASERPOWER_CH1){
							ADDS1(EM_LASER_POWER_CH1);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_MP);
							SetProgressValue(GDDC_PAGE_STANDBY_MP_0, GDDC_PAGE_STANDBY_MP_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_POWER_CH1_DEC:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH1] > CONFIG_MIN_LASERPOWER_CH1){
							DECS1(EM_LASER_POWER_CH1);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_MP);						
							SetProgressValue(GDDC_PAGE_STANDBY_MP_0, GDDC_PAGE_STANDBY_MP_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_POSWIDTH_ADD:{	
					if(state == 0x00){
						RES(R_STANDBY_KEY_POSWIDTH_ADD_DOWN);
						T10MS(T10MS_POSWIDTH_ADD_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_POSWIDTH_ADD_DOWN);
						NVRAM0[EM_LASER_MP_POSWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_MP_POSWIDTH]);
						updataPosWidthDisplay(LASER_MODE_MP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_POSWIDTH_DEC:{
					if(state == 0x00){
						RES(R_STANDBY_KEY_POSWIDTH_DEC_DOWN);	
						T10MS(T10MS_POSWIDTH_DEC_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_POSWIDTH_DEC_DOWN);
						NVRAM0[EM_LASER_MP_POSWIDTH] = pulseWidthDec(NVRAM0[EM_LASER_MP_POSWIDTH]);
						updataPosWidthDisplay(LASER_MODE_MP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_NEGWIDTH_ADD:{
					if(state == 0x00){
						RES(R_STANDBY_KEY_NEGWIDTH_ADD_DOWN);
						T10MS(T10MS_NEGWIDTH_ADD_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_NEGWIDTH_ADD_DOWN);
						NVRAM0[EM_LASER_MP_NEGWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_MP_NEGWIDTH]);
						updataNegWidthDisplay(LASER_MODE_MP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_NEGWIDTH_DEC:{
					if(state == 0x00){
						RES(R_STANDBY_KEY_NEGWIDTH_DEC_DOWN);
						T10MS(T10MS_NEGWIDTH_DEC_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_NEGWIDTH_DEC_DOWN);
						NVRAM0[EM_LASER_MP_NEGWIDTH] = pulseWidthDec(NVRAM0[EM_LASER_MP_NEGWIDTH]);
						updataNegWidthDisplay(LASER_MODE_MP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_SCHEME_SAVE:{
					if(state == 0x01){
						saveScheme();
						NVSAV();//立即更新NVRAM
					}
					else if(state == 0x00){
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_SCHEME_LAST:{//选择上一个方案
					if(state == 0){
						if(NVRAM0[DM_SCHEME_NUM] > 0){
							DECS1(DM_SCHEME_NUM);//+1
							loadScheme();//DM->EM
							updateStandbyDisplay();
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_SCHEME_NEXT:{//选择下一个方案
					if(state == 0){
						if(NVRAM0[DM_SCHEME_NUM] < (CONFIG_HMI_SCHEME_NUM - 1)){
							ADDS1(DM_SCHEME_NUM);//+1
							loadScheme();//DM->EM
							updateStandbyDisplay();
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_STANDBY:{
					if(state == 0x01){
						SET(R_STANDBY_KEY_STNADBY_DOWN);
					}
					else if(state == 0x00){
						SET(R_STANDBY_KEY_STNADBY_UP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_SELECT_CH0:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_CH0;
						SetButtonValue(GDDC_PAGE_STANDBY_MP_0, GDDC_PAGE_STANDBY_MP_KEY_SELECT_CH1, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_MP_0, GDDC_PAGE_STANDBY_MP_KEY_SELECT_BOTH, 0x00);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_SELECT_CH1:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_CH1;
						SetButtonValue(GDDC_PAGE_STANDBY_MP_0, GDDC_PAGE_STANDBY_MP_KEY_SELECT_CH0, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_MP_0, GDDC_PAGE_STANDBY_MP_KEY_SELECT_BOTH, 0x00);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_SELECT_BOTH:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_BOTH;
						SetButtonValue(GDDC_PAGE_STANDBY_MP_0, GDDC_PAGE_STANDBY_MP_KEY_SELECT_CH0, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_MP_0, GDDC_PAGE_STANDBY_MP_KEY_SELECT_CH1, 0x00);
					}
					break;
				}	
				case GDDC_PAGE_STANDBY_MP_KEY_MODE_CW:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_CW;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_MODE_MP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_MP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_MODE_GP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_GP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_MODE_SP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_SP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_MODE_SIGNAL:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_SIGNAL;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_MODE_DERMA:{	
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_DERMA;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_MP_KEY_RESET:{
					if(state == 0x01){
						NVRAM0[EM_RELEASE_TOTAL_TIME] = 0;
						NVRAM0[EM_RELEASE_TOTAL_ENERGY] = 0;
						SetTextInt32(GDDC_PAGE_STANDBY_MP_0, GDDC_PAGE_STANDBY_MP_TEXTDISPLAY_ENERGY ,NVRAM0[EM_RELEASE_TOTAL_ENERGY], 1, 0);
						SetTextInt32(GDDC_PAGE_STANDBY_MP_0, GDDC_PAGE_STANDBY_MP_TEXTDISPLAY_RELEASE_TIME ,NVRAM0[EM_RELEASE_TOTAL_TIME], 1, 0);
						SetButtonValue(GDDC_PAGE_STANDBY_MP_0, GDDC_PAGE_STANDBY_MP_KEY_RESET, 0x00);
					}
					break;
				}	
				case GDDC_PAGE_STANDBY_MP_KEY_ENTER_OPTION:{
					if(state == 0x01){
						SET(R_STANDBY_KEY_ENTER_OPTION_DOWN);
					}
					else if(state == 0x00){
						SET(R_STANDBY_KEY_ENTER_OPTION_UP);
					}
					break;
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_GP_0:{//主界面STANDBY GP
			switch(control_id){				
				case GDDC_PAGE_STANDBY_GP_KEY_POWER_CH0_ADD:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH0] < CONFIG_MAX_LASERPOWER_CH0){
							ADDS1(EM_LASER_POWER_CH0);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_GP);
							SetProgressValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));						
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_POWER_CH0_DEC:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH0] > CONFIG_MIN_LASERPOWER_CH0){
							DECS1(EM_LASER_POWER_CH0);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_GP);						
							SetProgressValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_POWER_CH1_ADD:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH1] < CONFIG_MAX_LASERPOWER_CH1){
							ADDS1(EM_LASER_POWER_CH1);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_GP);
							SetProgressValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_POWER_CH1_DEC:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH1] > CONFIG_MIN_LASERPOWER_CH1){
							DECS1(EM_LASER_POWER_CH1);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_GP);
							SetProgressValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_POSWIDTH_ADD:{	
					if(state == 0x00){
						RES(R_STANDBY_KEY_POSWIDTH_ADD_DOWN);
						T10MS(T10MS_POSWIDTH_ADD_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_POSWIDTH_ADD_DOWN);
						NVRAM0[EM_LASER_GP_POSWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_GP_POSWIDTH]);
						updataPosWidthDisplay(LASER_MODE_GP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_POSWIDTH_DEC:{
					if(state == 0x00){
						RES(R_STANDBY_KEY_POSWIDTH_DEC_DOWN);
						T10MS(T10MS_POSWIDTH_DEC_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_POSWIDTH_DEC_DOWN);
						NVRAM0[EM_LASER_GP_POSWIDTH] = pulseWidthDec(NVRAM0[EM_LASER_GP_POSWIDTH]);
						updataPosWidthDisplay(LASER_MODE_GP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_NEGWIDTH_ADD:{
					if(state == 0x00){
						RES(R_STANDBY_KEY_NEGWIDTH_ADD_DOWN);
						T10MS(T10MS_NEGWIDTH_ADD_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_NEGWIDTH_ADD_DOWN);
						NVRAM0[EM_LASER_GP_NEGWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_GP_NEGWIDTH]);
						updataNegWidthDisplay(LASER_MODE_GP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_NEGWIDTH_DEC:{
					if(state == 0x00){
						RES(R_STANDBY_KEY_NEGWIDTH_DEC_DOWN);
						T10MS(T10MS_NEGWIDTH_DEC_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_NEGWIDTH_DEC_DOWN);
						NVRAM0[EM_LASER_GP_NEGWIDTH] = pulseWidthDec(NVRAM0[EM_LASER_GP_NEGWIDTH]);
						updataNegWidthDisplay(LASER_MODE_GP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_TIMES_ADD:{
					if(state == 0x00){
						RES(R_STANDBY_KEY_TIMES_ADD_DOWN);
						T10MS(T10MS_TIMES_ADD_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){
						SET(R_STANDBY_KEY_TIMES_ADD_DOWN);
						NVRAM0[EM_LASER_GP_NEGWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_GP_NEGWIDTH]);
						SetTextInt32(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_TIMES ,NVRAM0[EM_LASER_GP_TIMES], 1, 0);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_TIMES_DEC:{
					if(state == 0x0){
						RES(R_STANDBY_KEY_TIMES_DEC_DOWN);
						T10MS(T10MS_TIMES_DEC_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){
						SET(R_STANDBY_KEY_TIMES_DEC_DOWN);
						if(NVRAM0[EM_LASER_GP_TIMES] > CONFIG_MIN_LASER_TIMES){
							DECS1(EM_LASER_GP_TIMES);//-1
							SetTextInt32(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_TIMES ,NVRAM0[EM_LASER_GP_TIMES], 1, 0);
						}	
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_GROUP_OFF_ADD:{
					if(state == 0x0){
						RES(R_STANDBY_KEY_GROUP_OFF_ADD_DOWN);
						T10MS(T10MS_GROUP_OFF_ADD_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_GROUP_OFF_ADD_DOWN);
						if(NVRAM0[EM_LASER_GP_GROUP_OFF] < CONFIG_MAX_LASER_GROUP_OFF){
							ADDS1(EM_LASER_GP_GROUP_OFF);//+1
							SetTextInt32(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_GROUP_OFF ,NVRAM0[EM_LASER_GP_GROUP_OFF], 1, 0);
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_GROUP_OFF_DEC:{
					if(state == 0x0){//UP
						RES(R_STANDBY_KEY_GROUP_OFF_DEC_DOWN);
						T10MS(T10MS_GROUP_OFF_DEC_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_GROUP_OFF_DEC_DOWN);
						if(NVRAM0[EM_LASER_GP_GROUP_OFF] > CONFIG_MIN_LASER_GROUP_OFF){
							DECS1(EM_LASER_GP_GROUP_OFF);//-1
							SetTextInt32(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_GROUP_OFF ,NVRAM0[EM_LASER_GP_GROUP_OFF], 1, 0);
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_SCHEME_SAVE:{
					if(state == 0x01){
						saveScheme();
						FDSAV();//FDRAM->EPROM
					}
					else if(state == 0x00){
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_SCHEME_LAST:{//选择上一个方案
					if(state == 0){
						if(NVRAM0[DM_SCHEME_NUM] > 0){
							DECS1(DM_SCHEME_NUM);//+1
							loadScheme();//DM->EM
							updateStandbyDisplay();
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_SCHEME_NEXT:{//选择下一个方案
					if(state == 0){
						if(NVRAM0[DM_SCHEME_NUM] < (CONFIG_HMI_SCHEME_NUM - 1)){
							ADDS1(DM_SCHEME_NUM);//+1
							loadScheme();//DM->EM
							updateStandbyDisplay();
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_STANDBY:{
					if(state == 0x01){
						SET(R_STANDBY_KEY_STNADBY_DOWN);
					}
					else if(state == 0x00){
						SET(R_STANDBY_KEY_STNADBY_UP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_SELECT_CH0:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_CH0;
						SetButtonValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_KEY_SELECT_CH1, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_KEY_SELECT_BOTH, 0x00);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_SELECT_CH1:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_CH1;
						SetButtonValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_KEY_SELECT_CH0, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_KEY_SELECT_BOTH, 0x00);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_SELECT_BOTH:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_BOTH;
						SetButtonValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_KEY_SELECT_CH0, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_KEY_SELECT_CH1, 0x00);
					}
					break;
				}	
				case GDDC_PAGE_STANDBY_GP_KEY_MODE_CW:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_CW;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_MODE_MP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_MP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_MODE_GP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_GP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_MODE_SP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_SP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_MODE_SIGNAL:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_SIGNAL;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_MODE_DERMA:{	
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_DERMA;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_GP_KEY_RESET:{
					if(state == 0x01){
						NVRAM0[EM_RELEASE_TOTAL_TIME] = 0;
						NVRAM0[EM_RELEASE_TOTAL_ENERGY] = 0;
						SetTextInt32(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_ENERGY ,NVRAM0[EM_RELEASE_TOTAL_ENERGY], 1, 0);
						SetTextInt32(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_TEXTDISPLAY_RELEASE_TIME ,NVRAM0[EM_RELEASE_TOTAL_TIME], 1, 0);
						SetButtonValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_KEY_RESET, 0x00);
					}
					break;
				}	
				case GDDC_PAGE_STANDBY_GP_KEY_ENTER_OPTION:{
					if(state == 0x01){
						SET(R_STANDBY_KEY_ENTER_OPTION_DOWN);
					}
					else if(state == 0x00){
						SET(R_STANDBY_KEY_ENTER_OPTION_UP);
					}
					break;
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_SIGNAL_0:{//主界面STANDBY EVLA SIGNAL
			switch(control_id){				
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_POWER_CH0_ADD:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH0] < CONFIG_MAX_LASERPOWER_CH0){
							ADDS1(EM_LASER_POWER_CH0);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_SIGNAL);
							SetProgressValue(GDDC_PAGE_STANDBY_SIGNAL_0, GDDC_PAGE_STANDBY_SIGNAL_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));						
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_POWER_CH0_DEC:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH0] > CONFIG_MIN_LASERPOWER_CH0){
							DECS1(EM_LASER_POWER_CH0);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_SIGNAL);	
							SetProgressValue(GDDC_PAGE_STANDBY_SIGNAL_0, GDDC_PAGE_STANDBY_SIGNAL_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_POWER_CH1_ADD:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH1] < CONFIG_MAX_LASERPOWER_CH1){
							ADDS1(EM_LASER_POWER_CH1);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_SIGNAL);
							SetProgressValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_POWER_CH1_DEC:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH1] > CONFIG_MIN_LASERPOWER_CH1){
							DECS1(EM_LASER_POWER_CH1);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_SIGNAL);
							SetProgressValue(GDDC_PAGE_STANDBY_SIGNAL_0, GDDC_PAGE_STANDBY_SIGNAL_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_ENERGY_INTERVAL_ADD:{
					if(state == 0x01){	
						if(NVRAM0[EM_LASER_SIGNAL_ENERGY_INTERVAL] < CONFIG_MAX_LASER_ENERGY_INTERVAL){
							NVRAM0[EM_LASER_SIGNAL_ENERGY_INTERVAL] += 100;
						}
						SetTextInt32(GDDC_PAGE_STANDBY_SIGNAL_0, GDDC_PAGE_STANDBY_SIGNAL_TEXTDISPLAY_ENERGY_INTERVAL ,NVRAM0[EM_LASER_SIGNAL_ENERGY_INTERVAL], 1, 0);	
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_ENERGY_INTERVAL_DEC:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_SIGNAL_ENERGY_INTERVAL] > CONFIG_MIN_LASER_ENERGY_INTERVAL){
							NVRAM0[EM_LASER_SIGNAL_ENERGY_INTERVAL] -= 100;
						}
						SetTextInt32(GDDC_PAGE_STANDBY_SIGNAL_0, GDDC_PAGE_STANDBY_SIGNAL_TEXTDISPLAY_ENERGY_INTERVAL ,NVRAM0[EM_LASER_SIGNAL_ENERGY_INTERVAL], 1, 0);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_SCHEME_SAVE:{
					if(state == 0x01){
						saveScheme();
						FDSAV();//立即更新NVRAM
					}
					else if(state == 0x00){
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_SCHEME_LAST :{//选择上一个方案
					if(state == 0){
						if(NVRAM0[DM_SCHEME_NUM] > 0){
							DECS1(DM_SCHEME_NUM);//+1
							loadScheme();//DM->EM
							updateStandbyDisplay();
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_SCHEME_NEXT:{//选择下一个方案
					if(state == 0){
						if(NVRAM0[DM_SCHEME_NUM] < (CONFIG_HMI_SCHEME_NUM - 1)){
							ADDS1(DM_SCHEME_NUM);//+1
							loadScheme();//DM->EM
							updateStandbyDisplay();
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_STANDBY:{
					if(state == 0x01){
						SET(R_STANDBY_KEY_STNADBY_DOWN);
					}
					else if(state == 0x00){
						SET(R_STANDBY_KEY_STNADBY_UP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_SELECT_CH0:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_CH0;
						SetButtonValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_KEY_SELECT_CH1, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_KEY_SELECT_BOTH, 0x00);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_SELECT_CH1:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_CH1;
						SetButtonValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_KEY_SELECT_CH0, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_KEY_SELECT_BOTH, 0x00);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_SELECT_BOTH:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_BOTH;
						SetButtonValue(GDDC_PAGE_STANDBY_SIGNAL_0, GDDC_PAGE_STANDBY_SIGNAL_KEY_SELECT_CH0, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_SIGNAL_0, GDDC_PAGE_STANDBY_SIGNAL_KEY_SELECT_CH1, 0x00);
					}
					break;
				}	
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_MODE_CW:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_CW;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_MODE_MP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_MP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_MODE_GP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_GP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_MODE_SP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_SP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_MODE_SIGNAL:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_SIGNAL;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_MODE_DERMA:{	
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_DERMA;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_RESET:{
					if(state == 0x01){
						NVRAM0[EM_RELEASE_TOTAL_TIME] = 0;
						NVRAM0[EM_RELEASE_TOTAL_ENERGY] = 0;
						SetTextInt32(GDDC_PAGE_STANDBY_SIGNAL_0, GDDC_PAGE_STANDBY_SIGNAL_TEXTDISPLAY_ENERGY ,NVRAM0[EM_RELEASE_TOTAL_ENERGY], 1, 0);
						SetTextInt32(GDDC_PAGE_STANDBY_SIGNAL_0, GDDC_PAGE_STANDBY_SIGNAL_TEXTDISPLAY_RELEASE_TIME ,NVRAM0[EM_RELEASE_TOTAL_TIME], 1, 0);
						SetButtonValue(GDDC_PAGE_STANDBY_GP_0, GDDC_PAGE_STANDBY_GP_KEY_RESET, 0x00);
					}
					break;
				}	
				case GDDC_PAGE_STANDBY_SIGNAL_KEY_ENTER_OPTION:{
					if(state == 0x01){
						SET(R_STANDBY_KEY_ENTER_OPTION_DOWN);
					}
					else if(state == 0x00){
						SET(R_STANDBY_KEY_ENTER_OPTION_UP);
					}
					break;
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_STANDBY_DERMA_0:{//主界面STNADBY DERMA
			switch(control_id){	
				case GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_0MM5:{
					if(state == 0x01){
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_0MM5, true);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_1MM0, false);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_2MM0, false);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_3MM0, false);
						NVRAM0[EM_LASER_DERMA_SPOT_SIZE] = DERMA_SPOT_SIZE_0MM5;
					}
					break;
				}			
				case GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_1MM0:{
					if(state == 0x01){
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_0MM5, false);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_1MM0, true);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_2MM0, false);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_3MM0, false);
						NVRAM0[EM_LASER_DERMA_SPOT_SIZE] = DERMA_SPOT_SIZE_1MM0;
					}
					break;
				}	
				case GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_2MM0:{
					if(state == 0x01){
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_0MM5, false);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_1MM0, false);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_2MM0, true);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_3MM0, false);
						NVRAM0[EM_LASER_DERMA_SPOT_SIZE] = DERMA_SPOT_SIZE_2MM0;
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_3MM0:{
					if(state == 0x01){
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_0MM5, false);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_1MM0, false);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_2MM0, false);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SPOT_3MM0, true);
						NVRAM0[EM_LASER_DERMA_SPOT_SIZE] = DERMA_SPOT_SIZE_3MM0;
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_POSWIDTH_ADD:{	
					if(state == 0x00){
						RES(R_STANDBY_KEY_POSWIDTH_ADD_DOWN);
						T10MS(T10MS_POSWIDTH_ADD_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_POSWIDTH_ADD_DOWN);
						NVRAM0[EM_LASER_DERMA_POSWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_DERMA_POSWIDTH]);
						updataPosWidthDisplay(LASER_MODE_DERMA);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_POSWIDTH_DEC:{
					if(state == 0x00){
						RES(R_STANDBY_KEY_POSWIDTH_DEC_DOWN);
						T10MS(T10MS_POSWIDTH_DEC_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_POSWIDTH_DEC_DOWN);
						NVRAM0[EM_LASER_DERMA_POSWIDTH] = pulseWidthDec(NVRAM0[EM_LASER_DERMA_POSWIDTH]);//-1
						updataPosWidthDisplay(LASER_MODE_DERMA);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_NEGWIDTH_ADD:{
					if(state == 0x00){
						RES(R_STANDBY_KEY_NEGWIDTH_ADD_DOWN);
						T10MS(T10MS_NEGWIDTH_ADD_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_NEGWIDTH_ADD_DOWN);
						NVRAM0[EM_LASER_DERMA_NEGWIDTH] = pulseWidthAdd(NVRAM0[EM_LASER_DERMA_NEGWIDTH]);
						updataNegWidthDisplay(LASER_MODE_DERMA);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_NEGWIDTH_DEC:{
					if(state == 0x00){
						RES(R_STANDBY_KEY_NEGWIDTH_DEC_DOWN);
						T10MS(T10MS_NEGWIDTH_DEC_KEYDOWN_DELAY, false, CONFIG_KEY_REPEAT_DELAY_TIME);
					}
					else if(state == 0x01){//DOWN
						SET(R_STANDBY_KEY_NEGWIDTH_DEC_DOWN);
						NVRAM0[EM_LASER_DERMA_NEGWIDTH] = pulseWidthDec(NVRAM0[EM_LASER_DERMA_NEGWIDTH]);
						updataNegWidthDisplay(LASER_MODE_DERMA);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_POWER_CH0_ADD:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH0] < CONFIG_MAX_LASERPOWER_CH0){
							ADDS1(EM_LASER_POWER_CH0);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];					
							updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_DERMA);
							SetProgressValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));						
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_POWER_CH0_DEC:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH0] > CONFIG_MIN_LASERPOWER_CH0){
							DECS1(EM_LASER_POWER_CH0);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_DERMA);
							SetProgressValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_PROGRESS_CH0, ((uint32_t)NVRAM0[EM_LASER_POWER_CH0] * 100 / CONFIG_MAX_LASERPOWER_CH0));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_POWER_CH1_ADD:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH1] < CONFIG_MAX_LASERPOWER_CH1){
							ADDS1(EM_LASER_POWER_CH1);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH1, LASER_MODE_DERMA);
							SetProgressValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_POWER_CH1_DEC:{
					if(state == 0x01){
						if(NVRAM0[EM_LASER_POWER_CH1] > CONFIG_MIN_LASERPOWER_CH1){
							DECS1(EM_LASER_POWER_CH1);
							NVRAM0[EM_TOTAL_POWER] = NVRAM0[EM_LASER_POWER_CH0] + NVRAM0[EM_LASER_POWER_CH1];
							updatePowerDisplay(LASER_SELECT_CH0, LASER_MODE_DERMA);
							SetProgressValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_SIGNAL_PROGRESS_CH1, ((uint32_t)NVRAM0[EM_LASER_POWER_CH1] * 100 / CONFIG_MAX_LASERPOWER_CH1));
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_SCHEME_SAVE:{
					if(state == 0x01){
						saveScheme();
						FDSAV();//FDRAM->EPROM
					}
					else if(state == 0x00){
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_SCHEME_LAST :{//选择上一个方案
					if(state == 0){
						if(NVRAM0[DM_SCHEME_NUM] > 0){
							DECS1(DM_SCHEME_NUM);//+1
							loadScheme();//DM->EM
							updateStandbyDisplay();
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_SCHEME_NEXT:{//选择下一个方案
					if(state == 0){
						if(NVRAM0[DM_SCHEME_NUM] < (CONFIG_HMI_SCHEME_NUM - 1)){
							ADDS1(DM_SCHEME_NUM);//+1
							loadScheme();//DM->EM
							updateStandbyDisplay();
						}
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_STANDBY:{
					if(state == 0x01){
						SET(R_STANDBY_KEY_STNADBY_DOWN);
					}
					else if(state == 0x00){
						SET(R_STANDBY_KEY_STNADBY_UP);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_SELECT_CH0:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_CH0;
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SELECT_CH1, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SELECT_BOTH, 0x00);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_SELECT_CH1:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_CH1;
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SELECT_CH0, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SELECT_BOTH, 0x00);
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_SELECT_BOTH:{
					if(state == 0x01){
						NVRAM0[EM_LASER_SELECT] = LASER_SELECT_BOTH;
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SELECT_CH0, 0x00);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_SELECT_CH1, 0x00);
					}
					break;
				}	
				case GDDC_PAGE_STANDBY_DERMA_KEY_MODE_CW:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_CW;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_MODE_MP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_MP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_MODE_GP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_GP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_MODE_SP:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_SP;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_MODE_SIGNAL:{
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_SIGNAL;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_MODE_DERMA:{	
					if(state == 0x01){
						NVRAM0[EM_LASER_PULSE_MODE] = LASER_MODE_DERMA;
						updateStandbyDisplay();
					}
					break;
				}
				case GDDC_PAGE_STANDBY_DERMA_KEY_RESET:{
					if(state == 0x01){
						NVRAM0[EM_RELEASE_TOTAL_TIME] = 0;
						NVRAM0[EM_RELEASE_TOTAL_ENERGY] = 0;
						SetTextInt32(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_TEXTDISPLAY_ENERGY ,NVRAM0[EM_RELEASE_TOTAL_ENERGY], 1, 0);
						SetTextInt32(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_TEXTDISPLAY_RELEASE_TIME ,NVRAM0[EM_RELEASE_TOTAL_TIME], 1, 0);
						SetButtonValue(GDDC_PAGE_STANDBY_DERMA_0, GDDC_PAGE_STANDBY_DERMA_KEY_RESET, 0x00);
					}
					break;
				}	
				case GDDC_PAGE_STANDBY_DERMA_KEY_ENTER_OPTION:{
					if(state == 0x01){
						SET(R_STANDBY_KEY_ENTER_OPTION_DOWN);
					}
					else if(state == 0x00){
						SET(R_STANDBY_KEY_ENTER_OPTION_UP);
					}
					break;
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_OPTION_0:{//选项页面
			switch(control_id){
				case GDDC_PAGE_OPTION_KEY_TONE:{
					if(state == 0x01){
						SET(MR_BEEM_TONE);
					}
					if(state == 0x00){
						RES(MR_BEEM_TONE);
					}
					break;
				}
				case GDDC_PAGE_OPTION_KEY_AIM_BRG_ADD:{
					if(state == 0x01){
						if(NVRAM0[DM_AIM_BRG] < CONFIG_MAX_AIM_BRG){
							NVRAM0[DM_AIM_BRG] += 1;//+1	
							SetProgressValue(GDDC_PAGE_OPTION_0, GDDC_PAGE_OPTION_PROGRESS_AIM_BRG, NVRAM0[DM_AIM_BRG]);//更新进度条
							SetTextInt32(GDDC_PAGE_OPTION_0, GDDC_PAGE_OPTION_TEXTDISPLAY_AIM_BRG , NVRAM0[DM_AIM_BRG], 1, 0);
						}
					}
					break;
				}
				case GDDC_PAGE_OPTION_KEY_AIM_BRG_DEC:{
					if(state == 0x01){
						if(NVRAM0[DM_AIM_BRG] > CONFIG_MIN_AIM_BRG){
							NVRAM0[DM_AIM_BRG] -= 1;//-1	
							SetProgressValue(GDDC_PAGE_OPTION_0, GDDC_PAGE_OPTION_PROGRESS_AIM_BRG, NVRAM0[DM_AIM_BRG]);//更新进度条
							SetTextInt32(GDDC_PAGE_OPTION_0, GDDC_PAGE_OPTION_TEXTDISPLAY_AIM_BRG , NVRAM0[DM_AIM_BRG], 1, 0);
						}
					}
					break;					
				}
				case GDDC_PAGE_OPTION_KEY_BEEM_VOLUME_ADD:{
					if(state == 0x01){
						if(NVRAM0[DM_BEEM_VOLUME] < CONFIG_MAX_BEEM_VOLUME){
							NVRAM0[DM_BEEM_VOLUME] += 1;
							SetProgressValue(GDDC_PAGE_OPTION_0, GDDC_PAGE_OPTION_PROGRESS_BEEM_VOLUME, NVRAM0[DM_BEEM_VOLUME]);//更新进度条
							SetTextInt32(GDDC_PAGE_OPTION_0, GDDC_PAGE_OPTION_TEXTDISPLAY_BEEM_VOLUME , NVRAM0[DM_BEEM_VOLUME], 1, 0);
						}
					}
					break;					
				}
				case GDDC_PAGE_OPTION_KEY_BEEM_VOLUME_DEC:{
					if(state == 0x01){
						if(NVRAM0[DM_BEEM_VOLUME] > CONFIG_MIN_BEEM_VOLUME){
							NVRAM0[DM_BEEM_VOLUME] -= 1;
							SetProgressValue(GDDC_PAGE_OPTION_0, GDDC_PAGE_OPTION_PROGRESS_BEEM_VOLUME, NVRAM0[DM_BEEM_VOLUME]);//更新进度条
							SetTextInt32(GDDC_PAGE_OPTION_0, GDDC_PAGE_OPTION_TEXTDISPLAY_BEEM_VOLUME , NVRAM0[DM_BEEM_VOLUME], 1, 0);
						}
					}
					break;					
				}
				case GDDC_PAGE_OPTION_KEY_LCD_BRG_ADD:{
					if(state == 0x01){
						if(NVRAM0[DM_LCD_BRG] < CONFIG_MAX_LCD_BRG){
							NVRAM0[DM_LCD_BRG] += 1;
							SetTextInt32(GDDC_PAGE_OPTION_0, GDDC_PAGE_OPTION_TEXTDISPLAY_LCD_BRG , NVRAM0[DM_LCD_BRG], 1, 0);
							SetBackLight(getLcdDuty(NVRAM0[DM_LCD_BRG]));
						}
					}
					break;
				}
				case GDDC_PAGE_OPTION_KEY_LCD_BRG_DEC:{
					if(state == 0x01){
						if(NVRAM0[DM_LCD_BRG] > CONFIG_MIN_LCD_BRG){
							NVRAM0[DM_LCD_BRG] -= 1;
							SetTextInt32(GDDC_PAGE_OPTION_0, GDDC_PAGE_OPTION_TEXTDISPLAY_LCD_BRG , NVRAM0[DM_LCD_BRG], 1, 0);
							SetBackLight(getLcdDuty(NVRAM0[DM_LCD_BRG]));
						}
					}
					break;					
				}
				case GDDC_PAGE_OPTION_KEY_ENTER_INFORMATION:{//信息
					if(state == 0x01){
						SET(R_OPTION_KEY_ENTER_INFORMATION_DOWN);
					}
					else if(state == 0x00){
						SET(R_OPTION_KEY_ENTER_INFORMATION_UP);
					}
					break;							
				}
				case GDDC_PAGE_OPTION_KEY_ENTER_CORRECTION:{//功率校正
					if(state == 0x01){
						SET(R_OPTION_KEY_ENTER_CORRECTION_DOWN);
					}
					else if(state == 0x00){
						RES(R_OPTION_KEY_ENTER_CORRECTION_UP);
					}
					break;
				}
				case GDDC_PAGE_OPTION_KEY_ENTER_OK:{//OK
					if(state == 0x01){
						SET(R_OPTION_KEY_ENTER_OK_DOWN);
					}
					else if(state == 0x00){
						RES(R_OPTION_KEY_ENTER_OK_UP);
					}
					break;
				}
				case GDDC_PAGE_OPTION_KEY_HAND_SWITCH_ON:{
					if(state == 0x01){
						SET(MR_FOOSWITCH_HAND_SWITCH);
					}
					break;
				}
				case GDDC_PAGE_OPTION_KEY_ENTER_DIAGNOSIS:{
					if(state == 0x01){
						SET(R_OPTION_KEY_ENTER_DIAGNOSIS_DOWN);
					}
					if(state == 0x00){
						SET(R_OPTION_KEY_ENTER_DIAGNOSIS_UP);
					}
					break;
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_INFORMATION_0:{
			switch(control_id){
				case GDDC_PAGE_INFORMATION_KEY_ENTER_OK:{
					if(state == 0x1){
						SET(R_INFORMATION_KEY_OK_DOWN);
					}
					else if(state == 0x0){
						SET(R_INFORMATION_KEY_OK_UP);
					}
					break;
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_SCHEME_0:{
			switch(control_id){
				case GDDC_PAGE_SCHEME_KEY_RENAME:{
					if(state == 0x01){
						SET(R_SCHEME_KEY_RENAME_DOWN);
					}
					else if(state == 0x00){
						SET(R_SCHEME_KEY_RENAME_UP);
					}	
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SAVE_USB:{
					if(state == 0x01){
						SET(R_SCHEME_KEY_SAVE_USB_DOWN);
					}
					else if(state == 0x00){
						SET(R_SCHEME_KEY_SAVE_USB_UP);
					}
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_LOAD_USB:{
					if(state == 0x01){
						SET(R_SCHEME_KEY_LOAD_USB_DOWN);
					}
					else if(state == 0x00){
						SET(R_SCHEME_KEY_LOAD_USB_UP);
					}
					break;
				}	
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_0:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(0);
					}
					break;
				}	
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_1:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(1);
					}
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_2:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(2);
					}					
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_3:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(3);
					}					
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_4:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(4);
					}					
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_5:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(5);
					}					
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_6:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(6);
					}					
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_7:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(7);
					}
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_8:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(8);
					}					
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_9:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(9);
					}					
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_10:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(10);
					}					
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_11:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(11);
					}					
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_12:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(12);
					}					
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_13:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(13);
					}					
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_14:{	
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(14);
					}				
					break;
				}
				case GDDC_PAGE_SCHEME_KEY_SCHEME_SELECT_15:{
					if(state == 0x01){
						unselectSchemeNum(NVRAM0[DM_SCHEME_NUM]);
						unselectSchemeNum(NVRAM0[EM_SCHEME_NUM_TMP]);
						seletcSchemeNum(15);
					}
					break;
				}
				default:break;
			}
			break;
		}
		case GDDC_PAGE_DIAGNOSIS_0:{
			switch(control_id){
				case GDDC_PAGE_DIAGNOSIS_KEY_ENTER_OK:{
					SET(R_DIAGNOSIS_OK_DOWN);
					break;
				}
				default:break;
			}
		}
		default:break;
	}
}