#include "dcHmiApp.h"
/*****************************************************************************/
#define GDDC_PAGE_POWERUP							0
#define GDDC_PAGE_PASSCODE							1
#define GDDC_PAGE_NEW_PASSCODE						2
#define GDDC_PAGE_STANDBY							3
#define GDDC_PAGE_READY								4
#define GDDC_PAGE_OPTION							5//选项页面
#define GDDC_PAGE_INFO								6//信息页面
#define GDDC_PAGE_SCHEME							7//方案页面

/*****************************************************************************/

#define FSMSTEP_POWERUP								0//上电
//自检状态
#define FSMSTEP_CHECK_HMI							100//HMI自检
#define FSMSTEP_CHECK_EPROM							101//单片机自检
#define FSMSTEP_CHECK_INTBUS						102//触摸屏通信自检
#define FSMSTEP_CHECK_LDR							103//激光驱动器自检
#define FSMSTEP_CHECK_TEMPER						104//温度自检
#define FSMSTEP_CHECK_USBHOST						105//USBHOST模块自检
#define FSMSTEP_CHECK_NFC							106//NFC模块自检
#define FSMSTEP_CHECK_NRF24L01						107//无线脚踏RF自检
//密码输入状态
#define FSMSTEP_PASSCODE_INPUT						200//密码输入状态
#define FSMSTEP_PASSCODE_NEW0						201//密码更改状态第一次输入
#define FSMSTEP_PASSCODE_NEW1						202//密码更改状态第二次输入
//工作状态
#define FSMSTEP_STANDBY								300//等待状态
#define FSMSTEP_READY_LOAD_PARA						301//载入参数
#define FSMSTEP_READY_LOAD_DONE						302//载入参数完毕
#define FSMSTEP_LASER_WAIT_TRIGGER					303//激光触发
#define FSMSTEP_LASER_EMITING						304//激光发射中
#define FSMSTEP_LASER_STOP							305//激光发射结束
//选项状态
#define FSMSTEP_OPTION								400//选项菜单
//
#define FSMSTEP_INFO								500
//
#define FSMSTEP_SCHEME								600//方案菜单
//
#define FSMSTEP_FAULT								-1//故障状态
/*****************************************************************************/
#if CONFIG_USING_DCHMI_APP == 1
void dcHmiLoopInit(void){//初始化模块
	NVRAM0[EM_HMI_OPERA_STEP] = 0;
}
void dcHmiLoop(void){//HMI轮训程序
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_FAULT){//故障步骤
		if(LD(R_SAFE_FAULT)){
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_FAULT;
			SET(Y_LED_ALARM);//故障灯亮
			SET(SPCOIL_BEEM_ENABLE);//蜂鸣器常响
		}
		else{
			RES(Y_LED_ALARM);//故障灯亮
			RES(SPCOIL_BEEM_ENABLE);//蜂鸣器常响
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;
		}
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_POWERUP){//上电步骤	
#if CONFIG_DEBUG == 1
		printf("sPlc->dcHmiLoop->OPERA_STEP:FSMSTEP_POWERUP\n");
#endif
		loadScheme();//从掉电存储寄存器中恢复方案参数
		RES(R_CHECK_EPROM_DONE);
		RES(R_CHECK_INTBUS_DONE);			
		RES(R_CHECK_LDR_DONE);			
		RES(R_CHECK_TEMPER_DONE);				
		RES(R_CHECK_USBHOST_DONE);		
		RES(R_CHECK_NFC_DONE);			
		RES(R_CHECK_NRF24L01_DONE);	

		RES(R_CHECK_EPROM_PASS);				
		RES(R_CHECK_INTBUS_PASS);						
		RES(R_CHECK_LDR_PASS);						
		RES(R_CHECK_TEMPER_PASS);					
		RES(R_CHECK_USBHOST_PASS);					
		RES(R_CHECK_NFC_PASS);						
		RES(R_CHECK_NRF24L01_PASS);					

		RES(R_CHECK_EPROM_FAIL);						
		RES(R_CHECK_INTBUS_FAIL);						
		RES(R_CHECK_LDR_FAIL);						
		RES(R_CHECK_TEMPER_FAIL);						
		RES(R_CHECK_USBHOST_FAIL);					
		RES(R_CHECK_NFC_FAIL);						
		RES(R_CHECK_NRF24L01_FAIL);
		CLR(EM_DC_PAGE);
		CLR(EM_DC_PASSCODE_INDEX);
		CLR(EM_ERROR_CODE);
		CLR(EM_DC_NEW_PASSCODE0);
		CLR(EM_DC_NEW_PASSCODE0);
		
		NVRAM0[EM_DC_DEFAULT_PASSCODE0] = CONFIG_HMI_DEFAULT_PASSSWORD0;
		NVRAM0[EM_DC_DEFAULT_PASSCODE1] = CONFIG_HMI_DEFAULT_PASSSWORD1;
		//检查储存密码是否合规
		NVRAM0[TM_START + 0] = NVRAM0[DM_DC_OLD_PASSCODE0] & 0x00FF;
		NVRAM0[TM_START + 1] = (NVRAM0[DM_DC_OLD_PASSCODE0] >> 8) & 0x00FF;
		NVRAM0[TM_START + 2] = NVRAM0[DM_DC_OLD_PASSCODE1] & 0x00FF;
		NVRAM0[TM_START + 3] = (NVRAM0[DM_DC_OLD_PASSCODE1] >> 8) & 0x00FF;
		if((NVRAM0[TM_START + 0] < 0x30) || (NVRAM0[TM_START + 0] > 0x39) ||
		   (NVRAM0[TM_START + 1] < 0x30) || (NVRAM0[TM_START + 1] > 0x39) ||
		   (NVRAM0[TM_START + 2] < 0x30) || (NVRAM0[TM_START + 2] > 0x39) ||
		   (NVRAM0[TM_START + 3] < 0x30) || (NVRAM0[TM_START + 3] > 0x39)){
			NVRAM0[DM_DC_OLD_PASSCODE0] = CONFIG_HMI_DEFAULT_PASSSWORD0;
			NVRAM0[DM_DC_OLD_PASSCODE1] = CONFIG_HMI_DEFAULT_PASSSWORD1;  
		}
		RES(SPCOIL_DCHMI_RESET_REQ);
		SET(SPCOIL_DCHMI_RESET_DOING);
		RES(SPCOIL_DCHMI_RESET_DONE);

		RES(SPCOIL_DCHMI_UPDATE_REQ);
		RES(SPCOIL_DCHMI_UPDATE_DOING);
		RES(SPCOIL_DCHMO_UPDATE_DONE);
		queue_reset();//清空HMI指令接收缓冲区	
		NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_HMI;
		
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_CHECK_HMI){//等待HMI复位
		T100MS(T100MS_READY_HMI_RESET_DELAY, true, 3);
		if(LD(T_100MS_START * 16 + T100MS_READY_HMI_RESET_DELAY)){
			T100MS(T100MS_READY_HMI_RESET_DELAY, false, 3);
			RES(SPCOIL_DCHMI_RESET_DOING);
			SET(SPCOIL_DCHMI_RESET_DONE);	
			//HMI从内置FLASH中恢复设置	
			SET(SPCOIL_DCHMI_UPDATE_DOING);
			//FlashRestoreControl(FLASH_DATA_VERSION,FLASH_DATA_ADDR);
			RES(SPCOIL_DCHMI_UPDATE_DOING);
			SET(SPCOIL_DCHMO_UPDATE_DONE);
			//设置HMI页面
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_POWERUP;//HMI页面
			SetScreen(NVRAM0[EM_DC_PAGE]);
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_EPROM;
				
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_HMI;//EPROM自检失败	
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_CHECK_EPROM){//EPROM自检步骤
		//测试EPROM
#if CONFIG_SPLC_USING_EPROM == 1
		NVRAM0[TM_START + 0] = rand()%0xFF;
		NVRAM0[TM_START + 1] = rand()%0xFF;
		NVRAM0[TM_START + 2] = rand()%0xFF;
		NVRAM0[TM_START + 3] = rand()%0xFF;
		epromWriteOneByte((CONFIG_EPROM_SIZE - 1), NVRAM0[TM_START + 0]);//写EPROM
		epromWriteOneByte((CONFIG_EPROM_SIZE - 2), NVRAM0[TM_START + 1]);//写EPROM
		epromWriteOneByte((CONFIG_EPROM_SIZE - 3), NVRAM0[TM_START + 2]);//写EPROM
		epromWriteOneByte((CONFIG_EPROM_SIZE - 4), NVRAM0[TM_START + 3]);//写EPROM
		//读EPROM
		NVRAM0[TM_START + 4] = epromReadOneByte((CONFIG_EPROM_SIZE - 1));
		NVRAM0[TM_START + 5] = epromReadOneByte((CONFIG_EPROM_SIZE - 2));
		NVRAM0[TM_START + 6] = epromReadOneByte((CONFIG_EPROM_SIZE - 3));
		NVRAM0[TM_START + 7] = epromReadOneByte((CONFIG_EPROM_SIZE - 4));
		if((NVRAM0[TM_START + 0] == NVRAM0[TM_START + 4]) && (NVRAM0[TM_START + 1] == NVRAM0[TM_START + 5]) &&
		   (NVRAM0[TM_START + 2] == NVRAM0[TM_START + 6]) && (NVRAM0[TM_START + 3] == NVRAM0[TM_START + 7])){
			setLedVar(true);
			delayMs(250);
			setLedVar(false);
			delayMs(250);
			setLedVar(true);
			delayMs(250);
			setLedVar(false); 
			SET(R_CHECK_EPROM_PASS);
			NVRAM0[EM_ERROR_CODE] = ERRPR_CODE_NOERR;
		}
		else{
			setLedVar(true);
			
			SET(R_CHECK_EPROM_FAIL);
			NVRAM0[EM_ERROR_CODE] = ERROR_CODE_EPROM;
		}
#else
		SET(R_CHECK_EPROM_PASS);
		RES(R_CHECK_EPROM_FAIL);
		NVRAM0[EM_ERROR_CODE] = ERRPR_CODE_NOERR;
#endif
		if(LD(R_CHECK_EPROM_PASS) && LDB(R_CHECK_EPROM_FAIL)){
			T100MS(T100MS_CHECK_FLASH_DELAY, true, 3);
			if(LD(T_100MS_START * 16 + T100MS_CHECK_FLASH_DELAY)){
				T100MS(T100MS_CHECK_FLASH_DELAY, false, 3);
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_INTBUS;
				SET(R_CHECK_EPROM_DONE);
			}
			else{
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_EPROM;//EPROM自检失败
			}
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_EPROM;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_CHECK_INTBUS){//内部总线自检步骤
		T100MS(T100MS_CHECK_INTBUS_DELAY, true, 3);
		if(LD(T_100MS_START * 16 + T100MS_CHECK_INTBUS_DELAY)){
			T100MS(T100MS_CHECK_INTBUS_DELAY, false, 3);
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_LDR;
			SET(R_CHECK_INTBUS_DONE);
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_INTBUS;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_CHECK_LDR){//激光驱动器自检步骤
		T100MS(T100MS_CHECK_LDR_DELAY, true, 3);
		if(LD(T_100MS_START * 16 + T100MS_CHECK_LDR_DELAY)){
			T100MS(T100MS_CHECK_LDR_DELAY, false, 3);
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_TEMPER;
			SET(R_CHECK_LDR_DONE);
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_LDR;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_CHECK_TEMPER){//温度自检步骤
		T100MS(T100MS_CHECK_TEMPER_DELAY, true, 3);
		if(LD(T_100MS_START * 16 + T100MS_CHECK_TEMPER_DELAY)){
			T100MS(T100MS_CHECK_TEMPER_DELAY, false, 3);
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_USBHOST;
			SET(R_CHECK_TEMPER_DONE);
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_TEMPER;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_CHECK_USBHOST){//USBHOST自检步骤
		T100MS(T100MS_CHECK_USBHOST_DELAY, true, 3);
		if(LD(T_100MS_START * 16 + T100MS_CHECK_USBHOST_DELAY)){
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_USBHOST;
			SET(R_CHECK_USBHOST_DONE);
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_NFC;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_CHECK_NFC){//NFC自检步骤
		T100MS(T100MS_CHECK_NFC_DELAY, true, 3);
		if(LD(T_100MS_START * 16 + T100MS_CHECK_NFC_DELAY)){
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_NRF24L01;
			SET(R_CHECK_NFC_DONE);
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_NFC;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_CHECK_NRF24L01){//NRF24L01自检步骤
		T100MS(T100MS_CHECK_NRF24L01_DELAY, true, 3);
		if(LD(T_100MS_START * 16 + T100MS_CHECK_NRF24L01_DELAY)){
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_INPUT;
			SET(R_CHECK_NRF24L01_DONE);
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_PASSCODE;//HMI页面
			SetScreen(NVRAM0[EM_DC_PAGE]);
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_NRF24L01;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_PASSCODE_INPUT){//等待输入开机密码
		if(LD(R_DC_PASSCODE_ENTER_REQ)){//进入待机界面
			if(((NVRAM0[EM_DC_NEW_PASSCODE0] == NVRAM0[DM_DC_OLD_PASSCODE0] && NVRAM0[EM_DC_NEW_PASSCODE1] == NVRAM0[DM_DC_OLD_PASSCODE1])) ||
               ((NVRAM0[EM_DC_NEW_PASSCODE0] == NVRAM0[EM_DC_DEFAULT_PASSCODE0]) && (NVRAM0[EM_DC_NEW_PASSCODE1] == NVRAM0[DM_DC_OLD_PASSCODE1]))){
				NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY;
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;	
			}			   
			CLR(EM_DC_NEW_PASSCODE0);//清空已输入密码
			CLR(EM_DC_NEW_PASSCODE1);
			CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引 
			RES(R_DC_PASSCODE_ENTER_REQ);
		}
		else if(LD(R_DC_PASSCODE_CHANGE_REQ)){//进入密码修改界面
			if((NVRAM0[EM_DC_NEW_PASSCODE0] == NVRAM0[DM_DC_OLD_PASSCODE0]) && (NVRAM0[EM_DC_NEW_PASSCODE1] == NVRAM0[DM_DC_OLD_PASSCODE1])){
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_NEW0;
				NVRAM0[EM_DC_PAGE] = GDDC_PAGE_NEW_PASSCODE;
			}
			else if((NVRAM0[EM_DC_NEW_PASSCODE0] == NVRAM0[EM_DC_DEFAULT_PASSCODE0]) && (NVRAM0[EM_DC_NEW_PASSCODE1] == NVRAM0[DM_DC_OLD_PASSCODE1])){
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_NEW0;
				NVRAM0[EM_DC_PAGE] = GDDC_PAGE_NEW_PASSCODE;
			}
			CLR(EM_DC_NEW_PASSCODE0);//清空已输入密码
			CLR(EM_DC_NEW_PASSCODE1);
			CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引
			RES(R_DC_PASSCODE_CHANGE_REQ);		
		}
		else if(LD(R_DC_PASSCODE_CANCEL_REQ)){//清空密码 CANCEL
			CLR(EM_DC_NEW_PASSCODE0);//清空已输入密码
			CLR(EM_DC_NEW_PASSCODE1);
			CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引
			RES(R_DC_PASSCODE_CANCEL_REQ);
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_PASSCODE;
		}
		else if(LD(R_DC_PASSCODE_BACKSPACE_REQ)){//回退密码字符 BACKSPACE
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
			RES(R_DC_PASSCODE_BACKSPACE_REQ);
		}
		else if(LD(R_DC_PASSCODE_KEY1)){//按键1
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
			RES(R_DC_PASSCODE_KEY1);
		}
		else if(LD(R_DC_PASSCODE_KEY2)){//按键2
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
			RES(R_DC_PASSCODE_KEY2);
		}
		else if(LD(R_DC_PASSCODE_KEY3)){//按键3
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
			RES(R_DC_PASSCODE_KEY3);
		}
		else if(LD(R_DC_PASSCODE_KEY4)){//按键4
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
			RES(R_DC_PASSCODE_KEY4);
		}
		else if(LD(R_DC_PASSCODE_KEY5)){//按键5
			if(NVRAM0[EM_DC_PASSCODE_INDEX] == 0){
				NVRAM0[EM_DC_NEW_PASSCODE0] |= 0x3500;
				NVRAM0[EM_DC_PASSCODE_INDEX] = 1;
			}
			else if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
				NVRAM0[EM_DC_NEW_PASSCODE0] = EM_DC_NEW_PASSCODE0 | 0x0035;
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
			RES(R_DC_PASSCODE_KEY5);
		}
		else if(LD(R_DC_PASSCODE_KEY6)){//按键6
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
			RES(R_DC_PASSCODE_KEY6);
		}
		else if(LD(R_DC_PASSCODE_KEY7)){//按键7
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
			RES(R_DC_PASSCODE_KEY7);
		}
		else if(LD(R_DC_PASSCODE_KEY8)){//按键8
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
			RES(R_DC_PASSCODE_KEY8);
		}
		else if(LD(R_DC_PASSCODE_KEY9)){//按键9
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
			RES(R_DC_PASSCODE_KEY9);			
		}
		else if(LD(R_DC_PASSCODE_KEY0)){//按键0
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
			RES(R_DC_PASSCODE_KEY0);
		}
		else{		
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_PASSCODE;
			
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_INPUT;	
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_PASSCODE_NEW0){//等待输入新密码
		if(LD(R_DC_NEW_PASSCODE_SAVE_REQ)){//新密码输入完毕进入等待操作
			if((NVRAM0[EM_DC_PASSCODE_INDEX] >= 4) && (NVRAM0[EM_DC_NEW_PASSCODE0] != 0x0000) && (NVRAM0[EM_DC_NEW_PASSCODE0] != 0x0000)){
				MOV(DM_DC_OLD_PASSCODE0, EM_DC_NEW_PASSCODE0);
				MOV(DM_DC_OLD_PASSCODE1, EM_DC_NEW_PASSCODE1);
				FSAV();
				CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引 
				CLR(EM_DC_NEW_PASSCODE0);
				CLR(EM_DC_NEW_PASSCODE1);
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_INPUT;
				NVRAM0[EM_DC_PAGE] = GDDC_PAGE_PASSCODE;
#if CONFIG_DEBUG == 1
				printf("sPlc->dcHmiLoop->New PassCode:0x%4X,0x%4X Save!\n", NVRAM0[DM_DC_OLD_PASSCODE0], NVRAM0[DM_DC_OLD_PASSCODE1]);
#endif
			}
			else{
				CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引 
				CLR(EM_DC_NEW_PASSCODE0);
				CLR(EM_DC_NEW_PASSCODE1);
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_NEW0;
				NVRAM0[EM_DC_PAGE] = GDDC_PAGE_NEW_PASSCODE;
#if CONFIG_DEBUG == 1				
				printf("sPlc->dcHmiLoop->New PassCode Save Fail\n");
#endif
			}
			RES(R_DC_NEW_PASSCODE_SAVE_REQ);
		}
		else if(LD(R_DC_NEW_PASSCODE_ABANDON_REQ)){//放弃新密码修改
			CLR(EM_DC_NEW_PASSCODE0);
			CLR(EM_DC_NEW_PASSCODE1);
			CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引 
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_INPUT;
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_PASSCODE;
			RES(R_DC_NEW_PASSCODE_ABANDON_REQ);
		}
		else if(LD(R_DC_NEW_PASSCODE_CANCEL_REQ)){//清空已输入新密码
			CLR(EM_DC_NEW_PASSCODE0);
			CLR(EM_DC_NEW_PASSCODE1);
			CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引 	
			RES(R_DC_NEW_PASSCODE_CANCEL_REQ);
		}
		else if(LD(R_DC_NEW_PASSCODE_BACKSPACE_REQ)){//输入新密码退格
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
			RES(R_DC_NEW_PASSCODE_BACKSPACE_REQ);
		}	
		else if(LD(R_DC_NEW_PASSCODE_KEY1)){//按键1
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
			RES(R_DC_NEW_PASSCODE_KEY1);
		}
		else if(LD(R_DC_NEW_PASSCODE_KEY2)){//按键2
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
			RES(R_DC_NEW_PASSCODE_KEY2);
		}
		else if(LD(R_DC_NEW_PASSCODE_KEY3)){//按键3
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
			RES(R_DC_NEW_PASSCODE_KEY3);
		}
		else if(LD(R_DC_NEW_PASSCODE_KEY4)){//按键4
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
			RES(R_DC_NEW_PASSCODE_KEY4);
		}
		else if(LD(R_DC_NEW_PASSCODE_KEY5)){//按键5
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
			RES(R_DC_NEW_PASSCODE_KEY5);
		}
		else if(LD(R_DC_NEW_PASSCODE_KEY6)){//按键6
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
			RES(R_DC_NEW_PASSCODE_KEY6);
		}
		else if(LD(R_DC_NEW_PASSCODE_KEY7)){//按键7
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
			RES(R_DC_NEW_PASSCODE_KEY7);
		}
		else if(LD(R_DC_NEW_PASSCODE_KEY8)){//按键8
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
			RES(R_DC_NEW_PASSCODE_KEY8);
		}
		else if(LD(R_DC_NEW_PASSCODE_KEY9)){//按键9
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
			RES(R_DC_NEW_PASSCODE_KEY9);
		}
		else if(LD(R_DC_NEW_PASSCODE_KEY0)){//按键0
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
			RES(R_DC_NEW_PASSCODE_KEY0);
		}
		else{
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_NEW_PASSCODE;	
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_NEW0;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_STANDBY){//待机状态机
		if(LD(R_SAFE_FAULT)){//
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_FAULT;
		}
		else if(LD(R_DC_STANDBY_POSWIDTH_ADD_REQ)){//正脉宽增加
			if(NVRAM0[EM_LASER_POSWIDTH] <  CONFIG_MAX_LASER_POSWIDTH){
				ADDS1(EM_LASER_POSWIDTH);
			}
			RES(R_DC_STANDBY_POSWIDTH_ADD_REQ);
		}
		else if(LD(R_DC_STANDBY_POSWIDTH_DEC_REQ)){//正脉宽减小
			if(NVRAM0[EM_LASER_POSWIDTH] > CONFIG_MIN_LASER_POSWIDTH){
				DECS1(EM_LASER_POSWIDTH);
			}
			RES(R_DC_STANDBY_POSWIDTH_DEC_REQ);
		}
		else if(LD(R_DC_STANDBY_NEGWIDTH_ADD_REQ)){//负脉宽增加
			if(NVRAM0[EM_LASER_NEGWIDTH] <  CONFIG_MAX_LASER_NEGWIDTH){
				ADDS1(EM_LASER_NEGWIDTH);
			}
			RES(R_DC_STANDBY_NEGWIDTH_ADD_REQ);
		}
		else if(LD(R_DC_STANDBY_NEGWIDTH_DEC_REQ)){//负脉宽减小
			if(NVRAM0[EM_LASER_NEGWIDTH] > CONFIG_MIN_LASER_NEGWIDTH){
				DECS1(EM_LASER_NEGWIDTH);
			}
			RES(R_DC_STANDBY_NEGWIDTH_DEC_REQ);
		}
		else if(LD(R_DC_STANDBY_RESET_REQ)){//复位能量和计时器时间
			CLR(EM_DC_DISPLAY_RELEASE_TIME);
			CLR(EM_DC_DISPLAY_RELEASE_ENERGY);
			RES(R_DC_STANDBY_RESET_REQ);
		}
		else if(LD(R_DC_STANDBY_SELECT_CH0_REQ)){//选择激光通道0
			NVRAM0[EM_LASER_SELECT] = LASER_TIMER_SELECT_CH0;
			RES(R_DC_STANDBY_SELECT_CH0_REQ);
		}
		else if(LD(R_DC_STANDBY_SELECT_CH1_REQ)){//选择激光通道1
			NVRAM0[EM_LASER_SELECT] = LASER_TIMER_SELECT_CH1;
			RES(R_DC_STANDBY_SELECT_CH0_REQ);
		}
		else if(LD(R_DC_STANDBY_SELECT_CH01_REQ)){//选择激光通道0+1
			NVRAM0[EM_LASER_SELECT] = LASER_TIMER_SELECT_BOTH;
			RES(R_DC_STANDBY_SELECT_CH01_REQ);
		}
		else if(LD(R_DC_STANDBY_MODE_CW_REQ)){//选择连续模式
			NVRAM0[EM_LASER_PULSE_MODE] = LASER_TIMER_MODE_CW;
			RES(R_DC_STANDBY_MODE_CW_REQ);
		}
		else if(LD(R_DC_STANDBY_MODE_SP_REQ)){//选择单脉冲模式
			NVRAM0[EM_LASER_PULSE_MODE] = LASER_TIMER_MODE_SP;
			RES(R_DC_STANDBY_MODE_SP_REQ);
		}
		else if(LD(R_DC_STANDBY_MODE_MP_REQ)){//选择多脉冲模式
			NVRAM0[EM_LASER_PULSE_MODE] = LASER_TIMER_MODE_MP;
			RES(R_DC_STANDBY_MODE_MP_REQ);
		}
		else if(LD(R_DC_STANDBY_MODE_GP_REQ)){//选择可编程脉冲模式
			NVRAM0[EM_LASER_PULSE_MODE] = LASER_TIMER_MODE_GP;
			RES(R_DC_STANDBY_MODE_GP_REQ);
		}
		else if(LD(R_DC_STANDBY_GROUP_ADD_REQ)){//可编程脉冲数增加
			if(NVRAM0[DM_LASER_GROUP] < CONFIG_MAX_LASER_GROUP){
				ADDS1(DM_LASER_GROUP);
			}
			RES(R_DC_STANDBY_GROUP_ADD_REQ);
		}
		else if(LD(R_DC_STANDBY_GROUP_DEC_REQ)){//可编程脉冲数减小
			if(NVRAM0[DM_LASER_GROUP] > CONFIG_MIN_LASER_GROUP){
				DECS1(DM_LASER_GROUP);
			}
			RES(R_DC_STANDBY_GROUP_DEC_REQ);
		}
		else if(LD(R_DC_STANDBY_SPACE_ADD_REQ)){//可编程脉冲间隔增加
			if(NVRAM0[EM_LASER_SPACE] > CONFIG_MAX_LASER_SPACE){
				ADDS1(EM_LASER_SPACE);
			}
			RES(R_DC_STANDBY_SPACE_ADD_REQ);
		}
		else if(LD(R_DC_STANDBY_SPACE_DEC_REQ)){//可编程脉冲间隔减小
			if(NVRAM0[EM_LASER_SPACE] < CONFIG_MIN_LASER_SPACE){
				DECS1(EM_LASER_SPACE);
			}
			RES(R_DC_STANDBY_SPACE_DEC_REQ);
		}
		else if(LD(R_DC_STANDBY_SCHEME_SAVE_REQ)){//当前设定储存请求
			BCPY((DM_SCHEME_START_0 + 25 * NVRAM0[DM_SCHEME_NUM]), EM_LASER_SCHEME_NAME, 25); 
			RES(R_DC_STANDBY_SCHEME_SAVE_REQ);
		}
		else if(LD(R_DC_STANDBY_LASERPOWER0_ADD_REQ)){//增大通道0激光功率
			if(NVRAM0[EM_LASER_POWER_CH0] < CONFIG_MAX_LASERPOWER_CH0){
				ADDS1(EM_LASER_POWER_CH0);
			}
			RES(R_DC_STANDBY_LASERPOWER0_ADD_REQ);
		}
		else if(LD(R_DC_STANDBY_LASERPOWER1_ADD_REQ)){//增大通道1激光功率
			if(NVRAM0[EM_LASER_POWER_CH1] < CONFIG_MAX_LASERPOWER_CH1){
				ADDS1(EM_LASER_POWER_CH1);
			}
			RES(R_DC_STANDBY_LASERPOWER1_ADD_REQ);
		}
		else if(LD(R_DC_STANDBY_LASERPOWER0_DEC_REQ)){//减小通道0激光功率
			if(NVRAM0[EM_LASER_POWER_CH0] < CONFIG_MAX_LASERPOWER_CH0){
				DECS1(EM_LASER_POWER_CH0);
			}
			RES(R_DC_STANDBY_LASERPOWER0_DEC_REQ);
		}
		else if(LD(R_DC_STANDBY_LASERPOWER1_DEC_REQ)){//减小通道1激光功率
			if(NVRAM0[EM_LASER_POWER_CH1] < CONFIG_MAX_LASERPOWER_CH1){
				DECS1(EM_LASER_POWER_CH1);
			}
			RES(R_DC_STANDBY_LASERPOWER1_DEC_REQ);
		}
		else if(LD(R_DC_STANDBY_OPTION)){//选择选项界面
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_OPTION;
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_OPTION;
			RES(R_DC_STANDBY_OPTION);
		}
		else if(LD(R_DC_STANDBY_LAST_SCHEME)){//选择上一个方案
			if(NVRAM0[DM_SCHEME_NUM] > 0){
				DECS1(DM_SCHEME_NUM);
				BCPY(EM_LASER_SCHEME_NAME, (DM_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 25), 25);//DM->EM
			}
			RES(R_DC_STANDBY_LAST_SCHEME);
		}
		else if(LD(R_DC_STANDBY_NEXT_SCHEME)){//选择下一个方案
			if(NVRAM0[DM_SCHEME_NUM] < CONFIG_HMI_SCHEME_NUM){
				ADDS1(DM_SCHEME_NUM);
				BCPY(EM_LASER_SCHEME_NAME, (DM_SCHEME_START_0 + NVRAM0[DM_SCHEME_NUM] * 25), 25);//DM->EM
			}
			RES(R_DC_STANDBY_NEXT_SCHEME);
		}
		else if(LD(R_DC_STANDBY_READY)){//点击READY
			
			NVRAM0[SPREG_BEEM_MODE] = BEEM_TIMER_MODE_0;
			NVRAM0[SPREG_BEEM_VOLUME] = NVRAM0[DM_BEEM_VOLUME];
			SET(SPCOIL_BEEM_ENABLE);//打开蜂鸣器			
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_READY_LOAD_PARA;
			RES(LD(R_DC_STANDBY_READY));
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_READY_LOAD_PARA){//将发射参数载入运行寄存器并打开蜂鸣器
		NVRAM0[SPREG_LASER_MODE] = NVRAM0[EM_LASER_PULSE_MODE];
		NVRAM0[SPREG_LASER_SELECT] = NVRAM0[EM_LASER_SELECT];
		NVRAM0[SPREG_LASER_TMATE] = NVRAM0[EM_LASER_POSWIDTH];//激光脉冲正脉宽 10mS
		NVRAM0[SPREG_LASER_TOVERTIME] = NVRAM0[EM_LASER_POSWIDTH] + NVRAM0[EM_LASER_NEGWIDTH];//激光脉冲周期 25mS
		NVRAM0[SPREG_LASER_PMATE] = NVRAM0[EM_LASER_GROUP];//10个脉冲
		NVRAM0[SPREG_LASER_POVERTIME] = NVRAM0[EM_LASER_SPACE];//间隔33mS
		PCLAR0(EM_LASER_POWER_CH0, SPREG_DAC_0);//功率->DAC CODE
		PCLAR1(EM_LASER_POWER_CH1, SPREG_DAC_1);//功率->DAC CODE
		T100MS(T100MS_READY_BEEM_DELAY, true, 3);//启动计时器延时500mS//打开计时器
		//清空计时器
		if(LD(T_100MS_START * 16 + T100MS_READY_BEEM_DELAY)){
			T100MS(T100MS_READY_BEEM_DELAY, false, 3);
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_READY_LOAD_DONE;
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_READY_LOAD_PARA;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_READY_LOAD_DONE){//参数载入完毕并停止蜂鸣器
		RES(SPCOIL_BEEM_ENABLE);//关闭蜂鸣器
		NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_LASER_WAIT_TRIGGER;
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_LASER_WAIT_TRIGGER){//等待触发激光
		if(LD(R_SAFE_FAULT)){
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_FAULT;	
		}
		else if(LDB(R_DC_STANDBY_READY)){//回到等待状态
			
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;
			NVRAM0[EM_DC_PAGE] = GDDC_PAGE_STANDBY;//切换待机页面
		}
		else if(LD(X_FOOTSWITCH_OC) && LDB(X_FOOTSWITCH_ON)){//发射激光	
			NVRAM0[SPREG_BEEM_MODE] = BEEM_TIMER_MODE_1;
			NVRAM0[SPREG_BEEM_VOLUME] = NVRAM0[DM_BEEM_VOLUME];
			SET(SPCOIL_BEEM_ENABLE);//打开蜂鸣器	
#if CONFIG_SPLC_USING_LASER_TIMER == 1			
			STLAR();
#endif
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_LASER_EMITING;	
		}		
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;	
		}
		return;
	}
//	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_LASER_EMITING){//发激光中
//		if(LD(R_SAFE_FAULT)){//发现故障
//			EDLAR();
//			RES(SPCOIL_BEEM_ENABLE);//打开蜂鸣器	
//			RES(R_DC_STANDBY_READY);//取消准备状态
//			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_FAULT;
//		}
//		else if(LD(X_FOOTSWITCH_OC) && LDB(X_FOOTSWITCH_ON)){//发射激光
//			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_LASER_EMITING;		
//		}
//		else{
//			EDLAR();
//			RES(SPCOIL_BEEM_ENABLE);//关闭蜂鸣器	
//			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_LASER_WAIT_TRIGGER;
//		}
//		return;
//	}
//	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_OPTION){//选项界面
//		if(LD(R_DC_OPTION_BEEM_TONE)){//声光同步
//			RES(R_DC_OPTION_BEEM_TONE);
//		}
//		else if(LD(R_DC_OPTION_AIM_ON)){
//			RES(R_DC_OPTION_AIM_ON);
//		}
//		else if(LD(R_DC_OPTION_RETURN_REQ)){
//			RES(R_DC_OPTION_RETURN_REQ);
//		}
//		else if(LD(R_DC_OPTION_SCHEME_REQ)){
//			RES(R_DC_OPTION_SCHEME_REQ);
//		}
//		else if(LD(R_DC_OPTION_INFO_REQ)){
//			RES(R_DC_OPTION_INFO_REQ);
//		}
//		else{
//		}
//		return;
//	}
	if(LDB(SPCOIL_DCHMI_RESTORE_DOING) && LD(SPCOIL_DCHMI_RESTORE_DONE)){//HMI复位完成后处理串口指令
		NVRAM0[SPREG_HMI_CMDSIZE] = queue_find_cmd(hmiCmdBuffer, CMD_MAX_SIZE);//从缓冲区中获取一条指令         
        if(NVRAM0[SPREG_HMI_CMDSIZE] > 0){//接收到指令及判断是否为开机提示                                                            
            ProcessMessage((PCTRL_MSG)hmiCmdBuffer, NVRAM0[SPREG_HMI_CMDSIZE]);//指令处理  
        }                                                                             
        if(LDP(SPCOIL_PS100MS) && LD(SPCOIL_DCHMI_UPDATE_REQ)){//每100mS刷新一次UI
            RES(SPCOIL_DCHMI_UPDATE_REQ);   
            UpdateUI();
        } 
	}
}

#endif