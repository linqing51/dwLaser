#include "hal_iic.h"
/*****************************************************************************/
void iic_start(hal_iic_t *iic)
{//启动iic总线的函数，当SCL为高电平时使SDA产生一个负跳变
	iic->setSDA_H();
	iic->setSCL_H();
	NOP();
	iic->setSDA_L();
	swDelayUs(iic->busFreq);
	iic->setSCL_L();
}
void iic_restart(hal_iic_t *iic )
{//IIC复位
	iic->setSDA_H();
    iic->setSCL_H();
	swDelayUs(iic->busFreq);
    iic->setSDA_L();
	swDelayUs(iic->busFreq);
    iic->setSCL_L();
}
void iic_stop(hal_iic_t *iic)
{//终止iic总线，当SCL为高电平时使SDA产生一个正跳变
	iic->setSDA_L();
	swDelayUs(iic->busFreq);
    iic->setSCL_H();
	swDelayUs(iic->busFreq);
    iic->setSDA_H();
	swDelayUs(iic->busFreq);
}

uint8_t iic_waitAck(hal_iic_t *iic)
{
	uint8_t ack;
    iic->setSDA_H();
	swDelayUs(iic->busFreq);
    if(iic->setSCL_H() < 0)
    {
#if CONFIG_IIC_DEBUG == 1
		printf("wait ack timeout\n");
#endif
        return IIC_TIMEOUT;
    }
    ack = !(iic->getSDA());//ACK:SDA pin is pulled low
#if CONFIG_IIC_DEBUG == 1
    printf("%s\n", ack ? "ACK" : "NACK");
#endif
    iic->setSCL_L();
    return ack;
}

uint8_t iic_writeByte(hal_iic_t *iic, uint8_t wdata)
{//向iic总线写一个字节*/
    int32_t i;
    uint8_t xbit;
    for (i = 7; i >= 0; i--)
    {
        iic->setSCL_L();
        xbit = (wdata >> i) & 1;
		if(xbit)
			iic->setSDA_H();
		else
			iic->setSDA_L();
        swDelayUs(iic->busFreq);
        if((iic->setSCL_H()) < 0)
        {
#if CONFIG_IIC_DEBUG ==1 
            printf("i2c_writeb: 0x%02x, "
                    "wait scl pin high timeout at bit %d\n",
                    wdata, i);
#endif
            return IIC_TIMEOUT;
        }
    }
    iic->setSCL_L();
    swDelayUs(iic->busFreq);
    return iic_waitAck(iic); 
}

uint8_t iic_readByte(hal_iic_t *iic)
{//从iic总线读一个字节
	uint8_t i;
    uint8_t rdata = 0;
    iic->setSDA_H();
	swDelayUs(iic->busFreq);
    for(i = 0; i < 8; i++)
    {
        rdata <<= 1;
        if((iic->setSCL_H()) < 0)
        {
#if CONFIG_IIC_DEBUG ==1 
            printf("i2c_readb: wait scl pin high "
                    "timeout at bit %d\n", 7 - i);
#endif
            return IIC_TIMEOUT;
        }
        if ( iic->getSDA())
		{
            rdata |= 1;
		}
        iic->setSCL_L();
		swDelayUs(iic->busFreq);
    }
    return rdata;
}


