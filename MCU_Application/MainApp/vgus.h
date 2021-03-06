#ifndef __VGUS_H__
#define __VGUS_H__
/*****************************************************************************/
#include "lib.h"
#include "sPlc.h"
/*****************************************************************************/
#define T100MS_VGUS_OVERTIME				0//VGUS 接收超时
#define T100MS_VGUS_POWERON					1//VGUS 上电超时
#define T100MS_VGUS_INIT					2//VGUS 初始化超时
#define R_VGUS_POWERON_DOING				(R_START * 16 + 0)//上电进行中
#define R_VGUS_POWERON_DONE					(R_START * 16 + 1)//上电完成
#define R_VGUS_INIT_DOING					(R_START * 16 + 2)//初始化进行中
#define R_VGUS_INIT_DONE					(R_START * 16 + 3)//初始化完成
#define R_VGUS_UPLOAD_DOING					(R_START * 16 + 4)//上传进行中
#define R_VGUS_UPLOAD_DONE					(R_START * 16 + 5)//上传完成
#define R_VGUS_DOWNLOAD_DOING				(R_START * 16 + 6)//下载进行中
#define R_VGUS_DOWNLOAD_DONE				(R_START * 16 + 7)//下载完成

#define DM_VGUS_PINCODE						0//密码值
#define DM_VGUS_NEWPINCODE					1//新密码值
#define DM_VGUS_BRIGHTNESS					2//屏幕亮度值
#define DM_VGUS_VOLUME						3//蜂鸣器音量
#define DM_VGUS_TONE						4//蜂鸣器声音模式


#define EM_VGUS_WAVE_SEL					(EM_START + 0)//波长选择->100
#define EM_VGUS_MODE_SEL					(EM_START + 1)//模式选择->101
#define EM_VGUS_POWER_980					(EM_START + 2)//功率->102
#define EM_VGUS_POWER_1470					(EM_START + 3)//功率->103
#define EM_VGUS_PP_POS						(EM_START + 4)//正脉宽->104
#define EM_VGUS_PP_NEG						(EM_START + 5)//负脉宽->105
#define EM_VGUS_PP_SPACE					(EM_START + 6)//群脉冲间隔->106
#define EM_VGUS_PP_GROUP					(EM_START + 7)//群脉冲个数->107
#define EM_VGUS_DISP_NAME					(EM_START + 10)//9+32//方案名称->110-159

#define EM_VGUS_DISP_ENERGY					40//32bit ->110
#define EM_VGUS_DISP_TIME					42//32bit ->112
#define EM_VGUS_DISP_WARNING				50//32Byte ->300

#define EM_VGUS_QUEUE		 				500//vGus读写队列

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

void vGusRegRead(uint8_t addr, uint8_t length);//读取VGUS寄存器
void vGusRegWrite(uint8_t addr, uint8_t *pbuf ,uint8_t length);//写入VGUS寄存器
void vGusVarRead(uint16_t addr, uint8_t length);//读取VGUS变量
void vGusVarWrite(uint16_t addr, int16_t dat);//写入VGUS变量
void vGusInit(void);//vGus初始化
void vGusWaitPowerOn(void);//等待vGus上电
void vGusUpload(void);
void vGusDownload(void);
void vGusLoop(void);//vGus轮询
/*****************************************************************************/

#endif