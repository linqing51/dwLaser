#ifndef __FATEKPROTOCOL_TIMER_H__
#define __FATEKPROTOCOL_TIMER_H__
extern void FatekTimerInit(void);//��ʱ����ʼ��
extern void FatekStartTimer(unsigned int t/*��ʱʱ��mS*/);//��ʼ��ʱ��
extern void FatekStopTimer(void);//�رռ�ʱ��
extern unsigned char  FatekTimerOverFlowed;		   //��ʱ���洦��־
#endif