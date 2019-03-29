#include "usbSpi.h"
/*****************************************************************************/
void usbSpiInit(void){//USB CH376初始化
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;// Preserve SFRPAGE	    
	//SPI总线初始化
	SFRPAGE = SPI0_PAGE;
	SPI0CKR = (CONFIG_SYSCLK / (2 * CONFIG_SPICLK));//设置SPI时钟频率
	SPI0CFG = 0x0;//CKPOL=0, CKPHA=0
	SPI0CFG |= (1 << 6);//MSTEN: Master Mode Enable.
	SPI0CN = 0x0;
	SPI0CN |= (1 << 2);
	SPI0CN |= (1 << 3);
	SPI0CN |= 1 << 0;//SPIEN: SPI0 Enable.
    SFRPAGE = SFRPAGE_SAVE; 
}
static void usbSpiNssSet(uint8_t nss){//SPI NSS设置
	if(nss){
		P7 |= 0x01;
	}
	else{
		P7 &= 0xFE;
	}
}
static uint8_t usbSpiTransmit(uint8_t txd){//CH376 SPI 收发
	xdata uint8_t rxd;
	xdata uint8_t SFRPAGE_SAVE = SFRPAGE;
	SFRPAGE = SPI0_PAGE;
	SPI0DAT = txd;         
	while (!SPIF);                      
	SPIF = 0; 
	rxd = SPI0DAT;
	SFRPAGE = SFRPAGE_SAVE;
	return(rxd);
}

void xWriteCH376Cmd(uint8_t mCmd){//向CH376写命令
	usbSpiNssSet(true);
	usbSpiNssSet(false);
	usbSpiTransmit(mCmd);//发出命令码
	delayUs(2);//延时1.5uS确保读写周期大于1.5uS,或者用上面一行的状态查询代替
}
void xWriteCH376Data(uint8_t mData){//向CH376写数据
	usbSpiTransmit(mData);
	delayUs(1);//确保读写周期大于0.6uS
}
void xEndCH376Cmd(void){
	usbSpiNssSet(true);
}
uint8_t	xReadCH376Data(void){//从CH376读数据
	delayUs(1);//确保读写周期大于0.6uS
	return(usbSpiTransmit(0xFF));
}
uint8_t	usbSpiIntQuery( void ){//查询CH376中断
	return((P1 >> 7) & 0x01);//连接了CH376的中断引脚则直接查询中断引脚 */
}
uint8_t	usbHostInit(void){//初始化CH376
	xdata uint8_t	res;
	xWriteCH376Cmd(CMD11_CHECK_EXIST);//测试单片机与CH376之间的通讯接口
	xWriteCH376Data(0x65);
	res = xReadCH376Data();
	xEndCH376Cmd();
	if(res != 0x9A){
		SET(SPCOIL_USB_INT_SUCCESS);//设置SPLC标志
		return(ERR_USB_UNKNOWN);//通讯接口不正常,可能原因有:接口连接异常,其它设备影响(片选不唯一),串口波特率,一直在复位,晶振不工作 */
	}
	else{
		RES(SPCOIL_USB_UNKNOWN_ERROR);
	}
	xWriteCH376Cmd(CMD11_SET_USB_MODE);//设备USB工作模式
	xWriteCH376Data(0x05);
	delayUs(20);
	res = xReadCH376Data();
	xEndCH376Cmd();
	if(res == CMD_RET_SUCCESS){
		RES(SPCOIL_USB_UNKNOWN_ERROR);
		SET(SPCOIL_USB_INT_SUCCESS);
		return(USB_INT_SUCCESS);
	}
	else{
		SET(SPCOIL_USB_UNKNOWN_ERROR);
		RES(SPCOIL_USB_INT_SUCCESS);
		return(ERR_USB_UNKNOWN);//设置模式错误
	}
}

/* 检查操作状态,如果错误则显示错误代码并停机,应该替换为实际的处理措施,例如显示错误信息,等待用户确认后重试等 */
void mStopIfError(uint8_t iError){
	if(iError == USB_INT_SUCCESS){
		return;//操作成功
	}
	
	//printf("Error: %02X\n", (uint16_t)iError);//显示错误
	while(1){
/*		LED_OUT_ACT( );*/  /* LED闪烁 */
		delayMs( 200 );
/*		LED_OUT_INACT( );*/
		delayMs( 200 );
	}
}