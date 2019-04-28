#include "dcHmiApp.h"
/*****************************************************************************/
#define FSMSTEP_POWERUP								0//上电
//自检状态
#define FSMSTEP_CHECK_EPROM							100//单片机自检
#define FSMSTEP_CHECK_INTBUS						101//触摸屏通信自检
#define FSMSTEP_CHECK_LDR							102//激光驱动器自检
#define FSMSTEP_CHECK_TEMPER						103//温度自检
#define FSMSTEP_CHECK_USBHOST						104//USBHOST模块自检
#define FSMSTEP_CHECK_NFC							105//NFC模块自检
#define FSMSTEP_CHECK_NRF24L01						106//无线脚踏RF自检
//密码输入状态
#define FSMSTEP_PASSCODE_INPUT						200//密码输入状态
#define FSMSTEP_PASSCODE_NEW0						201//密码更改状态第一次输入
#define FSMSTEP_PASSCODE_NEW1						202//密码更改状态第二次输入
//工作状态
#define FSMSTEP_STANDBY								300//等待状态
#define FSMSTEP_READY_LOAD_PARA						301//载入参数
#define FSMSTEP_READY_LOAD_DONE						302//载入参数完毕
#define FSMSTEP_LASER_TRIGGER						303//激光触发
#define FSMSTEP_LASER_EMITING						304//激光发射中
#define FSMSTEP_LASER_STOP							305//激光发射结束
//选项状态
#define FSMSTEP_OPTION								400//选项菜单
//
#define FSMSTEP_FAULT								-1//故障状态
/*****************************************************************************/
#if CONFIG_USING_DCHMI_APP == 1
void dcHmiLoopInit(void){//初始化模块
	NVRAM0[EM_HMI_OPERA_STEP] = 0;
}
void dcHmiLoop(void){//HMI轮训程序
	uint8_t cTemp0, cTemp1, cTemp2, cTemp3;
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
		loadScheme();//从掉电存储寄存器中恢复方案参数
		NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_EPROM;
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
		NVRAM0[EM_DC_DEFAULT_PASSCODE0] = 0x3433;//00
		NVRAM0[EM_DC_DEFAULT_PASSCODE1] = 0x3231;//00
		if((NVRAM0[DM_DC_OLD_PASSCODE0] == 0x0000) || (NVRAM0[DM_DC_OLD_PASSCODE1] = 0x0000)){
			NVRAM0[DM_DC_OLD_PASSCODE0] = 0x3433;//00
			NVRAM0[DM_DC_OLD_PASSCODE1] = 0x3231;//00
		}
		NVRAM0[EM_DC_PAGE] = 0x0;//HMI页面		
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_CHECK_EPROM){//EPROM自检步骤
		//测试FM24C64
		if(LDB(R_CHECK_EPROM_PASS) && LDB(R_CHECK_EPROM_FAIL)){
#if CONFIG_SPLC_USING_EPROM == 1
			epromWriteOneByte((CONFIG_EPROM_SIZE - 1), 0x12);//写EPROM
			epromWriteOneByte((CONFIG_EPROM_SIZE - 2), 0x34);//写EPROM
			epromWriteOneByte((CONFIG_EPROM_SIZE - 3), 0x56);//写EPROM
			epromWriteOneByte((CONFIG_EPROM_SIZE - 4), 0x78);//写EPROM
			//读EPROM
			cTemp0 = epromReadOneByte((CONFIG_EPROM_SIZE - 1));
			cTemp1 = epromReadOneByte((CONFIG_EPROM_SIZE - 2));
			cTemp2 = epromReadOneByte((CONFIG_EPROM_SIZE - 3));
			cTemp3 = epromReadOneByte((CONFIG_EPROM_SIZE - 4));
			if((cTemp0 == 0x12) && (cTemp1 == 0x34) && (cTemp2 == 0x56) && (cTemp3 == 0x78)){
				SET(R_CHECK_EPROM_PASS);
				RES(R_CHECK_EPROM_FAIL);
				NVRAM0[EM_ERROR_CODE] = ERRPR_CODE_NOERR;
			}
			else{
				RES(R_CHECK_EPROM_PASS);
				SET(R_CHECK_EPROM_FAIL);
				NVRAM0[EM_ERROR_CODE] = ERROR_CODE_EPROM;
			}
#else
			SET(R_CHECK_EPROM_PASS);
			RES(R_CHECK_EPROM_FAIL);
			NVRAM0[EM_ERROR_CODE] = ERRPR_CODE_NOERR;
#endif
		}
		if(LD(R_CHECK_EPROM_PASS)){
			T100MS(T100MS_CHECK_FLASH_DELAY, true, 3);
			if(LD(T_100MS_START * 16 + T100MS_CHECK_FLASH_DELAY)){
				T100MS(T100MS_CHECK_FLASH_DELAY, false, 3);
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_INTBUS;
				SET(R_CHECK_EPROM_DONE);
			}
			else{
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_EPROM;
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
			NVRAM0[EM_DC_PAGE] = 0x1;//HMI页面
		}
		else{
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_CHECK_NRF24L01;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_PASSCODE_INPUT){//等待输入开机密码
		if(LD(R_DC_PASSCODE_ENTER_REQ)){//进入待机界面
			if((NVRAM0[EM_DC_NEW_PASSCODE0] == NVRAM0[DM_DC_OLD_PASSCODE0] && NVRAM0[EM_DC_NEW_PASSCODE1] == NVRAM0[DM_DC_OLD_PASSCODE1]) ||
               (NVRAM0[EM_DC_NEW_PASSCODE0] == NVRAM0[EM_DC_DEFAULT_PASSCODE0] && NVRAM0[EM_DC_NEW_PASSCODE1] == NVRAM0[DM_DC_OLD_PASSCODE1])){
				NVRAM0[EM_DC_PAGE] = 3;
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;	
			}			   
			CLR(EM_DC_NEW_PASSCODE0);//清空已输入密码
			CLR(EM_DC_NEW_PASSCODE1);
			CLR(EM_DC_PASSCODE_INDEX);//清空密码显示位索引 
			RES(R_DC_PASSCODE_ENTER_REQ);
		}
		else if(LD(R_DC_PASSCODE_CHANGE_REQ)){//进入密码修改界面
			if((NVRAM0[EM_DC_NEW_PASSCODE0] == NVRAM0[DM_DC_OLD_PASSCODE0] && NVRAM0[EM_DC_NEW_PASSCODE1] == NVRAM0[DM_DC_OLD_PASSCODE1]) ||
               (NVRAM0[EM_DC_NEW_PASSCODE0] == NVRAM0[EM_DC_DEFAULT_PASSCODE0] && NVRAM0[EM_DC_NEW_PASSCODE1] == NVRAM0[DM_DC_OLD_PASSCODE1])){
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_NEW0;
				NVRAM0[EM_DC_PAGE] = 2;
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
			NVRAM0[EM_DC_PAGE] = 1;
		}
		else if(LD(R_DC_PASSCODE_BACKSPACE)){//回退密码字符 BACKSPACE
			if(NVRAM0[EM_DC_PASSCODE_INDEX] == 4){
				NVRAM0[EM_DC_NEW_PASSCODE1] &= 0xFF00;
				NVRAM0[EM_DC_PASSCODE_INDEX] = 0x3;
			}
			if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
				NVRAM0[EM_DC_NEW_PASSCODE1] &= 0x00FF;
 				NVRAM0[EM_DC_PASSCODE_INDEX] = 0x2;	
			}
			if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
 				NVRAM0[EM_DC_NEW_PASSCODE0] &= 0xFF00;	
 				NVRAM0[EM_DC_PASSCODE_INDEX] = 0x1;	
			}
			if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
 				NVRAM0[EM_DC_NEW_PASSCODE0] &= 0x00FF;
				NVRAM0[EM_DC_PASSCODE_INDEX] = 0x0;	
			}
			RES(R_DC_PASSCODE_BACKSPACE);
		}
		else{		
			NVRAM0[EM_DC_PAGE] = 1;
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_INPUT;			
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_PASSCODE_NEW0){//等待输入新密码
		if(LD(R_DC_NEW_PASSCODE_INPUT_SAVE)){//新密码输入完毕进入等待操作
			MOV(DM_DC_OLD_PASSCODE0, EM_DC_NEW_PASSCODE0);
			MOV(DM_DC_OLD_PASSCODE1, EM_DC_NEW_PASSCODE1);
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;
			RES(R_DC_NEW_PASSCODE_INPUT_SAVE);
			NVRAM0[EM_DC_PAGE] = 3;
		}
		else if(LD(R_DC_NEW_PASSCODE_INPUT_ABANDON)){//放弃新密码修改
			CLR(EM_DC_NEW_PASSCODE0);
			CLR(EM_DC_NEW_PASSCODE1);
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_PASSCODE_INPUT;
			RES(R_DC_NEW_PASSCODE_INPUT_ABANDON);
			NVRAM0[EM_DC_PAGE] = 1;
		}
		else if(LD(R_DC_NEW_PASSCODE_BACKSPACE)){//输入新密码退格
			if(NVRAM0[EM_DC_PASSCODE_INDEX] == 4){
				NVRAM0[EM_DC_NEW_PASSCODE0] &= 0xFF00;
				NVRAM0[EM_DC_PASSCODE_INDEX] = 0x3;
			}
			if(NVRAM0[EM_DC_PASSCODE_INDEX] == 3){
				NVRAM0[EM_DC_NEW_PASSCODE0] &= 0x00FF;
 				NVRAM0[EM_DC_PASSCODE_INDEX] = 0x2;	
			}
			if(NVRAM0[EM_DC_PASSCODE_INDEX] == 2){
 				NVRAM0[EM_DC_NEW_PASSCODE1] &= 0xFF00;	
 				NVRAM0[EM_DC_PASSCODE_INDEX] = 0x1;	
			}
			if(NVRAM0[EM_DC_PASSCODE_INDEX] == 1){
 				NVRAM0[EM_DC_NEW_PASSCODE1] &= 0x00FF;
				NVRAM0[EM_DC_PASSCODE_INDEX] = 0x0;	
			}	
			RES(R_DC_NEW_PASSCODE_BACKSPACE);
		}
		else{
			NVRAM0[EM_DC_PAGE] = 1;	
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
			DECS1(EM_LASER_POSWIDTH);
			RES(R_DC_STANDBY_POSWIDTH_DEC_REQ);
		}
		else if(LD(R_DC_STANDBY_NEGWIDTH_ADD_REQ)){//负脉宽增加
			if(NVRAM0[EM_LASER_NEGWIDTH] <  CONFIG_MAX_LASER_NEGWIDTH){
				ADDS1(EM_LASER_NEGWIDTH);
			}
			RES(R_DC_STANDBY_NEGWIDTH_ADD_REQ);
		}
		else if(LD(R_DC_STANDBY_NEGWIDTH_DEC_REQ)){//负脉宽减小
			DECS1(EM_LASER_NEGWIDTH);
			RES(R_DC_STANDBY_NEGWIDTH_DEC_REQ);
		}
		else if(LD(R_DC_STANDBY_RESET_REQ)){//复位能量和计时器时间
			RES(R_DC_STANDBY_RESET_REQ);
		}
		else if(LD(R_DC_STANDBY_SELECT_CH0_REQ)){//选择激光通道0
			RES(R_DC_STANDBY_SELECT_CH0_REQ);
		}
		else if(LD(R_DC_STANDBY_SELECT_CH1_REQ)){//选择激光通道1
			RES(R_DC_STANDBY_SELECT_CH0_REQ);
		}
		else if(LD(R_DC_STANDBY_SELECT_CH01_REQ)){//选择激光通道0+1
			RES(R_DC_STANDBY_SELECT_CH01_REQ);
		}
		else if(LD(R_DC_STANDBY_MODE_CW_REQ)){
			RES(R_DC_STANDBY_MODE_CW_REQ);
		}
		else if(LD(R_DC_STANDBY_MODE_SP_REQ)){
			RES(R_DC_STANDBY_MODE_SP_REQ);
		}
		else if(LD(R_DC_STANDBY_MODE_MP_REQ)){
			RES(R_DC_STANDBY_MODE_MP_REQ);
		}
		else if(LD(R_DC_STANDBY_MODE_GP_REQ)){
			RES(R_DC_STANDBY_MODE_GP_REQ);
		}
		else if(LD(R_DC_STANDBY_POSWIDTH_ADD_REQ)){
			RES(R_DC_STANDBY_POSWIDTH_ADD_REQ);
		}
		else if(LD(R_DC_STANDBY_POSWIDTH_DEC_REQ)){
			RES(R_DC_STANDBY_POSWIDTH_DEC_REQ);
		}
		else if(LD(R_DC_STANDBY_NEGWIDTH_ADD_REQ)){
			RES(R_DC_STANDBY_NEGWIDTH_ADD_REQ);
		}
		else if(LD(R_DC_STANDBY_NEGWIDTH_DEC_REQ)){
			RES(R_DC_STANDBY_NEGWIDTH_DEC_REQ);
		}
		else if(LD(R_DC_STANDBY_TIMER_ADD_REQ)){
			RES(R_DC_STANDBY_TIMER_ADD_REQ);
		}
		else if(LD(R_DC_STANDBY_TIMER_DEC_REQ)){
			RES(R_DC_STANDBY_TIMER_DEC_REQ);
		}
		else if(LD(R_DC_STANDBY_SPACE_ADD_REQ)){
			RES(R_DC_STANDBY_SPACE_ADD_REQ);
		}
		else if(LD(R_DC_STANDBY_SPACE_DEC_REQ)){
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
			if(NVRAM0[EM_LASER_POWER_CH0] < CONFIG_MAX_LASERPOWER_CH0){
				ADDS1(EM_LASER_POWER_CH0);
			}
			RES(R_DC_STANDBY_LASERPOWER0_ADD_REQ);
		}
		else if(LD(R_DC_STANDBY_LASERPOWER1_ADD_REQ)){//增大通道1激光功率
			if(NVRAM0[EM_LASER_POWER_CH1] < CONFIG_MAX_LASERPOWER_CH1){
				ADDS1(EM_LASER_POWER_CH1);
			}
			if(NVRAM0[EM_LASER_POWER_CH1] < CONFIG_MAX_LASERPOWER_CH1){
				ADDS1(EM_LASER_POWER_CH1);
			}
			RES(R_DC_STANDBY_LASERPOWER1_ADD_REQ);
		}
		else if(LD(R_DC_STANDBY_LASERPOWER0_DEC_REQ)){//减小通道0激光功率
			if(NVRAM0[EM_LASER_POWER_CH0] < CONFIG_MAX_LASERPOWER_CH0){
				DECS1(EM_LASER_POWER_CH0);
			}
			if(NVRAM0[EM_LASER_POWER_CH0] < CONFIG_MAX_LASERPOWER_CH0){
				DECS1(EM_LASER_POWER_CH0);
			}
			RES(R_DC_STANDBY_LASERPOWER0_DEC_REQ);
		}
		else if(LD(R_DC_STANDBY_LASERPOWER1_DEC_REQ)){//减小通道1激光功率
			if(NVRAM0[EM_LASER_POWER_CH1] < CONFIG_MAX_LASERPOWER_CH1){
				DECS1(EM_LASER_POWER_CH1);
			}
			if(NVRAM0[EM_LASER_POWER_CH1] < CONFIG_MAX_LASERPOWER_CH1){
				DECS1(EM_LASER_POWER_CH1);
			}
			RES(R_DC_STANDBY_LASERPOWER1_DEC_REQ);
		}
		else if(LD(R_DC_STANDBY_OPTION)){
			RES(R_DC_STANDBY_OPTION);
		}
		else if(LD(R_DC_STANDBY_READY)){
			RES(LD(R_DC_STANDBY_READY));
			//				NVRAM0[SPREG_BEEM_MODE] = BEEM_MODE_0;
//				NVRAM0[SPREG_BEEM_VOLUME] = NVRAM0[DM_BEEM_VOLUME];
//				SET(SPCOIL_BEEM_ENABLE);//打开蜂鸣器			
//				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_READY_LOAD_PARA;
		}
		else{
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_READY_LOAD_PARA){//READY
//		NVRAM0[SPREG_LASER_MODE] = NVRAM0[EM_LASER_PULSE_MODE];
//		NVRAM0[SPREG_LASER_SELECT] = NVRAM0[EM_LASER_SELECT];
//		NVRAM0[SPREG_LASER_TMATE] = NVRAM0[EM_LASER_POSWIDTH];//激光脉冲正脉宽 10mS
//		NVRAM0[SPREG_LASER_TOVERTIME] = NVRAM0[EM_LASER_POSWIDTH] + NVRAM0[EM_LASER_NEGWIDTH];//激光脉冲周期 25mS
//		NVRAM0[SPREG_LASER_PMATE] = NVRAM0[EM_LASER_GROUP];//10个脉冲
//		NVRAM0[SPREG_LASER_POVERTIME] = NVRAM0[EM_LASER_SPACE];//间隔33mS
//		PCLAR0(EM_LASER_POWER_CH0, SPREG_DAC_0);//功率->DAC CODE
//		PCLAR1(EM_LASER_POWER_CH1, SPREG_DAC_1);//功率->DAC CODE
//		T100MS(T100MS_READY_BEEM_DELAY, true, 3);//启动计时器延时500mS//打开计时器
//		//清空计时器
//		if(LD(T_100MS_START * 16 + T100MS_READY_BEEM_DELAY)){
//			T100MS(T100MS_READY_BEEM_DELAY, false, 3);
//			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_READY_LOAD_DONE;
//		}
//		else{
//			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_READY_LOAD_PARA;
//		}
//		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_READY_LOAD_DONE){//READY状态
		RES(SPCOIL_BEEM_ENABLE);//关闭蜂鸣器
		NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_LASER_TRIGGER;
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_LASER_TRIGGER){//等待触发激光
		if(LD(R_SAFE_FAULT)){
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_FAULT;	
		}
		else{
			if(LD(R_DC_STANDBY_READY)){
				if(LD(X_FOOTSWITCH_OC) && LDB(X_FOOTSWITCH_ON)){//发射激光	
					NVRAM0[SPREG_BEEM_MODE] = BEEM_MODE_1;
					NVRAM0[SPREG_BEEM_VOLUME] = NVRAM0[DM_BEEM_VOLUME];
					SET(SPCOIL_BEEM_ENABLE);//打开蜂鸣器		
					STLAR();
					NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_LASER_EMITING;	
				}		
			}
			else{
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_STANDBY;	
			}
		}
		return;
	}
	if(NVRAM0[EM_HMI_OPERA_STEP] == FSMSTEP_LASER_EMITING){//等待触发激光
		if(LD(R_SAFE_FAULT)){//发现故障
			EDLAR();
			RES(SPCOIL_BEEM_ENABLE);//打开蜂鸣器	
			RES(R_DC_STANDBY_READY);//取消准备状态
			NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_FAULT;
		}
		else{
			if(LD(X_FOOTSWITCH_OC) && LDB(X_FOOTSWITCH_ON)){//发射激光
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_LASER_EMITING;		
			}
			else{
				EDLAR();
				RES(SPCOIL_BEEM_ENABLE);//关闭蜂鸣器	
				NVRAM0[EM_HMI_OPERA_STEP] = FSMSTEP_LASER_TRIGGER;
			}
		}
	}
	return;
}

#endif