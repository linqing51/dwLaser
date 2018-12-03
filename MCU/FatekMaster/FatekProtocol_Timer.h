#ifndef __FATEKPROTOCOL_TIMER_H__
#define __FATEKPROTOCOL_TIMER_H__
extern void FatekTimerInit(void);//计时器初始化
extern void FatekStartTimer(unsigned int t/*计时时间mS*/);//开始计时器
extern void FatekStopTimer(void);//关闭计时器
extern unsigned char  FatekTimerOverFlowed;		   //计时器益处标志
#endif