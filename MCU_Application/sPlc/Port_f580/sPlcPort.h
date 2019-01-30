#ifndef __SPLCPORT_H__
#define __SPLCPORT_H__
/*****************************************************************************/
#include "lib.h"
#include "device.h"
#include "sPlc.h"
#include "sPlcConfig.h"
/*****************************************************************************/
#include "sPlcTimer.h"
#include "sPlcInt.h"
#if CONFIG_SPLC_USING_UART1 == 1
#include "sPlcUart.h"
#endif

#if CONFIG_SPLC_USING_ADC == 1
#include "sPlcChipAdc.h"
#endif
#if CONFIG_SPLC_USING_DAC == 1
#include "sPlcDac.h"
#endif
#if CONFIG_SPLC_USING_MB_RTU_SLAVE == 1
#include "Modbus.h"
#include "ModbusPort.h"
#endif



#if CONFIG_SPLC_USING_LED == 1
#include "sPlcLed.h"
#endif

#if CONFIG_SPLC_USING_IO_INPUT == 1
#include "sPlcIo.h"
#endif

#if CONFIG_SPLC_USING_IO_OUTPUT == 1
#endif

#if CONFIG_SPLC_USING_WDT == 1
#include "sPlcWatchDog.h"
#endif

/*****************************************************************************/



#endif
