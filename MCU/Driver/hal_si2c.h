#include ""
/*****************************************************************************/
#typedef struct hal_si2c_t
{
	void *setSDA(uint8_t st);
	void *setSCL(uint8_t st);
	void *getSDA(void);
	void *getSCL(void);
	uint8_t busDelay;//×ÜÏßÆµÂÊ 
};
