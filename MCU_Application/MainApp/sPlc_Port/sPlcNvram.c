#include "sPlcNvram.h"
/*****************************************************************************/
void loadNvram(void){//��EPROM������NVRAM
	memset(NVRAM0, 0x0, (CONFIG_NVRAM_SIZE * 2));//��ʼ��NVRAM
	setLedEprom(DEBUG_LED_ON);
	epromRead(0, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));//��EPROM�лָ�MR
	setLedEprom(DEBUG_LED_OFF);
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
#if CONFIG_SPLC_USING_WDT == 1
	if ((RSTSRC & 0x02) == 0x00){
		if(RSTSRC == 0x08){//���WDT���Ź� ���Ź���λ������
			SET(SPCOIL_WATCHDOG);
			setLedError(DEBUG_LED_ON);
			setLedRun(DEBUG_LED_ON);
			setLedDac(DEBUG_LED_OFF);
			setLedEprom(DEBUG_LED_OFF);
			delayMs(100);
		}
	}
#endif
}
void clearNvram(void){//���NVRAM����	
	idata uint8_t oldEA;
	idata uint16_t i;
	oldEA = EA;//�ر��ж�
	EA = 0;
	disableWatchDog();
	for(i = 0; i<= CONFIG_EPROM_SIZE;i ++){
		if(getLedEprom()){
			setLedEprom(DEBUG_LED_OFF);
		}
		else{
			setLedEprom(DEBUG_LED_ON);
		}
		epromWriteOneByte(i, 0x0);
		
	}
	EA = oldEA;//�ָ��ж�
}
void saveNvram(void){//ǿ�ƽ�NVRAM����EPROM
	DISABLE_INTERRUPT;
	setLedEprom(DEBUG_LED_ON);
	epromWrite(0x0, (uint8_t*)NVRAM0, ((MR_END + 1) * 2));
	setLedEprom(DEBUG_LED_OFF);
	ENABLE_INTERRUPT;
}
void updataNvram(void){//����NVRAM->EPROM
	data uint8_t *sp0, *sp1;
	data uint16_t i;
	sp0 = (uint8_t*)NVRAM0;
	sp1 = (uint8_t*)NVRAM1;
	for(i = (MR_START * 2);i < ((MR_END + 1) * 2);i ++){//����MR
		if(*(sp0 + i) != *(sp1 + i)){
			setLedEprom(DEBUG_LED_ON);
			epromWriteOneByte(i, *(sp0 + i));
			setLedEprom(DEBUG_LED_OFF);
		}	
	}
	sp0 = (uint8_t*)NVRAM0;
	sp1 = (uint8_t*)NVRAM1;
	for(i = (DM_START * 2);i < ((DM_END + 1) * 2);i ++){//����DM
		if(*(sp0 + i) != *(sp1 + i)){
			setLedEprom(DEBUG_LED_ON);
			epromWriteOneByte(i, *(sp0 + i));
			setLedEprom(DEBUG_LED_OFF);
		}
	}
	memcpy((uint8_t*)NVRAM1, (uint8_t*)NVRAM0, (CONFIG_NVRAM_SIZE * 2));
}
