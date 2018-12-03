#include "UART.H"
/*****************************************************************************/
static int32_t outtime;
void sendchar(uint8_t ch){//·¢ËÍ×Ö·û´«
    TI0 = 0;
	SBUF0 = ch;
	while(!TI0);
}
void sendstring(int8_t *pchar,uint16_t len){//·¢ËÍ×Ö·û´®
	uint16_t i;
	for( i=0;i< len;i++){
		sendchar(*(pchar+i));
	}
}
uint8_t revchar(void){//½ÓÊÕ×Ö·û´®
	int8_t ctemp;
	int32_t Revtime;
	Revtime	= outtime;
    while(Revtime--)
	{
		if(RI0 == 1)
		{			
			break;
		}
	}
	ctemp = SBUF0;
	RI0 = 0;
	return ctemp;
}
void setrevouttime(int32_t mtime){
	outtime = mtime;
}