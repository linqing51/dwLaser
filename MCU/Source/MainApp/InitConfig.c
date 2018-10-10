#include "appConfig.h"
/*****************************************************************************/
#if CONFIG_MCU_F020 == 1
void Reset_Sources_Init()
{
    WDTCN     = 0xDE;
    WDTCN     = 0xAD;
}

void Timer_Init()
{
    TMOD      = 0x01;
}

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    Reset_Sources_Init();
    Timer_Init();
}
#endif

#if CONFIG_MCU_F340 == 1
void PCA_Init()
{
    PCA0MD    &= ~0x40;
    PCA0MD    = 0x00;
}

void Timer_Init()
{
    TMOD      = 0x01;
    CKCON     = 0x50;
}

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    PCA_Init();
    Timer_Init();
}

#endif

#if CONFIG_MCU_F580 == 1
#endif

