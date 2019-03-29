#ifndef	__DEBUG_H__
#define __DEBUG_H__
#include "lib.h"
#include"ch376.h"

#ifdef __CX51__
#ifndef __C51__
#define __C51__		1
#endif
#endif

#ifdef __C51__
#define	BIG_ENDIAN		1
#endif
#ifdef __C51__
#pragma NOAREGS
#endif

/* 检查操作状态,如果错误则显示错误代码并停机,应该替换为实际的处理措施,例如显示错误信息,等待用户确认后重试等 */
void	mStopIfError( UINT8 iError );

#endif
