#ifndef __HMILOOP_H__
#define __HMILOOP_H__
/*****************************************************************************/
#include "lib.h"
#include "hmiCmdQueue.h"
#include "hmiDriver.h"
#include "hmiUserUart.h"
#include "hmiCmdProcess.h"
extern uint8_t hmiCmdBuffer[CMD_MAX_SIZE];//ָ���
/*****************************************************************************/
void UpdateUI(void);//����UI����
void dcHmiLoop(void);
/*****************************************************************************/

#endif

