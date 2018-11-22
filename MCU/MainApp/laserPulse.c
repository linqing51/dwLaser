#include "MainApp.h"
/*****************************************************************************/
sbit LaserMod_PIN						= P0^6;
/*****************************************************************************/
myDevice_t myDevice;
/*****************************************************************************/
#define ENUM_CHANNEL1					4321
#define ENUM_CHANNEL2					8765
#define ENUM_CHANNEL_BOTH				9431
#define ENUM_MODE_CW					7631//连续模式
#define ENUM_MODE_SP					8934//单脉冲模式
#define ENUM_MODE_MP					2453//多脉冲模式
#define ENUM_MODE_GP					3876//群脉冲模式
#define ENUM_MODE_CC					14563//校正模式
#define LASER_OFF						1
#define LASER_ON						0
#define LED_OFF							1
#define LED_ON							0
//code char *LOOPTEST 					= "Hello World Power BOARD!";//测试回环
//定义R寄存器地址
code char *R_LASER_POSWIDTH				= "R03002";//激光正脉宽设定
code char *R_LASER_NEGWIDTH 			= "R03003";//激光负脉宽设定
code char *R_LASER_GROUP_SPACE			= "R03004";//群脉冲间隔
code char *R_LASER_GROUP_NUM 			= "R03005";//群脉冲个数
code char *R_LASER_MODE					= "R03006";//发射模式
code char *R_LASER_SELECT				= "R03007";//通道选择
code char *R_SETCUR_CH1		 			= "R03198";//激光通道1电流设定
code char *R_SETCUR_CH2 				= "R03199";//激光通道2电流设定
code char *W_VERSION					= "R03200";//板卡固件版本
code char *W_IPID_OUT					= "R03201";//IPID输出值	
code char *W_LASER_T					= "R03202";//激光器温度	NTC0
code char *W_RADIATOR_T	 				= "R03203";//散热器温度	NTC1
code char *W_ENVI_T						= "R03204";//板卡温度	TMCU
code char *W_PHOTODIODE_CH1				= "R03205";//PD1测量值	mV
code char *W_PHOTODIODE_CH2				= "R03206";//PD2测量值  mV
//定义D寄存器地址
code char *R_IPID_KP					= "D00002";//IPID 参数KP 比例增益
code char *R_IPID_TI					= "D00003";//IPID 参数TI积分时间
code char *R_IPID_TD					= "D00004";//IPID 参数TD微分时间
code char *R_IPID_TS					= "D00005";//IPID 参数TS采样周期
code char *R_IPID_REFT					= "D00005";//IPID 参数目标温度
code char *R_FAN_V						= "D00006";//风扇转速设定 0-4095
code char *R_AIM_VOLTAGE				= "D00007";//指示激光亮度
code char *R_BEEM_VOLUME				= "D00008";//蜂鸣器音量
//定义M寄存器地址
code char *W_FLAG_MCUHEART				= "M0001";//反馈到PLC心跳
code char *R_MCU_RESET					= "M0003";//PLC复位MCU
code char *R_BEEM_ENABLE				= "M0004";//蜂鸣器使能
code char *W_FIBER_SENSOR_CH1			= "M0005";//激光器通道0光纤报警
code char *W_FIBER_SENSOR_CH2			= "M0006";//激光器通道1光纤报警
code char *W_COOL_ENABLE				= "M0029";//制冷输出MCU
code char *R_FLAG_LASER_START 			= "M0034";//激光开始发射标志
code char *W_FLAG_LASER_INDICATE		= "M0035";//激光发射完毕标志
code char *R_LASER_READY				= "M0050";//准备状态
/*****************************************************************************/
void startLaser(myDevice_t *p);
void stopLaser(myDevice_t *p);
void SetLaserCurrent(myDevice_t *p) reentrant;
void Timer1_Init(void);
void Timer2_Init(void);
/*****************************************************************************/

static void Timer2_Init(void)
{//TIMER2 初始化
	int8_t SFRPAGE_save = SFRPAGE;	
	uint16_t temp;
	SFRPAGE = ACTIVE_PAGE;
	TMR2CN = 0x0;
	temp = (uint16_t)(0xFFFF - (CONFIG_TIMER2_OVERFLOW_US * (CONFIG_SYSCLK / 1000000L)));
	TMR2RLH = (uint8_t)((temp >> 8) & 0xff);
	TMR2RLL = (uint8_t)(temp & 0xff);
	TF2H = 0;//Timer 2 High Byte Overflow Flag.
	TF2L = 0;//Timer 2 Low Byte Overflow Flag.	
	ET2 = 0;
	TR2 = 0;//使能TIMER2计时器
	SFRPAGE = SFRPAGE_save;
}

void Timer2_ISR(void) interrupt INTERRUPT_TIMER2
{//TIMER2 中断 激光发射
	data myDevice_t *p = &myDevice;
	data int8_t SFRPAGE_save = SFRPAGE;
	SFRPAGE = ACTIVE_PAGE;
	TF2H = 0;
	SFRPAGE = SFRPAGE_save;
	switch(p->LaserMode)
	{
		case ENUM_MODE_CC:
		{//CC模式
			SetLaserCurrent(p);
			break;
		}
		case ENUM_MODE_SP:
		{//SP模式
			break;
		}
		case ENUM_MODE_MP:
		{//MP模式	
			if(p->softTimer.tCounter == p->softTimer.tMate)
			{//计时器匹配
				LaserMod_PIN = LASER_OFF;//翻转输出
			}
			if(p->softTimer.tCounter == p->softTimer.tOverflow)
			{//计时器溢出
				p->softTimer.tCounter = 0;//清零
			}
			if(p->softTimer.tCounter == 0)
			{//翻转
				LaserMod_PIN = LASER_ON;//翻转输出
			}
			p->softTimer.tCounter ++;
			break;
		}
		case ENUM_MODE_GP:
		{//GP模式
			if(p->softTimer.pCounter < p->softTimer.pMate)
			{
				if(p->softTimer.tCounter == 0)
				{
					if(p->softTimer.pCounter < p->softTimer.pMate)
					{
						LaserMod_PIN = LASER_ON;//翻转输出						
					}
				}
				if(p->softTimer.tCounter == p->softTimer.tMate)
				{//计时器匹配
					LaserMod_PIN = LASER_OFF;//翻转输出
				}
				if(p->softTimer.tCounter == (p->softTimer.tOverflow - 1))
				{//计时器溢出
					p->softTimer.tCounter = 0xFFFF;//清零
					p->softTimer.pCounter ++;//清零	
				}
				p->softTimer.tCounter ++;
			}
			if(p->softTimer.pCounter == p->softTimer.pMate && p->softTimer.tCounter == 0)
			{//脉冲个数发现匹配
				LaserMod_PIN = LASER_OFF;
				p->softTimer.pCounter = 0xFFFF;
				p->softTimer.sCounter = 0x0;
			}
			if(p->softTimer.pCounter == 0xFFFF)
			{		
				if(p->softTimer.sCounter == p->softTimer.sMate)
				{
					p->softTimer.pCounter = 0;	
				}
				p->softTimer.sCounter ++;
			}
			break;
		}
		default:break;
	}
}

void initLaserPulse(void)
{//初始化LaserPulse
}

void setLaserCurrent(myDevice_t *p) reentrant
{//设定激光器电流值
	if(p->SelectChannel == ENUM_CHANNEL1)
	{
		//ad5621_write(AD5621_LASER_CH1, p->LaserCurrent[0]);
	}
	else if(myDevice.SelectChannel == ENUM_CHANNEL2)
	{
		//ad5621_write(AD5621_LASER_CH2, p->LaserCurrent[1]);
	}
	else if(p->SelectChannel == ENUM_CHANNEL_BOTH)
	{
		//ad5621_write(AD5621_LASER_CH1, p->LaserCurrent[0]);
		//ad5621_write(AD5621_LASER_CH2, p->LaserCurrent[1]);
	}
} 

void startLaser(myDevice_t *p)
{//开始发射脉冲	
	data int8_t SFRPAGE_save = SFRPAGE;
	if(p->LaserMode == ENUM_MODE_CW)
	{
		SetLaserCurrent(p);
		LaserMod_PIN = LASER_ON;
	}
	else if((p->LaserMode == ENUM_MODE_SP) | 
			(p->LaserMode == ENUM_MODE_MP) |
			(p->LaserMode == ENUM_MODE_GP))
	{
		p->softTimer.tMate = p->PosWidth;//设置匹配值
		p->softTimer.tOverflow = p->NegWidth + p->PosWidth;//设置溢出值
		p->softTimer.tCounter = 0x0;	
		p->softTimer.pMate = 0x0;//脉冲个数匹配值
		p->softTimer.sMate = 0x0;//脉个数溢出值
		p->softTimer.pCounter = 0x0;
		p->softTimer.sCounter = 0x0;
		SFRPAGE = ACTIVE_PAGE;	
		TF2H = 0;//Timer 2 High Byte Overflow Flag.
		ET2 = 1;
		SetLaserCurrent(p);
		TMR2L = 0xFF;
		TMR2H = 0xFF;
		TR2 = 1;//使能TIMER2计时器
		SFRPAGE = SFRPAGE_save;
	}
	else if(p->LaserMode == ENUM_MODE_CC)
	{//校正模式
		p->softTimer.tMate = p->PosWidth;//设置匹配值
		p->softTimer.tOverflow = p->NegWidth + p->PosWidth;//设置溢出值
		p->softTimer.tCounter = 0x0;	
		p->softTimer.pMate = p->GroupNum;//脉冲个数匹配值
		p->softTimer.sMate = p->GroupSpace;//脉个数溢出值
		p->softTimer.pCounter = 0x0;
		p->softTimer.sCounter = 0x0;
		SFRPAGE = ACTIVE_PAGE;	
		TF2H = 0;//Timer 2 High Byte Overflow Flag.
		ET2 = 1;
		TMR2L = 0xFF;
		TMR2H = 0xFF;
		TR2 = 1;//使能TIMER2计时器
		SFRPAGE = SFRPAGE_save;
	}
	p->FlagIndicate = 1;
}
void stopLaser(myDevice_t *p)
{//停止发射脉冲
	TR2 = 0;
	ET2 = 0;
	TF2H = 0;
	LaserMod_PIN = LASER_OFF;
	ad5621_write(AD5621_LASER_CH1, 0);
	ad5621_write(AD5621_LASER_CH2, 0);
	p->FlagIndicate = 0;	
}

