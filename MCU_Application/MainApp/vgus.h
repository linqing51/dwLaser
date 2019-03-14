#ifndef __VGUS_H__
#define __VGUS_H__
/*****************************************************************************/
#include "lib.h"
#include "sPlc.h"
/*****************************************************************************/
#define R_VGUS_UPLOAD_DOING					(R_START + 10)
#define R_VGUS_UPLOAD_DONE					(R_START + 11)


#define DM_VGUS_PINCODE						0//����ֵ
#define DM_VGUS_NEWPINCODE					1//������ֵ
#define DM_VGUS_BRIGHTNESS					2//��Ļ����ֵ
#define DM_VGUS_VOLUME						3//����������
#define DM_VGUS_TONE						4//����������ģʽ


#define EM_VGUS_WAVE_SEL					(EM_START + 0)//����ѡ��->100
#define EM_VGUS_MODE_SEL					(EM_START + 1)//ģʽѡ��->101
#define EM_VGUS_POWER_980					(EM_START + 2)//����->102
#define EM_VGUS_POWER_1470					(EM_START + 3)//����->103
#define EM_VGUS_PP_POS						(EM_START + 4)//������->104
#define EM_VGUS_PP_NEG						(EM_START + 5)//������->105
#define EM_VGUS_PP_SPACE					(EM_START + 6)//Ⱥ������->106
#define EM_VGUS_PP_GROUP					(EM_START + 7)//Ⱥ�������->107
#define EM_VGUS_DISP_NAME					(EM_START + 10)//9+32//��������->110-159

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


void vGusRegRead(uint8_t addr, uint8_t length);//��ȡVGUS�Ĵ���
void vGusRegWrite(uint8_t addr, uint8_t *pbuf ,uint8_t length);//д��VGUS�Ĵ���
void vGusVarRead(uint16_t addr, uint8_t length);//��ȡVGUS����
void vGusVarWrite(uint16_t addr, uint16_t *pbuf ,uint8_t length);//д��VGUS����
/*****************************************************************************/

#endif