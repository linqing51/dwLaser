#include "MainApp.h"
#include "vGus.h"
//#include "sPlcTest.h"
/*****************************************************************************/
////C8051F020 �����ʱ�����ܶ���
////TIMER0 ->SPLC_FRAME
////TIMER1 ->
////TIMER2 ->UART0 Buadrate
//<<<<<<< HEAD
////TIMER3 ->Modbus RTU TIMER
//=======
////TIMER3 ->NO FUNCTION
//>>>>>>> MCFCL_25MP
////TIMER4 ->UART1 Buadrate
////C8051F580 ��ʱ�����ܶ���
////TIMER0 ->SPLC_FRAME
////TIMER1 ->UART1 Baud Rate Generator
////TIMER2 ->SPLC_LASER
////TIMER3 ->MODBUS RTU TIMER
////TIMER4 ->EXT TIMER OUT
////TIMER5 ->BEEM
///*****************************************************************************/
//#define DM_TOTAL_TIME_L					(DM_START + 0)
//#define DM_TOTAL_TIME_H					(DM_START + 1)
/*****************************************************************************/
//<<<<<<< HEAD
//#define ENUM_MODE_CW					0//����ģʽ
//#define ENUM_MODE_SP					1//������ģʽ
//#define ENUM_MODE_MP					2//������ģʽ
//#define ENUM_MODE_GP					3//Ⱥ����ģʽ
//#define ENUM_MODE_CC					4//У��ģʽ
///*****************************************************************************/
///*****************************************************************************/
//#define STEPNUM_FAULT					-1//����
//#define STEPNUM_INIT					0//��ʼ��
//#define STEPNUM_STANDBY					1//����
//#define STEPNUM_INTO_READY				2//����׼��
//#define STEPNUM_READY					3//׼��
//#define STEPNUM_LASERON					4//���⿪ʼ

#define DM_VGUS_PINCODE						0//����ֵ
#define DM_VGUS_NEWPINCODE					1//������ֵ
#define DM_VGUS_BRIGHTNESS					2//��Ļ����ֵ
#define DM_VGUS_VOLUME						3//����������
#define DM_VGUS_TONE						4//����������ģʽ


#define EM_VGUS_WAVE_SEL					0//����ѡ��->100
#define EM_VGUS_MODE_SEL					1//ģʽѡ��->101
#define EM_VGUS_POWER_980					2//����->102
#define EM_VGUS_POWER_1470					3//����->103
#define EM_VGUS_PP_POS						4//������->104
#define EM_VGUS_PP_NEG						5//������->105
#define EM_VGUS_PP_SPACE					6//Ⱥ������->106
#define EM_VGUS_PP_GROUP					7//Ⱥ�������->107
#define EM_VGUS_DISP_NAME					10//9+32//��������->110-159

#define EM_VGUS_DISP_ENERGY					40//32bit ->110
#define EM_VGUS_DISP_TIME					42//32bit ->112
#define EM_VGUS_DISP_WARNING				50//32Byte ->300

#define DM_SCHEME_0							0
#define DM_SCHEME_1							40
#define DM_SCHEME_2							80
#define DM_SCHEME_3							120
#define DM_SCHEME_4							160
#define DM_SCHEME_5							200
#define DM_SCHEME_6							240
#define DM_SCHEME_7							280
#define DM_SCHEME_8							320
#define DM_SCHEME_9							360//40
#define DM_SCHEME_10						360//40
#define DM_SCHEME_11						360//40
#define DM_SCHEME_12						360//40
#define DM_SCHEME_13						360//40
#define DM_SCHEME_14						360//40
#define DM_SCHEME_15						360//40

#define R_VGUS_READY
#define R_VGUS_SAVE
#define R_VGUS_DISP_RESET
bit debugLed0, debugLed1, debugLed2, debugLed3;
void main(void){
	initDevice();
	sPlcInit();//��ʼ�����߼�
	URECV(UART1, (6 + 1));
	vGusRegRead(0, 1);
	
	while(1){
		
		debugLed0 = ~debugLed0;
		sPlcProcessStart();
		//debugLed0 = false;
	
		//debugLed1 = true;
		if(LD(SPCOIL_START_UP)){//ִ��һ�εĴ���
		
		}
		//debugLed1 = false;

#if CONFIG_SPLC_FUNTEST == 1
		//sPlcTest();
#endif
		
		//debugLed2 = true;
		sPlcProcessEnd();
		//debugLed2 = false;
	}
}


