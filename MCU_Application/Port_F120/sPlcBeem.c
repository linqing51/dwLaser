#include "sPlcBeem.h"
/*****************************************************************************/
void sPlcBeemInit(void){//蜂鸣器初始化
	NVRAM0[SPREG_BEEM_VOLUME] = 0;
	NVRAM0[SPREG_BEEM_MODE] = 0;
	NVRAM0[SPREG_BEEM_TCOUNTER] = 0;
	NVRAM0[SPREG_BEEM_PCOUNTER] = 0;
	NVRAM0[SPREG_BEEM_POS] = 0;
	NVRAM0[SPREG_BEEM_CYCLE] = 0;
	RES(SPCOIL_BEEM_EMITING);
	RES(SPCOIL_BEEM_EMITOVER);
}
void sPlcBeemLoop(void){//蜂鸣器轮询
	if(LD(SPCOIL_BEEM_EMITING) && (NVRAM0[SPREG_BEEM_PCOUNTER] <= NVRAM0[SPREG_BEEM_RELEASE])){
		if(NVRAM0[SPREG_BEEM_TCOUNTER] == 0){
			NVRAM1[SPREG_HPWM2_DUTYRATIO] = NVRAM0[SPREG_BEEM_VOLUME];//打开蜂鸣器		
		}
		if(NVRAM0[SPREG_BEEM_TCOUNTER] > NVRAM0[SPREG_BEEM_POS]){
			NVRAM1[SPREG_HPWM2_DUTYRATIO] = 0;//关闭蜂鸣器
		}
		if(NVRAM0[SPREG_BEEM_TCOUNTER] > NVRAM0[SPREG_BEEM_CYCLE]){
			(uint16_t)NVRAM0[SPREG_BEEM_TCOUNTER] = 0xFFFF;//计时器清零
		}
	}
	else{//计算结束
		RES(SPCOIL_BEEM_EMITING);
		SET(SPCOIL_BEEM_EMITOVER);
		NVRAM1[SPREG_HPWM2_DUTYRATIO] = 0;//关闭蜂鸣器
	}
	
}
void testBenchBeem(uint8_t volume, uint8_t mode){//蜂鸣器测试
}
void EDBEEM(void){//停止蜂鸣器
}
void STBEEM(void){//开始蜂鸣器
	if(NVRAM0[SPREG_BEEM_MODE] == BEEM_MODE_0){//模式0 CW
		
	}
	if(NVRAM0[SPREG_BEEM_MODE] == BEEM_MODE_1){//模式1 短间隔
	}
	if(NVRAM0[SPREG_BEEM_MODE] == BEEM_MODE_2){//模式2 长间隔
	}
}