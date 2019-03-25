#ifndef __LIB_H__
#define __LIB_H__
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <INTRINS.H>
#include <ctype.h>
#include <LIMITS.H>
#include <math.h>
#include "crc32.h"
#include "delay.h"
#include "endian.h"
#include "stdbool.h"
#include "stdint.h"
#include "si_toolchain.h"
#include "compiler_defs.h"
/*****************************************************************************/
#ifdef C8051F580
#include "C8051F580_defs.h"
#define CONFIG_SYSCLK                       (48000000L)//F580内部48M
#define CONFIG_SARCLK      					(2000000L)//ADC0时钟 <3MHz
#endif
/*****************************************************************************/
#ifdef C8051F020
#include "C8051F020_defs.h"
#define CONFIG_SYSCLK                       (22118400L)
#define CONFIG_SARCLK      					(2000000L)//ADC0时钟 <2.5MHz
#endif
/*****************************************************************************/
#ifdef C8051F120
#include "C8051F120_defs.h"
#define CONFIG_SYSCLK                       (22118400L * 4)
#define CONFIG_SARCLK      					(2000000L)//ADC0时钟 <2.5MHz
#endif

#endif