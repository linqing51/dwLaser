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
#include "sPlcSimEprom.h"
/*****************************************************************************/
#include "sPlcUart.h"
#if CONFIG_SPLC_USING_PCA == 1
#include "sPlcPca.h"
#endif
#if CONFIG_SPLC_USING_ADC == 1
#include "sPlcChipAdc.h"
#endif
#if CONFIG_SPLC_USING_DAC == 1
#include "sPlcChipDac.h"
#endif
#if CONFIG_SPLC_USING_IO_INPUT == 1
#include "sPlcIoIn.h"
#endif
#if CONFIG_SPLC_USING_IO_OUTPUT == 1
#include "sPlcIoOut.h"
#endif
#if CONFIG_SPLC_USING_EPROM == 1
#include "eprom.h"
#endif
#if CONFIG_USING_RTU_SLAVE == 1
#include "sPlcModbus.h"
#include "sPlcModbusPort.h"
#endif
#if CONFIG_USING_USB == 1
#include "usbSpi.h"
#include "FILE_SYS.H"
#include "sPlcUsb.h"
#endif
#if CONFIG_USING_SIMEPROM == 1
#include "sPlcSimEprom.h"
#endif
#if CONFIG_USING_ONCHIPFLASH == 1
#include "F120_FlashPrimitives.h"
#include "F120_FlashUtils.h"
#endif
#if CONFIG_SPLC_USING_LASER_TIMER == 1
#include "sPlcLaser.h"
#endif
#if CONFIG_SPLC_USING_I2C0 == 1
#include "i2c0.h"
#if CONFIG_SPLC_USING_EPROM == 1
#include "eprom.h"
#endif
#endif
#if CONFIG_SPLC_USING_I2C1 == 1
#include "i2c1.h"
#endif
#if CONFIG_SPLC_USING_I2C2 == 1
#include "i2c2.h"
#endif
#if CONFIG_SPLC_USING_I2C3 == 1
#include "i2c3.h"
#endif

/*****************************************************************************/



#endif
