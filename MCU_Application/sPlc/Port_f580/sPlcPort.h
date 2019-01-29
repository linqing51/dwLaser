#ifndef __SPLCPORT_H__
#define __SPLCPORT_H__
/*****************************************************************************/
#include "sPlc.h"
#include "sPlcConfig.h"
#include "stdint.h"
#include "stdbool.h"
#include "endian.h"
#include "si_toolchain.h"
#include "compiler_defs.h"
#include "C8051F580_defs.h"
/*****************************************************************************/
#include "delay.h"
#include "i2c0.h"
#include "i2c1.h"
#include "i2c2.h"
#include "i2c3.h"
#include "i2c4.h"
#include "i2c5.h"
#include "i2c6.h"
#include "eprom.h"
#include "mcp47x6.h"
#include "inPca9554.h"
#include "outPca9554.h"
/*****************************************************************************/
#include "delay.h"
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
