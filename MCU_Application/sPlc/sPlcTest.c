#include "sPlcTest.h"
//÷∏¡Ó≤‚ ‘≥Ã–Ú
#if CONFIG_SPLC_FUNTEST == 1
static void sPlcTest_XTAB(void){
	//ÃÓ≥‰X÷·
	int16_t srcX, distY, length;
	NVRAM0[EM_START + 0] = 100;
	NVRAM0[EM_START + 1] = 440;
	NVRAM0[EM_START + 2] = 1126;
	NVRAM0[EM_START + 3] = 1531;
	NVRAM0[EM_START + 4] = 1901;
	NVRAM0[EM_START + 5] = 2523;
	NVRAM0[EM_START + 6] = 3208;
	NVRAM0[EM_START + 7] = 4503;
	NVRAM0[EM_START + 8] = 5327;
	NVRAM0[EM_START + 9] = 6909;
	//ÃÓ≥‰Y÷·
	NVRAM0[EM_START + 10] = 1101;
	NVRAM0[EM_START + 11] = 1442;
	NVRAM0[EM_START + 12] = 11123;
	NVRAM0[EM_START + 13] = 11501;
	NVRAM0[EM_START + 14] = 11901;
	NVRAM0[EM_START + 15] = 12523;
	NVRAM0[EM_START + 16] = 13205;
	NVRAM0[EM_START + 17] = 14507;
	NVRAM0[EM_START + 18] = 15329;
	NVRAM0[EM_START + 19] = 16901;
	
	srcX = 3343;
	length = 10;
	XTAB(&distY, &srcX, (NVRAM0 + EM_START + 0), &length);
}
void sPlcTest_YTAB(void){
	
}
void sPlcTest_TNTC(void){
}
	
void sPlcTest_TENV(void){
}

void sPlcTest(void){
	sPlcTest_XTAB();
}

#endif