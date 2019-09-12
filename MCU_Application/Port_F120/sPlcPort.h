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
#include "sPlcLaser.h"
#include "sPlcPca.h"
#include "sPlcUart.h"
/*****************************************************************************/
#include "sPlcChipAdc.h"
#include "sPlcChipDac.h"
#include "sPlcIoIn.h"
#include "sPlcIoOut.h"
#if CONFIG_SPLC_USING_CH376 == 1
#include "usbSpi.h"
#include "FILE_SYS.H"
#include "sPlcUsb.h"
#endif

#if CONFIG_SPLC_USING_I2C0 == 1
#include "i2c0.h"
	#if CONFIG_SPLC_USING_EPROM == 1
	#include "eprom.h"
	#endif
#endif

#if CONFIG_SPLC_USING_DK25L == 1
#include "sPlcDK25L.h"
#endif
/*****************************************************************************/



#endif
