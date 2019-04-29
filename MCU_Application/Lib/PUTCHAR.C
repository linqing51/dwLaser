/***********************************************************************/
/*  This file is part of the C51 Compiler package                      */
/*  Copyright KEIL ELEKTRONIK GmbH 1990 - 2002                         */
/***********************************************************************/
/*                                                                     */
/*  PUTCHAR.C:  This routine is the general character output of C51.   */
/*  You may add this file to a uVision2 project.                       */
/*                                                                     */
/*  To translate this file use C51 with the following invocation:      */
/*     C51 PUTCHAR.C <memory model>                                    */
/*                                                                     */
/*  To link the modified PUTCHAR.OBJ file to your application use the  */
/*  following Lx51 invocation:                                         */
/*     Lx51 <your object file list>, PUTCHAR.OBJ <controls>            */
/*                                                                     */
/***********************************************************************/

#include "lib.h"

#define XON  0x11
#define XOFF 0x13
/*
 * putchar (full version):  expands '\n' into CR LF and handles
 *                          XON/XOFF (Ctrl+S/Ctrl+Q) protocol
 */
#if CONFIG_DEBUG_CONSOLE == 1
char putchar(char c){
	uint8_t SFRPAGE_SAVE = SFRPAGE;// Save Current SFR page
	SFRPAGE = UART1_PAGE;// Set SFR page
	if(c == '\n'){
		if(SCON1 & 0x01){
			if(SBUF1 == XOFF){
				do{
					SCON1 &= 0xFE;//RI1 = 0	
					while (!(SCON1 & 0x01));
				}
			while(SBUF1 != XON);
			SCON1 &= 0xFE;//RI1 = 0	
			}
		}
		while(!(SCON1 & 0x02));
		SCON1 &= 0xFD;//TI1 = 0
		SBUF1 = 0x0d;//output CR
	}
	if(SCON1 & 0x01){
		if(SBUF1 == XOFF){
		do{
			SCON1 &= 0xFE;//RI1 = 0	
			while (!(SCON1 & 0x01));
		}
		while (SBUF1 != XON);
		SCON1 &= 0xFE;//RI1 = 0	
		}
	}
	while (!(SCON1 & 0x02));
	SCON1 &= 0xFD;//TI1 = 0
	SBUF1 = c;
	SFRPAGE = SFRPAGE_SAVE;// Restore SFR page
	return c;
}
#endif