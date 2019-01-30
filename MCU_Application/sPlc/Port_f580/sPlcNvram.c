#include "sPlcNvram.h"
/*****************************************************************************/
void loadNvram(void){//从EPROM中载入NVRAM
	//判断EPROM是否存在
#if CONFIG_SPLC_USING_EPROM == 1
	uint8_t sPlcDev[2];
	epromRead((CONFIG_EPROM_SIZE - 2), sPlcDev, 2);//从EPROM中恢复MR
	if((sPlcDev[0] == (CONFIG_SPLC_DEV & 0xFF)) && (sPlcDev[1] == ((CONFIG_SPLC_DEV >> 8) && 0xFF))){//EPROM 校验码正确
		RES(SPCOIL_NVRAM_FAIL);
		memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//初始化NVRAM
		SET_LED_EPROM(DEBUG_LED_ON);
		epromRead(0, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));//从EPROM中恢复MR
		SET_LED_EPROM(DEBUG_LED_OFF);
		clearEM();
		clearR();
		clearT();
		clearTD();
		clearC();
		clearX();
		clearY();
		clearSPREG();
		clearSPCOIL();
		memcpy(NVRAM1, NVRAM0, (CONFIG_NVRAM_SIZE * 2));
	}
	else{//校验码错误
		clearNvram();//清空EPROM
		epromWriteOneByte((CONFIG_EPROM_SIZE - 2), (uint8_t)(CONFIG_SPLC_DEV & 0xFF));
		epromWriteOneByte((CONFIG_EPROM_SIZE - 1), (uint8_t)((CONFIG_SPLC_DEV >> 8) & 0xFF));
		SET(SPCOIL_NVRAM_FAIL);
	}
#endif
}
void clearNvram(void){//清除NVRAM数据	
	idata uint8_t oldEA;
	idata uint16_t i;
	oldEA = EA;//关闭中断
	EA = 0;
	disableWatchDog();
	for(i = 0; i<= CONFIG_EPROM_SIZE;i ++){
		SET_LED_EPROM(DEBUG_LED_ON);
		epromWriteOneByte(i, 0x0);
		SET_LED_EPROM(DEBUG_LED_OFF);
	}
	EA = oldEA;//恢复中断
}
void saveNvram(void){//强制将NVRAM存入EPROM
	DISABLE_INTERRUPT;
	SET_LED_EPROM(DEBUG_LED_ON);
	epromWrite(0x0, (uint8_t*)NVRAM0, ((MR_END + 1) * 2));
	SET_LED_EPROM(DEBUG_LED_OFF);
	ENABLE_INTERRUPT;
}
void updataNvram(void){//更新NVRAM->EPROM
	data uint8_t *sp0, *sp1;
	data uint16_t i;
	sp0 = (uint8_t*)NVRAM0;
	sp1 = (uint8_t*)NVRAM1;
	for(i = (MR_START * 2);i < ((MR_END + 1) * 2);i ++){//储存MR
		if(*(sp0 + i) != *(sp1 + i)){
			SET_LED_EPROM(DEBUG_LED_ON);
			epromWriteOneByte(i, *(sp0 + i));
			SET_LED_EPROM(DEBUG_LED_OFF);
		}	
	}
	sp0 = (uint8_t*)NVRAM0;
	sp1 = (uint8_t*)NVRAM1;
	for(i = (DM_START * 2);i < ((DM_END + 1) * 2);i ++){//储存DM
		if(*(sp0 + i) != *(sp1 + i)){
			SET_LED_EPROM(DEBUG_LED_ON);
			epromWriteOneByte(i, *(sp0 + i));
			SET_LED_EPROM(DEBUG_LED_OFF);
		}
	}
	memcpy((uint8_t*)NVRAM1, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));
}
