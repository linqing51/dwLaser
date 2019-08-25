#ifndef __DCHMINOTIFYREADRTC_H__
#define __DCHMINOTIFYREADRTC_H__
/*****************************************************************************/
#include "sPlc.h"
#include "appSplcAdr.h"
#include "dcHmiRes.h"
#include "backgroundApp.h"
#include "hmiLib.h"
#include "dcHmiApp.h"
/*****************************************************************************/
void NotifyReadRTC(uint8_t year,uint8_t month,uint8_t week,uint8_t day,uint8_t hour,uint8_t minute,uint8_t second);

#endif
