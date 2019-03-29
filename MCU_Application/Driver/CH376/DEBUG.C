#include	"DEBUG.H"
/*****************************************************************************/
/* 检查操作状态,如果错误则显示错误代码并停机,应该替换为实际的处理措施,例如显示错误信息,等待用户确认后重试等 */
void mStopIfError(uint8_t iError){
	if(iError == USB_INT_SUCCESS){
		return;//操作成功
	}
	printf("Error: %02X\n", (uint16_t)iError);//显示错误
	while(1){
/*		LED_OUT_ACT( );*/  /* LED闪烁 */
		delayMs( 200 );
/*		LED_OUT_INACT( );*/
		delayMs( 200 );
	}
}