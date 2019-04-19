#ifndef __BACKGROUNDAPP_H__
#define __BACKGROUNDAPP_H__
/*****************************************************************************/
#include "sPlc.h"
#include "appSplcAdr.h"
/*****************************************************************************/
void loadScheme(void);//DM->EM
void saveScheme(void);//EM->DM
void backgroundAppInit(void);
void backgroundApp(void);
#endif