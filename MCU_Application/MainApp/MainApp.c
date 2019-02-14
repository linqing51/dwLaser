#include "MainApp.h"
/*****************************************************************************/
//C8051F020 ��ʱ�����ܶ���
//TIMER0 ->SPLC
//TIMER1 ->Modbus RTU
//TIMER2 ->UART0 Buadrate
//TIMER3 ->NO FUNCTION
//TIMER4 ->UART1 Buadrate
/*****************************************************************************/
#define DM_TOTAL_TIME_L					(DM_START + 0)
#define DM_TOTAL_TIME_H					(DM_START + 1)
/*****************************************************************************/
void sPlcBoxLedRefresh(void){//ˢ�µ�״̬
//0x81,00,01,......,84///������ɫ�Ƶ�����.AAΪ����55Ϊ��
//0x81,00,02,......,84///���ƺ�ɫ�Ƶ�����.AAΪ����55Ϊ��
//0x81,00,06,84//��ȫ��
//0x81,00,09,xx,yy,zz,84//���Ƶ�ͨ��xx�ĵƵ�����zz=0ʱ���̵ƶ���zz=01,yy=00ʱ��������zz=01,yy=01ʱ��������	
	idata uint8_t i;
	for(i = EM_DAC_0;i < EM_DAC_25;i ++){
		if((uint16_t)(NVRAM0[i]) > 0){
			SET(R_START * 16 + i - EM_DAC_0);
		}
		else{
			RES(R_START * 16 + i - EM_DAC_0);
		}
	}
	if(LDB(SPCOIL_UART1_SEND_BUSY) && LDB(R_BOX_GREEN_SENDED)){//ˢ���̵�
		NVRAM0[BOX_SEND_BFADDR + 0] = BOX_CMD_STX;
		NVRAM0[BOX_SEND_BFADDR + 1] = 0x00;
		NVRAM0[BOX_SEND_BFADDR + 2] = 0x01;
		for(i = 3;i < 28;i ++){
			if(LD(R_START * 16 + i - 3)){
				NVRAM0[BOX_SEND_BFADDR + i] = 0xAA;
			}
			else{
				NVRAM0[BOX_SEND_BFADDR + i] = 0x55;
			}			
		}
		NVRAM0[(BOX_SEND_BFADDR + BOX_SEND_LENGTH - 1)] = 0x84;
		SET(R_BOX_GREEN_SENDED);
		RES(R_BOX_RED_SENDED);		
		USEND(SPLC_UART1, BOX_SEND_BFADDR, BOX_SEND_LENGTH);//��������
	}
	if(LDB(SPCOIL_UART1_SEND_BUSY) && LDB(R_BOX_RED_SENDED)){//ˢ�º��
		NVRAM0[BOX_SEND_BFADDR + 0] = BOX_CMD_STX;
		NVRAM0[BOX_SEND_BFADDR + 1] = 0x00;
		NVRAM0[BOX_SEND_BFADDR + 2] = 0x02;
		for(i = 3;i < 28;i ++){
			if(LD(R_START * 16 + 32 + i -3)){
				NVRAM0[BOX_SEND_BFADDR + i] = 0xAA;
			}
			else{
				NVRAM0[BOX_SEND_BFADDR + i] = 0x55;
			}			
		}
		NVRAM0[(BOX_SEND_BFADDR + BOX_SEND_LENGTH - 1)] = 0x84;
		RES(R_BOX_GREEN_SENDED);
		SET(R_BOX_RED_SENDED);		
		USEND(SPLC_UART1, BOX_SEND_BFADDR, BOX_SEND_LENGTH);//��������				
	}
}
void main(void){
	initDeviceF020();
	sPlcInit();//��ʼ�����߼�
	initModbus(CONFIG_MB_RTU_SLAVE_ADDRESS, CONFIG_UART0_BAUDRATE);
	ENABLE_INTERRUPT;
	while(1){
		sPlcProcessStart();
		if(LD(SPCOIL_START_UP)){//ִ��һ�εĴ���
			RES(R_BOX_GREEN_SENDED);
			RES(R_BOX_RED_SENDED);
		}
		if(LD(T_100MS_START * 16U + 0)){//ÿ100mSִ��һ��BOX����ˢ��
			sPlcBoxLedRefresh();
			T100MS(0, false, 1);
		}
		else{
			T100MS(0, true, 1);
		}
		
//		if(LDP(SPCOIL_PS1000MS)){
//			p32 = (uint32_t*)(&NVRAM0[DM_TOTAL_TIME_L]);
//			*p32 = *p32 + 1;
//		}
		sPlcProcessEnd();
	}
}