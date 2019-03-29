#ifndef __SPLCPORT_H__
#define __SPLCPORT_H__
/*****************************************************************************/
#include "sPlc.h"
#include "sPlcConfig.h"
#include "lib.h"
/*****************************************************************************/
#include "InitDevice.h"
#include "delay.h"
#include "sPlcMcu.h"
#include "sPlcTimer.h"
/*****************************************************************************/
#include "sPlcUart.h"
#if CONFIG_SPLC_USING_ADC == 1
#include "sPlcChipAdc.h"
#endif
#if CONFIG_SPLC_USING_DAC == 1
#include "sPlcChipDac.h"
#endif
#if CONFIG_SPLC_USING_LED == 1
#include "sPlcLed.h"
#endif
#if CONFIG_SPLC_USING_IO_INPUT == 1
#include "sPlcIo.h"
#endif
#if CONFIG_SPLC_USING_IO_OUTPUT == 1
#endif
#if CONFIG_SPLC_USING_EPROM == 1
#include "eprom.h"
#endif
#if CONFIG_USING_RTU_SLAVE == 1
#include "sPlcModbus.h"
#include "sPlcModbusPort.h"
#endif



/*****************************************************************************/



#endif
