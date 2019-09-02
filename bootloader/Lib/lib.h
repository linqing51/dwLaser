#ifndef __LIB_H__
#define __LIB_H__
/*****************************************************************************/
#include "si_toolchain.h"
#include "compiler_defs.h"
/*****************************************************************************/
/*****************************************************************************/
#ifdef C8051F120
#include "C8051F120_defs.h"
#define CONFIG_OSCCLK						(22118400L)
#define CONFIG_SYSCLK                       (CONFIG_OSCCLK * 4)
#define CONFIG_SARCLK      					(2000000L)//ADC0 ±÷” <2.5MHz
#define CONFIG_SPICLK						(5000000L)//SPI ±÷” 5MHz
#endif
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <INTRINS.H>
#include <ctype.h>
#include <LIMITS.H>
#include "crc16.h"
#include "delay.h"
#include "endian.h"
#include "stdbool.h"
#include "stdint.h"
/*****************************************************************************/
#endif

