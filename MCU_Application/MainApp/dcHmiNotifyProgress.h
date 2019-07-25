#ifndef __DCHMINOTIFYPROGRESS_H__
#define __DCHMINOTIFYPROGRESS_H__
/*****************************************************************************/
#include "sPlc.h"
#include "appSplcAdr.h"
#include "dcHmiRes.h"
#include "backgroundApp.h"
#include "hmiLib.h"
#include "dcHmiApp.h"
/*****************************************************************************/
void NotifyProgress(uint16_t screen_id, uint16_t control_id, uint32_t value); 
#endif