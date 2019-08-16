#ifndef __DCHMINOTIFYTEXT_H__
#define __DCHMINOTIFYTEXT_H__
/*****************************************************************************/
#include "sPlc.h"
#include "appSplcAdr.h"
#include "dcHmiRes.h"
#include "backgroundApp.h"
#include "hmiLib.h"
#include "dcHmiApp.h"
/*****************************************************************************/
void NotifyText(uint16_t screen_id, uint16_t control_id, uint8_t *str);
#endif