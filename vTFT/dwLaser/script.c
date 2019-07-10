/*
函数：on_init
功能：系统执行初始化
*/
void on_init()
{
}

/*
函数：on_systick
功能：定期执行任务(1秒/次)
*/
void on_systick()
{
}

/*
函数：on_timer
功能：定时器超时通知
参数：timer_id，定时器ID
相关操作：
启动定时器：start_timer(timer_id,timeout,countdown,repeat)
            timer_id-定时器ID（0~9）
			timeout-超时时间，毫秒单位
			countdown-0顺计时，1倒计时，决定sys.timer递增或递减
			repeat-重复次数，0表示无穷
停止定时器：stop_timer(timer_id)
定时器数值：sys.timer0~sys.timer9，毫秒单位
*/
void on_timer(int timer_id)
{	
}

/*
函数：on_variant_upate
功能：串口通信导致变量更新时，执行此函数
*/
void on_variant_upate()
{
}

/*
函数：on_control_notify
功能：控件值更新通知
参数：screen_id，画面ID
参数：control_id，控件ID
参数：value，新值
*/
void on_control_notify(int screen_id,int control_id,int value){
	//密码输入 按键 1
	if(screen_id == 1 && control_id == 1){//KEY1
		if(value == 1){//按下
			R_DC_PASSCODE_KEY1 = 1;		
		}
	}
	//密码输入 按键 2
 	if(screen_id == 1 && control_id == 2){//KEY2
		if(value == 1){//按下
			R_DC_PASSCODE_KEY2 = 1;	
		}
	}
	//密码输入 按键 3
	if(screen_id == 1 && control_id == 3){//KEY3
		if(value == 1){//按下
			R_DC_PASSCODE_KEY3 = 1;		
		}
	}	
 	//密码输入 按键 4
	if(screen_id == 1 && control_id == 4){
		if(value == 1){//按下
			R_DC_PASSCODE_KEY4 = 1;
		}
	}	
  	//密码输入 按键 5
	if(screen_id == 1 && control_id == 5){
		if(value == 1){//按下
			R_DC_PASSCODE_KEY5 = 1;		
		}
	}	
	//密码输入 按键 6
	if(screen_id == 1 && control_id == 6){
		if(value == 1){//按下
			R_DC_PASSCODE_KEY6 = 1;		
		}
	}
	//密码输入 按键 7
	if(screen_id == 1 && control_id == 7){
		if(value == 1){//按下
			R_DC_PASSCODE_KEY7 = 1;		
		}
	}
	//密码输入 按键 8
	if(screen_id == 1 && control_id == 8){
		if(value == 1){//按下
			R_DC_PASSCODE_KEY8 = 1;		
		}
	}	
	//密码输入 按键 9
	if(screen_id == 1 && control_id == 9){
		if(value == 1){//按下
			R_DC_PASSCODE_KEY9 = 1;		
		}
	}
 	//密码输入 按键 0
	if(screen_id == 1 && control_id == 10){
		if(value == 1){//按下
			R_DC_PASSCODE_KEY0 = 1;
		}
	}	
	//密码输入 按键Cancle
	if(screen_id == 1 && control_id == 11){
		if(value == 1){//按下
			R_DC_PASSCODE_CANCEL_REQ = 1;		
		}
	}
	//密码输入 按键Backspace
	if(screen_id == 1 && control_id == 12){
		if(value == 1){//按下
			R_DC_PASSCODE_BACKSPACE_REQ = 1;
		}
	}
	//密码输入 按键Change Passcode
	if(screen_id == 1 && control_id == 13){
		if(value == 1){//按下
			R_DC_PASSCODE_CHANGE_REQ = 1;	
		}
	}
	//密码输入 按键Enter
	if(screen_id == 1 && control_id == 14){
		if(value == 1){//按下
			R_DC_PASSCODE_ENTER_REQ = 1;				
		}
	}
	//密码修改 按键1
	if(screen_id == 2 && control_id == 1){
		if(value == 1){//按下
			R_DC_NEW_PASSCODE_KEY1 = 1;		
		}
	}
	//密码修改 按键2
	if(screen_id == 2 && control_id == 2){
		if(value == 1){//按下
			R_DC_NEW_PASSCODE_KEY2 = 1;
		}
	}
	//密码修改 按键3
	if(screen_id == 2 && control_id == 3){
		if(value == 1){//按下
			R_DC_NEW_PASSCODE_KEY3 = 1;
		}
	}
	//密码修改 按键4
	if(screen_id == 2 && control_id == 4){
		if(value == 1){//按下
			R_DC_NEW_PASSCODE_KEY4 = 1;
		}
	}
	//密码修改 按键5
	if(screen_id == 2 && control_id == 5){
		if(value == 1){//按下
			R_DC_NEW_PASSCODE_KEY5 = 1;
		}
	}
	//密码修改 按键6
	if(screen_id == 2 && control_id == 6){
		if(value == 1){//按下
			R_DC_NEW_PASSCODE_KEY6 = 1;	
		}
	}
	//密码修改 按键7
	if(screen_id == 2 && control_id == 7){
		if(value == 1){//按下
			R_DC_NEW_PASSCODE_KEY7 = 1;
		}
	}
	//密码修改 按键8
	if(screen_id == 2 && control_id == 8){
		if(value == 1){//按下
			R_DC_NEW_PASSCODE_KEY8 = 1;
		}
	}
	//密码修改 按键9
	if(screen_id == 2 && control_id == 9){
		if(value == 1){//按下
			R_DC_NEW_PASSCODE_KEY9 = 1;
		}
	}
	//密码修改 按键0
 	if(screen_id == 2 && control_id == 10){
		if(value == 1){//按下
			R_DC_NEW_PASSCODE_KEY0 = 1;
		}
	}	
	//密码修改 按键Cancel
	if(screen_id == 2 && control_id == 11){
		if(value == 1){//按下
			R_DC_NEW_PASSCODE_CANCEL_REQ = 1;
		}
	}
	//密码修改 按键Backspace
 	if(screen_id == 2 && control_id == 12){
		if(value == 1){//按下
			R_DC_NEW_PASSCODE_BACKSPACE_REQ = 1;
		}
	}	
	//密码修改 Save
	if(screen_id == 2 && control_id == 13){
		if(value == 1){//按下
			R_DC_NEW_PASSCODE_SAVE_REQ = 1;	
		}
	}
	//密码修改 Back
	if(screen_id == 2 && control_id == 14){
		if(value == 1){//按下
			R_DC_NEW_PASSCODE_ABANDON_REQ = 1;				
		}
	}
}

/*
函数：on_screen_change
功能：画面切换通知，当前画面ID发生变化时执行此函数
参数：screen_id，当前画面ID
*/
void on_screen_change(int screen_id)
{
}

